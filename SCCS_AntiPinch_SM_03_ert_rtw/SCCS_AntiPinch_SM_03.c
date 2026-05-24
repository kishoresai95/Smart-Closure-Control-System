/*
 * File: SCCS_AntiPinch_SM_03.c
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

#include "SCCS_AntiPinch_SM_03.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define SCCS_AntiPinc_IN_PINCH_DETECTED ((uint8_T)4U)
#define SCCS_AntiPinch_SM_03_IN_CLOSING ((uint8_T)1U)
#define SCCS_AntiPinch_SM_03_IN_IDLE   ((uint8_T)2U)
#define SCCS_AntiPinch_SM_03_IN_OPENING ((uint8_T)3U)
#define SCCS_AntiPinch_SM__IN_REVERSING ((uint8_T)5U)

/* Block states (default storage) */
DW_SCCS_AntiPinch_SM_03_T SCCS_AntiPinch_SM_03_DW;

/* External inputs (root inport signals with default storage) */
ExtU_SCCS_AntiPinch_SM_03_T SCCS_AntiPinch_SM_03_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_SCCS_AntiPinch_SM_03_T SCCS_AntiPinch_SM_03_Y;

/* Real-time model */
static RT_MODEL_SCCS_AntiPinch_SM_03_T SCCS_AntiPinch_SM_03_M_;
RT_MODEL_SCCS_AntiPinch_SM_03_T *const SCCS_AntiPinch_SM_03_M =
  &SCCS_AntiPinch_SM_03_M_;

/* Model step function */
void SCCS_AntiPinch_SM_03_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/Close_Command'
   *  Inport: '<Root>/Door_Position'
   *  Inport: '<Root>/Motor_Current'
   *  Inport: '<Root>/Open_Command'
   */
  if (SCCS_AntiPinch_SM_03_DW.temporalCounter_i1 < 63U) {
    SCCS_AntiPinch_SM_03_DW.temporalCounter_i1++;
  }

  if (SCCS_AntiPinch_SM_03_DW.is_active_c3_SCCS_AntiPinch_SM_ == 0U) {
    SCCS_AntiPinch_SM_03_DW.is_active_c3_SCCS_AntiPinch_SM_ = 1U;
    SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
      SCCS_AntiPinch_SM_03_IN_IDLE;

    /* Outport: '<Root>/Motor_Voltage' */
    SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 0.0;

    /* Outport: '<Root>/Pinch_Detected' */
    SCCS_AntiPinch_SM_03_Y.Pinch_Detected = 0.0;

    /* Outport: '<Root>/Door_State' */
    SCCS_AntiPinch_SM_03_Y.Door_State = 1.0;
  } else {
    switch (SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03) {
     case SCCS_AntiPinch_SM_03_IN_CLOSING:
      /* Outport: '<Root>/Motor_Voltage' */
      SCCS_AntiPinch_SM_03_Y.Motor_Voltage = -10.0;

      /* Outport: '<Root>/Door_State' */
      SCCS_AntiPinch_SM_03_Y.Door_State = 3.0;
      if (SCCS_AntiPinch_SM_03_U.Motor_Current > 8.0) {
        SCCS_AntiPinch_SM_03_DW.temporalCounter_i1 = 0U;
        SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
          SCCS_AntiPinc_IN_PINCH_DETECTED;

        /* Outport: '<Root>/Motor_Voltage' */
        SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 0.0;

        /* Outport: '<Root>/Pinch_Detected' */
        SCCS_AntiPinch_SM_03_Y.Pinch_Detected = 1.0;

        /* Outport: '<Root>/Door_State' */
        SCCS_AntiPinch_SM_03_Y.Door_State = 4.0;
      } else if ((SCCS_AntiPinch_SM_03_U.Door_Position <= 0.0) ||
                 (SCCS_AntiPinch_SM_03_U.Close_Command == 0.0)) {
        SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
          SCCS_AntiPinch_SM_03_IN_IDLE;

        /* Outport: '<Root>/Motor_Voltage' */
        SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 0.0;

        /* Outport: '<Root>/Pinch_Detected' */
        SCCS_AntiPinch_SM_03_Y.Pinch_Detected = 0.0;

        /* Outport: '<Root>/Door_State' */
        SCCS_AntiPinch_SM_03_Y.Door_State = 1.0;
      }
      break;

     case SCCS_AntiPinch_SM_03_IN_IDLE:
      /* Outport: '<Root>/Motor_Voltage' */
      SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 0.0;

      /* Outport: '<Root>/Pinch_Detected' */
      SCCS_AntiPinch_SM_03_Y.Pinch_Detected = 0.0;

      /* Outport: '<Root>/Door_State' */
      SCCS_AntiPinch_SM_03_Y.Door_State = 1.0;
      if (SCCS_AntiPinch_SM_03_U.Open_Command == 1.0) {
        SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
          SCCS_AntiPinch_SM_03_IN_OPENING;

        /* Outport: '<Root>/Motor_Voltage' */
        SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 10.0;

        /* Outport: '<Root>/Door_State' */
        SCCS_AntiPinch_SM_03_Y.Door_State = 2.0;
      } else if (SCCS_AntiPinch_SM_03_U.Close_Command == 1.0) {
        SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
          SCCS_AntiPinch_SM_03_IN_CLOSING;

        /* Outport: '<Root>/Motor_Voltage' */
        SCCS_AntiPinch_SM_03_Y.Motor_Voltage = -10.0;

        /* Outport: '<Root>/Door_State' */
        SCCS_AntiPinch_SM_03_Y.Door_State = 3.0;
      }
      break;

     case SCCS_AntiPinch_SM_03_IN_OPENING:
      /* Outport: '<Root>/Motor_Voltage' */
      SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 10.0;

      /* Outport: '<Root>/Door_State' */
      SCCS_AntiPinch_SM_03_Y.Door_State = 2.0;
      if ((SCCS_AntiPinch_SM_03_U.Door_Position >= 400.0) ||
          (SCCS_AntiPinch_SM_03_U.Open_Command == 0.0)) {
        SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
          SCCS_AntiPinch_SM_03_IN_IDLE;

        /* Outport: '<Root>/Motor_Voltage' */
        SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 0.0;

        /* Outport: '<Root>/Pinch_Detected' */
        SCCS_AntiPinch_SM_03_Y.Pinch_Detected = 0.0;

        /* Outport: '<Root>/Door_State' */
        SCCS_AntiPinch_SM_03_Y.Door_State = 1.0;
      }
      break;

     case SCCS_AntiPinc_IN_PINCH_DETECTED:
      /* Outport: '<Root>/Motor_Voltage' */
      SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 0.0;

      /* Outport: '<Root>/Pinch_Detected' */
      SCCS_AntiPinch_SM_03_Y.Pinch_Detected = 1.0;

      /* Outport: '<Root>/Door_State' */
      SCCS_AntiPinch_SM_03_Y.Door_State = 4.0;
      if (SCCS_AntiPinch_SM_03_DW.temporalCounter_i1 >= 10U) {
        SCCS_AntiPinch_SM_03_DW.temporalCounter_i1 = 0U;
        SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
          SCCS_AntiPinch_SM__IN_REVERSING;

        /* Outport: '<Root>/Motor_Voltage' */
        SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 10.0;

        /* Outport: '<Root>/Door_State' */
        SCCS_AntiPinch_SM_03_Y.Door_State = 5.0;
      }
      break;

     default:
      /* Outport: '<Root>/Motor_Voltage' */
      /* case IN_REVERSING: */
      SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 10.0;

      /* Outport: '<Root>/Door_State' */
      SCCS_AntiPinch_SM_03_Y.Door_State = 5.0;
      if (SCCS_AntiPinch_SM_03_DW.temporalCounter_i1 >= 50U) {
        SCCS_AntiPinch_SM_03_DW.is_c3_SCCS_AntiPinch_SM_03 =
          SCCS_AntiPinch_SM_03_IN_IDLE;

        /* Outport: '<Root>/Motor_Voltage' */
        SCCS_AntiPinch_SM_03_Y.Motor_Voltage = 0.0;

        /* Outport: '<Root>/Pinch_Detected' */
        SCCS_AntiPinch_SM_03_Y.Pinch_Detected = 0.0;

        /* Outport: '<Root>/Door_State' */
        SCCS_AntiPinch_SM_03_Y.Door_State = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void SCCS_AntiPinch_SM_03_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void SCCS_AntiPinch_SM_03_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
