/* Include files */

#include <stddef.h>
#include "blas.h"
#include "leader_qball2_mytest_sfun.h"
#include "c4_leader_qball2_mytest.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "leader_qball2_mytest_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[21] = { "Q_angle", "Q_gyro", "R_angle",
  "e", "S", "K_0", "K_1", "nargin", "nargout", "acc_angle", "gyro_rate",
  "opti_angle", "dt", "BatteryOnTop", "angle", "P_00", "P_01", "P_10", "P_11",
  "x_angle", "x_bias" };

/* Function Declarations */
static void initialize_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void initialize_params_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void enable_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void disable_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void set_sim_state_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void sf_gateway_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void c4_chartstep_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void initSimStructsc4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_x_bias, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_x_angle, const char_T *c4_identifier);
static real_T c4_d_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_11, const char_T *c4_identifier);
static real_T c4_f_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_g_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_10, const char_T *c4_identifier);
static real_T c4_h_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_i_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_01, const char_T *c4_identifier);
static real_T c4_j_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_k_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_00, const char_T *c4_identifier);
static real_T c4_l_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_m_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_angle, const char_T *c4_identifier);
static real_T c4_n_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(const char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(const uint32_T c4_u);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_o_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_p_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_leader_qball2_mytest, const
  char_T *c4_identifier);
static uint8_T c4_q_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_P_00_not_empty = false;
  chartInstance->c4_P_01_not_empty = false;
  chartInstance->c4_P_10_not_empty = false;
  chartInstance->c4_P_11_not_empty = false;
  chartInstance->c4_x_angle_not_empty = false;
  chartInstance->c4_x_bias_not_empty = false;
  chartInstance->c4_is_active_c4_leader_qball2_mytest = 0U;
}

static void initialize_params_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
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
  real_T c4_f_hoistedGlobal;
  real_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  uint8_T c4_h_hoistedGlobal;
  uint8_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  real_T *c4_angle;
  c4_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(8, 1), false);
  c4_hoistedGlobal = *c4_angle;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_P_00;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  if (!chartInstance->c4_P_00_not_empty) {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = chartInstance->c4_P_01;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  if (!chartInstance->c4_P_01_not_empty) {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_P_10;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  if (!chartInstance->c4_P_10_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_P_11;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  if (!chartInstance->c4_P_11_not_empty) {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = chartInstance->c4_x_angle;
  c4_f_u = c4_f_hoistedGlobal;
  c4_g_y = NULL;
  if (!chartInstance->c4_x_angle_not_empty) {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_g_hoistedGlobal = chartInstance->c4_x_bias;
  c4_g_u = c4_g_hoistedGlobal;
  c4_h_y = NULL;
  if (!chartInstance->c4_x_bias_not_empty) {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_h_hoistedGlobal = chartInstance->c4_is_active_c4_leader_qball2_mytest;
  c4_h_u = c4_h_hoistedGlobal;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_angle;
  c4_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *c4_angle = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 0)), "angle");
  chartInstance->c4_P_00 = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "P_00");
  chartInstance->c4_P_01 = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "P_01");
  chartInstance->c4_P_10 = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 3)), "P_10");
  chartInstance->c4_P_11 = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 4)), "P_11");
  chartInstance->c4_x_angle = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 5)), "x_angle");
  chartInstance->c4_x_bias = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 6)), "x_bias");
  chartInstance->c4_is_active_c4_leader_qball2_mytest = c4_p_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
     "is_active_c4_leader_qball2_mytest");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_leader_qball2_mytest(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  real_T *c4_angle;
  real_T *c4_acc_angle;
  real_T *c4_gyro_rate;
  real_T *c4_opti_angle;
  real_T *c4_dt;
  real_T *c4_BatteryOnTop;
  c4_BatteryOnTop = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_opti_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_leader_qball2_mytest(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_leader_qball2_mytestMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c4_angle, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_acc_angle, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_gyro_rate, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_opti_angle, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_dt, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_BatteryOnTop, 5U);
}

static void c4_chartstep_c4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_acc_angle;
  real_T c4_gyro_rate;
  real_T c4_opti_angle;
  real_T c4_dt;
  real_T c4_BatteryOnTop;
  uint32_T c4_debug_family_var_map[21];
  real_T c4_Q_angle;
  real_T c4_Q_gyro;
  real_T c4_R_angle;
  real_T c4_e;
  real_T c4_S;
  real_T c4_K_0;
  real_T c4_K_1;
  real_T c4_nargin = 5.0;
  real_T c4_nargout = 1.0;
  real_T c4_angle;
  real_T c4_f_hoistedGlobal;
  real_T c4_A;
  real_T c4_B;
  real_T c4_x;
  real_T c4_y;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_g_hoistedGlobal;
  real_T c4_b_A;
  real_T c4_b_B;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T *c4_b_BatteryOnTop;
  real_T *c4_b_dt;
  real_T *c4_b_opti_angle;
  real_T *c4_b_gyro_rate;
  real_T *c4_b_acc_angle;
  real_T *c4_b_angle;
  c4_b_BatteryOnTop = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_opti_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_b_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_acc_angle;
  c4_b_hoistedGlobal = *c4_b_gyro_rate;
  c4_c_hoistedGlobal = *c4_b_opti_angle;
  c4_d_hoistedGlobal = *c4_b_dt;
  c4_e_hoistedGlobal = *c4_b_BatteryOnTop;
  c4_acc_angle = c4_hoistedGlobal;
  c4_gyro_rate = c4_b_hoistedGlobal;
  c4_opti_angle = c4_c_hoistedGlobal;
  c4_dt = c4_d_hoistedGlobal;
  c4_BatteryOnTop = c4_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 21U, 21U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Q_angle, 0U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Q_gyro, 1U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_R_angle, 2U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e, 3U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_S, 4U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_K_0, 5U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_K_1, 6U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 7U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 8U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_acc_angle, 9U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_gyro_rate, 10U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_opti_angle, 11U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_dt, 12U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_BatteryOnTop, 13U, c4_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_angle, 14U, c4_g_sf_marshallOut,
    c4_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_P_00, 15U,
    c4_f_sf_marshallOut, c4_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_P_01, 16U,
    c4_e_sf_marshallOut, c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_P_10, 17U,
    c4_d_sf_marshallOut, c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_P_11, 18U,
    c4_c_sf_marshallOut, c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_x_angle, 19U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_x_bias, 20U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c4_BatteryOnTop == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
    c4_Q_angle = 0.001;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
    c4_Q_angle = 0.01;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_Q_gyro = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_R_angle = 0.03;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c4_P_00_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
    chartInstance->c4_P_00 = 0.0;
    chartInstance->c4_P_00_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c4_P_01_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
    chartInstance->c4_P_01 = 0.0;
    chartInstance->c4_P_01_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c4_P_10_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
    chartInstance->c4_P_10 = 0.0;
    chartInstance->c4_P_10_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c4_P_11_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 31);
    chartInstance->c4_P_11 = 0.0;
    chartInstance->c4_P_11_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c4_x_bias_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 34);
    chartInstance->c4_x_bias = 0.0;
    chartInstance->c4_x_bias_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 36);
  if (CV_EML_IF(0, 1, 6, !chartInstance->c4_x_angle_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
    chartInstance->c4_x_angle = 0.0;
    chartInstance->c4_x_angle_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 42);
  chartInstance->c4_x_angle += c4_dt * (c4_gyro_rate - chartInstance->c4_x_bias);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
  chartInstance->c4_P_00 = (chartInstance->c4_P_00 - c4_dt *
    (chartInstance->c4_P_10 + chartInstance->c4_P_01)) + c4_Q_angle * c4_dt;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
  chartInstance->c4_P_01 -= c4_dt * chartInstance->c4_P_11;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 45);
  chartInstance->c4_P_10 -= c4_dt * chartInstance->c4_P_11;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 46);
  chartInstance->c4_P_11 += 0.01 * c4_dt;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 50);
  c4_e = ((0.9 * chartInstance->c4_x_angle + 0.01 * c4_acc_angle) + 0.09 *
          c4_opti_angle) - chartInstance->c4_x_angle;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 51);
  c4_S = chartInstance->c4_P_00 + c4_R_angle;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 52);
  c4_f_hoistedGlobal = chartInstance->c4_P_00;
  c4_A = c4_f_hoistedGlobal;
  c4_B = c4_S;
  c4_x = c4_A;
  c4_y = c4_B;
  c4_b_x = c4_x;
  c4_b_y = c4_y;
  c4_c_x = c4_b_x;
  c4_c_y = c4_b_y;
  c4_K_0 = c4_c_x / c4_c_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 53);
  c4_g_hoistedGlobal = chartInstance->c4_P_10;
  c4_b_A = c4_g_hoistedGlobal;
  c4_b_B = c4_S;
  c4_d_x = c4_b_A;
  c4_d_y = c4_b_B;
  c4_e_x = c4_d_x;
  c4_e_y = c4_d_y;
  c4_f_x = c4_e_x;
  c4_f_y = c4_e_y;
  c4_K_1 = c4_f_x / c4_f_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 56);
  chartInstance->c4_x_angle += c4_K_0 * c4_e;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 57);
  chartInstance->c4_x_bias += c4_K_1 * c4_e;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 58);
  chartInstance->c4_P_00 -= c4_K_0 * chartInstance->c4_P_00;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 59);
  chartInstance->c4_P_01 -= c4_K_0 * chartInstance->c4_P_01;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 60);
  chartInstance->c4_P_10 -= c4_K_1 * chartInstance->c4_P_00;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 61);
  chartInstance->c4_P_11 -= c4_K_1 * chartInstance->c4_P_01;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 63);
  c4_angle = chartInstance->c4_x_angle;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -63);
  _SFD_SYMBOL_SCOPE_POP();
  *c4_b_angle = c4_angle;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_leader_qball2_mytest
  (SFc4_leader_qball2_mytestInstanceStruct *chartInstance)
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
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_x_bias_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_x_bias, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_x_bias),
    &c4_thisId);
  sf_mex_destroy(&c4_b_x_bias);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_x_bias_not_empty = false;
  } else {
    chartInstance->c4_x_bias_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d0;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_x_bias;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_b_x_bias = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_x_bias),
    &c4_thisId);
  sf_mex_destroy(&c4_b_x_bias);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_x_angle_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_x_angle, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_x_angle),
    &c4_thisId);
  sf_mex_destroy(&c4_b_x_angle);
  return c4_y;
}

static real_T c4_d_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_x_angle_not_empty = false;
  } else {
    chartInstance->c4_x_angle_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d1;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_x_angle;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_b_x_angle = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_x_angle),
    &c4_thisId);
  sf_mex_destroy(&c4_b_x_angle);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_P_11_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_11, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_11), &c4_thisId);
  sf_mex_destroy(&c4_b_P_11);
  return c4_y;
}

static real_T c4_f_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_P_11_not_empty = false;
  } else {
    chartInstance->c4_P_11_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d2;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_P_11;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_b_P_11 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_11), &c4_thisId);
  sf_mex_destroy(&c4_b_P_11);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_P_10_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_g_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_10, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_10), &c4_thisId);
  sf_mex_destroy(&c4_b_P_10);
  return c4_y;
}

static real_T c4_h_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d3;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_P_10_not_empty = false;
  } else {
    chartInstance->c4_P_10_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d3, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d3;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_P_10;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_b_P_10 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_10), &c4_thisId);
  sf_mex_destroy(&c4_b_P_10);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_P_01_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_i_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_01, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_01), &c4_thisId);
  sf_mex_destroy(&c4_b_P_01);
  return c4_y;
}

static real_T c4_j_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d4;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_P_01_not_empty = false;
  } else {
    chartInstance->c4_P_01_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d4, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d4;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_P_01;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_b_P_01 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_01), &c4_thisId);
  sf_mex_destroy(&c4_b_P_01);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_P_00_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_k_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_P_00, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_00), &c4_thisId);
  sf_mex_destroy(&c4_b_P_00);
  return c4_y;
}

static real_T c4_l_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d5;
  if (mxIsEmpty(c4_u)) {
    chartInstance->c4_P_00_not_empty = false;
  } else {
    chartInstance->c4_P_00_not_empty = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d5, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d5;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_P_00;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_b_P_00 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_P_00), &c4_thisId);
  sf_mex_destroy(&c4_b_P_00);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_m_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_angle, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_angle), &c4_thisId);
  sf_mex_destroy(&c4_angle);
  return c4_y;
}

static real_T c4_n_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d6;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d6, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d6;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_angle;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_angle = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_angle), &c4_thisId);
  sf_mex_destroy(&c4_angle);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_leader_qball2_mytest_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
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
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
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

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_o_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i0, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_p_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_leader_qball2_mytest, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_leader_qball2_mytest), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_leader_qball2_mytest);
  return c4_y;
}

static uint8_T c4_q_emlrt_marshallIn(SFc4_leader_qball2_mytestInstanceStruct
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

static void init_dsm_address_info(SFc4_leader_qball2_mytestInstanceStruct
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

void sf_c4_leader_qball2_mytest_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2656408451U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4226951715U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1581800012U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1732251482U);
}

mxArray *sf_c4_leader_qball2_mytest_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bI5R6pKUhre2ShOiszjt0D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_leader_qball2_mytest_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_leader_qball2_mytest_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_leader_qball2_mytest(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[4],T\"angle\",},{M[4],M[0],T\"P_00\",S'l','i','p'{{M1x2[273 277],M[0],}}},{M[4],M[0],T\"P_01\",S'l','i','p'{{M1x2[294 298],M[0],}}},{M[4],M[0],T\"P_10\",S'l','i','p'{{M1x2[315 319],M[0],}}},{M[4],M[0],T\"P_11\",S'l','i','p'{{M1x2[336 340],M[0],}}},{M[4],M[0],T\"x_angle\",S'l','i','p'{{M1x2[357 364],M[0],}}},{M[4],M[0],T\"x_bias\",S'l','i','p'{{M1x2[381 387],M[0],}}},{M[8],M[0],T\"is_active_c4_leader_qball2_mytest\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_leader_qball2_mytest_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _leader_qball2_mytestMachineNumber_,
           4,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_leader_qball2_mytestMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_leader_qball2_mytestMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _leader_qball2_mytestMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"angle");
          _SFD_SET_DATA_PROPS(1,1,1,0,"acc_angle");
          _SFD_SET_DATA_PROPS(2,1,1,0,"gyro_rate");
          _SFD_SET_DATA_PROPS(3,1,1,0,"opti_angle");
          _SFD_SET_DATA_PROPS(4,1,1,0,"dt");
          _SFD_SET_DATA_PROPS(5,1,1,0,"BatteryOnTop");
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
        _SFD_CV_INIT_EML(0,1,1,7,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1408);
        _SFD_CV_INIT_EML_IF(0,1,0,82,103,147,183);
        _SFD_CV_INIT_EML_IF(0,1,1,402,418,-1,444);
        _SFD_CV_INIT_EML_IF(0,1,2,454,470,-1,496);
        _SFD_CV_INIT_EML_IF(0,1,3,501,517,-1,543);
        _SFD_CV_INIT_EML_IF(0,1,4,548,564,-1,590);
        _SFD_CV_INIT_EML_IF(0,1,5,596,614,-1,643);
        _SFD_CV_INIT_EML_IF(0,1,6,649,668,-1,698);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_g_sf_marshallOut,(MexInFcnForType)c4_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_angle;
          real_T *c4_acc_angle;
          real_T *c4_gyro_rate;
          real_T *c4_opti_angle;
          real_T *c4_dt;
          real_T *c4_BatteryOnTop;
          c4_BatteryOnTop = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_opti_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c4_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_angle);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_acc_angle);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_gyro_rate);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_opti_angle);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_dt);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_BatteryOnTop);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _leader_qball2_mytestMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "4tASnhwPvkvXY6lb1FUTgG";
}

static void sf_opaque_initialize_c4_leader_qball2_mytest(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_leader_qball2_mytest
    ((SFc4_leader_qball2_mytestInstanceStruct*) chartInstanceVar);
  initialize_c4_leader_qball2_mytest((SFc4_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_leader_qball2_mytest(void *chartInstanceVar)
{
  enable_c4_leader_qball2_mytest((SFc4_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_leader_qball2_mytest(void *chartInstanceVar)
{
  disable_c4_leader_qball2_mytest((SFc4_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_leader_qball2_mytest(void *chartInstanceVar)
{
  sf_gateway_c4_leader_qball2_mytest((SFc4_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_leader_qball2_mytest
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_leader_qball2_mytest
    ((SFc4_leader_qball2_mytestInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_leader_qball2_mytest();/* state var info */
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

extern void sf_internal_set_sim_state_c4_leader_qball2_mytest(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c4_leader_qball2_mytest();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_leader_qball2_mytest((SFc4_leader_qball2_mytestInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_leader_qball2_mytest(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c4_leader_qball2_mytest(S);
}

static void sf_opaque_set_sim_state_c4_leader_qball2_mytest(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_leader_qball2_mytest(S, st);
}

static void sf_opaque_terminate_c4_leader_qball2_mytest(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_leader_qball2_mytestInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_leader_qball2_mytest_optimization_info();
    }

    finalize_c4_leader_qball2_mytest((SFc4_leader_qball2_mytestInstanceStruct*)
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
  initSimStructsc4_leader_qball2_mytest((SFc4_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_leader_qball2_mytest(SimStruct *S)
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
    initialize_params_c4_leader_qball2_mytest
      ((SFc4_leader_qball2_mytestInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_leader_qball2_mytest_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(17733523U));
  ssSetChecksum1(S,(3808049489U));
  ssSetChecksum2(S,(3561949788U));
  ssSetChecksum3(S,(3821524448U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_leader_qball2_mytest(SimStruct *S)
{
  SFc4_leader_qball2_mytestInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_leader_qball2_mytestInstanceStruct *)utMalloc(sizeof
    (SFc4_leader_qball2_mytestInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_leader_qball2_mytestInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_leader_qball2_mytest;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_leader_qball2_mytest;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_leader_qball2_mytest;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_leader_qball2_mytest;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_leader_qball2_mytest;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_leader_qball2_mytest;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_leader_qball2_mytest;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_leader_qball2_mytest;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_leader_qball2_mytest;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_leader_qball2_mytest;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_leader_qball2_mytest;
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

void c4_leader_qball2_mytest_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_leader_qball2_mytest(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_leader_qball2_mytest_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
