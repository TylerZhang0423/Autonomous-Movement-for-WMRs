/*
 * follower_qbot2.h
 *
 * Code generation for model "follower_qbot2".
 *
 * Model version              : 1.94
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 17:54:36 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_follower_qbot2_h_
#define RTW_HEADER_follower_qbot2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef follower_qbot2_COMMON_INCLUDES_
# define follower_qbot2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_string.h"
#include "quanser_memory.h"
#include "stream_client_block.h"
#include "quanser_extern.h"
#endif                                 /* follower_qbot2_COMMON_INCLUDES_ */

#include "follower_qbot2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<S13>/Switch Case Action Subsystem' */
typedef struct {
  int8_T SwitchCaseActionSubsystem_Subsy;/* '<S13>/Switch Case Action Subsystem' */
} DW_SwitchCaseActionSubsystem__T;

/* Block signals (auto storage) */
typedef struct {
  real_T StreamClient_o3[4];           /* '<S1>/Stream Client' */
  real_T DataTypeConversion;           /* '<S1>/Data Type Conversion' */
  real_T StreamClient_o3_f[3];         /* '<S2>/Stream Client' */
  real_T DataTypeConversion_n;         /* '<S2>/Data Type Conversion' */
  real_T Switch[3];                    /* '<S3>/Switch' */
  real_T Switch1[3];                   /* '<S3>/Switch1' */
  real_T SwitchArrived[3];             /* '<S4>/Switch - Arrived' */
  real_T x0;                           /* '<S33>/x0' */
  real_T ManualSwitchQBot2Enable;      /* '<Root>/Manual Switch - QBot 2 Enable' */
  real_T RateLimiterLinearSpeed;       /* '<S5>/Rate Limiter - Linear Speed' */
  real_T x0_l;                         /* '<S34>/x0' */
  real_T RateLimiterRotationRate;      /* '<S5>/Rate Limiter - Rotation Rate' */
  real_T Product;                      /* '<S33>/Product' */
  real_T Product1;                     /* '<S33>/Product1' */
  real_T Product_k;                    /* '<S34>/Product' */
  real_T Product1_j;                   /* '<S34>/Product1' */
  real_T Vf;                           /* '<S35>/Way Point Control' */
  real_T W;                            /* '<S35>/Way Point Control' */
  real_T vR;                           /* '<S24>/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)' */
  real_T vL;                           /* '<S24>/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)' */
  real_T div_e[2];                     /* '<S17>/div' */
  int32_T StreamClient_o2;             /* '<S1>/Stream Client' */
  int32_T StreamClient_o2_i;           /* '<S2>/Stream Client' */
  boolean_T StreamClient_o4;           /* '<S1>/Stream Client' */
  boolean_T RelationalOperator;        /* '<S10>/Relational Operator' */
  boolean_T RelationalOperator_b;      /* '<S11>/Relational Operator' */
  boolean_T StreamClient_o4_d;         /* '<S2>/Stream Client' */
  boolean_T RelationalOperator_l;      /* '<S12>/Relational Operator' */
  boolean_T LogicalOperator1;          /* '<S3>/Logical Operator1' */
} B_follower_qbot2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S10>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S11>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S12>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S31>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE;             /* '<S27>/Sum( k=1,n-1, x(k) )' */
  real_T UnitDelay_DSTATE_e;           /* '<S21>/Unit Delay' */
  real_T Sumk1n1xk_DSTATE_k[2];        /* '<S17>/Sum( k=1,n-1, x(k) )' */
  real_T HILInitialize_AIMinimums[10]; /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[10]; /* '<Root>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[4];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[4];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POValues[4];    /* '<Root>/HIL Initialize' */
  real_T HILInitialize_OOValues[4];    /* '<Root>/HIL Initialize' */
  real_T Memory_PreviousInput[3];      /* '<S3>/Memory' */
  real_T Memory1_PreviousInput[3];     /* '<S3>/Memory1' */
  real_T PrevY;                        /* '<S5>/Rate Limiter - Linear Speed' */
  real_T LastMajorTime;                /* '<S5>/Rate Limiter - Linear Speed' */
  real_T PrevY_o;                      /* '<S5>/Rate Limiter - Rotation Rate' */
  real_T LastMajorTime_c;              /* '<S5>/Rate Limiter - Rotation Rate' */
  real_T HILWrite_OtherBuffer[2];      /* '<S26>/HIL Write' */
  real_T Memory_PreviousInput_e;       /* '<S35>/Memory' */
  real_T Vf_1;                         /* '<S35>/Way Point Control' */
  real_T end_flag;                     /* '<S35>/Way Point Control' */
  t_pstream StreamClient_Stream;       /* '<S1>/Stream Client' */
  t_pstream StreamClient_Stream_o;     /* '<S2>/Stream Client' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *HILRead1_PWORK;                /* '<S26>/HIL Read1' */
  void *HILWrite_PWORK;                /* '<S26>/HIL Write' */
  int32_T HILInitialize_QuadratureModes[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[4];/* '<Root>/HIL Initialize' */
  int32_T HILRead1_EncoderBuffer[2];   /* '<S26>/HIL Read1' */
  uint32_T HILInitialize_POSortedChans[4];/* '<Root>/HIL Initialize' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S33>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_p;               /* '<S34>/Integrator1' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S10>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S11>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S12>/Discrete-Time Integrator' */
  int8_T EnabledMovingAverage_SubsysRanB;/* '<S25>/Enabled Moving Average' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S25>/Switch Case' */
  int8_T SwitchCaseActionSubsystem1_Subs;/* '<S25>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem2_Subs;/* '<S25>/Switch Case Action Subsystem2' */
  int8_T EnabledMovingAverage_SubsysRa_e;/* '<S13>/Enabled Moving Average' */
  int8_T SwitchCase_ActiveSubsystem_p; /* '<S13>/Switch Case' */
  int8_T SwitchCaseActionSubsystem1_Su_m;/* '<S13>/Switch Case Action Subsystem1' */
  int8_T SwitchCaseActionSubsystem2_Su_j;/* '<S13>/Switch Case Action Subsystem2' */
  boolean_T StreamClient_Connected;    /* '<S1>/Stream Client' */
  boolean_T StreamClient_Connected_i;  /* '<S2>/Stream Client' */
  boolean_T EnabledMovingAverage_MODE; /* '<S25>/Enabled Moving Average' */
  boolean_T EnabledMovingAverage_MODE_g;/* '<S13>/Enabled Moving Average' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem_a;/* '<S25>/Switch Case Action Subsystem' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem;/* '<S13>/Switch Case Action Subsystem' */
} DW_follower_qbot2_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S33>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<S34>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S33>/Integrator2' */
  real_T Integrator2_CSTATE_e;         /* '<S34>/Integrator2' */
} X_follower_qbot2_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S33>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<S34>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S33>/Integrator2' */
  real_T Integrator2_CSTATE_e;         /* '<S34>/Integrator2' */
} XDot_follower_qbot2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S33>/Integrator1' */
  boolean_T Integrator1_CSTATE_l;      /* '<S34>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S33>/Integrator2' */
  boolean_T Integrator2_CSTATE_e;      /* '<S34>/Integrator2' */
} XDis_follower_qbot2_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters for system: '<S13>/Switch Case Action Subsystem' */
struct P_SwitchCaseActionSubsystem_f_T_ {
  real_T zero_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S18>/zero'
                                        */
};

/* Parameters (auto storage) */
struct P_follower_qbot2_T_ {
  real_T HILInitialize_analog_input_maxi[9];/* Mask Parameter: HILInitialize_analog_input_maxi
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_analog_input_mini[9];/* Mask Parameter: HILInitialize_analog_input_mini
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T StreamClient_default_value[4];/* Mask Parameter: StreamClient_default_value
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  real_T StreamClient_default_value_g[3];/* Mask Parameter: StreamClient_default_value_g
                                          * Referenced by: '<S2>/Stream Client'
                                          */
  real_T BiasRemoval_end_time;         /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S13>/Step: end_time'
                                        */
  real_T BiasRemoval_end_time_a;       /* Mask Parameter: BiasRemoval_end_time_a
                                        * Referenced by: '<S25>/Step: end_time'
                                        */
  real_T HILInitialize_final_other_outpu[4];/* Mask Parameter: HILInitialize_final_other_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_final_pwm_outputs;/* Mask Parameter: HILInitialize_final_pwm_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_other_out[4];/* Mask Parameter: HILInitialize_initial_other_out
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_initial_pwm_outpu;/* Mask Parameter: HILInitialize_initial_pwm_outpu
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T SecondOrderLowPassFilter1_input;/* Mask Parameter: SecondOrderLowPassFilter1_input
                                          * Referenced by: '<S33>/wn'
                                          */
  real_T SecondOrderLowPassFilter4_input;/* Mask Parameter: SecondOrderLowPassFilter4_input
                                          * Referenced by: '<S34>/wn'
                                          */
  real_T SecondOrderLowPassFilter1_inp_f;/* Mask Parameter: SecondOrderLowPassFilter1_inp_f
                                          * Referenced by: '<S33>/zt'
                                          */
  real_T SecondOrderLowPassFilter4_inp_i;/* Mask Parameter: SecondOrderLowPassFilter4_inp_i
                                          * Referenced by: '<S34>/zt'
                                          */
  real_T NormalizeVector_maxzero;      /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S16>/Switch'
                                        */
  real_T HILInitialize_pwm_frequency;  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_pwm_leading_deadb;/* Mask Parameter: HILInitialize_pwm_leading_deadb
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_pwm_trailing_dead;/* Mask Parameter: HILInitialize_pwm_trailing_dead
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_c;/* Mask Parameter: HILInitialize_set_other_outpu_c
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_n;/* Mask Parameter: HILInitialize_set_other_outpu_n
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_h;/* Mask Parameter: HILInitialize_set_other_outpu_h
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T BiasRemoval_start_time;       /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S13>/Step: start_time'
                                        */
  real_T BiasRemoval_start_time_g;     /* Mask Parameter: BiasRemoval_start_time_g
                                        * Referenced by: '<S25>/Step: start_time'
                                        */
  real_T BiasRemoval_switch_id;        /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T BiasRemoval_switch_id_m;      /* Mask Parameter: BiasRemoval_switch_id_m
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T HILInitialize_watchdog_pwm_outp;/* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  int32_T HILInitialize_initial_encoder_c;/* Mask Parameter: HILInitialize_initial_encoder_c
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_alignment; /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_configuration;/* Mask Parameter: HILInitialize_pwm_configuration
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_modes;     /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_polarity;  /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_watchdog_digital_;/* Mask Parameter: HILInitialize_watchdog_digital_
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  uint32_T HILRead1_analog_channels;   /* Mask Parameter: HILRead1_analog_channels
                                        * Referenced by: '<S26>/HIL Read1'
                                        */
  uint32_T HILInitialize_analog_input_chan[10];/* Mask Parameter: HILInitialize_analog_input_chan
                                                * Referenced by: '<Root>/HIL Initialize'
                                                */
  uint32_T HILRead1_digital_channels[3];/* Mask Parameter: HILRead1_digital_channels
                                         * Referenced by: '<S26>/HIL Read1'
                                         */
  uint32_T HILInitialize_encoder_channels[4];/* Mask Parameter: HILInitialize_encoder_channels
                                              * Referenced by: '<Root>/HIL Initialize'
                                              */
  uint32_T HILRead1_encoder_channels[2];/* Mask Parameter: HILRead1_encoder_channels
                                         * Referenced by: '<S26>/HIL Read1'
                                         */
  uint32_T HILRead1_other_channels;    /* Mask Parameter: HILRead1_other_channels
                                        * Referenced by: '<S26>/HIL Read1'
                                        */
  uint32_T HILWrite_other_channels[2]; /* Mask Parameter: HILWrite_other_channels
                                        * Referenced by: '<S26>/HIL Write'
                                        */
  uint32_T HILInitialize_other_output_chan[4];/* Mask Parameter: HILInitialize_other_output_chan
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILInitialize_pwm_channels[4];/* Mask Parameter: HILInitialize_pwm_channels
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  uint32_T HILInitialize_quadrature;   /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int8_T ShowMessageonHost_message_icon;/* Mask Parameter: ShowMessageonHost_message_icon
                                         * Referenced by: '<S3>/Show Message on Host'
                                         */
  int8_T ShowMessageonHost1_message_icon;/* Mask Parameter: ShowMessageonHost1_message_icon
                                          * Referenced by: '<S3>/Show Message on Host1'
                                          */
  int8_T ShowMessageonHost2_message_icon;/* Mask Parameter: ShowMessageonHost2_message_icon
                                          * Referenced by: '<S3>/Show Message on Host2'
                                          */
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint8_T CompareToConstant_const_k;   /* Mask Parameter: CompareToConstant_const_k
                                        * Referenced by: '<S9>/Constant'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  boolean_T HILInitialize_final_digital_out;/* Mask Parameter: HILInitialize_final_digital_out
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_initial_digital_o;/* Mask Parameter: HILInitialize_initial_digital_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_input_;/* Mask Parameter: HILInitialize_set_analog_input_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_inpu_g;/* Mask Parameter: HILInitialize_set_analog_inpu_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_o;/* Mask Parameter: HILInitialize_set_analog_outp_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_m;/* Mask Parameter: HILInitialize_set_analog_outp_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_out_oi;/* Mask Parameter: HILInitialize_set_analog_out_oi
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_out_o2;/* Mask Parameter: HILInitialize_set_analog_out_o2
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_k;/* Mask Parameter: HILInitialize_set_analog_outp_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_g;/* Mask Parameter: HILInitialize_set_analog_outp_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_k;/* Mask Parameter: HILInitialize_set_clock_frequ_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_f;/* Mask Parameter: HILInitialize_set_clock_param_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_j;/* Mask Parameter: HILInitialize_set_digital_out_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_g;/* Mask Parameter: HILInitialize_set_digital_out_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_m;/* Mask Parameter: HILInitialize_set_digital_out_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_m3;/* Mask Parameter: HILInitialize_set_digital_ou_m3
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_gg;/* Mask Parameter: HILInitialize_set_digital_ou_gg
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_d;/* Mask Parameter: HILInitialize_set_digital_out_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_count;/* Mask Parameter: HILInitialize_set_encoder_count
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_cou_f;/* Mask Parameter: HILInitialize_set_encoder_cou_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_param;/* Mask Parameter: HILInitialize_set_encoder_param
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_par_h;/* Mask Parameter: HILInitialize_set_encoder_par_h
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outpu_l;/* Mask Parameter: HILInitialize_set_other_outpu_l
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_d;/* Mask Parameter: HILInitialize_set_pwm_outputs_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_f;/* Mask Parameter: HILInitialize_set_pwm_outputs_f
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_b;/* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__c;/* Mask Parameter: HILInitialize_set_pwm_params__c
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T DummyAngle_Value;             /* Expression: 0
                                        * Referenced by: '<S4>/Dummy Angle'
                                        */
  real_T unity_Value;                  /* Expression: 1
                                        * Referenced by: '<S21>/unity'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S21>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S17>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T Vbiased_Y0;                   /* Expression: [0]
                                        * Referenced by: '<S19>/Vbiased'
                                        */
  real_T Vunbiased_Y0;                 /* Expression: [0]
                                        * Referenced by: '<S20>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0;            /* Expression: 0
                                        * Referenced by: '<S13>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal;        /* Expression: 1
                                        * Referenced by: '<S13>/Step: start_time'
                                        */
  real_T Stepend_time_Y0;              /* Expression: 0
                                        * Referenced by: '<S13>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal;          /* Expression: 1
                                        * Referenced by: '<S13>/Step: end_time'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T unity_Value_a;                /* Expression: 1
                                        * Referenced by: '<S31>/unity'
                                        */
  real_T UnitDelay_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay'
                                        */
  real_T Sumk1n1xk_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S27>/Sum( k=1,n-1, x(k) )'
                                        */
  real_T Vbiased_Y0_o;                 /* Expression: [0]
                                        * Referenced by: '<S29>/Vbiased'
                                        */
  real_T Vunbiased_Y0_p;               /* Expression: [0]
                                        * Referenced by: '<S30>/Vunbiased'
                                        */
  real_T Stepstart_time_Y0_g;          /* Expression: 0
                                        * Referenced by: '<S25>/Step: start_time'
                                        */
  real_T Stepstart_time_YFinal_p;      /* Expression: 1
                                        * Referenced by: '<S25>/Step: start_time'
                                        */
  real_T Stepend_time_Y0_g;            /* Expression: 0
                                        * Referenced by: '<S25>/Step: end_time'
                                        */
  real_T Stepend_time_YFinal_i;        /* Expression: 1
                                        * Referenced by: '<S25>/Step: end_time'
                                        */
  real_T SignalThreshold_Value;        /* Expression: 0.5
                                        * Referenced by: '<S3>/Signal Threshold'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S10>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  real_T TimeoutThresholds_Value;      /* Expression: 1
                                        * Referenced by: '<S3>/Timeout Threshold (s)'
                                        */
  real_T DiscreteTimeIntegrator_gainva_d;/* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                          * Referenced by: '<S11>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_n;  /* Expression: 0
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                          * Referenced by: '<S12>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T FollowingDistancem_Value;     /* Expression: 0.5
                                        * Referenced by: '<Root>/Following Distance (m)'
                                        */
  real_T LandingZoneBoundarym_Value;   /* Expression: 0.5
                                        * Referenced by: '<S4>/Landing Zone Boundary (m)'
                                        */
  real_T BoundaryZoneLimitm_Value;     /* Expression: 0.15
                                        * Referenced by: '<S4>/Boundary Zone Limit (m)'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S33>/x0'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Enable'
                                        */
  real_T Disable_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/Disable'
                                        */
  real_T RateLimiterLinearSpeed_RisingLi;/* Expression: 1
                                          * Referenced by: '<S5>/Rate Limiter - Linear Speed'
                                          */
  real_T RateLimiterLinearSpeed_FallingL;/* Expression: -1
                                          * Referenced by: '<S5>/Rate Limiter - Linear Speed'
                                          */
  real_T x0_Value_n;                   /* Expression: input_init
                                        * Referenced by: '<S34>/x0'
                                        */
  real_T RateLimiterRotationRate_RisingL;/* Expression: 1
                                          * Referenced by: '<S5>/Rate Limiter - Rotation Rate'
                                          */
  real_T RateLimiterRotationRate_Falling;/* Expression: -1
                                          * Referenced by: '<S5>/Rate Limiter - Rotation Rate'
                                          */
  real_T VLimit2_Value;                /* Expression: 10
                                        * Referenced by: '<Root>/V Limit2'
                                        */
  real_T Gain_Gain;                    /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Sequential_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Sequential'
                                        */
  real_T Simultaneous_Value;           /* Expression: 2
                                        * Referenced by: '<Root>/Simultaneous'
                                        */
  real_T VLimit_Value;                 /* Expression: 0.5
                                        * Referenced by: '<Root>/V Limit'
                                        */
  real_T VLimit1_Value;                /* Expression: 0.05
                                        * Referenced by: '<Root>/V Limit1'
                                        */
  real_T Kv_1_Value;                   /* Expression: 0.7
                                        * Referenced by: '<S7>/Kv_1'
                                        */
  real_T Kv_2_Value;                   /* Expression: 0.7
                                        * Referenced by: '<S7>/Kv_2'
                                        */
  real_T Kv_3_Value;                   /* Expression: 0.4
                                        * Referenced by: '<S7>/Kv_3'
                                        */
  real_T Kv_4_Value;                   /* Expression: 0.9
                                        * Referenced by: '<S7>/Kv_4'
                                        */
  real_T Constant_Value_d;             /* Expression: 2
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S33>/Integrator2'
                                        */
  real_T WaypointStep_Value;           /* Expression: 1
                                        * Referenced by: '<S7>/Waypoint Step'
                                        */
  real_T Memory_X0_n;                  /* Expression: [0]
                                        * Referenced by: '<S35>/Memory'
                                        */
  real_T Constant_Value_l;             /* Expression: 2
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Integrator2_IC_j;             /* Expression: 0
                                        * Referenced by: '<S34>/Integrator2'
                                        */
  int32_T StreamClient_SndPriority;    /* Computed Parameter: StreamClient_SndPriority
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  int32_T StreamClient_RcvPriority;    /* Computed Parameter: StreamClient_RcvPriority
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  int32_T StreamClient_SndPriority_n;  /* Computed Parameter: StreamClient_SndPriority_n
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  int32_T StreamClient_RcvPriority_p;  /* Computed Parameter: StreamClient_RcvPriority_p
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint32_T StreamClient_SndSize;       /* Computed Parameter: StreamClient_SndSize
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  uint32_T StreamClient_RcvSize;       /* Computed Parameter: StreamClient_RcvSize
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  uint32_T StreamClient_SndFIFO;       /* Computed Parameter: StreamClient_SndFIFO
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  uint32_T StreamClient_RcvFIFO;       /* Computed Parameter: StreamClient_RcvFIFO
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  uint32_T StreamClient_SndSize_a;     /* Computed Parameter: StreamClient_SndSize_a
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint32_T StreamClient_RcvSize_j;     /* Computed Parameter: StreamClient_RcvSize_j
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint32_T StreamClient_SndFIFO_h;     /* Computed Parameter: StreamClient_SndFIFO_h
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint32_T StreamClient_RcvFIFO_h;     /* Computed Parameter: StreamClient_RcvFIFO_h
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  int8_T StreamClient_Optimize;        /* Computed Parameter: StreamClient_Optimize
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  int8_T StreamClient_Implementation;  /* Computed Parameter: StreamClient_Implementation
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  int8_T StreamClient_Optimize_i;      /* Computed Parameter: StreamClient_Optimize_i
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  int8_T StreamClient_Implementation_g;/* Computed Parameter: StreamClient_Implementation_g
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint8_T StringConstant1_Value[80];   /* Expression: value
                                        * Referenced by: '<S6>/String Constant1'
                                        */
  uint8_T StreamClient_URI;            /* Expression: uri_argument
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  uint8_T StreamClient_Endian;         /* Computed Parameter: StreamClient_Endian
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  uint8_T StringConstant2_Value[80];   /* Expression: value
                                        * Referenced by: '<S6>/String Constant2'
                                        */
  uint8_T StreamClient_URI_o;          /* Expression: uri_argument
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint8_T StreamClient_Endian_i;       /* Computed Parameter: StreamClient_Endian_i
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  uint8_T ManualSwitchQBot2Enable_Current;/* Computed Parameter: ManualSwitchQBot2Enable_Current
                                           * Referenced by: '<Root>/Manual Switch - QBot 2 Enable'
                                           */
  uint8_T ManualSwitchTrackingMethod_Curr;/* Computed Parameter: ManualSwitchTrackingMethod_Curr
                                           * Referenced by: '<Root>/Manual Switch - Tracking Method'
                                           */
  boolean_T StreamClient_Active;       /* Computed Parameter: StreamClient_Active
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  boolean_T StreamClient_Active_j;     /* Computed Parameter: StreamClient_Active_j
                                        * Referenced by: '<S2>/Stream Client'
                                        */
  boolean_T HILRead1_Active;           /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<S26>/HIL Read1'
                                        */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S26>/HIL Write'
                                        */
  P_SwitchCaseActionSubsystem_f_T SwitchCaseActionSubsystem_a;/* '<S25>/Switch Case Action Subsystem' */
  P_SwitchCaseActionSubsystem_f_T SwitchCaseActionSubsystem;/* '<S13>/Switch Case Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_follower_qbot2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_follower_qbot2_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][4];
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
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_follower_qbot2_T follower_qbot2_P;

/* Block signals (auto storage) */
extern B_follower_qbot2_T follower_qbot2_B;

/* Continuous states (auto storage) */
extern X_follower_qbot2_T follower_qbot2_X;

/* Block states (auto storage) */
extern DW_follower_qbot2_T follower_qbot2_DW;

/* Model entry point functions */
extern void follower_qbot2_initialize(void);
extern void follower_qbot2_step(void);
extern void follower_qbot2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_follower_qbot2_T *const follower_qbot2_M;

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
 * '<Root>' : 'follower_qbot2'
 * '<S1>'   : 'follower_qbot2/Data From Host'
 * '<S2>'   : 'follower_qbot2/Data From Leader'
 * '<S3>'   : 'follower_qbot2/Error Monitoring'
 * '<S4>'   : 'follower_qbot2/Generate Follower Commands'
 * '<S5>'   : 'follower_qbot2/QBot 2'
 * '<S6>'   : 'follower_qbot2/URI Definitions'
 * '<S7>'   : 'follower_qbot2/Waypoint Controller'
 * '<S8>'   : 'follower_qbot2/Data From Host/Compare To Constant'
 * '<S9>'   : 'follower_qbot2/Data From Leader/Compare To Constant'
 * '<S10>'  : 'follower_qbot2/Error Monitoring/Threshold'
 * '<S11>'  : 'follower_qbot2/Error Monitoring/Threshold1'
 * '<S12>'  : 'follower_qbot2/Error Monitoring/Threshold2'
 * '<S13>'  : 'follower_qbot2/Generate Follower Commands/Bias Removal'
 * '<S14>'  : 'follower_qbot2/Generate Follower Commands/Check if going to last waypoint'
 * '<S15>'  : 'follower_qbot2/Generate Follower Commands/Magnitude'
 * '<S16>'  : 'follower_qbot2/Generate Follower Commands/Normalize Vector'
 * '<S17>'  : 'follower_qbot2/Generate Follower Commands/Bias Removal/Enabled Moving Average'
 * '<S18>'  : 'follower_qbot2/Generate Follower Commands/Bias Removal/Switch Case Action Subsystem'
 * '<S19>'  : 'follower_qbot2/Generate Follower Commands/Bias Removal/Switch Case Action Subsystem1'
 * '<S20>'  : 'follower_qbot2/Generate Follower Commands/Bias Removal/Switch Case Action Subsystem2'
 * '<S21>'  : 'follower_qbot2/Generate Follower Commands/Bias Removal/Enabled Moving Average/Increment'
 * '<S22>'  : 'follower_qbot2/Generate Follower Commands/Check if going to last waypoint/Magnitude'
 * '<S23>'  : 'follower_qbot2/QBot 2/QBot_Basic'
 * '<S24>'  : 'follower_qbot2/QBot 2/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity  into Left and Right Wheel Vellocity)'
 * '<S25>'  : 'follower_qbot2/QBot 2/QBot_Basic/Bias Removal'
 * '<S26>'  : 'follower_qbot2/QBot 2/QBot_Basic/QBot2_IO_Basic'
 * '<S27>'  : 'follower_qbot2/QBot 2/QBot_Basic/Bias Removal/Enabled Moving Average'
 * '<S28>'  : 'follower_qbot2/QBot 2/QBot_Basic/Bias Removal/Switch Case Action Subsystem'
 * '<S29>'  : 'follower_qbot2/QBot 2/QBot_Basic/Bias Removal/Switch Case Action Subsystem1'
 * '<S30>'  : 'follower_qbot2/QBot 2/QBot_Basic/Bias Removal/Switch Case Action Subsystem2'
 * '<S31>'  : 'follower_qbot2/QBot 2/QBot_Basic/Bias Removal/Enabled Moving Average/Increment'
 * '<S32>'  : 'follower_qbot2/QBot 2/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity  into Left and Right Wheel Vellocity)/Qbot2_Inverse_Kinematics  (Forward Velocity and Angular Velocity into Left and Right Wheel Vellocity)'
 * '<S33>'  : 'follower_qbot2/Waypoint Controller/Second-Order Low-Pass Filter1'
 * '<S34>'  : 'follower_qbot2/Waypoint Controller/Second-Order Low-Pass Filter4'
 * '<S35>'  : 'follower_qbot2/Waypoint Controller/Trajectory control (Way-points)'
 * '<S36>'  : 'follower_qbot2/Waypoint Controller/Trajectory control (Way-points)/Way Point Control'
 */
#endif                                 /* RTW_HEADER_follower_qbot2_h_ */
