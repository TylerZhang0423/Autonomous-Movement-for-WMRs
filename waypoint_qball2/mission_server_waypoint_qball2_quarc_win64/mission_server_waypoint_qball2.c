/*
 * mission_server_waypoint_qball2.c
 *
 * Code generation for model "mission_server_waypoint_qball2".
 *
 * Model version              : 1.381
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 19:37:12 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "mission_server_waypoint_qball2.h"
#include "mission_server_waypoint_qball2_private.h"
#include "mission_server_waypoint_qball2_dt.h"

/* Named constants for Chart: '<S1>/Logic Chart' */
#define mission__IN_WaitForStartCommand ((uint8_T)4U)
#define mission_s_IN_QballGetsWaypoints ((uint8_T)2U)
#define mission_serv_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define mission_server__MIN_QUAD_HEIGHT (0.5)
#define mission_server_waypo_CALL_EVENT (-1)
#define mission_server_waypo_IN_Landing ((uint8_T)1U)
#define mission_server_waypo_IN_Takeoff ((uint8_T)3U)

/* Named constants for Chart: '<S5>/Chart - Scheduler Logic' */
#define mission_serv_IN_Increment_Index ((uint8_T)1U)
#define mission_server_way_IN_Issue_CMD ((uint8_T)3U)
#define mission_server_waypo_event_tick (0)
#define mission_server_waypoint_IN_Init ((uint8_T)2U)

/* Block signals (auto storage) */
B_mission_server_waypoint_qba_T mission_server_waypoint_qball_B;

/* Block states (auto storage) */
DW_mission_server_waypoint_qb_T mission_server_waypoint_qbal_DW;

/* Real-time model */
RT_MODEL_mission_server_waypo_T mission_server_waypoint_qbal_M_;
RT_MODEL_mission_server_waypo_T *const mission_server_waypoint_qbal_M =
  &mission_server_waypoint_qbal_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void mission_server_waypoint_qball2_step(void)
{
  /* local block i/o variables */
  real_T rtb_TmpSignalConversionAtStream[10];
  boolean_T rtb_RelationalOperator_h;
  real_T sRoll;
  real_T cRoll;
  real_T sPitch;
  real_T cPitch;
  real_T sYaw;
  real_T cYaw;
  real_T rtb_Product[3];
  int32_T i;
  real_T rtb_R_idx_0;
  real_T rtb_R_idx_2;
  real_T rtb_R_idx_5;
  real_T rtb_R_idx_8;

  /* Reset subsysRan breadcrumbs */
  srClearBC(mission_server_waypoint_qbal_DW.ChartSchedulerLogic_SubsysRanBC);

  /* S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */

  /* S-Function Block: mission_server_waypoint_qball2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result = 0;
    result = optitrack_rb_get_position
      (mission_server_waypoint_qbal_DW.OptiTrackTrackables_Optitrack,
       &mission_server_waypoint_qball_B.OptiTrackTrackables_o1[0],
       &mission_server_waypoint_qball_B.OptiTrackTrackables_o2[0],
       &mission_server_waypoint_qball_B.OptiTrackTrackables_o3[0], (t_boolean *)
       &mission_server_waypoint_qball_B.OptiTrackTrackables_o4);
    if ((result < 0) && (result != -QERR_WOULD_BLOCK)) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_waypoint_qbal_M, _rt_error_message);
    }
  }

  /* Gain: '<S7>/Convert Optitrack frame to Right-Hand Convention' */
  mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[0] =
    mission_server_waypoint_qball_P.ConvertOptitrackframetoRightHan[0] *
    mission_server_waypoint_qball_B.OptiTrackTrackables_o1[0];
  mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[1] =
    mission_server_waypoint_qball_P.ConvertOptitrackframetoRightHan[1] *
    mission_server_waypoint_qball_B.OptiTrackTrackables_o1[1];
  mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[2] =
    mission_server_waypoint_qball_P.ConvertOptitrackframetoRightHan[2] *
    mission_server_waypoint_qball_B.OptiTrackTrackables_o1[2];

  /* Memory: '<S5>/Memory' */
  mission_server_waypoint_qball_B.Memory =
    mission_server_waypoint_qbal_DW.Memory_PreviousInput;
  for (i = 0; i < 5; i++) {
    /* Constant: '<Root>/Constant2' */
    mission_server_waypoint_qball_B.Constant2[i] =
      mission_server_waypoint_qball_P.Constant2_Value[i];

    /* Constant: '<Root>/Constant3' */
    mission_server_waypoint_qball_B.Constant3[i] =
      mission_server_waypoint_qball_P.Constant3_Value[i];
  }

  /* S-Function (fcncallgen): '<S5>/Function-Call Generator (Clock Ticks)' incorporates:
   *  Chart: '<S5>/Chart - Scheduler Logic'
   */
  /* S-Function (fcncallgen): '<S5>/Function-Call Generator (Clock Ticks)' incorporates:
   *  Chart: '<S5>/Chart - Scheduler Logic'
   *  TriggerPort: '<S15>/tick'
   */
  /* Chart: '<S5>/Chart - Scheduler Logic' */
  mission_server_waypoint_qball_B.tick = 2;
  mission_server_waypoint_qbal_DW.presentTicks =
    mission_server_waypoint_qbal_M->Timing.clockTick0;
  mission_server_waypoint_qbal_DW.elapsedTicks =
    mission_server_waypoint_qbal_DW.presentTicks -
    mission_server_waypoint_qbal_DW.previousTicks;
  mission_server_waypoint_qbal_DW.previousTicks =
    mission_server_waypoint_qbal_DW.presentTicks;
  if (mission_server_waypoint_qbal_DW.temporalCounter_i1 +
      mission_server_waypoint_qbal_DW.elapsedTicks <= 511U) {
    mission_server_waypoint_qbal_DW.temporalCounter_i1 = (uint16_T)
      (mission_server_waypoint_qbal_DW.temporalCounter_i1 +
       mission_server_waypoint_qbal_DW.elapsedTicks);
  } else {
    mission_server_waypoint_qbal_DW.temporalCounter_i1 = 511U;
  }

  /* Gateway: Waypoint Scheduler/Chart - Scheduler Logic */
  /* Event: '<S15>:3' */
  mission_server_waypoint_qbal_DW.sfEvent = mission_server_waypo_event_tick;

  /* During: Waypoint Scheduler/Chart - Scheduler Logic */
  if (mission_server_waypoint_qbal_DW.is_active_c3_mission_server_way == 0U) {
    /* Entry: Waypoint Scheduler/Chart - Scheduler Logic */
    mission_server_waypoint_qbal_DW.is_active_c3_mission_server_way = 1U;

    /* Entry Internal: Waypoint Scheduler/Chart - Scheduler Logic */
    /* Transition: '<S15>:5' */
    mission_server_waypoint_qbal_DW.is_c3_mission_server_waypoint_q =
      mission_server_waypoint_IN_Init;

    /* Entry 'Init': '<S15>:1' */
    mission_server_waypoint_qball_B.done = 0.0;
    mission_server_waypoint_qball_B.idx = 1.0;
    mission_server_waypoint_qball_B.last_waypoint = 0.0;
    mission_server_waypoint_qball_B.x_ref =
      mission_server_waypoint_qball_B.Constant2[(int32_T)
      mission_server_waypoint_qball_B.idx - 1];
    mission_server_waypoint_qball_B.z_ref =
      mission_server_waypoint_qball_B.Constant3[(int32_T)
      mission_server_waypoint_qball_B.idx - 1];
  } else {
    switch (mission_server_waypoint_qbal_DW.is_c3_mission_server_waypoint_q) {
     case mission_serv_IN_Increment_Index:
      /* During 'Increment_Index': '<S15>:8' */
      /* Transition: '<S15>:10' */
      mission_server_waypoint_qbal_DW.is_c3_mission_server_waypoint_q =
        mission_server_way_IN_Issue_CMD;
      mission_server_waypoint_qbal_DW.temporalCounter_i1 = 0U;

      /* Entry 'Issue_CMD': '<S15>:6' */
      if (mission_server_waypoint_qball_B.idx ==
          mission_server_waypoint_qball_B.Widthx) {
        mission_server_waypoint_qball_B.last_waypoint = 1.0;
      }
      break;

     case mission_server_waypoint_IN_Init:
      /* During 'Init': '<S15>:1' */
      /* Transition: '<S15>:7' */
      mission_server_waypoint_qbal_DW.is_c3_mission_server_waypoint_q =
        mission_server_way_IN_Issue_CMD;
      mission_server_waypoint_qbal_DW.temporalCounter_i1 = 0U;

      /* Entry 'Issue_CMD': '<S15>:6' */
      if (mission_server_waypoint_qball_B.idx ==
          mission_server_waypoint_qball_B.Widthx) {
        mission_server_waypoint_qball_B.last_waypoint = 1.0;
      }
      break;

     default:
      /* During 'Issue_CMD': '<S15>:6' */
      if ((mission_server_waypoint_qbal_DW.temporalCounter_i1 >= 500U) &&
          (mission_server_waypoint_qball_B.Memory == 1)) {
        /* Transition: '<S15>:9' */
        mission_server_waypoint_qbal_DW.is_c3_mission_server_waypoint_q =
          mission_serv_IN_Increment_Index;

        /* Entry 'Increment_Index': '<S15>:8' */
        if (mission_server_waypoint_qball_B.idx ==
            mission_server_waypoint_qball_B.Widthx) {
          mission_server_waypoint_qball_B.done = 1.0;
        } else {
          mission_server_waypoint_qball_B.idx++;
        }
      } else {
        mission_server_waypoint_qball_B.x_ref =
          mission_server_waypoint_qball_B.Constant2[(int32_T)
          mission_server_waypoint_qball_B.idx - 1];
        mission_server_waypoint_qball_B.z_ref =
          mission_server_waypoint_qball_B.Constant3[(int32_T)
          mission_server_waypoint_qball_B.idx - 1];
      }
      break;
    }
  }

  mission_server_waypoint_qbal_DW.ChartSchedulerLogic_SubsysRanBC = 4;

  /* End of Chart: '<S5>/Chart - Scheduler Logic' */

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Toggle High'
   *  Constant: '<Root>/Toggle Low'
   */
  if (mission_server_waypoint_qball_P.ManualSwitch1_CurrentSetting == 1) {
    mission_server_waypoint_qball_B.ManualSwitch1 =
      mission_server_waypoint_qball_P.ToggleHigh_Value;
  } else {
    mission_server_waypoint_qball_B.ManualSwitch1 =
      mission_server_waypoint_qball_P.ToggleLow_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Chart: '<S1>/Logic Chart' */
  /* Gateway: Logic Subsystem/Logic Chart */
  mission_server_waypoint_qbal_DW.sfEvent_g = mission_server_waypo_CALL_EVENT;
  mission_server_waypoint_qbal_DW.start_stop_prev =
    mission_server_waypoint_qbal_DW.start_stop_start;
  mission_server_waypoint_qbal_DW.start_stop_start =
    mission_server_waypoint_qball_B.ManualSwitch1;

  /* During: Logic Subsystem/Logic Chart */
  if (mission_server_waypoint_qbal_DW.is_active_c1_mission_server_way == 0U) {
    mission_server_waypoint_qbal_DW.start_stop_prev =
      mission_server_waypoint_qball_B.ManualSwitch1;

    /* Entry: Logic Subsystem/Logic Chart */
    mission_server_waypoint_qbal_DW.is_active_c1_mission_server_way = 1U;

    /* Entry Internal: Logic Subsystem/Logic Chart */
    /* Transition: '<S6>:2' */
    mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q =
      mission__IN_WaitForStartCommand;
  } else {
    switch (mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q) {
     case mission_server_waypo_IN_Landing:
      /* During 'Landing': '<S6>:34' */
      break;

     case mission_s_IN_QballGetsWaypoints:
      /* During 'QballGetsWaypoints': '<S6>:22' */
      if (mission_server_waypoint_qbal_DW.start_stop_prev !=
          mission_server_waypoint_qbal_DW.start_stop_start) {
        /* Transition: '<S6>:29' */
        mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q =
          mission_server_waypo_IN_Landing;

        /* Entry 'Landing': '<S6>:34' */
        mission_server_waypoint_qball_B.qball_takeoff = 0.0;
        mission_server_waypoint_qball_B.x_quad_ref =
          mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[0];
        mission_server_waypoint_qball_B.z_quad_ref =
          mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[2];
      } else {
        mission_server_waypoint_qball_B.x_quad_ref =
          mission_server_waypoint_qball_B.x_ref;
        mission_server_waypoint_qball_B.z_quad_ref =
          mission_server_waypoint_qball_B.z_ref;
      }
      break;

     case mission_server_waypo_IN_Takeoff:
      /* During 'Takeoff': '<S6>:18' */
      if (mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[1] >=
          mission_server__MIN_QUAD_HEIGHT) {
        /* Transition: '<S6>:24' */
        mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q =
          mission_s_IN_QballGetsWaypoints;
      } else {
        if (mission_server_waypoint_qbal_DW.start_stop_prev !=
            mission_server_waypoint_qbal_DW.start_stop_start) {
          /* Transition: '<S6>:31' */
          mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q =
            mission_server_waypo_IN_Landing;

          /* Entry 'Landing': '<S6>:34' */
          mission_server_waypoint_qball_B.qball_takeoff = 0.0;
          mission_server_waypoint_qball_B.x_quad_ref =
            mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[0];
          mission_server_waypoint_qball_B.z_quad_ref =
            mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[2];
        }
      }
      break;

     default:
      /* During 'WaitForStartCommand': '<S6>:1' */
      if (mission_server_waypoint_qbal_DW.start_stop_prev !=
          mission_server_waypoint_qbal_DW.start_stop_start) {
        /* Transition: '<S6>:19' */
        mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q =
          mission_server_waypo_IN_Takeoff;

        /* Entry 'Takeoff': '<S6>:18' */
        mission_server_waypoint_qball_B.qball_takeoff = 1.0;
      } else {
        mission_server_waypoint_qball_B.qball_takeoff = 0.0;
        mission_server_waypoint_qball_B.x_quad_ref =
          mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[0];
        mission_server_waypoint_qball_B.z_quad_ref =
          mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[2];
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Logic Chart' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  mission_server_waypoint_qball_B.DataTypeConversion =
    mission_server_waypoint_qball_B.OptiTrackTrackables_o4;

  /* Constant: '<S13>/Dummy Data' */
  mission_server_waypoint_qball_B.DummyData =
    mission_server_waypoint_qball_P.DummyData_Value;

  /* Gain: '<S7>/Convert Optitrack orientation frame to Right-Hand Convention' incorporates:
   *  Product: '<S7>/Product'
   */
  rtb_R_idx_8 = mission_server_waypoint_qball_P.ConvertOptitrackorientationfram
    [0] * mission_server_waypoint_qball_B.OptiTrackTrackables_o3[0];
  sPitch = mission_server_waypoint_qball_P.ConvertOptitrackorientationfram[1] *
    mission_server_waypoint_qball_B.OptiTrackTrackables_o3[1];
  cPitch = mission_server_waypoint_qball_P.ConvertOptitrackorientationfram[2] *
    mission_server_waypoint_qball_B.OptiTrackTrackables_o3[2];

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Rotate Basis from UVS Orientation to Global Frame'
   *  Math: '<S7>/Inverse of Orthonormal Matrix is its Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product[i] =
      mission_server_waypoint_qball_P.RotateBasisfromUVSOrientationto[3 * i + 2]
      * cPitch +
      (mission_server_waypoint_qball_P.RotateBasisfromUVSOrientationto[3 * i + 1]
       * sPitch +
       mission_server_waypoint_qball_P.RotateBasisfromUVSOrientationto[3 * i] *
       rtb_R_idx_8);
  }

  /* MATLAB Function: '<S9>/RotationMatrix_from_EulerAngles_yzx' */
  /* MATLAB Function 'RotationMatrix_from_EulerAngles_YZX/RotationMatrix_from_EulerAngles_yzx': '<S11>:1' */
  /*  Create rotation matrix from Euler (Y,Z, X) convention. */
  /* '<S11>:1:6' */
  sRoll = sin(rtb_Product[0]);

  /* '<S11>:1:7' */
  cRoll = cos(rtb_Product[0]);

  /* '<S11>:1:8' */
  sPitch = sin(rtb_Product[1]);

  /* '<S11>:1:9' */
  cPitch = cos(rtb_Product[1]);

  /* '<S11>:1:10' */
  sYaw = sin(rtb_Product[2]);

  /* '<S11>:1:11' */
  cYaw = cos(rtb_Product[2]);

  /* '<S11>:1:13' */
  /* '<S11>:1:15' */
  /* '<S11>:1:17' */
  /* '<S11>:1:18' */
  /* '<S11>:1:19' */
  /* '<S11>:1:21' */
  /* '<S11>:1:22' */
  /* '<S11>:1:23' */
  /* '<S11>:1:25' */
  rtb_R_idx_0 = cPitch * cYaw;
  rtb_R_idx_2 = -sPitch * cYaw;
  rtb_R_idx_5 = cRoll * sPitch * sYaw + sRoll * cPitch;
  rtb_R_idx_8 = -sRoll * sPitch * sYaw + cRoll * cPitch;

  /* MATLAB Function: '<S8>/EulerAngles_zyx_from_RotationMatrix' incorporates:
   *  Constant: '<S7>/Default Dummy'
   *  MATLAB Function: '<S9>/RotationMatrix_from_EulerAngles_yzx'
   */
  /* MATLAB Function 'EulerAngles_ZYX_from_RotationMatrix/EulerAngles_zyx_from_RotationMatrix': '<S10>:1' */
  /*  Extract the Euler angles (Z-Y-X) from rotatin matrix */
  /*  Assumption:  */
  /*  The rotation matrix is defined as: */
  /*  */
  /*  r0 = R . r1 */
  /*  */
  /*  where r1 is a vector expressed in the rotated frame */
  /*    r0 is the vector expressed in the reference frame */
  /*  Setting the singularity tolerance */
  /* '<S10>:1:14' */
  /*  Extract Euler angles from the rotation matrix */
  /* '<S10>:1:17' */
  sRoll = asin(rtb_R_idx_2);
  if (1.0 - fabs(rtb_R_idx_2) > 2.2204460492503131E-16) {
    /* '<S10>:1:18' */
    /*  Not at Euler singularity */
    /* '<S10>:1:20' */
    /* '<S10>:1:21' */
    cPitch = rt_atan2d_snf(rtb_R_idx_5, rtb_R_idx_8);

    /* '<S10>:1:22' */
    sPitch = rt_atan2d_snf(sYaw, rtb_R_idx_0);
  } else {
    /*  At Euler singularity */
    /* '<S10>:1:25' */
    /*  Roll and Yaw are ambiguous. */
    /*  Use the optional angular measurement to resolve the ambiguity */
    /* '<S10>:1:29' */
    cRoll = acos(cRoll * cYaw);
    if (-sRoll > 0.0) {
      /* '<S10>:1:31' */
      /*  pitch is +pi/2 */
      /*  RollYaw = Roll + Yaw */
      /*  Therefore, */
      /*  Roll = RollYaw - Yaw */
      /*  Or  */
      /*  Yaw = RollYaw - Roll */
      if (mission_server_waypoint_qball_P.DefaultDummy_Value != 0.0) {
        /* '<S10>:1:38' */
        /*  Roll Aux measurement available */
        /* '<S10>:1:39' */
        cPitch = mission_server_waypoint_qball_P.DefaultDummy_Value;

        /* '<S10>:1:40' */
        sPitch = cRoll - mission_server_waypoint_qball_P.DefaultDummy_Value;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S10>:1:42' */
        sPitch = mission_server_waypoint_qball_P.DefaultDummy_Value;

        /* '<S10>:1:43' */
        cPitch = cRoll - mission_server_waypoint_qball_P.DefaultDummy_Value;
      }
    } else {
      /*  pitch is -pi/2 */
      /*  RollYaw = Roll - Yaw */
      /*  Therefore, */
      /*  Roll = RollYaw + Yaw */
      /*  Or */
      /*  Yaw = -RollYaw + Roll */
      if (mission_server_waypoint_qball_P.DefaultDummy_Value != 0.0) {
        /* '<S10>:1:52' */
        /*  Roll Aux measurement available */
        /* '<S10>:1:53' */
        cPitch = mission_server_waypoint_qball_P.DefaultDummy_Value;

        /* '<S10>:1:54' */
        sPitch = -cRoll + mission_server_waypoint_qball_P.DefaultDummy_Value;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S10>:1:56' */
        sPitch = mission_server_waypoint_qball_P.DefaultDummy_Value;

        /* '<S10>:1:57' */
        cPitch = cRoll + mission_server_waypoint_qball_P.DefaultDummy_Value;
      }
    }
  }

  /* '<S10>:1:62' */
  mission_server_waypoint_qball_B.Angles[0] = cPitch;
  mission_server_waypoint_qball_B.Angles[1] = -sRoll;
  mission_server_waypoint_qball_B.Angles[2] = sPitch;

  /* End of MATLAB Function: '<S8>/EulerAngles_zyx_from_RotationMatrix' */

  /* Constant: '<S12>/Dummy Data [3]1' */
  mission_server_waypoint_qball_B.DummyData31[0] =
    mission_server_waypoint_qball_P.DummyData31_Value[0];
  mission_server_waypoint_qball_B.DummyData31[1] =
    mission_server_waypoint_qball_P.DummyData31_Value[1];
  mission_server_waypoint_qball_B.DummyData31[2] =
    mission_server_waypoint_qball_P.DummyData31_Value[2];

  /* Constant: '<S12>/Dummy Data [3]2' */
  mission_server_waypoint_qball_B.DummyData32[0] =
    mission_server_waypoint_qball_P.DummyData32_Value[0];
  mission_server_waypoint_qball_B.DummyData32[1] =
    mission_server_waypoint_qball_P.DummyData32_Value[1];
  mission_server_waypoint_qball_B.DummyData32[2] =
    mission_server_waypoint_qball_P.DummyData32_Value[2];

  /* Constant: '<S12>/Dummy Data [3]' */
  mission_server_waypoint_qball_B.DummyData3[0] =
    mission_server_waypoint_qball_P.DummyData3_Value[0];
  mission_server_waypoint_qball_B.DummyData3[1] =
    mission_server_waypoint_qball_P.DummyData3_Value[1];
  mission_server_waypoint_qball_B.DummyData3[2] =
    mission_server_waypoint_qball_P.DummyData3_Value[2];

  /* Constant: '<S12>/Dummy Data' */
  mission_server_waypoint_qball_B.DummyData_i =
    mission_server_waypoint_qball_P.DummyData_Value_n;

  /* SignalConversion: '<S4>/TmpSignal ConversionAtStream ServerInport1' */
  rtb_TmpSignalConversionAtStream[0] =
    mission_server_waypoint_qball_B.x_quad_ref;
  rtb_TmpSignalConversionAtStream[1] =
    mission_server_waypoint_qball_B.qball_takeoff;
  rtb_TmpSignalConversionAtStream[2] =
    mission_server_waypoint_qball_B.z_quad_ref;
  rtb_TmpSignalConversionAtStream[3] =
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[0];
  rtb_TmpSignalConversionAtStream[4] =
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[1];
  rtb_TmpSignalConversionAtStream[5] =
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[2];
  rtb_TmpSignalConversionAtStream[6] =
    mission_server_waypoint_qball_B.DataTypeConversion;
  rtb_TmpSignalConversionAtStream[7] = mission_server_waypoint_qball_B.Angles[0];
  rtb_TmpSignalConversionAtStream[8] = mission_server_waypoint_qball_B.Angles[1];
  rtb_TmpSignalConversionAtStream[9] = mission_server_waypoint_qball_B.Angles[2];

  /* S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_waypoint_qball2/Serve Data for Qball 2/Stream Server (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    if (mission_server_waypoint_qball_P.Enable_Value) {
      send_result = pstream_send
        (mission_server_waypoint_qbal_DW.StreamServer_Stream,
         &rtb_TmpSignalConversionAtStream[0]);
    } else {
      send_result = 0;
    }

    mission_server_waypoint_qball_B.StreamServer_o3 = (send_result > 0);
    mission_server_waypoint_qball_B.StreamServer_o2 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      mission_server_waypoint_qball_B.StreamServer_o2 = send_result;
    }

    pstream_get_state(mission_server_waypoint_qbal_DW.StreamServer_Stream,
                      &state);
    mission_server_waypoint_qball_B.StreamServer_o1 = state;
  }

  /* RelationalOperator: '<S5>/Relational Operator' */
  rtb_RelationalOperator_h = (mission_server_waypoint_qball_B.Widthx !=
    mission_server_waypoint_qball_B.Widthz);

  /* S-Function (stop_with_error_block): '<S5>/Stop with Error' */

  /* S-Function Block: mission_server_waypoint_qball2/Waypoint Scheduler/Stop with Error (stop_with_error_block) */
  {
    if (rtb_RelationalOperator_h) {
      rtmSetErrorStatus(mission_server_waypoint_qbal_M,
                        "Error: Number of x and z waypoints not equal!");
      return;
    }
  }

  /* Sum: '<S17>/Sum' */
  rtb_R_idx_8 = mission_server_waypoint_qball_B.x_ref -
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[0];
  sPitch = mission_server_waypoint_qball_B.z_ref -
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[2];

  /* Sqrt: '<S17>/Sqrt' incorporates:
   *  DotProduct: '<S17>/Dot Product'
   */
  mission_server_waypoint_qball_B.Sqrt = sqrt(rtb_R_idx_8 * rtb_R_idx_8 + sPitch
    * sPitch);

  /* Update for Memory: '<S5>/Memory' incorporates:
   *  Constant: '<S5>/Tracking Tolerance - Leader (m)'
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  mission_server_waypoint_qbal_DW.Memory_PreviousInput =
    (mission_server_waypoint_qball_B.Sqrt <=
     mission_server_waypoint_qball_P.TrackingToleranceLeaderm_Value);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, mission_server_waypoint_qbal_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(mission_server_waypoint_qbal_M)!=-1) &&
        !((rtmGetTFinal(mission_server_waypoint_qbal_M)-
           mission_server_waypoint_qbal_M->Timing.taskTime0) >
          mission_server_waypoint_qbal_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(mission_server_waypoint_qbal_M, "Simulation finished");
    }

    if (rtmGetStopRequested(mission_server_waypoint_qbal_M)) {
      rtmSetErrorStatus(mission_server_waypoint_qbal_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++mission_server_waypoint_qbal_M->Timing.clockTick0)) {
    ++mission_server_waypoint_qbal_M->Timing.clockTickH0;
  }

  mission_server_waypoint_qbal_M->Timing.taskTime0 =
    mission_server_waypoint_qbal_M->Timing.clockTick0 *
    mission_server_waypoint_qbal_M->Timing.stepSize0 +
    mission_server_waypoint_qbal_M->Timing.clockTickH0 *
    mission_server_waypoint_qbal_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void mission_server_waypoint_qball2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mission_server_waypoint_qbal_M, 0,
                sizeof(RT_MODEL_mission_server_waypo_T));
  rtmSetTFinal(mission_server_waypoint_qbal_M, -1);
  mission_server_waypoint_qbal_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  mission_server_waypoint_qbal_M->Sizes.checksums[0] = (2645695073U);
  mission_server_waypoint_qbal_M->Sizes.checksums[1] = (3961551629U);
  mission_server_waypoint_qbal_M->Sizes.checksums[2] = (2463350884U);
  mission_server_waypoint_qbal_M->Sizes.checksums[3] = (364762844U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    mission_server_waypoint_qbal_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &mission_server_waypoint_qbal_DW.ChartSchedulerLogic_SubsysRanBC;
    rteiSetModelMappingInfoPtr(mission_server_waypoint_qbal_M->extModeInfo,
      &mission_server_waypoint_qbal_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(mission_server_waypoint_qbal_M->extModeInfo,
                        mission_server_waypoint_qbal_M->Sizes.checksums);
    rteiSetTPtr(mission_server_waypoint_qbal_M->extModeInfo, rtmGetTPtr
                (mission_server_waypoint_qbal_M));
  }

  /* block I/O */
  (void) memset(((void *) &mission_server_waypoint_qball_B), 0,
                sizeof(B_mission_server_waypoint_qba_T));

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      mission_server_waypoint_qball_B.Constant2[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      mission_server_waypoint_qball_B.Constant3[i] = 0.0;
    }

    mission_server_waypoint_qball_B.OptiTrackTrackables_o1[0] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o1[1] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o1[2] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o2[0] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o2[1] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o2[2] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o2[3] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o3[0] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o3[1] = 0.0;
    mission_server_waypoint_qball_B.OptiTrackTrackables_o3[2] = 0.0;
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[0] = 0.0;
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[1] = 0.0;
    mission_server_waypoint_qball_B.ConvertOptitrackframetoRightHan[2] = 0.0;
    mission_server_waypoint_qball_B.Widthx = 0.0;
    mission_server_waypoint_qball_B.ManualSwitch1 = 0.0;
    mission_server_waypoint_qball_B.DataTypeConversion = 0.0;
    mission_server_waypoint_qball_B.DummyData = 0.0;
    mission_server_waypoint_qball_B.DummyData31[0] = 0.0;
    mission_server_waypoint_qball_B.DummyData31[1] = 0.0;
    mission_server_waypoint_qball_B.DummyData31[2] = 0.0;
    mission_server_waypoint_qball_B.DummyData32[0] = 0.0;
    mission_server_waypoint_qball_B.DummyData32[1] = 0.0;
    mission_server_waypoint_qball_B.DummyData32[2] = 0.0;
    mission_server_waypoint_qball_B.DummyData3[0] = 0.0;
    mission_server_waypoint_qball_B.DummyData3[1] = 0.0;
    mission_server_waypoint_qball_B.DummyData3[2] = 0.0;
    mission_server_waypoint_qball_B.DummyData_i = 0.0;
    mission_server_waypoint_qball_B.Widthz = 0.0;
    mission_server_waypoint_qball_B.Sqrt = 0.0;
    mission_server_waypoint_qball_B.idx = 0.0;
    mission_server_waypoint_qball_B.done = 0.0;
    mission_server_waypoint_qball_B.x_ref = 0.0;
    mission_server_waypoint_qball_B.z_ref = 0.0;
    mission_server_waypoint_qball_B.last_waypoint = 0.0;
    mission_server_waypoint_qball_B.Angles[0] = 0.0;
    mission_server_waypoint_qball_B.Angles[1] = 0.0;
    mission_server_waypoint_qball_B.Angles[2] = 0.0;
    mission_server_waypoint_qball_B.qball_takeoff = 0.0;
    mission_server_waypoint_qball_B.x_quad_ref = 0.0;
    mission_server_waypoint_qball_B.z_quad_ref = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&mission_server_waypoint_qbal_DW, 0,
                sizeof(DW_mission_server_waypoint_qb_T));

  {
    int_T i;
    for (i = 0; i < 1000; i++) {
      mission_server_waypoint_qbal_DW.QBall2Trajectory_XBuffer[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 1000; i++) {
      mission_server_waypoint_qbal_DW.QBall2Trajectory_YBuffer[i] = 0.0;
    }
  }

  mission_server_waypoint_qbal_DW.start_stop_prev = 0.0;
  mission_server_waypoint_qbal_DW.start_stop_start = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    mission_server_waypoint_qbal_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  {
    int32_T i;

    /* Start for S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */

    /* S-Function Block: mission_server_waypoint_qball2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
    {
      t_error result;
      result = optitrack_rb_initialize
        (&mission_server_waypoint_qbal_DW.OptiTrackTrackables_Optitrack,
         "C:\\Users\\user\\Desktop\\final\\Calibration Very High Quality Exceptional (MeanErr 0.001 mm) 2017-05-16 6.48pm.cal",
         "C:\\Users\\user\\Desktop\\final\\RigidBodies 2017-05-26 7.29pm.tra");
      if (result == 0) {
        result = optitrack_set_rigid_body_ids
          (mission_server_waypoint_qbal_DW.OptiTrackTrackables_Optitrack,
           &mission_server_waypoint__ConstP.OptiTrackTrackables_RBIDs, 1);
      }

      if (result < 0) {
        optitrack_rb_close
          (mission_server_waypoint_qbal_DW.OptiTrackTrackables_Optitrack);
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(mission_server_waypoint_qbal_M, _rt_error_message);
      }
    }

    /* Start for Width: '<S5>/Width - x' */
    mission_server_waypoint_qball_B.Widthx = 5.0;
    for (i = 0; i < 5; i++) {
      /* Start for Constant: '<Root>/Constant2' */
      mission_server_waypoint_qball_B.Constant2[i] =
        mission_server_waypoint_qball_P.Constant2_Value[i];

      /* Start for Constant: '<Root>/Constant3' */
      mission_server_waypoint_qball_B.Constant3[i] =
        mission_server_waypoint_qball_P.Constant3_Value[i];
    }

    /* Start for S-Function (stream_server_block): '<S4>/Stream Server' */

    /* S-Function Block: mission_server_waypoint_qball2/Serve Data for Qball 2/Stream Server (stream_server_block) */
    {
      qthread_attr_t send_thread_attributes;
      struct qsched_param scheduling_parameters;
      int min_priority = qsched_get_priority_min(QSCHED_FIFO);
      int max_priority = qsched_get_priority_max(QSCHED_FIFO);
      t_pstream_options options;
      t_error result;
      mission_server_waypoint_qbal_DW.StreamServer_Stream = NULL;
      result = 0;
      options.size = sizeof(options);
      options.flags = mission_server_waypoint_qball_P.StreamServer_Endian &
        PSTREAM_FLAG_ENDIAN_MASK;
      if (mission_server_waypoint_qball_P.StreamServer_Implementation ==
          STREAM_SERVER_IMPLEMENTATION_THREAD) {
        options.flags |= PSTREAM_FLAG_MULTITHREADED;
      }

      if (mission_server_waypoint_qball_P.StreamServer_Optimize ==
          STREAM_SERVER_OPTIMIZE_LATENCY) {
        options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
      }

      options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
      options.send_unit_size = 8;
      options.num_send_units = 10;
      options.send_buffer_size =
        mission_server_waypoint_qball_P.StreamServer_SndSize;
      options.send_fifo_size =
        mission_server_waypoint_qball_P.StreamServer_SndFIFO;
      options.num_send_dimensions = 0;
      options.max_send_dimensions = NULL;
      if (mission_server_waypoint_qball_P.StreamServer_SndPriority <
          min_priority) {
        scheduling_parameters.sched_priority = min_priority;
      } else if (mission_server_waypoint_qball_P.StreamServer_SndPriority >
                 max_priority) {
        scheduling_parameters.sched_priority = max_priority;
      } else {
        scheduling_parameters.sched_priority =
          mission_server_waypoint_qball_P.StreamServer_SndPriority;
      }

      qthread_attr_init(&send_thread_attributes);
      result = qthread_attr_setschedpolicy(&send_thread_attributes, QSCHED_FIFO);
      if (result == 0) {
        result = qthread_attr_setschedparam(&send_thread_attributes,
          &scheduling_parameters);
        if (result == 0) {
          result = qthread_attr_setinheritsched(&send_thread_attributes,
            QTHREAD_EXPLICIT_SCHED);
          if (result < 0) {
            rtmSetErrorStatus(mission_server_waypoint_qbal_M,
                              "Unable to set scheduling inheritance for Stream Client sending thread");
          }
        } else {
          rtmSetErrorStatus(mission_server_waypoint_qbal_M,
                            "The specified thread priority for the Stream Client sending thread is not valid for this target");
        }
      } else {
        rtmSetErrorStatus(mission_server_waypoint_qbal_M,
                          "Unable to set scheduling policy for Stream Client sending thread");
      }

      options.send_thread_attributes = &send_thread_attributes;
      options.receive_unit_size = 1;
      options.num_receive_units = 0;
      options.receive_buffer_size = 0;
      options.receive_fifo_size = 0;
      options.receive_thread_attributes = NULL;
      options.num_receive_dimensions = 0;
      options.max_receive_dimensions = NULL;
      if (result == 0) {
        result = pstream_listen((const char *)
          mission_server_waypoint_qball_P.StreamServer_URI, &options,
          &mission_server_waypoint_qbal_DW.StreamServer_Stream);
        if (result < 0 && result != -QERR_WOULD_BLOCK) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(mission_server_waypoint_qbal_M, _rt_error_message);
        }
      }

      qthread_attr_destroy(&send_thread_attributes);
    }

    /* Start for Width: '<S5>/Width - z' */
    mission_server_waypoint_qball_B.Widthz = 5.0;
  }

  /* InitializeConditions for Memory: '<S5>/Memory' */
  mission_server_waypoint_qbal_DW.Memory_PreviousInput =
    mission_server_waypoint_qball_P.Memory_X0;

  /* InitializeConditions for S-Function (fcncallgen): '<S5>/Function-Call Generator (Clock Ticks)' incorporates:
   *  InitializeConditions for Chart: '<S5>/Chart - Scheduler Logic'
   */
  /* InitializeConditions for Chart: '<S5>/Chart - Scheduler Logic' */
  mission_server_waypoint_qbal_DW.temporalCounter_i1 = 0U;
  mission_server_waypoint_qbal_DW.is_active_c3_mission_server_way = 0U;
  mission_server_waypoint_qbal_DW.is_c3_mission_server_waypoint_q =
    mission_serv_IN_NO_ACTIVE_CHILD;
  mission_server_waypoint_qbal_DW.presentTicks = 0U;
  mission_server_waypoint_qbal_DW.elapsedTicks = 0U;
  mission_server_waypoint_qbal_DW.previousTicks = 0U;

  /* InitializeConditions for Chart: '<S1>/Logic Chart' */
  mission_server_waypoint_qbal_DW.sfEvent_g = mission_server_waypo_CALL_EVENT;
  mission_server_waypoint_qbal_DW.is_active_c1_mission_server_way = 0U;
  mission_server_waypoint_qbal_DW.is_c1_mission_server_waypoint_q =
    mission_serv_IN_NO_ACTIVE_CHILD;

  /* Enable for S-Function (fcncallgen): '<S5>/Function-Call Generator (Clock Ticks)' incorporates:
   *  Enable for Chart: '<S5>/Chart - Scheduler Logic'
   */
  /* Enable for Chart: '<S5>/Chart - Scheduler Logic' */
  mission_server_waypoint_qbal_DW.presentTicks =
    mission_server_waypoint_qbal_M->Timing.clockTick0;
  mission_server_waypoint_qbal_DW.previousTicks =
    mission_server_waypoint_qbal_DW.presentTicks;
}

/* Model terminate function */
void mission_server_waypoint_qball2_terminate(void)
{
  /* Terminate for S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */
  /* S-Function Block: mission_server_waypoint_qball2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result;
    if ((result = optitrack_rb_close
         (mission_server_waypoint_qbal_DW.OptiTrackTrackables_Optitrack)) < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_waypoint_qbal_M, _rt_error_message);
    }
  }

  /* Terminate for S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_waypoint_qball2/Serve Data for Qball 2/Stream Server (stream_server_block) */
  {
    if (mission_server_waypoint_qbal_DW.StreamServer_Stream != NULL) {
      pstream_close(mission_server_waypoint_qbal_DW.StreamServer_Stream);
    }

    mission_server_waypoint_qbal_DW.StreamServer_Stream = NULL;
  }
}
