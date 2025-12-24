/*
 * File: HIL_data.c
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

/* Block parameters (default storage) */
P_HIL_T HIL_P = {
  /* Variable: k
   * Referenced by: '<S1>/Gain'
   */
  { 602.75090390280661, 41.244411499089786, -3.8633370464313792,
    -21.834306955065557 },

  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S15>/Slider Gain'
   */
  4000.0,

  /* Expression: 2*pi
   * Referenced by: '<S2>/Constant'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S2>/Bias1'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S2>/Constant1'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S2>/Bias3'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S2>/Bias4'
   */
  3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S3>/Constant'
   */
  6.2831853071795862,

  /* Expression: pi
   * Referenced by: '<S3>/Bias1'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S3>/Bias2'
   */
  -3.1415926535897931,

  /* Expression: 2*pi
   * Referenced by: '<S3>/Constant1'
   */
  6.2831853071795862,

  /* Expression: -pi
   * Referenced by: '<S3>/Bias3'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S3>/Bias4'
   */
  3.1415926535897931,

  /* Expression: 0.01
   * Referenced by: '<S10>/MATLAB System'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S5>/MATLAB System1'
   */
  0.01,

  /* Expression: 255/12
   * Referenced by: '<S8>/Gain1'
   */
  21.25,

  /* Expression: 1/22
   * Referenced by: '<S10>/Gain'
   */
  0.045454545454545456,

  /* Expression: 1/46.73
   * Referenced by: '<S10>/Gain1'
   */
  0.021399529210357374,

  /* Expression: 360
   * Referenced by: '<S10>/Gain2'
   */
  360.0,

  /* Expression: pi/180
   * Referenced by: '<S11>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1/600
   * Referenced by: '<S5>/Gain2'
   */
  0.0016666666666666668,

  /* Expression: 1/2
   * Referenced by: '<S5>/Gain3'
   */
  0.5,

  /* Expression: 360
   * Referenced by: '<S5>/Gain'
   */
  360.0,

  /* Expression: pi/180
   * Referenced by: '<S13>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<S3>/Bias5'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant1'
   */
  1.0,

  /* Expression: pi/9
   * Referenced by: '<S1>/Switch'
   */
  0.3490658503988659,

  /* Expression: 0
   * Referenced by: '<S1>/Gain1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S9>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Switch'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S9>/Saturation1'
   */
  255.0,

  /* Expression: -255
   * Referenced by: '<S9>/Saturation1'
   */
  -255.0,

  /* Expression: 180/pi
   * Referenced by: '<S6>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S7>/Gain'
   */
  57.295779513082323,

  /* Expression: 3
   * Referenced by: '<S12>/Constant'
   */
  3.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
