#ifndef __c23_leader_qball2_mytest_h__
#define __c23_leader_qball2_mytest_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_leader_qball2_mytestInstanceStruct
#define typedef_SFc23_leader_qball2_mytestInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  boolean_T c23_isStable;
  boolean_T c23_doneDoubleBufferReInit;
  uint8_T c23_is_active_c23_leader_qball2_mytest;
} SFc23_leader_qball2_mytestInstanceStruct;

#endif                                 /*typedef_SFc23_leader_qball2_mytestInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c23_leader_qball2_mytest_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_leader_qball2_mytest_get_check_sum(mxArray *plhs[]);
extern void c23_leader_qball2_mytest_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
