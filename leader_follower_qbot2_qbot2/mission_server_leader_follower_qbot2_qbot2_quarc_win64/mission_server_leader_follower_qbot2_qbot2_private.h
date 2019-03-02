/*
 * mission_server_leader_follower_qbot2_qbot2_private.h
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
#ifndef RTW_HEADER_mission_server_leader_follower_qbot2_qbot2_private_h_
#define RTW_HEADER_mission_server_leader_follower_qbot2_qbot2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void EulerAngles_zyx_from_RotationMa(const real_T rtu_R[9], real_T
  rtu_auxAngle, B_EulerAngles_zyx_from_Rotati_T *localB);
extern void RotationMatrix_from_EulerAngles(real_T rtu_roll, real_T rtu_pitch,
  real_T rtu_yaw, B_RotationMatrix_from_EulerAn_T *localB);

#endif                                 /* RTW_HEADER_mission_server_leader_follower_qbot2_qbot2_private_h_ */
