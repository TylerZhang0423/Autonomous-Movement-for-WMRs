/*
 * leader_qball2_private.h
 *
 * Code generation for model "leader_qball2".
 *
 * Model version              : 1.898
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri May 26 19:34:49 2017
 *
 * Target selection: quarc_linux_duovero.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_leader_qball2_private_h_
#define RTW_HEADER_leader_qball2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void leade_EnabledMovingAverage_Init(DW_EnabledMovingAverage_leade_T
  *localDW, P_EnabledMovingAverage_leader_T *localP);
extern void lead_EnabledMovingAverage_Start(DW_EnabledMovingAverage_leade_T
  *localDW, P_EnabledMovingAverage_leader_T *localP);
extern void le_EnabledMovingAverage_Disable(DW_EnabledMovingAverage_leade_T
  *localDW);
extern void leader_qba_EnabledMovingAverage(boolean_T rtu_Enable, const real_T
  rtu_x_n[3], B_EnabledMovingAverage_leader_T *localB,
  DW_EnabledMovingAverage_leade_T *localDW, P_EnabledMovingAverage_leader_T
  *localP);
extern void leader_q_EmbeddedMATLABFunction(real_T rtu_u, real_T rtu_x, real_T
  rtu_threshold, B_EmbeddedMATLABFunction_lead_T *localB);
extern void leader_q_EnabledSubsystem1_Init(DW_EnabledSubsystem1_leader_q_T
  *localDW, P_EnabledSubsystem1_leader_qb_T *localP);
extern void leader__EnabledSubsystem1_Start(B_EnabledSubsystem1_leader_qb_T
  *localB, DW_EnabledSubsystem1_leader_q_T *localDW,
  P_EnabledSubsystem1_leader_qb_T *localP);
extern void leade_EnabledSubsystem1_Disable(B_EnabledSubsystem1_leader_qb_T
  *localB, DW_EnabledSubsystem1_leader_q_T *localDW,
  P_EnabledSubsystem1_leader_qb_T *localP);
extern void leader_qball2_EnabledSubsystem1(RT_MODEL_leader_qball2_T * const
  leader_qball2_M, boolean_T rtu_Enable, real_T rtu_timeoutlimit,
  B_EnabledSubsystem1_leader_qb_T *localB, DW_EnabledSubsystem1_leader_q_T
  *localDW, P_EnabledSubsystem1_leader_qb_T *localP);
extern void leader_qball2_step0(void);
extern void leader_qball2_step2(void); /* private model entry point functions */
extern void leader_qball2_derivatives(void);

#endif                                 /* RTW_HEADER_leader_qball2_private_h_ */