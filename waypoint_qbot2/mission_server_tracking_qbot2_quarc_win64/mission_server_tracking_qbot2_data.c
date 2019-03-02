/*
 * mission_server_tracking_qbot2_data.c
 *
 * Code generation for model "mission_server_tracking_qbot2".
 *
 * Model version              : 1.94
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed May 31 17:51:20 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "mission_server_tracking_qbot2.h"
#include "mission_server_tracking_qbot2_private.h"

/* Block parameters (auto storage) */
P_mission_server_tracking_qbo_T mission_server_tracking_qbot2_P = {
  3,                                   /* Mask Parameter: ShowMessageonHost_message_icon
                                        * Referenced by: '<S5>/Show Message on Host'
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
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */

  /*  Expression: [-1;1;1]
   * Referenced by: '<S7>/Convert Optitrack frame to Right-Hand Convention'
   */
  { -1.0, 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Toggle High'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Toggle Low'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Dummy Data'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Default x (m)'
                                        */

  /*  Expression: [1 -1 0]
   * Referenced by: '<Root>/Waypoints - x'
   */
  { 1.0, -1.0, 0.0 },

  /*  Expression: [1 1 0]
   * Referenced by: '<Root>/Waypoints - z'
   */
  { 1.0, 1.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Default z (m)'
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
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch2'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch3'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<S3>/To Host File'
   */
  { 109U, 105U, 115U, 115U, 105U, 111U, 110U, 95U, 100U, 97U, 116U, 97U, 95U,
    51U, 49U, 45U, 77U, 97U, 121U, 45U, 50U, 48U, 49U, 55U, 95U, 49U, 55U, 45U,
    53U, 49U, 45U, 49U, 55U, 46U, 109U, 97U, 116U, 0U },

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
  0                                    /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S4>/Stream Server'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_mission_server_trackin_T mission_server_tracking__ConstP = {
  /* Computed Parameter: OptiTrackTrackables_RBIDs
   * Referenced by: '<S2>/OptiTrack Trackables'
   */
  2U
};
