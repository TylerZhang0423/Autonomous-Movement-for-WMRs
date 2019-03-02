/*
 * tracking.h
 *
 * Code generation for model "tracking".
 *
 * Model version              : 1.1094
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Apr 05 19:14:37 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_tracking_h_
#define RTW_HEADER_tracking_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef tracking_COMMON_INCLUDES_
# define tracking_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* tracking_COMMON_INCLUDES_ */

#include "tracking_types.h"

/* Shared type includes */
#include "multiword_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  real_T Constant2;                    /* '<S4>/Constant2' */
  real_T Constant1;                    /* '<S4>/Constant1' */
  real_T Constant9;                    /* '<S4>/Constant9' */
  real_T Constant1_a;                  /* '<S5>/Constant1' */
  real_T Integrator2;                  /* '<S5>/Integrator2' */
  real_T Constant9_m;                  /* '<S5>/Constant9' */
  real_T Integrator3;                  /* '<S5>/Integrator3' */
  real_T Constant2_a;                  /* '<S5>/Constant2' */
  real_T Integrator1;                  /* '<S5>/Integrator1' */
  real_T Product1;                     /* '<S11>/Product1' */
  real_T Product1_a;                   /* '<S9>/Product1' */
  real_T VectorConcatenate[15];        /* '<Root>/Vector Concatenate' */
  real_T mmtom;                        /* '<S8>/mm to m' */
  real_T x0;                           /* '<S9>/x0' */
  real_T Product;                      /* '<S9>/Product' */
  real_T mmtom_o;                      /* '<S10>/mm to m' */
  real_T x0_j;                         /* '<S11>/x0' */
  real_T Product_f;                    /* '<S11>/Product' */
  real_T vL;                           /* '<Root>/vR to vC2' */
  real_T vR;                           /* '<Root>/vR to vC2' */
  real_T x_dot;                        /* '<S16>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T y_dot;                        /* '<S16>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T psi_dot;                      /* '<S16>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T x_dot_e;                      /* '<S13>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T y_dot_i;                      /* '<S13>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T psi_dot_n;                    /* '<S13>/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)' */
  real_T vC;                           /* '<S12>/Qbot2_Diff_Drive_Kinematics' */
  real_T Omega;                        /* '<S12>/Qbot2_Diff_Drive_Kinematics' */
  real_T u_1r;                         /* '<Root>/MATLAB Function' */
  real_T u_2r;                         /* '<Root>/MATLAB Function' */
} B_tracking_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AIMinimums[10]; /* '<Root>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[10]; /* '<Root>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[4];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[4];/* '<Root>/HIL Initialize' */
  real_T HILInitialize_POValues[4];    /* '<Root>/HIL Initialize' */
  real_T HILInitialize_OOValues[2];    /* '<Root>/HIL Initialize' */
  real_T HILWrite_OtherBuffer[2];      /* '<Root>/HIL Write' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *HILWrite_PWORK;                /* '<Root>/HIL Write' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  void *HILRead1_PWORK;                /* '<Root>/HIL Read1' */
  struct {
    void *LoggedData;
  } FloatingScope_PWORK;               /* synthesized block */

  int32_T HILInitialize_QuadratureModes[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[4];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[4];/* '<Root>/HIL Initialize' */
  int32_T HILRead1_EncoderBuffer[2];   /* '<Root>/HIL Read1' */
  uint32_T HILInitialize_POSortedChans[4];/* '<Root>/HIL Initialize' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S4>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator2_IWORK;                 /* '<S4>/Integrator2' */

  struct {
    int_T IcNeedsLoading;
  } Integrator3_IWORK;                 /* '<S4>/Integrator3' */

  struct {
    int_T IcNeedsLoading;
  } Integrator2_IWORK_g;               /* '<S5>/Integrator2' */

  struct {
    int_T IcNeedsLoading;
  } Integrator3_IWORK_a;               /* '<S5>/Integrator3' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_j;               /* '<S5>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_d;               /* '<S9>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK_p;               /* '<S11>/Integrator1' */
} DW_tracking_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator2_CSTATE_f;         /* '<S5>/Integrator2' */
  real_T Integrator3_CSTATE_d;         /* '<S5>/Integrator3' */
  real_T Integrator1_CSTATE_c;         /* '<S5>/Integrator1' */
  real_T Integrator2_CSTATE_b;         /* '<S11>/Integrator2' */
  real_T Integrator2_CSTATE_fg;        /* '<S9>/Integrator2' */
  real_T Integrator1_CSTATE_j;         /* '<S9>/Integrator1' */
  real_T Integrator1_CSTATE_ch;        /* '<S11>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S13>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S16>/Integrator' */
} X_tracking_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator2_CSTATE_f;         /* '<S5>/Integrator2' */
  real_T Integrator3_CSTATE_d;         /* '<S5>/Integrator3' */
  real_T Integrator1_CSTATE_c;         /* '<S5>/Integrator1' */
  real_T Integrator2_CSTATE_b;         /* '<S11>/Integrator2' */
  real_T Integrator2_CSTATE_fg;        /* '<S9>/Integrator2' */
  real_T Integrator1_CSTATE_j;         /* '<S9>/Integrator1' */
  real_T Integrator1_CSTATE_ch;        /* '<S11>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S13>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S16>/Integrator' */
} XDot_tracking_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S4>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<S4>/Integrator3' */
  boolean_T Integrator2_CSTATE_f;      /* '<S5>/Integrator2' */
  boolean_T Integrator3_CSTATE_d;      /* '<S5>/Integrator3' */
  boolean_T Integrator1_CSTATE_c;      /* '<S5>/Integrator1' */
  boolean_T Integrator2_CSTATE_b;      /* '<S11>/Integrator2' */
  boolean_T Integrator2_CSTATE_fg;     /* '<S9>/Integrator2' */
  boolean_T Integrator1_CSTATE_j;      /* '<S9>/Integrator1' */
  boolean_T Integrator1_CSTATE_ch;     /* '<S11>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S13>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S16>/Integrator' */
} XDis_tracking_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct P_tracking_T_ {
  real_T HILInitialize_analog_input_maxi[9];/* Mask Parameter: HILInitialize_analog_input_maxi
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_analog_input_mini[9];/* Mask Parameter: HILInitialize_analog_input_mini
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_final_other_outpu[3];/* Mask Parameter: HILInitialize_final_other_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_final_pwm_outputs;/* Mask Parameter: HILInitialize_final_pwm_outputs
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_other_out[3];/* Mask Parameter: HILInitialize_initial_other_out
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T HILInitialize_initial_pwm_outpu;/* Mask Parameter: HILInitialize_initial_pwm_outpu
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T SecondOrderLowPassFilter2_input;/* Mask Parameter: SecondOrderLowPassFilter2_input
                                          * Referenced by: '<S11>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_p;/* Mask Parameter: SecondOrderLowPassFilter2_inp_p
                                          * Referenced by: '<S9>/wn'
                                          */
  real_T SecondOrderLowPassFilter2_inp_l;/* Mask Parameter: SecondOrderLowPassFilter2_inp_l
                                          * Referenced by: '<S9>/zt'
                                          */
  real_T SecondOrderLowPassFilter2_inp_k;/* Mask Parameter: SecondOrderLowPassFilter2_inp_k
                                          * Referenced by: '<S11>/zt'
                                          */
  real_T HILInitialize_pwm_frequency[4];/* Mask Parameter: HILInitialize_pwm_frequency
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
  real_T HILInitialize_set_other_outpu_l;/* Mask Parameter: HILInitialize_set_other_outpu_l
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_h;/* Mask Parameter: HILInitialize_set_other_outpu_h
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_b;/* Mask Parameter: HILInitialize_set_other_outpu_b
                                          * Referenced by: '<Root>/HIL Initialize'
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
  int32_T HILInitialize_pwm_modes[4];  /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_pwm_polarity;  /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  int32_T HILInitialize_watchdog_digital_;/* Mask Parameter: HILInitialize_watchdog_digital_
                                           * Referenced by: '<Root>/HIL Initialize'
                                           */
  uint32_T HILRead1_analog_channels;   /* Mask Parameter: HILRead1_analog_channels
                                        * Referenced by: '<Root>/HIL Read1'
                                        */
  uint32_T HILInitialize_analog_input_chan[10];/* Mask Parameter: HILInitialize_analog_input_chan
                                                * Referenced by: '<Root>/HIL Initialize'
                                                */
  uint32_T HILRead1_digital_channels[3];/* Mask Parameter: HILRead1_digital_channels
                                         * Referenced by: '<Root>/HIL Read1'
                                         */
  uint32_T HILInitialize_encoder_channels[4];/* Mask Parameter: HILInitialize_encoder_channels
                                              * Referenced by: '<Root>/HIL Initialize'
                                              */
  uint32_T HILRead1_encoder_channels[2];/* Mask Parameter: HILRead1_encoder_channels
                                         * Referenced by: '<Root>/HIL Read1'
                                         */
  uint32_T HILWrite_other_channels[2]; /* Mask Parameter: HILWrite_other_channels
                                        * Referenced by: '<Root>/HIL Write'
                                        */
  uint32_T HILRead1_other_channels;    /* Mask Parameter: HILRead1_other_channels
                                        * Referenced by: '<Root>/HIL Read1'
                                        */
  uint32_T HILInitialize_other_output_chan[2];/* Mask Parameter: HILInitialize_other_output_chan
                                               * Referenced by: '<Root>/HIL Initialize'
                                               */
  uint32_T HILInitialize_pwm_channels[4];/* Mask Parameter: HILInitialize_pwm_channels
                                          * Referenced by: '<Root>/HIL Initialize'
                                          */
  uint32_T HILInitialize_quadrature;   /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
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
  boolean_T HILInitialize_set_analog_inpu_a;/* Mask Parameter: HILInitialize_set_analog_inpu_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_m;/* Mask Parameter: HILInitialize_set_analog_outp_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_g;/* Mask Parameter: HILInitialize_set_analog_outp_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_n;/* Mask Parameter: HILInitialize_set_analog_outp_n
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_l;/* Mask Parameter: HILInitialize_set_analog_outp_l
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_a;/* Mask Parameter: HILInitialize_set_analog_outp_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_out_lq;/* Mask Parameter: HILInitialize_set_analog_out_lq
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_n;/* Mask Parameter: HILInitialize_set_clock_frequ_n
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_k;/* Mask Parameter: HILInitialize_set_clock_param_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_h;/* Mask Parameter: HILInitialize_set_digital_out_h
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_j;/* Mask Parameter: HILInitialize_set_digital_out_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_l;/* Mask Parameter: HILInitialize_set_digital_out_l
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_g;/* Mask Parameter: HILInitialize_set_digital_out_g
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_d;/* Mask Parameter: HILInitialize_set_digital_out_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_ou_h3;/* Mask Parameter: HILInitialize_set_digital_ou_h3
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_count;/* Mask Parameter: HILInitialize_set_encoder_count
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_cou_m;/* Mask Parameter: HILInitialize_set_encoder_cou_m
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_param;/* Mask Parameter: HILInitialize_set_encoder_param
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_par_a;/* Mask Parameter: HILInitialize_set_encoder_par_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outpu_d;/* Mask Parameter: HILInitialize_set_other_outpu_d
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_j;/* Mask Parameter: HILInitialize_set_pwm_outputs_j
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_e;/* Mask Parameter: HILInitialize_set_pwm_outputs_e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_k;/* Mask Parameter: HILInitialize_set_pwm_outputs_k
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__e;/* Mask Parameter: HILInitialize_set_pwm_params__e
                                             * Referenced by: '<Root>/HIL Initialize'
                                             */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant9_Value;              /* Expression: 2
                                        * Referenced by: '<S4>/Constant9'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant9_Value_e;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant9'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S11>/Integrator2'
                                        */
  real_T Integrator2_IC_k;             /* Expression: 0
                                        * Referenced by: '<S9>/Integrator2'
                                        */
  real_T tickstoencoderrotation_Gain;  /* Expression: 2*pi/52
                                        * Referenced by: '<S8>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotationg;/* Expression: 1/49.5833
                                          * Referenced by: '<S8>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T wheelradiousmm_Gain;          /* Expression: 35
                                        * Referenced by: '<S8>/wheel radious (mm)'
                                        */
  real_T mmtom_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S8>/mm to m'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T x0_Value;                     /* Expression: input_init
                                        * Referenced by: '<S9>/x0'
                                        */
  real_T tickstoencoderrotation_Gain_i;/* Expression: 2*pi/52
                                        * Referenced by: '<S10>/ticks to encoder rotation'
                                        */
  real_T encoderrotationtowheelrotatio_n;/* Expression: 1/49.5833
                                          * Referenced by: '<S10>/ encoder rotation to wheel rotation (gear ratio)'
                                          */
  real_T wheelradiousmm_Gain_k;        /* Expression: 35
                                        * Referenced by: '<S10>/wheel radious (mm)'
                                        */
  real_T mmtom_Gain_h;                 /* Expression: 1/1000
                                        * Referenced by: '<S10>/mm to m'
                                        */
  real_T Constant_Value_m;             /* Expression: 2
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T x0_Value_k;                   /* Expression: input_init
                                        * Referenced by: '<S11>/x0'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S16>/Integrator'
                                        */
  boolean_T HILWrite_Active;           /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<Root>/HIL Write'
                                        */
  boolean_T HILRead1_Active;           /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<Root>/HIL Read1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_tracking_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_tracking_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][12];
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
extern P_tracking_T tracking_P;

/* Block signals (auto storage) */
extern B_tracking_T tracking_B;

/* Continuous states (auto storage) */
extern X_tracking_T tracking_X;

/* Block states (auto storage) */
extern DW_tracking_T tracking_DW;

/* Model entry point functions */
extern void tracking_initialize(void);
extern void tracking_step(void);
extern void tracking_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tracking_T *const tracking_M;

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
 * '<Root>' : 'tracking'
 * '<S1>'   : 'tracking/Encoder_to_Velocity2'
 * '<S2>'   : 'tracking/Encoder_to_Velocity3'
 * '<S3>'   : 'tracking/MATLAB Function'
 * '<S4>'   : 'tracking/Qbot2_Full_Kinematics'
 * '<S5>'   : 'tracking/Subsystem'
 * '<S6>'   : 'tracking/Subsystem1'
 * '<S7>'   : 'tracking/vR to vC2'
 * '<S8>'   : 'tracking/Encoder_to_Velocity2/Encoder to Distance'
 * '<S9>'   : 'tracking/Encoder_to_Velocity2/Second-Order Low-Pass Filter2'
 * '<S10>'  : 'tracking/Encoder_to_Velocity3/Encoder to Distance'
 * '<S11>'  : 'tracking/Encoder_to_Velocity3/Second-Order Low-Pass Filter2'
 * '<S12>'  : 'tracking/Qbot2_Full_Kinematics/Qbot2_Diff_Drive_Kinematics'
 * '<S13>'  : 'tracking/Qbot2_Full_Kinematics/Qbot2_Kinematics (No Gyro)'
 * '<S14>'  : 'tracking/Qbot2_Full_Kinematics/Qbot2_Diff_Drive_Kinematics/Qbot2_Diff_Drive_Kinematics'
 * '<S15>'  : 'tracking/Qbot2_Full_Kinematics/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)'
 * '<S16>'  : 'tracking/Subsystem/Qbot2_Kinematics (No Gyro)'
 * '<S17>'  : 'tracking/Subsystem/Qbot2_Kinematics (No Gyro)/Qbot2_Kinematics (Vf,W to x_dot,y_dot and psi_dot)'
 * '<S18>'  : 'tracking/Subsystem1/e=T(q_r-q)'
 */
#endif                                 /* RTW_HEADER_tracking_h_ */
