/*
 * AZ5forceCntrl_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&AZ5forceCntrl_B.u05kg5s50), 0, 0, 8 },

  { (char_T *)(&AZ5forceCntrl_B.Add), 3, 0, 40 }
  ,

  { (char_T *)(&AZ5forceCntrl_DW.PacketOutput1_PWORK[0]), 11, 0, 4 },

  { (char_T *)(&AZ5forceCntrl_DW.clockTickCounter), 6, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&AZ5forceCntrl_P.PacketOutput1_MaxMissedTicks), 0, 0, 4 },

  { (char_T *)(&AZ5forceCntrl_P.PacketOutput1_PacketID), 6, 0, 2 },

  { (char_T *)(&AZ5forceCntrl_P.Saturation3_UpperSat), 0, 0, 40 },

  { (char_T *)(&AZ5forceCntrl_P.Constant10_Value), 5, 0, 4 },

  { (char_T *)(&AZ5forceCntrl_P.en1_Value), 3, 0, 10 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] AZ5forceCntrl_dt.h */
