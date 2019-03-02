/* Include files */

#include "tracking_sfun.h"
#include "tracking_sfun_debug_macros.h"
#include "c1_tracking.h"
#include "c3_tracking.h"
#include "c4_tracking.h"
#include "c7_tracking.h"
#include "c9_tracking.h"
#include "c14_tracking.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _trackingMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void tracking_initializer(void)
{
}

void tracking_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_tracking_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_tracking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_tracking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_tracking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_tracking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_tracking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_tracking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_tracking_process_testpoint_info_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "tracking")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_tracking_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4148407593U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1252910200U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2688205383U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2674023211U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(50674125U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3813134317U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3107855424U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2706751478U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_tracking_get_check_sum(mxArray *plhs[]);
          sf_c1_tracking_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_tracking_get_check_sum(mxArray *plhs[]);
          sf_c3_tracking_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_tracking_get_check_sum(mxArray *plhs[]);
          sf_c4_tracking_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_tracking_get_check_sum(mxArray *plhs[]);
          sf_c7_tracking_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_tracking_get_check_sum(mxArray *plhs[]);
          sf_c9_tracking_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_tracking_get_check_sum(mxArray *plhs[]);
          sf_c14_tracking_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3084158392U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2524169757U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2812955680U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(245732821U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(607313355U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2592320449U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(485053980U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1579114780U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_tracking_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "RmSTlJywITl4Y1mVi18ExE") == 0) {
          extern mxArray *sf_c1_tracking_get_autoinheritance_info(void);
          plhs[0] = sf_c1_tracking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "tpn6PPKCnEQjaXSgG6rC9E") == 0) {
          extern mxArray *sf_c3_tracking_get_autoinheritance_info(void);
          plhs[0] = sf_c3_tracking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "XsiZrq27mnRYEEzwoQ0GxF") == 0) {
          extern mxArray *sf_c4_tracking_get_autoinheritance_info(void);
          plhs[0] = sf_c4_tracking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "nSPSMaDVqoy5PWE1RZuer") == 0) {
          extern mxArray *sf_c7_tracking_get_autoinheritance_info(void);
          plhs[0] = sf_c7_tracking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "JNg9YNFjFlfJ5zTroDYjtE") == 0) {
          extern mxArray *sf_c9_tracking_get_autoinheritance_info(void);
          plhs[0] = sf_c9_tracking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "YWpEpFaxsmFMPkmEcWVcWD") == 0) {
          extern mxArray *sf_c14_tracking_get_autoinheritance_info(void);
          plhs[0] = sf_c14_tracking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_tracking_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_tracking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_tracking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_tracking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_tracking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_tracking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_tracking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_tracking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_tracking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_tracking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_tracking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_tracking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_tracking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_tracking_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "HH5duMUSKWF4EGoqyNcHpE") == 0) {
          extern mxArray *sf_c1_tracking_third_party_uses_info(void);
          plhs[0] = sf_c1_tracking_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "F80rWjy0Jn8XRMjpQzyPB") == 0) {
          extern mxArray *sf_c3_tracking_third_party_uses_info(void);
          plhs[0] = sf_c3_tracking_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7K9AuYSdbNKzgzKejBUaVE") == 0) {
          extern mxArray *sf_c4_tracking_third_party_uses_info(void);
          plhs[0] = sf_c4_tracking_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "X5zyGXwPG4lgQwZceVqRIC") == 0) {
          extern mxArray *sf_c7_tracking_third_party_uses_info(void);
          plhs[0] = sf_c7_tracking_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "PxAr8ZRrkUU0v8xUXBUCMH") == 0) {
          extern mxArray *sf_c9_tracking_third_party_uses_info(void);
          plhs[0] = sf_c9_tracking_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "MJA58JoFESrmfafDnty2hG") == 0) {
          extern mxArray *sf_c14_tracking_third_party_uses_info(void);
          plhs[0] = sf_c14_tracking_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_tracking_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "HH5duMUSKWF4EGoqyNcHpE") == 0) {
          extern mxArray *sf_c1_tracking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_tracking_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "F80rWjy0Jn8XRMjpQzyPB") == 0) {
          extern mxArray *sf_c3_tracking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_tracking_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "7K9AuYSdbNKzgzKejBUaVE") == 0) {
          extern mxArray *sf_c4_tracking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_tracking_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "X5zyGXwPG4lgQwZceVqRIC") == 0) {
          extern mxArray *sf_c7_tracking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_tracking_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "PxAr8ZRrkUU0v8xUXBUCMH") == 0) {
          extern mxArray *sf_c9_tracking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_tracking_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "MJA58JoFESrmfafDnty2hG") == 0) {
          extern mxArray *sf_c14_tracking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_tracking_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void tracking_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _trackingMachineNumber_ = sf_debug_initialize_machine(debugInstance,"tracking",
    "sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_trackingMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_trackingMachineNumber_,0);
}

void tracking_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_tracking_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("tracking",
      "tracking");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_tracking_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
