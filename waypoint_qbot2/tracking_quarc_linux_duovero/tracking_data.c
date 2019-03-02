/*
 * tracking_data.c
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
#include "tracking.h"
#include "tracking_private.h"

/* Block parameters (auto storage) */
P_tracking_T tracking_P = {
  /*  Mask Parameter: HILInitialize_analog_input_maxi
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 5.0, 5.0, 5.0, 5.0, 16.5, 3.3, 3.3, 3.3, 3.3 },

  /*  Mask Parameter: HILInitialize_analog_input_mini
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Mask Parameter: HILInitialize_final_other_outpu
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 1.0 },
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_initial_other_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 7.0 },
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: SecondOrderLowPassFilter2_input
                                        * Referenced by: '<S11>/wn'
                                        */
  10.0,                                /* Mask Parameter: SecondOrderLowPassFilter2_inp_p
                                        * Referenced by: '<S9>/wn'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_inp_l
                                        * Referenced by: '<S9>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_inp_k
                                        * Referenced by: '<S11>/zt'
                                        */

  /*  Mask Parameter: HILInitialize_pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 19531.25, 19531.25, 19531.25, 19531.25 },
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_b
                                        * Referenced by: '<Root>/HIL Initialize'
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

  /*  Mask Parameter: HILInitialize_pwm_modes
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 0, 0, 0 },
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  4U,                                  /* Mask Parameter: HILRead1_analog_channels
                                        * Referenced by: '<Root>/HIL Read1'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U },

  /*  Mask Parameter: HILRead1_digital_channels
   * Referenced by: '<Root>/HIL Read1'
   */
  { 8U, 9U, 10U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Mask Parameter: HILRead1_encoder_channels
   * Referenced by: '<Root>/HIL Read1'
   */
  { 2U, 3U },

  /*  Mask Parameter: HILWrite_other_channels
   * Referenced by: '<Root>/HIL Write'
   */
  { 2000U, 2001U },
  1002U,                               /* Mask Parameter: HILRead1_other_channels
                                        * Referenced by: '<Root>/HIL Read1'
                                        */

  /*  Mask Parameter: HILInitialize_other_output_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 2000U, 2001U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
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
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_lq
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_ou_h3
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S4>/Constant1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S4>/Constant9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Integrator2'
                                        */
  0.1208304866765305,                  /* Expression: 2*pi/52
                                        * Referenced by: '<S8>/ticks to encoder rotation'
                                        */
  0.020168080785264393,                /* Expression: 1/49.5833
                                        * Referenced by: '<S8>/ encoder rotation to wheel rotation (gear ratio)'
                                        */
  35.0,                                /* Expression: 35
                                        * Referenced by: '<S8>/wheel radious (mm)'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S8>/mm to m'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S9>/x0'
                                        */
  0.1208304866765305,                  /* Expression: 2*pi/52
                                        * Referenced by: '<S10>/ticks to encoder rotation'
                                        */
  0.020168080785264393,                /* Expression: 1/49.5833
                                        * Referenced by: '<S10>/ encoder rotation to wheel rotation (gear ratio)'
                                        */
  35.0,                                /* Expression: 35
                                        * Referenced by: '<S10>/wheel radious (mm)'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S10>/mm to m'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S11>/x0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Integrator'
                                        */
  1,                                   /* Computed Parameter: HILWrite_Active
                                        * Referenced by: '<Root>/HIL Write'
                                        */
  1                                    /* Computed Parameter: HILRead1_Active
                                        * Referenced by: '<Root>/HIL Read1'
                                        */
};
