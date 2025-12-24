/*
 * File: HIL.h
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

#ifndef RTW_HEADER_HIL_h_
#define RTW_HEADER_HIL_h_
#ifndef HIL_COMMON_INCLUDES_
#define HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "encoder_arduino.h"
#endif                                 /* HIL_COMMON_INCLUDES_ */

#include "HIL_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
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
  real_T Gain1;                        /* '<S10>/Gain1' */
  real_T Gain1_a;                      /* '<S11>/Gain1' */
  real_T Derivative;                   /* '<S10>/Derivative' */
  real_T Gain1_f;                      /* '<S13>/Gain1' */
  real_T Derivative_f;                 /* '<S5>/Derivative' */
  real_T motorcontrol;                 /* '<S1>/Switch' */
  real_T MotorPwm;                     /* '<S9>/Saturation1' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T Gain_c;                       /* '<S7>/Gain' */
  real_T u;                            /* '<S8>/MATLAB Function2' */
} B_HIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoder_arduino_HIL_T obj;           /* '<S5>/MATLAB System1' */
  Encoder_arduino_HIL_T obj_l;         /* '<S10>/MATLAB System' */
  codertarget_arduinobase_block_T obj_m;/* '<S9>/Digital Output1' */
  codertarget_arduinobase_block_T obj_j;/* '<S9>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l0;/* '<S9>/PWM' */
  real_T TimeStampA;                   /* '<S10>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S10>/Derivative' */
  real_T TimeStampB;                   /* '<S10>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S10>/Derivative' */
  real_T TimeStampA_j;                 /* '<S5>/Derivative' */
  real_T LastUAtTimeA_m;               /* '<S5>/Derivative' */
  real_T TimeStampB_a;                 /* '<S5>/Derivative' */
  real_T LastUAtTimeB_p;               /* '<S5>/Derivative' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S12>/Scope' */

  uint8_T is_active_c3_HIL;            /* '<S8>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit;    /* '<S8>/MATLAB Function2' */
} DW_HIL_T;

/* Parameters (default storage) */
struct P_HIL_T_ {
  real_T k[4];                         /* Variable: k
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S15>/Slider Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Bias1_Bias;                   /* Expression: pi
                                        * Referenced by: '<S2>/Bias1'
                                        */
  real_T Bias2_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S2>/Bias2'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Bias3_Bias;                   /* Expression: -pi
                                        * Referenced by: '<S2>/Bias3'
                                        */
  real_T Bias4_Bias;                   /* Expression: pi
                                        * Referenced by: '<S2>/Bias4'
                                        */
  real_T Constant_Value_g;             /* Expression: 2*pi
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Bias1_Bias_b;                 /* Expression: pi
                                        * Referenced by: '<S3>/Bias1'
                                        */
  real_T Bias2_Bias_f;                 /* Expression: -pi
                                        * Referenced by: '<S3>/Bias2'
                                        */
  real_T Constant1_Value_k;            /* Expression: 2*pi
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Bias3_Bias_p;                 /* Expression: -pi
                                        * Referenced by: '<S3>/Bias3'
                                        */
  real_T Bias4_Bias_k;                 /* Expression: pi
                                        * Referenced by: '<S3>/Bias4'
                                        */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S10>/MATLAB System'
                                        */
  real_T MATLABSystem1_SampleTime;     /* Expression: 0.01
                                        * Referenced by: '<S5>/MATLAB System1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 255/12
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/22
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 1/46.73
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 360
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: pi/180
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 1/600
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 360
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain_mf;                /* Expression: pi/180
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T Bias5_Bias;                   /* Expression: pi
                                        * Referenced by: '<S3>/Bias5'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Switch_Threshold_j;           /* Expression: pi/9
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 0
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -255
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 3
                                        * Referenced by: '<S12>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_HIL_T {
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
extern P_HIL_T HIL_P;

/* Block signals (default storage) */
extern B_HIL_T HIL_B;

/* Block states (default storage) */
extern DW_HIL_T HIL_DW;

/* Model entry point functions */
extern void HIL_initialize(void);
extern void HIL_step(void);
extern void HIL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HIL_T *const HIL_M;
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
 * '<Root>' : 'HIL'
 * '<S1>'   : 'HIL/Furuta pendulum'
 * '<S2>'   : 'HIL/Furuta pendulum/Angle conversion'
 * '<S3>'   : 'HIL/Furuta pendulum/Angle conversion 1'
 * '<S4>'   : 'HIL/Furuta pendulum/DC motor with encoder'
 * '<S5>'   : 'HIL/Furuta pendulum/Encoder'
 * '<S6>'   : 'HIL/Furuta pendulum/Radians to Degrees'
 * '<S7>'   : 'HIL/Furuta pendulum/Radians to Degrees1'
 * '<S8>'   : 'HIL/Furuta pendulum/Swing up'
 * '<S9>'   : 'HIL/Furuta pendulum/DC motor with encoder/DC motor'
 * '<S10>'  : 'HIL/Furuta pendulum/DC motor with encoder/Encoder'
 * '<S11>'  : 'HIL/Furuta pendulum/DC motor with encoder/Encoder/Degrees to Radians'
 * '<S12>'  : 'HIL/Furuta pendulum/DC motor with encoder/Encoder/Emergency stop'
 * '<S13>'  : 'HIL/Furuta pendulum/Encoder/Degrees to Radians'
 * '<S14>'  : 'HIL/Furuta pendulum/Swing up/MATLAB Function2'
 * '<S15>'  : 'HIL/Furuta pendulum/Swing up/Slider Gain'
 */
#endif                                 /* RTW_HEADER_HIL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
