/*
 * mission_server_leader_follower_qbot2_qbot2_dt.h
 *
 * Code generation for model "mission_server_leader_follower_qbot2_qbot2".
 *
 * Model version              : 1.50
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 17:52:37 2017
 *
 * Target selection: quarc_win64.tlc
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
  sizeof(t_optitrack_properties),
  sizeof(t_uint64),
  sizeof(t_pstream)
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
  "t_optitrack_properties",
  "t_uint64",
  "t_pstream"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&mission_server_leader_followe_B.OptiTrackTrackables_o1[0]), 0, 0,
    43 },

  { (char_T *)(&mission_server_leader_followe_B.StreamServer_o2), 6, 0, 2 },

  { (char_T *)(&mission_server_leader_followe_B.StreamServer_o1), 3, 0, 2 },

  { (char_T *)(&mission_server_leader_followe_B.OptiTrackTrackables_o4[0]), 8, 0,
    4 },

  { (char_T *)
    (&mission_server_leader_followe_B.sf_RotationMatrix_from_EulerAng.R[0]), 0,
    0, 9 },

  { (char_T *)
    (&mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotatio.Angles[0]),
    0, 0, 3 },

  { (char_T *)
    (&mission_server_leader_followe_B.sf_RotationMatrix_from_EulerA_h.R[0]), 0,
    0, 9 },

  { (char_T *)
    (&mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotat_j.Angles[0]),
    0, 0, 3 }
  ,

  { (char_T *)(&mission_server_leader_follow_DW.idx), 0, 0, 3 },

  { (char_T *)(&mission_server_leader_follow_DW.OptiTrackTrackables_Optitrack),
    14, 0, 1 },

  { (char_T *)(&mission_server_leader_follow_DW.ToHostFile_PointsWritten), 15, 0,
    1 },

  { (char_T *)(&mission_server_leader_follow_DW.StreamServer_Stream), 16, 0, 2 },

  { (char_T *)(&mission_server_leader_follow_DW.ToHostFile_PWORK), 11, 0, 1 },

  { (char_T *)(&mission_server_leader_follow_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&mission_server_leader_follow_DW.ToHostFile_SamplesCount), 7, 0,
    2 },

  { (char_T *)(&mission_server_leader_follow_DW.is_active_c4_mission_server_lea),
    3, 0, 2 },

  { (char_T *)(&mission_server_leader_follow_DW.isStable), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  17U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&mission_server_leader_followe_P.ShowMessageonHost_message_icon),
    2, 0, 1 },

  { (char_T *)(&mission_server_leader_followe_P.RotateBasisfromUVSOrientationto
               [0]), 0, 0, 54 },

  { (char_T *)(&mission_server_leader_followe_P.StreamServer_SndPriority), 6, 0,
    4 },

  { (char_T *)(&mission_server_leader_followe_P.ToHostFile_Decimation), 7, 0, 9
  },

  { (char_T *)(&mission_server_leader_followe_P.StreamServer_Optimize), 2, 0, 4
  },

  { (char_T *)(&mission_server_leader_followe_P.ManualSwitch_CurrentSetting), 3,
    0, 105 },

  { (char_T *)(&mission_server_leader_followe_P.StreamServer_Active), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] mission_server_leader_follower_qbot2_qbot2_dt.h */
