/*
 * leader_qball2_mytest.h
 *
 * Code generation for model "leader_qball2_mytest".
 *
 * Model version              : 1.901
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Aug 31 23:14:23 2015
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_leader_qball2_mytest_h_
#define RTW_HEADER_leader_qball2_mytest_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef leader_qball2_mytest_COMMON_INCLUDES_
# define leader_qball2_mytest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "math.h"
#include "quanser_sigmoid.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_time.h"
#include "quanser_string.h"
#include "quanser_memory.h"
#include "stream_client_block.h"
#include "quanser_types.h"
#include "stream_server_block.h"
#include "quanser_extern.h"
#endif                                 /* leader_qball2_mytest_COMMON_INCLUDES_ */

#include "leader_qball2_mytest_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals for system '<S31>/Enabled Moving Average' */
typedef struct {
  real_T div[3];                       /* '<S34>/div' */
} B_EnabledMovingAverage_leader_T;

/* Block states (auto storage) for system '<S31>/Enabled Moving Average' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S38>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE[3];          /* '<S34>/Sum( k=1,n-1, x(k) )' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S31>/Enabled Moving Average' */
  boolean_T EnabledMovingAverage_MODE; /* '<S31>/Enabled Moving Average' */
} DW_EnabledMovingAverage_leade_T;

/* Block signals for system '<S61>/Embedded MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S61>/Embedded MATLAB Function' */
} B_EmbeddedMATLABFunction_lead_T;

/* Block signals for system '<S66>/Enabled Subsystem1' */
typedef struct {
  boolean_T RelationalOperator;        /* '<S77>/Relational Operator' */
} B_EnabledSubsystem1_leader_qb_T;

/* Block states (auto storage) for system '<S66>/Enabled Subsystem1' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S77>/Discrete-Time Integrator' */
  int8_T EnabledSubsystem1_SubsysRanBC;/* '<S66>/Enabled Subsystem1' */
  boolean_T EnabledSubsystem1_MODE;    /* '<S66>/Enabled Subsystem1' */
} DW_EnabledSubsystem1_leader_q_T;

/* Block signals (auto storage) */
typedef struct {
  real_T SampleTime;                   /* '<S3>/Sample Time' */
  real_T Saturation[4];                /* '<S3>/Saturation' */
  real_T HILReadWrite1_o1;             /* '<S3>/HIL Read Write1' */
  real_T HILReadWrite1_o2[7];          /* '<S3>/HIL Read Write1' */
  real_T StreamClient_o3[10];          /* '<S4>/Stream Client' */
  real_T wn;                           /* '<S48>/wn' */
  real_T Product1;                     /* '<S48>/Product1' */
  real_T Constant3;                    /* '<S29>/Constant3' */
  real_T HeightEstimateBiasEstimateRefer;/* '<S29>/Height Estimate Bias (Estimate Reference at Centre of QBall 2) ' */
  real_T OptiTrackHeightMeasurementBias;/* '<S29>/OptiTrack Height Measurement Bias' */
  real_T RateTransition;               /* '<S55>/Rate Transition' */
  real_T Derivative;                   /* '<S55>/Derivative' */
  real_T RateTransition1;              /* '<S54>/Rate Transition1' */
  real_T RateTransition_c;             /* '<S54>/Rate Transition' */
  real_T Gain;                         /* '<S54>/Gain' */
  real_T RateTransition3;              /* '<S54>/Rate Transition3' */
  real_T s;                            /* '<S54>/s' */
  real_T BatteryTopOrBottom;           /* '<S23>/Battery Top Or Bottom' */
  real_T SwitchBatteryConfigAcceleromter[3];/* '<S23>/Switch Battery Config - Acceleromter (Top or Bottom)' */
  real_T x0;                           /* '<S32>/x0' */
  real_T Integrator1[3];               /* '<S32>/Integrator1' */
  real_T Calibrationtimes;             /* '<S30>/Calibration time (s)' */
  real_T Sum[3];                       /* '<S30>/Sum' */
  real_T Constant;                     /* '<S29>/Constant' */
  real_T Constant1;                    /* '<S29>/Constant1' */
  real_T Product;                      /* '<S51>/Product' */
  real_T wn_i;                         /* '<S49>/wn' */
  real_T Product1_o;                   /* '<S49>/Product1' */
  real_T wn_g;                         /* '<S50>/wn' */
  real_T Product1_k;                   /* '<S50>/Product1' */
  real_T Gain5;                        /* '<S29>/Gain5' */
  real_T Gain4;                        /* '<S29>/Gain4' */
  real_T x0_p;                         /* '<S47>/x0' */
  real_T Constant2;                    /* '<S29>/Constant2' */
  real_T Gain8;                        /* '<S29>/Gain8' */
  real_T Gain1;                        /* '<S42>/Gain1' */
  real_T Gain7;                        /* '<S42>/Gain7' */
  real_T Gain2;                        /* '<S42>/Gain2' */
  real_T Gain6;                        /* '<S42>/Gain6' */
  real_T Constant_d;                   /* '<S47>/Constant' */
  real_T wn_a;                         /* '<S47>/wn' */
  real_T InverseModulus;               /* '<S4>/Inverse Modulus' */
  real_T zt;                           /* '<S47>/zt' */
  real_T Product_f;                    /* '<S47>/Product' */
  real_T Product1_a;                   /* '<S47>/Product1' */
  real_T Constant_e;                   /* '<S48>/Constant' */
  real_T x0_h;                         /* '<S48>/x0' */
  real_T zt_i;                         /* '<S48>/zt' */
  real_T Product_l;                    /* '<S48>/Product' */
  real_T Constant_p;                   /* '<S49>/Constant' */
  real_T x0_j;                         /* '<S49>/x0' */
  real_T zt_n;                         /* '<S49>/zt' */
  real_T Product_d;                    /* '<S49>/Product' */
  real_T Constant_a;                   /* '<S50>/Constant' */
  real_T x0_d;                         /* '<S50>/x0' */
  real_T zt_nn;                        /* '<S50>/zt' */
  real_T Product_g;                    /* '<S50>/Product' */
  real_T RateTransition4;              /* '<S54>/Rate Transition4' */
  real_T Accelerometeroffsetsmanuallycal;/* '<S23>/Accelerometer offsets manually calibrated2' */
  real_T Gain1_m;                      /* '<S26>/Gain1' */
  real_T Gain_e;                       /* '<S26>/Gain' */
  real_T Constant_o;                   /* '<S32>/Constant' */
  real_T wn_n;                         /* '<S32>/wn' */
  real_T zt_j;                         /* '<S32>/zt' */
  real_T Product_lj[3];                /* '<S32>/Product' */
  real_T Product1_e[3];                /* '<S32>/Product1' */
  real_T Calibrationtimes_j;           /* '<S27>/Calibration time (s)' */
  real_T Sum_m[3];                     /* '<S27>/Sum' */
  real_T Divide;                       /* '<S23>/Divide' */
  real_T Fcn;                          /* '<S14>/Fcn' */
  real_T Integrator;                   /* '<S14>/Integrator' */
  real_T HPF;                          /* '<S14>/HPF' */
  real_T Fcn_a;                        /* '<S15>/Fcn' */
  real_T Integrator_f;                 /* '<S15>/Integrator' */
  real_T ManualSwitch;                 /* '<S15>/Manual Switch' */
  real_T Bias;                         /* '<S13>/Bias' */
  real_T Sum4;                         /* '<S13>/Sum4' */
  real_T Constant_a0;                  /* '<S70>/Constant' */
  real_T wn_p;                         /* '<S139>/wn' */
  real_T Product1_n;                   /* '<S139>/Product1' */
  real_T SwitchKd;                     /* '<S131>/Switch - Kd' */
  real_T vmaxtakeoff;                  /* '<S135>/vmax takeoff' */
  real_T amaxtakeoff;                  /* '<S135>/amax takeoff' */
  real_T Constant_m;                   /* '<S136>/Constant' */
  real_T Constant_es;                  /* '<S129>/Constant' */
  real_T CLOSEDLOOPON;                 /* '<S5>/CLOSED-LOOP ON' */
  real_T ManualSwitch2;                /* '<S5>/Manual Switch2' */
  real_T SliderGain;                   /* '<S92>/Slider Gain' */
  real_T RateLimiter3;                 /* '<S7>/Rate Limiter3' */
  real_T Constant_g;                   /* '<S116>/Constant' */
  real_T Constant_j;                   /* '<S137>/Constant' */
  real_T vmaxflight;                   /* '<S135>/vmax flight' */
  real_T amaxflight;                   /* '<S135>/amax flight' */
  real_T ContinuousSigmoid_o1;         /* '<S130>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o2;         /* '<S130>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o3;         /* '<S130>/Continuous Sigmoid' */
  real_T ContinuousSigmoid_o4;         /* '<S130>/Continuous Sigmoid' */
  real_T SwitchKp;                     /* '<S131>/Switch - Kp' */
  real_T Memory;                       /* '<S138>/Memory' */
  real_T Integrator_a;                 /* '<S131>/Integrator' */
  real_T Constant1_l;                  /* '<S131>/Constant1' */
  real_T ThrottleTrim;                 /* '<S7>/Throttle Trim' */
  real_T Constant_ov;                  /* '<S131>/Constant' */
  real_T heightcommand1;               /* '<S117>/height command1' */
  real_T heightcommand2;               /* '<S117>/height command2' */
  real_T Switch;                       /* '<S11>/Switch' */
  real_T Constant1_o;                  /* '<S122>/Constant1' */
  real_T landthrottletarget;           /* '<S122>/land throttle target' */
  real_T SigmoidPath_o1;               /* '<S124>/Sigmoid Path' */
  real_T SigmoidPath_o2;               /* '<S124>/Sigmoid Path' */
  real_T SigmoidPath_o3;               /* '<S124>/Sigmoid Path' */
  real_T SigmoidPath_o4;               /* '<S124>/Sigmoid Path' */
  real_T ManualSwitch_a;               /* '<S123>/Manual Switch' */
  real_T Switch_e;                     /* '<S118>/Switch' */
  real_T Constant_h;                   /* '<S141>/Constant' */
  real_T Sum5;                         /* '<S13>/Sum5' */
  real_T ManualSwitch4;                /* '<S5>/Manual Switch4' */
  real_T SliderGain_o;                 /* '<S143>/Slider Gain' */
  real_T Saturation_c;                 /* '<S13>/Saturation' */
  real_T Constant_m3;                  /* '<S17>/Constant' */
  real_T Constant_ef;                  /* '<S18>/Constant' */
  real_T SwitchKd_k;                   /* '<S81>/Switch - Kd' */
  real_T Memory_o;                     /* '<S85>/Memory' */
  real_T Switch_p;                     /* '<S83>/Switch' */
  real_T ManualSwitch_f;               /* '<S6>/Manual Switch' */
  real_T ManualSwitch_b;               /* '<S81>/Manual Switch' */
  real_T SwitchKp_b;                   /* '<S81>/Switch - Kp' */
  real_T Constant_em;                  /* '<S91>/Constant' */
  real_T Integrator1_l;                /* '<S81>/Integrator1' */
  real_T Pitch_Trim;                   /* '<S7>/Pitch_Trim' */
  real_T Sum_b;                        /* '<S81>/Sum' */
  real_T Sum_n;                        /* '<S2>/Sum' */
  real_T Sum1;                         /* '<S2>/Sum1' */
  real_T SwitchKd_m;                   /* '<S97>/Switch - Kd' */
  real_T Memory_f;                     /* '<S103>/Memory' */
  real_T Switch_f;                     /* '<S101>/Switch' */
  real_T ManualSwitch_j;               /* '<S8>/Manual Switch' */
  real_T SwitchKp_f;                   /* '<S97>/Switch - Kp' */
  real_T Constant_n;                   /* '<S99>/Constant' */
  real_T Integrator1_n;                /* '<S97>/Integrator1' */
  real_T roll_trim;                    /* '<S7>/roll_trim' */
  real_T Sum_ng;                       /* '<S97>/Sum' */
  real_T Sum2;                         /* '<S2>/Sum2' */
  real_T Sum3;                         /* '<S2>/Sum3' */
  real_T Constant_gy;                  /* '<S21>/Constant' */
  real_T Product2[4];                  /* '<S16>/Product2' */
  real_T Gain_d[2];                    /* '<S4>/Gain' */
  real_T wn_h;                         /* '<S89>/wn' */
  real_T Product1_ey;                  /* '<S89>/Product1' */
  real_T SliderGain_e;                 /* '<S96>/Slider Gain' */
  real_T RateLimiter2;                 /* '<S7>/Rate Limiter2' */
  real_T Product_c;                    /* '<S82>/Product' */
  real_T wn_a5;                        /* '<S107>/wn' */
  real_T Product1_d;                   /* '<S107>/Product1' */
  real_T SwitchKd_o;                   /* '<S104>/Switch - Kd' */
  real_T SliderGain_p;                 /* '<S94>/Slider Gain' */
  real_T RateLimiter1;                 /* '<S7>/Rate Limiter1' */
  real_T SwitchKp_c;                   /* '<S104>/Switch - Kp' */
  real_T Constant_emr;                 /* '<S89>/Constant' */
  real_T x0_dh;                        /* '<S89>/x0' */
  real_T zt_je;                        /* '<S89>/zt' */
  real_T Product_b;                    /* '<S89>/Product' */
  real_T SwitchKi;                     /* '<S86>/Switch - Ki' */
  real_T SwitchKi_h;                   /* '<S81>/Switch - Ki' */
  real_T Gain1_a[3];                   /* '<S6>/Gain1' */
  real_T Gain4_g[4];                   /* '<S8>/Gain4' */
  real_T SwitchKi_i;                   /* '<S97>/Switch - Ki' */
  real_T Product_n;                    /* '<S100>/Product' */
  real_T Constant_c;                   /* '<S107>/Constant' */
  real_T x0_i;                         /* '<S107>/x0' */
  real_T zt_g;                         /* '<S107>/zt' */
  real_T Product_j;                    /* '<S107>/Product' */
  real_T SwitchKi_b;                   /* '<S104>/Switch - Ki' */
  real_T Gain1_k[4];                   /* '<S8>/Gain1' */
  real_T DataTypeConversion;           /* '<S112>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S112>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<S112>/Data Type Conversion2' */
  real_T DataTypeConversion3;          /* '<S112>/Data Type Conversion3' */
  real_T Constant_gl;                  /* '<S139>/Constant' */
  real_T x0_g;                         /* '<S139>/x0' */
  real_T zt_m;                         /* '<S139>/zt' */
  real_T Product_lu;                   /* '<S139>/Product' */
  real_T SwitchKi_n;                   /* '<S131>/Switch - Ki' */
  real_T SwitchKi_ih;                  /* '<S13>/Switch - Ki' */
  real_T land;                         /* '<S131>/User-controller landing state machine' */
  real_T In1;                          /* '<S134>/In1' */
  real_T Constant_hf;                  /* '<S133>/Constant' */
  real_T SigmoidCompute_o1[11];        /* '<S125>/Sigmoid Compute' */
  real_T enable;                       /* '<S116>/MATLAB Function' */
  real_T Constant_k;                   /* '<S108>/Constant' */
  real_T adj_roll_cmd;                 /* '<S103>/adjust_roll_command' */
  real_T Constant_cm;                  /* '<S90>/Constant' */
  real_T adj_pitch_cmd;                /* '<S85>/adjust_pitch_command' */
  real_T Constant_om;                  /* '<S79>/Constant' */
  real_T Constant_mq;                  /* '<S78>/Constant' */
  real_T div[3];                       /* '<S57>/div' */
  real_T In1_g;                        /* '<S56>/In1' */
  real_T angle;                        /* '<S29>/Kalman Filter - Yaw' */
  real_T angle_m;                      /* '<S29>/Kalman Filter - Roll' */
  real_T angle_f;                      /* '<S29>/Kalman Filter - Pitch' */
  real_T height;                       /* '<S29>/Kalman Filter - Height' */
  real_T y;                            /* '<S28>/Embedded MATLAB Function' */
  real_T n;                            /* '<S26>/correct accel mounting' */
  real_T nhat[3];                      /* '<S26>/correct accel mounting' */
  real_T check;                        /* '<S26>/correct accel mounting' */
  real_T acc_body[3];                  /* '<S26>/correct accel mounting' */
  real_T Constant_cd;                  /* '<S19>/Constant' */
  int32_T StreamClient_o2;             /* '<S4>/Stream Client' */
  int32_T StreamServer_o2;             /* '<S10>/Stream Server' */
  int8_T SigmoidCompute_o2;            /* '<S125>/Sigmoid Compute' */
  uint8_T StreamClient_o1;             /* '<S4>/Stream Client' */
  uint8_T Compare;                     /* '<S59>/Compare' */
  uint8_T Compare_k;                   /* '<S21>/Compare' */
  uint8_T Compare_m;                   /* '<S84>/Compare' */
  uint8_T Compare_p;                   /* '<S102>/Compare' */
  uint8_T StreamServer_o1;             /* '<S10>/Stream Server' */
  boolean_T StreamClient_o4;           /* '<S4>/Stream Client' */
  boolean_T RelationalOperator;        /* '<S30>/Relational Operator' */
  boolean_T RelationalOperator_o;      /* '<S27>/Relational Operator' */
  boolean_T Compare_j;                 /* '<S60>/Compare' */
  boolean_T HILWatchdog;               /* '<S3>/HIL Watchdog' */
  boolean_T Compare_pf;                /* '<S71>/Compare' */
  boolean_T LogicalOperator;           /* '<S64>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S66>/Logical Operator5' */
  boolean_T LogicalOperator2;          /* '<S66>/Logical Operator2' */
  boolean_T LogicalOperator2_o;        /* '<S138>/Logical Operator2' */
  boolean_T Compare_i;                 /* '<S127>/Compare' */
  boolean_T LogicalOperator_b;         /* '<S123>/Logical Operator' */
  boolean_T LogicalOperator_a;         /* '<S118>/Logical Operator' */
  boolean_T Compare_h;                 /* '<S141>/Compare' */
  boolean_T LogicalOperator_m;         /* '<S16>/Logical Operator' */
  boolean_T Compare_f;                 /* '<S91>/Compare' */
  boolean_T Compare_n;                 /* '<S99>/Compare' */
  boolean_T LogicalOperator1;          /* '<S20>/Logical Operator1' */
  boolean_T LogicalOperator4;          /* '<S72>/Logical Operator4' */
  boolean_T LogicalOperator1_o;        /* '<S88>/Logical Operator1' */
  boolean_T LogicalOperator1_h;        /* '<S106>/Logical Operator1' */
  boolean_T StreamServer_o3;           /* '<S10>/Stream Server' */
  boolean_T RelationalOperator_og;     /* '<S76>/Relational Operator' */
  boolean_T RelationalOperator_m;      /* '<S22>/Relational Operator' */
  B_EnabledSubsystem1_leader_qb_T EnabledSubsystem1_b;/* '<S123>/Enabled Subsystem1' */
  B_EnabledSubsystem1_leader_qb_T EnabledSubsystem1;/* '<S66>/Enabled Subsystem1' */
  B_EmbeddedMATLABFunction_lead_T sf_EmbeddedMATLABFunction_j4;/* '<S63>/Embedded MATLAB Function' */
  B_EmbeddedMATLABFunction_lead_T sf_EmbeddedMATLABFunction;/* '<S62>/Embedded MATLAB Function' */
  B_EmbeddedMATLABFunction_lead_T sf_EmbeddedMATLABFunction_d;/* '<S61>/Embedded MATLAB Function' */
  B_EnabledMovingAverage_leader_T EnabledMovingAverage_e;/* '<S27>/Enabled Moving Average' */
  B_EnabledMovingAverage_leader_T EnabledMovingAverage_c;/* '<S31>/Enabled Moving Average' */
} B_leader_qball2_mytest_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  t_timeout SampleTime_PreviousTime;   /* '<S3>/Sample Time' */
  real_T UnitDelay_DSTATE;             /* '<S54>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S76>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_o;           /* '<S58>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE[3];          /* '<S57>/Sum( k=1,n-1, x(k) )' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S22>/Discrete-Time Integrator' */
  real_T HILInitialize_OOValues[4];    /* '<S3>/HIL Initialize' */
  real_T Memory_PreviousInput[4];      /* '<S3>/Memory' */
  real_T Memory_PreviousInput_g;       /* '<S62>/Memory' */
  real_T Memory_PreviousInput_b;       /* '<S28>/Memory' */
  real_T RateTransition_Buffer0;       /* '<S55>/Rate Transition' */
  real_T TimeStampA;                   /* '<S55>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S55>/Derivative' */
  real_T TimeStampB;                   /* '<S55>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S55>/Derivative' */
  real_T RateTransition1_Buffer0;      /* '<S54>/Rate Transition1' */
  real_T RateTransition_Buffer0_l;     /* '<S54>/Rate Transition' */
  real_T InverseModulus_PreviousInput; /* '<S4>/Inverse Modulus' */
  real_T InverseModulus_Revolutions;   /* '<S4>/Inverse Modulus' */
  real_T PrevY;                        /* '<S7>/Rate Limiter' */
  real_T PrevY_k;                      /* '<S7>/Rate Limiter3' */
  real_T LastMajorTime;                /* '<S7>/Rate Limiter3' */
  real_T ContinuousSigmoid_Sigmoid[11];/* '<S130>/Continuous Sigmoid' */
  real_T Memory_PreviousInput_p;       /* '<S138>/Memory' */
  real_T SigmoidPath_Path[11];         /* '<S124>/Sigmoid Path' */
  real_T SigmoidPath_NewPath[11];      /* '<S124>/Sigmoid Path' */
  real_T TimeStampA_e;                 /* '<S123>/Derivative' */
  real_T LastUAtTimeA_a;               /* '<S123>/Derivative' */
  real_T TimeStampB_c;                 /* '<S123>/Derivative' */
  real_T LastUAtTimeB_l;               /* '<S123>/Derivative' */
  real_T Memory_PreviousInput_i;       /* '<S85>/Memory' */
  real_T Memory_PreviousInput_j;       /* '<S103>/Memory' */
  real_T Memory_PreviousInput_it;      /* '<S61>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S63>/Memory' */
  real_T PrevY_i;                      /* '<S7>/Rate Limiter2' */
  real_T LastMajorTime_c;              /* '<S7>/Rate Limiter2' */
  real_T PrevY_a;                      /* '<S7>/Rate Limiter1' */
  real_T LastMajorTime_j;              /* '<S7>/Rate Limiter1' */
  real_T state;                        /* '<S131>/User-controller landing state machine' */
  real_T c;                            /* '<S131>/User-controller landing state machine' */
  real_T state_h;                      /* '<S116>/MATLAB Function' */
  real_T counter;                      /* '<S116>/MATLAB Function' */
  real_T P_00;                         /* '<S29>/Kalman Filter - Yaw' */
  real_T P_01;                         /* '<S29>/Kalman Filter - Yaw' */
  real_T P_10;                         /* '<S29>/Kalman Filter - Yaw' */
  real_T P_11;                         /* '<S29>/Kalman Filter - Yaw' */
  real_T x_angle;                      /* '<S29>/Kalman Filter - Yaw' */
  real_T x_bias;                       /* '<S29>/Kalman Filter - Yaw' */
  real_T P_00_g;                       /* '<S29>/Kalman Filter - Roll' */
  real_T P_01_h;                       /* '<S29>/Kalman Filter - Roll' */
  real_T P_10_h;                       /* '<S29>/Kalman Filter - Roll' */
  real_T P_11_n;                       /* '<S29>/Kalman Filter - Roll' */
  real_T x_angle_g;                    /* '<S29>/Kalman Filter - Roll' */
  real_T x_bias_e;                     /* '<S29>/Kalman Filter - Roll' */
  real_T P_00_p;                       /* '<S29>/Kalman Filter - Pitch' */
  real_T P_01_c;                       /* '<S29>/Kalman Filter - Pitch' */
  real_T P_10_m;                       /* '<S29>/Kalman Filter - Pitch' */
  real_T P_11_a;                       /* '<S29>/Kalman Filter - Pitch' */
  real_T x_angle_h;                    /* '<S29>/Kalman Filter - Pitch' */
  real_T x_bias_l;                     /* '<S29>/Kalman Filter - Pitch' */
  real_T P_00_b;                       /* '<S29>/Kalman Filter - Height' */
  real_T P_01_f;                       /* '<S29>/Kalman Filter - Height' */
  real_T P_10_j;                       /* '<S29>/Kalman Filter - Height' */
  real_T P_11_h;                       /* '<S29>/Kalman Filter - Height' */
  real_T x_height;                     /* '<S29>/Kalman Filter - Height' */
  real_T x_bias_h;                     /* '<S29>/Kalman Filter - Height' */
  t_pstream StreamClient_Stream;       /* '<S4>/Stream Client' */
  t_pstream StreamServer_Stream;       /* '<S10>/Stream Server' */
  t_uint64 ToHostFile_PointsWritten;   /* '<S9>/To Host File' */
  t_card HILInitialize_Card;           /* '<S3>/HIL Initialize' */
  struct {
    real_T Time;
    real_T Target;
    real_T PPos;
    real_T PVel;
  } ContinuousSigmoid_RWORK;           /* '<S130>/Continuous Sigmoid' */

  struct {
    real_T Time;
  } SigmoidPath_RWORK;                 /* '<S124>/Sigmoid Path' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK;              /* '<S7>/Transport Delay' */

  void *HILReadWrite1_PWORK;           /* '<S3>/HIL Read Write1' */
  struct {
    void *LoggedData;
  } Battery_PWORK;                     /* '<S3>/Battery' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S29>/Scope1' */

  struct {
    void *LoggedData;
  } height_Kalman_PWORK;               /* '<S29>/height_Kalman' */

  struct {
    void *LoggedData;
  } pitch_Kalman_PWORK;                /* '<S29>/pitch_Kalman' */

  struct {
    void *LoggedData;
  } roll_Kalman_PWORK;                 /* '<S29>/roll_Kalman' */

  struct {
    void *LoggedData;
  } yaw_Kalman_PWORK;                  /* '<S29>/yaw_Kalman' */

  struct {
    void *LoggedData;
  } pitch_acc_PWORK;                   /* '<S42>/pitch_acc' */

  struct {
    void *LoggedData;
  } pitch_acc_asin_PWORK;              /* '<S42>/pitch_acc_asin' */

  struct {
    void *LoggedData;
  } roll_acc_PWORK;                    /* '<S42>/roll_acc' */

  struct {
    void *LoggedData;
  } roll_acc_asin_PWORK;               /* '<S42>/roll_acc_asin' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S54>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_c;                    /* '<S54>/Scope1' */

  struct {
    void *LoggedData;
  } accelerometerxyz_PWORK;            /* '<S23>/accelerometer x, y, z' */

  struct {
    void *LoggedData;
  } gyroscopexyz_PWORK;                /* '<S23>/gyroscope x, y, z' */

  struct {
    void *LoggedData;
  } sonar_PWORK;                       /* '<S23>/sonar' */

  struct {
    void *LoggedData;
  } FilteredAccel_PWORK;               /* '<S26>/Filtered Accel' */

  struct {
    void *LoggedData;
  } NormalizedBiasVector_PWORK;        /* '<S26>/Normalized Bias Vector' */

  struct {
    void *LoggedData;
  } check_PWORK;                       /* '<S26>/check' */

  struct {
    void *LoggedData;
  } accelcalibrated_PWORK;             /* '<S27>/accel calibrated' */

  struct {
    void *LoggedData;
  } accelsoffset_PWORK;                /* '<S27>/accels offset' */

  struct {
    void *LoggedData;
  } PWM_PWORK;                         /* '<S3>/PWM' */

  struct {
    void *LoggedData;
  } sonar_PWORK_p;                     /* '<S3>/sonar' */

  void *HILWatchdog_PWORK;             /* '<S3>/HIL Watchdog' */
  struct {
    void *LoggedData;
  } watchdog_PWORK;                    /* '<S3>/watchdog' */

  struct {
    void *LoggedData;
  } RollPitchrunawaycheck_PWORK;       /* '<S16>/Roll, Pitch runaway check' */

  struct {
    void *LoggedData;
  } motors_in_PWORK;                   /* '<S16>/motors_in' */

  struct {
    void *LoggedData;
  } motors_out_PWORK;                  /* '<S16>/motors_out' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_cr;                   /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } error_PWORK;                       /* '<S4>/error' */

  struct {
    void *LoggedData;
  } new_PWORK;                         /* '<S4>/new' */

  struct {
    void *LoggedData;
  } PacketfromTarget_PWORK;            /* '<S65>/Packet from Target' */

  struct {
    void *LoggedData;
  } rcvdpackets_PWORK;                 /* '<S4>/rcvd packets' */

  struct {
    void *LoggedData;
  } state_PWORK;                       /* '<S4>/state' */

  struct {
    void *LoggedData;
  } land_PWORK;                        /* '<S66>/land' */

  struct {
    void *LoggedData;
  } armed_PWORK;                       /* '<S4>/armed' */

  struct {
    void *LoggedData;
  } Pitch_PWORK;                       /* '<S6>/Pitch' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S7>/Transport Delay' */

  struct {
    void *LoggedData;
  } Origvadjustedpitch_PWORK;          /* '<S82>/Orig v. adjusted pitch' */

  struct {
    void *LoggedData;
  } pitchcontrolsignalcomponents_PW;   /* '<S81>/pitch control signal components' */

  struct {
    void *LoggedData;
  } Pitch1_PWORK;                      /* '<S6>/Pitch1' */

  struct {
    void *LoggedData;
  } Roll_PWORK;                        /* '<S8>/Roll' */

  struct {
    void *LoggedData;
  } Origvadjustedroll_PWORK;           /* '<S100>/Orig v. adjusted roll' */

  struct {
    void *LoggedData;
  } X_cmdandX_meas_PWORK;              /* '<S100>/X_cmd and X_meas' */

  struct {
    void *LoggedData;
  } Roll1_PWORK;                       /* '<S8>/Roll1' */

  void *ToHostFile_PWORK;              /* '<S9>/To Host File' */
  struct {
    void *LoggedData;
  } throttlecmd_PWORK;                 /* '<S11>/throttle cmd' */

  struct {
    void *LoggedData;
  } throttlesw_PWORK;                  /* '<S11>/throttle sw' */

  struct {
    void *LoggedData;
  } throttlejoystick_PWORK;            /* '<S117>/throttle joystick' */

  struct {
    void *LoggedData;
  } landwsonar_PWORK;                  /* '<S118>/land w// sonar' */

  struct {
    void *LoggedData;
  } HeightPID_PWORK;                   /* '<S131>/Height P I D' */

  struct {
    void *LoggedData;
  } u_yaw_PWORK;                       /* '<S13>/u_yaw' */

  struct {
    void *LoggedData;
  } u_yaw1_PWORK;                      /* '<S13>/u_yaw1' */

  struct {
    void *LoggedData;
  } yaw_error_PWORK;                   /* '<S13>/yaw_error' */

  int32_T HILInitialize_DOStates[2];   /* '<S3>/HIL Initialize' */
  uint32_T ToHostFile_SamplesCount;    /* '<S9>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<S9>/To Host File' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S32>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_j;               /* '<S47>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_o;               /* '<S48>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_l;               /* '<S49>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_ov;              /* '<S50>/Integrator1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S7>/Transport Delay' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_b;               /* '<S89>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_li;              /* '<S107>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_g;               /* '<S139>/Integrator1' */

  int8_T TriggeredSubsystem_SubsysRanBC;/* '<S55>/Triggered Subsystem' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S30>/Enabled Moving Average' */
  int8_T EnabledSubsystemLatchOutputHigh;/* '<S66>/Enabled Subsystem Latch Output High' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S66>/Enabled Subsystem' */
  int8_T EnabledSubsystem2_SubsysRanBC;/* '<S66>/Enabled Subsystem2' */
  int8_T EnabledSubsystem_SubsysRanBC_l;/* '<S129>/Enabled Subsystem' */
  int8_T SigmoidPath_Toggle;           /* '<S124>/Sigmoid Path' */
  int8_T EnabledSubsystem_SubsysRanBC_d;/* '<S16>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC_h;/* '<S83>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC_f;/* '<S101>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC_m;/* '<S20>/Enabled Subsystem' */
  int8_T TriggeredSigmoidCompute_SubsysR;/* '<S124>/Triggered Sigmoid Compute' */
  int8_T armheightcommand_SubsysRanBC; /* '<S130>/arm height command' */
  int8_T SigmoidCompute_Toggle;        /* '<S125>/Sigmoid Compute' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S31>/Switch Case' */
  int8_T SwitchCaseActionSubsystem_Subsy;/* '<S31>/Switch Case Action Subsystem' */
  int8_T SwitchCaseActionSubsystem1_Subs;/* '<S31>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem2_Subs;/* '<S31>/Switch Case Action Subsystem2' */
  uint8_T ContinuousSigmoid_Flag;      /* '<S130>/Continuous Sigmoid' */
  uint8_T SigmoidPath_Flag;            /* '<S124>/Sigmoid Path' */
  boolean_T HILInitialize_DOBits[2];   /* '<S3>/HIL Initialize' */
  boolean_T StreamClient_Connected;    /* '<S4>/Stream Client' */
  boolean_T InverseModulus_FirstSample;/* '<S4>/Inverse Modulus' */
  boolean_T HILWatchdog_IsStarted;     /* '<S3>/HIL Watchdog' */
  t_boolean HILReadWrite1_W_DigitalBuffer[2];/* '<S3>/HIL Read Write1' */
  boolean_T EnabledMovingAverage_MODE; /* '<S30>/Enabled Moving Average' */
  boolean_T EnabledSubsystem_MODE;     /* '<S66>/Enabled Subsystem' */
  boolean_T EnabledSubsystem_MODE_h;   /* '<S20>/Enabled Subsystem' */
  boolean_T armheightcommand_MODE;     /* '<S130>/arm height command' */
  DW_EnabledSubsystem1_leader_q_T EnabledSubsystem1_b;/* '<S123>/Enabled Subsystem1' */
  DW_EnabledSubsystem1_leader_q_T EnabledSubsystem1;/* '<S66>/Enabled Subsystem1' */
  DW_EnabledMovingAverage_leade_T EnabledMovingAverage_e;/* '<S27>/Enabled Moving Average' */
  DW_EnabledMovingAverage_leade_T EnabledMovingAverage_c;/* '<S31>/Enabled Moving Average' */
} DW_leader_qball2_mytest_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S48>/Integrator2' */
  real_T Integrator1_CSTATE[3];        /* '<S32>/Integrator1' */
  real_T HighPassFilterRoll_CSTATE;    /* '<S29>/High Pass Filter - Roll' */
  real_T HighPassFilterPitch_CSTATE;   /* '<S29>/High Pass Filter - Pitch' */
  real_T Integrator2_CSTATE_j;         /* '<S49>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S50>/Integrator2' */
  real_T Integrator1_CSTATE_l;         /* '<S47>/Integrator1' */
  real_T HighPassFilterYaw_CSTATE;     /* '<S29>/High Pass Filter - Yaw' */
  real_T Integrator2_CSTATE_o;         /* '<S47>/Integrator2' */
  real_T Integrator1_CSTATE_a;         /* '<S48>/Integrator1' */
  real_T Integrator1_CSTATE_ly;        /* '<S49>/Integrator1' */
  real_T Integrator1_CSTATE_lyr;       /* '<S50>/Integrator1' */
  real_T Integrator2_CSTATE_i2[3];     /* '<S32>/Integrator2' */
  real_T TransferFcn_CSTATE;           /* '<S23>/Transfer Fcn' */
  real_T LPF_CSTATE;                   /* '<S14>/LPF' */
  real_T Integrator_CSTATE;            /* '<S14>/Integrator' */
  real_T HPF_CSTATE;                   /* '<S14>/HPF' */
  real_T LPF1_CSTATE;                  /* '<S15>/LPF1' */
  real_T Integrator_CSTATE_g;          /* '<S15>/Integrator' */
  real_T HPF1_CSTATE;                  /* '<S15>/HPF1' */
  real_T LowPassFilterFilteredYawRate_CS;/* '<S13>/Low Pass Filter (Filtered Yaw Rate)' */
  real_T Integrator2_CSTATE_e;         /* '<S139>/Integrator2' */
  real_T Integrator_CSTATE_ga;         /* '<S131>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S13>/Integrator' */
  real_T LowPassFilterFilteredYawRateFor;/* '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)' */
  real_T LowPassFilterFilteredPitchRate_;/* '<S81>/Low Pass Filter (Filtered Pitch Rate)' */
  real_T Integrator1_CSTATE_g;         /* '<S81>/Integrator1' */
  real_T LowPassFilterFilteredRollRate_C;/* '<S97>/Low Pass Filter (Filtered Roll Rate)' */
  real_T Integrator1_CSTATE_n;         /* '<S97>/Integrator1' */
  real_T Integrator2_CSTATE_ir;        /* '<S89>/Integrator2' */
  real_T Integrator_CSTATE_k;          /* '<S86>/Integrator' */
  real_T Integrator2_CSTATE_a;         /* '<S107>/Integrator2' */
  real_T Integrator1_CSTATE_nx;        /* '<S104>/Integrator1' */
  real_T Integrator1_CSTATE_c;         /* '<S89>/Integrator1' */
  real_T Integrator1_CSTATE_e;         /* '<S107>/Integrator1' */
  real_T Integrator1_CSTATE_d;         /* '<S139>/Integrator1' */
} X_leader_qball2_mytest_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S48>/Integrator2' */
  real_T Integrator1_CSTATE[3];        /* '<S32>/Integrator1' */
  real_T HighPassFilterRoll_CSTATE;    /* '<S29>/High Pass Filter - Roll' */
  real_T HighPassFilterPitch_CSTATE;   /* '<S29>/High Pass Filter - Pitch' */
  real_T Integrator2_CSTATE_j;         /* '<S49>/Integrator2' */
  real_T Integrator2_CSTATE_i;         /* '<S50>/Integrator2' */
  real_T Integrator1_CSTATE_l;         /* '<S47>/Integrator1' */
  real_T HighPassFilterYaw_CSTATE;     /* '<S29>/High Pass Filter - Yaw' */
  real_T Integrator2_CSTATE_o;         /* '<S47>/Integrator2' */
  real_T Integrator1_CSTATE_a;         /* '<S48>/Integrator1' */
  real_T Integrator1_CSTATE_ly;        /* '<S49>/Integrator1' */
  real_T Integrator1_CSTATE_lyr;       /* '<S50>/Integrator1' */
  real_T Integrator2_CSTATE_i2[3];     /* '<S32>/Integrator2' */
  real_T TransferFcn_CSTATE;           /* '<S23>/Transfer Fcn' */
  real_T LPF_CSTATE;                   /* '<S14>/LPF' */
  real_T Integrator_CSTATE;            /* '<S14>/Integrator' */
  real_T HPF_CSTATE;                   /* '<S14>/HPF' */
  real_T LPF1_CSTATE;                  /* '<S15>/LPF1' */
  real_T Integrator_CSTATE_g;          /* '<S15>/Integrator' */
  real_T HPF1_CSTATE;                  /* '<S15>/HPF1' */
  real_T LowPassFilterFilteredYawRate_CS;/* '<S13>/Low Pass Filter (Filtered Yaw Rate)' */
  real_T Integrator2_CSTATE_e;         /* '<S139>/Integrator2' */
  real_T Integrator_CSTATE_ga;         /* '<S131>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S13>/Integrator' */
  real_T LowPassFilterFilteredYawRateFor;/* '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)' */
  real_T LowPassFilterFilteredPitchRate_;/* '<S81>/Low Pass Filter (Filtered Pitch Rate)' */
  real_T Integrator1_CSTATE_g;         /* '<S81>/Integrator1' */
  real_T LowPassFilterFilteredRollRate_C;/* '<S97>/Low Pass Filter (Filtered Roll Rate)' */
  real_T Integrator1_CSTATE_n;         /* '<S97>/Integrator1' */
  real_T Integrator2_CSTATE_ir;        /* '<S89>/Integrator2' */
  real_T Integrator_CSTATE_k;          /* '<S86>/Integrator' */
  real_T Integrator2_CSTATE_a;         /* '<S107>/Integrator2' */
  real_T Integrator1_CSTATE_nx;        /* '<S104>/Integrator1' */
  real_T Integrator1_CSTATE_c;         /* '<S89>/Integrator1' */
  real_T Integrator1_CSTATE_e;         /* '<S107>/Integrator1' */
  real_T Integrator1_CSTATE_d;         /* '<S139>/Integrator1' */
} XDot_leader_qball2_mytest_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S48>/Integrator2' */
  boolean_T Integrator1_CSTATE[3];     /* '<S32>/Integrator1' */
  boolean_T HighPassFilterRoll_CSTATE; /* '<S29>/High Pass Filter - Roll' */
  boolean_T HighPassFilterPitch_CSTATE;/* '<S29>/High Pass Filter - Pitch' */
  boolean_T Integrator2_CSTATE_j;      /* '<S49>/Integrator2' */
  boolean_T Integrator2_CSTATE_i;      /* '<S50>/Integrator2' */
  boolean_T Integrator1_CSTATE_l;      /* '<S47>/Integrator1' */
  boolean_T HighPassFilterYaw_CSTATE;  /* '<S29>/High Pass Filter - Yaw' */
  boolean_T Integrator2_CSTATE_o;      /* '<S47>/Integrator2' */
  boolean_T Integrator1_CSTATE_a;      /* '<S48>/Integrator1' */
  boolean_T Integrator1_CSTATE_ly;     /* '<S49>/Integrator1' */
  boolean_T Integrator1_CSTATE_lyr;    /* '<S50>/Integrator1' */
  boolean_T Integrator2_CSTATE_i2[3];  /* '<S32>/Integrator2' */
  boolean_T TransferFcn_CSTATE;        /* '<S23>/Transfer Fcn' */
  boolean_T LPF_CSTATE;                /* '<S14>/LPF' */
  boolean_T Integrator_CSTATE;         /* '<S14>/Integrator' */
  boolean_T HPF_CSTATE;                /* '<S14>/HPF' */
  boolean_T LPF1_CSTATE;               /* '<S15>/LPF1' */
  boolean_T Integrator_CSTATE_g;       /* '<S15>/Integrator' */
  boolean_T HPF1_CSTATE;               /* '<S15>/HPF1' */
  boolean_T LowPassFilterFilteredYawRate_CS;/* '<S13>/Low Pass Filter (Filtered Yaw Rate)' */
  boolean_T Integrator2_CSTATE_e;      /* '<S139>/Integrator2' */
  boolean_T Integrator_CSTATE_ga;      /* '<S131>/Integrator' */
  boolean_T Integrator_CSTATE_h;       /* '<S13>/Integrator' */
  boolean_T LowPassFilterFilteredYawRateFor;/* '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)' */
  boolean_T LowPassFilterFilteredPitchRate_;/* '<S81>/Low Pass Filter (Filtered Pitch Rate)' */
  boolean_T Integrator1_CSTATE_g;      /* '<S81>/Integrator1' */
  boolean_T LowPassFilterFilteredRollRate_C;/* '<S97>/Low Pass Filter (Filtered Roll Rate)' */
  boolean_T Integrator1_CSTATE_n;      /* '<S97>/Integrator1' */
  boolean_T Integrator2_CSTATE_ir;     /* '<S89>/Integrator2' */
  boolean_T Integrator_CSTATE_k;       /* '<S86>/Integrator' */
  boolean_T Integrator2_CSTATE_a;      /* '<S107>/Integrator2' */
  boolean_T Integrator1_CSTATE_nx;     /* '<S104>/Integrator1' */
  boolean_T Integrator1_CSTATE_c;      /* '<S89>/Integrator1' */
  boolean_T Integrator1_CSTATE_e;      /* '<S107>/Integrator1' */
  boolean_T Integrator1_CSTATE_d;      /* '<S139>/Integrator1' */
} XDis_leader_qball2_mytest_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S131>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_f;   /* '<S13>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S81>/Integrator1' */
  ZCSigState Integrator1_Reset_ZCE_e;  /* '<S97>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S86>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_f;  /* '<S104>/Integrator1' */
  ZCSigState TriggeredSigmoidCompute_Trig_ZC;/* '<S124>/Triggered Sigmoid Compute' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S55>/Triggered Subsystem' */
} PrevZCX_leader_qball2_mytest_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters for system: '<S31>/Enabled Moving Average' */
struct P_EnabledMovingAverage_leader_T_ {
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S38>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S38>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S34>/Sum( k=1,n-1, x(k) )'
                                        */
};

/* Parameters for system: '<S66>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_leader_qb_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S77>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S77>/Discrete-Time Integrator'
                                        */
  boolean_T timeout_Y0;                /* Computed Parameter: timeout_Y0
                                        * Referenced by: '<S77>/timeout'
                                        */
};

/* Parameters (auto storage) */
struct P_leader_qball2_mytest_T_ {
  real_T KdHEIGHT_DOWN;                /* Variable: KdHEIGHT_DOWN
                                        * Referenced by: '<S131>/Kd - Battery DOWN'
                                        */
  real_T KdHEIGHT_UP;                  /* Variable: KdHEIGHT_UP
                                        * Referenced by: '<S131>/Kd - Battery UP'
                                        */
  real_T KdOUTER_PITCH_DOWN;           /* Variable: KdOUTER_PITCH_DOWN
                                        * Referenced by: '<S86>/Kv - Battery DOWN'
                                        */
  real_T KdOUTER_PITCH_UP;             /* Variable: KdOUTER_PITCH_UP
                                        * Referenced by: '<S86>/Kv - Battery UP'
                                        */
  real_T KdOUTER_ROLL_DOWN;            /* Variable: KdOUTER_ROLL_DOWN
                                        * Referenced by: '<S104>/Kv - DOWN'
                                        */
  real_T KdOUTER_ROLL_UP;              /* Variable: KdOUTER_ROLL_UP
                                        * Referenced by: '<S104>/Kv - UP'
                                        */
  real_T KdPITCH_DOWN;                 /* Variable: KdPITCH_DOWN
                                        * Referenced by: '<S81>/Kd - Battery DOWN'
                                        */
  real_T KdPITCH_UP;                   /* Variable: KdPITCH_UP
                                        * Referenced by: '<S81>/Kd - Battery UP'
                                        */
  real_T KdROLL_DOWN;                  /* Variable: KdROLL_DOWN
                                        * Referenced by: '<S97>/Kd - Battery DOWN'
                                        */
  real_T KdROLL_UP;                    /* Variable: KdROLL_UP
                                        * Referenced by: '<S97>/Kd - Battery UP'
                                        */
  real_T KdYAW_DOWN;                   /* Variable: KdYAW_DOWN
                                        * Referenced by: '<S13>/Kd - Battery DOWN'
                                        */
  real_T KdYAW_UP;                     /* Variable: KdYAW_UP
                                        * Referenced by: '<S13>/Kd - Battery UP'
                                        */
  real_T KiHEIGHT_DOWN;                /* Variable: KiHEIGHT_DOWN
                                        * Referenced by: '<S131>/Ki - Battery DOWN'
                                        */
  real_T KiHEIGHT_UP;                  /* Variable: KiHEIGHT_UP
                                        * Referenced by: '<S131>/Ki - Battery UP'
                                        */
  real_T KiOUTER_PITCH_DOWN;           /* Variable: KiOUTER_PITCH_DOWN
                                        * Referenced by: '<S86>/Ki - Battery DOWN'
                                        */
  real_T KiOUTER_PITCH_UP;             /* Variable: KiOUTER_PITCH_UP
                                        * Referenced by: '<S86>/Ki - Battery UP'
                                        */
  real_T KiOUTER_ROLL_DOWN;            /* Variable: KiOUTER_ROLL_DOWN
                                        * Referenced by: '<S104>/Ki - Battery DOWN'
                                        */
  real_T KiOUTER_ROLL_UP;              /* Variable: KiOUTER_ROLL_UP
                                        * Referenced by: '<S104>/Ki - Battery UP'
                                        */
  real_T KiPITCH_DOWN;                 /* Variable: KiPITCH_DOWN
                                        * Referenced by: '<S81>/Ki - Battery DOWN'
                                        */
  real_T KiPITCH_UP;                   /* Variable: KiPITCH_UP
                                        * Referenced by: '<S81>/Ki - Battery UP'
                                        */
  real_T KiROLL_DOWN;                  /* Variable: KiROLL_DOWN
                                        * Referenced by: '<S97>/Ki - Battery DOWN'
                                        */
  real_T KiROLL_UP;                    /* Variable: KiROLL_UP
                                        * Referenced by: '<S97>/Ki - Battery UP'
                                        */
  real_T KiYAW_DOWN;                   /* Variable: KiYAW_DOWN
                                        * Referenced by: '<S13>/Ki - Battery DOWN'
                                        */
  real_T KiYAW_UP;                     /* Variable: KiYAW_UP
                                        * Referenced by: '<S13>/Ki - Battery UP'
                                        */
  real_T KpHEIGHT_DOWN;                /* Variable: KpHEIGHT_DOWN
                                        * Referenced by: '<S131>/Kp - Battery DOWN'
                                        */
  real_T KpHEIGHT_UP;                  /* Variable: KpHEIGHT_UP
                                        * Referenced by: '<S131>/Kp - Battery UP'
                                        */
  real_T KpOUTER_PITCH_DOWN;           /* Variable: KpOUTER_PITCH_DOWN
                                        * Referenced by: '<S86>/Kp - Battery DOWN'
                                        */
  real_T KpOUTER_PITCH_UP;             /* Variable: KpOUTER_PITCH_UP
                                        * Referenced by: '<S86>/Kp - Battery UP'
                                        */
  real_T KpOUTER_ROLL_DOWN;            /* Variable: KpOUTER_ROLL_DOWN
                                        * Referenced by: '<S104>/Kp - Battery DOWN'
                                        */
  real_T KpOUTER_ROLL_UP;              /* Variable: KpOUTER_ROLL_UP
                                        * Referenced by: '<S104>/Kp - Battery UP'
                                        */
  real_T KpPITCH_DOWN;                 /* Variable: KpPITCH_DOWN
                                        * Referenced by: '<S81>/Kp - Battery DOWN'
                                        */
  real_T KpPITCH_UP;                   /* Variable: KpPITCH_UP
                                        * Referenced by: '<S81>/Kp - Battery UP'
                                        */
  real_T KpROLL_DOWN;                  /* Variable: KpROLL_DOWN
                                        * Referenced by: '<S97>/Kp - Battery DOWN'
                                        */
  real_T KpROLL_UP;                    /* Variable: KpROLL_UP
                                        * Referenced by: '<S97>/Kp - Battery UP'
                                        */
  real_T KpYAW_DOWN;                   /* Variable: KpYAW_DOWN
                                        * Referenced by: '<S13>/Kp - Battery DOWN'
                                        */
  real_T KpYAW_UP;                     /* Variable: KpYAW_UP
                                        * Referenced by: '<S13>/Kp - Battery UP'
                                        */
  real_T LIMIT_CMD_PITCH;              /* Variable: LIMIT_CMD_PITCH
                                        * Referenced by: '<S86>/Saturation1'
                                        */
  real_T LIMIT_CMD_ROLL;               /* Variable: LIMIT_CMD_ROLL
                                        * Referenced by: '<S104>/Saturation1'
                                        */
  real_T LIMIT_MAX_HEIGHT;             /* Variable: LIMIT_MAX_HEIGHT
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T LIMIT_MAX_X;                  /* Variable: LIMIT_MAX_X
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T LIMIT_MAX_Z;                  /* Variable: LIMIT_MAX_Z
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T LIMIT_MIN_HEIGHT;             /* Variable: LIMIT_MIN_HEIGHT
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  real_T LIMIT_MIN_X;                  /* Variable: LIMIT_MIN_X
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T LIMIT_MIN_Z;                  /* Variable: LIMIT_MIN_Z
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  real_T LIMIT_RATE_HEIGHT;            /* Variable: LIMIT_RATE_HEIGHT
                                        * Referenced by: '<S7>/Rate Limiter3'
                                        */
  real_T LIMIT_RATE_X;                 /* Variable: LIMIT_RATE_X
                                        * Referenced by: '<S7>/Rate Limiter1'
                                        */
  real_T LIMIT_RATE_Z;                 /* Variable: LIMIT_RATE_Z
                                        * Referenced by: '<S7>/Rate Limiter2'
                                        */
  real_T LIMIT_uCMD_PITCH;             /* Variable: LIMIT_uCMD_PITCH
                                        * Referenced by: '<S81>/Saturation1'
                                        */
  real_T LIMIT_uCMD_ROLL;              /* Variable: LIMIT_uCMD_ROLL
                                        * Referenced by: '<S97>/Saturation'
                                        */
  real_T LIMIT_uCMD_YAW;               /* Variable: LIMIT_uCMD_YAW
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T OFFSET_HEIGHT;                /* Variable: OFFSET_HEIGHT
                                        * Referenced by:
                                        *   '<S29>/Height Estimate Bias (Estimate Reference at Centre of QBall 2) '
                                        *   '<S29>/OptiTrack Height Measurement Bias'
                                        */
  real_T OMEGA_DIFF;                   /* Variable: OMEGA_DIFF
                                        * Referenced by:
                                        *   '<S48>/wn'
                                        *   '<S49>/wn'
                                        *   '<S50>/wn'
                                        *   '<S139>/wn'
                                        *   '<S89>/wn'
                                        *   '<S107>/wn'
                                        */
  real_T OMEGA_FILTER;                 /* Variable: OMEGA_FILTER
                                        * Referenced by:
                                        *   '<S32>/wn'
                                        *   '<S47>/wn'
                                        */
  real_T TIMEOUT_CALIB;                /* Variable: TIMEOUT_CALIB
                                        * Referenced by: '<S31>/Step: end_time'
                                        */
  real_T TRIM_THROTTLE;                /* Variable: TRIM_THROTTLE
                                        * Referenced by: '<S7>/Throttle Trim'
                                        */
  real_T TRIM_U_PITCH;                 /* Variable: TRIM_U_PITCH
                                        * Referenced by: '<S7>/Pitch_Trim'
                                        */
  real_T TRIM_U_ROLL;                  /* Variable: TRIM_U_ROLL
                                        * Referenced by: '<S7>/roll_trim'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<S23>/Accelerometer offsets manually calibrated2'
                                        */
  real_T joystick_range_max;           /* Variable: joystick_range_max
                                        * Referenced by: '<S117>/height command2'
                                        */
  real_T joystick_range_min;           /* Variable: joystick_range_min
                                        * Referenced by: '<S117>/height command1'
                                        */
  real_T FOH1_Ts;                      /* Mask Parameter: FOH1_Ts
                                        * Referenced by:
                                        *   '<S54>/Bias'
                                        *   '<S54>/Gain'
                                        */
  real_T HILInitialize_analog_input_maxi[3];/* Mask Parameter: HILInitialize_analog_input_maxi
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  real_T HILInitialize_analog_input_mini[3];/* Mask Parameter: HILInitialize_analog_input_mini
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T CompareToConstant_const_o;    /* Mask Parameter: CompareToConstant_const_o
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T CompareToConstant_const_d;    /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T CompareToConstant_const_k;    /* Mask Parameter: CompareToConstant_const_k
                                        * Referenced by: '<S136>/Constant'
                                        */
  real_T CompareToConstant_const_c;    /* Mask Parameter: CompareToConstant_const_c
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T CompareToConstant1_const_c;   /* Mask Parameter: CompareToConstant1_const_c
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T CompareToConstant1_const_h;   /* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S137>/Constant'
                                        */
  real_T CompareToConstant_const_m;    /* Mask Parameter: CompareToConstant_const_m
                                        * Referenced by: '<S126>/Constant'
                                        */
  real_T CompareToConstant_const_ol;   /* Mask Parameter: CompareToConstant_const_ol
                                        * Referenced by: '<S141>/Constant'
                                        */
  real_T CompareToConstant1_const_n;   /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T CompareToConstant2_const;     /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T CompareToConstant_const_a;    /* Mask Parameter: CompareToConstant_const_a
                                        * Referenced by: '<S91>/Constant'
                                        */
  real_T CompareToConstant_const_i;    /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S99>/Constant'
                                        */
  real_T CompareToConstant_const_g;    /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T CompareToConstant_const_aq;   /* Mask Parameter: CompareToConstant_const_aq
                                        * Referenced by: '<S73>/Constant'
                                        */
  real_T CompareToConstant_const_ap;   /* Mask Parameter: CompareToConstant_const_ap
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T CompareToConstant_const_mk;   /* Mask Parameter: CompareToConstant_const_mk
                                        * Referenced by: '<S102>/Constant'
                                        */
  real_T StreamClient_default_value[10];/* Mask Parameter: StreamClient_default_value
                                         * Referenced by: '<S4>/Stream Client'
                                         */
  real_T HILInitialize_final_other_outpu;/* Mask Parameter: HILInitialize_final_other_outpu
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_final_pwm_outputs;/* Mask Parameter: HILInitialize_final_pwm_outputs
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S92>/Slider Gain'
                                        */
  real_T Joystickyawcommandgain1_gain; /* Mask Parameter: Joystickyawcommandgain1_gain
                                        * Referenced by: '<S144>/Slider Gain'
                                        */
  real_T Joystickyawcommandgain_gain;  /* Mask Parameter: Joystickyawcommandgain_gain
                                        * Referenced by: '<S143>/Slider Gain'
                                        */
  real_T Joystickyawcontrolgain_gain;  /* Mask Parameter: Joystickyawcontrolgain_gain
                                        * Referenced by: '<S142>/Slider Gain'
                                        */
  real_T SliderGain4_gain;             /* Mask Parameter: SliderGain4_gain
                                        * Referenced by: '<S96>/Slider Gain'
                                        */
  real_T SliderGain2_gain;             /* Mask Parameter: SliderGain2_gain
                                        * Referenced by: '<S94>/Slider Gain'
                                        */
  real_T SliderGain1_gain;             /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S93>/Slider Gain'
                                        */
  real_T SliderGain3_gain;             /* Mask Parameter: SliderGain3_gain
                                        * Referenced by: '<S95>/Slider Gain'
                                        */
  real_T ContinuousSigmoid_hold_off;   /* Mask Parameter: ContinuousSigmoid_hold_off
                                        * Referenced by: '<S130>/Continuous Sigmoid'
                                        */
  real_T TriggeredSigmoid_hold_off;    /* Mask Parameter: TriggeredSigmoid_hold_off
                                        * Referenced by: '<S124>/Sigmoid Path'
                                        */
  real_T HILInitialize_initial_other_out;/* Mask Parameter: HILInitialize_initial_other_out
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T ContinuousSigmoid_initial_posit;/* Mask Parameter: ContinuousSigmoid_initial_posit
                                          * Referenced by: '<S130>/Continuous Sigmoid'
                                          */
  real_T HILInitialize_initial_pwm_outpu;/* Mask Parameter: HILInitialize_initial_pwm_outpu
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T ContinuousSigmoid_initial_veloc;/* Mask Parameter: ContinuousSigmoid_initial_veloc
                                          * Referenced by: '<S130>/Continuous Sigmoid'
                                          */
  real_T SecondOrderLowPassFilter3_input;/* Mask Parameter: SecondOrderLowPassFilter3_input
                                          * Referenced by: '<S47>/zt'
                                          */
  real_T SecondOrderLowPassFilter4_input;/* Mask Parameter: SecondOrderLowPassFilter4_input
                                          * Referenced by: '<S48>/zt'
                                          */
  real_T SecondOrderLowPassFilter5_input;/* Mask Parameter: SecondOrderLowPassFilter5_input
                                          * Referenced by: '<S49>/zt'
                                          */
  real_T SecondOrderLowPassFilter7_input;/* Mask Parameter: SecondOrderLowPassFilter7_input
                                          * Referenced by: '<S50>/zt'
                                          */
  real_T SecondOrderLowPassFilter2_input;/* Mask Parameter: SecondOrderLowPassFilter2_input
                                          * Referenced by: '<S32>/zt'
                                          */
  real_T SecondOrderLowPassFilter1_input;/* Mask Parameter: SecondOrderLowPassFilter1_input
                                          * Referenced by: '<S89>/zt'
                                          */
  real_T SecondOrderLowPassFilter1_inp_e;/* Mask Parameter: SecondOrderLowPassFilter1_inp_e
                                          * Referenced by: '<S107>/zt'
                                          */
  real_T SecondOrderLowPassFilter_input_;/* Mask Parameter: SecondOrderLowPassFilter_input_
                                          * Referenced by: '<S139>/zt'
                                          */
  real_T TriggeredSigmoid_max_accelerati;/* Mask Parameter: TriggeredSigmoid_max_accelerati
                                          * Referenced by: '<S125>/Sigmoid Compute'
                                          */
  real_T TriggeredSigmoid_max_velocity;/* Mask Parameter: TriggeredSigmoid_max_velocity
                                        * Referenced by: '<S125>/Sigmoid Compute'
                                        */
  real_T HILInitialize_pwm_frequency;  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_pwm_leading_deadb;/* Mask Parameter: HILInitialize_pwm_leading_deadb
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_pwm_trailing_dead;/* Mask Parameter: HILInitialize_pwm_trailing_dead
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_f;/* Mask Parameter: HILInitialize_set_other_outpu_f
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_m;/* Mask Parameter: HILInitialize_set_other_outpu_m
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_i;/* Mask Parameter: HILInitialize_set_other_outpu_i
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S31>/Step: start_time'
                                        */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T HILInitialize_watchdog_other_ou;/* Mask Parameter: HILInitialize_watchdog_other_ou
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_watchdog_pwm_outp;/* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  int32_T HILInitialize_pwm_alignment; /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_configuration;/* Mask Parameter: HILInitialize_pwm_configuration
                                           * Referenced by: '<S3>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_modes;     /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_polarity;  /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  int32_T HILInitialize_watchdog_digital_;/* Mask Parameter: HILInitialize_watchdog_digital_
                                           * Referenced by: '<S3>/HIL Initialize'
                                           */
  uint32_T HILInitialize_analog_input_chan[3];/* Mask Parameter: HILInitialize_analog_input_chan
                                               * Referenced by: '<S3>/HIL Initialize'
                                               */
  uint32_T HILReadWrite1_analog_input_chan;/* Mask Parameter: HILReadWrite1_analog_input_chan
                                            * Referenced by: '<S3>/HIL Read Write1'
                                            */
  uint32_T HILInitialize_digital_output_ch[2];/* Mask Parameter: HILInitialize_digital_output_ch
                                               * Referenced by: '<S3>/HIL Initialize'
                                               */
  uint32_T HILReadWrite1_digital_output_ch[2];/* Mask Parameter: HILReadWrite1_digital_output_ch
                                               * Referenced by: '<S3>/HIL Read Write1'
                                               */
  uint32_T HILReadWrite1_other_input_chann[7];/* Mask Parameter: HILReadWrite1_other_input_chann
                                               * Referenced by: '<S3>/HIL Read Write1'
                                               */
  uint32_T HILInitialize_other_output_chan[4];/* Mask Parameter: HILInitialize_other_output_chan
                                               * Referenced by: '<S3>/HIL Initialize'
                                               */
  uint32_T HILReadWrite1_other_output_chan[4];/* Mask Parameter: HILReadWrite1_other_output_chan
                                               * Referenced by: '<S3>/HIL Read Write1'
                                               */
  int8_T ShowMessageonHost1_message_icon;/* Mask Parameter: ShowMessageonHost1_message_icon
                                          * Referenced by: '<S25>/Show Message on Host1'
                                          */
  int8_T ShowMessageonHost_message_icon;/* Mask Parameter: ShowMessageonHost_message_icon
                                         * Referenced by: '<S24>/Show Message on Host'
                                         */
  int8_T ShowMessageonHost1_message_ic_m;/* Mask Parameter: ShowMessageonHost1_message_ic_m
                                          * Referenced by: '<S72>/Show Message on Host1'
                                          */
  int8_T ShowMessageonHost_message_ico_h;/* Mask Parameter: ShowMessageonHost_message_ico_h
                                          * Referenced by: '<S66>/Show Message on Host'
                                          */
  int8_T ShowMessageonHost1_message_i_m5;/* Mask Parameter: ShowMessageonHost1_message_i_m5
                                          * Referenced by: '<S66>/Show Message on Host1'
                                          */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  boolean_T HILInitialize_final_digital_out[2];/* Mask Parameter: HILInitialize_final_digital_out
                                                * Referenced by: '<S3>/HIL Initialize'
                                                */
  boolean_T HILInitialize_initial_digital_o;/* Mask Parameter: HILInitialize_initial_digital_o
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_input_;/* Mask Parameter: HILInitialize_set_analog_input_
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_inpu_e;/* Mask Parameter: HILInitialize_set_analog_inpu_e
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_g;/* Mask Parameter: HILInitialize_set_analog_outp_g
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_out_gi;/* Mask Parameter: HILInitialize_set_analog_out_gi
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_l;/* Mask Parameter: HILInitialize_set_analog_outp_l
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_m;/* Mask Parameter: HILInitialize_set_analog_outp_m
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_h;/* Mask Parameter: HILInitialize_set_analog_outp_h
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_out_m2;/* Mask Parameter: HILInitialize_set_analog_out_m2
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_i;/* Mask Parameter: HILInitialize_set_clock_frequ_i
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_b;/* Mask Parameter: HILInitialize_set_clock_param_b
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_a;/* Mask Parameter: HILInitialize_set_digital_out_a
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_c;/* Mask Parameter: HILInitialize_set_digital_out_c
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_o;/* Mask Parameter: HILInitialize_set_digital_out_o
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_p;/* Mask Parameter: HILInitialize_set_digital_out_p
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_j;/* Mask Parameter: HILInitialize_set_digital_out_j
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_n;/* Mask Parameter: HILInitialize_set_digital_out_n
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_count;/* Mask Parameter: HILInitialize_set_encoder_count
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_cou_l;/* Mask Parameter: HILInitialize_set_encoder_cou_l
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_param;/* Mask Parameter: HILInitialize_set_encoder_param
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_par_p;/* Mask Parameter: HILInitialize_set_encoder_par_p
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outp_i5;/* Mask Parameter: HILInitialize_set_other_outp_i5
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_b;/* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_e;/* Mask Parameter: HILInitialize_set_pwm_outputs_e
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_n;/* Mask Parameter: HILInitialize_set_pwm_outputs_n
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__e;/* Mask Parameter: HILInitialize_set_pwm_params__e
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  real_T Out1_Y0;                      /* Expression: 1
                                        * Referenced by: '<S19>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S22>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */
  real_T TransformGyroDataForBatteryBott[3];/* Expression: [1 -1 -1]
                                             * Referenced by: '<S23>/Transform Gyro Data (For Battery Bottom Configuration)'
                                             */
  real_T TransformAccelerometerDataForBa[3];/* Expression: [1 -1 -1]
                                             * Referenced by: '<S23>/Transform Accelerometer Data (For Battery Bottom Configuration)'
                                             */
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S35>/zero'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S36>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S37>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S31>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S31>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S31>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S31>/Step: end_time'
                                        */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S58>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S58>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S57>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                          * Referenced by: '<S76>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S76>/Discrete-Time Integrator'
                                        */
  real_T Out1_Y0_f;                    /* Expression: 0
                                        * Referenced by: '<S78>/Out1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T Out1_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S79>/Out1'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T JoystickSensitivity_Gain;     /* Expression: 0.15
                                        * Referenced by: '<S80>/Joystick Sensitivity'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S80>/Switch'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T Out1_Y0_g;                    /* Expression: 0
                                        * Referenced by: '<S90>/Out1'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S90>/Constant'
                                        */
  real_T JoystickSensitivity_Gain_j;   /* Expression: 0.15
                                        * Referenced by: '<S98>/Joystick Sensitivity'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0.5
                                        * Referenced by: '<S98>/Switch'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T Out1_Y0_l;                    /* Expression: 0
                                        * Referenced by: '<S108>/Out1'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T Joystickthrottlescaling_Gain; /* Expression: 0.8
                                        * Referenced by: '<S117>/Joystick throttle scaling'
                                        */
  real_T Switch_Threshold_ak;          /* Expression: 0.5
                                        * Referenced by: '<S116>/Switch'
                                        */
  real_T Out1_Y0_gt;                   /* Expression: 0
                                        * Referenced by: '<S133>/Out1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S133>/Constant'
                                        */
  real_T Out1_Y0_lz;                   /* Expression: 0
                                        * Referenced by: '<S134>/Out1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5e-4
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Motorenable_Value[2];         /* Expression: [1 1]
                                        * Referenced by: '<S3>/Motor enable'
                                        */
  real_T Memory_X0[4];                 /* Expression: [0 0 0 0]
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Memory_X0_b;                  /* Expression: 0
                                        * Referenced by: '<S62>/Memory'
                                        */
  real_T Constant_Value_b;             /* Expression: 3
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S48>/Integrator2'
                                        */
  real_T Constant3_Value;              /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant3'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 3
                                        * Referenced by: '<S23>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 0
                                        * Referenced by: '<S23>/Saturation'
                                        */
  real_T Memory_X0_g;                  /* Expression: 0
                                        * Referenced by: '<S28>/Memory'
                                        */
  real_T Constant_Value_g1;            /* Expression: 0.5
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S55>/Rate Transition'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * Referenced by: '<S54>/Rate Transition1'
                                        */
  real_T RateTransition_X0_o;          /* Expression: 0
                                        * Referenced by: '<S54>/Rate Transition'
                                        */
  real_T BatteryOnTop_Value;           /* Expression: 1
                                        * Referenced by: '<S23>/Battery On Top'
                                        */
  real_T BatteryOnBottom_Value;        /* Expression: 0
                                        * Referenced by: '<S23>/Battery On Bottom'
                                        */
  real_T SwitchBatteryConfigAcceleromter;/* Expression: 0.5
                                          * Referenced by: '<S23>/Switch Battery Config - Acceleromter (Top or Bottom)'
                                          */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S32>/x0'
                                        */
  real_T SwitchBatteryConfigGyroToporBot;/* Expression: 0.5
                                          * Referenced by: '<S23>/Switch Battery Config - Gyro (Top or Bottom)'
                                          */
  real_T Calibrationtimes_Value;       /* Expression: 1
                                        * Referenced by: '<S30>/Calibration time (s)'
                                        */
  real_T HighPassFilterRoll_A;         /* Computed Parameter: HighPassFilterRoll_A
                                        * Referenced by: '<S29>/High Pass Filter - Roll'
                                        */
  real_T HighPassFilterRoll_C;         /* Computed Parameter: HighPassFilterRoll_C
                                        * Referenced by: '<S29>/High Pass Filter - Roll'
                                        */
  real_T HighPassFilterRoll_D;         /* Computed Parameter: HighPassFilterRoll_D
                                        * Referenced by: '<S29>/High Pass Filter - Roll'
                                        */
  real_T Constant_Value_jv;            /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T HighPassFilterPitch_A;        /* Computed Parameter: HighPassFilterPitch_A
                                        * Referenced by: '<S29>/High Pass Filter - Pitch'
                                        */
  real_T HighPassFilterPitch_C;        /* Computed Parameter: HighPassFilterPitch_C
                                        * Referenced by: '<S29>/High Pass Filter - Pitch'
                                        */
  real_T HighPassFilterPitch_D;        /* Computed Parameter: HighPassFilterPitch_D
                                        * Referenced by: '<S29>/High Pass Filter - Pitch'
                                        */
  real_T Constant1_Value;              /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Integrator2_IC_m;             /* Expression: 0
                                        * Referenced by: '<S49>/Integrator2'
                                        */
  real_T Integrator2_IC_a;             /* Expression: 0
                                        * Referenced by: '<S50>/Integrator2'
                                        */
  real_T Gain5_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain4'
                                        */
  real_T x0_Value_a;                   /* Expression: input_init
                                        * Referenced by: '<S47>/x0'
                                        */
  real_T HighPassFilterYaw_A;          /* Computed Parameter: HighPassFilterYaw_A
                                        * Referenced by: '<S29>/High Pass Filter - Yaw'
                                        */
  real_T HighPassFilterYaw_C;          /* Computed Parameter: HighPassFilterYaw_C
                                        * Referenced by: '<S29>/High Pass Filter - Yaw'
                                        */
  real_T HighPassFilterYaw_D;          /* Computed Parameter: HighPassFilterYaw_D
                                        * Referenced by: '<S29>/High Pass Filter - Yaw'
                                        */
  real_T Constant2_Value;              /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Gain8_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain8'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T Gain7_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain7'
                                        */
  real_T Gain2_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain2'
                                        */
  real_T Gain6_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain6'
                                        */
  real_T Constant_Value_mn;            /* Expression: 2
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Integrator2_IC_e;             /* Expression: 0
                                        * Referenced by: '<S47>/Integrator2'
                                        */
  real_T InverseModulus_Modulus;       /* Expression: modulus
                                        * Referenced by: '<S4>/Inverse Modulus'
                                        */
  real_T Constant_Value_hq;            /* Expression: 2
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T x0_Value_h;                   /* Expression: input_init
                                        * Referenced by: '<S48>/x0'
                                        */
  real_T Constant_Value_h3;            /* Expression: 2
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T x0_Value_c;                   /* Expression: input_init
                                        * Referenced by: '<S49>/x0'
                                        */
  real_T Constant_Value_p0;            /* Expression: 2
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T x0_Value_k;                   /* Expression: input_init
                                        * Referenced by: '<S50>/x0'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S54>/Unit Delay'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 2
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Integrator2_IC_k;             /* Expression: 0
                                        * Referenced by: '<S32>/Integrator2'
                                        */
  real_T initialaccel_Value[3];        /* Expression: [0 0 -9.81]
                                        * Referenced by: '<S27>/initial accel'
                                        */
  real_T Calibrationtimes_Value_e;     /* Expression: 1
                                        * Referenced by: '<S27>/Calibration time (s)'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: -9.0
                                        * Referenced by: '<S23>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -9.8
                                        * Referenced by: '<S23>/Saturation2'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S23>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S23>/Transfer Fcn'
                                        */
  real_T HILWatchdog_Timeout;          /* Expression: timeout
                                        * Referenced by: '<S3>/HIL Watchdog'
                                        */
  real_T LPF_A;                        /* Computed Parameter: LPF_A
                                        * Referenced by: '<S14>/LPF'
                                        */
  real_T LPF_C;                        /* Computed Parameter: LPF_C
                                        * Referenced by: '<S14>/LPF'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  real_T HPF_A;                        /* Computed Parameter: HPF_A
                                        * Referenced by: '<S14>/HPF'
                                        */
  real_T HPF_C;                        /* Computed Parameter: HPF_C
                                        * Referenced by: '<S14>/HPF'
                                        */
  real_T HPF_D;                        /* Computed Parameter: HPF_D
                                        * Referenced by: '<S14>/HPF'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T LPF1_A;                       /* Computed Parameter: LPF1_A
                                        * Referenced by: '<S15>/LPF1'
                                        */
  real_T LPF1_C;                       /* Computed Parameter: LPF1_C
                                        * Referenced by: '<S15>/LPF1'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T HPF1_A;                       /* Computed Parameter: HPF1_A
                                        * Referenced by: '<S15>/HPF1'
                                        */
  real_T HPF1_C;                       /* Computed Parameter: HPF1_C
                                        * Referenced by: '<S15>/HPF1'
                                        */
  real_T HPF1_D;                       /* Computed Parameter: HPF1_D
                                        * Referenced by: '<S15>/HPF1'
                                        */
  real_T LowPassFilterFilteredYawRate_A;/* Computed Parameter: LowPassFilterFilteredYawRate_A
                                         * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate)'
                                         */
  real_T LowPassFilterFilteredYawRate_C;/* Computed Parameter: LowPassFilterFilteredYawRate_C
                                         * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate)'
                                         */
  real_T SwitchKd_Threshold;           /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch - Kd'
                                        */
  real_T headingcommand_Value;         /* Expression: 0*pi/180
                                        * Referenced by: '<S7>/heading command'
                                        */
  real_T RateLimiter_RisingLim;        /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  real_T Bias_Bias;                    /* Expression: 0
                                        * Referenced by: '<S13>/Bias'
                                        */
  real_T SwitchKp_Threshold;           /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch - Kp'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S119>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S119>/Saturation3'
                                        */
  real_T Integrator2_IC_kr;            /* Expression: 0
                                        * Referenced by: '<S139>/Integrator2'
                                        */
  real_T SwitchKd_Threshold_p;         /* Expression: 0.5
                                        * Referenced by: '<S131>/Switch - Kd'
                                        */
  real_T vmaxtakeoff_Value;            /* Expression: 2
                                        * Referenced by: '<S135>/vmax takeoff'
                                        */
  real_T amaxtakeoff_Value;            /* Expression: 0.2
                                        * Referenced by: '<S135>/amax takeoff'
                                        */
  real_T Constant_Value_aa;            /* Expression: 0
                                        * Referenced by: '<S129>/Constant'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S66>/Constant2'
                                        */
  real_T CLOSEDLOOPON_Value;           /* Expression: 1
                                        * Referenced by: '<S5>/CLOSED-LOOP ON'
                                        */
  real_T JOYSTICKON_Value;             /* Expression: 0
                                        * Referenced by: '<S5>/JOYSTICK ON'
                                        */
  real_T Constant1_Value_n;            /* Expression: 1
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T SignalGenerator_Amplitude;    /* Expression: 0
                                        * Referenced by: '<S7>/Signal Generator'
                                        */
  real_T SignalGenerator_Frequency;    /* Expression: 0.0125
                                        * Referenced by: '<S7>/Signal Generator'
                                        */
  real_T Constant1_Value_m;            /* Expression: qc_get_step_size
                                        * Referenced by: '<S116>/Constant1'
                                        */
  real_T Constant_Value_c2;            /* Expression: 0
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0.5
                                        * Referenced by: '<S129>/Switch'
                                        */
  real_T vmaxflight_Value;             /* Expression: 2
                                        * Referenced by: '<S135>/vmax flight'
                                        */
  real_T amaxflight_Value;             /* Expression: 10
                                        * Referenced by: '<S135>/amax flight'
                                        */
  real_T SwitchKp_Threshold_c;         /* Expression: 0.5
                                        * Referenced by: '<S131>/Switch - Kp'
                                        */
  real_T Memory_X0_j;                  /* Expression: 0
                                        * Referenced by: '<S138>/Memory'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S131>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S131>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S131>/Integrator'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S131>/Constant1'
                                        */
  real_T Constant_Value_bn;            /* Expression: 1.65e-4*20*0.5
                                        * Referenced by: '<S131>/Constant'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0.5
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S122>/Constant1'
                                        */
  real_T landthrottletarget_Value;     /* Expression: 0
                                        * Referenced by: '<S122>/land throttle target'
                                        */
  real_T Constant2_Value_f;            /* Expression: 5
                                        * Referenced by: '<S123>/Constant2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S123>/Constant1'
                                        */
  real_T Constant_Value_o5;            /* Expression: 0
                                        * Referenced by: '<S127>/Constant'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T LowPassFilterFilteredYawRateFor;/* Computed Parameter: LowPassFilterFilteredYawRateFor
                                          * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)'
                                          */
  real_T LowPassFilterFilteredYawRateF_c;/* Computed Parameter: LowPassFilterFilteredYawRateF_c
                                          * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)'
                                          */
  real_T DefaultJoystickCMDYaw_Value;  /* Expression: 0
                                        * Referenced by: '<S4>/Default Joystick CMD - Yaw'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T LowPassFilterFilteredPitchRate_;/* Computed Parameter: LowPassFilterFilteredPitchRate_
                                          * Referenced by: '<S81>/Low Pass Filter (Filtered Pitch Rate)'
                                          */
  real_T LowPassFilterFilteredPitchRat_e;/* Computed Parameter: LowPassFilterFilteredPitchRat_e
                                          * Referenced by: '<S81>/Low Pass Filter (Filtered Pitch Rate)'
                                          */
  real_T SwitchKd_Threshold_k;         /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch - Kd'
                                        */
  real_T Memory_X0_a;                  /* Expression: 0
                                        * Referenced by: '<S85>/Memory'
                                        */
  real_T DefaultJoystickCMDPitch_Value;/* Expression: 0
                                        * Referenced by: '<S4>/Default Joystick CMD - Pitch'
                                        */
  real_T Switch_Threshold_o;           /* Expression: 0.5
                                        * Referenced by: '<S83>/Switch'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 0.15
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T SwitchKp_Threshold_f;         /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch - Kp'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S81>/Integrator1'
                                        */
  real_T LowPassFilterFilteredRollRate_A;/* Computed Parameter: LowPassFilterFilteredRollRate_A
                                          * Referenced by: '<S97>/Low Pass Filter (Filtered Roll Rate)'
                                          */
  real_T LowPassFilterFilteredRollRate_C;/* Computed Parameter: LowPassFilterFilteredRollRate_C
                                          * Referenced by: '<S97>/Low Pass Filter (Filtered Roll Rate)'
                                          */
  real_T SwitchKd_Threshold_pr;        /* Expression: 0.5
                                        * Referenced by: '<S97>/Switch - Kd'
                                        */
  real_T Memory_X0_p;                  /* Expression: 0
                                        * Referenced by: '<S103>/Memory'
                                        */
  real_T DefaultJoystickCMDRoll_Value; /* Expression: 0
                                        * Referenced by: '<S4>/Default Joystick CMD - Roll'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0.5
                                        * Referenced by: '<S101>/Switch'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.15
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T SwitchKp_Threshold_g;         /* Expression: 0.5
                                        * Referenced by: '<S97>/Switch - Kp'
                                        */
  real_T Integrator1_IC_g;             /* Expression: 0
                                        * Referenced by: '<S97>/Integrator1'
                                        */
  real_T StepInitializezerothrottlefor3s;/* Expression: 3
                                          * Referenced by: '<S16>/Step Initialize zero throttle for 3 seconds'
                                          */
  real_T StepInitializezerothrottlefor_c;/* Expression: 0
                                          * Referenced by: '<S16>/Step Initialize zero throttle for 3 seconds'
                                          */
  real_T StepInitializezerothrottlefor_a;/* Expression: 1
                                          * Referenced by: '<S16>/Step Initialize zero throttle for 3 seconds'
                                          */
  real_T Constant2_Value_n;            /* Expression: 2
                                        * Referenced by: '<S20>/Constant2'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Constant_Value_k;             /* Expression: 3
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Memory_X0_h;                  /* Expression: 0
                                        * Referenced by: '<S61>/Memory'
                                        */
  real_T Constant_Value_d;             /* Expression: 3
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Memory_X0_m;                  /* Expression: 0
                                        * Referenced by: '<S63>/Memory'
                                        */
  real_T Integrator2_IC_b;             /* Expression: 0
                                        * Referenced by: '<S89>/Integrator2'
                                        */
  real_T SwitchKd_Threshold_c;         /* Expression: 0.5
                                        * Referenced by: '<S86>/Switch - Kd'
                                        */
  real_T Constant2_Value_n3;           /* Expression: 1
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T TransportDelay_Delay;         /* Expression: 5
                                        * Referenced by: '<S7>/Transport Delay'
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S7>/Transport Delay'
                                        */
  real_T SwitchKp_Threshold_k;         /* Expression: 0.5
                                        * Referenced by: '<S86>/Switch - Kp'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * Referenced by: '<S86>/Integrator'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S86>/Gain4'
                                        */
  real_T Integrator2_IC_h;             /* Expression: 0
                                        * Referenced by: '<S107>/Integrator2'
                                        */
  real_T SwitchKd_Threshold_g;         /* Expression: 0.5
                                        * Referenced by: '<S104>/Switch - Kd'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T SignalGenerator1_Amplitude;   /* Expression: 0
                                        * Referenced by: '<S7>/Signal Generator1'
                                        */
  real_T SignalGenerator1_Frequency;   /* Expression: 0.05
                                        * Referenced by: '<S7>/Signal Generator1'
                                        */
  real_T SwitchKp_Threshold_fn;        /* Expression: 0.5
                                        * Referenced by: '<S104>/Switch - Kp'
                                        */
  real_T Integrator1_IC_b;             /* Expression: 0
                                        * Referenced by: '<S104>/Integrator1'
                                        */
  real_T Constant_Value_ni;            /* Expression: 2
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T x0_Value_b;                   /* Expression: input_init
                                        * Referenced by: '<S89>/x0'
                                        */
  real_T SwitchKi_Threshold;           /* Expression: 0.5
                                        * Referenced by: '<S86>/Switch - Ki'
                                        */
  real_T SwitchKi_Threshold_m;         /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch - Ki'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 180/pi
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T SignalGenerator2_Amplitude;   /* Expression: 1
                                        * Referenced by: '<S7>/Signal Generator2'
                                        */
  real_T SignalGenerator2_Frequency;   /* Expression: 0.05
                                        * Referenced by: '<S7>/Signal Generator2'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain4'
                                        */
  real_T SwitchKi_Threshold_c;         /* Expression: 0.5
                                        * Referenced by: '<S97>/Switch - Ki'
                                        */
  real_T Constant_Value_hg;            /* Expression: 2
                                        * Referenced by: '<S107>/Constant'
                                        */
  real_T x0_Value_p;                   /* Expression: input_init
                                        * Referenced by: '<S107>/x0'
                                        */
  real_T SwitchKi_Threshold_g;         /* Expression: 0.5
                                        * Referenced by: '<S104>/Switch - Ki'
                                        */
  real_T Gain1_Gain_ln;                /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T DummyHeadingReferencerad_Value;/* Expression: 0
                                         * Referenced by: '<S10>/Dummy Heading Reference (rad)'
                                         */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<S10>/Enable'
                                        */
  real_T Constant_Value_h3z;           /* Expression: 2
                                        * Referenced by: '<S139>/Constant'
                                        */
  real_T x0_Value_ch;                  /* Expression: input_init
                                        * Referenced by: '<S139>/x0'
                                        */
  real_T SwitchKi_Threshold_mj;        /* Expression: 0.5
                                        * Referenced by: '<S131>/Switch - Ki'
                                        */
  real_T SwitchKi_Threshold_b;         /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch - Ki'
                                        */
  int32_T StreamClient_SndPriority;    /* Computed Parameter: StreamClient_SndPriority
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  int32_T StreamClient_RcvPriority;    /* Computed Parameter: StreamClient_RcvPriority
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  int32_T StreamServer_SndPriority;    /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  int32_T StreamServer_RcvPriority;    /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  uint32_T StreamClient_SndSize;       /* Computed Parameter: StreamClient_SndSize
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  uint32_T StreamClient_RcvSize;       /* Computed Parameter: StreamClient_RcvSize
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  uint32_T StreamClient_SndFIFO;       /* Computed Parameter: StreamClient_SndFIFO
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  uint32_T StreamClient_RcvFIFO;       /* Computed Parameter: StreamClient_RcvFIFO
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  uint32_T ToHostFile_Decimation;      /* Computed Parameter: ToHostFile_Decimation
                                        * Referenced by: '<S9>/To Host File'
                                        */
  uint32_T StreamServer_SndSize;       /* Computed Parameter: StreamServer_SndSize
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  uint32_T StreamServer_RcvSize;       /* Computed Parameter: StreamServer_RcvSize
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  uint32_T StreamServer_SndFIFO;       /* Computed Parameter: StreamServer_SndFIFO
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  uint32_T StreamServer_RcvFIFO;       /* Computed Parameter: StreamServer_RcvFIFO
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  int8_T StreamClient_Optimize;        /* Computed Parameter: StreamClient_Optimize
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  int8_T StreamClient_Implementation;  /* Computed Parameter: StreamClient_Implementation
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  int8_T StreamServer_Optimize;        /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  int8_T StreamServer_Implementation;  /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  uint8_T StringConstant1_Value[80];   /* Expression: value
                                        * Referenced by: '<S12>/String Constant1'
                                        */
  uint8_T StreamClient_URI;            /* Expression: uri_argument
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  uint8_T StreamClient_Endian;         /* Computed Parameter: StreamClient_Endian
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  uint8_T BatteryTopOrBottom_CurrentSetti;/* Computed Parameter: BatteryTopOrBottom_CurrentSetti
                                           * Referenced by: '<S23>/Battery Top Or Bottom'
                                           */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S15>/Manual Switch'
                                        */
  uint8_T ManualSwitch_CurrentSetting_m;/* Computed Parameter: ManualSwitch_CurrentSetting_m
                                         * Referenced by: '<S119>/Manual Switch'
                                         */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch2'
                                        */
  uint8_T ManualSwitch_CurrentSetting_f;/* Computed Parameter: ManualSwitch_CurrentSetting_f
                                         * Referenced by: '<S131>/Manual Switch'
                                         */
  uint8_T ManualSwitch_CurrentSetting_l;/* Computed Parameter: ManualSwitch_CurrentSetting_l
                                         * Referenced by: '<S123>/Manual Switch'
                                         */
  uint8_T ManualSwitch4_CurrentSetting;/* Computed Parameter: ManualSwitch4_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch4'
                                        */
  uint8_T ManualSwitch_CurrentSetting_lk;/* Computed Parameter: ManualSwitch_CurrentSetting_lk
                                          * Referenced by: '<S6>/Manual Switch'
                                          */
  uint8_T ManualSwitch_CurrentSetting_j;/* Computed Parameter: ManualSwitch_CurrentSetting_j
                                         * Referenced by: '<S81>/Manual Switch'
                                         */
  uint8_T ManualSwitch_CurrentSetting_k;/* Computed Parameter: ManualSwitch_CurrentSetting_k
                                         * Referenced by: '<S8>/Manual Switch'
                                         */
  uint8_T ManualSwitch_CurrentSetting_h;/* Computed Parameter: ManualSwitch_CurrentSetting_h
                                         * Referenced by: '<S97>/Manual Switch'
                                         */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<S7>/Manual Switch1'
                                        */
  uint8_T ManualSwitch2_CurrentSetting_c;/* Computed Parameter: ManualSwitch2_CurrentSetting_c
                                          * Referenced by: '<S7>/Manual Switch2'
                                          */
  uint8_T ToHostFile_file_name[43];    /* Expression: file_name_argument
                                        * Referenced by: '<S9>/To Host File'
                                        */
  uint8_T ToHostFile_VarName[11];      /* Expression: variable_name_argument
                                        * Referenced by: '<S9>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat;       /* Computed Parameter: ToHostFile_FileFormat
                                        * Referenced by: '<S9>/To Host File'
                                        */
  uint8_T StreamServer_URI[24];        /* Expression: uri_argument
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  uint8_T StreamServer_Endian;         /* Computed Parameter: StreamServer_Endian
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  boolean_T timeout_Y0;                /* Computed Parameter: timeout_Y0
                                        * Referenced by: '<S22>/timeout'
                                        */
  boolean_T timeout_Y0_k;              /* Computed Parameter: timeout_Y0_k
                                        * Referenced by: '<S76>/timeout'
                                        */
  boolean_T HILReadWrite1_Active;      /* Computed Parameter: HILReadWrite1_Active
                                        * Referenced by: '<S3>/HIL Read Write1'
                                        */
  boolean_T StreamClient_Active;       /* Computed Parameter: StreamClient_Active
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  boolean_T HILWatchdog_Active;        /* Computed Parameter: HILWatchdog_Active
                                        * Referenced by: '<S3>/HIL Watchdog'
                                        */
  boolean_T StreamServer_Active;       /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  P_EnabledSubsystem1_leader_qb_T EnabledSubsystem1_b;/* '<S123>/Enabled Subsystem1' */
  P_EnabledSubsystem1_leader_qb_T EnabledSubsystem1;/* '<S66>/Enabled Subsystem1' */
  P_EnabledMovingAverage_leader_T EnabledMovingAverage_e;/* '<S27>/Enabled Moving Average' */
  P_EnabledMovingAverage_leader_T EnabledMovingAverage_c;/* '<S31>/Enabled Moving Average' */
};

/* Real-time Model Data Structure */
struct tag_RTM_leader_qball2_mytest_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_leader_qball2_mytest_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][40];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
      uint8_T cLimit[3];
    } TaskCounters;

    struct {
      uint8_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_leader_qball2_mytest_T leader_qball2_mytest_P;

/* Block signals (auto storage) */
extern B_leader_qball2_mytest_T leader_qball2_mytest_B;

/* Continuous states (auto storage) */
extern X_leader_qball2_mytest_T leader_qball2_mytest_X;

/* Block states (auto storage) */
extern DW_leader_qball2_mytest_T leader_qball2_mytest_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_leader_qball2_mytest_T leader_qball2_mytest_PrevZCX;

/* Model entry point functions */
extern void leader_qball2_mytest_initialize(void);
extern void leader_qball2_mytest_step0(void);
extern void leader_qball2_mytest_step(int_T tid);
extern void leader_qball2_mytest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_leader_qball2_mytest_T *const leader_qball2_mytest_M;

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
 * '<Root>' : 'leader_qball2_mytest'
 * '<S1>'   : 'leader_qball2_mytest/Calculate Roll Pitch'
 * '<S2>'   : 'leader_qball2_mytest/Control signal mixing'
 * '<S3>'   : 'leader_qball2_mytest/DAQ'
 * '<S4>'   : 'leader_qball2_mytest/Data from host'
 * '<S5>'   : 'leader_qball2_mytest/Mode control'
 * '<S6>'   : 'leader_qball2_mytest/Pitch Controller'
 * '<S7>'   : 'leader_qball2_mytest/Position Commands'
 * '<S8>'   : 'leader_qball2_mytest/Roll Controller'
 * '<S9>'   : 'leader_qball2_mytest/SAVE DATA (black box)'
 * '<S10>'  : 'leader_qball2_mytest/Serve Data For Follower'
 * '<S11>'  : 'leader_qball2_mytest/Throttle and height control'
 * '<S12>'  : 'leader_qball2_mytest/URI Definitions'
 * '<S13>'  : 'leader_qball2_mytest/Yaw Controller'
 * '<S14>'  : 'leader_qball2_mytest/Calculate Roll Pitch/Calculate Pitch'
 * '<S15>'  : 'leader_qball2_mytest/Calculate Roll Pitch/Calculate Roll'
 * '<S16>'  : 'leader_qball2_mytest/Control signal mixing/Safety - Motor Shutoff if: - Roll//Pitch Data Runaway (> 40 deg) - Initial 3 second of execution for motor initialization'
 * '<S17>'  : 'leader_qball2_mytest/Control signal mixing/Safety - Motor Shutoff if: - Roll//Pitch Data Runaway (> 40 deg) - Initial 3 second of execution for motor initialization/Compare To Constant1'
 * '<S18>'  : 'leader_qball2_mytest/Control signal mixing/Safety - Motor Shutoff if: - Roll//Pitch Data Runaway (> 40 deg) - Initial 3 second of execution for motor initialization/Compare To Constant2'
 * '<S19>'  : 'leader_qball2_mytest/Control signal mixing/Safety - Motor Shutoff if: - Roll//Pitch Data Runaway (> 40 deg) - Initial 3 second of execution for motor initialization/Enabled Subsystem'
 * '<S20>'  : 'leader_qball2_mytest/Control signal mixing/Safety - Motor Shutoff if: - Roll//Pitch Data Runaway (> 40 deg) - Initial 3 second of execution for motor initialization/throttle enable'
 * '<S21>'  : 'leader_qball2_mytest/Control signal mixing/Safety - Motor Shutoff if: - Roll//Pitch Data Runaway (> 40 deg) - Initial 3 second of execution for motor initialization/throttle enable/Compare To Constant'
 * '<S22>'  : 'leader_qball2_mytest/Control signal mixing/Safety - Motor Shutoff if: - Roll//Pitch Data Runaway (> 40 deg) - Initial 3 second of execution for motor initialization/throttle enable/Enabled Subsystem'
 * '<S23>'  : 'leader_qball2_mytest/DAQ/Initialize sensors'
 * '<S24>'  : 'leader_qball2_mytest/DAQ/Low battery check'
 * '<S25>'  : 'leader_qball2_mytest/DAQ/spike detection'
 * '<S26>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data'
 * '<S27>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate accelerometer (Obsolete)'
 * '<S28>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Nonlinear Limit (Reject Spikes)'
 * '<S29>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering'
 * '<S30>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Zero gyro'
 * '<S31>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/Bias Removal'
 * '<S32>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/Second-Order Low-Pass Filter2'
 * '<S33>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/correct accel mounting'
 * '<S34>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/Bias Removal/Enabled Moving Average'
 * '<S35>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/Bias Removal/Switch Case Action Subsystem'
 * '<S36>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/Bias Removal/Switch Case Action Subsystem1'
 * '<S37>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/Bias Removal/Switch Case Action Subsystem2'
 * '<S38>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate Accelerometer Data/Bias Removal/Enabled Moving Average/Increment'
 * '<S39>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate accelerometer (Obsolete)/Enabled Moving Average'
 * '<S40>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Calibrate accelerometer (Obsolete)/Enabled Moving Average/Increment'
 * '<S41>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Nonlinear Limit (Reject Spikes)/Embedded MATLAB Function'
 * '<S42>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Calculate Roll and Pitch (From Acceleration Data)'
 * '<S43>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Height'
 * '<S44>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Pitch'
 * '<S45>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Roll'
 * '<S46>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Kalman Filter - Yaw'
 * '<S47>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Second-Order Low-Pass Filter3'
 * '<S48>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Second-Order Low-Pass Filter4'
 * '<S49>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Second-Order Low-Pass Filter5'
 * '<S50>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Second-Order Low-Pass Filter7'
 * '<S51>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Signal Conditioning - Sonar'
 * '<S52>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Calculate Roll and Pitch (From Acceleration Data)/calc_roll_pitch'
 * '<S53>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Calculate Roll and Pitch (From Acceleration Data)/calc_roll_pitch_asin'
 * '<S54>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Signal Conditioning - Sonar/FOH1'
 * '<S55>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Signal Conditioning - Sonar/Sampler'
 * '<S56>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Sensor Fusion//Filtering/Signal Conditioning - Sonar/Sampler/Triggered Subsystem'
 * '<S57>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Zero gyro/Enabled Moving Average'
 * '<S58>'  : 'leader_qball2_mytest/DAQ/Initialize sensors/Zero gyro/Enabled Moving Average/Increment'
 * '<S59>'  : 'leader_qball2_mytest/DAQ/Low battery check/Compare To Constant'
 * '<S60>'  : 'leader_qball2_mytest/DAQ/spike detection/Compare To Constant'
 * '<S61>'  : 'leader_qball2_mytest/Data from host/Subsystem4'
 * '<S62>'  : 'leader_qball2_mytest/Data from host/Subsystem5'
 * '<S63>'  : 'leader_qball2_mytest/Data from host/Subsystem6'
 * '<S64>'  : 'leader_qball2_mytest/Data from host/Subsystem7'
 * '<S65>'  : 'leader_qball2_mytest/Data from host/rcvd packet monitoring'
 * '<S66>'  : 'leader_qball2_mytest/Data from host/timeout safety'
 * '<S67>'  : 'leader_qball2_mytest/Data from host/Subsystem4/Embedded MATLAB Function'
 * '<S68>'  : 'leader_qball2_mytest/Data from host/Subsystem5/Embedded MATLAB Function'
 * '<S69>'  : 'leader_qball2_mytest/Data from host/Subsystem6/Embedded MATLAB Function'
 * '<S70>'  : 'leader_qball2_mytest/Data from host/Subsystem7/Compare To Constant'
 * '<S71>'  : 'leader_qball2_mytest/Data from host/Subsystem7/Compare To Constant1'
 * '<S72>'  : 'leader_qball2_mytest/Data from host/rcvd packet monitoring/spike detection'
 * '<S73>'  : 'leader_qball2_mytest/Data from host/rcvd packet monitoring/spike detection/Compare To Constant'
 * '<S74>'  : 'leader_qball2_mytest/Data from host/timeout safety/Compare To Constant'
 * '<S75>'  : 'leader_qball2_mytest/Data from host/timeout safety/Compare To Constant1'
 * '<S76>'  : 'leader_qball2_mytest/Data from host/timeout safety/Enabled Subsystem'
 * '<S77>'  : 'leader_qball2_mytest/Data from host/timeout safety/Enabled Subsystem1'
 * '<S78>'  : 'leader_qball2_mytest/Data from host/timeout safety/Enabled Subsystem2'
 * '<S79>'  : 'leader_qball2_mytest/Data from host/timeout safety/Enabled Subsystem Latch Output High'
 * '<S80>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem'
 * '<S81>'  : 'leader_qball2_mytest/Pitch Controller/pitch controller'
 * '<S82>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/OT pos control'
 * '<S83>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/Safety - Emergency Landing Zero Ref CMD'
 * '<S84>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/OT pos control/Compare To Constant'
 * '<S85>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/OT pos control/adjust_for_heading'
 * '<S86>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/OT pos control/rate limitted control'
 * '<S87>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/OT pos control/adjust_for_heading/adjust_pitch_command'
 * '<S88>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/OT pos control/rate limitted control/Integrator reset'
 * '<S89>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/OT pos control/rate limitted control/Second-Order Low-Pass Filter1'
 * '<S90>'  : 'leader_qball2_mytest/Pitch Controller/Subsystem/Safety - Emergency Landing Zero Ref CMD/Enabled Subsystem'
 * '<S91>'  : 'leader_qball2_mytest/Pitch Controller/pitch controller/Compare To Constant'
 * '<S92>'  : 'leader_qball2_mytest/Position Commands/Slider Gain'
 * '<S93>'  : 'leader_qball2_mytest/Position Commands/Slider Gain1'
 * '<S94>'  : 'leader_qball2_mytest/Position Commands/Slider Gain2'
 * '<S95>'  : 'leader_qball2_mytest/Position Commands/Slider Gain3'
 * '<S96>'  : 'leader_qball2_mytest/Position Commands/Slider Gain4'
 * '<S97>'  : 'leader_qball2_mytest/Roll Controller/Roll Controller'
 * '<S98>'  : 'leader_qball2_mytest/Roll Controller/Subsystem'
 * '<S99>'  : 'leader_qball2_mytest/Roll Controller/Roll Controller/Compare To Constant'
 * '<S100>' : 'leader_qball2_mytest/Roll Controller/Subsystem/OT pos control'
 * '<S101>' : 'leader_qball2_mytest/Roll Controller/Subsystem/Safety - Emergency Landing Zero Ref CMD'
 * '<S102>' : 'leader_qball2_mytest/Roll Controller/Subsystem/OT pos control/Compare To Constant'
 * '<S103>' : 'leader_qball2_mytest/Roll Controller/Subsystem/OT pos control/adjust_for_heading'
 * '<S104>' : 'leader_qball2_mytest/Roll Controller/Subsystem/OT pos control/rate limitted control'
 * '<S105>' : 'leader_qball2_mytest/Roll Controller/Subsystem/OT pos control/adjust_for_heading/adjust_roll_command'
 * '<S106>' : 'leader_qball2_mytest/Roll Controller/Subsystem/OT pos control/rate limitted control/Integrator reset'
 * '<S107>' : 'leader_qball2_mytest/Roll Controller/Subsystem/OT pos control/rate limitted control/Second-Order Low-Pass Filter1'
 * '<S108>' : 'leader_qball2_mytest/Roll Controller/Subsystem/Safety - Emergency Landing Zero Ref CMD/Enabled Subsystem'
 * '<S109>' : 'leader_qball2_mytest/SAVE DATA (black box)/Signals 1-10'
 * '<S110>' : 'leader_qball2_mytest/SAVE DATA (black box)/Signals 11-20'
 * '<S111>' : 'leader_qball2_mytest/SAVE DATA (black box)/Signals 21-30'
 * '<S112>' : 'leader_qball2_mytest/SAVE DATA (black box)/Signals 31-40'
 * '<S113>' : 'leader_qball2_mytest/SAVE DATA (black box)/Signals 41-50'
 * '<S114>' : 'leader_qball2_mytest/SAVE DATA (black box)/Signals 51-60'
 * '<S115>' : 'leader_qball2_mytest/SAVE DATA (black box)/Signals 61-70'
 * '<S116>' : 'leader_qball2_mytest/Throttle and height control/Height joystick adjust'
 * '<S117>' : 'leader_qball2_mytest/Throttle and height control/Joystick mode throttle'
 * '<S118>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed '
 * '<S119>' : 'leader_qball2_mytest/Throttle and height control/height control'
 * '<S120>' : 'leader_qball2_mytest/Throttle and height control/Height joystick adjust/MATLAB Function'
 * '<S121>' : 'leader_qball2_mytest/Throttle and height control/Joystick mode throttle/Joystick to Throttle  Mapping'
 * '<S122>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Limit descent rate'
 * '<S123>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Subsystem'
 * '<S124>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Limit descent rate/Triggered Sigmoid'
 * '<S125>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Limit descent rate/Triggered Sigmoid/Triggered Sigmoid Compute'
 * '<S126>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Subsystem/Compare To Constant'
 * '<S127>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Subsystem/Compare To Zero'
 * '<S128>' : 'leader_qball2_mytest/Throttle and height control/Safety - Active During Emergency Landing: Ramp Throttle CMD down to zero if Sonar Failed /Subsystem/Enabled Subsystem1'
 * '<S129>' : 'leader_qball2_mytest/Throttle and height control/height control/Safety - Emergency Landing (Set Height Ref CMD to zero)'
 * '<S130>' : 'leader_qball2_mytest/Throttle and height control/height control/sigmoid1'
 * '<S131>' : 'leader_qball2_mytest/Throttle and height control/height control/sonar controller'
 * '<S132>' : 'leader_qball2_mytest/Throttle and height control/height control/sonar height'
 * '<S133>' : 'leader_qball2_mytest/Throttle and height control/height control/Safety - Emergency Landing (Set Height Ref CMD to zero)/Enabled Subsystem'
 * '<S134>' : 'leader_qball2_mytest/Throttle and height control/height control/sigmoid1/arm height command'
 * '<S135>' : 'leader_qball2_mytest/Throttle and height control/height control/sigmoid1/sigmoid limits'
 * '<S136>' : 'leader_qball2_mytest/Throttle and height control/height control/sigmoid1/sigmoid limits/Compare To Constant'
 * '<S137>' : 'leader_qball2_mytest/Throttle and height control/height control/sigmoid1/sigmoid limits/Compare To Constant1'
 * '<S138>' : 'leader_qball2_mytest/Throttle and height control/height control/sonar controller/Integrator reset'
 * '<S139>' : 'leader_qball2_mytest/Throttle and height control/height control/sonar controller/Second-Order Low-Pass Filter'
 * '<S140>' : 'leader_qball2_mytest/Throttle and height control/height control/sonar controller/User-controller landing state machine'
 * '<S141>' : 'leader_qball2_mytest/Yaw Controller/Compare To Constant'
 * '<S142>' : 'leader_qball2_mytest/Yaw Controller/Joystick yaw  control gain'
 * '<S143>' : 'leader_qball2_mytest/Yaw Controller/Joystick yaw command gain'
 * '<S144>' : 'leader_qball2_mytest/Yaw Controller/Joystick yaw command gain1'
 */
#endif                                 /* RTW_HEADER_leader_qball2_mytest_h_ */
