  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (AZ5forceCntrl_P)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_P.PacketOutput1_MaxMissedTicks
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_P.PacketInput1_MaxMissedTicks
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AZ5forceCntrl_P.PacketOutput1_YieldWhenWaiting
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AZ5forceCntrl_P.PacketInput1_YieldWhenWaiting
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_P.PacketOutput1_PacketID
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_P.PacketInput1_PacketID
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_P.Saturation3_UpperSat
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_P.Saturation3_LowerSat
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AZ5forceCntrl_P.Saturation1_UpperSat
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AZ5forceCntrl_P.Saturation1_LowerSat
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AZ5forceCntrl_P.orsel_Value
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AZ5forceCntrl_P.Switch1_Threshold
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AZ5forceCntrl_P.Saturation_UpperSat
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AZ5forceCntrl_P.Saturation_LowerSat
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AZ5forceCntrl_P.Saturation_UpperSat_h
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AZ5forceCntrl_P.Saturation_LowerSat_h
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% AZ5forceCntrl_P.c4_Value
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% AZ5forceCntrl_P.c5_Value
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% AZ5forceCntrl_P.zero1_Value
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% AZ5forceCntrl_P.u05kg5s50_Amp
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% AZ5forceCntrl_P.u05kg5s50_Period
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% AZ5forceCntrl_P.u05kg5s50_Duty
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% AZ5forceCntrl_P.u05kg5s50_PhaseDelay
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
	  ;% AZ5forceCntrl_P.TransferFcn_A
	  section.data(18).logicalSrcIdx = 25;
	  section.data(18).dtTransOffset = 17;
	
	  ;% AZ5forceCntrl_P.TransferFcn_C
	  section.data(19).logicalSrcIdx = 26;
	  section.data(19).dtTransOffset = 18;
	
	  ;% AZ5forceCntrl_P.select_Value
	  section.data(20).logicalSrcIdx = 27;
	  section.data(20).dtTransOffset = 19;
	
	  ;% AZ5forceCntrl_P.Constant13_Value
	  section.data(21).logicalSrcIdx = 28;
	  section.data(21).dtTransOffset = 20;
	
	  ;% AZ5forceCntrl_P.Vref_Value
	  section.data(22).logicalSrcIdx = 29;
	  section.data(22).dtTransOffset = 21;
	
	  ;% AZ5forceCntrl_P.Constant17_Value
	  section.data(23).logicalSrcIdx = 30;
	  section.data(23).dtTransOffset = 22;
	
	  ;% AZ5forceCntrl_P.Constant20_Value
	  section.data(24).logicalSrcIdx = 31;
	  section.data(24).dtTransOffset = 23;
	
	  ;% AZ5forceCntrl_P.Switch_Threshold
	  section.data(25).logicalSrcIdx = 32;
	  section.data(25).dtTransOffset = 24;
	
	  ;% AZ5forceCntrl_P.zero2_Value
	  section.data(26).logicalSrcIdx = 33;
	  section.data(26).dtTransOffset = 25;
	
	  ;% AZ5forceCntrl_P.TransferFcn1_A
	  section.data(27).logicalSrcIdx = 34;
	  section.data(27).dtTransOffset = 26;
	
	  ;% AZ5forceCntrl_P.TransferFcn1_C
	  section.data(28).logicalSrcIdx = 35;
	  section.data(28).dtTransOffset = 27;
	
	  ;% AZ5forceCntrl_P.Gain1_Gain
	  section.data(29).logicalSrcIdx = 36;
	  section.data(29).dtTransOffset = 28;
	
	  ;% AZ5forceCntrl_P.zero_Value
	  section.data(30).logicalSrcIdx = 37;
	  section.data(30).dtTransOffset = 29;
	
	  ;% AZ5forceCntrl_P.u90_UpperSat
	  section.data(31).logicalSrcIdx = 38;
	  section.data(31).dtTransOffset = 30;
	
	  ;% AZ5forceCntrl_P.u90_LowerSat
	  section.data(32).logicalSrcIdx = 39;
	  section.data(32).dtTransOffset = 31;
	
	  ;% AZ5forceCntrl_P.Analog1_Value
	  section.data(33).logicalSrcIdx = 40;
	  section.data(33).dtTransOffset = 32;
	
	  ;% AZ5forceCntrl_P.Analog1_Value_j
	  section.data(34).logicalSrcIdx = 41;
	  section.data(34).dtTransOffset = 33;
	
	  ;% AZ5forceCntrl_P.Analog2_Value
	  section.data(35).logicalSrcIdx = 42;
	  section.data(35).dtTransOffset = 34;
	
	  ;% AZ5forceCntrl_P.Analog3_Value
	  section.data(36).logicalSrcIdx = 43;
	  section.data(36).dtTransOffset = 35;
	
	  ;% AZ5forceCntrl_P.f_Value
	  section.data(37).logicalSrcIdx = 44;
	  section.data(37).dtTransOffset = 36;
	
	  ;% AZ5forceCntrl_P.Saturation1_UpperSat_k
	  section.data(38).logicalSrcIdx = 45;
	  section.data(38).dtTransOffset = 37;
	
	  ;% AZ5forceCntrl_P.Saturation1_LowerSat_g
	  section.data(39).logicalSrcIdx = 46;
	  section.data(39).dtTransOffset = 38;
	
	  ;% AZ5forceCntrl_P.Constant11_Value
	  section.data(40).logicalSrcIdx = 47;
	  section.data(40).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_P.Constant10_Value
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_P.Constant11_Value_a
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AZ5forceCntrl_P.Saturation_UpperSat_o
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AZ5forceCntrl_P.Saturation_LowerSat_n
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_P.en1_Value
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_P.en2_Value
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AZ5forceCntrl_P.ARR_S_Value
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AZ5forceCntrl_P.en3_Value
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AZ5forceCntrl_P.en_Value
	  section.data(5).logicalSrcIdx = 56;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AZ5forceCntrl_P.CH_Value
	  section.data(6).logicalSrcIdx = 57;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AZ5forceCntrl_P.Constant21_Value
	  section.data(7).logicalSrcIdx = 58;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AZ5forceCntrl_P.ManualSwitch_CurrentSetting
	  section.data(8).logicalSrcIdx = 59;
	  section.data(8).dtTransOffset = 7;
	
	  ;% AZ5forceCntrl_P.Switch2_Threshold
	  section.data(9).logicalSrcIdx = 60;
	  section.data(9).dtTransOffset = 8;
	
	  ;% AZ5forceCntrl_P.Switch1_Threshold_j
	  section.data(10).logicalSrcIdx = 61;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    nTotSects     = 2;
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
    ;% Auto data (AZ5forceCntrl_B)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_B.u05kg5s50
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_B.Sum3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AZ5forceCntrl_B.TransferFcn
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% AZ5forceCntrl_B.Sum4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% AZ5forceCntrl_B.Sum1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% AZ5forceCntrl_B.u90
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% AZ5forceCntrl_B.Switch2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% AZ5forceCntrl_B.RoundingFunction
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_B.Add
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_B.PacketInput1
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% AZ5forceCntrl_B.IndexVector
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 34;
	
	  ;% AZ5forceCntrl_B.IndexVector1
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 35;
	
	  ;% AZ5forceCntrl_B.DataTypeConversion
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 36;
	
	  ;% AZ5forceCntrl_B.DataTypeConversion1
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 37;
	
	  ;% AZ5forceCntrl_B.DataTypeConversion_f
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 38;
	
	  ;% AZ5forceCntrl_B.DataTypeConversion1_l
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 2;
    sectIdxOffset = 2;
    
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
    ;% Auto data (AZ5forceCntrl_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_DW.PacketOutput1_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% AZ5forceCntrl_DW.PacketInput1_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% AZ5forceCntrl_DW.u0s005015_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% AZ5forceCntrl_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
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


  targMap.checksum0 = 3544583764;
  targMap.checksum1 = 3175780881;
  targMap.checksum2 = 961125186;
  targMap.checksum3 = 4042304875;

