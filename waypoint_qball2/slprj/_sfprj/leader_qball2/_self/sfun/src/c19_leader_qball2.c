/* Include files */

#include <stddef.h>
#include "blas.h"
#include "leader_qball2_sfun.h"
#include "c19_leader_qball2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "leader_qball2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c19_debug_family_names[19] = { "Q_sonar", "Q_optitrack",
  "R_height", "e", "S", "K_0", "K_1", "nargin", "nargout", "optitrack",
  "sonar_d", "dt", "height", "P_00", "P_01", "P_10", "P_11", "x_height",
  "x_bias" };

/* Function Declarations */
static void initialize_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance);
static void initialize_params_c19_leader_qball2
  (SFc19_leader_qball2InstanceStruct *chartInstance);
static void enable_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance);
static void disable_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance);
static void c19_update_debugger_state_c19_leader_qball2
  (SFc19_leader_qball2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_leader_qball2
  (SFc19_leader_qball2InstanceStruct *chartInstance);
static void set_sim_state_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_st);
static void finalize_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance);
static void sf_gateway_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance);
static void c19_chartstep_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance);
static void initSimStructsc19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_x_bias, const char_T *c19_identifier);
static real_T c19_b_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_c_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_x_height, const char_T *c19_identifier);
static real_T c19_d_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_e_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_11, const char_T *c19_identifier);
static real_T c19_f_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_g_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_10, const char_T *c19_identifier);
static real_T c19_h_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_e_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_i_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_01, const char_T *c19_identifier);
static real_T c19_j_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_f_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_k_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_00, const char_T *c19_identifier);
static real_T c19_l_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_g_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_m_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_height, const char_T *c19_identifier);
static real_T c19_n_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static void c19_info_helper(const mxArray **c19_info);
static const mxArray *c19_emlrt_marshallOut(const char * c19_u);
static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u);
static const mxArray *c19_h_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_o_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_p_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_leader_qball2, const char_T
  *c19_identifier);
static uint8_T c19_q_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info(SFc19_leader_qball2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_P_00_not_empty = false;
  chartInstance->c19_P_01_not_empty = false;
  chartInstance->c19_P_10_not_empty = false;
  chartInstance->c19_P_11_not_empty = false;
  chartInstance->c19_x_height_not_empty = false;
  chartInstance->c19_x_bias_not_empty = false;
  chartInstance->c19_is_active_c19_leader_qball2 = 0U;
}

static void initialize_params_c19_leader_qball2
  (SFc19_leader_qball2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_leader_qball2
  (SFc19_leader_qball2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c19_leader_qball2
  (SFc19_leader_qball2InstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  real_T c19_hoistedGlobal;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  real_T c19_b_hoistedGlobal;
  real_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T c19_c_hoistedGlobal;
  real_T c19_c_u;
  const mxArray *c19_d_y = NULL;
  real_T c19_d_hoistedGlobal;
  real_T c19_d_u;
  const mxArray *c19_e_y = NULL;
  real_T c19_e_hoistedGlobal;
  real_T c19_e_u;
  const mxArray *c19_f_y = NULL;
  real_T c19_f_hoistedGlobal;
  real_T c19_f_u;
  const mxArray *c19_g_y = NULL;
  real_T c19_g_hoistedGlobal;
  real_T c19_g_u;
  const mxArray *c19_h_y = NULL;
  uint8_T c19_h_hoistedGlobal;
  uint8_T c19_h_u;
  const mxArray *c19_i_y = NULL;
  real_T *c19_height;
  c19_height = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(8, 1), false);
  c19_hoistedGlobal = *c19_height;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal = chartInstance->c19_P_00;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  if (!chartInstance->c19_P_00_not_empty) {
    sf_mex_assign(&c19_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c19_y, 1, c19_c_y);
  c19_c_hoistedGlobal = chartInstance->c19_P_01;
  c19_c_u = c19_c_hoistedGlobal;
  c19_d_y = NULL;
  if (!chartInstance->c19_P_01_not_empty) {
    sf_mex_assign(&c19_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_c_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c19_y, 2, c19_d_y);
  c19_d_hoistedGlobal = chartInstance->c19_P_10;
  c19_d_u = c19_d_hoistedGlobal;
  c19_e_y = NULL;
  if (!chartInstance->c19_P_10_not_empty) {
    sf_mex_assign(&c19_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_e_y, sf_mex_create("y", &c19_d_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c19_y, 3, c19_e_y);
  c19_e_hoistedGlobal = chartInstance->c19_P_11;
  c19_e_u = c19_e_hoistedGlobal;
  c19_f_y = NULL;
  if (!chartInstance->c19_P_11_not_empty) {
    sf_mex_assign(&c19_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_f_y, sf_mex_create("y", &c19_e_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c19_y, 4, c19_f_y);
  c19_f_hoistedGlobal = chartInstance->c19_x_bias;
  c19_f_u = c19_f_hoistedGlobal;
  c19_g_y = NULL;
  if (!chartInstance->c19_x_bias_not_empty) {
    sf_mex_assign(&c19_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_g_y, sf_mex_create("y", &c19_f_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c19_y, 5, c19_g_y);
  c19_g_hoistedGlobal = chartInstance->c19_x_height;
  c19_g_u = c19_g_hoistedGlobal;
  c19_h_y = NULL;
  if (!chartInstance->c19_x_height_not_empty) {
    sf_mex_assign(&c19_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_h_y, sf_mex_create("y", &c19_g_u, 0, 0U, 0U, 0U, 0),
                  false);
  }

  sf_mex_setcell(c19_y, 6, c19_h_y);
  c19_h_hoistedGlobal = chartInstance->c19_is_active_c19_leader_qball2;
  c19_h_u = c19_h_hoistedGlobal;
  c19_i_y = NULL;
  sf_mex_assign(&c19_i_y, sf_mex_create("y", &c19_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 7, c19_i_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T *c19_height;
  c19_height = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  *c19_height = c19_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c19_u, 0)), "height");
  chartInstance->c19_P_00 = c19_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c19_u, 1)), "P_00");
  chartInstance->c19_P_01 = c19_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c19_u, 2)), "P_01");
  chartInstance->c19_P_10 = c19_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c19_u, 3)), "P_10");
  chartInstance->c19_P_11 = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c19_u, 4)), "P_11");
  chartInstance->c19_x_bias = c19_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c19_u, 5)), "x_bias");
  chartInstance->c19_x_height = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c19_u, 6)), "x_height");
  chartInstance->c19_is_active_c19_leader_qball2 = c19_p_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 7)),
     "is_active_c19_leader_qball2");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_leader_qball2(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance)
{
  real_T *c19_height;
  real_T *c19_optitrack;
  real_T *c19_sonar_d;
  real_T *c19_dt;
  c19_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c19_sonar_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c19_optitrack = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c19_height = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c19_sfEvent);
  chartInstance->c19_sfEvent = CALL_EVENT;
  c19_chartstep_c19_leader_qball2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_leader_qball2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c19_height, 0U);
  _SFD_DATA_RANGE_CHECK(*c19_optitrack, 1U);
  _SFD_DATA_RANGE_CHECK(*c19_sonar_d, 2U);
  _SFD_DATA_RANGE_CHECK(*c19_dt, 3U);
}

static void c19_chartstep_c19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance)
{
  real_T c19_hoistedGlobal;
  real_T c19_b_hoistedGlobal;
  real_T c19_c_hoistedGlobal;
  real_T c19_optitrack;
  real_T c19_sonar_d;
  real_T c19_dt;
  uint32_T c19_debug_family_var_map[19];
  real_T c19_Q_sonar;
  real_T c19_Q_optitrack;
  real_T c19_R_height;
  real_T c19_e;
  real_T c19_S;
  real_T c19_K_0;
  real_T c19_K_1;
  real_T c19_nargin = 3.0;
  real_T c19_nargout = 1.0;
  real_T c19_height;
  real_T c19_d_hoistedGlobal;
  real_T c19_A;
  real_T c19_B;
  real_T c19_x;
  real_T c19_y;
  real_T c19_b_x;
  real_T c19_b_y;
  real_T c19_c_x;
  real_T c19_c_y;
  real_T c19_e_hoistedGlobal;
  real_T c19_b_A;
  real_T c19_b_B;
  real_T c19_d_x;
  real_T c19_d_y;
  real_T c19_e_x;
  real_T c19_e_y;
  real_T c19_f_x;
  real_T c19_f_y;
  real_T *c19_b_dt;
  real_T *c19_b_sonar_d;
  real_T *c19_b_optitrack;
  real_T *c19_b_height;
  c19_b_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c19_b_sonar_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c19_b_optitrack = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c19_b_height = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = *c19_b_optitrack;
  c19_b_hoistedGlobal = *c19_b_sonar_d;
  c19_c_hoistedGlobal = *c19_b_dt;
  c19_optitrack = c19_hoistedGlobal;
  c19_sonar_d = c19_b_hoistedGlobal;
  c19_dt = c19_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_Q_sonar, 0U, c19_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_Q_optitrack, 1U, c19_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_R_height, 2U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_e, 3U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_S, 4U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_K_0, 5U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_K_1, 6U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 7U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 8U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_optitrack, 9U, c19_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_sonar_d, 10U, c19_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c19_dt, 11U, c19_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_height, 12U, c19_g_sf_marshallOut,
    c19_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c19_P_00, 13U,
    c19_f_sf_marshallOut, c19_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c19_P_01, 14U,
    c19_e_sf_marshallOut, c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c19_P_10, 15U,
    c19_d_sf_marshallOut, c19_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c19_P_11, 16U,
    c19_c_sf_marshallOut, c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c19_x_height, 17U,
    c19_b_sf_marshallOut, c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c19_x_bias, 18U,
    c19_sf_marshallOut, c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 4);
  c19_Q_sonar = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 5);
  c19_Q_optitrack = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 6);
  c19_R_height = 0.03;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 10);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 12);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 13);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 16);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c19_P_00_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 17);
    chartInstance->c19_P_00 = 0.0;
    chartInstance->c19_P_00_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 20);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c19_P_01_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 21);
    chartInstance->c19_P_01 = 0.0;
    chartInstance->c19_P_01_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 23);
  if (CV_EML_IF(0, 1, 2, !chartInstance->c19_P_10_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 24);
    chartInstance->c19_P_10 = 0.0;
    chartInstance->c19_P_10_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 26);
  if (CV_EML_IF(0, 1, 3, !chartInstance->c19_P_11_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 27);
    chartInstance->c19_P_11 = 0.0;
    chartInstance->c19_P_11_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 29);
  if (CV_EML_IF(0, 1, 4, !chartInstance->c19_x_bias_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 30);
    chartInstance->c19_x_bias = 0.0;
    chartInstance->c19_x_bias_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 32);
  if (CV_EML_IF(0, 1, 5, !chartInstance->c19_x_height_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 33);
    chartInstance->c19_x_height = 0.0;
    chartInstance->c19_x_height_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 38);
  chartInstance->c19_x_height += c19_dt * (c19_sonar_d -
    chartInstance->c19_x_bias);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 39);
  chartInstance->c19_P_00 = (chartInstance->c19_P_00 - c19_dt *
    (chartInstance->c19_P_10 + chartInstance->c19_P_01)) + 0.1 * c19_dt;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 40);
  chartInstance->c19_P_01 -= c19_dt * chartInstance->c19_P_11;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 41);
  chartInstance->c19_P_10 -= c19_dt * chartInstance->c19_P_11;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 42);
  chartInstance->c19_P_11 += 0.01 * c19_dt;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 45);
  c19_e = (0.05 * chartInstance->c19_x_height + 0.95 * c19_optitrack) -
    chartInstance->c19_x_height;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 46);
  c19_S = chartInstance->c19_P_00 + c19_R_height;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 47);
  c19_d_hoistedGlobal = chartInstance->c19_P_00;
  c19_A = c19_d_hoistedGlobal;
  c19_B = c19_S;
  c19_x = c19_A;
  c19_y = c19_B;
  c19_b_x = c19_x;
  c19_b_y = c19_y;
  c19_c_x = c19_b_x;
  c19_c_y = c19_b_y;
  c19_K_0 = c19_c_x / c19_c_y;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 48);
  c19_e_hoistedGlobal = chartInstance->c19_P_10;
  c19_b_A = c19_e_hoistedGlobal;
  c19_b_B = c19_S;
  c19_d_x = c19_b_A;
  c19_d_y = c19_b_B;
  c19_e_x = c19_d_x;
  c19_e_y = c19_d_y;
  c19_f_x = c19_e_x;
  c19_f_y = c19_e_y;
  c19_K_1 = c19_f_x / c19_f_y;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 51);
  chartInstance->c19_x_height += c19_K_0 * c19_e;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 52);
  chartInstance->c19_x_bias += c19_K_1 * c19_e;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 53);
  chartInstance->c19_P_00 -= c19_K_0 * chartInstance->c19_P_00;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 54);
  chartInstance->c19_P_01 -= c19_K_0 * chartInstance->c19_P_01;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 55);
  chartInstance->c19_P_10 -= c19_K_1 * chartInstance->c19_P_00;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 56);
  chartInstance->c19_P_11 -= c19_K_1 * chartInstance->c19_P_01;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 58);
  c19_height = chartInstance->c19_x_height;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -58);
  _SFD_SYMBOL_SCOPE_POP();
  *c19_b_height = c19_height;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c19_sfEvent);
}

static void initSimStructsc19_leader_qball2(SFc19_leader_qball2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  (void)c19_chartNumber;
  (void)c19_instanceNumber;
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  if (!chartInstance->c19_x_bias_not_empty) {
    sf_mex_assign(&c19_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_x_bias, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_x_bias),
    &c19_thisId);
  sf_mex_destroy(&c19_b_x_bias);
  return c19_y;
}

static real_T c19_b_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  if (mxIsEmpty(c19_u)) {
    chartInstance->c19_x_bias_not_empty = false;
  } else {
    chartInstance->c19_x_bias_not_empty = true;
    sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
    c19_y = c19_d0;
  }

  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_x_bias;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_b_x_bias = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_x_bias),
    &c19_thisId);
  sf_mex_destroy(&c19_b_x_bias);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  if (!chartInstance->c19_x_height_not_empty) {
    sf_mex_assign(&c19_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_c_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_x_height, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_x_height),
    &c19_thisId);
  sf_mex_destroy(&c19_b_x_height);
  return c19_y;
}

static real_T c19_d_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d1;
  if (mxIsEmpty(c19_u)) {
    chartInstance->c19_x_height_not_empty = false;
  } else {
    chartInstance->c19_x_height_not_empty = true;
    sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d1, 1, 0, 0U, 0, 0U, 0);
    c19_y = c19_d1;
  }

  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_x_height;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_b_x_height = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_x_height),
    &c19_thisId);
  sf_mex_destroy(&c19_b_x_height);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  if (!chartInstance->c19_P_11_not_empty) {
    sf_mex_assign(&c19_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_e_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_11, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_11),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_11);
  return c19_y;
}

static real_T c19_f_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d2;
  if (mxIsEmpty(c19_u)) {
    chartInstance->c19_P_11_not_empty = false;
  } else {
    chartInstance->c19_P_11_not_empty = true;
    sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d2, 1, 0, 0U, 0, 0U, 0);
    c19_y = c19_d2;
  }

  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_P_11;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_b_P_11 = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_11),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_11);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  if (!chartInstance->c19_P_10_not_empty) {
    sf_mex_assign(&c19_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_g_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_10, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_10),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_10);
  return c19_y;
}

static real_T c19_h_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d3;
  if (mxIsEmpty(c19_u)) {
    chartInstance->c19_P_10_not_empty = false;
  } else {
    chartInstance->c19_P_10_not_empty = true;
    sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d3, 1, 0, 0U, 0, 0U, 0);
    c19_y = c19_d3;
  }

  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_P_10;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_b_P_10 = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_10),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_10);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_e_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  if (!chartInstance->c19_P_01_not_empty) {
    sf_mex_assign(&c19_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_i_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_01, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_01),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_01);
  return c19_y;
}

static real_T c19_j_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d4;
  if (mxIsEmpty(c19_u)) {
    chartInstance->c19_P_01_not_empty = false;
  } else {
    chartInstance->c19_P_01_not_empty = true;
    sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d4, 1, 0, 0U, 0, 0U, 0);
    c19_y = c19_d4;
  }

  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_P_01;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_b_P_01 = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_01),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_01);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_f_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  if (!chartInstance->c19_P_00_not_empty) {
    sf_mex_assign(&c19_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_k_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_P_00, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_00),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_00);
  return c19_y;
}

static real_T c19_l_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d5;
  if (mxIsEmpty(c19_u)) {
    chartInstance->c19_P_00_not_empty = false;
  } else {
    chartInstance->c19_P_00_not_empty = true;
    sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d5, 1, 0, 0U, 0, 0U, 0);
    c19_y = c19_d5;
  }

  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_P_00;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_b_P_00 = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_P_00),
    &c19_thisId);
  sf_mex_destroy(&c19_b_P_00);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_g_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_m_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_height, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_height),
    &c19_thisId);
  sf_mex_destroy(&c19_height);
  return c19_y;
}

static real_T c19_n_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d6;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d6, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d6;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_height;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_height = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_height),
    &c19_thisId);
  sf_mex_destroy(&c19_height);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_leader_qball2_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c19_info_helper(&c19_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c19_nameCaptureInfo);
  return c19_nameCaptureInfo;
}

static void c19_info_helper(const mxArray **c19_info)
{
  const mxArray *c19_rhs0 = NULL;
  const mxArray *c19_lhs0 = NULL;
  const mxArray *c19_rhs1 = NULL;
  const mxArray *c19_lhs1 = NULL;
  const mxArray *c19_rhs2 = NULL;
  const mxArray *c19_lhs2 = NULL;
  const mxArray *c19_rhs3 = NULL;
  const mxArray *c19_lhs3 = NULL;
  const mxArray *c19_rhs4 = NULL;
  const mxArray *c19_lhs4 = NULL;
  const mxArray *c19_rhs5 = NULL;
  const mxArray *c19_lhs5 = NULL;
  const mxArray *c19_rhs6 = NULL;
  const mxArray *c19_lhs6 = NULL;
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1388481696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c19_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c19_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c19_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c19_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c19_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c19_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c19_info, c19_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c19_info, c19_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c19_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c19_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c19_info, sf_mex_duplicatearraysafe(&c19_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c19_rhs0);
  sf_mex_destroy(&c19_lhs0);
  sf_mex_destroy(&c19_rhs1);
  sf_mex_destroy(&c19_lhs1);
  sf_mex_destroy(&c19_rhs2);
  sf_mex_destroy(&c19_lhs2);
  sf_mex_destroy(&c19_rhs3);
  sf_mex_destroy(&c19_lhs3);
  sf_mex_destroy(&c19_rhs4);
  sf_mex_destroy(&c19_lhs4);
  sf_mex_destroy(&c19_rhs5);
  sf_mex_destroy(&c19_lhs5);
  sf_mex_destroy(&c19_rhs6);
  sf_mex_destroy(&c19_lhs6);
}

static const mxArray *c19_emlrt_marshallOut(const char * c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c19_u)), false);
  return c19_y;
}

static const mxArray *c19_b_emlrt_marshallOut(const uint32_T c19_u)
{
  const mxArray *c19_y = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 7, 0U, 0U, 0U, 0), false);
  return c19_y;
}

static const mxArray *c19_h_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_o_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i0, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_leader_qball2InstanceStruct *chartInstance;
  chartInstance = (SFc19_leader_qball2InstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_p_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_leader_qball2, const char_T
  *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_leader_qball2), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_leader_qball2);
  return c19_y;
}

static uint8_T c19_q_emlrt_marshallIn(SFc19_leader_qball2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info(SFc19_leader_qball2InstanceStruct
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

void sf_c19_leader_qball2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3933155389U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3809742249U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3965668871U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2822570386U);
}

mxArray *sf_c19_leader_qball2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("puHtRh2QoMu2dXE533lHr");
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

mxArray *sf_c19_leader_qball2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_leader_qball2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c19_leader_qball2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[4],T\"height\",},{M[4],M[0],T\"P_00\",S'l','i','p'{{M1x2[181 185],M[0],}}},{M[4],M[0],T\"P_01\",S'l','i','p'{{M1x2[202 206],M[0],}}},{M[4],M[0],T\"P_10\",S'l','i','p'{{M1x2[223 227],M[0],}}},{M[4],M[0],T\"P_11\",S'l','i','p'{{M1x2[244 248],M[0],}}},{M[4],M[0],T\"x_bias\",S'l','i','p'{{M1x2[290 296],M[0],}}},{M[4],M[0],T\"x_height\",S'l','i','p'{{M1x2[265 273],M[0],}}},{M[8],M[0],T\"is_active_c19_leader_qball2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_leader_qball2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_leader_qball2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc19_leader_qball2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _leader_qball2MachineNumber_,
           19,
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
        init_script_number_translation(_leader_qball2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_leader_qball2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _leader_qball2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"height");
          _SFD_SET_DATA_PROPS(1,1,1,0,"optitrack");
          _SFD_SET_DATA_PROPS(2,1,1,0,"sonar_d");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1271);
        _SFD_CV_INIT_EML_IF(0,1,0,311,327,-1,353);
        _SFD_CV_INIT_EML_IF(0,1,1,363,379,-1,405);
        _SFD_CV_INIT_EML_IF(0,1,2,410,426,-1,452);
        _SFD_CV_INIT_EML_IF(0,1,3,457,473,-1,499);
        _SFD_CV_INIT_EML_IF(0,1,4,505,523,-1,552);
        _SFD_CV_INIT_EML_IF(0,1,5,558,578,-1,609);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_g_sf_marshallOut,(MexInFcnForType)
          c19_g_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c19_height;
          real_T *c19_optitrack;
          real_T *c19_sonar_d;
          real_T *c19_dt;
          c19_dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c19_sonar_d = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c19_optitrack = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c19_height = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_height);
          _SFD_SET_DATA_VALUE_PTR(1U, c19_optitrack);
          _SFD_SET_DATA_VALUE_PTR(2U, c19_sonar_d);
          _SFD_SET_DATA_VALUE_PTR(3U, c19_dt);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _leader_qball2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "6J37iI47RwXGSZyaWLiFUH";
}

static void sf_opaque_initialize_c19_leader_qball2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_leader_qball2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
    chartInstanceVar);
  initialize_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c19_leader_qball2(void *chartInstanceVar)
{
  enable_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_leader_qball2(void *chartInstanceVar)
{
  disable_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c19_leader_qball2(void *chartInstanceVar)
{
  sf_gateway_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_leader_qball2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_leader_qball2
    ((SFc19_leader_qball2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_leader_qball2();/* state var info */
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

extern void sf_internal_set_sim_state_c19_leader_qball2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c19_leader_qball2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_leader_qball2(SimStruct* S)
{
  return sf_internal_get_sim_state_c19_leader_qball2(S);
}

static void sf_opaque_set_sim_state_c19_leader_qball2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c19_leader_qball2(S, st);
}

static void sf_opaque_terminate_c19_leader_qball2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_leader_qball2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_leader_qball2_optimization_info();
    }

    finalize_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
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
  initSimStructsc19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_leader_qball2(SimStruct *S)
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
    initialize_params_c19_leader_qball2((SFc19_leader_qball2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_leader_qball2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_leader_qball2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(787446411U));
  ssSetChecksum1(S,(2336908231U));
  ssSetChecksum2(S,(1488694732U));
  ssSetChecksum3(S,(2660166256U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_leader_qball2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_leader_qball2(SimStruct *S)
{
  SFc19_leader_qball2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc19_leader_qball2InstanceStruct *)utMalloc(sizeof
    (SFc19_leader_qball2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_leader_qball2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_leader_qball2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_leader_qball2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_leader_qball2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_leader_qball2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c19_leader_qball2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_leader_qball2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_leader_qball2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_leader_qball2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_leader_qball2;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_leader_qball2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c19_leader_qball2;
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

void c19_leader_qball2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_leader_qball2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_leader_qball2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_leader_qball2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_leader_qball2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
