/*
 * leader_qbot2_data.c
 *
 * Code generation for model "leader_qbot2".
 *
 * Model version              : 1.97
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed May 31 17:51:37 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "leader_qbot2.h"
#include "leader_qbot2_private.h"

/* Block parameters (auto storage) */
P_leader_qbot2_T leader_qbot2_P = {
  /*  Mask Parameter: HILInitialize_analog_input_maxi
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 5.0, 5.0, 5.0, 5.0, 16.5, 3.3, 3.3, 3.3, 3.3 },

  /*  Mask Parameter: HILInitialize_analog_input_mini
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Mask Parameter: StreamClient_default_value
   * Referenced by: '<S1>/Stream Client'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  4.0,                                 /* Mask Parameter: BiasRemoval_end_time
                                        * Referenced by: '<S12>/Step: end_time'
                                        */

  /*  Mask Parameter: HILInitialize_final_other_outpu
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 7.0 },
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_initial_other_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 7.0 },
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  30.0,                                /* Mask Parameter: SecondOrderLowPassFilter1_input
                                        * Referenced by: '<S20>/wn'
                                        */
  60.0,                                /* Mask Parameter: SecondOrderLowPassFilter4_input
                                        * Referenced by: '<S21>/wn'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter1_inp_f
                                        * Referenced by: '<S20>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter4_inp_i
                                        * Referenced by: '<S21>/zt'
                                        */
  19531.25,                            /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  3.0,                                 /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S12>/Step: start_time'
                                        */
  1.0,                                 /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S12>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  4U,                                  /* Mask Parameter: HILRead1_analog_channels
                                        * Referenced by: '<S13>/HIL Read1'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U },

  /*  Mask Parameter: HILRead1_digital_channels
   * Referenced by: '<S13>/HIL Read1'
   */
  { 8U, 9U, 10U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Mask Parameter: HILRead1_encoder_channels
   * Referenced by: '<S13>/HIL Read1'
   */
  { 2U, 3U },
  1002U,                               /* Mask Parameter: HILRead1_other_channels
                                        * Referenced by: '<S13>/HIL Read1'
                                        */

  /*  Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S13>/HIL Write'
   */
  { 2000U, 2001U },

  /*  Mask Parameter: HILInitialize_other_output_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 2000U, 2001U, 14000U, 16000U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  2,                                   /* Mask Parameter: ShowMessageonHost_message_icon
                                        * Referenced by: '<S2>/Show Message on Host'
                                        */
  2,                                   /* Mask Parameter: ShowMessageonHost1_message_icon
                                        * Referenced by: '<S2>/Show Message on Host1'
                                        */
  2U,                                  /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S7>/Constant'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_oi
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_o2
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_m3
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_ou_gg
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/unity'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Sum( k=1,n-1, x(k) )'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S15>/zero'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S16>/Vbiased'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S17>/Vunbiased'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Step: start_time'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Step: start_time'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Step: end_time'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Step: end_time'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S2>/Signal Threshold'
                                        */
  0.002,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Discrete-Time Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Timeout Threshold (s)'
                                        */
  0.002,                               /* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Dummy'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory1'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S20>/x0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Enable'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Disable'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Rate Limiter - Linear Speed'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Rate Limiter - Linear Speed'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S21>/x0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Rate Limiter - Turning Rate'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Rate Limiter - Turning Rate'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Enable'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/V Limit2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Sequential'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Simultaneous'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/V Limit'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<Root>/V Limit1'
                                        */
  0.7,                                 /* Expression: 0.7
                                        * Referenced by: '<S6>/Kv_1'
                                        */
  0.7,                                 /* Expression: 0.7
                                        * Referenced by: '<S6>/Kv_2'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S6>/Kv_3'
                                        */
  0.9,                                 /* Expression: 0.9
                                        * Referenced by: '<S6>/Kv_4'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S20>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Integrator2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Waypoint Step'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S22>/Memory'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S21>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Integrator2'
                                        */
  0,                                   /* Computed Parameter: StreamClient_SndPriority
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  0,                                   /* Computed Parameter: StreamClient_RcvPriority
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  0,                                   /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1460U,                               /* Computed Parameter: StreamClient_SndSize
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  1460U,                               /* Computed Parameter: StreamClient_RcvSize
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  1000U,                               /* Computed Parameter: StreamClient_SndFIFO
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  1000U,                               /* Computed Parameter: StreamClient_RcvFIFO
                                        * Referenced by: '<S1>/Stream Client'
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
  2,                                   /* Computed Parameter: StreamClient_Optimize
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  1,                                   /* Computed Parameter: StreamClient_Implementation
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  2,                                   /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1,                                   /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S4>/Stream Server'
                                        */

  /*  Expression: value
   * Referenced by: '<S5>/String Constant1'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 49U, 57U, 50U, 46U, 49U, 54U,
    56U, 46U, 50U, 46U, 49U, 48U, 58U, 49U, 56U, 48U, 48U, 54U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
  0U,                                  /* Expression: uri_argument
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  1U,                                  /* Computed Parameter: StreamClient_Endian
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitchQBot2Enable_Current
                                        * Referenced by: '<Root>/Manual Switch - QBot 2 Enable'
                                        */

  /*  Expression: uri_argument
   * Referenced by: '<S4>/Stream Server'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 55U, 0U },
  1U,                                  /* Computed Parameter: StreamServer_Endian
                                        * Referenced by: '<S4>/Stream Server'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitchTrackingMethod_Curr
                                        * Referenced by: '<Root>/Manual Switch - Tracking Method'
                                        */
  0,                                   /* Computed Parameter: StreamClient_Active
                                        * Referenced by: '<S1>/Stream Client'
                                        */
  1,                                   /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<S13>/HIL Read1'
                                        */
  1,                                   /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<S13>/HIL Write'
                                        */
  0                                    /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S4>/Stream Server'
                                        */
};
