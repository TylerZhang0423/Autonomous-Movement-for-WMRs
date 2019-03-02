  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
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
    ;% Auto data (mission_server_waypoint_qball_P)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.QBall2Trajectory_maximum_x
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.QBall2Trajectory_maximum_y
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_waypoint_qball_P.QBall2Trajectory_minimum_x
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% mission_server_waypoint_qball_P.QBall2Trajectory_minimum_y
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.QBall2Trajectory_update_rate
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.ShowMessageonHost_message_icon
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.QBall2Trajectory_trace_mode
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.ConvertOptitrackframetoRightHan
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.Constant2_Value
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 3;
	
	  ;% mission_server_waypoint_qball_P.Constant3_Value
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 8;
	
	  ;% mission_server_waypoint_qball_P.ToggleHigh_Value
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 13;
	
	  ;% mission_server_waypoint_qball_P.ToggleLow_Value
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 14;
	
	  ;% mission_server_waypoint_qball_P.DummyData_Value
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 15;
	
	  ;% mission_server_waypoint_qball_P.RotateBasisfromUVSOrientationto
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 16;
	
	  ;% mission_server_waypoint_qball_P.ConvertOptitrackorientationfram
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 25;
	
	  ;% mission_server_waypoint_qball_P.DefaultDummy_Value
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 28;
	
	  ;% mission_server_waypoint_qball_P.DummyData31_Value
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 29;
	
	  ;% mission_server_waypoint_qball_P.DummyData32_Value
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 32;
	
	  ;% mission_server_waypoint_qball_P.DummyData3_Value
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 35;
	
	  ;% mission_server_waypoint_qball_P.DummyData_Value_n
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 38;
	
	  ;% mission_server_waypoint_qball_P.Enable_Value
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 39;
	
	  ;% mission_server_waypoint_qball_P.TrackingToleranceLeaderm_Value
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.StreamServer_SndPriority
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_RcvPriority
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.ToHostFile_Decimation
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_SndSize
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_RcvSize
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_SndFIFO
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_RcvFIFO
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.StreamServer_Optimize
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_Implementation
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.ManualSwitch1_CurrentSetting
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.ToHostFile_file_name
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_waypoint_qball_P.ToHostFile_VarName
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 39;
	
	  ;% mission_server_waypoint_qball_P.ToHostFile_FileFormat
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 52;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_URI
	  section.data(5).logicalSrcIdx = 35;
	  section.data(5).dtTransOffset = 53;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_Endian
	  section.data(6).logicalSrcIdx = 36;
	  section.data(6).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_P.Memory_X0
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_P.StreamServer_Active
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
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
    nTotSects     = 5;
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
    ;% Auto data (mission_server_waypoint_qball_B)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_B.OptiTrackTrackables_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_B.OptiTrackTrackables_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% mission_server_waypoint_qball_B.OptiTrackTrackables_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 7;
	
	  ;% mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 10;
	
	  ;% mission_server_waypoint_qball_B.Widthx
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 13;
	
	  ;% mission_server_waypoint_qball_B.Constant2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 14;
	
	  ;% mission_server_waypoint_qball_B.Constant3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 19;
	
	  ;% mission_server_waypoint_qball_B.ManualSwitch1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 24;
	
	  ;% mission_server_waypoint_qball_B.DataTypeConversion
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 25;
	
	  ;% mission_server_waypoint_qball_B.DummyData
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 26;
	
	  ;% mission_server_waypoint_qball_B.DummyData31
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 27;
	
	  ;% mission_server_waypoint_qball_B.DummyData32
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 30;
	
	  ;% mission_server_waypoint_qball_B.DummyData3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 33;
	
	  ;% mission_server_waypoint_qball_B.DummyData_i
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 36;
	
	  ;% mission_server_waypoint_qball_B.Widthz
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 37;
	
	  ;% mission_server_waypoint_qball_B.Sqrt
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 38;
	
	  ;% mission_server_waypoint_qball_B.idx
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 39;
	
	  ;% mission_server_waypoint_qball_B.done
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 40;
	
	  ;% mission_server_waypoint_qball_B.x_ref
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 41;
	
	  ;% mission_server_waypoint_qball_B.z_ref
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 42;
	
	  ;% mission_server_waypoint_qball_B.last_waypoint
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 43;
	
	  ;% mission_server_waypoint_qball_B.Angles
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 44;
	
	  ;% mission_server_waypoint_qball_B.qball_takeoff
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 47;
	
	  ;% mission_server_waypoint_qball_B.x_quad_ref
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 48;
	
	  ;% mission_server_waypoint_qball_B.z_quad_ref
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 49;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_B.StreamServer_o2
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_B.tick
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_B.StreamServer_o1
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qball_B.OptiTrackTrackables_o4
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qball_B.Memory
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_waypoint_qball_B.StreamServer_o3
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    nTotSects     = 12;
    sectIdxOffset = 5;
    
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
    ;% Auto data (mission_server_waypoint_qbal_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.QBall2Trajectory_XBuffer
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qbal_DW.QBall2Trajectory_YBuffer
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1000;
	
	  ;% mission_server_waypoint_qbal_DW.start_stop_prev
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2000;
	
	  ;% mission_server_waypoint_qbal_DW.start_stop_start
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 2001;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.OptiTrackTrackables_Optitrack
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.ToHostFile_PointsWritten
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.StreamServer_Stream
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.OptiTrackxyz_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qbal_DW.ToHostFile_PWORK
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.sfEvent
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qbal_DW.sfEvent_g
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.ToHostFile_SamplesCount
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qbal_DW.ToHostFile_ArrayNameLength
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_waypoint_qbal_DW.presentTicks
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
	  ;% mission_server_waypoint_qbal_DW.elapsedTicks
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 3;
	
	  ;% mission_server_waypoint_qbal_DW.previousTicks
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.QBall2Trajectory_IWORK
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.ChartSchedulerLogic_SubsysRanBC
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.is_active_c3_mission_server_way
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qbal_DW.is_c3_mission_server_waypoint_q
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_waypoint_qbal_DW.is_active_c1_mission_server_way
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% mission_server_waypoint_qbal_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% mission_server_waypoint_qbal_DW.QBall2Trajectory_IsFull
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% mission_server_waypoint_qbal_DW.isStable
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% mission_server_waypoint_qbal_DW.isStable_e
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
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


  targMap.checksum0 = 2645695073;
  targMap.checksum1 = 3961551629;
  targMap.checksum2 = 2463350884;
  targMap.checksum3 = 364762844;

