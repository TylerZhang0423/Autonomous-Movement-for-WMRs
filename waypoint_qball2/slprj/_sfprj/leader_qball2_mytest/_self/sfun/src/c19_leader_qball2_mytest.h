#ifndef __c19_leader_qball2_mytest_h__
#define __c19_leader_qball2_mytest_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_leader_qball2_mytestInstanceStruct
#define typedef_SFc19_leader_qball2_mytestInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_leader_qball2_mytest;
  real_T c19_P_00;
  boolean_T c19_P_00_not_empty;
  real_T c19_P_01;
  boolean_T c19_P_01_not_empty;
  real_T c19_P_10;
  boolean_T c19_P_10_not_empty;
  real_T c19_P_11;
  boolean_T c19_P_11_not_empty;
  real_T c19_x_height;
  boolean_T c19_x_height_not_empty;
  real_T c19_x_bias;
  boolean_T c19_x_bias_not_empty;
} SFc19_leader_qball2_mytestInstanceStruct;

#endif                                 /*typedef_SFc19_leader_qball2_mytestInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c19_leader_qball2_mytest_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
extern void c19_leader_qball2_mytest_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
