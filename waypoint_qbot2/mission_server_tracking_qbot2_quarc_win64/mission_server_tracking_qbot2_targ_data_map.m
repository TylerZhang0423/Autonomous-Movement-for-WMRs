  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
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
    ;% Auto data (mission_server_tracking_qbot2_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_P.ShowMessageonHost_message_icon
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_P.RotateBasisfromUVSOrientationto
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot2_P.ConvertOptitrackorientationfram
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 9;
	
	  ;% mission_server_tracking_qbot2_P.DefaultDummy_Value
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 12;
	
	  ;% mission_server_tracking_qbot2_P.Gain_Gain
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 13;
	
	  ;% mission_server_tracking_qbot2_P.ConvertOptitrackframetoRightHan
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 14;
	
	  ;% mission_server_tracking_qbot2_P.ToggleHigh_Value
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 17;
	
	  ;% mission_server_tracking_qbot2_P.ToggleLow_Value
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 18;
	
	  ;% mission_server_tracking_qbot2_P.DummyData_Value
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 19;
	
	  ;% mission_server_tracking_qbot2_P.Defaultxm_Value
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 20;
	
	  ;% mission_server_tracking_qbot2_P.Waypointsx_Value
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 21;
	
	  ;% mission_server_tracking_qbot2_P.Waypointsz_Value
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 24;
	
	  ;% mission_server_tracking_qbot2_P.Defaultzm_Value
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 27;
	
	  ;% mission_server_tracking_qbot2_P.DummyData31_Value
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 28;
	
	  ;% mission_server_tracking_qbot2_P.DummyData32_Value
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 31;
	
	  ;% mission_server_tracking_qbot2_P.DummyData3_Value
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 34;
	
	  ;% mission_server_tracking_qbot2_P.DummyData_Value_d
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 37;
	
	  ;% mission_server_tracking_qbot2_P.Enable_Value
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_P.StreamServer_SndPriority
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_RcvPriority
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_P.ToHostFile_Decimation
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_SndSize
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_RcvSize
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_SndFIFO
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_RcvFIFO
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_P.StreamServer_Optimize
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_Implementation
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot2_P.ManualSwitch2_CurrentSetting
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_tracking_qbot2_P.ManualSwitch3_CurrentSetting
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% mission_server_tracking_qbot2_P.ToHostFile_file_name
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% mission_server_tracking_qbot2_P.ToHostFile_VarName
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 41;
	
	  ;% mission_server_tracking_qbot2_P.ToHostFile_FileFormat
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 54;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_URI
	  section.data(7).logicalSrcIdx = 33;
	  section.data(7).dtTransOffset = 55;
	
	  ;% mission_server_tracking_qbot2_P.StreamServer_Endian
	  section.data(8).logicalSrcIdx = 34;
	  section.data(8).dtTransOffset = 79;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_P.StreamServer_Active
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
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
    nTotSects     = 4;
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
    ;% Auto data (mission_server_tracking_qbot2_B)
    ;%
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_B.OptiTrackTrackables_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot2_B.OptiTrackTrackables_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% mission_server_tracking_qbot2_B.OptiTrackTrackables_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 7;
	
	  ;% mission_server_tracking_qbot2_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 10;
	
	  ;% mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 13;
	
	  ;% mission_server_tracking_qbot2_B.DataTypeConversion
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 16;
	
	  ;% mission_server_tracking_qbot2_B.ManualSwitch
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 17;
	
	  ;% mission_server_tracking_qbot2_B.DummyData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 18;
	
	  ;% mission_server_tracking_qbot2_B.ManualSwitch2
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 19;
	
	  ;% mission_server_tracking_qbot2_B.ManualSwitch3
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 20;
	
	  ;% mission_server_tracking_qbot2_B.DummyData31
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 21;
	
	  ;% mission_server_tracking_qbot2_B.DummyData32
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 24;
	
	  ;% mission_server_tracking_qbot2_B.DummyData3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 27;
	
	  ;% mission_server_tracking_qbot2_B.DummyData_l
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 30;
	
	  ;% mission_server_tracking_qbot2_B.waypoint_num
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 31;
	
	  ;% mission_server_tracking_qbot2_B.mission_complete
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 32;
	
	  ;% mission_server_tracking_qbot2_B.Angles
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 33;
	
	  ;% mission_server_tracking_qbot2_B.x_ugv_ref
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 36;
	
	  ;% mission_server_tracking_qbot2_B.z_ugv_ref
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_B.StreamServer_o2
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_B.StreamServer_o1
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot2_B.OptiTrackTrackables_o4
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot2_B.StreamServer_o3
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
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
    nTotSects     = 9;
    sectIdxOffset = 4;
    
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
    ;% Auto data (mission_server_tracking_qbot_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.idx
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot_DW.start_stop_prev
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_tracking_qbot_DW.start_stop_start
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.OptiTrackTrackables_Optitrack
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.StreamServer_Stream
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.ToHostFile_PWORK
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.sfEvent
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.ToHostFile_SamplesCount
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot_DW.ToHostFile_ArrayNameLength
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.is_active_c4_mission_server_tra
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_tracking_qbot_DW.is_c4_mission_server_tracking_q
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_tracking_qbot_DW.isStable
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 3210549779;
  targMap.checksum1 = 3016562147;
  targMap.checksum2 = 3355896578;
  targMap.checksum3 = 1640827827;

