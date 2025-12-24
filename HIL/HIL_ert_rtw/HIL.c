/*
 * File: HIL.c
 *
 * Code generated for Simulink model 'HIL'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Dec 23 11:31:25 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HIL.h"
#include "rtwtypes.h"
#include "HIL_private.h"
#include <math.h>
#include "HIL_types.h"
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_HIL_T HIL_B;

/* Block states (default storage) */
DW_HIL_T HIL_DW;

/* Real-time model */
static RT_MODEL_HIL_T HIL_M_;
RT_MODEL_HIL_T *const HIL_M = &HIL_M_;
real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

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
void HIL_step(void)
{
  {
    codertarget_arduinobase_inter_T *obj;
    real_T Joint2angle;
    real_T Switch;
    real_T rtb_Bias5;
    real_T rtb_Switch;
    real_T *lastU;
    int32_T rtb_MATLABSystem_0;
    int16_T tmp;
    uint8_T tmp_0;

    /* MATLABSystem: '<S10>/MATLAB System' */
    if (HIL_DW.obj_l.SampleTime != HIL_P.MATLABSystem_SampleTime) {
      HIL_DW.obj_l.SampleTime = HIL_P.MATLABSystem_SampleTime;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_MATLABSystem_0 = enc_output(1.0);

    /* Gain: '<S10>/Gain1' incorporates:
     *  DataTypeConversion: '<S10>/Cast To Double'
     *  Gain: '<S10>/Gain'
     *  MATLABSystem: '<S10>/MATLAB System'
     */
    HIL_B.Gain1 = HIL_P.Gain_Gain * (real_T)rtb_MATLABSystem_0 *
      HIL_P.Gain1_Gain_m;

    /* Gain: '<S11>/Gain1' incorporates:
     *  Gain: '<S10>/Gain2'
     */
    HIL_B.Gain1_a = HIL_P.Gain2_Gain * HIL_B.Gain1 * HIL_P.Gain1_Gain_l;

    /* Derivative: '<S10>/Derivative' incorporates:
     *  Derivative: '<S5>/Derivative'
     */
    rtb_Switch = HIL_M->Timing.t[0];
    if ((HIL_DW.TimeStampA >= rtb_Switch) && (HIL_DW.TimeStampB >= rtb_Switch))
    {
      /* Derivative: '<S10>/Derivative' */
      HIL_B.Derivative = 0.0;
    } else {
      Switch = HIL_DW.TimeStampA;
      lastU = &HIL_DW.LastUAtTimeA;
      if (HIL_DW.TimeStampA < HIL_DW.TimeStampB) {
        if (HIL_DW.TimeStampB < rtb_Switch) {
          Switch = HIL_DW.TimeStampB;
          lastU = &HIL_DW.LastUAtTimeB;
        }
      } else if (HIL_DW.TimeStampA >= rtb_Switch) {
        Switch = HIL_DW.TimeStampB;
        lastU = &HIL_DW.LastUAtTimeB;
      }

      /* Derivative: '<S10>/Derivative' */
      HIL_B.Derivative = (HIL_B.Gain1_a - *lastU) / (rtb_Switch - Switch);
    }

    /* End of Derivative: '<S10>/Derivative' */

    /* MATLABSystem: '<S5>/MATLAB System1' */
    if (HIL_DW.obj.SampleTime != HIL_P.MATLABSystem1_SampleTime) {
      HIL_DW.obj.SampleTime = HIL_P.MATLABSystem1_SampleTime;
    }

    /*         %% Define output properties */
    /*  Call: int enc_output(int enc) */
    rtb_MATLABSystem_0 = enc_output(0.0);

    /* Gain: '<S13>/Gain1' incorporates:
     *  DataTypeConversion: '<S5>/Cast To Double1'
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain2'
     *  Gain: '<S5>/Gain3'
     *  MATLABSystem: '<S5>/MATLAB System1'
     */
    HIL_B.Gain1_f = HIL_P.Gain2_Gain_p * (real_T)rtb_MATLABSystem_0 *
      HIL_P.Gain3_Gain * HIL_P.Gain_Gain_d * HIL_P.Gain1_Gain_mf;

    /* Derivative: '<S5>/Derivative' */
    if ((HIL_DW.TimeStampA_j >= rtb_Switch) && (HIL_DW.TimeStampB_a >=
         rtb_Switch)) {
      /* Derivative: '<S5>/Derivative' */
      HIL_B.Derivative_f = 0.0;
    } else {
      Switch = HIL_DW.TimeStampA_j;
      lastU = &HIL_DW.LastUAtTimeA_m;
      if (HIL_DW.TimeStampA_j < HIL_DW.TimeStampB_a) {
        if (HIL_DW.TimeStampB_a < rtb_Switch) {
          Switch = HIL_DW.TimeStampB_a;
          lastU = &HIL_DW.LastUAtTimeB_p;
        }
      } else if (HIL_DW.TimeStampA_j >= rtb_Switch) {
        Switch = HIL_DW.TimeStampB_a;
        lastU = &HIL_DW.LastUAtTimeB_p;
      }

      /* Derivative: '<S5>/Derivative' */
      HIL_B.Derivative_f = (HIL_B.Gain1_f - *lastU) / (rtb_Switch - Switch);
    }

    /* Switch: '<S2>/Switch' */
    if (HIL_B.Gain1_a > HIL_P.Switch_Threshold) {
      /* Switch: '<S2>/Switch' incorporates:
       *  Bias: '<S2>/Bias1'
       *  Bias: '<S2>/Bias2'
       *  Constant: '<S2>/Constant'
       *  Math: '<S2>/Rem'
       */
      Switch = rt_remd_snf(HIL_B.Gain1_a + HIL_P.Bias1_Bias,
                           HIL_P.Constant_Value) + HIL_P.Bias2_Bias;
    } else {
      /* Switch: '<S2>/Switch' incorporates:
       *  Bias: '<S2>/Bias3'
       *  Bias: '<S2>/Bias4'
       *  Constant: '<S2>/Constant1'
       *  Math: '<S2>/Rem1'
       */
      Switch = rt_remd_snf(HIL_B.Gain1_a + HIL_P.Bias3_Bias,
                           HIL_P.Constant1_Value) + HIL_P.Bias4_Bias;
    }

    /* End of Switch: '<S2>/Switch' */

    /* Bias: '<S3>/Bias5' */
    rtb_Bias5 = HIL_B.Gain1_f + HIL_P.Bias5_Bias;

    /* Switch: '<S3>/Switch' */
    if (rtb_Bias5 > HIL_P.Switch_Threshold_p) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Bias: '<S3>/Bias1'
       *  Bias: '<S3>/Bias2'
       *  Constant: '<S3>/Constant'
       *  Math: '<S3>/Rem'
       */
      rtb_Bias5 = rt_remd_snf(rtb_Bias5 + HIL_P.Bias1_Bias_b,
        HIL_P.Constant_Value_g) + HIL_P.Bias2_Bias_f;
    } else {
      /* Switch: '<S3>/Switch' incorporates:
       *  Bias: '<S3>/Bias3'
       *  Bias: '<S3>/Bias4'
       *  Constant: '<S3>/Constant1'
       *  Math: '<S3>/Rem1'
       */
      rtb_Bias5 = rt_remd_snf(rtb_Bias5 + HIL_P.Bias3_Bias_p,
        HIL_P.Constant1_Value_k) + HIL_P.Bias4_Bias_k;
    }

    /* End of Switch: '<S3>/Switch' */

    /* MATLAB Function: '<S8>/MATLAB Function2' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Gain: '<S15>/Slider Gain'
     */
    Joint2angle = rtb_Bias5;
    if (rtb_Bias5 > 6.2831853071795862) {
      Joint2angle = rtb_Bias5 - 6.2831853071795862;
    } else if (rtb_Bias5 < 0.0) {
      Joint2angle = rtb_Bias5 + 6.2831853071795862;
    }

    rtb_Switch = cos(Joint2angle);
    if (HIL_B.Derivative_f * rtb_Switch >= 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    HIL_B.u = (0.0 - (HIL_B.Derivative_f * HIL_B.Derivative_f *
                      6.6089425242880327E-6 + (rtb_Switch - 1.0) *
                      0.0027021935849999177)) * (HIL_P.SliderGain_gain *
      HIL_P.Constant1_Value_a) * (real_T)tmp;
    if ((Joint2angle <= 0.28559933214452665) && (Joint2angle >=
         -0.28559933214452665)) {
      HIL_B.u = 0.0;
    }

    /* End of MATLAB Function: '<S8>/MATLAB Function2' */

    /* Switch: '<S1>/Switch' incorporates:
     *  Abs: '<S1>/Abs'
     */
    if (fabs(rtb_Bias5) > HIL_P.Switch_Threshold_j) {
      /* Switch: '<S1>/Switch' incorporates:
       *  Gain: '<S8>/Gain1'
       */
      HIL_B.motorcontrol = HIL_P.Gain1_Gain * HIL_B.u;
    } else {
      /* Switch: '<S1>/Switch' incorporates:
       *  Gain: '<S1>/Gain'
       *  SignalConversion generated from: '<S1>/Gain'
       */
      HIL_B.motorcontrol = ((-HIL_P.k[0] * rtb_Bias5 + -HIL_P.k[1] *
        HIL_B.Derivative_f) + -HIL_P.k[2] * Switch) + -HIL_P.k[3] *
        HIL_B.Derivative;
    }

    /* End of Switch: '<S1>/Switch' */
    /* Gain: '<S1>/Gain1' */
    HIL_B.MotorPwm = HIL_P.Gain1_Gain_n * HIL_B.motorcontrol;

    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     */
    if (HIL_B.MotorPwm > HIL_P.Switch_Threshold_k) {
      rtb_Switch = HIL_P.Constant_Value_k;
    } else {
      rtb_Switch = HIL_P.Constant1_Value_i;
    }

    /* End of Switch: '<S9>/Switch' */

    /* MATLABSystem: '<S9>/Digital Output' incorporates:
     *  Logic: '<S9>/NOT'
     */
    writeDigitalPin(7, (uint8_T)!(rtb_Switch != 0.0));

    /* MATLABSystem: '<S9>/Digital Output1' */
    rtb_Switch = rt_roundd_snf(rtb_Switch);
    if (rtb_Switch < 256.0) {
      if (rtb_Switch >= 0.0) {
        tmp_0 = (uint8_T)rtb_Switch;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    writeDigitalPin(8, tmp_0);

    /* End of MATLABSystem: '<S9>/Digital Output1' */

    /* Saturate: '<S9>/Saturation1' */
    if (HIL_B.MotorPwm > HIL_P.Saturation1_UpperSat) {
      /* Gain: '<S1>/Gain1' incorporates:
       *  Saturate: '<S9>/Saturation1'
       */
      HIL_B.MotorPwm = HIL_P.Saturation1_UpperSat;
    } else if (HIL_B.MotorPwm < HIL_P.Saturation1_LowerSat) {
      /* Gain: '<S1>/Gain1' incorporates:
       *  Saturate: '<S9>/Saturation1'
       */
      HIL_B.MotorPwm = HIL_P.Saturation1_LowerSat;
    }

    /* End of Saturate: '<S9>/Saturation1' */
    /* MATLABSystem: '<S9>/PWM' */
    obj = &HIL_DW.obj_l0;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Abs: '<S9>/Abs1' */
    rtb_Switch = fabs(HIL_B.MotorPwm);

    /* MATLABSystem: '<S9>/PWM' */
    if (!(rtb_Switch <= 255.0)) {
      rtb_Switch = 255.0;
    }

    MW_PWM_SetDutyCycle(HIL_DW.obj_l0.PWMDriverObj.MW_PWM_HANDLE, rtb_Switch);

    /* Gain: '<S6>/Gain' */
    HIL_B.Gain = HIL_P.Gain_Gain_k * rtb_Bias5;

    /* Gain: '<S7>/Gain' */
    HIL_B.Gain_c = HIL_P.Gain_Gain_p * Switch;

    /* Stop: '<S12>/Stop Simulation' incorporates:
     *  Abs: '<S12>/Abs1'
     *  Constant: '<S12>/Constant'
     *  RelationalOperator: '<S12>/GreaterThan'
     */
    if (fabs(HIL_B.Gain1) > HIL_P.Constant_Value_o) {
      rtmSetStopRequested(HIL_M, 1);
    }

    /* End of Stop: '<S12>/Stop Simulation' */
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<S10>/Derivative' */
    if (HIL_DW.TimeStampA == (rtInf)) {
      HIL_DW.TimeStampA = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeA;
    } else if (HIL_DW.TimeStampB == (rtInf)) {
      HIL_DW.TimeStampB = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeB;
    } else if (HIL_DW.TimeStampA < HIL_DW.TimeStampB) {
      HIL_DW.TimeStampA = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeA;
    } else {
      HIL_DW.TimeStampB = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeB;
    }

    *lastU = HIL_B.Gain1_a;

    /* End of Update for Derivative: '<S10>/Derivative' */

    /* Update for Derivative: '<S5>/Derivative' */
    if (HIL_DW.TimeStampA_j == (rtInf)) {
      HIL_DW.TimeStampA_j = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeA_m;
    } else if (HIL_DW.TimeStampB_a == (rtInf)) {
      HIL_DW.TimeStampB_a = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeB_p;
    } else if (HIL_DW.TimeStampA_j < HIL_DW.TimeStampB_a) {
      HIL_DW.TimeStampA_j = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeA_m;
    } else {
      HIL_DW.TimeStampB_a = HIL_M->Timing.t[0];
      lastU = &HIL_DW.LastUAtTimeB_p;
    }

    *lastU = HIL_B.Gain1_f;

    /* End of Update for Derivative: '<S5>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((HIL_M->Timing.clockTick0 * 1) + 0)
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
      ((HIL_M->Timing.clockTick1 * 1) + 0)
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
  HIL_M->Timing.t[0] =
    ((time_T)(++HIL_M->Timing.clockTick0)) * HIL_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    HIL_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void HIL_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&HIL_M->solverInfo, &HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&HIL_M->solverInfo, &rtmGetTPtr(HIL_M));
    rtsiSetStepSizePtr(&HIL_M->solverInfo, &HIL_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&HIL_M->solverInfo, (&rtmGetErrorStatus(HIL_M)));
    rtsiSetRTModelPtr(&HIL_M->solverInfo, HIL_M);
  }

  rtsiSetSimTimeStep(&HIL_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&HIL_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(HIL_M, &HIL_M->Timing.tArray[0]);
  rtmSetTFinal(HIL_M, -1);
  HIL_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  HIL_M->Sizes.checksums[0] = (3969916176U);
  HIL_M->Sizes.checksums[1] = (2774403085U);
  HIL_M->Sizes.checksums[2] = (1436107337U);
  HIL_M->Sizes.checksums[3] = (1554860002U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    HIL_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HIL_M->extModeInfo,
      &HIL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HIL_M->extModeInfo, HIL_M->Sizes.checksums);
    rteiSetTPtr(HIL_M->extModeInfo, rtmGetTPtr(HIL_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;

    /* InitializeConditions for Derivative: '<S10>/Derivative' */
    HIL_DW.TimeStampA = (rtInf);
    HIL_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S5>/Derivative' */
    HIL_DW.TimeStampA_j = (rtInf);
    HIL_DW.TimeStampB_a = (rtInf);

    /* Start for MATLABSystem: '<S10>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    HIL_DW.obj_l.matlabCodegenIsDeleted = false;

    /*  Do not generate code for sprintf */
    HIL_DW.obj_l.SampleTime = HIL_P.MATLABSystem_SampleTime;
    HIL_DW.obj_l.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(1.0, 3.0, 5.0);
    HIL_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/MATLAB System1' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    HIL_DW.obj.matlabCodegenIsDeleted = false;

    /*  Do not generate code for sprintf */
    HIL_DW.obj.SampleTime = HIL_P.MATLABSystem1_SampleTime;
    HIL_DW.obj.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(0.0, 2.0, 4.0);
    HIL_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Digital Output' */
    HIL_DW.obj_j.matlabCodegenIsDeleted = false;
    HIL_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(7, 1);
    HIL_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Digital Output1' */
    HIL_DW.obj_m.matlabCodegenIsDeleted = false;
    HIL_DW.obj_m.isInitialized = 1L;
    digitalIOSetup(8, 1);
    HIL_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/PWM' */
    HIL_DW.obj_l0.matlabCodegenIsDeleted = false;
    obj = &HIL_DW.obj_l0;
    HIL_DW.obj_l0.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    HIL_DW.obj_l0.isSetupComplete = true;
  }
}

/* Model terminate function */
void HIL_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S10>/MATLAB System' */
  if (!HIL_DW.obj_l.matlabCodegenIsDeleted) {
    HIL_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/MATLAB System' */

  /* Terminate for MATLABSystem: '<S5>/MATLAB System1' */
  if (!HIL_DW.obj.matlabCodegenIsDeleted) {
    HIL_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/MATLAB System1' */
  /* Terminate for MATLABSystem: '<S9>/Digital Output' */
  if (!HIL_DW.obj_j.matlabCodegenIsDeleted) {
    HIL_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Output' */

  /* Terminate for MATLABSystem: '<S9>/Digital Output1' */
  if (!HIL_DW.obj_m.matlabCodegenIsDeleted) {
    HIL_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S9>/PWM' */
  obj = &HIL_DW.obj_l0;
  if (!HIL_DW.obj_l0.matlabCodegenIsDeleted) {
    HIL_DW.obj_l0.matlabCodegenIsDeleted = true;
    if ((HIL_DW.obj_l0.isInitialized == 1L) && HIL_DW.obj_l0.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(HIL_DW.obj_l0.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(HIL_DW.obj_l0.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
