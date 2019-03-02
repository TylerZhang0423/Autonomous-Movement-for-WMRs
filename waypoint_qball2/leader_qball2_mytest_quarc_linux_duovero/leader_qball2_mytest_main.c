/****************************************************************************
 * leader_qball2_mytest_main.c
 *
 * This file was generated automatically by QUARC. It serves as the main
 * entry point for the real-time code.
 *
 * Date:           Mon Aug 31 23:14:23 2015
 * Model version:  1.901
 * Matlab version: 8.6 (R2014a) 27-Dec-2013
 ****************************************************************************/

#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "rtwtypes.h"
#include "leader_qball2_mytest.h"
#include "leader_qball2_mytest_private.h"
#include "rtmodel.h"
#include "rt_sim.h"
#include "quanser_limits.h"
#include "ext_work.h"
#include "quanser_timer.h"
#include "quanser_semaphore.h"
#include "quanser_thread.h"
#include "quanser_signal.h"
#include "quanser_string.h"
#include "quanser_messages.h"

/*=========*
 * Defines *
 *=========*/
static const int_T exit_failure = 1;
static const int_T exit_success = 0;

#define STRINGIZE1(name)               #name
#define STRINGIZE(name)                STRINGIZE1(name)          /* need to expand name    */
#ifndef RT
# error "must define RT"
#endif

/*
   #ifndef rtmSetTFinal
   #define rtmSetTFinal(rtm,val)           ((rtm)->Timing.tFinal = (val))
   #endif
 */
#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      (3)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            (0.002)
#endif

#define SS_HAVESTDIO                   HAVESTDIO
#ifdef HAVESTDIO
#define ssPrintf                       printf
#else
#define ssPrintf
#endif

#define rtInf                          get_infinity()

static const real_T RUN_FOREVER = -1.0;
typedef RT_MODEL_leader_qball2_mytest_T RT_MODEL;

/*====================*
 * External functions *
 *====================*/
EXTERN RT_MODEL * leader_qball2_mytest(void);

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];

/*
   extern void leader_qball2_mytest_initialize();
   extern void leader_qball2_mytest_terminate();
 */

/* extern void leader_qball2_mytest_step(int_T tid); */

/* multi-rate step function */

/*==================================*
 * Global data local to this module *
 *==================================*/
static struct {
  int_T overrunFlags[1];
  int_T isrOverrun;
  boolean_T stopExecutionFlag;
  boolean_T startedFlag;
  char message[256];
  char submessage[192];
} GBLbuf;

EXTERN void rtExtModeStart(void);
EXTERN void rtExtModeQuarcCleanup(int_T numSampTimes);
EXTERN boolean_T rtExtModeQuarcStartup(RTWExtModeInfo *ei,
  int_T num_sample_times,
  boolean_T *stopReqPtr,
  int_T priority,
  int32_T stack_size,
  boolean_T enable_printing);
EXTERN void rtExtModeQuarcParseArgs(int_T argc,
  const char_T *argv[],
  const char_T *default_uri);
EXTERN void rtExtSetReturnStatus(const char * message);
EXTERN void
  _do_assertion(const char * expression, const char * file_name, int line_number)
{
  string_format(GBLbuf.message, sizeof(GBLbuf.message),
                "Assertion in %s at line %d: (%s) is false",
                file_name, line_number, expression);
  rtmSetErrorStatus(leader_qball2_mytest_M, GBLbuf.message);
}

typedef struct tag_subrate_info {
  RT_MODEL * S;
  qthread_t thread;
  qthread_id_t thread_id;
  qsem_t sem;
  int_T tid;
  int_T eventFlag;
} subrate_info_T;

static subrate_info_T subrate_info[1];

/* Function: tSubRate ========================================================
 * Abstract:
 *  This is the entry point for each sub-rate task.  This task simply executes
 *  the appropriate  blocks in the model each time the passed semaphore is
 *  given. This routine returns only when execution should be stopped.
 */
static int_T tSubRate(RT_MODEL * S, qsem_t * sem, int_T tid)
{
  while (1) {
    if (qsem_wait(sem) || GBLbuf.stopExecutionFlag) {
      break;
    }

    /*
       If the semaphore is still signaled after we wait then
       it was signaled twice so the sub-rate task has not been
       able to keep up. An overrun has occurred.
     */
    if (qsem_trywait(sem) == 0) {
      (void) fprintf(stderr, "Rate for subrate task %d is too fast.\n", tid);
      fflush(stderr);
    }

    leader_qball2_mytest_step(tid);
  }

  return(1);
}                                      /* end tSubRate */

qthread_return_t QTHREAD_DECL subrate_start_routine(void * argument)
{
  subrate_info_T * context = (subrate_info_T *) argument;
  qsigset_t signal_set;
  qsigemptyset(&signal_set);
  qsigaddset(&signal_set, SIGINT);
  qsigaddset(&signal_set, SIGBREAK);
  qsigaddset(&signal_set, SIGRTMAX);   /* SIGRTMAX is used by the qtimer routines */
  qthread_sigmask(QSIG_BLOCK, &signal_set, NULL);
  tSubRate(context->S, &context->sem, context->tid);
  return (qthread_return_t) 0;
}

/* Function: rtOneStep =======================================================
 *
 * Abstract:
 *      Perform one step of the model for the base rate task and signal
 *      subrate tasks to run when appropriate.
 */
static void rt_OneStep(RT_MODEL * S)
{
  int_T i;

  /***********************************************
   * Check and see if error status has been set  *
   ***********************************************/
  if (rtmGetErrorStatus(S) != NULL) {
    GBLbuf.stopExecutionFlag = 1;
    return;
  }

  /* enable interrupts here */
  for (i=0; i < 1; i++) {
    int_T task = i + 2;
    if (rtmStepTask(S, task) && subrate_info[i].eventFlag++) {
      /* OverrunFlags[i]++; */
      rtmSetErrorStatus(S, "Sampling rate is too fast.");
      return;
    }

    if (++rtmTaskCounter(S, task) == rtmCounterLimit(S, task))
      rtmTaskCounter(S, task) = 0;
  }

  leader_qball2_mytest_step(0);

  /************************************************************************
   * Model step complete for base sample time, now it is okay to          *
   * re-interrupt this ISR.                                               *
   ************************************************************************/

  /*********************************************
   * Step the model for any other sample times *
   *********************************************/
  for (i=0; i < 1; i++) {
    if (subrate_info[i].eventFlag) {
      /* Signal any lower priority tasks that have a hit,
       * then check to see if the task locked the semaphore
       * (i.e. if it was blocking at the time the semaphore
       * was posted).  If not, it means that task did not
       * finish in its alloted time period.
       *
       * NOTE: On a single (not hyperthreaded) CPU, these tasks
       *       won't run until the base rate thread goes to sleep
       *       because they have a lower priority. However, on a
       *       hyperthreaded or multiple CPU system, a task may
       *       run immediately.
       */
      qsem_post(&subrate_info[i].sem);
      --subrate_info[i].eventFlag;
    }
  }

  rtExtModeCheckEndTrigger();
}                                      /* end rtOneStep */

static void
  control_c_handler(int signal_number)
{
  /*
     Set a global flag to stop model execution and
     terminate cleanly. Signal the start semaphore
     to make the model exit if it is waiting for
     a start signal from the host.
   */
  GBLbuf.stopExecutionFlag = 1;
  rtExtModeStart();
}

int
  main(int argc, char * argv[])
{
  RT_MODEL * S;
  int_T count;
  int exit_code = exit_success;
  boolean_T parseError = false;
  real_T final_time = -2;              /* Let model select final time */
  int scheduling_priority;
  struct qsched_param scheduling;
  t_period timeout;
  t_timer_notify notify;
  t_error result;

  /*
   * Make controller threads higher priority than external mode threads:
   *   ext_priority = priority of lowest priority external mode thread
   *   min_priority = minimum allowable priority of lowest priority model task
   *   max_priority = maximum allowable priority of lowest priority model task
   */
  int ext_priority = qsched_get_priority_min(QSCHED_FIFO);
  int min_priority = ext_priority + 2;
  int max_priority = qsched_get_priority_max(QSCHED_FIFO) - 1;
  qsigset_t signal_set;
  qsigaction_t action;
  int_T stack_size = 0;                /* default stack size */
  (void) ssPrintf("Entered main(argc=%d, argv=%p)\n", argc, argv);
  for (count = 0; count < argc; count++) {
    (void) ssPrintf("  argv[%d] = %s\n", count, argv[count]);
  }

  scheduling_priority = 20;            /* default priority */
  if (scheduling_priority < min_priority) {
    scheduling_priority = min_priority;
  } else if (scheduling_priority > max_priority) {
    scheduling_priority = max_priority;
  }

  /*
   * Parse the standard RTW parameters.  Let all unrecognized parameters
   * pass through to external mode for parsing.  NULL out all args handled
   * so that the external mode parsing can ignore them.
   */
  for (count = 1; count < argc; ) {
    const char *option = argv[count++];
    char extraneous_characters[2];
    if ((strcmp(option, "-tf") == 0) && (count != argc)) {/* final time */
      const char * tf_argument = argv[count++];
      double time_value;               /* use a double for the sscanf since real_T may be a float or a double depending on the platform */
      if (strcmp(tf_argument, "inf") == 0) {
        time_value = RUN_FOREVER;
      } else {
        int items = sscanf(tf_argument, "%lf%1s", &time_value,
                           extraneous_characters);
        if ((items != 1) || (time_value < 0.0) ) {
          (void) fprintf(stderr,
                         "final_time must be a positive, real value or inf.\n");
          parseError = true;
          break;
        }
      }

      final_time = (real_T) time_value;
      argv[count-2] = NULL;
      argv[count-1] = NULL;
    } else if ((strcmp(option, "-pri") == 0) && (count != argc)) {/* base priority */
      const char * pri_argument = argv[count++];
      int priority;                    /* use an int for the sscanf since int_T may be the wrong size depending on the platform */
      int items = sscanf(pri_argument, "%d%1s", &priority, extraneous_characters);
      if ((items != 1) || (priority < min_priority) ) {
        (void) fprintf(stderr,
                       "priority must be a greater than or equal to %d.\n",
                       min_priority);
        parseError = true;
        break;
      }

      if (priority > max_priority) {
        (void) fprintf(stderr, "priority must be less than or equal to %d.\n",
                       max_priority);
        parseError = true;
        break;
      }

      scheduling_priority = priority;
      argv[count-2] = NULL;
      argv[count-1] = NULL;
    } else if ((strcmp(option, "-ss") == 0) && (count != argc)) {/* stack size */
      const char * stack_argument = argv[count++];
      int stack;                       /* use an int for the sscanf since int_T may be the wrong size depending on the platform */
      int items = sscanf(stack_argument, "%d%1s", &stack, extraneous_characters);
      if ((items != 1) || (stack < QTHREAD_STACK_MIN) ) {
        (void) fprintf(stderr,
                       "stack size must be a integral value greater than or equal to %d.\n",
                       QTHREAD_STACK_MIN);
        parseError = true;
        break;
      }

      stack_size = (int_T)stack;
      argv[count-2] = NULL;
      argv[count-1] = NULL;
    } else if ((strcmp(option, "-d") == 0) && (count != argc)) {/* current directory */
      const char * path_name = argv[count++];
      chdir(path_name);
      argv[count-2] = NULL;
      argv[count-1] = NULL;
    }
  }

  rtExtModeQuarcParseArgs(argc, (const char **) argv,
    "tcpip://192.168.2.26:17001?keep_alive=1");

  /*
   * Check for unprocessed ("unhandled") args.
   */
  for (count = 1; count < argc; count++) {
    if (argv[count] != NULL) {
      (void) fprintf(stderr, "Unexpected command line argument: \"%s\".\n",
                     argv[count]);
      parseError = true;
    }
  }

  if (parseError) {
    (void) fprintf(stderr,
                   "\nUsage: leader_qball2_mytest -option1 val1 -option2 val2 -option3 ...\n\n");
    (void) fprintf(stderr,
                   "\t-tf  20               - sets final time to 20 seconds\n");
    (void) fprintf(stderr,
                   "\t-d   C:\\data          - sets current directory to C:\\data\n");
    (void) fprintf(stderr,
                   "\t-pri 5                - sets the minimum thread priority\n");
    (void) fprintf(stderr,
                   "\t-ss  65536            - sets the stack size for model threads\n");
    (void) fprintf(stderr,
                   "\t-w                    - wait for host to connect before starting\n");
    (void) fprintf(stderr,
                   "\t-uri shmem://mymodel  - set external mode URL to \"shmem://mymodel\"\n");
    (void) fprintf(stderr, "\n");
    return (exit_failure);
  }

  /****************************
   * Initialize global memory *
   ****************************/
  (void)memset(&GBLbuf, 0, sizeof(GBLbuf));

  /************************
   * Initialize the model *
   ************************/
  leader_qball2_mytest_initialize();
  S = leader_qball2_mytest_M;
  if (final_time >= 0.0 || final_time == RUN_FOREVER) {
    rtmSetTFinal(S,final_time);
  } else {
    rtmSetTFinal(S,rtInf);
  }

  qsigemptyset(&signal_set);
  qsigaddset(&signal_set, SIGRTMAX);   /* SIGRTMAX is used by the qtimer routines */
  qthread_sigmask(QSIG_BLOCK, &signal_set, NULL);
  action.sa_handler = control_c_handler;
  action.sa_flags = 0;
  qsigemptyset(&action.sa_mask);
  qsigaction(SIGINT, &action, NULL);
  qsigaction(SIGBREAK, &action, NULL);
  qsigemptyset(&signal_set);
  qsigaddset(&signal_set, SIGINT);
  qsigaddset(&signal_set, SIGBREAK);
  qthread_sigmask(QSIG_UNBLOCK, &signal_set, NULL);
  fflush(stdout);
  if (rtExtModeQuarcStartup(rtmGetRTWExtModeInfo(S),
       rtmGetNumSampleTimes(S),
       &rtmGetStopRequested(S),
       ext_priority,                   /* external mode thread priority */
       stack_size,
       SS_HAVESTDIO)) {
    (void) ssPrintf("\n** starting the model **\n");
    if (rtmGetErrorStatus(S) == NULL) {
      int subrate_index;
      int subrate;

      /*************************************************************************
       * Execute the model.
       *************************************************************************/
      if (rtmGetTFinal(S) == RUN_FOREVER) {
        (void) ssPrintf("\n**May run forever. Model stop time set to infinity.**\n");
      }

      (void) ssPrintf("Creating a multithreaded model\n");
      for (subrate_index = 0; subrate_index >= 0; --subrate_index) {
        subrate_info[subrate_index].S = S;
        subrate_info[subrate_index].tid = 2 + subrate_index;
        result = qsem_init(&subrate_info[subrate_index].sem, 0);
        if (result == 0) {
          qthread_attr_t thread_attr;
          (void) ssPrintf("Creating subrate thread %d with priority %d...\n",
                          subrate_info[subrate_index].tid, scheduling_priority);
          qthread_attr_init(&thread_attr);
          if (stack_size > 0)
            qthread_attr_setstacksize(&thread_attr, stack_size);
          qthread_attr_setschedpolicy(&thread_attr, QSCHED_FIFO);
          qthread_attr_setinheritsched(&thread_attr, QTHREAD_EXPLICIT_SCHED);
          scheduling.sched_priority = scheduling_priority;
          qthread_attr_setschedparam(&thread_attr, &scheduling);
          result = qthread_create(&subrate_info[subrate_index].thread,
            &subrate_info[subrate_index].thread_id, &thread_attr,
            subrate_start_routine, &subrate_info[subrate_index]);
          qthread_attr_destroy(&thread_attr);
          if (result == 0) {
            scheduling_priority++;
          } else {
            msg_get_error_messageA(NULL, result, GBLbuf.submessage, sizeof
              (GBLbuf.submessage));
            string_format(GBLbuf.message, sizeof(GBLbuf.message),
                          "Unable to create subrate thread %d. %s",
                          subrate_info[subrate_index].tid, GBLbuf.submessage);
            rtmSetErrorStatus(S, GBLbuf.message);
            qsem_destroy(&subrate_info[subrate_index].sem);
            break;
          }
        } else {
          msg_get_error_messageA(NULL, result, GBLbuf.submessage, sizeof
            (GBLbuf.submessage));
          string_format(GBLbuf.message, sizeof(GBLbuf.message),
                        "Unable to create semaphore for subrate thread %d. %s",
                        subrate_info[subrate_index].tid, GBLbuf.submessage);
          rtmSetErrorStatus(S, GBLbuf.message);
          break;
        }
      }

      if (subrate_index < 0) {         /* all threads successfully created */
        timeout.seconds = (t_long) (rtmGetStepSize(S));
        timeout.nanoseconds = (t_int) ((rtmGetStepSize(S) - timeout.seconds) *
          1000000000L);
        result = qtimer_event_create(&notify.notify_value.event);
        if (result == 0) {
          t_timer timer;
          scheduling.sched_priority = scheduling_priority;
          qthread_setschedparam(qthread_self(), QSCHED_FIFO, &scheduling);
          notify.notify_type = TIMER_NOTIFY_EVENT;
          result = qtimer_create(&notify, &timer);
          if (result == 0) {
            result = qtimer_begin_resolution(timer, &timeout);
            if (result == 0) {
              t_period actual_timeout;
              (void) ssPrintf("Creating main thread with priority %d and period %g...\n",
                              scheduling_priority, rtmGetStepSize(S));
              result = qtimer_get_actual_period(timer, &timeout, &actual_timeout);
              if (result == 0 && (timeout.nanoseconds !=
                                  actual_timeout.nanoseconds || timeout.seconds
                                  != actual_timeout.seconds))
                (void) ssPrintf("*** Actual period will be %g ***\n",
                                actual_timeout.seconds + 1e-9 *
                                actual_timeout.nanoseconds);
              fflush(stdout);
              result = qtimer_set_time(timer, &timeout, true);
              if (result == 0) {
                /* Enter the periodic loop */
                while (result == 0) {
                  if (GBLbuf.stopExecutionFlag || rtmGetStopRequested(S)) {
                    break;
                  }

                  if (rtmGetTFinal(S) != RUN_FOREVER && rtmGetTFinal(S) -
                      rtmGetT(S) <= rtmGetT(S)*DBL_EPSILON) {
                    break;
                  }

                  if (qtimer_get_overrun(timer) > 0) {
                    (void) fprintf(stderr,
                                   "Sampling rate is too fast for base rate\n");
                    fflush(stderr);
                  }

                  rt_OneStep(S);
                  result = qtimer_event_wait(notify.notify_value.event);
                }

                /* disarm the timer */
                qtimer_cancel(timer);
                if (rtmGetStopRequested(S) == false && rtmGetErrorStatus(S) ==
                    NULL) {
                  /* Execute model last time step if final time expired */
                  rt_OneStep(S);
                }

                (void) ssPrintf("Main thread exited\n");
              } else {
                msg_get_error_messageA(NULL, result, GBLbuf.submessage, sizeof
                  (GBLbuf.submessage));
                string_format(GBLbuf.message, sizeof(GBLbuf.message),
                              "Unable to set base rate. %s", GBLbuf.submessage);
                rtmSetErrorStatus(S, GBLbuf.message);
              }

              {
                pstream_shutdown(leader_qball2_mytest_DW.StreamClient_Stream);
                pstream_shutdown(leader_qball2_mytest_DW.StreamServer_Stream);
              }

              /* Do NOT use the subrate_index variable for this loop! */
              for (subrate = 0; subrate < 1; subrate++) {
                qthread_cancel(subrate_info[subrate].thread,
                               subrate_info[subrate].thread_id);
              }

              qtimer_end_resolution(timer);
            } else {
              msg_get_error_messageA(NULL, result, GBLbuf.submessage, sizeof
                (GBLbuf.submessage));
              string_format(GBLbuf.message, sizeof(GBLbuf.message),
                            "Sampling period of %lg is too fast for the system clock. %s",
                            rtmGetStepSize(S), GBLbuf.submessage);
              rtmSetErrorStatus(S, GBLbuf.message);
            }

            qtimer_delete(timer);
          } else {
            msg_get_error_messageA(NULL, result, GBLbuf.submessage, sizeof
              (GBLbuf.submessage));
            string_format(GBLbuf.message, sizeof(GBLbuf.message),
                          "Unable to create timer for base rate. %s",
                          GBLbuf.submessage);
            rtmSetErrorStatus(S, GBLbuf.message);
          }

          qtimer_event_delete(notify.notify_value.event);
        } else {
          msg_get_error_messageA(NULL, result, GBLbuf.submessage, sizeof
            (GBLbuf.submessage));
          string_format(GBLbuf.message, sizeof(GBLbuf.message),
                        "Unable to create timer event for base rate. %s",
                        GBLbuf.submessage);
          rtmSetErrorStatus(S, GBLbuf.message);
        }

        GBLbuf.stopExecutionFlag = 1;
      }

      /*
         If all the subrate threads were created successfully, then subrate_index is
         equal to -1 and subrate_index++ is 0. If some of the subrate threads could
         not be created successfully then subrate_index++ is the index of the last
         successfully created thread.
       */
      for (subrate_index++; subrate_index < 1; subrate_index++) {
        qthread_return_t exit_code;

        /*qsem_post(&subrate_info[subrate_index].sem);*/
        qthread_cancel(subrate_info[subrate_index].thread,
                       subrate_info[subrate_index].thread_id);
        qthread_join(subrate_info[subrate_index].thread, &exit_code);
        qsem_destroy(&subrate_info[subrate_index].sem);
        (void) ssPrintf("Subrate thread %d returned exit_code: %p\n",
                        subrate_info[subrate_index].tid, exit_code);
      }
    }
  } else {
    rtmSetErrorStatus(S, "Unable to initialize external mode.");
  }

  rtExtSetReturnStatus(rtmGetErrorStatus(S));
  rtExtModeQuarcCleanup(rtmGetNumSampleTimes(S));

  /********************
   * Cleanup and exit *
   ********************/
  (void) ssPrintf("Invoking model termination function...\n");
  leader_qball2_mytest_terminate();
  (void) ssPrintf("Exiting real-time code\n");
  return (exit_code);
}
