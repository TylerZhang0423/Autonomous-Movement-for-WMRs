/*
 * mission_server_waypoint_qball2.h
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
#ifndef RTW_HEADER_mission_server_waypoint_qball2_h_
#define RTW_HEADER_mission_server_waypoint_qball2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef mission_server_waypoint_qball2_COMMON_INCLUDES_
# define mission_server_waypoint_qball2_COMMON_INCLUDES_
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
#endif                                 /* mission_server_waypoint_qball2_COMMON_INCLUDES_ */

#include "mission_server_waypoint_qball2_types.h"

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

#define mission_server_waypoint_qball2_M (mission_server_waypoint_qbal_M)

/* Block signals (auto storage) */
typedef struct {
  real_T OptiTrackTrackables_o1[3];    /* '<S2>/OptiTrack Trackables' */
  real_T OptiTrackTrackables_o2[4];    /* '<S2>/OptiTrack Trackables' */
  real_T OptiTrackTrackables_o3[3];    /* '<S2>/OptiTrack Trackables' */
  real_T ConvertOptitrackframetoRightHan[3];/* '<S7>/Convert Optitrack frame to Right-Hand Convention' */
  real_T Widthx;                       /* '<S5>/Width - x' */
  real_T Constant2[5];                 /* '<Root>/Constant2' */
  real_T Constant3[5];                 /* '<Root>/Constant3' */
  real_T ManualSwitch1;                /* '<Root>/Manual Switch1' */
  real_T DataTypeConversion;           /* '<S2>/Data Type Conversion' */
  real_T DummyData;                    /* '<S13>/Dummy Data' */
  real_T DummyData31[3];               /* '<S12>/Dummy Data [3]1' */
  real_T DummyData32[3];               /* '<S12>/Dummy Data [3]2' */
  real_T DummyData3[3];                /* '<S12>/Dummy Data [3]' */
  real_T DummyData_i;                  /* '<S12>/Dummy Data' */
  real_T Widthz;                       /* '<S5>/Width - z' */
  real_T Sqrt;                         /* '<S17>/Sqrt' */
  real_T idx;                          /* '<S5>/Chart - Scheduler Logic' */
  real_T done;                         /* '<S5>/Chart - Scheduler Logic' */
  real_T x_ref;                        /* '<S5>/Chart - Scheduler Logic' */
  real_T z_ref;                        /* '<S5>/Chart - Scheduler Logic' */
  real_T last_waypoint;                /* '<S5>/Chart - Scheduler Logic' */
  real_T Angles[3];                    /* '<S8>/EulerAngles_zyx_from_RotationMatrix' */
  real_T qball_takeoff;                /* '<S1>/Logic Chart' */
  real_T x_quad_ref;                   /* '<S1>/Logic Chart' */
  real_T z_quad_ref;                   /* '<S1>/Logic Chart' */
  int32_T StreamServer_o2;             /* '<S4>/Stream Server' */
  int8_T tick;                         /* '<S5>/Chart - Scheduler Logic' */
  uint8_T StreamServer_o1;             /* '<S4>/Stream Server' */
  boolean_T OptiTrackTrackables_o4;    /* '<S2>/OptiTrack Trackables' */
  boolean_T Memory;                    /* '<S5>/Memory' */
  boolean_T StreamServer_o3;           /* '<S4>/Stream Server' */
} B_mission_server_waypoint_qba_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T QBall2Trajectory_XBuffer[1000];/* '<Root>/QBall 2 Trajectory' */
  real_T QBall2Trajectory_YBuffer[1000];/* '<Root>/QBall 2 Trajectory' */
  real_T start_stop_prev;              /* '<S1>/Logic Chart' */
  real_T start_stop_start;             /* '<S1>/Logic Chart' */
  t_optitrack_properties OptiTrackTrackables_Optitrack;/* '<S2>/OptiTrack Trackables' */
  t_uint64 ToHostFile_PointsWritten;   /* '<S3>/To Host File' */
  t_pstream StreamServer_Stream;       /* '<S4>/Stream Server' */
  struct {
    void *LoggedData;
  } OptiTrackxyz_PWORK;                /* '<Root>/OptiTrack (x, y, z)' */

  void *ToHostFile_PWORK;              /* '<S3>/To Host File' */
  int32_T sfEvent;                     /* '<S5>/Chart - Scheduler Logic' */
  int32_T sfEvent_g;                   /* '<S1>/Logic Chart' */
  uint32_T ToHostFile_SamplesCount;    /* '<S3>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<S3>/To Host File' */
  uint32_T presentTicks;               /* '<S5>/Chart - Scheduler Logic' */
  uint32_T elapsedTicks;               /* '<S5>/Chart - Scheduler Logic' */
  uint32_T previousTicks;              /* '<S5>/Chart - Scheduler Logic' */
  int_T QBall2Trajectory_IWORK[2];     /* '<Root>/QBall 2 Trajectory' */
  uint16_T temporalCounter_i1;         /* '<S5>/Chart - Scheduler Logic' */
  int8_T ChartSchedulerLogic_SubsysRanBC;/* '<S5>/Chart - Scheduler Logic' */
  uint8_T is_active_c3_mission_server_way;/* '<S5>/Chart - Scheduler Logic' */
  uint8_T is_c3_mission_server_waypoint_q;/* '<S5>/Chart - Scheduler Logic' */
  uint8_T is_active_c1_mission_server_way;/* '<S1>/Logic Chart' */
  uint8_T is_c1_mission_server_waypoint_q;/* '<S1>/Logic Chart' */
  boolean_T Memory_PreviousInput;      /* '<S5>/Memory' */
  boolean_T QBall2Trajectory_IsFull;   /* '<Root>/QBall 2 Trajectory' */
  boolean_T isStable;                  /* '<S5>/Chart - Scheduler Logic' */
  boolean_T isStable_e;                /* '<S1>/Logic Chart' */
} DW_mission_server_waypoint_qb_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: OptiTrackTrackables_RBIDs
   * Referenced by: '<S2>/OptiTrack Trackables'
   */
  uint32_T OptiTrackTrackables_RBIDs;
} ConstP_mission_server_waypoin_T;

/* Parameters (auto storage) */
struct P_mission_server_waypoint_qba_T_ {
  real_T QBall2Trajectory_maximum_x;   /* Mask Parameter: QBall2Trajectory_maximum_x
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  real_T QBall2Trajectory_maximum_y;   /* Mask Parameter: QBall2Trajectory_maximum_y
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  real_T QBall2Trajectory_minimum_x;   /* Mask Parameter: QBall2Trajectory_minimum_x
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  real_T QBall2Trajectory_minimum_y;   /* Mask Parameter: QBall2Trajectory_minimum_y
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  int32_T QBall2Trajectory_update_rate;/* Mask Parameter: QBall2Trajectory_update_rate
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  int8_T ShowMessageonHost_message_icon;/* Mask Parameter: ShowMessageonHost_message_icon
                                         * Referenced by: '<S5>/Show Message on Host'
                                         */
  int8_T QBall2Trajectory_trace_mode;  /* Mask Parameter: QBall2Trajectory_trace_mode
                                        * Referenced by: '<Root>/QBall 2 Trajectory'
                                        */
  real_T ConvertOptitrackframetoRightHan[3];/* Expression: [-1;1;1]
                                             * Referenced by: '<S7>/Convert Optitrack frame to Right-Hand Convention'
                                             */
  real_T Constant2_Value[5];           /* Expression: [1 -1 -1 1 0]*0.5
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value[5];           /* Expression: [1 1 -1 -1 0]*0.5
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T ToggleHigh_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Toggle High'
                                        */
  real_T ToggleLow_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Toggle Low'
                                        */
  real_T DummyData_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Dummy Data'
                                        */
  real_T RotateBasisfromUVSOrientationto[9];/* Expression: [0 -1 0;0 0 1;-1 0 0]
                                             * Referenced by: '<S7>/Rotate Basis from UVS Orientation to Global Frame'
                                             */
  real_T ConvertOptitrackorientationfram[3];/* Expression: [1;-1;-1]
                                             * Referenced by: '<S7>/Convert Optitrack orientation frame to Right-Hand Convention'
                                             */
  real_T DefaultDummy_Value;           /* Expression: 0
                                        * Referenced by: '<S7>/Default Dummy'
                                        */
  real_T DummyData31_Value[3];         /* Expression: [0 0 0]
                                        * Referenced by: '<S12>/Dummy Data [3]1'
                                        */
  real_T DummyData32_Value[3];         /* Expression: [0 0 0]
                                        * Referenced by: '<S12>/Dummy Data [3]2'
                                        */
  real_T DummyData3_Value[3];          /* Expression: [0 0 0]
                                        * Referenced by: '<S12>/Dummy Data [3]'
                                        */
  real_T DummyData_Value_n;            /* Expression: 0
                                        * Referenced by: '<S12>/Dummy Data'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */
  real_T TrackingToleranceLeaderm_Value;/* Expression: 0.15
                                         * Referenced by: '<S5>/Tracking Tolerance - Leader (m)'
                                         */
  int32_T StreamServer_SndPriority;    /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  int32_T StreamServer_RcvPriority;    /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S4>/Stream Server'
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
  int8_T StreamServer_Optimize;        /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  int8_T StreamServer_Implementation;  /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
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
  boolean_T Memory_X0;                 /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S5>/Memory'
                                        */
  boolean_T StreamServer_Active;       /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S4>/Stream Server'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_mission_server_waypoi_T {
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
extern P_mission_server_waypoint_qba_T mission_server_waypoint_qball_P;

/* Block signals (auto storage) */
extern B_mission_server_waypoint_qba_T mission_server_waypoint_qball_B;

/* Block states (auto storage) */
extern DW_mission_server_waypoint_qb_T mission_server_waypoint_qbal_DW;

/* Constant parameters (auto storage) */
extern const ConstP_mission_server_waypoin_T mission_server_waypoint__ConstP;

/* Model entry point functions */
extern void mission_server_waypoint_qball2_initialize(void);
extern void mission_server_waypoint_qball2_step(void);
extern void mission_server_waypoint_qball2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mission_server_waypo_T *const mission_server_waypoint_qbal_M;

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
 * '<Root>' : 'mission_server_waypoint_qball2'
 * '<S1>'   : 'mission_server_waypoint_qball2/Logic Subsystem'
 * '<S2>'   : 'mission_server_waypoint_qball2/OptiTrack Measurements'
 * '<S3>'   : 'mission_server_waypoint_qball2/SAVE DATA (Black Box)'
 * '<S4>'   : 'mission_server_waypoint_qball2/Serve Data for Qball 2'
 * '<S5>'   : 'mission_server_waypoint_qball2/Waypoint Scheduler'
 * '<S6>'   : 'mission_server_waypoint_qball2/Logic Subsystem/Logic Chart'
 * '<S7>'   : 'mission_server_waypoint_qball2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 '
 * '<S8>'   : 'mission_server_waypoint_qball2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /EulerAngles_ZYX_from_RotationMatrix'
 * '<S9>'   : 'mission_server_waypoint_qball2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /RotationMatrix_from_EulerAngles_YZX'
 * '<S10>'  : 'mission_server_waypoint_qball2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /EulerAngles_ZYX_from_RotationMatrix/EulerAngles_zyx_from_RotationMatrix'
 * '<S11>'  : 'mission_server_waypoint_qball2/OptiTrack Measurements/Compute OptiTrack POSE - Trackable 1 /RotationMatrix_from_EulerAngles_YZX/RotationMatrix_from_EulerAngles_yzx'
 * '<S12>'  : 'mission_server_waypoint_qball2/SAVE DATA (Black Box)/Other Data Signal 21 - 30'
 * '<S13>'  : 'mission_server_waypoint_qball2/SAVE DATA (Black Box)/System Status Signal 1 - 10'
 * '<S14>'  : 'mission_server_waypoint_qball2/SAVE DATA (Black Box)/Vehicle Data Signal 11 - 20'
 * '<S15>'  : 'mission_server_waypoint_qball2/Waypoint Scheduler/Chart - Scheduler Logic'
 * '<S16>'  : 'mission_server_waypoint_qball2/Waypoint Scheduler/Check for Waypoint Arrival'
 * '<S17>'  : 'mission_server_waypoint_qball2/Waypoint Scheduler/Check for Waypoint Arrival/Error - Leader'
 */
#endif                                 /* RTW_HEADER_mission_server_waypoint_qball2_h_ */
