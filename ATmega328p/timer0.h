#include <inttypes.h>

#define TIMER0_OCA0_MODE_NORMAL       (0)
#define TIMER0_OCA0_MODE_TOGGLE       (1)
#define TIMER0_OCA0_MODE_NONINVERTING (2)
#define TIMER0_OCA0_MODE_INVERTING    (3)

#define TIMER0_OCB0_MODE_NORMAL       (0)
#define TIMER0_OCB0_MODE_TOGGLE       (1)
#define TIMER0_OCB0_MODE_NONINVERTING (2)
#define TIMER0_OCB0_MODE_INVERTING    (3)

typedef enum Timer0Waveform
{
  Timer0Waveform_Normal_MaxTop = 0,
  Timer0Waveform_PWMPhaseCorrect_MaxTop,
  Timer0Waveform_CTC_OCRATop,
  Timer0Waveform_FastPWM_MaxTop,
  Timer0Waveform_PWMPhaseCorrect_OCRATop = 5,
  Timer0Waveform_FastPWM_OCRATop = 7
};

typedef enum Timer0ClockSource
{
  Timer0ClockSource_off,
  Timer0ClockSource_div1,
  Timer0ClockSource_div8,
  Timer0ClockSource_div64,
  Timer0ClockSource_div256,
  Timer0ClockSource_div1024,
  Timer0ClockSource_T0Falling,
  Timer0ClockSource_T0Rising
};

typedef enum Timer0OC0AMode
{
  Timer0OC0AMode_normal,
  Timer0OC0AMode_toggle,
  Timer0OC0AMode_noninverting,
  Timer0OC0AMode_inverting
};

typedef enum Timer0OC0BMode
{
  Timer0OC0BMode_normal,
  Timer0OC0BMode_toggle,
  Timer0OC0BMode_noninverting,
  Timer0OC0BMode_inverting
};


void Timer0_setWaveform(Timer0Waveform waveform);
void Timer0_setClock(Timer0ClockSource source);
void Timer0_setOC0AMode(Timer0OC0AMode mode);
void Timer0_setOC0BMode(Timer0OC0BMode mode);
void Timer0_setCompareA(uint8_t compare);
void Timer0_setCompareB(uint8_t compare);