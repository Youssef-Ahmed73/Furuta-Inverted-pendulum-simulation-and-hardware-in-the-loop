/*
 * File: Data_acquisition.h
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

#ifndef RTW_HEADER_Data_acquisition_h_
#define RTW_HEADER_Data_acquisition_h_
#ifndef Data_acquisition_COMMON_INCLUDES_
#define Data_acquisition_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "encoder_arduino.h"
#include "MW_PWM.h"
#endif                                 /* Data_acquisition_COMMON_INCLUDES_ */

#include "Data_acquisition_types.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain3;                        /* '<Root>/Gain3' */
} B_Data_acquisition_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoder_arduino_Data_acquisit_T obj; /* '<Root>/MATLAB System1' */
  Encoder_arduino_Data_acquisit_T obj_p;/* '<Root>/MATLAB System' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_n;/* '<Root>/PWM' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_Data_acquisition_T;

/* Parameters (default storage) */
struct P_Data_acquisition_T_ {
  real_T MATLABSystem_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T MATLABSystem1_SampleTime;     /* Expression: 0.01
                                        * Referenced by: '<Root>/MATLAB System1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/22
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/46.73
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant7_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/600
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 100
                                        * Referenced by: '<Root>/Step'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Data_acquisition_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Data_acquisition_T Data_acquisition_P;

/* Block signals (default storage) */
extern B_Data_acquisition_T Data_acquisition_B;

/* Block states (default storage) */
extern DW_Data_acquisition_T Data_acquisition_DW;

/* Model entry point functions */
extern void Data_acquisition_initialize(void);
extern void Data_acquisition_step(void);
extern void Data_acquisition_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Data_acquisition_T *const Data_acquisition_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Data_acquisition'
 */
#endif                                 /* RTW_HEADER_Data_acquisition_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
