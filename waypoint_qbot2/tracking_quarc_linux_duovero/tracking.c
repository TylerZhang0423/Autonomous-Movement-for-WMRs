/*
 * tracking.c
 *
 * Code generation for model "tracking".
 *
 * Model version              : 1.1094
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Apr 05 19:14:37 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "tracking.h"
#include "tracking_private.h"
#include "tracking_dt.h"

/* Block signals (auto storage) */
B_tracking_T tracking_B;

/* Continuous states */
X_tracking_T tracking_X;

/* Block states (auto storage) */
DW_tracking_T tracking_DW;

/* Real-time model */
RT_MODEL_tracking_T tracking_M_;
RT_MODEL_tracking_T *const tracking_M = &tracking_M_;

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
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  tracking_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void tracking_step(void)
{
  /* local block i/o variables */
  real_T rtb_Clock1;
  real_T rtb_Integrator1;
  real_T rtb_Integrator2;
  real_T rtb_Integrator2_b;
  real_T rtb_Integrator1_h;
  real_T rtb_HILRead1_o1;
  real_T rtb_HILRead1_o4;
  real_T rtb_HILRead1_o2[2];
  boolean_T rtb_HILRead1_o3[3];
  real_T h;
  real_T x0_1;
  real_T V1;
  real_T k1;
  real_T k0;
  real_T rtb_Product[3];
  real_T rtb_u1;
  real_T rtb_y[9];
  int32_T i;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* set solver stop time */
    if (!(tracking_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&tracking_M->solverInfo,
                            ((tracking_M->Timing.clockTickH0 + 1) *
        tracking_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&tracking_M->solverInfo,
                            ((tracking_M->Timing.clockTick0 + 1) *
        tracking_M->Timing.stepSize0 + tracking_M->Timing.clockTickH0 *
        tracking_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(tracking_M)) {
    tracking_M->Timing.t[0] = rtsiGetT(&tracking_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(tracking_M)) {
  }

  /* Clock: '<Root>/Clock1' */
  rtb_Clock1 = tracking_M->Timing.t[0];
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Constant: '<S4>/Constant2' */
    tracking_B.Constant2 = tracking_P.Constant2_Value;
  }

  /* Integrator: '<S4>/Integrator1' */
  if (tracking_DW.Integrator1_IWORK.IcNeedsLoading) {
    tracking_X.Integrator1_CSTATE = tracking_B.Constant2;
  }

  rtb_Integrator1 = tracking_X.Integrator1_CSTATE;

  /* MATLAB Function: '<S6>/e=T(q_r-q)' */
  /* MATLAB Function 'Subsystem1/e=T(q_r-q)': '<S18>:1' */
  /*  transform posture errors from global coordinates to loacl coordinates */
  /* '<S18>:1:3' */
  rtb_y[0] = cos(rtb_Integrator1);
  rtb_y[3] = sin(rtb_Integrator1);
  rtb_y[6] = 0.0;
  rtb_y[1] = -sin(rtb_Integrator1);
  rtb_y[4] = cos(rtb_Integrator1);
  rtb_y[7] = 0.0;
  rtb_y[2] = 0.0;
  rtb_y[5] = 0.0;
  rtb_y[8] = 1.0;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Constant: '<S4>/Constant1' */
    tracking_B.Constant1 = tracking_P.Constant1_Value;
  }

  /* Integrator: '<S4>/Integrator2' */
  if (tracking_DW.Integrator2_IWORK.IcNeedsLoading) {
    tracking_X.Integrator2_CSTATE = tracking_B.Constant1;
  }

  rtb_Integrator2 = tracking_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Constant: '<S4>/Constant9' */
    tracking_B.Constant9 = tracking_P.Constant9_Value;
  }

  /* Integrator: '<S4>/Integrator3' */
  if (tracking_DW.Integrator3_IWORK.IcNeedsLoading) {
    tracking_X.Integrator3_CSTATE = tracking_B.Constant9;
  }

  rtb_Integrator2_b = tracking_X.Integrator3_CSTATE;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Constant: '<S5>/Constant1' */
    tracking_B.Constant1_a = tracking_P.Constant1_Value_n;
  }

  /* Integrator: '<S5>/Integrator2' */
  if (tracking_DW.Integrator2_IWORK_g.IcNeedsLoading) {
    tracking_X.Integrator2_CSTATE_f = tracking_B.Constant1_a;
  }

  tracking_B.Integrator2 = tracking_X.Integrator2_CSTATE_f;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Constant: '<S5>/Constant9' */
    tracking_B.Constant9_m = tracking_P.Constant9_Value_e;
  }

  /* Integrator: '<S5>/Integrator3' */
  if (tracking_DW.Integrator3_IWORK_a.IcNeedsLoading) {
    tracking_X.Integrator3_CSTATE_d = tracking_B.Constant9_m;
  }

  tracking_B.Integrator3 = tracking_X.Integrator3_CSTATE_d;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Constant: '<S5>/Constant2' */
    tracking_B.Constant2_a = tracking_P.Constant2_Value_i;
  }

  /* Integrator: '<S5>/Integrator1' */
  if (tracking_DW.Integrator1_IWORK_j.IcNeedsLoading) {
    tracking_X.Integrator1_CSTATE_c = tracking_B.Constant2_a;
  }

  tracking_B.Integrator1 = tracking_X.Integrator1_CSTATE_c;

  /* Sum: '<S6>/Add' */
  k0 = tracking_B.Integrator2 - rtb_Integrator2;
  rtb_u1 = tracking_B.Integrator3 - rtb_Integrator2_b;
  h = tracking_B.Integrator1 - rtb_Integrator1;

  /* Product: '<S6>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_Product[i] = rtb_y[i + 6] * h + (rtb_y[i + 3] * rtb_u1 + rtb_y[i] * k0);
  }

  /* End of Product: '<S6>/Product' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S3>:1' */
  /* '<S3>:1:3' */
  tracking_B.u_1r = 0.3;

  /* '<S3>:1:4' */
  /*  */
  /*      n = 1.1; c = 0.15; */
  /*      x_dot = (3*c*cos(3*c*t)*cos(c*t)-c*sin(3*c*t)*sin(c*t))*n; */
  /*      x_sec_dot = (-9*c^2*sin(3*c*t)*cos(c*t)-3*c^2*cos(3*c*t)*sin(c*t)... */
  /*          -3*c^2*cos(3*c*t)*sin(c*t)-c^2*sin(3*c*t)*cos(c*t))*n; */
  /*      y_dot = (3*c*cos(3*c*t)*sin(c*t)+c*sin(3*c*t)*cos(c*t))*n; */
  /*      y_sec_dot = (-9*c^2*sin(3*c*t)*sin(c*t)+3*c^2*cos(3*c*t)*cos(c*t)... */
  /*          +3*c^2*cos(3*c*t)*cos(c*t)-c^2*sin(3*c*t)*sin(c*t))*n; */
  /*      u_1r = (x_dot^2+y_dot^2)^0.5; */
  /*      %u_1r_dot = (x_dot*x_sec_dot+y_dot*y_sec_dot)/u_1r; */
  /*      u_2r = (y_sec_dot*x_dot-x_sec_dot*y_dot)/(u_1r^2); */
  /*   */
  /* epsilong1 */
  /* epsilong0x0 */
  /* k0lamda0-1time-varying parameter k1 */
  /* miutime-varying k1 */
  /* x0x0t */
  /* gamascalargama */
  /* '<S3>:1:28' */
  /*  */
  /*   */
  /* '<S3>:1:34' */
  h = 0.9 * cos(rtb_Clock1) + 1.0;

  /* '<S3>:1:35' */
  /* '<S3>:1:37' */
  /* '<S3>:1:38' */
  /* '<S3>:1:39' */
  /* '<S3>:1:40' */
  x0_1 = 0.01 * h * rtb_Product[1] / (sqrt(rtb_Product[1] * rtb_Product[1] +
    -rtb_Product[0] * -rtb_Product[0]) + 1.0) + rtb_Product[2];

  /* ----------------------------------(u1,u2)-------------------- */
  /* '<S3>:1:43' */
  V1 = sqrt(rtb_Product[1] * rtb_Product[1] + -rtb_Product[0] * -rtb_Product[0]);

  /* '<S3>:1:44' */
  k1 = 0.75 / sqrt(x0_1 * x0_1 + 0.0025000000000000005);

  /* '<S3>:1:45' */
  if (-rtb_Product[0] < 0.0) {
    k0 = -1.0;
  } else if (-rtb_Product[0] > 0.0) {
    k0 = 1.0;
  } else if (-rtb_Product[0] == 0.0) {
    k0 = 0.0;
  } else {
    k0 = -rtb_Product[0];
  }

  k0 = ((0.7 - fabs(k1 * x0_1 + 0.3) * 0.17) + 0.3 * cos(rtb_Product[2]) * k0) *
    (tanh(2.0 * fabs(-rtb_Product[0])) / (2.0 * fabs(-rtb_Product[0])));

  /* '<S3>:1:48' */
  /* '<S3>:1:49' */
  /* '<S3>:1:52' */
  rtb_u1 = 0.3 * cos(rtb_Product[2]) - k0 * -rtb_Product[0];

  /* '<S3>:1:53' */
  h = (((((0.3 * -rtb_Product[0] + 0.3 * sin(rtb_Product[2])) * h + -0.9 * sin
          (rtb_Clock1) * rtb_Product[1]) + sqrt(V1)) - (-rtb_Product[0] *
         -rtb_Product[0] * -k0 + 0.3 * rtb_Product[1] * sin(rtb_Product[2])) *
        (h * rtb_Product[1]) / 2.0 * ((1.0 + V1) * (1.0 + V1)) * V1) * 0.01 /
       (1.0 - 0.01 * h * -rtb_Product[0] / (1.0 + V1)) + 0.3) + k1 * x0_1;
  tracking_B.u_2r = 0.3;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLAB Function: '<Root>/vR to vC2' */
  /* MATLAB Function 'vR to vC2': '<S7>:1' */
  /* '<S7>:1:6' */
  tracking_B.vL = rtb_u1 - h * 0.34 / 2.0;

  /* '<S7>:1:7' */
  tracking_B.vR = h * 0.34 / 2.0 + rtb_u1;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* S-Function (hil_write_block): '<Root>/HIL Write' */

    /* S-Function Block: tracking/HIL Write (hil_write_block) */
    {
      t_error result;
      tracking_DW.HILWrite_OtherBuffer[0] = tracking_B.vR;
      tracking_DW.HILWrite_OtherBuffer[1] = tracking_B.vL;
      result = hil_write(tracking_DW.HILInitialize_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         tracking_P.HILWrite_other_channels, 2U,
                         NULL,
                         NULL,
                         NULL,
                         &tracking_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
      }
    }
  }

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' */
  tracking_B.VectorConcatenate[0] = rtb_Clock1;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn2' */
  tracking_B.VectorConcatenate[1] = rtb_Product[0];
  tracking_B.VectorConcatenate[2] = rtb_Product[1];
  tracking_B.VectorConcatenate[3] = rtb_Product[2];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn3' */
  tracking_B.VectorConcatenate[4] = rtb_Integrator2;
  tracking_B.VectorConcatenate[5] = rtb_Integrator2_b;
  tracking_B.VectorConcatenate[6] = rtb_Integrator1;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn4' */
  tracking_B.VectorConcatenate[7] = tracking_B.Integrator2;
  tracking_B.VectorConcatenate[8] = tracking_B.Integrator3;
  tracking_B.VectorConcatenate[9] = tracking_B.Integrator1;

  /* Integrator: '<S11>/Integrator2' */
  rtb_Integrator2_b = tracking_X.Integrator2_CSTATE_b;

  /* Product: '<S11>/Product1' incorporates:
   *  Constant: '<S11>/wn'
   */
  tracking_B.Product1 = tracking_P.SecondOrderLowPassFilter2_input *
    rtb_Integrator2_b;

  /* Integrator: '<S9>/Integrator2' */
  rtb_Integrator2 = tracking_X.Integrator2_CSTATE_fg;

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<S9>/wn'
   */
  tracking_B.Product1_a = tracking_P.SecondOrderLowPassFilter2_inp_p *
    rtb_Integrator2;

  /* MATLAB Function: '<S12>/Qbot2_Diff_Drive_Kinematics' */
  /* MATLAB Function 'Qbot2_Full_Kinematics/Qbot2_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics': '<S14>:1' */
  /* '<S14>:1:6' */
  tracking_B.vC = (tracking_B.Product1 + tracking_B.Product1_a) * 0.5;

  /* '<S14>:1:7' */
  tracking_B.Omega = (tracking_B.Product1_a - tracking_B.Product1) *
    2.9411764705882351;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn5' */
  tracking_B.VectorConcatenate[10] = tracking_B.vC;
  tracking_B.VectorConcatenate[11] = tracking_B.Omega;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn6' */
  tracking_B.VectorConcatenate[12] = tracking_B.u_1r;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn7' */
  tracking_B.VectorConcatenate[13] = tracking_B.u_2r;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn8' */
  tracking_B.VectorConcatenate[14] = 0.0;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* S-Function (hil_read_block): '<Root>/HIL Read1' */

    /* S-Function Block: tracking/HIL Read1 (hil_read_block) */
    {
      t_error result = hil_read(tracking_DW.HILInitialize_Card,
        &tracking_P.HILRead1_analog_channels, 1U,
        tracking_P.HILRead1_encoder_channels, 2U,
        tracking_P.HILRead1_digital_channels, 3U,
        &tracking_P.HILRead1_other_channels, 1U,
        &rtb_HILRead1_o1,
        &tracking_DW.HILRead1_EncoderBuffer[0],
                                (t_boolean *)&rtb_HILRead1_o3[0],
        &rtb_HILRead1_o4
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
      } else {
        rtb_HILRead1_o2[0] = tracking_DW.HILRead1_EncoderBuffer[0];
        rtb_HILRead1_o2[1] = tracking_DW.HILRead1_EncoderBuffer[1];
      }
    }

    /* Gain: '<S8>/mm to m' incorporates:
     *  Gain: '<S8>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S8>/ticks to encoder rotation'
     *  Gain: '<S8>/wheel radious (mm)'
     */
    tracking_B.mmtom = tracking_P.tickstoencoderrotation_Gain * rtb_HILRead1_o2
      [0] * tracking_P.encoderrotationtowheelrotationg *
      tracking_P.wheelradiousmm_Gain * tracking_P.mmtom_Gain;

    /* Constant: '<S9>/x0' */
    tracking_B.x0 = tracking_P.x0_Value;
  }

  /* Integrator: '<S9>/Integrator1' */
  if (tracking_DW.Integrator1_IWORK_d.IcNeedsLoading) {
    tracking_X.Integrator1_CSTATE_j = tracking_B.x0;
  }

  rtb_Integrator1_h = tracking_X.Integrator1_CSTATE_j;

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/wn'
   *  Constant: '<S9>/zt'
   *  Product: '<S9>/Product2'
   *  Sum: '<S9>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  tracking_B.Product = ((tracking_B.mmtom - rtb_Integrator1_h) - rtb_Integrator2
                        * tracking_P.Constant_Value *
                        tracking_P.SecondOrderLowPassFilter2_inp_l) *
    tracking_P.SecondOrderLowPassFilter2_inp_p;
  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Gain: '<S10>/mm to m' incorporates:
     *  Gain: '<S10>/ encoder rotation to wheel rotation (gear ratio)'
     *  Gain: '<S10>/ticks to encoder rotation'
     *  Gain: '<S10>/wheel radious (mm)'
     */
    tracking_B.mmtom_o = tracking_P.tickstoencoderrotation_Gain_i *
      rtb_HILRead1_o2[1] * tracking_P.encoderrotationtowheelrotatio_n *
      tracking_P.wheelradiousmm_Gain_k * tracking_P.mmtom_Gain_h;

    /* Constant: '<S11>/x0' */
    tracking_B.x0_j = tracking_P.x0_Value_k;
  }

  /* Integrator: '<S11>/Integrator1' */
  if (tracking_DW.Integrator1_IWORK_p.IcNeedsLoading) {
    tracking_X.Integrator1_CSTATE_ch = tracking_B.x0_j;
  }

  rtb_Integrator1_h = tracking_X.Integrator1_CSTATE_ch;

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/wn'
   *  Constant: '<S11>/zt'
   *  Product: '<S11>/Product2'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S11>/Sum1'
   */
  tracking_B.Product_f = ((tracking_B.mmtom_o - rtb_Integrator1_h) -
    rtb_Integrator2_b * tracking_P.Constant_Value_m *
    tracking_P.SecondOrderLowPassFilter2_inp_k) *
    tracking_P.SecondOrderLowPassFilter2_input;

  /* MATLAB Function: '<S13>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' incorporates:
   *  Integrator: '<S13>/Integrator'
   */
  /* MATLAB Function 'Qbot2_Full_Kinematics/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)': '<S15>:1' */
  /* '<S15>:1:5' */
  tracking_B.x_dot_e = cos(tracking_X.Integrator_CSTATE) * tracking_B.vC;

  /* '<S15>:1:6' */
  tracking_B.y_dot_i = sin(tracking_X.Integrator_CSTATE) * tracking_B.vC;

  /* '<S15>:1:7' */
  tracking_B.psi_dot_n = tracking_B.Omega;

  /* MATLAB Function: '<S16>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' incorporates:
   *  Integrator: '<S16>/Integrator'
   */
  /* MATLAB Function 'Subsystem/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)': '<S17>:1' */
  /*  vC=0; */
  /*  Omega=0; */
  /* '<S17>:1:6' */
  tracking_B.x_dot = cos(tracking_X.Integrator_CSTATE_l) * tracking_B.u_1r;

  /* '<S17>:1:7' */
  tracking_B.y_dot = sin(tracking_X.Integrator_CSTATE_l) * tracking_B.u_1r;

  /* '<S17>:1:8' */
  tracking_B.psi_dot = tracking_B.u_2r;
  if (rtmIsMajorTimeStep(tracking_M)) {
  }

  if (rtmIsMajorTimeStep(tracking_M)) {
    /* Update for Integrator: '<S4>/Integrator1' */
    tracking_DW.Integrator1_IWORK.IcNeedsLoading = 0;

    /* Update for Integrator: '<S4>/Integrator2' */
    tracking_DW.Integrator2_IWORK.IcNeedsLoading = 0;

    /* Update for Integrator: '<S4>/Integrator3' */
    tracking_DW.Integrator3_IWORK.IcNeedsLoading = 0;

    /* Update for Integrator: '<S5>/Integrator2' */
    tracking_DW.Integrator2_IWORK_g.IcNeedsLoading = 0;

    /* Update for Integrator: '<S5>/Integrator3' */
    tracking_DW.Integrator3_IWORK_a.IcNeedsLoading = 0;

    /* Update for Integrator: '<S5>/Integrator1' */
    tracking_DW.Integrator1_IWORK_j.IcNeedsLoading = 0;

    /* Update for Integrator: '<S9>/Integrator1' */
    tracking_DW.Integrator1_IWORK_d.IcNeedsLoading = 0;

    /* Update for Integrator: '<S11>/Integrator1' */
    tracking_DW.Integrator1_IWORK_p.IcNeedsLoading = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, tracking_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(tracking_M)) {/* Sample time: [0.01s, 0.0s] */
      rtExtModeUpload(1, (((tracking_M->Timing.clockTick1+
                            tracking_M->Timing.clockTickH1* 4294967296.0)) *
                          0.01));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(tracking_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(tracking_M)!=-1) &&
          !((rtmGetTFinal(tracking_M)-(((tracking_M->Timing.clockTick1+
               tracking_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((tracking_M->Timing.clockTick1+tracking_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(tracking_M, "Simulation finished");
      }

      if (rtmGetStopRequested(tracking_M)) {
        rtmSetErrorStatus(tracking_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&tracking_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++tracking_M->Timing.clockTick0)) {
      ++tracking_M->Timing.clockTickH0;
    }

    tracking_M->Timing.t[0] = rtsiGetSolverStopTime(&tracking_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      tracking_M->Timing.clockTick1++;
      if (!tracking_M->Timing.clockTick1) {
        tracking_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void tracking_derivatives(void)
{
  XDot_tracking_T *_rtXdot;
  _rtXdot = ((XDot_tracking_T *) tracking_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator1_CSTATE =
      tracking_B.psi_dot_n;
  }

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator2_CSTATE =
      tracking_B.x_dot_e;
  }

  /* Derivatives for Integrator: '<S4>/Integrator3' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator3_CSTATE =
      tracking_B.y_dot_i;
  }

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator2_CSTATE_f =
      tracking_B.x_dot;
  }

  /* Derivatives for Integrator: '<S5>/Integrator3' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator3_CSTATE_d =
      tracking_B.y_dot;
  }

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator1_CSTATE_c =
      tracking_B.psi_dot;
  }

  /* Derivatives for Integrator: '<S11>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_b = tracking_B.Product_f;

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_fg = tracking_B.Product;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator1_CSTATE_j =
      tracking_B.Product1_a;
  }

  /* Derivatives for Integrator: '<S11>/Integrator1' */
  {
    ((XDot_tracking_T *) tracking_M->ModelData.derivs)->Integrator1_CSTATE_ch =
      tracking_B.Product1;
  }

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE = tracking_B.Omega;

  /* Derivatives for Integrator: '<S16>/Integrator' */
  _rtXdot->Integrator_CSTATE_l = tracking_B.u_2r;
}

/* Model initialize function */
void tracking_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)tracking_M, 0,
                sizeof(RT_MODEL_tracking_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&tracking_M->solverInfo,
                          &tracking_M->Timing.simTimeStep);
    rtsiSetTPtr(&tracking_M->solverInfo, &rtmGetTPtr(tracking_M));
    rtsiSetStepSizePtr(&tracking_M->solverInfo, &tracking_M->Timing.stepSize0);
    rtsiSetdXPtr(&tracking_M->solverInfo, &tracking_M->ModelData.derivs);
    rtsiSetContStatesPtr(&tracking_M->solverInfo, (real_T **)
                         &tracking_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&tracking_M->solverInfo,
      &tracking_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&tracking_M->solverInfo, (&rtmGetErrorStatus
      (tracking_M)));
    rtsiSetRTModelPtr(&tracking_M->solverInfo, tracking_M);
  }

  rtsiSetSimTimeStep(&tracking_M->solverInfo, MAJOR_TIME_STEP);
  tracking_M->ModelData.intgData.f[0] = tracking_M->ModelData.odeF[0];
  tracking_M->ModelData.contStates = ((X_tracking_T *) &tracking_X);
  rtsiSetSolverData(&tracking_M->solverInfo, (void *)
                    &tracking_M->ModelData.intgData);
  rtsiSetSolverName(&tracking_M->solverInfo,"ode1");
  rtmSetTPtr(tracking_M, &tracking_M->Timing.tArray[0]);
  rtmSetTFinal(tracking_M, 99.0);
  tracking_M->Timing.stepSize0 = 0.01;
  rtmSetFirstInitCond(tracking_M, 1);

  /* External mode info */
  tracking_M->Sizes.checksums[0] = (3950585350U);
  tracking_M->Sizes.checksums[1] = (1257311778U);
  tracking_M->Sizes.checksums[2] = (3748661183U);
  tracking_M->Sizes.checksums[3] = (1862469195U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    tracking_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(tracking_M->extModeInfo,
      &tracking_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(tracking_M->extModeInfo, tracking_M->Sizes.checksums);
    rteiSetTPtr(tracking_M->extModeInfo, rtmGetTPtr(tracking_M));
  }

  /* block I/O */
  {
    int_T i;
    for (i = 0; i < 15; i++) {
      tracking_B.VectorConcatenate[i] = 0.0;
    }

    tracking_B.Constant2 = 0.0;
    tracking_B.Constant1 = 0.0;
    tracking_B.Constant9 = 0.0;
    tracking_B.Constant1_a = 0.0;
    tracking_B.Integrator2 = 0.0;
    tracking_B.Constant9_m = 0.0;
    tracking_B.Integrator3 = 0.0;
    tracking_B.Constant2_a = 0.0;
    tracking_B.Integrator1 = 0.0;
    tracking_B.Product1 = 0.0;
    tracking_B.Product1_a = 0.0;
    tracking_B.mmtom = 0.0;
    tracking_B.x0 = 0.0;
    tracking_B.Product = 0.0;
    tracking_B.mmtom_o = 0.0;
    tracking_B.x0_j = 0.0;
    tracking_B.Product_f = 0.0;
    tracking_B.vL = 0.0;
    tracking_B.vR = 0.0;
    tracking_B.x_dot = 0.0;
    tracking_B.y_dot = 0.0;
    tracking_B.psi_dot = 0.0;
    tracking_B.x_dot_e = 0.0;
    tracking_B.y_dot_i = 0.0;
    tracking_B.psi_dot_n = 0.0;
    tracking_B.vC = 0.0;
    tracking_B.Omega = 0.0;
    tracking_B.u_1r = 0.0;
    tracking_B.u_2r = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&tracking_X, 0,
                  sizeof(X_tracking_T));
  }

  /* states (dwork) */
  (void) memset((void *)&tracking_DW, 0,
                sizeof(DW_tracking_T));

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      tracking_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      tracking_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  tracking_DW.HILInitialize_FilterFrequency[0] = 0.0;
  tracking_DW.HILInitialize_FilterFrequency[1] = 0.0;
  tracking_DW.HILInitialize_FilterFrequency[2] = 0.0;
  tracking_DW.HILInitialize_FilterFrequency[3] = 0.0;
  tracking_DW.HILInitialize_POSortedFreqs[0] = 0.0;
  tracking_DW.HILInitialize_POSortedFreqs[1] = 0.0;
  tracking_DW.HILInitialize_POSortedFreqs[2] = 0.0;
  tracking_DW.HILInitialize_POSortedFreqs[3] = 0.0;
  tracking_DW.HILInitialize_POValues[0] = 0.0;
  tracking_DW.HILInitialize_POValues[1] = 0.0;
  tracking_DW.HILInitialize_POValues[2] = 0.0;
  tracking_DW.HILInitialize_POValues[3] = 0.0;
  tracking_DW.HILInitialize_OOValues[0] = 0.0;
  tracking_DW.HILInitialize_OOValues[1] = 0.0;
  tracking_DW.HILWrite_OtherBuffer[0] = 0.0;
  tracking_DW.HILWrite_OtherBuffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    tracking_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: tracking/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qbot2", "0", &tracking_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(tracking_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(tracking_DW.HILInitialize_Card,
      "enc0_dir=0;enc0_filter=1;enc0_a=0;enc0_b=0;enc0_z=1;enc0_reload=0;enc1_dir=0;enc1_filter=1;enc1_a=0;enc1_b=0;enc1_z=1;enc1_reload=0;pwm0_immediate=0;pwm1_immediate=0;pwm2_immediate=0;pwm3_immediate=0;",
      201);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(tracking_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(tracking_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(tracking_M, _rt_error_message);
      return;
    }

    if ((tracking_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (tracking_P.HILInitialize_set_analog_inpu_a && is_switching)) {
      {
        int_T i1;
        const real_T *p_HILInitialize_analog_input_mini =
          tracking_P.HILInitialize_analog_input_mini;
        real_T *dw_AIMinimums = &tracking_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = p_HILInitialize_analog_input_mini[i1];
        }
      }

      tracking_DW.HILInitialize_AIMinimums[8] =
        tracking_P.HILInitialize_analog_input_mini[8];
      tracking_DW.HILInitialize_AIMinimums[9] =
        tracking_P.HILInitialize_analog_input_mini[8];

      {
        int_T i1;
        const real_T *p_HILInitialize_analog_input_maxi =
          tracking_P.HILInitialize_analog_input_maxi;
        real_T *dw_AIMaximums = &tracking_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = p_HILInitialize_analog_input_maxi[i1];
        }
      }

      tracking_DW.HILInitialize_AIMaximums[8] =
        tracking_P.HILInitialize_analog_input_maxi[8];
      tracking_DW.HILInitialize_AIMaximums[9] =
        tracking_P.HILInitialize_analog_input_maxi[8];
      result = hil_set_analog_input_ranges(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_analog_input_chan, 10U,
        &tracking_DW.HILInitialize_AIMinimums[0],
        &tracking_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }
    }

    if ((tracking_P.HILInitialize_set_encoder_param && !is_switching) ||
        (tracking_P.HILInitialize_set_encoder_par_a && is_switching)) {
      tracking_DW.HILInitialize_QuadratureModes[0] =
        tracking_P.HILInitialize_quadrature;
      tracking_DW.HILInitialize_QuadratureModes[1] =
        tracking_P.HILInitialize_quadrature;
      tracking_DW.HILInitialize_QuadratureModes[2] =
        tracking_P.HILInitialize_quadrature;
      tracking_DW.HILInitialize_QuadratureModes[3] =
        tracking_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_encoder_channels, 4U,
        (t_encoder_quadrature_mode *)
        &tracking_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }
    }

    if ((tracking_P.HILInitialize_set_encoder_count && !is_switching) ||
        (tracking_P.HILInitialize_set_encoder_cou_m && is_switching)) {
      tracking_DW.HILInitialize_InitialEICounts[0] =
        tracking_P.HILInitialize_initial_encoder_c;
      tracking_DW.HILInitialize_InitialEICounts[1] =
        tracking_P.HILInitialize_initial_encoder_c;
      tracking_DW.HILInitialize_InitialEICounts[2] =
        tracking_P.HILInitialize_initial_encoder_c;
      tracking_DW.HILInitialize_InitialEICounts[3] =
        tracking_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_encoder_channels, 4U,
        &tracking_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }
    }

    if ((tracking_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (tracking_P.HILInitialize_set_pwm_params__e && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_pwm_channels, 4U, (t_pwm_mode *)
        tracking_P.HILInitialize_pwm_modes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }

      if (tracking_P.HILInitialize_pwm_modes[0] == PWM_DUTY_CYCLE_MODE ||
          tracking_P.HILInitialize_pwm_modes[0] == PWM_ONE_SHOT_MODE ||
          tracking_P.HILInitialize_pwm_modes[0] == PWM_TIME_MODE) {
        tracking_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_channels[0];
        tracking_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_frequency[0];
        num_duty_cycle_modes++;
      } else {
        tracking_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_channels[0];
        tracking_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_frequency[0];
        num_frequency_modes++;
      }

      if (tracking_P.HILInitialize_pwm_modes[1] == PWM_DUTY_CYCLE_MODE ||
          tracking_P.HILInitialize_pwm_modes[1] == PWM_ONE_SHOT_MODE ||
          tracking_P.HILInitialize_pwm_modes[1] == PWM_TIME_MODE) {
        tracking_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_channels[1];
        tracking_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_frequency[1];
        num_duty_cycle_modes++;
      } else {
        tracking_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_channels[1];
        tracking_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_frequency[1];
        num_frequency_modes++;
      }

      if (tracking_P.HILInitialize_pwm_modes[2] == PWM_DUTY_CYCLE_MODE ||
          tracking_P.HILInitialize_pwm_modes[2] == PWM_ONE_SHOT_MODE ||
          tracking_P.HILInitialize_pwm_modes[2] == PWM_TIME_MODE) {
        tracking_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_channels[2];
        tracking_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_frequency[2];
        num_duty_cycle_modes++;
      } else {
        tracking_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_channels[2];
        tracking_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_frequency[2];
        num_frequency_modes++;
      }

      if (tracking_P.HILInitialize_pwm_modes[3] == PWM_DUTY_CYCLE_MODE ||
          tracking_P.HILInitialize_pwm_modes[3] == PWM_ONE_SHOT_MODE ||
          tracking_P.HILInitialize_pwm_modes[3] == PWM_TIME_MODE) {
        tracking_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_channels[3];
        tracking_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
          tracking_P.HILInitialize_pwm_frequency[3];
        num_duty_cycle_modes++;
      } else {
        tracking_DW.HILInitialize_POSortedChans[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_channels[3];
        tracking_DW.HILInitialize_POSortedFreqs[3U - num_frequency_modes] =
          tracking_P.HILInitialize_pwm_frequency[3];
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(tracking_DW.HILInitialize_Card,
          &tracking_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &tracking_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(tracking_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(tracking_DW.HILInitialize_Card,
          &tracking_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &tracking_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(tracking_M, _rt_error_message);
          return;
        }
      }

      tracking_DW.HILInitialize_POModeValues[0] =
        tracking_P.HILInitialize_pwm_configuration;
      tracking_DW.HILInitialize_POModeValues[1] =
        tracking_P.HILInitialize_pwm_configuration;
      tracking_DW.HILInitialize_POModeValues[2] =
        tracking_P.HILInitialize_pwm_configuration;
      tracking_DW.HILInitialize_POModeValues[3] =
        tracking_P.HILInitialize_pwm_configuration;
      tracking_DW.HILInitialize_POAlignValues[0] =
        tracking_P.HILInitialize_pwm_alignment;
      tracking_DW.HILInitialize_POAlignValues[1] =
        tracking_P.HILInitialize_pwm_alignment;
      tracking_DW.HILInitialize_POAlignValues[2] =
        tracking_P.HILInitialize_pwm_alignment;
      tracking_DW.HILInitialize_POAlignValues[3] =
        tracking_P.HILInitialize_pwm_alignment;
      tracking_DW.HILInitialize_POPolarityVals[0] =
        tracking_P.HILInitialize_pwm_polarity;
      tracking_DW.HILInitialize_POPolarityVals[1] =
        tracking_P.HILInitialize_pwm_polarity;
      tracking_DW.HILInitialize_POPolarityVals[2] =
        tracking_P.HILInitialize_pwm_polarity;
      tracking_DW.HILInitialize_POPolarityVals[3] =
        tracking_P.HILInitialize_pwm_polarity;
      result = hil_set_pwm_configuration(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_pwm_channels, 4U,
        (t_pwm_configuration *) &tracking_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &tracking_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &tracking_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }

      tracking_DW.HILInitialize_POSortedFreqs[0] =
        tracking_P.HILInitialize_pwm_leading_deadb;
      tracking_DW.HILInitialize_POSortedFreqs[1] =
        tracking_P.HILInitialize_pwm_leading_deadb;
      tracking_DW.HILInitialize_POSortedFreqs[2] =
        tracking_P.HILInitialize_pwm_leading_deadb;
      tracking_DW.HILInitialize_POSortedFreqs[3] =
        tracking_P.HILInitialize_pwm_leading_deadb;
      tracking_DW.HILInitialize_POValues[0] =
        tracking_P.HILInitialize_pwm_trailing_dead;
      tracking_DW.HILInitialize_POValues[1] =
        tracking_P.HILInitialize_pwm_trailing_dead;
      tracking_DW.HILInitialize_POValues[2] =
        tracking_P.HILInitialize_pwm_trailing_dead;
      tracking_DW.HILInitialize_POValues[3] =
        tracking_P.HILInitialize_pwm_trailing_dead;
      result = hil_set_pwm_deadband(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_pwm_channels, 4U,
        &tracking_DW.HILInitialize_POSortedFreqs[0],
        &tracking_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }
    }

    if ((tracking_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (tracking_P.HILInitialize_set_pwm_outputs_j && is_switching)) {
      tracking_DW.HILInitialize_POValues[0] =
        tracking_P.HILInitialize_initial_pwm_outpu;
      tracking_DW.HILInitialize_POValues[1] =
        tracking_P.HILInitialize_initial_pwm_outpu;
      tracking_DW.HILInitialize_POValues[2] =
        tracking_P.HILInitialize_initial_pwm_outpu;
      tracking_DW.HILInitialize_POValues[3] =
        tracking_P.HILInitialize_initial_pwm_outpu;
      result = hil_write_pwm(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_pwm_channels, 4U,
        &tracking_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }
    }

    if (tracking_P.HILInitialize_set_pwm_outputs_o) {
      tracking_DW.HILInitialize_POValues[0] =
        tracking_P.HILInitialize_watchdog_pwm_outp;
      tracking_DW.HILInitialize_POValues[1] =
        tracking_P.HILInitialize_watchdog_pwm_outp;
      tracking_DW.HILInitialize_POValues[2] =
        tracking_P.HILInitialize_watchdog_pwm_outp;
      tracking_DW.HILInitialize_POValues[3] =
        tracking_P.HILInitialize_watchdog_pwm_outp;
      result = hil_watchdog_set_pwm_expiration_state
        (tracking_DW.HILInitialize_Card, tracking_P.HILInitialize_pwm_channels,
         4U, &tracking_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }
    }

    if ((tracking_P.HILInitialize_set_other_outputs && !is_switching) ||
        (tracking_P.HILInitialize_set_other_outpu_l && is_switching)) {
      result = hil_write_other(tracking_DW.HILInitialize_Card,
        tracking_P.HILInitialize_other_output_chan, 2U,
        tracking_P.HILInitialize_initial_other_out);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(tracking_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for Constant: '<S4>/Constant2' */
  tracking_B.Constant2 = tracking_P.Constant2_Value;

  /* Start for Constant: '<S4>/Constant1' */
  tracking_B.Constant1 = tracking_P.Constant1_Value;

  /* Start for Constant: '<S4>/Constant9' */
  tracking_B.Constant9 = tracking_P.Constant9_Value;

  /* Start for Constant: '<S5>/Constant1' */
  tracking_B.Constant1_a = tracking_P.Constant1_Value_n;

  /* Start for Constant: '<S5>/Constant9' */
  tracking_B.Constant9_m = tracking_P.Constant9_Value_e;

  /* Start for Constant: '<S5>/Constant2' */
  tracking_B.Constant2_a = tracking_P.Constant2_Value_i;

  /* Start for Constant: '<S9>/x0' */
  tracking_B.x0 = tracking_P.x0_Value;

  /* Start for Constant: '<S11>/x0' */
  tracking_B.x0_j = tracking_P.x0_Value_k;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator1_CSTATE = 0.0;
  }

  tracking_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator2_CSTATE = 2.0;
  }

  tracking_DW.Integrator2_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S4>/Integrator3' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator3_CSTATE = 2.0;
  }

  tracking_DW.Integrator3_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S5>/Integrator2' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator2_CSTATE_f = 0.0;
  }

  tracking_DW.Integrator2_IWORK_g.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S5>/Integrator3' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator3_CSTATE_d = 0.0;
  }

  tracking_DW.Integrator3_IWORK_a.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator1_CSTATE_c = 0.0;
  }

  tracking_DW.Integrator1_IWORK_j.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S11>/Integrator2' */
  tracking_X.Integrator2_CSTATE_b = tracking_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S9>/Integrator2' */
  tracking_X.Integrator2_CSTATE_fg = tracking_P.Integrator2_IC_k;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator1_CSTATE_j = 0.0;
  }

  tracking_DW.Integrator1_IWORK_d.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S11>/Integrator1' */
  if (rtmIsFirstInitCond(tracking_M)) {
    tracking_X.Integrator1_CSTATE_ch = 0.0;
  }

  tracking_DW.Integrator1_IWORK_p.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  tracking_X.Integrator_CSTATE = tracking_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S16>/Integrator' */
  tracking_X.Integrator_CSTATE_l = tracking_P.Integrator_IC_p;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(tracking_M)) {
    rtmSetFirstInitCond(tracking_M, 0);
  }
}

/* Model terminate function */
void tracking_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: tracking/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_pwm_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(tracking_DW.HILInitialize_Card);
    hil_monitor_stop_all(tracking_DW.HILInitialize_Card);
    is_switching = false;
    if ((tracking_P.HILInitialize_set_pwm_outputs_k && !is_switching) ||
        (tracking_P.HILInitialize_set_pwm_outputs_e && is_switching)) {
      tracking_DW.HILInitialize_POValues[0] =
        tracking_P.HILInitialize_final_pwm_outputs;
      tracking_DW.HILInitialize_POValues[1] =
        tracking_P.HILInitialize_final_pwm_outputs;
      tracking_DW.HILInitialize_POValues[2] =
        tracking_P.HILInitialize_final_pwm_outputs;
      tracking_DW.HILInitialize_POValues[3] =
        tracking_P.HILInitialize_final_pwm_outputs;
      num_final_pwm_outputs = 4U;
    }

    if ((tracking_P.HILInitialize_set_other_outpu_b && !is_switching) ||
        (tracking_P.HILInitialize_set_other_outpu_h && is_switching)) {
      num_final_other_outputs = 2U;
    }

    if (0
        || num_final_pwm_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(tracking_DW.HILInitialize_Card
                         , NULL, 0
                         , tracking_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , tracking_P.HILInitialize_other_output_chan,
                         num_final_other_outputs
                         , NULL
                         , &tracking_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , tracking_P.HILInitialize_final_other_outpu
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(tracking_DW.HILInitialize_Card,
            tracking_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &tracking_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(tracking_DW.HILInitialize_Card,
            tracking_P.HILInitialize_other_output_chan, num_final_other_outputs,
            tracking_P.HILInitialize_final_other_outpu);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(tracking_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(tracking_DW.HILInitialize_Card);
    hil_monitor_delete_all(tracking_DW.HILInitialize_Card);
    hil_close(tracking_DW.HILInitialize_Card);
    tracking_DW.HILInitialize_Card = NULL;
  }
}
