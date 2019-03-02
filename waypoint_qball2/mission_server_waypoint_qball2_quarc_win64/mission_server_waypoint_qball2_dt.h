/*
 * mission_server_waypoint_qball2_dt.h
 *
 * Code generation for model "mission_server_waypoint_qball2".
 *
 * Model version              : 1.381
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 19:37:12 2017
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
  { (char_T *)(&mission_server_waypoint_qball_B.OptiTrackTrackables_o1[0]), 0, 0,
    50 },

  { (char_T *)(&mission_server_waypoint_qball_B.StreamServer_o2), 6, 0, 1 },

  { (char_T *)(&mission_server_waypoint_qball_B.tick), 2, 0, 1 },

  { (char_T *)(&mission_server_waypoint_qball_B.StreamServer_o1), 3, 0, 1 },

  { (char_T *)(&mission_server_waypoint_qball_B.OptiTrackTrackables_o4), 8, 0, 3
  }
  ,

  { (char_T *)(&mission_server_waypoint_qbal_DW.QBall2Trajectory_XBuffer[0]), 0,
    0, 2002 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.OptiTrackTrackables_Optitrack),
    14, 0, 1 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.ToHostFile_PointsWritten), 15, 0,
    1 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.StreamServer_Stream), 16, 0, 1 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.OptiTrackxyz_PWORK.LoggedData),
    11, 0, 2 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.sfEvent), 6, 0, 2 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.ToHostFile_SamplesCount), 7, 0,
    5 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.QBall2Trajectory_IWORK[0]), 10,
    0, 2 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.temporalCounter_i1), 5, 0, 1 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.ChartSchedulerLogic_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.is_active_c3_mission_server_way),
    3, 0, 4 },

  { (char_T *)(&mission_server_waypoint_qbal_DW.Memory_PreviousInput), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  17U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&mission_server_waypoint_qball_P.QBall2Trajectory_maximum_x), 0,
    0, 4 },

  { (char_T *)(&mission_server_waypoint_qball_P.QBall2Trajectory_update_rate), 6,
    0, 1 },

  { (char_T *)(&mission_server_waypoint_qball_P.ShowMessageonHost_message_icon),
    2, 0, 2 },

  { (char_T *)(&mission_server_waypoint_qball_P.ConvertOptitrackframetoRightHan
               [0]), 0, 0, 41 },

  { (char_T *)(&mission_server_waypoint_qball_P.StreamServer_SndPriority), 6, 0,
    2 },

  { (char_T *)(&mission_server_waypoint_qball_P.ToHostFile_Decimation), 7, 0, 5
  },

  { (char_T *)(&mission_server_waypoint_qball_P.StreamServer_Optimize), 2, 0, 2
  },

  { (char_T *)(&mission_server_waypoint_qball_P.ManualSwitch1_CurrentSetting), 3,
    0, 78 },

  { (char_T *)(&mission_server_waypoint_qball_P.Memory_X0), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] mission_server_waypoint_qball2_dt.h */
