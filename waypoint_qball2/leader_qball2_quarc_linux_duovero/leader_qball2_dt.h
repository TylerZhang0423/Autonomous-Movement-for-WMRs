/*
 * leader_qball2_dt.h
 *
 * Code generation for model "leader_qball2".
 *
 * Model version              : 1.898
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 19:34:49 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_timeout),
  sizeof(t_pstream),
  sizeof(t_uint64),
  sizeof(t_card),
  sizeof(t_boolean)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_timeout",
  "t_pstream",
  "t_uint64",
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&leader_qball2_B.SampleTime), 0, 0, 264 },

  { (char_T *)(&leader_qball2_B.StreamClient_o2), 6, 0, 2 },

  { (char_T *)(&leader_qball2_B.SigmoidCompute_o2), 2, 0, 1 },

  { (char_T *)(&leader_qball2_B.StreamClient_o1), 3, 0, 6 },

  { (char_T *)(&leader_qball2_B.StreamClient_o4), 8, 0, 24 },

  { (char_T *)(&leader_qball2_B.EnabledSubsystem1_b.RelationalOperator), 8, 0, 1
  },

  { (char_T *)(&leader_qball2_B.EnabledSubsystem1.RelationalOperator), 8, 0, 1 },

  { (char_T *)(&leader_qball2_B.sf_EmbeddedMATLABFunction_j4.y), 0, 0, 1 },

  { (char_T *)(&leader_qball2_B.sf_EmbeddedMATLABFunction.y), 0, 0, 1 },

  { (char_T *)(&leader_qball2_B.sf_EmbeddedMATLABFunction_d.y), 0, 0, 1 },

  { (char_T *)(&leader_qball2_B.EnabledMovingAverage_e.div[0]), 0, 0, 3 },

  { (char_T *)(&leader_qball2_B.EnabledMovingAverage_c.div[0]), 0, 0, 3 }
  ,

  { (char_T *)(&leader_qball2_DW.SampleTime_PreviousTime), 14, 0, 1 },

  { (char_T *)(&leader_qball2_DW.UnitDelay_DSTATE), 0, 0, 101 },

  { (char_T *)(&leader_qball2_DW.StreamClient_Stream), 15, 0, 2 },

  { (char_T *)(&leader_qball2_DW.ToHostFile_PointsWritten), 16, 0, 1 },

  { (char_T *)(&leader_qball2_DW.HILInitialize_Card), 17, 0, 1 },

  { (char_T *)(&leader_qball2_DW.ContinuousSigmoid_RWORK.Time), 0, 0, 2 },

  { (char_T *)(&leader_qball2_DW.HILReadWrite1_PWORK), 11, 0, 53 },

  { (char_T *)(&leader_qball2_DW.HILInitialize_DOStates[0]), 6, 0, 2 },

  { (char_T *)(&leader_qball2_DW.ToHostFile_SamplesCount), 7, 0, 2 },

  { (char_T *)(&leader_qball2_DW.Integrator1_IWORK.IcNeedsLoading), 10, 0, 8 },

  { (char_T *)(&leader_qball2_DW.TriggeredSubsystem_SubsysRanBC), 2, 0, 18 },

  { (char_T *)(&leader_qball2_DW.ContinuousSigmoid_Flag), 3, 0, 2 },

  { (char_T *)(&leader_qball2_DW.HILInitialize_DOBits[0]), 8, 0, 5 },

  { (char_T *)(&leader_qball2_DW.HILReadWrite1_W_DigitalBuffer[0]), 18, 0, 2 },

  { (char_T *)(&leader_qball2_DW.EnabledMovingAverage_MODE), 8, 0, 4 },

  { (char_T *)
    (&leader_qball2_DW.EnabledSubsystem1_b.DiscreteTimeIntegrator_DSTATE), 0, 0,
    1 },

  { (char_T *)
    (&leader_qball2_DW.EnabledSubsystem1_b.EnabledSubsystem1_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&leader_qball2_DW.EnabledSubsystem1_b.EnabledSubsystem1_MODE), 8,
    0, 1 },

  { (char_T *)(&leader_qball2_DW.EnabledSubsystem1.DiscreteTimeIntegrator_DSTATE),
    0, 0, 1 },

  { (char_T *)(&leader_qball2_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&leader_qball2_DW.EnabledSubsystem1.EnabledSubsystem1_MODE), 8, 0,
    1 },

  { (char_T *)(&leader_qball2_DW.EnabledMovingAverage_e.UnitDelay_DSTATE), 0, 0,
    4 },

  { (char_T *)
    (&leader_qball2_DW.EnabledMovingAverage_e.EnabledMovingAverage_SubsysRanB),
    2, 0, 1 },

  { (char_T *)
    (&leader_qball2_DW.EnabledMovingAverage_e.EnabledMovingAverage_MODE), 8, 0,
    1 },

  { (char_T *)(&leader_qball2_DW.EnabledMovingAverage_c.UnitDelay_DSTATE), 0, 0,
    4 },

  { (char_T *)
    (&leader_qball2_DW.EnabledMovingAverage_c.EnabledMovingAverage_SubsysRanB),
    2, 0, 1 },

  { (char_T *)
    (&leader_qball2_DW.EnabledMovingAverage_c.EnabledMovingAverage_MODE), 8, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  39U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&leader_qball2_P.KdHEIGHT_DOWN), 0, 0, 126 },

  { (char_T *)(&leader_qball2_P.HILInitialize_pwm_alignment), 6, 0, 5 },

  { (char_T *)(&leader_qball2_P.HILInitialize_analog_input_chan[0]), 7, 0, 23 },

  { (char_T *)(&leader_qball2_P.ShowMessageonHost1_message_icon), 2, 0, 5 },

  { (char_T *)(&leader_qball2_P.HILInitialize_active), 8, 0, 36 },

  { (char_T *)(&leader_qball2_P.Out1_Y0), 0, 0, 233 },

  { (char_T *)(&leader_qball2_P.StreamClient_SndPriority), 6, 0, 4 },

  { (char_T *)(&leader_qball2_P.StreamClient_SndSize), 7, 0, 9 },

  { (char_T *)(&leader_qball2_P.StreamClient_Optimize), 2, 0, 4 },

  { (char_T *)(&leader_qball2_P.StringConstant1_Value[0]), 3, 0, 173 },

  { (char_T *)(&leader_qball2_P.timeout_Y0), 8, 0, 6 },

  { (char_T *)(&leader_qball2_P.EnabledSubsystem1_b.Constant_Value), 0, 0, 3 },

  { (char_T *)(&leader_qball2_P.EnabledSubsystem1_b.timeout_Y0), 8, 0, 1 },

  { (char_T *)(&leader_qball2_P.EnabledSubsystem1.Constant_Value), 0, 0, 3 },

  { (char_T *)(&leader_qball2_P.EnabledSubsystem1.timeout_Y0), 8, 0, 1 },

  { (char_T *)(&leader_qball2_P.EnabledMovingAverage_e.unity_Value), 0, 0, 3 },

  { (char_T *)(&leader_qball2_P.EnabledMovingAverage_c.unity_Value), 0, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  17U,
  rtPTransitions
};

/* [EOF] leader_qball2_dt.h */
