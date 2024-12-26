/*
 * File: BreakDownControll.h
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

#ifndef RTW_HEADER_BreakDownControll_h_
#define RTW_HEADER_BreakDownControll_h_
#ifndef BreakDownControll_COMMON_INCLUDES_
#define BreakDownControll_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BreakDownControll_COMMON_INCLUDES_ */

#include "BreakDownControll_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S10>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S10>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_l;          /* '<S11>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_p;          /* '<S11>/Unit Delay2' */
  real_T on_time_cnt;                  /* '<S20>/Chart' */
  real_T off_time_cnt;                 /* '<S20>/Chart' */
  real32_T UnitDelay1_DSTATE_p;        /* '<S9>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_k;        /* '<S9>/Unit Delay2' */
  uint8_T UnitDelay3_DSTATE;           /* '<S9>/Unit Delay3' */
  uint8_T is_c11_BreakDownControll;    /* '<S20>/Chart' */
} DW_BreakDownControll_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T PINI_ValveShortFltFL_flg;     /* '<Root>/PINI_ValveShortFltFL_flg' */
  real_T PINI_ValveOpenFltFL_flg;      /* '<Root>/PINI_ValveOpenFltFL_flg' */
  real_T PINI_ValveOverCurrFltFL_flg; /* '<Root>/PINI_ValveOverCurrFltFL_flg' */
  real_T PINI_ValveShortFltFR_flg;     /* '<Root>/PINI_ValveShortFltFR_flg' */
  real_T PINI_ValveOpenFltFR_flg;      /* '<Root>/PINI_ValveOpenFltFR_flg' */
  real_T PINI_ValveOverCurrFltFR_flg; /* '<Root>/PINI_ValveOverCurrFltFR_flg' */
  real_T PINI_ValveShortFltRL_flg;     /* '<Root>/PINI_ValveShortFltRL_flg' */
  real_T PINI_ValveOpenFltRL_flg;      /* '<Root>/PINI_ValveOpenFltRL_flg' */
  real_T PINI_ValveOverCurrFltRL_flg; /* '<Root>/PINI_ValveOverCurrFltRL_flg' */
  real_T PINI_ValveShortFltRR_flg;     /* '<Root>/PINI_ValveShortFltRR_flg' */
  real_T PINI_ValveOpenFltRR_flg;      /* '<Root>/PINI_ValveOpenFltRR_flg' */
  real_T PINI_ValveOverCurrFltRR_flg; /* '<Root>/PINI_ValveOverCurrFltRR_flg' */
  uint32_T Gp_IoProxy_Core2Send_Gp_IoProxy;
          /* '<Root>/Gp_IoProxy_Core2Send_Gp_IoProxy_Core2_uVfPINI_VBat2_PIN' */
  real32_T PINI_9945_2Temp_deg;        /* '<Root>/PINI_9945_2Temp_deg' */
  boolean_T SprgStReqFL_boolean;       /* '<Root>/SprgStReqFL_boolean' */
  boolean_T SprgStReqFR_boolean;       /* '<Root>/SprgStReqFR_boolean' */
  boolean_T SprgStReqRL_boolean;       /* '<Root>/SprgStReqRL_boolean' */
  boolean_T SprgStReqRR_boolean;       /* '<Root>/SprgStReqRR_boolean' */
} ExtU_BreakDownControll_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T SprgFltFL_uint8;             /* '<Root>/SprgFltFL_uint8' */
  uint8_T SprgFltFR_uint8;             /* '<Root>/SprgFltFR_uint8' */
  uint8_T SprgFltRL_uint8;             /* '<Root>/SprgFltRL_uint8' */
  uint8_T SprgFltRR_uint8;             /* '<Root>/SprgFltRR_uint8' */
  boolean_T REVD_LRevsLghtDrvSts_flg;  /* '<Root>/REVD_LRevsLghtDrvSts_flg' */
  uint8_T FailSafeSt_uint8;            /* '<Root>/FailSafeSt_uint8' */
} ExtY_BreakDownControll_T;

/* Real-time Model Data Structure */
struct tag_RTM_BreakDownControll_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_BreakDownControll_T BreakDownControll_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_BreakDownControll_T BreakDownControll_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BreakDownControll_T BreakDownControll_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T VbAirRadiotube_CanTransFlt_null;/* '<Root>/CanTransFlt_Boolean' */
extern uint8_T VuAirRadiotube_FailSafeSt_nul1l;/* '<Root>/Signal Copy' */
extern boolean_T VbAirRadiotube_FlagOutputCircuitFlt_null;/* '<S7>/OR' */
extern boolean_T VbAirRadiotube_FlagOutputVFlt_null;/* '<S10>/Switch3' */
extern boolean_T VbAirRadiotube_FlagOutputVLowFlt_null;/* '<S11>/Switch3' */
extern boolean_T VbAirRadiotube_FlagOutputTempFlt_null;/* '<Root>/Cast To Boolean2' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T KfBaseTimer_ms;          /* Variable: KfBaseTimer_ms
                                        * Referenced by:
                                        *   '<S1>/Constant1'
                                        *   '<S1>/Constant10'
                                        */
extern real_T KfPWM_BaseTime_ms;       /* Variable: KfPWM_BaseTime_ms
                                        * Referenced by: '<S8>/BaseTimer1'
                                        */
extern real_T KfPWM_OnDebTime_ms;      /* Variable: KfPWM_OnDebTime_ms
                                        * Referenced by: '<S8>/OnDebTime1'
                                        */
extern real_T KfPWM_PeriodTime_ms;     /* Variable: KfPWM_PeriodTime_ms
                                        * Referenced by: '<S8>/PeriodTimer1'
                                        */
extern real_T KfTriggerTimer_ms;       /* Variable: KfTriggerTimer_ms
                                        * Referenced by:
                                        *   '<S1>/Constant5'
                                        *   '<S1>/Constant9'
                                        */
extern real32_T KfBaseTimerV_ms;       /* Variable: KfBaseTimerV_ms
                                        * Referenced by: '<Root>/Constant7'
                                        */
extern real32_T KfLowerTempthreshold_value;/* Variable: KfLowerTempthreshold_value
                                            * Referenced by: '<Root>/Constant5'
                                            */
extern real32_T KfTriggerTimerV_ms;    /* Variable: KfTriggerTimerV_ms
                                        * Referenced by: '<Root>/Constant6'
                                        */
extern real32_T KfUpperTempThreshold_value;/* Variable: KfUpperTempThreshold_value
                                            * Referenced by: '<Root>/Constant1'
                                            */
extern uint32_T KfLowerVThreshold_mV;  /* Variable: KfLowerVThreshold_mV
                                        * Referenced by: '<S1>/Constant2'
                                        */
extern uint32_T KfUpperVThreshold_mV;  /* Variable: KfUpperVThreshold_mV
                                        * Referenced by: '<S1>/Constant4'
                                        */
extern uint8_T KuFailSafeOverRide_null;/* Variable: KuFailSafeOverRide_null
                                        * Referenced by: '<Root>/Constant2'
                                        */
extern uint8_T KuFailSafeSwitch_null;  /* Variable: KuFailSafeSwitch_null
                                        * Referenced by: '<Root>/Constant'
                                        */

/* Model entry point functions */
extern void BreakDownControll_initialize(void);
extern void BreakDownControll_step(void);
extern void BreakDownControll_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BreakDownControll_T *const BreakDownControll_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'BreakDownControll'
 * '<S1>'   : 'BreakDownControll/FltVBat'
 * '<S2>'   : 'BreakDownControll/Subsystem'
 * '<S3>'   : 'BreakDownControll/Subsystem1'
 * '<S4>'   : 'BreakDownControll/Subsystem2'
 * '<S5>'   : 'BreakDownControll/Subsystem23'
 * '<S6>'   : 'BreakDownControll/Subsystem3'
 * '<S7>'   : 'BreakDownControll/Subsystem4'
 * '<S8>'   : 'BreakDownControll/Subsystem5'
 * '<S9>'   : 'BreakDownControll/UpWarningDetectionA'
 * '<S10>'  : 'BreakDownControll/FltVBat/Subsystem4'
 * '<S11>'  : 'BreakDownControll/FltVBat/Subsystem6'
 * '<S12>'  : 'BreakDownControll/FltVBat/Subsystem4/Compare To Constant'
 * '<S13>'  : 'BreakDownControll/FltVBat/Subsystem6/Compare To Constant'
 * '<S14>'  : 'BreakDownControll/Subsystem/Chart'
 * '<S15>'  : 'BreakDownControll/Subsystem1/Chart1'
 * '<S16>'  : 'BreakDownControll/Subsystem2/Chart2'
 * '<S17>'  : 'BreakDownControll/Subsystem3/Chart3'
 * '<S18>'  : 'BreakDownControll/Subsystem4/Chart1'
 * '<S19>'  : 'BreakDownControll/Subsystem5/Chart2'
 * '<S20>'  : 'BreakDownControll/Subsystem5/PWM1'
 * '<S21>'  : 'BreakDownControll/Subsystem5/PWM1/Chart'
 */
#endif                                 /* RTW_HEADER_BreakDownControll_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
