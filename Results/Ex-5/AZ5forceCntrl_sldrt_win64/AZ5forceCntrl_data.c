/*
 * AZ5forceCntrl_data.c
 *
 * Code generation for model "AZ5forceCntrl".
 *
 * Model version              : 1.28
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Sat May 27 10:39:26 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AZ5forceCntrl.h"
#include "AZ5forceCntrl_private.h"

/* Block parameters (auto storage) */
P_AZ5forceCntrl_T AZ5forceCntrl_P = {
  1.0E+7,                              /* Mask Parameter: PacketOutput1_MaxMissedTicks
                                        * Referenced by: '<S2>/Packet Output1'
                                        */
  1.0E+6,                              /* Mask Parameter: PacketInput1_MaxMissedTicks
                                        * Referenced by: '<S2>/Packet Input1'
                                        */
  0.0,                                 /* Mask Parameter: PacketOutput1_YieldWhenWaiting
                                        * Referenced by: '<S2>/Packet Output1'
                                        */
  0.0,                                 /* Mask Parameter: PacketInput1_YieldWhenWaiting
                                        * Referenced by: '<S2>/Packet Input1'
                                        */
  1,                                   /* Mask Parameter: PacketOutput1_PacketID
                                        * Referenced by: '<S2>/Packet Output1'
                                        */
  1,                                   /* Mask Parameter: PacketInput1_PacketID
                                        * Referenced by: '<S2>/Packet Input1'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/orsel'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S7>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S8>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  84000.0,                             /* Expression: 84000
                                        * Referenced by: '<S3>/c4'
                                        */
  840000.0,                            /* Expression: 840000
                                        * Referenced by: '<S3>/c5'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<Root>/zero1'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<Root>/0.05kg 5s 50%'
                                        */
  2.0,                                 /* Computed Parameter: u05kg5s50_Period
                                        * Referenced by: '<Root>/0.05kg 5s 50%'
                                        */
  1.0,                                 /* Computed Parameter: u05kg5s50_Duty
                                        * Referenced by: '<Root>/0.05kg 5s 50%'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/0.05kg 5s 50%'
                                        */
  -10.0,                               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  10.0,                                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/select'
                                        */
  4095.0,                              /* Expression: 4095
                                        * Referenced by: '<S1>/Constant13'
                                        */
  2.5,                                 /* Expression: vr
                                        * Referenced by: '<S1>/Vref'
                                        */
  8.0,                                 /* Expression: 8
                                        * Referenced by: '<S1>/Constant17'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Constant20'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  0.16,                                /* Expression: 0.16
                                        * Referenced by: '<Root>/zero2'
                                        */
  -1.0,                                /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  80.0,                                /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  400.0,                               /* Expression: 400
                                        * Referenced by: '<Root>/Gain1'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/zero'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<Root>/0..90'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/0..90'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Analog1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S7>/Analog1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S7>/Analog2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S7>/Analog3'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/f'
                                        */
  84000.0,                             /* Expression: 84000
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  256.0,                               /* Expression: 256
                                        * Referenced by: '<S5>/Constant11'
                                        */
  256U,                                /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S1>/Constant10'
                                        */
  256U,                                /* Computed Parameter: Constant11_Value_a
                                        * Referenced by: '<S6>/Constant11'
                                        */
  65535U,                              /* Computed Parameter: Saturation_UpperSat_o
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0U,                                  /* Computed Parameter: Saturation_LowerSat_n
                                        * Referenced by: '<S3>/Saturation'
                                        */
  2U,                                  /* Computed Parameter: en1_Value
                                        * Referenced by: '<S4>/en1'
                                        */
  4U,                                  /* Computed Parameter: en2_Value
                                        * Referenced by: '<S4>/en2'
                                        */
  0U,                                  /* Computed Parameter: ARR_S_Value
                                        * Referenced by: '<S3>/ARR_S'
                                        */
  8U,                                  /* Computed Parameter: en3_Value
                                        * Referenced by: '<S4>/en3'
                                        */
  7U,                                  /* Computed Parameter: en_Value
                                        * Referenced by: '<S4>/en'
                                        */
  15U,                                 /* Computed Parameter: CH_Value
                                        * Referenced by: '<S1>/CH'
                                        */
  1U,                                  /* Computed Parameter: Constant21_Value
                                        * Referenced by: '<S1>/Constant21'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U,                                  /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S3>/Switch2'
                                        */
  0U                                   /* Computed Parameter: Switch1_Threshold_j
                                        * Referenced by: '<S3>/Switch1'
                                        */
};
