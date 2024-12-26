/*
 * File: BreakDownControll.c
 *
 * Code generated for Simulink model 'BreakDownControll'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec 12 15:38:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BreakDownControll.h"
#include "rtwtypes.h"
#include "BreakDownControll_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Named constants for Chart: '<S20>/Chart' */
#define BreakDownControll_IN_Init      ((uint8_T)1U)
#define BreakDownControll_IN_OFF       ((uint8_T)2U)
#define BreakDownControll_IN_ON        ((uint8_T)3U)
#define BreakDownControll_IN_count     ((uint8_T)4U)

/* Exported block signals */
boolean_T VbAirRadiotube_CanTransFlt_null;/* '<Root>/CanTransFlt_Boolean' */
uint8_T VuAirRadiotube_FailSafeSt_nul1l;/* '<Root>/Signal Copy' */
boolean_T VbAirRadiotube_FlagOutputCircuitFlt_null;/* '<S7>/OR' */
boolean_T VbAirRadiotube_FlagOutputVFlt_null;/* '<S10>/Switch3' */
boolean_T VbAirRadiotube_FlagOutputVLowFlt_null;/* '<S11>/Switch3' */
boolean_T VbAirRadiotube_FlagOutputTempFlt_null;/* '<Root>/Cast To Boolean2' */

/* Exported block parameters */
real_T KfBaseTimer_ms = 1.0;           /* Variable: KfBaseTimer_ms
                                        * Referenced by:
                                        *   '<S1>/Constant1'
                                        *   '<S1>/Constant10'
                                        */
real_T KfPWM_BaseTime_ms = 1.0;        /* Variable: KfPWM_BaseTime_ms
                                        * Referenced by: '<S8>/BaseTimer1'
                                        */
real_T KfPWM_OnDebTime_ms = 200.0;     /* Variable: KfPWM_OnDebTime_ms
                                        * Referenced by: '<S8>/OnDebTime1'
                                        */
real_T KfPWM_PeriodTime_ms = 600.0;    /* Variable: KfPWM_PeriodTime_ms
                                        * Referenced by: '<S8>/PeriodTimer1'
                                        */
real_T KfTriggerTimer_ms = 200.0;      /* Variable: KfTriggerTimer_ms
                                        * Referenced by:
                                        *   '<S1>/Constant5'
                                        *   '<S1>/Constant9'
                                        */
real32_T KfBaseTimerV_ms = 1.0F;       /* Variable: KfBaseTimerV_ms
                                        * Referenced by: '<Root>/Constant7'
                                        */
real32_T KfLowerTempthreshold_value = -40.0F;/* Variable: KfLowerTempthreshold_value
                                              * Referenced by: '<Root>/Constant5'
                                              */
real32_T KfTriggerTimerV_ms = 200.0F;  /* Variable: KfTriggerTimerV_ms
                                        * Referenced by: '<Root>/Constant6'
                                        */
real32_T KfUpperTempThreshold_value = 80.0F;/* Variable: KfUpperTempThreshold_value
                                             * Referenced by: '<Root>/Constant1'
                                             */
uint32_T KfLowerVThreshold_mV = 9000U; /* Variable: KfLowerVThreshold_mV
                                        * Referenced by: '<S1>/Constant2'
                                        */
uint32_T KfUpperVThreshold_mV = 16000U;/* Variable: KfUpperVThreshold_mV
                                        * Referenced by: '<S1>/Constant4'
                                        */
uint8_T KuFailSafeOverRide_null = 0U;  /* Variable: KuFailSafeOverRide_null
                                        * Referenced by: '<Root>/Constant2'
                                        */
uint8_T KuFailSafeSwitch_null = 0U;    /* Variable: KuFailSafeSwitch_null
                                        * Referenced by: '<Root>/Constant'
                                        */

/* Block states (default storage) */
DW_BreakDownControll_T BreakDownControll_DW;

/* External inputs (root inport signals with default storage) */
ExtU_BreakDownControll_T BreakDownControll_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BreakDownControll_T BreakDownControll_Y;

/* Real-time model */
static RT_MODEL_BreakDownControll_T BreakDownControll_M_;
RT_MODEL_BreakDownControll_T *const BreakDownControll_M = &BreakDownControll_M_;

/*
 * System initialize for atomic system:
 *    '<S4>/Chart2'
 *    '<S6>/Chart3'
 */
void BreakDownControll_Chart2_Init(real_T *rty_y)
{
  *rty_y = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Chart2'
 *    '<S6>/Chart3'
 */
void BreakDownControll_Chart2(real_T rtu_short, real_T rtu_open, real_T rtu_over,
  real_T *rty_y)
{
  /* Chart: '<S4>/Chart2' */
  if ((rtu_short == 0.0) && (rtu_open == 0.0) && (rtu_over == 0.0)) {
    *rty_y = 0.0;
  } else if ((rtu_short == 1.0) && (rtu_open == 0.0) && (rtu_over == 0.0)) {
    *rty_y = 1.0;
  } else if ((rtu_short == 0.0) && (rtu_open == 1.0) && (rtu_over == 0.0)) {
    *rty_y = 2.0;
  } else {
    *rty_y = 3.0;
  }

  /* End of Chart: '<S4>/Chart2' */
}

/* Model step function */
void BreakDownControll_step(void)
{
  real_T rtb_y_ce;
  int32_T SignalOut;
  int32_T Switch;
  int32_T rtb_y;
  boolean_T rtb_DataTypeConversion_c;

  /* Chart: '<S2>/Chart' incorporates:
   *  Inport: '<Root>/PINI_ValveOpenFltFL_flg'
   *  Inport: '<Root>/PINI_ValveOverCurrFltFL_flg'
   *  Inport: '<Root>/PINI_ValveShortFltFL_flg'
   */
  if ((BreakDownControll_U.PINI_ValveShortFltFL_flg == 0.0) &&
      (BreakDownControll_U.PINI_ValveOpenFltFL_flg == 0.0) &&
      (BreakDownControll_U.PINI_ValveOverCurrFltFL_flg == 0.0)) {
    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    BreakDownControll_Y.SprgFltFR_uint8 = 0U;
  } else if ((BreakDownControll_U.PINI_ValveShortFltFL_flg == 1.0) &&
             (BreakDownControll_U.PINI_ValveOpenFltFL_flg == 0.0) &&
             (BreakDownControll_U.PINI_ValveOverCurrFltFL_flg == 0.0)) {
    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    BreakDownControll_Y.SprgFltFR_uint8 = 1U;
  } else if ((BreakDownControll_U.PINI_ValveShortFltFL_flg == 0.0) &&
             (BreakDownControll_U.PINI_ValveOpenFltFL_flg == 1.0) &&
             (BreakDownControll_U.PINI_ValveOverCurrFltFL_flg == 0.0)) {
    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    BreakDownControll_Y.SprgFltFR_uint8 = 2U;
  } else {
    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    BreakDownControll_Y.SprgFltFR_uint8 = 3U;
  }

  /* End of Chart: '<S2>/Chart' */

  /* Outport: '<Root>/SprgFltFL_uint8' */
  BreakDownControll_Y.SprgFltFL_uint8 = BreakDownControll_Y.SprgFltFR_uint8;

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  rtb_DataTypeConversion_c = (BreakDownControll_Y.SprgFltFR_uint8 != 0);

  /* Chart: '<S3>/Chart1' incorporates:
   *  Inport: '<Root>/PINI_ValveOpenFltFR_flg'
   *  Inport: '<Root>/PINI_ValveOverCurrFltFR_flg'
   *  Inport: '<Root>/PINI_ValveShortFltFR_flg'
   */
  if ((BreakDownControll_U.PINI_ValveShortFltFR_flg == 0.0) &&
      (BreakDownControll_U.PINI_ValveOpenFltFR_flg == 0.0) &&
      (BreakDownControll_U.PINI_ValveOverCurrFltFR_flg == 0.0)) {
    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    BreakDownControll_Y.SprgFltFR_uint8 = 0U;
  } else if ((BreakDownControll_U.PINI_ValveShortFltFR_flg == 1.0) &&
             (BreakDownControll_U.PINI_ValveOpenFltFR_flg == 0.0) &&
             (BreakDownControll_U.PINI_ValveOverCurrFltFR_flg == 0.0)) {
    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    BreakDownControll_Y.SprgFltFR_uint8 = 1U;
  } else if ((BreakDownControll_U.PINI_ValveShortFltFR_flg == 0.0) &&
             (BreakDownControll_U.PINI_ValveOpenFltFR_flg == 1.0) &&
             (BreakDownControll_U.PINI_ValveOverCurrFltFR_flg == 0.0)) {
    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    BreakDownControll_Y.SprgFltFR_uint8 = 2U;
  } else {
    /* DataTypeConversion: '<S3>/Data Type Conversion' */
    BreakDownControll_Y.SprgFltFR_uint8 = 3U;
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Chart: '<S4>/Chart2' incorporates:
   *  Inport: '<Root>/PINI_ValveOpenFltRL_flg'
   *  Inport: '<Root>/PINI_ValveOverCurrFltRL_flg'
   *  Inport: '<Root>/PINI_ValveShortFltRL_flg'
   */
  BreakDownControll_Chart2(BreakDownControll_U.PINI_ValveShortFltRL_flg,
    BreakDownControll_U.PINI_ValveOpenFltRL_flg,
    BreakDownControll_U.PINI_ValveOverCurrFltRL_flg, &rtb_y_ce);

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  rtb_y_ce = floor(rtb_y_ce);
  if (rtIsNaN(rtb_y_ce) || rtIsInf(rtb_y_ce)) {
    rtb_y_ce = 0.0;
  } else {
    rtb_y_ce = fmod(rtb_y_ce, 256.0);
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  BreakDownControll_Y.SprgFltRL_uint8 = (uint8_T)(rtb_y_ce < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_y_ce : (int32_T)(uint8_T)rtb_y_ce);

  /* Chart: '<S6>/Chart3' incorporates:
   *  Inport: '<Root>/PINI_ValveOpenFltRR_flg'
   *  Inport: '<Root>/PINI_ValveOverCurrFltRR_flg'
   *  Inport: '<Root>/PINI_ValveShortFltRR_flg'
   */
  BreakDownControll_Chart2(BreakDownControll_U.PINI_ValveShortFltRR_flg,
    BreakDownControll_U.PINI_ValveOpenFltRR_flg,
    BreakDownControll_U.PINI_ValveOverCurrFltRR_flg, &rtb_y_ce);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  rtb_y_ce = floor(rtb_y_ce);
  if (rtIsNaN(rtb_y_ce) || rtIsInf(rtb_y_ce)) {
    rtb_y_ce = 0.0;
  } else {
    rtb_y_ce = fmod(rtb_y_ce, 256.0);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  BreakDownControll_Y.SprgFltRR_uint8 = (uint8_T)(rtb_y_ce < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_y_ce : (int32_T)(uint8_T)rtb_y_ce);

  /* Logic: '<S7>/OR' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  DataTypeConversion: '<S7>/Data Type Conversion3'
   */
  VbAirRadiotube_FlagOutputCircuitFlt_null = (rtb_DataTypeConversion_c ||
    (BreakDownControll_Y.SprgFltFR_uint8 != 0) ||
    (BreakDownControll_Y.SprgFltRL_uint8 != 0) ||
    (BreakDownControll_Y.SprgFltRR_uint8 != 0));

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant2'
   *  Inport: '<Root>/Gp_IoProxy_Core2Send_Gp_IoProxy_Core2_uVfPINI_VBat2_PIN'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S1>/Relational Operator4'
   *  Sum: '<S10>/Add'
   *  Sum: '<S10>/Add1'
   *  Switch: '<S10>/Switch1'
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S10>/Unit Delay2'
   */
  if (KfLowerVThreshold_mV > BreakDownControll_U.Gp_IoProxy_Core2Send_Gp_IoProxy)
  {
    BreakDownControll_DW.UnitDelay1_DSTATE += KfBaseTimer_ms;
    BreakDownControll_DW.UnitDelay2_DSTATE = 0.0;
  } else {
    BreakDownControll_DW.UnitDelay1_DSTATE = 0.0;
    BreakDownControll_DW.UnitDelay2_DSTATE += KfBaseTimer_ms;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Switch: '<S10>/Switch3' incorporates:
   *  Constant: '<S1>/Constant9'
   *  RelationalOperator: '<S10>/Relational Operator3'
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  if (BreakDownControll_DW.UnitDelay1_DSTATE >= KfTriggerTimer_ms) {
    /* Switch: '<S10>/Switch3' incorporates:
     *  Constant: '<S10>/Constant6'
     */
    VbAirRadiotube_FlagOutputVFlt_null = true;
  } else {
    /* Switch: '<S10>/Switch3' incorporates:
     *  RelationalOperator: '<S10>/Relational Operator2'
     *  Switch: '<S10>/Switch4'
     *  UnitDelay: '<S10>/Unit Delay2'
     *  UnitDelay: '<S10>/Unit Delay3'
     */
    VbAirRadiotube_FlagOutputVFlt_null =
      ((!(BreakDownControll_DW.UnitDelay2_DSTATE >= KfTriggerTimer_ms)) &&
       VbAirRadiotube_FlagOutputVFlt_null);
  }

  /* End of Switch: '<S10>/Switch3' */

  /* Switch: '<S11>/Switch2' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant4'
   *  Inport: '<Root>/Gp_IoProxy_Core2Send_Gp_IoProxy_Core2_uVfPINI_VBat2_PIN'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S1>/Relational Operator1'
   *  Sum: '<S11>/Add'
   *  Sum: '<S11>/Add1'
   *  Switch: '<S11>/Switch1'
   *  UnitDelay: '<S11>/Unit Delay1'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  if (BreakDownControll_U.Gp_IoProxy_Core2Send_Gp_IoProxy > KfUpperVThreshold_mV)
  {
    BreakDownControll_DW.UnitDelay1_DSTATE_l += KfBaseTimer_ms;
    BreakDownControll_DW.UnitDelay2_DSTATE_p = 0.0;
  } else {
    BreakDownControll_DW.UnitDelay1_DSTATE_l = 0.0;
    BreakDownControll_DW.UnitDelay2_DSTATE_p += KfBaseTimer_ms;
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Switch: '<S11>/Switch3' incorporates:
   *  Constant: '<S1>/Constant5'
   *  RelationalOperator: '<S11>/Relational Operator3'
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  if (BreakDownControll_DW.UnitDelay1_DSTATE_l >= KfTriggerTimer_ms) {
    /* Switch: '<S11>/Switch3' incorporates:
     *  Constant: '<S11>/Constant6'
     */
    VbAirRadiotube_FlagOutputVLowFlt_null = true;
  } else {
    /* Switch: '<S11>/Switch3' incorporates:
     *  RelationalOperator: '<S11>/Relational Operator2'
     *  Switch: '<S11>/Switch4'
     *  UnitDelay: '<S11>/Unit Delay2'
     *  UnitDelay: '<S11>/Unit Delay3'
     */
    VbAirRadiotube_FlagOutputVLowFlt_null =
      ((!(BreakDownControll_DW.UnitDelay2_DSTATE_p >= KfTriggerTimer_ms)) &&
       VbAirRadiotube_FlagOutputVLowFlt_null);
  }

  /* End of Switch: '<S11>/Switch3' */

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant7'
   *  Constant: '<S9>/Constant1'
   *  Inport: '<Root>/PINI_9945_2Temp_deg'
   *  RelationalOperator: '<S9>/Relational Operator1'
   *  Sum: '<S9>/Add'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  if (KfUpperTempThreshold_value < BreakDownControll_U.PINI_9945_2Temp_deg) {
    BreakDownControll_DW.UnitDelay1_DSTATE_p += KfBaseTimerV_ms;
  } else {
    BreakDownControll_DW.UnitDelay1_DSTATE_p = 0.0F;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant7'
   *  Constant: '<S9>/Constant2'
   *  Inport: '<Root>/PINI_9945_2Temp_deg'
   *  RelationalOperator: '<S9>/Relational Operator4'
   *  Sum: '<S9>/Add1'
   *  UnitDelay: '<S9>/Unit Delay2'
   */
  if (BreakDownControll_U.PINI_9945_2Temp_deg < KfLowerTempthreshold_value) {
    BreakDownControll_DW.UnitDelay2_DSTATE_k += KfBaseTimerV_ms;
  } else {
    BreakDownControll_DW.UnitDelay2_DSTATE_k = 0.0F;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S9>/Constant6'
   *  RelationalOperator: '<S9>/Relational Operator2'
   *  RelationalOperator: '<S9>/Relational Operator3'
   *  Switch: '<S9>/Switch4'
   *  UnitDelay: '<S9>/Unit Delay1'
   *  UnitDelay: '<S9>/Unit Delay2'
   *  UnitDelay: '<S9>/Unit Delay3'
   */
  if (BreakDownControll_DW.UnitDelay1_DSTATE_p >= KfTriggerTimerV_ms) {
    BreakDownControll_DW.UnitDelay3_DSTATE = 1U;
  } else if (BreakDownControll_DW.UnitDelay2_DSTATE_k >= KfTriggerTimerV_ms) {
    /* Switch: '<S9>/Switch4' incorporates:
     *  Constant: '<S9>/Constant5'
     *  UnitDelay: '<S9>/Unit Delay3'
     */
    BreakDownControll_DW.UnitDelay3_DSTATE = 0U;
  }

  /* End of Switch: '<S9>/Switch3' */

  /* DataTypeConversion: '<Root>/Cast To Boolean2' incorporates:
   *  UnitDelay: '<S9>/Unit Delay3'
   */
  VbAirRadiotube_FlagOutputTempFlt_null =
    (BreakDownControll_DW.UnitDelay3_DSTATE != 0);

  /* Switch: '<S5>/Switch' incorporates:
   *  Chart: '<S7>/Chart1'
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Inport: '<Root>/CanTransFlt_Boolean'
   *  Logic: '<S7>/OR1'
   */
  if (KuFailSafeSwitch_null != 0) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    VuAirRadiotube_FailSafeSt_nul1l = KuFailSafeOverRide_null;
  } else if (VbAirRadiotube_FlagOutputCircuitFlt_null ||
             VbAirRadiotube_CanTransFlt_null ||
             VbAirRadiotube_FlagOutputVFlt_null ||
             VbAirRadiotube_FlagOutputVLowFlt_null) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Chart: '<S7>/Chart1'
     *  DataTypeConversion: '<S7>/Data Type Conversion4'
     */
    VuAirRadiotube_FailSafeSt_nul1l = 1U;
  } else if (VbAirRadiotube_FlagOutputTempFlt_null) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Chart: '<S7>/Chart1'
     *  DataTypeConversion: '<S7>/Data Type Conversion4'
     */
    VuAirRadiotube_FailSafeSt_nul1l = 2U;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Chart: '<S7>/Chart1'
     *  DataTypeConversion: '<S7>/Data Type Conversion4'
     */
    VuAirRadiotube_FailSafeSt_nul1l = 0U;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Chart: '<S8>/Chart2' incorporates:
   *  Inport: '<Root>/SprgStReqFL_boolean'
   *  Inport: '<Root>/SprgStReqFR_boolean'
   *  Inport: '<Root>/SprgStReqRL_boolean'
   *  Inport: '<Root>/SprgStReqRR_boolean'
   *  Logic: '<S8>/OR'
   */
  if (VuAirRadiotube_FailSafeSt_nul1l != 0) {
    rtb_y = 2;
  } else {
    rtb_y = (BreakDownControll_U.SprgStReqFL_boolean ||
             BreakDownControll_U.SprgStReqFR_boolean ||
             BreakDownControll_U.SprgStReqRL_boolean ||
             BreakDownControll_U.SprgStReqRR_boolean);
  }

  /* End of Chart: '<S8>/Chart2' */

  /* Switch: '<S8>/Switch' */
  Switch = (rtb_y >= 2);

  /* Chart: '<S20>/Chart' incorporates:
   *  Constant: '<S8>/BaseTimer1'
   *  Constant: '<S8>/OnDebTime1'
   *  Constant: '<S8>/PeriodTimer1'
   */
  switch (BreakDownControll_DW.is_c11_BreakDownControll) {
   case BreakDownControll_IN_Init:
    SignalOut = 0;
    if (Switch != 0) {
      BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_count;
      SignalOut = 1;
      BreakDownControll_DW.off_time_cnt = 0.0;
      BreakDownControll_DW.on_time_cnt = KfPWM_BaseTime_ms;
    }
    break;

   case BreakDownControll_IN_OFF:
    SignalOut = 1;
    if (BreakDownControll_DW.on_time_cnt >= KfPWM_OnDebTime_ms) {
      BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_ON;
      SignalOut = 0;
      BreakDownControll_DW.on_time_cnt = 0.0;
      BreakDownControll_DW.off_time_cnt = KfPWM_BaseTime_ms;
    } else if (Switch == 0) {
      BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_Init;
      BreakDownControll_DW.on_time_cnt = 0.0;
      BreakDownControll_DW.off_time_cnt = 0.0;
      SignalOut = 0;
    } else {
      BreakDownControll_DW.on_time_cnt += KfPWM_BaseTime_ms;
    }
    break;

   case BreakDownControll_IN_ON:
    SignalOut = 0;
    if (BreakDownControll_DW.off_time_cnt >= KfPWM_PeriodTime_ms -
        KfPWM_OnDebTime_ms) {
      BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_OFF;
      SignalOut = 1;
      BreakDownControll_DW.off_time_cnt = 0.0;
      BreakDownControll_DW.on_time_cnt = KfPWM_BaseTime_ms;
    } else if (Switch == 0) {
      BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_Init;
      BreakDownControll_DW.on_time_cnt = 0.0;
      BreakDownControll_DW.off_time_cnt = 0.0;
    } else {
      BreakDownControll_DW.off_time_cnt += KfPWM_BaseTime_ms;
    }
    break;

   default:
    /* case IN_count: */
    SignalOut = 1;
    if (Switch == 0) {
      BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_Init;
      BreakDownControll_DW.on_time_cnt = 0.0;
      BreakDownControll_DW.off_time_cnt = 0.0;
      SignalOut = 0;
    } else if (BreakDownControll_DW.on_time_cnt >= KfPWM_OnDebTime_ms) {
      BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_ON;
      SignalOut = 0;
      BreakDownControll_DW.on_time_cnt = 0.0;
      BreakDownControll_DW.off_time_cnt = KfPWM_BaseTime_ms;
    } else {
      BreakDownControll_DW.on_time_cnt += KfPWM_BaseTime_ms;
    }
    break;
  }

  /* End of Chart: '<S20>/Chart' */

  /* Switch: '<S8>/Switch1' */
  if (VuAirRadiotube_FailSafeSt_nul1l >= 1) {
    /* Outport: '<Root>/REVD_LRevsLghtDrvSts_flg' */
    BreakDownControll_Y.REVD_LRevsLghtDrvSts_flg = (SignalOut != 0);
  } else {
    /* Outport: '<Root>/REVD_LRevsLghtDrvSts_flg' incorporates:
     *  Constant: '<S8>/Constant5'
     *  RelationalOperator: '<S8>/Relational Operator1'
     */
    BreakDownControll_Y.REVD_LRevsLghtDrvSts_flg = (rtb_y == 1);
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Outport: '<Root>/FailSafeSt_uint8' */
  BreakDownControll_Y.FailSafeSt_uint8 = VuAirRadiotube_FailSafeSt_nul1l;
}

/* Model initialize function */
void BreakDownControll_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T rtb_y;

    /* SystemInitialize for Chart: '<S4>/Chart2' */
    BreakDownControll_Chart2_Init(&rtb_y);

    /* SystemInitialize for Chart: '<S6>/Chart3' */
    BreakDownControll_Chart2_Init(&rtb_y);

    /* Chart: '<S20>/Chart' */
    BreakDownControll_DW.is_c11_BreakDownControll = BreakDownControll_IN_Init;
  }
}

/* Model terminate function */
void BreakDownControll_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
