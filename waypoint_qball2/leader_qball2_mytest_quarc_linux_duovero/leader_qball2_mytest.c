/*
 * leader_qball2_mytest.c
 *
 * Code generation for model "leader_qball2_mytest".
 *
 * Model version              : 1.901
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Aug 31 23:14:23 2015
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "leader_qball2_mytest.h"
#include "leader_qball2_mytest_private.h"
#include "leader_qball2_mytest_dt.h"

/* Block signals (auto storage) */
B_leader_qball2_mytest_T leader_qball2_mytest_B;

/* Continuous states */
X_leader_qball2_mytest_T leader_qball2_mytest_X;

/* Block states (auto storage) */
DW_leader_qball2_mytest_T leader_qball2_mytest_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_leader_qball2_mytest_T leader_qball2_mytest_PrevZCX;

/* Real-time model */
RT_MODEL_leader_qball2_mytest_T leader_qball2_mytest_M_;
RT_MODEL_leader_qball2_mytest_T *const leader_qball2_mytest_M =
  &leader_qball2_mytest_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

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
  int_T nXc = 40;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  leader_qball2_mytest_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Initial conditions for enable system:
 *    '<S31>/Enabled Moving Average'
 *    '<S27>/Enabled Moving Average'
 */
void leade_EnabledMovingAverage_Init(DW_EnabledMovingAverage_leade_T *localDW,
  P_EnabledMovingAverage_leader_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S34>/Sum( k=1,n-1, x(k) )' */
  localDW->Sumk1n1xk_DSTATE[0] = localP->Sumk1n1xk_InitialCondition;
  localDW->Sumk1n1xk_DSTATE[1] = localP->Sumk1n1xk_InitialCondition;
  localDW->Sumk1n1xk_DSTATE[2] = localP->Sumk1n1xk_InitialCondition;
}

/*
 * Disable for enable system:
 *    '<S31>/Enabled Moving Average'
 *    '<S27>/Enabled Moving Average'
 */
void le_EnabledMovingAverage_Disable(DW_EnabledMovingAverage_leade_T *localDW)
{
  localDW->EnabledMovingAverage_MODE = false;
}

/*
 * Start for enable system:
 *    '<S31>/Enabled Moving Average'
 *    '<S27>/Enabled Moving Average'
 */
void lead_EnabledMovingAverage_Start(DW_EnabledMovingAverage_leade_T *localDW,
  P_EnabledMovingAverage_leader_T *localP)
{
  localDW->EnabledMovingAverage_MODE = false;

  /* InitializeConditions for Enabled SubSystem: '<S31>/Enabled Moving Average' */
  leade_EnabledMovingAverage_Init(localDW, localP);

  /* End of InitializeConditions for SubSystem: '<S31>/Enabled Moving Average' */
}

/*
 * Output and update for enable system:
 *    '<S31>/Enabled Moving Average'
 *    '<S27>/Enabled Moving Average'
 */
void leader_qba_EnabledMovingAverage(boolean_T rtu_Enable, const real_T rtu_x_n
  [3], B_EnabledMovingAverage_leader_T *localB, DW_EnabledMovingAverage_leade_T *
  localDW, P_EnabledMovingAverage_leader_T *localP)
{
  real_T rtb_Count_m;
  real_T rtb_Sum_iu_idx_0;
  real_T rtb_Sum_iu_idx_1;
  real_T rtb_Sum_iu_idx_2;

  /* Outputs for Enabled SubSystem: '<S31>/Enabled Moving Average' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->EnabledMovingAverage_MODE) {
      leade_EnabledMovingAverage_Init(localDW, localP);
      localDW->EnabledMovingAverage_MODE = true;
    }

    /* Sum: '<S38>/Count' incorporates:
     *  Constant: '<S38>/unity'
     *  UnitDelay: '<S38>/Unit Delay'
     */
    rtb_Count_m = localP->unity_Value + localDW->UnitDelay_DSTATE;

    /* Sum: '<S34>/Sum' incorporates:
     *  UnitDelay: '<S34>/Sum( k=1,n-1, x(k) )'
     */
    rtb_Sum_iu_idx_0 = rtu_x_n[0] + localDW->Sumk1n1xk_DSTATE[0];
    rtb_Sum_iu_idx_1 = rtu_x_n[1] + localDW->Sumk1n1xk_DSTATE[1];
    rtb_Sum_iu_idx_2 = rtu_x_n[2] + localDW->Sumk1n1xk_DSTATE[2];

    /* Product: '<S34>/div' */
    localB->div[0] = rtb_Sum_iu_idx_0 / rtb_Count_m;
    localB->div[1] = rtb_Sum_iu_idx_1 / rtb_Count_m;
    localB->div[2] = rtb_Sum_iu_idx_2 / rtb_Count_m;

    /* Update for UnitDelay: '<S38>/Unit Delay' */
    localDW->UnitDelay_DSTATE = rtb_Count_m;

    /* Update for UnitDelay: '<S34>/Sum( k=1,n-1, x(k) )' */
    localDW->Sumk1n1xk_DSTATE[0] = rtb_Sum_iu_idx_0;
    localDW->Sumk1n1xk_DSTATE[1] = rtb_Sum_iu_idx_1;
    localDW->Sumk1n1xk_DSTATE[2] = rtb_Sum_iu_idx_2;
    srUpdateBC(localDW->EnabledMovingAverage_SubsysRanB);
  } else {
    if (localDW->EnabledMovingAverage_MODE) {
      le_EnabledMovingAverage_Disable(localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S31>/Enabled Moving Average' */
}

/*
 * Output and update for atomic system:
 *    '<S61>/Embedded MATLAB Function'
 *    '<S62>/Embedded MATLAB Function'
 *    '<S63>/Embedded MATLAB Function'
 */
void leader_q_EmbeddedMATLABFunction(real_T rtu_u, real_T rtu_x, real_T
  rtu_threshold, B_EmbeddedMATLABFunction_lead_T *localB)
{
  /* MATLAB Function 'Data from host/Subsystem4/Embedded MATLAB Function': '<S67>:1' */
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  if ((rtu_u < rtu_threshold) && (rtu_u > -rtu_threshold)) {
    /* '<S67>:1:5' */
    /* '<S67>:1:6' */
    localB->y = rtu_u;
  } else {
    /* '<S67>:1:8' */
    localB->y = rtu_x;
  }
}

/*
 * Initial conditions for enable system:
 *    '<S66>/Enabled Subsystem1'
 *    '<S123>/Enabled Subsystem1'
 */
void leader_q_EnabledSubsystem1_Init(DW_EnabledSubsystem1_leader_q_T *localDW,
  P_EnabledSubsystem1_leader_qb_T *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = localP->DiscreteTimeIntegrator_IC;
}

/*
 * Disable for enable system:
 *    '<S66>/Enabled Subsystem1'
 *    '<S123>/Enabled Subsystem1'
 */
void leade_EnabledSubsystem1_Disable(B_EnabledSubsystem1_leader_qb_T *localB,
  DW_EnabledSubsystem1_leader_q_T *localDW, P_EnabledSubsystem1_leader_qb_T
  *localP)
{
  /* Disable for Outport: '<S77>/timeout' */
  localB->RelationalOperator = localP->timeout_Y0;
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Start for enable system:
 *    '<S66>/Enabled Subsystem1'
 *    '<S123>/Enabled Subsystem1'
 */
void leader__EnabledSubsystem1_Start(B_EnabledSubsystem1_leader_qb_T *localB,
  DW_EnabledSubsystem1_leader_q_T *localDW, P_EnabledSubsystem1_leader_qb_T
  *localP)
{
  localDW->EnabledSubsystem1_MODE = false;

  /* InitializeConditions for Enabled SubSystem: '<S66>/Enabled Subsystem1' */
  leader_q_EnabledSubsystem1_Init(localDW, localP);

  /* End of InitializeConditions for SubSystem: '<S66>/Enabled Subsystem1' */

  /* VirtualOutportStart for Outport: '<S77>/timeout' */
  localB->RelationalOperator = localP->timeout_Y0;
}

/*
 * Output and update for enable system:
 *    '<S66>/Enabled Subsystem1'
 *    '<S123>/Enabled Subsystem1'
 */
void leader_qball2_EnabledSubsystem1(RT_MODEL_leader_qball2_mytest_T * const
  leader_qball2_mytest_M, boolean_T rtu_Enable, real_T rtu_timeoutlimit,
  B_EnabledSubsystem1_leader_qb_T *localB, DW_EnabledSubsystem1_leader_q_T
  *localDW, P_EnabledSubsystem1_leader_qb_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S66>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S77>/Enable'
   */
  if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    if (rtu_Enable) {
      if (!localDW->EnabledSubsystem1_MODE) {
        leader_q_EnabledSubsystem1_Init(localDW, localP);
        localDW->EnabledSubsystem1_MODE = true;
      }
    } else {
      if (localDW->EnabledSubsystem1_MODE) {
        leade_EnabledSubsystem1_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->EnabledSubsystem1_MODE) {
    /* RelationalOperator: '<S77>/Relational Operator' incorporates:
     *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator'
     */
    localB->RelationalOperator = (localDW->DiscreteTimeIntegrator_DSTATE >=
      rtu_timeoutlimit);

    /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S77>/Constant'
     */
    localDW->DiscreteTimeIntegrator_DSTATE +=
      localP->DiscreteTimeIntegrator_gainval * localP->Constant_Value;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      srUpdateBC(localDW->EnabledSubsystem1_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S66>/Enabled Subsystem1' */
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

/* Model step function for TID0 */
void leader_qball2_mytest_step0(void)  /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Memory;
  real_T rtb_Integrator1;
  real_T rtb_Sum1_je[3];
  real_T rtb_Switch;
  real_T rtb_Switch_j[2];
  real_T rtb_Memory_l;
  real_T rtb_Memory_e;
  real_T rtb_SliderGain_m;
  real_T rtb_TmpSignalConversionAtStream[3];
  real_T rtb_Integrator1_o;
  real_T rtb_Integrator2_p;
  real_T rtb_SwitchKp;
  real_T rtb_ManualSwitch_l;
  real_T rtb_Integrator1_k;
  real_T rtb_Integrator1_i;
  boolean_T rtb_Compare_a;
  boolean_T rtb_LogicalOperator_c;
  if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    /* set solver stop time */
    if (!(leader_qball2_mytest_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&leader_qball2_mytest_M->solverInfo,
                            ((leader_qball2_mytest_M->Timing.clockTickH0 + 1) *
        leader_qball2_mytest_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&leader_qball2_mytest_M->solverInfo,
                            ((leader_qball2_mytest_M->Timing.clockTick0 + 1) *
        leader_qball2_mytest_M->Timing.stepSize0 +
        leader_qball2_mytest_M->Timing.clockTickH0 *
        leader_qball2_mytest_M->Timing.stepSize0 * 4294967296.0));
    }

    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Update the flag to indicate when data transfers from
       *  Sample time: [0.002s, 0.0s] to Sample time: [0.1s, 0.0s]  */
      (leader_qball2_mytest_M->Timing.RateInteraction.TID1_2)++;
      if ((leader_qball2_mytest_M->Timing.RateInteraction.TID1_2) > 49) {
        leader_qball2_mytest_M->Timing.RateInteraction.TID1_2 = 0;
      }
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(leader_qball2_mytest_M)) {
    leader_qball2_mytest_M->Timing.t[0] = rtsiGetT
      (&leader_qball2_mytest_M->solverInfo);
  }

  {
    real_T *lastU;
    real_T e;
    real_T K_0;
    real_T K_1;
    real_T Phi;
    real_T cTheta;
    real_T roll_acc;
    ZCEventType zcEvent;
    uint8_T rtb_Compare;
    boolean_T rtb_LogicalOperator;
    boolean_T rtb_Compare_d[10];
    real_T rtb_Gain4;
    int8_T rtAction;
    real_T rtb_Sum2_ir;
    int32_T i;
    real_T cTheta_0[9];
    real_T rtb_Sum_bh_idx_1;
    real_T rtb_SwitchBatteryConfigGyroTo_0;
    real_T rtb_SwitchBatteryConfigGyroTo_1;
    real_T rtb_SwitchBatteryConfigGyroTo_2;

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_d);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_m);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (leader_qball2_mytest_DW.EnabledMovingAverage_c.EnabledMovingAverage_SubsysRanB);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.SwitchCaseActionSubsystem_Subsy);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.SwitchCaseActionSubsystem1_Subs);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.SwitchCaseActionSubsystem2_Subs);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.TriggeredSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledMovingAverage_SubsysRanB);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC
      (leader_qball2_mytest_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystem2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystemLatchOutputHigh);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_h);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_f);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.TriggeredSigmoidCompute_SubsysR);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_l);

    /* Reset subsysRan breadcrumbs */
    srClearBC(leader_qball2_mytest_DW.armheightcommand_SubsysRanBC);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* S-Function (sample_time_block): '<S3>/Sample Time' */

      /* S-Function Block: leader_qball2_mytest/DAQ/Sample Time (sample_time_block) */
      {
        t_error result;
        t_timeout current_time;
        t_timeout time_difference;
        result = timeout_get_high_resolution_time(&current_time);
        if (result == 0) {
          result = timeout_subtract(&time_difference, &current_time,
            &leader_qball2_mytest_DW.SampleTime_PreviousTime);
          leader_qball2_mytest_B.SampleTime = time_difference.seconds +
            time_difference.nanoseconds * 1e-9;
          memcpy(&leader_qball2_mytest_DW.SampleTime_PreviousTime, &current_time,
                 sizeof(t_timeout));
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
          return;
        }
      }

      /* Saturate: '<S3>/Saturation' incorporates:
       *  Memory: '<S3>/Memory'
       */
      if (leader_qball2_mytest_DW.Memory_PreviousInput[0] >
          leader_qball2_mytest_P.Saturation_UpperSat) {
        leader_qball2_mytest_B.Saturation[0] =
          leader_qball2_mytest_P.Saturation_UpperSat;
      } else if (leader_qball2_mytest_DW.Memory_PreviousInput[0] <
                 leader_qball2_mytest_P.Saturation_LowerSat) {
        leader_qball2_mytest_B.Saturation[0] =
          leader_qball2_mytest_P.Saturation_LowerSat;
      } else {
        leader_qball2_mytest_B.Saturation[0] =
          leader_qball2_mytest_DW.Memory_PreviousInput[0];
      }

      if (leader_qball2_mytest_DW.Memory_PreviousInput[1] >
          leader_qball2_mytest_P.Saturation_UpperSat) {
        leader_qball2_mytest_B.Saturation[1] =
          leader_qball2_mytest_P.Saturation_UpperSat;
      } else if (leader_qball2_mytest_DW.Memory_PreviousInput[1] <
                 leader_qball2_mytest_P.Saturation_LowerSat) {
        leader_qball2_mytest_B.Saturation[1] =
          leader_qball2_mytest_P.Saturation_LowerSat;
      } else {
        leader_qball2_mytest_B.Saturation[1] =
          leader_qball2_mytest_DW.Memory_PreviousInput[1];
      }

      if (leader_qball2_mytest_DW.Memory_PreviousInput[2] >
          leader_qball2_mytest_P.Saturation_UpperSat) {
        leader_qball2_mytest_B.Saturation[2] =
          leader_qball2_mytest_P.Saturation_UpperSat;
      } else if (leader_qball2_mytest_DW.Memory_PreviousInput[2] <
                 leader_qball2_mytest_P.Saturation_LowerSat) {
        leader_qball2_mytest_B.Saturation[2] =
          leader_qball2_mytest_P.Saturation_LowerSat;
      } else {
        leader_qball2_mytest_B.Saturation[2] =
          leader_qball2_mytest_DW.Memory_PreviousInput[2];
      }

      if (leader_qball2_mytest_DW.Memory_PreviousInput[3] >
          leader_qball2_mytest_P.Saturation_UpperSat) {
        leader_qball2_mytest_B.Saturation[3] =
          leader_qball2_mytest_P.Saturation_UpperSat;
      } else if (leader_qball2_mytest_DW.Memory_PreviousInput[3] <
                 leader_qball2_mytest_P.Saturation_LowerSat) {
        leader_qball2_mytest_B.Saturation[3] =
          leader_qball2_mytest_P.Saturation_LowerSat;
      } else {
        leader_qball2_mytest_B.Saturation[3] =
          leader_qball2_mytest_DW.Memory_PreviousInput[3];
      }

      /* End of Saturate: '<S3>/Saturation' */

      /* S-Function (hil_read_write_block): '<S3>/HIL Read Write1' */

      /* S-Function Block: leader_qball2_mytest/DAQ/HIL Read Write1 (hil_read_write_block) */
      {
        t_error result;
        leader_qball2_mytest_DW.HILReadWrite1_W_DigitalBuffer[0] =
          (leader_qball2_mytest_P.Motorenable_Value[0] != 0);
        leader_qball2_mytest_DW.HILReadWrite1_W_DigitalBuffer[1] =
          (leader_qball2_mytest_P.Motorenable_Value[1] != 0);
        result = hil_read_write(leader_qball2_mytest_DW.HILInitialize_Card,
          &leader_qball2_mytest_P.HILReadWrite1_analog_input_chan, 1U,
          NULL, 0U,
          NULL, 0U,
          leader_qball2_mytest_P.HILReadWrite1_other_input_chann, 7U,
          NULL, 0U,
          NULL, 0U,
          leader_qball2_mytest_P.HILReadWrite1_digital_output_ch, 2U,
          leader_qball2_mytest_P.HILReadWrite1_other_output_chan, 4U,
          &leader_qball2_mytest_B.HILReadWrite1_o1,
          NULL,
          NULL,
          &leader_qball2_mytest_B.HILReadWrite1_o2[0],
          NULL,
          NULL,
          &leader_qball2_mytest_DW.HILReadWrite1_W_DigitalBuffer[0],
          &leader_qball2_mytest_B.Saturation[0]
          );
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        }
      }

      /* S-Function (stream_client_block): '<S4>/Stream Client' */

      /* S-Function Block: leader_qball2_mytest/Data from host/Stream Client (stream_client_block) */
      {
        t_pstream_state state;
        t_error receive_result;
        if (!leader_qball2_mytest_DW.StreamClient_Connected) {
          qthread_attr_t receive_thread_attributes;
          struct qsched_param scheduling_parameters;
          int min_priority = qsched_get_priority_min(QSCHED_FIFO);
          int max_priority = qsched_get_priority_max(QSCHED_FIFO);
          t_pstream_options options;
          t_error result;
          result = 0;
          options.size = sizeof(options);
          options.flags = leader_qball2_mytest_P.StreamClient_Endian &
            PSTREAM_FLAG_ENDIAN_MASK;
          if (leader_qball2_mytest_P.StreamClient_Implementation ==
              STREAM_CLIENT_IMPLEMENTATION_THREAD) {
            options.flags |= PSTREAM_FLAG_MULTITHREADED;
          }

          if (leader_qball2_mytest_P.StreamClient_Optimize ==
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
          options.num_receive_units = 10;
          options.receive_buffer_size =
            leader_qball2_mytest_P.StreamClient_RcvSize;
          options.receive_fifo_size =
            leader_qball2_mytest_P.StreamClient_RcvFIFO;
          options.num_receive_dimensions = 0;
          options.max_receive_dimensions = NULL;
          if (leader_qball2_mytest_P.StreamClient_RcvPriority < min_priority) {
            scheduling_parameters.sched_priority = min_priority;
          } else if (leader_qball2_mytest_P.StreamClient_RcvPriority >
                     max_priority) {
            scheduling_parameters.sched_priority = max_priority;
          } else {
            scheduling_parameters.sched_priority =
              leader_qball2_mytest_P.StreamClient_RcvPriority;
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
                rtmSetErrorStatus(leader_qball2_mytest_M,
                                  "Unable to set scheduling inheritance for Stream Client receiving thread");
              }
            } else {
              rtmSetErrorStatus(leader_qball2_mytest_M,
                                "The specified thread priority for the Stream Client receiving thread is not valid for this target");
            }
          } else {
            rtmSetErrorStatus(leader_qball2_mytest_M,
                              "Unable to set scheduling policy for Stream Client receiving thread");
          }

          options.receive_thread_attributes = &receive_thread_attributes;
          if (result == 0) {
            /* Make sure URI is null-terminated */
            if (string_length((char *)
                              leader_qball2_mytest_P.StringConstant1_Value, 80) ==
                80) {
              rtmSetErrorStatus(leader_qball2_mytest_M,
                                "URI passed to Stream Client block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = pstream_connect((char *)
                leader_qball2_mytest_P.StringConstant1_Value, &options,
                &leader_qball2_mytest_DW.StreamClient_Stream);
              if (result < 0 && result != -QERR_WOULD_BLOCK) {
                msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
                  (_rt_error_message));
                rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
              }
            }
          }

          qthread_attr_destroy(&receive_thread_attributes);
          leader_qball2_mytest_DW.StreamClient_Connected = true;
        }

        receive_result = pstream_receive
          (leader_qball2_mytest_DW.StreamClient_Stream,
           &leader_qball2_mytest_B.StreamClient_o3[0]);
        leader_qball2_mytest_B.StreamClient_o4 = (receive_result > 0);
        leader_qball2_mytest_B.StreamClient_o2 = 0;
        if (receive_result < 0 && receive_result != -QERR_WOULD_BLOCK) {
          leader_qball2_mytest_B.StreamClient_o2 = receive_result;
        }

        pstream_get_state(leader_qball2_mytest_DW.StreamClient_Stream, &state);
        leader_qball2_mytest_B.StreamClient_o1 = state;
      }

      /* Memory: '<S62>/Memory' */
      rtb_Memory = leader_qball2_mytest_DW.Memory_PreviousInput_g;

      /* MATLAB Function: '<S62>/Embedded MATLAB Function' incorporates:
       *  Constant: '<S62>/Constant'
       */
      leader_q_EmbeddedMATLABFunction(leader_qball2_mytest_B.StreamClient_o3[4],
        rtb_Memory, leader_qball2_mytest_P.Constant_Value_b,
        &leader_qball2_mytest_B.sf_EmbeddedMATLABFunction);

      /* Constant: '<S48>/wn' */
      leader_qball2_mytest_B.wn = leader_qball2_mytest_P.OMEGA_DIFF;
    }

    /* Integrator: '<S48>/Integrator2' */
    rtb_Integrator2_p = leader_qball2_mytest_X.Integrator2_CSTATE;

    /* Product: '<S48>/Product1' */
    leader_qball2_mytest_B.Product1 = leader_qball2_mytest_B.wn *
      rtb_Integrator2_p;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S29>/Constant3' */
      leader_qball2_mytest_B.Constant3 = leader_qball2_mytest_P.Constant3_Value;
    }

    /* MATLAB Function: '<S29>/Kalman Filter - Height' */
    /* MATLAB Function 'DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Height': '<S43>:1' */
    /* 0.01; %0.001 */
    /* 0.01;  %0.003 */
    /* '<S43>:1:6' */
    /* 0.03 */
    /*  Calculate the new output */
    /* '<S43>:1:38' */
    leader_qball2_mytest_DW.x_height += (leader_qball2_mytest_B.Product1 -
      leader_qball2_mytest_DW.x_bias_h) * leader_qball2_mytest_B.Constant3;

    /* '<S43>:1:39' */
    leader_qball2_mytest_DW.P_00_b = (leader_qball2_mytest_DW.P_00_b -
      (leader_qball2_mytest_DW.P_10_j + leader_qball2_mytest_DW.P_01_f) *
      leader_qball2_mytest_B.Constant3) + 0.1 * leader_qball2_mytest_B.Constant3;

    /* '<S43>:1:40' */
    leader_qball2_mytest_DW.P_01_f -= leader_qball2_mytest_B.Constant3 *
      leader_qball2_mytest_DW.P_11_h;

    /* '<S43>:1:41' */
    leader_qball2_mytest_DW.P_10_j -= leader_qball2_mytest_B.Constant3 *
      leader_qball2_mytest_DW.P_11_h;

    /* '<S43>:1:42' */
    leader_qball2_mytest_DW.P_11_h += 0.01 * leader_qball2_mytest_B.Constant3;

    /*  Assuming H = [0.95 (effect of optitrack) 0.05 (effect of sonar)] */
    /* '<S43>:1:45' */
    e = (0.05 * leader_qball2_mytest_DW.x_height + 0.95 *
         leader_qball2_mytest_B.sf_EmbeddedMATLABFunction.y) -
      leader_qball2_mytest_DW.x_height;

    /* '<S43>:1:46' */
    /* '<S43>:1:47' */
    K_0 = leader_qball2_mytest_DW.P_00_b / (leader_qball2_mytest_DW.P_00_b +
      0.03);

    /* '<S43>:1:48' */
    K_1 = leader_qball2_mytest_DW.P_10_j / (leader_qball2_mytest_DW.P_00_b +
      0.03);

    /*  Correction */
    /* '<S43>:1:51' */
    leader_qball2_mytest_DW.x_height += K_0 * e;

    /* '<S43>:1:52' */
    leader_qball2_mytest_DW.x_bias_h += K_1 * e;

    /* '<S43>:1:53' */
    leader_qball2_mytest_DW.P_00_b -= K_0 * leader_qball2_mytest_DW.P_00_b;

    /* '<S43>:1:54' */
    leader_qball2_mytest_DW.P_01_f -= K_0 * leader_qball2_mytest_DW.P_01_f;

    /* '<S43>:1:55' */
    leader_qball2_mytest_DW.P_10_j -= K_1 * leader_qball2_mytest_DW.P_00_b;

    /* '<S43>:1:56' */
    leader_qball2_mytest_DW.P_11_h -= K_1 * leader_qball2_mytest_DW.P_01_f;

    /* '<S43>:1:58' */
    leader_qball2_mytest_B.height = leader_qball2_mytest_DW.x_height;

    /* Bias: '<S29>/Height Estimate Bias (Estimate Reference at Centre of QBall 2) ' */
    leader_qball2_mytest_B.HeightEstimateBiasEstimateRefer =
      leader_qball2_mytest_B.height + -leader_qball2_mytest_P.OFFSET_HEIGHT;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Bias: '<S29>/OptiTrack Height Measurement Bias' */
      leader_qball2_mytest_B.OptiTrackHeightMeasurementBias =
        leader_qball2_mytest_B.sf_EmbeddedMATLABFunction.y +
        -leader_qball2_mytest_P.OFFSET_HEIGHT;

      /* Saturate: '<S23>/Saturation' */
      if (leader_qball2_mytest_B.HILReadWrite1_o2[6] >
          leader_qball2_mytest_P.Saturation_UpperSat_g) {
        e = leader_qball2_mytest_P.Saturation_UpperSat_g;
      } else if (leader_qball2_mytest_B.HILReadWrite1_o2[6] <
                 leader_qball2_mytest_P.Saturation_LowerSat_j) {
        e = leader_qball2_mytest_P.Saturation_LowerSat_j;
      } else {
        e = leader_qball2_mytest_B.HILReadWrite1_o2[6];
      }

      /* End of Saturate: '<S23>/Saturation' */

      /* MATLAB Function: '<S28>/Embedded MATLAB Function' incorporates:
       *  Constant: '<S28>/Constant'
       *  Memory: '<S28>/Memory'
       */
      /* MATLAB Function 'DAQ/Initialize sensors/Nonlinear Limit (Reject Spikes)/Embedded MATLAB Function': '<S41>:1' */
      /*  This block supports the Embedded MATLAB subset. */
      /*  See the help menu for details.  */
      if (fabs(e - leader_qball2_mytest_DW.Memory_PreviousInput_b) <
          leader_qball2_mytest_P.Constant_Value_g1) {
        /* '<S41>:1:5' */
        /* '<S41>:1:6' */
        leader_qball2_mytest_B.y = e;
      } else {
        /* '<S41>:1:8' */
        leader_qball2_mytest_B.y =
          leader_qball2_mytest_DW.Memory_PreviousInput_b;
      }

      /* End of MATLAB Function: '<S28>/Embedded MATLAB Function' */

      /* RateTransition: '<S55>/Rate Transition' */
      if (leader_qball2_mytest_M->Timing.RateInteraction.TID1_2 == 1) {
        leader_qball2_mytest_B.RateTransition =
          leader_qball2_mytest_DW.RateTransition_Buffer0;
      }

      /* End of RateTransition: '<S55>/Rate Transition' */
    }

    /* Derivative: '<S55>/Derivative' */
    if ((leader_qball2_mytest_DW.TimeStampA >= leader_qball2_mytest_M->Timing.t
         [0]) && (leader_qball2_mytest_DW.TimeStampB >=
                  leader_qball2_mytest_M->Timing.t[0])) {
      leader_qball2_mytest_B.Derivative = 0.0;
    } else {
      e = leader_qball2_mytest_DW.TimeStampA;
      lastU = &leader_qball2_mytest_DW.LastUAtTimeA;
      if (leader_qball2_mytest_DW.TimeStampA <
          leader_qball2_mytest_DW.TimeStampB) {
        if (leader_qball2_mytest_DW.TimeStampB <
            leader_qball2_mytest_M->Timing.t[0]) {
          e = leader_qball2_mytest_DW.TimeStampB;
          lastU = &leader_qball2_mytest_DW.LastUAtTimeB;
        }
      } else {
        if (leader_qball2_mytest_DW.TimeStampA >=
            leader_qball2_mytest_M->Timing.t[0]) {
          e = leader_qball2_mytest_DW.TimeStampB;
          lastU = &leader_qball2_mytest_DW.LastUAtTimeB;
        }
      }

      leader_qball2_mytest_B.Derivative = (leader_qball2_mytest_B.RateTransition
        - *lastU) / (leader_qball2_mytest_M->Timing.t[0] - e);
    }

    /* End of Derivative: '<S55>/Derivative' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Triggered SubSystem: '<S55>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S56>/Trigger'
       */
      if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
        zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                           &leader_qball2_mytest_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                           (leader_qball2_mytest_B.Derivative));
        if (zcEvent != NO_ZCEVENT) {
          /* Inport: '<S56>/In1' */
          leader_qball2_mytest_B.In1_g = leader_qball2_mytest_B.y;
          leader_qball2_mytest_DW.TriggeredSubsystem_SubsysRanBC = 4;
        }
      }

      /* End of Outputs for SubSystem: '<S55>/Triggered Subsystem' */

      /* RateTransition: '<S54>/Rate Transition1' */
      if (leader_qball2_mytest_M->Timing.RateInteraction.TID1_2 == 1) {
        leader_qball2_mytest_B.RateTransition1 =
          leader_qball2_mytest_DW.RateTransition1_Buffer0;
      }

      /* End of RateTransition: '<S54>/Rate Transition1' */
    }

    /* Clock: '<S54>/Clock' */
    rtb_SwitchKp = leader_qball2_mytest_M->Timing.t[0];

    /* RateTransition: '<S54>/Rate Transition' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M) &&
        (leader_qball2_mytest_M->Timing.RateInteraction.TID1_2 == 1)) {
      leader_qball2_mytest_B.RateTransition_c =
        leader_qball2_mytest_DW.RateTransition_Buffer0_l;
    }

    /* End of RateTransition: '<S54>/Rate Transition' */

    /* Gain: '<S54>/Gain' incorporates:
     *  Bias: '<S54>/Bias'
     *  Sum: '<S54>/Sum2'
     */
    leader_qball2_mytest_B.Gain = ((rtb_SwitchKp +
      -leader_qball2_mytest_P.FOH1_Ts) - leader_qball2_mytest_B.RateTransition_c)
      * (1.0 / leader_qball2_mytest_P.FOH1_Ts);

    /* RateTransition: '<S54>/Rate Transition3' incorporates:
     *  Constant: '<S32>/x0'
     */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      leader_qball2_mytest_B.RateTransition3 = leader_qball2_mytest_B.Gain;

      /* Sum: '<S54>/s' incorporates:
       *  Product: '<S54>/Product'
       */
      leader_qball2_mytest_B.s = leader_qball2_mytest_B.RateTransition1 *
        leader_qball2_mytest_B.RateTransition3 + leader_qball2_mytest_B.In1_g;

      /* ManualSwitch: '<S23>/Battery Top Or Bottom' incorporates:
       *  Constant: '<S23>/Battery On Bottom'
       *  Constant: '<S23>/Battery On Top'
       */
      if (leader_qball2_mytest_P.BatteryTopOrBottom_CurrentSetti == 1) {
        leader_qball2_mytest_B.BatteryTopOrBottom =
          leader_qball2_mytest_P.BatteryOnTop_Value;
      } else {
        leader_qball2_mytest_B.BatteryTopOrBottom =
          leader_qball2_mytest_P.BatteryOnBottom_Value;
      }

      /* End of ManualSwitch: '<S23>/Battery Top Or Bottom' */

      /* Switch: '<S23>/Switch Battery Config - Acceleromter (Top or Bottom)' incorporates:
       *  Gain: '<S23>/Transform Accelerometer Data (For Battery Bottom Configuration)'
       */
      if (leader_qball2_mytest_B.BatteryTopOrBottom >
          leader_qball2_mytest_P.SwitchBatteryConfigAcceleromter) {
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[0] =
          leader_qball2_mytest_B.HILReadWrite1_o2[3];
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[1] =
          leader_qball2_mytest_B.HILReadWrite1_o2[4];
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[2] =
          leader_qball2_mytest_B.HILReadWrite1_o2[5];
      } else {
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[0] =
          leader_qball2_mytest_P.TransformAccelerometerDataForBa[0] *
          leader_qball2_mytest_B.HILReadWrite1_o2[3];
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[1] =
          leader_qball2_mytest_P.TransformAccelerometerDataForBa[1] *
          leader_qball2_mytest_B.HILReadWrite1_o2[4];
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[2] =
          leader_qball2_mytest_P.TransformAccelerometerDataForBa[2] *
          leader_qball2_mytest_B.HILReadWrite1_o2[5];
      }

      /* End of Switch: '<S23>/Switch Battery Config - Acceleromter (Top or Bottom)' */

      /* Outputs for Atomic SubSystem: '<S26>/Bias Removal' */
      /* Step: '<S31>/Step: start_time' */
      if ((((leader_qball2_mytest_M->Timing.clockTick1+
             leader_qball2_mytest_M->Timing.clockTickH1* 4294967296.0)) * 0.002)
          < leader_qball2_mytest_P.BiasRemoval_start_time) {
        K_1 = leader_qball2_mytest_P.Stepstart_time_Y0;
      } else {
        K_1 = leader_qball2_mytest_P.Stepstart_time_YFinal;
      }

      /* End of Step: '<S31>/Step: start_time' */

      /* Step: '<S31>/Step: end_time' */
      if ((((leader_qball2_mytest_M->Timing.clockTick1+
             leader_qball2_mytest_M->Timing.clockTickH1* 4294967296.0)) * 0.002)
          < leader_qball2_mytest_P.TIMEOUT_CALIB) {
        K_0 = leader_qball2_mytest_P.Stepend_time_Y0;
      } else {
        K_0 = leader_qball2_mytest_P.Stepend_time_YFinal;
      }

      /* End of Step: '<S31>/Step: end_time' */

      /* Logic: '<S31>/Logical Operator' incorporates:
       *  Logic: '<S31>/Logical Operator1'
       */
      rtb_LogicalOperator_c = ((K_1 != 0.0) && (!(K_0 != 0.0)));

      /* Outputs for Enabled SubSystem: '<S31>/Enabled Moving Average' */
      leader_qba_EnabledMovingAverage(rtb_LogicalOperator_c,
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter,
        &leader_qball2_mytest_B.EnabledMovingAverage_c,
        &leader_qball2_mytest_DW.EnabledMovingAverage_c,
        (P_EnabledMovingAverage_leader_T *)
        &leader_qball2_mytest_P.EnabledMovingAverage_c);

      /* End of Outputs for SubSystem: '<S31>/Enabled Moving Average' */

      /* SwitchCase: '<S31>/Switch Case' incorporates:
       *  Constant: '<S31>/Constant'
       */
      rtAction = -1;
      if (leader_qball2_mytest_P.BiasRemoval_switch_id < 0.0) {
        K_1 = ceil(leader_qball2_mytest_P.BiasRemoval_switch_id);
      } else {
        K_1 = floor(leader_qball2_mytest_P.BiasRemoval_switch_id);
      }

      if (rtIsNaN(K_1) || rtIsInf(K_1)) {
        K_1 = 0.0;
      } else {
        K_1 = fmod(K_1, 4.294967296E+9);
      }

      switch (K_1 < 0.0 ? -(int32_T)(uint32_T)-K_1 : (int32_T)(uint32_T)K_1) {
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

      leader_qball2_mytest_DW.SwitchCase_ActiveSubsystem = rtAction;
      switch (rtAction) {
       case 0:
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S31>/Switch Case Action Subsystem1' incorporates:
         *  ActionPort: '<S36>/Action Port'
         */
        srUpdateBC(leader_qball2_mytest_DW.SwitchCaseActionSubsystem1_Subs);

        /* End of Outputs for SubSystem: '<S31>/Switch Case Action Subsystem1' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S31>/Switch Case Action Subsystem2' incorporates:
         *  ActionPort: '<S37>/Action Port'
         */
        srUpdateBC(leader_qball2_mytest_DW.SwitchCaseActionSubsystem2_Subs);

        /* End of Outputs for SubSystem: '<S31>/Switch Case Action Subsystem2' */
        break;
      }

      /* End of SwitchCase: '<S31>/Switch Case' */
      /* End of Outputs for SubSystem: '<S26>/Bias Removal' */
      leader_qball2_mytest_B.x0 = leader_qball2_mytest_P.x0_Value;
    }

    /* End of RateTransition: '<S54>/Rate Transition3' */

    /* Integrator: '<S32>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE[0] = leader_qball2_mytest_B.x0;
      leader_qball2_mytest_X.Integrator1_CSTATE[1] = leader_qball2_mytest_B.x0;
      leader_qball2_mytest_X.Integrator1_CSTATE[2] = leader_qball2_mytest_B.x0;
    }

    leader_qball2_mytest_B.Integrator1[0] =
      leader_qball2_mytest_X.Integrator1_CSTATE[0];
    leader_qball2_mytest_B.Integrator1[1] =
      leader_qball2_mytest_X.Integrator1_CSTATE[1];
    leader_qball2_mytest_B.Integrator1[2] =
      leader_qball2_mytest_X.Integrator1_CSTATE[2];

    /* MATLAB Function: '<S26>/correct accel mounting' */
    /* MATLAB Function 'DAQ/Initialize sensors/Calibrate Accelerometer Data/correct accel mounting': '<S33>:1' */
    /* '<S33>:1:4' */
    e = 2.2250738585072014E-308;
    K_0 = fabs(leader_qball2_mytest_B.EnabledMovingAverage_c.div[0]);
    if (K_0 > 2.2250738585072014E-308) {
      rtb_Gain4 = 1.0;
      e = K_0;
    } else {
      K_1 = K_0 / 2.2250738585072014E-308;
      rtb_Gain4 = K_1 * K_1;
    }

    K_0 = fabs(leader_qball2_mytest_B.EnabledMovingAverage_c.div[1]);
    if (K_0 > e) {
      K_1 = e / K_0;
      rtb_Gain4 = rtb_Gain4 * K_1 * K_1 + 1.0;
      e = K_0;
    } else {
      K_1 = K_0 / e;
      rtb_Gain4 += K_1 * K_1;
    }

    K_0 = fabs(leader_qball2_mytest_B.EnabledMovingAverage_c.div[2]);
    if (K_0 > e) {
      K_1 = e / K_0;
      rtb_Gain4 = rtb_Gain4 * K_1 * K_1 + 1.0;
      e = K_0;
    } else {
      K_1 = K_0 / e;
      rtb_Gain4 += K_1 * K_1;
    }

    rtb_Gain4 = e * sqrt(rtb_Gain4);
    if (rtb_Gain4 > 2.2204460492503131E-16) {
      /* '<S33>:1:6' */
      /* '<S33>:1:7' */
      leader_qball2_mytest_B.nhat[0] =
        -leader_qball2_mytest_B.EnabledMovingAverage_c.div[0] / rtb_Gain4;
      leader_qball2_mytest_B.nhat[1] =
        -leader_qball2_mytest_B.EnabledMovingAverage_c.div[1] / rtb_Gain4;
      leader_qball2_mytest_B.nhat[2] =
        -leader_qball2_mytest_B.EnabledMovingAverage_c.div[2] / rtb_Gain4;
    } else {
      /* '<S33>:1:9' */
      leader_qball2_mytest_B.nhat[0] = 0.0;
      leader_qball2_mytest_B.nhat[1] = 0.0;
      leader_qball2_mytest_B.nhat[2] = 1.0;
    }

    /* '<S33>:1:12' */
    Phi = rt_atan2d_snf(leader_qball2_mytest_B.nhat[1],
                        leader_qball2_mytest_B.nhat[2]);

    /* '<S33>:1:13' */
    rtb_Sum2_ir = rt_atan2d_snf(-leader_qball2_mytest_B.nhat[0],
      leader_qball2_mytest_B.nhat[1] * sin(Phi) + leader_qball2_mytest_B.nhat[2]
      * cos(Phi));

    /* '<S33>:1:15' */
    e = sin(Phi);

    /* '<S33>:1:16' */
    K_0 = cos(Phi);

    /* '<S33>:1:18' */
    K_1 = sin(rtb_Sum2_ir);

    /* '<S33>:1:19' */
    cTheta = cos(rtb_Sum2_ir);

    /* '<S33>:1:23' */
    leader_qball2_mytest_B.check = (sin(Phi) * cos(rtb_Sum2_ir) *
      leader_qball2_mytest_B.nhat[1] + -sin(rtb_Sum2_ir) *
      leader_qball2_mytest_B.nhat[0]) + cos(Phi) * cos(rtb_Sum2_ir) *
      leader_qball2_mytest_B.nhat[2];

    /* '<S33>:1:26' */
    /* '<S33>:1:30' */
    leader_qball2_mytest_B.n = rtb_Gain4;
    cTheta_0[0] = cTheta;
    cTheta_0[3] = e * K_1;
    cTheta_0[6] = K_0 * K_1;
    cTheta_0[1] = 0.0;
    cTheta_0[4] = K_0;
    cTheta_0[7] = -e;
    cTheta_0[2] = -K_1;
    cTheta_0[5] = e * cTheta;
    cTheta_0[8] = K_0 * cTheta;
    for (i = 0; i < 3; i++) {
      leader_qball2_mytest_B.acc_body[i] = 0.0;
      leader_qball2_mytest_B.acc_body[i] += cTheta_0[i] *
        leader_qball2_mytest_B.Integrator1[0];
      leader_qball2_mytest_B.acc_body[i] += cTheta_0[i + 3] *
        leader_qball2_mytest_B.Integrator1[1];
      leader_qball2_mytest_B.acc_body[i] += cTheta_0[i + 6] *
        leader_qball2_mytest_B.Integrator1[2];
    }

    /* MATLAB Function: '<S42>/calc_roll_pitch' */
    /* MATLAB Function 'DAQ/Initialize sensors/Sensor Fusion//Filtering/Calculate Roll and Pitch (From Acceleration Data)/calc_roll_pitch': '<S52>:1' */
    /* '<S52>:1:3' */
    e = 2.2250738585072014E-308;
    K_0 = fabs(leader_qball2_mytest_B.acc_body[0]);
    if (K_0 > 2.2250738585072014E-308) {
      rtb_Gain4 = 1.0;
      e = K_0;
    } else {
      K_1 = K_0 / 2.2250738585072014E-308;
      rtb_Gain4 = K_1 * K_1;
    }

    K_0 = fabs(leader_qball2_mytest_B.acc_body[1]);
    if (K_0 > e) {
      K_1 = e / K_0;
      rtb_Gain4 = rtb_Gain4 * K_1 * K_1 + 1.0;
      e = K_0;
    } else {
      K_1 = K_0 / e;
      rtb_Gain4 += K_1 * K_1;
    }

    K_0 = fabs(leader_qball2_mytest_B.acc_body[2]);
    if (K_0 > e) {
      K_1 = e / K_0;
      rtb_Gain4 = rtb_Gain4 * K_1 * K_1 + 1.0;
      e = K_0;
    } else {
      K_1 = K_0 / e;
      rtb_Gain4 += K_1 * K_1;
    }

    rtb_Gain4 = e * sqrt(rtb_Gain4);
    if (rtb_Gain4 > 2.2204460492503131E-16) {
      /* '<S52>:1:4' */
      /* '<S52>:1:5' */
      K_1 = -leader_qball2_mytest_B.acc_body[0] / rtb_Gain4;
      rtb_Sum_bh_idx_1 = -leader_qball2_mytest_B.acc_body[1] / rtb_Gain4;
      K_0 = -leader_qball2_mytest_B.acc_body[2] / rtb_Gain4;
    } else {
      /* '<S52>:1:7' */
      K_1 = 0.0;
      rtb_Sum_bh_idx_1 = 0.0;
      K_0 = 1.0;
    }

    /* '<S52>:1:10' */
    roll_acc = rt_atan2d_snf(rtb_Sum_bh_idx_1, K_0);

    /* '<S52>:1:11' */
    cTheta = rt_atan2d_snf(-K_1, rtb_Sum_bh_idx_1 * sin(roll_acc) + K_0 * cos
      (roll_acc));
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Switch: '<S23>/Switch Battery Config - Gyro (Top or Bottom)' incorporates:
       *  Gain: '<S23>/Transform Gyro Data (For Battery Bottom Configuration)'
       */
      if (leader_qball2_mytest_B.BatteryTopOrBottom >
          leader_qball2_mytest_P.SwitchBatteryConfigGyroToporBot) {
        rtb_SwitchBatteryConfigGyroTo_0 =
          leader_qball2_mytest_B.HILReadWrite1_o2[0];
        rtb_SwitchBatteryConfigGyroTo_1 =
          leader_qball2_mytest_B.HILReadWrite1_o2[1];
        rtb_SwitchBatteryConfigGyroTo_2 =
          leader_qball2_mytest_B.HILReadWrite1_o2[2];
      } else {
        rtb_SwitchBatteryConfigGyroTo_0 =
          leader_qball2_mytest_P.TransformGyroDataForBatteryBott[0] *
          leader_qball2_mytest_B.HILReadWrite1_o2[0];
        rtb_SwitchBatteryConfigGyroTo_1 =
          leader_qball2_mytest_P.TransformGyroDataForBatteryBott[1] *
          leader_qball2_mytest_B.HILReadWrite1_o2[1];
        rtb_SwitchBatteryConfigGyroTo_2 =
          leader_qball2_mytest_P.TransformGyroDataForBatteryBott[2] *
          leader_qball2_mytest_B.HILReadWrite1_o2[2];
      }

      /* End of Switch: '<S23>/Switch Battery Config - Gyro (Top or Bottom)' */
    }

    /* Clock: '<S30>/Clock' */
    rtb_SwitchKp = leader_qball2_mytest_M->Timing.t[0];
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S30>/Calibration time (s)' */
      leader_qball2_mytest_B.Calibrationtimes =
        leader_qball2_mytest_P.Calibrationtimes_Value;
    }

    /* RelationalOperator: '<S30>/Relational Operator' */
    leader_qball2_mytest_B.RelationalOperator = (rtb_SwitchKp <
      leader_qball2_mytest_B.Calibrationtimes);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Enabled SubSystem: '<S30>/Enabled Moving Average' incorporates:
       *  EnablePort: '<S57>/Enable'
       */
      if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
        if (leader_qball2_mytest_B.RelationalOperator) {
          if (!leader_qball2_mytest_DW.EnabledMovingAverage_MODE) {
            /* InitializeConditions for UnitDelay: '<S58>/Unit Delay' */
            leader_qball2_mytest_DW.UnitDelay_DSTATE_o =
              leader_qball2_mytest_P.UnitDelay_InitialCondition;

            /* InitializeConditions for UnitDelay: '<S57>/Sum( k=1,n-1, x(k) )' */
            leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[0] =
              leader_qball2_mytest_P.Sumk1n1xk_InitialCondition;
            leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[1] =
              leader_qball2_mytest_P.Sumk1n1xk_InitialCondition;
            leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[2] =
              leader_qball2_mytest_P.Sumk1n1xk_InitialCondition;
            leader_qball2_mytest_DW.EnabledMovingAverage_MODE = true;
          }
        } else {
          if (leader_qball2_mytest_DW.EnabledMovingAverage_MODE) {
            leader_qball2_mytest_DW.EnabledMovingAverage_MODE = false;
          }
        }
      }

      if (leader_qball2_mytest_DW.EnabledMovingAverage_MODE) {
        /* Sum: '<S58>/Count' incorporates:
         *  Constant: '<S58>/unity'
         *  UnitDelay: '<S58>/Unit Delay'
         */
        e = leader_qball2_mytest_P.unity_Value +
          leader_qball2_mytest_DW.UnitDelay_DSTATE_o;

        /* Sum: '<S57>/Sum' incorporates:
         *  UnitDelay: '<S57>/Sum( k=1,n-1, x(k) )'
         */
        K_1 = rtb_SwitchBatteryConfigGyroTo_0 +
          leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[0];
        rtb_Sum_bh_idx_1 = rtb_SwitchBatteryConfigGyroTo_1 +
          leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[1];
        K_0 = rtb_SwitchBatteryConfigGyroTo_2 +
          leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[2];

        /* Product: '<S57>/div' */
        leader_qball2_mytest_B.div[0] = K_1 / e;
        leader_qball2_mytest_B.div[1] = rtb_Sum_bh_idx_1 / e;
        leader_qball2_mytest_B.div[2] = K_0 / e;

        /* Update for UnitDelay: '<S58>/Unit Delay' */
        leader_qball2_mytest_DW.UnitDelay_DSTATE_o = e;

        /* Update for UnitDelay: '<S57>/Sum( k=1,n-1, x(k) )' */
        leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[0] = K_1;
        leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[1] = rtb_Sum_bh_idx_1;
        leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[2] = K_0;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledMovingAverage_SubsysRanB);
        }
      }

      /* End of Outputs for SubSystem: '<S30>/Enabled Moving Average' */

      /* Sum: '<S30>/Sum' */
      leader_qball2_mytest_B.Sum[0] = rtb_SwitchBatteryConfigGyroTo_0 -
        leader_qball2_mytest_B.div[0];
      leader_qball2_mytest_B.Sum[1] = rtb_SwitchBatteryConfigGyroTo_1 -
        leader_qball2_mytest_B.div[1];
      leader_qball2_mytest_B.Sum[2] = rtb_SwitchBatteryConfigGyroTo_2 -
        leader_qball2_mytest_B.div[2];

      /* Constant: '<S29>/Constant' */
      leader_qball2_mytest_B.Constant = leader_qball2_mytest_P.Constant_Value_jv;
    }

    /* MATLAB Function: '<S29>/Kalman Filter - Roll' incorporates:
     *  MATLAB Function: '<S42>/calc_roll_pitch'
     *  TransferFcn: '<S29>/High Pass Filter - Roll'
     */
    /* MATLAB Function 'DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Roll': '<S45>:1' */
    if (leader_qball2_mytest_B.BatteryTopOrBottom == 1.0) {
      /* '<S45>:1:4' */
      /* '<S45>:1:5' */
      e = 0.001;

      /* 0.01; %0.001 */
    } else {
      /* '<S45>:1:7' */
      e = 0.01;
    }

    /* 0.01;  %0.003 */
    /* '<S45>:1:10' */
    /* 0.03 */
    /*  Calculate the new output */
    /* '<S45>:1:42' */
    leader_qball2_mytest_DW.x_angle_g +=
      ((leader_qball2_mytest_P.HighPassFilterRoll_C *
        leader_qball2_mytest_X.HighPassFilterRoll_CSTATE +
        leader_qball2_mytest_P.HighPassFilterRoll_D *
        leader_qball2_mytest_B.Sum[0]) - leader_qball2_mytest_DW.x_bias_e) *
      leader_qball2_mytest_B.Constant;

    /* '<S45>:1:43' */
    leader_qball2_mytest_DW.P_00_g = (leader_qball2_mytest_DW.P_00_g -
      (leader_qball2_mytest_DW.P_10_h + leader_qball2_mytest_DW.P_01_h) *
      leader_qball2_mytest_B.Constant) + e * leader_qball2_mytest_B.Constant;

    /* '<S45>:1:44' */
    leader_qball2_mytest_DW.P_01_h -= leader_qball2_mytest_B.Constant *
      leader_qball2_mytest_DW.P_11_n;

    /* '<S45>:1:45' */
    leader_qball2_mytest_DW.P_10_h -= leader_qball2_mytest_B.Constant *
      leader_qball2_mytest_DW.P_11_n;

    /* '<S45>:1:46' */
    leader_qball2_mytest_DW.P_11_n += 0.01 * leader_qball2_mytest_B.Constant;

    /*  Assuming H = [0.97 (effect of gyro) 0.03 (effect of acc)] */
    /* '<S45>:1:49' */
    e = (0.97 * leader_qball2_mytest_DW.x_angle_g + 0.03 * roll_acc) -
      leader_qball2_mytest_DW.x_angle_g;

    /* '<S45>:1:50' */
    /* '<S45>:1:51' */
    K_0 = leader_qball2_mytest_DW.P_00_g / (leader_qball2_mytest_DW.P_00_g +
      0.03);

    /* '<S45>:1:52' */
    K_1 = leader_qball2_mytest_DW.P_10_h / (leader_qball2_mytest_DW.P_00_g +
      0.03);

    /*  Correction */
    /* '<S45>:1:55' */
    leader_qball2_mytest_DW.x_angle_g += K_0 * e;

    /* '<S45>:1:56' */
    leader_qball2_mytest_DW.x_bias_e += K_1 * e;

    /* '<S45>:1:57' */
    leader_qball2_mytest_DW.P_00_g -= K_0 * leader_qball2_mytest_DW.P_00_g;

    /* '<S45>:1:58' */
    leader_qball2_mytest_DW.P_01_h -= K_0 * leader_qball2_mytest_DW.P_01_h;

    /* '<S45>:1:59' */
    leader_qball2_mytest_DW.P_10_h -= K_1 * leader_qball2_mytest_DW.P_00_g;

    /* '<S45>:1:60' */
    leader_qball2_mytest_DW.P_11_n -= K_1 * leader_qball2_mytest_DW.P_01_h;

    /* '<S45>:1:62' */
    leader_qball2_mytest_B.angle_m = leader_qball2_mytest_DW.x_angle_g;

    /* End of MATLAB Function: '<S29>/Kalman Filter - Roll' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S29>/Constant1' */
      leader_qball2_mytest_B.Constant1 = leader_qball2_mytest_P.Constant1_Value;
    }

    /* MATLAB Function: '<S29>/Kalman Filter - Pitch' incorporates:
     *  TransferFcn: '<S29>/High Pass Filter - Pitch'
     */
    /* MATLAB Function 'DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Pitch': '<S44>:1' */
    if (leader_qball2_mytest_B.BatteryTopOrBottom == 1.0) {
      /* '<S44>:1:4' */
      /* '<S44>:1:5' */
      e = 0.001;

      /* 0.01; %0.001 */
    } else {
      /* '<S44>:1:7' */
      e = 0.01;
    }

    /* 0.01;  %0.003 */
    /* '<S44>:1:10' */
    /* 0.03 */
    /*  Calculate the new output */
    /* '<S44>:1:42' */
    leader_qball2_mytest_DW.x_angle_h +=
      ((leader_qball2_mytest_P.HighPassFilterPitch_C *
        leader_qball2_mytest_X.HighPassFilterPitch_CSTATE +
        leader_qball2_mytest_P.HighPassFilterPitch_D *
        leader_qball2_mytest_B.Sum[1]) - leader_qball2_mytest_DW.x_bias_l) *
      leader_qball2_mytest_B.Constant1;

    /* '<S44>:1:43' */
    leader_qball2_mytest_DW.P_00_p = (leader_qball2_mytest_DW.P_00_p -
      (leader_qball2_mytest_DW.P_10_m + leader_qball2_mytest_DW.P_01_c) *
      leader_qball2_mytest_B.Constant1) + e * leader_qball2_mytest_B.Constant1;

    /* '<S44>:1:44' */
    leader_qball2_mytest_DW.P_01_c -= leader_qball2_mytest_B.Constant1 *
      leader_qball2_mytest_DW.P_11_a;

    /* '<S44>:1:45' */
    leader_qball2_mytest_DW.P_10_m -= leader_qball2_mytest_B.Constant1 *
      leader_qball2_mytest_DW.P_11_a;

    /* '<S44>:1:46' */
    leader_qball2_mytest_DW.P_11_a += 0.01 * leader_qball2_mytest_B.Constant1;

    /*  Assuming H = [0.98 (effect of gyro) 0.02 (effect of acc)] */
    /* e = (0.97*x_angle + 0.03*acc_angle) - x_angle; */
    /* '<S44>:1:50' */
    e = ((0.9 * leader_qball2_mytest_DW.x_angle_h + 0.01 * cTheta) + 0.09 *
         leader_qball2_mytest_B.StreamClient_o3[8]) -
      leader_qball2_mytest_DW.x_angle_h;

    /* '<S44>:1:51' */
    /* '<S44>:1:52' */
    K_0 = leader_qball2_mytest_DW.P_00_p / (leader_qball2_mytest_DW.P_00_p +
      0.03);

    /* '<S44>:1:53' */
    K_1 = leader_qball2_mytest_DW.P_10_m / (leader_qball2_mytest_DW.P_00_p +
      0.03);

    /*  Correction */
    /* '<S44>:1:56' */
    leader_qball2_mytest_DW.x_angle_h += K_0 * e;

    /* '<S44>:1:57' */
    leader_qball2_mytest_DW.x_bias_l += K_1 * e;

    /* '<S44>:1:58' */
    leader_qball2_mytest_DW.P_00_p -= K_0 * leader_qball2_mytest_DW.P_00_p;

    /* '<S44>:1:59' */
    leader_qball2_mytest_DW.P_01_c -= K_0 * leader_qball2_mytest_DW.P_01_c;

    /* '<S44>:1:60' */
    leader_qball2_mytest_DW.P_10_m -= K_1 * leader_qball2_mytest_DW.P_00_p;

    /* '<S44>:1:61' */
    leader_qball2_mytest_DW.P_11_a -= K_1 * leader_qball2_mytest_DW.P_01_c;

    /* '<S44>:1:63' */
    leader_qball2_mytest_B.angle_f = leader_qball2_mytest_DW.x_angle_h;

    /* End of MATLAB Function: '<S29>/Kalman Filter - Pitch' */

    /* Product: '<S51>/Product' incorporates:
     *  Trigonometry: '<S51>/Trigonometric Function'
     *  Trigonometry: '<S51>/Trigonometric Function2'
     */
    leader_qball2_mytest_B.Product = leader_qball2_mytest_B.s * cos
      (leader_qball2_mytest_B.angle_m) * cos(leader_qball2_mytest_B.angle_f);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S49>/wn' */
      leader_qball2_mytest_B.wn_i = leader_qball2_mytest_P.OMEGA_DIFF;
    }

    /* Integrator: '<S49>/Integrator2' */
    rtb_SwitchKp = leader_qball2_mytest_X.Integrator2_CSTATE_j;

    /* Product: '<S49>/Product1' */
    leader_qball2_mytest_B.Product1_o = leader_qball2_mytest_B.wn_i *
      rtb_SwitchKp;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S50>/wn' */
      leader_qball2_mytest_B.wn_g = leader_qball2_mytest_P.OMEGA_DIFF;
    }

    /* Integrator: '<S50>/Integrator2' */
    rtb_Integrator1_k = leader_qball2_mytest_X.Integrator2_CSTATE_i;

    /* Product: '<S50>/Product1' */
    leader_qball2_mytest_B.Product1_k = leader_qball2_mytest_B.wn_g *
      rtb_Integrator1_k;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Gain: '<S29>/Gain5' */
    leader_qball2_mytest_B.Gain5 = leader_qball2_mytest_P.Gain5_Gain *
      leader_qball2_mytest_B.angle_f;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Gain: '<S29>/Gain4' */
    leader_qball2_mytest_B.Gain4 = leader_qball2_mytest_P.Gain4_Gain *
      leader_qball2_mytest_B.angle_m;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S47>/x0' */
      leader_qball2_mytest_B.x0_p = leader_qball2_mytest_P.x0_Value_a;
    }

    /* Integrator: '<S47>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK_j.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE_l = leader_qball2_mytest_B.x0_p;
    }

    rtb_Integrator1 = leader_qball2_mytest_X.Integrator1_CSTATE_l;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S29>/Constant2' */
      leader_qball2_mytest_B.Constant2 = leader_qball2_mytest_P.Constant2_Value;
    }

    /* MATLAB Function: '<S29>/Kalman Filter - Yaw' incorporates:
     *  TransferFcn: '<S29>/High Pass Filter - Yaw'
     */
    /* MATLAB Function 'DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Yaw': '<S46>:1' */
    /* 0.01; %0.001 */
    /* 0.01;  %0.003 */
    /* '<S46>:1:6' */
    /* 0.03 */
    /*  Calculate the new output */
    /* '<S46>:1:38' */
    leader_qball2_mytest_DW.x_angle +=
      ((leader_qball2_mytest_P.HighPassFilterYaw_C *
        leader_qball2_mytest_X.HighPassFilterYaw_CSTATE +
        leader_qball2_mytest_P.HighPassFilterYaw_D * leader_qball2_mytest_B.Sum
        [2]) - leader_qball2_mytest_DW.x_bias) *
      leader_qball2_mytest_B.Constant2;

    /* '<S46>:1:39' */
    leader_qball2_mytest_DW.P_00 = (leader_qball2_mytest_DW.P_00 -
      (leader_qball2_mytest_DW.P_10 + leader_qball2_mytest_DW.P_01) *
      leader_qball2_mytest_B.Constant2) + 0.01 *
      leader_qball2_mytest_B.Constant2;

    /* '<S46>:1:40' */
    leader_qball2_mytest_DW.P_01 -= leader_qball2_mytest_B.Constant2 *
      leader_qball2_mytest_DW.P_11;

    /* '<S46>:1:41' */
    leader_qball2_mytest_DW.P_10 -= leader_qball2_mytest_B.Constant2 *
      leader_qball2_mytest_DW.P_11;

    /* '<S46>:1:42' */
    leader_qball2_mytest_DW.P_11 += 0.01 * leader_qball2_mytest_B.Constant2;

    /*  Assuming H = [0.98 (effect of gyro) 0.02 (effect of acc)] */
    /* '<S46>:1:45' */
    e = (0.5 * leader_qball2_mytest_DW.x_angle + 0.5 * rtb_Integrator1) -
      leader_qball2_mytest_DW.x_angle;

    /* '<S46>:1:46' */
    /* '<S46>:1:47' */
    K_0 = leader_qball2_mytest_DW.P_00 / (leader_qball2_mytest_DW.P_00 + 0.03);

    /* '<S46>:1:48' */
    K_1 = leader_qball2_mytest_DW.P_10 / (leader_qball2_mytest_DW.P_00 + 0.03);

    /*  Correction */
    /* '<S46>:1:51' */
    leader_qball2_mytest_DW.x_angle += K_0 * e;

    /* '<S46>:1:52' */
    leader_qball2_mytest_DW.x_bias += K_1 * e;

    /* '<S46>:1:53' */
    leader_qball2_mytest_DW.P_00 -= K_0 * leader_qball2_mytest_DW.P_00;

    /* '<S46>:1:54' */
    leader_qball2_mytest_DW.P_01 -= K_0 * leader_qball2_mytest_DW.P_01;

    /* '<S46>:1:55' */
    leader_qball2_mytest_DW.P_10 -= K_1 * leader_qball2_mytest_DW.P_00;

    /* '<S46>:1:56' */
    leader_qball2_mytest_DW.P_11 -= K_1 * leader_qball2_mytest_DW.P_01;

    /* '<S46>:1:58' */
    leader_qball2_mytest_B.angle = leader_qball2_mytest_DW.x_angle;

    /* Gain: '<S29>/Gain8' */
    leader_qball2_mytest_B.Gain8 = leader_qball2_mytest_P.Gain8_Gain *
      leader_qball2_mytest_B.angle;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Gain: '<S42>/Gain1' */
    leader_qball2_mytest_B.Gain1 = leader_qball2_mytest_P.Gain1_Gain_i * cTheta;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Gain: '<S42>/Gain7' incorporates:
     *  MATLAB Function: '<S42>/calc_roll_pitch_asin'
     */
    /* MATLAB Function 'DAQ/Initialize sensors/Sensor Fusion//Filtering/Calculate Roll and Pitch (From Acceleration Data)/calc_roll_pitch_asin': '<S53>:1' */
    /* '<S53>:1:4' */
    /* '<S53>:1:6' */
    leader_qball2_mytest_B.Gain7 = asin(leader_qball2_mytest_B.acc_body[0] / 9.8)
      * leader_qball2_mytest_P.Gain7_Gain;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Gain: '<S42>/Gain2' incorporates:
     *  MATLAB Function: '<S42>/calc_roll_pitch'
     */
    leader_qball2_mytest_B.Gain2 = leader_qball2_mytest_P.Gain2_Gain * roll_acc;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Gain: '<S42>/Gain6' incorporates:
     *  MATLAB Function: '<S42>/calc_roll_pitch_asin'
     */
    leader_qball2_mytest_B.Gain6 = asin(-leader_qball2_mytest_B.acc_body[1] /
      9.8) * leader_qball2_mytest_P.Gain6_Gain;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S47>/Constant' */
      leader_qball2_mytest_B.Constant_d =
        leader_qball2_mytest_P.Constant_Value_mn;
    }

    /* Integrator: '<S47>/Integrator2' */
    rtb_ManualSwitch_l = leader_qball2_mytest_X.Integrator2_CSTATE_o;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S47>/wn' */
      leader_qball2_mytest_B.wn_a = leader_qball2_mytest_P.OMEGA_FILTER;

      /* S-Function (inverse_modulus_block): '<S4>/Inverse Modulus' */
      /* S-Function Block: leader_qball2_mytest/Data from host/Inverse Modulus (inverse_modulus_block) */
      {
        static const real_T sampling_period = 0.002;
        real_T half_range = leader_qball2_mytest_P.InverseModulus_Modulus / 2.0;
        real_T du, dy;
        if (leader_qball2_mytest_DW.InverseModulus_FirstSample) {
          leader_qball2_mytest_DW.InverseModulus_FirstSample = false;
          leader_qball2_mytest_DW.InverseModulus_PreviousInput =
            leader_qball2_mytest_B.StreamClient_o3[9];
        }

        du = (real_T) leader_qball2_mytest_B.StreamClient_o3[9] -
          leader_qball2_mytest_DW.InverseModulus_PreviousInput;
        if (du > half_range) {
          leader_qball2_mytest_DW.InverseModulus_Revolutions =
            leader_qball2_mytest_DW.InverseModulus_Revolutions - 1;
          dy = du - leader_qball2_mytest_P.InverseModulus_Modulus;
        } else if (du < -half_range) {
          leader_qball2_mytest_DW.InverseModulus_Revolutions =
            leader_qball2_mytest_DW.InverseModulus_Revolutions + 1;
          dy = du + leader_qball2_mytest_P.InverseModulus_Modulus;
        } else {
          dy = du;
        }

        leader_qball2_mytest_B.InverseModulus =
          leader_qball2_mytest_B.StreamClient_o3[9] +
          leader_qball2_mytest_DW.InverseModulus_Revolutions *
          leader_qball2_mytest_P.InverseModulus_Modulus;
        leader_qball2_mytest_DW.InverseModulus_PreviousInput =
          leader_qball2_mytest_B.StreamClient_o3[9];
      }

      /* Constant: '<S47>/zt' */
      leader_qball2_mytest_B.zt =
        leader_qball2_mytest_P.SecondOrderLowPassFilter3_input;
    }

    /* Product: '<S47>/Product' incorporates:
     *  Product: '<S47>/Product2'
     *  Sum: '<S47>/Sum'
     *  Sum: '<S47>/Sum1'
     */
    leader_qball2_mytest_B.Product_f = ((leader_qball2_mytest_B.InverseModulus -
      rtb_Integrator1) - rtb_ManualSwitch_l * leader_qball2_mytest_B.Constant_d *
      leader_qball2_mytest_B.zt) * leader_qball2_mytest_B.wn_a;

    /* Product: '<S47>/Product1' */
    leader_qball2_mytest_B.Product1_a = leader_qball2_mytest_B.wn_a *
      rtb_ManualSwitch_l;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S48>/Constant' */
      leader_qball2_mytest_B.Constant_e =
        leader_qball2_mytest_P.Constant_Value_hq;

      /* Constant: '<S48>/x0' */
      leader_qball2_mytest_B.x0_h = leader_qball2_mytest_P.x0_Value_h;
    }

    /* Integrator: '<S48>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK_o.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE_a = leader_qball2_mytest_B.x0_h;
    }

    rtb_ManualSwitch_l = leader_qball2_mytest_X.Integrator1_CSTATE_a;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S48>/zt' */
      leader_qball2_mytest_B.zt_i =
        leader_qball2_mytest_P.SecondOrderLowPassFilter4_input;
    }

    /* Product: '<S48>/Product' incorporates:
     *  Product: '<S48>/Product2'
     *  Sum: '<S48>/Sum'
     *  Sum: '<S48>/Sum1'
     */
    leader_qball2_mytest_B.Product_l = ((leader_qball2_mytest_B.Product -
      rtb_ManualSwitch_l) - rtb_Integrator2_p *
      leader_qball2_mytest_B.Constant_e * leader_qball2_mytest_B.zt_i) *
      leader_qball2_mytest_B.wn;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S49>/Constant' */
      leader_qball2_mytest_B.Constant_p =
        leader_qball2_mytest_P.Constant_Value_h3;

      /* Constant: '<S49>/x0' */
      leader_qball2_mytest_B.x0_j = leader_qball2_mytest_P.x0_Value_c;
    }

    /* Integrator: '<S49>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK_l.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE_ly = leader_qball2_mytest_B.x0_j;
    }

    rtb_ManualSwitch_l = leader_qball2_mytest_X.Integrator1_CSTATE_ly;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S49>/zt' */
      leader_qball2_mytest_B.zt_n =
        leader_qball2_mytest_P.SecondOrderLowPassFilter5_input;
    }

    /* Product: '<S49>/Product' incorporates:
     *  Product: '<S49>/Product2'
     *  Sum: '<S49>/Sum'
     *  Sum: '<S49>/Sum1'
     */
    leader_qball2_mytest_B.Product_d = ((leader_qball2_mytest_B.height -
      rtb_ManualSwitch_l) - rtb_SwitchKp * leader_qball2_mytest_B.Constant_p *
      leader_qball2_mytest_B.zt_n) * leader_qball2_mytest_B.wn_i;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S50>/Constant' */
      leader_qball2_mytest_B.Constant_a =
        leader_qball2_mytest_P.Constant_Value_p0;

      /* Constant: '<S50>/x0' */
      leader_qball2_mytest_B.x0_d = leader_qball2_mytest_P.x0_Value_k;
    }

    /* Integrator: '<S50>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK_ov.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE_lyr =
        leader_qball2_mytest_B.x0_d;
    }

    rtb_ManualSwitch_l = leader_qball2_mytest_X.Integrator1_CSTATE_lyr;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S50>/zt' */
      leader_qball2_mytest_B.zt_nn =
        leader_qball2_mytest_P.SecondOrderLowPassFilter7_input;
    }

    /* Product: '<S50>/Product' incorporates:
     *  Product: '<S50>/Product2'
     *  Sum: '<S50>/Sum'
     *  Sum: '<S50>/Sum1'
     */
    leader_qball2_mytest_B.Product_g =
      ((leader_qball2_mytest_B.sf_EmbeddedMATLABFunction.y - rtb_ManualSwitch_l)
       - rtb_Integrator1_k * leader_qball2_mytest_B.Constant_a *
       leader_qball2_mytest_B.zt_nn) * leader_qball2_mytest_B.wn_g;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* RateTransition: '<S54>/Rate Transition4' */
      if (leader_qball2_mytest_M->Timing.RateInteraction.TID1_2 == 1) {
        leader_qball2_mytest_B.RateTransition4 = leader_qball2_mytest_B.In1_g;
      }

      /* End of RateTransition: '<S54>/Rate Transition4' */

      /* Constant: '<S23>/Accelerometer offsets manually calibrated2' */
      leader_qball2_mytest_B.Accelerometeroffsetsmanuallycal =
        -leader_qball2_mytest_P.g;
    }

    /* Gain: '<S26>/Gain1' incorporates:
     *  MATLAB Function: '<S26>/correct accel mounting'
     */
    leader_qball2_mytest_B.Gain1_m = leader_qball2_mytest_P.Gain1_Gain_b *
      rtb_Sum2_ir;

    /* Gain: '<S26>/Gain' incorporates:
     *  MATLAB Function: '<S26>/correct accel mounting'
     */
    leader_qball2_mytest_B.Gain_e = leader_qball2_mytest_P.Gain_Gain * Phi;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S32>/Constant' */
      leader_qball2_mytest_B.Constant_o =
        leader_qball2_mytest_P.Constant_Value_o;

      /* Constant: '<S32>/wn' */
      leader_qball2_mytest_B.wn_n = leader_qball2_mytest_P.OMEGA_FILTER;

      /* Constant: '<S32>/zt' */
      leader_qball2_mytest_B.zt_j =
        leader_qball2_mytest_P.SecondOrderLowPassFilter2_input;
    }

    /* Product: '<S32>/Product' incorporates:
     *  Integrator: '<S32>/Integrator2'
     *  Product: '<S32>/Product2'
     *  Sum: '<S32>/Sum'
     *  Sum: '<S32>/Sum1'
     */
    leader_qball2_mytest_B.Product_lj[0] =
      ((leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[0] -
        leader_qball2_mytest_B.Integrator1[0]) -
       leader_qball2_mytest_X.Integrator2_CSTATE_i2[0] *
       leader_qball2_mytest_B.Constant_o * leader_qball2_mytest_B.zt_j) *
      leader_qball2_mytest_B.wn_n;
    leader_qball2_mytest_B.Product_lj[1] =
      ((leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[1] -
        leader_qball2_mytest_B.Integrator1[1]) -
       leader_qball2_mytest_X.Integrator2_CSTATE_i2[1] *
       leader_qball2_mytest_B.Constant_o * leader_qball2_mytest_B.zt_j) *
      leader_qball2_mytest_B.wn_n;
    leader_qball2_mytest_B.Product_lj[2] =
      ((leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[2] -
        leader_qball2_mytest_B.Integrator1[2]) -
       leader_qball2_mytest_X.Integrator2_CSTATE_i2[2] *
       leader_qball2_mytest_B.Constant_o * leader_qball2_mytest_B.zt_j) *
      leader_qball2_mytest_B.wn_n;

    /* Product: '<S32>/Product1' incorporates:
     *  Integrator: '<S32>/Integrator2'
     */
    leader_qball2_mytest_B.Product1_e[0] = leader_qball2_mytest_B.wn_n *
      leader_qball2_mytest_X.Integrator2_CSTATE_i2[0];
    leader_qball2_mytest_B.Product1_e[1] = leader_qball2_mytest_B.wn_n *
      leader_qball2_mytest_X.Integrator2_CSTATE_i2[1];
    leader_qball2_mytest_B.Product1_e[2] = leader_qball2_mytest_B.wn_n *
      leader_qball2_mytest_X.Integrator2_CSTATE_i2[2];
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Sum: '<S27>/Sum1' incorporates:
       *  Constant: '<S27>/initial accel'
       */
      rtb_Sum1_je[0] = leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[0]
        - leader_qball2_mytest_P.initialaccel_Value[0];
      rtb_Sum1_je[1] = leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[1]
        - leader_qball2_mytest_P.initialaccel_Value[1];
      rtb_Sum1_je[2] = leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[2]
        - leader_qball2_mytest_P.initialaccel_Value[2];
    }

    /* Clock: '<S27>/Clock' */
    rtb_ManualSwitch_l = leader_qball2_mytest_M->Timing.t[0];
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S27>/Calibration time (s)' */
      leader_qball2_mytest_B.Calibrationtimes_j =
        leader_qball2_mytest_P.Calibrationtimes_Value_e;
    }

    /* RelationalOperator: '<S27>/Relational Operator' */
    leader_qball2_mytest_B.RelationalOperator_o = (rtb_ManualSwitch_l <
      leader_qball2_mytest_B.Calibrationtimes_j);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Enabled SubSystem: '<S27>/Enabled Moving Average' */
      leader_qba_EnabledMovingAverage
        (leader_qball2_mytest_B.RelationalOperator_o, rtb_Sum1_je,
         &leader_qball2_mytest_B.EnabledMovingAverage_e,
         &leader_qball2_mytest_DW.EnabledMovingAverage_e,
         (P_EnabledMovingAverage_leader_T *)
         &leader_qball2_mytest_P.EnabledMovingAverage_e);

      /* End of Outputs for SubSystem: '<S27>/Enabled Moving Average' */

      /* Sum: '<S27>/Sum' */
      leader_qball2_mytest_B.Sum_m[0] =
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[0] -
        leader_qball2_mytest_B.EnabledMovingAverage_e.div[0];
      leader_qball2_mytest_B.Sum_m[1] =
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[1] -
        leader_qball2_mytest_B.EnabledMovingAverage_e.div[1];
      leader_qball2_mytest_B.Sum_m[2] =
        leader_qball2_mytest_B.SwitchBatteryConfigAcceleromter[2] -
        leader_qball2_mytest_B.EnabledMovingAverage_e.div[2];
    }

    /* Saturate: '<S23>/Saturation2' */
    if (leader_qball2_mytest_B.acc_body[2] >
        leader_qball2_mytest_P.Saturation2_UpperSat) {
      K_1 = leader_qball2_mytest_P.Saturation2_UpperSat;
    } else if (leader_qball2_mytest_B.acc_body[2] <
               leader_qball2_mytest_P.Saturation2_LowerSat) {
      K_1 = leader_qball2_mytest_P.Saturation2_LowerSat;
    } else {
      K_1 = leader_qball2_mytest_B.acc_body[2];
    }

    /* Product: '<S23>/Divide' incorporates:
     *  Saturate: '<S23>/Saturation2'
     */
    leader_qball2_mytest_B.Divide =
      leader_qball2_mytest_B.Accelerometeroffsetsmanuallycal / K_1;

    /* TransferFcn: '<S23>/Transfer Fcn' */
    rtb_ManualSwitch_l = 0.0;
    rtb_ManualSwitch_l += leader_qball2_mytest_P.TransferFcn_C *
      leader_qball2_mytest_X.TransferFcn_CSTATE;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* RelationalOperator: '<S60>/Compare' incorporates:
       *  Abs: '<S25>/Abs'
       *  Constant: '<S60>/Constant'
       */
      leader_qball2_mytest_B.Compare_j = (fabs
        (leader_qball2_mytest_B.HILReadWrite1_o2[6]) >=
        leader_qball2_mytest_P.CompareToConstant_const);

      /* RelationalOperator: '<S59>/Compare' incorporates:
       *  Constant: '<S59>/Constant'
       */
      leader_qball2_mytest_B.Compare = (uint8_T)
        (leader_qball2_mytest_B.HILReadWrite1_o1 <=
         leader_qball2_mytest_P.CompareToConstant_const_o);

      /* S-Function (hil_watchdog_block): '<S3>/HIL Watchdog' */

      /* S-Function Block: leader_qball2_mytest/DAQ/HIL Watchdog (hil_watchdog_block) */
      {
        t_error result;
        if (leader_qball2_mytest_DW.HILWatchdog_IsStarted) {
          result = hil_watchdog_reload
            (leader_qball2_mytest_DW.HILInitialize_Card);
        } else {
          result = hil_watchdog_start(leader_qball2_mytest_DW.HILInitialize_Card,
            leader_qball2_mytest_P.HILWatchdog_Timeout);
          if (result == 0) {
            leader_qball2_mytest_DW.HILWatchdog_IsStarted = true;
            result = 1;                /* indicate watchdog has not expired */
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        }

        leader_qball2_mytest_B.HILWatchdog = (result == 0);
      }
    }

    /* Fcn: '<S14>/Fcn' */
    K_0 = leader_qball2_mytest_B.acc_body[0] / 9.81;
    if (K_0 > 1.0) {
      K_0 = 1.0;
    } else {
      if (K_0 < -1.0) {
        K_0 = -1.0;
      }
    }

    leader_qball2_mytest_B.Fcn = asin(K_0);

    /* End of Fcn: '<S14>/Fcn' */

    /* Integrator: '<S14>/Integrator' */
    leader_qball2_mytest_B.Integrator = leader_qball2_mytest_X.Integrator_CSTATE;

    /* TransferFcn: '<S14>/HPF' */
    leader_qball2_mytest_B.HPF = 0.0;
    leader_qball2_mytest_B.HPF += leader_qball2_mytest_P.HPF_C *
      leader_qball2_mytest_X.HPF_CSTATE;
    leader_qball2_mytest_B.HPF += leader_qball2_mytest_P.HPF_D *
      leader_qball2_mytest_B.Integrator;

    /* Fcn: '<S15>/Fcn' incorporates:
     *  Gain: '<S15>/Gain1'
     */
    K_0 = leader_qball2_mytest_P.Gain1_Gain_e * leader_qball2_mytest_B.acc_body
      [1] / 9.81;
    if (K_0 > 1.0) {
      K_0 = 1.0;
    } else {
      if (K_0 < -1.0) {
        K_0 = -1.0;
      }
    }

    leader_qball2_mytest_B.Fcn_a = asin(K_0);

    /* End of Fcn: '<S15>/Fcn' */

    /* Integrator: '<S15>/Integrator' */
    leader_qball2_mytest_B.Integrator_f =
      leader_qball2_mytest_X.Integrator_CSTATE_g;

    /* TransferFcn: '<S15>/HPF1' */
    rtb_Integrator1_k = 0.0;
    rtb_Integrator1_k += leader_qball2_mytest_P.HPF1_C *
      leader_qball2_mytest_X.HPF1_CSTATE;
    rtb_Integrator1_k += leader_qball2_mytest_P.HPF1_D *
      leader_qball2_mytest_B.Integrator_f;

    /* ManualSwitch: '<S15>/Manual Switch' incorporates:
     *  MATLAB Function: '<S42>/calc_roll_pitch'
     */
    if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting == 1) {
      leader_qball2_mytest_B.ManualSwitch = rtb_Integrator1_k;
    } else {
      leader_qball2_mytest_B.ManualSwitch = roll_acc;
    }

    /* End of ManualSwitch: '<S15>/Manual Switch' */

    /* TransferFcn: '<S13>/Low Pass Filter (Filtered Yaw Rate)' */
    K_0 = leader_qball2_mytest_P.LowPassFilterFilteredYawRate_C *
      leader_qball2_mytest_X.LowPassFilterFilteredYawRate_CS;

    /* Switch: '<S13>/Switch - Kd' incorporates:
     *  Gain: '<S13>/Kd - Battery DOWN'
     *  Gain: '<S13>/Kd - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKd_Threshold) {
      rtb_Integrator1_k = leader_qball2_mytest_P.KdYAW_UP * K_0;
    } else {
      rtb_Integrator1_k = leader_qball2_mytest_P.KdYAW_DOWN * K_0;
    }

    /* End of Switch: '<S13>/Switch - Kd' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* RateLimiter: '<S7>/Rate Limiter' incorporates:
       *  Constant: '<S7>/heading command'
       */
      Phi = leader_qball2_mytest_P.headingcommand_Value -
        leader_qball2_mytest_DW.PrevY;
      if (Phi > leader_qball2_mytest_P.RateLimiter_RisingLim) {
        e = leader_qball2_mytest_DW.PrevY +
          leader_qball2_mytest_P.RateLimiter_RisingLim;
      } else if (Phi < leader_qball2_mytest_P.RateLimiter_FallingLim) {
        e = leader_qball2_mytest_DW.PrevY +
          leader_qball2_mytest_P.RateLimiter_FallingLim;
      } else {
        e = leader_qball2_mytest_P.headingcommand_Value;
      }

      leader_qball2_mytest_DW.PrevY = e;

      /* End of RateLimiter: '<S7>/Rate Limiter' */

      /* Bias: '<S13>/Bias' */
      leader_qball2_mytest_B.Bias = e + leader_qball2_mytest_P.Bias_Bias;
    }

    /* Sum: '<S13>/Sum4' */
    leader_qball2_mytest_B.Sum4 = leader_qball2_mytest_B.Bias -
      leader_qball2_mytest_B.angle;

    /* Switch: '<S13>/Switch - Kp' incorporates:
     *  Gain: '<S13>/Kp - Battery DOWN'
     *  Gain: '<S13>/Kp - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKp_Threshold) {
      rtb_SwitchKp = leader_qball2_mytest_P.KpYAW_UP *
        leader_qball2_mytest_B.Sum4;
    } else {
      rtb_SwitchKp = leader_qball2_mytest_P.KpYAW_DOWN *
        leader_qball2_mytest_B.Sum4;
    }

    /* End of Switch: '<S13>/Switch - Kp' */

    /* Clock: '<S64>/Clock' */
    rtb_Integrator2_p = leader_qball2_mytest_M->Timing.t[0];
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S70>/Constant' */
      leader_qball2_mytest_B.Constant_a0 =
        leader_qball2_mytest_P.CompareToConstant_const_d;

      /* RelationalOperator: '<S71>/Compare' incorporates:
       *  Constant: '<S71>/Constant'
       */
      leader_qball2_mytest_B.Compare_pf =
        (leader_qball2_mytest_B.StreamClient_o3[1] >
         leader_qball2_mytest_P.CompareToConstant1_const);
    }

    /* Logic: '<S64>/Logical Operator' incorporates:
     *  RelationalOperator: '<S70>/Compare'
     */
    leader_qball2_mytest_B.LogicalOperator = ((rtb_Integrator2_p >
      leader_qball2_mytest_B.Constant_a0) && leader_qball2_mytest_B.Compare_pf);

    /* Product: '<S132>/Product' incorporates:
     *  Trigonometry: '<S132>/Trigonometric Function'
     *  Trigonometry: '<S132>/Trigonometric Function2'
     */
    rtb_Integrator2_p = cos(leader_qball2_mytest_B.angle_f) * cos
      (leader_qball2_mytest_B.angle_m) * leader_qball2_mytest_B.y;

    /* Saturate: '<S119>/Saturation3' */
    if (rtb_Integrator2_p > leader_qball2_mytest_P.Saturation3_UpperSat) {
      rtb_Integrator2_p = leader_qball2_mytest_P.Saturation3_UpperSat;
    } else {
      if (rtb_Integrator2_p < leader_qball2_mytest_P.Saturation3_LowerSat) {
        rtb_Integrator2_p = leader_qball2_mytest_P.Saturation3_LowerSat;
      }
    }

    /* End of Saturate: '<S119>/Saturation3' */

    /* ManualSwitch: '<S119>/Manual Switch' */
    if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting_m == 1) {
      cTheta = rtb_Integrator2_p;
    } else {
      cTheta = leader_qball2_mytest_B.HeightEstimateBiasEstimateRefer;
    }

    /* End of ManualSwitch: '<S119>/Manual Switch' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S139>/wn' */
      leader_qball2_mytest_B.wn_p = leader_qball2_mytest_P.OMEGA_DIFF;
    }

    /* Integrator: '<S139>/Integrator2' */
    rtb_Integrator2_p = leader_qball2_mytest_X.Integrator2_CSTATE_e;

    /* Product: '<S139>/Product1' */
    leader_qball2_mytest_B.Product1_n = leader_qball2_mytest_B.wn_p *
      rtb_Integrator2_p;

    /* Sum: '<S131>/Sum1' */
    e = leader_qball2_mytest_B.Product1_n - leader_qball2_mytest_B.Product1_k;

    /* Switch: '<S131>/Switch - Kd' incorporates:
     *  Gain: '<S131>/Kd - Battery DOWN'
     *  Gain: '<S131>/Kd - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKd_Threshold_p) {
      leader_qball2_mytest_B.SwitchKd = leader_qball2_mytest_P.KdHEIGHT_UP * e;
    } else {
      leader_qball2_mytest_B.SwitchKd = leader_qball2_mytest_P.KdHEIGHT_DOWN * e;
    }

    /* End of Switch: '<S131>/Switch - Kd' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S135>/vmax takeoff' */
      leader_qball2_mytest_B.vmaxtakeoff =
        leader_qball2_mytest_P.vmaxtakeoff_Value;

      /* Constant: '<S135>/amax takeoff' */
      leader_qball2_mytest_B.amaxtakeoff =
        leader_qball2_mytest_P.amaxtakeoff_Value;

      /* Constant: '<S136>/Constant' */
      leader_qball2_mytest_B.Constant_m =
        leader_qball2_mytest_P.CompareToConstant_const_k;
    }

    /* RelationalOperator: '<S136>/Compare' */
    rtb_Compare = (uint8_T)(cTheta <= leader_qball2_mytest_B.Constant_m);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S129>/Constant' */
      leader_qball2_mytest_B.Constant_es =
        leader_qball2_mytest_P.Constant_Value_aa;

      /* Outputs for Enabled SubSystem: '<S66>/Enabled Subsystem Latch Output High' incorporates:
       *  EnablePort: '<S79>/Enable'
       */
      /* RelationalOperator: '<S74>/Compare' incorporates:
       *  Constant: '<S74>/Constant'
       *  Constant: '<S79>/Constant'
       */
      if ((leader_qball2_mytest_B.HILReadWrite1_o1 <=
           leader_qball2_mytest_P.CompareToConstant_const_c) > 0) {
        leader_qball2_mytest_B.Constant_om =
          leader_qball2_mytest_P.Constant_Value_m;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystemLatchOutputHigh);
        }
      }

      /* End of RelationalOperator: '<S74>/Compare' */
      /* End of Outputs for SubSystem: '<S66>/Enabled Subsystem Latch Output High' */

      /* Logic: '<S66>/Logical Operator' */
      rtb_LogicalOperator = !leader_qball2_mytest_B.StreamClient_o4;

      /* Outputs for Enabled SubSystem: '<S66>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S76>/Enable'
       */
      if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
        if (rtb_LogicalOperator) {
          if (!leader_qball2_mytest_DW.EnabledSubsystem_MODE) {
            /* InitializeConditions for DiscreteIntegrator: '<S76>/Discrete-Time Integrator' */
            leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE =
              leader_qball2_mytest_P.DiscreteTimeIntegrator_IC_m;
            leader_qball2_mytest_DW.EnabledSubsystem_MODE = true;
          }
        } else {
          if (leader_qball2_mytest_DW.EnabledSubsystem_MODE) {
            /* Disable for Outport: '<S76>/timeout' */
            leader_qball2_mytest_B.RelationalOperator_og =
              leader_qball2_mytest_P.timeout_Y0_k;
            leader_qball2_mytest_DW.EnabledSubsystem_MODE = false;
          }
        }
      }

      if (leader_qball2_mytest_DW.EnabledSubsystem_MODE) {
        /* RelationalOperator: '<S76>/Relational Operator' incorporates:
         *  Constant: '<S66>/Constant2'
         *  DiscreteIntegrator: '<S76>/Discrete-Time Integrator'
         */
        leader_qball2_mytest_B.RelationalOperator_og =
          (leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE >=
           leader_qball2_mytest_P.Constant2_Value_a);

        /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S76>/Constant'
         */
        leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE +=
          leader_qball2_mytest_P.DiscreteTimeIntegrator_gainva_a *
          leader_qball2_mytest_P.Constant_Value_n;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC);
        }
      }

      /* End of Outputs for SubSystem: '<S66>/Enabled Subsystem' */

      /* Constant: '<S5>/CLOSED-LOOP ON' */
      leader_qball2_mytest_B.CLOSEDLOOPON =
        leader_qball2_mytest_P.CLOSEDLOOPON_Value;

      /* ManualSwitch: '<S5>/Manual Switch2' incorporates:
       *  Constant: '<S5>/JOYSTICK ON'
       */
      if (leader_qball2_mytest_P.ManualSwitch2_CurrentSetting == 1) {
        leader_qball2_mytest_B.ManualSwitch2 =
          leader_qball2_mytest_B.CLOSEDLOOPON;
      } else {
        leader_qball2_mytest_B.ManualSwitch2 =
          leader_qball2_mytest_P.JOYSTICKON_Value;
      }

      /* End of ManualSwitch: '<S5>/Manual Switch2' */

      /* RelationalOperator: '<S75>/Compare' incorporates:
       *  Constant: '<S75>/Constant'
       */
      rtb_Compare_a = (leader_qball2_mytest_B.StreamClient_o3[6] <
                       leader_qball2_mytest_P.CompareToConstant1_const_c);

      /* Outputs for Enabled SubSystem: '<S66>/Enabled Subsystem1' */

      /* Constant: '<S66>/Constant1' */
      leader_qball2_EnabledSubsystem1(leader_qball2_mytest_M, rtb_Compare_a,
        leader_qball2_mytest_P.Constant1_Value_n,
        &leader_qball2_mytest_B.EnabledSubsystem1,
        &leader_qball2_mytest_DW.EnabledSubsystem1,
        (P_EnabledSubsystem1_leader_qb_T *)
        &leader_qball2_mytest_P.EnabledSubsystem1);

      /* End of Outputs for SubSystem: '<S66>/Enabled Subsystem1' */

      /* Logic: '<S66>/Logical Operator5' */
      leader_qball2_mytest_B.LogicalOperator5 =
        ((leader_qball2_mytest_B.ManualSwitch2 != 0.0) &&
         leader_qball2_mytest_B.EnabledSubsystem1.RelationalOperator);

      /* Outputs for Enabled SubSystem: '<S66>/Enabled Subsystem2' incorporates:
       *  EnablePort: '<S78>/Enable'
       */
      /* Logic: '<S66>/Logical Operator1' incorporates:
       *  Constant: '<S78>/Constant'
       */
      if (leader_qball2_mytest_B.RelationalOperator_og ||
          leader_qball2_mytest_B.LogicalOperator5) {
        leader_qball2_mytest_B.Constant_mq =
          leader_qball2_mytest_P.Constant_Value_c;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystem2_SubsysRanBC);
        }
      }

      /* End of Logic: '<S66>/Logical Operator1' */
      /* End of Outputs for SubSystem: '<S66>/Enabled Subsystem2' */

      /* Logic: '<S66>/Logical Operator2' */
      leader_qball2_mytest_B.LogicalOperator2 =
        ((leader_qball2_mytest_B.Constant_om != 0.0) ||
         (leader_qball2_mytest_B.Constant_mq != 0.0));

      /* Outputs for Enabled SubSystem: '<S129>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S133>/Enable'
       */
      if (leader_qball2_mytest_B.LogicalOperator2) {
        /* Constant: '<S133>/Constant' */
        leader_qball2_mytest_B.Constant_hf =
          leader_qball2_mytest_P.Constant_Value_l;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_l);
        }
      }

      /* End of Outputs for SubSystem: '<S129>/Enabled Subsystem' */

      /* Gain: '<S92>/Slider Gain' incorporates:
       *  Constant: '<S7>/Constant'
       */
      leader_qball2_mytest_B.SliderGain = leader_qball2_mytest_P.SliderGain_gain
        * leader_qball2_mytest_P.Constant_Value_e;
    }

    /* SignalGenerator: '<S7>/Signal Generator' */
    K_1 = leader_qball2_mytest_P.SignalGenerator_Frequency *
      leader_qball2_mytest_M->Timing.t[0];
    if (K_1 - floor(K_1) >= 0.5) {
      rtb_Integrator1_i = leader_qball2_mytest_P.SignalGenerator_Amplitude;
    } else {
      rtb_Integrator1_i = -leader_qball2_mytest_P.SignalGenerator_Amplitude;
    }

    /* End of SignalGenerator: '<S7>/Signal Generator' */

    /* Sum: '<S7>/Sum' */
    rtb_Integrator1_i += leader_qball2_mytest_B.SliderGain;

    /* Saturate: '<S7>/Saturation2' */
    if (rtb_Integrator1_i > leader_qball2_mytest_P.LIMIT_MAX_HEIGHT) {
      e = leader_qball2_mytest_P.LIMIT_MAX_HEIGHT;
    } else if (rtb_Integrator1_i < leader_qball2_mytest_P.LIMIT_MIN_HEIGHT) {
      e = leader_qball2_mytest_P.LIMIT_MIN_HEIGHT;
    } else {
      e = rtb_Integrator1_i;
    }

    /* End of Saturate: '<S7>/Saturation2' */

    /* RateLimiter: '<S7>/Rate Limiter3' */
    if (leader_qball2_mytest_DW.LastMajorTime == (rtInf)) {
      leader_qball2_mytest_B.RateLimiter3 = e;
    } else {
      K_0 = leader_qball2_mytest_M->Timing.t[0] -
        leader_qball2_mytest_DW.LastMajorTime;
      K_1 = K_0 * leader_qball2_mytest_P.LIMIT_RATE_HEIGHT;
      Phi = e - leader_qball2_mytest_DW.PrevY_k;
      if (Phi > K_1) {
        leader_qball2_mytest_B.RateLimiter3 = leader_qball2_mytest_DW.PrevY_k +
          K_1;
      } else {
        K_0 *= -leader_qball2_mytest_P.LIMIT_RATE_HEIGHT;
        if (Phi < K_0) {
          leader_qball2_mytest_B.RateLimiter3 = leader_qball2_mytest_DW.PrevY_k
            + K_0;
        } else {
          leader_qball2_mytest_B.RateLimiter3 = e;
        }
      }
    }

    /* End of RateLimiter: '<S7>/Rate Limiter3' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* MATLAB Function: '<S116>/MATLAB Function' incorporates:
       *  Constant: '<S116>/Constant1'
       */
      /* MATLAB Function 'Throttle and height control/Height joystick adjust/MATLAB Function': '<S120>:1' */
      /* '<S120>:1:15' */
      /* '<S120>:1:16' */
      switch ((int32_T)leader_qball2_mytest_DW.state_h) {
       case 0:
        /*  Idle */
        /* '<S120>:1:20' */
        leader_qball2_mytest_B.enable = 0.0;
        if (leader_qball2_mytest_B.StreamClient_o3[1] > 0.2) {
          /* '<S120>:1:21' */
          /* '<S120>:1:22' */
          leader_qball2_mytest_DW.state_h = 1.0;

          /*  armed */
        }
        break;

       case 1:
        /*  Armed */
        /* '<S120>:1:25' */
        leader_qball2_mytest_B.enable = 0.0;

        /* '<S120>:1:26' */
        leader_qball2_mytest_DW.counter++;
        if (leader_qball2_mytest_DW.counter >= 3.5 /
            leader_qball2_mytest_P.Constant1_Value_m) {
          /* '<S120>:1:27' */
          /* '<S120>:1:28' */
          leader_qball2_mytest_DW.state_h = 2.0;

          /*  Active */
          /* '<S120>:1:29' */
          leader_qball2_mytest_DW.counter = 0.0;
        }

        if (leader_qball2_mytest_B.StreamClient_o3[1] < 0.2) {
          /* '<S120>:1:31' */
          /* '<S120>:1:32' */
          leader_qball2_mytest_DW.state_h = 0.0;

          /* '<S120>:1:33' */
          leader_qball2_mytest_DW.counter = 0.0;
        }
        break;

       case 2:
        /*  Active */
        /* '<S120>:1:36' */
        leader_qball2_mytest_B.enable = 1.0;
        if (leader_qball2_mytest_B.StreamClient_o3[1] < 0.2) {
          /* '<S120>:1:37' */
          /* '<S120>:1:38' */
          leader_qball2_mytest_DW.state_h = 0.0;
        }
        break;

       default:
        /* '<S120>:1:41' */
        leader_qball2_mytest_B.enable = 0.0;

        /* '<S120>:1:42' */
        leader_qball2_mytest_DW.state_h = 0.0;

        /* '<S120>:1:43' */
        leader_qball2_mytest_DW.counter = 0.0;
        break;
      }

      /* End of MATLAB Function: '<S116>/MATLAB Function' */

      /* Constant: '<S116>/Constant' */
      leader_qball2_mytest_B.Constant_g =
        leader_qball2_mytest_P.Constant_Value_c2;
    }

    /* Switch: '<S129>/Switch' incorporates:
     *  Switch: '<S116>/Switch'
     */
    if (leader_qball2_mytest_B.Constant_hf >=
        leader_qball2_mytest_P.Switch_Threshold_g) {
      rtb_Switch = leader_qball2_mytest_B.Constant_es;
    } else if (leader_qball2_mytest_B.enable >=
               leader_qball2_mytest_P.Switch_Threshold_ak) {
      /* Switch: '<S116>/Switch' */
      rtb_Switch = leader_qball2_mytest_B.RateLimiter3;
    } else {
      rtb_Switch = leader_qball2_mytest_B.Constant_g;
    }

    /* End of Switch: '<S129>/Switch' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S137>/Constant' */
      leader_qball2_mytest_B.Constant_j =
        leader_qball2_mytest_P.CompareToConstant1_const_h;

      /* Constant: '<S135>/vmax flight' */
      leader_qball2_mytest_B.vmaxflight =
        leader_qball2_mytest_P.vmaxflight_Value;

      /* Constant: '<S135>/amax flight' */
      leader_qball2_mytest_B.amaxflight =
        leader_qball2_mytest_P.amaxflight_Value;
    }

    /* Switch: '<S135>/Switch' incorporates:
     *  Logic: '<S135>/Logical Operator'
     *  RelationalOperator: '<S137>/Compare'
     */
    if ((rtb_Compare != 0) || (rtb_Switch <= leader_qball2_mytest_B.Constant_j))
    {
      rtb_Switch_j[0] = leader_qball2_mytest_B.vmaxtakeoff;
      rtb_Switch_j[1] = leader_qball2_mytest_B.amaxtakeoff;
    } else {
      rtb_Switch_j[0] = leader_qball2_mytest_B.vmaxflight;
      rtb_Switch_j[1] = leader_qball2_mytest_B.amaxflight;
    }

    /* End of Switch: '<S135>/Switch' */

    /* S-Function (continuous_sigmoid_block): '<S130>/Continuous Sigmoid' */
    {
    }

    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* S-Function (continuous_sigmoid_block): '<S130>/Continuous Sigmoid' */
      {
        /* Determine the correct step size for the output ports */

        /*  Check if the target position has changed or if it is the first
           simulation step, in which case we need to compute the initial
           trajectory. */
        if (leader_qball2_mytest_DW.ContinuousSigmoid_Flag == 1 ||
            leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time == 0) {
          /*  Read the new position and reset the flag */
          leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_XD]
            = leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Target;
          leader_qball2_mytest_DW.ContinuousSigmoid_Flag = 0;

          /*  Calculate a single step using the new trajectory to account for the target
             change that occured at the previous sample (i.e., there is a one sample delay
             between the point where the target position changes and the trajectory changes
             based on the new target)    */
          if (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time == 0) {
            /*  Do not update the trajectory since we are at time 0 in simulation
               (leave t = 0)   */
          } else {
            /*  Set the relative time to one step size so that a single step
               is computed for the new trajectory  */

            /*  Set the default values in sigmoid_parameters to the trajectory
               state at the last time step.    */
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X0]
              = leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.PPos;
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_V0]
              = leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.PVel;
            leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time = 0.002;
          }

          /*  Calculate the new trajectory    */
          sigmoid_calculate_trajectory
            (&leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[0], 0,
             leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X0],
             leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_V0],
             rtb_Switch_j[1], rtb_Switch_j[0]);
        }

        /* Mark the target as not reached */
        leader_qball2_mytest_B.ContinuousSigmoid_o4 = 0;
        if (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time <
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T1])
        {
          leader_qball2_mytest_B.ContinuousSigmoid_o3 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_AP];
          leader_qball2_mytest_B.ContinuousSigmoid_o2 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_V0]
            + leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_AP]
            * leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time;
          leader_qball2_mytest_B.ContinuousSigmoid_o1 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X0]
            + (leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_V0]
               + 0.5 *
               leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_AP]
               * leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time) *
            leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time;
        } else if (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time <
                   leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T2])
        {
          leader_qball2_mytest_B.ContinuousSigmoid_o3 = 0;
          leader_qball2_mytest_B.ContinuousSigmoid_o2 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_VP];
          leader_qball2_mytest_B.ContinuousSigmoid_o1 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X1]
            + leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_VP]
            * (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time -
               leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T1]);
        } else if (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time <
                   leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T3])
        {
          leader_qball2_mytest_B.ContinuousSigmoid_o3 =
            -leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_AP];
          leader_qball2_mytest_B.ContinuousSigmoid_o2 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_VP]
            - leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_AP]
            * (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time -
               leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T2]);
          leader_qball2_mytest_B.ContinuousSigmoid_o1 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X2]
            + (leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_VP]
               - 0.5 *
               leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_AP]
               * (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time -
                  leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T2]))
            * (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time -
               leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T2]);
        } else {
          leader_qball2_mytest_B.ContinuousSigmoid_o3 = 0;
          leader_qball2_mytest_B.ContinuousSigmoid_o2 = 0;
          leader_qball2_mytest_B.ContinuousSigmoid_o1 =
            leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_XD];/* always attainable */

          /* Mark the target as reached after the hold-off period */
          if ((leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time -
               leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T3])
              >=
              leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_HOLD_OFF])
            leader_qball2_mytest_B.ContinuousSigmoid_o4 = 1;/* Assert Done signal */
        }

        /*  Save the current position/velocity to be used next time step (possibly) */
        leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.PPos =
          leader_qball2_mytest_B.ContinuousSigmoid_o1;
        leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.PVel =
          leader_qball2_mytest_B.ContinuousSigmoid_o2;

        /*  Increment the relative time RWork to the NEXT time step */
        leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time += 0.002;
      }
    }

    /* Sum: '<S131>/Sum3' */
    rtb_SwitchBatteryConfigGyroTo_0 =
      leader_qball2_mytest_B.ContinuousSigmoid_o1 - cTheta;

    /* Switch: '<S131>/Switch - Kp' incorporates:
     *  Gain: '<S131>/Kp - Battery DOWN'
     *  Gain: '<S131>/Kp - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKp_Threshold_c) {
      leader_qball2_mytest_B.SwitchKp = leader_qball2_mytest_P.KpHEIGHT_UP *
        rtb_SwitchBatteryConfigGyroTo_0;
    } else {
      leader_qball2_mytest_B.SwitchKp = leader_qball2_mytest_P.KpHEIGHT_DOWN *
        rtb_SwitchBatteryConfigGyroTo_0;
    }

    /* End of Switch: '<S131>/Switch - Kp' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Memory: '<S138>/Memory' */
      leader_qball2_mytest_B.Memory =
        leader_qball2_mytest_DW.Memory_PreviousInput_p;
    }

    /* Logic: '<S138>/Logical Operator2' incorporates:
     *  Logic: '<S138>/Logical Operator1'
     */
    leader_qball2_mytest_B.LogicalOperator2_o =
      ((!leader_qball2_mytest_B.LogicalOperator) &&
       (leader_qball2_mytest_B.Memory != 0.0));

    /* Integrator: '<S131>/Integrator'
     *
     * Regarding '<S131>/Integrator':
     *  Limited Integrator
     */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      ZCEventType zcEvent;
      zcEvent = ((ZCEventType) ((leader_qball2_mytest_B.LogicalOperator2_o !=
        (leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE == POS_ZCSIG)) &&
                  (leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE !=
                   UNINITIALIZED_ZCSIG)));

      /* evaluate zero-crossings and the level of the reset signal */
      leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE = (ZCSigState)
        leader_qball2_mytest_B.LogicalOperator2_o;
      if (zcEvent || leader_qball2_mytest_B.LogicalOperator2_o) {
        leader_qball2_mytest_X.Integrator_CSTATE_ga =
          leader_qball2_mytest_P.Integrator_IC_f;
      }
    }

    if (leader_qball2_mytest_X.Integrator_CSTATE_ga >=
        leader_qball2_mytest_P.Integrator_UpperSat ) {
      leader_qball2_mytest_X.Integrator_CSTATE_ga =
        leader_qball2_mytest_P.Integrator_UpperSat;
    } else if (leader_qball2_mytest_X.Integrator_CSTATE_ga <=
               leader_qball2_mytest_P.Integrator_LowerSat ) {
      leader_qball2_mytest_X.Integrator_CSTATE_ga =
        leader_qball2_mytest_P.Integrator_LowerSat;
    }

    leader_qball2_mytest_B.Integrator_a =
      leader_qball2_mytest_X.Integrator_CSTATE_ga;

    /* Sum: '<S131>/Sum4' */
    rtb_Integrator1_i = (leader_qball2_mytest_B.SwitchKd +
                         leader_qball2_mytest_B.SwitchKp) +
      leader_qball2_mytest_B.Integrator_a;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S131>/Constant1' */
      leader_qball2_mytest_B.Constant1_l =
        leader_qball2_mytest_P.Constant1_Value_f;
    }

    /* ManualSwitch: '<S131>/Manual Switch' */
    if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting_f != 1) {
      rtb_Integrator1_i = leader_qball2_mytest_B.Constant1_l;
    }

    /* End of ManualSwitch: '<S131>/Manual Switch' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S7>/Throttle Trim' */
      leader_qball2_mytest_B.ThrottleTrim = leader_qball2_mytest_P.TRIM_THROTTLE;
    }

    /* Sum: '<S131>/Sum2' */
    K_0 = rtb_Integrator1_i + leader_qball2_mytest_B.ThrottleTrim;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S131>/Constant' */
      leader_qball2_mytest_B.Constant_ov =
        leader_qball2_mytest_P.Constant_Value_bn;
    }

    /* MATLAB Function: '<S131>/User-controller landing state machine' */
    /* MATLAB Function 'Throttle and height control/height control/sonar controller/User-controller landing state machine': '<S140>:1' */
    /*  This block supports the Embedded MATLAB subset. */
    /*  See the help menu for details.  */
    /*  state variable */
    /*    0 : landed state. Motors off until cmd > 0. */
    /*    1 : fly state. Motors enabled until cmd <= 0 AND height <= 0.20 m. */
    /*  c variable: represents the latched control signal. */
    /* '<S140>:1:20' */
    leader_qball2_mytest_B.land = 0.0;
    switch ((int32_T)leader_qball2_mytest_DW.state) {
     case 0:
      if ((int32_T)leader_qball2_mytest_B.LogicalOperator > 0) {
        /* '<S140>:1:24' */
        /* '<S140>:1:25' */
        leader_qball2_mytest_DW.state = 1.0;

        /* '<S140>:1:26' */
        leader_qball2_mytest_DW.c = K_0;

        /* '<S140>:1:27' */
      } else {
        /* '<S140>:1:29' */
        leader_qball2_mytest_B.land = 1.0;

        /* '<S140>:1:30' */
        leader_qball2_mytest_DW.c -= leader_qball2_mytest_B.Constant_ov;
        if (leader_qball2_mytest_DW.c < 0.0) {
          /* '<S140>:1:31' */
          /* '<S140>:1:32' */
          leader_qball2_mytest_DW.c = 0.0;
        }

        /* '<S140>:1:34' */
        K_0 = leader_qball2_mytest_DW.c;
      }
      break;

     case 1:
      /* '<S140>:1:38' */
      leader_qball2_mytest_DW.c = K_0;

      /* '<S140>:1:39' */
      if (((int32_T)leader_qball2_mytest_B.LogicalOperator <= 0) && (cTheta <=
           0.08)) {
        /* '<S140>:1:40' */
        /* '<S140>:1:41' */
        leader_qball2_mytest_DW.state = 0.0;

        /* '<S140>:1:42' */
        leader_qball2_mytest_B.land = 1.0;
      }
      break;

     default:
      /* '<S140>:1:46' */
      K_0 = leader_qball2_mytest_DW.c;
      break;
    }

    /* End of MATLAB Function: '<S131>/User-controller landing state machine' */

    /* Product: '<S117>/Divide' */
    e = rtb_ManualSwitch_l * leader_qball2_mytest_B.StreamClient_o3[1];
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S117>/height command1' */
      leader_qball2_mytest_B.heightcommand1 =
        leader_qball2_mytest_P.joystick_range_min;

      /* Constant: '<S117>/height command2' */
      leader_qball2_mytest_B.heightcommand2 =
        leader_qball2_mytest_P.joystick_range_max;
    }

    /* MATLAB Function: '<S117>/Joystick to Throttle  Mapping' */
    /* MATLAB Function 'Throttle and height control/Joystick mode throttle/Joystick to Throttle  Mapping': '<S121>:1' */
    /*  This block supports the Embedded MATLAB subset. */
    /*  See the help menu for details.  */
    /*  l1 = .6; */
    /*  l2 = .9; */
    if (e < 0.1) {
      /* '<S121>:1:7' */
      /* '<S121>:1:8' */
      e = 0.0;

      /* .8/.1*u */
    } else {
      /* '<S121>:1:10' */
      e = (leader_qball2_mytest_B.heightcommand2 -
           leader_qball2_mytest_B.heightcommand1) / 0.9 * (e - 0.1) +
        leader_qball2_mytest_B.heightcommand1;
    }

    /* End of MATLAB Function: '<S117>/Joystick to Throttle  Mapping' */

    /* Switch: '<S11>/Switch' incorporates:
     *  Gain: '<S117>/Joystick throttle scaling'
     */
    if (leader_qball2_mytest_B.CLOSEDLOOPON >=
        leader_qball2_mytest_P.Switch_Threshold_h) {
      leader_qball2_mytest_B.Switch = K_0;
    } else {
      leader_qball2_mytest_B.Switch =
        leader_qball2_mytest_P.Joystickthrottlescaling_Gain * e;
    }

    /* End of Switch: '<S11>/Switch' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S122>/Constant1' */
      leader_qball2_mytest_B.Constant1_o =
        leader_qball2_mytest_P.Constant1_Value_j;

      /* Constant: '<S122>/land throttle target' */
      leader_qball2_mytest_B.landthrottletarget =
        leader_qball2_mytest_P.landthrottletarget_Value;
    }

    /* S-Function (sigmoid_path): '<S124>/Sigmoid Path' */
    {
    }

    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* S-Function (sigmoid_path): '<S124>/Sigmoid Path' */
      {
        /* Determine the correct step size for the output ports */

        /*  Check if the target position has changed or if it is the first
           simulation step, in which case we need to compute the initial
           trajectory. */
        if (leader_qball2_mytest_DW.SigmoidPath_Flag == 1) {
          /*  Read the new sigmoid parameters and reset the flag */
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T1] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_T1];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T2] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_T2];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T3] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_T3];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X0] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_X0];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X1] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_X1];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X2] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_X2];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_XD] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_XD];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_V0] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_V0];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_VP] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_VP];
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP] =
            leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_AP];
          leader_qball2_mytest_DW.SigmoidPath_Flag = 0;

          /*  Reset the relative time to one step (since the sigmoid params actually changed
             last step)  */
          leader_qball2_mytest_DW.SigmoidPath_RWORK.Time = 0.002;

          /* Reset the hold-off value */
          leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_HOLD_OFF] =
            leader_qball2_mytest_P.TriggeredSigmoid_hold_off;
        }

        /* Mark the target as not reached */
        leader_qball2_mytest_B.SigmoidPath_o4 = 0;
        if (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time == 0) {
          leader_qball2_mytest_B.SigmoidPath_o3 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP];
          leader_qball2_mytest_B.SigmoidPath_o2 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_V0];
          leader_qball2_mytest_B.SigmoidPath_o1 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X0];

          /*  Check if we are starting this trajectory at the target and the hold-off
             time is zero. If so, and the velocity and acceleration are zero, raise
             the Done signal cause we're there!  */
          if (leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X0] ==
              leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_XD] &&
              leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_HOLD_OFF]
              == 0
              && leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_V0] ==
              0 && leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP]
              == 0) {
            leader_qball2_mytest_B.SigmoidPath_o4 = 1;
          }
        } else if (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time <
                   leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T1])
        {
          leader_qball2_mytest_B.SigmoidPath_o3 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP];
          leader_qball2_mytest_B.SigmoidPath_o2 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_V0] +
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP] *
            leader_qball2_mytest_DW.SigmoidPath_RWORK.Time;
          leader_qball2_mytest_B.SigmoidPath_o1 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X0] +
            (leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_V0] +
             0.5 * leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP]
             * leader_qball2_mytest_DW.SigmoidPath_RWORK.Time) *
            leader_qball2_mytest_DW.SigmoidPath_RWORK.Time;
        } else if (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time <
                   leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T2])
        {
          leader_qball2_mytest_B.SigmoidPath_o3 = 0;
          leader_qball2_mytest_B.SigmoidPath_o2 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_VP];
          leader_qball2_mytest_B.SigmoidPath_o1 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X1] +
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_VP] *
            (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time -
             leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T1]);
        } else if (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time <
                   leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T3])
        {
          leader_qball2_mytest_B.SigmoidPath_o3 =
            -leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP];
          leader_qball2_mytest_B.SigmoidPath_o2 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_VP] -
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP] *
            (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time -
             leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T2]);
          leader_qball2_mytest_B.SigmoidPath_o1 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X2] +
            (leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_VP] -
             0.5 * leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP]
             * (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time -
                leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T2]))
            * (leader_qball2_mytest_DW.SigmoidPath_RWORK.Time -
               leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T2]);
        } else {
          leader_qball2_mytest_B.SigmoidPath_o3 = 0;
          leader_qball2_mytest_B.SigmoidPath_o2 = 0;
          leader_qball2_mytest_B.SigmoidPath_o1 =
            leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_XD];/* always attainable */

          /* Mark the target as reached after the hold-off period */
          if ((leader_qball2_mytest_DW.SigmoidPath_RWORK.Time -
               leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T3]) >=
              leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_HOLD_OFF])
            leader_qball2_mytest_B.SigmoidPath_o4 = 1;/* Assert Done signal */
        }

        /*  Increment the relative time RWork to the NEXT time step */
        leader_qball2_mytest_DW.SigmoidPath_RWORK.Time += 0.002;
      }

      /* ManualSwitch: '<S123>/Manual Switch' incorporates:
       *  Constant: '<S123>/Constant1'
       */
      if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting_l == 1) {
        leader_qball2_mytest_B.ManualSwitch_a = leader_qball2_mytest_B.y;
      } else {
        leader_qball2_mytest_B.ManualSwitch_a =
          leader_qball2_mytest_P.Constant1_Value_c;
      }

      /* End of ManualSwitch: '<S123>/Manual Switch' */
    }

    /* Derivative: '<S123>/Derivative' */
    if ((leader_qball2_mytest_DW.TimeStampA_e >=
         leader_qball2_mytest_M->Timing.t[0]) &&
        (leader_qball2_mytest_DW.TimeStampB_c >=
         leader_qball2_mytest_M->Timing.t[0])) {
      rtb_Integrator1_i = 0.0;
    } else {
      e = leader_qball2_mytest_DW.TimeStampA_e;
      lastU = &leader_qball2_mytest_DW.LastUAtTimeA_a;
      if (leader_qball2_mytest_DW.TimeStampA_e <
          leader_qball2_mytest_DW.TimeStampB_c) {
        if (leader_qball2_mytest_DW.TimeStampB_c <
            leader_qball2_mytest_M->Timing.t[0]) {
          e = leader_qball2_mytest_DW.TimeStampB_c;
          lastU = &leader_qball2_mytest_DW.LastUAtTimeB_l;
        }
      } else {
        if (leader_qball2_mytest_DW.TimeStampA_e >=
            leader_qball2_mytest_M->Timing.t[0]) {
          e = leader_qball2_mytest_DW.TimeStampB_c;
          lastU = &leader_qball2_mytest_DW.LastUAtTimeB_l;
        }
      }

      rtb_Integrator1_i = (leader_qball2_mytest_B.ManualSwitch_a - *lastU) /
        (leader_qball2_mytest_M->Timing.t[0] - e);
    }

    /* End of Derivative: '<S123>/Derivative' */

    /* RelationalOperator: '<S127>/Compare' incorporates:
     *  Constant: '<S127>/Constant'
     */
    leader_qball2_mytest_B.Compare_i = (rtb_Integrator1_i ==
      leader_qball2_mytest_P.Constant_Value_o5);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Enabled SubSystem: '<S123>/Enabled Subsystem1' */

      /* Constant: '<S123>/Constant2' */
      leader_qball2_EnabledSubsystem1(leader_qball2_mytest_M,
        leader_qball2_mytest_B.Compare_i,
        leader_qball2_mytest_P.Constant2_Value_f,
        &leader_qball2_mytest_B.EnabledSubsystem1_b,
        &leader_qball2_mytest_DW.EnabledSubsystem1_b,
        (P_EnabledSubsystem1_leader_qb_T *)
        &leader_qball2_mytest_P.EnabledSubsystem1_b);

      /* End of Outputs for SubSystem: '<S123>/Enabled Subsystem1' */

      /* Logic: '<S123>/Logical Operator' incorporates:
       *  Constant: '<S126>/Constant'
       *  Logic: '<S123>/Logical Operator3'
       *  RelationalOperator: '<S126>/Compare'
       */
      leader_qball2_mytest_B.LogicalOperator_b =
        ((!leader_qball2_mytest_B.EnabledSubsystem1_b.RelationalOperator) &&
         (leader_qball2_mytest_B.CLOSEDLOOPON ==
          leader_qball2_mytest_P.CompareToConstant_const_m));

      /* Logic: '<S118>/Logical Operator' incorporates:
       *  Logic: '<S118>/Logical Operator1'
       */
      leader_qball2_mytest_B.LogicalOperator_a =
        (leader_qball2_mytest_B.LogicalOperator2 &&
         (!leader_qball2_mytest_B.LogicalOperator_b));
    }

    /* Switch: '<S118>/Switch' */
    if (leader_qball2_mytest_B.LogicalOperator_a) {
      leader_qball2_mytest_B.Switch_e = leader_qball2_mytest_B.SigmoidPath_o1;
    } else {
      leader_qball2_mytest_B.Switch_e = leader_qball2_mytest_B.Switch;
    }

    /* End of Switch: '<S118>/Switch' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S141>/Constant' */
      leader_qball2_mytest_B.Constant_h =
        leader_qball2_mytest_P.CompareToConstant_const_ol;
    }

    /* RelationalOperator: '<S141>/Compare' */
    leader_qball2_mytest_B.Compare_h = (leader_qball2_mytest_B.Switch_e <
      leader_qball2_mytest_B.Constant_h);

    /* Integrator: '<S13>/Integrator' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      ZCEventType zcEvent;
      zcEvent = ((ZCEventType) ((leader_qball2_mytest_B.Compare_h !=
        (leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_f == POS_ZCSIG)) &&
                  (leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_f !=
                   UNINITIALIZED_ZCSIG)));

      /* evaluate zero-crossings and the level of the reset signal */
      leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_f = (ZCSigState)
        leader_qball2_mytest_B.Compare_h;
      if (zcEvent || leader_qball2_mytest_B.Compare_h) {
        leader_qball2_mytest_X.Integrator_CSTATE_h =
          leader_qball2_mytest_P.Integrator_IC_p;
      }
    }

    rtb_Integrator1_i = leader_qball2_mytest_X.Integrator_CSTATE_h;

    /* Sum: '<S13>/Sum5' */
    leader_qball2_mytest_B.Sum5 = (rtb_SwitchKp - rtb_Integrator1_k) +
      rtb_Integrator1_i;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* ManualSwitch: '<S5>/Manual Switch4' incorporates:
       *  Constant: '<S5>/JOYSTICK ON'
       */
      if (leader_qball2_mytest_P.ManualSwitch4_CurrentSetting == 1) {
        leader_qball2_mytest_B.ManualSwitch4 =
          leader_qball2_mytest_B.CLOSEDLOOPON;
      } else {
        leader_qball2_mytest_B.ManualSwitch4 =
          leader_qball2_mytest_P.JOYSTICKON_Value;
      }

      /* End of ManualSwitch: '<S5>/Manual Switch4' */
    }

    /* TransferFcn: '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)' */
    rtb_Integrator1_i = 0.0;
    rtb_Integrator1_i += leader_qball2_mytest_P.LowPassFilterFilteredYawRateF_c *
      leader_qball2_mytest_X.LowPassFilterFilteredYawRateFor;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Gain: '<S143>/Slider Gain' incorporates:
       *  Constant: '<S4>/Default Joystick CMD - Yaw'
       */
      leader_qball2_mytest_B.SliderGain_o =
        leader_qball2_mytest_P.Joystickyawcommandgain_gain *
        leader_qball2_mytest_P.DefaultJoystickCMDYaw_Value;
    }

    /* Switch: '<S13>/Switch' incorporates:
     *  Gain: '<S13>/Gain1'
     *  Gain: '<S142>/Slider Gain'
     *  Gain: '<S144>/Slider Gain'
     *  Sum: '<S13>/Sum1'
     */
    if (leader_qball2_mytest_B.ManualSwitch4 >=
        leader_qball2_mytest_P.Switch_Threshold_p) {
      rtb_Integrator1_i = leader_qball2_mytest_B.Sum5;
    } else {
      rtb_Integrator1_i = (leader_qball2_mytest_P.Joystickyawcommandgain1_gain *
                           rtb_Integrator1_i -
                           leader_qball2_mytest_B.SliderGain_o) *
        leader_qball2_mytest_P.Joystickyawcontrolgain_gain *
        leader_qball2_mytest_P.Gain1_Gain;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Saturate: '<S13>/Saturation' */
    if (rtb_Integrator1_i > leader_qball2_mytest_P.LIMIT_uCMD_YAW) {
      leader_qball2_mytest_B.Saturation_c =
        leader_qball2_mytest_P.LIMIT_uCMD_YAW;
    } else if (rtb_Integrator1_i < -leader_qball2_mytest_P.LIMIT_uCMD_YAW) {
      leader_qball2_mytest_B.Saturation_c =
        -leader_qball2_mytest_P.LIMIT_uCMD_YAW;
    } else {
      leader_qball2_mytest_B.Saturation_c = rtb_Integrator1_i;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Gain: '<S2>/Gain2' */
    rtb_Integrator1_i = leader_qball2_mytest_P.Gain2_Gain_k *
      leader_qball2_mytest_B.Saturation_c;

    /* Abs: '<S16>/Abs' */
    rtb_ManualSwitch_l = fabs(leader_qball2_mytest_B.HPF);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S17>/Constant' */
      leader_qball2_mytest_B.Constant_m3 =
        leader_qball2_mytest_P.CompareToConstant1_const_n;
    }

    /* RelationalOperator: '<S17>/Compare' */
    rtb_Compare = (uint8_T)(rtb_ManualSwitch_l >
      leader_qball2_mytest_B.Constant_m3);

    /* Abs: '<S16>/Abs1' */
    rtb_ManualSwitch_l = fabs(leader_qball2_mytest_B.ManualSwitch);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S18>/Constant' */
      leader_qball2_mytest_B.Constant_ef =
        leader_qball2_mytest_P.CompareToConstant2_const;
    }

    /* Logic: '<S16>/Logical Operator' incorporates:
     *  RelationalOperator: '<S18>/Compare'
     */
    leader_qball2_mytest_B.LogicalOperator_m = ((rtb_Compare != 0) ||
      (rtb_ManualSwitch_l > leader_qball2_mytest_B.Constant_ef));
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S19>/Enable'
       */
      if (leader_qball2_mytest_B.LogicalOperator_m) {
        /* Constant: '<S19>/Constant' */
        leader_qball2_mytest_B.Constant_cd =
          leader_qball2_mytest_P.Constant_Value;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_d);
        }
      }

      /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem' */
    }

    /* TransferFcn: '<S81>/Low Pass Filter (Filtered Pitch Rate)' */
    K_0 = leader_qball2_mytest_P.LowPassFilterFilteredPitchRat_e *
      leader_qball2_mytest_X.LowPassFilterFilteredPitchRate_;

    /* Switch: '<S81>/Switch - Kd' incorporates:
     *  Gain: '<S81>/Kd - Battery DOWN'
     *  Gain: '<S81>/Kd - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKd_Threshold_k) {
      leader_qball2_mytest_B.SwitchKd_k = leader_qball2_mytest_P.KdPITCH_UP *
        K_0;
    } else {
      leader_qball2_mytest_B.SwitchKd_k = leader_qball2_mytest_P.KdPITCH_DOWN *
        K_0;
    }

    /* End of Switch: '<S81>/Switch - Kd' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Enabled SubSystem: '<S83>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S90>/Enable'
       */
      if (leader_qball2_mytest_B.LogicalOperator2) {
        /* Constant: '<S90>/Constant' */
        leader_qball2_mytest_B.Constant_cm =
          leader_qball2_mytest_P.Constant_Value_g;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_h);
        }
      }

      /* End of Outputs for SubSystem: '<S83>/Enabled Subsystem' */

      /* Memory: '<S85>/Memory' */
      leader_qball2_mytest_B.Memory_o =
        leader_qball2_mytest_DW.Memory_PreviousInput_i;

      /* Switch: '<S83>/Switch' incorporates:
       *  Constant: '<S4>/Default Joystick CMD - Pitch'
       *  Constant: '<S83>/Constant'
       *  Gain: '<S80>/Joystick Sensitivity'
       *  Switch: '<S80>/Switch'
       */
      if (leader_qball2_mytest_B.Constant_cm >=
          leader_qball2_mytest_P.Switch_Threshold_o) {
        leader_qball2_mytest_B.Switch_p =
          leader_qball2_mytest_P.Constant_Value_p;
      } else if (leader_qball2_mytest_B.ManualSwitch2 >=
                 leader_qball2_mytest_P.Switch_Threshold) {
        /* Switch: '<S80>/Switch' */
        leader_qball2_mytest_B.Switch_p = leader_qball2_mytest_B.Memory_o;
      } else {
        leader_qball2_mytest_B.Switch_p =
          leader_qball2_mytest_P.JoystickSensitivity_Gain *
          leader_qball2_mytest_P.DefaultJoystickCMDPitch_Value;
      }

      /* End of Switch: '<S83>/Switch' */

      /* ManualSwitch: '<S6>/Manual Switch' incorporates:
       *  Constant: '<S4>/Default Joystick CMD - Pitch'
       *  Gain: '<S6>/Gain'
       */
      if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting_lk == 1) {
        leader_qball2_mytest_B.ManualSwitch_f = leader_qball2_mytest_B.Switch_p;
      } else {
        leader_qball2_mytest_B.ManualSwitch_f =
          leader_qball2_mytest_P.Gain_Gain_j *
          leader_qball2_mytest_P.DefaultJoystickCMDPitch_Value;
      }

      /* End of ManualSwitch: '<S6>/Manual Switch' */
    }

    /* ManualSwitch: '<S81>/Manual Switch' */
    if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting_j == 1) {
      leader_qball2_mytest_B.ManualSwitch_b = leader_qball2_mytest_B.angle_f;
    } else {
      leader_qball2_mytest_B.ManualSwitch_b = leader_qball2_mytest_B.HPF;
    }

    /* End of ManualSwitch: '<S81>/Manual Switch' */

    /* Sum: '<S81>/Sum2' */
    rtb_Sum_bh_idx_1 = leader_qball2_mytest_B.ManualSwitch_f -
      leader_qball2_mytest_B.ManualSwitch_b;

    /* Switch: '<S81>/Switch - Kp' incorporates:
     *  Gain: '<S81>/Kp - Battery DOWN'
     *  Gain: '<S81>/Kp - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKp_Threshold_f) {
      leader_qball2_mytest_B.SwitchKp_b = leader_qball2_mytest_P.KpPITCH_UP *
        rtb_Sum_bh_idx_1;
    } else {
      leader_qball2_mytest_B.SwitchKp_b = leader_qball2_mytest_P.KpPITCH_DOWN *
        rtb_Sum_bh_idx_1;
    }

    /* End of Switch: '<S81>/Switch - Kp' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S91>/Constant' */
      leader_qball2_mytest_B.Constant_em =
        leader_qball2_mytest_P.CompareToConstant_const_a;
    }

    /* RelationalOperator: '<S91>/Compare' */
    leader_qball2_mytest_B.Compare_f = (leader_qball2_mytest_B.Switch_e <
      leader_qball2_mytest_B.Constant_em);

    /* Integrator: '<S81>/Integrator1' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      ZCEventType zcEvent;
      zcEvent = ((ZCEventType) ((leader_qball2_mytest_B.Compare_f !=
        (leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE == POS_ZCSIG)) &&
                  (leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE !=
                   UNINITIALIZED_ZCSIG)));

      /* evaluate zero-crossings and the level of the reset signal */
      leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE = (ZCSigState)
        leader_qball2_mytest_B.Compare_f;
      if (zcEvent || leader_qball2_mytest_B.Compare_f) {
        leader_qball2_mytest_X.Integrator1_CSTATE_g =
          leader_qball2_mytest_P.Integrator1_IC;
      }
    }

    leader_qball2_mytest_B.Integrator1_l =
      leader_qball2_mytest_X.Integrator1_CSTATE_g;

    /* Sum: '<S81>/Sum4' */
    rtb_ManualSwitch_l = (leader_qball2_mytest_B.SwitchKp_b -
                          leader_qball2_mytest_B.SwitchKd_k) +
      leader_qball2_mytest_B.Integrator1_l;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S7>/Pitch_Trim' */
      leader_qball2_mytest_B.Pitch_Trim = leader_qball2_mytest_P.TRIM_U_PITCH;
    }

    /* Saturate: '<S81>/Saturation1' */
    if (rtb_ManualSwitch_l > leader_qball2_mytest_P.LIMIT_uCMD_PITCH) {
      K_1 = leader_qball2_mytest_P.LIMIT_uCMD_PITCH;
    } else if (rtb_ManualSwitch_l < -leader_qball2_mytest_P.LIMIT_uCMD_PITCH) {
      K_1 = -leader_qball2_mytest_P.LIMIT_uCMD_PITCH;
    } else {
      K_1 = rtb_ManualSwitch_l;
    }

    /* Sum: '<S81>/Sum' incorporates:
     *  Saturate: '<S81>/Saturation1'
     */
    leader_qball2_mytest_B.Sum_b = K_1 + leader_qball2_mytest_B.Pitch_Trim;

    /* Sum: '<S2>/Sum' */
    leader_qball2_mytest_B.Sum_n = (leader_qball2_mytest_B.Switch_e +
      leader_qball2_mytest_B.Saturation_c) + leader_qball2_mytest_B.Sum_b;

    /* Sum: '<S2>/Sum1' */
    leader_qball2_mytest_B.Sum1 = (leader_qball2_mytest_B.Switch_e +
      leader_qball2_mytest_B.Saturation_c) - leader_qball2_mytest_B.Sum_b;

    /* TransferFcn: '<S97>/Low Pass Filter (Filtered Roll Rate)' */
    K_0 = leader_qball2_mytest_P.LowPassFilterFilteredRollRate_C *
      leader_qball2_mytest_X.LowPassFilterFilteredRollRate_C;

    /* Switch: '<S97>/Switch - Kd' incorporates:
     *  Gain: '<S97>/Kd - Battery DOWN'
     *  Gain: '<S97>/Kd - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKd_Threshold_pr) {
      leader_qball2_mytest_B.SwitchKd_m = leader_qball2_mytest_P.KdROLL_UP * K_0;
    } else {
      leader_qball2_mytest_B.SwitchKd_m = leader_qball2_mytest_P.KdROLL_DOWN *
        K_0;
    }

    /* End of Switch: '<S97>/Switch - Kd' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Enabled SubSystem: '<S101>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S108>/Enable'
       */
      if (leader_qball2_mytest_B.LogicalOperator2) {
        /* Constant: '<S108>/Constant' */
        leader_qball2_mytest_B.Constant_k =
          leader_qball2_mytest_P.Constant_Value_j;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_f);
        }
      }

      /* End of Outputs for SubSystem: '<S101>/Enabled Subsystem' */

      /* Memory: '<S103>/Memory' */
      leader_qball2_mytest_B.Memory_f =
        leader_qball2_mytest_DW.Memory_PreviousInput_j;

      /* Switch: '<S101>/Switch' incorporates:
       *  Constant: '<S101>/Constant'
       *  Constant: '<S4>/Default Joystick CMD - Roll'
       *  Gain: '<S98>/Joystick Sensitivity'
       *  Switch: '<S98>/Switch'
       */
      if (leader_qball2_mytest_B.Constant_k >=
          leader_qball2_mytest_P.Switch_Threshold_j) {
        leader_qball2_mytest_B.Switch_f =
          leader_qball2_mytest_P.Constant_Value_a;
      } else if (leader_qball2_mytest_B.ManualSwitch2 >=
                 leader_qball2_mytest_P.Switch_Threshold_a) {
        /* Switch: '<S98>/Switch' */
        leader_qball2_mytest_B.Switch_f = leader_qball2_mytest_B.Memory_f;
      } else {
        leader_qball2_mytest_B.Switch_f =
          leader_qball2_mytest_P.JoystickSensitivity_Gain_j *
          leader_qball2_mytest_P.DefaultJoystickCMDRoll_Value;
      }

      /* End of Switch: '<S101>/Switch' */

      /* ManualSwitch: '<S8>/Manual Switch' incorporates:
       *  Constant: '<S4>/Default Joystick CMD - Roll'
       *  Gain: '<S8>/Gain'
       */
      if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting_k == 1) {
        leader_qball2_mytest_B.ManualSwitch_j = leader_qball2_mytest_B.Switch_f;
      } else {
        leader_qball2_mytest_B.ManualSwitch_j =
          leader_qball2_mytest_P.Gain_Gain_f *
          leader_qball2_mytest_P.DefaultJoystickCMDRoll_Value;
      }

      /* End of ManualSwitch: '<S8>/Manual Switch' */
    }

    /* ManualSwitch: '<S97>/Manual Switch' */
    if (leader_qball2_mytest_P.ManualSwitch_CurrentSetting_h == 1) {
      rtb_ManualSwitch_l = leader_qball2_mytest_B.angle_m;
    } else {
      rtb_ManualSwitch_l = leader_qball2_mytest_B.ManualSwitch;
    }

    /* End of ManualSwitch: '<S97>/Manual Switch' */

    /* Sum: '<S97>/Sum2' */
    rtb_Sum2_ir = leader_qball2_mytest_B.ManualSwitch_j - rtb_ManualSwitch_l;

    /* Switch: '<S97>/Switch - Kp' incorporates:
     *  Gain: '<S97>/Kp - Battery DOWN'
     *  Gain: '<S97>/Kp - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKp_Threshold_g) {
      leader_qball2_mytest_B.SwitchKp_f = leader_qball2_mytest_P.KpROLL_UP *
        rtb_Sum2_ir;
    } else {
      leader_qball2_mytest_B.SwitchKp_f = leader_qball2_mytest_P.KpROLL_DOWN *
        rtb_Sum2_ir;
    }

    /* End of Switch: '<S97>/Switch - Kp' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S99>/Constant' */
      leader_qball2_mytest_B.Constant_n =
        leader_qball2_mytest_P.CompareToConstant_const_i;
    }

    /* RelationalOperator: '<S99>/Compare' */
    leader_qball2_mytest_B.Compare_n = (leader_qball2_mytest_B.Switch_e <
      leader_qball2_mytest_B.Constant_n);

    /* Integrator: '<S97>/Integrator1' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      ZCEventType zcEvent;
      zcEvent = ((ZCEventType) ((leader_qball2_mytest_B.Compare_n !=
        (leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_e == POS_ZCSIG)) &&
                  (leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_e !=
                   UNINITIALIZED_ZCSIG)));

      /* evaluate zero-crossings and the level of the reset signal */
      leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_e = (ZCSigState)
        leader_qball2_mytest_B.Compare_n;
      if (zcEvent || leader_qball2_mytest_B.Compare_n) {
        leader_qball2_mytest_X.Integrator1_CSTATE_n =
          leader_qball2_mytest_P.Integrator1_IC_g;
      }
    }

    leader_qball2_mytest_B.Integrator1_n =
      leader_qball2_mytest_X.Integrator1_CSTATE_n;

    /* Sum: '<S97>/Sum4' */
    rtb_Integrator1_k = (leader_qball2_mytest_B.SwitchKp_f -
                         leader_qball2_mytest_B.SwitchKd_m) +
      leader_qball2_mytest_B.Integrator1_n;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S7>/roll_trim' */
      leader_qball2_mytest_B.roll_trim = leader_qball2_mytest_P.TRIM_U_ROLL;
    }

    /* Saturate: '<S97>/Saturation' */
    if (rtb_Integrator1_k > leader_qball2_mytest_P.LIMIT_uCMD_ROLL) {
      K_1 = leader_qball2_mytest_P.LIMIT_uCMD_ROLL;
    } else if (rtb_Integrator1_k < -leader_qball2_mytest_P.LIMIT_uCMD_ROLL) {
      K_1 = -leader_qball2_mytest_P.LIMIT_uCMD_ROLL;
    } else {
      K_1 = rtb_Integrator1_k;
    }

    /* Sum: '<S97>/Sum' incorporates:
     *  Saturate: '<S97>/Saturation'
     */
    leader_qball2_mytest_B.Sum_ng = K_1 + leader_qball2_mytest_B.roll_trim;

    /* Sum: '<S2>/Sum2' */
    leader_qball2_mytest_B.Sum2 = (leader_qball2_mytest_B.Switch_e +
      rtb_Integrator1_i) + leader_qball2_mytest_B.Sum_ng;

    /* Sum: '<S2>/Sum3' */
    leader_qball2_mytest_B.Sum3 = (leader_qball2_mytest_B.Switch_e +
      rtb_Integrator1_i) - leader_qball2_mytest_B.Sum_ng;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Step: '<S16>/Step Initialize zero throttle for 3 seconds' */
    if (leader_qball2_mytest_M->Timing.t[0] <
        leader_qball2_mytest_P.StepInitializezerothrottlefor3s) {
      rtb_Integrator1_i = leader_qball2_mytest_P.StepInitializezerothrottlefor_c;
    } else {
      rtb_Integrator1_i = leader_qball2_mytest_P.StepInitializezerothrottlefor_a;
    }

    /* End of Step: '<S16>/Step Initialize zero throttle for 3 seconds' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S21>/Constant' */
      leader_qball2_mytest_B.Constant_gy =
        leader_qball2_mytest_P.CompareToConstant_const_g;
    }

    /* RelationalOperator: '<S21>/Compare' */
    leader_qball2_mytest_B.Compare_k = (uint8_T)(leader_qball2_mytest_B.Switch_e
      <= leader_qball2_mytest_B.Constant_gy);
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S22>/Enable'
       */
      if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
        if (leader_qball2_mytest_B.Compare_k > 0) {
          if (!leader_qball2_mytest_DW.EnabledSubsystem_MODE_h) {
            /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
            leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE_a =
              leader_qball2_mytest_P.DiscreteTimeIntegrator_IC;
            leader_qball2_mytest_DW.EnabledSubsystem_MODE_h = true;
          }
        } else {
          if (leader_qball2_mytest_DW.EnabledSubsystem_MODE_h) {
            /* Disable for Outport: '<S22>/timeout' */
            leader_qball2_mytest_B.RelationalOperator_m =
              leader_qball2_mytest_P.timeout_Y0;
            leader_qball2_mytest_DW.EnabledSubsystem_MODE_h = false;
          }
        }
      }

      if (leader_qball2_mytest_DW.EnabledSubsystem_MODE_h) {
        /* RelationalOperator: '<S22>/Relational Operator' incorporates:
         *  Constant: '<S20>/Constant2'
         *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
         */
        leader_qball2_mytest_B.RelationalOperator_m =
          (leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE_a >=
           leader_qball2_mytest_P.Constant2_Value_n);

        /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S22>/Constant'
         */
        leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE_a +=
          leader_qball2_mytest_P.DiscreteTimeIntegrator_gainval *
          leader_qball2_mytest_P.Constant_Value_h;
        if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
          srUpdateBC(leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_m);
        }
      }

      /* End of Outputs for SubSystem: '<S20>/Enabled Subsystem' */

      /* Logic: '<S20>/Logical Operator1' */
      leader_qball2_mytest_B.LogicalOperator1 =
        !leader_qball2_mytest_B.RelationalOperator_m;
    }

    /* Product: '<S16>/Product2' incorporates:
     *  Product: '<S16>/Product1'
     */
    leader_qball2_mytest_B.Product2[0] = (real_T)
      leader_qball2_mytest_B.LogicalOperator1 * leader_qball2_mytest_B.Sum_n *
      leader_qball2_mytest_B.Constant_cd * rtb_Integrator1_i;
    leader_qball2_mytest_B.Product2[1] = (real_T)
      leader_qball2_mytest_B.LogicalOperator1 * leader_qball2_mytest_B.Sum1 *
      leader_qball2_mytest_B.Constant_cd * rtb_Integrator1_i;
    leader_qball2_mytest_B.Product2[2] = (real_T)
      leader_qball2_mytest_B.LogicalOperator1 * leader_qball2_mytest_B.Sum2 *
      leader_qball2_mytest_B.Constant_cd * rtb_Integrator1_i;
    leader_qball2_mytest_B.Product2[3] = (real_T)
      leader_qball2_mytest_B.LogicalOperator1 * leader_qball2_mytest_B.Sum3 *
      leader_qball2_mytest_B.Constant_cd * rtb_Integrator1_i;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Gain: '<S4>/Gain' */
      leader_qball2_mytest_B.Gain_d[0] = leader_qball2_mytest_P.Gain_Gain_n *
        leader_qball2_mytest_B.InverseModulus;
      leader_qball2_mytest_B.Gain_d[1] = leader_qball2_mytest_P.Gain_Gain_n *
        leader_qball2_mytest_B.StreamClient_o3[9];

      /* RelationalOperator: '<S73>/Compare' incorporates:
       *  Abs: '<S72>/Abs'
       *  Constant: '<S73>/Constant'
       */
      for (i = 0; i < 10; i++) {
        rtb_Compare_d[i] = (fabs(leader_qball2_mytest_B.StreamClient_o3[i]) >=
                            leader_qball2_mytest_P.CompareToConstant_const_aq);
      }

      /* End of RelationalOperator: '<S73>/Compare' */

      /* Logic: '<S72>/Logical Operator4' */
      rtb_LogicalOperator = rtb_Compare_d[0];
      for (i = 0; i < 9; i++) {
        rtb_LogicalOperator = (rtb_LogicalOperator || rtb_Compare_d[i + 1]);
      }

      leader_qball2_mytest_B.LogicalOperator4 = rtb_LogicalOperator;

      /* End of Logic: '<S72>/Logical Operator4' */

      /* Memory: '<S61>/Memory' */
      rtb_Memory_l = leader_qball2_mytest_DW.Memory_PreviousInput_it;

      /* MATLAB Function: '<S61>/Embedded MATLAB Function' incorporates:
       *  Constant: '<S61>/Constant'
       */
      leader_q_EmbeddedMATLABFunction(leader_qball2_mytest_B.StreamClient_o3[3],
        rtb_Memory_l, leader_qball2_mytest_P.Constant_Value_k,
        &leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_d);

      /* Memory: '<S63>/Memory' */
      rtb_Memory_e = leader_qball2_mytest_DW.Memory_PreviousInput_m;

      /* MATLAB Function: '<S63>/Embedded MATLAB Function' incorporates:
       *  Constant: '<S63>/Constant'
       */
      leader_q_EmbeddedMATLABFunction(leader_qball2_mytest_B.StreamClient_o3[5],
        rtb_Memory_e, leader_qball2_mytest_P.Constant_Value_d,
        &leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_j4);

      /* Constant: '<S89>/wn' */
      leader_qball2_mytest_B.wn_h = leader_qball2_mytest_P.OMEGA_DIFF;
    }

    /* Integrator: '<S89>/Integrator2' */
    rtb_Integrator1_i = leader_qball2_mytest_X.Integrator2_CSTATE_ir;

    /* Product: '<S89>/Product1' */
    leader_qball2_mytest_B.Product1_ey = leader_qball2_mytest_B.wn_h *
      rtb_Integrator1_i;

    /* Switch: '<S86>/Switch - Kd' incorporates:
     *  Gain: '<S86>/Kv - Battery DOWN'
     *  Gain: '<S86>/Kv - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKd_Threshold_c) {
      rtb_Integrator1_k = leader_qball2_mytest_P.KdOUTER_PITCH_UP *
        leader_qball2_mytest_B.Product1_ey;
    } else {
      rtb_Integrator1_k = leader_qball2_mytest_P.KdOUTER_PITCH_DOWN *
        leader_qball2_mytest_B.Product1_ey;
    }

    /* End of Switch: '<S86>/Switch - Kd' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Gain: '<S96>/Slider Gain' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      leader_qball2_mytest_B.SliderGain_e =
        leader_qball2_mytest_P.SliderGain4_gain *
        leader_qball2_mytest_P.Constant2_Value_n3;
    }

    /* TransportDelay: '<S7>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &leader_qball2_mytest_DW.TransportDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &leader_qball2_mytest_DW.TransportDelay_PWORK.TUbufferPtrs[1];
      real_T simTime = leader_qball2_mytest_M->Timing.t[0];
      real_T tMinusDelay = simTime - leader_qball2_mytest_P.TransportDelay_Delay;
      rtb_SwitchKp = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        leader_qball2_mytest_DW.TransportDelay_IWORK.CircularBufSize,
        &leader_qball2_mytest_DW.TransportDelay_IWORK.Last,
        leader_qball2_mytest_DW.TransportDelay_IWORK.Tail,
        leader_qball2_mytest_DW.TransportDelay_IWORK.Head,
        leader_qball2_mytest_P.TransportDelay_InitOutput,
        0,
        0);
    }

    /* ManualSwitch: '<S7>/Manual Switch1' */
    if (leader_qball2_mytest_P.ManualSwitch1_CurrentSetting == 1) {
      rtb_SwitchKp = leader_qball2_mytest_B.SliderGain_e;
    }

    /* End of ManualSwitch: '<S7>/Manual Switch1' */

    /* Saturate: '<S7>/Saturation1' */
    if (rtb_SwitchKp > leader_qball2_mytest_P.LIMIT_MAX_Z) {
      e = leader_qball2_mytest_P.LIMIT_MAX_Z;
    } else if (rtb_SwitchKp < leader_qball2_mytest_P.LIMIT_MIN_Z) {
      e = leader_qball2_mytest_P.LIMIT_MIN_Z;
    } else {
      e = rtb_SwitchKp;
    }

    /* End of Saturate: '<S7>/Saturation1' */

    /* RateLimiter: '<S7>/Rate Limiter2' */
    if (leader_qball2_mytest_DW.LastMajorTime_c == (rtInf)) {
      leader_qball2_mytest_B.RateLimiter2 = e;
    } else {
      K_0 = leader_qball2_mytest_M->Timing.t[0] -
        leader_qball2_mytest_DW.LastMajorTime_c;
      K_1 = K_0 * leader_qball2_mytest_P.LIMIT_RATE_Z;
      Phi = e - leader_qball2_mytest_DW.PrevY_i;
      if (Phi > K_1) {
        leader_qball2_mytest_B.RateLimiter2 = leader_qball2_mytest_DW.PrevY_i +
          K_1;
      } else {
        K_0 *= -leader_qball2_mytest_P.LIMIT_RATE_Z;
        if (Phi < K_0) {
          leader_qball2_mytest_B.RateLimiter2 = leader_qball2_mytest_DW.PrevY_i
            + K_0;
        } else {
          leader_qball2_mytest_B.RateLimiter2 = e;
        }
      }
    }

    /* End of RateLimiter: '<S7>/Rate Limiter2' */

    /* Sum: '<S82>/Sum2' */
    cTheta = leader_qball2_mytest_B.RateLimiter2 -
      leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_j4.y;

    /* Switch: '<S86>/Switch - Kp' incorporates:
     *  Gain: '<S86>/Kp - Battery DOWN'
     *  Gain: '<S86>/Kp - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKp_Threshold_k) {
      rtb_SwitchKp = leader_qball2_mytest_P.KpOUTER_PITCH_UP * cTheta;
    } else {
      rtb_SwitchKp = leader_qball2_mytest_P.KpOUTER_PITCH_DOWN * cTheta;
    }

    /* End of Switch: '<S86>/Switch - Kp' */

    /* Logic: '<S88>/Logical Operator1' */
    leader_qball2_mytest_B.LogicalOperator1_o =
      !leader_qball2_mytest_B.LogicalOperator;

    /* Integrator: '<S86>/Integrator' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      ZCEventType zcEvent;
      zcEvent = ((ZCEventType) ((leader_qball2_mytest_B.LogicalOperator1_o !=
        (leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_n == POS_ZCSIG)) &&
                  (leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_n !=
                   UNINITIALIZED_ZCSIG)));

      /* evaluate zero-crossings and the level of the reset signal */
      leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_n = (ZCSigState)
        leader_qball2_mytest_B.LogicalOperator1_o;
      if (zcEvent || leader_qball2_mytest_B.LogicalOperator1_o) {
        leader_qball2_mytest_X.Integrator_CSTATE_k =
          leader_qball2_mytest_P.Integrator_IC_e;
      }
    }

    rtb_Integrator1_o = leader_qball2_mytest_X.Integrator_CSTATE_k;

    /* Sum: '<S86>/Sum4' */
    rtb_Integrator1_k = (rtb_SwitchKp - rtb_Integrator1_k) + rtb_Integrator1_o;

    /* Saturate: '<S86>/Saturation1' */
    if (rtb_Integrator1_k > leader_qball2_mytest_P.LIMIT_CMD_PITCH) {
      K_1 = leader_qball2_mytest_P.LIMIT_CMD_PITCH;
    } else if (rtb_Integrator1_k < -leader_qball2_mytest_P.LIMIT_CMD_PITCH) {
      K_1 = -leader_qball2_mytest_P.LIMIT_CMD_PITCH;
    } else {
      K_1 = rtb_Integrator1_k;
    }

    /* Gain: '<S86>/Gain4' incorporates:
     *  Saturate: '<S86>/Saturation1'
     */
    rtb_Gain4 = leader_qball2_mytest_P.Gain4_Gain_k * K_1;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* RelationalOperator: '<S84>/Compare' incorporates:
       *  Constant: '<S84>/Constant'
       */
      leader_qball2_mytest_B.Compare_m = (uint8_T)
        (leader_qball2_mytest_B.sf_EmbeddedMATLABFunction.y >
         leader_qball2_mytest_P.CompareToConstant_const_ap);
    }

    /* Product: '<S82>/Product' */
    leader_qball2_mytest_B.Product_c = rtb_Gain4 * (real_T)
      leader_qball2_mytest_B.Compare_m;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S107>/wn' */
      leader_qball2_mytest_B.wn_a5 = leader_qball2_mytest_P.OMEGA_DIFF;
    }

    /* Integrator: '<S107>/Integrator2' */
    rtb_Integrator1_o = leader_qball2_mytest_X.Integrator2_CSTATE_a;

    /* Product: '<S107>/Product1' */
    leader_qball2_mytest_B.Product1_d = leader_qball2_mytest_B.wn_a5 *
      rtb_Integrator1_o;

    /* Switch: '<S104>/Switch - Kd' incorporates:
     *  Gain: '<S104>/Kv - DOWN'
     *  Gain: '<S104>/Kv - UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKd_Threshold_g) {
      leader_qball2_mytest_B.SwitchKd_o = leader_qball2_mytest_P.KdOUTER_ROLL_UP
        * leader_qball2_mytest_B.Product1_d;
    } else {
      leader_qball2_mytest_B.SwitchKd_o =
        leader_qball2_mytest_P.KdOUTER_ROLL_DOWN *
        leader_qball2_mytest_B.Product1_d;
    }

    /* End of Switch: '<S104>/Switch - Kd' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Gain: '<S94>/Slider Gain' incorporates:
       *  Constant: '<S7>/Constant1'
       */
      leader_qball2_mytest_B.SliderGain_p =
        leader_qball2_mytest_P.SliderGain2_gain *
        leader_qball2_mytest_P.Constant1_Value_b;
    }

    /* SignalGenerator: '<S7>/Signal Generator1' */
    K_1 = leader_qball2_mytest_P.SignalGenerator1_Frequency *
      leader_qball2_mytest_M->Timing.t[0];
    if (K_1 - floor(K_1) >= 0.5) {
      rtb_Integrator1_k = leader_qball2_mytest_P.SignalGenerator1_Amplitude;
    } else {
      rtb_Integrator1_k = -leader_qball2_mytest_P.SignalGenerator1_Amplitude;
    }

    /* End of SignalGenerator: '<S7>/Signal Generator1' */

    /* Gain: '<S93>/Slider Gain' */
    rtb_Integrator1_k *= leader_qball2_mytest_P.SliderGain1_gain;

    /* ManualSwitch: '<S7>/Manual Switch2' */
    if (leader_qball2_mytest_P.ManualSwitch2_CurrentSetting_c == 1) {
      rtb_Integrator1_k = leader_qball2_mytest_B.SliderGain_p;
    }

    /* End of ManualSwitch: '<S7>/Manual Switch2' */

    /* Saturate: '<S7>/Saturation' */
    if (rtb_Integrator1_k > leader_qball2_mytest_P.LIMIT_MAX_X) {
      e = leader_qball2_mytest_P.LIMIT_MAX_X;
    } else if (rtb_Integrator1_k < leader_qball2_mytest_P.LIMIT_MIN_X) {
      e = leader_qball2_mytest_P.LIMIT_MIN_X;
    } else {
      e = rtb_Integrator1_k;
    }

    /* End of Saturate: '<S7>/Saturation' */

    /* RateLimiter: '<S7>/Rate Limiter1' */
    if (leader_qball2_mytest_DW.LastMajorTime_j == (rtInf)) {
      leader_qball2_mytest_B.RateLimiter1 = e;
    } else {
      K_0 = leader_qball2_mytest_M->Timing.t[0] -
        leader_qball2_mytest_DW.LastMajorTime_j;
      K_1 = K_0 * leader_qball2_mytest_P.LIMIT_RATE_X;
      Phi = e - leader_qball2_mytest_DW.PrevY_a;
      if (Phi > K_1) {
        leader_qball2_mytest_B.RateLimiter1 = leader_qball2_mytest_DW.PrevY_a +
          K_1;
      } else {
        K_0 *= -leader_qball2_mytest_P.LIMIT_RATE_X;
        if (Phi < K_0) {
          leader_qball2_mytest_B.RateLimiter1 = leader_qball2_mytest_DW.PrevY_a
            + K_0;
        } else {
          leader_qball2_mytest_B.RateLimiter1 = e;
        }
      }
    }

    /* End of RateLimiter: '<S7>/Rate Limiter1' */

    /* Sum: '<S100>/Sum1' */
    e = leader_qball2_mytest_B.RateLimiter1 -
      leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_d.y;

    /* Switch: '<S104>/Switch - Kp' incorporates:
     *  Gain: '<S104>/Kp - Battery DOWN'
     *  Gain: '<S104>/Kp - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKp_Threshold_fn) {
      leader_qball2_mytest_B.SwitchKp_c = leader_qball2_mytest_P.KpOUTER_ROLL_UP
        * e;
    } else {
      leader_qball2_mytest_B.SwitchKp_c =
        leader_qball2_mytest_P.KpOUTER_ROLL_DOWN * e;
    }

    /* End of Switch: '<S104>/Switch - Kp' */

    /* Logic: '<S106>/Logical Operator1' */
    leader_qball2_mytest_B.LogicalOperator1_h =
      !leader_qball2_mytest_B.LogicalOperator;

    /* Integrator: '<S104>/Integrator1' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      ZCEventType zcEvent;
      zcEvent = ((ZCEventType) ((leader_qball2_mytest_B.LogicalOperator1_h !=
        (leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_f == POS_ZCSIG)) &&
                  (leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_f !=
                   UNINITIALIZED_ZCSIG)));

      /* evaluate zero-crossings and the level of the reset signal */
      leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_f = (ZCSigState)
        leader_qball2_mytest_B.LogicalOperator1_h;
      if (zcEvent || leader_qball2_mytest_B.LogicalOperator1_h) {
        leader_qball2_mytest_X.Integrator1_CSTATE_nx =
          leader_qball2_mytest_P.Integrator1_IC_b;
      }
    }

    rtb_Integrator1_k = leader_qball2_mytest_X.Integrator1_CSTATE_nx;

    /* Sum: '<S104>/Sum4' */
    rtb_Integrator1_k += leader_qball2_mytest_B.SwitchKp_c -
      leader_qball2_mytest_B.SwitchKd_o;

    /* Saturate: '<S104>/Saturation1' */
    if (rtb_Integrator1_k > leader_qball2_mytest_P.LIMIT_CMD_ROLL) {
      K_0 = leader_qball2_mytest_P.LIMIT_CMD_ROLL;
    } else if (rtb_Integrator1_k < -leader_qball2_mytest_P.LIMIT_CMD_ROLL) {
      K_0 = -leader_qball2_mytest_P.LIMIT_CMD_ROLL;
    } else {
      K_0 = rtb_Integrator1_k;
    }

    /* End of Saturate: '<S104>/Saturation1' */

    /* MATLAB Function: '<S85>/adjust_pitch_command' */
    /* MATLAB Function 'Pitch Controller/Subsystem/OT pos control/adjust_for_heading/adjust_pitch_command': '<S87>:1' */
    /*  Given the roll and pitch commands computed for the global frame, this function */
    /*  rotates the pitch command into the local frame, allowing the control */
    /*  command to work even for non-zero yaw. */
    /* '<S87>:1:8' */
    leader_qball2_mytest_B.adj_pitch_cmd = -K_0 * sin
      (leader_qball2_mytest_B.angle) + leader_qball2_mytest_B.Product_c * cos
      (leader_qball2_mytest_B.angle);

    /* adj_pitch_cmd = roll_cmd*sin(heading) + pitch_cmd*cos(heading); */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S89>/Constant' */
      leader_qball2_mytest_B.Constant_emr =
        leader_qball2_mytest_P.Constant_Value_ni;

      /* Constant: '<S89>/x0' */
      leader_qball2_mytest_B.x0_dh = leader_qball2_mytest_P.x0_Value_b;
    }

    /* Integrator: '<S89>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK_b.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE_c = leader_qball2_mytest_B.x0_dh;
    }

    rtb_Integrator1_k = leader_qball2_mytest_X.Integrator1_CSTATE_c;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S89>/zt' */
      leader_qball2_mytest_B.zt_je =
        leader_qball2_mytest_P.SecondOrderLowPassFilter1_input;
    }

    /* Product: '<S89>/Product' incorporates:
     *  Product: '<S89>/Product2'
     *  Sum: '<S89>/Sum'
     *  Sum: '<S89>/Sum1'
     */
    leader_qball2_mytest_B.Product_b =
      ((leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_j4.y -
        rtb_Integrator1_k) - rtb_Integrator1_i *
       leader_qball2_mytest_B.Constant_emr * leader_qball2_mytest_B.zt_je) *
      leader_qball2_mytest_B.wn_h;

    /* Switch: '<S86>/Switch - Ki' incorporates:
     *  Gain: '<S86>/Ki - Battery DOWN'
     *  Gain: '<S86>/Ki - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKi_Threshold) {
      leader_qball2_mytest_B.SwitchKi = leader_qball2_mytest_P.KiOUTER_PITCH_UP *
        cTheta;
    } else {
      leader_qball2_mytest_B.SwitchKi =
        leader_qball2_mytest_P.KiOUTER_PITCH_DOWN * cTheta;
    }

    /* End of Switch: '<S86>/Switch - Ki' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Switch: '<S81>/Switch - Ki' incorporates:
     *  Gain: '<S81>/Ki - Battery DOWN'
     *  Gain: '<S81>/Ki - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKi_Threshold_m) {
      leader_qball2_mytest_B.SwitchKi_h = leader_qball2_mytest_P.KiPITCH_UP *
        rtb_Sum_bh_idx_1;
    } else {
      leader_qball2_mytest_B.SwitchKi_h = leader_qball2_mytest_P.KiPITCH_DOWN *
        rtb_Sum_bh_idx_1;
    }

    /* End of Switch: '<S81>/Switch - Ki' */

    /* Gain: '<S6>/Gain1' */
    leader_qball2_mytest_B.Gain1_a[0] = leader_qball2_mytest_P.Gain1_Gain_l *
      leader_qball2_mytest_B.angle_f;
    leader_qball2_mytest_B.Gain1_a[1] = leader_qball2_mytest_P.Gain1_Gain_l *
      leader_qball2_mytest_B.HPF;
    leader_qball2_mytest_B.Gain1_a[2] = leader_qball2_mytest_P.Gain1_Gain_l *
      leader_qball2_mytest_B.StreamClient_o3[8];
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* SignalGenerator: '<S7>/Signal Generator2' */
    K_1 = leader_qball2_mytest_P.SignalGenerator2_Frequency *
      leader_qball2_mytest_M->Timing.t[0];
    if (K_1 - floor(K_1) >= 0.5) {
      rtb_Integrator1_i = leader_qball2_mytest_P.SignalGenerator2_Amplitude;
    } else {
      rtb_Integrator1_i = -leader_qball2_mytest_P.SignalGenerator2_Amplitude;
    }

    /* End of SignalGenerator: '<S7>/Signal Generator2' */

    /* Gain: '<S95>/Slider Gain' */
    rtb_SliderGain_m = leader_qball2_mytest_P.SliderGain3_gain *
      rtb_Integrator1_i;

    /* Gain: '<S8>/Gain4' */
    leader_qball2_mytest_B.Gain4_g[0] = leader_qball2_mytest_P.Gain4_Gain_f *
      leader_qball2_mytest_B.Switch_f;
    leader_qball2_mytest_B.Gain4_g[1] = leader_qball2_mytest_P.Gain4_Gain_f *
      rtb_ManualSwitch_l;
    leader_qball2_mytest_B.Gain4_g[2] = leader_qball2_mytest_P.Gain4_Gain_f *
      leader_qball2_mytest_B.StreamClient_o3[7];
    leader_qball2_mytest_B.Gain4_g[3] = leader_qball2_mytest_P.Gain4_Gain_f *
      leader_qball2_mytest_B.angle_m;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Switch: '<S97>/Switch - Ki' incorporates:
     *  Gain: '<S97>/Ki - Battery DOWN'
     *  Gain: '<S97>/Ki - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKi_Threshold_c) {
      leader_qball2_mytest_B.SwitchKi_i = leader_qball2_mytest_P.KiROLL_UP *
        rtb_Sum2_ir;
    } else {
      leader_qball2_mytest_B.SwitchKi_i = leader_qball2_mytest_P.KiROLL_DOWN *
        rtb_Sum2_ir;
    }

    /* End of Switch: '<S97>/Switch - Ki' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* RelationalOperator: '<S102>/Compare' incorporates:
       *  Constant: '<S102>/Constant'
       */
      leader_qball2_mytest_B.Compare_p = (uint8_T)
        (leader_qball2_mytest_B.sf_EmbeddedMATLABFunction.y >
         leader_qball2_mytest_P.CompareToConstant_const_mk);
    }

    /* Product: '<S100>/Product' */
    leader_qball2_mytest_B.Product_n = K_0 * (real_T)
      leader_qball2_mytest_B.Compare_p;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* MATLAB Function: '<S103>/adjust_roll_command' */
    /* MATLAB Function 'Roll Controller/Subsystem/OT pos control/adjust_for_heading/adjust_roll_command': '<S105>:1' */
    /*  Given the roll and pitch commands computed for the global frame, this function */
    /*  rotates the roll command into the local frame, allowing the control */
    /*  command to work even for non-zero yaw. */
    /* '<S105>:1:8' */
    leader_qball2_mytest_B.adj_roll_cmd = leader_qball2_mytest_B.Product_n * cos
      (leader_qball2_mytest_B.angle) + rtb_Gain4 * sin
      (leader_qball2_mytest_B.angle);

    /* adj_roll_cmd = roll_cmd*cos(heading) - pitch_cmd*sin(heading); */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S107>/Constant' */
      leader_qball2_mytest_B.Constant_c =
        leader_qball2_mytest_P.Constant_Value_hg;

      /* Constant: '<S107>/x0' */
      leader_qball2_mytest_B.x0_i = leader_qball2_mytest_P.x0_Value_p;
    }

    /* Integrator: '<S107>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK_li.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE_e = leader_qball2_mytest_B.x0_i;
    }

    rtb_Integrator1_i = leader_qball2_mytest_X.Integrator1_CSTATE_e;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S107>/zt' */
      leader_qball2_mytest_B.zt_g =
        leader_qball2_mytest_P.SecondOrderLowPassFilter1_inp_e;
    }

    /* Product: '<S107>/Product' incorporates:
     *  Product: '<S107>/Product2'
     *  Sum: '<S107>/Sum'
     *  Sum: '<S107>/Sum1'
     */
    leader_qball2_mytest_B.Product_j =
      ((leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_d.y - rtb_Integrator1_i)
       - rtb_Integrator1_o * leader_qball2_mytest_B.Constant_c *
       leader_qball2_mytest_B.zt_g) * leader_qball2_mytest_B.wn_a5;

    /* Switch: '<S104>/Switch - Ki' incorporates:
     *  Gain: '<S104>/Ki - Battery DOWN'
     *  Gain: '<S104>/Ki - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKi_Threshold_g) {
      leader_qball2_mytest_B.SwitchKi_b = leader_qball2_mytest_P.KiOUTER_ROLL_UP
        * e;
    } else {
      leader_qball2_mytest_B.SwitchKi_b =
        leader_qball2_mytest_P.KiOUTER_ROLL_DOWN * e;
    }

    /* End of Switch: '<S104>/Switch - Ki' */

    /* Gain: '<S8>/Gain1' incorporates:
     *  MATLAB Function: '<S42>/calc_roll_pitch'
     */
    leader_qball2_mytest_B.Gain1_k[0] = leader_qball2_mytest_P.Gain1_Gain_ln *
      leader_qball2_mytest_B.angle_m;
    leader_qball2_mytest_B.Gain1_k[1] = leader_qball2_mytest_P.Gain1_Gain_ln *
      leader_qball2_mytest_B.ManualSwitch;
    leader_qball2_mytest_B.Gain1_k[2] = leader_qball2_mytest_P.Gain1_Gain_ln *
      leader_qball2_mytest_B.StreamClient_o3[7];
    leader_qball2_mytest_B.Gain1_k[3] = leader_qball2_mytest_P.Gain1_Gain_ln *
      roll_acc;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* DataTypeConversion: '<S112>/Data Type Conversion' */
      leader_qball2_mytest_B.DataTypeConversion =
        leader_qball2_mytest_B.StreamClient_o4;

      /* DataTypeConversion: '<S112>/Data Type Conversion1' */
      leader_qball2_mytest_B.DataTypeConversion1 =
        leader_qball2_mytest_B.RelationalOperator_og;

      /* DataTypeConversion: '<S112>/Data Type Conversion2' */
      leader_qball2_mytest_B.DataTypeConversion2 =
        leader_qball2_mytest_B.EnabledSubsystem1.RelationalOperator;

      /* DataTypeConversion: '<S112>/Data Type Conversion3' */
      leader_qball2_mytest_B.DataTypeConversion3 =
        leader_qball2_mytest_B.LogicalOperator2;

      /* SignalConversion: '<S10>/TmpSignal ConversionAtStream ServerInport1' incorporates:
       *  Constant: '<S10>/Dummy Heading Reference (rad)'
       */
      rtb_TmpSignalConversionAtStream[0] =
        leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_d.y;
      rtb_TmpSignalConversionAtStream[1] =
        leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_j4.y;
      rtb_TmpSignalConversionAtStream[2] =
        leader_qball2_mytest_P.DummyHeadingReferencerad_Value;

      /* S-Function (stream_server_block): '<S10>/Stream Server' */

      /* S-Function Block: leader_qball2_mytest/Serve Data For Follower/Stream Server (stream_server_block) */
      {
        t_pstream_state state;
        t_error send_result;
        if (leader_qball2_mytest_P.Enable_Value) {
          send_result = pstream_send(leader_qball2_mytest_DW.StreamServer_Stream,
            &rtb_TmpSignalConversionAtStream[0]);
        } else {
          send_result = 0;
        }

        leader_qball2_mytest_B.StreamServer_o3 = (send_result > 0);
        leader_qball2_mytest_B.StreamServer_o2 = 0;
        if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
          leader_qball2_mytest_B.StreamServer_o2 = send_result;
        }

        pstream_get_state(leader_qball2_mytest_DW.StreamServer_Stream, &state);
        leader_qball2_mytest_B.StreamServer_o1 = state;
      }

      /* Outputs for Triggered SubSystem: '<S124>/Triggered Sigmoid Compute' incorporates:
       *  TriggerPort: '<S125>/Trigger'
       */
      if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
        if (leader_qball2_mytest_B.LogicalOperator2 &&
            (leader_qball2_mytest_PrevZCX.TriggeredSigmoidCompute_Trig_ZC !=
             POS_ZCSIG)) {
          /* S-Function (sigmoid_compute): '<S125>/Sigmoid Compute' */
          /* S-Function Block: leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Limit descent rate/Triggered Sigmoid/Triggered Sigmoid Compute/Sigmoid Compute (sigmoid_compute) */
          {
            /*  update the sigmoid_params with the new target and initial position/velocity  */
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_X0] =
              leader_qball2_mytest_B.Switch;
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_V0] =
              leader_qball2_mytest_B.Constant1_o;
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_XD] =
              leader_qball2_mytest_B.landthrottletarget;

            /*  Check that the initial velocity does not exceed the maximum velocity */
            if (fabs
                (leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_V0])
                > leader_qball2_mytest_P.TriggeredSigmoid_max_velocity) {
              return;
            }

            /*  Compute the new trajectory  */
            sigmoid_calculate_trajectory
              (&leader_qball2_mytest_B.SigmoidCompute_o1[0], 0,
               leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_X0],
               leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_V0],
               leader_qball2_mytest_P.TriggeredSigmoid_max_accelerati,
               leader_qball2_mytest_P.TriggeredSigmoid_max_velocity);

            /*  Toggle the output flag  */
            if (leader_qball2_mytest_DW.SigmoidCompute_Toggle == 0) {
              leader_qball2_mytest_DW.SigmoidCompute_Toggle = 1;
            } else {
              leader_qball2_mytest_DW.SigmoidCompute_Toggle = 0;
            }

            leader_qball2_mytest_B.SigmoidCompute_o2 =
              leader_qball2_mytest_DW.SigmoidCompute_Toggle;
          }

          leader_qball2_mytest_DW.TriggeredSigmoidCompute_SubsysR = 4;
        }

        leader_qball2_mytest_PrevZCX.TriggeredSigmoidCompute_Trig_ZC = (uint8_T)
          (leader_qball2_mytest_B.LogicalOperator2 ? (int32_T)POS_ZCSIG :
           (int32_T)ZERO_ZCSIG);
      }

      /* End of Outputs for SubSystem: '<S124>/Triggered Sigmoid Compute' */

      /* Outputs for Enabled SubSystem: '<S130>/arm height command' incorporates:
       *  EnablePort: '<S134>/Enable'
       */
      if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
        if (leader_qball2_mytest_B.LogicalOperator) {
          if (!leader_qball2_mytest_DW.armheightcommand_MODE) {
            leader_qball2_mytest_DW.armheightcommand_MODE = true;
          }
        } else {
          if (leader_qball2_mytest_DW.armheightcommand_MODE) {
            /* Disable for Outport: '<S134>/Out1' */
            leader_qball2_mytest_B.In1 = leader_qball2_mytest_P.Out1_Y0_lz;
            leader_qball2_mytest_DW.armheightcommand_MODE = false;
          }
        }
      }

      /* End of Outputs for SubSystem: '<S130>/arm height command' */
    }

    /* Outputs for Enabled SubSystem: '<S130>/arm height command' incorporates:
     *  EnablePort: '<S134>/Enable'
     */
    if (leader_qball2_mytest_DW.armheightcommand_MODE) {
      /* Inport: '<S134>/In1' */
      leader_qball2_mytest_B.In1 = rtb_Switch;
      if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
        srUpdateBC(leader_qball2_mytest_DW.armheightcommand_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S130>/arm height command' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S139>/Constant' */
      leader_qball2_mytest_B.Constant_gl =
        leader_qball2_mytest_P.Constant_Value_h3z;

      /* Constant: '<S139>/x0' */
      leader_qball2_mytest_B.x0_g = leader_qball2_mytest_P.x0_Value_ch;
    }

    /* Integrator: '<S139>/Integrator1' */
    if (leader_qball2_mytest_DW.Integrator1_IWORK_g.IcNeedsLoading) {
      leader_qball2_mytest_X.Integrator1_CSTATE_d = leader_qball2_mytest_B.x0_g;
    }

    rtb_Integrator1_o = leader_qball2_mytest_X.Integrator1_CSTATE_d;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Constant: '<S139>/zt' */
      leader_qball2_mytest_B.zt_m =
        leader_qball2_mytest_P.SecondOrderLowPassFilter_input_;
    }

    /* Product: '<S139>/Product' incorporates:
     *  Product: '<S139>/Product2'
     *  Sum: '<S139>/Sum'
     *  Sum: '<S139>/Sum1'
     */
    leader_qball2_mytest_B.Product_lu =
      ((leader_qball2_mytest_B.ContinuousSigmoid_o1 - rtb_Integrator1_o) -
       rtb_Integrator2_p * leader_qball2_mytest_B.Constant_gl *
       leader_qball2_mytest_B.zt_m) * leader_qball2_mytest_B.wn_p;

    /* Switch: '<S131>/Switch - Ki' incorporates:
     *  Gain: '<S131>/Ki - Battery DOWN'
     *  Gain: '<S131>/Ki - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKi_Threshold_mj) {
      leader_qball2_mytest_B.SwitchKi_n = leader_qball2_mytest_P.KiHEIGHT_UP *
        rtb_SwitchBatteryConfigGyroTo_0;
    } else {
      leader_qball2_mytest_B.SwitchKi_n = leader_qball2_mytest_P.KiHEIGHT_DOWN *
        rtb_SwitchBatteryConfigGyroTo_0;
    }

    /* End of Switch: '<S131>/Switch - Ki' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    }

    /* Switch: '<S13>/Switch - Ki' incorporates:
     *  Gain: '<S13>/Ki - Battery DOWN'
     *  Gain: '<S13>/Ki - Battery UP'
     */
    if (leader_qball2_mytest_B.BatteryTopOrBottom >
        leader_qball2_mytest_P.SwitchKi_Threshold_b) {
      leader_qball2_mytest_B.SwitchKi_ih = leader_qball2_mytest_P.KiYAW_UP *
        leader_qball2_mytest_B.Sum4;
    } else {
      leader_qball2_mytest_B.SwitchKi_ih = leader_qball2_mytest_P.KiYAW_DOWN *
        leader_qball2_mytest_B.Sum4;
    }

    /* End of Switch: '<S13>/Switch - Ki' */
  }

  if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    real_T *lastU;
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Update for Memory: '<S3>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput[0] =
        leader_qball2_mytest_B.Product2[0];
      leader_qball2_mytest_DW.Memory_PreviousInput[1] =
        leader_qball2_mytest_B.Product2[1];
      leader_qball2_mytest_DW.Memory_PreviousInput[2] =
        leader_qball2_mytest_B.Product2[2];
      leader_qball2_mytest_DW.Memory_PreviousInput[3] =
        leader_qball2_mytest_B.Product2[3];

      /* Update for Memory: '<S62>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput_g =
        leader_qball2_mytest_B.sf_EmbeddedMATLABFunction.y;

      /* Update for Memory: '<S28>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput_b = leader_qball2_mytest_B.y;
    }

    /* Update for Derivative: '<S55>/Derivative' */
    if (leader_qball2_mytest_DW.TimeStampA == (rtInf)) {
      leader_qball2_mytest_DW.TimeStampA = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeA;
    } else if (leader_qball2_mytest_DW.TimeStampB == (rtInf)) {
      leader_qball2_mytest_DW.TimeStampB = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeB;
    } else if (leader_qball2_mytest_DW.TimeStampA <
               leader_qball2_mytest_DW.TimeStampB) {
      leader_qball2_mytest_DW.TimeStampA = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeA;
    } else {
      leader_qball2_mytest_DW.TimeStampB = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeB;
    }

    *lastU = leader_qball2_mytest_B.RateTransition;

    /* End of Update for Derivative: '<S55>/Derivative' */
    /* Update for Integrator: '<S32>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK.IcNeedsLoading = 0;

    /* Update for Integrator: '<S47>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK_j.IcNeedsLoading = 0;

    /* Update for Integrator: '<S48>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK_o.IcNeedsLoading = 0;

    /* Update for Integrator: '<S49>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK_l.IcNeedsLoading = 0;

    /* Update for Integrator: '<S50>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK_ov.IcNeedsLoading = 0;

    /* Update for RateLimiter: '<S7>/Rate Limiter3' */
    leader_qball2_mytest_DW.PrevY_k = leader_qball2_mytest_B.RateLimiter3;
    leader_qball2_mytest_DW.LastMajorTime = leader_qball2_mytest_M->Timing.t[0];

    {
      if (leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Target !=
          leader_qball2_mytest_B.In1) {
        leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Target =
          leader_qball2_mytest_B.In1;
        leader_qball2_mytest_DW.ContinuousSigmoid_Flag = 1;
      }
    }

    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      {
      }

      /* Update for Memory: '<S138>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput_p =
        leader_qball2_mytest_B.land;
    }

    {
    }

    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      {
        if (leader_qball2_mytest_DW.SigmoidPath_Toggle !=
            leader_qball2_mytest_B.SigmoidCompute_o2) {
          leader_qball2_mytest_DW.SigmoidPath_Toggle =
            leader_qball2_mytest_B.SigmoidCompute_o2;

          /*  Update the sigmoid parameters and set the flag  */
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_T1] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_T1];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_T2] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_T2];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_T3] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_T3];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_X0] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_X0];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_X1] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_X1];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_X2] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_X2];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_XD] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_XD];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_V0] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_V0];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_VP] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_VP];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_AP] =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_AP];
          leader_qball2_mytest_DW.SigmoidPath_NewPath[SIGMOID_PARAMETER_HOLD_OFF]
            =
            leader_qball2_mytest_B.SigmoidCompute_o1[SIGMOID_PARAMETER_HOLD_OFF];
          leader_qball2_mytest_DW.SigmoidPath_Flag = 1;
        }
      }
    }

    /* Update for Derivative: '<S123>/Derivative' */
    if (leader_qball2_mytest_DW.TimeStampA_e == (rtInf)) {
      leader_qball2_mytest_DW.TimeStampA_e = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeA_a;
    } else if (leader_qball2_mytest_DW.TimeStampB_c == (rtInf)) {
      leader_qball2_mytest_DW.TimeStampB_c = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeB_l;
    } else if (leader_qball2_mytest_DW.TimeStampA_e <
               leader_qball2_mytest_DW.TimeStampB_c) {
      leader_qball2_mytest_DW.TimeStampA_e = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeA_a;
    } else {
      leader_qball2_mytest_DW.TimeStampB_c = leader_qball2_mytest_M->Timing.t[0];
      lastU = &leader_qball2_mytest_DW.LastUAtTimeB_l;
    }

    *lastU = leader_qball2_mytest_B.ManualSwitch_a;

    /* End of Update for Derivative: '<S123>/Derivative' */
    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Update for Memory: '<S85>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput_i =
        leader_qball2_mytest_B.adj_pitch_cmd;
    }

    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Update for Memory: '<S103>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput_j =
        leader_qball2_mytest_B.adj_roll_cmd;
    }

    if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
      /* Update for Memory: '<S61>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput_it =
        leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_d.y;

      /* Update for Memory: '<S63>/Memory' */
      leader_qball2_mytest_DW.Memory_PreviousInput_m =
        leader_qball2_mytest_B.sf_EmbeddedMATLABFunction_j4.y;
    }

    /* Update for TransportDelay: '<S7>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &leader_qball2_mytest_DW.TransportDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &leader_qball2_mytest_DW.TransportDelay_PWORK.TUbufferPtrs[1];
      real_T simTime = leader_qball2_mytest_M->Timing.t[0];
      leader_qball2_mytest_DW.TransportDelay_IWORK.Head =
        ((leader_qball2_mytest_DW.TransportDelay_IWORK.Head <
          (leader_qball2_mytest_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
         (leader_qball2_mytest_DW.TransportDelay_IWORK.Head+1) : 0);
      if (leader_qball2_mytest_DW.TransportDelay_IWORK.Head ==
          leader_qball2_mytest_DW.TransportDelay_IWORK.Tail) {
        leader_qball2_mytest_DW.TransportDelay_IWORK.Tail =
          ((leader_qball2_mytest_DW.TransportDelay_IWORK.Tail <
            (leader_qball2_mytest_DW.TransportDelay_IWORK.CircularBufSize-1)) ?
           (leader_qball2_mytest_DW.TransportDelay_IWORK.Tail+1) : 0);
      }

      (*tBuffer)[leader_qball2_mytest_DW.TransportDelay_IWORK.Head] = simTime;
      (*uBuffer)[leader_qball2_mytest_DW.TransportDelay_IWORK.Head] =
        rtb_SliderGain_m;
    }

    /* Update for RateLimiter: '<S7>/Rate Limiter2' */
    leader_qball2_mytest_DW.PrevY_i = leader_qball2_mytest_B.RateLimiter2;
    leader_qball2_mytest_DW.LastMajorTime_c = leader_qball2_mytest_M->Timing.t[0];

    /* Update for RateLimiter: '<S7>/Rate Limiter1' */
    leader_qball2_mytest_DW.PrevY_a = leader_qball2_mytest_B.RateLimiter1;
    leader_qball2_mytest_DW.LastMajorTime_j = leader_qball2_mytest_M->Timing.t[0];

    /* Update for Integrator: '<S89>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK_b.IcNeedsLoading = 0;

    /* Update for Integrator: '<S107>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK_li.IcNeedsLoading = 0;

    /* Update for Integrator: '<S139>/Integrator1' */
    leader_qball2_mytest_DW.Integrator1_IWORK_g.IcNeedsLoading = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(3);
    rtExtModeUpload(1, leader_qball2_mytest_M->Timing.t[0]);
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(leader_qball2_mytest_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(leader_qball2_mytest_M)!=-1) &&
          !((rtmGetTFinal(leader_qball2_mytest_M)-
             (((leader_qball2_mytest_M->Timing.clockTick1+
                leader_qball2_mytest_M->Timing.clockTickH1* 4294967296.0)) *
              0.002)) > (((leader_qball2_mytest_M->Timing.clockTick1+
                           leader_qball2_mytest_M->Timing.clockTickH1*
                           4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(leader_qball2_mytest_M, "Simulation finished");
      }

      if (rtmGetStopRequested(leader_qball2_mytest_M)) {
        rtmSetErrorStatus(leader_qball2_mytest_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&leader_qball2_mytest_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++leader_qball2_mytest_M->Timing.clockTick0)) {
      ++leader_qball2_mytest_M->Timing.clockTickH0;
    }

    leader_qball2_mytest_M->Timing.t[0] = rtsiGetSolverStopTime
      (&leader_qball2_mytest_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.002, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    leader_qball2_mytest_M->Timing.clockTick1++;
    if (!leader_qball2_mytest_M->Timing.clockTick1) {
      leader_qball2_mytest_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void leader_qball2_mytest_derivatives(void)
{
  XDot_leader_qball2_mytest_T *_rtXdot;
  _rtXdot = ((XDot_leader_qball2_mytest_T *)
             leader_qball2_mytest_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S48>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = leader_qball2_mytest_B.Product_l;

  /* Derivatives for Integrator: '<S32>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = leader_qball2_mytest_B.Product1_e[0];
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = leader_qball2_mytest_B.Product1_e[1];
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = leader_qball2_mytest_B.Product1_e[2];
  }

  /* Derivatives for TransferFcn: '<S29>/High Pass Filter - Roll' */
  _rtXdot->HighPassFilterRoll_CSTATE = 0.0;
  _rtXdot->HighPassFilterRoll_CSTATE +=
    leader_qball2_mytest_P.HighPassFilterRoll_A *
    leader_qball2_mytest_X.HighPassFilterRoll_CSTATE;
  _rtXdot->HighPassFilterRoll_CSTATE += leader_qball2_mytest_B.Sum[0];

  /* Derivatives for TransferFcn: '<S29>/High Pass Filter - Pitch' */
  _rtXdot->HighPassFilterPitch_CSTATE = 0.0;
  _rtXdot->HighPassFilterPitch_CSTATE +=
    leader_qball2_mytest_P.HighPassFilterPitch_A *
    leader_qball2_mytest_X.HighPassFilterPitch_CSTATE;
  _rtXdot->HighPassFilterPitch_CSTATE += leader_qball2_mytest_B.Sum[1];

  /* Derivatives for Integrator: '<S49>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_j = leader_qball2_mytest_B.Product_d;

  /* Derivatives for Integrator: '<S50>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_i = leader_qball2_mytest_B.Product_g;

  /* Derivatives for Integrator: '<S47>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE_l = leader_qball2_mytest_B.Product1_a;
  }

  /* Derivatives for TransferFcn: '<S29>/High Pass Filter - Yaw' */
  _rtXdot->HighPassFilterYaw_CSTATE = 0.0;
  _rtXdot->HighPassFilterYaw_CSTATE +=
    leader_qball2_mytest_P.HighPassFilterYaw_A *
    leader_qball2_mytest_X.HighPassFilterYaw_CSTATE;
  _rtXdot->HighPassFilterYaw_CSTATE += leader_qball2_mytest_B.Sum[2];

  /* Derivatives for Integrator: '<S47>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_o = leader_qball2_mytest_B.Product_f;

  /* Derivatives for Integrator: '<S48>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE_a = leader_qball2_mytest_B.Product1;
  }

  /* Derivatives for Integrator: '<S49>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE_ly = leader_qball2_mytest_B.Product1_o;
  }

  /* Derivatives for Integrator: '<S50>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE_lyr = leader_qball2_mytest_B.Product1_k;
  }

  /* Derivatives for Integrator: '<S32>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_i2[0] = leader_qball2_mytest_B.Product_lj[0];
  _rtXdot->Integrator2_CSTATE_i2[1] = leader_qball2_mytest_B.Product_lj[1];
  _rtXdot->Integrator2_CSTATE_i2[2] = leader_qball2_mytest_B.Product_lj[2];

  /* Derivatives for TransferFcn: '<S23>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += leader_qball2_mytest_P.TransferFcn_A *
    leader_qball2_mytest_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += leader_qball2_mytest_B.Divide;

  /* Derivatives for TransferFcn: '<S14>/LPF' */
  _rtXdot->LPF_CSTATE = 0.0;
  _rtXdot->LPF_CSTATE += leader_qball2_mytest_P.LPF_A *
    leader_qball2_mytest_X.LPF_CSTATE;
  _rtXdot->LPF_CSTATE += leader_qball2_mytest_B.Fcn;

  /* Derivatives for Integrator: '<S14>/Integrator' */
  _rtXdot->Integrator_CSTATE = leader_qball2_mytest_B.Sum[1];

  /* Derivatives for TransferFcn: '<S14>/HPF' */
  _rtXdot->HPF_CSTATE = 0.0;
  _rtXdot->HPF_CSTATE += leader_qball2_mytest_P.HPF_A *
    leader_qball2_mytest_X.HPF_CSTATE;
  _rtXdot->HPF_CSTATE += leader_qball2_mytest_B.Integrator;

  /* Derivatives for TransferFcn: '<S15>/LPF1' */
  _rtXdot->LPF1_CSTATE = 0.0;
  _rtXdot->LPF1_CSTATE += leader_qball2_mytest_P.LPF1_A *
    leader_qball2_mytest_X.LPF1_CSTATE;
  _rtXdot->LPF1_CSTATE += leader_qball2_mytest_B.Fcn_a;

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = leader_qball2_mytest_B.Sum[0];

  /* Derivatives for TransferFcn: '<S15>/HPF1' */
  _rtXdot->HPF1_CSTATE = 0.0;
  _rtXdot->HPF1_CSTATE += leader_qball2_mytest_P.HPF1_A *
    leader_qball2_mytest_X.HPF1_CSTATE;
  _rtXdot->HPF1_CSTATE += leader_qball2_mytest_B.Integrator_f;

  /* Derivatives for TransferFcn: '<S13>/Low Pass Filter (Filtered Yaw Rate)' */
  _rtXdot->LowPassFilterFilteredYawRate_CS = 0.0;
  _rtXdot->LowPassFilterFilteredYawRate_CS +=
    leader_qball2_mytest_P.LowPassFilterFilteredYawRate_A *
    leader_qball2_mytest_X.LowPassFilterFilteredYawRate_CS;
  _rtXdot->LowPassFilterFilteredYawRate_CS += leader_qball2_mytest_B.Sum[2];

  /* Derivatives for Integrator: '<S139>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e = leader_qball2_mytest_B.Product_lu;

  /* Derivatives for Integrator: '<S131>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( leader_qball2_mytest_X.Integrator_CSTATE_ga <=
            leader_qball2_mytest_P.Integrator_LowerSat );
    usat = ( leader_qball2_mytest_X.Integrator_CSTATE_ga >=
            leader_qball2_mytest_P.Integrator_UpperSat );
    if (!leader_qball2_mytest_B.LogicalOperator2_o && ((!lsat && !usat) ||
         (lsat && (leader_qball2_mytest_B.SwitchKi_n > 0)) ||
         (usat && (leader_qball2_mytest_B.SwitchKi_n < 0))) ) {
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator_CSTATE_ga = leader_qball2_mytest_B.SwitchKi_n;
    } else {
      /* in saturation or level reset is active */
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator_CSTATE_ga = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S13>/Integrator' */
  {
    if (!leader_qball2_mytest_B.Compare_h) {
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator_CSTATE_h = leader_qball2_mytest_B.SwitchKi_ih;
    } else {
      /* level reset is active*/
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator_CSTATE_h = 0.0;
    }
  }

  /* Derivatives for TransferFcn: '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)' */
  _rtXdot->LowPassFilterFilteredYawRateFor = 0.0;
  _rtXdot->LowPassFilterFilteredYawRateFor +=
    leader_qball2_mytest_P.LowPassFilterFilteredYawRateFor *
    leader_qball2_mytest_X.LowPassFilterFilteredYawRateFor;
  _rtXdot->LowPassFilterFilteredYawRateFor += leader_qball2_mytest_B.Sum[2];

  /* Derivatives for TransferFcn: '<S81>/Low Pass Filter (Filtered Pitch Rate)' */
  _rtXdot->LowPassFilterFilteredPitchRate_ = 0.0;
  _rtXdot->LowPassFilterFilteredPitchRate_ +=
    leader_qball2_mytest_P.LowPassFilterFilteredPitchRate_ *
    leader_qball2_mytest_X.LowPassFilterFilteredPitchRate_;
  _rtXdot->LowPassFilterFilteredPitchRate_ += leader_qball2_mytest_B.Sum[1];

  /* Derivatives for Integrator: '<S81>/Integrator1' */
  {
    if (!leader_qball2_mytest_B.Compare_f) {
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator1_CSTATE_g = leader_qball2_mytest_B.SwitchKi_h;
    } else {
      /* level reset is active*/
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator1_CSTATE_g = 0.0;
    }
  }

  /* Derivatives for TransferFcn: '<S97>/Low Pass Filter (Filtered Roll Rate)' */
  _rtXdot->LowPassFilterFilteredRollRate_C = 0.0;
  _rtXdot->LowPassFilterFilteredRollRate_C +=
    leader_qball2_mytest_P.LowPassFilterFilteredRollRate_A *
    leader_qball2_mytest_X.LowPassFilterFilteredRollRate_C;
  _rtXdot->LowPassFilterFilteredRollRate_C += leader_qball2_mytest_B.Sum[0];

  /* Derivatives for Integrator: '<S97>/Integrator1' */
  {
    if (!leader_qball2_mytest_B.Compare_n) {
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator1_CSTATE_n = leader_qball2_mytest_B.SwitchKi_i;
    } else {
      /* level reset is active*/
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator1_CSTATE_n = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S89>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_ir = leader_qball2_mytest_B.Product_b;

  /* Derivatives for Integrator: '<S86>/Integrator' */
  {
    if (!leader_qball2_mytest_B.LogicalOperator1_o) {
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator_CSTATE_k = leader_qball2_mytest_B.SwitchKi;
    } else {
      /* level reset is active*/
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator_CSTATE_k = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S107>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_a = leader_qball2_mytest_B.Product_j;

  /* Derivatives for Integrator: '<S104>/Integrator1' */
  {
    if (!leader_qball2_mytest_B.LogicalOperator1_h) {
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator1_CSTATE_nx = leader_qball2_mytest_B.SwitchKi_b;
    } else {
      /* level reset is active*/
      ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs
        )->Integrator1_CSTATE_nx = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S89>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE_c = leader_qball2_mytest_B.Product1_ey;
  }

  /* Derivatives for Integrator: '<S107>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE_e = leader_qball2_mytest_B.Product1_d;
  }

  /* Derivatives for Integrator: '<S139>/Integrator1' */
  {
    ((XDot_leader_qball2_mytest_T *) leader_qball2_mytest_M->ModelData.derivs)
      ->Integrator1_CSTATE_d = leader_qball2_mytest_B.Product1_n;
  }
}

/* Model step function for TID2 */
void leader_qball2_mytest_step2(void)  /* Sample time: [0.1s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DigitalClock;
  real_T rtb_Sum_k;
  real_T rtb_DigitalClock_k;

  /* DigitalClock: '<S54>/Digital Clock' */
  rtb_DigitalClock = (((leader_qball2_mytest_M->Timing.clockTick2+
                        leader_qball2_mytest_M->Timing.clockTickH2* 4294967296.0))
                      * 0.1);

  /* Sum: '<S54>/Sum' incorporates:
   *  UnitDelay: '<S54>/Unit Delay'
   */
  rtb_Sum_k = leader_qball2_mytest_B.RateTransition4 -
    leader_qball2_mytest_DW.UnitDelay_DSTATE;

  /* DigitalClock: '<S55>/Digital Clock' */
  rtb_DigitalClock_k = (((leader_qball2_mytest_M->Timing.clockTick2+
    leader_qball2_mytest_M->Timing.clockTickH2* 4294967296.0)) * 0.1);

  /* Update for RateTransition: '<S55>/Rate Transition' */
  leader_qball2_mytest_DW.RateTransition_Buffer0 = rtb_DigitalClock_k;

  /* Update for RateTransition: '<S54>/Rate Transition1' */
  leader_qball2_mytest_DW.RateTransition1_Buffer0 = rtb_Sum_k;

  /* Update for RateTransition: '<S54>/Rate Transition' */
  leader_qball2_mytest_DW.RateTransition_Buffer0_l = rtb_DigitalClock;

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  leader_qball2_mytest_DW.UnitDelay_DSTATE =
    leader_qball2_mytest_B.RateTransition4;
  rtExtModeUpload(2, (((leader_qball2_mytest_M->Timing.clockTick2+
                        leader_qball2_mytest_M->Timing.clockTickH2* 4294967296.0))
                      * 0.1));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  leader_qball2_mytest_M->Timing.clockTick2++;
  if (!leader_qball2_mytest_M->Timing.clockTick2) {
    leader_qball2_mytest_M->Timing.clockTickH2++;
  }
}

/* Model step wrapper function for compatibility with a static main program */
void leader_qball2_mytest_step(int_T tid)
{
  switch (tid) {
   case 0 :
    leader_qball2_mytest_step0();
    break;

   case 2 :
    leader_qball2_mytest_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void leader_qball2_mytest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)leader_qball2_mytest_M, 0,
                sizeof(RT_MODEL_leader_qball2_mytest_T));
  (leader_qball2_mytest_M)->Timing.TaskCounters.cLimit[0] = 1;
  (leader_qball2_mytest_M)->Timing.TaskCounters.cLimit[1] = 1;
  (leader_qball2_mytest_M)->Timing.TaskCounters.cLimit[2] = 50;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&leader_qball2_mytest_M->solverInfo,
                          &leader_qball2_mytest_M->Timing.simTimeStep);
    rtsiSetTPtr(&leader_qball2_mytest_M->solverInfo, &rtmGetTPtr
                (leader_qball2_mytest_M));
    rtsiSetStepSizePtr(&leader_qball2_mytest_M->solverInfo,
                       &leader_qball2_mytest_M->Timing.stepSize0);
    rtsiSetdXPtr(&leader_qball2_mytest_M->solverInfo,
                 &leader_qball2_mytest_M->ModelData.derivs);
    rtsiSetContStatesPtr(&leader_qball2_mytest_M->solverInfo, (real_T **)
                         &leader_qball2_mytest_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&leader_qball2_mytest_M->solverInfo,
      &leader_qball2_mytest_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&leader_qball2_mytest_M->solverInfo,
                          (&rtmGetErrorStatus(leader_qball2_mytest_M)));
    rtsiSetRTModelPtr(&leader_qball2_mytest_M->solverInfo,
                      leader_qball2_mytest_M);
  }

  rtsiSetSimTimeStep(&leader_qball2_mytest_M->solverInfo, MAJOR_TIME_STEP);
  leader_qball2_mytest_M->ModelData.intgData.f[0] =
    leader_qball2_mytest_M->ModelData.odeF[0];
  leader_qball2_mytest_M->ModelData.contStates = ((X_leader_qball2_mytest_T *)
    &leader_qball2_mytest_X);
  rtsiSetSolverData(&leader_qball2_mytest_M->solverInfo, (void *)
                    &leader_qball2_mytest_M->ModelData.intgData);
  rtsiSetSolverName(&leader_qball2_mytest_M->solverInfo,"ode1");
  rtmSetTPtr(leader_qball2_mytest_M, &leader_qball2_mytest_M->Timing.tArray[0]);
  rtmSetTFinal(leader_qball2_mytest_M, -1);
  leader_qball2_mytest_M->Timing.stepSize0 = 0.002;
  rtmSetFirstInitCond(leader_qball2_mytest_M, 1);

  /* External mode info */
  leader_qball2_mytest_M->Sizes.checksums[0] = (112178149U);
  leader_qball2_mytest_M->Sizes.checksums[1] = (365111478U);
  leader_qball2_mytest_M->Sizes.checksums[2] = (3125634437U);
  leader_qball2_mytest_M->Sizes.checksums[3] = (4112400441U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[84];
    leader_qball2_mytest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_d;
    systemRan[2] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_m;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledMovingAverage_c.EnabledMovingAverage_SubsysRanB;
    systemRan[6] = (sysRanDType *)
      &leader_qball2_mytest_DW.SwitchCaseActionSubsystem_Subsy;
    systemRan[7] = (sysRanDType *)
      &leader_qball2_mytest_DW.SwitchCaseActionSubsystem1_Subs;
    systemRan[8] = (sysRanDType *)
      &leader_qball2_mytest_DW.SwitchCaseActionSubsystem2_Subs;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledMovingAverage_e.EnabledMovingAverage_SubsysRanB;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)
      &leader_qball2_mytest_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledMovingAverage_SubsysRanB;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem2_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystemLatchOutputHigh;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_h;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = &rtAlwaysEnabled;
    systemRan[58] = &rtAlwaysEnabled;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = (sysRanDType *)
      &leader_qball2_mytest_DW.TriggeredSigmoidCompute_SubsysR;
    systemRan[66] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem1_b.EnabledSubsystem1_SubsysRanBC;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = (sysRanDType *)
      &leader_qball2_mytest_DW.EnabledSubsystem_SubsysRanBC_l;
    systemRan[69] = (sysRanDType *)
      &leader_qball2_mytest_DW.armheightcommand_SubsysRanBC;
    systemRan[70] = &rtAlwaysEnabled;
    systemRan[71] = &rtAlwaysEnabled;
    systemRan[72] = &rtAlwaysEnabled;
    systemRan[73] = &rtAlwaysEnabled;
    systemRan[74] = &rtAlwaysEnabled;
    systemRan[75] = &rtAlwaysEnabled;
    systemRan[76] = &rtAlwaysEnabled;
    systemRan[77] = &rtAlwaysEnabled;
    systemRan[78] = &rtAlwaysEnabled;
    systemRan[79] = &rtAlwaysEnabled;
    systemRan[80] = &rtAlwaysEnabled;
    systemRan[81] = &rtAlwaysEnabled;
    systemRan[82] = &rtAlwaysEnabled;
    systemRan[83] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(leader_qball2_mytest_M->extModeInfo,
      &leader_qball2_mytest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(leader_qball2_mytest_M->extModeInfo,
                        leader_qball2_mytest_M->Sizes.checksums);
    rteiSetTPtr(leader_qball2_mytest_M->extModeInfo, rtmGetTPtr
                (leader_qball2_mytest_M));
  }

  /* block I/O */
  (void) memset(((void *) &leader_qball2_mytest_B), 0,
                sizeof(B_leader_qball2_mytest_T));

  /* states (continuous) */
  {
    (void) memset((void *)&leader_qball2_mytest_X, 0,
                  sizeof(X_leader_qball2_mytest_T));
  }

  /* states (dwork) */
  (void) memset((void *)&leader_qball2_mytest_DW, 0,
                sizeof(DW_leader_qball2_mytest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    leader_qball2_mytest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: leader_qball2_mytest/DAQ/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qball2", "0", &leader_qball2_mytest_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (leader_qball2_mytest_DW.HILInitialize_Card,
       "gyro_fs=500;gyro_rate=800;gyro_bw=110;accel_rate=800;accel_fs=8", 64);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(leader_qball2_mytest_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
      return;
    }

    if ((leader_qball2_mytest_P.HILInitialize_set_analog_input_ && !is_switching)
        || (leader_qball2_mytest_P.HILInitialize_set_analog_inpu_e &&
            is_switching)) {
      result = hil_set_analog_input_ranges
        (leader_qball2_mytest_DW.HILInitialize_Card,
         leader_qball2_mytest_P.HILInitialize_analog_input_chan, 3U,
         leader_qball2_mytest_P.HILInitialize_analog_input_mini,
         leader_qball2_mytest_P.HILInitialize_analog_input_maxi);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (leader_qball2_mytest_DW.HILInitialize_Card, NULL, 0U,
       leader_qball2_mytest_P.HILInitialize_digital_output_ch, 2U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
      return;
    }

    if ((leader_qball2_mytest_P.HILInitialize_set_digital_out_c && !is_switching)
        || (leader_qball2_mytest_P.HILInitialize_set_digital_out_o &&
            is_switching)) {
      leader_qball2_mytest_DW.HILInitialize_DOBits[0] =
        leader_qball2_mytest_P.HILInitialize_initial_digital_o;
      leader_qball2_mytest_DW.HILInitialize_DOBits[1] =
        leader_qball2_mytest_P.HILInitialize_initial_digital_o;
      result = hil_write_digital(leader_qball2_mytest_DW.HILInitialize_Card,
        leader_qball2_mytest_P.HILInitialize_digital_output_ch, 2U, (t_boolean *)
        &leader_qball2_mytest_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        return;
      }
    }

    if (leader_qball2_mytest_P.HILInitialize_set_digital_out_n) {
      leader_qball2_mytest_DW.HILInitialize_DOStates[0] =
        leader_qball2_mytest_P.HILInitialize_watchdog_digital_;
      leader_qball2_mytest_DW.HILInitialize_DOStates[1] =
        leader_qball2_mytest_P.HILInitialize_watchdog_digital_;
      result = hil_watchdog_set_digital_expiration_state
        (leader_qball2_mytest_DW.HILInitialize_Card,
         leader_qball2_mytest_P.HILInitialize_digital_output_ch, 2U, (const
          t_digital_state *) &leader_qball2_mytest_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        return;
      }
    }

    if ((leader_qball2_mytest_P.HILInitialize_set_other_outputs && !is_switching)
        || (leader_qball2_mytest_P.HILInitialize_set_other_outpu_f &&
            is_switching)) {
      leader_qball2_mytest_DW.HILInitialize_OOValues[0] =
        leader_qball2_mytest_P.HILInitialize_initial_other_out;
      leader_qball2_mytest_DW.HILInitialize_OOValues[1] =
        leader_qball2_mytest_P.HILInitialize_initial_other_out;
      leader_qball2_mytest_DW.HILInitialize_OOValues[2] =
        leader_qball2_mytest_P.HILInitialize_initial_other_out;
      leader_qball2_mytest_DW.HILInitialize_OOValues[3] =
        leader_qball2_mytest_P.HILInitialize_initial_other_out;
      result = hil_write_other(leader_qball2_mytest_DW.HILInitialize_Card,
        leader_qball2_mytest_P.HILInitialize_other_output_chan, 4U,
        &leader_qball2_mytest_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        return;
      }
    }

    if (leader_qball2_mytest_P.HILInitialize_set_other_outp_i5) {
      leader_qball2_mytest_DW.HILInitialize_OOValues[0] =
        leader_qball2_mytest_P.HILInitialize_watchdog_other_ou;
      leader_qball2_mytest_DW.HILInitialize_OOValues[1] =
        leader_qball2_mytest_P.HILInitialize_watchdog_other_ou;
      leader_qball2_mytest_DW.HILInitialize_OOValues[2] =
        leader_qball2_mytest_P.HILInitialize_watchdog_other_ou;
      leader_qball2_mytest_DW.HILInitialize_OOValues[3] =
        leader_qball2_mytest_P.HILInitialize_watchdog_other_ou;
      result = hil_watchdog_set_other_expiration_state
        (leader_qball2_mytest_DW.HILInitialize_Card,
         leader_qball2_mytest_P.HILInitialize_other_output_chan, 4U,
         &leader_qball2_mytest_DW.HILInitialize_OOValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (sample_time_block): '<S3>/Sample Time' */

  /* S-Function Block: leader_qball2_mytest/DAQ/Sample Time (sample_time_block) */
  {
    t_error result;
    result = timeout_get_high_resolution_time
      (&leader_qball2_mytest_DW.SampleTime_PreviousTime);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (stream_client_block): '<S4>/Stream Client' */

  /* S-Function Block: leader_qball2_mytest/Data from host/Stream Client (stream_client_block) */
  {
    leader_qball2_mytest_DW.StreamClient_Stream = NULL;

    {
      int_T i1;
      real_T *y2 = &leader_qball2_mytest_B.StreamClient_o3[0];
      const real_T *p_StreamClient_default_value =
        leader_qball2_mytest_P.StreamClient_default_value;
      for (i1=0; i1 < 10; i1++) {
        y2[i1] = p_StreamClient_default_value[i1];
      }
    }

    leader_qball2_mytest_DW.StreamClient_Connected = false;
  }

  /* Start for Constant: '<S29>/Constant3' */
  leader_qball2_mytest_B.Constant3 = leader_qball2_mytest_P.Constant3_Value;

  /* Start for RateTransition: '<S55>/Rate Transition' */
  leader_qball2_mytest_B.RateTransition =
    leader_qball2_mytest_P.RateTransition_X0;

  /* Start for RateTransition: '<S54>/Rate Transition1' */
  leader_qball2_mytest_B.RateTransition1 =
    leader_qball2_mytest_P.RateTransition1_X0;

  /* Start for RateTransition: '<S54>/Rate Transition' */
  leader_qball2_mytest_B.RateTransition_c =
    leader_qball2_mytest_P.RateTransition_X0_o;

  /* Start for Atomic SubSystem: '<S26>/Bias Removal' */

  /* Start for Enabled SubSystem: '<S31>/Enabled Moving Average' */
  lead_EnabledMovingAverage_Start
    (&leader_qball2_mytest_DW.EnabledMovingAverage_c,
     (P_EnabledMovingAverage_leader_T *)
     &leader_qball2_mytest_P.EnabledMovingAverage_c);

  /* End of Start for SubSystem: '<S31>/Enabled Moving Average' */

  /* Start for SwitchCase: '<S31>/Switch Case' */
  leader_qball2_mytest_DW.SwitchCase_ActiveSubsystem = -1;

  /* End of Start for SubSystem: '<S26>/Bias Removal' */

  /* Start for Constant: '<S32>/x0' */
  leader_qball2_mytest_B.x0 = leader_qball2_mytest_P.x0_Value;

  /* Start for Enabled SubSystem: '<S30>/Enabled Moving Average' */
  leader_qball2_mytest_DW.EnabledMovingAverage_MODE = false;

  /* End of Start for SubSystem: '<S30>/Enabled Moving Average' */

  /* InitializeConditions for Enabled SubSystem: '<S30>/Enabled Moving Average' */
  /* InitializeConditions for UnitDelay: '<S58>/Unit Delay' */
  leader_qball2_mytest_DW.UnitDelay_DSTATE_o =
    leader_qball2_mytest_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S57>/Sum( k=1,n-1, x(k) )' */
  leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[0] =
    leader_qball2_mytest_P.Sumk1n1xk_InitialCondition;
  leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[1] =
    leader_qball2_mytest_P.Sumk1n1xk_InitialCondition;
  leader_qball2_mytest_DW.Sumk1n1xk_DSTATE[2] =
    leader_qball2_mytest_P.Sumk1n1xk_InitialCondition;

  /* End of InitializeConditions for SubSystem: '<S30>/Enabled Moving Average' */

  /* Start for Constant: '<S29>/Constant' */
  leader_qball2_mytest_B.Constant = leader_qball2_mytest_P.Constant_Value_jv;

  /* Start for Constant: '<S29>/Constant1' */
  leader_qball2_mytest_B.Constant1 = leader_qball2_mytest_P.Constant1_Value;

  /* Start for Constant: '<S47>/x0' */
  leader_qball2_mytest_B.x0_p = leader_qball2_mytest_P.x0_Value_a;

  /* Start for Constant: '<S29>/Constant2' */
  leader_qball2_mytest_B.Constant2 = leader_qball2_mytest_P.Constant2_Value;

  /* Start for S-Function (inverse_modulus_block): '<S4>/Inverse Modulus' */
  /* S-Function Block: leader_qball2_mytest/Data from host/Inverse Modulus (inverse_modulus_block) */
  {
    leader_qball2_mytest_DW.InverseModulus_FirstSample = true;
    leader_qball2_mytest_DW.InverseModulus_Revolutions = 0;
  }

  /* Start for Constant: '<S48>/x0' */
  leader_qball2_mytest_B.x0_h = leader_qball2_mytest_P.x0_Value_h;

  /* Start for Constant: '<S49>/x0' */
  leader_qball2_mytest_B.x0_j = leader_qball2_mytest_P.x0_Value_c;

  /* Start for Constant: '<S50>/x0' */
  leader_qball2_mytest_B.x0_d = leader_qball2_mytest_P.x0_Value_k;

  /* Start for Enabled SubSystem: '<S27>/Enabled Moving Average' */
  lead_EnabledMovingAverage_Start
    (&leader_qball2_mytest_DW.EnabledMovingAverage_e,
     (P_EnabledMovingAverage_leader_T *)
     &leader_qball2_mytest_P.EnabledMovingAverage_e);

  /* End of Start for SubSystem: '<S27>/Enabled Moving Average' */

  /* Start for S-Function (hil_watchdog_block): '<S3>/HIL Watchdog' */

  /* S-Function Block: leader_qball2_mytest/DAQ/HIL Watchdog (hil_watchdog_block) */
  {
    leader_qball2_mytest_DW.HILWatchdog_IsStarted = false;
  }

  /* Start for Enabled SubSystem: '<S66>/Enabled Subsystem Latch Output High' */
  /* VirtualOutportStart for Outport: '<S79>/Out1' */
  leader_qball2_mytest_B.Constant_om = leader_qball2_mytest_P.Out1_Y0_o;

  /* End of Start for SubSystem: '<S66>/Enabled Subsystem Latch Output High' */

  /* Start for Enabled SubSystem: '<S66>/Enabled Subsystem' */
  leader_qball2_mytest_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S66>/Enabled Subsystem' */

  /* InitializeConditions for Enabled SubSystem: '<S66>/Enabled Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S76>/Discrete-Time Integrator' */
  leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE =
    leader_qball2_mytest_P.DiscreteTimeIntegrator_IC_m;

  /* End of InitializeConditions for SubSystem: '<S66>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S66>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S76>/timeout' */
  leader_qball2_mytest_B.RelationalOperator_og =
    leader_qball2_mytest_P.timeout_Y0_k;

  /* End of Start for SubSystem: '<S66>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S66>/Enabled Subsystem1' */
  leader__EnabledSubsystem1_Start(&leader_qball2_mytest_B.EnabledSubsystem1,
    &leader_qball2_mytest_DW.EnabledSubsystem1, (P_EnabledSubsystem1_leader_qb_T
    *)&leader_qball2_mytest_P.EnabledSubsystem1);

  /* End of Start for SubSystem: '<S66>/Enabled Subsystem1' */

  /* Start for Enabled SubSystem: '<S66>/Enabled Subsystem2' */
  /* VirtualOutportStart for Outport: '<S78>/Out1' */
  leader_qball2_mytest_B.Constant_mq = leader_qball2_mytest_P.Out1_Y0_f;

  /* End of Start for SubSystem: '<S66>/Enabled Subsystem2' */

  /* Start for Enabled SubSystem: '<S129>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S133>/Out1' */
  leader_qball2_mytest_B.Constant_hf = leader_qball2_mytest_P.Out1_Y0_gt;

  /* End of Start for SubSystem: '<S129>/Enabled Subsystem' */
  /* Start for S-Function (continuous_sigmoid_block): '<S130>/Continuous Sigmoid' */

  /* S-Function Block: leader_qball2_mytest/Throttle and height control/height control/sigmoid1/Continuous Sigmoid (continuous_sigmoid_block) */
  {
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T1] = 0;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T2] = 0;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_T3] = 0;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X0] =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_posit;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X1] =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_posit;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_X2] =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_posit;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_XD] =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_posit;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_V0] =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_veloc;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_VP] = 0;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_AP] = 0;
    leader_qball2_mytest_DW.ContinuousSigmoid_Sigmoid[SIGMOID_PARAMETER_HOLD_OFF]
      = leader_qball2_mytest_P.ContinuousSigmoid_hold_off;
    leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Time = 0;
    leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.Target =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_posit;
    leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.PPos =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_posit;
    leader_qball2_mytest_DW.ContinuousSigmoid_RWORK.PVel =
      leader_qball2_mytest_P.ContinuousSigmoid_initial_veloc;
    leader_qball2_mytest_DW.ContinuousSigmoid_Flag = 0;
  }

  /* Start for Constant: '<S131>/Constant' */
  leader_qball2_mytest_B.Constant_ov = leader_qball2_mytest_P.Constant_Value_bn;

  /* Start for Constant: '<S117>/height command1' */
  leader_qball2_mytest_B.heightcommand1 =
    leader_qball2_mytest_P.joystick_range_min;

  /* Start for Constant: '<S117>/height command2' */
  leader_qball2_mytest_B.heightcommand2 =
    leader_qball2_mytest_P.joystick_range_max;

  /* Start for Constant: '<S122>/Constant1' */
  leader_qball2_mytest_B.Constant1_o = leader_qball2_mytest_P.Constant1_Value_j;

  /* Start for Constant: '<S122>/land throttle target' */
  leader_qball2_mytest_B.landthrottletarget =
    leader_qball2_mytest_P.landthrottletarget_Value;

  /* Start for S-Function (sigmoid_path): '<S124>/Sigmoid Path' */

  /* S-Function Block: leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Limit descent rate/Triggered Sigmoid/Sigmoid Path (sigmoid_path) */
  {
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T1] = 0;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T2] = 0;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_T3] = 0;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X0] =
      leader_qball2_mytest_B.Switch;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X1] = 0;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_X2] = 0;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_XD] =
      leader_qball2_mytest_B.landthrottletarget;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_V0] =
      leader_qball2_mytest_B.Constant1_o;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_VP] = 0;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_AP] = 0;
    leader_qball2_mytest_DW.SigmoidPath_Path[SIGMOID_PARAMETER_HOLD_OFF] =
      leader_qball2_mytest_P.TriggeredSigmoid_hold_off;
    leader_qball2_mytest_DW.SigmoidPath_RWORK.Time = 0;

    /*  initialize the toggle flag to -1 so that it is toggled
       on the first trigger    */
    leader_qball2_mytest_DW.SigmoidPath_Toggle = -1;
  }

  /* Start for Enabled SubSystem: '<S123>/Enabled Subsystem1' */
  leader__EnabledSubsystem1_Start(&leader_qball2_mytest_B.EnabledSubsystem1_b,
    &leader_qball2_mytest_DW.EnabledSubsystem1_b,
    (P_EnabledSubsystem1_leader_qb_T *)
    &leader_qball2_mytest_P.EnabledSubsystem1_b);

  /* End of Start for SubSystem: '<S123>/Enabled Subsystem1' */

  /* Start for Enabled SubSystem: '<S16>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S19>/Out1' */
  leader_qball2_mytest_B.Constant_cd = leader_qball2_mytest_P.Out1_Y0;

  /* End of Start for SubSystem: '<S16>/Enabled Subsystem' */
  /* Start for Enabled SubSystem: '<S83>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S90>/Out1' */
  leader_qball2_mytest_B.Constant_cm = leader_qball2_mytest_P.Out1_Y0_g;

  /* End of Start for SubSystem: '<S83>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S101>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S108>/Out1' */
  leader_qball2_mytest_B.Constant_k = leader_qball2_mytest_P.Out1_Y0_l;

  /* End of Start for SubSystem: '<S101>/Enabled Subsystem' */
  /* Start for Enabled SubSystem: '<S20>/Enabled Subsystem' */
  leader_qball2_mytest_DW.EnabledSubsystem_MODE_h = false;

  /* End of Start for SubSystem: '<S20>/Enabled Subsystem' */

  /* InitializeConditions for Enabled SubSystem: '<S20>/Enabled Subsystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  leader_qball2_mytest_DW.DiscreteTimeIntegrator_DSTATE_a =
    leader_qball2_mytest_P.DiscreteTimeIntegrator_IC;

  /* End of InitializeConditions for SubSystem: '<S20>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S20>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S22>/timeout' */
  leader_qball2_mytest_B.RelationalOperator_m =
    leader_qball2_mytest_P.timeout_Y0;

  /* End of Start for SubSystem: '<S20>/Enabled Subsystem' */
  /* Start for TransportDelay: '<S7>/Transport Delay' */
  {
    real_T *pBuffer =
      &leader_qball2_mytest_DW.TransportDelay_RWORK.TUbufferArea[0];
    leader_qball2_mytest_DW.TransportDelay_IWORK.Tail = 0;
    leader_qball2_mytest_DW.TransportDelay_IWORK.Head = 0;
    leader_qball2_mytest_DW.TransportDelay_IWORK.Last = 0;
    leader_qball2_mytest_DW.TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = leader_qball2_mytest_P.TransportDelay_InitOutput;
    pBuffer[1024] = leader_qball2_mytest_M->Timing.t[0];
    leader_qball2_mytest_DW.TransportDelay_PWORK.TUbufferPtrs[0] = (void *)
      &pBuffer[0];
    leader_qball2_mytest_DW.TransportDelay_PWORK.TUbufferPtrs[1] = (void *)
      &pBuffer[1024];
  }

  /* Start for Constant: '<S89>/x0' */
  leader_qball2_mytest_B.x0_dh = leader_qball2_mytest_P.x0_Value_b;

  /* Start for Constant: '<S107>/x0' */
  leader_qball2_mytest_B.x0_i = leader_qball2_mytest_P.x0_Value_p;

  /* Start for S-Function (stream_server_block): '<S10>/Stream Server' */

  /* S-Function Block: leader_qball2_mytest/Serve Data For Follower/Stream Server (stream_server_block) */
  {
    qthread_attr_t send_thread_attributes;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    t_pstream_options options;
    t_error result;
    leader_qball2_mytest_DW.StreamServer_Stream = NULL;
    result = 0;
    options.size = sizeof(options);
    options.flags = leader_qball2_mytest_P.StreamServer_Endian &
      PSTREAM_FLAG_ENDIAN_MASK;
    if (leader_qball2_mytest_P.StreamServer_Implementation ==
        STREAM_SERVER_IMPLEMENTATION_THREAD) {
      options.flags |= PSTREAM_FLAG_MULTITHREADED;
    }

    if (leader_qball2_mytest_P.StreamServer_Optimize ==
        STREAM_SERVER_OPTIMIZE_LATENCY) {
      options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
    }

    options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
    options.send_unit_size = 8;
    options.num_send_units = 3;
    options.send_buffer_size = leader_qball2_mytest_P.StreamServer_SndSize;
    options.send_fifo_size = leader_qball2_mytest_P.StreamServer_SndFIFO;
    options.num_send_dimensions = 0;
    options.max_send_dimensions = NULL;
    if (leader_qball2_mytest_P.StreamServer_SndPriority < min_priority) {
      scheduling_parameters.sched_priority = min_priority;
    } else if (leader_qball2_mytest_P.StreamServer_SndPriority > max_priority) {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        leader_qball2_mytest_P.StreamServer_SndPriority;
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
          rtmSetErrorStatus(leader_qball2_mytest_M,
                            "Unable to set scheduling inheritance for Stream Client sending thread");
        }
      } else {
        rtmSetErrorStatus(leader_qball2_mytest_M,
                          "The specified thread priority for the Stream Client sending thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(leader_qball2_mytest_M,
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
      result = pstream_listen((const char *)
        leader_qball2_mytest_P.StreamServer_URI, &options,
        &leader_qball2_mytest_DW.StreamServer_Stream);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
      }
    }

    qthread_attr_destroy(&send_thread_attributes);
  }

  /* Start for Triggered SubSystem: '<S124>/Triggered Sigmoid Compute' */

  /* Start for S-Function (sigmoid_compute): '<S125>/Sigmoid Compute' */

  /* S-Function Block: leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Limit descent rate/Triggered Sigmoid/Triggered Sigmoid Compute/Sigmoid Compute (sigmoid_compute) */
  {
    leader_qball2_mytest_DW.SigmoidPath_Flag = 0;
  }

  /* End of Start for SubSystem: '<S124>/Triggered Sigmoid Compute' */

  /* Start for Enabled SubSystem: '<S130>/arm height command' */
  leader_qball2_mytest_DW.armheightcommand_MODE = false;

  /* VirtualOutportStart for Outport: '<S134>/Out1' */
  leader_qball2_mytest_B.In1 = leader_qball2_mytest_P.Out1_Y0_lz;

  /* End of Start for SubSystem: '<S130>/arm height command' */
  /* Start for Constant: '<S139>/x0' */
  leader_qball2_mytest_B.x0_g = leader_qball2_mytest_P.x0_Value_ch;
  leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  leader_qball2_mytest_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  leader_qball2_mytest_PrevZCX.Integrator1_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  leader_qball2_mytest_PrevZCX.TriggeredSigmoidCompute_Trig_ZC = POS_ZCSIG;
  leader_qball2_mytest_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput[0] =
    leader_qball2_mytest_P.Memory_X0[0];
  leader_qball2_mytest_DW.Memory_PreviousInput[1] =
    leader_qball2_mytest_P.Memory_X0[1];
  leader_qball2_mytest_DW.Memory_PreviousInput[2] =
    leader_qball2_mytest_P.Memory_X0[2];
  leader_qball2_mytest_DW.Memory_PreviousInput[3] =
    leader_qball2_mytest_P.Memory_X0[3];

  /* InitializeConditions for Memory: '<S62>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput_g =
    leader_qball2_mytest_P.Memory_X0_b;

  /* InitializeConditions for Integrator: '<S48>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE =
    leader_qball2_mytest_P.Integrator2_IC;

  /* InitializeConditions for MATLAB Function: '<S29>/Kalman Filter - Height' */
  leader_qball2_mytest_DW.P_00_b = 0.0;
  leader_qball2_mytest_DW.P_01_f = 0.0;
  leader_qball2_mytest_DW.P_10_j = 0.0;
  leader_qball2_mytest_DW.P_11_h = 0.0;
  leader_qball2_mytest_DW.x_height = 0.0;
  leader_qball2_mytest_DW.x_bias_h = 0.0;

  /* InitializeConditions for Memory: '<S28>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput_b =
    leader_qball2_mytest_P.Memory_X0_g;

  /* InitializeConditions for RateTransition: '<S55>/Rate Transition' */
  leader_qball2_mytest_DW.RateTransition_Buffer0 =
    leader_qball2_mytest_P.RateTransition_X0;

  /* InitializeConditions for Derivative: '<S55>/Derivative' */
  leader_qball2_mytest_DW.TimeStampA = (rtInf);
  leader_qball2_mytest_DW.TimeStampB = (rtInf);

  /* InitializeConditions for RateTransition: '<S54>/Rate Transition1' */
  leader_qball2_mytest_DW.RateTransition1_Buffer0 =
    leader_qball2_mytest_P.RateTransition1_X0;

  /* InitializeConditions for RateTransition: '<S54>/Rate Transition' */
  leader_qball2_mytest_DW.RateTransition_Buffer0_l =
    leader_qball2_mytest_P.RateTransition_X0_o;

  /* InitializeConditions for Integrator: '<S32>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE[0] = 0.0;
    leader_qball2_mytest_X.Integrator1_CSTATE[1] = 0.0;
    leader_qball2_mytest_X.Integrator1_CSTATE[2] = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for TransferFcn: '<S29>/High Pass Filter - Roll' */
  leader_qball2_mytest_X.HighPassFilterRoll_CSTATE = 0.0;

  /* InitializeConditions for MATLAB Function: '<S29>/Kalman Filter - Roll' */
  leader_qball2_mytest_DW.P_00_g = 0.0;
  leader_qball2_mytest_DW.P_01_h = 0.0;
  leader_qball2_mytest_DW.P_10_h = 0.0;
  leader_qball2_mytest_DW.P_11_n = 0.0;
  leader_qball2_mytest_DW.x_angle_g = 0.0;
  leader_qball2_mytest_DW.x_bias_e = 0.0;

  /* InitializeConditions for TransferFcn: '<S29>/High Pass Filter - Pitch' */
  leader_qball2_mytest_X.HighPassFilterPitch_CSTATE = 0.0;

  /* InitializeConditions for MATLAB Function: '<S29>/Kalman Filter - Pitch' */
  leader_qball2_mytest_DW.P_00_p = 0.0;
  leader_qball2_mytest_DW.P_01_c = 0.0;
  leader_qball2_mytest_DW.P_10_m = 0.0;
  leader_qball2_mytest_DW.P_11_a = 0.0;
  leader_qball2_mytest_DW.x_angle_h = 0.0;
  leader_qball2_mytest_DW.x_bias_l = 0.0;

  /* InitializeConditions for Integrator: '<S49>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE_j =
    leader_qball2_mytest_P.Integrator2_IC_m;

  /* InitializeConditions for Integrator: '<S50>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE_i =
    leader_qball2_mytest_P.Integrator2_IC_a;

  /* InitializeConditions for Integrator: '<S47>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE_l = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK_j.IcNeedsLoading = 1;

  /* InitializeConditions for TransferFcn: '<S29>/High Pass Filter - Yaw' */
  leader_qball2_mytest_X.HighPassFilterYaw_CSTATE = 0.0;

  /* InitializeConditions for MATLAB Function: '<S29>/Kalman Filter - Yaw' */
  leader_qball2_mytest_DW.P_00 = 0.0;
  leader_qball2_mytest_DW.P_01 = 0.0;
  leader_qball2_mytest_DW.P_10 = 0.0;
  leader_qball2_mytest_DW.P_11 = 0.0;
  leader_qball2_mytest_DW.x_angle = 0.0;
  leader_qball2_mytest_DW.x_bias = 0.0;

  /* InitializeConditions for Integrator: '<S47>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE_o =
    leader_qball2_mytest_P.Integrator2_IC_e;

  /* InitializeConditions for Integrator: '<S48>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE_a = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK_o.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S49>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE_ly = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK_l.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S50>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE_lyr = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK_ov.IcNeedsLoading = 1;

  /* InitializeConditions for UnitDelay: '<S54>/Unit Delay' */
  leader_qball2_mytest_DW.UnitDelay_DSTATE =
    leader_qball2_mytest_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for Integrator: '<S32>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE_i2[0] =
    leader_qball2_mytest_P.Integrator2_IC_k;
  leader_qball2_mytest_X.Integrator2_CSTATE_i2[1] =
    leader_qball2_mytest_P.Integrator2_IC_k;
  leader_qball2_mytest_X.Integrator2_CSTATE_i2[2] =
    leader_qball2_mytest_P.Integrator2_IC_k;

  /* InitializeConditions for TransferFcn: '<S23>/Transfer Fcn' */
  leader_qball2_mytest_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S14>/LPF' */
  leader_qball2_mytest_X.LPF_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S14>/Integrator' */
  leader_qball2_mytest_X.Integrator_CSTATE =
    leader_qball2_mytest_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S14>/HPF' */
  leader_qball2_mytest_X.HPF_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S15>/LPF1' */
  leader_qball2_mytest_X.LPF1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  leader_qball2_mytest_X.Integrator_CSTATE_g =
    leader_qball2_mytest_P.Integrator_IC_l;

  /* InitializeConditions for TransferFcn: '<S15>/HPF1' */
  leader_qball2_mytest_X.HPF1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S13>/Low Pass Filter (Filtered Yaw Rate)' */
  leader_qball2_mytest_X.LowPassFilterFilteredYawRate_CS = 0.0;

  /* InitializeConditions for RateLimiter: '<S7>/Rate Limiter' */
  leader_qball2_mytest_DW.PrevY = leader_qball2_mytest_P.RateLimiter_IC;

  /* InitializeConditions for Integrator: '<S139>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE_e =
    leader_qball2_mytest_P.Integrator2_IC_kr;

  /* InitializeConditions for RateLimiter: '<S7>/Rate Limiter3' */
  leader_qball2_mytest_DW.LastMajorTime = (rtInf);

  /* InitializeConditions for MATLAB Function: '<S116>/MATLAB Function' */
  leader_qball2_mytest_DW.state_h = 0.0;
  leader_qball2_mytest_DW.counter = 0.0;

  /* InitializeConditions for Memory: '<S138>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput_p =
    leader_qball2_mytest_P.Memory_X0_j;

  /* InitializeConditions for Integrator: '<S131>/Integrator' */
  leader_qball2_mytest_X.Integrator_CSTATE_ga =
    leader_qball2_mytest_P.Integrator_IC_f;

  /* InitializeConditions for MATLAB Function: '<S131>/User-controller landing state machine' */
  leader_qball2_mytest_DW.state = 0.0;
  leader_qball2_mytest_DW.c = 0.0;

  /* InitializeConditions for Derivative: '<S123>/Derivative' */
  leader_qball2_mytest_DW.TimeStampA_e = (rtInf);
  leader_qball2_mytest_DW.TimeStampB_c = (rtInf);

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  leader_qball2_mytest_X.Integrator_CSTATE_h =
    leader_qball2_mytest_P.Integrator_IC_p;

  /* InitializeConditions for TransferFcn: '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)' */
  leader_qball2_mytest_X.LowPassFilterFilteredYawRateFor = 0.0;

  /* InitializeConditions for TransferFcn: '<S81>/Low Pass Filter (Filtered Pitch Rate)' */
  leader_qball2_mytest_X.LowPassFilterFilteredPitchRate_ = 0.0;

  /* InitializeConditions for Memory: '<S85>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput_i =
    leader_qball2_mytest_P.Memory_X0_a;

  /* InitializeConditions for Integrator: '<S81>/Integrator1' */
  leader_qball2_mytest_X.Integrator1_CSTATE_g =
    leader_qball2_mytest_P.Integrator1_IC;

  /* InitializeConditions for TransferFcn: '<S97>/Low Pass Filter (Filtered Roll Rate)' */
  leader_qball2_mytest_X.LowPassFilterFilteredRollRate_C = 0.0;

  /* InitializeConditions for Memory: '<S103>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput_j =
    leader_qball2_mytest_P.Memory_X0_p;

  /* InitializeConditions for Integrator: '<S97>/Integrator1' */
  leader_qball2_mytest_X.Integrator1_CSTATE_n =
    leader_qball2_mytest_P.Integrator1_IC_g;

  /* InitializeConditions for Memory: '<S61>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput_it =
    leader_qball2_mytest_P.Memory_X0_h;

  /* InitializeConditions for Memory: '<S63>/Memory' */
  leader_qball2_mytest_DW.Memory_PreviousInput_m =
    leader_qball2_mytest_P.Memory_X0_m;

  /* InitializeConditions for Integrator: '<S89>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE_ir =
    leader_qball2_mytest_P.Integrator2_IC_b;

  /* InitializeConditions for RateLimiter: '<S7>/Rate Limiter2' */
  leader_qball2_mytest_DW.LastMajorTime_c = (rtInf);

  /* InitializeConditions for Integrator: '<S86>/Integrator' */
  leader_qball2_mytest_X.Integrator_CSTATE_k =
    leader_qball2_mytest_P.Integrator_IC_e;

  /* InitializeConditions for Integrator: '<S107>/Integrator2' */
  leader_qball2_mytest_X.Integrator2_CSTATE_a =
    leader_qball2_mytest_P.Integrator2_IC_h;

  /* InitializeConditions for RateLimiter: '<S7>/Rate Limiter1' */
  leader_qball2_mytest_DW.LastMajorTime_j = (rtInf);

  /* InitializeConditions for Integrator: '<S104>/Integrator1' */
  leader_qball2_mytest_X.Integrator1_CSTATE_nx =
    leader_qball2_mytest_P.Integrator1_IC_b;

  /* InitializeConditions for Integrator: '<S89>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE_c = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK_b.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S107>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE_e = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK_li.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S139>/Integrator1' */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    leader_qball2_mytest_X.Integrator1_CSTATE_d = 0.0;
  }

  leader_qball2_mytest_DW.Integrator1_IWORK_g.IcNeedsLoading = 1;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(leader_qball2_mytest_M)) {
    rtmSetFirstInitCond(leader_qball2_mytest_M, 0);
  }
}

/* Model terminate function */
void leader_qball2_mytest_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: leader_qball2_mytest/DAQ/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(leader_qball2_mytest_DW.HILInitialize_Card);
    hil_monitor_stop_all(leader_qball2_mytest_DW.HILInitialize_Card);
    is_switching = false;

    /* S-Function Block: leader_qball2_mytest/DAQ/HIL Watchdog (hil_watchdog_block) */
    {
      hil_watchdog_stop(leader_qball2_mytest_DW.HILInitialize_Card);
    }

    if ((leader_qball2_mytest_P.HILInitialize_set_digital_out_j && !is_switching)
        || (leader_qball2_mytest_P.HILInitialize_set_digital_out_p &&
            is_switching)) {
      num_final_digital_outputs = 2U;
    }

    if ((leader_qball2_mytest_P.HILInitialize_set_other_outpu_i && !is_switching)
        || (leader_qball2_mytest_P.HILInitialize_set_other_outpu_m &&
            is_switching)) {
      leader_qball2_mytest_DW.HILInitialize_OOValues[0] =
        leader_qball2_mytest_P.HILInitialize_final_other_outpu;
      leader_qball2_mytest_DW.HILInitialize_OOValues[1] =
        leader_qball2_mytest_P.HILInitialize_final_other_outpu;
      leader_qball2_mytest_DW.HILInitialize_OOValues[2] =
        leader_qball2_mytest_P.HILInitialize_final_other_outpu;
      leader_qball2_mytest_DW.HILInitialize_OOValues[3] =
        leader_qball2_mytest_P.HILInitialize_final_other_outpu;
      num_final_other_outputs = 4U;
    }

    if (0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(leader_qball2_mytest_DW.HILInitialize_Card
                         , NULL, 0
                         , NULL, 0
                         ,
                         leader_qball2_mytest_P.HILInitialize_digital_output_ch,
                         num_final_digital_outputs
                         ,
                         leader_qball2_mytest_P.HILInitialize_other_output_chan,
                         num_final_other_outputs
                         , NULL
                         , NULL
                         , (t_boolean *)
                         leader_qball2_mytest_P.HILInitialize_final_digital_out
                         , &leader_qball2_mytest_DW.HILInitialize_OOValues[0]
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (leader_qball2_mytest_DW.HILInitialize_Card,
             leader_qball2_mytest_P.HILInitialize_digital_output_ch,
             num_final_digital_outputs, (t_boolean *)
             leader_qball2_mytest_P.HILInitialize_final_digital_out);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (leader_qball2_mytest_DW.HILInitialize_Card,
             leader_qball2_mytest_P.HILInitialize_other_output_chan,
             num_final_other_outputs,
             &leader_qball2_mytest_DW.HILInitialize_OOValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(leader_qball2_mytest_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(leader_qball2_mytest_DW.HILInitialize_Card);
    hil_monitor_delete_all(leader_qball2_mytest_DW.HILInitialize_Card);
    hil_close(leader_qball2_mytest_DW.HILInitialize_Card);
    leader_qball2_mytest_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_client_block): '<S4>/Stream Client' */

  /* S-Function Block: leader_qball2_mytest/Data from host/Stream Client (stream_client_block) */
  {
    if (leader_qball2_mytest_DW.StreamClient_Stream != NULL) {
      pstream_close(leader_qball2_mytest_DW.StreamClient_Stream);
    }

    leader_qball2_mytest_DW.StreamClient_Stream = NULL;
  }

  /* Terminate for S-Function (stream_server_block): '<S10>/Stream Server' */

  /* S-Function Block: leader_qball2_mytest/Serve Data For Follower/Stream Server (stream_server_block) */
  {
    if (leader_qball2_mytest_DW.StreamServer_Stream != NULL) {
      pstream_close(leader_qball2_mytest_DW.StreamServer_Stream);
    }

    leader_qball2_mytest_DW.StreamServer_Stream = NULL;
  }
}
