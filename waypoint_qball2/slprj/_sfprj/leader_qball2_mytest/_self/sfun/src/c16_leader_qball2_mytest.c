/* Include files */

#include <stddef.h>
#include "blas.h"
#include "leader_qball2_mytest_sfun.h"
#include "c16_leader_qball2_mytest.h"
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
static const char * c16_debug_family_names[19] = { "Q_angle", "Q_gyro",
  "R_angle", "e", "S", "K_0", "K_1", "nargin", "nargout", "acc_angle",
  "gyro_rate", "dt", "angle", "P_00", "P_01", "P_10", "P_11", "x_angle",
  "x_bias" };

/* Function Declarations */
static void initialize_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void initialize_params_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void enable_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void disable_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void set_sim_state_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray
   *c16_st);
static void finalize_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void sf_gateway_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void c16_chartstep_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void initSimStructsc16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_x_bias, const char_T *c16_identifier);
static real_T c16_b_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_c_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_x_angle, const char_T *c16_identifier);
static real_T c16_d_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_e_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_11, const char_T *c16_identifier);
static real_T c16_f_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_g_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_10, const char_T *c16_identifier);
static real_T c16_h_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_i_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_01, const char_T *c16_identifier);
static real_T c16_j_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_k_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_00, const char_T *c16_identifier);
static real_T c16_l_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_g_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_m_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_angle, const char_T *c16_identifier);
static real_T c16_n_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(const mxArray **c16_info);
static const mxArray *c16_emlrt_marshallOut(const char * c16_u);
static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u);
static const mxArray *c16_h_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_o_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_p_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_leader_qball2_mytest, const
  char_T *c16_identifier);
static uint8_T c16_q_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c16_P_00_not_empty = false;
  chartInstance->c16_P_01_not_empty = false;
  chartInstance->c16_P_10_not_empty = false;
  chartInstance->c16_P_11_not_empty = false;
  chartInstance->c16_x_angle_not_empty = false;
  chartInstance->c16_x_bias_not_empty = false;
  chartInstance->c16_is_active_c16_leader_qball2_mytest = 0U;
}

static void initialize_params_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c16_update_debugger_state_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  real_T c16_hoistedGlobal;
  real_T c16_u;
  const mxArray *c16_b_y = NULL;
  real_T c16_b_hoistedGlobal;
  real_T c16_b_u;
  const mxArray *c16_c_y = NULL;
  real_T c16_c_hoistedGlobal;
  real_T c16_c_u;
  const mxArray *c16_d_y = NULL;
  real_T c16_d_hoistedGlobal;
  real_T c16_d_u;
  const mxArray *c16_e_y = NULL;
  real_T c16_e_hoistedGlobal;
  real_T c16_e_u;
  const mxArray *c16_f_y = NULL;
  real_T c16_f_hoistedGlobal;
  real_T c16_f_u;
  const mxArray *c16_g_y = NULL;
  real_T c16_g_hoistedGlobal;
  real_T c16_g_u;
  const mxArray *c16_h_y = NULL;
  uint8_T c16_h_hoistedGlobal;
  uint8_T c16_h_u;
  const mxArray *c16_i_y = NULL;
  real_T *c16_angle;
  c16_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellmatrix(8, 1), false);
  c16_hoistedGlobal = *c16_angle;
  c16_u = c16_hoistedGlobal;
  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  c16_b_hoistedGlobal = chartInstance->c16_P_00;
  c16_b_u = c16_b_hoistedGlobal;
  c16_c_y = NULL;
  if (!chartInstance->c16_P_00_not_empty) {
    sf_mex_assign(&c16_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_c_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c16_y, 1, c16_c_y);
  c16_c_hoistedGlobal = chartInstance->c16_P_01;
  c16_c_u = c16_c_hoistedGlobal;
  c16_d_y = NULL;
  if (!chartInstance->c16_P_01_not_empty) {
    sf_mex_assign(&c16_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c16_y, 2, c16_d_y);
  c16_d_hoistedGlobal = chartInstance->c16_P_10;
  c16_d_u = c16_d_hoistedGlobal;
  c16_e_y = NULL;
  if (!chartInstance->c16_P_10_not_empty) {
    sf_mex_assign(&c16_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_e_y, sf_mex_create("y", &c16_d_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c16_y, 3, c16_e_y);
  c16_e_hoistedGlobal = chartInstance->c16_P_11;
  c16_e_u = c16_e_hoistedGlobal;
  c16_f_y = NULL;
  if (!chartInstance->c16_P_11_not_empty) {
    sf_mex_assign(&c16_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_f_y, sf_mex_create("y", &c16_e_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c16_y, 4, c16_f_y);
  c16_f_hoistedGlobal = chartInstance->c16_x_angle;
  c16_f_u = c16_f_hoistedGlobal;
  c16_g_y = NULL;
  if (!chartInstance->c16_x_angle_not_empty) {
    sf_mex_assign(&c16_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_g_y, sf_mex_create("y", &c16_f_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c16_y, 5, c16_g_y);
  c16_g_hoistedGlobal = chartInstance->c16_x_bias;
  c16_g_u = c16_g_hoistedGlobal;
  c16_h_y = NULL;
  if (!chartInstance->c16_x_bias_not_empty) {
    sf_mex_assign(&c16_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_h_y, sf_mex_create("y", &c16_g_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c16_y, 6, c16_h_y);
  c16_h_hoistedGlobal = chartInstance->c16_is_active_c16_leader_qball2_mytest;
  c16_h_u = c16_h_hoistedGlobal;
  c16_i_y = NULL;
  sf_mex_assign(&c16_i_y, sf_mex_create("y", &c16_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c16_y, 7, c16_i_y);
  sf_mex_assign(&c16_st, c16_y, false);
  return c16_st;
}

static void set_sim_state_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray
   *c16_st)
{
  const mxArray *c16_u;
  real_T *c16_angle;
  c16_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = true;
  c16_u = sf_mex_dup(c16_st);
  *c16_angle = c16_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c16_u, 0)), "angle");
  chartInstance->c16_P_00 = c16_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 1)), "P_00");
  chartInstance->c16_P_01 = c16_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 2)), "P_01");
  chartInstance->c16_P_10 = c16_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 3)), "P_10");
  chartInstance->c16_P_11 = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 4)), "P_11");
  chartInstance->c16_x_angle = c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 5)), "x_angle");
  chartInstance->c16_x_bias = c16_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c16_u, 6)), "x_bias");
  chartInstance->c16_is_active_c16_leader_qball2_mytest = c16_p_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 7)),
     "is_active_c16_leader_qball2_mytest");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_leader_qball2_mytest(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  real_T *c16_angle;
  real_T *c16_acc_angle;
  real_T *c16_gyro_rate;
  real_T *c16_dt;
  c16_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c16_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c16_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c16_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_leader_qball2_mytest(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_leader_qball2_mytestMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c16_angle, 0U);
  _SFD_DATA_RANGE_CHECK(*c16_acc_angle, 1U);
  _SFD_DATA_RANGE_CHECK(*c16_gyro_rate, 2U);
  _SFD_DATA_RANGE_CHECK(*c16_dt, 3U);
}

static void c16_chartstep_c16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  real_T c16_hoistedGlobal;
  real_T c16_b_hoistedGlobal;
  real_T c16_c_hoistedGlobal;
  real_T c16_acc_angle;
  real_T c16_gyro_rate;
  real_T c16_dt;
  uint32_T c16_debug_family_var_map[19];
  real_T c16_Q_angle;
  real_T c16_Q_gyro;
  real_T c16_R_angle;
  real_T c16_e;
  real_T c16_S;
  real_T c16_K_0;
  real_T c16_K_1;
  real_T c16_nargin = 3.0;
  real_T c16_nargout = 1.0;
  real_T c16_angle;
  real_T c16_d_hoistedGlobal;
  real_T c16_A;
  real_T c16_B;
  real_T c16_x;
  real_T c16_y;
  real_T c16_b_x;
  real_T c16_b_y;
  real_T c16_c_x;
  real_T c16_c_y;
  real_T c16_e_hoistedGlobal;
  real_T c16_b_A;
  real_T c16_b_B;
  real_T c16_d_x;
  real_T c16_d_y;
  real_T c16_e_x;
  real_T c16_e_y;
  real_T c16_f_x;
  real_T c16_f_y;
  real_T *c16_b_dt;
  real_T *c16_b_gyro_rate;
  real_T *c16_b_acc_angle;
  real_T *c16_b_angle;
  c16_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c16_b_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c16_b_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c16_b_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
  c16_hoistedGlobal = *c16_b_acc_angle;
  c16_b_hoistedGlobal = *c16_b_gyro_rate;
  c16_c_hoistedGlobal = *c16_b_dt;
  c16_acc_angle = c16_hoistedGlobal;
  c16_gyro_rate = c16_b_hoistedGlobal;
  c16_dt = c16_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_Q_angle, 0U, c16_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_Q_gyro, 1U, c16_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_R_angle, 2U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_e, 3U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_S, 4U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_K_0, 5U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_K_1, 6U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 7U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 8U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_acc_angle, 9U, c16_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_gyro_rate, 10U, c16_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_dt, 11U, c16_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_angle, 12U, c16_g_sf_marshallOut,
    c16_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c16_P_00, 13U,
    c16_f_sf_marshallOut, c16_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c16_P_01, 14U,
    c16_e_sf_marshallOut, c16_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c16_P_10, 15U,
    c16_d_sf_marshallOut, c16_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c16_P_11, 16U,
    c16_c_sf_marshallOut, c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c16_x_angle, 17U,
    c16_b_sf_marshallOut, c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c16_x_bias, 18U,
    c16_sf_marshallOut, c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 4);
  c16_Q_angle = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 5);
  c16_Q_gyro = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 6);
  c16_R_angle = 0.03;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 16);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c16_P_00_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 17);
    chartInstance->c16_P_00 = 0.0;
    chartInstance->c16_P_00_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 20);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c16_P_01_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 21);
    chartInstance->c16_P_01 = 0.0;
    chartInstance->c16_P_01_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 23);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c16_P_10_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 24);
    chartInstance->c16_P_10 = 0.0;
    chartInstance->c16_P_10_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 26);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c16_P_11_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 27);
    chartInstance->c16_P_11 = 0.0;
    chartInstance->c16_P_11_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 29);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c16_x_bias_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 30);
    chartInstance->c16_x_bias = 0.0;
    chartInstance->c16_x_bias_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 32);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c16_x_angle_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 33);
    chartInstance->c16_x_angle = 0.0;
    chartInstance->c16_x_angle_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 38);
  chartInstance->c16_x_angle += c16_dt * (c16_gyro_rate -
    chartInstance->c16_x_bias);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 39);
  chartInstance->c16_P_00 = (chartInstance->c16_P_00 - c16_dt *
    (chartInstance->c16_P_10 + chartInstance->c16_P_01)) + 0.01 * c16_dt;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 40);
  chartInstance->c16_P_01 -= c16_dt * chartInstance->c16_P_11;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 41);
  chartInstance->c16_P_10 -= c16_dt * chartInstance->c16_P_11;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 42);
  chartInstance->c16_P_11 += 0.01 * c16_dt;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 45);
  c16_e = (0.5 * chartInstance->c16_x_angle + 0.5 * c16_acc_angle) -
    chartInstance->c16_x_angle;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 46);
  c16_S = chartInstance->c16_P_00 + c16_R_angle;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 47);
  c16_d_hoistedGlobal = chartInstance->c16_P_00;
  c16_A = c16_d_hoistedGlobal;
  c16_B = c16_S;
  c16_x = c16_A;
  c16_y = c16_B;
  c16_b_x = c16_x;
  c16_b_y = c16_y;
  c16_c_x = c16_b_x;
  c16_c_y = c16_b_y;
  c16_K_0 = c16_c_x / c16_c_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 48);
  c16_e_hoistedGlobal = chartInstance->c16_P_10;
  c16_b_A = c16_e_hoistedGlobal;
  c16_b_B = c16_S;
  c16_d_x = c16_b_A;
  c16_d_y = c16_b_B;
  c16_e_x = c16_d_x;
  c16_e_y = c16_d_y;
  c16_f_x = c16_e_x;
  c16_f_y = c16_e_y;
  c16_K_1 = c16_f_x / c16_f_y;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 51);
  chartInstance->c16_x_angle += c16_K_0 * c16_e;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 52);
  chartInstance->c16_x_bias += c16_K_1 * c16_e;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 53);
  chartInstance->c16_P_00 -= c16_K_0 * chartInstance->c16_P_00;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 54);
  chartInstance->c16_P_01 -= c16_K_0 * chartInstance->c16_P_01;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 55);
  chartInstance->c16_P_10 -= c16_K_1 * chartInstance->c16_P_00;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 56);
  chartInstance->c16_P_11 -= c16_K_1 * chartInstance->c16_P_01;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 58);
  c16_angle = chartInstance->c16_x_angle;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -58);
  _SFD_SYMBOL_SCOPE_POP();
  *c16_b_angle = c16_angle;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_leader_qball2_mytest
  (SFc16_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber, uint32_T c16_instanceNumber)
{
  (void)c16_machineNumber;
  (void)c16_chartNumber;
  (void)c16_instanceNumber;
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  if (!chartInstance->c16_x_bias_not_empty) {
    sf_mex_assign(&c16_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_x_bias, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_x_bias),
    &c16_thisId);
  sf_mex_destroy(&c16_b_x_bias);
  return c16_y;
}

static real_T c16_b_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  if (mxIsEmpty(c16_u)) {
    chartInstance->c16_x_bias_not_empty = false;
  } else {
    chartInstance->c16_x_bias_not_empty = true;
    sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
    c16_y = c16_d0;
  }

  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_x_bias;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_b_x_bias = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_x_bias),
    &c16_thisId);
  sf_mex_destroy(&c16_b_x_bias);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  if (!chartInstance->c16_x_angle_not_empty) {
    sf_mex_assign(&c16_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_c_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_x_angle, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_x_angle),
    &c16_thisId);
  sf_mex_destroy(&c16_b_x_angle);
  return c16_y;
}

static real_T c16_d_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d1;
  if (mxIsEmpty(c16_u)) {
    chartInstance->c16_x_angle_not_empty = false;
  } else {
    chartInstance->c16_x_angle_not_empty = true;
    sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d1, 1, 0, 0U, 0, 0U, 0);
    c16_y = c16_d1;
  }

  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_x_angle;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_b_x_angle = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_x_angle),
    &c16_thisId);
  sf_mex_destroy(&c16_b_x_angle);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  if (!chartInstance->c16_P_11_not_empty) {
    sf_mex_assign(&c16_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_e_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_11, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_11),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_11);
  return c16_y;
}

static real_T c16_f_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d2;
  if (mxIsEmpty(c16_u)) {
    chartInstance->c16_P_11_not_empty = false;
  } else {
    chartInstance->c16_P_11_not_empty = true;
    sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d2, 1, 0, 0U, 0, 0U, 0);
    c16_y = c16_d2;
  }

  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_P_11;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_b_P_11 = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_11),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_11);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  if (!chartInstance->c16_P_10_not_empty) {
    sf_mex_assign(&c16_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_g_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_10, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_10),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_10);
  return c16_y;
}

static real_T c16_h_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d3;
  if (mxIsEmpty(c16_u)) {
    chartInstance->c16_P_10_not_empty = false;
  } else {
    chartInstance->c16_P_10_not_empty = true;
    sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d3, 1, 0, 0U, 0, 0U, 0);
    c16_y = c16_d3;
  }

  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_P_10;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_b_P_10 = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_10),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_10);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  if (!chartInstance->c16_P_01_not_empty) {
    sf_mex_assign(&c16_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_i_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_01, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_01),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_01);
  return c16_y;
}

static real_T c16_j_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d4;
  if (mxIsEmpty(c16_u)) {
    chartInstance->c16_P_01_not_empty = false;
  } else {
    chartInstance->c16_P_01_not_empty = true;
    sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d4, 1, 0, 0U, 0, 0U, 0);
    c16_y = c16_d4;
  }

  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_P_01;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_b_P_01 = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_01),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_01);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  if (!chartInstance->c16_P_00_not_empty) {
    sf_mex_assign(&c16_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_k_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_P_00, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_00),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_00);
  return c16_y;
}

static real_T c16_l_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d5;
  if (mxIsEmpty(c16_u)) {
    chartInstance->c16_P_00_not_empty = false;
  } else {
    chartInstance->c16_P_00_not_empty = true;
    sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d5, 1, 0, 0U, 0, 0U, 0);
    c16_y = c16_d5;
  }

  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_P_00;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_b_P_00 = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_P_00),
    &c16_thisId);
  sf_mex_destroy(&c16_b_P_00);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_g_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static real_T c16_m_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_angle, const char_T *c16_identifier)
{
  real_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_angle),
    &c16_thisId);
  sf_mex_destroy(&c16_angle);
  return c16_y;
}

static real_T c16_n_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d6;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d6, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d6;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_angle;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_angle = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_angle),
    &c16_thisId);
  sf_mex_destroy(&c16_angle);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_leader_qball2_mytest_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  sf_mex_assign(&c16_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c16_info_helper(&c16_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(const mxArray **c16_info)
{
  const mxArray *c16_rhs0 = NULL;
  const mxArray *c16_lhs0 = NULL;
  const mxArray *c16_rhs1 = NULL;
  const mxArray *c16_lhs1 = NULL;
  const mxArray *c16_rhs2 = NULL;
  const mxArray *c16_lhs2 = NULL;
  const mxArray *c16_rhs3 = NULL;
  const mxArray *c16_lhs3 = NULL;
  const mxArray *c16_rhs4 = NULL;
  const mxArray *c16_lhs4 = NULL;
  const mxArray *c16_rhs5 = NULL;
  const mxArray *c16_lhs5 = NULL;
  const mxArray *c16_rhs6 = NULL;
  const mxArray *c16_lhs6 = NULL;
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c16_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c16_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c16_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c16_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c16_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c16_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c16_info, c16_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c16_info, c16_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c16_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c16_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c16_info, sf_mex_duplicatearraysafe(&c16_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c16_rhs0);
  sf_mex_destroy(&c16_lhs0);
  sf_mex_destroy(&c16_rhs1);
  sf_mex_destroy(&c16_lhs1);
  sf_mex_destroy(&c16_rhs2);
  sf_mex_destroy(&c16_lhs2);
  sf_mex_destroy(&c16_rhs3);
  sf_mex_destroy(&c16_lhs3);
  sf_mex_destroy(&c16_rhs4);
  sf_mex_destroy(&c16_lhs4);
  sf_mex_destroy(&c16_rhs5);
  sf_mex_destroy(&c16_lhs5);
  sf_mex_destroy(&c16_rhs6);
  sf_mex_destroy(&c16_lhs6);
}

static const mxArray *c16_emlrt_marshallOut(const char * c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c16_u)), false);
  return c16_y;
}

static const mxArray *c16_b_emlrt_marshallOut(const uint32_T c16_u)
{
  const mxArray *c16_y = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 7, 0U, 0U, 0U, 0), false);
  return c16_y;
}

static const mxArray *c16_h_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, false);
  return c16_mxArrayOutData;
}

static int32_T c16_o_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i0, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_p_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_leader_qball2_mytest, const
  char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_leader_qball2_mytest), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_leader_qball2_mytest);
  return c16_y;
}

static uint8_T c16_q_emlrt_marshallIn(SFc16_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  (void)chartInstance;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_leader_qball2_mytestInstanceStruct
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

void sf_c16_leader_qball2_mytest_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(789255876U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2423035164U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(291723847U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3029398841U);
}

mxArray *sf_c16_leader_qball2_mytest_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LJbrp1HKVP78rDSKT32s3B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

mxArray *sf_c16_leader_qball2_mytest_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c16_leader_qball2_mytest_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c16_leader_qball2_mytest(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[4],T\"angle\",},{M[4],M[0],T\"P_00\",S'l','i','p'{{M1x2[178 182],M[0],}}},{M[4],M[0],T\"P_01\",S'l','i','p'{{M1x2[199 203],M[0],}}},{M[4],M[0],T\"P_10\",S'l','i','p'{{M1x2[220 224],M[0],}}},{M[4],M[0],T\"P_11\",S'l','i','p'{{M1x2[241 245],M[0],}}},{M[4],M[0],T\"x_angle\",S'l','i','p'{{M1x2[262 269],M[0],}}},{M[4],M[0],T\"x_bias\",S'l','i','p'{{M1x2[286 292],M[0],}}},{M[8],M[0],T\"is_active_c16_leader_qball2_mytest\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_leader_qball2_mytest_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _leader_qball2_mytestMachineNumber_,
           16,
           1,
           1,
           0,
           4,
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1244);
        _SFD_CV_INIT_EML_IF(0,1,0,307,323,-1,349);
        _SFD_CV_INIT_EML_IF(0,1,1,359,375,-1,401);
        _SFD_CV_INIT_EML_IF(0,1,2,406,422,-1,448);
        _SFD_CV_INIT_EML_IF(0,1,3,453,469,-1,495);
        _SFD_CV_INIT_EML_IF(0,1,4,501,519,-1,548);
        _SFD_CV_INIT_EML_IF(0,1,5,554,573,-1,603);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_g_sf_marshallOut,(MexInFcnForType)
          c16_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c16_angle;
          real_T *c16_acc_angle;
          real_T *c16_gyro_rate;
          real_T *c16_dt;
          c16_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c16_gyro_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c16_acc_angle = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c16_angle = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c16_angle);
          _SFD_SET_DATA_VALUE_PTR(1U, c16_acc_angle);
          _SFD_SET_DATA_VALUE_PTR(2U, c16_gyro_rate);
          _SFD_SET_DATA_VALUE_PTR(3U, c16_dt);
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
  return "OPGOJtI13b6YPIZn6TDa6B";
}

static void sf_opaque_initialize_c16_leader_qball2_mytest(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_leader_qball2_mytest
    ((SFc16_leader_qball2_mytestInstanceStruct*) chartInstanceVar);
  initialize_c16_leader_qball2_mytest((SFc16_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c16_leader_qball2_mytest(void *chartInstanceVar)
{
  enable_c16_leader_qball2_mytest((SFc16_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c16_leader_qball2_mytest(void *chartInstanceVar)
{
  disable_c16_leader_qball2_mytest((SFc16_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c16_leader_qball2_mytest(void *chartInstanceVar)
{
  sf_gateway_c16_leader_qball2_mytest((SFc16_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_leader_qball2_mytest
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_leader_qball2_mytest
    ((SFc16_leader_qball2_mytestInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_leader_qball2_mytest();/* state var info */
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

extern void sf_internal_set_sim_state_c16_leader_qball2_mytest(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c16_leader_qball2_mytest();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_leader_qball2_mytest
    ((SFc16_leader_qball2_mytestInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_leader_qball2_mytest(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c16_leader_qball2_mytest(S);
}

static void sf_opaque_set_sim_state_c16_leader_qball2_mytest(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c16_leader_qball2_mytest(S, st);
}

static void sf_opaque_terminate_c16_leader_qball2_mytest(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_leader_qball2_mytestInstanceStruct*) chartInstanceVar)
      ->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_leader_qball2_mytest_optimization_info();
    }

    finalize_c16_leader_qball2_mytest((SFc16_leader_qball2_mytestInstanceStruct*)
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
  initSimStructsc16_leader_qball2_mytest
    ((SFc16_leader_qball2_mytestInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_leader_qball2_mytest(SimStruct *S)
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
    initialize_params_c16_leader_qball2_mytest
      ((SFc16_leader_qball2_mytestInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_leader_qball2_mytest_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,16,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1364858449U));
  ssSetChecksum1(S,(1983176527U));
  ssSetChecksum2(S,(1304984343U));
  ssSetChecksum3(S,(2064831949U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_leader_qball2_mytest(SimStruct *S)
{
  SFc16_leader_qball2_mytestInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc16_leader_qball2_mytestInstanceStruct *)utMalloc(sizeof
    (SFc16_leader_qball2_mytestInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_leader_qball2_mytestInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_leader_qball2_mytest;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_leader_qball2_mytest;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_leader_qball2_mytest;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c16_leader_qball2_mytest;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_leader_qball2_mytest;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_leader_qball2_mytest;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_leader_qball2_mytest;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_leader_qball2_mytest;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_leader_qball2_mytest;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_leader_qball2_mytest;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_leader_qball2_mytest;
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

void c16_leader_qball2_mytest_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_leader_qball2_mytest(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_leader_qball2_mytest_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
