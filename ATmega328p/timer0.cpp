#include "timer0.h"
#include <avr/io.h>

#define TCCR0A_WGM_MASK ((1<<WGM01) | (1<<WGM00))
#define TCCR0A_OC0A_MASK ((1<<COM0A1) | (1<<COM0A0))
#define TCCR0A_OC0B_MASK ((1<<COM0B1) | (1<<COM0B0))
#define TCCR0B_WGM_MASK (1<<WGM02)
#define TCCR0B_CLOCK_MASK ((1<<CS02) | (1<<CS01) | (1<<CS00))

void Timer0_setWaveform(Timer0Waveform waveform)
{
  uint8_t registerTempA = TCCR0A & (~TCCR0A_WGM_MASK);
  uint8_t registerTempB = TCCR0B & (~TCCR0B_WGM_MASK);
  switch(waveform)
  {
    case Timer0Waveform_Normal_MaxTop:
      registerTempA |= (0<<WGM01) | (0<<WGM00);
      registerTempB |= (0<<WGM02);
      break;
    case Timer0Waveform_PWMPhaseCorrect_MaxTop:
      registerTempA |= (0<<WGM01) | (1<<WGM00);
      registerTempB |= (0<<WGM02);
      break;
    case Timer0Waveform_CTC_OCRATop:
      registerTempA |= (1<<WGM01) | (0<<WGM00);
      registerTempB |= (0<<WGM02);
      break;
    case Timer0Waveform_FastPWM_MaxTop:
      registerTempA |= (1<<WGM01) | (1<<WGM00);
      registerTempB |= (0<<WGM02);
      break;
    case Timer0Waveform_PWMPhaseCorrect_OCRATop:
      registerTempA |= (0<<WGM01) | (1<<WGM00);
      registerTempB |= (1<<WGM02);
      break;
    case Timer0Waveform_FastPWM_OCRATop:
      registerTempA |= (1<<WGM01) | (1<<WGM00);
      registerTempB |= (1<<WGM02);
      break;
    default:
      return;
  }
  TCCR0A = registerTempA;
  TCCR0B = registerTempB;
}

void Timer0_setClock(Timer0ClockSource source)
{
  uint8_t registerTempB = TCCR0B & (~TCCR0B_CLOCK_MASK);
  switch(source)
  {
    case Timer0ClockSource_off:
      registerTempB |= (0<<CS02) | (0<<CS01) | (0<<CS00);
      break;
    case Timer0ClockSource_div1:
      registerTempB |= (0<<CS02) | (0<<CS01) | (1<<CS00);
      break;
    case Timer0ClockSource_div8:
      registerTempB |= (0<<CS02) | (1<<CS01) | (0<<CS00);
      break;
    case Timer0ClockSource_div64:
      registerTempB |= (0<<CS02) | (1<<CS01) | (1<<CS00);
      break;
    case Timer0ClockSource_div256:
      registerTempB |= (1<<CS02) | (0<<CS01) | (0<<CS00);
      break;
    case Timer0ClockSource_div1024:
      registerTempB |= (1<<CS02) | (0<<CS01) | (1<<CS00);
      break;
    case Timer0ClockSource_T0Falling:
      registerTempB |= (1<<CS02) | (1<<CS01) | (0<<CS00);
      break;
    case Timer0ClockSource_T0Rising:
      registerTempB |= (1<<CS02) | (1<<CS01) | (1<<CS00);
      break;
    default:
      return;
  }
  TCCR0B = registerTempB;
}

void Timer0_setOC0AMode(Timer0OC0AMode mode)
{
  uint8_t registerTempA = TCCR0A & (~TCCR0A_OC0A_MASK);
  switch(mode)
  {
    case Timer0OC0AMode_normal:
      registerTempA |= (0<<COM0A1) | (0<<COM0A0);
      break;
    case Timer0OC0AMode_toggle:
      registerTempA |= (0<<COM0A1) | (1<<COM0A0);
      break;
    case Timer0OC0AMode_noninverting:
      registerTempA |= (1<<COM0A1) | (0<<COM0A0);
      break;
    case Timer0OC0AMode_inverting:
      registerTempA |= (1<<COM0A1) | (1<<COM0A0);
      break;
    default:
      return;
  }
  TCCR0A = registerTempA;
}

void Timer0_setOC0BMode(Timer0OC0BMode mode)
{
  uint8_t registerTempA = TCCR0A & (~TCCR0A_OC0B_MASK);
  switch(mode)
  {
    case Timer0OC0BMode_normal:
      registerTempA |= (0<<COM0B1) | (0<<COM0B0);
      break;
    case Timer0OC0BMode_toggle:
      registerTempA |= (0<<COM0B1) | (1<<COM0B0);
      break;
    case Timer0OC0BMode_noninverting:
      registerTempA |= (1<<COM0B1) | (0<<COM0B0);
      break;
    case Timer0OC0BMode_inverting:
      registerTempA |= (1<<COM0B1) | (1<<COM0B0);
      break;
    default:
      return;
  }
  TCCR0A = registerTempA;
}

void Timer0_setCompareA(uint8_t compare)
{
  OCR0A = compare;
}

void Timer0_setCompareB(uint8_t compare)
{
  OCR0B = compare;
}
