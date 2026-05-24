/*
 * File: SCCS_AntiPinch_SM_03.h
 *
 * Code generated for Simulink model 'SCCS_AntiPinch_SM_03'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun May 24 17:41:50 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef SCCS_AntiPinch_SM_03_h_
#define SCCS_AntiPinch_SM_03_h_
#ifndef SCCS_AntiPinch_SM_03_COMMON_INCLUDES_
#define SCCS_AntiPinch_SM_03_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                               /* SCCS_AntiPinch_SM_03_COMMON_INCLUDES_ */

#include "SCCS_AntiPinch_SM_03_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_SCCS_AntiPinch_SM_;/* '<Root>/Chart' */
  uint8_T is_c3_SCCS_AntiPinch_SM_03;  /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_SCCS_AntiPinch_SM_03_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Door_Position;                /* '<Root>/Door_Position' */
  real_T Motor_Current;                /* '<Root>/Motor_Current' */
  real_T Close_Command;                /* '<Root>/Close_Command' */
  real_T Open_Command;                 /* '<Root>/Open_Command' */
} ExtU_SCCS_AntiPinch_SM_03_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Motor_Voltage;                /* '<Root>/Motor_Voltage' */
  real_T Pinch_Detected;               /* '<Root>/Pinch_Detected' */
  real_T Door_State;                   /* '<Root>/Door_State' */
} ExtY_SCCS_AntiPinch_SM_03_T;

/* Real-time Model Data Structure */
struct tag_RTM_SCCS_AntiPinch_SM_03_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_SCCS_AntiPinch_SM_03_T SCCS_AntiPinch_SM_03_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_SCCS_AntiPinch_SM_03_T SCCS_AntiPinch_SM_03_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_SCCS_AntiPinch_SM_03_T SCCS_AntiPinch_SM_03_Y;

/* Model entry point functions */
extern void SCCS_AntiPinch_SM_03_initialize(void);
extern void SCCS_AntiPinch_SM_03_step(void);
extern void SCCS_AntiPinch_SM_03_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SCCS_AntiPinch_SM_03_T *const SCCS_AntiPinch_SM_03_M;

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
 * '<Root>' : 'SCCS_AntiPinch_SM_03'
 * '<S1>'   : 'SCCS_AntiPinch_SM_03/Chart'
 */
#endif                                 /* SCCS_AntiPinch_SM_03_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
