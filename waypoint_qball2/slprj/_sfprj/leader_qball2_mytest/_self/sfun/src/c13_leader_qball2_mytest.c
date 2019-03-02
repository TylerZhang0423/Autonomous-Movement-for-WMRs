/* Include files */

#include <stddef.h>
#include "blas.h"
#include "leader_qball2_mytest_sfun.h"
#include "c13_leader_qball2_mytest.h"
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
static const char * c13_debug_family_names[20] = { "Q_angle", "Q_gyro",
  "R_angle", "e", "S", "K_0", "K_1", "nargin", "nargout", "acc_angle",
  "gyro_rate", "dt", "BatteryOnTop", "angle", "P_00", "P_01", "P_10", "P_11",
  "x_angle", "x_bias" };

/* Function Declarations */
static void initialize_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void initialize_params_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void enable_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void disable_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void set_sim_state_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray
   *c13_st);
static void finalize_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void sf_gateway_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void c13_chartstep_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void initSimStructsc13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_x_bias, const char_T *c13_identifier);
static real_T c13_b_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_x_angle, const char_T *c13_identifier);
static real_T c13_d_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_e_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_11, const char_T *c13_identifier);
static real_T c13_f_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_g_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_10, const char_T *c13_identifier);
static real_T c13_h_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_i_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_01, const char_T *c13_identifier);
static real_T c13_j_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_k_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_00, const char_T *c13_identifier);
static real_T c13_l_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_m_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_angle, const char_T *c13_identifier);
static real_T c13_n_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_info_helper(const mxArray **c13_info);
static const mxArray *c13_emlrt_marshallOut(const char * c13_u);
static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_u);
static const mxArray *c13_h_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_o_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_p_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_leader_qball2_mytest, const
  char_T *c13_identifier);
static uint8_T c13_q_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_P_00_not_empty = false;
  chartInstance->c13_P_01_not_empty = false;
  chartInstance->c13_P_10_not_empty = false;
  chartInstance->c13_P_11_not_empty = false;
  chartInstance->c13_x_angle_not_empty = false;
  chartInstance->c13_x_bias_not_empty = false;
  chartInstance->c13_is_active_c13_leader_qball2_mytest = 0U;
}

static void initialize_params_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c13_update_debugger_state_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_b_hoistedGlobal;
  real_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_c_hoistedGlobal;
  real_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_d_hoistedGlobal;
  real_T c13_d_u;
  const mxArray *c13_e_y = NULL;
  real_T c13_e_hoistedGlobal;
  real_T c13_e_u;
  const mxArray *c13_f_y = NULL;
  real_T c13_f_hoistedGlobal;
  real_T c13_f_u;
  const mxArray *c13_g_y = NULL;
  real_T c13_g_hoistedGlobal;
  real_T c13_g_u;
  const mxArray *c13_h_y = NULL;
  uint8_T c13_h_hoistedGlobal;
  uint8_T c13_h_u;
  const mxArray *c13_i_y = NULL;
  real_T *c13_angle;
  c13_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(8, 1), false);
  c13_hoistedGlobal = *c13_angle;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = chartInstance->c13_P_00;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  if (!chartInstance->c13_P_00_not_empty) {
    sf_mex_assign(&c13_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_c_hoistedGlobal = chartInstance->c13_P_01;
  c13_c_u = c13_c_hoistedGlobal;
  c13_d_y = NULL;
  if (!chartInstance->c13_P_01_not_empty) {
    sf_mex_assign(&c13_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c13_y, 2, c13_d_y);
  c13_d_hoistedGlobal = chartInstance->c13_P_10;
  c13_d_u = c13_d_hoistedGlobal;
  c13_e_y = NULL;
  if (!chartInstance->c13_P_10_not_empty) {
    sf_mex_assign(&c13_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c13_y, 3, c13_e_y);
  c13_e_hoistedGlobal = chartInstance->c13_P_11;
  c13_e_u = c13_e_hoistedGlobal;
  c13_f_y = NULL;
  if (!chartInstance->c13_P_11_not_empty) {
    sf_mex_assign(&c13_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_e_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c13_y, 4, c13_f_y);
  c13_f_hoistedGlobal = chartInstance->c13_x_angle;
  c13_f_u = c13_f_hoistedGlobal;
  c13_g_y = NULL;
  if (!chartInstance->c13_x_angle_not_empty) {
    sf_mex_assign(&c13_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_g_y, sf_mex_create("y", &c13_f_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c13_y, 5, c13_g_y);
  c13_g_hoistedGlobal = chartInstance->c13_x_bias;
  c13_g_u = c13_g_hoistedGlobal;
  c13_h_y = NULL;
  if (!chartInstance->c13_x_bias_not_empty) {
    sf_mex_assign(&c13_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_h_y, sf_mex_create("y", &c13_g_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c13_y, 6, c13_h_y);
  c13_h_hoistedGlobal = chartInstance->c13_is_active_c13_leader_qball2_mytest;
  c13_h_u = c13_h_hoistedGlobal;
  c13_i_y = NULL;
  sf_mex_assign(&c13_i_y, sf_mex_create("y", &c13_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 7, c13_i_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray
   *c13_st)
{
  const mxArray *c13_u;
  real_T *c13_angle;
  c13_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  *c13_angle = c13_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 0)), "angle");
  chartInstance->c13_P_00 = c13_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 1)), "P_00");
  chartInstance->c13_P_01 = c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 2)), "P_01");
  chartInstance->c13_P_10 = c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 3)), "P_10");
  chartInstance->c13_P_11 = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 4)), "P_11");
  chartInstance->c13_x_angle = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 5)), "x_angle");
  chartInstance->c13_x_bias = c13_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 6)), "x_bias");
  chartInstance->c13_is_active_c13_leader_qball2_mytest = c13_p_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 7)),
     "is_active_c13_leader_qball2_mytest");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_leader_qball2_mytest(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  real_T *c13_angle;
  real_T *c13_acc_angle;
  real_T *c13_gyro_rate;
  real_T *c13_dt;
  real_T *c13_BatteryOnTop;
  c13_BatteryOnTop = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c13_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c13_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c13_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c13_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
  chartInstance->c13_sfEvent = CALL_EVENT;
  c13_chartstep_c13_leader_qball2_mytest(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_leader_qball2_mytestMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c13_angle, 0U);
  _SFD_DATA_RANGE_CHECK(*c13_acc_angle, 1U);
  _SFD_DATA_RANGE_CHECK(*c13_gyro_rate, 2U);
  _SFD_DATA_RANGE_CHECK(*c13_dt, 3U);
  _SFD_DATA_RANGE_CHECK(*c13_BatteryOnTop, 4U);
}

static void c13_chartstep_c13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  real_T c13_hoistedGlobal;
  real_T c13_b_hoistedGlobal;
  real_T c13_c_hoistedGlobal;
  real_T c13_d_hoistedGlobal;
  real_T c13_acc_angle;
  real_T c13_gyro_rate;
  real_T c13_dt;
  real_T c13_BatteryOnTop;
  uint32_T c13_debug_family_var_map[20];
  real_T c13_Q_angle;
  real_T c13_Q_gyro;
  real_T c13_R_angle;
  real_T c13_e;
  real_T c13_S;
  real_T c13_K_0;
  real_T c13_K_1;
  real_T c13_nargin = 4.0;
  real_T c13_nargout = 1.0;
  real_T c13_angle;
  real_T c13_e_hoistedGlobal;
  real_T c13_A;
  real_T c13_B;
  real_T c13_x;
  real_T c13_y;
  real_T c13_b_x;
  real_T c13_b_y;
  real_T c13_c_x;
  real_T c13_c_y;
  real_T c13_f_hoistedGlobal;
  real_T c13_b_A;
  real_T c13_b_B;
  real_T c13_d_x;
  real_T c13_d_y;
  real_T c13_e_x;
  real_T c13_e_y;
  real_T c13_f_x;
  real_T c13_f_y;
  real_T *c13_b_BatteryOnTop;
  real_T *c13_b_dt;
  real_T *c13_b_gyro_rate;
  real_T *c13_b_acc_angle;
  real_T *c13_b_angle;
  c13_b_BatteryOnTop = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c13_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c13_b_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c13_b_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
  c13_hoistedGlobal = *c13_b_acc_angle;
  c13_b_hoistedGlobal = *c13_b_gyro_rate;
  c13_c_hoistedGlobal = *c13_b_dt;
  c13_d_hoistedGlobal = *c13_b_BatteryOnTop;
  c13_acc_angle = c13_hoistedGlobal;
  c13_gyro_rate = c13_b_hoistedGlobal;
  c13_dt = c13_c_hoistedGlobal;
  c13_BatteryOnTop = c13_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_Q_angle, 0U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_Q_gyro, 1U, c13_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_R_angle, 2U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_e, 3U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_S, 4U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_K_0, 5U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_K_1, 6U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 7U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 8U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_acc_angle, 9U, c13_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_gyro_rate, 10U, c13_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_dt, 11U, c13_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_BatteryOnTop, 12U, c13_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_angle, 13U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_P_00, 14U,
    c13_f_sf_marshallOut, c13_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_P_01, 15U,
    c13_e_sf_marshallOut, c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_P_10, 16U,
    c13_d_sf_marshallOut, c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_P_11, 17U,
    c13_c_sf_marshallOut, c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_x_angle, 18U,
    c13_b_sf_marshallOut, c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c13_x_bias, 19U,
    c13_sf_marshallOut, c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c13_BatteryOnTop == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
    c13_Q_angle = 0.001;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
    c13_Q_angle = 0.01;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 9);
  c13_Q_gyro = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 10);
  c13_R_angle = 0.03;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 18);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 20);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c13_P_00_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 21);
    chartInstance->c13_P_00 = 0.0;
    chartInstance->c13_P_00_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 24);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c13_P_01_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 25);
    chartInstance->c13_P_01 = 0.0;
    chartInstance->c13_P_01_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 27);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c13_P_10_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 28);
    chartInstance->c13_P_10 = 0.0;
    chartInstance->c13_P_10_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 30);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c13_P_11_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 31);
    chartInstance->c13_P_11 = 0.0;
    chartInstance->c13_P_11_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 33);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c13_x_bias_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 34);
    chartInstance->c13_x_bias = 0.0;
    chartInstance->c13_x_bias_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 36);
  if (CV_EML_IF(0, 1, 6, !chartInstance->c13_x_angle_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 37);
    chartInstance->c13_x_angle = 0.0;
    chartInstance->c13_x_angle_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 42);
  chartInstance->c13_x_angle += c13_dt * (c13_gyro_rate -
    chartInstance->c13_x_bias);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 43);
  chartInstance->c13_P_00 = (chartInstance->c13_P_00 - c13_dt *
    (chartInstance->c13_P_10 + chartInstance->c13_P_01)) + c13_Q_angle * c13_dt;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 44);
  chartInstance->c13_P_01 -= c13_dt * chartInstance->c13_P_11;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 45);
  chartInstance->c13_P_10 -= c13_dt * chartInstance->c13_P_11;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 46);
  chartInstance->c13_P_11 += 0.01 * c13_dt;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 49);
  c13_e = (0.97 * chartInstance->c13_x_angle + 0.03 * c13_acc_angle) -
    chartInstance->c13_x_angle;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 50);
  c13_S = chartInstance->c13_P_00 + c13_R_angle;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 51);
  c13_e_hoistedGlobal = chartInstance->c13_P_00;
  c13_A = c13_e_hoistedGlobal;
  c13_B = c13_S;
  c13_x = c13_A;
  c13_y = c13_B;
  c13_b_x = c13_x;
  c13_b_y = c13_y;
  c13_c_x = c13_b_x;
  c13_c_y = c13_b_y;
  c13_K_0 = c13_c_x / c13_c_y;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 52);
  c13_f_hoistedGlobal = chartInstance->c13_P_10;
  c13_b_A = c13_f_hoistedGlobal;
  c13_b_B = c13_S;
  c13_d_x = c13_b_A;
  c13_d_y = c13_b_B;
  c13_e_x = c13_d_x;
  c13_e_y = c13_d_y;
  c13_f_x = c13_e_x;
  c13_f_y = c13_e_y;
  c13_K_1 = c13_f_x / c13_f_y;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 55);
  chartInstance->c13_x_angle += c13_K_0 * c13_e;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 56);
  chartInstance->c13_x_bias += c13_K_1 * c13_e;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 57);
  chartInstance->c13_P_00 -= c13_K_0 * chartInstance->c13_P_00;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 58);
  chartInstance->c13_P_01 -= c13_K_0 * chartInstance->c13_P_01;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 59);
  chartInstance->c13_P_10 -= c13_K_1 * chartInstance->c13_P_00;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 60);
  chartInstance->c13_P_11 -= c13_K_1 * chartInstance->c13_P_01;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 62);
  c13_angle = chartInstance->c13_x_angle;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
  *c13_b_angle = c13_angle;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
}

static void initSimStructsc13_leader_qball2_mytest
  (SFc13_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  (void)c13_chartNumber;
  (void)c13_instanceNumber;
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_x_bias_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_x_bias, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_x_bias),
    &c13_thisId);
  sf_mex_destroy(&c13_b_x_bias);
  return c13_y;
}

static real_T c13_b_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_x_bias_not_empty = false;
  } else {
    chartInstance->c13_x_bias_not_empty = true;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d0;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_x_bias;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_b_x_bias = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_x_bias),
    &c13_thisId);
  sf_mex_destroy(&c13_b_x_bias);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_x_angle_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_x_angle, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_x_angle),
    &c13_thisId);
  sf_mex_destroy(&c13_b_x_angle);
  return c13_y;
}

static real_T c13_d_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d1;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_x_angle_not_empty = false;
  } else {
    chartInstance->c13_x_angle_not_empty = true;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d1, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d1;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_x_angle;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_b_x_angle = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_x_angle),
    &c13_thisId);
  sf_mex_destroy(&c13_b_x_angle);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_P_11_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_e_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_11, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_11),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_11);
  return c13_y;
}

static real_T c13_f_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d2;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_P_11_not_empty = false;
  } else {
    chartInstance->c13_P_11_not_empty = true;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d2, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d2;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_P_11;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_b_P_11 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_11),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_11);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_P_10_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_g_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_10, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_10),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_10);
  return c13_y;
}

static real_T c13_h_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d3;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_P_10_not_empty = false;
  } else {
    chartInstance->c13_P_10_not_empty = true;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d3, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d3;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_P_10;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_b_P_10 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_10),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_10);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_P_01_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_i_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_01, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_01),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_01);
  return c13_y;
}

static real_T c13_j_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d4;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_P_01_not_empty = false;
  } else {
    chartInstance->c13_P_01_not_empty = true;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d4, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d4;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_P_01;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_b_P_01 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_01),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_01);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  if (!chartInstance->c13_P_00_not_empty) {
    sf_mex_assign(&c13_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_k_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_P_00, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_00),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_00);
  return c13_y;
}

static real_T c13_l_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d5;
  if (mxIsEmpty(c13_u)) {
    chartInstance->c13_P_00_not_empty = false;
  } else {
    chartInstance->c13_P_00_not_empty = true;
    sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d5, 1, 0, 0U, 0, 0U, 0);
    c13_y = c13_d5;
  }

  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_P_00;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_b_P_00 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_P_00),
    &c13_thisId);
  sf_mex_destroy(&c13_b_P_00);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_m_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_angle, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_angle),
    &c13_thisId);
  sf_mex_destroy(&c13_angle);
  return c13_y;
}

static real_T c13_n_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d6;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d6, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d6;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_angle;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_angle = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_angle),
    &c13_thisId);
  sf_mex_destroy(&c13_angle);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_leader_qball2_mytest_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c13_info_helper(&c13_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(const mxArray **c13_info)
{
  const mxArray *c13_rhs0 = NULL;
  const mxArray *c13_lhs0 = NULL;
  const mxArray *c13_rhs1 = NULL;
  const mxArray *c13_lhs1 = NULL;
  const mxArray *c13_rhs2 = NULL;
  const mxArray *c13_lhs2 = NULL;
  const mxArray *c13_rhs3 = NULL;
  const mxArray *c13_lhs3 = NULL;
  const mxArray *c13_rhs4 = NULL;
  const mxArray *c13_lhs4 = NULL;
  const mxArray *c13_rhs5 = NULL;
  const mxArray *c13_lhs5 = NULL;
  const mxArray *c13_rhs6 = NULL;
  const mxArray *c13_lhs6 = NULL;
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c13_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c13_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c13_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c13_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c13_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c13_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c13_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c13_rhs0);
  sf_mex_destroy(&c13_lhs0);
  sf_mex_destroy(&c13_rhs1);
  sf_mex_destroy(&c13_lhs1);
  sf_mex_destroy(&c13_rhs2);
  sf_mex_destroy(&c13_lhs2);
  sf_mex_destroy(&c13_rhs3);
  sf_mex_destroy(&c13_lhs3);
  sf_mex_destroy(&c13_rhs4);
  sf_mex_destroy(&c13_lhs4);
  sf_mex_destroy(&c13_rhs5);
  sf_mex_destroy(&c13_lhs5);
  sf_mex_destroy(&c13_rhs6);
  sf_mex_destroy(&c13_lhs6);
}

static const mxArray *c13_emlrt_marshallOut(const char * c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c13_u)), false);
  return c13_y;
}

static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 7, 0U, 0U, 0U, 0), false);
  return c13_y;
}

static const mxArray *c13_h_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_o_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i0, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_p_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_leader_qball2_mytest, const
  char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_leader_qball2_mytest), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_leader_qball2_mytest);
  return c13_y;
}

static uint8_T c13_q_emlrt_marshallIn(SFc13_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_leader_qball2_mytestInstanceStruct
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

void sf_c13_leader_qball2_mytest_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3672875744U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1526184017U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2789263302U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3118531169U);
}

mxArray *sf_c13_leader_qball2_mytest_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xFG6tB0REHTKvhSxzuS5gH");
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

mxArray *sf_c13_leader_qball2_mytest_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_leader_qball2_mytest_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_leader_qball2_mytest(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[4],T\"angle\",},{M[4],M[0],T\"P_00\",S'l','i','p'{{M1x2[261 265],M[0],}}},{M[4],M[0],T\"P_01\",S'l','i','p'{{M1x2[282 286],M[0],}}},{M[4],M[0],T\"P_10\",S'l','i','p'{{M1x2[303 307],M[0],}}},{M[4],M[0],T\"P_11\",S'l','i','p'{{M1x2[324 328],M[0],}}},{M[4],M[0],T\"x_angle\",S'l','i','p'{{M1x2[345 352],M[0],}}},{M[4],M[0],T\"x_bias\",S'l','i','p'{{M1x2[369 375],M[0],}}},{M[8],M[0],T\"is_active_c13_leader_qball2_mytest\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_leader_qball2_mytest_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _leader_qball2_mytestMachineNumber_,
           13,
           1,
           1,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(3,1,1,0,"dt");
          _SFD_SET_DATA_PROPS(4,1,1,0,"BatteryOnTop");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1329);
        _SFD_CV_INIT_EML_IF(0,1,0,71,92,137,173);
        _SFD_CV_INIT_EML_IF(0,1,1,390,406,-1,432);
        _SFD_CV_INIT_EML_IF(0,1,2,442,458,-1,484);
        _SFD_CV_INIT_EML_IF(0,1,3,489,505,-1,531);
        _SFD_CV_INIT_EML_IF(0,1,4,536,552,-1,578);
        _SFD_CV_INIT_EML_IF(0,1,5,584,602,-1,631);
        _SFD_CV_INIT_EML_IF(0,1,6,637,656,-1,686);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_g_sf_marshallOut,(MexInFcnForType)
          c13_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c13_angle;
          real_T *c13_acc_angle;
          real_T *c13_gyro_rate;
          real_T *c13_dt;
          real_T *c13_BatteryOnTop;
          c13_BatteryOnTop = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c13_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c13_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c13_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c13_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_angle);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_acc_angle);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_gyro_rate);
          _SFD_SET_DATA_VALUE_PTR(3U, c13_dt);
          _SFD_SET_DATA_VALUE_PTR(4U, c13_BatteryOnTop);
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
  return "xDT88peDz76TrJfYloBUsF";
}

static void sf_opaque_initialize_c13_leader_qball2_mytest(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_leader_qball2_mytest
    ((SFc13_leader_qball2_mytestInstanceStruct*) chartInstanceVar);
  initialize_c13_leader_qball2_mytest((SFc13_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_leader_qball2_mytest(void *chartInstanceVar)
{
  enable_c13_leader_qball2_mytest((SFc13_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_leader_qball2_mytest(void *chartInstanceVar)
{
  disable_c13_leader_qball2_mytest((SFc13_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_leader_qball2_mytest(void *chartInstanceVar)
{
  sf_gateway_c13_leader_qball2_mytest((SFc13_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_leader_qball2_mytest
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_leader_qball2_mytest
    ((SFc13_leader_qball2_mytestInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_leader_qball2_mytest();/* state var info */
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

extern void sf_internal_set_sim_state_c13_leader_qball2_mytest(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c13_leader_qball2_mytest();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_leader_qball2_mytest
    ((SFc13_leader_qball2_mytestInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_leader_qball2_mytest(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c13_leader_qball2_mytest(S);
}

static void sf_opaque_set_sim_state_c13_leader_qball2_mytest(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_leader_qball2_mytest(S, st);
}

static void sf_opaque_terminate_c13_leader_qball2_mytest(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_leader_qball2_mytestInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_leader_qball2_mytest_optimization_info();
    }

    finalize_c13_leader_qball2_mytest((SFc13_leader_qball2_mytestInstanceStruct*)
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
  initSimStructsc13_leader_qball2_mytest
    ((SFc13_leader_qball2_mytestInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_leader_qball2_mytest(SimStruct *S)
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
    initialize_params_c13_leader_qball2_mytest
      ((SFc13_leader_qball2_mytestInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_leader_qball2_mytest_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3153443157U));
  ssSetChecksum1(S,(2379096038U));
  ssSetChecksum2(S,(1353648791U));
  ssSetChecksum3(S,(582492292U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_leader_qball2_mytest(SimStruct *S)
{
  SFc13_leader_qball2_mytestInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc13_leader_qball2_mytestInstanceStruct *)utMalloc(sizeof
    (SFc13_leader_qball2_mytestInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_leader_qball2_mytestInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_leader_qball2_mytest;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_leader_qball2_mytest;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_leader_qball2_mytest;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c13_leader_qball2_mytest;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_leader_qball2_mytest;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_leader_qball2_mytest;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_leader_qball2_mytest;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_leader_qball2_mytest;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_leader_qball2_mytest;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_leader_qball2_mytest;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_leader_qball2_mytest;
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

void c13_leader_qball2_mytest_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_leader_qball2_mytest(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_leader_qball2_mytest_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
