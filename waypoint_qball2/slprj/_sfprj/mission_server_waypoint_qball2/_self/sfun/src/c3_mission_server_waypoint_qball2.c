/* Include files */

#include <stddef.h>
#include "blas.h"
#include "mission_server_waypoint_qball2_sfun.h"
#include "c3_mission_server_waypoint_qball2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mission_server_waypoint_qball2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c3_event_tick                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Increment_Index          ((uint8_T)1U)
#define c3_IN_Init                     ((uint8_T)2U)
#define c3_IN_Issue_CMD                ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[5];

/* Function Declarations */
static void initialize_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void initialize_params_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void enable_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void disable_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void ext_mode_exec_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void set_sim_state_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void finalize_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void sf_gateway_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void initSimStructsc3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_d_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_is_active_c3_mission_server_waypoint_qball2, const char_T
   *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint16_T c3_h_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_temporalCounter_i1, const char_T *c3_identifier);
static uint16_T c3_i_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint32_T c3_j_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_previousTicks, const char_T *c3_identifier);
static uint32_T c3_k_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_l_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_m_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber);
static void init_dsm_address_info
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  uint8_T *c3_is_active_c3_mission_server_waypoint_qball2;
  uint8_T *c3_is_c3_mission_server_waypoint_qball2;
  uint32_T *c3_presentTicks;
  uint32_T *c3_elapsedTicks;
  uint32_T *c3_previousTicks;
  uint16_T *c3_temporalCounter_i1;
  c3_previousTicks = (uint32_T *)ssGetDWork(chartInstance->S, 7);
  c3_elapsedTicks = (uint32_T *)ssGetDWork(chartInstance->S, 6);
  c3_presentTicks = (uint32_T *)ssGetDWork(chartInstance->S, 5);
  c3_temporalCounter_i1 = (uint16_T *)ssGetDWork(chartInstance->S, 4);
  c3_is_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c3_is_active_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  *c3_temporalCounter_i1 = 0U;
  *c3_is_active_c3_mission_server_waypoint_qball2 = 0U;
  *c3_is_c3_mission_server_waypoint_qball2 = c3_IN_NO_ACTIVE_CHILD;
  *c3_presentTicks = 0U;
  *c3_elapsedTicks = 0U;
  *c3_previousTicks = 0U;
}

static void initialize_params_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  uint32_T *c3_presentTicks;
  uint32_T *c3_previousTicks;
  c3_previousTicks = (uint32_T *)ssGetDWork(chartInstance->S, 7);
  c3_presentTicks = (uint32_T *)ssGetDWork(chartInstance->S, 5);
  _sfTime_ = sf_get_time(chartInstance->S);
  *c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.002 + 0.5);
  *c3_previousTicks = *c3_presentTicks;
}

static void disable_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  uint32_T *c3_presentTicks;
  uint32_T *c3_previousTicks;
  uint32_T *c3_elapsedTicks;
  uint16_T *c3_temporalCounter_i1;
  c3_previousTicks = (uint32_T *)ssGetDWork(chartInstance->S, 7);
  c3_elapsedTicks = (uint32_T *)ssGetDWork(chartInstance->S, 6);
  c3_presentTicks = (uint32_T *)ssGetDWork(chartInstance->S, 5);
  c3_temporalCounter_i1 = (uint16_T *)ssGetDWork(chartInstance->S, 4);
  _sfTime_ = sf_get_time(chartInstance->S);
  *c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.002 + 0.5);
  *c3_elapsedTicks = *c3_presentTicks - *c3_previousTicks;
  *c3_previousTicks = *c3_presentTicks;
  if ((uint32_T)*c3_temporalCounter_i1 + *c3_elapsedTicks <= 511U) {
    *c3_temporalCounter_i1 = (uint16_T)((uint32_T)*c3_temporalCounter_i1 +
      *c3_elapsedTicks);
  } else {
    *c3_temporalCounter_i1 = 511U;
  }
}

static void c3_update_debugger_state_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  uint8_T *c3_is_active_c3_mission_server_waypoint_qball2;
  uint8_T *c3_is_c3_mission_server_waypoint_qball2;
  int32_T *c3_sfEvent;
  c3_is_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c3_is_active_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*c3_is_active_c3_mission_server_waypoint_qball2 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, *c3_sfEvent);
  }

  if (*c3_is_c3_mission_server_waypoint_qball2 == c3_IN_Increment_Index) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c3_sfEvent);
  }

  if (*c3_is_c3_mission_server_waypoint_qball2 == c3_IN_Issue_CMD) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c3_sfEvent);
  }

  if (*c3_is_c3_mission_server_waypoint_qball2 == c3_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  c3_update_debugger_state_c3_mission_server_waypoint_qball2(chartInstance);
}

static const mxArray *get_sim_state_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint16_T c3_h_hoistedGlobal;
  uint16_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  uint32_T c3_i_hoistedGlobal;
  uint32_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T *c3_done;
  real_T *c3_idx;
  real_T *c3_last_waypoint;
  real_T *c3_x_ref;
  real_T *c3_z_ref;
  uint8_T *c3_is_active_c3_mission_server_waypoint_qball2;
  uint8_T *c3_is_c3_mission_server_waypoint_qball2;
  uint16_T *c3_temporalCounter_i1;
  uint32_T *c3_previousTicks;
  c3_previousTicks = (uint32_T *)ssGetDWork(chartInstance->S, 7);
  c3_temporalCounter_i1 = (uint16_T *)ssGetDWork(chartInstance->S, 4);
  c3_last_waypoint = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_x_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_done = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_idx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c3_is_active_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(9, 1), false);
  c3_hoistedGlobal = *c3_done;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_idx;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_last_waypoint;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_x_ref;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_z_ref;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_is_active_c3_mission_server_waypoint_qball2;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *c3_is_c3_mission_server_waypoint_qball2;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *c3_temporalCounter_i1;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *c3_previousTicks;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_done;
  real_T *c3_idx;
  real_T *c3_last_waypoint;
  real_T *c3_x_ref;
  real_T *c3_z_ref;
  uint8_T *c3_is_active_c3_mission_server_waypoint_qball2;
  uint8_T *c3_is_c3_mission_server_waypoint_qball2;
  uint16_T *c3_temporalCounter_i1;
  uint32_T *c3_previousTicks;
  c3_previousTicks = (uint32_T *)ssGetDWork(chartInstance->S, 7);
  c3_temporalCounter_i1 = (uint16_T *)ssGetDWork(chartInstance->S, 4);
  c3_last_waypoint = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_x_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_done = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_idx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c3_is_active_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_u = sf_mex_dup(c3_st);
  *c3_done = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "done");
  *c3_idx = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "idx");
  *c3_last_waypoint = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "last_waypoint");
  *c3_x_ref = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    3)), "x_ref");
  *c3_z_ref = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    4)), "z_ref");
  *c3_is_active_c3_mission_server_waypoint_qball2 = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
     "is_active_c3_mission_server_waypoint_qball2");
  *c3_is_c3_mission_server_waypoint_qball2 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 6)), "is_c3_mission_server_waypoint_qball2");
  *c3_temporalCounter_i1 = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "temporalCounter_i1");
  *c3_previousTicks = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "previousTicks");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 9)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_mission_server_waypoint_qball2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  uint16_T *c3_temporalCounter_i1;
  uint8_T *c3_is_c3_mission_server_waypoint_qball2;
  c3_temporalCounter_i1 = (uint16_T *)ssGetDWork(chartInstance->S, 4);
  c3_is_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (*c3_is_c3_mission_server_waypoint_qball2 == c3_IN_Issue_CMD) {
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        *c3_temporalCounter_i1 = 0U;
      }
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  uint32_T *c3_presentTicks;
  uint32_T *c3_previousTicks;
  uint32_T *c3_elapsedTicks;
  uint16_T *c3_temporalCounter_i1;
  real_T *c3_idx;
  real_T *c3_done;
  real_T *c3_x_ref;
  real_T *c3_z_ref;
  boolean_T *c3_Arrived;
  real_T *c3_n;
  real_T *c3_last_waypoint;
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_mission_server_waypoint_qball2;
  uint8_T *c3_is_c3_mission_server_waypoint_qball2;
  real_T (*c3_x_waypoints)[5];
  real_T (*c3_z_waypoints)[5];
  boolean_T guard1 = false;
  c3_previousTicks = (uint32_T *)ssGetDWork(chartInstance->S, 7);
  c3_elapsedTicks = (uint32_T *)ssGetDWork(chartInstance->S, 6);
  c3_presentTicks = (uint32_T *)ssGetDWork(chartInstance->S, 5);
  c3_temporalCounter_i1 = (uint16_T *)ssGetDWork(chartInstance->S, 4);
  c3_last_waypoint = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_z_waypoints = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
  c3_x_waypoints = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 2);
  c3_n = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_Arrived = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_x_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_done = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_idx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c3_is_active_c3_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_mission_server_waypoint_qball2(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  *c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.002 + 0.5);
  *c3_elapsedTicks = *c3_presentTicks - *c3_previousTicks;
  *c3_previousTicks = *c3_presentTicks;
  if ((uint32_T)*c3_temporalCounter_i1 + *c3_elapsedTicks <= 511U) {
    *c3_temporalCounter_i1 = (uint16_T)((uint32_T)*c3_temporalCounter_i1 +
      *c3_elapsedTicks);
  } else {
    *c3_temporalCounter_i1 = 511U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, *c3_sfEvent);
  _SFD_DATA_RANGE_CHECK_MIN(*c3_idx, 0U, 0.0);
  _SFD_DATA_RANGE_CHECK_MIN_MAX(*c3_done, 1U, 0.0, 1.0);
  _SFD_DATA_RANGE_CHECK(*c3_x_ref, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_z_ref, 3U);
  _SFD_DATA_RANGE_CHECK_MIN_MAX((real_T)*c3_Arrived, 4U, 0.0, 1.0);
  _SFD_DATA_RANGE_CHECK(*c3_n, 5U);
  for (c3_i0 = 0; c3_i0 < 5; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_x_waypoints)[c3_i0], 6U);
  }

  for (c3_i1 = 0; c3_i1 < 5; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((*c3_z_waypoints)[c3_i1], 7U);
  }

  _SFD_DATA_RANGE_CHECK_MIN_MAX(*c3_last_waypoint, 8U, 0.0, 1.0);
  *c3_sfEvent = c3_event_tick;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_tick, *c3_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, *c3_sfEvent);
  if (*c3_is_active_c3_mission_server_waypoint_qball2 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, *c3_sfEvent);
    *c3_is_active_c3_mission_server_waypoint_qball2 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *c3_sfEvent);
    *c3_is_c3_mission_server_waypoint_qball2 = c3_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *c3_done = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK_MIN_MAX(*c3_done, 1U, 0.0, 1.0);
    *c3_idx = 1.0;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK_MIN(*c3_idx, 0U, 0.0);
    *c3_last_waypoint = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK_MIN_MAX(*c3_last_waypoint, 8U, 0.0, 1.0);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    *c3_x_ref = (*c3_x_waypoints)[_SFD_ARRAY_BOUNDS_CHECK(6U,
      _SFD_EML_ARRAY_BOUNDS_CHECK(
      "State Init #242 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): x_ref = x_waypoints(idx);\n                        "
      "                                                              ^^^^^^^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "State Init #242 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): x_ref = x_waypoints(idx);\n                        "
      "                                                                          ^^^",
      *c3_idx), 1, 5, 1, 0) - 1, 0, 4, 1, 0)];
    c3_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c3_x_ref, 2U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    *c3_z_ref = (*c3_z_waypoints)[_SFD_ARRAY_BOUNDS_CHECK(7U,
      _SFD_EML_ARRAY_BOUNDS_CHECK(
      "State Init #242 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): z_ref = z_waypoints(idx);\n                        "
      "                                                              ^^^^^^^^^^^",
      (int32_T)_SFD_INTEGER_CHECK(
      "State Init #242 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): z_ref = z_waypoints(idx);\n                        "
      "                                                                          ^^^",
      *c3_idx), 1, 5, 1, 0) - 1, 0, 4, 1, 0)];
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c3_z_ref, 3U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*c3_is_c3_mission_server_waypoint_qball2) {
     case c3_IN_Increment_Index:
      CV_CHART_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *c3_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c3_sfEvent);
      *c3_is_c3_mission_server_waypoint_qball2 = c3_IN_Issue_CMD;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c3_sfEvent);
      *c3_temporalCounter_i1 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
      if (CV_EML_IF(2, 1, 0, *c3_idx == *c3_n)) {
        *c3_last_waypoint = 1.0;
        c3_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_DATA_RANGE_CHECK_MIN_MAX(*c3_last_waypoint, 8U, 0.0, 1.0);
      }

      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c3_sfEvent);
      break;

     case c3_IN_Init:
      CV_CHART_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *c3_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c3_sfEvent);
      *c3_is_c3_mission_server_waypoint_qball2 = c3_IN_Issue_CMD;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c3_sfEvent);
      *c3_temporalCounter_i1 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
      if (CV_EML_IF(2, 1, 0, *c3_idx == *c3_n)) {
        *c3_last_waypoint = 1.0;
        c3_updateDataWrittenToVector(chartInstance, 4U);
        _SFD_DATA_RANGE_CHECK_MIN_MAX(*c3_last_waypoint, 8U, 0.0, 1.0);
      }

      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c3_sfEvent);
      break;

     case c3_IN_Issue_CMD:
      CV_CHART_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, *c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_e_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(2, 0, 0, *c3_temporalCounter_i1 >= 500)) {
        if (CV_EML_COND(2, 0, 1, (real_T)*c3_Arrived == 1.0)) {
          CV_EML_MCDC(2, 0, 0, true);
          CV_EML_IF(2, 0, 0, true);
          c3_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(2, 0, 0, false);
        CV_EML_IF(2, 0, 0, false);
        c3_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c3_sfEvent);
        *c3_is_c3_mission_server_waypoint_qball2 = c3_IN_Increment_Index;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        if (CV_EML_IF(0, 1, 0, *c3_idx == *c3_n)) {
          *c3_done = 1.0;
          c3_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK_MIN_MAX(*c3_done, 1U, 0.0, 1.0);
        } else {
          c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
          (*c3_idx)++;
          c3_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK_MIN(*c3_idx, 0U, 0.0);
        }

        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        *c3_x_ref = (*c3_x_waypoints)[_SFD_ARRAY_BOUNDS_CHECK(6U,
          _SFD_EML_ARRAY_BOUNDS_CHECK(
          "State Issue_CMD #241 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): x_ref = x_waypoints(idx);\n                   "
          "                                                                        ^^^^^^^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "State Issue_CMD #241 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): x_ref = x_waypoints(idx);\n                   "
          "                                                                                    ^^^",
          *c3_idx), 1, 5, 1, 0) - 1, 0, 4, 1, 0)];
        c3_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*c3_x_ref, 2U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        *c3_z_ref = (*c3_z_waypoints)[_SFD_ARRAY_BOUNDS_CHECK(7U,
          _SFD_EML_ARRAY_BOUNDS_CHECK(
          "State Issue_CMD #241 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): z_ref = z_waypoints(idx);\n                   "
          "                                                                        ^^^^^^^^^^^",
          (int32_T)_SFD_INTEGER_CHECK(
          "State Issue_CMD #241 in Chart \'Waypoint Scheduler/Chart - Scheduler Logic\' (#239): z_ref = z_waypoints(idx);\n                   "
          "                                                                                    ^^^",
          *c3_idx), 1, 5, 1, 0) - 1, 0, 4, 1, 0)];
        c3_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*c3_z_ref, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      *c3_is_c3_mission_server_waypoint_qball2 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c3_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_tick, *c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_mission_server_waypoint_qball2MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc3_mission_server_waypoint_qball2
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray
  *sf_c3_mission_server_waypoint_qball2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_d_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i2, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_tick;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_tick = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_tick), &c3_thisId);
  sf_mex_destroy(&c3_tick);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i3, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i4;
  real_T c3_b_inData[5];
  int32_T c3_i5;
  real_T c3_u[5];
  const mxArray *c3_y = NULL;
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i4 = 0; c3_i4 < 5; c3_i4++) {
    c3_b_inData[c3_i4] = (*(real_T (*)[5])c3_inData)[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 5; c3_i5++) {
    c3_u[c3_i5] = c3_b_inData[c3_i5];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_is_active_c3_mission_server_waypoint_qball2, const char_T
   *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_is_active_c3_mission_server_waypoint_qball2), &c3_thisId);
  sf_mex_destroy(&c3_is_active_c3_mission_server_waypoint_qball2);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint16_T c3_h_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_temporalCounter_i1, const char_T *c3_identifier)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_temporalCounter_i1),
    &c3_thisId);
  sf_mex_destroy(&c3_temporalCounter_i1);
  return c3_y;
}

static uint16_T c3_i_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint32_T c3_j_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_previousTicks, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_previousTicks),
    &c3_thisId);
  sf_mex_destroy(&c3_previousTicks);
  return c3_y;
}

static uint32_T c3_k_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u2, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_l_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_m_emlrt_marshallIn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex)
{
  (void)chartInstance;
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 4, 1, 0)] = true;
}

static void c3_errorIfDataNotWrittenToFcn
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 4, 1,
    0)]);
}

static void init_dsm_address_info
  (SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c3_mission_server_waypoint_qball2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3817526285U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4133738491U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(949694396U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(929632727U);
}

mxArray *sf_c3_mission_server_waypoint_qball2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GgKRvbU3PuLWtBrdJ6yy8B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_mission_server_waypoint_qball2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_mission_server_waypoint_qball2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_mission_server_waypoint_qball2
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[11],T\"done\",},{M[1],M[4],T\"idx\",},{M[1],M[18],T\"last_waypoint\",},{M[1],M[12],T\"x_ref\",},{M[1],M[13],T\"z_ref\",},{M[8],M[0],T\"is_active_c3_mission_server_waypoint_qball2\",},{M[9],M[0],T\"is_c3_mission_server_waypoint_qball2\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[6],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_mission_server_waypoint_qball2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _mission_server_waypoint_qball2MachineNumber_,
           3,
           3,
           4,
           0,
           9,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation
          (_mission_server_waypoint_qball2MachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _mission_server_waypoint_qball2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _mission_server_waypoint_qball2MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"idx");
          _SFD_SET_DATA_PROPS(1,2,0,1,"done");
          _SFD_SET_DATA_PROPS(2,2,0,1,"x_ref");
          _SFD_SET_DATA_PROPS(3,2,0,1,"z_ref");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Arrived");
          _SFD_SET_DATA_PROPS(5,1,1,0,"n");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x_waypoints");
          _SFD_SET_DATA_PROPS(7,1,1,0,"z_waypoints");
          _SFD_SET_DATA_PROPS(8,2,0,1,"last_waypoint");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,1,0,23,32,46,71);
        _SFD_CV_INIT_EML(2,1,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,1,0,17,26,-1,54);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,0,24,0,24);

        {
          static int condStart[] = { 0, 14 };

          static int condEnd[] = { 13, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,0,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_idx;
          real_T *c3_done;
          real_T *c3_x_ref;
          real_T *c3_z_ref;
          boolean_T *c3_Arrived;
          real_T *c3_n;
          real_T *c3_last_waypoint;
          real_T (*c3_x_waypoints)[5];
          real_T (*c3_z_waypoints)[5];
          c3_last_waypoint = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c3_z_waypoints = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S,
            3);
          c3_x_waypoints = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S,
            2);
          c3_n = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_Arrived = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_x_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_done = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_idx = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_idx);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_done);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_x_ref);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_z_ref);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_Arrived);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_n);
          _SFD_SET_DATA_VALUE_PTR(6U, *c3_x_waypoints);
          _SFD_SET_DATA_VALUE_PTR(7U, *c3_z_waypoints);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_last_waypoint);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _mission_server_waypoint_qball2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "1dEEoiCAmVutnBhLwrRp2B";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_mission_server_waypoint_qball2_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 3, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c3_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_mission_server_waypoint_qball2InstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_mission_server_waypoint_qball2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
  initialize_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  enable_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  disable_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  sf_gateway_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  ext_mode_exec_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c3_mission_server_waypoint_qball2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_mission_server_waypoint_qball2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_mission_server_waypoint_qball2
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_mission_server_waypoint_qball2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_mission_server_waypoint_qball2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_mission_server_waypoint_qball2(S);
}

static void sf_opaque_set_sim_state_c3_mission_server_waypoint_qball2(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c3_mission_server_waypoint_qball2(S, st);
}

static void sf_opaque_terminate_c3_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_mission_server_waypoint_qball2InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mission_server_waypoint_qball2_optimization_info();
    }

    finalize_c3_mission_server_waypoint_qball2
      ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_mission_server_waypoint_qball2
    ((SFc3_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_mission_server_waypoint_qball2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_mission_server_waypoint_qball2
      ((SFc3_mission_server_waypoint_qball2InstanceStruct*)
       (chartInfo->chartInstance));
  }
}

mxArray *sf_c3_mission_server_waypoint_qball2_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c3_mission_server_waypoint_qball2\",T\"is_active_c3_mission_server_waypoint_qball2\"},{T\"is_c3_mission_server_waypoint_qball2\",T\"is_c3_mission_server_waypoint_qball2\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x8'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size'{{T\"int32\",,,,,,,M[0],M[]},{T\"boolean\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint16\",,,,,,,M[0],M[]},{T\"uint32\",,,,,,,M[0],M[]},{T\"uint32\",,,,,,,M[0],M[]},{T\"uint32\",,,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 8, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 134152651U, 3783207668U, 2409771618U,
    1013745280U };

  return checksum;
}

static void mdlSetWorkWidths_c3_mission_server_waypoint_qball2(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mission_server_waypoint_qball2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
    }

    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1855721578U));
  ssSetChecksum1(S,(179404341U));
  ssSetChecksum2(S,(299900169U));
  ssSetChecksum3(S,(3345076310U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_mission_server_waypoint_qball2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_mission_server_waypoint_qball2(SimStruct *S)
{
  SFc3_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_mission_server_waypoint_qball2InstanceStruct *)utMalloc
    (sizeof(SFc3_mission_server_waypoint_qball2InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_mission_server_waypoint_qball2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c3_mission_server_waypoint_qball2;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_mission_server_waypoint_qball2_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_mission_server_waypoint_qball2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_mission_server_waypoint_qball2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_mission_server_waypoint_qball2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_mission_server_waypoint_qball2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
