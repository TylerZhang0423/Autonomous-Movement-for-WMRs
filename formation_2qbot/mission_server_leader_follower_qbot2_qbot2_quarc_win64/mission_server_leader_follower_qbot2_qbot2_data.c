/*
 * mission_server_leader_follower_qbot2_qbot2_data.c
 *
 * Code generation for model "mission_server_leader_follower_qbot2_qbot2".
 *
 * Model version              : 1.86
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Jun 01 15:22:20 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "mission_server_leader_follower_qbot2_qbot2.h"
#include "mission_server_leader_follower_qbot2_qbot2_private.h"

/* Block parameters (auto storage) */
P_mission_server_leader_follo_T mission_server_leader_followe_P = {
  3,                                   /* Mask Parameter: ShowMessageonHost_message_icon
                                        * Referenced by: '<S7>/Show Message on Host'
                                        */
  3,                                   /* Mask Parameter: ShowMessageonHost_message_ico_k
                                        * Referenced by: '<S8>/Show Message on Host'
                                        */

  /*  Expression: [0 -1 0;0 0 1;-1 0 0]
   * Referenced by: '<S12>/Rotate Basis from UVS Orientation to Global Frame'
   */
  { 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /*  Expression: [1;-1;-1]
   * Referenced by: '<S12>/Convert Optitrack orientation frame to Right-Hand Convention'
   */
  { 1.0, -1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Default Dummy'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */

  /*  Expression: [-1;1;1]
   * Referenced by: '<S12>/Convert Optitrack frame to Right-Hand Convention'
   */
  { -1.0, 1.0, 1.0 },

  /*  Expression: [-1;1;1]
   * Referenced by: '<S11>/Convert Optitrack frame to Right-Hand Convention'
   */
  { -1.0, 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Toggle High'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Toggle Low'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Dummy Data'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Default x (m)'
                                        */
  0.2,                                 /* Expression: [0.2]
                                        * Referenced by: '<Root>/Waypoints - x (m)'
                                        */
  0.2,                                 /* Expression: [0.2]
                                        * Referenced by: '<Root>/Waypoints - z (m)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Default z (m)'
                                        */

  /*  Expression: [0 -1 0;0 0 1;-1 0 0]
   * Referenced by: '<S11>/Rotate Basis from UVS Orientation to Global Frame'
   */
  { 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /*  Expression: [1;-1;-1]
   * Referenced by: '<S11>/Convert Optitrack orientation frame to Right-Hand Convention'
   */
  { 1.0, -1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Default Dummy'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S21>/Dummy Data [3]'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Dummy Data'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Default x (m)'
                                        */
  -0.2,                                /* Expression: [-0.2]
                                        * Referenced by: '<Root>/Waypoints - x (m)1'
                                        */
  -0.2,                                /* Expression: [-0.2]
                                        * Referenced by: '<Root>/Waypoints - z (m)1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Default z (m)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Enable1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Enable'
                                        */
  0,                                   /* Computed Parameter: StreamServer2_SndPriority
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  0,                                   /* Computed Parameter: StreamServer2_RcvPriority
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  0,                                   /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile_Decimation
                                        * Referenced by: '<S4>/To Host File'
                                        */
  1460U,                               /* Computed Parameter: StreamServer2_SndSize
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  1460U,                               /* Computed Parameter: StreamServer2_RcvSize
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  1000U,                               /* Computed Parameter: StreamServer2_SndFIFO
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  1000U,                               /* Computed Parameter: StreamServer2_RcvFIFO
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  1460U,                               /* Computed Parameter: StreamServer_SndSize
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  1460U,                               /* Computed Parameter: StreamServer_RcvSize
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_SndFIFO
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_RcvFIFO
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  2,                                   /* Computed Parameter: StreamServer2_Optimize
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  1,                                   /* Computed Parameter: StreamServer2_Implementation
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  2,                                   /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  1,                                   /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<S7>/Manual Switch2'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<S7>/Manual Switch3'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<S4>/To Host File'
   */
  { 109U, 105U, 115U, 115U, 105U, 111U, 110U, 95U, 100U, 97U, 116U, 97U, 95U,
    48U, 49U, 45U, 74U, 117U, 110U, 45U, 50U, 48U, 49U, 55U, 95U, 49U, 53U, 45U,
    50U, 50U, 45U, 49U, 53U, 46U, 109U, 97U, 116U, 0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<S4>/To Host File'
   */
  { 109U, 105U, 115U, 115U, 105U, 111U, 110U, 95U, 100U, 97U, 116U, 97U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile_FileFormat
                                        * Referenced by: '<S4>/To Host File'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting_b
                                        * Referenced by: '<S8>/Manual Switch2'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch3_CurrentSetting_k
                                        * Referenced by: '<S8>/Manual Switch3'
                                        */

  /*  Expression: uri_argument
   * Referenced by: '<S5>/Stream Server2'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 53U, 0U },
  1U,                                  /* Computed Parameter: StreamServer2_Endian
                                        * Referenced by: '<S5>/Stream Server2'
                                        */

  /*  Expression: uri_argument
   * Referenced by: '<S6>/Stream Server'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 54U, 0U },
  1U,                                  /* Computed Parameter: StreamServer_Endian
                                        * Referenced by: '<S6>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer2_Active
                                        * Referenced by: '<S5>/Stream Server2'
                                        */
  0                                    /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S6>/Stream Server'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_mission_server_leader__T mission_server_leader_fo_ConstP = {
  /* Computed Parameter: OptiTrackTrackables_R
   * Referenced by: '<S3>/OptiTrack Trackables'
   */
  { 1U, 2U }
};
