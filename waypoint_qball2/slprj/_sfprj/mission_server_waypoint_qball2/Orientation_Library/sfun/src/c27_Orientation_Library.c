/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Orientation_Library_sfun.h"
#include "c27_Orientation_Library.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Orientation_Library_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c27_debug_family_names[12] = { "tol", "pitch", "roll", "yaw",
  "RollYaw", "nargin", "nargout", "R", "auxAngle", "auxSelect", "Angles",
  "isSingular" };

/* Function Declarations */
static void initialize_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void initialize_params_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void enable_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void disable_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void c27_update_debugger_state_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void set_sim_state_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance, const mxArray *c27_st);
static void finalize_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void sf_gateway_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void initSimStructsc27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static real_T c27_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_isSingular, const char_T *c27_identifier);
static real_T c27_b_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_c_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_Angles, const char_T *c27_identifier,
  real_T c27_y[3]);
static void c27_d_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[3]);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_info_helper(const mxArray **c27_info);
static const mxArray *c27_emlrt_marshallOut(const char * c27_u);
static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u);
static void c27_eml_error(SFc27_Orientation_LibraryInstanceStruct *chartInstance);
static real_T c27_atan2(SFc27_Orientation_LibraryInstanceStruct *chartInstance,
  real_T c27_y, real_T c27_x);
static void c27_b_eml_error(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_e_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_f_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Orientation_Library, const
  char_T *c27_identifier);
static uint8_T c27_g_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c27_is_active_c27_Orientation_Library = 0U;
}

static void initialize_params_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c27_update_debugger_state_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  int32_T c27_i0;
  real_T c27_u[3];
  const mxArray *c27_b_y = NULL;
  real_T c27_hoistedGlobal;
  real_T c27_b_u;
  const mxArray *c27_c_y = NULL;
  uint8_T c27_b_hoistedGlobal;
  uint8_T c27_c_u;
  const mxArray *c27_d_y = NULL;
  real_T *c27_isSingular;
  real_T (*c27_Angles)[3];
  c27_isSingular = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c27_Angles = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellmatrix(3, 1), false);
  for (c27_i0 = 0; c27_i0 < 3; c27_i0++) {
    c27_u[c27_i0] = (*c27_Angles)[c27_i0];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_hoistedGlobal = *c27_isSingular;
  c27_b_u = c27_hoistedGlobal;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 1, c27_c_y);
  c27_b_hoistedGlobal = chartInstance->c27_is_active_c27_Orientation_Library;
  c27_c_u = c27_b_hoistedGlobal;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c27_y, 2, c27_d_y);
  sf_mex_assign(&c27_st, c27_y, false);
  return c27_st;
}

static void set_sim_state_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance, const mxArray *c27_st)
{
  const mxArray *c27_u;
  real_T c27_dv0[3];
  int32_T c27_i1;
  real_T *c27_isSingular;
  real_T (*c27_Angles)[3];
  c27_isSingular = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c27_Angles = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c27_doneDoubleBufferReInit = true;
  c27_u = sf_mex_dup(c27_st);
  c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 0)),
    "Angles", c27_dv0);
  for (c27_i1 = 0; c27_i1 < 3; c27_i1++) {
    (*c27_Angles)[c27_i1] = c27_dv0[c27_i1];
  }

  *c27_isSingular = c27_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c27_u, 1)), "isSingular");
  chartInstance->c27_is_active_c27_Orientation_Library = c27_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 2)),
     "is_active_c27_Orientation_Library");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_Orientation_Library(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  int32_T c27_i2;
  real_T c27_hoistedGlobal;
  real_T c27_b_hoistedGlobal;
  int32_T c27_i3;
  real_T c27_R[9];
  real_T c27_auxAngle;
  real_T c27_auxSelect;
  uint32_T c27_debug_family_var_map[12];
  real_T c27_tol;
  real_T c27_pitch;
  real_T c27_roll;
  real_T c27_yaw;
  real_T c27_RollYaw;
  real_T c27_nargin = 3.0;
  real_T c27_nargout = 2.0;
  real_T c27_Angles[3];
  real_T c27_isSingular;
  real_T c27_x;
  real_T c27_b_x;
  real_T c27_c_x;
  real_T c27_d_x;
  real_T c27_y;
  real_T c27_e_x;
  real_T c27_f_x;
  real_T c27_b_roll[3];
  int32_T c27_i4;
  int32_T c27_i5;
  int32_T c27_i6;
  real_T *c27_b_isSingular;
  real_T *c27_b_auxAngle;
  real_T *c27_b_auxSelect;
  real_T (*c27_b_Angles)[3];
  real_T (*c27_b_R)[9];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c27_b_auxSelect = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c27_b_auxAngle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c27_b_isSingular = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c27_b_Angles = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c27_sfEvent);
  for (c27_i2 = 0; c27_i2 < 9; c27_i2++) {
    _SFD_DATA_RANGE_CHECK((*c27_b_R)[c27_i2], 0U);
  }

  chartInstance->c27_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c27_sfEvent);
  c27_hoistedGlobal = *c27_b_auxAngle;
  c27_b_hoistedGlobal = *c27_b_auxSelect;
  for (c27_i3 = 0; c27_i3 < 9; c27_i3++) {
    c27_R[c27_i3] = (*c27_b_R)[c27_i3];
  }

  c27_auxAngle = c27_hoistedGlobal;
  c27_auxSelect = c27_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_tol, 0U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_pitch, 1U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_roll, 2U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_yaw, 3U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_RollYaw, 4U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 5U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 6U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c27_R, 7U, c27_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_auxAngle, 8U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_auxSelect, 9U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c27_Angles, 10U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_isSingular, 11U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 14);
  c27_tol = 2.2204460492503131E-16;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 17);
  c27_x = c27_R[2];
  c27_b_x = c27_x;
  guard2 = false;
  if (c27_b_x < -1.0) {
    guard2 = true;
  } else {
    if (1.0 < c27_b_x) {
      guard2 = true;
    }
  }

  if (guard2 == true) {
    c27_eml_error(chartInstance);
  }

  c27_b_x = muDoubleScalarAsin(c27_b_x);
  c27_pitch = -c27_b_x;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 18);
  c27_c_x = c27_R[2];
  c27_d_x = c27_c_x;
  c27_y = muDoubleScalarAbs(c27_d_x);
  if (CV_EML_IF(0, 1, 0, 1.0 - c27_y > c27_tol)) {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 20);
    c27_isSingular = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 21);
    c27_roll = c27_atan2(chartInstance, c27_R[5], c27_R[8]);
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 22);
    c27_yaw = c27_atan2(chartInstance, c27_R[1], c27_R[0]);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 25);
    c27_isSingular = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 29);
    c27_e_x = c27_R[4];
    c27_RollYaw = c27_e_x;
    guard1 = false;
    if (c27_RollYaw < -1.0) {
      guard1 = true;
    } else {
      if (1.0 < c27_RollYaw) {
        guard1 = true;
      }
    }

    if (guard1 == true) {
      c27_b_eml_error(chartInstance);
    }

    c27_f_x = c27_RollYaw;
    c27_RollYaw = c27_f_x;
    c27_RollYaw = muDoubleScalarAcos(c27_RollYaw);
    _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 31);
    if (CV_EML_IF(0, 1, 1, c27_pitch > 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 38);
      if (CV_EML_IF(0, 1, 2, c27_auxSelect != 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 39);
        c27_roll = c27_auxAngle;
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 40);
        c27_yaw = c27_RollYaw - c27_roll;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 42);
        c27_yaw = c27_auxAngle;
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 43);
        c27_roll = c27_RollYaw - c27_yaw;
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 52);
      if (CV_EML_IF(0, 1, 3, c27_auxSelect != 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 53);
        c27_roll = c27_auxAngle;
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 54);
        c27_yaw = -c27_RollYaw + c27_roll;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 56);
        c27_yaw = c27_auxAngle;
        _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 57);
        c27_roll = c27_RollYaw + c27_yaw;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 62);
  c27_b_roll[0] = c27_roll;
  c27_b_roll[1] = c27_pitch;
  c27_b_roll[2] = c27_yaw;
  for (c27_i4 = 0; c27_i4 < 3; c27_i4++) {
    c27_Angles[c27_i4] = c27_b_roll[c27_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -62);
  _SFD_SYMBOL_SCOPE_POP();
  for (c27_i5 = 0; c27_i5 < 3; c27_i5++) {
    (*c27_b_Angles)[c27_i5] = c27_Angles[c27_i5];
  }

  *c27_b_isSingular = c27_isSingular;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c27_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Orientation_LibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c27_i6 = 0; c27_i6 < 3; c27_i6++) {
    _SFD_DATA_RANGE_CHECK((*c27_b_Angles)[c27_i6], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c27_b_isSingular, 2U);
  _SFD_DATA_RANGE_CHECK(*c27_b_auxAngle, 3U);
  _SFD_DATA_RANGE_CHECK(*c27_b_auxSelect, 4U);
}

static void initSimStructsc27_Orientation_Library
  (SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber, uint32_T c27_instanceNumber)
{
  (void)c27_machineNumber;
  (void)c27_chartNumber;
  (void)c27_instanceNumber;
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static real_T c27_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_isSingular, const char_T *c27_identifier)
{
  real_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_isSingular),
    &c27_thisId);
  sf_mex_destroy(&c27_isSingular);
  return c27_y;
}

static real_T c27_b_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d0, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_isSingular;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)chartInstanceVoid;
  c27_isSingular = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_isSingular),
    &c27_thisId);
  sf_mex_destroy(&c27_isSingular);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i7;
  real_T c27_b_inData[3];
  int32_T c27_i8;
  real_T c27_u[3];
  const mxArray *c27_y = NULL;
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i7 = 0; c27_i7 < 3; c27_i7++) {
    c27_b_inData[c27_i7] = (*(real_T (*)[3])c27_inData)[c27_i7];
  }

  for (c27_i8 = 0; c27_i8 < 3; c27_i8++) {
    c27_u[c27_i8] = c27_b_inData[c27_i8];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static void c27_c_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_Angles, const char_T *c27_identifier,
  real_T c27_y[3])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_Angles), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_Angles);
}

static void c27_d_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[3])
{
  real_T c27_dv1[3];
  int32_T c27_i9;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c27_i9 = 0; c27_i9 < 3; c27_i9++) {
    c27_y[c27_i9] = c27_dv1[c27_i9];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_Angles;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[3];
  int32_T c27_i10;
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)chartInstanceVoid;
  c27_Angles = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_Angles), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_Angles);
  for (c27_i10 = 0; c27_i10 < 3; c27_i10++) {
    (*(real_T (*)[3])c27_outData)[c27_i10] = c27_y[c27_i10];
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i11;
  int32_T c27_i12;
  int32_T c27_i13;
  real_T c27_b_inData[9];
  int32_T c27_i14;
  int32_T c27_i15;
  int32_T c27_i16;
  real_T c27_u[9];
  const mxArray *c27_y = NULL;
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i11 = 0;
  for (c27_i12 = 0; c27_i12 < 3; c27_i12++) {
    for (c27_i13 = 0; c27_i13 < 3; c27_i13++) {
      c27_b_inData[c27_i13 + c27_i11] = (*(real_T (*)[9])c27_inData)[c27_i13 +
        c27_i11];
    }

    c27_i11 += 3;
  }

  c27_i14 = 0;
  for (c27_i15 = 0; c27_i15 < 3; c27_i15++) {
    for (c27_i16 = 0; c27_i16 < 3; c27_i16++) {
      c27_u[c27_i16 + c27_i14] = c27_b_inData[c27_i16 + c27_i14];
    }

    c27_i14 += 3;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

const mxArray *sf_c27_Orientation_Library_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  sf_mex_assign(&c27_nameCaptureInfo, sf_mex_createstruct("structure", 2, 18, 1),
                false);
  c27_info_helper(&c27_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c27_nameCaptureInfo);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(const mxArray **c27_info)
{
  const mxArray *c27_rhs0 = NULL;
  const mxArray *c27_lhs0 = NULL;
  const mxArray *c27_rhs1 = NULL;
  const mxArray *c27_lhs1 = NULL;
  const mxArray *c27_rhs2 = NULL;
  const mxArray *c27_lhs2 = NULL;
  const mxArray *c27_rhs3 = NULL;
  const mxArray *c27_lhs3 = NULL;
  const mxArray *c27_rhs4 = NULL;
  const mxArray *c27_lhs4 = NULL;
  const mxArray *c27_rhs5 = NULL;
  const mxArray *c27_lhs5 = NULL;
  const mxArray *c27_rhs6 = NULL;
  const mxArray *c27_lhs6 = NULL;
  const mxArray *c27_rhs7 = NULL;
  const mxArray *c27_lhs7 = NULL;
  const mxArray *c27_rhs8 = NULL;
  const mxArray *c27_lhs8 = NULL;
  const mxArray *c27_rhs9 = NULL;
  const mxArray *c27_lhs9 = NULL;
  const mxArray *c27_rhs10 = NULL;
  const mxArray *c27_lhs10 = NULL;
  const mxArray *c27_rhs11 = NULL;
  const mxArray *c27_lhs11 = NULL;
  const mxArray *c27_rhs12 = NULL;
  const mxArray *c27_lhs12 = NULL;
  const mxArray *c27_rhs13 = NULL;
  const mxArray *c27_lhs13 = NULL;
  const mxArray *c27_rhs14 = NULL;
  const mxArray *c27_lhs14 = NULL;
  const mxArray *c27_rhs15 = NULL;
  const mxArray *c27_lhs15 = NULL;
  const mxArray *c27_rhs16 = NULL;
  const mxArray *c27_lhs16 = NULL;
  const mxArray *c27_rhs17 = NULL;
  const mxArray *c27_lhs17 = NULL;
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eps"), "name", "name", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c27_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_eps"), "name", "name", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c27_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c27_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("asin"), "name", "name", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343851970U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c27_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_error"), "name", "name",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c27_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_asin"), "name",
                  "name", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343851976U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c27_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("abs"), "name", "name", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c27_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1363732556U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c27_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c27_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("atan2"), "name", "name", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343851972U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c27_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c27_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c27_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c27_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1389329520U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c27_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c27_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(""), "context", "context", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("acos"), "name", "name", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343851966U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c27_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_error"), "name", "name",
                  16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c27_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("eml_scalar_acos"), "name",
                  "name", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c27_info, c27_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(1343851976U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c27_info, c27_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c27_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c27_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c27_info, sf_mex_duplicatearraysafe(&c27_lhs17), "lhs", "lhs",
                  17);
  sf_mex_destroy(&c27_rhs0);
  sf_mex_destroy(&c27_lhs0);
  sf_mex_destroy(&c27_rhs1);
  sf_mex_destroy(&c27_lhs1);
  sf_mex_destroy(&c27_rhs2);
  sf_mex_destroy(&c27_lhs2);
  sf_mex_destroy(&c27_rhs3);
  sf_mex_destroy(&c27_lhs3);
  sf_mex_destroy(&c27_rhs4);
  sf_mex_destroy(&c27_lhs4);
  sf_mex_destroy(&c27_rhs5);
  sf_mex_destroy(&c27_lhs5);
  sf_mex_destroy(&c27_rhs6);
  sf_mex_destroy(&c27_lhs6);
  sf_mex_destroy(&c27_rhs7);
  sf_mex_destroy(&c27_lhs7);
  sf_mex_destroy(&c27_rhs8);
  sf_mex_destroy(&c27_lhs8);
  sf_mex_destroy(&c27_rhs9);
  sf_mex_destroy(&c27_lhs9);
  sf_mex_destroy(&c27_rhs10);
  sf_mex_destroy(&c27_lhs10);
  sf_mex_destroy(&c27_rhs11);
  sf_mex_destroy(&c27_lhs11);
  sf_mex_destroy(&c27_rhs12);
  sf_mex_destroy(&c27_lhs12);
  sf_mex_destroy(&c27_rhs13);
  sf_mex_destroy(&c27_lhs13);
  sf_mex_destroy(&c27_rhs14);
  sf_mex_destroy(&c27_lhs14);
  sf_mex_destroy(&c27_rhs15);
  sf_mex_destroy(&c27_lhs15);
  sf_mex_destroy(&c27_rhs16);
  sf_mex_destroy(&c27_lhs16);
  sf_mex_destroy(&c27_rhs17);
  sf_mex_destroy(&c27_lhs17);
}

static const mxArray *c27_emlrt_marshallOut(const char * c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c27_u)), false);
  return c27_y;
}

static const mxArray *c27_b_emlrt_marshallOut(const uint32_T c27_u)
{
  const mxArray *c27_y = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 7, 0U, 0U, 0U, 0), false);
  return c27_y;
}

static void c27_eml_error(SFc27_Orientation_LibraryInstanceStruct *chartInstance)
{
  int32_T c27_i17;
  static char_T c27_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c27_u[30];
  const mxArray *c27_y = NULL;
  int32_T c27_i18;
  static char_T c27_cv1[4] = { 'a', 's', 'i', 'n' };

  char_T c27_b_u[4];
  const mxArray *c27_b_y = NULL;
  (void)chartInstance;
  for (c27_i17 = 0; c27_i17 < 30; c27_i17++) {
    c27_u[c27_i17] = c27_cv0[c27_i17];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c27_i18 = 0; c27_i18 < 4; c27_i18++) {
    c27_b_u[c27_i18] = c27_cv1[c27_i18];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c27_y, 14, c27_b_y));
}

static real_T c27_atan2(SFc27_Orientation_LibraryInstanceStruct *chartInstance,
  real_T c27_y, real_T c27_x)
{
  real_T c27_b_y;
  real_T c27_b_x;
  (void)chartInstance;
  c27_b_y = c27_y;
  c27_b_x = c27_x;
  return muDoubleScalarAtan2(c27_b_y, c27_b_x);
}

static void c27_b_eml_error(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance)
{
  int32_T c27_i19;
  static char_T c27_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c27_u[30];
  const mxArray *c27_y = NULL;
  int32_T c27_i20;
  static char_T c27_cv3[4] = { 'a', 'c', 'o', 's' };

  char_T c27_b_u[4];
  const mxArray *c27_b_y = NULL;
  (void)chartInstance;
  for (c27_i19 = 0; c27_i19 < 30; c27_i19++) {
    c27_u[c27_i19] = c27_cv2[c27_i19];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c27_i20 = 0; c27_i20 < 4; c27_i20++) {
    c27_b_u[c27_i20] = c27_cv3[c27_i20];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c27_y, 14, c27_b_y));
}

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, false);
  return c27_mxArrayOutData;
}

static int32_T c27_e_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i21;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i21, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i21;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_f_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_Orientation_Library, const
  char_T *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_Orientation_Library), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_Orientation_Library);
  return c27_y;
}

static uint8_T c27_g_emlrt_marshallIn(SFc27_Orientation_LibraryInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  (void)chartInstance;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info(SFc27_Orientation_LibraryInstanceStruct
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

void sf_c27_Orientation_Library_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2614708269U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3617316668U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(129785366U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1533655158U);
}

mxArray *sf_c27_Orientation_Library_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nTpW1BBmmZaDS2XYYePZMC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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

mxArray *sf_c27_Orientation_Library_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c27_Orientation_Library_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c27_Orientation_Library(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"Angles\",},{M[1],M[9],T\"isSingular\",},{M[8],M[0],T\"is_active_c27_Orientation_Library\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_Orientation_Library_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_Orientation_LibraryInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Orientation_LibraryMachineNumber_,
           27,
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
        init_script_number_translation(_Orientation_LibraryMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Orientation_LibraryMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Orientation_LibraryMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Angles");
          _SFD_SET_DATA_PROPS(2,2,0,1,"isSingular");
          _SFD_SET_DATA_PROPS(3,1,1,0,"auxAngle");
          _SFD_SET_DATA_PROPS(4,1,1,0,"auxSelect");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1669);
        _SFD_CV_INIT_EML_IF(0,1,0,455,478,597,1636);
        _SFD_CV_INIT_EML_IF(0,1,1,793,806,1216,1632);
        _SFD_CV_INIT_EML_IF(0,1,2,970,988,1098,1211);
        _SFD_CV_INIT_EML_IF(0,1,3,1382,1400,1511,1624);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
            c27_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)c27_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c27_isSingular;
          real_T *c27_auxAngle;
          real_T *c27_auxSelect;
          real_T (*c27_R)[9];
          real_T (*c27_Angles)[3];
          c27_auxSelect = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c27_auxAngle = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c27_isSingular = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c27_Angles = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c27_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c27_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c27_Angles);
          _SFD_SET_DATA_VALUE_PTR(2U, c27_isSingular);
          _SFD_SET_DATA_VALUE_PTR(3U, c27_auxAngle);
          _SFD_SET_DATA_VALUE_PTR(4U, c27_auxSelect);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Orientation_LibraryMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "zelOckGDTako9Mz3UnniCH";
}

static void sf_opaque_initialize_c27_Orientation_Library(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_Orientation_LibraryInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c27_Orientation_Library
    ((SFc27_Orientation_LibraryInstanceStruct*) chartInstanceVar);
  initialize_c27_Orientation_Library((SFc27_Orientation_LibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c27_Orientation_Library(void *chartInstanceVar)
{
  enable_c27_Orientation_Library((SFc27_Orientation_LibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c27_Orientation_Library(void *chartInstanceVar)
{
  disable_c27_Orientation_Library((SFc27_Orientation_LibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c27_Orientation_Library(void *chartInstanceVar)
{
  sf_gateway_c27_Orientation_Library((SFc27_Orientation_LibraryInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c27_Orientation_Library
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c27_Orientation_Library
    ((SFc27_Orientation_LibraryInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_Orientation_Library();/* state var info */
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

extern void sf_internal_set_sim_state_c27_Orientation_Library(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c27_Orientation_Library();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c27_Orientation_Library((SFc27_Orientation_LibraryInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c27_Orientation_Library(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c27_Orientation_Library(S);
}

static void sf_opaque_set_sim_state_c27_Orientation_Library(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c27_Orientation_Library(S, st);
}

static void sf_opaque_terminate_c27_Orientation_Library(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_Orientation_LibraryInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Orientation_Library_optimization_info();
    }

    finalize_c27_Orientation_Library((SFc27_Orientation_LibraryInstanceStruct*)
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
  initSimStructsc27_Orientation_Library((SFc27_Orientation_LibraryInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_Orientation_Library(SimStruct *S)
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
    initialize_params_c27_Orientation_Library
      ((SFc27_Orientation_LibraryInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_Orientation_Library(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Orientation_Library_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,27,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,27);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1784619431U));
  ssSetChecksum1(S,(832487846U));
  ssSetChecksum2(S,(460811541U));
  ssSetChecksum3(S,(2897353213U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c27_Orientation_Library(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_Orientation_Library(SimStruct *S)
{
  SFc27_Orientation_LibraryInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc27_Orientation_LibraryInstanceStruct *)utMalloc(sizeof
    (SFc27_Orientation_LibraryInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_Orientation_LibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_Orientation_Library;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_Orientation_Library;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c27_Orientation_Library;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c27_Orientation_Library;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c27_Orientation_Library;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_Orientation_Library;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_Orientation_Library;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_Orientation_Library;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_Orientation_Library;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_Orientation_Library;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c27_Orientation_Library;
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

void c27_Orientation_Library_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_Orientation_Library(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_Orientation_Library(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_Orientation_Library(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_Orientation_Library_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
