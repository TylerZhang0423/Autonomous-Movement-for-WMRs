/*
 * leader_qbot2.c
 *
 * Code generation for model "leader_qbot2".
 *
 * Model version              : 1.93
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 17:54:07 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "leader_qbot2.h"
#include "leader_qbot2_private.h"
#include "leader_qbot2_dt.h"

/* Block signals (auto storage) */
B_leader_qbot2_T leader_qbot2_B;

/* Continuous states */
X_leader_qbot2_T leader_qbot2_X;

/* Block states (auto storage) */
DW_leader_qbot2_T leader_qbot2_DW;

/* Real-time model */
RT_MODEL_leader_qbot2_T leader_qbot2_M_;
RT_MODEL_leader_qbot2_T *const leader_qbot2_M = &leader_qbot2_M_;

/* Forward declaration for local functions */
static void leader_qb_ClosedLoop_Sequential(real_T dist, real_T theta, real_T
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
  leader_qbot2_derivatives();
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

/* Function for MATLAB Function: '<S22>/Way Point Control' */
static void leader_qb_ClosedLoop_Sequential(real_T dist, real_T theta, real_T
  vlimit, real_T ang_thr, real_T Kv, real_T Kw, real_T Vf_1, real_T *Vf, real_T *
  W)
{
  real_T wmax;
  real_T theta_0;

  /* '<S23>:1:154' */
  wmax = 2.0 * vlimit;
  if (((fabs(theta) > ang_thr) && (Vf_1 < 0.01)) || (fabs(theta) > 5.0 * ang_thr))
  {
    /* '<S23>:1:156' */
    /*  once rotated, then moves. once started moving, it won't turn unless the heading is too off target or have reached the previous target. */
    /* '<S23>:1:157' */
    *W = Kw * theta;

    /* '<S23>:1:158' */
    *Vf = 0.0;
    if (fabs(*W) > wmax) {
      /* '<S23>:1:159' */
      /* '<S23>:1:160' */
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
    /* '<S23>:1:163' */
    *Vf = Kv * dist;
    if (fabs(*Vf) > vlimit) {
      /* '<S23>:1:165' */
      /* '<S23>:1:166' */
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
    /* '<S23>:1:172' */
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
void leader_qbot2_step(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator1;
  real_T rtb_Integrator1_e;
  real_T rtb_HILRead1_o1;
  real_T rtb_HILRead1_o2[2];
  real_T rtb_HILRead1_o4;
  real_T rtb_DataTypeConversion;
  real_T rtb_DataTypeConversion_e;
  real_T rtb_states;
  real_T rtb_TmpSignalConversionAtStream[3];
  uint8_T rtb_StreamClient_o1;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_j;
  boolean_T rtb_HILRead1_o3[3];
  real_T currentTime;
  real_T target_distance;
  real_T states;
  real_T rtheta;
  boolean_T rtb_Relation;
  boolean_T rtb_Relation_h;
  boolean_T rtb_LogicalOperator_o;
  real_T rtb_Product;
  real_T rtb_Gain;
  int8_T rtAction;
  real_T rtb_ManualSwitchTrackingMethod;
  real_T rtb_target_xy_idx_0;
  real_T rtb_target_xy_idx_1;
  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    /* set solver stop time */
    if (!(leader_qbot2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&leader_qbot2_M->solverInfo,
                            ((leader_qbot2_M->Timing.clockTickH0 + 1) *
        leader_qbot2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&leader_qbot2_M->solverInfo,
                            ((leader_qbot2_M->Timing.clockTick0 + 1) *
        leader_qbot2_M->Timing.stepSize0 + leader_qbot2_M->Timing.clockTickH0 *
        leader_qbot2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(leader_qbot2_M)) {
    leader_qbot2_M->Timing.t[0] = rtsiGetT(&leader_qbot2_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(leader_qbot2_DW.EnabledMovingAverage_SubsysRanB);

  /* Reset subsysRan breadcrumbs */
  srClearBC(leader_qbot2_DW.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(leader_qbot2_DW.SwitchCaseActionSubsystem1_Subs);

  /* Reset subsysRan breadcrumbs */
  srClearBC(leader_qbot2_DW.SwitchCaseActionSubsystem2_Subs);
  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    /* S-Function (stream_client_block): '<S1>/Stream Client' */

    /* S-Function Block: leader_qbot2/Data From Host/Stream Client (stream_client_block) */
    {
      t_pstream_state state;
      t_error receive_result;
      if (!leader_qbot2_DW.StreamClient_Connected) {
        qthread_attr_t receive_thread_attributes;
        struct qsched_param scheduling_parameters;
        int min_priority = qsched_get_priority_min(QSCHED_FIFO);
        int max_priority = qsched_get_priority_max(QSCHED_FIFO);
        t_pstream_options options;
        t_error result;
        result = 0;
        options.size = sizeof(options);
        options.flags = leader_qbot2_P.StreamClient_Endian &
          PSTREAM_FLAG_ENDIAN_MASK;
        if (leader_qbot2_P.StreamClient_Implementation ==
            STREAM_CLIENT_IMPLEMENTATION_THREAD) {
          options.flags |= PSTREAM_FLAG_MULTITHREADED;
        }

        if (leader_qbot2_P.StreamClient_Optimize ==
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
        options.num_receive_units = 6;
        options.receive_buffer_size = leader_qbot2_P.StreamClient_RcvSize;
        options.receive_fifo_size = leader_qbot2_P.StreamClient_RcvFIFO;
        options.num_receive_dimensions = 0;
        options.max_receive_dimensions = NULL;
        if (leader_qbot2_P.StreamClient_RcvPriority < min_priority) {
          scheduling_parameters.sched_priority = min_priority;
        } else if (leader_qbot2_P.StreamClient_RcvPriority > max_priority) {
          scheduling_parameters.sched_priority = max_priority;
        } else {
          scheduling_parameters.sched_priority =
            leader_qbot2_P.StreamClient_RcvPriority;
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
              rtmSetErrorStatus(leader_qbot2_M,
                                "Unable to set scheduling inheritance for Stream Client receiving thread");
            }
          } else {
            rtmSetErrorStatus(leader_qbot2_M,
                              "The specified thread priority for the Stream Client receiving thread is not valid for this target");
          }
        } else {
          rtmSetErrorStatus(leader_qbot2_M,
                            "Unable to set scheduling policy for Stream Client receiving thread");
        }

        options.receive_thread_attributes = &receive_thread_attributes;
        if (result == 0) {
          /* Make sure URI is null-terminated */
          if (string_length((char *) leader_qbot2_P.StringConstant1_Value, 80) ==
              80) {
            rtmSetErrorStatus(leader_qbot2_M,
                              "URI passed to Stream Client block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = pstream_connect((char *)
              leader_qbot2_P.StringConstant1_Value, &options,
              &leader_qbot2_DW.StreamClient_Stream);
            if (result < 0 && result != -QERR_WOULD_BLOCK) {
              msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
                (_rt_error_message));
              rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
            }
          }
        }

        qthread_attr_destroy(&receive_thread_attributes);
        leader_qbot2_DW.StreamClient_Connected = true;
      }

      receive_result = pstream_receive(leader_qbot2_DW.StreamClient_Stream,
        &leader_qbot2_B.StreamClient_o3[0]);
      leader_qbot2_B.StreamClient_o4 = (receive_result > 0);
      leader_qbot2_B.StreamClient_o2 = 0;
      if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
        leader_qbot2_B.StreamClient_o2 = receive_result;
      }

      pstream_get_state(leader_qbot2_DW.StreamClient_Stream, &state);
      rtb_StreamClient_o1 = state;
    }

    /* RelationalOperator: '<S8>/Relation' incorporates:
     *  Constant: '<S2>/Signal Threshold'
     */
    rtb_Relation = (leader_qbot2_B.StreamClient_o3[5] <
                    leader_qbot2_P.SignalThreshold_Value);

    /* Logic: '<S8>/Logical Operator' */
    rtb_LogicalOperator = !rtb_Relation;

    /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator || (leader_qbot2_DW.DiscreteTimeIntegrator_PrevRese
         != 0)) {
      leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE =
        leader_qbot2_P.DiscreteTimeIntegrator_IC;
    }

    /* RelationalOperator: '<S8>/Relational Operator' incorporates:
     *  Constant: '<S2>/Timeout Threshold (s)'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     */
    leader_qbot2_B.RelationalOperator =
      (leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE >=
       leader_qbot2_P.TimeoutThresholds_Value);

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     */
    leader_qbot2_B.DataTypeConversion = (rtb_StreamClient_o1 <=
      leader_qbot2_P.CompareToConstant_const);

    /* RelationalOperator: '<S9>/Relation' incorporates:
     *  Constant: '<S2>/Signal Threshold'
     */
    rtb_Relation_h = (leader_qbot2_B.DataTypeConversion <
                      leader_qbot2_P.SignalThreshold_Value);

    /* Logic: '<S9>/Logical Operator' */
    rtb_LogicalOperator_j = !rtb_Relation_h;

    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_j ||
        (leader_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n != 0)) {
      leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l =
        leader_qbot2_P.DiscreteTimeIntegrator_IC_n;
    }

    /* RelationalOperator: '<S9>/Relational Operator' incorporates:
     *  Constant: '<S2>/Timeout Threshold (s)'
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
     */
    leader_qbot2_B.RelationalOperator_b =
      (leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l >=
       leader_qbot2_P.TimeoutThresholds_Value);

    /* Logic: '<S2>/Logical Operator1' */
    leader_qbot2_B.LogicalOperator1 = (leader_qbot2_B.RelationalOperator ||
      leader_qbot2_B.RelationalOperator_b);

    /* Constant: '<S1>/Dummy' */
    leader_qbot2_B.Dummy = leader_qbot2_P.Dummy_Value;

    /* Logic: '<S2>/Logical Operator' */
    rtb_LogicalOperator_o = ((leader_qbot2_B.StreamClient_o3[5] != 0.0) ||
      (leader_qbot2_B.DataTypeConversion != 0.0));

    /* Memory: '<S2>/Memory' */
    rtb_TmpSignalConversionAtStream[0] = leader_qbot2_DW.Memory_PreviousInput[0];
    rtb_TmpSignalConversionAtStream[1] = leader_qbot2_DW.Memory_PreviousInput[1];
    rtb_TmpSignalConversionAtStream[2] = leader_qbot2_DW.Memory_PreviousInput[2];

    /* Switch: '<S2>/Switch' */
    if (rtb_LogicalOperator_o) {
      leader_qbot2_B.Switch[0] = leader_qbot2_B.StreamClient_o3[0];
      leader_qbot2_B.Switch[1] = leader_qbot2_B.Dummy;
      leader_qbot2_B.Switch[2] = leader_qbot2_B.StreamClient_o3[1];
    } else {
      leader_qbot2_B.Switch[0] = rtb_TmpSignalConversionAtStream[0];
      leader_qbot2_B.Switch[1] = rtb_TmpSignalConversionAtStream[1];
      leader_qbot2_B.Switch[2] = rtb_TmpSignalConversionAtStream[2];
    }

    /* End of Switch: '<S2>/Switch' */

    /* Memory: '<S2>/Memory1' */
    rtb_TmpSignalConversionAtStream[0] = leader_qbot2_DW.Memory1_PreviousInput[0];
    rtb_TmpSignalConversionAtStream[1] = leader_qbot2_DW.Memory1_PreviousInput[1];
    rtb_TmpSignalConversionAtStream[2] = leader_qbot2_DW.Memory1_PreviousInput[2];

    /* Switch: '<S2>/Switch1' */
    if (rtb_LogicalOperator_o) {
      leader_qbot2_B.Switch1[0] = leader_qbot2_B.StreamClient_o3[2];
      leader_qbot2_B.Switch1[1] = leader_qbot2_B.StreamClient_o3[3];
      leader_qbot2_B.Switch1[2] = leader_qbot2_B.StreamClient_o3[4];
    } else {
      leader_qbot2_B.Switch1[0] = rtb_TmpSignalConversionAtStream[0];
      leader_qbot2_B.Switch1[1] = rtb_TmpSignalConversionAtStream[1];
      leader_qbot2_B.Switch1[2] = rtb_TmpSignalConversionAtStream[2];
    }

    /* End of Switch: '<S2>/Switch1' */

    /* S-Function (hil_read_block): '<S13>/HIL Read1' */

    /* S-Function Block: leader_qbot2/QBot 2/QBot_Basic/QBot2_IO_Basic/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read(leader_qbot2_DW.HILInitialize_Card,
        &leader_qbot2_P.HILRead1_analog_channels, 1U,
        leader_qbot2_P.HILRead1_encoder_channels, 2U,
        leader_qbot2_P.HILRead1_digital_channels, 3U,
        &leader_qbot2_P.HILRead1_other_channels, 1U,
        &rtb_HILRead1_o1,
        &leader_qbot2_DW.HILRead1_EncoderBuffer[0],
                                (t_boolean *)&rtb_HILRead1_o3[0],
        &rtb_HILRead1_o4
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
      } else {
        rtb_HILRead1_o2[0] = leader_qbot2_DW.HILRead1_EncoderBuffer[0];
        rtb_HILRead1_o2[1] = leader_qbot2_DW.HILRead1_EncoderBuffer[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S10>/Bias Removal' */
    /* Step: '<S12>/Step: start_time' */
    currentTime = (((leader_qbot2_M->Timing.clockTick1+
                     leader_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002);
    if (currentTime < leader_qbot2_P.BiasRemoval_start_time) {
      currentTime = leader_qbot2_P.Stepstart_time_Y0;
    } else {
      currentTime = leader_qbot2_P.Stepstart_time_YFinal;
    }

    /* End of Step: '<S12>/Step: start_time' */

    /* Step: '<S12>/Step: end_time' */
    if ((((leader_qbot2_M->Timing.clockTick1+leader_qbot2_M->Timing.clockTickH1*
           4294967296.0)) * 0.002) < leader_qbot2_P.BiasRemoval_end_time) {
      rtb_target_xy_idx_0 = leader_qbot2_P.Stepend_time_Y0;
    } else {
      rtb_target_xy_idx_0 = leader_qbot2_P.Stepend_time_YFinal;
    }

    /* End of Step: '<S12>/Step: end_time' */

    /* Outputs for Enabled SubSystem: '<S12>/Enabled Moving Average' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    /* Logic: '<S12>/Logical Operator' incorporates:
     *  Logic: '<S12>/Logical Operator1'
     */
    if ((currentTime != 0.0) && (!(rtb_target_xy_idx_0 != 0.0))) {
      if (!leader_qbot2_DW.EnabledMovingAverage_MODE) {
        /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
        leader_qbot2_DW.UnitDelay_DSTATE =
          leader_qbot2_P.UnitDelay_InitialCondition;

        /* InitializeConditions for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
        leader_qbot2_DW.Sumk1n1xk_DSTATE =
          leader_qbot2_P.Sumk1n1xk_InitialCondition;
        leader_qbot2_DW.EnabledMovingAverage_MODE = true;
      }

      /* Update for UnitDelay: '<S18>/Unit Delay' incorporates:
       *  Constant: '<S18>/unity'
       *  Sum: '<S18>/Count'
       *  UnitDelay: '<S18>/Unit Delay'
       */
      leader_qbot2_DW.UnitDelay_DSTATE += leader_qbot2_P.unity_Value;

      /* Update for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' incorporates:
       *  Sum: '<S14>/Sum'
       *  UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )'
       */
      leader_qbot2_DW.Sumk1n1xk_DSTATE += rtb_HILRead1_o4;
      srUpdateBC(leader_qbot2_DW.EnabledMovingAverage_SubsysRanB);
    } else {
      if (leader_qbot2_DW.EnabledMovingAverage_MODE) {
        leader_qbot2_DW.EnabledMovingAverage_MODE = false;
      }
    }

    /* End of Logic: '<S12>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S12>/Enabled Moving Average' */

    /* SwitchCase: '<S12>/Switch Case' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rtAction = -1;
    if (leader_qbot2_P.BiasRemoval_switch_id < 0.0) {
      rtb_target_xy_idx_0 = ceil(leader_qbot2_P.BiasRemoval_switch_id);
    } else {
      rtb_target_xy_idx_0 = floor(leader_qbot2_P.BiasRemoval_switch_id);
    }

    if (rtIsNaN(rtb_target_xy_idx_0) || rtIsInf(rtb_target_xy_idx_0)) {
      rtb_target_xy_idx_0 = 0.0;
    } else {
      rtb_target_xy_idx_0 = fmod(rtb_target_xy_idx_0, 4.294967296E+9);
    }

    switch (rtb_target_xy_idx_0 < 0.0 ? -(int32_T)(uint32_T)-rtb_target_xy_idx_0
            : (int32_T)(uint32_T)rtb_target_xy_idx_0) {
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

    leader_qbot2_DW.SwitchCase_ActiveSubsystem = rtAction;
    switch (rtAction) {
     case 0:
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S12>/Switch Case Action Subsystem1' incorporates:
       *  ActionPort: '<S16>/Action Port'
       */
      srUpdateBC(leader_qbot2_DW.SwitchCaseActionSubsystem1_Subs);

      /* End of Outputs for SubSystem: '<S12>/Switch Case Action Subsystem1' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S12>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      srUpdateBC(leader_qbot2_DW.SwitchCaseActionSubsystem2_Subs);

      /* End of Outputs for SubSystem: '<S12>/Switch Case Action Subsystem2' */
      break;
    }

    /* End of SwitchCase: '<S12>/Switch Case' */
    /* End of Outputs for SubSystem: '<S10>/Bias Removal' */

    /* Constant: '<S20>/x0' */
    leader_qbot2_B.x0 = leader_qbot2_P.x0_Value;
  }

  /* Integrator: '<S20>/Integrator1' */
  if (leader_qbot2_DW.Integrator1_IWORK.IcNeedsLoading) {
    leader_qbot2_X.Integrator1_CSTATE = leader_qbot2_B.x0;
  }

  rtb_Integrator1 = leader_qbot2_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    /* ManualSwitch: '<Root>/Manual Switch - QBot 2 Enable' incorporates:
     *  Constant: '<Root>/Disable'
     *  Constant: '<Root>/Enable'
     */
    if (leader_qbot2_P.ManualSwitchQBot2Enable_Current == 1) {
      leader_qbot2_B.ManualSwitchQBot2Enable = leader_qbot2_P.Enable_Value;
    } else {
      leader_qbot2_B.ManualSwitchQBot2Enable = leader_qbot2_P.Disable_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch - QBot 2 Enable' */
  }

  /* Product: '<Root>/Product' */
  rtb_Product = rtb_Integrator1 * leader_qbot2_B.ManualSwitchQBot2Enable *
    leader_qbot2_B.StreamClient_o3[5];

  /* RateLimiter: '<S3>/Rate Limiter - Linear Speed' */
  if (leader_qbot2_DW.LastMajorTime == (rtInf)) {
    leader_qbot2_B.RateLimiterLinearSpeed = rtb_Product;
  } else {
    currentTime = leader_qbot2_M->Timing.t[0] - leader_qbot2_DW.LastMajorTime;
    rtheta = currentTime * leader_qbot2_P.RateLimiterLinearSpeed_RisingLi;
    rtb_target_xy_idx_0 = rtb_Product - leader_qbot2_DW.PrevY;
    if (rtb_target_xy_idx_0 > rtheta) {
      leader_qbot2_B.RateLimiterLinearSpeed = leader_qbot2_DW.PrevY + rtheta;
    } else {
      currentTime *= leader_qbot2_P.RateLimiterLinearSpeed_FallingL;
      if (rtb_target_xy_idx_0 < currentTime) {
        leader_qbot2_B.RateLimiterLinearSpeed = leader_qbot2_DW.PrevY +
          currentTime;
      } else {
        leader_qbot2_B.RateLimiterLinearSpeed = rtb_Product;
      }
    }
  }

  /* End of RateLimiter: '<S3>/Rate Limiter - Linear Speed' */
  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    /* Constant: '<S21>/x0' */
    leader_qbot2_B.x0_l = leader_qbot2_P.x0_Value_n;
  }

  /* Integrator: '<S21>/Integrator1' */
  if (leader_qbot2_DW.Integrator1_IWORK_p.IcNeedsLoading) {
    leader_qbot2_X.Integrator1_CSTATE_l = leader_qbot2_B.x0_l;
  }

  rtb_Integrator1_e = leader_qbot2_X.Integrator1_CSTATE_l;

  /* Product: '<Root>/Product1' */
  rtb_Product = rtb_Integrator1_e * leader_qbot2_B.ManualSwitchQBot2Enable *
    leader_qbot2_B.StreamClient_o3[5];

  /* RateLimiter: '<S3>/Rate Limiter - Rotation Rate' */
  if (leader_qbot2_DW.LastMajorTime_l == (rtInf)) {
    leader_qbot2_B.RateLimiterRotationRate = rtb_Product;
  } else {
    currentTime = leader_qbot2_M->Timing.t[0] - leader_qbot2_DW.LastMajorTime_l;
    rtheta = currentTime * leader_qbot2_P.RateLimiterRotationRate_RisingL;
    rtb_target_xy_idx_0 = rtb_Product - leader_qbot2_DW.PrevY_m;
    if (rtb_target_xy_idx_0 > rtheta) {
      leader_qbot2_B.RateLimiterRotationRate = leader_qbot2_DW.PrevY_m + rtheta;
    } else {
      currentTime *= leader_qbot2_P.RateLimiterRotationRate_Falling;
      if (rtb_target_xy_idx_0 < currentTime) {
        leader_qbot2_B.RateLimiterRotationRate = leader_qbot2_DW.PrevY_m +
          currentTime;
      } else {
        leader_qbot2_B.RateLimiterRotationRate = rtb_Product;
      }
    }
  }

  /* End of RateLimiter: '<S3>/Rate Limiter - Rotation Rate' */

  /* MATLAB Function: '<S11>/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)' */
  /* MATLAB Function 'QBot 2/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity  into Left and Right Wheel Vellocity)/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)': '<S19>:1' */
  /*  Eqn Based on the eqn 4.52 (W is the angular velocity) */
  /* '<S19>:1:7' */
  leader_qbot2_B.vR = leader_qbot2_B.RateLimiterRotationRate * 0.235 / 2.0 +
    leader_qbot2_B.RateLimiterLinearSpeed;

  /* '<S19>:1:8' */
  leader_qbot2_B.vL = leader_qbot2_B.RateLimiterLinearSpeed -
    leader_qbot2_B.RateLimiterRotationRate * 0.235 / 2.0;
  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    /* S-Function (hil_write_block): '<S13>/HIL Write' */

    /* S-Function Block: leader_qbot2/QBot 2/QBot_Basic/QBot2_IO_Basic/HIL Write (hil_write_block) */
    {
      t_error result;
      leader_qbot2_DW.HILWrite_OtherBuffer[0] = leader_qbot2_B.vR;
      leader_qbot2_DW.HILWrite_OtherBuffer[1] = leader_qbot2_B.vL;
      result = hil_write(leader_qbot2_DW.HILInitialize_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         leader_qbot2_P.HILWrite_other_channels, 2U,
                         NULL,
                         NULL,
                         NULL,
                         &leader_qbot2_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
      }
    }

    /* SignalConversion: '<S4>/TmpSignal ConversionAtStream ServerInport1' */
    rtb_TmpSignalConversionAtStream[0] = leader_qbot2_B.Switch1[0];
    rtb_TmpSignalConversionAtStream[1] = leader_qbot2_B.Switch1[2];
    rtb_TmpSignalConversionAtStream[2] = leader_qbot2_B.Switch1[1];

    /* S-Function (stream_server_block): '<S4>/Stream Server' */

    /* S-Function Block: leader_qbot2/Serve Data For Follower/Stream Server (stream_server_block) */
    {
      t_pstream_state state;
      t_error send_result;
      if (leader_qbot2_P.Enable_Value_m) {
        send_result = pstream_send(leader_qbot2_DW.StreamServer_Stream,
          &rtb_TmpSignalConversionAtStream[0]);
      } else {
        send_result = 0;
      }

      leader_qbot2_B.StreamServer_o3 = (send_result > 0);
      leader_qbot2_B.StreamServer_o2 = 0;
      if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
        leader_qbot2_B.StreamServer_o2 = send_result;
      }

      pstream_get_state(leader_qbot2_DW.StreamServer_Stream, &state);
      leader_qbot2_B.StreamServer_o1 = state;
    }

    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    rtb_DataTypeConversion = rtb_Relation;

    /* DataTypeConversion: '<S9>/Data Type Conversion' */
    rtb_DataTypeConversion_e = rtb_Relation_h;

    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/V Limit2'
     */
    rtb_Gain = leader_qbot2_P.Gain_Gain * leader_qbot2_P.VLimit2_Value;

    /* ManualSwitch: '<Root>/Manual Switch - Tracking Method' incorporates:
     *  Constant: '<Root>/Sequential'
     *  Constant: '<Root>/Simultaneous'
     */
    if (leader_qbot2_P.ManualSwitchTrackingMethod_Curr == 1) {
      rtb_ManualSwitchTrackingMethod = leader_qbot2_P.Sequential_Value;
    } else {
      rtb_ManualSwitchTrackingMethod = leader_qbot2_P.Simultaneous_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch - Tracking Method' */
  }

  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    /* MATLAB Function: '<S22>/Way Point Control' incorporates:
     *  Constant: '<Root>/V Limit'
     *  Constant: '<Root>/V Limit1'
     *  Constant: '<S6>/Kv_1'
     *  Constant: '<S6>/Kv_2'
     *  Constant: '<S6>/Kv_3'
     *  Constant: '<S6>/Kv_4'
     *  Constant: '<S6>/Waypoint Step'
     *  Memory: '<S22>/Memory'
     *  SignalConversion: '<S23>/TmpSignal ConversionAt SFunction Inport1'
     *  SignalConversion: '<S23>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'Waypoint Controller/Trajectory control (Way-points)/Way Point Control': '<S23>:1' */
    /*  Initialize output variables */
    /* '<S23>:1:7' */
    leader_qbot2_B.Vf = 0.0;

    /* '<S23>:1:8' */
    leader_qbot2_B.W = 0.0;

    /* '<S23>:1:19' */
    states = leader_qbot2_DW.Memory_PreviousInput_e;

    /* '<S23>:1:23' */
    /* '<S23>:1:24' */
    /* '<S23>:1:25' */
    /* -------------------------------------------------------------------------- */
    /* '<S23>:1:105' */
    rtheta = leader_qbot2_B.Switch1[1];
    if (leader_qbot2_B.Switch1[1] > 3.1415926535897931) {
      /* '<S23>:1:106' */
      /* '<S23>:1:107' */
      rtheta = leader_qbot2_B.Switch1[1] - 6.2831853071795862;
    } else {
      if (leader_qbot2_B.Switch1[1] < -3.1415926535897931) {
        /* '<S23>:1:108' */
        /* '<S23>:1:109' */
        rtheta = leader_qbot2_B.Switch1[1] + 6.2831853071795862;
      }
    }

    /* '<S23>:1:26' */
    rtb_target_xy_idx_0 = leader_qbot2_B.Switch1[2];
    rtb_target_xy_idx_1 = leader_qbot2_B.Switch1[0];

    /* '<S23>:1:27' */
    /* '<S23>:1:32' */
    if (leader_qbot2_DW.Memory_PreviousInput_e == 1.0) {
      /* '<S23>:1:33' */
      /* '<S23>:1:34' */
      /* '<S23>:1:35' */
      rtb_target_xy_idx_0 = leader_qbot2_B.Switch[2];

      /* '<S23>:1:34' */
      /* '<S23>:1:35' */
      rtb_target_xy_idx_1 = leader_qbot2_B.Switch[0];

      /* '<S23>:1:34' */
    }

    /* '<S23>:1:41' */
    /* '<S23>:1:42' */
    /* '<S23>:1:43' */
    /*  ------------------------------------------------------------------------- */
    /* '<S23>:1:114' */
    currentTime = leader_qbot2_B.Switch1[2] - rtb_target_xy_idx_0;
    rtb_Product = leader_qbot2_B.Switch1[0] - rtb_target_xy_idx_1;
    target_distance = sqrt(currentTime * currentTime + rtb_Product * rtb_Product);

    /* '<S23>:1:44' */
    /*  ------------------------------------------------------------------------- */
    /* '<S23>:1:119' */
    /* '<S23>:1:120' */
    /* '<S23>:1:121' */
    rtb_target_xy_idx_0 = rt_atan2d_snf(rtb_target_xy_idx_1 -
      leader_qbot2_B.Switch1[0], rtb_target_xy_idx_0 - leader_qbot2_B.Switch1[2]);

    /* '<S23>:1:122' */
    /* -------------------------------------------------------------------------- */
    /* '<S23>:1:105' */
    if (rtb_target_xy_idx_0 > 3.1415926535897931) {
      /* '<S23>:1:106' */
      /* '<S23>:1:107' */
      rtb_target_xy_idx_0 -= 6.2831853071795862;
    } else {
      if (rtb_target_xy_idx_0 < -3.1415926535897931) {
        /* '<S23>:1:108' */
        /* '<S23>:1:109' */
        rtb_target_xy_idx_0 += 6.2831853071795862;
      }
    }

    /* -------------------------------------------------------------------------- */
    /* '<S23>:1:105' */
    currentTime = rtheta;
    if (rtheta > 3.1415926535897931) {
      /* '<S23>:1:106' */
      /* '<S23>:1:107' */
      currentTime = rtheta - 6.2831853071795862;
    } else {
      if (rtheta < -3.1415926535897931) {
        /* '<S23>:1:108' */
        /* '<S23>:1:109' */
        currentTime = rtheta + 6.2831853071795862;
      }
    }

    rtb_target_xy_idx_0 -= currentTime;

    /* -------------------------------------------------------------------------- */
    /* '<S23>:1:105' */
    if (rtb_target_xy_idx_0 > 3.1415926535897931) {
      /* '<S23>:1:106' */
      /* '<S23>:1:107' */
      rtb_target_xy_idx_0 -= 6.2831853071795862;
    } else {
      if (rtb_target_xy_idx_0 < -3.1415926535897931) {
        /* '<S23>:1:108' */
        /* '<S23>:1:109' */
        rtb_target_xy_idx_0 += 6.2831853071795862;
      }
    }

    if ((leader_qbot2_DW.Memory_PreviousInput_e == 1.0) && (target_distance <=
         leader_qbot2_P.VLimit1_Value)) {
      /* '<S23>:1:46' */
      /* || states(1) == -1 */
      /*  %        states(1) = -1; */
      /*  right_vel = int16(0); */
      /*  left_vel = int16(0); */
      /*   %       target_distance = 0; */
      /* '<S23>:1:51' */
      leader_qbot2_B.Vf = 0.0;

      /* '<S23>:1:52' */
      leader_qbot2_B.W = 0.0;
      if ((leader_qbot2_DW.end_flag == 1.0) && (target_distance <=
           leader_qbot2_P.VLimit1_Value)) {
        /* '<S23>:1:54' */
        /*  after all waypoints, psi will be adjusted to psi_d  */
        /* -------------------------------------------------------------------------- */
        /* '<S23>:1:105' */
        currentTime = leader_qbot2_B.Switch[1];
        if (leader_qbot2_B.Switch[1] > 3.1415926535897931) {
          /* '<S23>:1:106' */
          /* '<S23>:1:107' */
          currentTime = leader_qbot2_B.Switch[1] - 6.2831853071795862;
        } else {
          if (leader_qbot2_B.Switch[1] < -3.1415926535897931) {
            /* '<S23>:1:108' */
            /* '<S23>:1:109' */
            currentTime = leader_qbot2_B.Switch[1] + 6.2831853071795862;
          }
        }

        /* -------------------------------------------------------------------------- */
        /* '<S23>:1:105' */
        if (rtheta > 3.1415926535897931) {
          /* '<S23>:1:106' */
          /* '<S23>:1:107' */
          rtheta -= 6.2831853071795862;
        } else {
          if (rtheta < -3.1415926535897931) {
            /* '<S23>:1:108' */
            /* '<S23>:1:109' */
            rtheta += 6.2831853071795862;
          }
        }

        currentTime -= rtheta;

        /* -------------------------------------------------------------------------- */
        /* '<S23>:1:105' */
        if (currentTime > 3.1415926535897931) {
          /* '<S23>:1:106' */
          /* '<S23>:1:107' */
          currentTime -= 6.2831853071795862;
        } else {
          if (currentTime < -3.1415926535897931) {
            /* '<S23>:1:108' */
            /* '<S23>:1:109' */
            currentTime += 6.2831853071795862;
          }
        }

        leader_qb_ClosedLoop_Sequential(0.0, currentTime,
          leader_qbot2_P.VLimit_Value, rtb_Gain, leader_qbot2_P.Kv_1_Value,
          leader_qbot2_P.Kv_2_Value, leader_qbot2_DW.Vf_1, &rtb_Product, &rtheta);

        /* '<S23>:1:55' */
        leader_qbot2_B.Vf = rtb_Product;

        /* '<S23>:1:55' */
        leader_qbot2_B.W = rtheta;

        /* '<S23>:1:56' */
        leader_qbot2_DW.Vf_1 = rtb_Product;
      }
    } else if ((target_distance <= leader_qbot2_P.VLimit1_Value) &&
               (leader_qbot2_DW.end_flag == 0.0)) {
      /* '<S23>:1:62' */
      /* '<S23>:1:63' */
      states = leader_qbot2_DW.Memory_PreviousInput_e +
        leader_qbot2_P.WaypointStep_Value;

      /* 1; */
      if (leader_qbot2_DW.Memory_PreviousInput_e > 0.0) {
        /* '<S23>:1:65' */
        while ((fabs(leader_qbot2_B.Switch[2] - leader_qbot2_B.Switch[2]) < 2.0 *
                leader_qbot2_P.VLimit1_Value) && (fabs(leader_qbot2_B.Switch[0]
                 - leader_qbot2_B.Switch[0]) < 2.0 *
                leader_qbot2_P.VLimit1_Value)) {
          /* '<S23>:1:66' */
          if (states <= 1.0 - leader_qbot2_P.WaypointStep_Value) {
            /* '<S23>:1:67' */
            /* '<S23>:1:68' */
            states += leader_qbot2_P.WaypointStep_Value;

            /* 1; */
          } else {
            /* '<S23>:1:70' */
            states = 1.0;
          }
        }
      } else {
        /* '<S23>:1:74' */
        states += leader_qbot2_P.WaypointStep_Value;

        /* 1; */
      }

      if (states >= 1.0) {
        /* '<S23>:1:77' */
        /* '<S23>:1:78' */
        states = 1.0;

        /* '<S23>:1:79' */
        leader_qbot2_DW.end_flag = 1.0;
      }

      /*   elseif (end_flag == 1) && (target_distance <= dist_thr) % after all waypoints, psi will be adjusted to psi_d  */
      /*           [Vf, W] = ClosedLoop_Sequential(0, check_angle(check_angle(Psi_d)-check_angle(rtheta)), vlimit, ang_thr, dist_thr, Kv_1, Kw_1, Vf_1);  */
      /*            Vf_1=Vf; */
    } else if (rtb_ManualSwitchTrackingMethod == 2.0) {
      /* '<S23>:1:89' */
      /*  ------------------------------------------------------------------------- */
      /* '<S23>:1:131' */
      rtheta = 2.0 * leader_qbot2_P.VLimit_Value;

      /* '<S23>:1:132' */
      rtb_Product = leader_qbot2_P.Kv_4_Value * rtb_target_xy_idx_0;

      /* if abs(theta)<pi */
      /* '<S23>:1:135' */
      currentTime = leader_qbot2_P.Kv_3_Value * target_distance;

      /* else */
      /*     Vf=0; */
      /* end */
      /* '<S23>:1:140' */
      if (fabs(rtb_Product) > rtheta) {
        /* '<S23>:1:141' */
        /* '<S23>:1:142' */
        if (rtb_Product < 0.0) {
          rtb_Product = -1.0;
        } else if (rtb_Product > 0.0) {
          rtb_Product = 1.0;
        } else {
          if (rtb_Product == 0.0) {
            rtb_Product = 0.0;
          }
        }

        rtb_Product *= rtheta;
      }

      if (fabs(currentTime) > leader_qbot2_P.VLimit_Value) {
        /* '<S23>:1:144' */
        /* '<S23>:1:145' */
        currentTime = fabs(currentTime) * leader_qbot2_P.VLimit_Value;
      }

      /* '<S23>:1:90' */
      leader_qbot2_B.Vf = currentTime;

      /* '<S23>:1:90' */
      leader_qbot2_B.W = rtb_Product;
    } else {
      /*             [right_vel, left_vel] = rotate_and_go(ang_to_tar, vlimit, ang_thr); */
      leader_qb_ClosedLoop_Sequential(target_distance, rtb_target_xy_idx_0,
        leader_qbot2_P.VLimit_Value, rtb_Gain, leader_qbot2_P.Kv_1_Value,
        leader_qbot2_P.Kv_2_Value, leader_qbot2_DW.Vf_1, &currentTime,
        &rtb_Product);

      /* '<S23>:1:93' */
      leader_qbot2_B.Vf = currentTime;

      /* '<S23>:1:93' */
      leader_qbot2_B.W = rtb_Product;

      /* '<S23>:1:94' */
      leader_qbot2_DW.Vf_1 = currentTime;
    }

    rtb_states = states;

    /* End of MATLAB Function: '<S22>/Way Point Control' */
  }

  /* Product: '<S20>/Product' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/wn'
   *  Constant: '<S20>/zt'
   *  Integrator: '<S20>/Integrator2'
   *  Product: '<S20>/Product2'
   *  Sum: '<S20>/Sum'
   *  Sum: '<S20>/Sum1'
   */
  leader_qbot2_B.Product = ((leader_qbot2_B.Vf - rtb_Integrator1) -
    leader_qbot2_X.Integrator2_CSTATE * leader_qbot2_P.Constant_Value *
    leader_qbot2_P.SecondOrderLowPassFilter1_inp_f) *
    leader_qbot2_P.SecondOrderLowPassFilter1_input;

  /* Product: '<S20>/Product1' incorporates:
   *  Constant: '<S20>/wn'
   *  Integrator: '<S20>/Integrator2'
   */
  leader_qbot2_B.Product1 = leader_qbot2_P.SecondOrderLowPassFilter1_input *
    leader_qbot2_X.Integrator2_CSTATE;

  /* Product: '<S21>/Product' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/wn'
   *  Constant: '<S21>/zt'
   *  Integrator: '<S21>/Integrator2'
   *  Product: '<S21>/Product2'
   *  Sum: '<S21>/Sum'
   *  Sum: '<S21>/Sum1'
   */
  leader_qbot2_B.Product_k = ((leader_qbot2_B.W - rtb_Integrator1_e) -
    leader_qbot2_X.Integrator2_CSTATE_e * leader_qbot2_P.Constant_Value_l *
    leader_qbot2_P.SecondOrderLowPassFilter4_inp_i) *
    leader_qbot2_P.SecondOrderLowPassFilter4_input;

  /* Product: '<S21>/Product1' incorporates:
   *  Constant: '<S21>/wn'
   *  Integrator: '<S21>/Integrator2'
   */
  leader_qbot2_B.Product1_j = leader_qbot2_P.SecondOrderLowPassFilter4_input *
    leader_qbot2_X.Integrator2_CSTATE_e;
  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    if (rtmIsMajorTimeStep(leader_qbot2_M)) {
      /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
      if (!rtb_LogicalOperator) {
        leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE +=
          leader_qbot2_P.DiscreteTimeIntegrator_gainval * rtb_DataTypeConversion;
      }

      if (rtb_LogicalOperator) {
        leader_qbot2_DW.DiscreteTimeIntegrator_PrevRese = 1;
      } else {
        leader_qbot2_DW.DiscreteTimeIntegrator_PrevRese = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
      if (!rtb_LogicalOperator_j) {
        leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l +=
          leader_qbot2_P.DiscreteTimeIntegrator_gainva_d *
          rtb_DataTypeConversion_e;
      }

      if (rtb_LogicalOperator_j) {
        leader_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n = 1;
      } else {
        leader_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n = 0;
      }

      /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

      /* Update for Memory: '<S2>/Memory' */
      leader_qbot2_DW.Memory_PreviousInput[0] = leader_qbot2_B.Switch[0];
      leader_qbot2_DW.Memory_PreviousInput[1] = leader_qbot2_B.Switch[1];
      leader_qbot2_DW.Memory_PreviousInput[2] = leader_qbot2_B.Switch[2];

      /* Update for Memory: '<S2>/Memory1' */
      leader_qbot2_DW.Memory1_PreviousInput[0] = leader_qbot2_B.Switch1[0];
      leader_qbot2_DW.Memory1_PreviousInput[1] = leader_qbot2_B.Switch1[1];
      leader_qbot2_DW.Memory1_PreviousInput[2] = leader_qbot2_B.Switch1[2];
    }

    /* Update for Integrator: '<S20>/Integrator1' */
    leader_qbot2_DW.Integrator1_IWORK.IcNeedsLoading = 0;

    /* Update for RateLimiter: '<S3>/Rate Limiter - Linear Speed' */
    leader_qbot2_DW.PrevY = leader_qbot2_B.RateLimiterLinearSpeed;
    leader_qbot2_DW.LastMajorTime = leader_qbot2_M->Timing.t[0];

    /* Update for Integrator: '<S21>/Integrator1' */
    leader_qbot2_DW.Integrator1_IWORK_p.IcNeedsLoading = 0;

    /* Update for RateLimiter: '<S3>/Rate Limiter - Rotation Rate' */
    leader_qbot2_DW.PrevY_m = leader_qbot2_B.RateLimiterRotationRate;
    leader_qbot2_DW.LastMajorTime_l = leader_qbot2_M->Timing.t[0];
    if (rtmIsMajorTimeStep(leader_qbot2_M)) {
      /* Update for Memory: '<S22>/Memory' */
      leader_qbot2_DW.Memory_PreviousInput_e = rtb_states;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, leader_qbot2_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(leader_qbot2_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (((leader_qbot2_M->Timing.clockTick1+
                            leader_qbot2_M->Timing.clockTickH1* 4294967296.0)) *
                          0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(leader_qbot2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(leader_qbot2_M)!=-1) &&
          !((rtmGetTFinal(leader_qbot2_M)-(((leader_qbot2_M->Timing.clockTick1+
               leader_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((leader_qbot2_M->Timing.clockTick1+
               leader_qbot2_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(leader_qbot2_M, "Simulation finished");
      }

      if (rtmGetStopRequested(leader_qbot2_M)) {
        rtmSetErrorStatus(leader_qbot2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&leader_qbot2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++leader_qbot2_M->Timing.clockTick0)) {
      ++leader_qbot2_M->Timing.clockTickH0;
    }

    leader_qbot2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&leader_qbot2_M->solverInfo);

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
      leader_qbot2_M->Timing.clockTick1++;
      if (!leader_qbot2_M->Timing.clockTick1) {
        leader_qbot2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void leader_qbot2_derivatives(void)
{
  XDot_leader_qbot2_T *_rtXdot;
  _rtXdot = ((XDot_leader_qbot2_T *) leader_qbot2_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S20>/Integrator1' */
  {
    ((XDot_leader_qbot2_T *) leader_qbot2_M->ModelData.derivs)
      ->Integrator1_CSTATE = leader_qbot2_B.Product1;
  }

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  {
    ((XDot_leader_qbot2_T *) leader_qbot2_M->ModelData.derivs)
      ->Integrator1_CSTATE_l = leader_qbot2_B.Product1_j;
  }

  /* Derivatives for Integrator: '<S20>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = leader_qbot2_B.Product;

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e = leader_qbot2_B.Product_k;
}

/* Model initialize function */
void leader_qbot2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)leader_qbot2_M, 0,
                sizeof(RT_MODEL_leader_qbot2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&leader_qbot2_M->solverInfo,
                          &leader_qbot2_M->Timing.simTimeStep);
    rtsiSetTPtr(&leader_qbot2_M->solverInfo, &rtmGetTPtr(leader_qbot2_M));
    rtsiSetStepSizePtr(&leader_qbot2_M->solverInfo,
                       &leader_qbot2_M->Timing.stepSize0);
    rtsiSetdXPtr(&leader_qbot2_M->solverInfo, &leader_qbot2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&leader_qbot2_M->solverInfo, (real_T **)
                         &leader_qbot2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&leader_qbot2_M->solverInfo,
      &leader_qbot2_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&leader_qbot2_M->solverInfo, (&rtmGetErrorStatus
      (leader_qbot2_M)));
    rtsiSetRTModelPtr(&leader_qbot2_M->solverInfo, leader_qbot2_M);
  }

  rtsiSetSimTimeStep(&leader_qbot2_M->solverInfo, MAJOR_TIME_STEP);
  leader_qbot2_M->ModelData.intgData.f[0] = leader_qbot2_M->ModelData.odeF[0];
  leader_qbot2_M->ModelData.contStates = ((X_leader_qbot2_T *) &leader_qbot2_X);
  rtsiSetSolverData(&leader_qbot2_M->solverInfo, (void *)
                    &leader_qbot2_M->ModelData.intgData);
  rtsiSetSolverName(&leader_qbot2_M->solverInfo,"ode1");
  rtmSetTPtr(leader_qbot2_M, &leader_qbot2_M->Timing.tArray[0]);
  rtmSetTFinal(leader_qbot2_M, -1);
  leader_qbot2_M->Timing.stepSize0 = 0.002;
  rtmSetFirstInitCond(leader_qbot2_M, 1);

  /* External mode info */
  leader_qbot2_M->Sizes.checksums[0] = (3139040800U);
  leader_qbot2_M->Sizes.checksums[1] = (1670589118U);
  leader_qbot2_M->Sizes.checksums[2] = (2860596514U);
  leader_qbot2_M->Sizes.checksums[3] = (319544384U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    leader_qbot2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &leader_qbot2_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[2] = (sysRanDType *)
      &leader_qbot2_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[3] = (sysRanDType *)
      &leader_qbot2_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[4] = (sysRanDType *)
      &leader_qbot2_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(leader_qbot2_M->extModeInfo,
      &leader_qbot2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(leader_qbot2_M->extModeInfo,
                        leader_qbot2_M->Sizes.checksums);
    rteiSetTPtr(leader_qbot2_M->extModeInfo, rtmGetTPtr(leader_qbot2_M));
  }

  /* block I/O */
  (void) memset(((void *) &leader_qbot2_B), 0,
                sizeof(B_leader_qbot2_T));

  /* states (continuous) */
  {
    (void) memset((void *)&leader_qbot2_X, 0,
                  sizeof(X_leader_qbot2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&leader_qbot2_DW, 0,
                sizeof(DW_leader_qbot2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    leader_qbot2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: leader_qbot2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qbot2", "0", &leader_qbot2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(leader_qbot2_DW.HILInitialize_Card,
      "enc0_dir=0;enc0_filter=1;enc0_a=0;enc0_b=0;enc0_z=1;enc0_reload=0;enc1_dir=0;enc1_filter=1;enc1_a=0;enc1_b=0;enc1_z=1;enc1_reload=0;pwm0_immediate=0;pwm1_immediate=0;pwm2_immediate=0;pwm3_immediate=0;",
      201);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(leader_qbot2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
      return;
    }

    if ((leader_qbot2_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_analog_inpu_g && is_switching)) {
      {
        int_T i1;
        const real_T *p_HILInitialize_analog_input_mini =
          leader_qbot2_P.HILInitialize_analog_input_mini;
        real_T *dw_AIMinimums = &leader_qbot2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = p_HILInitialize_analog_input_mini[i1];
        }
      }

      leader_qbot2_DW.HILInitialize_AIMinimums[8] =
        leader_qbot2_P.HILInitialize_analog_input_mini[8];
      leader_qbot2_DW.HILInitialize_AIMinimums[9] =
        leader_qbot2_P.HILInitialize_analog_input_mini[8];

      {
        int_T i1;
        const real_T *p_HILInitialize_analog_input_maxi =
          leader_qbot2_P.HILInitialize_analog_input_maxi;
        real_T *dw_AIMaximums = &leader_qbot2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = p_HILInitialize_analog_input_maxi[i1];
        }
      }

      leader_qbot2_DW.HILInitialize_AIMaximums[8] =
        leader_qbot2_P.HILInitialize_analog_input_maxi[8];
      leader_qbot2_DW.HILInitialize_AIMaximums[9] =
        leader_qbot2_P.HILInitialize_analog_input_maxi[8];
      result = hil_set_analog_input_ranges(leader_qbot2_DW.HILInitialize_Card,
        leader_qbot2_P.HILInitialize_analog_input_chan, 10U,
        &leader_qbot2_DW.HILInitialize_AIMinimums[0],
        &leader_qbot2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((leader_qbot2_P.HILInitialize_set_encoder_param && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_encoder_par_h && is_switching)) {
      leader_qbot2_DW.HILInitialize_QuadratureModes[0] =
        leader_qbot2_P.HILInitialize_quadrature;
      leader_qbot2_DW.HILInitialize_QuadratureModes[1] =
        leader_qbot2_P.HILInitialize_quadrature;
      leader_qbot2_DW.HILInitialize_QuadratureModes[2] =
        leader_qbot2_P.HILInitialize_quadrature;
      leader_qbot2_DW.HILInitialize_QuadratureModes[3] =
        leader_qbot2_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode
        (leader_qbot2_DW.HILInitialize_Card,
         leader_qbot2_P.HILInitialize_encoder_channels, 4U,
         (t_encoder_quadrature_mode *)
         &leader_qbot2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((leader_qbot2_P.HILInitialize_set_encoder_count && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_encoder_cou_f && is_switching)) {
      leader_qbot2_DW.HILInitialize_InitialEICounts[0] =
        leader_qbot2_P.HILInitialize_initial_encoder_c;
      leader_qbot2_DW.HILInitialize_InitialEICounts[1] =
        leader_qbot2_P.HILInitialize_initial_encoder_c;
      leader_qbot2_DW.HILInitialize_InitialEICounts[2] =
        leader_qbot2_P.HILInitialize_initial_encoder_c;
      leader_qbot2_DW.HILInitialize_InitialEICounts[3] =
        leader_qbot2_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(leader_qbot2_DW.HILInitialize_Card,
        leader_qbot2_P.HILInitialize_encoder_channels, 4U,
        &leader_qbot2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((leader_qbot2_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_pwm_params__c && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      leader_qbot2_DW.HILInitialize_POModeValues[0] =
        leader_qbot2_P.HILInitialize_pwm_modes;
      leader_qbot2_DW.HILInitialize_POModeValues[1] =
        leader_qbot2_P.HILInitialize_pwm_modes;
      leader_qbot2_DW.HILInitialize_POModeValues[2] =
        leader_qbot2_P.HILInitialize_pwm_modes;
      leader_qbot2_DW.HILInitialize_POModeValues[3] =
        leader_qbot2_P.HILInitialize_pwm_modes;
      result = hil_set_pwm_mode(leader_qbot2_DW.HILInitialize_Card,
        leader_qbot2_P.HILInitialize_pwm_channels, 4U, (t_pwm_mode *)
        &leader_qbot2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }

      if (leader_qbot2_DW.HILInitialize_POModeValues[0] == PWM_DUTY_CYCLE_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[0] == PWM_ONE_SHOT_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[0] == PWM_TIME_MODE) {
        leader_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[0];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        leader_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[0];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (leader_qbot2_DW.HILInitialize_POModeValues[1] == PWM_DUTY_CYCLE_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[1] == PWM_ONE_SHOT_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[1] == PWM_TIME_MODE) {
        leader_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[1];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        leader_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[1];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (leader_qbot2_DW.HILInitialize_POModeValues[2] == PWM_DUTY_CYCLE_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[2] == PWM_ONE_SHOT_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[2] == PWM_TIME_MODE) {
        leader_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[2];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        leader_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[2];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (leader_qbot2_DW.HILInitialize_POModeValues[3] == PWM_DUTY_CYCLE_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[3] == PWM_ONE_SHOT_MODE ||
          leader_qbot2_DW.HILInitialize_POModeValues[3] == PWM_TIME_MODE) {
        leader_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[3];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_duty_cycle_modes++;
      } else {
        leader_qbot2_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_channels[3];
        leader_qbot2_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          leader_qbot2_P.HILInitialize_pwm_frequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(leader_qbot2_DW.HILInitialize_Card,
          &leader_qbot2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &leader_qbot2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(leader_qbot2_DW.HILInitialize_Card,
          &leader_qbot2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &leader_qbot2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
          return;
        }
      }

      leader_qbot2_DW.HILInitialize_POModeValues[0] =
        leader_qbot2_P.HILInitialize_pwm_configuration;
      leader_qbot2_DW.HILInitialize_POModeValues[1] =
        leader_qbot2_P.HILInitialize_pwm_configuration;
      leader_qbot2_DW.HILInitialize_POModeValues[2] =
        leader_qbot2_P.HILInitialize_pwm_configuration;
      leader_qbot2_DW.HILInitialize_POModeValues[3] =
        leader_qbot2_P.HILInitialize_pwm_configuration;
      leader_qbot2_DW.HILInitialize_POAlignValues[0] =
        leader_qbot2_P.HILInitialize_pwm_alignment;
      leader_qbot2_DW.HILInitialize_POAlignValues[1] =
        leader_qbot2_P.HILInitialize_pwm_alignment;
      leader_qbot2_DW.HILInitialize_POAlignValues[2] =
        leader_qbot2_P.HILInitialize_pwm_alignment;
      leader_qbot2_DW.HILInitialize_POAlignValues[3] =
        leader_qbot2_P.HILInitialize_pwm_alignment;
      leader_qbot2_DW.HILInitialize_POPolarityVals[0] =
        leader_qbot2_P.HILInitialize_pwm_polarity;
      leader_qbot2_DW.HILInitialize_POPolarityVals[1] =
        leader_qbot2_P.HILInitialize_pwm_polarity;
      leader_qbot2_DW.HILInitialize_POPolarityVals[2] =
        leader_qbot2_P.HILInitialize_pwm_polarity;
      leader_qbot2_DW.HILInitialize_POPolarityVals[3] =
        leader_qbot2_P.HILInitialize_pwm_polarity;
      result = hil_set_pwm_configuration(leader_qbot2_DW.HILInitialize_Card,
        leader_qbot2_P.HILInitialize_pwm_channels, 4U,
        (t_pwm_configuration *) &leader_qbot2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &leader_qbot2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &leader_qbot2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }

      leader_qbot2_DW.HILInitialize_POSortedFreqs[0] =
        leader_qbot2_P.HILInitialize_pwm_leading_deadb;
      leader_qbot2_DW.HILInitialize_POSortedFreqs[1] =
        leader_qbot2_P.HILInitialize_pwm_leading_deadb;
      leader_qbot2_DW.HILInitialize_POSortedFreqs[2] =
        leader_qbot2_P.HILInitialize_pwm_leading_deadb;
      leader_qbot2_DW.HILInitialize_POSortedFreqs[3] =
        leader_qbot2_P.HILInitialize_pwm_leading_deadb;
      leader_qbot2_DW.HILInitialize_POValues[0] =
        leader_qbot2_P.HILInitialize_pwm_trailing_dead;
      leader_qbot2_DW.HILInitialize_POValues[1] =
        leader_qbot2_P.HILInitialize_pwm_trailing_dead;
      leader_qbot2_DW.HILInitialize_POValues[2] =
        leader_qbot2_P.HILInitialize_pwm_trailing_dead;
      leader_qbot2_DW.HILInitialize_POValues[3] =
        leader_qbot2_P.HILInitialize_pwm_trailing_dead;
      result = hil_set_pwm_deadband(leader_qbot2_DW.HILInitialize_Card,
        leader_qbot2_P.HILInitialize_pwm_channels, 4U,
        &leader_qbot2_DW.HILInitialize_POSortedFreqs[0],
        &leader_qbot2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((leader_qbot2_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_pwm_outputs_d && is_switching)) {
      leader_qbot2_DW.HILInitialize_POValues[0] =
        leader_qbot2_P.HILInitialize_initial_pwm_outpu;
      leader_qbot2_DW.HILInitialize_POValues[1] =
        leader_qbot2_P.HILInitialize_initial_pwm_outpu;
      leader_qbot2_DW.HILInitialize_POValues[2] =
        leader_qbot2_P.HILInitialize_initial_pwm_outpu;
      leader_qbot2_DW.HILInitialize_POValues[3] =
        leader_qbot2_P.HILInitialize_initial_pwm_outpu;
      result = hil_write_pwm(leader_qbot2_DW.HILInitialize_Card,
        leader_qbot2_P.HILInitialize_pwm_channels, 4U,
        &leader_qbot2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }
    }

    if (leader_qbot2_P.HILInitialize_set_pwm_outputs_o) {
      leader_qbot2_DW.HILInitialize_POValues[0] =
        leader_qbot2_P.HILInitialize_watchdog_pwm_outp;
      leader_qbot2_DW.HILInitialize_POValues[1] =
        leader_qbot2_P.HILInitialize_watchdog_pwm_outp;
      leader_qbot2_DW.HILInitialize_POValues[2] =
        leader_qbot2_P.HILInitialize_watchdog_pwm_outp;
      leader_qbot2_DW.HILInitialize_POValues[3] =
        leader_qbot2_P.HILInitialize_watchdog_pwm_outp;
      result = hil_watchdog_set_pwm_expiration_state
        (leader_qbot2_DW.HILInitialize_Card,
         leader_qbot2_P.HILInitialize_pwm_channels, 4U,
         &leader_qbot2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }
    }

    if ((leader_qbot2_P.HILInitialize_set_other_outputs && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_other_outpu_c && is_switching)) {
      result = hil_write_other(leader_qbot2_DW.HILInitialize_Card,
        leader_qbot2_P.HILInitialize_other_output_chan, 4U,
        leader_qbot2_P.HILInitialize_initial_other_out);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (stream_client_block): '<S1>/Stream Client' */

  /* S-Function Block: leader_qbot2/Data From Host/Stream Client (stream_client_block) */
  {
    leader_qbot2_DW.StreamClient_Stream = NULL;

    {
      int_T i1;
      real_T *y2 = &leader_qbot2_B.StreamClient_o3[0];
      const real_T *p_StreamClient_default_value =
        leader_qbot2_P.StreamClient_default_value;
      for (i1=0; i1 < 6; i1++) {
        y2[i1] = p_StreamClient_default_value[i1];
      }
    }

    leader_qbot2_DW.StreamClient_Connected = false;
  }

  /* Start for Atomic SubSystem: '<S10>/Bias Removal' */
  /* Start for Enabled SubSystem: '<S12>/Enabled Moving Average' */
  leader_qbot2_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S12>/Enabled Moving Average' */

  /* InitializeConditions for Enabled SubSystem: '<S12>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  leader_qbot2_DW.UnitDelay_DSTATE = leader_qbot2_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S14>/Sum( k=1,n-1, x(k) )' */
  leader_qbot2_DW.Sumk1n1xk_DSTATE = leader_qbot2_P.Sumk1n1xk_InitialCondition;

  /* End of InitializeConditions for SubSystem: '<S12>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S12>/Switch Case' */
  leader_qbot2_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S10>/Bias Removal' */

  /* Start for Constant: '<S20>/x0' */
  leader_qbot2_B.x0 = leader_qbot2_P.x0_Value;

  /* Start for Constant: '<S21>/x0' */
  leader_qbot2_B.x0_l = leader_qbot2_P.x0_Value_n;

  /* Start for S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: leader_qbot2/Serve Data For Follower/Stream Server (stream_server_block) */
  {
    qthread_attr_t send_thread_attributes;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    t_pstream_options options;
    t_error result;
    leader_qbot2_DW.StreamServer_Stream = NULL;
    result = 0;
    options.size = sizeof(options);
    options.flags = leader_qbot2_P.StreamServer_Endian &
      PSTREAM_FLAG_ENDIAN_MASK;
    if (leader_qbot2_P.StreamServer_Implementation ==
        STREAM_SERVER_IMPLEMENTATION_THREAD) {
      options.flags |= PSTREAM_FLAG_MULTITHREADED;
    }

    if (leader_qbot2_P.StreamServer_Optimize == STREAM_SERVER_OPTIMIZE_LATENCY)
    {
      options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
    }

    options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
    options.send_unit_size = 8;
    options.num_send_units = 3;
    options.send_buffer_size = leader_qbot2_P.StreamServer_SndSize;
    options.send_fifo_size = leader_qbot2_P.StreamServer_SndFIFO;
    options.num_send_dimensions = 0;
    options.max_send_dimensions = NULL;
    if (leader_qbot2_P.StreamServer_SndPriority < min_priority) {
      scheduling_parameters.sched_priority = min_priority;
    } else if (leader_qbot2_P.StreamServer_SndPriority > max_priority) {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        leader_qbot2_P.StreamServer_SndPriority;
    }

    qthread_attr_init(&send_thread_attributes);
    result = qthread_attr_setschedpolicy(&send_thread_attributes, QSCHED_FIFO);
    if (result == 0) {
      result = qthread_attr_setschedparam(&send_thread_attributes,
        &scheduling_parameters);
      if (result == 0) {
        result = qthread_attr_setinheritsched(&send_thread_attributes,
          QTHREAD_EXPLICIT_SCHED);
        if (result < 0) {
          rtmSetErrorStatus(leader_qbot2_M,
                            "Unable to set scheduling inheritance for Stream Client sending thread");
        }
      } else {
        rtmSetErrorStatus(leader_qbot2_M,
                          "The specified thread priority for the Stream Client sending thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(leader_qbot2_M,
                        "Unable to set scheduling policy for Stream Client sending thread");
    }

    options.send_thread_attributes = &send_thread_attributes;
    options.receive_unit_size = 1;
    options.num_receive_units = 0;
    options.receive_buffer_size = 0;
    options.receive_fifo_size = 0;
    options.receive_thread_attributes = NULL;
    options.num_receive_dimensions = 0;
    options.max_receive_dimensions = NULL;
    if (result == 0) {
      result = pstream_listen((const char *) leader_qbot2_P.StreamServer_URI,
        &options, &leader_qbot2_DW.StreamServer_Stream);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
      }
    }

    qthread_attr_destroy(&send_thread_attributes);
  }

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE =
    leader_qbot2_P.DiscreteTimeIntegrator_IC;
  leader_qbot2_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l =
    leader_qbot2_P.DiscreteTimeIntegrator_IC_n;
  leader_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n = 0;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  leader_qbot2_DW.Memory_PreviousInput[0] = leader_qbot2_P.Memory_X0;
  leader_qbot2_DW.Memory_PreviousInput[1] = leader_qbot2_P.Memory_X0;
  leader_qbot2_DW.Memory_PreviousInput[2] = leader_qbot2_P.Memory_X0;

  /* InitializeConditions for Memory: '<S2>/Memory1' */
  leader_qbot2_DW.Memory1_PreviousInput[0] = leader_qbot2_P.Memory1_X0;
  leader_qbot2_DW.Memory1_PreviousInput[1] = leader_qbot2_P.Memory1_X0;
  leader_qbot2_DW.Memory1_PreviousInput[2] = leader_qbot2_P.Memory1_X0;

  /* InitializeConditions for Integrator: '<S20>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qbot2_M)) {
    leader_qbot2_X.Integrator1_CSTATE = 0.0;
  }

  leader_qbot2_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for RateLimiter: '<S3>/Rate Limiter - Linear Speed' */
  leader_qbot2_DW.LastMajorTime = (rtInf);

  /* InitializeConditions for Integrator: '<S21>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qbot2_M)) {
    leader_qbot2_X.Integrator1_CSTATE_l = 0.0;
  }

  leader_qbot2_DW.Integrator1_IWORK_p.IcNeedsLoading = 1;

  /* InitializeConditions for RateLimiter: '<S3>/Rate Limiter - Rotation Rate' */
  leader_qbot2_DW.LastMajorTime_l = (rtInf);

  /* InitializeConditions for Integrator: '<S20>/Integrator2' */
  leader_qbot2_X.Integrator2_CSTATE = leader_qbot2_P.Integrator2_IC;

  /* InitializeConditions for Memory: '<S22>/Memory' */
  leader_qbot2_DW.Memory_PreviousInput_e = leader_qbot2_P.Memory_X0_n;

  /* InitializeConditions for MATLAB Function: '<S22>/Way Point Control' */
  leader_qbot2_DW.Vf_1 = 0.0;
  leader_qbot2_DW.end_flag = 0.0;

  /* InitializeConditions for Integrator: '<S21>/Integrator2' */
  leader_qbot2_X.Integrator2_CSTATE_e = leader_qbot2_P.Integrator2_IC_j;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(leader_qbot2_M)) {
    rtmSetFirstInitCond(leader_qbot2_M, 0);
  }
}

/* Model terminate function */
void leader_qbot2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: leader_qbot2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(leader_qbot2_DW.HILInitialize_Card);
    hil_monitor_stop_all(leader_qbot2_DW.HILInitialize_Card);
    is_switching = false;
    if ((leader_qbot2_P.HILInitialize_set_pwm_outputs_b && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_pwm_outputs_f && is_switching)) {
      leader_qbot2_DW.HILInitialize_POValues[0] =
        leader_qbot2_P.HILInitialize_final_pwm_outputs;
      leader_qbot2_DW.HILInitialize_POValues[1] =
        leader_qbot2_P.HILInitialize_final_pwm_outputs;
      leader_qbot2_DW.HILInitialize_POValues[2] =
        leader_qbot2_P.HILInitialize_final_pwm_outputs;
      leader_qbot2_DW.HILInitialize_POValues[3] =
        leader_qbot2_P.HILInitialize_final_pwm_outputs;
      num_final_pwm_outputs = 4U;
    }

    if ((leader_qbot2_P.HILInitialize_set_other_outpu_h && !is_switching) ||
        (leader_qbot2_P.HILInitialize_set_other_outpu_n && is_switching)) {
      num_final_other_outputs = 4U;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(leader_qbot2_DW.HILInitialize_Card
                         , NULL, 0
                         , leader_qbot2_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , leader_qbot2_P.HILInitialize_other_output_chan,
                         num_final_other_outputs
                         , NULL
                         , &leader_qbot2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , leader_qbot2_P.HILInitialize_final_other_outpu
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(leader_qbot2_DW.HILInitialize_Card,
            leader_qbot2_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &leader_qbot2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(leader_qbot2_DW.HILInitialize_Card,
            leader_qbot2_P.HILInitialize_other_output_chan,
            num_final_other_outputs,
            leader_qbot2_P.HILInitialize_final_other_outpu);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(leader_qbot2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(leader_qbot2_DW.HILInitialize_Card);
    hil_monitor_delete_all(leader_qbot2_DW.HILInitialize_Card);
    hil_close(leader_qbot2_DW.HILInitialize_Card);
    leader_qbot2_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_client_block): '<S1>/Stream Client' */

  /* S-Function Block: leader_qbot2/Data From Host/Stream Client (stream_client_block) */
  {
    if (leader_qbot2_DW.StreamClient_Stream != NULL) {
      pstream_close(leader_qbot2_DW.StreamClient_Stream);
    }

    leader_qbot2_DW.StreamClient_Stream = NULL;
  }

  /* Terminate for S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: leader_qbot2/Serve Data For Follower/Stream Server (stream_server_block) */
  {
    if (leader_qbot2_DW.StreamServer_Stream != NULL) {
      pstream_close(leader_qbot2_DW.StreamServer_Stream);
    }

    leader_qbot2_DW.StreamServer_Stream = NULL;
  }
}
