/*
 * follower_qbot2.c
 *
 * Code generation for model "follower_qbot2".
 *
 * Model version              : 1.94
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 17:54:36 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "follower_qbot2.h"
#include "follower_qbot2_private.h"
#include "follower_qbot2_dt.h"

/* Block signals (auto storage) */
B_follower_qbot2_T follower_qbot2_B;

/* Continuous states */
X_follower_qbot2_T follower_qbot2_X;

/* Block states (auto storage) */
DW_follower_qbot2_T follower_qbot2_DW;

/* Real-time model */
RT_MODEL_follower_qbot2_T follower_qbot2_M_;
RT_MODEL_follower_qbot2_T *const follower_qbot2_M = &follower_qbot2_M_;

/* Forward declaration for local functions */
static void follower__ClosedLoop_Sequential(real_T dist, real_T theta, real_T
  vlimit, real_T ang_thr, real_T Kv, real_T Kw, real_T Vf_1, real_T *Vf, real_T *
  W);

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  follower_qbot2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S35>/Way Point Control' */
static void follower__ClosedLoop_Sequential(real_T dist, real_T theta, real_T
  vlimit, real_T ang_thr, real_T Kv, real_T Kw, real_T Vf_1, real_T *Vf, real_T *
  W)
{
  real_T wmax;
  real_T theta_0;

  /* '<S36>:1:154' */
  wmax = 2.0 * vlimit;
  if (((fabs(theta) > ang_thr) && (Vf_1 < 0.01)) || (fabs(theta) > 5.0 * ang_thr))
  {
    /* '<S36>:1:156' */
    /*  once rotated, then moves. once started moving, it won't turn unless the heading is too off target or have reached the previous target. */
    /* '<S36>:1:157' */
    *W = Kw * theta;

    /* '<S36>:1:158' */
    *Vf = 0.0;
    if (fabs(*W) > wmax) {
      /* '<S36>:1:159' */
      /* '<S36>:1:160' */
      if (theta < 0.0) {
        theta_0 = -1.0;
      } else if (theta > 0.0) {
        theta_0 = 1.0;
      } else if (theta == 0.0) {
        theta_0 = 0.0;
      } else {
        theta_0 = theta;
      }

      *W = theta_0 * wmax;
    }
  } else {
    /* '<S36>:1:163' */
    *Vf = Kv * dist;
    if (fabs(*Vf) > vlimit) {
      /* '<S36>:1:165' */
      /* '<S36>:1:166' */
      if (*Vf < 0.0) {
        wmax = -1.0;
      } else if (*Vf > 0.0) {
        wmax = 1.0;
      } else if (*Vf == 0.0) {
        wmax = 0.0;
      } else {
        wmax = *Vf;
      }

      *Vf = wmax * vlimit;
    }

    /*  if (abs(theta) > 2*ang_thr) */
    /*    W=Kw*theta; */
    /*    Vf=0.4*Vf; */
    /*  else */
    /* '<S36>:1:172' */
    *W = 0.0;

    /*  end */
    /*  if abs(W)> wmax */
    /*      W=sign(theta)*wmax; */
    /*  end */
  }

  /* { */
  /* function [vr, vl] = solve_inv_kin(dist, theta, vlimit, delta_t) */
  /*  */
  /* d = 0.23; */
  /* vmax = vlimit(2); */
  /* wmax = (2*vmax)/d; */
  /* w = theta/delta_t; */
  /* w_sign = sign(w); */
  /* if abs(w) > wmax */
  /*     w = w_sign*wmax; */
  /*     vr = int16(round((d*w)/2)); */
  /*     vl = int16(-vr); */
  /* else */
  /*     v = dist/delta_t; */
  /*     vr_tmp = (2*v + d*w)/2; */
  /*     vl_tmp = 2*v - vr_tmp; */
  /*      */
  /*     max_of_vrvl = abs(max(vr_tmp, vl_tmp)); */
  /*     if max_of_vrvl > vmax */
  /*         vr_tmp = (vr_tmp/max_of_vrvl)*vmax; */
  /*         vl_tmp = (vl_tmp/max_of_vrvl)*vmax; */
  /*     end */
  /*     vr = int16(vr_tmp); */
  /*     vl = int16(vl_tmp); */
  /*  */
  /* end */
  /*  */
  /* return; */
  /* } */
  /* { */
  /*  ------------------------------------------------------------------------- */
  /* function [vr, vl] = rotate_and_go(theta, vlimit, ang_thr) */
  /*  */
  /* if abs(theta) > ang_thr */
  /*     if theta >= 0 */
  /*         vr = int16(vlimit(1)); */
  /*         vl = int16(-vlimit(1)); */
  /*     else */
  /*         vr = int16(-vlimit(1)); */
  /*         vl = int16(vlimit(1)); */
  /*     end */
  /* else */
  /*         vr = int16(vlimit(2)); */
  /*         vl = int16(vlimit(2)); */
  /* end */
  /*  */
  /* return; */
  /*  ------------------------------------------------------------------------- */
  /* } */
}

/* Model step function */
void follower_qbot2_step(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator1;
  real_T rtb_Integrator1_e;
  real_T rtb_HILRead1_o1;
  real_T rtb_HILRead1_o2[2];
  real_T rtb_HILRead1_o4;
  real_T rtb_DataTypeConversion;
  real_T rtb_DataTypeConversion_e;
  real_T rtb_DataTypeConversion_m;
  real_T rtb_states;
  uint8_T rtb_StreamClient_o1;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_j;
  boolean_T rtb_LogicalOperator_l;
  boolean_T rtb_HILRead1_o3[3];
  real_T target_distance;
  real_T states;
  boolean_T rtb_Relation;
  real_T rtb_Sqrt;
  boolean_T rtb_Relation_h;
  boolean_T rtb_Relation_g;
  real_T rtb_Gain;
  int8_T rtAction;
  real_T rtb_ManualSwitchTrackingMethod;
  real_T rtb_Count_e;
  real_T rtb_Sum_idx_0;
  real_T rtb_Sum_idx_1;
  real_T rtb_Sum_p_idx_0;
  real_T rtb_Sum_p_idx_1;
  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    /* set solver stop time */
    if (!(follower_qbot2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&follower_qbot2_M->solverInfo,
                            ((follower_qbot2_M->Timing.clockTickH0 + 1) *
        follower_qbot2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&follower_qbot2_M->solverInfo,
                            ((follower_qbot2_M->Timing.clockTick0 + 1) *
        follower_qbot2_M->Timing.stepSize0 +
        follower_qbot2_M->Timing.clockTickH0 *
        follower_qbot2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(follower_qbot2_M)) {
    follower_qbot2_M->Timing.t[0] = rtsiGetT(&follower_qbot2_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(follower_qbot2_DW.EnabledMovingAverage_SubsysRa_e);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (follower_qbot2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(follower_qbot2_DW.SwitchCaseActionSubsystem1_Su_m);

  /* Reset subsysRan breadcrumbs */
  srClearBC(follower_qbot2_DW.SwitchCaseActionSubsystem2_Su_j);

  /* Reset subsysRan breadcrumbs */
  srClearBC(follower_qbot2_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(follower_qbot2_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(follower_qbot2_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    /* S-Function (stream_client_block): '<S1>/Stream Client' */

    /* S-Function Block: follower_qbot2/Data From Host/Stream Client (stream_client_block) */
    {
      t_pstream_state state;
      t_error receive_result;
      if (!follower_qbot2_DW.StreamClient_Connected) {
        qthread_attr_t receive_thread_attributes;
        struct qsched_param scheduling_parameters;
        int min_priority = qsched_get_priority_min(QSCHED_FIFO);
        int max_priority = qsched_get_priority_max(QSCHED_FIFO);
        t_pstream_options options;
        t_error result;
        result = 0;
        options.size = sizeof(options);
        options.flags = follower_qbot2_P.StreamClient_Endian &
          PSTREAM_FLAG_ENDIAN_MASK;
        if (follower_qbot2_P.StreamClient_Implementation ==
            STREAM_CLIENT_IMPLEMENTATION_THREAD) {
          options.flags |= PSTREAM_FLAG_MULTITHREADED;
        }

        if (follower_qbot2_P.StreamClient_Optimize ==
            STREAM_CLIENT_OPTIMIZE_LATENCY) {
          options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
        }

        options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
        options.send_unit_size = 1;
        options.num_send_units = 0;
        options.send_buffer_size = 0;
        options.send_fifo_size = 0;
        options.send_thread_attributes = NULL;
        options.num_send_dimensions = 0;
        options.max_send_dimensions = NULL;
        options.receive_unit_size = 8;
        options.num_receive_units = 4;
        options.receive_buffer_size = follower_qbot2_P.StreamClient_RcvSize;
        options.receive_fifo_size = follower_qbot2_P.StreamClient_RcvFIFO;
        options.num_receive_dimensions = 0;
        options.max_receive_dimensions = NULL;
        if (follower_qbot2_P.StreamClient_RcvPriority < min_priority) {
          scheduling_parameters.sched_priority = min_priority;
        } else if (follower_qbot2_P.StreamClient_RcvPriority > max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            follower_qbot2_P.StreamClient_RcvPriority;
        }

        qthread_attr_init(&receive_thread_attributes);
        result = qthread_attr_setschedpolicy(&receive_thread_attributes,
          QSCHED_FIFO);
        if (result == 0) {
          result = qthread_attr_setschedparam(&receive_thread_attributes,
            &scheduling_parameters);
          if (result == 0) {
            result = qthread_attr_setinheritsched(&receive_thread_attributes,
              QTHREAD_EXPLICIT_SCHED);
            if (result < 0) {
              rtmSetErrorStatus(follower_qbot2_M,
                                "Unable to set scheduling inheritance for Stream Client receiving thread");
            }
          } else {
            rtmSetErrorStatus(follower_qbot2_M,
                              "The specified thread priority for the Stream Client receiving thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(follower_qbot2_M,
                            "Unable to set scheduling policy for Stream Client receiving thread");
        }

        options.receive_thread_attributes = &receive_thread_attributes;
        if (result == 0) {
          /* Make sure URI is null-terminated */
          if (string_length((char *) follower_qbot2_P.StringConstant1_Value, 80)
              == 80) {
            rtmSetErrorStatus(follower_qbot2_M,
                              "URI passed to Stream Client block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = pstream_connect((char *)
              follower_qbot2_P.StringConstant1_Value, &options,
              &follower_qbot2_DW.StreamClient_Stream);
            if (result < 0 && result != -QERR_WOULD_BLOCK) {
              msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
                (_rt_error_message));
              rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
            }
          }
        }

        qthread_attr_destroy(&receive_thread_attributes);
        follower_qbot2_DW.StreamClient_Connected = true;
      }

      receive_result = pstream_receive(follower_qbot2_DW.StreamClient_Stream,
        &follower_qbot2_B.StreamClient_o3[0]);
      follower_qbot2_B.StreamClient_o4 = (receive_result > 0);
      follower_qbot2_B.StreamClient_o2 = 0;
      if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
        follower_qbot2_B.StreamClient_o2 = receive_result;
      }

      pstream_get_state(follower_qbot2_DW.StreamClient_Stream, &state);
      rtb_StreamClient_o1 = state;
    }

    /* RelationalOperator: '<S10>/Relation' incorporates:
     *  Constant: '<S3>/Signal Threshold'
     */
    rtb_Relation = (follower_qbot2_B.StreamClient_o3[3] <
                    follower_qbot2_P.SignalThreshold_Value);

    /* Logic: '<S10>/Logical Operator' */
    rtb_LogicalOperator = !rtb_Relation;

    /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator ||
        (follower_qbot2_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
      follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE =
        follower_qbot2_P.DiscreteTimeIntegrator_IC;
    }

    /* RelationalOperator: '<S10>/Relational Operator' incorporates:
     *  Constant: '<S3>/Timeout Threshold (s)'
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
     */
    follower_qbot2_B.RelationalOperator =
      (follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE >=
       follower_qbot2_P.TimeoutThresholds_Value);

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant'
     *  RelationalOperator: '<S8>/Compare'
     */
    follower_qbot2_B.DataTypeConversion = (rtb_StreamClient_o1 <=
      follower_qbot2_P.CompareToConstant_const);

    /* RelationalOperator: '<S11>/Relation' incorporates:
     *  Constant: '<S3>/Signal Threshold'
     */
    rtb_Relation_h = (follower_qbot2_B.DataTypeConversion <
                      follower_qbot2_P.SignalThreshold_Value);

    /* Logic: '<S11>/Logical Operator' */
    rtb_LogicalOperator_j = !rtb_Relation_h;

    /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_j ||
        (follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n != 0)) {
      follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l =
        follower_qbot2_P.DiscreteTimeIntegrator_IC_n;
    }

    /* RelationalOperator: '<S11>/Relational Operator' incorporates:
     *  Constant: '<S3>/Timeout Threshold (s)'
     *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
     */
    follower_qbot2_B.RelationalOperator_b =
      (follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l >=
       follower_qbot2_P.TimeoutThresholds_Value);

    /* S-Function (stream_client_block): '<S2>/Stream Client' */

    /* S-Function Block: follower_qbot2/Data From Leader/Stream Client (stream_client_block) */
    {
      t_pstream_state state;
      t_error receive_result;
      if (!follower_qbot2_DW.StreamClient_Connected_i) {
        qthread_attr_t receive_thread_attributes;
        struct qsched_param scheduling_parameters;
        int min_priority = qsched_get_priority_min(QSCHED_FIFO);
        int max_priority = qsched_get_priority_max(QSCHED_FIFO);
        t_pstream_options options;
        t_error result;
        result = 0;
        options.size = sizeof(options);
        options.flags = follower_qbot2_P.StreamClient_Endian_i &
          PSTREAM_FLAG_ENDIAN_MASK;
        if (follower_qbot2_P.StreamClient_Implementation_g ==
            STREAM_CLIENT_IMPLEMENTATION_THREAD) {
          options.flags |= PSTREAM_FLAG_MULTITHREADED;
        }

        if (follower_qbot2_P.StreamClient_Optimize_i ==
            STREAM_CLIENT_OPTIMIZE_LATENCY) {
          options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
        }

        options.flags |= PSTREAM_FLAG_RECEIVE_MOST_RECENT;
        options.send_unit_size = 1;
        options.num_send_units = 0;
        options.send_buffer_size = 0;
        options.send_fifo_size = 0;
        options.send_thread_attributes = NULL;
        options.num_send_dimensions = 0;
        options.max_send_dimensions = NULL;
        options.receive_unit_size = 8;
        options.num_receive_units = 3;
        options.receive_buffer_size = follower_qbot2_P.StreamClient_RcvSize_j;
        options.receive_fifo_size = follower_qbot2_P.StreamClient_RcvFIFO_h;
        options.num_receive_dimensions = 0;
        options.max_receive_dimensions = NULL;
        if (follower_qbot2_P.StreamClient_RcvPriority_p < min_priority) {
          scheduling_parameters.sched_priority = min_priority;
        } else if (follower_qbot2_P.StreamClient_RcvPriority_p > max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            follower_qbot2_P.StreamClient_RcvPriority_p;
        }

        qthread_attr_init(&receive_thread_attributes);
        result = qthread_attr_setschedpolicy(&receive_thread_attributes,
          QSCHED_FIFO);
        if (result == 0) {
          result = qthread_attr_setschedparam(&receive_thread_attributes,
            &scheduling_parameters);
          if (result == 0) {
            result = qthread_attr_setinheritsched(&receive_thread_attributes,
              QTHREAD_EXPLICIT_SCHED);
            if (result < 0) {
              rtmSetErrorStatus(follower_qbot2_M,
                                "Unable to set scheduling inheritance for Stream Client receiving thread");
            }
          } else {
            rtmSetErrorStatus(follower_qbot2_M,
                              "The specified thread priority for the Stream Client receiving thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(follower_qbot2_M,
                            "Unable to set scheduling policy for Stream Client receiving thread");
        }

        options.receive_thread_attributes = &receive_thread_attributes;
        if (result == 0) {
          /* Make sure URI is null-terminated */
          if (string_length((char *) follower_qbot2_P.StringConstant2_Value, 80)
              == 80) {
            rtmSetErrorStatus(follower_qbot2_M,
                              "URI passed to Stream Client block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = pstream_connect((char *)
              follower_qbot2_P.StringConstant2_Value, &options,
              &follower_qbot2_DW.StreamClient_Stream_o);
            if (result < 0 && result != -QERR_WOULD_BLOCK) {
              msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
                (_rt_error_message));
              rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
            }
          }
        }

        qthread_attr_destroy(&receive_thread_attributes);
        follower_qbot2_DW.StreamClient_Connected_i = true;
      }

      receive_result = pstream_receive(follower_qbot2_DW.StreamClient_Stream_o,
        &follower_qbot2_B.StreamClient_o3_f[0]);
      follower_qbot2_B.StreamClient_o4_d = (receive_result > 0);
      follower_qbot2_B.StreamClient_o2_i = 0;
      if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
        follower_qbot2_B.StreamClient_o2_i = receive_result;
      }

      pstream_get_state(follower_qbot2_DW.StreamClient_Stream_o, &state);
      rtb_StreamClient_o1 = state;
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Constant: '<S9>/Constant'
     *  RelationalOperator: '<S9>/Compare'
     */
    follower_qbot2_B.DataTypeConversion_n = (rtb_StreamClient_o1 <=
      follower_qbot2_P.CompareToConstant_const_k);

    /* RelationalOperator: '<S12>/Relation' incorporates:
     *  Constant: '<S3>/Signal Threshold'
     */
    rtb_Relation_g = (follower_qbot2_B.DataTypeConversion_n <
                      follower_qbot2_P.SignalThreshold_Value);

    /* Logic: '<S12>/Logical Operator' */
    rtb_LogicalOperator_l = !rtb_Relation_g;

    /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_l ||
        (follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
      follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_c =
        follower_qbot2_P.DiscreteTimeIntegrator_IC_c;
    }

    /* RelationalOperator: '<S12>/Relational Operator' incorporates:
     *  Constant: '<S3>/Timeout Threshold (s)'
     *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
     */
    follower_qbot2_B.RelationalOperator_l =
      (follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_c >=
       follower_qbot2_P.TimeoutThresholds_Value);

    /* Logic: '<S3>/Logical Operator1' */
    follower_qbot2_B.LogicalOperator1 = (follower_qbot2_B.RelationalOperator ||
      follower_qbot2_B.RelationalOperator_b ||
      follower_qbot2_B.RelationalOperator_l);

    /* Switch: '<S3>/Switch' incorporates:
     *  Memory: '<S3>/Memory'
     */
    if (follower_qbot2_B.DataTypeConversion_n >=
        follower_qbot2_P.Switch_Threshold) {
      follower_qbot2_B.Switch[0] = follower_qbot2_B.StreamClient_o3_f[0];
    } else {
      follower_qbot2_B.Switch[0] = follower_qbot2_DW.Memory_PreviousInput[0];
    }

    if (follower_qbot2_B.DataTypeConversion_n >=
        follower_qbot2_P.Switch_Threshold) {
      follower_qbot2_B.Switch[1] = follower_qbot2_B.StreamClient_o3_f[2];
    } else {
      follower_qbot2_B.Switch[1] = follower_qbot2_DW.Memory_PreviousInput[1];
    }

    if (follower_qbot2_B.DataTypeConversion_n >=
        follower_qbot2_P.Switch_Threshold) {
      follower_qbot2_B.Switch[2] = follower_qbot2_B.StreamClient_o3_f[1];
    } else {
      follower_qbot2_B.Switch[2] = follower_qbot2_DW.Memory_PreviousInput[2];
    }

    /* End of Switch: '<S3>/Switch' */

    /* Switch: '<S3>/Switch1' incorporates:
     *  Logic: '<S3>/Logical Operator'
     *  Memory: '<S3>/Memory1'
     */
    if ((follower_qbot2_B.StreamClient_o3[3] != 0.0) ||
        (follower_qbot2_B.DataTypeConversion != 0.0)) {
      follower_qbot2_B.Switch1[0] = follower_qbot2_B.StreamClient_o3[0];
      follower_qbot2_B.Switch1[1] = follower_qbot2_B.StreamClient_o3[1];
      follower_qbot2_B.Switch1[2] = follower_qbot2_B.StreamClient_o3[2];
    } else {
      follower_qbot2_B.Switch1[0] = follower_qbot2_DW.Memory1_PreviousInput[0];
      follower_qbot2_B.Switch1[1] = follower_qbot2_DW.Memory1_PreviousInput[1];
      follower_qbot2_B.Switch1[2] = follower_qbot2_DW.Memory1_PreviousInput[2];
    }

    /* End of Switch: '<S3>/Switch1' */

    /* Sum: '<S4>/Sum' */
    rtb_Sum_idx_0 = follower_qbot2_B.Switch1[0] - follower_qbot2_B.Switch[0];
    rtb_Sum_idx_1 = follower_qbot2_B.Switch1[2] - follower_qbot2_B.Switch[2];

    /* Sqrt: '<S15>/Sqrt' incorporates:
     *  DotProduct: '<S15>/Dot Product'
     */
    rtb_Sqrt = sqrt(rtb_Sum_idx_0 * rtb_Sum_idx_0 + rtb_Sum_idx_1 *
                    rtb_Sum_idx_1);

    /* Outputs for Atomic SubSystem: '<S4>/Bias Removal' */
    /* Step: '<S13>/Step: start_time' */
    if ((((follower_qbot2_M->Timing.clockTick1+
           follower_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002) <
        follower_qbot2_P.BiasRemoval_start_time) {
      rtb_Sum_p_idx_0 = follower_qbot2_P.Stepstart_time_Y0;
    } else {
      rtb_Sum_p_idx_0 = follower_qbot2_P.Stepstart_time_YFinal;
    }

    /* End of Step: '<S13>/Step: start_time' */

    /* Step: '<S13>/Step: end_time' */
    if ((((follower_qbot2_M->Timing.clockTick1+
           follower_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002) <
        follower_qbot2_P.BiasRemoval_end_time) {
      rtb_Sum_p_idx_1 = follower_qbot2_P.Stepend_time_Y0;
    } else {
      rtb_Sum_p_idx_1 = follower_qbot2_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S13>/Step: end_time' */

    /* Outputs for Enabled SubSystem: '<S13>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    /* Logic: '<S13>/Logical Operator' incorporates:
     *  Logic: '<S13>/Logical Operator1'
     */
    if ((rtb_Sum_p_idx_0 != 0.0) && (!(rtb_Sum_p_idx_1 != 0.0))) {
      if (!follower_qbot2_DW.EnabledMovingAverage_MODE_g) {
        /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
        follower_qbot2_DW.UnitDelay_DSTATE_e =
          follower_qbot2_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S17>/Sum( k=1,n-1, x(k) )' */
        follower_qbot2_DW.Sumk1n1xk_DSTATE_k[0] =
          follower_qbot2_P.Sumk1n1xk_InitialCondition;
        follower_qbot2_DW.Sumk1n1xk_DSTATE_k[1] =
          follower_qbot2_P.Sumk1n1xk_InitialCondition;
        follower_qbot2_DW.EnabledMovingAverage_MODE_g = true;
      }

      /* Sum: '<S21>/Count' incorporates:
       *  Constant: '<S21>/unity'
       *  UnitDelay: '<S21>/Unit Delay'
       */
      rtb_Count_e = follower_qbot2_P.unity_Value +
        follower_qbot2_DW.UnitDelay_DSTATE_e;

      /* Sum: '<S17>/Sum' incorporates:
       *  UnitDelay: '<S17>/Sum( k=1,n-1, x(k) )'
       */
      rtb_Sum_p_idx_0 = follower_qbot2_B.Switch[0] +
        follower_qbot2_DW.Sumk1n1xk_DSTATE_k[0];
      rtb_Sum_p_idx_1 = follower_qbot2_B.Switch[2] +
        follower_qbot2_DW.Sumk1n1xk_DSTATE_k[1];

      /* Product: '<S17>/div' */
      follower_qbot2_B.div_e[0] = rtb_Sum_p_idx_0 / rtb_Count_e;
      follower_qbot2_B.div_e[1] = rtb_Sum_p_idx_1 / rtb_Count_e;

      /* Update for UnitDelay: '<S21>/Unit Delay' */
      follower_qbot2_DW.UnitDelay_DSTATE_e = rtb_Count_e;

      /* Update for UnitDelay: '<S17>/Sum( k=1,n-1, x(k) )' */
      follower_qbot2_DW.Sumk1n1xk_DSTATE_k[0] = rtb_Sum_p_idx_0;
      follower_qbot2_DW.Sumk1n1xk_DSTATE_k[1] = rtb_Sum_p_idx_1;
      srUpdateBC(follower_qbot2_DW.EnabledMovingAverage_SubsysRa_e);
    } else {
      if (follower_qbot2_DW.EnabledMovingAverage_MODE_g) {
        follower_qbot2_DW.EnabledMovingAverage_MODE_g = false;
      }
    }

    /* End of Logic: '<S13>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S13>/Enabled Moving Average' */

    /* SwitchCase: '<S13>/Switch Case' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtAction = -1;
    if (follower_qbot2_P.BiasRemoval_switch_id < 0.0) {
      rtb_Sum_p_idx_0 = ceil(follower_qbot2_P.BiasRemoval_switch_id);
    } else {
      rtb_Sum_p_idx_0 = floor(follower_qbot2_P.BiasRemoval_switch_id);
    }

    if (rtIsNaN(rtb_Sum_p_idx_0) || rtIsInf(rtb_Sum_p_idx_0)) {
      rtb_Sum_p_idx_0 = 0.0;
    } else {
      rtb_Sum_p_idx_0 = fmod(rtb_Sum_p_idx_0, 4.294967296E+9);
    }

    switch (rtb_Sum_p_idx_0 < 0.0 ? -(int32_T)(uint32_T)-rtb_Sum_p_idx_0 :
            (int32_T)(uint32_T)rtb_Sum_p_idx_0) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    follower_qbot2_DW.SwitchCase_ActiveSubsystem_p = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S13>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      srUpdateBC(follower_qbot2_DW.SwitchCaseActionSubsystem1_Su_m);

      /* End of Outputs for SubSystem: '<S13>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S13>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      srUpdateBC(follower_qbot2_DW.SwitchCaseActionSubsystem2_Su_j);

      /* End of Outputs for SubSystem: '<S13>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S13>/Switch Case' */
    /* End of Outputs for SubSystem: '<S4>/Bias Removal' */

    /* Sum: '<S16>/Sum of Elements' incorporates:
     *  Math: '<S16>/Math Function'
     */
    rtb_Count_e = rtb_Sum_idx_0 * rtb_Sum_idx_0 + rtb_Sum_idx_1 * rtb_Sum_idx_1;

    /* Math: '<S16>/Math Function1'
     *
     * About '<S16>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Count_e < 0.0) {
      rtb_Count_e = -sqrt(fabs(rtb_Count_e));
    } else {
      rtb_Count_e = sqrt(rtb_Count_e);
    }

    /* End of Math: '<S16>/Math Function1' */

    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/Constant'
     *  Product: '<S16>/Product'
     */
    if (!(rtb_Count_e > follower_qbot2_P.NormalizeVector_maxzero)) {
      rtb_Sum_idx_0 *= 0.0;
      rtb_Sum_idx_1 *= 0.0;
      rtb_Count_e = follower_qbot2_P.Constant_Value;
    }

    /* End of Switch: '<S16>/Switch' */

    /* Switch: '<S4>/Switch - Arrived' incorporates:
     *  Constant: '<Root>/Following Distance (m)'
     *  Constant: '<S4>/Boundary Zone Limit (m)'
     *  Constant: '<S4>/Dummy Angle'
     *  Logic: '<S4>/Logical Operator'
     *  Product: '<S16>/Divide'
     *  Product: '<S4>/Product'
     *  RelationalOperator: '<S4>/Relational Operator'
     *  RelationalOperator: '<S4>/Relational Operator1'
     *  Sum: '<S4>/Sum1'
     *  Sum: '<S4>/Sum2'
     *  Sum: '<S4>/Sum3'
     *  Switch: '<S4>/Switch - Last Waypoint (Disabled)'
     */
    if ((rtb_Sqrt <= follower_qbot2_P.FollowingDistancem_Value +
         follower_qbot2_P.BoundaryZoneLimitm_Value) && (rtb_Sqrt >=
         follower_qbot2_P.FollowingDistancem_Value -
         follower_qbot2_P.BoundaryZoneLimitm_Value)) {
      follower_qbot2_B.SwitchArrived[0] = follower_qbot2_B.Switch1[0];
      follower_qbot2_B.SwitchArrived[1] = follower_qbot2_B.Switch1[1];
      follower_qbot2_B.SwitchArrived[2] = follower_qbot2_B.Switch1[2];
    } else {
      follower_qbot2_B.SwitchArrived[0] = rtb_Sum_idx_0 / rtb_Count_e *
        follower_qbot2_P.FollowingDistancem_Value + follower_qbot2_B.Switch[0];
      follower_qbot2_B.SwitchArrived[1] = follower_qbot2_P.DummyAngle_Value;
      follower_qbot2_B.SwitchArrived[2] = rtb_Sum_idx_1 / rtb_Count_e *
        follower_qbot2_P.FollowingDistancem_Value + follower_qbot2_B.Switch[2];
    }

    /* End of Switch: '<S4>/Switch - Arrived' */

    /* S-Function (hil_read_block): '<S26>/HIL Read1' */

    /* S-Function Block: follower_qbot2/QBot 2/QBot_Basic/QBot2_IO_Basic/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read(follower_qbot2_DW.HILInitialize_Card,
        &follower_qbot2_P.HILRead1_analog_channels, 1U,
        follower_qbot2_P.HILRead1_encoder_channels, 2U,
        follower_qbot2_P.HILRead1_digital_channels, 3U,
        &follower_qbot2_P.HILRead1_other_channels, 1U,
        &rtb_HILRead1_o1,
        &follower_qbot2_DW.HILRead1_EncoderBuffer[0],
                                (t_boolean *)&rtb_HILRead1_o3[0],
        &rtb_HILRead1_o4
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
      } else {
        rtb_HILRead1_o2[0] = follower_qbot2_DW.HILRead1_EncoderBuffer[0];
        rtb_HILRead1_o2[1] = follower_qbot2_DW.HILRead1_EncoderBuffer[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S23>/Bias Removal' */
    /* Step: '<S25>/Step: start_time' */
    if ((((follower_qbot2_M->Timing.clockTick1+
           follower_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002) <
        follower_qbot2_P.BiasRemoval_start_time_g) {
      rtb_Sum_p_idx_0 = follower_qbot2_P.Stepstart_time_Y0_g;
    } else {
      rtb_Sum_p_idx_0 = follower_qbot2_P.Stepstart_time_YFinal_p;
    }

    /* End of Step: '<S25>/Step: start_time' */

    /* Step: '<S25>/Step: end_time' */
    if ((((follower_qbot2_M->Timing.clockTick1+
           follower_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002) <
        follower_qbot2_P.BiasRemoval_end_time_a) {
      rtb_Sum_p_idx_1 = follower_qbot2_P.Stepend_time_Y0_g;
    } else {
      rtb_Sum_p_idx_1 = follower_qbot2_P.Stepend_time_YFinal_i;
    }

    /* End of Step: '<S25>/Step: end_time' */

    /* Outputs for Enabled SubSystem: '<S25>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S27>/Enable'
     */
    /* Logic: '<S25>/Logical Operator' incorporates:
     *  Logic: '<S25>/Logical Operator1'
     */
    if ((rtb_Sum_p_idx_0 != 0.0) && (!(rtb_Sum_p_idx_1 != 0.0))) {
      if (!follower_qbot2_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
        follower_qbot2_DW.UnitDelay_DSTATE =
          follower_qbot2_P.UnitDelay_InitialCondition_h;

        /* InitializeConditions for UnitDelay: '<S27>/Sum( k=1,n-1, x(k) )' */
        follower_qbot2_DW.Sumk1n1xk_DSTATE =
          follower_qbot2_P.Sumk1n1xk_InitialCondition_h;
        follower_qbot2_DW.EnabledMovingAverage_MODE = true;
      }

      /* Update for UnitDelay: '<S31>/Unit Delay' incorporates:
       *  Constant: '<S31>/unity'
       *  Sum: '<S31>/Count'
       *  UnitDelay: '<S31>/Unit Delay'
       */
      follower_qbot2_DW.UnitDelay_DSTATE += follower_qbot2_P.unity_Value_a;

      /* Update for UnitDelay: '<S27>/Sum( k=1,n-1, x(k) )' incorporates:
       *  Sum: '<S27>/Sum'
       *  UnitDelay: '<S27>/Sum( k=1,n-1, x(k) )'
       */
      follower_qbot2_DW.Sumk1n1xk_DSTATE += rtb_HILRead1_o4;
      srUpdateBC(follower_qbot2_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      if (follower_qbot2_DW.EnabledMovingAverage_MODE) {
        follower_qbot2_DW.EnabledMovingAverage_MODE = false;
      }
    }

    /* End of Logic: '<S25>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S25>/Enabled Moving Average' */

    /* SwitchCase: '<S25>/Switch Case' incorporates:
     *  Constant: '<S25>/Constant'
     */
    rtAction = -1;
    if (follower_qbot2_P.BiasRemoval_switch_id_m < 0.0) {
      rtb_Sum_p_idx_0 = ceil(follower_qbot2_P.BiasRemoval_switch_id_m);
    } else {
      rtb_Sum_p_idx_0 = floor(follower_qbot2_P.BiasRemoval_switch_id_m);
    }

    if (rtIsNaN(rtb_Sum_p_idx_0) || rtIsInf(rtb_Sum_p_idx_0)) {
      rtb_Sum_p_idx_0 = 0.0;
    } else {
      rtb_Sum_p_idx_0 = fmod(rtb_Sum_p_idx_0, 4.294967296E+9);
    }

    switch (rtb_Sum_p_idx_0 < 0.0 ? -(int32_T)(uint32_T)-rtb_Sum_p_idx_0 :
            (int32_T)(uint32_T)rtb_Sum_p_idx_0) {
     case 1:
      rtAction = 0;
      break;

     case 2:
      rtAction = 1;
      break;

     case 3:
      rtAction = 2;
      break;
    }

    follower_qbot2_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S25>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      srUpdateBC(follower_qbot2_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S25>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S25>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      srUpdateBC(follower_qbot2_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S25>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S25>/Switch Case' */
    /* End of Outputs for SubSystem: '<S23>/Bias Removal' */

    /* Constant: '<S33>/x0' */
    follower_qbot2_B.x0 = follower_qbot2_P.x0_Value;
  }

  /* Integrator: '<S33>/Integrator1' */
  if (follower_qbot2_DW.Integrator1_IWORK.IcNeedsLoading) {
    follower_qbot2_X.Integrator1_CSTATE = follower_qbot2_B.x0;
  }

  rtb_Integrator1 = follower_qbot2_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    /* ManualSwitch: '<Root>/Manual Switch - QBot 2 Enable' incorporates:
     *  Constant: '<Root>/Disable'
     *  Constant: '<Root>/Enable'
     */
    if (follower_qbot2_P.ManualSwitchQBot2Enable_Current == 1) {
      follower_qbot2_B.ManualSwitchQBot2Enable = follower_qbot2_P.Enable_Value;
    } else {
      follower_qbot2_B.ManualSwitchQBot2Enable = follower_qbot2_P.Disable_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch - QBot 2 Enable' */
  }

  /* Product: '<Root>/Product' */
  rtb_Sum_p_idx_1 = rtb_Integrator1 * follower_qbot2_B.ManualSwitchQBot2Enable *
    follower_qbot2_B.StreamClient_o3[3];

  /* RateLimiter: '<S5>/Rate Limiter - Linear Speed' */
  if (follower_qbot2_DW.LastMajorTime == (rtInf)) {
    follower_qbot2_B.RateLimiterLinearSpeed = rtb_Sum_p_idx_1;
  } else {
    rtb_Count_e = follower_qbot2_M->Timing.t[0] -
      follower_qbot2_DW.LastMajorTime;
    rtb_Sqrt = rtb_Count_e * follower_qbot2_P.RateLimiterLinearSpeed_RisingLi;
    rtb_Sum_p_idx_0 = rtb_Sum_p_idx_1 - follower_qbot2_DW.PrevY;
    if (rtb_Sum_p_idx_0 > rtb_Sqrt) {
      follower_qbot2_B.RateLimiterLinearSpeed = follower_qbot2_DW.PrevY +
        rtb_Sqrt;
    } else {
      rtb_Count_e *= follower_qbot2_P.RateLimiterLinearSpeed_FallingL;
      if (rtb_Sum_p_idx_0 < rtb_Count_e) {
        follower_qbot2_B.RateLimiterLinearSpeed = follower_qbot2_DW.PrevY +
          rtb_Count_e;
      } else {
        follower_qbot2_B.RateLimiterLinearSpeed = rtb_Sum_p_idx_1;
      }
    }
  }

  /* End of RateLimiter: '<S5>/Rate Limiter - Linear Speed' */
  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    /* Constant: '<S34>/x0' */
    follower_qbot2_B.x0_l = follower_qbot2_P.x0_Value_n;
  }

  /* Integrator: '<S34>/Integrator1' */
  if (follower_qbot2_DW.Integrator1_IWORK_p.IcNeedsLoading) {
    follower_qbot2_X.Integrator1_CSTATE_l = follower_qbot2_B.x0_l;
  }

  rtb_Integrator1_e = follower_qbot2_X.Integrator1_CSTATE_l;

  /* Product: '<Root>/Product1' */
  rtb_Sum_p_idx_1 = rtb_Integrator1_e * follower_qbot2_B.ManualSwitchQBot2Enable
    * follower_qbot2_B.StreamClient_o3[3];

  /* RateLimiter: '<S5>/Rate Limiter - Rotation Rate' */
  if (follower_qbot2_DW.LastMajorTime_c == (rtInf)) {
    follower_qbot2_B.RateLimiterRotationRate = rtb_Sum_p_idx_1;
  } else {
    rtb_Count_e = follower_qbot2_M->Timing.t[0] -
      follower_qbot2_DW.LastMajorTime_c;
    rtb_Sqrt = rtb_Count_e * follower_qbot2_P.RateLimiterRotationRate_RisingL;
    rtb_Sum_p_idx_0 = rtb_Sum_p_idx_1 - follower_qbot2_DW.PrevY_o;
    if (rtb_Sum_p_idx_0 > rtb_Sqrt) {
      follower_qbot2_B.RateLimiterRotationRate = follower_qbot2_DW.PrevY_o +
        rtb_Sqrt;
    } else {
      rtb_Count_e *= follower_qbot2_P.RateLimiterRotationRate_Falling;
      if (rtb_Sum_p_idx_0 < rtb_Count_e) {
        follower_qbot2_B.RateLimiterRotationRate = follower_qbot2_DW.PrevY_o +
          rtb_Count_e;
      } else {
        follower_qbot2_B.RateLimiterRotationRate = rtb_Sum_p_idx_1;
      }
    }
  }

  /* End of RateLimiter: '<S5>/Rate Limiter - Rotation Rate' */

  /* MATLAB Function: '<S24>/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)' */
  /* MATLAB Function 'QBot 2/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity  into Left and Right Wheel Vellocity)/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)': '<S32>:1' */
  /*  Eqn Based on the eqn 4.52 (W is the angular velocity) */
  /* '<S32>:1:7' */
  follower_qbot2_B.vR = follower_qbot2_B.RateLimiterRotationRate * 0.235 / 2.0 +
    follower_qbot2_B.RateLimiterLinearSpeed;

  /* '<S32>:1:8' */
  follower_qbot2_B.vL = follower_qbot2_B.RateLimiterLinearSpeed -
    follower_qbot2_B.RateLimiterRotationRate * 0.235 / 2.0;
  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    /* S-Function (hil_write_block): '<S26>/HIL Write' */

    /* S-Function Block: follower_qbot2/QBot 2/QBot_Basic/QBot2_IO_Basic/HIL Write (hil_write_block) */
    {
      t_error result;
      follower_qbot2_DW.HILWrite_OtherBuffer[0] = follower_qbot2_B.vR;
      follower_qbot2_DW.HILWrite_OtherBuffer[1] = follower_qbot2_B.vL;
      result = hil_write(follower_qbot2_DW.HILInitialize_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         follower_qbot2_P.HILWrite_other_channels, 2U,
                         NULL,
                         NULL,
                         NULL,
                         &follower_qbot2_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
      }
    }

    /* DataTypeConversion: '<S10>/Data Type Conversion' */
    rtb_DataTypeConversion = rtb_Relation;

    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    rtb_DataTypeConversion_e = rtb_Relation_h;

    /* DataTypeConversion: '<S12>/Data Type Conversion' */
    rtb_DataTypeConversion_m = rtb_Relation_g;

    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/V Limit2'
     */
    rtb_Gain = follower_qbot2_P.Gain_Gain * follower_qbot2_P.VLimit2_Value;

    /* ManualSwitch: '<Root>/Manual Switch - Tracking Method' incorporates:
     *  Constant: '<Root>/Sequential'
     *  Constant: '<Root>/Simultaneous'
     */
    if (follower_qbot2_P.ManualSwitchTrackingMethod_Curr == 1) {
      rtb_ManualSwitchTrackingMethod = follower_qbot2_P.Sequential_Value;
    } else {
      rtb_ManualSwitchTrackingMethod = follower_qbot2_P.Simultaneous_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch - Tracking Method' */
  }

  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    /* MATLAB Function: '<S35>/Way Point Control' incorporates:
     *  Constant: '<Root>/V Limit'
     *  Constant: '<Root>/V Limit1'
     *  Constant: '<S7>/Kv_1'
     *  Constant: '<S7>/Kv_2'
     *  Constant: '<S7>/Kv_3'
     *  Constant: '<S7>/Kv_4'
     *  Constant: '<S7>/Waypoint Step'
     *  Memory: '<S35>/Memory'
     *  SignalConversion: '<S36>/TmpSignal ConversionAt SFunction Inport1'
     *  SignalConversion: '<S36>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'Waypoint Controller/Trajectory control (Way-points)/Way Point Control': '<S36>:1' */
    /*  Initialize output variables */
    /* '<S36>:1:7' */
    follower_qbot2_B.Vf = 0.0;

    /* '<S36>:1:8' */
    follower_qbot2_B.W = 0.0;

    /* '<S36>:1:19' */
    states = follower_qbot2_DW.Memory_PreviousInput_e;

    /* '<S36>:1:23' */
    /* '<S36>:1:24' */
    /* '<S36>:1:25' */
    /* -------------------------------------------------------------------------- */
    /* '<S36>:1:105' */
    rtb_Sqrt = follower_qbot2_B.Switch1[1];
    if (follower_qbot2_B.Switch1[1] > 3.1415926535897931) {
      /* '<S36>:1:106' */
      /* '<S36>:1:107' */
      rtb_Sqrt = follower_qbot2_B.Switch1[1] - 6.2831853071795862;
    } else {
      if (follower_qbot2_B.Switch1[1] < -3.1415926535897931) {
        /* '<S36>:1:108' */
        /* '<S36>:1:109' */
        rtb_Sqrt = follower_qbot2_B.Switch1[1] + 6.2831853071795862;
      }
    }

    /* '<S36>:1:26' */
    rtb_Sum_idx_0 = follower_qbot2_B.Switch1[2];
    rtb_Sum_idx_1 = follower_qbot2_B.Switch1[0];

    /* '<S36>:1:27' */
    /* '<S36>:1:32' */
    if (follower_qbot2_DW.Memory_PreviousInput_e == 1.0) {
      /* '<S36>:1:33' */
      /* '<S36>:1:34' */
      /* '<S36>:1:35' */
      rtb_Sum_idx_0 = follower_qbot2_B.SwitchArrived[2];

      /* '<S36>:1:34' */
      /* '<S36>:1:35' */
      rtb_Sum_idx_1 = follower_qbot2_B.SwitchArrived[0];

      /* '<S36>:1:34' */
    }

    /* '<S36>:1:41' */
    /* '<S36>:1:42' */
    /* '<S36>:1:43' */
    /*  ------------------------------------------------------------------------- */
    /* '<S36>:1:114' */
    rtb_Count_e = follower_qbot2_B.Switch1[2] - rtb_Sum_idx_0;
    rtb_Sum_p_idx_1 = follower_qbot2_B.Switch1[0] - rtb_Sum_idx_1;
    target_distance = sqrt(rtb_Count_e * rtb_Count_e + rtb_Sum_p_idx_1 *
      rtb_Sum_p_idx_1);

    /* '<S36>:1:44' */
    /*  ------------------------------------------------------------------------- */
    /* '<S36>:1:119' */
    /* '<S36>:1:120' */
    /* '<S36>:1:121' */
    rtb_Sum_p_idx_0 = rt_atan2d_snf(rtb_Sum_idx_1 - follower_qbot2_B.Switch1[0],
      rtb_Sum_idx_0 - follower_qbot2_B.Switch1[2]);

    /* '<S36>:1:122' */
    /* -------------------------------------------------------------------------- */
    /* '<S36>:1:105' */
    if (rtb_Sum_p_idx_0 > 3.1415926535897931) {
      /* '<S36>:1:106' */
      /* '<S36>:1:107' */
      rtb_Sum_p_idx_0 -= 6.2831853071795862;
    } else {
      if (rtb_Sum_p_idx_0 < -3.1415926535897931) {
        /* '<S36>:1:108' */
        /* '<S36>:1:109' */
        rtb_Sum_p_idx_0 += 6.2831853071795862;
      }
    }

    /* -------------------------------------------------------------------------- */
    /* '<S36>:1:105' */
    rtb_Count_e = rtb_Sqrt;
    if (rtb_Sqrt > 3.1415926535897931) {
      /* '<S36>:1:106' */
      /* '<S36>:1:107' */
      rtb_Count_e = rtb_Sqrt - 6.2831853071795862;
    } else {
      if (rtb_Sqrt < -3.1415926535897931) {
        /* '<S36>:1:108' */
        /* '<S36>:1:109' */
        rtb_Count_e = rtb_Sqrt + 6.2831853071795862;
      }
    }

    rtb_Sum_p_idx_0 -= rtb_Count_e;

    /* -------------------------------------------------------------------------- */
    /* '<S36>:1:105' */
    if (rtb_Sum_p_idx_0 > 3.1415926535897931) {
      /* '<S36>:1:106' */
      /* '<S36>:1:107' */
      rtb_Sum_p_idx_0 -= 6.2831853071795862;
    } else {
      if (rtb_Sum_p_idx_0 < -3.1415926535897931) {
        /* '<S36>:1:108' */
        /* '<S36>:1:109' */
        rtb_Sum_p_idx_0 += 6.2831853071795862;
      }
    }

    if ((follower_qbot2_DW.Memory_PreviousInput_e == 1.0) && (target_distance <=
         follower_qbot2_P.VLimit1_Value)) {
      /* '<S36>:1:46' */
      /* || states(1) == -1 */
      /*  %        states(1) = -1; */
      /*  right_vel = int16(0); */
      /*  left_vel = int16(0); */
      /*   %       target_distance = 0; */
      /* '<S36>:1:51' */
      follower_qbot2_B.Vf = 0.0;

      /* '<S36>:1:52' */
      follower_qbot2_B.W = 0.0;
      if ((follower_qbot2_DW.end_flag == 1.0) && (target_distance <=
           follower_qbot2_P.VLimit1_Value)) {
        /* '<S36>:1:54' */
        /*  after all waypoints, psi will be adjusted to psi_d  */
        /* -------------------------------------------------------------------------- */
        /* '<S36>:1:105' */
        rtb_Count_e = follower_qbot2_B.SwitchArrived[1];
        if (follower_qbot2_B.SwitchArrived[1] > 3.1415926535897931) {
          /* '<S36>:1:106' */
          /* '<S36>:1:107' */
          rtb_Count_e = follower_qbot2_B.SwitchArrived[1] - 6.2831853071795862;
        } else {
          if (follower_qbot2_B.SwitchArrived[1] < -3.1415926535897931) {
            /* '<S36>:1:108' */
            /* '<S36>:1:109' */
            rtb_Count_e = follower_qbot2_B.SwitchArrived[1] + 6.2831853071795862;
          }
        }

        /* -------------------------------------------------------------------------- */
        /* '<S36>:1:105' */
        if (rtb_Sqrt > 3.1415926535897931) {
          /* '<S36>:1:106' */
          /* '<S36>:1:107' */
          rtb_Sqrt -= 6.2831853071795862;
        } else {
          if (rtb_Sqrt < -3.1415926535897931) {
            /* '<S36>:1:108' */
            /* '<S36>:1:109' */
            rtb_Sqrt += 6.2831853071795862;
          }
        }

        rtb_Count_e -= rtb_Sqrt;

        /* -------------------------------------------------------------------------- */
        /* '<S36>:1:105' */
        if (rtb_Count_e > 3.1415926535897931) {
          /* '<S36>:1:106' */
          /* '<S36>:1:107' */
          rtb_Count_e -= 6.2831853071795862;
        } else {
          if (rtb_Count_e < -3.1415926535897931) {
            /* '<S36>:1:108' */
            /* '<S36>:1:109' */
            rtb_Count_e += 6.2831853071795862;
          }
        }

        follower__ClosedLoop_Sequential(0.0, rtb_Count_e,
          follower_qbot2_P.VLimit_Value, rtb_Gain, follower_qbot2_P.Kv_1_Value,
          follower_qbot2_P.Kv_2_Value, follower_qbot2_DW.Vf_1, &rtb_Sum_p_idx_1,
          &rtb_Sqrt);

        /* '<S36>:1:55' */
        follower_qbot2_B.Vf = rtb_Sum_p_idx_1;

        /* '<S36>:1:55' */
        follower_qbot2_B.W = rtb_Sqrt;

        /* '<S36>:1:56' */
        follower_qbot2_DW.Vf_1 = rtb_Sum_p_idx_1;
      }
    } else if ((target_distance <= follower_qbot2_P.VLimit1_Value) &&
               (follower_qbot2_DW.end_flag == 0.0)) {
      /* '<S36>:1:62' */
      /* '<S36>:1:63' */
      states = follower_qbot2_DW.Memory_PreviousInput_e +
        follower_qbot2_P.WaypointStep_Value;

      /* 1; */
      if (follower_qbot2_DW.Memory_PreviousInput_e > 0.0) {
        /* '<S36>:1:65' */
        while ((fabs(follower_qbot2_B.SwitchArrived[2] -
                     follower_qbot2_B.SwitchArrived[2]) < 2.0 *
                follower_qbot2_P.VLimit1_Value) && (fabs
                (follower_qbot2_B.SwitchArrived[0] -
                 follower_qbot2_B.SwitchArrived[0]) < 2.0 *
                follower_qbot2_P.VLimit1_Value)) {
          /* '<S36>:1:66' */
          if (states <= 1.0 - follower_qbot2_P.WaypointStep_Value) {
            /* '<S36>:1:67' */
            /* '<S36>:1:68' */
            states += follower_qbot2_P.WaypointStep_Value;

            /* 1; */
          } else {
            /* '<S36>:1:70' */
            states = 1.0;
          }
        }
      } else {
        /* '<S36>:1:74' */
        states += follower_qbot2_P.WaypointStep_Value;

        /* 1; */
      }

      if (states >= 1.0) {
        /* '<S36>:1:77' */
        /* '<S36>:1:78' */
        states = 1.0;

        /* '<S36>:1:79' */
        follower_qbot2_DW.end_flag = 1.0;
      }

      /*   elseif (end_flag == 1) && (target_distance <= dist_thr) % after all waypoints, psi will be adjusted to psi_d  */
      /*           [Vf, W] = ClosedLoop_Sequential(0, check_angle(check_angle(Psi_d)-check_angle(rtheta)), vlimit, ang_thr, dist_thr, Kv_1, Kw_1, Vf_1);  */
      /*            Vf_1=Vf; */
    } else if (rtb_ManualSwitchTrackingMethod == 2.0) {
      /* '<S36>:1:89' */
      /*  ------------------------------------------------------------------------- */
      /* '<S36>:1:131' */
      rtb_Sqrt = 2.0 * follower_qbot2_P.VLimit_Value;

      /* '<S36>:1:132' */
      rtb_Sum_p_idx_1 = follower_qbot2_P.Kv_4_Value * rtb_Sum_p_idx_0;

      /* if abs(theta)<pi */
      /* '<S36>:1:135' */
      rtb_Count_e = follower_qbot2_P.Kv_3_Value * target_distance;

      /* else */
      /*     Vf=0; */
      /* end */
      /* '<S36>:1:140' */
      if (fabs(rtb_Sum_p_idx_1) > rtb_Sqrt) {
        /* '<S36>:1:141' */
        /* '<S36>:1:142' */
        if (rtb_Sum_p_idx_1 < 0.0) {
          rtb_Sum_p_idx_1 = -1.0;
        } else if (rtb_Sum_p_idx_1 > 0.0) {
          rtb_Sum_p_idx_1 = 1.0;
        } else {
          if (rtb_Sum_p_idx_1 == 0.0) {
            rtb_Sum_p_idx_1 = 0.0;
          }
        }

        rtb_Sum_p_idx_1 *= rtb_Sqrt;
      }

      if (fabs(rtb_Count_e) > follower_qbot2_P.VLimit_Value) {
        /* '<S36>:1:144' */
        /* '<S36>:1:145' */
        rtb_Count_e = fabs(rtb_Count_e) * follower_qbot2_P.VLimit_Value;
      }

      /* '<S36>:1:90' */
      follower_qbot2_B.Vf = rtb_Count_e;

      /* '<S36>:1:90' */
      follower_qbot2_B.W = rtb_Sum_p_idx_1;
    } else {
      /*             [right_vel, left_vel] = rotate_and_go(ang_to_tar, vlimit, ang_thr); */
      follower__ClosedLoop_Sequential(target_distance, rtb_Sum_p_idx_0,
        follower_qbot2_P.VLimit_Value, rtb_Gain, follower_qbot2_P.Kv_1_Value,
        follower_qbot2_P.Kv_2_Value, follower_qbot2_DW.Vf_1, &rtb_Count_e,
        &rtb_Sum_p_idx_1);

      /* '<S36>:1:93' */
      follower_qbot2_B.Vf = rtb_Count_e;

      /* '<S36>:1:93' */
      follower_qbot2_B.W = rtb_Sum_p_idx_1;

      /* '<S36>:1:94' */
      follower_qbot2_DW.Vf_1 = rtb_Count_e;
    }

    rtb_states = states;

    /* End of MATLAB Function: '<S35>/Way Point Control' */
  }

  /* Product: '<S33>/Product' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/wn'
   *  Constant: '<S33>/zt'
   *  Integrator: '<S33>/Integrator2'
   *  Product: '<S33>/Product2'
   *  Sum: '<S33>/Sum'
   *  Sum: '<S33>/Sum1'
   */
  follower_qbot2_B.Product = ((follower_qbot2_B.Vf - rtb_Integrator1) -
    follower_qbot2_X.Integrator2_CSTATE * follower_qbot2_P.Constant_Value_d *
    follower_qbot2_P.SecondOrderLowPassFilter1_inp_f) *
    follower_qbot2_P.SecondOrderLowPassFilter1_input;

  /* Product: '<S33>/Product1' incorporates:
   *  Constant: '<S33>/wn'
   *  Integrator: '<S33>/Integrator2'
   */
  follower_qbot2_B.Product1 = follower_qbot2_P.SecondOrderLowPassFilter1_input *
    follower_qbot2_X.Integrator2_CSTATE;

  /* Product: '<S34>/Product' incorporates:
   *  Constant: '<S34>/Constant'
   *  Constant: '<S34>/wn'
   *  Constant: '<S34>/zt'
   *  Integrator: '<S34>/Integrator2'
   *  Product: '<S34>/Product2'
   *  Sum: '<S34>/Sum'
   *  Sum: '<S34>/Sum1'
   */
  follower_qbot2_B.Product_k = ((follower_qbot2_B.W - rtb_Integrator1_e) -
    follower_qbot2_X.Integrator2_CSTATE_e * follower_qbot2_P.Constant_Value_l *
    follower_qbot2_P.SecondOrderLowPassFilter4_inp_i) *
    follower_qbot2_P.SecondOrderLowPassFilter4_input;

  /* Product: '<S34>/Product1' incorporates:
   *  Constant: '<S34>/wn'
   *  Integrator: '<S34>/Integrator2'
   */
  follower_qbot2_B.Product1_j = follower_qbot2_P.SecondOrderLowPassFilter4_input
    * follower_qbot2_X.Integrator2_CSTATE_e;
  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    if (rtmIsMajorTimeStep(follower_qbot2_M)) {
      /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
      if (!rtb_LogicalOperator) {
        follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE +=
          follower_qbot2_P.DiscreteTimeIntegrator_gainval *
          rtb_DataTypeConversion;
      }

      if (rtb_LogicalOperator) {
        follower_qbot2_DW.DiscreteTimeIntegrator_PrevRese = 1;
      } else {
        follower_qbot2_DW.DiscreteTimeIntegrator_PrevRese = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
      if (!rtb_LogicalOperator_j) {
        follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l +=
          follower_qbot2_P.DiscreteTimeIntegrator_gainva_d *
          rtb_DataTypeConversion_e;
      }

      if (rtb_LogicalOperator_j) {
        follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n = 1;
      } else {
        follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
      if (!rtb_LogicalOperator_l) {
        follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_c +=
          follower_qbot2_P.DiscreteTimeIntegrator_gainva_e *
          rtb_DataTypeConversion_m;
      }

      if (rtb_LogicalOperator_l) {
        follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_g = 1;
      } else {
        follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_g = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

      /* Update for Memory: '<S3>/Memory' */
      follower_qbot2_DW.Memory_PreviousInput[0] = follower_qbot2_B.Switch[0];
      follower_qbot2_DW.Memory_PreviousInput[1] = follower_qbot2_B.Switch[1];
      follower_qbot2_DW.Memory_PreviousInput[2] = follower_qbot2_B.Switch[2];

      /* Update for Memory: '<S3>/Memory1' */
      follower_qbot2_DW.Memory1_PreviousInput[0] = follower_qbot2_B.Switch1[0];
      follower_qbot2_DW.Memory1_PreviousInput[1] = follower_qbot2_B.Switch1[1];
      follower_qbot2_DW.Memory1_PreviousInput[2] = follower_qbot2_B.Switch1[2];
    }

    /* Update for Integrator: '<S33>/Integrator1' */
    follower_qbot2_DW.Integrator1_IWORK.IcNeedsLoading = 0;

    /* Update for RateLimiter: '<S5>/Rate Limiter - Linear Speed' */
    follower_qbot2_DW.PrevY = follower_qbot2_B.RateLimiterLinearSpeed;
    follower_qbot2_DW.LastMajorTime = follower_qbot2_M->Timing.t[0];

    /* Update for Integrator: '<S34>/Integrator1' */
    follower_qbot2_DW.Integrator1_IWORK_p.IcNeedsLoading = 0;

    /* Update for RateLimiter: '<S5>/Rate Limiter - Rotation Rate' */
    follower_qbot2_DW.PrevY_o = follower_qbot2_B.RateLimiterRotationRate;
    follower_qbot2_DW.LastMajorTime_c = follower_qbot2_M->Timing.t[0];
    if (rtmIsMajorTimeStep(follower_qbot2_M)) {
      /* Update for Memory: '<S35>/Memory' */
      follower_qbot2_DW.Memory_PreviousInput_e = rtb_states;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, follower_qbot2_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(follower_qbot2_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((follower_qbot2_M->Timing.clockTick1+
                            follower_qbot2_M->Timing.clockTickH1* 4294967296.0))
                          * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(follower_qbot2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(follower_qbot2_M)!=-1) &&
          !((rtmGetTFinal(follower_qbot2_M)-
             (((follower_qbot2_M->Timing.clockTick1+
                follower_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((follower_qbot2_M->Timing.clockTick1+
               follower_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(follower_qbot2_M, "Simulation finished");
      }

      if (rtmGetStopRequested(follower_qbot2_M)) {
        rtmSetErrorStatus(follower_qbot2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&follower_qbot2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++follower_qbot2_M->Timing.clockTick0)) {
      ++follower_qbot2_M->Timing.clockTickH0;
    }

    follower_qbot2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&follower_qbot2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      follower_qbot2_M->Timing.clockTick1++;
      if (!follower_qbot2_M->Timing.clockTick1) {
        follower_qbot2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void follower_qbot2_derivatives(void)
{
  XDot_follower_qbot2_T *_rtXdot;
  _rtXdot = ((XDot_follower_qbot2_T *) follower_qbot2_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S33>/Integrator1' */
  {
    ((XDot_follower_qbot2_T *) follower_qbot2_M->ModelData.derivs)
      ->Integrator1_CSTATE = follower_qbot2_B.Product1;
  }

  /* Derivatives for Integrator: '<S34>/Integrator1' */
  {
    ((XDot_follower_qbot2_T *) follower_qbot2_M->ModelData.derivs)
      ->Integrator1_CSTATE_l = follower_qbot2_B.Product1_j;
  }

  /* Derivatives for Integrator: '<S33>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = follower_qbot2_B.Product;

  /* Derivatives for Integrator: '<S34>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e = follower_qbot2_B.Product_k;
}

/* Model initialize function */
void follower_qbot2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)follower_qbot2_M, 0,
                sizeof(RT_MODEL_follower_qbot2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&follower_qbot2_M->solverInfo,
                          &follower_qbot2_M->Timing.simTimeStep);
    rtsiSetTPtr(&follower_qbot2_M->solverInfo, &rtmGetTPtr(follower_qbot2_M));
    rtsiSetStepSizePtr(&follower_qbot2_M->solverInfo,
                       &follower_qbot2_M->Timing.stepSize0);
    rtsiSetdXPtr(&follower_qbot2_M->solverInfo,
                 &follower_qbot2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&follower_qbot2_M->solverInfo, (real_T **)
                         &follower_qbot2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&follower_qbot2_M->solverInfo,
      &follower_qbot2_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&follower_qbot2_M->solverInfo, (&rtmGetErrorStatus
      (follower_qbot2_M)));
    rtsiSetRTModelPtr(&follower_qbot2_M->solverInfo, follower_qbot2_M);
  }

  rtsiSetSimTimeStep(&follower_qbot2_M->solverInfo, MAJOR_TIME_STEP);
  follower_qbot2_M->ModelData.intgData.f[0] = follower_qbot2_M->ModelData.odeF[0];
  follower_qbot2_M->ModelData.contStates = ((X_follower_qbot2_T *)
    &follower_qbot2_X);
  rtsiSetSolverData(&follower_qbot2_M->solverInfo, (void *)
                    &follower_qbot2_M->ModelData.intgData);
  rtsiSetSolverName(&follower_qbot2_M->solverInfo,"ode1");
  rtmSetTPtr(follower_qbot2_M, &follower_qbot2_M->Timing.tArray[0]);
  rtmSetTFinal(follower_qbot2_M, -1);
  follower_qbot2_M->Timing.stepSize0 = 0.002;
  rtmSetFirstInitCond(follower_qbot2_M, 1);

  /* External mode info */
  follower_qbot2_M->Sizes.checksums[0] = (2184415200U);
  follower_qbot2_M->Sizes.checksums[1] = (3183646196U);
  follower_qbot2_M->Sizes.checksums[2] = (4164270047U);
  follower_qbot2_M->Sizes.checksums[3] = (2946492325U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    follower_qbot2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &follower_qbot2_DW.EnabledMovingAverage_SubsysRa_e;
    systemRan[3] = (sysRanDType *)
      &follower_qbot2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy;
    systemRan[4] = (sysRanDType *)
      &follower_qbot2_DW.SwitchCaseActionSubsystem1_Su_m;
    systemRan[5] = (sysRanDType *)
      &follower_qbot2_DW.SwitchCaseActionSubsystem2_Su_j;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &follower_qbot2_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[9] = (sysRanDType *)
      &follower_qbot2_DW.SwitchCaseActionSubsystem_a.SwitchCaseActionSubsystem_Subsy;
    systemRan[10] = (sysRanDType *)
      &follower_qbot2_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[11] = (sysRanDType *)
      &follower_qbot2_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(follower_qbot2_M->extModeInfo,
      &follower_qbot2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(follower_qbot2_M->extModeInfo,
                        follower_qbot2_M->Sizes.checksums);
    rteiSetTPtr(follower_qbot2_M->extModeInfo, rtmGetTPtr(follower_qbot2_M));
  }

  /* block I/O */
  (void) memset(((void *) &follower_qbot2_B), 0,
                sizeof(B_follower_qbot2_T));

  /* states (continuous) */
  {
    (void) memset((void *)&follower_qbot2_X, 0,
                  sizeof(X_follower_qbot2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&follower_qbot2_DW, 0,
                sizeof(DW_follower_qbot2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    follower_qbot2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: follower_qbot2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qbot2", "0", &follower_qbot2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(follower_qbot2_DW.HILInitialize_Card,
      "enc0_dir=0;enc0_filter=1;enc0_a=0;enc0_b=0;enc0_z=1;enc0_reload=0;enc1_dir=0;enc1_filter=1;enc1_a=0;enc1_b=0;enc1_z=1;enc1_reload=0;pwm0_immediate=0;pwm1_immediate=0;pwm2_immediate=0;pwm3_immediate=0;",
      201);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(follower_qbot2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
      return;
    }

    if ((follower_qbot2_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_analog_inpu_g && is_switching)) {
      {
        int_T i1;
        const real_T *p_HILInitialize_analog_input_mini =
          follower_qbot2_P.HILInitialize_analog_input_mini;
        real_T *dw_AIMinimums = &follower_qbot2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = p_HILInitialize_analog_input_mini[i1];
        }
      }

      follower_qbot2_DW.HILInitialize_AIMinimums[8] =
        follower_qbot2_P.HILInitialize_analog_input_mini[8];
      follower_qbot2_DW.HILInitialize_AIMinimums[9] =
        follower_qbot2_P.HILInitialize_analog_input_mini[8];

      {
        int_T i1;
        const real_T *p_HILInitialize_analog_input_maxi =
          follower_qbot2_P.HILInitialize_analog_input_maxi;
        real_T *dw_AIMaximums = &follower_qbot2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = p_HILInitialize_analog_input_maxi[i1];
        }
      }

      follower_qbot2_DW.HILInitialize_AIMaximums[8] =
        follower_qbot2_P.HILInitialize_analog_input_maxi[8];
      follower_qbot2_DW.HILInitialize_AIMaximums[9] =
        follower_qbot2_P.HILInitialize_analog_input_maxi[8];
      result = hil_set_analog_input_ranges(follower_qbot2_DW.HILInitialize_Card,
        follower_qbot2_P.HILInitialize_analog_input_chan, 10U,
        &follower_qbot2_DW.HILInitialize_AIMinimums[0],
        &follower_qbot2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((follower_qbot2_P.HILInitialize_set_encoder_param && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_encoder_par_h && is_switching)) {
      follower_qbot2_DW.HILInitialize_QuadratureModes[0] =
        follower_qbot2_P.HILInitialize_quadrature;
      follower_qbot2_DW.HILInitialize_QuadratureModes[1] =
        follower_qbot2_P.HILInitialize_quadrature;
      follower_qbot2_DW.HILInitialize_QuadratureModes[2] =
        follower_qbot2_P.HILInitialize_quadrature;
      follower_qbot2_DW.HILInitialize_QuadratureModes[3] =
        follower_qbot2_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode
        (follower_qbot2_DW.HILInitialize_Card,
         follower_qbot2_P.HILInitialize_encoder_channels, 4U,
         (t_encoder_quadrature_mode *)
         &follower_qbot2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((follower_qbot2_P.HILInitialize_set_encoder_count && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_encoder_cou_f && is_switching)) {
      follower_qbot2_DW.HILInitialize_InitialEICounts[0] =
        follower_qbot2_P.HILInitialize_initial_encoder_c;
      follower_qbot2_DW.HILInitialize_InitialEICounts[1] =
        follower_qbot2_P.HILInitialize_initial_encoder_c;
      follower_qbot2_DW.HILInitialize_InitialEICounts[2] =
        follower_qbot2_P.HILInitialize_initial_encoder_c;
      follower_qbot2_DW.HILInitialize_InitialEICounts[3] =
        follower_qbot2_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(follower_qbot2_DW.HILInitialize_Card,
        follower_qbot2_P.HILInitialize_encoder_channels, 4U,
        &follower_qbot2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((follower_qbot2_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_pwm_params__c && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      follower_qbot2_DW.HILInitialize_POModeValues[0] =
        follower_qbot2_P.HILInitialize_pwm_modes;
      follower_qbot2_DW.HILInitialize_POModeValues[1] =
        follower_qbot2_P.HILInitialize_pwm_modes;
      follower_qbot2_DW.HILInitialize_POModeValues[2] =
        follower_qbot2_P.HILInitialize_pwm_modes;
      follower_qbot2_DW.HILInitialize_POModeValues[3] =
        follower_qbot2_P.HILInitialize_pwm_modes;
      result = hil_set_pwm_mode(follower_qbot2_DW.HILInitialize_Card,
        follower_qbot2_P.HILInitialize_pwm_channels, 4U, (t_pwm_mode *)
        &follower_qbot2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }

      if (follower_qbot2_DW.HILInitialize_POModeValues[0] == PWM_DUTY_CYCLE_MODE
          || follower_qbot2_DW.HILInitialize_POModeValues[0] ==
          PWM_ONE_SHOT_MODE || follower_qbot2_DW.HILInitialize_POModeValues[0] ==
          PWM_TIME_MODE) {
        follower_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[0];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        follower_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[0];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (follower_qbot2_DW.HILInitialize_POModeValues[1] == PWM_DUTY_CYCLE_MODE
          || follower_qbot2_DW.HILInitialize_POModeValues[1] ==
          PWM_ONE_SHOT_MODE || follower_qbot2_DW.HILInitialize_POModeValues[1] ==
          PWM_TIME_MODE) {
        follower_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[1];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        follower_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[1];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (follower_qbot2_DW.HILInitialize_POModeValues[2] == PWM_DUTY_CYCLE_MODE
          || follower_qbot2_DW.HILInitialize_POModeValues[2] ==
          PWM_ONE_SHOT_MODE || follower_qbot2_DW.HILInitialize_POModeValues[2] ==
          PWM_TIME_MODE) {
        follower_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[2];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        follower_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[2];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (follower_qbot2_DW.HILInitialize_POModeValues[3] == PWM_DUTY_CYCLE_MODE
          || follower_qbot2_DW.HILInitialize_POModeValues[3] ==
          PWM_ONE_SHOT_MODE || follower_qbot2_DW.HILInitialize_POModeValues[3] ==
          PWM_TIME_MODE) {
        follower_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[3];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        follower_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_channels[3];
        follower_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          follower_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(follower_qbot2_DW.HILInitialize_Card,
          &follower_qbot2_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes, &follower_qbot2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(follower_qbot2_DW.HILInitialize_Card,
          &follower_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &follower_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
          return;
        }
      }

      follower_qbot2_DW.HILInitialize_POModeValues[0] =
        follower_qbot2_P.HILInitialize_pwm_configuration;
      follower_qbot2_DW.HILInitialize_POModeValues[1] =
        follower_qbot2_P.HILInitialize_pwm_configuration;
      follower_qbot2_DW.HILInitialize_POModeValues[2] =
        follower_qbot2_P.HILInitialize_pwm_configuration;
      follower_qbot2_DW.HILInitialize_POModeValues[3] =
        follower_qbot2_P.HILInitialize_pwm_configuration;
      follower_qbot2_DW.HILInitialize_POAlignValues[0] =
        follower_qbot2_P.HILInitialize_pwm_alignment;
      follower_qbot2_DW.HILInitialize_POAlignValues[1] =
        follower_qbot2_P.HILInitialize_pwm_alignment;
      follower_qbot2_DW.HILInitialize_POAlignValues[2] =
        follower_qbot2_P.HILInitialize_pwm_alignment;
      follower_qbot2_DW.HILInitialize_POAlignValues[3] =
        follower_qbot2_P.HILInitialize_pwm_alignment;
      follower_qbot2_DW.HILInitialize_POPolarityVals[0] =
        follower_qbot2_P.HILInitialize_pwm_polarity;
      follower_qbot2_DW.HILInitialize_POPolarityVals[1] =
        follower_qbot2_P.HILInitialize_pwm_polarity;
      follower_qbot2_DW.HILInitialize_POPolarityVals[2] =
        follower_qbot2_P.HILInitialize_pwm_polarity;
      follower_qbot2_DW.HILInitialize_POPolarityVals[3] =
        follower_qbot2_P.HILInitialize_pwm_polarity;
      result = hil_set_pwm_configuration(follower_qbot2_DW.HILInitialize_Card,
        follower_qbot2_P.HILInitialize_pwm_channels, 4U,
        (t_pwm_configuration *) &follower_qbot2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &follower_qbot2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &follower_qbot2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }

      follower_qbot2_DW.HILInitialize_POSortedFreqs[0] =
        follower_qbot2_P.HILInitialize_pwm_leading_deadb;
      follower_qbot2_DW.HILInitialize_POSortedFreqs[1] =
        follower_qbot2_P.HILInitialize_pwm_leading_deadb;
      follower_qbot2_DW.HILInitialize_POSortedFreqs[2] =
        follower_qbot2_P.HILInitialize_pwm_leading_deadb;
      follower_qbot2_DW.HILInitialize_POSortedFreqs[3] =
        follower_qbot2_P.HILInitialize_pwm_leading_deadb;
      follower_qbot2_DW.HILInitialize_POValues[0] =
        follower_qbot2_P.HILInitialize_pwm_trailing_dead;
      follower_qbot2_DW.HILInitialize_POValues[1] =
        follower_qbot2_P.HILInitialize_pwm_trailing_dead;
      follower_qbot2_DW.HILInitialize_POValues[2] =
        follower_qbot2_P.HILInitialize_pwm_trailing_dead;
      follower_qbot2_DW.HILInitialize_POValues[3] =
        follower_qbot2_P.HILInitialize_pwm_trailing_dead;
      result = hil_set_pwm_deadband(follower_qbot2_DW.HILInitialize_Card,
        follower_qbot2_P.HILInitialize_pwm_channels, 4U,
        &follower_qbot2_DW.HILInitialize_POSortedFreqs[0],
        &follower_qbot2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((follower_qbot2_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_pwm_outputs_d && is_switching)) {
      follower_qbot2_DW.HILInitialize_POValues[0] =
        follower_qbot2_P.HILInitialize_initial_pwm_outpu;
      follower_qbot2_DW.HILInitialize_POValues[1] =
        follower_qbot2_P.HILInitialize_initial_pwm_outpu;
      follower_qbot2_DW.HILInitialize_POValues[2] =
        follower_qbot2_P.HILInitialize_initial_pwm_outpu;
      follower_qbot2_DW.HILInitialize_POValues[3] =
        follower_qbot2_P.HILInitialize_initial_pwm_outpu;
      result = hil_write_pwm(follower_qbot2_DW.HILInitialize_Card,
        follower_qbot2_P.HILInitialize_pwm_channels, 4U,
        &follower_qbot2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }
    }

    if (follower_qbot2_P.HILInitialize_set_pwm_outputs_o) {
      follower_qbot2_DW.HILInitialize_POValues[0] =
        follower_qbot2_P.HILInitialize_watchdog_pwm_outp;
      follower_qbot2_DW.HILInitialize_POValues[1] =
        follower_qbot2_P.HILInitialize_watchdog_pwm_outp;
      follower_qbot2_DW.HILInitialize_POValues[2] =
        follower_qbot2_P.HILInitialize_watchdog_pwm_outp;
      follower_qbot2_DW.HILInitialize_POValues[3] =
        follower_qbot2_P.HILInitialize_watchdog_pwm_outp;
      result = hil_watchdog_set_pwm_expiration_state
        (follower_qbot2_DW.HILInitialize_Card,
         follower_qbot2_P.HILInitialize_pwm_channels, 4U,
         &follower_qbot2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((follower_qbot2_P.HILInitialize_set_other_outputs && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_other_outpu_c && is_switching)) {
      result = hil_write_other(follower_qbot2_DW.HILInitialize_Card,
        follower_qbot2_P.HILInitialize_other_output_chan, 4U,
        follower_qbot2_P.HILInitialize_initial_other_out);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (stream_client_block): '<S1>/Stream Client' */

  /* S-Function Block: follower_qbot2/Data From Host/Stream Client (stream_client_block) */
  {
    follower_qbot2_DW.StreamClient_Stream = NULL;
    follower_qbot2_B.StreamClient_o3[0] =
      follower_qbot2_P.StreamClient_default_value[0];
    follower_qbot2_B.StreamClient_o3[1] =
      follower_qbot2_P.StreamClient_default_value[1];
    follower_qbot2_B.StreamClient_o3[2] =
      follower_qbot2_P.StreamClient_default_value[2];
    follower_qbot2_B.StreamClient_o3[3] =
      follower_qbot2_P.StreamClient_default_value[3];
    follower_qbot2_DW.StreamClient_Connected = false;
  }

  /* Start for S-Function (stream_client_block): '<S2>/Stream Client' */

  /* S-Function Block: follower_qbot2/Data From Leader/Stream Client (stream_client_block) */
  {
    follower_qbot2_DW.StreamClient_Stream_o = NULL;
    follower_qbot2_B.StreamClient_o3_f[0] =
      follower_qbot2_P.StreamClient_default_value_g[0];
    follower_qbot2_B.StreamClient_o3_f[1] =
      follower_qbot2_P.StreamClient_default_value_g[1];
    follower_qbot2_B.StreamClient_o3_f[2] =
      follower_qbot2_P.StreamClient_default_value_g[2];
    follower_qbot2_DW.StreamClient_Connected_i = false;
  }

  /* Start for Atomic SubSystem: '<S4>/Bias Removal' */
  /* Start for Enabled SubSystem: '<S13>/Enabled Moving Average' */
  follower_qbot2_DW.EnabledMovingAverage_MODE_g = false;

  /* End of Start for SubSystem: '<S13>/Enabled Moving Average' */

  /* InitializeConditions for Enabled SubSystem: '<S13>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  follower_qbot2_DW.UnitDelay_DSTATE_e =
    follower_qbot2_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S17>/Sum( k=1,n-1, x(k) )' */
  follower_qbot2_DW.Sumk1n1xk_DSTATE_k[0] =
    follower_qbot2_P.Sumk1n1xk_InitialCondition;
  follower_qbot2_DW.Sumk1n1xk_DSTATE_k[1] =
    follower_qbot2_P.Sumk1n1xk_InitialCondition;

  /* End of InitializeConditions for SubSystem: '<S13>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S13>/Switch Case' */
  follower_qbot2_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S4>/Bias Removal' */

  /* Start for Atomic SubSystem: '<S23>/Bias Removal' */
  /* Start for Enabled SubSystem: '<S25>/Enabled Moving Average' */
  follower_qbot2_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S25>/Enabled Moving Average' */

  /* InitializeConditions for Enabled SubSystem: '<S25>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
  follower_qbot2_DW.UnitDelay_DSTATE =
    follower_qbot2_P.UnitDelay_InitialCondition_h;

  /* InitializeConditions for UnitDelay: '<S27>/Sum( k=1,n-1, x(k) )' */
  follower_qbot2_DW.Sumk1n1xk_DSTATE =
    follower_qbot2_P.Sumk1n1xk_InitialCondition_h;

  /* End of InitializeConditions for SubSystem: '<S25>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S25>/Switch Case' */
  follower_qbot2_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S23>/Bias Removal' */

  /* Start for Constant: '<S33>/x0' */
  follower_qbot2_B.x0 = follower_qbot2_P.x0_Value;

  /* Start for Constant: '<S34>/x0' */
  follower_qbot2_B.x0_l = follower_qbot2_P.x0_Value_n;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE =
    follower_qbot2_P.DiscreteTimeIntegrator_IC;
  follower_qbot2_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l =
    follower_qbot2_P.DiscreteTimeIntegrator_IC_n;
  follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_c =
    follower_qbot2_P.DiscreteTimeIntegrator_IC_c;
  follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  follower_qbot2_DW.Memory_PreviousInput[0] = follower_qbot2_P.Memory_X0;
  follower_qbot2_DW.Memory_PreviousInput[1] = follower_qbot2_P.Memory_X0;
  follower_qbot2_DW.Memory_PreviousInput[2] = follower_qbot2_P.Memory_X0;

  /* InitializeConditions for Memory: '<S3>/Memory1' */
  follower_qbot2_DW.Memory1_PreviousInput[0] = follower_qbot2_P.Memory1_X0;
  follower_qbot2_DW.Memory1_PreviousInput[1] = follower_qbot2_P.Memory1_X0;
  follower_qbot2_DW.Memory1_PreviousInput[2] = follower_qbot2_P.Memory1_X0;

  /* InitializeConditions for Integrator: '<S33>/Integrator1' */
  if (rtmIsFirstInitCond(follower_qbot2_M)) {
    follower_qbot2_X.Integrator1_CSTATE = 0.0;
  }

  follower_qbot2_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for RateLimiter: '<S5>/Rate Limiter - Linear Speed' */
  follower_qbot2_DW.LastMajorTime = (rtInf);

  /* InitializeConditions for Integrator: '<S34>/Integrator1' */
  if (rtmIsFirstInitCond(follower_qbot2_M)) {
    follower_qbot2_X.Integrator1_CSTATE_l = 0.0;
  }

  follower_qbot2_DW.Integrator1_IWORK_p.IcNeedsLoading = 1;

  /* InitializeConditions for RateLimiter: '<S5>/Rate Limiter - Rotation Rate' */
  follower_qbot2_DW.LastMajorTime_c = (rtInf);

  /* InitializeConditions for Integrator: '<S33>/Integrator2' */
  follower_qbot2_X.Integrator2_CSTATE = follower_qbot2_P.Integrator2_IC;

  /* InitializeConditions for Memory: '<S35>/Memory' */
  follower_qbot2_DW.Memory_PreviousInput_e = follower_qbot2_P.Memory_X0_n;

  /* InitializeConditions for MATLAB Function: '<S35>/Way Point Control' */
  follower_qbot2_DW.Vf_1 = 0.0;
  follower_qbot2_DW.end_flag = 0.0;

  /* InitializeConditions for Integrator: '<S34>/Integrator2' */
  follower_qbot2_X.Integrator2_CSTATE_e = follower_qbot2_P.Integrator2_IC_j;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(follower_qbot2_M)) {
    rtmSetFirstInitCond(follower_qbot2_M, 0);
  }
}

/* Model terminate function */
void follower_qbot2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: follower_qbot2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(follower_qbot2_DW.HILInitialize_Card);
    hil_monitor_stop_all(follower_qbot2_DW.HILInitialize_Card);
    is_switching = false;
    if ((follower_qbot2_P.HILInitialize_set_pwm_outputs_b && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_pwm_outputs_f && is_switching)) {
      follower_qbot2_DW.HILInitialize_POValues[0] =
        follower_qbot2_P.HILInitialize_final_pwm_outputs;
      follower_qbot2_DW.HILInitialize_POValues[1] =
        follower_qbot2_P.HILInitialize_final_pwm_outputs;
      follower_qbot2_DW.HILInitialize_POValues[2] =
        follower_qbot2_P.HILInitialize_final_pwm_outputs;
      follower_qbot2_DW.HILInitialize_POValues[3] =
        follower_qbot2_P.HILInitialize_final_pwm_outputs;
      num_final_pwm_outputs = 4U;
    }

    if ((follower_qbot2_P.HILInitialize_set_other_outpu_h && !is_switching) ||
        (follower_qbot2_P.HILInitialize_set_other_outpu_n && is_switching)) {
      num_final_other_outputs = 4U;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(follower_qbot2_DW.HILInitialize_Card
                         , NULL, 0
                         , follower_qbot2_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , follower_qbot2_P.HILInitialize_other_output_chan,
                         num_final_other_outputs
                         , NULL
                         , &follower_qbot2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , follower_qbot2_P.HILInitialize_final_other_outpu
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(follower_qbot2_DW.HILInitialize_Card,
            follower_qbot2_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &follower_qbot2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(follower_qbot2_DW.HILInitialize_Card,
            follower_qbot2_P.HILInitialize_other_output_chan,
            num_final_other_outputs,
            follower_qbot2_P.HILInitialize_final_other_outpu);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(follower_qbot2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(follower_qbot2_DW.HILInitialize_Card);
    hil_monitor_delete_all(follower_qbot2_DW.HILInitialize_Card);
    hil_close(follower_qbot2_DW.HILInitialize_Card);
    follower_qbot2_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_client_block): '<S1>/Stream Client' */

  /* S-Function Block: follower_qbot2/Data From Host/Stream Client (stream_client_block) */
  {
    if (follower_qbot2_DW.StreamClient_Stream != NULL) {
      pstream_close(follower_qbot2_DW.StreamClient_Stream);
    }

    follower_qbot2_DW.StreamClient_Stream = NULL;
  }

  /* Terminate for S-Function (stream_client_block): '<S2>/Stream Client' */

  /* S-Function Block: follower_qbot2/Data From Leader/Stream Client (stream_client_block) */
  {
    if (follower_qbot2_DW.StreamClient_Stream_o != NULL) {
      pstream_close(follower_qbot2_DW.StreamClient_Stream_o);
    }

    follower_qbot2_DW.StreamClient_Stream_o = NULL;
  }
}
