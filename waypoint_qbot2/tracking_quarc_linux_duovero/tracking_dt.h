/*
 * tracking_dt.h
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
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&tracking_B.Constant2), 0, 0, 44 }
  ,

  { (char_T *)(&tracking_DW.HILInitialize_AIMinimums[0]), 0, 0, 36 },

  { (char_T *)(&tracking_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&tracking_DW.HILWrite_PWORK), 11, 0, 4 },

  { (char_T *)(&tracking_DW.HILInitialize_QuadratureModes[0]), 6, 0, 22 },

  { (char_T *)(&tracking_DW.HILInitialize_POSortedChans[0]), 7, 0, 4 },

  { (char_T *)(&tracking_DW.Integrator1_IWORK.IcNeedsLoading), 10, 0, 8 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&tracking_P.HILInitialize_analog_input_maxi[0]), 0, 0, 41 },

  { (char_T *)(&tracking_P.HILInitialize_initial_encoder_c), 6, 0, 9 },

  { (char_T *)(&tracking_P.HILRead1_analog_channels), 7, 0, 30 },

  { (char_T *)(&tracking_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&tracking_P.Constant2_Value), 0, 0, 22 },

  { (char_T *)(&tracking_P.HILWrite_Active), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] tracking_dt.h */
