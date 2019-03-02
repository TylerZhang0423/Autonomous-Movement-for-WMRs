/* Include files */

#include <stddef.h>
#include "blas.h"
#include "leader_qball2_mytest_sfun.h"
#include "c5_leader_qball2_mytest.h"
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
static const char * c5_debug_family_names[10] = { "nargin", "nargout", "cmd",
  "height", "u", "rate", "y", "land", "state", "c" };

/* Function Declarations */
static void initialize_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void initialize_params_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void enable_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void disable_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void set_sim_state_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void sf_gateway_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void initSimStructsc5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_b_c, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_b_state, const char_T *c5_identifier);
static real_T c5_d_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_e_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_land, const char_T *c5_identifier);
static real_T c5_f_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_g_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_h_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_leader_qball2_mytest, const
  char_T *c5_identifier);
static uint8_T c5_i_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_state_not_empty = false;
  chartInstance->c5_c_not_empty = false;
  chartInstance->c5_is_active_c5_leader_qball2_mytest = 0U;
}

static void initialize_params_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  uint8_T c5_e_hoistedGlobal;
  uint8_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  real_T *c5_land;
  real_T *c5_g_y;
  c5_land = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_g_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(5, 1), false);
  c5_hoistedGlobal = *c5_land;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_g_y;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = chartInstance->c5_c;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  if (!chartInstance->c5_c_not_empty) {
    sf_mex_assign(&c5_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = chartInstance->c5_state;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  if (!chartInstance->c5_state_not_empty) {
    sf_mex_assign(&c5_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_e_hoistedGlobal = chartInstance->c5_is_active_c5_leader_qball2_mytest;
  c5_e_u = c5_e_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 4, c5_f_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_land;
  real_T *c5_y;
  c5_land = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *c5_land = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    0)), "land");
  *c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "y");
  chartInstance->c5_c = c5_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 2)), "c");
  chartInstance->c5_state = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 3)), "state");
  chartInstance->c5_is_active_c5_leader_qball2_mytest = c5_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 4)),
     "is_active_c5_leader_qball2_mytest");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_leader_qball2_mytest(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  boolean_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  boolean_T c5_cmd;
  real_T c5_height;
  real_T c5_u;
  real_T c5_rate;
  uint32_T c5_debug_family_var_map[10];
  real_T c5_nargin = 4.0;
  real_T c5_nargout = 2.0;
  real_T c5_y;
  real_T c5_land;
  boolean_T *c5_b_cmd;
  real_T *c5_b_y;
  real_T *c5_b_height;
  real_T *c5_b_u;
  real_T *c5_b_land;
  real_T *c5_b_rate;
  boolean_T guard1 = false;
  c5_b_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_land = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_height = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_cmd = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c5_b_cmd, 0U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_cmd;
  c5_b_hoistedGlobal = *c5_b_height;
  c5_c_hoistedGlobal = *c5_b_u;
  c5_d_hoistedGlobal = *c5_b_rate;
  c5_cmd = c5_hoistedGlobal;
  c5_height = c5_b_hoistedGlobal;
  c5_u = c5_c_hoistedGlobal;
  c5_rate = c5_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_cmd, 2U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_height, 3U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_u, 4U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_rate, 5U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_y, 6U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_land, 7U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c5_state, 8U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c5_c, 9U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c5_state_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
    chartInstance->c5_state = 0.0;
    chartInstance->c5_state_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  if (CV_EML_IF(0, 1, 1, !chartInstance->c5_c_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
    chartInstance->c5_c = 0.0;
    chartInstance->c5_c_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_land = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
  switch ((int32_T)_SFD_INTEGER_CHECK("state", chartInstance->c5_state)) {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
    if (CV_EML_IF(0, 1, 2, (real_T)c5_cmd > 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
      chartInstance->c5_state = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 26);
      chartInstance->c5_c = c5_u;
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 27);
      c5_y = c5_u;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
      c5_land = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 30);
      chartInstance->c5_c -= c5_rate;
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
      if (CV_EML_IF(0, 1, 3, chartInstance->c5_c < 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
        chartInstance->c5_c = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 34);
      c5_y = chartInstance->c5_c;
    }
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 38);
    chartInstance->c5_c = c5_u;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 39);
    c5_y = c5_u;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 40);
    guard1 = false;
    if (CV_EML_COND(0, 1, 0, (real_T)c5_cmd <= 0.0)) {
      if (CV_EML_COND(0, 1, 1, c5_height <= 0.08)) {
        CV_EML_MCDC(0, 1, 0, true);
        CV_EML_IF(0, 1, 4, true);
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 41);
        chartInstance->c5_state = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 42);
        c5_land = 1.0;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 4, false);
    }
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 46);
    c5_y = chartInstance->c5_c;
    break;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -46);
  _SFD_SYMBOL_SCOPE_POP();
  *c5_b_y = c5_y;
  *c5_b_land = c5_land;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_leader_qball2_mytestMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c5_b_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_height, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_u, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_land, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_b_rate, 5U);
}

static void initSimStructsc5_leader_qball2_mytest
  (SFc5_leader_qball2_mytestInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  if (!chartInstance->c5_c_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_b_c, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_c), &c5_thisId);
  sf_mex_destroy(&c5_b_c);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_c_not_empty = false;
  } else {
    chartInstance->c5_c_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
    c5_y = c5_d0;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_c;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_b_c = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_c), &c5_thisId);
  sf_mex_destroy(&c5_b_c);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  if (!chartInstance->c5_state_not_empty) {
    sf_mex_assign(&c5_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_b_state, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_state), &c5_thisId);
  sf_mex_destroy(&c5_b_state);
  return c5_y;
}

static real_T c5_d_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d1;
  if (mxIsEmpty(c5_u)) {
    chartInstance->c5_state_not_empty = false;
  } else {
    chartInstance->c5_state_not_empty = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d1, 1, 0, 0U, 0, 0U, 0);
    c5_y = c5_d1;
  }

  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_state;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_b_state = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_state), &c5_thisId);
  sf_mex_destroy(&c5_b_state);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_e_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_land, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_land), &c5_thisId);
  sf_mex_destroy(&c5_land);
  return c5_y;
}

static real_T c5_f_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d2;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d2, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d2;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_land;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_land = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_land), &c5_thisId);
  sf_mex_destroy(&c5_land);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  boolean_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(boolean_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

const mxArray *sf_c5_leader_qball2_mytest_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_g_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i0, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_leader_qball2_mytest, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_leader_qball2_mytest), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_leader_qball2_mytest);
  return c5_y;
}

static uint8_T c5_i_emlrt_marshallIn(SFc5_leader_qball2_mytestInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_leader_qball2_mytestInstanceStruct
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

void sf_c5_leader_qball2_mytest_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2583788347U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2127819799U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2895655948U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(143366030U);
}

mxArray *sf_c5_leader_qball2_mytest_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vWIhD63Zy6KboFfUbSYbdG");
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_leader_qball2_mytest_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_leader_qball2_mytest_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_leader_qball2_mytest(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[8],T\"land\",},{M[1],M[5],T\"y\",},{M[4],M[0],T\"c\",S'l','i','p'{{M1x2[351 352],M[0],}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[279 284],M[0],}}},{M[8],M[0],T\"is_active_c5_leader_qball2_mytest\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_leader_qball2_mytest_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _leader_qball2_mytestMachineNumber_,
           5,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"cmd");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"height");
          _SFD_SET_DATA_PROPS(3,1,1,0,"u");
          _SFD_SET_DATA_PROPS(4,2,0,1,"land");
          _SFD_SET_DATA_PROPS(5,1,1,0,"rate");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,1,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,876);
        _SFD_CV_INIT_EML_IF(0,1,0,355,372,-1,391);
        _SFD_CV_INIT_EML_IF(0,1,1,392,405,-1,420);
        _SFD_CV_INIT_EML_IF(0,1,2,465,475,545,688);
        _SFD_CV_INIT_EML_IF(0,1,3,610,618,-1,657);
        _SFD_CV_INIT_EML_IF(0,1,4,747,776,-1,833);

        {
          static int caseStart[] = { 847, 450, 702 };

          static int caseExprEnd[] = { 856, 456, 708 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,433,446,875,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 750, 762 };

          static int condEnd[] = { 758, 776 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,750,776,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)c5_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          boolean_T *c5_cmd;
          real_T *c5_y;
          real_T *c5_height;
          real_T *c5_u;
          real_T *c5_land;
          real_T *c5_rate;
          c5_rate = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_land = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_height = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_cmd = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_cmd);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_height);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_u);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_land);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_rate);
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
  return "TMQVHZjitbhhZZ5daln3EB";
}

static void sf_opaque_initialize_c5_leader_qball2_mytest(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_leader_qball2_mytest
    ((SFc5_leader_qball2_mytestInstanceStruct*) chartInstanceVar);
  initialize_c5_leader_qball2_mytest((SFc5_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_leader_qball2_mytest(void *chartInstanceVar)
{
  enable_c5_leader_qball2_mytest((SFc5_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_leader_qball2_mytest(void *chartInstanceVar)
{
  disable_c5_leader_qball2_mytest((SFc5_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_leader_qball2_mytest(void *chartInstanceVar)
{
  sf_gateway_c5_leader_qball2_mytest((SFc5_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_leader_qball2_mytest
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_leader_qball2_mytest
    ((SFc5_leader_qball2_mytestInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_leader_qball2_mytest();/* state var info */
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

extern void sf_internal_set_sim_state_c5_leader_qball2_mytest(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c5_leader_qball2_mytest();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_leader_qball2_mytest((SFc5_leader_qball2_mytestInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_leader_qball2_mytest(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c5_leader_qball2_mytest(S);
}

static void sf_opaque_set_sim_state_c5_leader_qball2_mytest(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_leader_qball2_mytest(S, st);
}

static void sf_opaque_terminate_c5_leader_qball2_mytest(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_leader_qball2_mytestInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_leader_qball2_mytest_optimization_info();
    }

    finalize_c5_leader_qball2_mytest((SFc5_leader_qball2_mytestInstanceStruct*)
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
  initSimStructsc5_leader_qball2_mytest((SFc5_leader_qball2_mytestInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_leader_qball2_mytest(SimStruct *S)
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
    initialize_params_c5_leader_qball2_mytest
      ((SFc5_leader_qball2_mytestInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_leader_qball2_mytest_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3077564097U));
  ssSetChecksum1(S,(2854675431U));
  ssSetChecksum2(S,(4069665080U));
  ssSetChecksum3(S,(3312628109U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_leader_qball2_mytest(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_leader_qball2_mytest(SimStruct *S)
{
  SFc5_leader_qball2_mytestInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_leader_qball2_mytestInstanceStruct *)utMalloc(sizeof
    (SFc5_leader_qball2_mytestInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_leader_qball2_mytestInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_leader_qball2_mytest;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_leader_qball2_mytest;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_leader_qball2_mytest;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_leader_qball2_mytest;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_leader_qball2_mytest;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_leader_qball2_mytest;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_leader_qball2_mytest;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_leader_qball2_mytest;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_leader_qball2_mytest;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_leader_qball2_mytest;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_leader_qball2_mytest;
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

void c5_leader_qball2_mytest_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_leader_qball2_mytest(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_leader_qball2_mytest(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_leader_qball2_mytest_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
