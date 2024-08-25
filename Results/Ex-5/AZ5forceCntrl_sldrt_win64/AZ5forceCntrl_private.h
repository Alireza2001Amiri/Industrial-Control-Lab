/*
 * AZ5forceCntrl_private.h
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

#ifndef RTW_HEADER_AZ5forceCntrl_private_h_
#define RTW_HEADER_AZ5forceCntrl_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);

/* private model entry point functions */
extern void AZ5forceCntrl_derivatives(void);

#endif                                 /* RTW_HEADER_AZ5forceCntrl_private_h_ */
