/* Include files */

#include <stddef.h>
#include "blas.h"
#include "leader_qbot2_sfun.h"
#include "c4_leader_qbot2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "leader_qbot2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[33] = { "finished_path_flag", "rx",
  "ry", "rtheta", "n", "xy", "i", "j", "tx", "ty", "nargin", "nargout",
  "target_list", "robot_xyt", "vlimit", "dist_thr", "ang_thr", "method", "step",
  "Kv_1", "Kw_1", "Kv_2", "Kw_2", "Psi_d", "pre_states", "Vf", "W",
  "target_distance", "ang_to_tar", "target_xy", "states", "Vf_1", "end_flag" };

static const char * c4_b_debug_family_names[4] = { "nargin", "nargout", "x", "y"
};

static const char * c4_c_debug_family_names[7] = { "nargin", "nargout", "rx",
  "ry", "tx", "ty", "dist" };

static const char * c4_d_debug_family_names[10] = { "X", "Y", "nargin",
  "nargout", "rx", "ry", "rtheta", "tx", "ty", "theta" };

static const char * c4_e_debug_family_names[14] = { "d", "vmax", "wmax",
  "nargin", "nargout", "dist", "theta", "vlimit", "ang_thr", "Kv", "Kw", "Vf_1",
  "Vf", "W" };

static const char * c4_f_debug_family_names[13] = { "d", "vmax", "wmax",
  "w_sign", "nargin", "nargout", "dist", "theta", "vlimit", "Kv", "Kw", "Vf",
  "W" };

/* Function Declarations */
static void initialize_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void initialize_params_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void enable_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void disable_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_leader_qbot2
  (SFc4_leader_qbot2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_leader_qbot2
  (SFc4_leader_qbot2InstanceStruct *chartInstance);
static void set_sim_state_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void sf_gateway_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void c4_chartstep_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void initSimStructsc4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct *chartInstance,
  const mxArray *c4_b_end_flag, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_b_Vf_1, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_states, const char_T *c4_identifier);
static real_T c4_f_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_g_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct *chartInstance,
  const mxArray *c4_target_xy, const char_T *c4_identifier, real_T c4_y[2]);
static void c4_h_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[2]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static real_T c4_check_angle(SFc4_leader_qbot2InstanceStruct *chartInstance,
  real_T c4_x);
static real_T c4_mpower(SFc4_leader_qbot2InstanceStruct *chartInstance, real_T
  c4_a);
static void c4_eml_scalar_eg(SFc4_leader_qbot2InstanceStruct *chartInstance);
static void c4_eml_error(SFc4_leader_qbot2InstanceStruct *chartInstance);
static void c4_ClosedLoop_Sequential(SFc4_leader_qbot2InstanceStruct
  *chartInstance, real_T c4_dist, real_T c4_theta, real_T c4_vlimit, real_T
  c4_ang_thr, real_T c4_Kv, real_T c4_Kw, real_T c4_b_Vf_1, real_T *c4_Vf,
  real_T *c4_W);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_i_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_j_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_leader_qbot2, const char_T
  *c4_identifier);
static uint8_T c4_k_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_leader_qbot2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_Vf_1_not_empty = false;
  chartInstance->c4_end_flag_not_empty = false;
  chartInstance->c4_is_active_c4_leader_qbot2 = 0U;
}

static void initialize_params_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_leader_qbot2
  (SFc4_leader_qbot2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_leader_qbot2
  (SFc4_leader_qbot2InstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_e_hoistedGlobal;
  real_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  int32_T c4_i0;
  real_T c4_f_u[2];
  const mxArray *c4_g_y = NULL;
  real_T c4_f_hoistedGlobal;
  real_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  uint8_T c4_h_hoistedGlobal;
  uint8_T c4_i_u;
  const mxArray *c4_j_y = NULL;
  real_T *c4_Vf;
  real_T *c4_W;
  real_T *c4_ang_to_tar;
  real_T *c4_states;
  real_T *c4_target_distance;
  real_T (*c4_target_xy)[2];
  c4_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(9, 1), false);
  c4_hoistedGlobal = *c4_Vf;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_W;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_ang_to_tar;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_states;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = *c4_target_distance;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  for (c4_i0 = 0; c4_i0 < 2; c4_i0++) {
    c4_f_u[c4_i0] = (*c4_target_xy)[c4_i0];
  }

  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_f_hoistedGlobal = chartInstance->c4_Vf_1;
  c4_g_u = c4_f_hoistedGlobal;
  c4_h_y = NULL;
  if (!chartInstance->c4_Vf_1_not_empty) {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_g_hoistedGlobal = chartInstance->c4_end_flag;
  c4_h_u = c4_g_hoistedGlobal;
  c4_i_y = NULL;
  if (!chartInstance->c4_end_flag_not_empty) {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_h_hoistedGlobal = chartInstance->c4_is_active_c4_leader_qbot2;
  c4_i_u = c4_h_hoistedGlobal;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[2];
  int32_T c4_i1;
  real_T *c4_Vf;
  real_T *c4_W;
  real_T *c4_ang_to_tar;
  real_T *c4_states;
  real_T *c4_target_distance;
  real_T (*c4_target_xy)[2];
  c4_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *c4_Vf = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    0)), "Vf");
  *c4_W = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "W");
  *c4_ang_to_tar = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "ang_to_tar");
  *c4_states = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 3)), "states");
  *c4_target_distance = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 4)), "target_distance");
  c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
                        "target_xy", c4_dv0);
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    (*c4_target_xy)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_Vf_1 = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 6)), "Vf_1");
  chartInstance->c4_end_flag = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 7)), "end_flag");
  chartInstance->c4_is_active_c4_leader_qbot2 = c4_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 8)),
     "is_active_c4_leader_qbot2");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_leader_qbot2(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  real_T *c4_vlimit;
  real_T *c4_dist_thr;
  real_T *c4_ang_thr;
  real_T *c4_method;
  real_T *c4_step;
  real_T *c4_Kv_1;
  real_T *c4_Kw_1;
  real_T *c4_Kv_2;
  real_T *c4_Kw_2;
  real_T *c4_Psi_d;
  real_T *c4_Vf;
  real_T *c4_W;
  real_T *c4_target_distance;
  real_T *c4_ang_to_tar;
  real_T *c4_states;
  real_T *c4_pre_states;
  real_T (*c4_target_xy)[2];
  real_T (*c4_robot_xyt)[3];
  real_T (*c4_target_list)[2];
  c4_pre_states = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c4_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_Psi_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c4_Kw_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c4_Kv_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c4_Kw_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c4_Kv_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c4_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c4_method = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c4_ang_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_dist_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_vlimit = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_robot_xyt = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c4_target_list = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_target_list)[c4_i2], 0U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_robot_xyt)[c4_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_vlimit, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_dist_thr, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_ang_thr, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_method, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_step, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_Kv_1, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_Kw_1, 8U);
  _SFD_DATA_RANGE_CHECK(*c4_Kv_2, 9U);
  _SFD_DATA_RANGE_CHECK(*c4_Kw_2, 10U);
  _SFD_DATA_RANGE_CHECK(*c4_Psi_d, 11U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_leader_qbot2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_leader_qbot2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c4_Vf, 12U);
  _SFD_DATA_RANGE_CHECK(*c4_W, 13U);
  _SFD_DATA_RANGE_CHECK(*c4_target_distance, 14U);
  _SFD_DATA_RANGE_CHECK(*c4_ang_to_tar, 15U);
  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_target_xy)[c4_i4], 16U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_states, 17U);
  _SFD_DATA_RANGE_CHECK(*c4_pre_states, 18U);
}

static void c4_chartstep_c4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_f_hoistedGlobal;
  real_T c4_g_hoistedGlobal;
  real_T c4_h_hoistedGlobal;
  real_T c4_i_hoistedGlobal;
  real_T c4_j_hoistedGlobal;
  real_T c4_k_hoistedGlobal;
  int32_T c4_i5;
  real_T c4_target_list[2];
  int32_T c4_i6;
  real_T c4_robot_xyt[3];
  real_T c4_vlimit;
  real_T c4_dist_thr;
  real_T c4_ang_thr;
  real_T c4_method;
  real_T c4_step;
  real_T c4_Kv_1;
  real_T c4_Kw_1;
  real_T c4_Kv_2;
  real_T c4_Kw_2;
  real_T c4_Psi_d;
  real_T c4_pre_states;
  uint32_T c4_debug_family_var_map[33];
  real_T c4_finished_path_flag;
  real_T c4_rx;
  real_T c4_ry;
  real_T c4_rtheta;
  real_T c4_n;
  real_T c4_xy;
  real_T c4_i;
  real_T c4_j;
  real_T c4_tx;
  real_T c4_ty;
  real_T c4_nargin = 13.0;
  real_T c4_nargout = 6.0;
  real_T c4_Vf;
  real_T c4_W;
  real_T c4_target_distance;
  real_T c4_ang_to_tar;
  real_T c4_target_xy[2];
  real_T c4_states;
  int32_T c4_b_j;
  real_T c4_b_rx;
  real_T c4_b_ry;
  real_T c4_b_tx;
  real_T c4_b_ty;
  uint32_T c4_b_debug_family_var_map[7];
  real_T c4_b_nargin = 4.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_rx;
  real_T c4_c_ry;
  real_T c4_b_rtheta;
  real_T c4_c_tx;
  real_T c4_c_ty;
  uint32_T c4_c_debug_family_var_map[10];
  real_T c4_X;
  real_T c4_Y;
  real_T c4_c_nargin = 5.0;
  real_T c4_c_nargout = 1.0;
  real_T c4_y;
  real_T c4_c_x;
  real_T c4_b_y;
  real_T c4_d_x;
  real_T c4_b_W;
  real_T c4_b_Vf;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_c_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_d_y;
  real_T c4_dist;
  real_T c4_theta;
  real_T c4_b_vlimit;
  real_T c4_Kv;
  real_T c4_Kw;
  uint32_T c4_d_debug_family_var_map[13];
  real_T c4_d;
  real_T c4_vmax;
  real_T c4_wmax;
  real_T c4_w_sign;
  real_T c4_d_nargin = 5.0;
  real_T c4_d_nargout = 2.0;
  real_T c4_c_Vf;
  real_T c4_c_W;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_e_y;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_f_y;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_g_y;
  real_T c4_d_W;
  real_T c4_d_Vf;
  int32_T c4_i7;
  real_T *c4_c_vlimit;
  real_T *c4_b_dist_thr;
  real_T *c4_b_ang_thr;
  real_T *c4_b_method;
  real_T *c4_b_step;
  real_T *c4_b_Kv_1;
  real_T *c4_b_Kw_1;
  real_T *c4_b_Kv_2;
  real_T *c4_b_Kw_2;
  real_T *c4_b_Psi_d;
  real_T *c4_b_pre_states;
  real_T *c4_e_Vf;
  real_T *c4_e_W;
  real_T *c4_b_target_distance;
  real_T *c4_b_ang_to_tar;
  real_T *c4_b_states;
  real_T (*c4_b_target_xy)[2];
  real_T (*c4_b_robot_xyt)[3];
  real_T (*c4_b_target_list)[2];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  int32_T exitg1;
  c4_b_pre_states = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c4_b_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_b_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_b_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_e_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_e_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_Psi_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c4_b_Kw_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c4_b_Kv_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c4_b_Kw_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c4_b_Kv_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c4_b_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c4_b_method = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c4_b_ang_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_dist_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_c_vlimit = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_robot_xyt = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_target_list = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_c_vlimit;
  c4_b_hoistedGlobal = *c4_b_dist_thr;
  c4_c_hoistedGlobal = *c4_b_ang_thr;
  c4_d_hoistedGlobal = *c4_b_method;
  c4_e_hoistedGlobal = *c4_b_step;
  c4_f_hoistedGlobal = *c4_b_Kv_1;
  c4_g_hoistedGlobal = *c4_b_Kw_1;
  c4_h_hoistedGlobal = *c4_b_Kv_2;
  c4_i_hoistedGlobal = *c4_b_Kw_2;
  c4_j_hoistedGlobal = *c4_b_Psi_d;
  c4_k_hoistedGlobal = *c4_b_pre_states;
  for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
    c4_target_list[c4_i5] = (*c4_b_target_list)[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_robot_xyt[c4_i6] = (*c4_b_robot_xyt)[c4_i6];
  }

  c4_vlimit = c4_hoistedGlobal;
  c4_dist_thr = c4_b_hoistedGlobal;
  c4_ang_thr = c4_c_hoistedGlobal;
  c4_method = c4_d_hoistedGlobal;
  c4_step = c4_e_hoistedGlobal;
  c4_Kv_1 = c4_f_hoistedGlobal;
  c4_Kw_1 = c4_g_hoistedGlobal;
  c4_Kv_2 = c4_h_hoistedGlobal;
  c4_Kw_2 = c4_i_hoistedGlobal;
  c4_Psi_d = c4_j_hoistedGlobal;
  c4_pre_states = c4_k_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 33U, 33U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_finished_path_flag, 0U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_rx, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ry, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_rtheta, 3U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_n, 4U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_xy, 5U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_i, 6U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_j, 7U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_tx, 8U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ty, 9U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 10U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 11U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_target_list, 12U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_robot_xyt, 13U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_vlimit, 14U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_dist_thr, 15U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_ang_thr, 16U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_method, 17U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_step, 18U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Kv_1, 19U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Kw_1, 20U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Kv_2, 21U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Kw_2, 22U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Psi_d, 23U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_pre_states, 24U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Vf, 25U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_W, 26U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_target_distance, 27U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ang_to_tar, 28U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_target_xy, 29U, c4_d_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_states, 30U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_Vf_1, 31U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_end_flag, 32U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_Vf = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_W = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_finished_path_flag = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c4_Vf_1_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
    chartInstance->c4_Vf_1 = 0.0;
    chartInstance->c4_Vf_1_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c4_end_flag_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
    chartInstance->c4_end_flag = 0.0;
    chartInstance->c4_end_flag_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_states = c4_pre_states;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
  c4_rx = c4_robot_xyt[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
  c4_ry = c4_robot_xyt[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
  c4_rtheta = c4_check_angle(chartInstance, c4_robot_xyt[2]);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
  c4_target_xy[0] = c4_rx;
  c4_target_xy[1] = c4_ry;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
  c4_n = 1.0;
  c4_xy = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
  CV_EML_COND(0, 1, 0, c4_n == 2.0);
  CV_EML_MCDC(0, 1, 0, false);
  CV_EML_IF(0, 1, 2, false);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
  c4_i = 1.0;
  CV_EML_FOR(0, 1, 0, 1);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
  if (CV_EML_IF(0, 1, 3, c4_states == c4_i)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 34);
    c4_j = 1.0;
    c4_b_j = 0;
    while (c4_b_j < 2) {
      c4_j = 1.0 + (real_T)c4_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
      c4_target_xy[_SFD_EML_ARRAY_BOUNDS_CHECK("target_xy", (int32_T)
        _SFD_INTEGER_CHECK("j", c4_j), 1, 2, 1, 0) - 1] =
        c4_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list", (int32_T)
        _SFD_INTEGER_CHECK("j", c4_j), 1, 2, 2, 0) - 1];
      c4_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 41);
  c4_tx = c4_target_xy[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 42);
  c4_ty = c4_target_xy[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
  c4_b_rx = c4_rx;
  c4_b_ry = c4_ry;
  c4_b_tx = c4_tx;
  c4_b_ty = c4_ty;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c4_c_debug_family_names,
    c4_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_rx, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_ry, 3U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_tx, 4U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_ty, 5U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_target_distance, 6U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 114);
  c4_x = c4_mpower(chartInstance, c4_b_rx - c4_b_tx) + c4_mpower(chartInstance,
    c4_b_ry - c4_b_ty);
  c4_target_distance = c4_x;
  if (c4_target_distance < 0.0) {
    c4_eml_error(chartInstance);
  }

  c4_b_x = c4_target_distance;
  c4_target_distance = c4_b_x;
  c4_target_distance = muDoubleScalarSqrt(c4_target_distance);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 115);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -115);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
  c4_c_rx = c4_rx;
  c4_c_ry = c4_ry;
  c4_b_rtheta = c4_rtheta;
  c4_c_tx = c4_tx;
  c4_c_ty = c4_ty;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c4_d_debug_family_names,
    c4_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_X, 0U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Y, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 3U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_rx, 4U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_ry, 5U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_rtheta, 6U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_tx, 7U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_ty, 8U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ang_to_tar, 9U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  CV_EML_FCN(0, 3);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 119);
  c4_X = c4_c_tx - c4_c_rx;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 120);
  c4_Y = c4_c_ty - c4_c_ry;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 121);
  c4_y = c4_Y;
  c4_c_x = c4_X;
  c4_eml_scalar_eg(chartInstance);
  c4_b_y = c4_y;
  c4_d_x = c4_c_x;
  c4_ang_to_tar = muDoubleScalarAtan2(c4_b_y, c4_d_x);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 122);
  c4_ang_to_tar = c4_check_angle(chartInstance, c4_check_angle(chartInstance,
    c4_ang_to_tar) - c4_check_angle(chartInstance, c4_b_rtheta));
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 124);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -124);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 46);
  guard1 = false;
  if (CV_EML_COND(0, 1, 2, c4_states == c4_n)) {
    if (CV_EML_COND(0, 1, 3, c4_target_distance <= c4_dist_thr)) {
      CV_EML_MCDC(0, 1, 1, true);
      CV_EML_IF(0, 1, 4, true);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 51);
      c4_Vf = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 52);
      c4_W = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 54);
      guard2 = false;
      if (CV_EML_COND(0, 1, 4, chartInstance->c4_end_flag == 1.0)) {
        if (CV_EML_COND(0, 1, 5, c4_target_distance <= c4_dist_thr)) {
          CV_EML_MCDC(0, 1, 2, true);
          CV_EML_IF(0, 1, 5, true);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 55);
          c4_ClosedLoop_Sequential(chartInstance, 0.0, c4_check_angle
            (chartInstance, c4_check_angle(chartInstance, c4_Psi_d) -
             c4_check_angle(chartInstance, c4_rtheta)), c4_vlimit, c4_ang_thr,
            c4_Kv_1, c4_Kw_1, chartInstance->c4_Vf_1, &c4_b_Vf, &c4_b_W);
          c4_Vf = c4_b_Vf;
          c4_W = c4_b_W;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 56);
          chartInstance->c4_Vf_1 = c4_Vf;
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
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 62);
    guard3 = false;
    if (CV_EML_COND(0, 1, 6, c4_target_distance <= c4_dist_thr)) {
      if (CV_EML_COND(0, 1, 7, chartInstance->c4_end_flag == 0.0)) {
        CV_EML_MCDC(0, 1, 3, true);
        CV_EML_IF(0, 1, 6, true);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 63);
        c4_states = c4_pre_states + c4_step;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 65);
        if (CV_EML_IF(0, 1, 7, c4_pre_states > 0.0)) {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 66);
          do {
            exitg1 = 0;
            c4_e_x = c4_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
              (int32_T)_SFD_INTEGER_CHECK("states", c4_states), 1, 1, 1, 0) - 1]
              - c4_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
              (int32_T)_SFD_INTEGER_CHECK("pre_states", c4_pre_states), 1, 1, 1,
              0) - 1];
            c4_f_x = c4_e_x;
            c4_c_y = muDoubleScalarAbs(c4_f_x);
            if (c4_c_y < 2.0 * c4_dist_thr) {
              c4_g_x = c4_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
                (int32_T)_SFD_INTEGER_CHECK("states", c4_states), 1, 1, 1, 0)] -
                c4_target_list[_SFD_EML_ARRAY_BOUNDS_CHECK("target_list",
                (int32_T)_SFD_INTEGER_CHECK("pre_states", c4_pre_states), 1, 1,
                1, 0)];
              c4_h_x = c4_g_x;
              c4_d_y = muDoubleScalarAbs(c4_h_x);
              if (c4_d_y < 2.0 * c4_dist_thr) {
                CV_EML_WHILE(0, 1, 0, true);
                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 67);
                if (CV_EML_IF(0, 1, 8, c4_states <= c4_n - c4_step)) {
                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 68);
                  c4_states += c4_step;
                } else {
                  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 70);
                  c4_states = c4_n;
                }

                _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 66);
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
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 74);
          c4_states += c4_step;
        }

        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 77);
        if (CV_EML_IF(0, 1, 9, c4_states >= c4_n)) {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 78);
          c4_states = c4_n;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 79);
          chartInstance->c4_end_flag = 1.0;
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
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 89);
      if (CV_EML_IF(0, 1, 10, c4_method == 2.0)) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 90);
        c4_dist = c4_target_distance;
        c4_theta = c4_ang_to_tar;
        c4_b_vlimit = c4_vlimit;
        c4_Kv = c4_Kv_2;
        c4_Kw = c4_Kw_2;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c4_f_debug_family_names,
          c4_d_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d, 0U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vmax, 1U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_wmax, 2U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_w_sign, 3U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 4U,
          c4_c_sf_marshallOut, c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 5U,
          c4_c_sf_marshallOut, c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_dist, 6U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta, 7U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_vlimit, 8U,
          c4_c_sf_marshallOut, c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Kv, 9U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Kw, 10U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_Vf, 11U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_W, 12U, c4_c_sf_marshallOut,
          c4_c_sf_marshallIn);
        CV_EML_FCN(0, 4);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 129U);
        c4_d = 0.23;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 130U);
        c4_vmax = c4_b_vlimit;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 131U);
        c4_wmax = 2.0 * c4_vmax;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 132U);
        c4_c_W = c4_Kw * c4_theta;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 135U);
        c4_c_Vf = c4_Kv * c4_dist;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 140U);
        c4_i_x = c4_c_W;
        c4_w_sign = c4_i_x;
        c4_j_x = c4_w_sign;
        c4_w_sign = c4_j_x;
        c4_w_sign = muDoubleScalarSign(c4_w_sign);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 141U);
        c4_k_x = c4_c_W;
        c4_l_x = c4_k_x;
        c4_e_y = muDoubleScalarAbs(c4_l_x);
        if (CV_EML_IF(0, 1, 13, c4_e_y > c4_wmax)) {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 142U);
          c4_c_W = c4_w_sign * c4_wmax;
        }

        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 144U);
        c4_m_x = c4_c_Vf;
        c4_n_x = c4_m_x;
        c4_f_y = muDoubleScalarAbs(c4_n_x);
        if (CV_EML_IF(0, 1, 14, c4_f_y > c4_b_vlimit)) {
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 145U);
          c4_o_x = c4_c_Vf;
          c4_p_x = c4_o_x;
          c4_g_y = muDoubleScalarAbs(c4_p_x);
          c4_c_Vf = c4_g_y * c4_b_vlimit;
        }

        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 148U);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -148);
        _SFD_SYMBOL_SCOPE_POP();
        c4_Vf = c4_c_Vf;
        c4_W = c4_c_W;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 93);
        c4_ClosedLoop_Sequential(chartInstance, c4_target_distance,
          c4_ang_to_tar, c4_vlimit, c4_ang_thr, c4_Kv_1, c4_Kw_1,
          chartInstance->c4_Vf_1, &c4_d_Vf, &c4_d_W);
        c4_Vf = c4_d_Vf;
        c4_W = c4_d_W;
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 94);
        chartInstance->c4_Vf_1 = c4_Vf;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 101);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -101);
  _SFD_SYMBOL_SCOPE_POP();
  *c4_e_Vf = c4_Vf;
  *c4_e_W = c4_W;
  *c4_b_target_distance = c4_target_distance;
  *c4_b_ang_to_tar = c4_ang_to_tar;
  for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
    (*c4_b_target_xy)[c4_i7] = c4_target_xy[c4_i7];
  }

  *c4_b_states = c4_states;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_leader_qbot2(SFc4_leader_qbot2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_end_flag_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct *chartInstance,
  const mxArray *c4_b_end_flag, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_end_flag),
    &c4_thisId);
  sf_mex_destroy(&c4_b_end_flag);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_end_flag_not_empty = false;
  } else {
    chartInstance->c4_end_flag_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d0;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_end_flag;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_b_end_flag = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_end_flag),
    &c4_thisId);
  sf_mex_destroy(&c4_b_end_flag);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_Vf_1_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_b_Vf_1, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Vf_1), &c4_thisId);
  sf_mex_destroy(&c4_b_Vf_1);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_Vf_1_not_empty = false;
  } else {
    chartInstance->c4_Vf_1_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d1;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_Vf_1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_b_Vf_1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Vf_1), &c4_thisId);
  sf_mex_destroy(&c4_b_Vf_1);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_states, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_states), &c4_thisId);
  sf_mex_destroy(&c4_states);
  return c4_y;
}

static real_T c4_f_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_states;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_states = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_states), &c4_thisId);
  sf_mex_destroy(&c4_states);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i8;
  real_T c4_b_inData[2];
  int32_T c4_i9;
  real_T c4_u[2];
  const mxArray *c4_y = NULL;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
    c4_b_inData[c4_i8] = (*(real_T (*)[2])c4_inData)[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 2; c4_i9++) {
    c4_u[c4_i9] = c4_b_inData[c4_i9];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_g_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct *chartInstance,
  const mxArray *c4_target_xy, const char_T *c4_identifier, real_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_target_xy), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_target_xy);
}

static void c4_h_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[2])
{
  real_T c4_dv1[2];
  int32_T c4_i10;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
    c4_y[c4_i10] = c4_dv1[c4_i10];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_target_xy;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[2];
  int32_T c4_i11;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_target_xy = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_target_xy), &c4_thisId,
                        c4_y);
  sf_mex_destroy(&c4_target_xy);
  for (c4_i11 = 0; c4_i11 < 2; c4_i11++) {
    (*(real_T (*)[2])c4_outData)[c4_i11] = c4_y[c4_i11];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i12;
  real_T c4_b_inData[3];
  int32_T c4_i13;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_b_inData[c4_i12] = (*(real_T (*)[3])c4_inData)[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_u[c4_i13] = c4_b_inData[c4_i13];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 1), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

const mxArray *sf_c4_leader_qbot2_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  const mxArray *c4_rhs2 = NULL;
  const mxArray *c4_lhs2 = NULL;
  const mxArray *c4_rhs3 = NULL;
  const mxArray *c4_lhs3 = NULL;
  const mxArray *c4_rhs4 = NULL;
  const mxArray *c4_lhs4 = NULL;
  const mxArray *c4_rhs5 = NULL;
  const mxArray *c4_lhs5 = NULL;
  const mxArray *c4_rhs6 = NULL;
  const mxArray *c4_lhs6 = NULL;
  const mxArray *c4_rhs7 = NULL;
  const mxArray *c4_lhs7 = NULL;
  const mxArray *c4_rhs8 = NULL;
  const mxArray *c4_lhs8 = NULL;
  const mxArray *c4_rhs9 = NULL;
  const mxArray *c4_lhs9 = NULL;
  const mxArray *c4_rhs10 = NULL;
  const mxArray *c4_lhs10 = NULL;
  const mxArray *c4_rhs11 = NULL;
  const mxArray *c4_lhs11 = NULL;
  const mxArray *c4_rhs12 = NULL;
  const mxArray *c4_lhs12 = NULL;
  const mxArray *c4_rhs13 = NULL;
  const mxArray *c4_lhs13 = NULL;
  const mxArray *c4_rhs14 = NULL;
  const mxArray *c4_lhs14 = NULL;
  const mxArray *c4_rhs15 = NULL;
  const mxArray *c4_lhs15 = NULL;
  const mxArray *c4_rhs16 = NULL;
  const mxArray *c4_lhs16 = NULL;
  const mxArray *c4_rhs17 = NULL;
  const mxArray *c4_lhs17 = NULL;
  const mxArray *c4_rhs18 = NULL;
  const mxArray *c4_lhs18 = NULL;
  const mxArray *c4_rhs19 = NULL;
  const mxArray *c4_lhs19 = NULL;
  const mxArray *c4_rhs20 = NULL;
  const mxArray *c4_lhs20 = NULL;
  const mxArray *c4_rhs21 = NULL;
  const mxArray *c4_lhs21 = NULL;
  const mxArray *c4_rhs22 = NULL;
  const mxArray *c4_lhs22 = NULL;
  const mxArray *c4_rhs23 = NULL;
  const mxArray *c4_lhs23 = NULL;
  const mxArray *c4_rhs24 = NULL;
  const mxArray *c4_lhs24 = NULL;
  const mxArray *c4_rhs25 = NULL;
  const mxArray *c4_lhs25 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("ismatrix"), "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c4_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c4_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c4_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c4_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c4_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c4_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c4_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c4_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c4_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c4_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c4_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("sqrt"), "name", "name", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343851986U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c4_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_error"), "name", "name",
                  14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c4_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286840338U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c4_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("atan2"), "name", "name", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1343851972U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c4_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c4_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c4_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c4_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("abs"), "name", "name", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c4_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c4_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c4_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("sign"), "name", "name", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c4_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c4_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1356563094U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c4_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
  sf_mex_destroy(&c4_rhs2);
  sf_mex_destroy(&c4_lhs2);
  sf_mex_destroy(&c4_rhs3);
  sf_mex_destroy(&c4_lhs3);
  sf_mex_destroy(&c4_rhs4);
  sf_mex_destroy(&c4_lhs4);
  sf_mex_destroy(&c4_rhs5);
  sf_mex_destroy(&c4_lhs5);
  sf_mex_destroy(&c4_rhs6);
  sf_mex_destroy(&c4_lhs6);
  sf_mex_destroy(&c4_rhs7);
  sf_mex_destroy(&c4_lhs7);
  sf_mex_destroy(&c4_rhs8);
  sf_mex_destroy(&c4_lhs8);
  sf_mex_destroy(&c4_rhs9);
  sf_mex_destroy(&c4_lhs9);
  sf_mex_destroy(&c4_rhs10);
  sf_mex_destroy(&c4_lhs10);
  sf_mex_destroy(&c4_rhs11);
  sf_mex_destroy(&c4_lhs11);
  sf_mex_destroy(&c4_rhs12);
  sf_mex_destroy(&c4_lhs12);
  sf_mex_destroy(&c4_rhs13);
  sf_mex_destroy(&c4_lhs13);
  sf_mex_destroy(&c4_rhs14);
  sf_mex_destroy(&c4_lhs14);
  sf_mex_destroy(&c4_rhs15);
  sf_mex_destroy(&c4_lhs15);
  sf_mex_destroy(&c4_rhs16);
  sf_mex_destroy(&c4_lhs16);
  sf_mex_destroy(&c4_rhs17);
  sf_mex_destroy(&c4_lhs17);
  sf_mex_destroy(&c4_rhs18);
  sf_mex_destroy(&c4_lhs18);
  sf_mex_destroy(&c4_rhs19);
  sf_mex_destroy(&c4_lhs19);
  sf_mex_destroy(&c4_rhs20);
  sf_mex_destroy(&c4_lhs20);
  sf_mex_destroy(&c4_rhs21);
  sf_mex_destroy(&c4_lhs21);
  sf_mex_destroy(&c4_rhs22);
  sf_mex_destroy(&c4_lhs22);
  sf_mex_destroy(&c4_rhs23);
  sf_mex_destroy(&c4_lhs23);
  sf_mex_destroy(&c4_rhs24);
  sf_mex_destroy(&c4_lhs24);
  sf_mex_destroy(&c4_rhs25);
  sf_mex_destroy(&c4_lhs25);
}

static const mxArray *c4_emlrt_marshallOut(const char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), false);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  return c4_y;
}

static real_T c4_check_angle(SFc4_leader_qbot2InstanceStruct *chartInstance,
  real_T c4_x)
{
  real_T c4_y;
  uint32_T c4_debug_family_var_map[4];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c4_b_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y, 3U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 105);
  c4_y = c4_x;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 106);
  if (CV_EML_IF(0, 1, 11, c4_x > 3.1415926535897931)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 107);
    c4_y = c4_x - 6.2831853071795862;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 108);
    if (CV_EML_IF(0, 1, 12, c4_x < -3.1415926535897931)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 109);
      c4_y = c4_x + 6.2831853071795862;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 111);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -111);
  _SFD_SYMBOL_SCOPE_POP();
  return c4_y;
}

static real_T c4_mpower(SFc4_leader_qbot2InstanceStruct *chartInstance, real_T
  c4_a)
{
  real_T c4_b_a;
  real_T c4_c_a;
  real_T c4_ak;
  real_T c4_d_a;
  c4_b_a = c4_a;
  c4_c_a = c4_b_a;
  c4_eml_scalar_eg(chartInstance);
  c4_ak = c4_c_a;
  c4_d_a = c4_ak;
  c4_eml_scalar_eg(chartInstance);
  return c4_d_a * c4_d_a;
}

static void c4_eml_scalar_eg(SFc4_leader_qbot2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_eml_error(SFc4_leader_qbot2InstanceStruct *chartInstance)
{
  int32_T c4_i14;
  static char_T c4_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c4_u[30];
  const mxArray *c4_y = NULL;
  int32_T c4_i15;
  static char_T c4_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c4_b_u[4];
  const mxArray *c4_b_y = NULL;
  (void)chartInstance;
  for (c4_i14 = 0; c4_i14 < 30; c4_i14++) {
    c4_u[c4_i14] = c4_cv0[c4_i14];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c4_i15 = 0; c4_i15 < 4; c4_i15++) {
    c4_b_u[c4_i15] = c4_cv1[c4_i15];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c4_y, 14, c4_b_y));
}

static void c4_ClosedLoop_Sequential(SFc4_leader_qbot2InstanceStruct
  *chartInstance, real_T c4_dist, real_T c4_theta, real_T c4_vlimit, real_T
  c4_ang_thr, real_T c4_Kv, real_T c4_Kw, real_T c4_b_Vf_1, real_T *c4_Vf,
  real_T *c4_W)
{
  uint32_T c4_debug_family_var_map[14];
  real_T c4_d;
  real_T c4_vmax;
  real_T c4_wmax;
  real_T c4_nargin = 8.0;
  real_T c4_nargout = 2.0;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_y;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_b_y;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_c_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_d_y;
  real_T c4_k_x;
  real_T c4_l_x;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c4_e_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d, 0U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vmax, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_wmax, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_dist, 5U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_theta, 6U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vlimit, 7U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ang_thr, 8U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Kv, 9U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Kw, 10U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_Vf_1, 11U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Vf, 12U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_W, 13U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  CV_EML_FCN(0, 5);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 152U);
  c4_d = 0.23;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 153U);
  c4_vmax = c4_vlimit;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 154U);
  c4_wmax = 2.0 * c4_vmax;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 156U);
  c4_x = c4_theta;
  c4_b_x = c4_x;
  c4_y = muDoubleScalarAbs(c4_b_x);
  guard1 = false;
  guard2 = false;
  if (CV_EML_COND(0, 1, 8, c4_y > c4_ang_thr)) {
    if (CV_EML_COND(0, 1, 9, c4_b_Vf_1 < 0.01)) {
      guard1 = true;
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    c4_c_x = c4_theta;
    c4_d_x = c4_c_x;
    c4_b_y = muDoubleScalarAbs(c4_d_x);
    if (CV_EML_COND(0, 1, 10, c4_b_y > 5.0 * c4_ang_thr)) {
      guard1 = true;
    } else {
      CV_EML_MCDC(0, 1, 4, false);
      CV_EML_IF(0, 1, 15, false);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 163U);
      *c4_Vf = c4_Kv * c4_dist;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 165U);
      c4_i_x = *c4_Vf;
      c4_j_x = c4_i_x;
      c4_d_y = muDoubleScalarAbs(c4_j_x);
      if (CV_EML_IF(0, 1, 17, c4_d_y > c4_vlimit)) {
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 166U);
        c4_k_x = *c4_Vf;
        c4_l_x = c4_k_x;
        c4_l_x = muDoubleScalarSign(c4_l_x);
        *c4_Vf = c4_l_x * c4_vlimit;
      }

      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 172U);
      *c4_W = 0.0;
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 4, true);
    CV_EML_IF(0, 1, 15, true);
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 157U);
    *c4_W = c4_Kw * c4_theta;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 158U);
    *c4_Vf = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 159U);
    c4_e_x = *c4_W;
    c4_f_x = c4_e_x;
    c4_c_y = muDoubleScalarAbs(c4_f_x);
    if (CV_EML_IF(0, 1, 16, c4_c_y > c4_wmax)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 160U);
      c4_g_x = c4_theta;
      c4_h_x = c4_g_x;
      c4_h_x = muDoubleScalarSign(c4_h_x);
      *c4_W = c4_h_x * c4_wmax;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 180U);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -180);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_i_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i16;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i16, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i16;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_leader_qbot2, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_leader_qbot2), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_leader_qbot2);
  return c4_y;
}

static uint8_T c4_k_emlrt_marshallIn(SFc4_leader_qbot2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_leader_qbot2InstanceStruct *chartInstance)
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

void sf_c4_leader_qbot2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3018246994U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4219343303U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3142439062U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2538761168U);
}

mxArray *sf_c4_leader_qbot2_get_autoinheritance_info(void)
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

mxArray *sf_c4_leader_qbot2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_leader_qbot2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_leader_qbot2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[12],T\"Vf\",},{M[1],M[13],T\"W\",},{M[1],M[18],T\"ang_to_tar\",},{M[1],M[15],T\"states\",},{M[1],M[14],T\"target_distance\",},{M[1],M[19],T\"target_xy\",},{M[4],M[0],T\"Vf_1\",S'l','i','p'{{M1x2[290 294],M[0],}}},{M[4],M[0],T\"end_flag\",S'l','i','p'{{M1x2[295 303],M[0],}}},{M[8],M[0],T\"is_active_c4_leader_qbot2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_leader_qbot2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_leader_qbot2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_leader_qbot2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _leader_qbot2MachineNumber_,
           4,
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
        init_script_number_translation(_leader_qbot2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_leader_qbot2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _leader_qbot2MachineNumber_,
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
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)
            c4_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_vlimit;
          real_T *c4_dist_thr;
          real_T *c4_ang_thr;
          real_T *c4_method;
          real_T *c4_step;
          real_T *c4_Kv_1;
          real_T *c4_Kw_1;
          real_T *c4_Kv_2;
          real_T *c4_Kw_2;
          real_T *c4_Psi_d;
          real_T *c4_Vf;
          real_T *c4_W;
          real_T *c4_target_distance;
          real_T *c4_ang_to_tar;
          real_T *c4_states;
          real_T *c4_pre_states;
          real_T (*c4_target_list)[2];
          real_T (*c4_robot_xyt)[3];
          real_T (*c4_target_xy)[2];
          c4_pre_states = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c4_states = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c4_target_xy = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S,
            5);
          c4_ang_to_tar = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_target_distance = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            3);
          c4_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_Vf = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_Psi_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c4_Kw_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c4_Kv_2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c4_Kw_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c4_Kv_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c4_step = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c4_method = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c4_ang_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_dist_thr = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_vlimit = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_robot_xyt = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c4_target_list = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_target_list);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_robot_xyt);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_vlimit);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_dist_thr);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_ang_thr);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_method);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_step);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_Kv_1);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_Kw_1);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_Kv_2);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_Kw_2);
          _SFD_SET_DATA_VALUE_PTR(11U, c4_Psi_d);
          _SFD_SET_DATA_VALUE_PTR(12U, c4_Vf);
          _SFD_SET_DATA_VALUE_PTR(13U, c4_W);
          _SFD_SET_DATA_VALUE_PTR(14U, c4_target_distance);
          _SFD_SET_DATA_VALUE_PTR(15U, c4_ang_to_tar);
          _SFD_SET_DATA_VALUE_PTR(16U, *c4_target_xy);
          _SFD_SET_DATA_VALUE_PTR(17U, c4_states);
          _SFD_SET_DATA_VALUE_PTR(18U, c4_pre_states);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _leader_qbot2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "bmsw4P7q8vBM6xQMVn6UfF";
}

static void sf_opaque_initialize_c4_leader_qbot2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_leader_qbot2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*)
    chartInstanceVar);
  initialize_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_leader_qbot2(void *chartInstanceVar)
{
  enable_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_leader_qbot2(void *chartInstanceVar)
{
  disable_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_leader_qbot2(void *chartInstanceVar)
{
  sf_gateway_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_leader_qbot2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_leader_qbot2
    ((SFc4_leader_qbot2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_leader_qbot2();/* state var info */
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

extern void sf_internal_set_sim_state_c4_leader_qbot2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_leader_qbot2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_leader_qbot2(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_leader_qbot2(S);
}

static void sf_opaque_set_sim_state_c4_leader_qbot2(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c4_leader_qbot2(S, st);
}

static void sf_opaque_terminate_c4_leader_qbot2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_leader_qbot2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_leader_qbot2_optimization_info();
    }

    finalize_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_leader_qbot2(SimStruct *S)
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
    initialize_params_c4_leader_qbot2((SFc4_leader_qbot2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_leader_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_leader_qbot2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
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
        infoStruct,4,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,6);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
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

static void mdlRTW_c4_leader_qbot2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_leader_qbot2(SimStruct *S)
{
  SFc4_leader_qbot2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_leader_qbot2InstanceStruct *)utMalloc(sizeof
    (SFc4_leader_qbot2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_leader_qbot2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_leader_qbot2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_leader_qbot2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_leader_qbot2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_leader_qbot2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_leader_qbot2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_leader_qbot2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_leader_qbot2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_leader_qbot2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_leader_qbot2;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_leader_qbot2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_leader_qbot2;
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

void c4_leader_qbot2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_leader_qbot2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_leader_qbot2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_leader_qbot2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_leader_qbot2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
