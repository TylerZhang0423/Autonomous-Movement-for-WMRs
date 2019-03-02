/*
 * leader_qbot2_dt.h
 *
 * Code generation for model "leader_qbot2".
 *
 * Model version              : 1.98
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Jun 01 15:14:15 2017
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
  sizeof(t_pstream),
  sizeof(t_card)
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
  "t_pstream",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&leader_qbot2_B.StreamClient_o3[0]), 0, 0, 27 },

  { (char_T *)(&leader_qbot2_B.StreamClient_o2), 6, 0, 1 },

  { (char_T *)(&leader_qbot2_B.StreamClient_o4), 8, 0, 4 }
  ,

  { (char_T *)(&leader_qbot2_DW.DiscreteTimeIntegrator_DSTATE), 0, 0, 55 },

  { (char_T *)(&leader_qbot2_DW.StreamClient_Stream), 14, 0, 1 },

  { (char_T *)(&leader_qbot2_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&leader_qbot2_DW.HILRead1_PWORK), 11, 0, 2 },

  { (char_T *)(&leader_qbot2_DW.HILInitialize_QuadratureModes[0]), 6, 0, 22 },

  { (char_T *)(&leader_qbot2_DW.HILInitialize_POSortedChans[0]), 7, 0, 4 },

  { (char_T *)(&leader_qbot2_DW.Integrator1_IWORK.IcNeedsLoading), 10, 0, 2 },

  { (char_T *)(&leader_qbot2_DW.DiscreteTimeIntegrator_PrevRese), 2, 0, 7 },

  { (char_T *)(&leader_qbot2_DW.StreamClient_Connected), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&leader_qbot2_P.HILInitialize_analog_input_maxi[0]), 0, 0, 49 },

  { (char_T *)(&leader_qbot2_P.HILInitialize_initial_encoder_c), 6, 0, 6 },

  { (char_T *)(&leader_qbot2_P.HILRead1_analog_channels), 7, 0, 32 },

  { (char_T *)(&leader_qbot2_P.ShowMessageonHost_message_icon), 2, 0, 2 },

  { (char_T *)(&leader_qbot2_P.CompareToConstant_const), 3, 0, 1 },

  { (char_T *)(&leader_qbot2_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&leader_qbot2_P.unity_Value), 0, 0, 43 },

  { (char_T *)(&leader_qbot2_P.StreamClient_SndPriority), 6, 0, 2 },

  { (char_T *)(&leader_qbot2_P.StreamClient_SndSize), 7, 0, 4 },

  { (char_T *)(&leader_qbot2_P.StreamClient_Optimize), 2, 0, 2 },

  { (char_T *)(&leader_qbot2_P.StringConstant1_Value[0]), 3, 0, 84 },

  { (char_T *)(&leader_qbot2_P.StreamClient_Active), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  12U,
  rtPTransitions
};

/* [EOF] leader_qbot2_dt.h */
