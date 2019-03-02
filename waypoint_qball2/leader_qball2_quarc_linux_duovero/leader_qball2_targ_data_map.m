  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 17;
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
    ;% Auto data (leader_qball2_P)
    ;%
      section.nData     = 113;
      section.data(113)  = dumData; %prealloc
      
	  ;% leader_qball2_P.KdHEIGHT_DOWN
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.KdHEIGHT_UP
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.KdOUTER_PITCH_DOWN
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.KdOUTER_PITCH_UP
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_P.KdOUTER_ROLL_DOWN
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_P.KdOUTER_ROLL_UP
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% leader_qball2_P.KdPITCH_DOWN
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% leader_qball2_P.KdPITCH_UP
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% leader_qball2_P.KdROLL_DOWN
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% leader_qball2_P.KdROLL_UP
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% leader_qball2_P.KdYAW_DOWN
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% leader_qball2_P.KdYAW_UP
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% leader_qball2_P.KiHEIGHT_DOWN
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% leader_qball2_P.KiHEIGHT_UP
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% leader_qball2_P.KiOUTER_PITCH_DOWN
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% leader_qball2_P.KiOUTER_PITCH_UP
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% leader_qball2_P.KiOUTER_ROLL_DOWN
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% leader_qball2_P.KiOUTER_ROLL_UP
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% leader_qball2_P.KiPITCH_DOWN
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% leader_qball2_P.KiPITCH_UP
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% leader_qball2_P.KiROLL_DOWN
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% leader_qball2_P.KiROLL_UP
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% leader_qball2_P.KiYAW_DOWN
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% leader_qball2_P.KiYAW_UP
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% leader_qball2_P.KpHEIGHT_DOWN
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% leader_qball2_P.KpHEIGHT_UP
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% leader_qball2_P.KpOUTER_PITCH_DOWN
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% leader_qball2_P.KpOUTER_PITCH_UP
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% leader_qball2_P.KpOUTER_ROLL_DOWN
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% leader_qball2_P.KpOUTER_ROLL_UP
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% leader_qball2_P.KpPITCH_DOWN
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% leader_qball2_P.KpPITCH_UP
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% leader_qball2_P.KpROLL_DOWN
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% leader_qball2_P.KpROLL_UP
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% leader_qball2_P.KpYAW_DOWN
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% leader_qball2_P.KpYAW_UP
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% leader_qball2_P.LIMIT_CMD_PITCH
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% leader_qball2_P.LIMIT_CMD_ROLL
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% leader_qball2_P.LIMIT_MAX_HEIGHT
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% leader_qball2_P.LIMIT_MAX_X
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% leader_qball2_P.LIMIT_MAX_Z
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% leader_qball2_P.LIMIT_MIN_HEIGHT
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% leader_qball2_P.LIMIT_MIN_X
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% leader_qball2_P.LIMIT_MIN_Z
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% leader_qball2_P.LIMIT_RATE_HEIGHT
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% leader_qball2_P.LIMIT_uCMD_PITCH
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% leader_qball2_P.LIMIT_uCMD_ROLL
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% leader_qball2_P.LIMIT_uCMD_YAW
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% leader_qball2_P.OFFSET_HEIGHT
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% leader_qball2_P.OMEGA_DIFF
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% leader_qball2_P.OMEGA_FILTER
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% leader_qball2_P.TIMEOUT_CALIB
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% leader_qball2_P.TRIM_THROTTLE
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% leader_qball2_P.TRIM_U_PITCH
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% leader_qball2_P.TRIM_U_ROLL
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% leader_qball2_P.g
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% leader_qball2_P.joystick_range_max
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% leader_qball2_P.joystick_range_min
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% leader_qball2_P.FOH1_Ts
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% leader_qball2_P.HILInitialize_analog_input_maxi
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% leader_qball2_P.HILInitialize_analog_input_mini
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 62;
	
	  ;% leader_qball2_P.CompareToConstant_const
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 65;
	
	  ;% leader_qball2_P.CompareToConstant_const_o
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 66;
	
	  ;% leader_qball2_P.CompareToConstant_const_d
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 67;
	
	  ;% leader_qball2_P.CompareToConstant1_const
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 68;
	
	  ;% leader_qball2_P.CompareToConstant_const_k
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 69;
	
	  ;% leader_qball2_P.CompareToConstant_const_c
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 70;
	
	  ;% leader_qball2_P.CompareToConstant1_const_c
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 71;
	
	  ;% leader_qball2_P.CompareToConstant1_const_h
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 72;
	
	  ;% leader_qball2_P.CompareToConstant_const_m
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 73;
	
	  ;% leader_qball2_P.CompareToConstant_const_ol
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 74;
	
	  ;% leader_qball2_P.CompareToConstant1_const_n
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 75;
	
	  ;% leader_qball2_P.CompareToConstant2_const
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 76;
	
	  ;% leader_qball2_P.CompareToConstant_const_a
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 77;
	
	  ;% leader_qball2_P.CompareToConstant_const_i
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 78;
	
	  ;% leader_qball2_P.CompareToConstant_const_g
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 79;
	
	  ;% leader_qball2_P.CompareToConstant_const_aq
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 80;
	
	  ;% leader_qball2_P.CompareToConstant_const_ap
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 81;
	
	  ;% leader_qball2_P.CompareToConstant_const_mk
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 82;
	
	  ;% leader_qball2_P.StreamClient_default_value
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 83;
	
	  ;% leader_qball2_P.HILInitialize_final_other_outpu
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 93;
	
	  ;% leader_qball2_P.HILInitialize_final_pwm_outputs
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 94;
	
	  ;% leader_qball2_P.SliderGain_gain
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 95;
	
	  ;% leader_qball2_P.Joystickyawcommandgain1_gain
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 96;
	
	  ;% leader_qball2_P.Joystickyawcommandgain_gain
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 97;
	
	  ;% leader_qball2_P.Joystickyawcontrolgain_gain
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 98;
	
	  ;% leader_qball2_P.ContinuousSigmoid_hold_off
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 99;
	
	  ;% leader_qball2_P.TriggeredSigmoid_hold_off
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 100;
	
	  ;% leader_qball2_P.HILInitialize_initial_other_out
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 101;
	
	  ;% leader_qball2_P.ContinuousSigmoid_initial_posit
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 102;
	
	  ;% leader_qball2_P.HILInitialize_initial_pwm_outpu
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 103;
	
	  ;% leader_qball2_P.ContinuousSigmoid_initial_veloc
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 104;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter3_input
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 105;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter4_input
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 106;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter5_input
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 107;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter7_input
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 108;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter2_input
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 109;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter1_input
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 110;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter1_inp_e
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 111;
	
	  ;% leader_qball2_P.SecondOrderLowPassFilter_input_
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 112;
	
	  ;% leader_qball2_P.TriggeredSigmoid_max_accelerati
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 113;
	
	  ;% leader_qball2_P.TriggeredSigmoid_max_velocity
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 114;
	
	  ;% leader_qball2_P.HILInitialize_pwm_frequency
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 115;
	
	  ;% leader_qball2_P.HILInitialize_pwm_leading_deadb
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 116;
	
	  ;% leader_qball2_P.HILInitialize_pwm_trailing_dead
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 117;
	
	  ;% leader_qball2_P.HILInitialize_set_other_outputs
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 118;
	
	  ;% leader_qball2_P.HILInitialize_set_other_outpu_f
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 119;
	
	  ;% leader_qball2_P.HILInitialize_set_other_outpu_m
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 120;
	
	  ;% leader_qball2_P.HILInitialize_set_other_outpu_i
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 121;
	
	  ;% leader_qball2_P.BiasRemoval_start_time
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 122;
	
	  ;% leader_qball2_P.BiasRemoval_switch_id
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 123;
	
	  ;% leader_qball2_P.HILInitialize_watchdog_other_ou
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 124;
	
	  ;% leader_qball2_P.HILInitialize_watchdog_pwm_outp
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 125;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% leader_qball2_P.HILInitialize_pwm_alignment
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.HILInitialize_pwm_configuration
	  section.data(2).logicalSrcIdx = 114;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.HILInitialize_pwm_modes
	  section.data(3).logicalSrcIdx = 115;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.HILInitialize_pwm_polarity
	  section.data(4).logicalSrcIdx = 116;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_P.HILInitialize_watchdog_digital_
	  section.data(5).logicalSrcIdx = 117;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% leader_qball2_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.HILReadWrite1_analog_input_chan
	  section.data(2).logicalSrcIdx = 119;
	  section.data(2).dtTransOffset = 3;
	
	  ;% leader_qball2_P.HILInitialize_digital_output_ch
	  section.data(3).logicalSrcIdx = 120;
	  section.data(3).dtTransOffset = 4;
	
	  ;% leader_qball2_P.HILReadWrite1_digital_output_ch
	  section.data(4).logicalSrcIdx = 121;
	  section.data(4).dtTransOffset = 6;
	
	  ;% leader_qball2_P.HILReadWrite1_other_input_chann
	  section.data(5).logicalSrcIdx = 122;
	  section.data(5).dtTransOffset = 8;
	
	  ;% leader_qball2_P.HILInitialize_other_output_chan
	  section.data(6).logicalSrcIdx = 123;
	  section.data(6).dtTransOffset = 15;
	
	  ;% leader_qball2_P.HILReadWrite1_other_output_chan
	  section.data(7).logicalSrcIdx = 124;
	  section.data(7).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% leader_qball2_P.ShowMessageonHost1_message_icon
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.ShowMessageonHost_message_icon
	  section.data(2).logicalSrcIdx = 126;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.ShowMessageonHost1_message_ic_m
	  section.data(3).logicalSrcIdx = 127;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.ShowMessageonHost_message_ico_h
	  section.data(4).logicalSrcIdx = 128;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_P.ShowMessageonHost1_message_i_m5
	  section.data(5).logicalSrcIdx = 129;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% leader_qball2_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 130;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 131;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 132;
	  section.data(3).dtTransOffset = 3;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 133;
	  section.data(4).dtTransOffset = 4;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_inpu_e
	  section.data(5).logicalSrcIdx = 134;
	  section.data(5).dtTransOffset = 5;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 135;
	  section.data(6).dtTransOffset = 6;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_outp_g
	  section.data(7).logicalSrcIdx = 136;
	  section.data(7).dtTransOffset = 7;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_out_gi
	  section.data(8).logicalSrcIdx = 137;
	  section.data(8).dtTransOffset = 8;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_outp_l
	  section.data(9).logicalSrcIdx = 138;
	  section.data(9).dtTransOffset = 9;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_outp_m
	  section.data(10).logicalSrcIdx = 139;
	  section.data(10).dtTransOffset = 10;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_outp_h
	  section.data(11).logicalSrcIdx = 140;
	  section.data(11).dtTransOffset = 11;
	
	  ;% leader_qball2_P.HILInitialize_set_analog_out_m2
	  section.data(12).logicalSrcIdx = 141;
	  section.data(12).dtTransOffset = 12;
	
	  ;% leader_qball2_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 142;
	  section.data(13).dtTransOffset = 13;
	
	  ;% leader_qball2_P.HILInitialize_set_clock_frequ_i
	  section.data(14).logicalSrcIdx = 143;
	  section.data(14).dtTransOffset = 14;
	
	  ;% leader_qball2_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 144;
	  section.data(15).dtTransOffset = 15;
	
	  ;% leader_qball2_P.HILInitialize_set_clock_param_b
	  section.data(16).logicalSrcIdx = 145;
	  section.data(16).dtTransOffset = 16;
	
	  ;% leader_qball2_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 146;
	  section.data(17).dtTransOffset = 17;
	
	  ;% leader_qball2_P.HILInitialize_set_digital_out_a
	  section.data(18).logicalSrcIdx = 147;
	  section.data(18).dtTransOffset = 18;
	
	  ;% leader_qball2_P.HILInitialize_set_digital_out_c
	  section.data(19).logicalSrcIdx = 148;
	  section.data(19).dtTransOffset = 19;
	
	  ;% leader_qball2_P.HILInitialize_set_digital_out_o
	  section.data(20).logicalSrcIdx = 149;
	  section.data(20).dtTransOffset = 20;
	
	  ;% leader_qball2_P.HILInitialize_set_digital_out_p
	  section.data(21).logicalSrcIdx = 150;
	  section.data(21).dtTransOffset = 21;
	
	  ;% leader_qball2_P.HILInitialize_set_digital_out_j
	  section.data(22).logicalSrcIdx = 151;
	  section.data(22).dtTransOffset = 22;
	
	  ;% leader_qball2_P.HILInitialize_set_digital_out_n
	  section.data(23).logicalSrcIdx = 152;
	  section.data(23).dtTransOffset = 23;
	
	  ;% leader_qball2_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 153;
	  section.data(24).dtTransOffset = 24;
	
	  ;% leader_qball2_P.HILInitialize_set_encoder_cou_l
	  section.data(25).logicalSrcIdx = 154;
	  section.data(25).dtTransOffset = 25;
	
	  ;% leader_qball2_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 155;
	  section.data(26).dtTransOffset = 26;
	
	  ;% leader_qball2_P.HILInitialize_set_encoder_par_p
	  section.data(27).logicalSrcIdx = 156;
	  section.data(27).dtTransOffset = 27;
	
	  ;% leader_qball2_P.HILInitialize_set_other_outp_i5
	  section.data(28).logicalSrcIdx = 157;
	  section.data(28).dtTransOffset = 28;
	
	  ;% leader_qball2_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 158;
	  section.data(29).dtTransOffset = 29;
	
	  ;% leader_qball2_P.HILInitialize_set_pwm_outputs_b
	  section.data(30).logicalSrcIdx = 159;
	  section.data(30).dtTransOffset = 30;
	
	  ;% leader_qball2_P.HILInitialize_set_pwm_outputs_e
	  section.data(31).logicalSrcIdx = 160;
	  section.data(31).dtTransOffset = 31;
	
	  ;% leader_qball2_P.HILInitialize_set_pwm_outputs_n
	  section.data(32).logicalSrcIdx = 161;
	  section.data(32).dtTransOffset = 32;
	
	  ;% leader_qball2_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 162;
	  section.data(33).dtTransOffset = 33;
	
	  ;% leader_qball2_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 163;
	  section.data(34).dtTransOffset = 34;
	
	  ;% leader_qball2_P.HILInitialize_set_pwm_params__e
	  section.data(35).logicalSrcIdx = 164;
	  section.data(35).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 223;
      section.data(223)  = dumData; %prealloc
      
	  ;% leader_qball2_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.Constant_Value
	  section.data(2).logicalSrcIdx = 166;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.Constant_Value_h
	  section.data(3).logicalSrcIdx = 167;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.DiscreteTimeIntegrator_gainval
	  section.data(4).logicalSrcIdx = 168;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_P.DiscreteTimeIntegrator_IC
	  section.data(5).logicalSrcIdx = 169;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_P.TransformGyroDataForBatteryBott
	  section.data(6).logicalSrcIdx = 170;
	  section.data(6).dtTransOffset = 5;
	
	  ;% leader_qball2_P.TransformAccelerometerDataForBa
	  section.data(7).logicalSrcIdx = 171;
	  section.data(7).dtTransOffset = 8;
	
	  ;% leader_qball2_P.zero_Y0
	  section.data(8).logicalSrcIdx = 172;
	  section.data(8).dtTransOffset = 11;
	
	  ;% leader_qball2_P.Vbiased_Y0
	  section.data(9).logicalSrcIdx = 173;
	  section.data(9).dtTransOffset = 12;
	
	  ;% leader_qball2_P.Vunbiased_Y0
	  section.data(10).logicalSrcIdx = 174;
	  section.data(10).dtTransOffset = 13;
	
	  ;% leader_qball2_P.Stepstart_time_Y0
	  section.data(11).logicalSrcIdx = 175;
	  section.data(11).dtTransOffset = 14;
	
	  ;% leader_qball2_P.Stepstart_time_YFinal
	  section.data(12).logicalSrcIdx = 176;
	  section.data(12).dtTransOffset = 15;
	
	  ;% leader_qball2_P.Stepend_time_Y0
	  section.data(13).logicalSrcIdx = 177;
	  section.data(13).dtTransOffset = 16;
	
	  ;% leader_qball2_P.Stepend_time_YFinal
	  section.data(14).logicalSrcIdx = 178;
	  section.data(14).dtTransOffset = 17;
	
	  ;% leader_qball2_P.unity_Value
	  section.data(15).logicalSrcIdx = 179;
	  section.data(15).dtTransOffset = 18;
	
	  ;% leader_qball2_P.UnitDelay_InitialCondition
	  section.data(16).logicalSrcIdx = 180;
	  section.data(16).dtTransOffset = 19;
	
	  ;% leader_qball2_P.Sumk1n1xk_InitialCondition
	  section.data(17).logicalSrcIdx = 181;
	  section.data(17).dtTransOffset = 20;
	
	  ;% leader_qball2_P.Constant_Value_n
	  section.data(18).logicalSrcIdx = 182;
	  section.data(18).dtTransOffset = 21;
	
	  ;% leader_qball2_P.DiscreteTimeIntegrator_gainva_a
	  section.data(19).logicalSrcIdx = 183;
	  section.data(19).dtTransOffset = 22;
	
	  ;% leader_qball2_P.DiscreteTimeIntegrator_IC_m
	  section.data(20).logicalSrcIdx = 184;
	  section.data(20).dtTransOffset = 23;
	
	  ;% leader_qball2_P.Out1_Y0_f
	  section.data(21).logicalSrcIdx = 185;
	  section.data(21).dtTransOffset = 24;
	
	  ;% leader_qball2_P.Constant_Value_c
	  section.data(22).logicalSrcIdx = 186;
	  section.data(22).dtTransOffset = 25;
	
	  ;% leader_qball2_P.Out1_Y0_o
	  section.data(23).logicalSrcIdx = 187;
	  section.data(23).dtTransOffset = 26;
	
	  ;% leader_qball2_P.Constant_Value_m
	  section.data(24).logicalSrcIdx = 188;
	  section.data(24).dtTransOffset = 27;
	
	  ;% leader_qball2_P.JoystickSensitivity_Gain
	  section.data(25).logicalSrcIdx = 189;
	  section.data(25).dtTransOffset = 28;
	
	  ;% leader_qball2_P.Switch_Threshold
	  section.data(26).logicalSrcIdx = 190;
	  section.data(26).dtTransOffset = 29;
	
	  ;% leader_qball2_P.Constant_Value_p
	  section.data(27).logicalSrcIdx = 191;
	  section.data(27).dtTransOffset = 30;
	
	  ;% leader_qball2_P.Out1_Y0_g
	  section.data(28).logicalSrcIdx = 192;
	  section.data(28).dtTransOffset = 31;
	
	  ;% leader_qball2_P.Constant_Value_g
	  section.data(29).logicalSrcIdx = 193;
	  section.data(29).dtTransOffset = 32;
	
	  ;% leader_qball2_P.JoystickSensitivity_Gain_j
	  section.data(30).logicalSrcIdx = 194;
	  section.data(30).dtTransOffset = 33;
	
	  ;% leader_qball2_P.Switch_Threshold_a
	  section.data(31).logicalSrcIdx = 195;
	  section.data(31).dtTransOffset = 34;
	
	  ;% leader_qball2_P.Constant_Value_a
	  section.data(32).logicalSrcIdx = 196;
	  section.data(32).dtTransOffset = 35;
	
	  ;% leader_qball2_P.Out1_Y0_l
	  section.data(33).logicalSrcIdx = 197;
	  section.data(33).dtTransOffset = 36;
	
	  ;% leader_qball2_P.Constant_Value_j
	  section.data(34).logicalSrcIdx = 198;
	  section.data(34).dtTransOffset = 37;
	
	  ;% leader_qball2_P.Joystickthrottlescaling_Gain
	  section.data(35).logicalSrcIdx = 199;
	  section.data(35).dtTransOffset = 38;
	
	  ;% leader_qball2_P.Switch_Threshold_ak
	  section.data(36).logicalSrcIdx = 200;
	  section.data(36).dtTransOffset = 39;
	
	  ;% leader_qball2_P.Out1_Y0_gt
	  section.data(37).logicalSrcIdx = 201;
	  section.data(37).dtTransOffset = 40;
	
	  ;% leader_qball2_P.Constant_Value_l
	  section.data(38).logicalSrcIdx = 202;
	  section.data(38).dtTransOffset = 41;
	
	  ;% leader_qball2_P.Out1_Y0_lz
	  section.data(39).logicalSrcIdx = 203;
	  section.data(39).dtTransOffset = 42;
	
	  ;% leader_qball2_P.Gain1_Gain
	  section.data(40).logicalSrcIdx = 204;
	  section.data(40).dtTransOffset = 43;
	
	  ;% leader_qball2_P.Motorenable_Value
	  section.data(41).logicalSrcIdx = 205;
	  section.data(41).dtTransOffset = 44;
	
	  ;% leader_qball2_P.Memory_X0
	  section.data(42).logicalSrcIdx = 206;
	  section.data(42).dtTransOffset = 46;
	
	  ;% leader_qball2_P.Saturation_UpperSat
	  section.data(43).logicalSrcIdx = 207;
	  section.data(43).dtTransOffset = 50;
	
	  ;% leader_qball2_P.Saturation_LowerSat
	  section.data(44).logicalSrcIdx = 208;
	  section.data(44).dtTransOffset = 51;
	
	  ;% leader_qball2_P.Memory_X0_b
	  section.data(45).logicalSrcIdx = 209;
	  section.data(45).dtTransOffset = 52;
	
	  ;% leader_qball2_P.Constant_Value_b
	  section.data(46).logicalSrcIdx = 210;
	  section.data(46).dtTransOffset = 53;
	
	  ;% leader_qball2_P.Integrator2_IC
	  section.data(47).logicalSrcIdx = 211;
	  section.data(47).dtTransOffset = 54;
	
	  ;% leader_qball2_P.Constant3_Value
	  section.data(48).logicalSrcIdx = 212;
	  section.data(48).dtTransOffset = 55;
	
	  ;% leader_qball2_P.Saturation_UpperSat_g
	  section.data(49).logicalSrcIdx = 213;
	  section.data(49).dtTransOffset = 56;
	
	  ;% leader_qball2_P.Saturation_LowerSat_j
	  section.data(50).logicalSrcIdx = 214;
	  section.data(50).dtTransOffset = 57;
	
	  ;% leader_qball2_P.Memory_X0_g
	  section.data(51).logicalSrcIdx = 215;
	  section.data(51).dtTransOffset = 58;
	
	  ;% leader_qball2_P.Constant_Value_g1
	  section.data(52).logicalSrcIdx = 216;
	  section.data(52).dtTransOffset = 59;
	
	  ;% leader_qball2_P.RateTransition_X0
	  section.data(53).logicalSrcIdx = 217;
	  section.data(53).dtTransOffset = 60;
	
	  ;% leader_qball2_P.RateTransition1_X0
	  section.data(54).logicalSrcIdx = 218;
	  section.data(54).dtTransOffset = 61;
	
	  ;% leader_qball2_P.RateTransition_X0_o
	  section.data(55).logicalSrcIdx = 219;
	  section.data(55).dtTransOffset = 62;
	
	  ;% leader_qball2_P.BatteryOnTop_Value
	  section.data(56).logicalSrcIdx = 220;
	  section.data(56).dtTransOffset = 63;
	
	  ;% leader_qball2_P.BatteryOnBottom_Value
	  section.data(57).logicalSrcIdx = 221;
	  section.data(57).dtTransOffset = 64;
	
	  ;% leader_qball2_P.SwitchBatteryConfigAcceleromter
	  section.data(58).logicalSrcIdx = 222;
	  section.data(58).dtTransOffset = 65;
	
	  ;% leader_qball2_P.x0_Value
	  section.data(59).logicalSrcIdx = 223;
	  section.data(59).dtTransOffset = 66;
	
	  ;% leader_qball2_P.SwitchBatteryConfigGyroToporBot
	  section.data(60).logicalSrcIdx = 224;
	  section.data(60).dtTransOffset = 67;
	
	  ;% leader_qball2_P.Calibrationtimes_Value
	  section.data(61).logicalSrcIdx = 225;
	  section.data(61).dtTransOffset = 68;
	
	  ;% leader_qball2_P.HighPassFilterRoll_A
	  section.data(62).logicalSrcIdx = 226;
	  section.data(62).dtTransOffset = 69;
	
	  ;% leader_qball2_P.HighPassFilterRoll_C
	  section.data(63).logicalSrcIdx = 227;
	  section.data(63).dtTransOffset = 70;
	
	  ;% leader_qball2_P.HighPassFilterRoll_D
	  section.data(64).logicalSrcIdx = 228;
	  section.data(64).dtTransOffset = 71;
	
	  ;% leader_qball2_P.Constant_Value_jv
	  section.data(65).logicalSrcIdx = 229;
	  section.data(65).dtTransOffset = 72;
	
	  ;% leader_qball2_P.HighPassFilterPitch_A
	  section.data(66).logicalSrcIdx = 230;
	  section.data(66).dtTransOffset = 73;
	
	  ;% leader_qball2_P.HighPassFilterPitch_C
	  section.data(67).logicalSrcIdx = 231;
	  section.data(67).dtTransOffset = 74;
	
	  ;% leader_qball2_P.HighPassFilterPitch_D
	  section.data(68).logicalSrcIdx = 232;
	  section.data(68).dtTransOffset = 75;
	
	  ;% leader_qball2_P.Constant1_Value
	  section.data(69).logicalSrcIdx = 233;
	  section.data(69).dtTransOffset = 76;
	
	  ;% leader_qball2_P.Integrator2_IC_m
	  section.data(70).logicalSrcIdx = 234;
	  section.data(70).dtTransOffset = 77;
	
	  ;% leader_qball2_P.Integrator2_IC_a
	  section.data(71).logicalSrcIdx = 235;
	  section.data(71).dtTransOffset = 78;
	
	  ;% leader_qball2_P.Gain5_Gain
	  section.data(72).logicalSrcIdx = 236;
	  section.data(72).dtTransOffset = 79;
	
	  ;% leader_qball2_P.Gain4_Gain
	  section.data(73).logicalSrcIdx = 237;
	  section.data(73).dtTransOffset = 80;
	
	  ;% leader_qball2_P.x0_Value_a
	  section.data(74).logicalSrcIdx = 238;
	  section.data(74).dtTransOffset = 81;
	
	  ;% leader_qball2_P.HighPassFilterYaw_A
	  section.data(75).logicalSrcIdx = 239;
	  section.data(75).dtTransOffset = 82;
	
	  ;% leader_qball2_P.HighPassFilterYaw_C
	  section.data(76).logicalSrcIdx = 240;
	  section.data(76).dtTransOffset = 83;
	
	  ;% leader_qball2_P.HighPassFilterYaw_D
	  section.data(77).logicalSrcIdx = 241;
	  section.data(77).dtTransOffset = 84;
	
	  ;% leader_qball2_P.Constant2_Value
	  section.data(78).logicalSrcIdx = 242;
	  section.data(78).dtTransOffset = 85;
	
	  ;% leader_qball2_P.Gain8_Gain
	  section.data(79).logicalSrcIdx = 243;
	  section.data(79).dtTransOffset = 86;
	
	  ;% leader_qball2_P.Gain1_Gain_i
	  section.data(80).logicalSrcIdx = 244;
	  section.data(80).dtTransOffset = 87;
	
	  ;% leader_qball2_P.Gain7_Gain
	  section.data(81).logicalSrcIdx = 245;
	  section.data(81).dtTransOffset = 88;
	
	  ;% leader_qball2_P.Gain2_Gain
	  section.data(82).logicalSrcIdx = 246;
	  section.data(82).dtTransOffset = 89;
	
	  ;% leader_qball2_P.Gain6_Gain
	  section.data(83).logicalSrcIdx = 247;
	  section.data(83).dtTransOffset = 90;
	
	  ;% leader_qball2_P.Constant_Value_mn
	  section.data(84).logicalSrcIdx = 248;
	  section.data(84).dtTransOffset = 91;
	
	  ;% leader_qball2_P.Integrator2_IC_e
	  section.data(85).logicalSrcIdx = 249;
	  section.data(85).dtTransOffset = 92;
	
	  ;% leader_qball2_P.InverseModulus_Modulus
	  section.data(86).logicalSrcIdx = 250;
	  section.data(86).dtTransOffset = 93;
	
	  ;% leader_qball2_P.Constant_Value_hq
	  section.data(87).logicalSrcIdx = 251;
	  section.data(87).dtTransOffset = 94;
	
	  ;% leader_qball2_P.x0_Value_h
	  section.data(88).logicalSrcIdx = 252;
	  section.data(88).dtTransOffset = 95;
	
	  ;% leader_qball2_P.Constant_Value_h3
	  section.data(89).logicalSrcIdx = 253;
	  section.data(89).dtTransOffset = 96;
	
	  ;% leader_qball2_P.x0_Value_c
	  section.data(90).logicalSrcIdx = 254;
	  section.data(90).dtTransOffset = 97;
	
	  ;% leader_qball2_P.Constant_Value_p0
	  section.data(91).logicalSrcIdx = 255;
	  section.data(91).dtTransOffset = 98;
	
	  ;% leader_qball2_P.x0_Value_k
	  section.data(92).logicalSrcIdx = 256;
	  section.data(92).dtTransOffset = 99;
	
	  ;% leader_qball2_P.UnitDelay_InitialCondition_b
	  section.data(93).logicalSrcIdx = 257;
	  section.data(93).dtTransOffset = 100;
	
	  ;% leader_qball2_P.Gain1_Gain_b
	  section.data(94).logicalSrcIdx = 258;
	  section.data(94).dtTransOffset = 101;
	
	  ;% leader_qball2_P.Gain_Gain
	  section.data(95).logicalSrcIdx = 259;
	  section.data(95).dtTransOffset = 102;
	
	  ;% leader_qball2_P.Constant_Value_o
	  section.data(96).logicalSrcIdx = 260;
	  section.data(96).dtTransOffset = 103;
	
	  ;% leader_qball2_P.Integrator2_IC_k
	  section.data(97).logicalSrcIdx = 261;
	  section.data(97).dtTransOffset = 104;
	
	  ;% leader_qball2_P.initialaccel_Value
	  section.data(98).logicalSrcIdx = 262;
	  section.data(98).dtTransOffset = 105;
	
	  ;% leader_qball2_P.Calibrationtimes_Value_e
	  section.data(99).logicalSrcIdx = 263;
	  section.data(99).dtTransOffset = 108;
	
	  ;% leader_qball2_P.Saturation2_UpperSat
	  section.data(100).logicalSrcIdx = 264;
	  section.data(100).dtTransOffset = 109;
	
	  ;% leader_qball2_P.Saturation2_LowerSat
	  section.data(101).logicalSrcIdx = 265;
	  section.data(101).dtTransOffset = 110;
	
	  ;% leader_qball2_P.TransferFcn_A
	  section.data(102).logicalSrcIdx = 266;
	  section.data(102).dtTransOffset = 111;
	
	  ;% leader_qball2_P.TransferFcn_C
	  section.data(103).logicalSrcIdx = 267;
	  section.data(103).dtTransOffset = 112;
	
	  ;% leader_qball2_P.HILWatchdog_Timeout
	  section.data(104).logicalSrcIdx = 268;
	  section.data(104).dtTransOffset = 113;
	
	  ;% leader_qball2_P.LPF_A
	  section.data(105).logicalSrcIdx = 269;
	  section.data(105).dtTransOffset = 114;
	
	  ;% leader_qball2_P.LPF_C
	  section.data(106).logicalSrcIdx = 270;
	  section.data(106).dtTransOffset = 115;
	
	  ;% leader_qball2_P.Integrator_IC
	  section.data(107).logicalSrcIdx = 271;
	  section.data(107).dtTransOffset = 116;
	
	  ;% leader_qball2_P.HPF_A
	  section.data(108).logicalSrcIdx = 272;
	  section.data(108).dtTransOffset = 117;
	
	  ;% leader_qball2_P.HPF_C
	  section.data(109).logicalSrcIdx = 273;
	  section.data(109).dtTransOffset = 118;
	
	  ;% leader_qball2_P.HPF_D
	  section.data(110).logicalSrcIdx = 274;
	  section.data(110).dtTransOffset = 119;
	
	  ;% leader_qball2_P.Gain1_Gain_e
	  section.data(111).logicalSrcIdx = 275;
	  section.data(111).dtTransOffset = 120;
	
	  ;% leader_qball2_P.LPF1_A
	  section.data(112).logicalSrcIdx = 276;
	  section.data(112).dtTransOffset = 121;
	
	  ;% leader_qball2_P.LPF1_C
	  section.data(113).logicalSrcIdx = 277;
	  section.data(113).dtTransOffset = 122;
	
	  ;% leader_qball2_P.Integrator_IC_l
	  section.data(114).logicalSrcIdx = 278;
	  section.data(114).dtTransOffset = 123;
	
	  ;% leader_qball2_P.HPF1_A
	  section.data(115).logicalSrcIdx = 279;
	  section.data(115).dtTransOffset = 124;
	
	  ;% leader_qball2_P.HPF1_C
	  section.data(116).logicalSrcIdx = 280;
	  section.data(116).dtTransOffset = 125;
	
	  ;% leader_qball2_P.HPF1_D
	  section.data(117).logicalSrcIdx = 281;
	  section.data(117).dtTransOffset = 126;
	
	  ;% leader_qball2_P.LowPassFilterFilteredYawRate_A
	  section.data(118).logicalSrcIdx = 282;
	  section.data(118).dtTransOffset = 127;
	
	  ;% leader_qball2_P.LowPassFilterFilteredYawRate_C
	  section.data(119).logicalSrcIdx = 283;
	  section.data(119).dtTransOffset = 128;
	
	  ;% leader_qball2_P.SwitchKd_Threshold
	  section.data(120).logicalSrcIdx = 284;
	  section.data(120).dtTransOffset = 129;
	
	  ;% leader_qball2_P.headingcommand_Value
	  section.data(121).logicalSrcIdx = 285;
	  section.data(121).dtTransOffset = 130;
	
	  ;% leader_qball2_P.RateLimiter_RisingLim
	  section.data(122).logicalSrcIdx = 286;
	  section.data(122).dtTransOffset = 131;
	
	  ;% leader_qball2_P.RateLimiter_FallingLim
	  section.data(123).logicalSrcIdx = 287;
	  section.data(123).dtTransOffset = 132;
	
	  ;% leader_qball2_P.RateLimiter_IC
	  section.data(124).logicalSrcIdx = 288;
	  section.data(124).dtTransOffset = 133;
	
	  ;% leader_qball2_P.Bias_Bias
	  section.data(125).logicalSrcIdx = 289;
	  section.data(125).dtTransOffset = 134;
	
	  ;% leader_qball2_P.SwitchKp_Threshold
	  section.data(126).logicalSrcIdx = 290;
	  section.data(126).dtTransOffset = 135;
	
	  ;% leader_qball2_P.Saturation3_UpperSat
	  section.data(127).logicalSrcIdx = 291;
	  section.data(127).dtTransOffset = 136;
	
	  ;% leader_qball2_P.Saturation3_LowerSat
	  section.data(128).logicalSrcIdx = 292;
	  section.data(128).dtTransOffset = 137;
	
	  ;% leader_qball2_P.Integrator2_IC_kr
	  section.data(129).logicalSrcIdx = 293;
	  section.data(129).dtTransOffset = 138;
	
	  ;% leader_qball2_P.SwitchKd_Threshold_p
	  section.data(130).logicalSrcIdx = 294;
	  section.data(130).dtTransOffset = 139;
	
	  ;% leader_qball2_P.vmaxtakeoff_Value
	  section.data(131).logicalSrcIdx = 295;
	  section.data(131).dtTransOffset = 140;
	
	  ;% leader_qball2_P.amaxtakeoff_Value
	  section.data(132).logicalSrcIdx = 296;
	  section.data(132).dtTransOffset = 141;
	
	  ;% leader_qball2_P.Constant_Value_aa
	  section.data(133).logicalSrcIdx = 297;
	  section.data(133).dtTransOffset = 142;
	
	  ;% leader_qball2_P.Constant2_Value_a
	  section.data(134).logicalSrcIdx = 298;
	  section.data(134).dtTransOffset = 143;
	
	  ;% leader_qball2_P.CLOSEDLOOPON_Value
	  section.data(135).logicalSrcIdx = 299;
	  section.data(135).dtTransOffset = 144;
	
	  ;% leader_qball2_P.JOYSTICKON_Value
	  section.data(136).logicalSrcIdx = 300;
	  section.data(136).dtTransOffset = 145;
	
	  ;% leader_qball2_P.Constant1_Value_n
	  section.data(137).logicalSrcIdx = 301;
	  section.data(137).dtTransOffset = 146;
	
	  ;% leader_qball2_P.Constant_Value_e
	  section.data(138).logicalSrcIdx = 302;
	  section.data(138).dtTransOffset = 147;
	
	  ;% leader_qball2_P.SignalGenerator_Amplitude
	  section.data(139).logicalSrcIdx = 303;
	  section.data(139).dtTransOffset = 148;
	
	  ;% leader_qball2_P.SignalGenerator_Frequency
	  section.data(140).logicalSrcIdx = 304;
	  section.data(140).dtTransOffset = 149;
	
	  ;% leader_qball2_P.Constant1_Value_m
	  section.data(141).logicalSrcIdx = 305;
	  section.data(141).dtTransOffset = 150;
	
	  ;% leader_qball2_P.Constant_Value_c2
	  section.data(142).logicalSrcIdx = 306;
	  section.data(142).dtTransOffset = 151;
	
	  ;% leader_qball2_P.Switch_Threshold_g
	  section.data(143).logicalSrcIdx = 307;
	  section.data(143).dtTransOffset = 152;
	
	  ;% leader_qball2_P.vmaxflight_Value
	  section.data(144).logicalSrcIdx = 308;
	  section.data(144).dtTransOffset = 153;
	
	  ;% leader_qball2_P.amaxflight_Value
	  section.data(145).logicalSrcIdx = 309;
	  section.data(145).dtTransOffset = 154;
	
	  ;% leader_qball2_P.SwitchKp_Threshold_c
	  section.data(146).logicalSrcIdx = 310;
	  section.data(146).dtTransOffset = 155;
	
	  ;% leader_qball2_P.Memory_X0_j
	  section.data(147).logicalSrcIdx = 311;
	  section.data(147).dtTransOffset = 156;
	
	  ;% leader_qball2_P.Integrator_IC_f
	  section.data(148).logicalSrcIdx = 312;
	  section.data(148).dtTransOffset = 157;
	
	  ;% leader_qball2_P.Integrator_UpperSat
	  section.data(149).logicalSrcIdx = 313;
	  section.data(149).dtTransOffset = 158;
	
	  ;% leader_qball2_P.Integrator_LowerSat
	  section.data(150).logicalSrcIdx = 314;
	  section.data(150).dtTransOffset = 159;
	
	  ;% leader_qball2_P.Constant1_Value_f
	  section.data(151).logicalSrcIdx = 315;
	  section.data(151).dtTransOffset = 160;
	
	  ;% leader_qball2_P.Constant_Value_bn
	  section.data(152).logicalSrcIdx = 316;
	  section.data(152).dtTransOffset = 161;
	
	  ;% leader_qball2_P.Switch_Threshold_h
	  section.data(153).logicalSrcIdx = 317;
	  section.data(153).dtTransOffset = 162;
	
	  ;% leader_qball2_P.Constant1_Value_j
	  section.data(154).logicalSrcIdx = 318;
	  section.data(154).dtTransOffset = 163;
	
	  ;% leader_qball2_P.landthrottletarget_Value
	  section.data(155).logicalSrcIdx = 319;
	  section.data(155).dtTransOffset = 164;
	
	  ;% leader_qball2_P.Constant2_Value_f
	  section.data(156).logicalSrcIdx = 320;
	  section.data(156).dtTransOffset = 165;
	
	  ;% leader_qball2_P.Constant1_Value_c
	  section.data(157).logicalSrcIdx = 321;
	  section.data(157).dtTransOffset = 166;
	
	  ;% leader_qball2_P.Constant_Value_o5
	  section.data(158).logicalSrcIdx = 322;
	  section.data(158).dtTransOffset = 167;
	
	  ;% leader_qball2_P.Integrator_IC_p
	  section.data(159).logicalSrcIdx = 323;
	  section.data(159).dtTransOffset = 168;
	
	  ;% leader_qball2_P.LowPassFilterFilteredYawRateFor
	  section.data(160).logicalSrcIdx = 324;
	  section.data(160).dtTransOffset = 169;
	
	  ;% leader_qball2_P.LowPassFilterFilteredYawRateF_c
	  section.data(161).logicalSrcIdx = 325;
	  section.data(161).dtTransOffset = 170;
	
	  ;% leader_qball2_P.DefaultJoystickCMDYaw_Value
	  section.data(162).logicalSrcIdx = 326;
	  section.data(162).dtTransOffset = 171;
	
	  ;% leader_qball2_P.Switch_Threshold_p
	  section.data(163).logicalSrcIdx = 327;
	  section.data(163).dtTransOffset = 172;
	
	  ;% leader_qball2_P.Gain2_Gain_k
	  section.data(164).logicalSrcIdx = 328;
	  section.data(164).dtTransOffset = 173;
	
	  ;% leader_qball2_P.LowPassFilterFilteredPitchRate_
	  section.data(165).logicalSrcIdx = 329;
	  section.data(165).dtTransOffset = 174;
	
	  ;% leader_qball2_P.LowPassFilterFilteredPitchRat_e
	  section.data(166).logicalSrcIdx = 330;
	  section.data(166).dtTransOffset = 175;
	
	  ;% leader_qball2_P.SwitchKd_Threshold_k
	  section.data(167).logicalSrcIdx = 331;
	  section.data(167).dtTransOffset = 176;
	
	  ;% leader_qball2_P.Memory_X0_a
	  section.data(168).logicalSrcIdx = 332;
	  section.data(168).dtTransOffset = 177;
	
	  ;% leader_qball2_P.DefaultJoystickCMDPitch_Value
	  section.data(169).logicalSrcIdx = 333;
	  section.data(169).dtTransOffset = 178;
	
	  ;% leader_qball2_P.Switch_Threshold_o
	  section.data(170).logicalSrcIdx = 334;
	  section.data(170).dtTransOffset = 179;
	
	  ;% leader_qball2_P.Gain_Gain_j
	  section.data(171).logicalSrcIdx = 335;
	  section.data(171).dtTransOffset = 180;
	
	  ;% leader_qball2_P.SwitchKp_Threshold_f
	  section.data(172).logicalSrcIdx = 336;
	  section.data(172).dtTransOffset = 181;
	
	  ;% leader_qball2_P.Integrator1_IC
	  section.data(173).logicalSrcIdx = 337;
	  section.data(173).dtTransOffset = 182;
	
	  ;% leader_qball2_P.LowPassFilterFilteredRollRate_A
	  section.data(174).logicalSrcIdx = 338;
	  section.data(174).dtTransOffset = 183;
	
	  ;% leader_qball2_P.LowPassFilterFilteredRollRate_C
	  section.data(175).logicalSrcIdx = 339;
	  section.data(175).dtTransOffset = 184;
	
	  ;% leader_qball2_P.SwitchKd_Threshold_pr
	  section.data(176).logicalSrcIdx = 340;
	  section.data(176).dtTransOffset = 185;
	
	  ;% leader_qball2_P.Memory_X0_p
	  section.data(177).logicalSrcIdx = 341;
	  section.data(177).dtTransOffset = 186;
	
	  ;% leader_qball2_P.DefaultJoystickCMDRoll_Value
	  section.data(178).logicalSrcIdx = 342;
	  section.data(178).dtTransOffset = 187;
	
	  ;% leader_qball2_P.Switch_Threshold_j
	  section.data(179).logicalSrcIdx = 343;
	  section.data(179).dtTransOffset = 188;
	
	  ;% leader_qball2_P.Gain_Gain_f
	  section.data(180).logicalSrcIdx = 344;
	  section.data(180).dtTransOffset = 189;
	
	  ;% leader_qball2_P.SwitchKp_Threshold_g
	  section.data(181).logicalSrcIdx = 345;
	  section.data(181).dtTransOffset = 190;
	
	  ;% leader_qball2_P.Integrator1_IC_g
	  section.data(182).logicalSrcIdx = 346;
	  section.data(182).dtTransOffset = 191;
	
	  ;% leader_qball2_P.StepInitializezerothrottlefor3s
	  section.data(183).logicalSrcIdx = 347;
	  section.data(183).dtTransOffset = 192;
	
	  ;% leader_qball2_P.StepInitializezerothrottlefor_c
	  section.data(184).logicalSrcIdx = 348;
	  section.data(184).dtTransOffset = 193;
	
	  ;% leader_qball2_P.StepInitializezerothrottlefor_a
	  section.data(185).logicalSrcIdx = 349;
	  section.data(185).dtTransOffset = 194;
	
	  ;% leader_qball2_P.Constant2_Value_n
	  section.data(186).logicalSrcIdx = 350;
	  section.data(186).dtTransOffset = 195;
	
	  ;% leader_qball2_P.Gain_Gain_n
	  section.data(187).logicalSrcIdx = 351;
	  section.data(187).dtTransOffset = 196;
	
	  ;% leader_qball2_P.Constant_Value_k
	  section.data(188).logicalSrcIdx = 352;
	  section.data(188).dtTransOffset = 197;
	
	  ;% leader_qball2_P.Memory_X0_h
	  section.data(189).logicalSrcIdx = 353;
	  section.data(189).dtTransOffset = 198;
	
	  ;% leader_qball2_P.Constant_Value_d
	  section.data(190).logicalSrcIdx = 354;
	  section.data(190).dtTransOffset = 199;
	
	  ;% leader_qball2_P.Memory_X0_m
	  section.data(191).logicalSrcIdx = 355;
	  section.data(191).dtTransOffset = 200;
	
	  ;% leader_qball2_P.Integrator2_IC_b
	  section.data(192).logicalSrcIdx = 356;
	  section.data(192).dtTransOffset = 201;
	
	  ;% leader_qball2_P.SwitchKd_Threshold_c
	  section.data(193).logicalSrcIdx = 357;
	  section.data(193).dtTransOffset = 202;
	
	  ;% leader_qball2_P.RateLimiter2_RisingLim
	  section.data(194).logicalSrcIdx = 358;
	  section.data(194).dtTransOffset = 203;
	
	  ;% leader_qball2_P.RateLimiter2_FallingLim
	  section.data(195).logicalSrcIdx = 359;
	  section.data(195).dtTransOffset = 204;
	
	  ;% leader_qball2_P.RateLimiter2_IC
	  section.data(196).logicalSrcIdx = 360;
	  section.data(196).dtTransOffset = 205;
	
	  ;% leader_qball2_P.SwitchKp_Threshold_k
	  section.data(197).logicalSrcIdx = 361;
	  section.data(197).dtTransOffset = 206;
	
	  ;% leader_qball2_P.Integrator_IC_e
	  section.data(198).logicalSrcIdx = 362;
	  section.data(198).dtTransOffset = 207;
	
	  ;% leader_qball2_P.Gain4_Gain_k
	  section.data(199).logicalSrcIdx = 363;
	  section.data(199).dtTransOffset = 208;
	
	  ;% leader_qball2_P.Integrator2_IC_h
	  section.data(200).logicalSrcIdx = 364;
	  section.data(200).dtTransOffset = 209;
	
	  ;% leader_qball2_P.SwitchKd_Threshold_g
	  section.data(201).logicalSrcIdx = 365;
	  section.data(201).dtTransOffset = 210;
	
	  ;% leader_qball2_P.RateLimiter1_RisingLim
	  section.data(202).logicalSrcIdx = 366;
	  section.data(202).dtTransOffset = 211;
	
	  ;% leader_qball2_P.RateLimiter1_FallingLim
	  section.data(203).logicalSrcIdx = 367;
	  section.data(203).dtTransOffset = 212;
	
	  ;% leader_qball2_P.RateLimiter1_IC
	  section.data(204).logicalSrcIdx = 368;
	  section.data(204).dtTransOffset = 213;
	
	  ;% leader_qball2_P.SwitchKp_Threshold_fn
	  section.data(205).logicalSrcIdx = 369;
	  section.data(205).dtTransOffset = 214;
	
	  ;% leader_qball2_P.Integrator1_IC_b
	  section.data(206).logicalSrcIdx = 370;
	  section.data(206).dtTransOffset = 215;
	
	  ;% leader_qball2_P.Constant_Value_ni
	  section.data(207).logicalSrcIdx = 371;
	  section.data(207).dtTransOffset = 216;
	
	  ;% leader_qball2_P.x0_Value_b
	  section.data(208).logicalSrcIdx = 372;
	  section.data(208).dtTransOffset = 217;
	
	  ;% leader_qball2_P.SwitchKi_Threshold
	  section.data(209).logicalSrcIdx = 373;
	  section.data(209).dtTransOffset = 218;
	
	  ;% leader_qball2_P.SwitchKi_Threshold_m
	  section.data(210).logicalSrcIdx = 374;
	  section.data(210).dtTransOffset = 219;
	
	  ;% leader_qball2_P.Gain1_Gain_l
	  section.data(211).logicalSrcIdx = 375;
	  section.data(211).dtTransOffset = 220;
	
	  ;% leader_qball2_P.Gain4_Gain_f
	  section.data(212).logicalSrcIdx = 376;
	  section.data(212).dtTransOffset = 221;
	
	  ;% leader_qball2_P.SwitchKi_Threshold_c
	  section.data(213).logicalSrcIdx = 377;
	  section.data(213).dtTransOffset = 222;
	
	  ;% leader_qball2_P.Constant_Value_hg
	  section.data(214).logicalSrcIdx = 378;
	  section.data(214).dtTransOffset = 223;
	
	  ;% leader_qball2_P.x0_Value_p
	  section.data(215).logicalSrcIdx = 379;
	  section.data(215).dtTransOffset = 224;
	
	  ;% leader_qball2_P.SwitchKi_Threshold_g
	  section.data(216).logicalSrcIdx = 380;
	  section.data(216).dtTransOffset = 225;
	
	  ;% leader_qball2_P.Gain1_Gain_ln
	  section.data(217).logicalSrcIdx = 381;
	  section.data(217).dtTransOffset = 226;
	
	  ;% leader_qball2_P.DummyHeadingReferencerad_Value
	  section.data(218).logicalSrcIdx = 382;
	  section.data(218).dtTransOffset = 227;
	
	  ;% leader_qball2_P.Enable_Value
	  section.data(219).logicalSrcIdx = 383;
	  section.data(219).dtTransOffset = 228;
	
	  ;% leader_qball2_P.Constant_Value_h3z
	  section.data(220).logicalSrcIdx = 384;
	  section.data(220).dtTransOffset = 229;
	
	  ;% leader_qball2_P.x0_Value_ch
	  section.data(221).logicalSrcIdx = 385;
	  section.data(221).dtTransOffset = 230;
	
	  ;% leader_qball2_P.SwitchKi_Threshold_mj
	  section.data(222).logicalSrcIdx = 386;
	  section.data(222).dtTransOffset = 231;
	
	  ;% leader_qball2_P.SwitchKi_Threshold_b
	  section.data(223).logicalSrcIdx = 387;
	  section.data(223).dtTransOffset = 232;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% leader_qball2_P.StreamClient_SndPriority
	  section.data(1).logicalSrcIdx = 388;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.StreamClient_RcvPriority
	  section.data(2).logicalSrcIdx = 389;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.StreamServer_SndPriority
	  section.data(3).logicalSrcIdx = 390;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.StreamServer_RcvPriority
	  section.data(4).logicalSrcIdx = 391;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% leader_qball2_P.StreamClient_SndSize
	  section.data(1).logicalSrcIdx = 392;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.StreamClient_RcvSize
	  section.data(2).logicalSrcIdx = 393;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.StreamClient_SndFIFO
	  section.data(3).logicalSrcIdx = 394;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.StreamClient_RcvFIFO
	  section.data(4).logicalSrcIdx = 395;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_P.ToHostFile_Decimation
	  section.data(5).logicalSrcIdx = 396;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_P.StreamServer_SndSize
	  section.data(6).logicalSrcIdx = 397;
	  section.data(6).dtTransOffset = 5;
	
	  ;% leader_qball2_P.StreamServer_RcvSize
	  section.data(7).logicalSrcIdx = 398;
	  section.data(7).dtTransOffset = 6;
	
	  ;% leader_qball2_P.StreamServer_SndFIFO
	  section.data(8).logicalSrcIdx = 399;
	  section.data(8).dtTransOffset = 7;
	
	  ;% leader_qball2_P.StreamServer_RcvFIFO
	  section.data(9).logicalSrcIdx = 400;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% leader_qball2_P.StreamClient_Optimize
	  section.data(1).logicalSrcIdx = 401;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.StreamClient_Implementation
	  section.data(2).logicalSrcIdx = 402;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.StreamServer_Optimize
	  section.data(3).logicalSrcIdx = 403;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.StreamServer_Implementation
	  section.data(4).logicalSrcIdx = 404;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% leader_qball2_P.StringConstant1_Value
	  section.data(1).logicalSrcIdx = 405;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.StreamClient_URI
	  section.data(2).logicalSrcIdx = 406;
	  section.data(2).dtTransOffset = 80;
	
	  ;% leader_qball2_P.StreamClient_Endian
	  section.data(3).logicalSrcIdx = 407;
	  section.data(3).dtTransOffset = 81;
	
	  ;% leader_qball2_P.BatteryTopOrBottom_CurrentSetti
	  section.data(4).logicalSrcIdx = 408;
	  section.data(4).dtTransOffset = 82;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting
	  section.data(5).logicalSrcIdx = 409;
	  section.data(5).dtTransOffset = 83;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting_m
	  section.data(6).logicalSrcIdx = 410;
	  section.data(6).dtTransOffset = 84;
	
	  ;% leader_qball2_P.ManualSwitch2_CurrentSetting
	  section.data(7).logicalSrcIdx = 411;
	  section.data(7).dtTransOffset = 85;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting_f
	  section.data(8).logicalSrcIdx = 412;
	  section.data(8).dtTransOffset = 86;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting_l
	  section.data(9).logicalSrcIdx = 413;
	  section.data(9).dtTransOffset = 87;
	
	  ;% leader_qball2_P.ManualSwitch4_CurrentSetting
	  section.data(10).logicalSrcIdx = 414;
	  section.data(10).dtTransOffset = 88;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting_lk
	  section.data(11).logicalSrcIdx = 415;
	  section.data(11).dtTransOffset = 89;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting_j
	  section.data(12).logicalSrcIdx = 416;
	  section.data(12).dtTransOffset = 90;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting_k
	  section.data(13).logicalSrcIdx = 417;
	  section.data(13).dtTransOffset = 91;
	
	  ;% leader_qball2_P.ManualSwitch_CurrentSetting_h
	  section.data(14).logicalSrcIdx = 418;
	  section.data(14).dtTransOffset = 92;
	
	  ;% leader_qball2_P.ToHostFile_file_name
	  section.data(15).logicalSrcIdx = 419;
	  section.data(15).dtTransOffset = 93;
	
	  ;% leader_qball2_P.ToHostFile_VarName
	  section.data(16).logicalSrcIdx = 420;
	  section.data(16).dtTransOffset = 136;
	
	  ;% leader_qball2_P.ToHostFile_FileFormat
	  section.data(17).logicalSrcIdx = 421;
	  section.data(17).dtTransOffset = 147;
	
	  ;% leader_qball2_P.StreamServer_URI
	  section.data(18).logicalSrcIdx = 422;
	  section.data(18).dtTransOffset = 148;
	
	  ;% leader_qball2_P.StreamServer_Endian
	  section.data(19).logicalSrcIdx = 423;
	  section.data(19).dtTransOffset = 172;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% leader_qball2_P.timeout_Y0
	  section.data(1).logicalSrcIdx = 424;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.timeout_Y0_k
	  section.data(2).logicalSrcIdx = 425;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.HILReadWrite1_Active
	  section.data(3).logicalSrcIdx = 426;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_P.StreamClient_Active
	  section.data(4).logicalSrcIdx = 427;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_P.HILWatchdog_Active
	  section.data(5).logicalSrcIdx = 428;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_P.StreamServer_Active
	  section.data(6).logicalSrcIdx = 429;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% leader_qball2_P.EnabledSubsystem1_b.Constant_Value
	  section.data(1).logicalSrcIdx = 430;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.EnabledSubsystem1_b.DiscreteTimeIntegrator_gainval
	  section.data(2).logicalSrcIdx = 431;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.EnabledSubsystem1_b.DiscreteTimeIntegrator_IC
	  section.data(3).logicalSrcIdx = 432;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_P.EnabledSubsystem1_b.timeout_Y0
	  section.data(1).logicalSrcIdx = 433;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% leader_qball2_P.EnabledSubsystem1.Constant_Value
	  section.data(1).logicalSrcIdx = 434;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.EnabledSubsystem1.DiscreteTimeIntegrator_gainval
	  section.data(2).logicalSrcIdx = 435;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.EnabledSubsystem1.DiscreteTimeIntegrator_IC
	  section.data(3).logicalSrcIdx = 436;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_P.EnabledSubsystem1.timeout_Y0
	  section.data(1).logicalSrcIdx = 437;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% leader_qball2_P.EnabledMovingAverage_e.unity_Value
	  section.data(1).logicalSrcIdx = 438;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.EnabledMovingAverage_e.UnitDelay_InitialCondition
	  section.data(2).logicalSrcIdx = 439;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.EnabledMovingAverage_e.Sumk1n1xk_InitialCondition
	  section.data(3).logicalSrcIdx = 440;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% leader_qball2_P.EnabledMovingAverage_c.unity_Value
	  section.data(1).logicalSrcIdx = 441;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_P.EnabledMovingAverage_c.UnitDelay_InitialCondition
	  section.data(2).logicalSrcIdx = 442;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_P.EnabledMovingAverage_c.Sumk1n1xk_InitialCondition
	  section.data(3).logicalSrcIdx = 443;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
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
    nTotSects     = 12;
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
    ;% Auto data (leader_qball2_B)
    ;%
      section.nData     = 206;
      section.data(206)  = dumData; %prealloc
      
	  ;% leader_qball2_B.SampleTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_B.Saturation
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_B.HILReadWrite1_o1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% leader_qball2_B.HILReadWrite1_o2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% leader_qball2_B.StreamClient_o3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 13;
	
	  ;% leader_qball2_B.wn
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 23;
	
	  ;% leader_qball2_B.Product1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 24;
	
	  ;% leader_qball2_B.Constant3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 25;
	
	  ;% leader_qball2_B.HeightEstimateBiasEstimateRefer
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 26;
	
	  ;% leader_qball2_B.OptiTrackHeightMeasurementBias
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 27;
	
	  ;% leader_qball2_B.RateTransition
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 28;
	
	  ;% leader_qball2_B.Derivative
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 29;
	
	  ;% leader_qball2_B.RateTransition1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 30;
	
	  ;% leader_qball2_B.RateTransition_c
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 31;
	
	  ;% leader_qball2_B.Gain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 32;
	
	  ;% leader_qball2_B.RateTransition3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 33;
	
	  ;% leader_qball2_B.s
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 34;
	
	  ;% leader_qball2_B.BatteryTopOrBottom
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 35;
	
	  ;% leader_qball2_B.SwitchBatteryConfigAcceleromter
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 36;
	
	  ;% leader_qball2_B.x0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 39;
	
	  ;% leader_qball2_B.Integrator1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 40;
	
	  ;% leader_qball2_B.Calibrationtimes
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 43;
	
	  ;% leader_qball2_B.Sum
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 44;
	
	  ;% leader_qball2_B.Constant
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 47;
	
	  ;% leader_qball2_B.Constant1
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 48;
	
	  ;% leader_qball2_B.Product
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 49;
	
	  ;% leader_qball2_B.wn_i
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 50;
	
	  ;% leader_qball2_B.Product1_o
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 51;
	
	  ;% leader_qball2_B.wn_g
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 52;
	
	  ;% leader_qball2_B.Product1_k
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 53;
	
	  ;% leader_qball2_B.Gain5
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 54;
	
	  ;% leader_qball2_B.Gain4
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 55;
	
	  ;% leader_qball2_B.x0_p
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 56;
	
	  ;% leader_qball2_B.Constant2
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 57;
	
	  ;% leader_qball2_B.Gain8
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 58;
	
	  ;% leader_qball2_B.Gain1
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 59;
	
	  ;% leader_qball2_B.Gain7
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 60;
	
	  ;% leader_qball2_B.Gain2
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 61;
	
	  ;% leader_qball2_B.Gain6
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 62;
	
	  ;% leader_qball2_B.Constant_d
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 63;
	
	  ;% leader_qball2_B.wn_a
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 64;
	
	  ;% leader_qball2_B.InverseModulus
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 65;
	
	  ;% leader_qball2_B.zt
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 66;
	
	  ;% leader_qball2_B.Product_f
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 67;
	
	  ;% leader_qball2_B.Product1_a
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 68;
	
	  ;% leader_qball2_B.Constant_e
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 69;
	
	  ;% leader_qball2_B.x0_h
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 70;
	
	  ;% leader_qball2_B.zt_i
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 71;
	
	  ;% leader_qball2_B.Product_l
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 72;
	
	  ;% leader_qball2_B.Constant_p
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 73;
	
	  ;% leader_qball2_B.x0_j
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 74;
	
	  ;% leader_qball2_B.zt_n
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 75;
	
	  ;% leader_qball2_B.Product_d
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 76;
	
	  ;% leader_qball2_B.Constant_a
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 77;
	
	  ;% leader_qball2_B.x0_d
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 78;
	
	  ;% leader_qball2_B.zt_nn
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 79;
	
	  ;% leader_qball2_B.Product_g
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 80;
	
	  ;% leader_qball2_B.RateTransition4
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 81;
	
	  ;% leader_qball2_B.Accelerometeroffsetsmanuallycal
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 82;
	
	  ;% leader_qball2_B.Gain1_m
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 83;
	
	  ;% leader_qball2_B.Gain_e
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 84;
	
	  ;% leader_qball2_B.Constant_o
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 85;
	
	  ;% leader_qball2_B.wn_n
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 86;
	
	  ;% leader_qball2_B.zt_j
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 87;
	
	  ;% leader_qball2_B.Product_lj
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 88;
	
	  ;% leader_qball2_B.Product1_e
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 91;
	
	  ;% leader_qball2_B.Calibrationtimes_j
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 94;
	
	  ;% leader_qball2_B.Sum_m
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 95;
	
	  ;% leader_qball2_B.Divide
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 98;
	
	  ;% leader_qball2_B.Fcn
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 99;
	
	  ;% leader_qball2_B.Integrator
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 100;
	
	  ;% leader_qball2_B.HPF
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 101;
	
	  ;% leader_qball2_B.Fcn_a
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 102;
	
	  ;% leader_qball2_B.Integrator_f
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 103;
	
	  ;% leader_qball2_B.ManualSwitch
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 104;
	
	  ;% leader_qball2_B.Bias
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 105;
	
	  ;% leader_qball2_B.Sum4
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 106;
	
	  ;% leader_qball2_B.Constant_a0
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 107;
	
	  ;% leader_qball2_B.wn_p
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 108;
	
	  ;% leader_qball2_B.Product1_n
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 109;
	
	  ;% leader_qball2_B.SwitchKd
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 110;
	
	  ;% leader_qball2_B.vmaxtakeoff
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 111;
	
	  ;% leader_qball2_B.amaxtakeoff
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 112;
	
	  ;% leader_qball2_B.Constant_m
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 113;
	
	  ;% leader_qball2_B.Constant_es
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 114;
	
	  ;% leader_qball2_B.CLOSEDLOOPON
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 115;
	
	  ;% leader_qball2_B.ManualSwitch2
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 116;
	
	  ;% leader_qball2_B.SliderGain
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 117;
	
	  ;% leader_qball2_B.RateLimiter3
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 118;
	
	  ;% leader_qball2_B.Constant_g
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 119;
	
	  ;% leader_qball2_B.Constant_j
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 120;
	
	  ;% leader_qball2_B.vmaxflight
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 121;
	
	  ;% leader_qball2_B.amaxflight
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 122;
	
	  ;% leader_qball2_B.ContinuousSigmoid_o1
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 123;
	
	  ;% leader_qball2_B.ContinuousSigmoid_o2
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 124;
	
	  ;% leader_qball2_B.ContinuousSigmoid_o3
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 125;
	
	  ;% leader_qball2_B.ContinuousSigmoid_o4
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 126;
	
	  ;% leader_qball2_B.SwitchKp
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 127;
	
	  ;% leader_qball2_B.Memory
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 128;
	
	  ;% leader_qball2_B.Integrator_a
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 129;
	
	  ;% leader_qball2_B.Constant1_l
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 130;
	
	  ;% leader_qball2_B.ThrottleTrim
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 131;
	
	  ;% leader_qball2_B.Constant_ov
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 132;
	
	  ;% leader_qball2_B.heightcommand1
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 133;
	
	  ;% leader_qball2_B.heightcommand2
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 134;
	
	  ;% leader_qball2_B.Switch
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 135;
	
	  ;% leader_qball2_B.Constant1_o
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 136;
	
	  ;% leader_qball2_B.landthrottletarget
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 137;
	
	  ;% leader_qball2_B.SigmoidPath_o1
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 138;
	
	  ;% leader_qball2_B.SigmoidPath_o2
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 139;
	
	  ;% leader_qball2_B.SigmoidPath_o3
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 140;
	
	  ;% leader_qball2_B.SigmoidPath_o4
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 141;
	
	  ;% leader_qball2_B.ManualSwitch_a
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 142;
	
	  ;% leader_qball2_B.Switch_e
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 143;
	
	  ;% leader_qball2_B.Constant_h
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 144;
	
	  ;% leader_qball2_B.Sum5
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 145;
	
	  ;% leader_qball2_B.ManualSwitch4
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 146;
	
	  ;% leader_qball2_B.SliderGain_o
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 147;
	
	  ;% leader_qball2_B.Saturation_c
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 148;
	
	  ;% leader_qball2_B.Constant_m3
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 149;
	
	  ;% leader_qball2_B.Constant_ef
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 150;
	
	  ;% leader_qball2_B.SwitchKd_k
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 151;
	
	  ;% leader_qball2_B.Memory_o
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 152;
	
	  ;% leader_qball2_B.Switch_p
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 153;
	
	  ;% leader_qball2_B.ManualSwitch_f
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 154;
	
	  ;% leader_qball2_B.ManualSwitch_b
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 155;
	
	  ;% leader_qball2_B.SwitchKp_b
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 156;
	
	  ;% leader_qball2_B.Constant_em
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 157;
	
	  ;% leader_qball2_B.Integrator1_l
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 158;
	
	  ;% leader_qball2_B.Pitch_Trim
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 159;
	
	  ;% leader_qball2_B.Sum_b
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 160;
	
	  ;% leader_qball2_B.Sum_n
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 161;
	
	  ;% leader_qball2_B.Sum1
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 162;
	
	  ;% leader_qball2_B.SwitchKd_m
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 163;
	
	  ;% leader_qball2_B.Memory_f
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 164;
	
	  ;% leader_qball2_B.Switch_f
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 165;
	
	  ;% leader_qball2_B.ManualSwitch_j
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 166;
	
	  ;% leader_qball2_B.SwitchKp_f
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 167;
	
	  ;% leader_qball2_B.Constant_n
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 168;
	
	  ;% leader_qball2_B.Integrator1_n
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 169;
	
	  ;% leader_qball2_B.roll_trim
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 170;
	
	  ;% leader_qball2_B.Sum_ng
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 171;
	
	  ;% leader_qball2_B.Sum2
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 172;
	
	  ;% leader_qball2_B.Sum3
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 173;
	
	  ;% leader_qball2_B.Constant_gy
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 174;
	
	  ;% leader_qball2_B.Product2
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 175;
	
	  ;% leader_qball2_B.Gain_d
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 179;
	
	  ;% leader_qball2_B.wn_h
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 181;
	
	  ;% leader_qball2_B.Product1_ey
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 182;
	
	  ;% leader_qball2_B.RateLimiter2
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 183;
	
	  ;% leader_qball2_B.SwitchKp_c
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 184;
	
	  ;% leader_qball2_B.Product_c
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 185;
	
	  ;% leader_qball2_B.wn_a5
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 186;
	
	  ;% leader_qball2_B.Product1_d
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 187;
	
	  ;% leader_qball2_B.SwitchKd_o
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 188;
	
	  ;% leader_qball2_B.RateLimiter1
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 189;
	
	  ;% leader_qball2_B.SwitchKp_cx
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 190;
	
	  ;% leader_qball2_B.Constant_emr
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 191;
	
	  ;% leader_qball2_B.x0_dh
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 192;
	
	  ;% leader_qball2_B.zt_je
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 193;
	
	  ;% leader_qball2_B.Product_b
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 194;
	
	  ;% leader_qball2_B.SwitchKi
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 195;
	
	  ;% leader_qball2_B.SwitchKi_h
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 196;
	
	  ;% leader_qball2_B.Gain1_a
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 197;
	
	  ;% leader_qball2_B.Gain4_g
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 200;
	
	  ;% leader_qball2_B.SwitchKi_i
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 204;
	
	  ;% leader_qball2_B.Product_n
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 205;
	
	  ;% leader_qball2_B.Constant_c
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 206;
	
	  ;% leader_qball2_B.x0_i
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 207;
	
	  ;% leader_qball2_B.zt_g
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 208;
	
	  ;% leader_qball2_B.Product_j
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 209;
	
	  ;% leader_qball2_B.SwitchKi_b
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 210;
	
	  ;% leader_qball2_B.Gain1_k
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 211;
	
	  ;% leader_qball2_B.DataTypeConversion
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 215;
	
	  ;% leader_qball2_B.DataTypeConversion1
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 216;
	
	  ;% leader_qball2_B.DataTypeConversion2
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 217;
	
	  ;% leader_qball2_B.DataTypeConversion3
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 218;
	
	  ;% leader_qball2_B.Constant_gl
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 219;
	
	  ;% leader_qball2_B.x0_g
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 220;
	
	  ;% leader_qball2_B.zt_m
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 221;
	
	  ;% leader_qball2_B.Product_lu
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 222;
	
	  ;% leader_qball2_B.SwitchKi_n
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 223;
	
	  ;% leader_qball2_B.SwitchKi_ih
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 224;
	
	  ;% leader_qball2_B.land
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 225;
	
	  ;% leader_qball2_B.In1
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 226;
	
	  ;% leader_qball2_B.Constant_hf
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 227;
	
	  ;% leader_qball2_B.SigmoidCompute_o1
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 228;
	
	  ;% leader_qball2_B.enable
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 239;
	
	  ;% leader_qball2_B.Constant_k
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 240;
	
	  ;% leader_qball2_B.adj_roll_cmd
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 241;
	
	  ;% leader_qball2_B.Constant_cm
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 242;
	
	  ;% leader_qball2_B.adj_pitch_cmd
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 243;
	
	  ;% leader_qball2_B.Constant_om
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 244;
	
	  ;% leader_qball2_B.Constant_mq
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 245;
	
	  ;% leader_qball2_B.div
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 246;
	
	  ;% leader_qball2_B.In1_g
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 249;
	
	  ;% leader_qball2_B.angle
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 250;
	
	  ;% leader_qball2_B.angle_m
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 251;
	
	  ;% leader_qball2_B.angle_f
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 252;
	
	  ;% leader_qball2_B.height
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 253;
	
	  ;% leader_qball2_B.y
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 254;
	
	  ;% leader_qball2_B.n
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 255;
	
	  ;% leader_qball2_B.nhat
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 256;
	
	  ;% leader_qball2_B.check
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 259;
	
	  ;% leader_qball2_B.acc_body
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 260;
	
	  ;% leader_qball2_B.Constant_cd
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 263;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% leader_qball2_B.StreamClient_o2
	  section.data(1).logicalSrcIdx = 206;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_B.StreamServer_o2
	  section.data(2).logicalSrcIdx = 207;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.SigmoidCompute_o2
	  section.data(1).logicalSrcIdx = 208;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% leader_qball2_B.StreamClient_o1
	  section.data(1).logicalSrcIdx = 209;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_B.Compare
	  section.data(2).logicalSrcIdx = 210;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_B.Compare_k
	  section.data(3).logicalSrcIdx = 211;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_B.Compare_m
	  section.data(4).logicalSrcIdx = 212;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_B.Compare_p
	  section.data(5).logicalSrcIdx = 213;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_B.StreamServer_o1
	  section.data(6).logicalSrcIdx = 214;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% leader_qball2_B.StreamClient_o4
	  section.data(1).logicalSrcIdx = 215;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_B.RelationalOperator
	  section.data(2).logicalSrcIdx = 216;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_B.RelationalOperator_o
	  section.data(3).logicalSrcIdx = 217;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_B.Compare_j
	  section.data(4).logicalSrcIdx = 218;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_B.HILWatchdog
	  section.data(5).logicalSrcIdx = 219;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_B.Compare_pf
	  section.data(6).logicalSrcIdx = 220;
	  section.data(6).dtTransOffset = 5;
	
	  ;% leader_qball2_B.LogicalOperator
	  section.data(7).logicalSrcIdx = 221;
	  section.data(7).dtTransOffset = 6;
	
	  ;% leader_qball2_B.LogicalOperator5
	  section.data(8).logicalSrcIdx = 222;
	  section.data(8).dtTransOffset = 7;
	
	  ;% leader_qball2_B.LogicalOperator2
	  section.data(9).logicalSrcIdx = 223;
	  section.data(9).dtTransOffset = 8;
	
	  ;% leader_qball2_B.LogicalOperator2_o
	  section.data(10).logicalSrcIdx = 224;
	  section.data(10).dtTransOffset = 9;
	
	  ;% leader_qball2_B.Compare_i
	  section.data(11).logicalSrcIdx = 225;
	  section.data(11).dtTransOffset = 10;
	
	  ;% leader_qball2_B.LogicalOperator_b
	  section.data(12).logicalSrcIdx = 226;
	  section.data(12).dtTransOffset = 11;
	
	  ;% leader_qball2_B.LogicalOperator_a
	  section.data(13).logicalSrcIdx = 227;
	  section.data(13).dtTransOffset = 12;
	
	  ;% leader_qball2_B.Compare_h
	  section.data(14).logicalSrcIdx = 228;
	  section.data(14).dtTransOffset = 13;
	
	  ;% leader_qball2_B.LogicalOperator_m
	  section.data(15).logicalSrcIdx = 229;
	  section.data(15).dtTransOffset = 14;
	
	  ;% leader_qball2_B.Compare_f
	  section.data(16).logicalSrcIdx = 230;
	  section.data(16).dtTransOffset = 15;
	
	  ;% leader_qball2_B.Compare_n
	  section.data(17).logicalSrcIdx = 231;
	  section.data(17).dtTransOffset = 16;
	
	  ;% leader_qball2_B.LogicalOperator1
	  section.data(18).logicalSrcIdx = 232;
	  section.data(18).dtTransOffset = 17;
	
	  ;% leader_qball2_B.LogicalOperator4
	  section.data(19).logicalSrcIdx = 233;
	  section.data(19).dtTransOffset = 18;
	
	  ;% leader_qball2_B.LogicalOperator1_o
	  section.data(20).logicalSrcIdx = 234;
	  section.data(20).dtTransOffset = 19;
	
	  ;% leader_qball2_B.LogicalOperator1_h
	  section.data(21).logicalSrcIdx = 235;
	  section.data(21).dtTransOffset = 20;
	
	  ;% leader_qball2_B.StreamServer_o3
	  section.data(22).logicalSrcIdx = 236;
	  section.data(22).dtTransOffset = 21;
	
	  ;% leader_qball2_B.RelationalOperator_og
	  section.data(23).logicalSrcIdx = 237;
	  section.data(23).dtTransOffset = 22;
	
	  ;% leader_qball2_B.RelationalOperator_m
	  section.data(24).logicalSrcIdx = 238;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.EnabledSubsystem1_b.RelationalOperator
	  section.data(1).logicalSrcIdx = 239;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.EnabledSubsystem1.RelationalOperator
	  section.data(1).logicalSrcIdx = 240;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.sf_EmbeddedMATLABFunction_j4.y
	  section.data(1).logicalSrcIdx = 241;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.sf_EmbeddedMATLABFunction.y
	  section.data(1).logicalSrcIdx = 242;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.sf_EmbeddedMATLABFunction_d.y
	  section.data(1).logicalSrcIdx = 243;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.EnabledMovingAverage_e.div
	  section.data(1).logicalSrcIdx = 244;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_B.EnabledMovingAverage_c.div
	  section.data(1).logicalSrcIdx = 245;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
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
    nTotSects     = 27;
    sectIdxOffset = 12;
    
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
    ;% Auto data (leader_qball2_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.SampleTime_PreviousTime
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 63;
      section.data(63)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_DW.UnitDelay_DSTATE_o
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_DW.Sumk1n1xk_DSTATE
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_DW.DiscreteTimeIntegrator_DSTATE_a
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 6;
	
	  ;% leader_qball2_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 7;
	
	  ;% leader_qball2_DW.Memory_PreviousInput
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 11;
	
	  ;% leader_qball2_DW.Memory_PreviousInput_g
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 15;
	
	  ;% leader_qball2_DW.Memory_PreviousInput_b
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 16;
	
	  ;% leader_qball2_DW.RateTransition_Buffer0
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 17;
	
	  ;% leader_qball2_DW.TimeStampA
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 18;
	
	  ;% leader_qball2_DW.LastUAtTimeA
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 19;
	
	  ;% leader_qball2_DW.TimeStampB
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 20;
	
	  ;% leader_qball2_DW.LastUAtTimeB
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 21;
	
	  ;% leader_qball2_DW.RateTransition1_Buffer0
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 22;
	
	  ;% leader_qball2_DW.RateTransition_Buffer0_l
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 23;
	
	  ;% leader_qball2_DW.InverseModulus_PreviousInput
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 24;
	
	  ;% leader_qball2_DW.InverseModulus_Revolutions
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 25;
	
	  ;% leader_qball2_DW.PrevY
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 26;
	
	  ;% leader_qball2_DW.PrevY_k
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 27;
	
	  ;% leader_qball2_DW.LastMajorTime
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 28;
	
	  ;% leader_qball2_DW.ContinuousSigmoid_Sigmoid
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 29;
	
	  ;% leader_qball2_DW.Memory_PreviousInput_p
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 40;
	
	  ;% leader_qball2_DW.SigmoidPath_Path
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 41;
	
	  ;% leader_qball2_DW.SigmoidPath_NewPath
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 52;
	
	  ;% leader_qball2_DW.TimeStampA_e
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 63;
	
	  ;% leader_qball2_DW.LastUAtTimeA_a
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 64;
	
	  ;% leader_qball2_DW.TimeStampB_c
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 65;
	
	  ;% leader_qball2_DW.LastUAtTimeB_l
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 66;
	
	  ;% leader_qball2_DW.Memory_PreviousInput_i
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 67;
	
	  ;% leader_qball2_DW.Memory_PreviousInput_j
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 68;
	
	  ;% leader_qball2_DW.Memory_PreviousInput_it
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 69;
	
	  ;% leader_qball2_DW.Memory_PreviousInput_m
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 70;
	
	  ;% leader_qball2_DW.PrevY_i
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 71;
	
	  ;% leader_qball2_DW.PrevY_a
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 72;
	
	  ;% leader_qball2_DW.state
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 73;
	
	  ;% leader_qball2_DW.c
	  section.data(37).logicalSrcIdx = 37;
	  section.data(37).dtTransOffset = 74;
	
	  ;% leader_qball2_DW.state_h
	  section.data(38).logicalSrcIdx = 38;
	  section.data(38).dtTransOffset = 75;
	
	  ;% leader_qball2_DW.counter
	  section.data(39).logicalSrcIdx = 39;
	  section.data(39).dtTransOffset = 76;
	
	  ;% leader_qball2_DW.P_00
	  section.data(40).logicalSrcIdx = 40;
	  section.data(40).dtTransOffset = 77;
	
	  ;% leader_qball2_DW.P_01
	  section.data(41).logicalSrcIdx = 41;
	  section.data(41).dtTransOffset = 78;
	
	  ;% leader_qball2_DW.P_10
	  section.data(42).logicalSrcIdx = 42;
	  section.data(42).dtTransOffset = 79;
	
	  ;% leader_qball2_DW.P_11
	  section.data(43).logicalSrcIdx = 43;
	  section.data(43).dtTransOffset = 80;
	
	  ;% leader_qball2_DW.x_angle
	  section.data(44).logicalSrcIdx = 44;
	  section.data(44).dtTransOffset = 81;
	
	  ;% leader_qball2_DW.x_bias
	  section.data(45).logicalSrcIdx = 45;
	  section.data(45).dtTransOffset = 82;
	
	  ;% leader_qball2_DW.P_00_g
	  section.data(46).logicalSrcIdx = 46;
	  section.data(46).dtTransOffset = 83;
	
	  ;% leader_qball2_DW.P_01_h
	  section.data(47).logicalSrcIdx = 47;
	  section.data(47).dtTransOffset = 84;
	
	  ;% leader_qball2_DW.P_10_h
	  section.data(48).logicalSrcIdx = 48;
	  section.data(48).dtTransOffset = 85;
	
	  ;% leader_qball2_DW.P_11_n
	  section.data(49).logicalSrcIdx = 49;
	  section.data(49).dtTransOffset = 86;
	
	  ;% leader_qball2_DW.x_angle_g
	  section.data(50).logicalSrcIdx = 50;
	  section.data(50).dtTransOffset = 87;
	
	  ;% leader_qball2_DW.x_bias_e
	  section.data(51).logicalSrcIdx = 51;
	  section.data(51).dtTransOffset = 88;
	
	  ;% leader_qball2_DW.P_00_p
	  section.data(52).logicalSrcIdx = 52;
	  section.data(52).dtTransOffset = 89;
	
	  ;% leader_qball2_DW.P_01_c
	  section.data(53).logicalSrcIdx = 53;
	  section.data(53).dtTransOffset = 90;
	
	  ;% leader_qball2_DW.P_10_m
	  section.data(54).logicalSrcIdx = 54;
	  section.data(54).dtTransOffset = 91;
	
	  ;% leader_qball2_DW.P_11_a
	  section.data(55).logicalSrcIdx = 55;
	  section.data(55).dtTransOffset = 92;
	
	  ;% leader_qball2_DW.x_angle_h
	  section.data(56).logicalSrcIdx = 56;
	  section.data(56).dtTransOffset = 93;
	
	  ;% leader_qball2_DW.x_bias_l
	  section.data(57).logicalSrcIdx = 57;
	  section.data(57).dtTransOffset = 94;
	
	  ;% leader_qball2_DW.P_00_b
	  section.data(58).logicalSrcIdx = 58;
	  section.data(58).dtTransOffset = 95;
	
	  ;% leader_qball2_DW.P_01_f
	  section.data(59).logicalSrcIdx = 59;
	  section.data(59).dtTransOffset = 96;
	
	  ;% leader_qball2_DW.P_10_j
	  section.data(60).logicalSrcIdx = 60;
	  section.data(60).dtTransOffset = 97;
	
	  ;% leader_qball2_DW.P_11_h
	  section.data(61).logicalSrcIdx = 61;
	  section.data(61).dtTransOffset = 98;
	
	  ;% leader_qball2_DW.x_height
	  section.data(62).logicalSrcIdx = 62;
	  section.data(62).dtTransOffset = 99;
	
	  ;% leader_qball2_DW.x_bias_h
	  section.data(63).logicalSrcIdx = 63;
	  section.data(63).dtTransOffset = 100;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.StreamClient_Stream
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.StreamServer_Stream
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.ContinuousSigmoid_RWORK.Time
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.SigmoidPath_RWORK.Time
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 53;
      section.data(53)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.HILReadWrite1_PWORK
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.Battery_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 72;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_DW.height_Kalman_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 73;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_DW.pitch_Kalman_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 74;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_DW.roll_Kalman_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 75;
	  section.data(6).dtTransOffset = 5;
	
	  ;% leader_qball2_DW.yaw_Kalman_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 76;
	  section.data(7).dtTransOffset = 6;
	
	  ;% leader_qball2_DW.pitch_acc_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 77;
	  section.data(8).dtTransOffset = 7;
	
	  ;% leader_qball2_DW.pitch_acc_asin_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 78;
	  section.data(9).dtTransOffset = 8;
	
	  ;% leader_qball2_DW.roll_acc_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 79;
	  section.data(10).dtTransOffset = 9;
	
	  ;% leader_qball2_DW.roll_acc_asin_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 80;
	  section.data(11).dtTransOffset = 10;
	
	  ;% leader_qball2_DW.Scope_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 81;
	  section.data(12).dtTransOffset = 11;
	
	  ;% leader_qball2_DW.Scope1_PWORK_c.LoggedData
	  section.data(13).logicalSrcIdx = 82;
	  section.data(13).dtTransOffset = 12;
	
	  ;% leader_qball2_DW.accelerometerxyz_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 83;
	  section.data(14).dtTransOffset = 13;
	
	  ;% leader_qball2_DW.gyroscopexyz_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 84;
	  section.data(15).dtTransOffset = 14;
	
	  ;% leader_qball2_DW.sonar_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 85;
	  section.data(16).dtTransOffset = 15;
	
	  ;% leader_qball2_DW.FilteredAccel_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 86;
	  section.data(17).dtTransOffset = 16;
	
	  ;% leader_qball2_DW.NormalizedBiasVector_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 87;
	  section.data(18).dtTransOffset = 17;
	
	  ;% leader_qball2_DW.check_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 88;
	  section.data(19).dtTransOffset = 18;
	
	  ;% leader_qball2_DW.accelcalibrated_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 89;
	  section.data(20).dtTransOffset = 19;
	
	  ;% leader_qball2_DW.accelsoffset_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 90;
	  section.data(21).dtTransOffset = 20;
	
	  ;% leader_qball2_DW.PWM_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 91;
	  section.data(22).dtTransOffset = 21;
	
	  ;% leader_qball2_DW.sonar_PWORK_p.LoggedData
	  section.data(23).logicalSrcIdx = 92;
	  section.data(23).dtTransOffset = 22;
	
	  ;% leader_qball2_DW.HILWatchdog_PWORK
	  section.data(24).logicalSrcIdx = 93;
	  section.data(24).dtTransOffset = 23;
	
	  ;% leader_qball2_DW.watchdog_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 94;
	  section.data(25).dtTransOffset = 24;
	
	  ;% leader_qball2_DW.RollPitchrunawaycheck_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 95;
	  section.data(26).dtTransOffset = 25;
	
	  ;% leader_qball2_DW.motors_in_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 96;
	  section.data(27).dtTransOffset = 26;
	
	  ;% leader_qball2_DW.motors_out_PWORK.LoggedData
	  section.data(28).logicalSrcIdx = 97;
	  section.data(28).dtTransOffset = 27;
	
	  ;% leader_qball2_DW.Scope1_PWORK_cr.LoggedData
	  section.data(29).logicalSrcIdx = 98;
	  section.data(29).dtTransOffset = 28;
	
	  ;% leader_qball2_DW.error_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 99;
	  section.data(30).dtTransOffset = 29;
	
	  ;% leader_qball2_DW.new_PWORK.LoggedData
	  section.data(31).logicalSrcIdx = 100;
	  section.data(31).dtTransOffset = 30;
	
	  ;% leader_qball2_DW.PacketfromTarget_PWORK.LoggedData
	  section.data(32).logicalSrcIdx = 101;
	  section.data(32).dtTransOffset = 31;
	
	  ;% leader_qball2_DW.rcvdpackets_PWORK.LoggedData
	  section.data(33).logicalSrcIdx = 102;
	  section.data(33).dtTransOffset = 32;
	
	  ;% leader_qball2_DW.state_PWORK.LoggedData
	  section.data(34).logicalSrcIdx = 103;
	  section.data(34).dtTransOffset = 33;
	
	  ;% leader_qball2_DW.land_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 104;
	  section.data(35).dtTransOffset = 34;
	
	  ;% leader_qball2_DW.armed_PWORK.LoggedData
	  section.data(36).logicalSrcIdx = 105;
	  section.data(36).dtTransOffset = 35;
	
	  ;% leader_qball2_DW.Pitch_PWORK.LoggedData
	  section.data(37).logicalSrcIdx = 106;
	  section.data(37).dtTransOffset = 36;
	
	  ;% leader_qball2_DW.Origvadjustedpitch_PWORK.LoggedData
	  section.data(38).logicalSrcIdx = 107;
	  section.data(38).dtTransOffset = 37;
	
	  ;% leader_qball2_DW.pitchcontrolsignalcomponents_PW.LoggedData
	  section.data(39).logicalSrcIdx = 108;
	  section.data(39).dtTransOffset = 38;
	
	  ;% leader_qball2_DW.Pitch1_PWORK.LoggedData
	  section.data(40).logicalSrcIdx = 109;
	  section.data(40).dtTransOffset = 39;
	
	  ;% leader_qball2_DW.Roll_PWORK.LoggedData
	  section.data(41).logicalSrcIdx = 110;
	  section.data(41).dtTransOffset = 40;
	
	  ;% leader_qball2_DW.Origvadjustedroll_PWORK.LoggedData
	  section.data(42).logicalSrcIdx = 111;
	  section.data(42).dtTransOffset = 41;
	
	  ;% leader_qball2_DW.X_cmdandX_meas_PWORK.LoggedData
	  section.data(43).logicalSrcIdx = 112;
	  section.data(43).dtTransOffset = 42;
	
	  ;% leader_qball2_DW.Roll1_PWORK.LoggedData
	  section.data(44).logicalSrcIdx = 113;
	  section.data(44).dtTransOffset = 43;
	
	  ;% leader_qball2_DW.ToHostFile_PWORK
	  section.data(45).logicalSrcIdx = 114;
	  section.data(45).dtTransOffset = 44;
	
	  ;% leader_qball2_DW.throttlecmd_PWORK.LoggedData
	  section.data(46).logicalSrcIdx = 115;
	  section.data(46).dtTransOffset = 45;
	
	  ;% leader_qball2_DW.throttlesw_PWORK.LoggedData
	  section.data(47).logicalSrcIdx = 116;
	  section.data(47).dtTransOffset = 46;
	
	  ;% leader_qball2_DW.throttlejoystick_PWORK.LoggedData
	  section.data(48).logicalSrcIdx = 117;
	  section.data(48).dtTransOffset = 47;
	
	  ;% leader_qball2_DW.landwsonar_PWORK.LoggedData
	  section.data(49).logicalSrcIdx = 118;
	  section.data(49).dtTransOffset = 48;
	
	  ;% leader_qball2_DW.HeightPID_PWORK.LoggedData
	  section.data(50).logicalSrcIdx = 119;
	  section.data(50).dtTransOffset = 49;
	
	  ;% leader_qball2_DW.u_yaw_PWORK.LoggedData
	  section.data(51).logicalSrcIdx = 120;
	  section.data(51).dtTransOffset = 50;
	
	  ;% leader_qball2_DW.u_yaw1_PWORK.LoggedData
	  section.data(52).logicalSrcIdx = 121;
	  section.data(52).dtTransOffset = 51;
	
	  ;% leader_qball2_DW.yaw_error_PWORK.LoggedData
	  section.data(53).logicalSrcIdx = 122;
	  section.data(53).dtTransOffset = 52;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.ToHostFile_SamplesCount
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.ToHostFile_ArrayNameLength
	  section.data(2).logicalSrcIdx = 125;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.Integrator1_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.Integrator1_IWORK_j.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 127;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_DW.Integrator1_IWORK_o.IcNeedsLoading
	  section.data(3).logicalSrcIdx = 128;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_DW.Integrator1_IWORK_l.IcNeedsLoading
	  section.data(4).logicalSrcIdx = 129;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_DW.Integrator1_IWORK_ov.IcNeedsLoading
	  section.data(5).logicalSrcIdx = 130;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_DW.Integrator1_IWORK_b.IcNeedsLoading
	  section.data(6).logicalSrcIdx = 131;
	  section.data(6).dtTransOffset = 5;
	
	  ;% leader_qball2_DW.Integrator1_IWORK_li.IcNeedsLoading
	  section.data(7).logicalSrcIdx = 132;
	  section.data(7).dtTransOffset = 6;
	
	  ;% leader_qball2_DW.Integrator1_IWORK_g.IcNeedsLoading
	  section.data(8).logicalSrcIdx = 133;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.TriggeredSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.EnabledMovingAverage_SubsysRanB
	  section.data(2).logicalSrcIdx = 135;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_DW.EnabledSubsystemLatchOutputHigh
	  section.data(3).logicalSrcIdx = 136;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_DW.EnabledSubsystem_SubsysRanBC
	  section.data(4).logicalSrcIdx = 137;
	  section.data(4).dtTransOffset = 3;
	
	  ;% leader_qball2_DW.EnabledSubsystem2_SubsysRanBC
	  section.data(5).logicalSrcIdx = 138;
	  section.data(5).dtTransOffset = 4;
	
	  ;% leader_qball2_DW.EnabledSubsystem_SubsysRanBC_l
	  section.data(6).logicalSrcIdx = 139;
	  section.data(6).dtTransOffset = 5;
	
	  ;% leader_qball2_DW.SigmoidPath_Toggle
	  section.data(7).logicalSrcIdx = 140;
	  section.data(7).dtTransOffset = 6;
	
	  ;% leader_qball2_DW.EnabledSubsystem_SubsysRanBC_d
	  section.data(8).logicalSrcIdx = 141;
	  section.data(8).dtTransOffset = 7;
	
	  ;% leader_qball2_DW.EnabledSubsystem_SubsysRanBC_h
	  section.data(9).logicalSrcIdx = 142;
	  section.data(9).dtTransOffset = 8;
	
	  ;% leader_qball2_DW.EnabledSubsystem_SubsysRanBC_f
	  section.data(10).logicalSrcIdx = 143;
	  section.data(10).dtTransOffset = 9;
	
	  ;% leader_qball2_DW.EnabledSubsystem_SubsysRanBC_m
	  section.data(11).logicalSrcIdx = 144;
	  section.data(11).dtTransOffset = 10;
	
	  ;% leader_qball2_DW.TriggeredSigmoidCompute_SubsysR
	  section.data(12).logicalSrcIdx = 145;
	  section.data(12).dtTransOffset = 11;
	
	  ;% leader_qball2_DW.armheightcommand_SubsysRanBC
	  section.data(13).logicalSrcIdx = 146;
	  section.data(13).dtTransOffset = 12;
	
	  ;% leader_qball2_DW.SigmoidCompute_Toggle
	  section.data(14).logicalSrcIdx = 147;
	  section.data(14).dtTransOffset = 13;
	
	  ;% leader_qball2_DW.SwitchCase_ActiveSubsystem
	  section.data(15).logicalSrcIdx = 148;
	  section.data(15).dtTransOffset = 14;
	
	  ;% leader_qball2_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(16).logicalSrcIdx = 149;
	  section.data(16).dtTransOffset = 15;
	
	  ;% leader_qball2_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(17).logicalSrcIdx = 150;
	  section.data(17).dtTransOffset = 16;
	
	  ;% leader_qball2_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(18).logicalSrcIdx = 151;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.ContinuousSigmoid_Flag
	  section.data(1).logicalSrcIdx = 152;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.SigmoidPath_Flag
	  section.data(2).logicalSrcIdx = 153;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.StreamClient_Connected
	  section.data(2).logicalSrcIdx = 155;
	  section.data(2).dtTransOffset = 2;
	
	  ;% leader_qball2_DW.InverseModulus_FirstSample
	  section.data(3).logicalSrcIdx = 156;
	  section.data(3).dtTransOffset = 3;
	
	  ;% leader_qball2_DW.HILWatchdog_IsStarted
	  section.data(4).logicalSrcIdx = 157;
	  section.data(4).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.HILReadWrite1_W_DigitalBuffer
	  section.data(1).logicalSrcIdx = 158;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledMovingAverage_MODE
	  section.data(1).logicalSrcIdx = 159;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.EnabledSubsystem_MODE
	  section.data(2).logicalSrcIdx = 160;
	  section.data(2).dtTransOffset = 1;
	
	  ;% leader_qball2_DW.EnabledSubsystem_MODE_h
	  section.data(3).logicalSrcIdx = 161;
	  section.data(3).dtTransOffset = 2;
	
	  ;% leader_qball2_DW.armheightcommand_MODE
	  section.data(4).logicalSrcIdx = 162;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledSubsystem1_b.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 163;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledSubsystem1_b.EnabledSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 164;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledSubsystem1_b.EnabledSubsystem1_MODE
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledSubsystem1.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 166;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 167;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledSubsystem1.EnabledSubsystem1_MODE
	  section.data(1).logicalSrcIdx = 168;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledMovingAverage_e.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 169;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.EnabledMovingAverage_e.Sumk1n1xk_DSTATE
	  section.data(2).logicalSrcIdx = 170;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledMovingAverage_e.EnabledMovingAverage_SubsysRanB
	  section.data(1).logicalSrcIdx = 171;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledMovingAverage_e.EnabledMovingAverage_MODE
	  section.data(1).logicalSrcIdx = 172;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledMovingAverage_c.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 173;
	  section.data(1).dtTransOffset = 0;
	
	  ;% leader_qball2_DW.EnabledMovingAverage_c.Sumk1n1xk_DSTATE
	  section.data(2).logicalSrcIdx = 174;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledMovingAverage_c.EnabledMovingAverage_SubsysRanB
	  section.data(1).logicalSrcIdx = 175;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% leader_qball2_DW.EnabledMovingAverage_c.EnabledMovingAverage_MODE
	  section.data(1).logicalSrcIdx = 176;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
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


  targMap.checksum0 = 3555560272;
  targMap.checksum1 = 540016725;
  targMap.checksum2 = 2653870487;
  targMap.checksum3 = 1225264746;

