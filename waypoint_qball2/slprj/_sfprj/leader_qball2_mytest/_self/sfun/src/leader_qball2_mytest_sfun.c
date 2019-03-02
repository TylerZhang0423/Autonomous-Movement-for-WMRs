/* Include files */

#include "leader_qball2_mytest_sfun.h"
#include "leader_qball2_mytest_sfun_debug_macros.h"
#include "c2_leader_qball2_mytest.h"
#include "c4_leader_qball2_mytest.h"
#include "c5_leader_qball2_mytest.h"
#include "c6_leader_qball2_mytest.h"
#include "c10_leader_qball2_mytest.h"
#include "c11_leader_qball2_mytest.h"
#include "c12_leader_qball2_mytest.h"
#include "c13_leader_qball2_mytest.h"
#include "c14_leader_qball2_mytest.h"
#include "c15_leader_qball2_mytest.h"
#include "c16_leader_qball2_mytest.h"
#include "c18_leader_qball2_mytest.h"
#include "c19_leader_qball2_mytest.h"
#include "c21_leader_qball2_mytest.h"
#include "c22_leader_qball2_mytest.h"
#include "c23_leader_qball2_mytest.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _leader_qball2_mytestMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void leader_qball2_mytest_initializer(void)
{
}

void leader_qball2_mytest_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_leader_qball2_mytest_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_leader_qball2_mytest_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_leader_qball2_mytest_process_testpoint_info_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "leader_qball2_mytest")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_leader_qball2_mytest_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4193274667U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(795624648U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2583129743U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3700858410U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3462572217U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3341147615U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(669974482U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(36276949U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c2_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c4_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c5_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c6_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c10_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c11_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c12_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c13_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c14_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c15_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c16_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c18_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c19_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c21_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c22_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
          sf_c23_leader_qball2_mytest_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3084158392U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2524169757U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2812955680U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(245732821U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(913085973U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4262471376U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2038980779U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3764870620U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_leader_qball2_mytest_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "SrdF6uasgdVQ7YHMsiYpiG") == 0) {
          extern mxArray *sf_c2_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "bI5R6pKUhre2ShOiszjt0D") == 0) {
          extern mxArray *sf_c4_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "vWIhD63Zy6KboFfUbSYbdG") == 0) {
          extern mxArray *sf_c5_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "ntxwRtTVhPypLHHBzKiGtF") == 0) {
          extern mxArray *sf_c6_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "4mw0JtAIQxUGDK3WevqPjH") == 0) {
          extern mxArray *sf_c10_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "4mw0JtAIQxUGDK3WevqPjH") == 0) {
          extern mxArray *sf_c11_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "4mw0JtAIQxUGDK3WevqPjH") == 0) {
          extern mxArray *sf_c12_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c12_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "xFG6tB0REHTKvhSxzuS5gH") == 0) {
          extern mxArray *sf_c13_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c13_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "8z4S8wKRRw1svW1Pj6zds") == 0) {
          extern mxArray *sf_c14_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c14_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "mEijgQzW1rDXeDurJsVaB") == 0) {
          extern mxArray *sf_c15_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c15_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "LJbrp1HKVP78rDSKT32s3B") == 0) {
          extern mxArray *sf_c16_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c16_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "brlIAlTsodQFE1dr5xSjNC") == 0) {
          extern mxArray *sf_c18_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c18_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "puHtRh2QoMu2dXE533lHr") == 0) {
          extern mxArray *sf_c19_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c19_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "WAt1MzYVS0jRnqDE31YZCC") == 0) {
          extern mxArray *sf_c21_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c21_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "hAvsGwKxbUhhAqM0Rf8L7B") == 0) {
          extern mxArray *sf_c22_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c22_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "JDR13ImN3t94WUj9CYUryC") == 0) {
          extern mxArray *sf_c23_leader_qball2_mytest_get_autoinheritance_info
            (void);
          plhs[0] = sf_c23_leader_qball2_mytest_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_leader_qball2_mytest_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_leader_qball2_mytest_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_leader_qball2_mytest_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_leader_qball2_mytest_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "BG7d1QxyZQOtguPp9jKRzF") == 0) {
          extern mxArray *sf_c2_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c2_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "4tASnhwPvkvXY6lb1FUTgG") == 0) {
          extern mxArray *sf_c4_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c4_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "TMQVHZjitbhhZZ5daln3EB") == 0) {
          extern mxArray *sf_c5_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c5_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "pKdHmKVgRIJfgIMlHL9EyE") == 0) {
          extern mxArray *sf_c6_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c6_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ttrMQi7RflxUlB9blFG6LD") == 0) {
          extern mxArray *sf_c10_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c10_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "ttrMQi7RflxUlB9blFG6LD") == 0) {
          extern mxArray *sf_c11_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c11_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "ttrMQi7RflxUlB9blFG6LD") == 0) {
          extern mxArray *sf_c12_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c12_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "xDT88peDz76TrJfYloBUsF") == 0) {
          extern mxArray *sf_c13_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c13_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "F3BhQ60bE9tGU57SNP8IAC") == 0) {
          extern mxArray *sf_c14_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c14_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "Ps6RuDKqkoyxfv50amkwWE") == 0) {
          extern mxArray *sf_c15_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c15_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OPGOJtI13b6YPIZn6TDa6B") == 0) {
          extern mxArray *sf_c16_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c16_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "oYVXTMUV1b7TsKljD1qm6F") == 0) {
          extern mxArray *sf_c18_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c18_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "6J37iI47RwXGSZyaWLiFUH") == 0) {
          extern mxArray *sf_c19_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c19_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "HBSBQ2eHcQxGUOlqW0CMkG") == 0) {
          extern mxArray *sf_c21_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c21_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "QhWiQ7C9yrGOXmbVk3yifD") == 0) {
          extern mxArray *sf_c22_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c22_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "t12yExnNvEbxmLrMwScLJF") == 0) {
          extern mxArray *sf_c23_leader_qball2_mytest_third_party_uses_info(void);
          plhs[0] = sf_c23_leader_qball2_mytest_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_leader_qball2_mytest_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "BG7d1QxyZQOtguPp9jKRzF") == 0) {
          extern mxArray *sf_c2_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "4tASnhwPvkvXY6lb1FUTgG") == 0) {
          extern mxArray *sf_c4_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "TMQVHZjitbhhZZ5daln3EB") == 0) {
          extern mxArray *sf_c5_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "pKdHmKVgRIJfgIMlHL9EyE") == 0) {
          extern mxArray *sf_c6_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c6_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ttrMQi7RflxUlB9blFG6LD") == 0) {
          extern mxArray *sf_c10_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c10_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "ttrMQi7RflxUlB9blFG6LD") == 0) {
          extern mxArray *sf_c11_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c11_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "ttrMQi7RflxUlB9blFG6LD") == 0) {
          extern mxArray *sf_c12_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c12_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "xDT88peDz76TrJfYloBUsF") == 0) {
          extern mxArray *sf_c13_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c13_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "F3BhQ60bE9tGU57SNP8IAC") == 0) {
          extern mxArray *sf_c14_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c14_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "Ps6RuDKqkoyxfv50amkwWE") == 0) {
          extern mxArray *sf_c15_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c15_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "OPGOJtI13b6YPIZn6TDa6B") == 0) {
          extern mxArray *sf_c16_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c16_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "oYVXTMUV1b7TsKljD1qm6F") == 0) {
          extern mxArray *sf_c18_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c18_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "6J37iI47RwXGSZyaWLiFUH") == 0) {
          extern mxArray *sf_c19_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c19_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "HBSBQ2eHcQxGUOlqW0CMkG") == 0) {
          extern mxArray *sf_c21_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c21_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "QhWiQ7C9yrGOXmbVk3yifD") == 0) {
          extern mxArray *sf_c22_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c22_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "t12yExnNvEbxmLrMwScLJF") == 0) {
          extern mxArray *sf_c23_leader_qball2_mytest_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c23_leader_qball2_mytest_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void leader_qball2_mytest_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _leader_qball2_mytestMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"leader_qball2_mytest","sfun",0,16,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _leader_qball2_mytestMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _leader_qball2_mytestMachineNumber_,0);
}

void leader_qball2_mytest_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_leader_qball2_mytest_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "leader_qball2_mytest", "leader_qball2_mytest");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_leader_qball2_mytest_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
