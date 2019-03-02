/*
 * leader_qball2_mytest_data.c
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
#include "leader_qball2_mytest.h"
#include "leader_qball2_mytest_private.h"

/* Block parameters (auto storage) */
P_leader_qball2_mytest_T leader_qball2_mytest_P = {
  0.15,                                /* Variable: KdHEIGHT_DOWN
                                        * Referenced by: '<S131>/Kd - Battery DOWN'
                                        */
  0.15,                                /* Variable: KdHEIGHT_UP
                                        * Referenced by: '<S131>/Kd - Battery UP'
                                        */
  0.4,                                 /* Variable: KdOUTER_PITCH_DOWN
                                        * Referenced by: '<S86>/Kv - Battery DOWN'
                                        */
  0.6,                                 /* Variable: KdOUTER_PITCH_UP
                                        * Referenced by: '<S86>/Kv - Battery UP'
                                        */
  0.4,                                 /* Variable: KdOUTER_ROLL_DOWN
                                        * Referenced by: '<S104>/Kv - DOWN'
                                        */
  0.4,                                 /* Variable: KdOUTER_ROLL_UP
                                        * Referenced by: '<S104>/Kv - UP'
                                        */
  0.1,                                 /* Variable: KdPITCH_DOWN
                                        * Referenced by: '<S81>/Kd - Battery DOWN'
                                        */
  0.1,                                 /* Variable: KdPITCH_UP
                                        * Referenced by: '<S81>/Kd - Battery UP'
                                        */
  0.1,                                 /* Variable: KdROLL_DOWN
                                        * Referenced by: '<S97>/Kd - Battery DOWN'
                                        */
  0.1,                                 /* Variable: KdROLL_UP
                                        * Referenced by: '<S97>/Kd - Battery UP'
                                        */
  0.32,                                /* Variable: KdYAW_DOWN
                                        * Referenced by: '<S13>/Kd - Battery DOWN'
                                        */
  0.32,                                /* Variable: KdYAW_UP
                                        * Referenced by: '<S13>/Kd - Battery UP'
                                        */
  0.35,                                /* Variable: KiHEIGHT_DOWN
                                        * Referenced by: '<S131>/Ki - Battery DOWN'
                                        */
  0.35,                                /* Variable: KiHEIGHT_UP
                                        * Referenced by: '<S131>/Ki - Battery UP'
                                        */
  0.08,                                /* Variable: KiOUTER_PITCH_DOWN
                                        * Referenced by: '<S86>/Ki - Battery DOWN'
                                        */
  0.08,                                /* Variable: KiOUTER_PITCH_UP
                                        * Referenced by: '<S86>/Ki - Battery UP'
                                        */
  0.08,                                /* Variable: KiOUTER_ROLL_DOWN
                                        * Referenced by: '<S104>/Ki - Battery DOWN'
                                        */
  0.08,                                /* Variable: KiOUTER_ROLL_UP
                                        * Referenced by: '<S104>/Ki - Battery UP'
                                        */
  0.08,                                /* Variable: KiPITCH_DOWN
                                        * Referenced by: '<S81>/Ki - Battery DOWN'
                                        */
  0.08,                                /* Variable: KiPITCH_UP
                                        * Referenced by: '<S81>/Ki - Battery UP'
                                        */
  0.08,                                /* Variable: KiROLL_DOWN
                                        * Referenced by: '<S97>/Ki - Battery DOWN'
                                        */
  0.08,                                /* Variable: KiROLL_UP
                                        * Referenced by: '<S97>/Ki - Battery UP'
                                        */
  0.0,                                 /* Variable: KiYAW_DOWN
                                        * Referenced by: '<S13>/Ki - Battery DOWN'
                                        */
  0.0,                                 /* Variable: KiYAW_UP
                                        * Referenced by: '<S13>/Ki - Battery UP'
                                        */
  0.5,                                 /* Variable: KpHEIGHT_DOWN
                                        * Referenced by: '<S131>/Kp - Battery DOWN'
                                        */
  0.5,                                 /* Variable: KpHEIGHT_UP
                                        * Referenced by: '<S131>/Kp - Battery UP'
                                        */
  0.3,                                 /* Variable: KpOUTER_PITCH_DOWN
                                        * Referenced by: '<S86>/Kp - Battery DOWN'
                                        */
  0.3,                                 /* Variable: KpOUTER_PITCH_UP
                                        * Referenced by: '<S86>/Kp - Battery UP'
                                        */
  0.3,                                 /* Variable: KpOUTER_ROLL_DOWN
                                        * Referenced by: '<S104>/Kp - Battery DOWN'
                                        */
  0.3,                                 /* Variable: KpOUTER_ROLL_UP
                                        * Referenced by: '<S104>/Kp - Battery UP'
                                        */
  0.5,                                 /* Variable: KpPITCH_DOWN
                                        * Referenced by: '<S81>/Kp - Battery DOWN'
                                        */
  0.5,                                 /* Variable: KpPITCH_UP
                                        * Referenced by: '<S81>/Kp - Battery UP'
                                        */
  0.5,                                 /* Variable: KpROLL_DOWN
                                        * Referenced by: '<S97>/Kp - Battery DOWN'
                                        */
  0.5,                                 /* Variable: KpROLL_UP
                                        * Referenced by: '<S97>/Kp - Battery UP'
                                        */
  0.45,                                /* Variable: KpYAW_DOWN
                                        * Referenced by: '<S13>/Kp - Battery DOWN'
                                        */
  0.45,                                /* Variable: KpYAW_UP
                                        * Referenced by: '<S13>/Kp - Battery UP'
                                        */
  0.087266462599716474,                /* Variable: LIMIT_CMD_PITCH
                                        * Referenced by: '<S86>/Saturation1'
                                        */
  0.087266462599716474,                /* Variable: LIMIT_CMD_ROLL
                                        * Referenced by: '<S104>/Saturation1'
                                        */
  2.0,                                 /* Variable: LIMIT_MAX_HEIGHT
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  1.0,                                 /* Variable: LIMIT_MAX_X
                                        * Referenced by: '<S7>/Saturation'
                                        */
  1.0,                                 /* Variable: LIMIT_MAX_Z
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  0.3,                                 /* Variable: LIMIT_MIN_HEIGHT
                                        * Referenced by: '<S7>/Saturation2'
                                        */
  -1.0,                                /* Variable: LIMIT_MIN_X
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -1.0,                                /* Variable: LIMIT_MIN_Z
                                        * Referenced by: '<S7>/Saturation1'
                                        */
  0.05,                                /* Variable: LIMIT_RATE_HEIGHT
                                        * Referenced by: '<S7>/Rate Limiter3'
                                        */
  0.15,                                /* Variable: LIMIT_RATE_X
                                        * Referenced by: '<S7>/Rate Limiter1'
                                        */
  0.15,                                /* Variable: LIMIT_RATE_Z
                                        * Referenced by: '<S7>/Rate Limiter2'
                                        */
  0.5,                                 /* Variable: LIMIT_uCMD_PITCH
                                        * Referenced by: '<S81>/Saturation1'
                                        */
  0.5,                                 /* Variable: LIMIT_uCMD_ROLL
                                        * Referenced by: '<S97>/Saturation'
                                        */
  0.5,                                 /* Variable: LIMIT_uCMD_YAW
                                        * Referenced by: '<S13>/Saturation'
                                        */
  0.3,                                 /* Variable: OFFSET_HEIGHT
                                        * Referenced by:
                                        *   '<S29>/Height Estimate Bias (Estimate Reference at Centre of QBall 2) '
                                        *   '<S29>/OptiTrack Height Measurement Bias'
                                        */
  60.0,                                /* Variable: OMEGA_DIFF
                                        * Referenced by:
                                        *   '<S48>/wn'
                                        *   '<S49>/wn'
                                        *   '<S50>/wn'
                                        *   '<S139>/wn'
                                        *   '<S89>/wn'
                                        *   '<S107>/wn'
                                        */
  60.0,                                /* Variable: OMEGA_FILTER
                                        * Referenced by:
                                        *   '<S32>/wn'
                                        *   '<S47>/wn'
                                        */
  1.0,                                 /* Variable: TIMEOUT_CALIB
                                        * Referenced by: '<S31>/Step: end_time'
                                        */
  0.36583125000000005,                 /* Variable: TRIM_THROTTLE
                                        * Referenced by: '<S7>/Throttle Trim'
                                        */
  0.009,                               /* Variable: TRIM_U_PITCH
                                        * Referenced by: '<S7>/Pitch_Trim'
                                        */
  -0.0065,                             /* Variable: TRIM_U_ROLL
                                        * Referenced by: '<S7>/roll_trim'
                                        */
  9.81,                                /* Variable: g
                                        * Referenced by: '<S23>/Accelerometer offsets manually calibrated2'
                                        */
  0.8,                                 /* Variable: joystick_range_max
                                        * Referenced by: '<S117>/height command2'
                                        */
  0.5,                                 /* Variable: joystick_range_min
                                        * Referenced by: '<S117>/height command1'
                                        */
  0.1,                                 /* Mask Parameter: FOH1_Ts
                                        * Referenced by:
                                        *   '<S54>/Bias'
                                        *   '<S54>/Gain'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_maxi
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 5.0, 5.0, 15.0 },

  /*  Mask Parameter: HILInitialize_analog_input_mini
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0.0, 0.0, 0.0 },
  3.0,                                 /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S60>/Constant'
                                        */
  10.5,                                /* Mask Parameter: CompareToConstant_const_o
                                        * Referenced by: '<S59>/Constant'
                                        */
  5.0,                                 /* Mask Parameter: CompareToConstant_const_d
                                        * Referenced by: '<S70>/Constant'
                                        */
  0.1,                                 /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S71>/Constant'
                                        */
  0.5,                                 /* Mask Parameter: CompareToConstant_const_k
                                        * Referenced by: '<S136>/Constant'
                                        */
  10.2,                                /* Mask Parameter: CompareToConstant_const_c
                                        * Referenced by: '<S74>/Constant'
                                        */
  0.9,                                 /* Mask Parameter: CompareToConstant1_const_c
                                        * Referenced by: '<S75>/Constant'
                                        */
  0.2,                                 /* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S137>/Constant'
                                        */
  1.0,                                 /* Mask Parameter: CompareToConstant_const_m
                                        * Referenced by: '<S126>/Constant'
                                        */
  0.07,                                /* Mask Parameter: CompareToConstant_const_ol
                                        * Referenced by: '<S141>/Constant'
                                        */
  0.69813170079773179,                 /* Mask Parameter: CompareToConstant1_const_n
                                        * Referenced by: '<S17>/Constant'
                                        */
  0.69813170079773179,                 /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S18>/Constant'
                                        */
  0.07,                                /* Mask Parameter: CompareToConstant_const_a
                                        * Referenced by: '<S91>/Constant'
                                        */
  0.07,                                /* Mask Parameter: CompareToConstant_const_i
                                        * Referenced by: '<S99>/Constant'
                                        */
  0.0525,                              /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S21>/Constant'
                                        */
  100.0,                               /* Mask Parameter: CompareToConstant_const_aq
                                        * Referenced by: '<S73>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: CompareToConstant_const_ap
                                        * Referenced by: '<S84>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: CompareToConstant_const_mk
                                        * Referenced by: '<S102>/Constant'
                                        */

  /*  Mask Parameter: StreamClient_default_value
   * Referenced by: '<S4>/Stream Client'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Mask Parameter: HILInitialize_final_other_outpu
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.4,                                 /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S92>/Slider Gain'
                                        */
  0.8,                                 /* Mask Parameter: Joystickyawcommandgain1_gain
                                        * Referenced by: '<S144>/Slider Gain'
                                        */
  0.39,                                /* Mask Parameter: Joystickyawcommandgain_gain
                                        * Referenced by: '<S143>/Slider Gain'
                                        */
  -44.0,                               /* Mask Parameter: Joystickyawcontrolgain_gain
                                        * Referenced by: '<S142>/Slider Gain'
                                        */
  0.0,                                 /* Mask Parameter: SliderGain4_gain
                                        * Referenced by: '<S96>/Slider Gain'
                                        */
  0.0,                                 /* Mask Parameter: SliderGain2_gain
                                        * Referenced by: '<S94>/Slider Gain'
                                        */
  0.4,                                 /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S93>/Slider Gain'
                                        */
  0.4,                                 /* Mask Parameter: SliderGain3_gain
                                        * Referenced by: '<S95>/Slider Gain'
                                        */
  0.5,                                 /* Mask Parameter: ContinuousSigmoid_hold_off
                                        * Referenced by: '<S130>/Continuous Sigmoid'
                                        */
  0.5,                                 /* Mask Parameter: TriggeredSigmoid_hold_off
                                        * Referenced by: '<S124>/Sigmoid Path'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_other_out
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: ContinuousSigmoid_initial_posit
                                        * Referenced by: '<S130>/Continuous Sigmoid'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: ContinuousSigmoid_initial_veloc
                                        * Referenced by: '<S130>/Continuous Sigmoid'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter3_input
                                        * Referenced by: '<S47>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter4_input
                                        * Referenced by: '<S48>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter5_input
                                        * Referenced by: '<S49>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter7_input
                                        * Referenced by: '<S50>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter2_input
                                        * Referenced by: '<S32>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter1_input
                                        * Referenced by: '<S89>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter1_inp_e
                                        * Referenced by: '<S107>/zt'
                                        */
  1.0,                                 /* Mask Parameter: SecondOrderLowPassFilter_input_
                                        * Referenced by: '<S139>/zt'
                                        */
  20000.0,                             /* Mask Parameter: TriggeredSigmoid_max_accelerati
                                        * Referenced by: '<S125>/Sigmoid Compute'
                                        */
  0.04,                                /* Mask Parameter: TriggeredSigmoid_max_velocity
                                        * Referenced by: '<S125>/Sigmoid Compute'
                                        */
  19531.25,                            /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_f
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_m
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_i
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: BiasRemoval_start_time
                                        * Referenced by: '<S31>/Step: start_time'
                                        */
  1.0,                                 /* Mask Parameter: BiasRemoval_switch_id
                                        * Referenced by: '<S31>/Constant'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_other_ou
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 0U, 1U, 2U },
  2U,                                  /* Mask Parameter: HILReadWrite1_analog_input_chan
                                        * Referenced by: '<S3>/HIL Read Write1'
                                        */

  /*  Mask Parameter: HILInitialize_digital_output_ch
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 8U, 9U },

  /*  Mask Parameter: HILReadWrite1_digital_output_ch
   * Referenced by: '<S3>/HIL Read Write1'
   */
  { 8U, 9U },

  /*  Mask Parameter: HILReadWrite1_other_input_chann
   * Referenced by: '<S3>/HIL Read Write1'
   */
  { 3000U, 3001U, 3002U, 4000U, 4001U, 4002U, 0U },

  /*  Mask Parameter: HILInitialize_other_output_chan
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 11000U, 11001U, 11002U, 11003U },

  /*  Mask Parameter: HILReadWrite1_other_output_chan
   * Referenced by: '<S3>/HIL Read Write1'
   */
  { 11003U, 11002U, 11000U, 11001U },
  2,                                   /* Mask Parameter: ShowMessageonHost1_message_icon
                                        * Referenced by: '<S25>/Show Message on Host1'
                                        */
  2,                                   /* Mask Parameter: ShowMessageonHost_message_icon
                                        * Referenced by: '<S24>/Show Message on Host'
                                        */
  2,                                   /* Mask Parameter: ShowMessageonHost1_message_ic_m
                                        * Referenced by: '<S72>/Show Message on Host1'
                                        */
  2,                                   /* Mask Parameter: ShowMessageonHost_message_ico_h
                                        * Referenced by: '<S66>/Show Message on Host'
                                        */
  2,                                   /* Mask Parameter: ShowMessageonHost1_message_i_m5
                                        * Referenced by: '<S66>/Show Message on Host1'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_final_digital_out
   * Referenced by: '<S3>/HIL Initialize'
   */
  { 1, 1 },
  0,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_e
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_g
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_gi
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_l
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_m
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_h
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_m2
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_i
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_b
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_a
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_c
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_o
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_p
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_n
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_l
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_p
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_other_outp_i5
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_e
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_n
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__e
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  0.002,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */

  /*  Expression: [1 -1 -1]
   * Referenced by: '<S23>/Transform Gyro Data (For Battery Bottom Configuration)'
   */
  { 1.0, -1.0, -1.0 },

  /*  Expression: [1 -1 -1]
   * Referenced by: '<S23>/Transform Accelerometer Data (For Battery Bottom Configuration)'
   */
  { 1.0, -1.0, -1.0 },
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S35>/zero'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S36>/Vbiased'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S37>/Vunbiased'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/Step: start_time'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S31>/Step: start_time'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/Step: end_time'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S31>/Step: end_time'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S58>/unity'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S58>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/Sum( k=1,n-1, x(k) )'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S76>/Constant'
                                        */
  0.002,                               /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                        * Referenced by: '<S76>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S76>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S78>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S78>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S79>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S79>/Constant'
                                        */
  0.15,                                /* Expression: 0.15
                                        * Referenced by: '<S80>/Joystick Sensitivity'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S80>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S90>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S90>/Constant'
                                        */
  0.15,                                /* Expression: 0.15
                                        * Referenced by: '<S98>/Joystick Sensitivity'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S98>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S101>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S108>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S108>/Constant'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S117>/Joystick throttle scaling'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S116>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S133>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S133>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S134>/Out1'
                                        */
  0.0005,                              /* Expression: 5e-4
                                        * Referenced by: '<S13>/Gain1'
                                        */

  /*  Expression: [1 1]
   * Referenced by: '<S3>/Motor enable'
   */
  { 1.0, 1.0 },

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S3>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S62>/Memory'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S62>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Integrator2'
                                        */
  0.002,                               /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant3'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S23>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Memory'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S28>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Rate Transition'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Rate Transition1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Rate Transition'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Battery On Top'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Battery On Bottom'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S23>/Switch Battery Config - Acceleromter (Top or Bottom)'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S32>/x0'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S23>/Switch Battery Config - Gyro (Top or Bottom)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S30>/Calibration time (s)'
                                        */
  -0.016666666666666666,               /* Computed Parameter: HighPassFilterRoll_A
                                        * Referenced by: '<S29>/High Pass Filter - Roll'
                                        */
  -0.016666666666666666,               /* Computed Parameter: HighPassFilterRoll_C
                                        * Referenced by: '<S29>/High Pass Filter - Roll'
                                        */
  1.0,                                 /* Computed Parameter: HighPassFilterRoll_D
                                        * Referenced by: '<S29>/High Pass Filter - Roll'
                                        */
  0.002,                               /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant'
                                        */
  -0.016666666666666666,               /* Computed Parameter: HighPassFilterPitch_A
                                        * Referenced by: '<S29>/High Pass Filter - Pitch'
                                        */
  -0.016666666666666666,               /* Computed Parameter: HighPassFilterPitch_C
                                        * Referenced by: '<S29>/High Pass Filter - Pitch'
                                        */
  1.0,                                 /* Computed Parameter: HighPassFilterPitch_D
                                        * Referenced by: '<S29>/High Pass Filter - Pitch'
                                        */
  0.002,                               /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S49>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S50>/Integrator2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain5'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain4'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S47>/x0'
                                        */
  -0.016666666666666666,               /* Computed Parameter: HighPassFilterYaw_A
                                        * Referenced by: '<S29>/High Pass Filter - Yaw'
                                        */
  -0.016666666666666666,               /* Computed Parameter: HighPassFilterYaw_C
                                        * Referenced by: '<S29>/High Pass Filter - Yaw'
                                        */
  1.0,                                 /* Computed Parameter: HighPassFilterYaw_D
                                        * Referenced by: '<S29>/High Pass Filter - Yaw'
                                        */
  0.002,                               /* Expression: qc_get_step_size
                                        * Referenced by: '<S29>/Constant2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S29>/Gain8'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain7'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S42>/Gain6'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S47>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Integrator2'
                                        */
  6.2831853071795862,                  /* Expression: modulus
                                        * Referenced by: '<S4>/Inverse Modulus'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S48>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S48>/x0'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S49>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S49>/x0'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S50>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S50>/x0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Unit Delay'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S32>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Integrator2'
                                        */

  /*  Expression: [0 0 -9.81]
   * Referenced by: '<S27>/initial accel'
   */
  { 0.0, 0.0, -9.81 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/Calibration time (s)'
                                        */
  -9.0,                                /* Expression: -9.0
                                        * Referenced by: '<S23>/Saturation2'
                                        */
  -9.8,                                /* Expression: -9.8
                                        * Referenced by: '<S23>/Saturation2'
                                        */
  -5.0,                                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S23>/Transfer Fcn'
                                        */
  5.0,                                 /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S23>/Transfer Fcn'
                                        */
  0.1,                                 /* Expression: timeout
                                        * Referenced by: '<S3>/HIL Watchdog'
                                        */
  -0.5,                                /* Computed Parameter: LPF_A
                                        * Referenced by: '<S14>/LPF'
                                        */
  0.5,                                 /* Computed Parameter: LPF_C
                                        * Referenced by: '<S14>/LPF'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  -0.5,                                /* Computed Parameter: HPF_A
                                        * Referenced by: '<S14>/HPF'
                                        */
  -0.5,                                /* Computed Parameter: HPF_C
                                        * Referenced by: '<S14>/HPF'
                                        */
  1.0,                                 /* Computed Parameter: HPF_D
                                        * Referenced by: '<S14>/HPF'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S15>/Gain1'
                                        */
  -0.5,                                /* Computed Parameter: LPF1_A
                                        * Referenced by: '<S15>/LPF1'
                                        */
  0.5,                                 /* Computed Parameter: LPF1_C
                                        * Referenced by: '<S15>/LPF1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  -0.5,                                /* Computed Parameter: HPF1_A
                                        * Referenced by: '<S15>/HPF1'
                                        */
  -0.5,                                /* Computed Parameter: HPF1_C
                                        * Referenced by: '<S15>/HPF1'
                                        */
  1.0,                                 /* Computed Parameter: HPF1_D
                                        * Referenced by: '<S15>/HPF1'
                                        */
  -60.0,                               /* Computed Parameter: LowPassFilterFilteredYawRate_A
                                        * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate)'
                                        */
  60.0,                                /* Computed Parameter: LowPassFilterFilteredYawRate_C
                                        * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate)'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch - Kd'
                                        */
  0.0,                                 /* Expression: 0*pi/180
                                        * Referenced by: '<S7>/heading command'
                                        */
  0.00052359877559829881,              /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  -0.00052359877559829881,             /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Rate Limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Bias'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch - Kp'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S119>/Saturation3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S119>/Saturation3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S139>/Integrator2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S131>/Switch - Kd'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S135>/vmax takeoff'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S135>/amax takeoff'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S129>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S66>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/CLOSED-LOOP ON'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/JOYSTICK ON'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S66>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Signal Generator'
                                        */
  0.0125,                              /* Expression: 0.0125
                                        * Referenced by: '<S7>/Signal Generator'
                                        */
  0.002,                               /* Expression: qc_get_step_size
                                        * Referenced by: '<S116>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S116>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S129>/Switch'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S135>/vmax flight'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S135>/amax flight'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S131>/Switch - Kp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S138>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S131>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S131>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S131>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S131>/Constant1'
                                        */
  0.00165,                             /* Expression: 1.65e-4*20*0.5
                                        * Referenced by: '<S131>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S11>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S122>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S122>/land throttle target'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S123>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S123>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S127>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFilteredYawRateFor
                                        * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFilteredYawRateF_c
                                        * Referenced by: '<S13>/Low Pass Filter (Filtered Yaw Rate) (For Joytstick Control)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Default Joystick CMD - Yaw'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  -60.0,                               /* Computed Parameter: LowPassFilterFilteredPitchRate_
                                        * Referenced by: '<S81>/Low Pass Filter (Filtered Pitch Rate)'
                                        */
  60.0,                                /* Computed Parameter: LowPassFilterFilteredPitchRat_e
                                        * Referenced by: '<S81>/Low Pass Filter (Filtered Pitch Rate)'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch - Kd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S85>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Default Joystick CMD - Pitch'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S83>/Switch'
                                        */
  0.15,                                /* Expression: 0.15
                                        * Referenced by: '<S6>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch - Kp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S81>/Integrator1'
                                        */
  -60.0,                               /* Computed Parameter: LowPassFilterFilteredRollRate_A
                                        * Referenced by: '<S97>/Low Pass Filter (Filtered Roll Rate)'
                                        */
  60.0,                                /* Computed Parameter: LowPassFilterFilteredRollRate_C
                                        * Referenced by: '<S97>/Low Pass Filter (Filtered Roll Rate)'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S97>/Switch - Kd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S103>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Default Joystick CMD - Roll'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S101>/Switch'
                                        */
  0.15,                                /* Expression: 0.15
                                        * Referenced by: '<S8>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S97>/Switch - Kp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S97>/Integrator1'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S16>/Step Initialize zero throttle for 3 seconds'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Step Initialize zero throttle for 3 seconds'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Step Initialize zero throttle for 3 seconds'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S20>/Constant2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S61>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S61>/Memory'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S63>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S89>/Integrator2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S86>/Switch - Kd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S7>/Transport Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Transport Delay'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S86>/Switch - Kp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S86>/Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S86>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S107>/Integrator2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S104>/Switch - Kd'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Signal Generator1'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S7>/Signal Generator1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S104>/Switch - Kp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S104>/Integrator1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S89>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S89>/x0'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S86>/Switch - Ki'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch - Ki'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S6>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Signal Generator2'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<S7>/Signal Generator2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S97>/Switch - Ki'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S107>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S107>/x0'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S104>/Switch - Ki'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Dummy Heading Reference (rad)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Enable'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S139>/Constant'
                                        */
  0.0,                                 /* Expression: input_init
                                        * Referenced by: '<S139>/x0'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S131>/Switch - Ki'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S13>/Switch - Ki'
                                        */
  0,                                   /* Computed Parameter: StreamClient_SndPriority
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  0,                                   /* Computed Parameter: StreamClient_RcvPriority
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  0,                                   /* Computed Parameter: StreamServer_SndPriority
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: StreamServer_RcvPriority
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  1460U,                               /* Computed Parameter: StreamClient_SndSize
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  1460U,                               /* Computed Parameter: StreamClient_RcvSize
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  1000U,                               /* Computed Parameter: StreamClient_SndFIFO
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  1000U,                               /* Computed Parameter: StreamClient_RcvFIFO
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  1U,                                  /* Computed Parameter: ToHostFile_Decimation
                                        * Referenced by: '<S9>/To Host File'
                                        */
  1460U,                               /* Computed Parameter: StreamServer_SndSize
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  1460U,                               /* Computed Parameter: StreamServer_RcvSize
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_SndFIFO
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  1000U,                               /* Computed Parameter: StreamServer_RcvFIFO
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  2,                                   /* Computed Parameter: StreamClient_Optimize
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  1,                                   /* Computed Parameter: StreamClient_Implementation
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  2,                                   /* Computed Parameter: StreamServer_Optimize
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  1,                                   /* Computed Parameter: StreamServer_Implementation
                                        * Referenced by: '<S10>/Stream Server'
                                        */

  /*  Expression: value
   * Referenced by: '<S12>/String Constant1'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 49U, 57U, 50U, 46U, 49U, 54U,
    56U, 46U, 50U, 46U, 49U, 48U, 58U, 49U, 56U, 48U, 48U, 54U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
  0U,                                  /* Expression: uri_argument
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  1U,                                  /* Computed Parameter: StreamClient_Endian
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  0U,                                  /* Computed Parameter: BatteryTopOrBottom_CurrentSetti
                                        * Referenced by: '<S23>/Battery Top Or Bottom'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S15>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_m
                                        * Referenced by: '<S119>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch2'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_f
                                        * Referenced by: '<S131>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_l
                                        * Referenced by: '<S123>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch4_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch4'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_lk
                                        * Referenced by: '<S6>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_j
                                        * Referenced by: '<S81>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_k
                                        * Referenced by: '<S8>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_h
                                        * Referenced by: '<S97>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<S7>/Manual Switch1'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch2_CurrentSetting_c
                                        * Referenced by: '<S7>/Manual Switch2'
                                        */

  /*  Expression: file_name_argument
   * Referenced by: '<S9>/To Host File'
   */
  { 113U, 98U, 97U, 108U, 108U, 95U, 102U, 108U, 105U, 103U, 104U, 116U, 95U,
    100U, 97U, 116U, 97U, 95U, 51U, 49U, 45U, 65U, 117U, 103U, 45U, 50U, 48U,
    49U, 53U, 95U, 50U, 51U, 45U, 49U, 52U, 45U, 49U, 55U, 46U, 109U, 97U, 116U,
    0U },

  /*  Expression: variable_name_argument
   * Referenced by: '<S9>/To Host File'
   */
  { 113U, 98U, 97U, 108U, 108U, 95U, 100U, 97U, 116U, 97U, 0U },
  1U,                                  /* Computed Parameter: ToHostFile_FileFormat
                                        * Referenced by: '<S9>/To Host File'
                                        */

  /*  Expression: uri_argument
   * Referenced by: '<S10>/Stream Server'
   */
  { 116U, 99U, 112U, 105U, 112U, 58U, 47U, 47U, 108U, 111U, 99U, 97U, 108U, 104U,
    111U, 115U, 116U, 58U, 49U, 56U, 48U, 48U, 55U, 0U },
  1U,                                  /* Computed Parameter: StreamServer_Endian
                                        * Referenced by: '<S10>/Stream Server'
                                        */
  0,                                   /* Computed Parameter: timeout_Y0
                                        * Referenced by: '<S22>/timeout'
                                        */
  0,                                   /* Computed Parameter: timeout_Y0_k
                                        * Referenced by: '<S76>/timeout'
                                        */
  0,                                   /* Computed Parameter: HILReadWrite1_Active
                                        * Referenced by: '<S3>/HIL Read Write1'
                                        */
  0,                                   /* Computed Parameter: StreamClient_Active
                                        * Referenced by: '<S4>/Stream Client'
                                        */
  0,                                   /* Computed Parameter: HILWatchdog_Active
                                        * Referenced by: '<S3>/HIL Watchdog'
                                        */
  0,                                   /* Computed Parameter: StreamServer_Active
                                        * Referenced by: '<S10>/Stream Server'
                                        */

  /* Start of '<S123>/Enabled Subsystem1' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S128>/Constant'
                                        */
    0.002,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S128>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S128>/Discrete-Time Integrator'
                                        */
    0                                  /* Computed Parameter: timeout_Y0
                                        * Referenced by: '<S128>/timeout'
                                        */
  }
  /* End of '<S123>/Enabled Subsystem1' */
  ,

  /* Start of '<S66>/Enabled Subsystem1' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S77>/Constant'
                                        */
    0.002,                             /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S77>/Discrete-Time Integrator'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S77>/Discrete-Time Integrator'
                                        */
    0                                  /* Computed Parameter: timeout_Y0
                                        * Referenced by: '<S77>/timeout'
                                        */
  }
  /* End of '<S66>/Enabled Subsystem1' */
  ,

  /* Start of '<S27>/Enabled Moving Average' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S40>/unity'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S40>/Unit Delay'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S39>/Sum( k=1,n-1, x(k) )'
                                        */
  }
  /* End of '<S27>/Enabled Moving Average' */
  ,

  /* Start of '<S31>/Enabled Moving Average' */
  {
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S38>/unity'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S38>/Unit Delay'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S34>/Sum( k=1,n-1, x(k) )'
                                        */
  }
  /* End of '<S31>/Enabled Moving Average' */
};
