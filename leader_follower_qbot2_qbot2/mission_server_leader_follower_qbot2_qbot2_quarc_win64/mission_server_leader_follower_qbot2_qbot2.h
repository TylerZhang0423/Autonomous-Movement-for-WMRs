/*
 * mission_server_leader_follower_qbot2_qbot2.h
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
#ifndef RTW_HEADER_mission_server_leader_follower_qbot2_qbot2_h_
#define RTW_HEADER_mission_server_leader_follower_qbot2_qbot2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef mission_server_leader_follower_qbot2_qbot2_COMMON_INCLUDES_
# define mission_server_leader_follower_qbot2_qbot2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "quanser_optitrack.h"
#include "quanser_messages.h"
#include "quanser_memory.h"
#include "quanser_string.h"
#include "stream_server_block.h"
#include "quanser_extern.h"
#endif                                 /* mission_server_leader_follower_qbot2_qbot2_COMMON_INCLUDES_ */

#include "mission_server_leader_follower_qbot2_qbot2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#define mission_server_leader_follower_qbot2_qbot2_M (mission_server_leader_follow_M)

/* Block signals for system '<S10>/EulerAngles_zyx_from_RotationMatrix' */
typedef struct {
  real_T Angles[3];                    /* '<S10>/EulerAngles_zyx_from_RotationMatrix' */
} B_EulerAngles_zyx_from_Rotati_T;

/* Block signals for system '<S11>/RotationMatrix_from_EulerAngles_yzx' */
typedef struct {
  real_T R[9];                         /* '<S11>/RotationMatrix_from_EulerAngles_yzx' */
} B_RotationMatrix_from_EulerAn_T;

/* Block signals (auto storage) */
typedef struct {
  real_T OptiTrackTrackables_o1[6];    /* '<S2>/OptiTrack Trackables' */
  real_T OptiTrackTrackables_o2[8];    /* '<S2>/OptiTrack Trackables' */
  real_T OptiTrackTrackables_o3[6];    /* '<S2>/OptiTrack Trackables' */
  real_T Gain[3];                      /* '<Root>/Gain' */
  real_T DataTypeConversion[2];        /* '<S2>/Data Type Conversion' */
  real_T ConvertOptitrackframetoRightHan[3];/* '<S9>/Convert Optitrack frame to Right-Hand Convention' */
  real_T ConvertOptitrackframetoRightH_d[3];/* '<S8>/Convert Optitrack frame to Right-Hand Convention' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T DummyData;                    /* '<S20>/Dummy Data' */
  real_T ManualSwitch2;                /* '<S6>/Manual Switch2' */
  real_T ManualSwitch3;                /* '<S6>/Manual Switch3' */
  real_T DummyData3[3];                /* '<S18>/Dummy Data [3]' */
  real_T DummyData_o;                  /* '<S18>/Dummy Data' */
  real_T waypoint_num;                 /* '<S6>/Waypoint Scheduler' */
  real_T mission_complete;             /* '<S6>/Waypoint Scheduler' */
  real_T x_ugv_ref;                    /* '<S1>/Logic Chart' */
  real_T z_ugv_ref;                    /* '<S1>/Logic Chart' */
  int32_T StreamServer_o2;             /* '<S4>/Stream Server' */
  int32_T StreamServer_o2_c;           /* '<S5>/Stream Server' */
  uint8_T StreamServer_o1;             /* '<S4>/Stream Server' */
  uint8_T StreamServer_o1_e;           /* '<S5>/Stream Server' */
  boolean_T OptiTrackTrackables_o4[2]; /* '<S2>/OptiTrack Trackables' */
  boolean_T StreamServer_o3;           /* '<S4>/Stream Server' */
  boolean_T StreamServer_o3_i;         /* '<S5>/Stream Server' */
  B_RotationMatrix_from_EulerAn_T sf_RotationMatrix_from_EulerAng;/* '<S15>/RotationMatrix_from_EulerAngles_yzx' */
  B_EulerAngles_zyx_from_Rotati_T sf_EulerAngles_zyx_from_Rotatio;/* '<S14>/EulerAngles_zyx_from_RotationMatrix' */
  B_RotationMatrix_from_EulerAn_T sf_RotationMatrix_from_EulerA_h;/* '<S11>/RotationMatrix_from_EulerAngles_yzx' */
  B_EulerAngles_zyx_from_Rotati_T sf_EulerAngles_zyx_from_Rotat_j;/* '<S10>/EulerAngles_zyx_from_RotationMatrix' */
} B_mission_server_leader_follo_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T idx;                          /* '<S6>/Waypoint Scheduler' */
  real_T start_stop_prev;              /* '<S1>/Logic Chart' */
  real_T start_stop_start;             /* '<S1>/Logic Chart' */
  t_optitrack_properties OptiTrackTrackables_Optitrack;/* '<S2>/OptiTrack Trackables' */
  t_uint64 ToHostFile_PointsWritten;   /* '<S3>/To Host File' */
  t_pstream StreamServer_Stream;       /* '<S4>/Stream Server' */
  t_pstream StreamServer_Stream_e;     /* '<S5>/Stream Server' */
  void *ToHostFile_PWORK;              /* '<S3>/To Host File' */
  int32_T sfEvent;                     /* '<S1>/Logic Chart' */
  uint32_T ToHostFile_SamplesCount;    /* '<S3>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<S3>/To Host File' */
  uint8_T is_active_c4_mission_server_lea;/* '<S1>/Logic Chart' */
  uint8_T is_c4_mission_server_leader_fol;/* '<S1>/Logic Chart' */
  boolean_T isStable;                  /* '<S1>/Logic Chart' */
} DW_mission_server_leader_foll_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: OptiTrackTrackables_R
   * Referenced by: '<S2>/OptiTrack Trackables'
   */
  uint32_T OptiTrackTrackables_R[2];
} ConstP_mission_server_leader__T;

/* Parameters (auto storage) */
struct P_mission_server_leader_follo_T_ {
  int8_T ShowMessageonHost_message_icon;/* Mask Parameter: ShowMessageonHost_message_icon
                                         * Referenced by: '<S6>/Show Message on Host'
                                         */
  real_T RotateBasisfromUVSOrientationto[9];/* Expression: [0 -1 0;0 0 1;-1 0 0]
                                             * Referenced by: '<S9>/Rotate Basis from UVS Orientation to Global Frame'
                                             */
  real_T ConvertOptitrackorientationfram[3];/* Expression: [1;-1;-1]
                                             * Referenced by: '<S9>/Convert Optitrack orientation frame to Right-Hand Convention'
                                             */
  real_T DefaultDummy_Value;           /* Expression: 0
                                        * Referenced by: '<S9>/Default Dummy'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T ConvertOptitrackframetoRightHan[3];/* Expression: [-1;1;1]
                                             * Referenced by: '<S9>/Convert Optitrack frame to Right-Hand Convention'
                                             */
  real_T ConvertOptitrackframetoRightH_j[3];/* Expression: [-1;1;1]
                                             * Referenced by: '<S8>/Convert Optitrack frame to Right-Hand Convention'
                                             */
  real_T ToggleHigh_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Toggle High'
                                        */
  real_T ToggleLow_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Toggle Low'
                                        */
  real_T DummyData_Value;              /* Expression: 0
                                        * Referenced by: '<S20>/Dummy Data'
                                        */
  real_T Defaultxm_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Default x (m)'
                                        */
  real_T Waypointsxm_Value[5];         /* Expression: [1 -1 -1 1 1]
                                        * Referenced by: '<Root>/Waypoints - x (m)'
                                        */
  real_T Waypointszm_Value[5];         /* Expression: [1 1 -1 -1 1]
                                        * Referenced by: '<Root>/Waypoints - z (m)'
                                        */
  real_T Defaultzm_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Default z (m)'
                                        */
  real_T RotateBasisfromUVSOrientation_m[9];/* Expression: [0 -1 0;0 0 1;-1 0 0]
                                             * Referenced by: '<S8>/Rotate Basis from UVS Orientation to Global Frame'
                                             */
  real_T ConvertOptitrackorientationfr_h[3];/* Expression: [1;-1;-1]
                                             * Referenced by: '<S8>/Convert Optitrack orientation frame to Right-Hand Convention'
                                             */
  real_T DefaultDummy_Value_f;         /* Expression: 0
                                        * Referenced by: '<S8>/Default Dummy'
                                        */
  real_T DummyData3_Value[3];          /* Expression: [0 0 0]
                                        * Referenced by: '<S18>/Dummy Data [3]'
                                        */
  real_T DummyData_Value_n;            /* Expression: 0
                                        * Referenced by: '<S18>/Dummy Data'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */
  real_T Enable_Value_b;               /* Expression: 1
                                        * Referenced by: '<S5>/Enable'
                                        */
  int32_T StreamServer_SndPriority;    /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  int32_T StreamServer_RcvPriority;    /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  int32_T StreamServer_SndPriority_n;  /* Computed Parameter: StreamServer_SndPriority_n
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  int32_T StreamServer_RcvPriority_n;  /* Computed Parameter: StreamServer_RcvPriority_n
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  uint32_T ToHostFile_Decimation;      /* Computed Parameter: ToHostFile_Decimation
                                        * Referenced by: '<S3>/To Host File'
                                        */
  uint32_T StreamServer_SndSize;       /* Computed Parameter: StreamServer_SndSize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  uint32_T StreamServer_RcvSize;       /* Computed Parameter: StreamServer_RcvSize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  uint32_T StreamServer_SndFIFO;       /* Computed Parameter: StreamServer_SndFIFO
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  uint32_T StreamServer_RcvFIFO;       /* Computed Parameter: StreamServer_RcvFIFO
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  uint32_T StreamServer_SndSize_a;     /* Computed Parameter: StreamServer_SndSize_a
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  uint32_T StreamServer_RcvSize_f;     /* Computed Parameter: StreamServer_RcvSize_f
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  uint32_T StreamServer_SndFIFO_m;     /* Computed Parameter: StreamServer_SndFIFO_m
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  uint32_T StreamServer_RcvFIFO_i;     /* Computed Parameter: StreamServer_RcvFIFO_i
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  int8_T StreamServer_Optimize;        /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  int8_T StreamServer_Implementation;  /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  int8_T StreamServer_Optimize_d;      /* Computed Parameter: StreamServer_Optimize_d
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  int8_T StreamServer_Implementation_p;/* Computed Parameter: StreamServer_Implementation_p
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<S6>/Manual Switch2'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;/* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<S6>/Manual Switch3'
                                        */
  uint8_T ToHostFile_file_name[38];    /* Expression: file_name_argument
                                        * Referenced by: '<S3>/To Host File'
                                        */
  uint8_T ToHostFile_VarName[13];      /* Expression: variable_name_argument
                                        * Referenced by: '<S3>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat;       /* Computed Parameter: ToHostFile_FileFormat
                                        * Referenced by: '<S3>/To Host File'
                                        */
  uint8_T StreamServer_URI[24];        /* Expression: uri_argument
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  uint8_T StreamServer_Endian;         /* Computed Parameter: StreamServer_Endian
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  uint8_T StreamServer_URI_a[24];      /* Expression: uri_argument
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  uint8_T StreamServer_Endian_e;       /* Computed Parameter: StreamServer_Endian_e
                                        * Referenced by: '<S5>/Stream Server'
                                        */
  boolean_T StreamServer_Active;       /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  boolean_T StreamServer_Active_p;     /* Computed Parameter: StreamServer_Active_p
                                        * Referenced by: '<S5>/Stream Server'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_mission_server_leader_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_mission_server_leader_follo_T mission_server_leader_followe_P;

/* Block signals (auto storage) */
extern B_mission_server_leader_follo_T mission_server_leader_followe_B;

/* Block states (auto storage) */
extern DW_mission_server_leader_foll_T mission_server_leader_follow_DW;

/* Constant parameters (auto storage) */
extern const ConstP_mission_server_leader__T mission_server_leader_fo_ConstP;

/* Model entry point functions */
extern void mission_server_leader_follower_qbot2_qbot2_initialize(void);
extern void mission_server_leader_follower_qbot2_qbot2_step(void);
extern void mission_server_leader_follower_qbot2_qbot2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mission_server_leade_T *const mission_server_leader_follow_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mission_server_leader_follower_qbot2_qbot2'
 * '<S1>'   : 'mission_server_leader_follower_qbot2_qbot2/Logic Subsystem'
 * '<S2>'   : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements'
 * '<S3>'   : 'mission_server_leader_follower_qbot2_qbot2/SAVE DATA (Black Box)'
 * '<S4>'   : 'mission_server_leader_follower_qbot2_qbot2/Serve Data For Follower'
 * '<S5>'   : 'mission_server_leader_follower_qbot2_qbot2/Serve Data For Leader'
 * '<S6>'   : 'mission_server_leader_follower_qbot2_qbot2/Trajectory Generation'
 * '<S7>'   : 'mission_server_leader_follower_qbot2_qbot2/Logic Subsystem/Logic Chart'
 * '<S8>'   : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 '
 * '<S9>'   : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 2'
 * '<S10>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /EulerAngles_ZYX_from_RotationMatrix'
 * '<S11>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /RotationMatrix_from_EulerAngles_YZX'
 * '<S12>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /EulerAngles_ZYX_from_RotationMatrix/EulerAngles_zyx_from_RotationMatrix'
 * '<S13>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /RotationMatrix_from_EulerAngles_YZX/RotationMatrix_from_EulerAngles_yzx'
 * '<S14>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 2/EulerAngles_ZYX_from_RotationMatrix'
 * '<S15>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 2/RotationMatrix_from_EulerAngles_YZX'
 * '<S16>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 2/EulerAngles_ZYX_from_RotationMatrix/EulerAngles_zyx_from_RotationMatrix'
 * '<S17>'  : 'mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 2/RotationMatrix_from_EulerAngles_YZX/RotationMatrix_from_EulerAngles_yzx'
 * '<S18>'  : 'mission_server_leader_follower_qbot2_qbot2/SAVE DATA (Black Box)/Follower Data Signal 21 - 30'
 * '<S19>'  : 'mission_server_leader_follower_qbot2_qbot2/SAVE DATA (Black Box)/Leader Data Signal 11 - 20'
 * '<S20>'  : 'mission_server_leader_follower_qbot2_qbot2/SAVE DATA (Black Box)/System Status Signal 1 - 10'
 * '<S21>'  : 'mission_server_leader_follower_qbot2_qbot2/Trajectory Generation/Waypoint Scheduler'
 */
#endif                                 /* RTW_HEADER_mission_server_leader_follower_qbot2_qbot2_h_ */
