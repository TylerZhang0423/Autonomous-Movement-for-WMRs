/* Include files */

#include <stddef.h>
#include "blas.h"
#include "follower_qbot2_sfun.h"
#include "c3_follower_qbot2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "follower_qbot2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[33] = { "finished_path_flag", "rx",
  "ry", "rtheta", "n", "xy", "i", "j", "tx", "ty", "nargin", "nargout",
  "target_list", "robot_xyt", "vlimit", "dist_thr", "ang_thr", "method", "step",
  "Kv_1", "Kw_1", "Kv_2", "Kw_2", "Psi_d", "pre_states", "Vf", "W",
  "target_distance", "ang_to_tar", "target_xy", "states", "Vf_1", "end_flag" };

static const char * c3_b_debug_family_names[4] = { "nargin", "nargout", "x", "y"
};

static const char * c3_c_debug_family_names[7] = { "nargin", "nargout", "rx",
  "ry", "tx", "ty", "dist" };

static const char * c3_d_debug_family_names[10] = { "X", "Y", "nargin",
  "nargout", "rx", "ry", "rtheta", "tx", "ty", "theta" };

static const char * c3_e_debug_family_names[14] = { "d", "vmax", "wmax",
  "nargin", "nargout", "dist", "theta", "vlimit", "ang_thr", "Kv", "Kw", "Vf_1",
  "Vf", "W" };

static const char * c3_f_debug_family_names[13] = { "d", "vmax", "wmax",
  "w_sign", "nargin", "nargout", "dist", "theta", "vlimit", "Kv", "Kw", "Vf",
  "W" };

/* Function Declarations */
static void initialize_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance);
static void initialize_params_c3_follower_qbot2
  (SFc3_follower_qbot2InstanceStruct *chartInstance);
static void enable_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance);
static void disable_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_follower_qbot2
  (SFc3_follower_qbot2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_follower_qbot2
  (SFc3_follower_qbot2InstanceStruct *chartInstance);
static void set_sim_state_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance);
static void sf_gateway_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance);
static void c3_chartstep_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance);
static void initSimStructsc3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_b_end_flag, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_b_Vf_1, const char_T *c3_identifier);
static real_T c3_d_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_states, const char_T *c3_identifier);
static real_T c3_f_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_target_xy, const char_T *c3_identifier,
  real_T c3_y[2]);
static void c3_h_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static real_T c3_check_angle(SFc3_follower_qbot2InstanceStruct *chartInstance,
  real_T c3_x);
static real_T c3_mpower(SFc3_follower_qbot2InstanceStruct *chartInstance, real_T
  c3_a);
static void c3_eml_scalar_eg(SFc3_follower_qbot2InstanceStruct *chartInstance);
static void c3_eml_error(SFc3_follower_qbot2InstanceStruct *chartInstance);
static void c3_ClosedLoop_Sequential(SFc3_follower_qbot2InstanceStruct
  *chartInstance, real_T c3_dist, real_T c3_theta, real_T c3_vlimit, real_T
  c3_ang_thr, real_T c3_Kv, real_T c3_Kw, real_T c3_b_Vf_1, real_T *c3_Vf,
  real_T *c3_W);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_i_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_j_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_follower_qbot2, const char_T *
  c3_identifier);
static uint8_T c3_k_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_follower_qbot2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_Vf_1_not_empty = false;
  chartInstance->c3_end_flag_not_empty = false;
  chartInstance->c3_is_active_c3_follower_qbot2 = 0U;
}

static void initialize_params_c3_follower_qbot2
  (SFc3_follower_qbot2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_follower_qbot2
  (SFc3_follower_qbot2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_follower_qbot2
  (SFc3_follower_qbot2InstanceStruct *chartInstance)
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
  int32_T c3_i0;
  real_T c3_f_u[2];
  const mxArray *c3_g_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T *c3_Vf;
  real_T *c3_W;
  real_T *c3_ang_to_tar;
  real_T *c3_states;
  real_T *c3_target_distance;
  real_T (*c3_target_xy)[2];
  c3_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(9, 1), false);
  c3_hoistedGlobal = *c3_Vf;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_W;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_ang_to_tar;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_states;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_target_distance;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    c3_f_u[c3_i0] = (*c3_target_xy)[c3_i0];
  }

  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_f_hoistedGlobal = chartInstance->c3_Vf_1;
  c3_g_u = c3_f_hoistedGlobal;
  c3_h_y = NULL;
  if (!chartInstance->c3_Vf_1_not_empty) {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_g_hoistedGlobal = chartInstance->c3_end_flag;
  c3_h_u = c3_g_hoistedGlobal;
  c3_i_y = NULL;
  if (!chartInstance->c3_end_flag_not_empty) {
    sf_mex_assign(&c3_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_active_c3_follower_qbot2;
  c3_i_u = c3_h_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[2];
  int32_T c3_i1;
  real_T *c3_Vf;
  real_T *c3_W;
  real_T *c3_ang_to_tar;
  real_T *c3_states;
  real_T *c3_target_distance;
  real_T (*c3_target_xy)[2];
  c3_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *c3_Vf = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "Vf");
  *c3_W = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "W");
  *c3_ang_to_tar = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "ang_to_tar");
  *c3_states = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 3)), "states");
  *c3_target_distance = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "target_distance");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 5)),
                        "target_xy", c3_dv0);
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    (*c3_target_xy)[c3_i1] = c3_dv0[c3_i1];
  }

  chartInstance->c3_Vf_1 = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "Vf_1");
  chartInstance->c3_end_flag = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "end_flag");
  chartInstance->c3_is_active_c3_follower_qbot2 = c3_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 8)),
     "is_active_c3_follower_qbot2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_follower_qbot2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
{
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  real_T *c3_vlimit;
  real_T *c3_dist_thr;
  real_T *c3_ang_thr;
  real_T *c3_method;
  real_T *c3_step;
  real_T *c3_Kv_1;
  real_T *c3_Kw_1;
  real_T *c3_Kv_2;
  real_T *c3_Kw_2;
  real_T *c3_Psi_d;
  real_T *c3_Vf;
  real_T *c3_W;
  real_T *c3_target_distance;
  real_T *c3_ang_to_tar;
  real_T *c3_states;
  real_T *c3_pre_states;
  real_T (*c3_target_xy)[2];
  real_T (*c3_robot_xyt)[3];
  real_T (*c3_target_list)[2];
  c3_pre_states = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c3_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_Psi_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_Kw_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_Kv_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_Kw_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_Kv_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_method = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_ang_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_dist_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_vlimit = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_robot_xyt = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_target_list = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_target_list)[c3_i2], 0U);
  }

  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_robot_xyt)[c3_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_vlimit, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_dist_thr, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_ang_thr, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_method, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_step, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_Kv_1, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_Kw_1, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_Kv_2, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_Kw_2, 10U);
  _SFD_DATA_RANGE_CHECK(*c3_Psi_d, 11U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_follower_qbot2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_follower_qbot2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c3_Vf, 12U);
  _SFD_DATA_RANGE_CHECK(*c3_W, 13U);
  _SFD_DATA_RANGE_CHECK(*c3_target_distance, 14U);
  _SFD_DATA_RANGE_CHECK(*c3_ang_to_tar, 15U);
  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_target_xy)[c3_i4], 16U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_states, 17U);
  _SFD_DATA_RANGE_CHECK(*c3_pre_states, 18U);
}

static void c3_chartstep_c3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_k_hoistedGlobal;
  int32_T c3_i5;
  real_T c3_target_list[2];
  int32_T c3_i6;
  real_T c3_robot_xyt[3];
  real_T c3_vlimit;
  real_T c3_dist_thr;
  real_T c3_ang_thr;
  real_T c3_method;
  real_T c3_step;
  real_T c3_Kv_1;
  real_T c3_Kw_1;
  real_T c3_Kv_2;
  real_T c3_Kw_2;
  real_T c3_Psi_d;
  real_T c3_pre_states;
  uint32_T c3_debug_family_var_map[33];
  real_T c3_finished_path_flag;
  real_T c3_rx;
  real_T c3_ry;
  real_T c3_rtheta;
  real_T c3_n;
  real_T c3_xy;
  real_T c3_i;
  real_T c3_j;
  real_T c3_tx;
  real_T c3_ty;
  real_T c3_nargin = 13.0;
  real_T c3_nargout = 6.0;
  real_T c3_Vf;
  real_T c3_W;
  real_T c3_target_distance;
  real_T c3_ang_to_tar;
  real_T c3_target_xy[2];
  real_T c3_states;
  int32_T c3_b_j;
  real_T c3_b_rx;
  real_T c3_b_ry;
  real_T c3_b_tx;
  real_T c3_b_ty;
  uint32_T c3_b_debug_family_var_map[7];
  real_T c3_b_nargin = 4.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_rx;
  real_T c3_c_ry;
  real_T c3_b_rtheta;
  real_T c3_c_tx;
  real_T c3_c_ty;
  uint32_T c3_c_debug_family_var_map[10];
  real_T c3_X;
  real_T c3_Y;
  real_T c3_c_nargin = 5.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_y;
  real_T c3_c_x;
  real_T c3_b_y;
  real_T c3_d_x;
  real_T c3_b_W;
  real_T c3_b_Vf;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_d_y;
  real_T c3_dist;
  real_T c3_theta;
  real_T c3_b_vlimit;
  real_T c3_Kv;
  real_T c3_Kw;
  uint32_T c3_d_debug_family_var_map[13];
  real_T c3_d;
  real_T c3_vmax;
  real_T c3_wmax;
  real_T c3_w_sign;
  real_T c3_d_nargin = 5.0;
  real_T c3_d_nargout = 2.0;
  real_T c3_c_Vf;
  real_T c3_c_W;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_e_y;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_f_y;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_g_y;
  real_T c3_d_W;
  real_T c3_d_Vf;
  int32_T c3_i7;
  real_T *c3_c_vlimit;
  real_T *c3_b_dist_thr;
  real_T *c3_b_ang_thr;
  real_T *c3_b_method;
  real_T *c3_b_step;
  real_T *c3_b_Kv_1;
  real_T *c3_b_Kw_1;
  real_T *c3_b_Kv_2;
  real_T *c3_b_Kw_2;
  real_T *c3_b_Psi_d;
  real_T *c3_b_pre_states;
  real_T *c3_e_Vf;
  real_T *c3_e_W;
  real_T *c3_b_target_distance;
  real_T *c3_b_ang_to_tar;
  real_T *c3_b_states;
  real_T (*c3_b_target_xy)[2];
  real_T (*c3_b_robot_xyt)[3];
  real_T (*c3_b_target_list)[2];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  int32_T exitg1;
  c3_b_pre_states = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c3_b_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_b_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c3_b_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_b_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_e_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_e_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_Psi_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_b_Kw_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_b_Kv_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_Kw_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_b_Kv_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_method = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_ang_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_dist_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_c_vlimit = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_robot_xyt = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_target_list = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_c_vlimit;
  c3_b_hoistedGlobal = *c3_b_dist_thr;
  c3_c_hoistedGlobal = *c3_b_ang_thr;
  c3_d_hoistedGlobal = *c3_b_method;
  c3_e_hoistedGlobal = *c3_b_step;
  c3_f_hoistedGlobal = *c3_b_Kv_1;
  c3_g_hoistedGlobal = *c3_b_Kw_1;
  c3_h_hoistedGlobal = *c3_b_Kv_2;
  c3_i_hoistedGlobal = *c3_b_Kw_2;
  c3_j_hoistedGlobal = *c3_b_Psi_d;
  c3_k_hoistedGlobal = *c3_b_pre_states;
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    c3_target_list[c3_i5] = (*c3_b_target_list)[c3_i5];
  }

  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    c3_robot_xyt[c3_i6] = (*c3_b_robot_xyt)[c3_i6];
  }

  c3_vlimit = c3_hoistedGlobal;
  c3_dist_thr = c3_b_hoistedGlobal;
  c3_ang_thr = c3_c_hoistedGlobal;
  c3_method = c3_d_hoistedGlobal;
  c3_step = c3_e_hoistedGlobal;
  c3_Kv_1 = c3_f_hoistedGlobal;
  c3_Kw_1 = c3_g_hoistedGlobal;
  c3_Kv_2 = c3_h_hoistedGlobal;
  c3_Kw_2 = c3_i_hoistedGlobal;
  c3_Psi_d = c3_j_hoistedGlobal;
  c3_pre_states = c3_k_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_finished_path_flag, 0U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_rx, 1U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ry, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_rtheta, 3U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_n, 4U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_xy, 5U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_i, 6U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j, 7U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_tx, 8U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ty, 9U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 10U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 11U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_target_list, 12U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_robot_xyt, 13U, c3_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_vlimit, 14U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_dist_thr, 15U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_ang_thr, 16U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_method, 17U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_step, 18U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Kv_1, 19U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Kw_1, 20U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Kv_2, 21U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Kw_2, 22U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Psi_d, 23U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_pre_states, 24U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Vf, 25U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_W, 26U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_target_distance, 27U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ang_to_tar, 28U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_target_xy, 29U, c3_d_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_states, 30U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_Vf_1, 31U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_end_flag, 32U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_Vf = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_W = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_finished_path_flag = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_Vf_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
    chartInstance->c3_Vf_1 = 0.0;
    chartInstance->c3_Vf_1_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c3_end_flag_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
    chartInstance->c3_end_flag = 0.0;
    chartInstance->c3_end_flag_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  c3_states = c3_pre_states;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
  c3_rx = c3_robot_xyt[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
  c3_ry = c3_robot_xyt[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
  c3_rtheta = c3_check_angle(chartInstance, c3_robot_xyt[2]);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  c3_target_xy[0] = c3_rx;
  c3_target_xy[1] = c3_ry;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
  c3_n = 1.0;
  c3_xy = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
  CV_EML_COND(0, 1, 0, c3_n == 2.0);
  CV_EML_MCDC(0, 1, 0, false);
  CV_EML_IF(0, 1, 2, false);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  c3_i = 1.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
  if (CV_EML_IF(0, 1, 3, c3_states == c3_i)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
    c3_j = 1.0;
    c3_b_j = 0;
    while (c3_b_j < 2) {
      c3_j = 1.0 + (real_T)c3_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
      c3_target_xy[_SFD_EML_ARRAY_BOUNDS_CHECK("target_xy", (int32_T)
        _SFD_INTEGER_CHECK("j", c3_j), 1, 2, 1, 0) - 1] =
        c3_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list", (int32_T)
        _SFD_INTEGER_CHECK("j", c3_j), 1, 2, 2, 0) - 1];
      c3_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
  c3_tx = c3_target_xy[0];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
  c3_ty = c3_target_xy[1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
  c3_b_rx = c3_rx;
  c3_b_ry = c3_ry;
  c3_b_tx = c3_tx;
  c3_b_ty = c3_ty;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_c_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_rx, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_ry, 3U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_tx, 4U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_ty, 5U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_target_distance, 6U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 114);
  c3_x = c3_mpower(chartInstance, c3_b_rx - c3_b_tx) + c3_mpower(chartInstance,
    c3_b_ry - c3_b_ty);
  c3_target_distance = c3_x;
  if (c3_target_distance < 0.0) {
    c3_eml_error(chartInstance);
  }

  c3_b_x = c3_target_distance;
  c3_target_distance = c3_b_x;
  c3_target_distance = muDoubleScalarSqrt(c3_target_distance);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 115);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -115);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
  c3_c_rx = c3_rx;
  c3_c_ry = c3_ry;
  c3_b_rtheta = c3_rtheta;
  c3_c_tx = c3_tx;
  c3_c_ty = c3_ty;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c3_d_debug_family_names,
    c3_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_X, 0U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Y, 1U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 3U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_rx, 4U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_ry, 5U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_rtheta, 6U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_tx, 7U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_ty, 8U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ang_to_tar, 9U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  CV_EML_FCN(0, 3);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 119);
  c3_X = c3_c_tx - c3_c_rx;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 120);
  c3_Y = c3_c_ty - c3_c_ry;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 121);
  c3_y = c3_Y;
  c3_c_x = c3_X;
  c3_eml_scalar_eg(chartInstance);
  c3_b_y = c3_y;
  c3_d_x = c3_c_x;
  c3_ang_to_tar = muDoubleScalarAtan2(c3_b_y, c3_d_x);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 122);
  c3_ang_to_tar = c3_check_angle(chartInstance, c3_check_angle(chartInstance,
    c3_ang_to_tar) - c3_check_angle(chartInstance, c3_b_rtheta));
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 124);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -124);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
  guard1 = false;
  if (CV_EML_COND(0, 1, 2, c3_states == c3_n)) {
    if (CV_EML_COND(0, 1, 3, c3_target_distance <= c3_dist_thr)) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 4, true);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
      c3_Vf = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
      c3_W = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
      guard2 = false;
      if (CV_EML_COND(0, 1, 4, chartInstance->c3_end_flag == 1.0)) {
        if (CV_EML_COND(0, 1, 5, c3_target_distance <= c3_dist_thr)) {
          CV_EML_MCDC(0, 1, 2, true);
          CV_EML_IF(0, 1, 5, true);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
          c3_ClosedLoop_Sequential(chartInstance, 0.0, c3_check_angle
            (chartInstance, c3_check_angle(chartInstance, c3_Psi_d) -
             c3_check_angle(chartInstance, c3_rtheta)), c3_vlimit, c3_ang_thr,
            c3_Kv_1, c3_Kw_1, chartInstance->c3_Vf_1, &c3_b_Vf, &c3_b_W);
          c3_Vf = c3_b_Vf;
          c3_W = c3_b_W;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 56);
          chartInstance->c3_Vf_1 = c3_Vf;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 2, false);
        CV_EML_IF(0, 1, 5, false);
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 4, false);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 62);
    guard3 = false;
    if (CV_EML_COND(0, 1, 6, c3_target_distance <= c3_dist_thr)) {
      if (CV_EML_COND(0, 1, 7, chartInstance->c3_end_flag == 0.0)) {
        CV_EML_MCDC(0, 1, 3, true);
        CV_EML_IF(0, 1, 6, true);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 63);
        c3_states = c3_pre_states + c3_step;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 65);
        if (CV_EML_IF(0, 1, 7, c3_pre_states > 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
          do {
            exitg1 = 0;
            c3_e_x = c3_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
              (int32_T)_SFD_INTEGER_CHECK("states", c3_states), 1, 1, 1, 0) - 1]
              - c3_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
              (int32_T)_SFD_INTEGER_CHECK("pre_states", c3_pre_states), 1, 1, 1,
              0) - 1];
            c3_f_x = c3_e_x;
            c3_c_y = muDoubleScalarAbs(c3_f_x);
            if (c3_c_y < 2.0 * c3_dist_thr) {
              c3_g_x = c3_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
                (int32_T)_SFD_INTEGER_CHECK("states", c3_states), 1, 1, 1, 0)] -
                c3_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
                (int32_T)_SFD_INTEGER_CHECK("pre_states", c3_pre_states), 1, 1,
                1, 0)];
              c3_h_x = c3_g_x;
              c3_d_y = muDoubleScalarAbs(c3_h_x);
              if (c3_d_y < 2.0 * c3_dist_thr) {
                CV_EML_WHILE(0, 1, 0, true);
                _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 67);
                if (CV_EML_IF(0, 1, 8, c3_states <= c3_n - c3_step)) {
                  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 68);
                  c3_states += c3_step;
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 70);
                  c3_states = c3_n;
                }

                _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 66);
                _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
              } else {
                exitg1 = 1;
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          CV_EML_WHILE(0, 1, 0, false);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 74);
          c3_states += c3_step;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 77);
        if (CV_EML_IF(0, 1, 9, c3_states >= c3_n)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 78);
          c3_states = c3_n;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 79);
          chartInstance->c3_end_flag = 1.0;
        }
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(0, 1, 3, false);
      CV_EML_IF(0, 1, 6, false);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 89);
      if (CV_EML_IF(0, 1, 10, c3_method == 2.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 90);
        c3_dist = c3_target_distance;
        c3_theta = c3_ang_to_tar;
        c3_b_vlimit = c3_vlimit;
        c3_Kv = c3_Kv_2;
        c3_Kw = c3_Kw_2;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c3_f_debug_family_names,
          c3_d_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d, 0U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_vmax, 1U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_wmax, 2U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_w_sign, 3U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 4U,
          c3_c_sf_marshallOut, c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 5U,
          c3_c_sf_marshallOut, c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_dist, 6U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_theta, 7U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_vlimit, 8U,
          c3_c_sf_marshallOut, c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Kv, 9U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Kw, 10U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_Vf, 11U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_W, 12U, c3_c_sf_marshallOut,
          c3_c_sf_marshallIn);
        CV_EML_FCN(0, 4);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 129U);
        c3_d = 0.23;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 130U);
        c3_vmax = c3_b_vlimit;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 131U);
        c3_wmax = 2.0 * c3_vmax;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 132U);
        c3_c_W = c3_Kw * c3_theta;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 135U);
        c3_c_Vf = c3_Kv * c3_dist;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 140U);
        c3_i_x = c3_c_W;
        c3_w_sign = c3_i_x;
        c3_j_x = c3_w_sign;
        c3_w_sign = c3_j_x;
        c3_w_sign = muDoubleScalarSign(c3_w_sign);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 141U);
        c3_k_x = c3_c_W;
        c3_l_x = c3_k_x;
        c3_e_y = muDoubleScalarAbs(c3_l_x);
        if (CV_EML_IF(0, 1, 13, c3_e_y > c3_wmax)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 142U);
          c3_c_W = c3_w_sign * c3_wmax;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 144U);
        c3_m_x = c3_c_Vf;
        c3_n_x = c3_m_x;
        c3_f_y = muDoubleScalarAbs(c3_n_x);
        if (CV_EML_IF(0, 1, 14, c3_f_y > c3_b_vlimit)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 145U);
          c3_o_x = c3_c_Vf;
          c3_p_x = c3_o_x;
          c3_g_y = muDoubleScalarAbs(c3_p_x);
          c3_c_Vf = c3_g_y * c3_b_vlimit;
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 148U);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -148);
        _SFD_SYMBOL_SCOPE_POP();
        c3_Vf = c3_c_Vf;
        c3_W = c3_c_W;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 93);
        c3_ClosedLoop_Sequential(chartInstance, c3_target_distance,
          c3_ang_to_tar, c3_vlimit, c3_ang_thr, c3_Kv_1, c3_Kw_1,
          chartInstance->c3_Vf_1, &c3_d_Vf, &c3_d_W);
        c3_Vf = c3_d_Vf;
        c3_W = c3_d_W;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 94);
        chartInstance->c3_Vf_1 = c3_Vf;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 101);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -101);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_e_Vf = c3_Vf;
  *c3_e_W = c3_W;
  *c3_b_target_distance = c3_target_distance;
  *c3_b_ang_to_tar = c3_ang_to_tar;
  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    (*c3_b_target_xy)[c3_i7] = c3_target_xy[c3_i7];
  }

  *c3_b_states = c3_states;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_follower_qbot2(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
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
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_end_flag_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_b_end_flag, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_end_flag),
    &c3_thisId);
  sf_mex_destroy(&c3_b_end_flag);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_end_flag_not_empty = false;
  } else {
    chartInstance->c3_end_flag_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d0;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_end_flag;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_b_end_flag = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_end_flag),
    &c3_thisId);
  sf_mex_destroy(&c3_b_end_flag);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_Vf_1_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_b_Vf_1, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Vf_1), &c3_thisId);
  sf_mex_destroy(&c3_b_Vf_1);
  return c3_y;
}

static real_T c3_d_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_Vf_1_not_empty = false;
  } else {
    chartInstance->c3_Vf_1_not_empty = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d1;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Vf_1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_b_Vf_1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Vf_1), &c3_thisId);
  sf_mex_destroy(&c3_b_Vf_1);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_states, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_states), &c3_thisId);
  sf_mex_destroy(&c3_states);
  return c3_y;
}

static real_T c3_f_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_states;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_states = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_states), &c3_thisId);
  sf_mex_destroy(&c3_states);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i8;
  real_T c3_b_inData[2];
  int32_T c3_i9;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
    c3_b_inData[c3_i8] = (*(real_T (*)[2])c3_inData)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    c3_u[c3_i9] = c3_b_inData[c3_i9];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_target_xy, const char_T *c3_identifier,
  real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_target_xy), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_target_xy);
}

static void c3_h_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2])
{
  real_T c3_dv1[2];
  int32_T c3_i10;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c3_i10 = 0; c3_i10 < 2; c3_i10++) {
    c3_y[c3_i10] = c3_dv1[c3_i10];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_target_xy;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i11;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_target_xy = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_target_xy), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_target_xy);
  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    (*(real_T (*)[2])c3_outData)[c3_i11] = c3_y[c3_i11];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i12;
  real_T c3_b_inData[3];
  int32_T c3_i13;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
    c3_b_inData[c3_i12] = (*(real_T (*)[3])c3_inData)[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
    c3_u[c3_i13] = c3_b_inData[c3_i13];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_follower_qbot2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("ismatrix"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sqrt"), "name", "name", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343851986U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840338U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("atan2"), "name", "name", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343851972U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sign"), "name", "name", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1356563094U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static real_T c3_check_angle(SFc3_follower_qbot2InstanceStruct *chartInstance,
  real_T c3_x)
{
  real_T c3_y;
  uint32_T c3_debug_family_var_map[4];
  real_T c3_nargin = 1.0;
  real_T c3_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_x, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_y, 3U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 105);
  c3_y = c3_x;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 106);
  if (CV_EML_IF(0, 1, 11, c3_x > 3.1415926535897931)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 107);
    c3_y = c3_x - 6.2831853071795862;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 108);
    if (CV_EML_IF(0, 1, 12, c3_x < -3.1415926535897931)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 109);
      c3_y = c3_x + 6.2831853071795862;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 111);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -111);
  _SFD_SYMBOL_SCOPE_POP();
  return c3_y;
}

static real_T c3_mpower(SFc3_follower_qbot2InstanceStruct *chartInstance, real_T
  c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_eml_scalar_eg(chartInstance);
  return c3_d_a * c3_d_a;
}

static void c3_eml_scalar_eg(SFc3_follower_qbot2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_error(SFc3_follower_qbot2InstanceStruct *chartInstance)
{
  int32_T c3_i14;
  static char_T c3_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  int32_T c3_i15;
  static char_T c3_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c3_b_u[4];
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  for (c3_i14 = 0; c3_i14 < 30; c3_i14++) {
    c3_u[c3_i14] = c3_cv0[c3_i14];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c3_i15 = 0; c3_i15 < 4; c3_i15++) {
    c3_b_u[c3_i15] = c3_cv1[c3_i15];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c3_y, 14, c3_b_y));
}

static void c3_ClosedLoop_Sequential(SFc3_follower_qbot2InstanceStruct
  *chartInstance, real_T c3_dist, real_T c3_theta, real_T c3_vlimit, real_T
  c3_ang_thr, real_T c3_Kv, real_T c3_Kw, real_T c3_b_Vf_1, real_T *c3_Vf,
  real_T *c3_W)
{
  uint32_T c3_debug_family_var_map[14];
  real_T c3_d;
  real_T c3_vmax;
  real_T c3_wmax;
  real_T c3_nargin = 8.0;
  real_T c3_nargout = 2.0;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_d_y;
  real_T c3_k_x;
  real_T c3_l_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c3_e_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d, 0U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_vmax, 1U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_wmax, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_dist, 5U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_theta, 6U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_vlimit, 7U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ang_thr, 8U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Kv, 9U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Kw, 10U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Vf_1, 11U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Vf, 12U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_W, 13U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  CV_EML_FCN(0, 5);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 152U);
  c3_d = 0.23;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 153U);
  c3_vmax = c3_vlimit;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 154U);
  c3_wmax = 2.0 * c3_vmax;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 156U);
  c3_x = c3_theta;
  c3_b_x = c3_x;
  c3_y = muDoubleScalarAbs(c3_b_x);
  guard1 = false;
  guard2 = false;
  if (CV_EML_COND(0, 1, 8, c3_y > c3_ang_thr)) {
    if (CV_EML_COND(0, 1, 9, c3_b_Vf_1 < 0.01)) {
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    c3_c_x = c3_theta;
    c3_d_x = c3_c_x;
    c3_b_y = muDoubleScalarAbs(c3_d_x);
    if (CV_EML_COND(0, 1, 10, c3_b_y > 5.0 * c3_ang_thr)) {
      guard1 = true;
    } else {
      CV_EML_MCDC(0, 1, 4, false);
      CV_EML_IF(0, 1, 15, false);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 163U);
      *c3_Vf = c3_Kv * c3_dist;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 165U);
      c3_i_x = *c3_Vf;
      c3_j_x = c3_i_x;
      c3_d_y = muDoubleScalarAbs(c3_j_x);
      if (CV_EML_IF(0, 1, 17, c3_d_y > c3_vlimit)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 166U);
        c3_k_x = *c3_Vf;
        c3_l_x = c3_k_x;
        c3_l_x = muDoubleScalarSign(c3_l_x);
        *c3_Vf = c3_l_x * c3_vlimit;
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 172U);
      *c3_W = 0.0;
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 4, true);
    CV_EML_IF(0, 1, 15, true);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 157U);
    *c3_W = c3_Kw * c3_theta;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 158U);
    *c3_Vf = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 159U);
    c3_e_x = *c3_W;
    c3_f_x = c3_e_x;
    c3_c_y = muDoubleScalarAbs(c3_f_x);
    if (CV_EML_IF(0, 1, 16, c3_c_y > c3_wmax)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 160U);
      c3_g_x = c3_theta;
      c3_h_x = c3_g_x;
      c3_h_x = muDoubleScalarSign(c3_h_x);
      *c3_W = c3_h_x * c3_wmax;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 180U);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -180);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_i_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i16;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i16, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i16;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_j_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_follower_qbot2, const char_T *
  c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_follower_qbot2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_follower_qbot2);
  return c3_y;
}

static uint8_T c3_k_emlrt_marshallIn(SFc3_follower_qbot2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_follower_qbot2InstanceStruct
  *chartInstance)
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

void sf_c3_follower_qbot2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3018246994U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4219343303U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3142439062U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2538761168U);
}

mxArray *sf_c3_follower_qbot2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jVQdiAepMqwsxzlo2uqKKG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(2);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      pr[1] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_follower_qbot2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_follower_qbot2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_follower_qbot2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[12],T\"Vf\",},{M[1],M[13],T\"W\",},{M[1],M[18],T\"ang_to_tar\",},{M[1],M[15],T\"states\",},{M[1],M[14],T\"target_distance\",},{M[1],M[19],T\"target_xy\",},{M[4],M[0],T\"Vf_1\",S'l','i','p'{{M1x2[290 294],M[0],}}},{M[4],M[0],T\"end_flag\",S'l','i','p'{{M1x2[295 303],M[0],}}},{M[8],M[0],T\"is_active_c3_follower_qbot2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_follower_qbot2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_follower_qbot2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_follower_qbot2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _follower_qbot2MachineNumber_,
           3,
           1,
           1,
           0,
           19,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_follower_qbot2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_follower_qbot2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _follower_qbot2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"target_list");
          _SFD_SET_DATA_PROPS(1,1,1,0,"robot_xyt");
          _SFD_SET_DATA_PROPS(2,1,1,0,"vlimit");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dist_thr");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ang_thr");
          _SFD_SET_DATA_PROPS(5,1,1,0,"method");
          _SFD_SET_DATA_PROPS(6,1,1,0,"step");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Kv_1");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Kw_1");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Kv_2");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Kw_2");
          _SFD_SET_DATA_PROPS(11,1,1,0,"Psi_d");
          _SFD_SET_DATA_PROPS(12,2,0,1,"Vf");
          _SFD_SET_DATA_PROPS(13,2,0,1,"W");
          _SFD_SET_DATA_PROPS(14,2,0,1,"target_distance");
          _SFD_SET_DATA_PROPS(15,2,0,1,"ang_to_tar");
          _SFD_SET_DATA_PROPS(16,2,0,1,"target_xy");
          _SFD_SET_DATA_PROPS(17,2,0,1,"states");
          _SFD_SET_DATA_PROPS(18,1,1,0,"pre_states");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,6,18,0,0,0,2,1,11,5);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2938);
        _SFD_CV_INIT_EML_FCN(0,1,"check_angle",2938,-1,3124);
        _SFD_CV_INIT_EML_FCN(0,2,"find_dist",3124,-1,3286);
        _SFD_CV_INIT_EML_FCN(0,3,"find_theta",3286,-1,3534);
        _SFD_CV_INIT_EML_FCN(0,4,"ClosedLoop_Both",3534,-1,3828);
        _SFD_CV_INIT_EML_FCN(0,5,"ClosedLoop_Sequential",3828,-1,5161);
        _SFD_CV_INIT_EML_IF(0,1,0,308,324,-1,342);
        _SFD_CV_INIT_EML_IF(0,1,1,344,364,-1,387);
        _SFD_CV_INIT_EML_IF(0,1,2,535,551,616,773);
        _SFD_CV_INIT_EML_IF(0,1,3,643,660,-1,761);
        _SFD_CV_INIT_EML_IF(0,1,4,907,961,1445,2850);
        _SFD_CV_INIT_EML_IF(0,1,5,1146,1197,-1,1431);
        _SFD_CV_INIT_EML_IF(0,1,6,1459,1508,2406,2846);
        _SFD_CV_INIT_EML_IF(0,1,7,1568,1588,1930,1987);
        _SFD_CV_INIT_EML_IF(0,1,8,1772,1796,1860,1911);
        _SFD_CV_INIT_EML_IF(0,1,9,2008,2025,-1,2090);
        _SFD_CV_INIT_EML_IF(0,1,10,2441,2455,2565,2820);
        _SFD_CV_INIT_EML_IF(0,1,11,2975,2984,3003,3017);
        _SFD_CV_INIT_EML_IF(0,1,12,3003,3017,-1,3017);
        _SFD_CV_INIT_EML_IF(0,1,13,3728,3744,-1,3769);
        _SFD_CV_INIT_EML_IF(0,1,14,3770,3788,-1,3817);
        _SFD_CV_INIT_EML_IF(0,1,15,3967,4040,4280,4587);
        _SFD_CV_INIT_EML_IF(0,1,16,4220,4235,-1,4279);
        _SFD_CV_INIT_EML_IF(0,1,17,4321,4338,-1,4382);
        _SFD_CV_INIT_EML_FOR(0,1,0,625,635,769);
        _SFD_CV_INIT_EML_FOR(0,1,1,673,684,749);
        _SFD_CV_INIT_EML_WHILE(0,1,0,1598,1759,1924);

        {
          static int condStart[] = { 538, 546 };

          static int condEnd[] = { 542, 551 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,538,551,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 912, 932 };

          static int condEnd[] = { 926, 959 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,911,960,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1150, 1169 };

          static int condEnd[] = { 1163, 1196 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,1149,1197,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1463, 1496 };

          static int condEnd[] = { 1490, 1507 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,1462,1508,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 3973, 4001, 4017 };

          static int condEnd[] = { 3993, 4010, 4039 };

          static int pfixExpr[] = { 0, 1, -3, 2, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,3970,4040,3,8,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)
            c3_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_vlimit;
          real_T *c3_dist_thr;
          real_T *c3_ang_thr;
          real_T *c3_method;
          real_T *c3_step;
          real_T *c3_Kv_1;
          real_T *c3_Kw_1;
          real_T *c3_Kv_2;
          real_T *c3_Kw_2;
          real_T *c3_Psi_d;
          real_T *c3_Vf;
          real_T *c3_W;
          real_T *c3_target_distance;
          real_T *c3_ang_to_tar;
          real_T *c3_states;
          real_T *c3_pre_states;
          real_T (*c3_target_list)[2];
          real_T (*c3_robot_xyt)[3];
          real_T (*c3_target_xy)[2];
          c3_pre_states = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c3_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c3_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S,
            5);
          c3_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            3);
          c3_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_Psi_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c3_Kw_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c3_Kv_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c3_Kw_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c3_Kv_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_method = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_ang_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_dist_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_vlimit = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_robot_xyt = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c3_target_list = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_target_list);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_robot_xyt);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_vlimit);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_dist_thr);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_ang_thr);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_method);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_step);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_Kv_1);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_Kw_1);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_Kv_2);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_Kw_2);
          _SFD_SET_DATA_VALUE_PTR(11U, c3_Psi_d);
          _SFD_SET_DATA_VALUE_PTR(12U, c3_Vf);
          _SFD_SET_DATA_VALUE_PTR(13U, c3_W);
          _SFD_SET_DATA_VALUE_PTR(14U, c3_target_distance);
          _SFD_SET_DATA_VALUE_PTR(15U, c3_ang_to_tar);
          _SFD_SET_DATA_VALUE_PTR(16U, *c3_target_xy);
          _SFD_SET_DATA_VALUE_PTR(17U, c3_states);
          _SFD_SET_DATA_VALUE_PTR(18U, c3_pre_states);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _follower_qbot2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "bmsw4P7q8vBM6xQMVn6UfF";
}

static void sf_opaque_initialize_c3_follower_qbot2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_follower_qbot2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
    chartInstanceVar);
  initialize_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_follower_qbot2(void *chartInstanceVar)
{
  enable_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_follower_qbot2(void *chartInstanceVar)
{
  disable_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_follower_qbot2(void *chartInstanceVar)
{
  sf_gateway_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_follower_qbot2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_follower_qbot2
    ((SFc3_follower_qbot2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_follower_qbot2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_follower_qbot2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_follower_qbot2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_follower_qbot2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_follower_qbot2(S);
}

static void sf_opaque_set_sim_state_c3_follower_qbot2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_follower_qbot2(S, st);
}

static void sf_opaque_terminate_c3_follower_qbot2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_follower_qbot2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_follower_qbot2_optimization_info();
    }

    finalize_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_follower_qbot2(SimStruct *S)
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
    initialize_params_c3_follower_qbot2((SFc3_follower_qbot2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_follower_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_follower_qbot2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 13; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1187468471U));
  ssSetChecksum1(S,(2035174982U));
  ssSetChecksum2(S,(3547300091U));
  ssSetChecksum3(S,(40328455U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_follower_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_follower_qbot2(SimStruct *S)
{
  SFc3_follower_qbot2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_follower_qbot2InstanceStruct *)utMalloc(sizeof
    (SFc3_follower_qbot2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_follower_qbot2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_follower_qbot2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_follower_qbot2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_follower_qbot2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_follower_qbot2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_follower_qbot2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_follower_qbot2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_follower_qbot2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_follower_qbot2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_follower_qbot2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_follower_qbot2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_follower_qbot2;
  chartInstance->chartInfo.extModeExec = NULL;
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

void c3_follower_qbot2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_follower_qbot2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_follower_qbot2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_follower_qbot2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_follower_qbot2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
