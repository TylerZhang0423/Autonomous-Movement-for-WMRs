/*
 * mission_server_tracking_qbot2.c
 *
 * Code generation for model "mission_server_tracking_qbot2".
 *
 * Model version              : 1.94
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed May 31 17:51:20 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "mission_server_tracking_qbot2.h"
#include "mission_server_tracking_qbot2_private.h"
#include "mission_server_tracking_qbot2_dt.h"

/* Named constants for Chart: '<S1>/Logic Chart' */
#define mission__IN_WaitForStartCommand ((uint8_T)2U)
#define mission_se_IN_QbotGetsWaypoints ((uint8_T)1U)
#define mission_serv_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define mission_server_track_CALL_EVENT (-1)

/* Block signals (auto storage) */
B_mission_server_tracking_qbo_T mission_server_tracking_qbot2_B;

/* Block states (auto storage) */
DW_mission_server_tracking_qb_T mission_server_tracking_qbot_DW;

/* Real-time model */
RT_MODEL_mission_server_track_T mission_server_tracking_qbot_M_;
RT_MODEL_mission_server_track_T *const mission_server_tracking_qbot_M =
  &mission_server_tracking_qbot_M_;
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
void mission_server_tracking_qbot2_step(void)
{
  /* local block i/o variables */
  real_T rtb_TmpSignalConversionAtStream[6];
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

  /* S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */

  /* S-Function Block: mission_server_tracking_qbot2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result = 0;
    result = optitrack_rb_get_position
      (mission_server_tracking_qbot_DW.OptiTrackTrackables_Optitrack,
       &mission_server_tracking_qbot2_B.OptiTrackTrackables_o1[0],
       &mission_server_tracking_qbot2_B.OptiTrackTrackables_o2[0],
       &mission_server_tracking_qbot2_B.OptiTrackTrackables_o3[0], (t_boolean *)
       &mission_server_tracking_qbot2_B.OptiTrackTrackables_o4);
    if ((result < 0) && (result != -QERR_WOULD_BLOCK)) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_tracking_qbot_M, _rt_error_message);
    }
  }

  /* Gain: '<S7>/Convert Optitrack orientation frame to Right-Hand Convention' incorporates:
   *  Product: '<S7>/Product'
   */
  rtb_R_idx_8 = mission_server_tracking_qbot2_P.ConvertOptitrackorientationfram
    [0] * mission_server_tracking_qbot2_B.OptiTrackTrackables_o3[0];
  sRoll = mission_server_tracking_qbot2_P.ConvertOptitrackorientationfram[1] *
    mission_server_tracking_qbot2_B.OptiTrackTrackables_o3[1];
  sPitch = mission_server_tracking_qbot2_P.ConvertOptitrackorientationfram[2] *
    mission_server_tracking_qbot2_B.OptiTrackTrackables_o3[2];

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Rotate Basis from UVS Orientation to Global Frame'
   *  Math: '<S7>/Inverse of Orthonormal Matrix is its Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product[i] =
      mission_server_tracking_qbot2_P.RotateBasisfromUVSOrientationto[3 * i + 2]
      * sPitch +
      (mission_server_tracking_qbot2_P.RotateBasisfromUVSOrientationto[3 * i + 1]
       * sRoll +
       mission_server_tracking_qbot2_P.RotateBasisfromUVSOrientationto[3 * i] *
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
  cPitch = asin(rtb_R_idx_2);
  if (1.0 - fabs(rtb_R_idx_2) > 2.2204460492503131E-16) {
    /* '<S10>:1:18' */
    /*  Not at Euler singularity */
    /* '<S10>:1:20' */
    /* '<S10>:1:21' */
    sPitch = rt_atan2d_snf(rtb_R_idx_5, rtb_R_idx_8);

    /* '<S10>:1:22' */
    cRoll = rt_atan2d_snf(sYaw, rtb_R_idx_0);
  } else {
    /*  At Euler singularity */
    /* '<S10>:1:25' */
    /*  Roll and Yaw are ambiguous. */
    /*  Use the optional angular measurement to resolve the ambiguity */
    /* '<S10>:1:29' */
    sRoll = acos(cRoll * cYaw);
    if (-cPitch > 0.0) {
      /* '<S10>:1:31' */
      /*  pitch is +pi/2 */
      /*  RollYaw = Roll + Yaw */
      /*  Therefore, */
      /*  Roll = RollYaw - Yaw */
      /*  Or  */
      /*  Yaw = RollYaw - Roll */
      if (mission_server_tracking_qbot2_P.DefaultDummy_Value != 0.0) {
        /* '<S10>:1:38' */
        /*  Roll Aux measurement available */
        /* '<S10>:1:39' */
        sPitch = mission_server_tracking_qbot2_P.DefaultDummy_Value;

        /* '<S10>:1:40' */
        cRoll = sRoll - mission_server_tracking_qbot2_P.DefaultDummy_Value;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S10>:1:42' */
        cRoll = mission_server_tracking_qbot2_P.DefaultDummy_Value;

        /* '<S10>:1:43' */
        sPitch = sRoll - mission_server_tracking_qbot2_P.DefaultDummy_Value;
      }
    } else {
      /*  pitch is -pi/2 */
      /*  RollYaw = Roll - Yaw */
      /*  Therefore, */
      /*  Roll = RollYaw + Yaw */
      /*  Or */
      /*  Yaw = -RollYaw + Roll */
      if (mission_server_tracking_qbot2_P.DefaultDummy_Value != 0.0) {
        /* '<S10>:1:52' */
        /*  Roll Aux measurement available */
        /* '<S10>:1:53' */
        sPitch = mission_server_tracking_qbot2_P.DefaultDummy_Value;

        /* '<S10>:1:54' */
        cRoll = -sRoll + mission_server_tracking_qbot2_P.DefaultDummy_Value;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S10>:1:56' */
        cRoll = mission_server_tracking_qbot2_P.DefaultDummy_Value;

        /* '<S10>:1:57' */
        sPitch = sRoll + mission_server_tracking_qbot2_P.DefaultDummy_Value;
      }
    }
  }

  /* '<S10>:1:62' */
  mission_server_tracking_qbot2_B.Angles[0] = sPitch;
  mission_server_tracking_qbot2_B.Angles[1] = -cPitch;
  mission_server_tracking_qbot2_B.Angles[2] = cRoll;

  /* End of MATLAB Function: '<S8>/EulerAngles_zyx_from_RotationMatrix' */

  /* Gain: '<Root>/Gain' */
  mission_server_tracking_qbot2_B.Gain[0] =
    mission_server_tracking_qbot2_P.Gain_Gain *
    mission_server_tracking_qbot2_B.Angles[0];
  mission_server_tracking_qbot2_B.Gain[1] =
    mission_server_tracking_qbot2_P.Gain_Gain *
    mission_server_tracking_qbot2_B.Angles[1];
  mission_server_tracking_qbot2_B.Gain[2] =
    mission_server_tracking_qbot2_P.Gain_Gain *
    mission_server_tracking_qbot2_B.Angles[2];

  /* Gain: '<S7>/Convert Optitrack frame to Right-Hand Convention' */
  mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[0] =
    mission_server_tracking_qbot2_P.ConvertOptitrackframetoRightHan[0] *
    mission_server_tracking_qbot2_B.OptiTrackTrackables_o1[0];
  mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[1] =
    mission_server_tracking_qbot2_P.ConvertOptitrackframetoRightHan[1] *
    mission_server_tracking_qbot2_B.OptiTrackTrackables_o1[1];
  mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[2] =
    mission_server_tracking_qbot2_P.ConvertOptitrackframetoRightHan[2] *
    mission_server_tracking_qbot2_B.OptiTrackTrackables_o1[2];

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  mission_server_tracking_qbot2_B.DataTypeConversion =
    mission_server_tracking_qbot2_B.OptiTrackTrackables_o4;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Toggle High'
   *  Constant: '<Root>/Toggle Low'
   */
  if (mission_server_tracking_qbot2_P.ManualSwitch_CurrentSetting == 1) {
    mission_server_tracking_qbot2_B.ManualSwitch =
      mission_server_tracking_qbot2_P.ToggleHigh_Value;
  } else {
    mission_server_tracking_qbot2_B.ManualSwitch =
      mission_server_tracking_qbot2_P.ToggleLow_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Constant: '<S13>/Dummy Data' */
  mission_server_tracking_qbot2_B.DummyData =
    mission_server_tracking_qbot2_P.DummyData_Value;

  /* MATLAB Function: '<S5>/Waypoint Scheduler' incorporates:
   *  Constant: '<Root>/Waypoints - x'
   *  Constant: '<Root>/Waypoints - z'
   */
  /* MATLAB Function 'Trajectory Generation/Waypoint Scheduler': '<S15>:1' */
  /*  This function generates a trajectory to be tracked based on a vector of */
  /*  waypoint positions that get passed in. We increment the */
  /*  index into the waypoint vector once the vehicle has got to within a */
  /*  pre-determined threshold of the waypoint.  */
  /* '<S15>:1:15' */
  mission_server_tracking_qbot2_B.mission_complete = 0.0;

  /*  The distance below which we switch to the next waypoint: */
  /* '<S15>:1:18' */
  /*  Check if we're still far enough away from the waypoint: */
  /* '<S15>:1:21' */
  sRoll = 2.2250738585072014E-308;
  cRoll = fabs(mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[0]
               - mission_server_tracking_qbot2_P.Waypointsx_Value[(int32_T)
               mission_server_tracking_qbot_DW.idx - 1]);
  if (cRoll > 2.2250738585072014E-308) {
    cPitch = 1.0;
    sRoll = cRoll;
  } else {
    sPitch = cRoll / 2.2250738585072014E-308;
    cPitch = sPitch * sPitch;
  }

  cRoll = fabs(mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[2]
               - mission_server_tracking_qbot2_P.Waypointsz_Value[(int32_T)
               mission_server_tracking_qbot_DW.idx - 1]);
  if (cRoll > sRoll) {
    sPitch = sRoll / cRoll;
    cPitch = cPitch * sPitch * sPitch + 1.0;
    sRoll = cRoll;
  } else {
    sPitch = cRoll / sRoll;
    cPitch += sPitch * sPitch;
  }

  cPitch = sRoll * sqrt(cPitch);
  if ((cPitch > 0.1) || (mission_server_tracking_qbot_DW.idx == 3.0)) {
    /* '<S15>:1:23' */
    /* '<S15>:1:24' */
    cPitch = mission_server_tracking_qbot2_P.Waypointsx_Value[(int32_T)
      mission_server_tracking_qbot_DW.idx - 1];

    /* '<S15>:1:25' */
    sRoll = mission_server_tracking_qbot2_P.Waypointsz_Value[(int32_T)
      mission_server_tracking_qbot_DW.idx - 1];
  } else {
    /*  Move to the next waypoint */
    /* '<S15>:1:27' */
    mission_server_tracking_qbot_DW.idx++;

    /* '<S15>:1:28' */
    cPitch = mission_server_tracking_qbot2_P.Waypointsx_Value[(int32_T)
      mission_server_tracking_qbot_DW.idx - 1];

    /* '<S15>:1:29' */
    sRoll = mission_server_tracking_qbot2_P.Waypointsz_Value[(int32_T)
      mission_server_tracking_qbot_DW.idx - 1];
  }

  /* '<S15>:1:32' */
  mission_server_tracking_qbot2_B.waypoint_num =
    mission_server_tracking_qbot_DW.idx;

  /*  Check if the mission is finished: */
  if (mission_server_tracking_qbot_DW.idx == 3.0) {
    /* '<S15>:1:35' */
    /* '<S15>:1:36' */
    mission_server_tracking_qbot2_B.mission_complete = 1.0;
  }

  /* End of MATLAB Function: '<S5>/Waypoint Scheduler' */

  /* ManualSwitch: '<S5>/Manual Switch2' incorporates:
   *  Constant: '<S5>/Default x (m)'
   */
  if (mission_server_tracking_qbot2_P.ManualSwitch2_CurrentSetting == 1) {
    mission_server_tracking_qbot2_B.ManualSwitch2 =
      mission_server_tracking_qbot2_P.Defaultxm_Value;
  } else {
    mission_server_tracking_qbot2_B.ManualSwitch2 = cPitch;
  }

  /* End of ManualSwitch: '<S5>/Manual Switch2' */

  /* ManualSwitch: '<S5>/Manual Switch3' incorporates:
   *  Constant: '<S5>/Default z (m)'
   */
  if (mission_server_tracking_qbot2_P.ManualSwitch3_CurrentSetting == 1) {
    mission_server_tracking_qbot2_B.ManualSwitch3 =
      mission_server_tracking_qbot2_P.Defaultzm_Value;
  } else {
    mission_server_tracking_qbot2_B.ManualSwitch3 = sRoll;
  }

  /* End of ManualSwitch: '<S5>/Manual Switch3' */

  /* Chart: '<S1>/Logic Chart' */
  /* Gateway: Logic Subsystem/Logic Chart */
  mission_server_tracking_qbot_DW.sfEvent = mission_server_track_CALL_EVENT;
  mission_server_tracking_qbot_DW.start_stop_prev =
    mission_server_tracking_qbot_DW.start_stop_start;
  mission_server_tracking_qbot_DW.start_stop_start =
    mission_server_tracking_qbot2_B.ManualSwitch;

  /* During: Logic Subsystem/Logic Chart */
  if (mission_server_tracking_qbot_DW.is_active_c4_mission_server_tra == 0U) {
    mission_server_tracking_qbot_DW.start_stop_prev =
      mission_server_tracking_qbot2_B.ManualSwitch;

    /* Entry: Logic Subsystem/Logic Chart */
    mission_server_tracking_qbot_DW.is_active_c4_mission_server_tra = 1U;

    /* Entry Internal: Logic Subsystem/Logic Chart */
    /* Transition: '<S6>:2' */
    mission_server_tracking_qbot_DW.is_c4_mission_server_tracking_q =
      mission__IN_WaitForStartCommand;
  } else if (mission_server_tracking_qbot_DW.is_c4_mission_server_tracking_q ==
             mission_se_IN_QbotGetsWaypoints) {
    /* During 'QbotGetsWaypoints': '<S6>:21' */
    if (mission_server_tracking_qbot_DW.start_stop_prev !=
        mission_server_tracking_qbot_DW.start_stop_start) {
      /* Transition: '<S6>:30' */
      mission_server_tracking_qbot_DW.is_c4_mission_server_tracking_q =
        mission__IN_WaitForStartCommand;
    } else {
      mission_server_tracking_qbot2_B.x_ugv_ref =
        mission_server_tracking_qbot2_B.ManualSwitch2;
      mission_server_tracking_qbot2_B.z_ugv_ref =
        mission_server_tracking_qbot2_B.ManualSwitch3;
    }
  } else {
    /* During 'WaitForStartCommand': '<S6>:1' */
    if (mission_server_tracking_qbot_DW.start_stop_prev !=
        mission_server_tracking_qbot_DW.start_stop_start) {
      /* Transition: '<S6>:19' */
      mission_server_tracking_qbot_DW.is_c4_mission_server_tracking_q =
        mission_se_IN_QbotGetsWaypoints;
    } else {
      mission_server_tracking_qbot2_B.x_ugv_ref =
        mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[0];
      mission_server_tracking_qbot2_B.z_ugv_ref =
        mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[2];
    }
  }

  /* End of Chart: '<S1>/Logic Chart' */

  /* Constant: '<S12>/Dummy Data [3]1' */
  mission_server_tracking_qbot2_B.DummyData31[0] =
    mission_server_tracking_qbot2_P.DummyData31_Value[0];
  mission_server_tracking_qbot2_B.DummyData31[1] =
    mission_server_tracking_qbot2_P.DummyData31_Value[1];
  mission_server_tracking_qbot2_B.DummyData31[2] =
    mission_server_tracking_qbot2_P.DummyData31_Value[2];

  /* Constant: '<S12>/Dummy Data [3]2' */
  mission_server_tracking_qbot2_B.DummyData32[0] =
    mission_server_tracking_qbot2_P.DummyData32_Value[0];
  mission_server_tracking_qbot2_B.DummyData32[1] =
    mission_server_tracking_qbot2_P.DummyData32_Value[1];
  mission_server_tracking_qbot2_B.DummyData32[2] =
    mission_server_tracking_qbot2_P.DummyData32_Value[2];

  /* Constant: '<S12>/Dummy Data [3]' */
  mission_server_tracking_qbot2_B.DummyData3[0] =
    mission_server_tracking_qbot2_P.DummyData3_Value[0];
  mission_server_tracking_qbot2_B.DummyData3[1] =
    mission_server_tracking_qbot2_P.DummyData3_Value[1];
  mission_server_tracking_qbot2_B.DummyData3[2] =
    mission_server_tracking_qbot2_P.DummyData3_Value[2];

  /* Constant: '<S12>/Dummy Data' */
  mission_server_tracking_qbot2_B.DummyData_l =
    mission_server_tracking_qbot2_P.DummyData_Value_d;

  /* SignalConversion: '<S4>/TmpSignal ConversionAtStream ServerInport1' */
  rtb_TmpSignalConversionAtStream[0] = mission_server_tracking_qbot2_B.x_ugv_ref;
  rtb_TmpSignalConversionAtStream[1] = mission_server_tracking_qbot2_B.z_ugv_ref;
  rtb_TmpSignalConversionAtStream[2] =
    mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[0];
  rtb_TmpSignalConversionAtStream[3] = mission_server_tracking_qbot2_B.Angles[2];
  rtb_TmpSignalConversionAtStream[4] =
    mission_server_tracking_qbot2_B.ConvertOptitrackframetoRightHan[2];
  rtb_TmpSignalConversionAtStream[5] =
    mission_server_tracking_qbot2_B.DataTypeConversion;

  /* S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_tracking_qbot2/Serve Data For QBot 2/Stream Server (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    if (mission_server_tracking_qbot2_P.Enable_Value) {
      send_result = pstream_send
        (mission_server_tracking_qbot_DW.StreamServer_Stream,
         &rtb_TmpSignalConversionAtStream[0]);
    } else {
      send_result = 0;
    }

    mission_server_tracking_qbot2_B.StreamServer_o3 = (send_result > 0);
    mission_server_tracking_qbot2_B.StreamServer_o2 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      mission_server_tracking_qbot2_B.StreamServer_o2 = send_result;
    }

    pstream_get_state(mission_server_tracking_qbot_DW.StreamServer_Stream,
                      &state);
    mission_server_tracking_qbot2_B.StreamServer_o1 = state;
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, mission_server_tracking_qbot_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(mission_server_tracking_qbot_M)!=-1) &&
        !((rtmGetTFinal(mission_server_tracking_qbot_M)-
           mission_server_tracking_qbot_M->Timing.taskTime0) >
          mission_server_tracking_qbot_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(mission_server_tracking_qbot_M, "Simulation finished");
    }

    if (rtmGetStopRequested(mission_server_tracking_qbot_M)) {
      rtmSetErrorStatus(mission_server_tracking_qbot_M, "Simulation finished");
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
  if (!(++mission_server_tracking_qbot_M->Timing.clockTick0)) {
    ++mission_server_tracking_qbot_M->Timing.clockTickH0;
  }

  mission_server_tracking_qbot_M->Timing.taskTime0 =
    mission_server_tracking_qbot_M->Timing.clockTick0 *
    mission_server_tracking_qbot_M->Timing.stepSize0 +
    mission_server_tracking_qbot_M->Timing.clockTickH0 *
    mission_server_tracking_qbot_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void mission_server_tracking_qbot2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mission_server_tracking_qbot_M, 0,
                sizeof(RT_MODEL_mission_server_track_T));
  rtmSetTFinal(mission_server_tracking_qbot_M, -1);
  mission_server_tracking_qbot_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  mission_server_tracking_qbot_M->Sizes.checksums[0] = (3210549779U);
  mission_server_tracking_qbot_M->Sizes.checksums[1] = (3016562147U);
  mission_server_tracking_qbot_M->Sizes.checksums[2] = (3355896578U);
  mission_server_tracking_qbot_M->Sizes.checksums[3] = (1640827827U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    mission_server_tracking_qbot_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(mission_server_tracking_qbot_M->extModeInfo,
      &mission_server_tracking_qbot_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(mission_server_tracking_qbot_M->extModeInfo,
                        mission_server_tracking_qbot_M->Sizes.checksums);
    rteiSetTPtr(mission_server_tracking_qbot_M->extModeInfo, rtmGetTPtr
                (mission_server_tracking_qbot_M));
  }

  /* block I/O */
  (void) memset(((void *) &mission_server_tracking_qbot2_B), 0,
                sizeof(B_mission_server_tracking_qbo_T));

  /* states (dwork) */
  (void) memset((void *)&mission_server_tracking_qbot_DW, 0,
                sizeof(DW_mission_server_tracking_qb_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    mission_server_tracking_qbot_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */

  /* S-Function Block: mission_server_tracking_qbot2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result;
    result = optitrack_rb_initialize
      (&mission_server_tracking_qbot_DW.OptiTrackTrackables_Optitrack,
       "C:\\Users\\user\\Desktop\\final\\Calibration Very High Quality Exceptional (MeanErr 0.001 mm) 2017-05-16 6.48pm.cal",
       "C:\\Users\\user\\Desktop\\final\\RigidBodies 2017-05-26 5.36pm_qbotx2.tra");
    if (result == 0) {
      result = optitrack_set_rigid_body_ids
        (mission_server_tracking_qbot_DW.OptiTrackTrackables_Optitrack,
         &mission_server_tracking__ConstP.OptiTrackTrackables_RBIDs, 1);
    }

    if (result < 0) {
      optitrack_rb_close
        (mission_server_tracking_qbot_DW.OptiTrackTrackables_Optitrack);
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_tracking_qbot_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_tracking_qbot2/Serve Data For QBot 2/Stream Server (stream_server_block) */
  {
    qthread_attr_t send_thread_attributes;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    t_pstream_options options;
    t_error result;
    mission_server_tracking_qbot_DW.StreamServer_Stream = NULL;
    result = 0;
    options.size = sizeof(options);
    options.flags = mission_server_tracking_qbot2_P.StreamServer_Endian &
      PSTREAM_FLAG_ENDIAN_MASK;
    if (mission_server_tracking_qbot2_P.StreamServer_Implementation ==
        STREAM_SERVER_IMPLEMENTATION_THREAD) {
      options.flags |= PSTREAM_FLAG_MULTITHREADED;
    }

    if (mission_server_tracking_qbot2_P.StreamServer_Optimize ==
        STREAM_SERVER_OPTIMIZE_LATENCY) {
      options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
    }

    options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
    options.send_unit_size = 8;
    options.num_send_units = 6;
    options.send_buffer_size =
      mission_server_tracking_qbot2_P.StreamServer_SndSize;
    options.send_fifo_size =
      mission_server_tracking_qbot2_P.StreamServer_SndFIFO;
    options.num_send_dimensions = 0;
    options.max_send_dimensions = NULL;
    if (mission_server_tracking_qbot2_P.StreamServer_SndPriority < min_priority)
    {
      scheduling_parameters.sched_priority = min_priority;
    } else if (mission_server_tracking_qbot2_P.StreamServer_SndPriority >
               max_priority) {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        mission_server_tracking_qbot2_P.StreamServer_SndPriority;
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
          rtmSetErrorStatus(mission_server_tracking_qbot_M,
                            "Unable to set scheduling inheritance for Stream Client sending thread");
        }
      } else {
        rtmSetErrorStatus(mission_server_tracking_qbot_M,
                          "The specified thread priority for the Stream Client sending thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(mission_server_tracking_qbot_M,
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
        mission_server_tracking_qbot2_P.StreamServer_URI, &options,
        &mission_server_tracking_qbot_DW.StreamServer_Stream);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(mission_server_tracking_qbot_M, _rt_error_message);
      }
    }

    qthread_attr_destroy(&send_thread_attributes);
  }

  /* InitializeConditions for MATLAB Function: '<S5>/Waypoint Scheduler' */
  mission_server_tracking_qbot_DW.idx = 1.0;

  /* InitializeConditions for Chart: '<S1>/Logic Chart' */
  mission_server_tracking_qbot_DW.sfEvent = mission_server_track_CALL_EVENT;
  mission_server_tracking_qbot_DW.is_active_c4_mission_server_tra = 0U;
  mission_server_tracking_qbot_DW.is_c4_mission_server_tracking_q =
    mission_serv_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void mission_server_tracking_qbot2_terminate(void)
{
  /* Terminate for S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */
  /* S-Function Block: mission_server_tracking_qbot2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result;
    if ((result = optitrack_rb_close
         (mission_server_tracking_qbot_DW.OptiTrackTrackables_Optitrack)) < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_tracking_qbot_M, _rt_error_message);
    }
  }

  /* Terminate for S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_tracking_qbot2/Serve Data For QBot 2/Stream Server (stream_server_block) */
  {
    if (mission_server_tracking_qbot_DW.StreamServer_Stream != NULL) {
      pstream_close(mission_server_tracking_qbot_DW.StreamServer_Stream);
    }

    mission_server_tracking_qbot_DW.StreamServer_Stream = NULL;
  }
}
