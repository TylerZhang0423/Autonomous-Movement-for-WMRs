/*
 * mission_server_leader_follower_qbot2_qbot2.c
 *
 * Code generation for model "mission_server_leader_follower_qbot2_qbot2".
 *
 * Model version              : 1.50
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 17:52:37 2017
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
 *    '<S10>/EulerAngles_zyx_from_RotationMatrix'
 *    '<S14>/EulerAngles_zyx_from_RotationMatrix'
 */
void EulerAngles_zyx_from_RotationMa(const real_T rtu_R[9], real_T rtu_auxAngle,
  B_EulerAngles_zyx_from_Rotati_T *localB)
{
  real_T roll;
  real_T yaw;
  real_T RollYaw;
  real_T x;

  /* MATLAB Function 'EulerAngles_ZYX_from_RotationMatrix/EulerAngles_zyx_from_RotationMatrix': '<S12>:1' */
  /*  Extract the Euler angles (Z-Y-X) from rotatin matrix */
  /*  Assumption:  */
  /*  The rotation matrix is defined as: */
  /*  */
  /*  r0 = R . r1 */
  /*  */
  /*  where r1 is a vector expressed in the rotated frame */
  /*    r0 is the vector expressed in the reference frame */
  /*  Setting the singularity tolerance */
  /* '<S12>:1:14' */
  /*  Extract Euler angles from the rotation matrix */
  /* '<S12>:1:17' */
  x = asin(rtu_R[2]);
  if (1.0 - fabs(rtu_R[2]) > 2.2204460492503131E-16) {
    /* '<S12>:1:18' */
    /*  Not at Euler singularity */
    /* '<S12>:1:20' */
    /* '<S12>:1:21' */
    roll = rt_atan2d_snf(rtu_R[5], rtu_R[8]);

    /* '<S12>:1:22' */
    yaw = rt_atan2d_snf(rtu_R[1], rtu_R[0]);
  } else {
    /*  At Euler singularity */
    /* '<S12>:1:25' */
    /*  Roll and Yaw are ambiguous. */
    /*  Use the optional angular measurement to resolve the ambiguity */
    /* '<S12>:1:29' */
    RollYaw = acos(rtu_R[4]);
    if (-x > 0.0) {
      /* '<S12>:1:31' */
      /*  pitch is +pi/2 */
      /*  RollYaw = Roll + Yaw */
      /*  Therefore, */
      /*  Roll = RollYaw - Yaw */
      /*  Or  */
      /*  Yaw = RollYaw - Roll */
      if (rtu_auxAngle != 0.0) {
        /* '<S12>:1:38' */
        /*  Roll Aux measurement available */
        /* '<S12>:1:39' */
        roll = rtu_auxAngle;

        /* '<S12>:1:40' */
        yaw = RollYaw - rtu_auxAngle;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S12>:1:42' */
        yaw = 0.0;

        /* '<S12>:1:43' */
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
        /* '<S12>:1:52' */
        /*  Roll Aux measurement available */
        /* '<S12>:1:53' */
        roll = rtu_auxAngle;

        /* '<S12>:1:54' */
        yaw = -RollYaw + rtu_auxAngle;
      } else {
        /*  Yaw Aux measurement available */
        /* '<S12>:1:56' */
        yaw = 0.0;

        /* '<S12>:1:57' */
        roll = RollYaw;
      }
    }
  }

  /* '<S12>:1:62' */
  localB->Angles[0] = roll;
  localB->Angles[1] = -x;
  localB->Angles[2] = yaw;
}

/*
 * Output and update for atomic system:
 *    '<S11>/RotationMatrix_from_EulerAngles_yzx'
 *    '<S15>/RotationMatrix_from_EulerAngles_yzx'
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

  /* MATLAB Function 'RotationMatrix_from_EulerAngles_YZX/RotationMatrix_from_EulerAngles_yzx': '<S13>:1' */
  /*  Create rotation matrix from Euler (Y,Z, X) convention. */
  /* '<S13>:1:6' */
  sRoll = sin(rtu_roll);

  /* '<S13>:1:7' */
  cRoll = cos(rtu_roll);

  /* '<S13>:1:8' */
  sPitch = sin(rtu_pitch);

  /* '<S13>:1:9' */
  cPitch = cos(rtu_pitch);

  /* '<S13>:1:10' */
  sYaw = sin(rtu_yaw);

  /* '<S13>:1:11' */
  cYaw = cos(rtu_yaw);

  /* '<S13>:1:13' */
  /* '<S13>:1:15' */
  /* '<S13>:1:17' */
  /* '<S13>:1:18' */
  /* '<S13>:1:19' */
  /* '<S13>:1:21' */
  /* '<S13>:1:22' */
  /* '<S13>:1:23' */
  /* '<S13>:1:25' */
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

/* Model step function */
void mission_server_leader_follower_qbot2_qbot2_step(void)
{
  /* local block i/o variables */
  real_T rtb_Product[3];
  real_T rtb_Product_i[3];
  real_T rtb_TmpSignalConversionAtStream[4];
  real_T rtb_TmpSignalConversionAtStre_p[6];
  real_T dist;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T i;

  /* S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */

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

  /* Gain: '<S9>/Convert Optitrack orientation frame to Right-Hand Convention' incorporates:
   *  Product: '<S9>/Product'
   */
  scale = mission_server_leader_followe_P.ConvertOptitrackorientationfram[0] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[3];
  absxk = mission_server_leader_followe_P.ConvertOptitrackorientationfram[1] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[4];
  t = mission_server_leader_followe_P.ConvertOptitrackorientationfram[2] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[5];

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/Rotate Basis from UVS Orientation to Global Frame'
   *  Math: '<S9>/Inverse of Orthonormal Matrix is its Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product[i] = 0.0;
    rtb_Product[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientationto[3 * i] *
      scale;
    rtb_Product[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientationto[3 * i + 1]
      * absxk;
    rtb_Product[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientationto[3 * i + 2]
      * t;
  }

  /* MATLAB Function: '<S15>/RotationMatrix_from_EulerAngles_yzx' */
  RotationMatrix_from_EulerAngles(rtb_Product[0], rtb_Product[1], rtb_Product[2],
    &mission_server_leader_followe_B.sf_RotationMatrix_from_EulerAng);

  /* MATLAB Function: '<S14>/EulerAngles_zyx_from_RotationMatrix' incorporates:
   *  Constant: '<S9>/Default Dummy'
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

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  mission_server_leader_followe_B.DataTypeConversion[0] =
    mission_server_leader_followe_B.OptiTrackTrackables_o4[0];
  mission_server_leader_followe_B.DataTypeConversion[1] =
    mission_server_leader_followe_B.OptiTrackTrackables_o4[1];

  /* Gain: '<S9>/Convert Optitrack frame to Right-Hand Convention' */
  mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightHan[0] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[3];
  mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[1] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightHan[1] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[4];
  mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2] =
    mission_server_leader_followe_P.ConvertOptitrackframetoRightHan[2] *
    mission_server_leader_followe_B.OptiTrackTrackables_o1[5];

  /* Gain: '<S8>/Convert Optitrack frame to Right-Hand Convention' */
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

  /* Constant: '<S20>/Dummy Data' */
  mission_server_leader_followe_B.DummyData =
    mission_server_leader_followe_P.DummyData_Value;

  /* MATLAB Function: '<S6>/Waypoint Scheduler' incorporates:
   *  Constant: '<Root>/Waypoints - x (m)'
   *  Constant: '<Root>/Waypoints - z (m)'
   */
  /* MATLAB Function 'Trajectory Generation/Waypoint Scheduler': '<S21>:1' */
  /*  This function generates a trajectory to be tracked based on a vector of */
  /*  waypoint positions that get passed in. We increment the */
  /*  index into the waypoint vector once the vehicle has got to within a */
  /*  pre-determined threshold of the waypoint.  */
  /* '<S21>:1:15' */
  mission_server_leader_followe_B.mission_complete = 0.0;

  /*  The distance below which we switch to the next waypoint: */
  /* '<S21>:1:18' */
  /*  Check if we're still far enough away from the waypoint: */
  /* '<S21>:1:21' */
  scale = 2.2250738585072014E-308;
  absxk = fabs(mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0]
               - mission_server_leader_followe_P.Waypointsxm_Value[(int32_T)
               mission_server_leader_follow_DW.idx - 1]);
  if (absxk > 2.2250738585072014E-308) {
    dist = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    dist = t * t;
  }

  absxk = fabs(mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2]
               - mission_server_leader_followe_P.Waypointszm_Value[(int32_T)
               mission_server_leader_follow_DW.idx - 1]);
  if (absxk > scale) {
    t = scale / absxk;
    dist = dist * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    dist += t * t;
  }

  dist = scale * sqrt(dist);
  if ((dist > 0.15) || (mission_server_leader_follow_DW.idx == 5.0)) {
    /* '<S21>:1:23' */
    /* '<S21>:1:24' */
    dist = mission_server_leader_followe_P.Waypointsxm_Value[(int32_T)
      mission_server_leader_follow_DW.idx - 1];

    /* '<S21>:1:25' */
    scale = mission_server_leader_followe_P.Waypointszm_Value[(int32_T)
      mission_server_leader_follow_DW.idx - 1];
  } else {
    /*  Move to the next waypoint */
    /* '<S21>:1:27' */
    mission_server_leader_follow_DW.idx++;

    /* '<S21>:1:28' */
    dist = mission_server_leader_followe_P.Waypointsxm_Value[(int32_T)
      mission_server_leader_follow_DW.idx - 1];

    /* '<S21>:1:29' */
    scale = mission_server_leader_followe_P.Waypointszm_Value[(int32_T)
      mission_server_leader_follow_DW.idx - 1];
  }

  /* '<S21>:1:32' */
  mission_server_leader_followe_B.waypoint_num =
    mission_server_leader_follow_DW.idx;

  /*  Check if the mission is finished: */
  if (mission_server_leader_follow_DW.idx == 5.0) {
    /* '<S21>:1:35' */
    /* '<S21>:1:36' */
    mission_server_leader_followe_B.mission_complete = 1.0;
  }

  /* End of MATLAB Function: '<S6>/Waypoint Scheduler' */

  /* ManualSwitch: '<S6>/Manual Switch2' incorporates:
   *  Constant: '<S6>/Default x (m)'
   */
  if (mission_server_leader_followe_P.ManualSwitch2_CurrentSetting == 1) {
    mission_server_leader_followe_B.ManualSwitch2 =
      mission_server_leader_followe_P.Defaultxm_Value;
  } else {
    mission_server_leader_followe_B.ManualSwitch2 = dist;
  }

  /* End of ManualSwitch: '<S6>/Manual Switch2' */

  /* ManualSwitch: '<S6>/Manual Switch3' incorporates:
   *  Constant: '<S6>/Default z (m)'
   */
  if (mission_server_leader_followe_P.ManualSwitch3_CurrentSetting == 1) {
    mission_server_leader_followe_B.ManualSwitch3 =
      mission_server_leader_followe_P.Defaultzm_Value;
  } else {
    mission_server_leader_followe_B.ManualSwitch3 = scale;
  }

  /* End of ManualSwitch: '<S6>/Manual Switch3' */

  /* Chart: '<S1>/Logic Chart' */
  /* Gateway: Logic Subsystem/Logic Chart */
  mission_server_leader_follow_DW.sfEvent = mission_server_le_CALL_EVENT_p3;
  mission_server_leader_follow_DW.start_stop_prev =
    mission_server_leader_follow_DW.start_stop_start;
  mission_server_leader_follow_DW.start_stop_start =
    mission_server_leader_followe_B.ManualSwitch;

  /* During: Logic Subsystem/Logic Chart */
  if (mission_server_leader_follow_DW.is_active_c4_mission_server_lea == 0U) {
    mission_server_leader_follow_DW.start_stop_prev =
      mission_server_leader_followe_B.ManualSwitch;

    /* Entry: Logic Subsystem/Logic Chart */
    mission_server_leader_follow_DW.is_active_c4_mission_server_lea = 1U;

    /* Entry Internal: Logic Subsystem/Logic Chart */
    /* Transition: '<S7>:2' */
    mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
      mission__IN_WaitForStartCommand;
  } else if (mission_server_leader_follow_DW.is_c4_mission_server_leader_fol ==
             mission_se_IN_QbotGetsWaypoints) {
    /* During 'QbotGetsWaypoints': '<S7>:21' */
    if (mission_server_leader_follow_DW.start_stop_prev !=
        mission_server_leader_follow_DW.start_stop_start) {
      /* Transition: '<S7>:30' */
      mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
        mission__IN_WaitForStartCommand;
    } else {
      mission_server_leader_followe_B.x_ugv_ref =
        mission_server_leader_followe_B.ManualSwitch2;
      mission_server_leader_followe_B.z_ugv_ref =
        mission_server_leader_followe_B.ManualSwitch3;
    }
  } else {
    /* During 'WaitForStartCommand': '<S7>:1' */
    if (mission_server_leader_follow_DW.start_stop_prev !=
        mission_server_leader_follow_DW.start_stop_start) {
      /* Transition: '<S7>:19' */
      mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
        mission_se_IN_QbotGetsWaypoints;
    } else {
      mission_server_leader_followe_B.x_ugv_ref =
        mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0];
      mission_server_leader_followe_B.z_ugv_ref =
        mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2];
    }
  }

  /* End of Chart: '<S1>/Logic Chart' */

  /* Gain: '<S8>/Convert Optitrack orientation frame to Right-Hand Convention' incorporates:
   *  Product: '<S8>/Product'
   */
  scale = mission_server_leader_followe_P.ConvertOptitrackorientationfr_h[0] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[0];
  absxk = mission_server_leader_followe_P.ConvertOptitrackorientationfr_h[1] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[1];
  t = mission_server_leader_followe_P.ConvertOptitrackorientationfr_h[2] *
    mission_server_leader_followe_B.OptiTrackTrackables_o3[2];

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Rotate Basis from UVS Orientation to Global Frame'
   *  Math: '<S8>/Inverse of Orthonormal Matrix is its Transpose'
   */
  for (i = 0; i < 3; i++) {
    rtb_Product_i[i] = 0.0;
    rtb_Product_i[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientation_m[3 * i] *
      scale;
    rtb_Product_i[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientation_m[3 * i + 1]
      * absxk;
    rtb_Product_i[i] +=
      mission_server_leader_followe_P.RotateBasisfromUVSOrientation_m[3 * i + 2]
      * t;
  }

  /* MATLAB Function: '<S11>/RotationMatrix_from_EulerAngles_yzx' */
  RotationMatrix_from_EulerAngles(rtb_Product_i[0], rtb_Product_i[1],
    rtb_Product_i[2],
    &mission_server_leader_followe_B.sf_RotationMatrix_from_EulerA_h);

  /* MATLAB Function: '<S10>/EulerAngles_zyx_from_RotationMatrix' incorporates:
   *  Constant: '<S8>/Default Dummy'
   */
  EulerAngles_zyx_from_RotationMa
    (mission_server_leader_followe_B.sf_RotationMatrix_from_EulerA_h.R,
     mission_server_leader_followe_P.DefaultDummy_Value_f,
     &mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotat_j);

  /* Constant: '<S18>/Dummy Data [3]' */
  mission_server_leader_followe_B.DummyData3[0] =
    mission_server_leader_followe_P.DummyData3_Value[0];
  mission_server_leader_followe_B.DummyData3[1] =
    mission_server_leader_followe_P.DummyData3_Value[1];
  mission_server_leader_followe_B.DummyData3[2] =
    mission_server_leader_followe_P.DummyData3_Value[2];

  /* Constant: '<S18>/Dummy Data' */
  mission_server_leader_followe_B.DummyData_o =
    mission_server_leader_followe_P.DummyData_Value_n;

  /* SignalConversion: '<S4>/TmpSignal ConversionAtStream ServerInport1' */
  rtb_TmpSignalConversionAtStream[0] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[0];
  rtb_TmpSignalConversionAtStream[1] =
    mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotat_j.Angles[2];
  rtb_TmpSignalConversionAtStream[2] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightH_d[2];
  rtb_TmpSignalConversionAtStream[3] =
    mission_server_leader_followe_B.DataTypeConversion[0];

  /* S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Follower/Stream Server (stream_server_block) */
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

  /* SignalConversion: '<S5>/TmpSignal ConversionAtStream ServerInport1' */
  rtb_TmpSignalConversionAtStre_p[0] = mission_server_leader_followe_B.x_ugv_ref;
  rtb_TmpSignalConversionAtStre_p[1] = mission_server_leader_followe_B.z_ugv_ref;
  rtb_TmpSignalConversionAtStre_p[2] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[0];
  rtb_TmpSignalConversionAtStre_p[3] =
    mission_server_leader_followe_B.sf_EulerAngles_zyx_from_Rotatio.Angles[2];
  rtb_TmpSignalConversionAtStre_p[4] =
    mission_server_leader_followe_B.ConvertOptitrackframetoRightHan[2];
  rtb_TmpSignalConversionAtStre_p[5] =
    mission_server_leader_followe_B.DataTypeConversion[1];

  /* S-Function (stream_server_block): '<S5>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Leader/Stream Server (stream_server_block) */
  {
    t_pstream_state state;
    t_error send_result;
    if (mission_server_leader_followe_P.Enable_Value_b) {
      send_result = pstream_send
        (mission_server_leader_follow_DW.StreamServer_Stream_e,
         &rtb_TmpSignalConversionAtStre_p[0]);
    } else {
      send_result = 0;
    }

    mission_server_leader_followe_B.StreamServer_o3_i = (send_result > 0);
    mission_server_leader_followe_B.StreamServer_o2_c = 0;
    if (send_result < 0 && send_result != -QERR_WOULD_BLOCK) {
      mission_server_leader_followe_B.StreamServer_o2_c = send_result;
    }

    pstream_get_state(mission_server_leader_follow_DW.StreamServer_Stream_e,
                      &state);
    mission_server_leader_followe_B.StreamServer_o1_e = state;
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
  mission_server_leader_follow_M->Sizes.checksums[0] = (959270900U);
  mission_server_leader_follow_M->Sizes.checksums[1] = (2501020908U);
  mission_server_leader_follow_M->Sizes.checksums[2] = (1079117191U);
  mission_server_leader_follow_M->Sizes.checksums[3] = (2830755330U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    mission_server_leader_follow_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
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

  /* Start for S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */

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

  /* Start for S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Follower/Stream Server (stream_server_block) */
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
    options.num_send_units = 4;
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

  /* Start for S-Function (stream_server_block): '<S5>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Leader/Stream Server (stream_server_block) */
  {
    qthread_attr_t send_thread_attributes;
    struct qsched_param scheduling_parameters;
    int min_priority = qsched_get_priority_min(QSCHED_FIFO);
    int max_priority = qsched_get_priority_max(QSCHED_FIFO);
    t_pstream_options options;
    t_error result;
    mission_server_leader_follow_DW.StreamServer_Stream_e = NULL;
    result = 0;
    options.size = sizeof(options);
    options.flags = mission_server_leader_followe_P.StreamServer_Endian_e &
      PSTREAM_FLAG_ENDIAN_MASK;
    if (mission_server_leader_followe_P.StreamServer_Implementation_p ==
        STREAM_SERVER_IMPLEMENTATION_THREAD) {
      options.flags |= PSTREAM_FLAG_MULTITHREADED;
    }

    if (mission_server_leader_followe_P.StreamServer_Optimize_d ==
        STREAM_SERVER_OPTIMIZE_LATENCY) {
      options.flags |= PSTREAM_FLAG_MINIMIZE_LATENCY;
    }

    options.flags |= PSTREAM_FLAG_SEND_MOST_RECENT;
    options.send_unit_size = 8;
    options.num_send_units = 6;
    options.send_buffer_size =
      mission_server_leader_followe_P.StreamServer_SndSize_a;
    options.send_fifo_size =
      mission_server_leader_followe_P.StreamServer_SndFIFO_m;
    options.num_send_dimensions = 0;
    options.max_send_dimensions = NULL;
    if (mission_server_leader_followe_P.StreamServer_SndPriority_n <
        min_priority) {
      scheduling_parameters.sched_priority = min_priority;
    } else if (mission_server_leader_followe_P.StreamServer_SndPriority_n >
               max_priority) {
      scheduling_parameters.sched_priority = max_priority;
    } else {
      scheduling_parameters.sched_priority =
        mission_server_leader_followe_P.StreamServer_SndPriority_n;
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
        mission_server_leader_followe_P.StreamServer_URI_a, &options,
        &mission_server_leader_follow_DW.StreamServer_Stream_e);
      if (result < 0 && result != -QERR_WOULD_BLOCK) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(mission_server_leader_follow_M, _rt_error_message);
      }
    }

    qthread_attr_destroy(&send_thread_attributes);
  }

  /* InitializeConditions for MATLAB Function: '<S6>/Waypoint Scheduler' */
  mission_server_leader_follow_DW.idx = 1.0;

  /* InitializeConditions for Chart: '<S1>/Logic Chart' */
  mission_server_leader_follow_DW.sfEvent = mission_server_le_CALL_EVENT_p3;
  mission_server_leader_follow_DW.is_active_c4_mission_server_lea = 0U;
  mission_server_leader_follow_DW.is_c4_mission_server_leader_fol =
    mission_serv_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void mission_server_leader_follower_qbot2_qbot2_terminate(void)
{
  /* Terminate for S-Function (optitrack_rigid_body_position_block): '<S2>/OptiTrack Trackables' */
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

  /* Terminate for S-Function (stream_server_block): '<S4>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Follower/Stream Server (stream_server_block) */
  {
    if (mission_server_leader_follow_DW.StreamServer_Stream != NULL) {
      pstream_close(mission_server_leader_follow_DW.StreamServer_Stream);
    }

    mission_server_leader_follow_DW.StreamServer_Stream = NULL;
  }

  /* Terminate for S-Function (stream_server_block): '<S5>/Stream Server' */

  /* S-Function Block: mission_server_leader_follower_qbot2_qbot2/Serve Data For Leader/Stream Server (stream_server_block) */
  {
    if (mission_server_leader_follow_DW.StreamServer_Stream_e != NULL) {
      pstream_close(mission_server_leader_follow_DW.StreamServer_Stream_e);
    }

    mission_server_leader_follow_DW.StreamServer_Stream_e = NULL;
  }
}
