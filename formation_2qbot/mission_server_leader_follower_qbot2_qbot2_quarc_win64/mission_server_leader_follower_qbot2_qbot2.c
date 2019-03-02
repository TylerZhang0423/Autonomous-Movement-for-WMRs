/*
 * mission_server_leader_follower_qbot2_qbot2.c
 *
 * Code generation for model "mission_server_leader_follower_qbot2_qbot2".
 *
 * Model version              : 1.86
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Jun 01 15:22:20 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "mission_server_leader_follower_qbot2_qbot2.h"
#include "mission_server_leader_follower_qbot2_qbot2_private.h"
#include "mission_server_leader_follower_qbot2_qbot2_dt.h"

/* Named constants for Chart: '<S1>/Logic Chart' */
#define mission__IN_WaitForStartCommand ((uint8_T)2U)
#define mission_se_IN_QbotGetsWaypoints ((uint8_T)1U)
#define mission_serv_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define mission_server_le_CALL_EVENT_p3 (-1)

/* Block signals (auto storage) */
B_mission_server_leader_follo_T mission_server_leader_followe_B;

/* Block states (auto storage) */
DW_mission_server_leader_foll_T mission_server_leader_follow_DW;

/* Real-time model */
RT_MODEL_mission_server_leade_T mission_server_leader_follow_M_;
RT_MODEL_mission_server_leade_T *const mission_server_leader_follow_M =
  &mission_server_leader_follow_M_;
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

/*
 * Output and update for atomic system:
 *    '<S13>/EulerAngles_zyx_from_RotationMatrix'
 *    '<S17>/EulerAngles_zyx_from_RotationMatrix'
 */
void EulerAngles_zyx_from_RotationMa(const real_T rtu_R[9], real_T rtu_auxAngle,
  B_EulerAngles_zyx_from_Rotati_T *localB)
{
  real_T roll;
  real_T yaw;
  real_T RollYaw;
  real_T x;

  /* MATLAB Function 'EulerAngles_ZYX_from_RotationMatrix/EulerAngles_zyx_from_RotationMatrix': '<S15>:1' */
  /*  Extract the Euler angles (Z-Y-X) from rotatin matrix */
  /*  Assumption:  */
  /*  The rotation matrix is defined as: */
  /*  */
  /*  r0 = R . r1 */
  /*  */
  /*  where r1 is a vector expressed in the rotated frame */
  /*    r0 is the vector expressed in the reference frame */
  /*  Setting the singularity tolerance */
  /* '<S15>:1:14' */
  /*  Extract Euler angles from the rotation matrix */
  /* '<S15>:1:17' */
  x = asin(rtu_R[2]);
  if (1.0 - fabs(rtu_R[2]) > 2.2204460492503131E-16) {
    /* '<S15>:1:18' */
    /*  Not at Euler singularity */
    /* '<S15>:1:20' */
    /* '<S15>:1:21' */
    roll = rt_atan2d_snf(rtu_R[5], rtu_R[8]);

    /* '<S15>:1:22' */
    yaw = rt_atan2d_snf(rtu_R[1], rtu_R[0]);
  } else {
    /*  At Euler singularity */
    /* '<S15>:1:25' */
    /*  Roll and Yaw are ambiguous. */
    /*  Use the optional angular measurement to resolve the ambiguity */
    /* '<S15>:1:29' */
    RollYaw = acos(rtu_R[4]);
    if (-x > 0.0) {
      /* '<S15>:1:31' */
      /*  pitch is +pi/2 */
      /*  RollYaw = Roll + Yaw */
      /*  Therefore, */
      /*  Roll = RollYaw - Yaw */
      /*  Or  */
      /*  Yaw = RollYaw - Roll */
      if (rtu_auxAngle != 0.0) {
        /* '<S15>:1:38' */
        /*  Roll Aux measurement available */
        /* '<S15>:1:39' */
        roll = rtu_auxAngle;

        /* '<S15>:1:40' */
        yaw = RollYaw - rtu_auxAngle;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S15>:1:42' */
        yaw = 0.0;

        /* '<S15>:1:43' */
        roll = RollYaw;
      }
    } else {
      /*  pitch is -pi/2 */
      /*  RollYaw = Roll - Yaw */
      /*  Therefore, */
      /*  Roll = RollYaw + Yaw */
      /*  Or */
      /*  Yaw = -RollYaw + Roll */
      if (rtu_auxAngle != 0.0) {
        /* '<S15>:1:52' */
        /*  Roll Aux measurement available */
        /* '<S15>:1:53' */
        roll = rtu_auxAngle;

        /* '<S15>:1:54' */
        yaw = -RollYaw + rtu_auxAngle;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S15>:1:56' */
        yaw = 0.0;

        /* '<S15>:1:57' */
        roll = RollYaw;
      }
    }
  }

  /* '<S15>:1:62' */
  localB->Angles[0] = roll;
  localB->Angles[1] = -x;
  localB->Angles[2] = yaw;
}

/*
 * Output and update for atomic system:
 *    '<S14>/RotationMatrix_from_EulerAngles_yzx'
 *    '<S18>/RotationMatrix_from_EulerAngles_yzx'
 */
void RotationMatrix_from_EulerAngles(real_T rtu_roll, real_T rtu_pitch, real_T
  rtu_yaw, B_RotationMatrix_from_EulerAn_T *localB)
{
  real_T sRoll;
  real_T cRoll;
  real_T sPitch;
  real_T cPitch;
  real_T sYaw;
  real_T cYaw;

  /* MATLAB Function 'RotationMatrix_from_EulerAngles_YZX/RotationMatrix_from_EulerAngles_yzx': '<S16>:1' */
  /*  Create rotation matrix from Euler (Y,Z, X) convention. */
  /* '<S16>:1:6' */
  sRoll = sin(rtu_roll);

  /* '<S16>:1:7' */
  cRoll = cos(rtu_roll);

  /* '<S16>:1:8' */
  sPitch = sin(rtu_pitch);

  /* '<S16>:1:9' */
  cPitch = cos(rtu_pitch);

  /* '<S16>:1:10' */
  sYaw = sin(rtu_yaw);

  /* '<S16>:1:11' */
  cYaw = cos(rtu_yaw);

  /* '<S16>:1:13' */
  /* '<S16>:1:15' */
  /* '<S16>:1:17' */
  /* '<S16>:1:18' */
  /* '<S16>:1:19' */
  /* '<S16>:1:21' */
  /* '<S16>:1:22' */
  /* '<S16>:1:23' */
  /* '<S16>:1:25' */
  localB->R[0] = cPitch * cYaw;
  localB->R[3] = -cPitch * sYaw * cRoll + sRoll * sPitch;
  localB->R[6] = cPitch * sYaw * sRoll + cRoll * sPitch;
  localB->R[1] = sYaw;
  localB->R[4] = cRoll * cYaw;
  localB->R[7] = -sRoll * cYaw;
  localB->R[2] = -sPitch * cYaw;
  localB->R[5] = cRoll * sPitch * sYaw + sRoll * cPitch;
  localB->R[8] = -sRoll * sPitch * sYaw + cRoll * cPitch;
}

/*
 * Initial conditions for atomic system:
 *    '<S7>/Waypoint Scheduler'
 *    '<S8>/Waypoint Scheduler'
 */
void mission__WaypointScheduler_Init(DW_WaypointScheduler_mission__T *localDW)
{
  localDW->idx = 1.0;
}

/*
 * Output and update for atomic system:
 *    '<S7>/Waypoint Scheduler'
 *    '<S8>/Waypoint Scheduler'
 */
void mission_serve_WaypointScheduler(real_T rtu_x_waypoint, real_T
  rtu_z_waypoint, real_T rtu_x_ugv, real_T rtu_z_ugv,
  B_WaypointScheduler_mission_s_T *localB, DW_WaypointScheduler_mission__T
  *localDW)
{
  real_T dist;
  real_T scale;
  real_T absxk;
  real_T t;

  /* MATLAB Function 'Trajectory Generation/Waypoint Scheduler': '<S24>:1' */
  /*  This function generates a trajectory to be tracked based on a vector of */
  /*  waypoint positions that get passed in. We increment the */
  /*  index into the waypoint vector once the vehicle has got to within a */
  /*  pre-determined threshold of the waypoint.  */
  /* '<S24>:1:15' */
  localB->mission_complete = 0.0;

  /*  The distance below which we switch to the next waypoint: */
  /* '<S24>:1:18' */
  /*  Check if we're still far enough away from the waypoint: */
  /* '<S24>:1:21' */
  scale = 2.2250738585072014E-308;
  absxk = fabs(rtu_x_ugv - rtu_x_waypoint);
  if (absxk > 2.2250738585072014E-308) {
    dist = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    dist = t * t;
  }

  absxk = fabs(rtu_z_ugv - rtu_z_waypoint);
  if (absxk > scale) {
    t = scale / absxk;
    dist = dist * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    dist += t * t;
  }

  dist = scale * sqrt(dist);
  if ((dist > 0.15) || (localDW->idx == 1.0)) {
    /* '<S24>:1:23' */
    /* '<S24>:1:24' */
    localB->x_ref = rtu_x_waypoint;

    /* '<S24>:1:25' */
    localB->z_ref = rtu_z_waypoint;
  } else {
    /*  Move to the next waypoint */
    /* '<S24>:1:27' */
    localDW->idx++;

    /* '<S24>:1:28' */
    localB->x_ref = rtu_x_waypoint;

    /* '<S24>:1:29' */
    localB->z_ref = rtu_z_waypoint;
  }

  /* '<S24>:1:32' */
  localB->waypoint_num = localDW->idx;

  /*  Check if the mission is finished: */
  if (localDW->idx == 1.0) {
    /* '<S24>:1:35' */
    /* '<S24>:1:36' */
    localB->mission_complete = 1.0;
  }
}

/* Model step function */
void mission_server_leader_follower_qbot2_qbot2_step(void)
{
  /* local block i/o variables */
  real_T rtb_Product[3];
  real_T rtb_Product_i[3];
  real_T rtb_TmpSignalConversionAtStream[6];
  int32_T i;
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;

  /* S-Function (optitrack_rigid_body_position_block): '<S3>/OptiTrack Trackables' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result = 0;
    result = optitrack_rb_get_position
      (mission_server_leader_follow_DW.OptiTrackTrackables_Optitrack,
       &mission_server_leader_followe_B.OptiTrackTrackables_o1[0],
       &mission_server_leader_followe_B.OptiTrackTrackables_o2[0],
       &mission_server_leader_followe_B.OptiTrackTrackables_o3[0], (t_boolean *)
       &mission_server_leader_followe_B.OptiTrackTrackables_o4[0]);
    if ((result < 0) && (result != -QERR_WOULD_BLOCK)) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_leader_follow_M, _rt_error_message);
    }
  }

  /* Gain: '<S12>/Convert Optitrack orientation frame to Right-Hand Convention' incorporates:
   *  Product: '<S12>/Product'
   */
  unnamed_idx_0 =
    mission_server_leader_followe_P.ConvertOptitrackorientationfram[0] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[3];
  unnamed_idx_1 =
    mission_server_leader_followe_P.ConvertOptitrackorientationfram[1] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[4];
  unnamed_idx_2 =
    mission_server_leader_followe_P.ConvertOptitrackorientationfram[2] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[5];

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S12>/Rotate Basis from UVS Orientation to Global Frame'
   *  Math: '<S12>/Inverse of Orthonormal Matrix is its Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product[i] = 0.0;
    rtb_Product[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientationto[3 * i] *
      unnamed_idx_0;
    rtb_Product[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientationto[3 * i + 1]
      * unnamed_idx_1;
    rtb_Product[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientationto[3 * i + 2]
      * unnamed_idx_2;
  }

  /* MATLAB Function: '<S18>/RotationMatrix_from_EulerAngles_yzx' */
  RotationMatrix_from_EulerAngles(rtb_Product[0], rtb_Product[1], rtb_Product[2],
    &mission_server_leader_followe_B.sf_RotationMatrix_from_EulerAng);

  /* MATLAB Function: '<S17>/EulerAngles_zyx_from_RotationMatrix' incorporates:
   *  Constant: '<S12>/Default Dummy'
   */
  EulerAngles_zyx_from_RotationMa
    (mission_server_leader_followe_B.sf_RotationMatrix_from_EulerAng.R,
     mission_server_leader_followe_P.DefaultDummy_Value,
     &mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotatio);

  /* Gain: '<Root>/Gain' */
  mission_server_leader_followe_B.Gain[0] =
    mission_server_leader_followe_P.Gain_Gain *
    mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotatio.Angles[0];
  mission_server_leader_followe_B.Gain[1] =
    mission_server_leader_followe_P.Gain_Gain *
    mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotatio.Angles[1];
  mission_server_leader_followe_B.Gain[2] =
    mission_server_leader_followe_P.Gain_Gain *
    mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotatio.Angles[2];

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  mission_server_leader_followe_B.DataTypeConversion[0] =
    mission_server_leader_followe_B.OptiTrackTrackables_o4[0];
  mission_server_leader_followe_B.DataTypeConversion[1] =
    mission_server_leader_followe_B.OptiTrackTrackables_o4[1];

  /* Gain: '<S12>/Convert Optitrack frame to Right-Hand Convention' */
  mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightHan[0] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[3];
  mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[1] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightHan[1] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[4];
  mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightHan[2] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[5];

  /* Gain: '<S11>/Convert Optitrack frame to Right-Hand Convention' */
  mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[0] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightH_j[0] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[0];
  mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[1] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightH_j[1] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[1];
  mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[2] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightH_j[2] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[2];

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Toggle High'
   *  Constant: '<Root>/Toggle Low'
   */
  if (mission_server_leader_followe_P.ManualSwitch_CurrentSetting == 1) {
    mission_server_leader_followe_B.ManualSwitch =
      mission_server_leader_followe_P.ToggleHigh_Value;
  } else {
    mission_server_leader_followe_B.ManualSwitch =
      mission_server_leader_followe_P.ToggleLow_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Constant: '<S23>/Dummy Data' */
  mission_server_leader_followe_B.DummyData =
    mission_server_leader_followe_P.DummyData_Value;

  /* MATLAB Function: '<S7>/Waypoint Scheduler' incorporates:
   *  Constant: '<Root>/Waypoints - x (m)'
   *  Constant: '<Root>/Waypoints - z (m)'
   */
  mission_serve_WaypointScheduler
    (mission_server_leader_followe_P.Waypointsxm_Value,
     mission_server_leader_followe_P.Waypointszm_Value,
     mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0],
     mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2],
     &mission_server_leader_followe_B.sf_WaypointScheduler,
     &mission_server_leader_follow_DW.sf_WaypointScheduler);

  /* ManualSwitch: '<S7>/Manual Switch2' incorporates:
   *  Constant: '<S7>/Default x (m)'
   */
  if (mission_server_leader_followe_P.ManualSwitch2_CurrentSetting == 1) {
    mission_server_leader_followe_B.ManualSwitch2 =
      mission_server_leader_followe_P.Defaultxm_Value;
  } else {
    mission_server_leader_followe_B.ManualSwitch2 =
      mission_server_leader_followe_B.sf_WaypointScheduler.x_ref;
  }

  /* End of ManualSwitch: '<S7>/Manual Switch2' */

  /* ManualSwitch: '<S7>/Manual Switch3' incorporates:
   *  Constant: '<S7>/Default z (m)'
   */
  if (mission_server_leader_followe_P.ManualSwitch3_CurrentSetting == 1) {
    mission_server_leader_followe_B.ManualSwitch3 =
      mission_server_leader_followe_P.Defaultzm_Value;
  } else {
    mission_server_leader_followe_B.ManualSwitch3 =
      mission_server_leader_followe_B.sf_WaypointScheduler.z_ref;
  }

  /* End of ManualSwitch: '<S7>/Manual Switch3' */

  /* Chart: '<S1>/Logic Chart' */
  /* Gateway: Logic Subsystem/Logic Chart */
  mission_server_leader_follow_DW.sfEvent_i = mission_server_le_CALL_EVENT_p3;
  mission_server_leader_follow_DW.start_stop_prev_k =
    mission_server_leader_follow_DW.start_stop_start_f;
  mission_server_leader_follow_DW.start_stop_start_f =
    mission_server_leader_followe_B.ManualSwitch;

  /* During: Logic Subsystem/Logic Chart */
  if (mission_server_leader_follow_DW.is_active_c4_mission_server_lea == 0U) {
    mission_server_leader_follow_DW.start_stop_prev_k =
      mission_server_leader_followe_B.ManualSwitch;

    /* Entry: Logic Subsystem/Logic Chart */
    mission_server_leader_follow_DW.is_active_c4_mission_server_lea = 1U;

    /* Entry Internal: Logic Subsystem/Logic Chart */
    /* Transition: '<S9>:2' */
    mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
      mission__IN_WaitForStartCommand;
  } else if (mission_server_leader_follow_DW.is_c4_mission_server_leader_fol ==
             mission_se_IN_QbotGetsWaypoints) {
    /* During 'QbotGetsWaypoints': '<S9>:21' */
    if (mission_server_leader_follow_DW.start_stop_prev_k !=
        mission_server_leader_follow_DW.start_stop_start_f) {
      /* Transition: '<S9>:30' */
      mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
        mission__IN_WaitForStartCommand;
    } else {
      mission_server_leader_followe_B.x_ugv_ref_h =
        mission_server_leader_followe_B.ManualSwitch2;
      mission_server_leader_followe_B.z_ugv_ref_d =
        mission_server_leader_followe_B.ManualSwitch3;
    }
  } else {
    /* During 'WaitForStartCommand': '<S9>:1' */
    if (mission_server_leader_follow_DW.start_stop_prev_k !=
        mission_server_leader_follow_DW.start_stop_start_f) {
      /* Transition: '<S9>:19' */
      mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
        mission_se_IN_QbotGetsWaypoints;
    } else {
      mission_server_leader_followe_B.x_ugv_ref_h =
        mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0];
      mission_server_leader_followe_B.z_ugv_ref_d =
        mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2];
    }
  }

  /* End of Chart: '<S1>/Logic Chart' */

  /* Gain: '<S11>/Convert Optitrack orientation frame to Right-Hand Convention' incorporates:
   *  Product: '<S11>/Product'
   */
  unnamed_idx_0 =
    mission_server_leader_followe_P.ConvertOptitrackorientationfr_h[0] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[0];
  unnamed_idx_1 =
    mission_server_leader_followe_P.ConvertOptitrackorientationfr_h[1] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[1];
  unnamed_idx_2 =
    mission_server_leader_followe_P.ConvertOptitrackorientationfr_h[2] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[2];

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/Rotate Basis from UVS Orientation to Global Frame'
   *  Math: '<S11>/Inverse of Orthonormal Matrix is its Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_i[i] = 0.0;
    rtb_Product_i[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientation_m[3 * i] *
      unnamed_idx_0;
    rtb_Product_i[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientation_m[3 * i + 1]
      * unnamed_idx_1;
    rtb_Product_i[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientation_m[3 * i + 2]
      * unnamed_idx_2;
  }

  /* MATLAB Function: '<S14>/RotationMatrix_from_EulerAngles_yzx' */
  RotationMatrix_from_EulerAngles(rtb_Product_i[0], rtb_Product_i[1],
    rtb_Product_i[2],
    &mission_server_leader_followe_B.sf_RotationMatrix_from_EulerA_h);

  /* MATLAB Function: '<S13>/EulerAngles_zyx_from_RotationMatrix' incorporates:
   *  Constant: '<S11>/Default Dummy'
   */
  EulerAngles_zyx_from_RotationMa
    (mission_server_leader_followe_B.sf_RotationMatrix_from_EulerA_h.R,
     mission_server_leader_followe_P.DefaultDummy_Value_f,
     &mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotat_j);

  /* Constant: '<S21>/Dummy Data [3]' */
  mission_server_leader_followe_B.DummyData3[0] =
    mission_server_leader_followe_P.DummyData3_Value[0];
  mission_server_leader_followe_B.DummyData3[1] =
    mission_server_leader_followe_P.DummyData3_Value[1];
  mission_server_leader_followe_B.DummyData3[2] =
    mission_server_leader_followe_P.DummyData3_Value[2];

  /* Constant: '<S21>/Dummy Data' */
  mission_server_leader_followe_B.DummyData_o =
    mission_server_leader_followe_P.DummyData_Value_n;

  /* MATLAB Function: '<S8>/Waypoint Scheduler' incorporates:
   *  Constant: '<Root>/Waypoints - x (m)1'
   *  Constant: '<Root>/Waypoints - z (m)1'
   */
  mission_serve_WaypointScheduler
    (mission_server_leader_followe_P.Waypointsxm1_Value,
     mission_server_leader_followe_P.Waypointszm1_Value,
     mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[0],
     mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[2],
     &mission_server_leader_followe_B.sf_WaypointScheduler_e,
     &mission_server_leader_follow_DW.sf_WaypointScheduler_e);

  /* ManualSwitch: '<S8>/Manual Switch2' incorporates:
   *  Constant: '<S8>/Default x (m)'
   */
  if (mission_server_leader_followe_P.ManualSwitch2_CurrentSetting_b == 1) {
    mission_server_leader_followe_B.ManualSwitch2_g =
      mission_server_leader_followe_P.Defaultxm_Value_d;
  } else {
    mission_server_leader_followe_B.ManualSwitch2_g =
      mission_server_leader_followe_B.sf_WaypointScheduler_e.x_ref;
  }

  /* End of ManualSwitch: '<S8>/Manual Switch2' */

  /* ManualSwitch: '<S8>/Manual Switch3' incorporates:
   *  Constant: '<S8>/Default z (m)'
   */
  if (mission_server_leader_followe_P.ManualSwitch3_CurrentSetting_k == 1) {
    mission_server_leader_followe_B.ManualSwitch3_h =
      mission_server_leader_followe_P.Defaultzm_Value_p;
  } else {
    mission_server_leader_followe_B.ManualSwitch3_h =
      mission_server_leader_followe_B.sf_WaypointScheduler_e.z_ref;
  }

  /* End of ManualSwitch: '<S8>/Manual Switch3' */

  /* Chart: '<S2>/Logic Chart' */
  /* Gateway: Logic Subsystem1/Logic Chart */
  mission_server_leader_follow_DW.sfEvent = mission_server_le_CALL_EVENT_p3;
  mission_server_leader_follow_DW.start_stop_prev =
    mission_server_leader_follow_DW.start_stop_start;
  mission_server_leader_follow_DW.start_stop_start =
    mission_server_leader_followe_B.ManualSwitch;

  /* During: Logic Subsystem1/Logic Chart */
  if (mission_server_leader_follow_DW.is_active_c1_mission_server_lea == 0U) {
    mission_server_leader_follow_DW.start_stop_prev =
      mission_server_leader_followe_B.ManualSwitch;

    /* Entry: Logic Subsystem1/Logic Chart */
    mission_server_leader_follow_DW.is_active_c1_mission_server_lea = 1U;

    /* Entry Internal: Logic Subsystem1/Logic Chart */
    /* Transition: '<S10>:2' */
    mission_server_leader_follow_DW.is_c1_mission_server_leader_fol =
      mission__IN_WaitForStartCommand;
  } else if (mission_server_leader_follow_DW.is_c1_mission_server_leader_fol ==
             mission_se_IN_QbotGetsWaypoints) {
    /* During 'QbotGetsWaypoints': '<S10>:21' */
    if (mission_server_leader_follow_DW.start_stop_prev !=
        mission_server_leader_follow_DW.start_stop_start) {
      /* Transition: '<S10>:30' */
      mission_server_leader_follow_DW.is_c1_mission_server_leader_fol =
        mission__IN_WaitForStartCommand;
    } else {
      mission_server_leader_followe_B.x_ugv_ref =
        mission_server_leader_followe_B.ManualSwitch2_g;
      mission_server_leader_followe_B.z_ugv_ref =
        mission_server_leader_followe_B.ManualSwitch3_h;
    }
  } else {
    /* During 'WaitForStartCommand': '<S10>:1' */
    if (mission_server_leader_follow_DW.start_stop_prev !=
        mission_server_leader_follow_DW.start_stop_start) {
      /* Transition: '<S10>:19' */
      mission_server_leader_follow_DW.is_c1_mission_server_leader_fol =
        mission_se_IN_QbotGetsWaypoints;
    } else {
      mission_server_leader_followe_B.x_ugv_ref =
        mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[0];
      mission_server_leader_followe_B.z_ugv_ref =
        mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[2];
    }
  }

  /* End of Chart: '<S2>/Logic Chart' */

  /* SignalConversion: '<S5>/TmpSignal ConversionAtStream Server2Inport1' */
  rtb_TmpSignalConversionAtStream[0] = mission_server_leader_followe_B.x_ugv_ref;
  rtb_TmpSignalConversionAtStream[1] = mission_server_leader_followe_B.z_ugv_ref;
  rtb_TmpSignalConversionAtStream[2] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[0];
  rtb_TmpSignalConversionAtStream[3] =
    mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotat_j.Angles[2];
  rtb_TmpSignalConversionAtStream[4] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[2];
  rtb_TmpSignalConversionAtStream[5] =
    mission_server_leader_followe_B.DataTypeConversion[0];

  /* S-Function (stream_server_block): '<S5>/Stream Server2' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Follower/Stream Server2 (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    if (mission_server_leader_followe_P.Enable1_Value) {
      send_result = pstream_send
        (mission_server_leader_follow_DW.StreamServer2_Stream,
         &rtb_TmpSignalConversionAtStream[0]);
    } else {
      send_result = 0;
    }

    mission_server_leader_followe_B.StreamServer2_o3 = (send_result > 0);
    mission_server_leader_followe_B.StreamServer2_o2 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      mission_server_leader_followe_B.StreamServer2_o2 = send_result;
    }

    pstream_get_state(mission_server_leader_follow_DW.StreamServer2_Stream,
                      &state);
    mission_server_leader_followe_B.StreamServer2_o1 = state;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtStream ServerInport1' */
  rtb_TmpSignalConversionAtStream[0] =
    mission_server_leader_followe_B.x_ugv_ref_h;
  rtb_TmpSignalConversionAtStream[1] =
    mission_server_leader_followe_B.z_ugv_ref_d;
  rtb_TmpSignalConversionAtStream[2] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0];
  rtb_TmpSignalConversionAtStream[3] =
    mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotatio.Angles[2];
  rtb_TmpSignalConversionAtStream[4] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2];
  rtb_TmpSignalConversionAtStream[5] =
    mission_server_leader_followe_B.DataTypeConversion[1];

  /* S-Function (stream_server_block): '<S6>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Leader/Stream Server (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    if (mission_server_leader_followe_P.Enable_Value) {
      send_result = pstream_send
        (mission_server_leader_follow_DW.StreamServer_Stream,
         &rtb_TmpSignalConversionAtStream[0]);
    } else {
      send_result = 0;
    }

    mission_server_leader_followe_B.StreamServer_o3 = (send_result > 0);
    mission_server_leader_followe_B.StreamServer_o2 = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      mission_server_leader_followe_B.StreamServer_o2 = send_result;
    }

    pstream_get_state(mission_server_leader_follow_DW.StreamServer_Stream,
                      &state);
    mission_server_leader_followe_B.StreamServer_o1 = state;
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(0, mission_server_leader_follow_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.002s, 0.0s] */
    if ((rtmGetTFinal(mission_server_leader_follow_M)!=-1) &&
        !((rtmGetTFinal(mission_server_leader_follow_M)-
           mission_server_leader_follow_M->Timing.taskTime0) >
          mission_server_leader_follow_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(mission_server_leader_follow_M, "Simulation finished");
    }

    if (rtmGetStopRequested(mission_server_leader_follow_M)) {
      rtmSetErrorStatus(mission_server_leader_follow_M, "Simulation finished");
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
  if (!(++mission_server_leader_follow_M->Timing.clockTick0)) {
    ++mission_server_leader_follow_M->Timing.clockTickH0;
  }

  mission_server_leader_follow_M->Timing.taskTime0 =
    mission_server_leader_follow_M->Timing.clockTick0 *
    mission_server_leader_follow_M->Timing.stepSize0 +
    mission_server_leader_follow_M->Timing.clockTickH0 *
    mission_server_leader_follow_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void mission_server_leader_follower_qbot2_qbot2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mission_server_leader_follow_M, 0,
                sizeof(RT_MODEL_mission_server_leade_T));
  rtmSetTFinal(mission_server_leader_follow_M, -1);
  mission_server_leader_follow_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  mission_server_leader_follow_M->Sizes.checksums[0] = (2367507700U);
  mission_server_leader_follow_M->Sizes.checksums[1] = (2204280479U);
  mission_server_leader_follow_M->Sizes.checksums[2] = (1582393253U);
  mission_server_leader_follow_M->Sizes.checksums[3] = (1197094014U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    mission_server_leader_follow_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(mission_server_leader_follow_M->extModeInfo,
      &mission_server_leader_follow_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(mission_server_leader_follow_M->extModeInfo,
                        mission_server_leader_follow_M->Sizes.checksums);
    rteiSetTPtr(mission_server_leader_follow_M->extModeInfo, rtmGetTPtr
                (mission_server_leader_follow_M));
  }

  /* block I/O */
  (void) memset(((void *) &mission_server_leader_followe_B), 0,
                sizeof(B_mission_server_leader_follo_T));

  /* states (dwork) */
  (void) memset((void *)&mission_server_leader_follow_DW, 0,
                sizeof(DW_mission_server_leader_foll_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    mission_server_leader_follow_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (optitrack_rigid_body_position_block): '<S3>/OptiTrack Trackables' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result;
    result = optitrack_rb_initialize
      (&mission_server_leader_follow_DW.OptiTrackTrackables_Optitrack,
       "C:\\Users\\user\\Desktop\\final\\Calibration Very High Quality Exceptional (MeanErr 0.001 mm) 2017-05-16 6.48pm.cal",
       "C:\\Users\\user\\Desktop\\final\\RigidBodies 2017-05-26 5.36pm_qbotx2.tra");
    if (result == 0) {
      result = optitrack_set_rigid_body_ids
        (mission_server_leader_follow_DW.OptiTrackTrackables_Optitrack,
         mission_server_leader_fo_ConstP.OptiTrackTrackables_R, 2);
    }

    if (result < 0) {
      optitrack_rb_close
        (mission_server_leader_follow_DW.OptiTrackTrackables_Optitrack);
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_leader_follow_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_server_block): '<S5>/Stream Server2' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Follower/Stream Server2 (stream_server_block) */
  {
    qthread_attr_t send_thread_attributes;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    t_pstream_options options;
    t_error result;
    mission_server_leader_follow_DW.StreamServer2_Stream = NULL;
    result = 0;
    options.size = sizeof(options);
    options.flags = mission_server_leader_followe_P.StreamServer2_Endian &
      PSTREAM_FLAG_ENDIAN_MASK;
    if (mission_server_leader_followe_P.StreamServer2_Implementation ==
        STREAM_SERVER_IMPLEMENTATION_THREAD) {
      options.flags |= PSTREAM_FLAG_MULTITHREADED;
    }

    if (mission_server_leader_followe_P.StreamServer2_Optimize ==
        STREAM_SERVER_OPTIMIZE_LATENCY) {
      options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
    }

    options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
    options.send_unit_size = 8;
    options.num_send_units = 6;
    options.send_buffer_size =
      mission_server_leader_followe_P.StreamServer2_SndSize;
    options.send_fifo_size =
      mission_server_leader_followe_P.StreamServer2_SndFIFO;
    options.num_send_dimensions = 0;
    options.max_send_dimensions = NULL;
    if (mission_server_leader_followe_P.StreamServer2_SndPriority < min_priority)
    {
      scheduling_parameters.sched_priority = min_priority;
    } else if (mission_server_leader_followe_P.StreamServer2_SndPriority >
               max_priority) {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        mission_server_leader_followe_P.StreamServer2_SndPriority;
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
          rtmSetErrorStatus(mission_server_leader_follow_M,
                            "Unable to set scheduling inheritance for Stream Client sending thread");
        }
      } else {
        rtmSetErrorStatus(mission_server_leader_follow_M,
                          "The specified thread priority for the Stream Client sending thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(mission_server_leader_follow_M,
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
        mission_server_leader_followe_P.StreamServer2_URI, &options,
        &mission_server_leader_follow_DW.StreamServer2_Stream);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(mission_server_leader_follow_M, _rt_error_message);
      }
    }

    qthread_attr_destroy(&send_thread_attributes);
  }

  /* Start for S-Function (stream_server_block): '<S6>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Leader/Stream Server (stream_server_block) */
  {
    qthread_attr_t send_thread_attributes;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    t_pstream_options options;
    t_error result;
    mission_server_leader_follow_DW.StreamServer_Stream = NULL;
    result = 0;
    options.size = sizeof(options);
    options.flags = mission_server_leader_followe_P.StreamServer_Endian &
      PSTREAM_FLAG_ENDIAN_MASK;
    if (mission_server_leader_followe_P.StreamServer_Implementation ==
        STREAM_SERVER_IMPLEMENTATION_THREAD) {
      options.flags |= PSTREAM_FLAG_MULTITHREADED;
    }

    if (mission_server_leader_followe_P.StreamServer_Optimize ==
        STREAM_SERVER_OPTIMIZE_LATENCY) {
      options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
    }

    options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
    options.send_unit_size = 8;
    options.num_send_units = 6;
    options.send_buffer_size =
      mission_server_leader_followe_P.StreamServer_SndSize;
    options.send_fifo_size =
      mission_server_leader_followe_P.StreamServer_SndFIFO;
    options.num_send_dimensions = 0;
    options.max_send_dimensions = NULL;
    if (mission_server_leader_followe_P.StreamServer_SndPriority < min_priority)
    {
      scheduling_parameters.sched_priority = min_priority;
    } else if (mission_server_leader_followe_P.StreamServer_SndPriority >
               max_priority) {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        mission_server_leader_followe_P.StreamServer_SndPriority;
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
          rtmSetErrorStatus(mission_server_leader_follow_M,
                            "Unable to set scheduling inheritance for Stream Client sending thread");
        }
      } else {
        rtmSetErrorStatus(mission_server_leader_follow_M,
                          "The specified thread priority for the Stream Client sending thread is not valid for this target");
      }
    } else {
      rtmSetErrorStatus(mission_server_leader_follow_M,
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
        mission_server_leader_followe_P.StreamServer_URI, &options,
        &mission_server_leader_follow_DW.StreamServer_Stream);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(mission_server_leader_follow_M, _rt_error_message);
      }
    }

    qthread_attr_destroy(&send_thread_attributes);
  }

  /* InitializeConditions for MATLAB Function: '<S7>/Waypoint Scheduler' */
  mission__WaypointScheduler_Init
    (&mission_server_leader_follow_DW.sf_WaypointScheduler);

  /* InitializeConditions for Chart: '<S1>/Logic Chart' */
  mission_server_leader_follow_DW.sfEvent_i = mission_server_le_CALL_EVENT_p3;
  mission_server_leader_follow_DW.is_active_c4_mission_server_lea = 0U;
  mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
    mission_serv_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for MATLAB Function: '<S8>/Waypoint Scheduler' */
  mission__WaypointScheduler_Init
    (&mission_server_leader_follow_DW.sf_WaypointScheduler_e);

  /* InitializeConditions for Chart: '<S2>/Logic Chart' */
  mission_server_leader_follow_DW.sfEvent = mission_server_le_CALL_EVENT_p3;
  mission_server_leader_follow_DW.is_active_c1_mission_server_lea = 0U;
  mission_server_leader_follow_DW.is_c1_mission_server_leader_fol =
    mission_serv_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void mission_server_leader_follower_qbot2_qbot2_terminate(void)
{
  /* Terminate for S-Function (optitrack_rigid_body_position_block): '<S3>/OptiTrack Trackables' */
  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/OptiTrack Measurements/OptiTrack Trackables (optitrack_rigid_body_position_block) */
  {
    t_error result;
    if ((result = optitrack_rb_close
         (mission_server_leader_follow_DW.OptiTrackTrackables_Optitrack)) < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(mission_server_leader_follow_M, _rt_error_message);
    }
  }

  /* Terminate for S-Function (stream_server_block): '<S5>/Stream Server2' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Follower/Stream Server2 (stream_server_block) */
  {
    if (mission_server_leader_follow_DW.StreamServer2_Stream != NULL) {
      pstream_close(mission_server_leader_follow_DW.StreamServer2_Stream);
    }

    mission_server_leader_follow_DW.StreamServer2_Stream = NULL;
  }

  /* Terminate for S-Function (stream_server_block): '<S6>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Leader/Stream Server (stream_server_block) */
  {
    if (mission_server_leader_follow_DW.StreamServer_Stream != NULL) {
      pstream_close(mission_server_leader_follow_DW.StreamServer_Stream);
    }

    mission_server_leader_follow_DW.StreamServer_Stream = NULL;
  }
}
