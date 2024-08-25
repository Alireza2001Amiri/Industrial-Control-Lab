/*
 * AZ5forceCntrl.c
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
#include "AZ5forceCntrl_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  9600.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.005, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 3U, 8, SLDRTBoardOptions0 },
};

/* Block signals (auto storage) */
B_AZ5forceCntrl_T AZ5forceCntrl_B;

/* Continuous states */
X_AZ5forceCntrl_T AZ5forceCntrl_X;

/* Block states (auto storage) */
DW_AZ5forceCntrl_T AZ5forceCntrl_DW;

/* Real-time model */
RT_MODEL_AZ5forceCntrl_T AZ5forceCntrl_M_;
RT_MODEL_AZ5forceCntrl_T *const AZ5forceCntrl_M = &AZ5forceCntrl_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (AZ5forceCntrl_M->Timing.TaskCounters.TID[2])++;
  if ((AZ5forceCntrl_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.5s, 0.0s] */
    AZ5forceCntrl_M->Timing.TaskCounters.TID[2] = 0;
  }

  AZ5forceCntrl_M->Timing.sampleHits[2] =
    (AZ5forceCntrl_M->Timing.TaskCounters.TID[2] == 0);
  (AZ5forceCntrl_M->Timing.TaskCounters.TID[3])++;
  if ((AZ5forceCntrl_M->Timing.TaskCounters.TID[3]) > 199) {/* Sample time: [1.0s, 0.0s] */
    AZ5forceCntrl_M->Timing.TaskCounters.TID[3] = 0;
  }

  AZ5forceCntrl_M->Timing.sampleHits[3] =
    (AZ5forceCntrl_M->Timing.TaskCounters.TID[3] == 0);
  (AZ5forceCntrl_M->Timing.TaskCounters.TID[4])++;
  if ((AZ5forceCntrl_M->Timing.TaskCounters.TID[4]) > 499) {/* Sample time: [2.5s, 0.0s] */
    AZ5forceCntrl_M->Timing.TaskCounters.TID[4] = 0;
  }

  AZ5forceCntrl_M->Timing.sampleHits[4] =
    (AZ5forceCntrl_M->Timing.TaskCounters.TID[4] == 0);
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  AZ5forceCntrl_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  AZ5forceCntrl_output();
  AZ5forceCntrl_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  AZ5forceCntrl_output();
  AZ5forceCntrl_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
  }

  return y;
}

/* Model output function */
void AZ5forceCntrl_output(void)
{
  uint8_T rtb_SUMUP[31];
  uint16_T rtb_MathFunction_k;
  real_T rtb_Add1;
  real_T tmp;
  if (rtmIsMajorTimeStep(AZ5forceCntrl_M)) {
    /* set solver stop time */
    if (!(AZ5forceCntrl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&AZ5forceCntrl_M->solverInfo,
                            ((AZ5forceCntrl_M->Timing.clockTickH0 + 1) *
        AZ5forceCntrl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&AZ5forceCntrl_M->solverInfo,
                            ((AZ5forceCntrl_M->Timing.clockTick0 + 1) *
        AZ5forceCntrl_M->Timing.stepSize0 + AZ5forceCntrl_M->Timing.clockTickH0 *
        AZ5forceCntrl_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(AZ5forceCntrl_M)) {
    AZ5forceCntrl_M->Timing.t[0] = rtsiGetT(&AZ5forceCntrl_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function Block: <S2>/Packet Output1 */

    /* no code required */

    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S3>/ARR_S'
     *  Constant: '<S4>/en3'
     *  Product: '<S4>/Product3'
     */
    AZ5forceCntrl_B.Add = (uint8_T)((uint32_T)AZ5forceCntrl_P.ARR_S_Value *
      AZ5forceCntrl_P.en3_Value);

    /* S-Function Block: <S2>/Packet Input1 */
    {
      uint8_T indata[33U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 33U,
        &AZ5forceCntrl_P.PacketInput1_PacketID, (double*) indata, NULL);
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;

        {
          int_T i1;
          uint8_T *y0 = &AZ5forceCntrl_B.PacketInput1[0];
          for (i1=0; i1 < 33; i1++) {
            y0[i1] = *indp.p_uint8_T++;
          }
        }
      }
    }

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn1' */
    rtb_SUMUP[15] = AZ5forceCntrl_B.PacketInput1[15];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn2' */
    rtb_SUMUP[16] = AZ5forceCntrl_B.PacketInput1[16];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn3' */
    rtb_SUMUP[17] = AZ5forceCntrl_B.PacketInput1[17];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn4' */
    rtb_SUMUP[18] = AZ5forceCntrl_B.PacketInput1[18];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn5' */
    rtb_SUMUP[19] = AZ5forceCntrl_B.PacketInput1[19];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn6' */
    rtb_SUMUP[20] = AZ5forceCntrl_B.PacketInput1[20];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn7' */
    rtb_SUMUP[21] = AZ5forceCntrl_B.PacketInput1[21];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn8' */
    rtb_SUMUP[22] = AZ5forceCntrl_B.PacketInput1[22];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn9' */
    rtb_SUMUP[23] = AZ5forceCntrl_B.PacketInput1[23];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn10' */
    rtb_SUMUP[24] = AZ5forceCntrl_B.PacketInput1[24];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn11' */
    rtb_SUMUP[25] = AZ5forceCntrl_B.PacketInput1[25];

    /* SignalConversion: '<S4>/ConcatBufferAtADCIn12' */
    rtb_SUMUP[26] = AZ5forceCntrl_B.PacketInput1[26];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn1' */
    rtb_SUMUP[1] = AZ5forceCntrl_B.PacketInput1[1];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn10' */
    rtb_SUMUP[10] = AZ5forceCntrl_B.PacketInput1[10];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn11' */
    rtb_SUMUP[11] = AZ5forceCntrl_B.PacketInput1[11];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn12' */
    rtb_SUMUP[12] = AZ5forceCntrl_B.PacketInput1[12];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn13' */
    rtb_SUMUP[13] = AZ5forceCntrl_B.PacketInput1[13];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn14' */
    rtb_SUMUP[14] = AZ5forceCntrl_B.PacketInput1[14];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn2' */
    rtb_SUMUP[2] = AZ5forceCntrl_B.PacketInput1[2];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn3' */
    rtb_SUMUP[3] = AZ5forceCntrl_B.PacketInput1[3];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn4' */
    rtb_SUMUP[4] = AZ5forceCntrl_B.PacketInput1[4];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn5' */
    rtb_SUMUP[5] = AZ5forceCntrl_B.PacketInput1[5];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn6' */
    rtb_SUMUP[6] = AZ5forceCntrl_B.PacketInput1[6];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn7' */
    rtb_SUMUP[7] = AZ5forceCntrl_B.PacketInput1[7];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn8' */
    rtb_SUMUP[8] = AZ5forceCntrl_B.PacketInput1[8];

    /* SignalConversion: '<S4>/ConcatBufferAtENCODER INPUTIn9' */
    rtb_SUMUP[9] = AZ5forceCntrl_B.PacketInput1[9];

    /* SignalConversion: '<S4>/ConcatBufferAtICIn1' */
    rtb_SUMUP[29] = AZ5forceCntrl_B.PacketInput1[29];

    /* SignalConversion: '<S4>/ConcatBufferAtICIn2' */
    rtb_SUMUP[30] = AZ5forceCntrl_B.PacketInput1[30];

    /* SignalConversion: '<S4>/ConcatBufferAtSUMUPIn1' */
    rtb_SUMUP[0] = AZ5forceCntrl_B.PacketInput1[0];

    /* SignalConversion: '<S4>/ConcatBufferAtSUMUPIn4' */
    rtb_SUMUP[27] = AZ5forceCntrl_B.PacketInput1[27];

    /* SignalConversion: '<S4>/ConcatBufferAtSUMUPIn5' */
    rtb_SUMUP[28] = AZ5forceCntrl_B.PacketInput1[28];
  }

  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[4] == 0) {
    /* DiscretePulseGenerator: '<Root>/0.05kg 5s 50%' */
    AZ5forceCntrl_B.u05kg5s50 = (AZ5forceCntrl_DW.clockTickCounter <
      AZ5forceCntrl_P.u05kg5s50_Duty) && (AZ5forceCntrl_DW.clockTickCounter >= 0)
      ? AZ5forceCntrl_P.u05kg5s50_Amp : 0.0;
    if (AZ5forceCntrl_DW.clockTickCounter >= AZ5forceCntrl_P.u05kg5s50_Period -
        1.0) {
      AZ5forceCntrl_DW.clockTickCounter = 0;
    } else {
      AZ5forceCntrl_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/0.05kg 5s 50%' */
  }

  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/zero1'
     */
    AZ5forceCntrl_B.Sum3 = AZ5forceCntrl_P.zero1_Value +
      AZ5forceCntrl_B.u05kg5s50;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  AZ5forceCntrl_B.TransferFcn = 0.0;
  AZ5forceCntrl_B.TransferFcn += AZ5forceCntrl_P.TransferFcn_C *
    AZ5forceCntrl_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[1] == 0) {
    /* MultiPortSwitch: '<S1>/Index Vector' incorporates:
     *  Constant: '<S1>/CH'
     */
    AZ5forceCntrl_B.IndexVector = rtb_SUMUP[AZ5forceCntrl_P.CH_Value];

    /* MultiPortSwitch: '<S1>/Index Vector1' incorporates:
     *  Constant: '<S1>/CH'
     *  Constant: '<S1>/Constant21'
     *  Sum: '<S1>/Add2'
     */
    AZ5forceCntrl_B.IndexVector1 = rtb_SUMUP[(uint8_T)((uint32_T)
      AZ5forceCntrl_P.CH_Value + AZ5forceCntrl_P.Constant21_Value)];

    /* Sum: '<S1>/Add' incorporates:
     *  Constant: '<S1>/Constant10'
     *  Product: '<S1>/Product'
     */
    rtb_MathFunction_k = (uint16_T)((uint32_T)(uint16_T)((uint32_T)
      AZ5forceCntrl_B.IndexVector * AZ5forceCntrl_P.Constant10_Value) +
      AZ5forceCntrl_B.IndexVector1);

    /* Sum: '<S1>/Add1' incorporates:
     *  Constant: '<S1>/Constant13'
     *  Constant: '<S1>/Constant17'
     *  Constant: '<S1>/Constant20'
     *  Constant: '<S1>/Vref'
     *  Product: '<S1>/Divide'
     *  Product: '<S1>/Product1'
     *  Product: '<S1>/Product2'
     */
    rtb_Add1 = (real_T)rtb_MathFunction_k / AZ5forceCntrl_P.Constant13_Value *
      AZ5forceCntrl_P.Vref_Value * AZ5forceCntrl_P.Constant17_Value -
      AZ5forceCntrl_P.Constant20_Value;

    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/orsel'
     *  Constant: '<S1>/select'
     *  Saturate: '<S1>/Saturation3'
     *  Switch: '<S1>/Switch1'
     */
    if (AZ5forceCntrl_P.select_Value > AZ5forceCntrl_P.Switch_Threshold) {
      rtb_Add1 = rtb_MathFunction_k;
    } else if (AZ5forceCntrl_P.orsel_Value > AZ5forceCntrl_P.Switch1_Threshold)
    {
      /* Saturate: '<S1>/Saturation1' incorporates:
       *  Switch: '<S1>/Switch1'
       */
      if (rtb_Add1 > AZ5forceCntrl_P.Saturation1_UpperSat) {
        rtb_Add1 = AZ5forceCntrl_P.Saturation1_UpperSat;
      } else {
        if (rtb_Add1 < AZ5forceCntrl_P.Saturation1_LowerSat) {
          rtb_Add1 = AZ5forceCntrl_P.Saturation1_LowerSat;
        }
      }

      /* End of Saturate: '<S1>/Saturation1' */
    } else if (rtb_Add1 > AZ5forceCntrl_P.Saturation3_UpperSat) {
      /* Saturate: '<S1>/Saturation3' incorporates:
       *  Switch: '<S1>/Switch1'
       */
      rtb_Add1 = AZ5forceCntrl_P.Saturation3_UpperSat;
    } else {
      if (rtb_Add1 < AZ5forceCntrl_P.Saturation3_LowerSat) {
        /* Saturate: '<S1>/Saturation3' incorporates:
         *  Switch: '<S1>/Switch1'
         */
        rtb_Add1 = AZ5forceCntrl_P.Saturation3_LowerSat;
      }
    }

    /* End of Switch: '<S1>/Switch' */

    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<Root>/zero2'
     */
    AZ5forceCntrl_B.Sum4 = rtb_Add1 + AZ5forceCntrl_P.zero2_Value;
  }

  /* Sum: '<Root>/Sum1' */
  AZ5forceCntrl_B.Sum1 = AZ5forceCntrl_B.Sum3 - AZ5forceCntrl_B.TransferFcn;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  rtb_Add1 = AZ5forceCntrl_P.TransferFcn1_C *
    AZ5forceCntrl_X.TransferFcn1_CSTATE;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (AZ5forceCntrl_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Add1 = AZ5forceCntrl_B.Sum3;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/zero'
   *  Gain: '<Root>/Gain1'
   */
  rtb_Add1 = AZ5forceCntrl_P.Gain1_Gain * rtb_Add1 + AZ5forceCntrl_P.zero_Value;

  /* Saturate: '<Root>/0..90' */
  if (rtb_Add1 > AZ5forceCntrl_P.u90_UpperSat) {
    AZ5forceCntrl_B.u90 = AZ5forceCntrl_P.u90_UpperSat;
  } else if (rtb_Add1 < AZ5forceCntrl_P.u90_LowerSat) {
    AZ5forceCntrl_B.u90 = AZ5forceCntrl_P.u90_LowerSat;
  } else {
    AZ5forceCntrl_B.u90 = rtb_Add1;
  }

  /* End of Saturate: '<Root>/0..90' */

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S3>/ARR_S'
   *  Constant: '<S7>/Analog1'
   *  Constant: '<S7>/Analog2'
   *  Constant: '<S7>/Analog3'
   *  Constant: '<S8>/Analog1'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product2'
   *  Product: '<S8>/Product'
   *  Rounding: '<S7>/Rounding Function'
   *  Rounding: '<S8>/Rounding Function'
   *  Saturate: '<S7>/Saturation'
   */
  if (AZ5forceCntrl_P.ARR_S_Value > AZ5forceCntrl_P.Switch2_Threshold) {
    /* Saturate: '<S8>/Saturation' */
    if (AZ5forceCntrl_B.u90 > AZ5forceCntrl_P.Saturation_UpperSat_h) {
      rtb_Add1 = AZ5forceCntrl_P.Saturation_UpperSat_h;
    } else if (AZ5forceCntrl_B.u90 < AZ5forceCntrl_P.Saturation_LowerSat_h) {
      rtb_Add1 = AZ5forceCntrl_P.Saturation_LowerSat_h;
    } else {
      rtb_Add1 = AZ5forceCntrl_B.u90;
    }

    /* End of Saturate: '<S8>/Saturation' */
    AZ5forceCntrl_B.Switch2 = floor(rtb_Add1 * AZ5forceCntrl_P.Analog1_Value);
  } else {
    if (AZ5forceCntrl_B.u90 > AZ5forceCntrl_P.Saturation_UpperSat) {
      /* Saturate: '<S7>/Saturation' */
      rtb_Add1 = AZ5forceCntrl_P.Saturation_UpperSat;
    } else if (AZ5forceCntrl_B.u90 < AZ5forceCntrl_P.Saturation_LowerSat) {
      /* Saturate: '<S7>/Saturation' */
      rtb_Add1 = AZ5forceCntrl_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S7>/Saturation' */
      rtb_Add1 = AZ5forceCntrl_B.u90;
    }

    AZ5forceCntrl_B.Switch2 = floor(rtb_Add1 * AZ5forceCntrl_P.Analog1_Value_j) *
      AZ5forceCntrl_P.Analog2_Value * AZ5forceCntrl_P.Analog3_Value;
  }

  /* End of Switch: '<S3>/Switch2' */
  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/ARR_S'
     *  Constant: '<S3>/c4'
     *  Constant: '<S3>/c5'
     */
    if (AZ5forceCntrl_P.ARR_S_Value > AZ5forceCntrl_P.Switch1_Threshold_j) {
      rtb_Add1 = AZ5forceCntrl_P.c5_Value;
    } else {
      rtb_Add1 = AZ5forceCntrl_P.c4_Value;
    }

    /* End of Switch: '<S3>/Switch1' */

    /* Saturate: '<S3>/Saturation1' incorporates:
     *  Constant: '<Root>/f'
     */
    if (AZ5forceCntrl_P.f_Value > AZ5forceCntrl_P.Saturation1_UpperSat_k) {
      tmp = AZ5forceCntrl_P.Saturation1_UpperSat_k;
    } else if (AZ5forceCntrl_P.f_Value < AZ5forceCntrl_P.Saturation1_LowerSat_g)
    {
      tmp = AZ5forceCntrl_P.Saturation1_LowerSat_g;
    } else {
      tmp = AZ5forceCntrl_P.f_Value;
    }

    /* End of Saturate: '<S3>/Saturation1' */

    /* Rounding: '<S3>/Rounding Function' incorporates:
     *  Product: '<S3>/Divide'
     */
    AZ5forceCntrl_B.RoundingFunction = floor(rtb_Add1 / tmp);
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<S5>/Constant11'
   *  Product: '<S5>/Divide1'
   */
  rtb_Add1 = floor(AZ5forceCntrl_B.Switch2 / AZ5forceCntrl_P.Constant11_Value);
  if (rtIsNaN(rtb_Add1) || rtIsInf(rtb_Add1)) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = fmod(rtb_Add1, 256.0);
  }

  AZ5forceCntrl_B.DataTypeConversion = (uint8_T)(rtb_Add1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_Add1 : (int32_T)(uint8_T)rtb_Add1);

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  Constant: '<S5>/Constant11'
   *  Math: '<S5>/Math Function'
   */
  rtb_Add1 = floor(rt_modd_snf(AZ5forceCntrl_B.Switch2,
    AZ5forceCntrl_P.Constant11_Value));
  if (rtIsNaN(rtb_Add1) || rtIsInf(rtb_Add1)) {
    rtb_Add1 = 0.0;
  } else {
    rtb_Add1 = fmod(rtb_Add1, 256.0);
  }

  AZ5forceCntrl_B.DataTypeConversion1 = (uint8_T)(rtb_Add1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_Add1 : (int32_T)(uint8_T)rtb_Add1);

  /* End of DataTypeConversion: '<S5>/Data Type Conversion1' */
  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[1] == 0) {
    /* Saturate: '<S3>/Saturation' */
    if (AZ5forceCntrl_B.RoundingFunction > AZ5forceCntrl_P.Saturation_UpperSat_o)
    {
      rtb_Add1 = AZ5forceCntrl_P.Saturation_UpperSat_o;
    } else if (AZ5forceCntrl_B.RoundingFunction <
               AZ5forceCntrl_P.Saturation_LowerSat_n) {
      rtb_Add1 = AZ5forceCntrl_P.Saturation_LowerSat_n;
    } else {
      rtb_Add1 = AZ5forceCntrl_B.RoundingFunction;
    }

    rtb_Add1 = floor(rtb_Add1);
    if (rtIsNaN(rtb_Add1) || rtIsInf(rtb_Add1)) {
      rtb_MathFunction_k = 0U;
    } else {
      rtb_MathFunction_k = (uint16_T)fmod(rtb_Add1, 65536.0);
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Constant: '<S6>/Constant11'
     *  Product: '<S6>/Divide1'
     */
    AZ5forceCntrl_B.DataTypeConversion_f = (uint8_T)
      (AZ5forceCntrl_P.Constant11_Value_a == 0U ? MAX_uint32_T : (uint32_T)
       rtb_MathFunction_k / AZ5forceCntrl_P.Constant11_Value_a);

    /* Math: '<S6>/Math Function' incorporates:
     *  Constant: '<S6>/Constant11'
     */
    if (AZ5forceCntrl_P.Constant11_Value_a != 0) {
      rtb_MathFunction_k %= AZ5forceCntrl_P.Constant11_Value_a;
    }

    /* End of Math: '<S6>/Math Function' */

    /* DataTypeConversion: '<S6>/Data Type Conversion1' */
    AZ5forceCntrl_B.DataTypeConversion1_l = (uint8_T)rtb_MathFunction_k;
  }
}

/* Model update function */
void AZ5forceCntrl_update(void)
{
  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function Block: <S2>/Packet Output1 */
    {
      uint8_T outdata[31U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        uint8_T pktout = AZ5forceCntrl_P.en_Value;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = AZ5forceCntrl_B.Add;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = AZ5forceCntrl_B.DataTypeConversion;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = AZ5forceCntrl_B.DataTypeConversion1;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = AZ5forceCntrl_B.DataTypeConversion_f;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = AZ5forceCntrl_B.DataTypeConversion1_l;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = ((uint8_T)0U);
        *outdp.p_uint8_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 31U,
                     &AZ5forceCntrl_P.PacketOutput1_PacketID, (double*) outdata,
                     NULL);
    }
  }

  if (rtmIsMajorTimeStep(AZ5forceCntrl_M)) {
    rt_ertODEUpdateContinuousStates(&AZ5forceCntrl_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++AZ5forceCntrl_M->Timing.clockTick0)) {
    ++AZ5forceCntrl_M->Timing.clockTickH0;
  }

  AZ5forceCntrl_M->Timing.t[0] = rtsiGetSolverStopTime
    (&AZ5forceCntrl_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++AZ5forceCntrl_M->Timing.clockTick1)) {
      ++AZ5forceCntrl_M->Timing.clockTickH1;
    }

    AZ5forceCntrl_M->Timing.t[1] = AZ5forceCntrl_M->Timing.clockTick1 *
      AZ5forceCntrl_M->Timing.stepSize1 + AZ5forceCntrl_M->Timing.clockTickH1 *
      AZ5forceCntrl_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.5s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++AZ5forceCntrl_M->Timing.clockTick2)) {
      ++AZ5forceCntrl_M->Timing.clockTickH2;
    }

    AZ5forceCntrl_M->Timing.t[2] = AZ5forceCntrl_M->Timing.clockTick2 *
      AZ5forceCntrl_M->Timing.stepSize2 + AZ5forceCntrl_M->Timing.clockTickH2 *
      AZ5forceCntrl_M->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++AZ5forceCntrl_M->Timing.clockTick3)) {
      ++AZ5forceCntrl_M->Timing.clockTickH3;
    }

    AZ5forceCntrl_M->Timing.t[3] = AZ5forceCntrl_M->Timing.clockTick3 *
      AZ5forceCntrl_M->Timing.stepSize3 + AZ5forceCntrl_M->Timing.clockTickH3 *
      AZ5forceCntrl_M->Timing.stepSize3 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(AZ5forceCntrl_M) &&
      AZ5forceCntrl_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update absolute timer for sample time: [2.5s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick4"
     * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick4 and the high bits
     * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++AZ5forceCntrl_M->Timing.clockTick4)) {
      ++AZ5forceCntrl_M->Timing.clockTickH4;
    }

    AZ5forceCntrl_M->Timing.t[4] = AZ5forceCntrl_M->Timing.clockTick4 *
      AZ5forceCntrl_M->Timing.stepSize4 + AZ5forceCntrl_M->Timing.clockTickH4 *
      AZ5forceCntrl_M->Timing.stepSize4 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void AZ5forceCntrl_derivatives(void)
{
  XDot_AZ5forceCntrl_T *_rtXdot;
  _rtXdot = ((XDot_AZ5forceCntrl_T *) AZ5forceCntrl_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += AZ5forceCntrl_P.TransferFcn_A *
    AZ5forceCntrl_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += AZ5forceCntrl_B.Sum4;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += AZ5forceCntrl_P.TransferFcn1_A *
    AZ5forceCntrl_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += AZ5forceCntrl_B.Sum1;
}

/* Model initialize function */
void AZ5forceCntrl_initialize(void)
{
  /* S-Function Block: <S2>/Packet Output1 */
  /* no initial value should be set */

  /* Start for DiscretePulseGenerator: '<Root>/0.05kg 5s 50%' */
  AZ5forceCntrl_DW.clockTickCounter = 0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  AZ5forceCntrl_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  AZ5forceCntrl_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void AZ5forceCntrl_terminate(void)
{
  /* S-Function Block: <S2>/Packet Output1 */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  AZ5forceCntrl_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  AZ5forceCntrl_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  AZ5forceCntrl_initialize();
}

void MdlTerminate(void)
{
  AZ5forceCntrl_terminate();
}

/* Registration function */
RT_MODEL_AZ5forceCntrl_T *AZ5forceCntrl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)AZ5forceCntrl_M, 0,
                sizeof(RT_MODEL_AZ5forceCntrl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&AZ5forceCntrl_M->solverInfo,
                          &AZ5forceCntrl_M->Timing.simTimeStep);
    rtsiSetTPtr(&AZ5forceCntrl_M->solverInfo, &rtmGetTPtr(AZ5forceCntrl_M));
    rtsiSetStepSizePtr(&AZ5forceCntrl_M->solverInfo,
                       &AZ5forceCntrl_M->Timing.stepSize0);
    rtsiSetdXPtr(&AZ5forceCntrl_M->solverInfo, &AZ5forceCntrl_M->derivs);
    rtsiSetContStatesPtr(&AZ5forceCntrl_M->solverInfo, (real_T **)
                         &AZ5forceCntrl_M->contStates);
    rtsiSetNumContStatesPtr(&AZ5forceCntrl_M->solverInfo,
      &AZ5forceCntrl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&AZ5forceCntrl_M->solverInfo,
      &AZ5forceCntrl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&AZ5forceCntrl_M->solverInfo,
      &AZ5forceCntrl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&AZ5forceCntrl_M->solverInfo,
      &AZ5forceCntrl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&AZ5forceCntrl_M->solverInfo, (&rtmGetErrorStatus
      (AZ5forceCntrl_M)));
    rtsiSetRTModelPtr(&AZ5forceCntrl_M->solverInfo, AZ5forceCntrl_M);
  }

  rtsiSetSimTimeStep(&AZ5forceCntrl_M->solverInfo, MAJOR_TIME_STEP);
  AZ5forceCntrl_M->intgData.y = AZ5forceCntrl_M->odeY;
  AZ5forceCntrl_M->intgData.f[0] = AZ5forceCntrl_M->odeF[0];
  AZ5forceCntrl_M->intgData.f[1] = AZ5forceCntrl_M->odeF[1];
  AZ5forceCntrl_M->intgData.f[2] = AZ5forceCntrl_M->odeF[2];
  AZ5forceCntrl_M->contStates = ((real_T *) &AZ5forceCntrl_X);
  rtsiSetSolverData(&AZ5forceCntrl_M->solverInfo, (void *)
                    &AZ5forceCntrl_M->intgData);
  rtsiSetSolverName(&AZ5forceCntrl_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = AZ5forceCntrl_M->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    AZ5forceCntrl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    AZ5forceCntrl_M->Timing.sampleTimes =
      (&AZ5forceCntrl_M->Timing.sampleTimesArray[0]);
    AZ5forceCntrl_M->Timing.offsetTimes =
      (&AZ5forceCntrl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    AZ5forceCntrl_M->Timing.sampleTimes[0] = (0.0);
    AZ5forceCntrl_M->Timing.sampleTimes[1] = (0.005);
    AZ5forceCntrl_M->Timing.sampleTimes[2] = (0.5);
    AZ5forceCntrl_M->Timing.sampleTimes[3] = (1.0);
    AZ5forceCntrl_M->Timing.sampleTimes[4] = (2.5);

    /* task offsets */
    AZ5forceCntrl_M->Timing.offsetTimes[0] = (0.0);
    AZ5forceCntrl_M->Timing.offsetTimes[1] = (0.0);
    AZ5forceCntrl_M->Timing.offsetTimes[2] = (0.0);
    AZ5forceCntrl_M->Timing.offsetTimes[3] = (0.0);
    AZ5forceCntrl_M->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(AZ5forceCntrl_M, &AZ5forceCntrl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = AZ5forceCntrl_M->Timing.sampleHitArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlSampleHits[i] = 1;
    }

    AZ5forceCntrl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(AZ5forceCntrl_M, 50.0);
  AZ5forceCntrl_M->Timing.stepSize0 = 0.005;
  AZ5forceCntrl_M->Timing.stepSize1 = 0.005;
  AZ5forceCntrl_M->Timing.stepSize2 = 0.5;
  AZ5forceCntrl_M->Timing.stepSize3 = 1.0;
  AZ5forceCntrl_M->Timing.stepSize4 = 2.5;

  /* External mode info */
  AZ5forceCntrl_M->Sizes.checksums[0] = (3544583764U);
  AZ5forceCntrl_M->Sizes.checksums[1] = (3175780881U);
  AZ5forceCntrl_M->Sizes.checksums[2] = (961125186U);
  AZ5forceCntrl_M->Sizes.checksums[3] = (4042304875U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    AZ5forceCntrl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AZ5forceCntrl_M->extModeInfo,
      &AZ5forceCntrl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AZ5forceCntrl_M->extModeInfo,
                        AZ5forceCntrl_M->Sizes.checksums);
    rteiSetTPtr(AZ5forceCntrl_M->extModeInfo, rtmGetTPtr(AZ5forceCntrl_M));
  }

  AZ5forceCntrl_M->solverInfoPtr = (&AZ5forceCntrl_M->solverInfo);
  AZ5forceCntrl_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&AZ5forceCntrl_M->solverInfo, 0.005);
  rtsiSetSolverMode(&AZ5forceCntrl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  AZ5forceCntrl_M->blockIO = ((void *) &AZ5forceCntrl_B);
  (void) memset(((void *) &AZ5forceCntrl_B), 0,
                sizeof(B_AZ5forceCntrl_T));

  /* parameters */
  AZ5forceCntrl_M->defaultParam = ((real_T *)&AZ5forceCntrl_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &AZ5forceCntrl_X;
    AZ5forceCntrl_M->contStates = (x);
    (void) memset((void *)&AZ5forceCntrl_X, 0,
                  sizeof(X_AZ5forceCntrl_T));
  }

  /* states (dwork) */
  AZ5forceCntrl_M->dwork = ((void *) &AZ5forceCntrl_DW);
  (void) memset((void *)&AZ5forceCntrl_DW, 0,
                sizeof(DW_AZ5forceCntrl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AZ5forceCntrl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  AZ5forceCntrl_M->Sizes.numContStates = (2);/* Number of continuous states */
  AZ5forceCntrl_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  AZ5forceCntrl_M->Sizes.numY = (0);   /* Number of model outputs */
  AZ5forceCntrl_M->Sizes.numU = (0);   /* Number of model inputs */
  AZ5forceCntrl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  AZ5forceCntrl_M->Sizes.numSampTimes = (5);/* Number of sample times */
  AZ5forceCntrl_M->Sizes.numBlocks = (127);/* Number of blocks */
  AZ5forceCntrl_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  AZ5forceCntrl_M->Sizes.numBlockPrms = (60);/* Sum of parameter "widths" */
  return AZ5forceCntrl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
