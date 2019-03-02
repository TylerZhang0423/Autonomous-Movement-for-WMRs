/*
 * mission_server_leader_follower_qbot2_qbot2_data.c
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
#include "mission_server_leader_follower_qbot2_qbot2.h"
#include "mission_server_leader_follower_qbot2_qbot2_private.h"

/* Block parameters (auto storage) */
P_mission_server_leader_follo_T mission_server_leader_followe_P = {
  3,                                   /* Mask Parameter: ShowMessageonHost_message_icon
                                        * Referenced by: '<S6>/Show Message on Host'
                                        */

  /*  Expression: [0 -1 0;0 0 1;-1 0 0]
   * Referenced by: '<S9>/Rotate Basis from UVS Orientation to Global Frame'
   */
  { 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /*  Expression: [1;-1;-1]
   * Referenced by: '<S9>/Convert Optitrack orientation frame to Right-Hand Convention'
   */
  { 1.0, -1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Default Dummy'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */

  /*  Expression: [-1;1;1]
   * Referenced by: '<S9>/Convert Optitrack frame to Right-Hand Convention'
   */
  { -1.0, 1.0, 1.0 },

  /*  Expression: [-1;1;1]
   * Referenced by: '<S8>/Convert Optitrack frame to Right-Hand Convention'
   */
  { -1.0, 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Toggle High'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Toggle Low'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Dummy Data'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Default x (m)'
                                        */

  /*  Expression: [1 -1 -1 1 1]
   * Referenced by: '<Root>/Waypoints - x (m)'
   */
  { 1.0, -1.0, -1.0, 1.0, 1.0 },

  /*  Expression: [1 1 -1 -1 1]
   * Referenced by: '<Root>/Waypoints - z (m)'
   */
  { 1.0, 1.0, -1.0, -1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Default z (m)'
                                        */

  /*  Expression: [0 -1 0;0 0 1;-1 0 0]
   * Referenced by: '<S8>/Rotate Basis from UVS Orientation to Global Frame'
   */
  { 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /*  Expression: [1;-1;-1]
   * Referenced by: '<S8>/Convert Optitrack orientation frame to Right-Hand Convention'
   */
  { 1.0, -1.0, -1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Default Dummy'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S18>/Dummy Data [3]'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Dummy Data'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Enable'
                                        */
  0,                                   /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_SndPriority_n
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_RcvPriority_n
                                        * Referenced by: '<S5>/Stream Server'
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
  1460U,                               /* Computed Parameter: StreamServer_SndSize_a
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  1460U,                               /* Computed Parameter: StreamServer_RcvSize_f
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_SndFIFO_m
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_RcvFIFO_i
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  2,                                   /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1,                                   /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  2,                                   /* Computed Parameter: StreamServer_Optimize_d
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  1,                                   /* Computed Parameter: StreamServer_Implementation_p
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<S6>/Manual Switch2'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<S6>/Manual Switch3'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<S3>/To Host File'
   */
  { 109U, 105U, 115U, 115U, 105U, 111U, 110U, 95U, 100U, 97U, 116U, 97U, 95U,
    50U, 54U, 45U, 77U, 97U, 121U, 45U, 50U, 48U, 49U, 55U, 95U, 49U, 55U, 45U,
    53U, 50U, 45U, 51U, 53U, 46U, 109U, 97U, 116U, 0U },

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
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 53U, 0U },
  1U,                                  /* Computed Parameter: StreamServer_Endian
                                        * Referenced by: '<S4>/Stream Server'
                                        */

  /*  Expression: uri_argument
   * Referenced by: '<S5>/Stream Server'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 54U, 0U },
  1U,                                  /* Computed Parameter: StreamServer_Endian_e
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  0                                    /* Computed Parameter: StreamServer_Active_p
                                        * Referenced by: '<S5>/Stream Server'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_mission_server_leader__T mission_server_leader_fo_ConstP = {
  /* Computed Parameter: OptiTrackTrackables_R
   * Referenced by: '<S2>/OptiTrack Trackables'
   */
  { 1U, 2U }
};
