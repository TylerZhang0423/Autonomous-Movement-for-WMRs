/* Include files */

#include <stddef.h>
#include "blas.h"
#include "mission_server_waypoint_qball2_sfun.h"
#include "c1_mission_server_waypoint_qball2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mission_server_waypoint_qball2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_Landing                  ((uint8_T)1U)
#define c1_IN_QballGetsWaypoints       ((uint8_T)2U)
#define c1_IN_Takeoff                  ((uint8_T)3U)
#define c1_IN_WaitForStartCommand      ((uint8_T)4U)
#define c1_const_MIN_QUAD_HEIGHT       (0.5)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c1_dataWrittenToVector[3];

/* Function Declarations */
static void initialize_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void initialize_params_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void enable_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void disable_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void ext_mode_exec_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void set_sim_state_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void finalize_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void sf_gateway_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void c1_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void initSimStructsc1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_is_active_c1_mission_server_waypoint_qball2, const char_T
   *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_g_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_h_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber);
static void init_dsm_address_info
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_mission_server_waypoint_qball2;
  uint8_T *c1_is_c1_mission_server_waypoint_qball2;
  c1_is_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c1_is_active_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  *c1_is_active_c1_mission_server_waypoint_qball2 = 0U;
  *c1_is_c1_mission_server_waypoint_qball2 = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_MIN_QUAD_HEIGHT = 0.5;
}

static void initialize_params_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  uint8_T *c1_is_active_c1_mission_server_waypoint_qball2;
  uint8_T *c1_is_c1_mission_server_waypoint_qball2;
  int32_T *c1_sfEvent;
  c1_is_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c1_is_active_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*c1_is_active_c1_mission_server_waypoint_qball2 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *c1_sfEvent);
  }

  if (*c1_is_c1_mission_server_waypoint_qball2 == c1_IN_WaitForStartCommand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *c1_sfEvent);
  }

  if (*c1_is_c1_mission_server_waypoint_qball2 == c1_IN_Takeoff) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c1_sfEvent);
  }

  if (*c1_is_c1_mission_server_waypoint_qball2 == c1_IN_QballGetsWaypoints) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c1_sfEvent);
  }

  if (*c1_is_c1_mission_server_waypoint_qball2 == c1_IN_Landing) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  c1_update_debugger_state_c1_mission_server_waypoint_qball2(chartInstance);
}

static const mxArray *get_sim_state_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T *c1_qball_takeoff;
  real_T *c1_x_quad_ref;
  real_T *c1_z_quad_ref;
  uint8_T *c1_is_active_c1_mission_server_waypoint_qball2;
  uint8_T *c1_is_c1_mission_server_waypoint_qball2;
  real_T *c1_start_stop_start;
  c1_start_stop_start = (real_T *)ssGetDWork(chartInstance->S, 5);
  c1_z_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_x_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_qball_takeoff = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c1_is_active_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(6, 1), false);
  c1_hoistedGlobal = *c1_qball_takeoff;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_x_quad_ref;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_z_quad_ref;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_is_active_c1_mission_server_waypoint_qball2;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_is_c1_mission_server_waypoint_qball2;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_start_stop_start;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_qball_takeoff;
  real_T *c1_x_quad_ref;
  real_T *c1_z_quad_ref;
  uint8_T *c1_is_active_c1_mission_server_waypoint_qball2;
  uint8_T *c1_is_c1_mission_server_waypoint_qball2;
  real_T *c1_start_stop_start;
  c1_start_stop_start = (real_T *)ssGetDWork(chartInstance->S, 5);
  c1_z_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_x_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_qball_takeoff = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c1_is_active_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_u = sf_mex_dup(c1_st);
  *c1_qball_takeoff = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "qball_takeoff");
  *c1_x_quad_ref = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "x_quad_ref");
  *c1_z_quad_ref = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "z_quad_ref");
  *c1_is_active_c1_mission_server_waypoint_qball2 = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
     "is_active_c1_mission_server_waypoint_qball2");
  *c1_is_c1_mission_server_waypoint_qball2 = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 4)), "is_c1_mission_server_waypoint_qball2");
  *c1_start_stop_start = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 5)), "start_stop_start");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_mission_server_waypoint_qball2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  real_T *c1_qball_takeoff;
  real_T *c1_x_quad;
  real_T *c1_y_quad;
  real_T *c1_z_quad;
  real_T *c1_x_ref;
  real_T *c1_z_ref;
  real_T *c1_x_quad_ref;
  real_T *c1_z_quad_ref;
  real_T *c1_start_stop;
  real_T *c1_start_stop_start;
  real_T *c1_start_stop_prev;
  c1_start_stop_start = (real_T *)ssGetDWork(chartInstance->S, 5);
  c1_start_stop_prev = (real_T *)ssGetDWork(chartInstance->S, 4);
  c1_start_stop = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_z_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_x_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_z_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_x_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_z_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_y_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_x_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_qball_takeoff = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c1_set_sim_state_side_effects_c1_mission_server_waypoint_qball2(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_qball_takeoff, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_x_quad, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_y_quad, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_z_quad, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_x_ref, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_z_ref, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_x_quad_ref, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_z_quad_ref, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_start_stop, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_MIN_QUAD_HEIGHT, 9U);
  *c1_sfEvent = CALL_EVENT;
  *c1_start_stop_prev = *c1_start_stop_start;
  *c1_start_stop_start = *c1_start_stop;
  c1_c1_mission_server_waypoint_qball2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_mission_server_waypoint_qball2MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c1_c1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 0.0;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  uint8_T *c1_is_active_c1_mission_server_waypoint_qball2;
  real_T *c1_start_stop;
  real_T *c1_start_stop_prev;
  real_T *c1_start_stop_start;
  uint8_T *c1_is_c1_mission_server_waypoint_qball2;
  real_T *c1_x_quad_ref;
  real_T *c1_x_ref;
  real_T *c1_z_quad_ref;
  real_T *c1_z_ref;
  real_T *c1_qball_takeoff;
  real_T *c1_x_quad;
  real_T *c1_z_quad;
  real_T *c1_y_quad;
  int32_T *c1_sfEvent;
  c1_start_stop_start = (real_T *)ssGetDWork(chartInstance->S, 5);
  c1_start_stop_prev = (real_T *)ssGetDWork(chartInstance->S, 4);
  c1_start_stop = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_z_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_x_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_z_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_x_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_z_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_y_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_x_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_qball_takeoff = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c1_is_active_c1_mission_server_waypoint_qball2 = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  if (*c1_is_active_c1_mission_server_waypoint_qball2 == 0U) {
    *c1_start_stop_prev = *c1_start_stop;
    *c1_start_stop_start = *c1_start_stop;
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *c1_sfEvent);
    *c1_is_active_c1_mission_server_waypoint_qball2 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *c1_sfEvent);
    *c1_is_c1_mission_server_waypoint_qball2 = c1_IN_WaitForStartCommand;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c1_sfEvent);
  } else {
    switch (*c1_is_c1_mission_server_waypoint_qball2) {
     case c1_IN_Landing:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
      break;

     case c1_IN_QballGetsWaypoints:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, *c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_h_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_out = CV_EML_IF(3, 0, 0, *c1_start_stop_prev != *c1_start_stop_start);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c1_sfEvent);
        *c1_is_c1_mission_server_waypoint_qball2 = c1_IN_Landing;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_qball_takeoff = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c1_qball_takeoff, 0U);
        *c1_x_quad_ref = *c1_x_quad;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c1_x_quad_ref, 6U);
        *c1_z_quad_ref = *c1_z_quad;
        c1_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*c1_z_quad_ref, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_x_quad_ref = *c1_x_ref;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c1_x_quad_ref, 6U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 6U);
        sf_mex_printf("%s =\\n", "x_quad_ref");
        c1_hoistedGlobal = *c1_x_quad_ref;
        c1_u = c1_hoistedGlobal;
        c1_y = NULL;
        sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
        *c1_z_quad_ref = *c1_z_ref;
        c1_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*c1_z_quad_ref, 7U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 2U, 7U);
        sf_mex_printf("%s =\\n", "z_quad_ref");
        c1_b_hoistedGlobal = *c1_z_quad_ref;
        c1_b_u = c1_b_hoistedGlobal;
        c1_b_y = NULL;
        sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_b_y);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c1_sfEvent);
      break;

     case c1_IN_Takeoff:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, *c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_f_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_b_out = CV_EML_IF(2, 0, 0, *c1_y_quad >= c1_const_MIN_QUAD_HEIGHT);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c1_sfEvent);
        *c1_is_c1_mission_server_waypoint_qball2 = c1_IN_QballGetsWaypoints;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c1_sfEvent);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, *c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_g_debug_family_names,
          c1_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
          c1_b_sf_marshallIn);
        c1_c_out = CV_EML_IF(4, 0, 0, *c1_start_stop_prev !=
                             *c1_start_stop_start);
        _SFD_SYMBOL_SCOPE_POP();
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c1_sfEvent);
          *c1_is_c1_mission_server_waypoint_qball2 = c1_IN_Landing;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
            c1_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          *c1_qball_takeoff = 0.0;
          c1_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*c1_qball_takeoff, 0U);
          *c1_x_quad_ref = *c1_x_quad;
          c1_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*c1_x_quad_ref, 6U);
          *c1_z_quad_ref = *c1_z_quad;
          c1_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*c1_z_quad_ref, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *c1_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c1_sfEvent);
      break;

     case c1_IN_WaitForStartCommand:
      CV_CHART_EVAL(0, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, *c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_e_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_d_out = CV_EML_IF(1, 0, 0, *c1_start_stop_prev != *c1_start_stop_start);
      _SFD_SYMBOL_SCOPE_POP();
      if (c1_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *c1_sfEvent);
        *c1_is_c1_mission_server_waypoint_qball2 = c1_IN_Takeoff;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_qball_takeoff = 1.0;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c1_qball_takeoff, 0U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        sf_mex_printf("%s =\\n", "qball_takeoff");
        c1_c_hoistedGlobal = *c1_qball_takeoff;
        c1_c_u = c1_c_hoistedGlobal;
        c1_c_y = NULL;
        sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_c_y);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *c1_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
          c1_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
          c1_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U,
          c1_sf_marshallOut, c1_sf_marshallIn);
        *c1_qball_takeoff = 0.0;
        c1_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c1_qball_takeoff, 0U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        sf_mex_printf("%s =\\n", "qball_takeoff");
        c1_d_hoistedGlobal = *c1_qball_takeoff;
        c1_d_u = c1_d_hoistedGlobal;
        c1_d_y = NULL;
        sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_d_y);
        *c1_x_quad_ref = *c1_x_quad;
        c1_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c1_x_quad_ref, 6U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 1U, 6U);
        sf_mex_printf("%s =\\n", "x_quad_ref");
        c1_e_hoistedGlobal = *c1_x_quad_ref;
        c1_e_u = c1_e_hoistedGlobal;
        c1_e_y = NULL;
        sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_e_y);
        *c1_z_quad_ref = *c1_z_quad;
        c1_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*c1_z_quad_ref, 7U);
        c1_errorIfDataNotWrittenToFcn(chartInstance, 2U, 7U);
        sf_mex_printf("%s =\\n", "z_quad_ref");
        c1_f_hoistedGlobal = *c1_z_quad_ref;
        c1_f_u = c1_f_hoistedGlobal;
        c1_f_y = NULL;
        sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c1_f_y);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      *c1_is_c1_mission_server_waypoint_qball2 = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
}

static void initSimStructsc1_mission_server_waypoint_qball2
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sf_internal_predicateOutput;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c1_sf_internal_predicateOutput = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_sf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_sf_internal_predicateOutput);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray
  *sf_c1_mission_server_waypoint_qball2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)
    chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_is_active_c1_mission_server_waypoint_qball2, const char_T
   *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_is_active_c1_mission_server_waypoint_qball2), &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_mission_server_waypoint_qball2);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_g_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_h_emlrt_marshallIn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c1_vectorIndex)
{
  (void)chartInstance;
  c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c1_vectorIndex, 0, 2, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance, uint32_T
   c1_vectorIndex, uint32_T c1_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c1_dataNumber, c1_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c1_vectorIndex, 0, 2, 1,
    0)]);
}

static void init_dsm_address_info
  (SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance)
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
void sf_c1_mission_server_waypoint_qball2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(314480349U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(640596624U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1249705119U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1379014475U);
}

mxArray *sf_c1_mission_server_waypoint_qball2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IpbYKoUWx6La7nabftny7D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_mission_server_waypoint_qball2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_mission_server_waypoint_qball2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_mission_server_waypoint_qball2
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[3],T\"qball_takeoff\",},{M[1],M[11],T\"x_quad_ref\",},{M[1],M[12],T\"z_quad_ref\",},{M[8],M[0],T\"is_active_c1_mission_server_waypoint_qball2\",},{M[9],M[0],T\"is_c1_mission_server_waypoint_qball2\",},{M[12],M[16],T\"start_stop_start\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_mission_server_waypoint_qball2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _mission_server_waypoint_qball2MachineNumber_,
           1,
           4,
           5,
           0,
           10,
           0,
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
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"qball_takeoff");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x_quad");
          _SFD_SET_DATA_PROPS(2,1,1,0,"y_quad");
          _SFD_SET_DATA_PROPS(3,1,1,0,"z_quad");
          _SFD_SET_DATA_PROPS(4,1,1,0,"x_ref");
          _SFD_SET_DATA_PROPS(5,1,1,0,"z_ref");
          _SFD_SET_DATA_PROPS(6,2,0,1,"x_quad_ref");
          _SFD_SET_DATA_PROPS(7,2,0,1,"z_quad_ref");
          _SFD_SET_DATA_PROPS(8,1,1,0,"start_stop");
          _SFD_SET_DATA_PROPS(9,7,0,0,"MIN_QUAD_HEIGHT");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,26,1,26);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,23,1,23);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,23,1,23);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_qball_takeoff;
          real_T *c1_x_quad;
          real_T *c1_y_quad;
          real_T *c1_z_quad;
          real_T *c1_x_ref;
          real_T *c1_z_ref;
          real_T *c1_x_quad_ref;
          real_T *c1_z_quad_ref;
          real_T *c1_start_stop;
          c1_start_stop = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_z_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_x_quad_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_z_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_x_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_z_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_y_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_x_quad = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_qball_takeoff = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_qball_takeoff);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_x_quad);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_y_quad);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_z_quad);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_x_ref);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_z_ref);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_x_quad_ref);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_z_quad_ref);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_start_stop);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c1_MIN_QUAD_HEIGHT);
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
  return "Iynp9aDDBLsTwee4BvyOTD";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_mission_server_waypoint_qball2_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 1, "dworkChecksum");
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

static void sf_opaque_initialize_c1_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_mission_server_waypoint_qball2InstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_mission_server_waypoint_qball2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
  initialize_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  enable_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  disable_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  sf_gateway_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  ext_mode_exec_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_mission_server_waypoint_qball2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_mission_server_waypoint_qball2();/* state var info */
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

extern void sf_internal_set_sim_state_c1_mission_server_waypoint_qball2
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_mission_server_waypoint_qball2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_mission_server_waypoint_qball2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_mission_server_waypoint_qball2(S);
}

static void sf_opaque_set_sim_state_c1_mission_server_waypoint_qball2(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_mission_server_waypoint_qball2(S, st);
}

static void sf_opaque_terminate_c1_mission_server_waypoint_qball2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_mission_server_waypoint_qball2InstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mission_server_waypoint_qball2_optimization_info();
    }

    finalize_c1_mission_server_waypoint_qball2
      ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_mission_server_waypoint_qball2
    ((SFc1_mission_server_waypoint_qball2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_mission_server_waypoint_qball2(SimStruct *S)
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
    initialize_params_c1_mission_server_waypoint_qball2
      ((SFc1_mission_server_waypoint_qball2InstanceStruct*)
       (chartInfo->chartInstance));
  }
}

mxArray *sf_c1_mission_server_waypoint_qball2_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c1_mission_server_waypoint_qball2\",T\"is_active_c1_mission_server_waypoint_qball2\"},{T\"is_c1_mission_server_waypoint_qball2\",T\"is_c1_mission_server_waypoint_qball2\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x6'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size'{{T\"int32\",,,,,,,M[0],M[]},{T\"boolean\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 6, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 2916794536U, 554565360U, 2479569735U,
    2185685532U };

  return checksum;
}

static void mdlSetWorkWidths_c1_mission_server_waypoint_qball2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mission_server_waypoint_qball2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2906746746U));
  ssSetChecksum1(S,(1652345427U));
  ssSetChecksum2(S,(999066621U));
  ssSetChecksum3(S,(494742691U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_mission_server_waypoint_qball2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_mission_server_waypoint_qball2(SimStruct *S)
{
  SFc1_mission_server_waypoint_qball2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_mission_server_waypoint_qball2InstanceStruct *)utMalloc
    (sizeof(SFc1_mission_server_waypoint_qball2InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_mission_server_waypoint_qball2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_mission_server_waypoint_qball2;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_mission_server_waypoint_qball2;
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

void c1_mission_server_waypoint_qball2_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_mission_server_waypoint_qball2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_mission_server_waypoint_qball2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_mission_server_waypoint_qball2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_mission_server_waypoint_qball2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
