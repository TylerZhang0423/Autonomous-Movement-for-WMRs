  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 14;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (follower_qbot2_P)
    ;%
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.HILInitialize_analog_input_maxi
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.HILInitialize_analog_input_mini
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% follower_qbot2_P.StreamClient_default_value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% follower_qbot2_P.StreamClient_default_value_g
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 22;
	
	  ;% follower_qbot2_P.BiasRemoval_end_time
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% follower_qbot2_P.BiasRemoval_end_time_a
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 26;
	
	  ;% follower_qbot2_P.HILInitialize_final_other_outpu
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 27;
	
	  ;% follower_qbot2_P.HILInitialize_final_pwm_outputs
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 31;
	
	  ;% follower_qbot2_P.HILInitialize_initial_other_out
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 32;
	
	  ;% follower_qbot2_P.HILInitialize_initial_pwm_outpu
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 36;
	
	  ;% follower_qbot2_P.SecondOrderLowPassFilter1_input
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 37;
	
	  ;% follower_qbot2_P.SecondOrderLowPassFilter4_input
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 38;
	
	  ;% follower_qbot2_P.SecondOrderLowPassFilter1_inp_f
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 39;
	
	  ;% follower_qbot2_P.SecondOrderLowPassFilter4_inp_i
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 40;
	
	  ;% follower_qbot2_P.NormalizeVector_maxzero
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 41;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_frequency
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 42;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_leading_deadb
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 43;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_trailing_dead
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 44;
	
	  ;% follower_qbot2_P.HILInitialize_set_other_outputs
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 45;
	
	  ;% follower_qbot2_P.HILInitialize_set_other_outpu_c
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 46;
	
	  ;% follower_qbot2_P.HILInitialize_set_other_outpu_n
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 47;
	
	  ;% follower_qbot2_P.HILInitialize_set_other_outpu_h
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 48;
	
	  ;% follower_qbot2_P.BiasRemoval_start_time
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 49;
	
	  ;% follower_qbot2_P.BiasRemoval_start_time_g
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 50;
	
	  ;% follower_qbot2_P.BiasRemoval_switch_id
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 51;
	
	  ;% follower_qbot2_P.BiasRemoval_switch_id_m
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 52;
	
	  ;% follower_qbot2_P.HILInitialize_watchdog_pwm_outp
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 53;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.HILInitialize_initial_encoder_c
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_alignment
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_configuration
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_modes
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_polarity
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
	  ;% follower_qbot2_P.HILInitialize_watchdog_digital_
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.HILRead1_analog_channels
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.HILInitialize_analog_input_chan
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.HILRead1_digital_channels
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 11;
	
	  ;% follower_qbot2_P.HILInitialize_encoder_channels
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 14;
	
	  ;% follower_qbot2_P.HILRead1_encoder_channels
	  section.data(5).logicalSrcIdx = 37;
	  section.data(5).dtTransOffset = 18;
	
	  ;% follower_qbot2_P.HILRead1_other_channels
	  section.data(6).logicalSrcIdx = 38;
	  section.data(6).dtTransOffset = 20;
	
	  ;% follower_qbot2_P.HILWrite_other_channels
	  section.data(7).logicalSrcIdx = 39;
	  section.data(7).dtTransOffset = 21;
	
	  ;% follower_qbot2_P.HILInitialize_other_output_chan
	  section.data(8).logicalSrcIdx = 40;
	  section.data(8).dtTransOffset = 23;
	
	  ;% follower_qbot2_P.HILInitialize_pwm_channels
	  section.data(9).logicalSrcIdx = 41;
	  section.data(9).dtTransOffset = 27;
	
	  ;% follower_qbot2_P.HILInitialize_quadrature
	  section.data(10).logicalSrcIdx = 42;
	  section.data(10).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.ShowMessageonHost_message_icon
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.ShowMessageonHost1_message_icon
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.ShowMessageonHost2_message_icon
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.CompareToConstant_const
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.CompareToConstant_const_k
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_inpu_g
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 4;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 5;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_outp_o
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 6;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_outp_m
	  section.data(8).logicalSrcIdx = 55;
	  section.data(8).dtTransOffset = 7;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_out_oi
	  section.data(9).logicalSrcIdx = 56;
	  section.data(9).dtTransOffset = 8;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_out_o2
	  section.data(10).logicalSrcIdx = 57;
	  section.data(10).dtTransOffset = 9;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_outp_k
	  section.data(11).logicalSrcIdx = 58;
	  section.data(11).dtTransOffset = 10;
	
	  ;% follower_qbot2_P.HILInitialize_set_analog_outp_g
	  section.data(12).logicalSrcIdx = 59;
	  section.data(12).dtTransOffset = 11;
	
	  ;% follower_qbot2_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 60;
	  section.data(13).dtTransOffset = 12;
	
	  ;% follower_qbot2_P.HILInitialize_set_clock_frequ_k
	  section.data(14).logicalSrcIdx = 61;
	  section.data(14).dtTransOffset = 13;
	
	  ;% follower_qbot2_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 62;
	  section.data(15).dtTransOffset = 14;
	
	  ;% follower_qbot2_P.HILInitialize_set_clock_param_f
	  section.data(16).logicalSrcIdx = 63;
	  section.data(16).dtTransOffset = 15;
	
	  ;% follower_qbot2_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 64;
	  section.data(17).dtTransOffset = 16;
	
	  ;% follower_qbot2_P.HILInitialize_set_digital_out_j
	  section.data(18).logicalSrcIdx = 65;
	  section.data(18).dtTransOffset = 17;
	
	  ;% follower_qbot2_P.HILInitialize_set_digital_out_g
	  section.data(19).logicalSrcIdx = 66;
	  section.data(19).dtTransOffset = 18;
	
	  ;% follower_qbot2_P.HILInitialize_set_digital_out_m
	  section.data(20).logicalSrcIdx = 67;
	  section.data(20).dtTransOffset = 19;
	
	  ;% follower_qbot2_P.HILInitialize_set_digital_ou_m3
	  section.data(21).logicalSrcIdx = 68;
	  section.data(21).dtTransOffset = 20;
	
	  ;% follower_qbot2_P.HILInitialize_set_digital_ou_gg
	  section.data(22).logicalSrcIdx = 69;
	  section.data(22).dtTransOffset = 21;
	
	  ;% follower_qbot2_P.HILInitialize_set_digital_out_d
	  section.data(23).logicalSrcIdx = 70;
	  section.data(23).dtTransOffset = 22;
	
	  ;% follower_qbot2_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 71;
	  section.data(24).dtTransOffset = 23;
	
	  ;% follower_qbot2_P.HILInitialize_set_encoder_cou_f
	  section.data(25).logicalSrcIdx = 72;
	  section.data(25).dtTransOffset = 24;
	
	  ;% follower_qbot2_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 73;
	  section.data(26).dtTransOffset = 25;
	
	  ;% follower_qbot2_P.HILInitialize_set_encoder_par_h
	  section.data(27).logicalSrcIdx = 74;
	  section.data(27).dtTransOffset = 26;
	
	  ;% follower_qbot2_P.HILInitialize_set_other_outpu_l
	  section.data(28).logicalSrcIdx = 75;
	  section.data(28).dtTransOffset = 27;
	
	  ;% follower_qbot2_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 76;
	  section.data(29).dtTransOffset = 28;
	
	  ;% follower_qbot2_P.HILInitialize_set_pwm_outputs_d
	  section.data(30).logicalSrcIdx = 77;
	  section.data(30).dtTransOffset = 29;
	
	  ;% follower_qbot2_P.HILInitialize_set_pwm_outputs_f
	  section.data(31).logicalSrcIdx = 78;
	  section.data(31).dtTransOffset = 30;
	
	  ;% follower_qbot2_P.HILInitialize_set_pwm_outputs_b
	  section.data(32).logicalSrcIdx = 79;
	  section.data(32).dtTransOffset = 31;
	
	  ;% follower_qbot2_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 80;
	  section.data(33).dtTransOffset = 32;
	
	  ;% follower_qbot2_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 81;
	  section.data(34).dtTransOffset = 33;
	
	  ;% follower_qbot2_P.HILInitialize_set_pwm_params__c
	  section.data(35).logicalSrcIdx = 82;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 58;
      section.data(58)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.DummyAngle_Value
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.unity_Value
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.UnitDelay_InitialCondition
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_P.Sumk1n1xk_InitialCondition
	  section.data(4).logicalSrcIdx = 86;
	  section.data(4).dtTransOffset = 3;
	
	  ;% follower_qbot2_P.Vbiased_Y0
	  section.data(5).logicalSrcIdx = 87;
	  section.data(5).dtTransOffset = 4;
	
	  ;% follower_qbot2_P.Vunbiased_Y0
	  section.data(6).logicalSrcIdx = 88;
	  section.data(6).dtTransOffset = 5;
	
	  ;% follower_qbot2_P.Stepstart_time_Y0
	  section.data(7).logicalSrcIdx = 89;
	  section.data(7).dtTransOffset = 6;
	
	  ;% follower_qbot2_P.Stepstart_time_YFinal
	  section.data(8).logicalSrcIdx = 90;
	  section.data(8).dtTransOffset = 7;
	
	  ;% follower_qbot2_P.Stepend_time_Y0
	  section.data(9).logicalSrcIdx = 91;
	  section.data(9).dtTransOffset = 8;
	
	  ;% follower_qbot2_P.Stepend_time_YFinal
	  section.data(10).logicalSrcIdx = 92;
	  section.data(10).dtTransOffset = 9;
	
	  ;% follower_qbot2_P.Constant_Value
	  section.data(11).logicalSrcIdx = 93;
	  section.data(11).dtTransOffset = 10;
	
	  ;% follower_qbot2_P.unity_Value_a
	  section.data(12).logicalSrcIdx = 94;
	  section.data(12).dtTransOffset = 11;
	
	  ;% follower_qbot2_P.UnitDelay_InitialCondition_h
	  section.data(13).logicalSrcIdx = 95;
	  section.data(13).dtTransOffset = 12;
	
	  ;% follower_qbot2_P.Sumk1n1xk_InitialCondition_h
	  section.data(14).logicalSrcIdx = 96;
	  section.data(14).dtTransOffset = 13;
	
	  ;% follower_qbot2_P.Vbiased_Y0_o
	  section.data(15).logicalSrcIdx = 97;
	  section.data(15).dtTransOffset = 14;
	
	  ;% follower_qbot2_P.Vunbiased_Y0_p
	  section.data(16).logicalSrcIdx = 98;
	  section.data(16).dtTransOffset = 15;
	
	  ;% follower_qbot2_P.Stepstart_time_Y0_g
	  section.data(17).logicalSrcIdx = 99;
	  section.data(17).dtTransOffset = 16;
	
	  ;% follower_qbot2_P.Stepstart_time_YFinal_p
	  section.data(18).logicalSrcIdx = 100;
	  section.data(18).dtTransOffset = 17;
	
	  ;% follower_qbot2_P.Stepend_time_Y0_g
	  section.data(19).logicalSrcIdx = 101;
	  section.data(19).dtTransOffset = 18;
	
	  ;% follower_qbot2_P.Stepend_time_YFinal_i
	  section.data(20).logicalSrcIdx = 102;
	  section.data(20).dtTransOffset = 19;
	
	  ;% follower_qbot2_P.SignalThreshold_Value
	  section.data(21).logicalSrcIdx = 103;
	  section.data(21).dtTransOffset = 20;
	
	  ;% follower_qbot2_P.DiscreteTimeIntegrator_gainval
	  section.data(22).logicalSrcIdx = 104;
	  section.data(22).dtTransOffset = 21;
	
	  ;% follower_qbot2_P.DiscreteTimeIntegrator_IC
	  section.data(23).logicalSrcIdx = 105;
	  section.data(23).dtTransOffset = 22;
	
	  ;% follower_qbot2_P.TimeoutThresholds_Value
	  section.data(24).logicalSrcIdx = 106;
	  section.data(24).dtTransOffset = 23;
	
	  ;% follower_qbot2_P.DiscreteTimeIntegrator_gainva_d
	  section.data(25).logicalSrcIdx = 107;
	  section.data(25).dtTransOffset = 24;
	
	  ;% follower_qbot2_P.DiscreteTimeIntegrator_IC_n
	  section.data(26).logicalSrcIdx = 108;
	  section.data(26).dtTransOffset = 25;
	
	  ;% follower_qbot2_P.DiscreteTimeIntegrator_gainva_e
	  section.data(27).logicalSrcIdx = 109;
	  section.data(27).dtTransOffset = 26;
	
	  ;% follower_qbot2_P.DiscreteTimeIntegrator_IC_c
	  section.data(28).logicalSrcIdx = 110;
	  section.data(28).dtTransOffset = 27;
	
	  ;% follower_qbot2_P.Memory_X0
	  section.data(29).logicalSrcIdx = 111;
	  section.data(29).dtTransOffset = 28;
	
	  ;% follower_qbot2_P.Switch_Threshold
	  section.data(30).logicalSrcIdx = 112;
	  section.data(30).dtTransOffset = 29;
	
	  ;% follower_qbot2_P.Memory1_X0
	  section.data(31).logicalSrcIdx = 113;
	  section.data(31).dtTransOffset = 30;
	
	  ;% follower_qbot2_P.FollowingDistancem_Value
	  section.data(32).logicalSrcIdx = 114;
	  section.data(32).dtTransOffset = 31;
	
	  ;% follower_qbot2_P.LandingZoneBoundarym_Value
	  section.data(33).logicalSrcIdx = 115;
	  section.data(33).dtTransOffset = 32;
	
	  ;% follower_qbot2_P.BoundaryZoneLimitm_Value
	  section.data(34).logicalSrcIdx = 116;
	  section.data(34).dtTransOffset = 33;
	
	  ;% follower_qbot2_P.x0_Value
	  section.data(35).logicalSrcIdx = 117;
	  section.data(35).dtTransOffset = 34;
	
	  ;% follower_qbot2_P.Enable_Value
	  section.data(36).logicalSrcIdx = 118;
	  section.data(36).dtTransOffset = 35;
	
	  ;% follower_qbot2_P.Disable_Value
	  section.data(37).logicalSrcIdx = 119;
	  section.data(37).dtTransOffset = 36;
	
	  ;% follower_qbot2_P.RateLimiterLinearSpeed_RisingLi
	  section.data(38).logicalSrcIdx = 120;
	  section.data(38).dtTransOffset = 37;
	
	  ;% follower_qbot2_P.RateLimiterLinearSpeed_FallingL
	  section.data(39).logicalSrcIdx = 121;
	  section.data(39).dtTransOffset = 38;
	
	  ;% follower_qbot2_P.x0_Value_n
	  section.data(40).logicalSrcIdx = 122;
	  section.data(40).dtTransOffset = 39;
	
	  ;% follower_qbot2_P.RateLimiterRotationRate_RisingL
	  section.data(41).logicalSrcIdx = 123;
	  section.data(41).dtTransOffset = 40;
	
	  ;% follower_qbot2_P.RateLimiterRotationRate_Falling
	  section.data(42).logicalSrcIdx = 124;
	  section.data(42).dtTransOffset = 41;
	
	  ;% follower_qbot2_P.VLimit2_Value
	  section.data(43).logicalSrcIdx = 125;
	  section.data(43).dtTransOffset = 42;
	
	  ;% follower_qbot2_P.Gain_Gain
	  section.data(44).logicalSrcIdx = 126;
	  section.data(44).dtTransOffset = 43;
	
	  ;% follower_qbot2_P.Sequential_Value
	  section.data(45).logicalSrcIdx = 127;
	  section.data(45).dtTransOffset = 44;
	
	  ;% follower_qbot2_P.Simultaneous_Value
	  section.data(46).logicalSrcIdx = 128;
	  section.data(46).dtTransOffset = 45;
	
	  ;% follower_qbot2_P.VLimit_Value
	  section.data(47).logicalSrcIdx = 129;
	  section.data(47).dtTransOffset = 46;
	
	  ;% follower_qbot2_P.VLimit1_Value
	  section.data(48).logicalSrcIdx = 130;
	  section.data(48).dtTransOffset = 47;
	
	  ;% follower_qbot2_P.Kv_1_Value
	  section.data(49).logicalSrcIdx = 131;
	  section.data(49).dtTransOffset = 48;
	
	  ;% follower_qbot2_P.Kv_2_Value
	  section.data(50).logicalSrcIdx = 132;
	  section.data(50).dtTransOffset = 49;
	
	  ;% follower_qbot2_P.Kv_3_Value
	  section.data(51).logicalSrcIdx = 133;
	  section.data(51).dtTransOffset = 50;
	
	  ;% follower_qbot2_P.Kv_4_Value
	  section.data(52).logicalSrcIdx = 134;
	  section.data(52).dtTransOffset = 51;
	
	  ;% follower_qbot2_P.Constant_Value_d
	  section.data(53).logicalSrcIdx = 135;
	  section.data(53).dtTransOffset = 52;
	
	  ;% follower_qbot2_P.Integrator2_IC
	  section.data(54).logicalSrcIdx = 136;
	  section.data(54).dtTransOffset = 53;
	
	  ;% follower_qbot2_P.WaypointStep_Value
	  section.data(55).logicalSrcIdx = 137;
	  section.data(55).dtTransOffset = 54;
	
	  ;% follower_qbot2_P.Memory_X0_n
	  section.data(56).logicalSrcIdx = 138;
	  section.data(56).dtTransOffset = 55;
	
	  ;% follower_qbot2_P.Constant_Value_l
	  section.data(57).logicalSrcIdx = 139;
	  section.data(57).dtTransOffset = 56;
	
	  ;% follower_qbot2_P.Integrator2_IC_j
	  section.data(58).logicalSrcIdx = 140;
	  section.data(58).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.StreamClient_SndPriority
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.StreamClient_RcvPriority
	  section.data(2).logicalSrcIdx = 142;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.StreamClient_SndPriority_n
	  section.data(3).logicalSrcIdx = 143;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_P.StreamClient_RcvPriority_p
	  section.data(4).logicalSrcIdx = 144;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.StreamClient_SndSize
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.StreamClient_RcvSize
	  section.data(2).logicalSrcIdx = 146;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.StreamClient_SndFIFO
	  section.data(3).logicalSrcIdx = 147;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_P.StreamClient_RcvFIFO
	  section.data(4).logicalSrcIdx = 148;
	  section.data(4).dtTransOffset = 3;
	
	  ;% follower_qbot2_P.StreamClient_SndSize_a
	  section.data(5).logicalSrcIdx = 149;
	  section.data(5).dtTransOffset = 4;
	
	  ;% follower_qbot2_P.StreamClient_RcvSize_j
	  section.data(6).logicalSrcIdx = 150;
	  section.data(6).dtTransOffset = 5;
	
	  ;% follower_qbot2_P.StreamClient_SndFIFO_h
	  section.data(7).logicalSrcIdx = 151;
	  section.data(7).dtTransOffset = 6;
	
	  ;% follower_qbot2_P.StreamClient_RcvFIFO_h
	  section.data(8).logicalSrcIdx = 152;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.StreamClient_Optimize
	  section.data(1).logicalSrcIdx = 153;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.StreamClient_Implementation
	  section.data(2).logicalSrcIdx = 154;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.StreamClient_Optimize_i
	  section.data(3).logicalSrcIdx = 155;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_P.StreamClient_Implementation_g
	  section.data(4).logicalSrcIdx = 156;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.StringConstant1_Value
	  section.data(1).logicalSrcIdx = 157;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.StreamClient_URI
	  section.data(2).logicalSrcIdx = 158;
	  section.data(2).dtTransOffset = 80;
	
	  ;% follower_qbot2_P.StreamClient_Endian
	  section.data(3).logicalSrcIdx = 159;
	  section.data(3).dtTransOffset = 81;
	
	  ;% follower_qbot2_P.StringConstant2_Value
	  section.data(4).logicalSrcIdx = 160;
	  section.data(4).dtTransOffset = 82;
	
	  ;% follower_qbot2_P.StreamClient_URI_o
	  section.data(5).logicalSrcIdx = 161;
	  section.data(5).dtTransOffset = 162;
	
	  ;% follower_qbot2_P.StreamClient_Endian_i
	  section.data(6).logicalSrcIdx = 162;
	  section.data(6).dtTransOffset = 163;
	
	  ;% follower_qbot2_P.ManualSwitchQBot2Enable_Current
	  section.data(7).logicalSrcIdx = 163;
	  section.data(7).dtTransOffset = 164;
	
	  ;% follower_qbot2_P.ManualSwitchTrackingMethod_Curr
	  section.data(8).logicalSrcIdx = 164;
	  section.data(8).dtTransOffset = 165;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.StreamClient_Active
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_P.StreamClient_Active_j
	  section.data(2).logicalSrcIdx = 166;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_P.HILRead1_Active
	  section.data(3).logicalSrcIdx = 167;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_P.HILWrite_Active
	  section.data(4).logicalSrcIdx = 168;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.SwitchCaseActionSubsystem_a.zero_Y0
	  section.data(1).logicalSrcIdx = 169;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% follower_qbot2_P.SwitchCaseActionSubsystem.zero_Y0
	  section.data(1).logicalSrcIdx = 170;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (follower_qbot2_B)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% follower_qbot2_B.StreamClient_o3
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_B.DataTypeConversion
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% follower_qbot2_B.StreamClient_o3_f
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% follower_qbot2_B.DataTypeConversion_n
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 8;
	
	  ;% follower_qbot2_B.Switch
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 9;
	
	  ;% follower_qbot2_B.Switch1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 12;
	
	  ;% follower_qbot2_B.SwitchArrived
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 15;
	
	  ;% follower_qbot2_B.x0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 18;
	
	  ;% follower_qbot2_B.ManualSwitchQBot2Enable
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 19;
	
	  ;% follower_qbot2_B.RateLimiterLinearSpeed
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 20;
	
	  ;% follower_qbot2_B.x0_l
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 21;
	
	  ;% follower_qbot2_B.RateLimiterRotationRate
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 22;
	
	  ;% follower_qbot2_B.Product
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 23;
	
	  ;% follower_qbot2_B.Product1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
	  ;% follower_qbot2_B.Product_k
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 25;
	
	  ;% follower_qbot2_B.Product1_j
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 26;
	
	  ;% follower_qbot2_B.Vf
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 27;
	
	  ;% follower_qbot2_B.W
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 28;
	
	  ;% follower_qbot2_B.vR
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 29;
	
	  ;% follower_qbot2_B.vL
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 30;
	
	  ;% follower_qbot2_B.div_e
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% follower_qbot2_B.StreamClient_o2
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_B.StreamClient_o2_i
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% follower_qbot2_B.StreamClient_o4
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_B.RelationalOperator
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_B.RelationalOperator_b
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_B.StreamClient_o4_d
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% follower_qbot2_B.RelationalOperator_l
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
	  ;% follower_qbot2_B.LogicalOperator1
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 11;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (follower_qbot2_DW)
    ;%
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_l
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_DW.DiscreteTimeIntegrator_DSTATE_c
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_DW.UnitDelay_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% follower_qbot2_DW.Sumk1n1xk_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% follower_qbot2_DW.UnitDelay_DSTATE_e
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% follower_qbot2_DW.Sumk1n1xk_DSTATE_k
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% follower_qbot2_DW.HILInitialize_AIMinimums
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% follower_qbot2_DW.HILInitialize_AIMaximums
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 18;
	
	  ;% follower_qbot2_DW.HILInitialize_FilterFrequency
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 28;
	
	  ;% follower_qbot2_DW.HILInitialize_POSortedFreqs
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 32;
	
	  ;% follower_qbot2_DW.HILInitialize_POValues
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 36;
	
	  ;% follower_qbot2_DW.HILInitialize_OOValues
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 40;
	
	  ;% follower_qbot2_DW.Memory_PreviousInput
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 44;
	
	  ;% follower_qbot2_DW.Memory1_PreviousInput
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 47;
	
	  ;% follower_qbot2_DW.PrevY
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 50;
	
	  ;% follower_qbot2_DW.LastMajorTime
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 51;
	
	  ;% follower_qbot2_DW.PrevY_o
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 52;
	
	  ;% follower_qbot2_DW.LastMajorTime_c
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 53;
	
	  ;% follower_qbot2_DW.HILWrite_OtherBuffer
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 54;
	
	  ;% follower_qbot2_DW.Memory_PreviousInput_e
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 56;
	
	  ;% follower_qbot2_DW.Vf_1
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 57;
	
	  ;% follower_qbot2_DW.end_flag
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.StreamClient_Stream
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_DW.StreamClient_Stream_o
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.HILRead1_PWORK
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_DW.HILWrite_PWORK
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_DW.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 4;
	
	  ;% follower_qbot2_DW.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 8;
	
	  ;% follower_qbot2_DW.HILInitialize_POAlignValues
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 12;
	
	  ;% follower_qbot2_DW.HILInitialize_POPolarityVals
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 16;
	
	  ;% follower_qbot2_DW.HILRead1_EncoderBuffer
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.Integrator1_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_DW.Integrator1_IWORK_p.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_n
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_DW.DiscreteTimeIntegrator_PrevRe_g
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_DW.EnabledMovingAverage_SubsysRanB
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
	  ;% follower_qbot2_DW.SwitchCase_ActiveSubsystem
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 4;
	
	  ;% follower_qbot2_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(6).logicalSrcIdx = 42;
	  section.data(6).dtTransOffset = 5;
	
	  ;% follower_qbot2_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(7).logicalSrcIdx = 43;
	  section.data(7).dtTransOffset = 6;
	
	  ;% follower_qbot2_DW.EnabledMovingAverage_SubsysRa_e
	  section.data(8).logicalSrcIdx = 44;
	  section.data(8).dtTransOffset = 7;
	
	  ;% follower_qbot2_DW.SwitchCase_ActiveSubsystem_p
	  section.data(9).logicalSrcIdx = 45;
	  section.data(9).dtTransOffset = 8;
	
	  ;% follower_qbot2_DW.SwitchCaseActionSubsystem1_Su_m
	  section.data(10).logicalSrcIdx = 46;
	  section.data(10).dtTransOffset = 9;
	
	  ;% follower_qbot2_DW.SwitchCaseActionSubsystem2_Su_j
	  section.data(11).logicalSrcIdx = 47;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.StreamClient_Connected
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% follower_qbot2_DW.StreamClient_Connected_i
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% follower_qbot2_DW.EnabledMovingAverage_MODE
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% follower_qbot2_DW.EnabledMovingAverage_MODE_g
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.SwitchCaseActionSubsystem_a.SwitchCaseActionSubsystem_Subsy
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% follower_qbot2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2184415200;
  targMap.checksum1 = 3183646196;
  targMap.checksum2 = 4164270047;
  targMap.checksum3 = 2946492325;

