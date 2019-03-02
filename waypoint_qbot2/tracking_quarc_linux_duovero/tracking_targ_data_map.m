  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (tracking_P)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% tracking_P.HILInitialize_analog_input_maxi
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_P.HILInitialize_analog_input_mini
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% tracking_P.HILInitialize_final_other_outpu
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% tracking_P.HILInitialize_final_pwm_outputs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 21;
	
	  ;% tracking_P.HILInitialize_initial_other_out
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 22;
	
	  ;% tracking_P.HILInitialize_initial_pwm_outpu
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 25;
	
	  ;% tracking_P.SecondOrderLowPassFilter2_input
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 26;
	
	  ;% tracking_P.SecondOrderLowPassFilter2_inp_p
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 27;
	
	  ;% tracking_P.SecondOrderLowPassFilter2_inp_l
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 28;
	
	  ;% tracking_P.SecondOrderLowPassFilter2_inp_k
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 29;
	
	  ;% tracking_P.HILInitialize_pwm_frequency
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 30;
	
	  ;% tracking_P.HILInitialize_pwm_leading_deadb
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 34;
	
	  ;% tracking_P.HILInitialize_pwm_trailing_dead
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 35;
	
	  ;% tracking_P.HILInitialize_set_other_outputs
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 36;
	
	  ;% tracking_P.HILInitialize_set_other_outpu_l
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 37;
	
	  ;% tracking_P.HILInitialize_set_other_outpu_h
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 38;
	
	  ;% tracking_P.HILInitialize_set_other_outpu_b
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 39;
	
	  ;% tracking_P.HILInitialize_watchdog_pwm_outp
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% tracking_P.HILInitialize_initial_encoder_c
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_P.HILInitialize_pwm_alignment
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% tracking_P.HILInitialize_pwm_configuration
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% tracking_P.HILInitialize_pwm_modes
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% tracking_P.HILInitialize_pwm_polarity
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 7;
	
	  ;% tracking_P.HILInitialize_watchdog_digital_
	  section.data(6).logicalSrcIdx = 23;
	  section.data(6).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% tracking_P.HILRead1_analog_channels
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_P.HILInitialize_analog_input_chan
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% tracking_P.HILRead1_digital_channels
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 11;
	
	  ;% tracking_P.HILInitialize_encoder_channels
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 14;
	
	  ;% tracking_P.HILRead1_encoder_channels
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 18;
	
	  ;% tracking_P.HILWrite_other_channels
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 20;
	
	  ;% tracking_P.HILRead1_other_channels
	  section.data(7).logicalSrcIdx = 30;
	  section.data(7).dtTransOffset = 22;
	
	  ;% tracking_P.HILInitialize_other_output_chan
	  section.data(8).logicalSrcIdx = 31;
	  section.data(8).dtTransOffset = 23;
	
	  ;% tracking_P.HILInitialize_pwm_channels
	  section.data(9).logicalSrcIdx = 32;
	  section.data(9).dtTransOffset = 25;
	
	  ;% tracking_P.HILInitialize_quadrature
	  section.data(10).logicalSrcIdx = 33;
	  section.data(10).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% tracking_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
	  ;% tracking_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 2;
	
	  ;% tracking_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 37;
	  section.data(4).dtTransOffset = 3;
	
	  ;% tracking_P.HILInitialize_set_analog_inpu_a
	  section.data(5).logicalSrcIdx = 38;
	  section.data(5).dtTransOffset = 4;
	
	  ;% tracking_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 39;
	  section.data(6).dtTransOffset = 5;
	
	  ;% tracking_P.HILInitialize_set_analog_outp_m
	  section.data(7).logicalSrcIdx = 40;
	  section.data(7).dtTransOffset = 6;
	
	  ;% tracking_P.HILInitialize_set_analog_outp_g
	  section.data(8).logicalSrcIdx = 41;
	  section.data(8).dtTransOffset = 7;
	
	  ;% tracking_P.HILInitialize_set_analog_outp_n
	  section.data(9).logicalSrcIdx = 42;
	  section.data(9).dtTransOffset = 8;
	
	  ;% tracking_P.HILInitialize_set_analog_outp_l
	  section.data(10).logicalSrcIdx = 43;
	  section.data(10).dtTransOffset = 9;
	
	  ;% tracking_P.HILInitialize_set_analog_outp_a
	  section.data(11).logicalSrcIdx = 44;
	  section.data(11).dtTransOffset = 10;
	
	  ;% tracking_P.HILInitialize_set_analog_out_lq
	  section.data(12).logicalSrcIdx = 45;
	  section.data(12).dtTransOffset = 11;
	
	  ;% tracking_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 46;
	  section.data(13).dtTransOffset = 12;
	
	  ;% tracking_P.HILInitialize_set_clock_frequ_n
	  section.data(14).logicalSrcIdx = 47;
	  section.data(14).dtTransOffset = 13;
	
	  ;% tracking_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 48;
	  section.data(15).dtTransOffset = 14;
	
	  ;% tracking_P.HILInitialize_set_clock_param_k
	  section.data(16).logicalSrcIdx = 49;
	  section.data(16).dtTransOffset = 15;
	
	  ;% tracking_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 50;
	  section.data(17).dtTransOffset = 16;
	
	  ;% tracking_P.HILInitialize_set_digital_out_h
	  section.data(18).logicalSrcIdx = 51;
	  section.data(18).dtTransOffset = 17;
	
	  ;% tracking_P.HILInitialize_set_digital_out_j
	  section.data(19).logicalSrcIdx = 52;
	  section.data(19).dtTransOffset = 18;
	
	  ;% tracking_P.HILInitialize_set_digital_out_l
	  section.data(20).logicalSrcIdx = 53;
	  section.data(20).dtTransOffset = 19;
	
	  ;% tracking_P.HILInitialize_set_digital_out_g
	  section.data(21).logicalSrcIdx = 54;
	  section.data(21).dtTransOffset = 20;
	
	  ;% tracking_P.HILInitialize_set_digital_out_d
	  section.data(22).logicalSrcIdx = 55;
	  section.data(22).dtTransOffset = 21;
	
	  ;% tracking_P.HILInitialize_set_digital_ou_h3
	  section.data(23).logicalSrcIdx = 56;
	  section.data(23).dtTransOffset = 22;
	
	  ;% tracking_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 57;
	  section.data(24).dtTransOffset = 23;
	
	  ;% tracking_P.HILInitialize_set_encoder_cou_m
	  section.data(25).logicalSrcIdx = 58;
	  section.data(25).dtTransOffset = 24;
	
	  ;% tracking_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 59;
	  section.data(26).dtTransOffset = 25;
	
	  ;% tracking_P.HILInitialize_set_encoder_par_a
	  section.data(27).logicalSrcIdx = 60;
	  section.data(27).dtTransOffset = 26;
	
	  ;% tracking_P.HILInitialize_set_other_outpu_d
	  section.data(28).logicalSrcIdx = 61;
	  section.data(28).dtTransOffset = 27;
	
	  ;% tracking_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 62;
	  section.data(29).dtTransOffset = 28;
	
	  ;% tracking_P.HILInitialize_set_pwm_outputs_j
	  section.data(30).logicalSrcIdx = 63;
	  section.data(30).dtTransOffset = 29;
	
	  ;% tracking_P.HILInitialize_set_pwm_outputs_e
	  section.data(31).logicalSrcIdx = 64;
	  section.data(31).dtTransOffset = 30;
	
	  ;% tracking_P.HILInitialize_set_pwm_outputs_k
	  section.data(32).logicalSrcIdx = 65;
	  section.data(32).dtTransOffset = 31;
	
	  ;% tracking_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 66;
	  section.data(33).dtTransOffset = 32;
	
	  ;% tracking_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 67;
	  section.data(34).dtTransOffset = 33;
	
	  ;% tracking_P.HILInitialize_set_pwm_params__e
	  section.data(35).logicalSrcIdx = 68;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% tracking_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
	  ;% tracking_P.Constant9_Value
	  section.data(3).logicalSrcIdx = 71;
	  section.data(3).dtTransOffset = 2;
	
	  ;% tracking_P.Constant1_Value_n
	  section.data(4).logicalSrcIdx = 72;
	  section.data(4).dtTransOffset = 3;
	
	  ;% tracking_P.Constant9_Value_e
	  section.data(5).logicalSrcIdx = 73;
	  section.data(5).dtTransOffset = 4;
	
	  ;% tracking_P.Constant2_Value_i
	  section.data(6).logicalSrcIdx = 74;
	  section.data(6).dtTransOffset = 5;
	
	  ;% tracking_P.Integrator2_IC
	  section.data(7).logicalSrcIdx = 75;
	  section.data(7).dtTransOffset = 6;
	
	  ;% tracking_P.Integrator2_IC_k
	  section.data(8).logicalSrcIdx = 76;
	  section.data(8).dtTransOffset = 7;
	
	  ;% tracking_P.tickstoencoderrotation_Gain
	  section.data(9).logicalSrcIdx = 77;
	  section.data(9).dtTransOffset = 8;
	
	  ;% tracking_P.encoderrotationtowheelrotationg
	  section.data(10).logicalSrcIdx = 78;
	  section.data(10).dtTransOffset = 9;
	
	  ;% tracking_P.wheelradiousmm_Gain
	  section.data(11).logicalSrcIdx = 79;
	  section.data(11).dtTransOffset = 10;
	
	  ;% tracking_P.mmtom_Gain
	  section.data(12).logicalSrcIdx = 80;
	  section.data(12).dtTransOffset = 11;
	
	  ;% tracking_P.Constant_Value
	  section.data(13).logicalSrcIdx = 81;
	  section.data(13).dtTransOffset = 12;
	
	  ;% tracking_P.x0_Value
	  section.data(14).logicalSrcIdx = 82;
	  section.data(14).dtTransOffset = 13;
	
	  ;% tracking_P.tickstoencoderrotation_Gain_i
	  section.data(15).logicalSrcIdx = 83;
	  section.data(15).dtTransOffset = 14;
	
	  ;% tracking_P.encoderrotationtowheelrotatio_n
	  section.data(16).logicalSrcIdx = 84;
	  section.data(16).dtTransOffset = 15;
	
	  ;% tracking_P.wheelradiousmm_Gain_k
	  section.data(17).logicalSrcIdx = 85;
	  section.data(17).dtTransOffset = 16;
	
	  ;% tracking_P.mmtom_Gain_h
	  section.data(18).logicalSrcIdx = 86;
	  section.data(18).dtTransOffset = 17;
	
	  ;% tracking_P.Constant_Value_m
	  section.data(19).logicalSrcIdx = 87;
	  section.data(19).dtTransOffset = 18;
	
	  ;% tracking_P.x0_Value_k
	  section.data(20).logicalSrcIdx = 88;
	  section.data(20).dtTransOffset = 19;
	
	  ;% tracking_P.Integrator_IC
	  section.data(21).logicalSrcIdx = 89;
	  section.data(21).dtTransOffset = 20;
	
	  ;% tracking_P.Integrator_IC_p
	  section.data(22).logicalSrcIdx = 90;
	  section.data(22).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% tracking_P.HILWrite_Active
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_P.HILRead1_Active
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (tracking_B)
    ;%
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% tracking_B.Constant2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_B.Constant1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% tracking_B.Constant9
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% tracking_B.Constant1_a
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% tracking_B.Integrator2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% tracking_B.Constant9_m
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% tracking_B.Integrator3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% tracking_B.Constant2_a
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% tracking_B.Integrator1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% tracking_B.Product1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% tracking_B.Product1_a
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% tracking_B.VectorConcatenate
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% tracking_B.mmtom
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 26;
	
	  ;% tracking_B.x0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 27;
	
	  ;% tracking_B.Product
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 28;
	
	  ;% tracking_B.mmtom_o
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 29;
	
	  ;% tracking_B.x0_j
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 30;
	
	  ;% tracking_B.Product_f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 31;
	
	  ;% tracking_B.vL
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 32;
	
	  ;% tracking_B.vR
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 33;
	
	  ;% tracking_B.x_dot
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 34;
	
	  ;% tracking_B.y_dot
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 35;
	
	  ;% tracking_B.psi_dot
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 36;
	
	  ;% tracking_B.x_dot_e
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 37;
	
	  ;% tracking_B.y_dot_i
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 38;
	
	  ;% tracking_B.psi_dot_n
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 39;
	
	  ;% tracking_B.vC
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 40;
	
	  ;% tracking_B.Omega
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 41;
	
	  ;% tracking_B.u_1r
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 42;
	
	  ;% tracking_B.u_2r
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 6;
    sectIdxOffset = 1;
    
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
    ;% Auto data (tracking_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% tracking_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 10;
	
	  ;% tracking_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 20;
	
	  ;% tracking_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% tracking_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 28;
	
	  ;% tracking_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 32;
	
	  ;% tracking_DW.HILWrite_OtherBuffer
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% tracking_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% tracking_DW.HILWrite_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_DW.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% tracking_DW.HILRead1_PWORK
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% tracking_DW.FloatingScope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% tracking_DW.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_DW.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 4;
	
	  ;% tracking_DW.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 8;
	
	  ;% tracking_DW.HILInitialize_POAlignValues
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 12;
	
	  ;% tracking_DW.HILInitialize_POPolarityVals
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 16;
	
	  ;% tracking_DW.HILRead1_EncoderBuffer
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% tracking_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% tracking_DW.Integrator1_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% tracking_DW.Integrator2_IWORK.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% tracking_DW.Integrator3_IWORK.IcNeedsLoading
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% tracking_DW.Integrator2_IWORK_g.IcNeedsLoading
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
	  ;% tracking_DW.Integrator3_IWORK_a.IcNeedsLoading
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 4;
	
	  ;% tracking_DW.Integrator1_IWORK_j.IcNeedsLoading
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 5;
	
	  ;% tracking_DW.Integrator1_IWORK_d.IcNeedsLoading
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 6;
	
	  ;% tracking_DW.Integrator1_IWORK_p.IcNeedsLoading
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
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


  targMap.checksum0 = 3950585350;
  targMap.checksum1 = 1257311778;
  targMap.checksum2 = 3748661183;
  targMap.checksum3 = 1862469195;

