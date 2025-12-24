/*
 * File: Data_acquisition.c
 *
 * Code generated for Simulink model 'Data_acquisition'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Dec 17 02:06:53 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Data_acquisition.h"
#include "rtwtypes.h"
#include <math.h>
#include "Data_acquisition_private.h"
#include "Data_acquisition_types.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Data_acquisition_T Data_acquisition_B;

/* Block states (default storage) */
DW_Data_acquisition_T Data_acquisition_DW;

/* Real-time model */
static RT_MODEL_Data_acquisition_T Data_acquisition_M_;
RT_MODEL_Data_acquisition_T *const Data_acquisition_M = &Data_acquisition_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Data_acquisition_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  int32_T rtb_MATLABSystem_0;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/MATLAB System' */
  if (Data_acquisition_DW.obj_p.SampleTime !=
      Data_acquisition_P.MATLABSystem_SampleTime) {
    Data_acquisition_DW.obj_p.SampleTime =
      Data_acquisition_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  /*  Call: int enc_output(int enc) */
  rtb_MATLABSystem_0 = enc_output(1.0);

  /* Abs: '<Root>/Abs' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  if (rtb_MATLABSystem_0 < 0L) {
    rtb_MATLABSystem_0 = -rtb_MATLABSystem_0;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Abs: '<Root>/Abs'
   *  DataTypeConversion: '<Root>/Cast To Double'
   *  Gain: '<Root>/Gain'
   */
  Data_acquisition_B.Gain1 = Data_acquisition_P.Gain_Gain * (real_T)
    rtb_MATLABSystem_0 * Data_acquisition_P.Gain1_Gain;

  /* Stop: '<Root>/Stop Simulation2' incorporates:
   *  Constant: '<Root>/Constant7'
   *  RelationalOperator: '<Root>/GreaterThan'
   */
  if (Data_acquisition_B.Gain1 > Data_acquisition_P.Constant7_Value) {
    rtmSetStopRequested(Data_acquisition_M, 1);
  }

  /* End of Stop: '<Root>/Stop Simulation2' */
  /* MATLABSystem: '<Root>/MATLAB System1' */
  if (Data_acquisition_DW.obj.SampleTime !=
      Data_acquisition_P.MATLABSystem1_SampleTime) {
    Data_acquisition_DW.obj.SampleTime =
      Data_acquisition_P.MATLABSystem1_SampleTime;
  }

  /*         %% Define output properties */
  /*  Call: int enc_output(int enc) */
  rtb_MATLABSystem_0 = enc_output(0.0);

  /* Abs: '<Root>/Abs1' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System1'
   */
  if (rtb_MATLABSystem_0 < 0L) {
    rtb_MATLABSystem_0 = -rtb_MATLABSystem_0;
  }

  /* Gain: '<Root>/Gain3' incorporates:
   *  Abs: '<Root>/Abs1'
   *  DataTypeConversion: '<Root>/Cast To Double1'
   *  Gain: '<Root>/Gain2'
   */
  Data_acquisition_B.Gain3 = Data_acquisition_P.Gain2_Gain * (real_T)
    rtb_MATLABSystem_0 * Data_acquisition_P.Gain3_Gain;

  /* MATLABSystem: '<Root>/PWM' */
  obj = &Data_acquisition_DW.obj_n;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Step: '<Root>/Step' */
  if (Data_acquisition_M->Timing.t[0] < Data_acquisition_P.Step_Time) {
    u0 = Data_acquisition_P.Step_Y0;
  } else {
    u0 = Data_acquisition_P.Step_YFinal;
  }

  /* Abs: '<Root>/Abs2' incorporates:
   *  Step: '<Root>/Step'
   */
  u0 = fabs(u0);

  /* MATLABSystem: '<Root>/PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  MW_PWM_SetDutyCycle(Data_acquisition_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (Data_acquisition_P.ManualSwitch_CurrentSetting == 1) {
    u0 = Data_acquisition_P.Constant_Value;
  } else {
    u0 = Data_acquisition_P.Constant1_Value;
  }

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch'
   */
  u0 = rt_roundd_snf(u0);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  if (Data_acquisition_P.ManualSwitch1_CurrentSetting == 1) {
    u0 = Data_acquisition_P.Constant2_Value;
  } else {
    u0 = Data_acquisition_P.Constant3_Value;
  }

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch1'
   */
  u0 = rt_roundd_snf(u0);
  if (u0 < 256.0) {
    if (u0 >= 0.0) {
      tmp = (uint8_T)u0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Data_acquisition_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Data_acquisition_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Data_acquisition_M->Timing.t[0] =
    ((time_T)(++Data_acquisition_M->Timing.clockTick0)) *
    Data_acquisition_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Data_acquisition_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Data_acquisition_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Data_acquisition_M->solverInfo,
                          &Data_acquisition_M->Timing.simTimeStep);
    rtsiSetTPtr(&Data_acquisition_M->solverInfo, &rtmGetTPtr(Data_acquisition_M));
    rtsiSetStepSizePtr(&Data_acquisition_M->solverInfo,
                       &Data_acquisition_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Data_acquisition_M->solverInfo, (&rtmGetErrorStatus
      (Data_acquisition_M)));
    rtsiSetRTModelPtr(&Data_acquisition_M->solverInfo, Data_acquisition_M);
  }

  rtsiSetSimTimeStep(&Data_acquisition_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Data_acquisition_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Data_acquisition_M, &Data_acquisition_M->Timing.tArray[0]);
  rtmSetTFinal(Data_acquisition_M, -1);
  Data_acquisition_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Data_acquisition_M->Sizes.checksums[0] = (2712894620U);
  Data_acquisition_M->Sizes.checksums[1] = (1433697115U);
  Data_acquisition_M->Sizes.checksums[2] = (2072478909U);
  Data_acquisition_M->Sizes.checksums[3] = (312442941U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    Data_acquisition_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Data_acquisition_M->extModeInfo,
      &Data_acquisition_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Data_acquisition_M->extModeInfo,
                        Data_acquisition_M->Sizes.checksums);
    rteiSetTPtr(Data_acquisition_M->extModeInfo, rtmGetTPtr(Data_acquisition_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    Data_acquisition_DW.obj_p.matlabCodegenIsDeleted = false;

    /*  Do not generate code for sprintf */
    Data_acquisition_DW.obj_p.SampleTime =
      Data_acquisition_P.MATLABSystem_SampleTime;
    Data_acquisition_DW.obj_p.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(1.0, 3.0, 5.0);
    Data_acquisition_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/MATLAB System1' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    Data_acquisition_DW.obj.matlabCodegenIsDeleted = false;

    /*  Do not generate code for sprintf */
    Data_acquisition_DW.obj.SampleTime =
      Data_acquisition_P.MATLABSystem1_SampleTime;
    Data_acquisition_DW.obj.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(0.0, 2.0, 4.0);
    Data_acquisition_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    Data_acquisition_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &Data_acquisition_DW.obj_n;
    Data_acquisition_DW.obj_n.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    Data_acquisition_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    Data_acquisition_DW.obj_m.matlabCodegenIsDeleted = false;
    Data_acquisition_DW.obj_m.isInitialized = 1L;
    digitalIOSetup(8, 1);
    Data_acquisition_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    Data_acquisition_DW.obj_j.matlabCodegenIsDeleted = false;
    Data_acquisition_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(7, 1);
    Data_acquisition_DW.obj_j.isSetupComplete = true;
  }
}

/* Model terminate function */
void Data_acquisition_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!Data_acquisition_DW.obj_p.matlabCodegenIsDeleted) {
    Data_acquisition_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */
  /* Terminate for MATLABSystem: '<Root>/MATLAB System1' */
  if (!Data_acquisition_DW.obj.matlabCodegenIsDeleted) {
    Data_acquisition_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System1' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &Data_acquisition_DW.obj_n;
  if (!Data_acquisition_DW.obj_n.matlabCodegenIsDeleted) {
    Data_acquisition_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Data_acquisition_DW.obj_n.isInitialized == 1L) &&
        Data_acquisition_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(Data_acquisition_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Data_acquisition_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!Data_acquisition_DW.obj_m.matlabCodegenIsDeleted) {
    Data_acquisition_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Data_acquisition_DW.obj_j.matlabCodegenIsDeleted) {
    Data_acquisition_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
