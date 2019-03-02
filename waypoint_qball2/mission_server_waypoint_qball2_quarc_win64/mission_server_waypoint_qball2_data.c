/*
 * mission_server_waypoint_qball2_data.c
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
#include "mission_server_waypoint_qball2.h"
#include "mission_server_waypoint_qball2_private.h"

/* Block parameters (auto storage) */
P_mission_server_waypoint_qba_T mission_server_waypoint_qball_P = {
  1.0,                                 /* Mask Parameter: QBall2Trajectory_maximum_x
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  1.0,                                 /* Mask Parameter: QBall2Trajectory_maximum_y
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  -1.0,                                /* Mask Parameter: QBall2Trajectory_minimum_x
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  -1.0,                                /* Mask Parameter: QBall2Trajectory_minimum_y
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  100,                                 /* Mask Parameter: QBall2Trajectory_update_rate
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  3,                                   /* Mask Parameter: ShowMessageonHost_message_icon
                                        * Referenced by: '<S5>/Show Message on Host'
                                        */
  2,                                   /* Mask Parameter: QBall2Trajectory_trace_mode
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */

  /*  Expression: [-1;1;1]
   * Referenced by: '<S7>/Convert Optitrack frame to Right-Hand Convention'
   */
  { -1.0, 1.0, 1.0 },

  /*  Expression: [1 -1 -1 1 0]*0.5
   * Referenced by: '<Root>/Constant2'
   */
  { 0.5, -0.5, -0.5, 0.5, 0.0 },

  /*  Expression: [1 1 -1 -1 0]*0.5
   * Referenced by: '<Root>/Constant3'
   */
  { 0.5, 0.5, -0.5, -0.5, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Toggle High'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Toggle Low'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Dummy Data'
                                        */

  /*  Expression: [0 -1 0;0 0 1;-1 0 0]
   * Referenced by: '<S7>/Rotate Basis from UVS Orientation to Global Frame'
   */
  { 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /*  Expression: [1;-1;-1]
   * Referenced by: '<S7>/Convert Optitrack orientation frame to Right-Hand Convention'
   */
  { 1.0, -1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Default Dummy'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S12>/Dummy Data [3]1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S12>/Dummy Data [3]2'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S12>/Dummy Data [3]'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Dummy Data'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */
  0.15,                                /* Expression: 0.15
                                        * Referenced by: '<S5>/Tracking Tolerance - Leader (m)'
                                        */
  0,                                   /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile_Decimation
                                        * Referenced by: '<S3>/To Host File'
                                        */
  1460U,                               /* Computed Parameter: StreamServer_SndSize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1460U,                               /* Computed Parameter: StreamServer_RcvSize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_SndFIFO
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_RcvFIFO
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  2,                                   /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1,                                   /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<S3>/To Host File'
   */
  { 109U, 105U, 115U, 115U, 105U, 111U, 110U, 95U, 100U, 97U, 116U, 97U, 95U,
    50U, 54U, 45U, 77U, 97U, 121U, 45U, 50U, 48U, 49U, 55U, 95U, 49U, 57U, 45U,
    51U, 55U, 45U, 49U, 49U, 46U, 109U, 97U, 116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<S3>/To Host File'
   */
  { 109U, 105U, 115U, 115U, 105U, 111U, 110U, 95U, 100U, 97U, 116U, 97U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile_FileFormat
                                        * Referenced by: '<S3>/To Host File'
                                        */

  /*  Expression: uri_argument
   * Referenced by: '<S4>/Stream Server'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 54U, 0U },
  1U,                                  /* Computed Parameter: StreamServer_Endian
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S5>/Memory'
                                        */
  0                                    /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S4>/Stream Server'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_mission_server_waypoin_T mission_server_waypoint__ConstP = {
  /* Computed Parameter: OptiTrackTrackables_RBIDs
   * Referenced by: '<S2>/OptiTrack Trackables'
   */
  1U
};
