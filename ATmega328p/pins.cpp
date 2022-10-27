#include "pins.h"
#include <avr/sfr_defs.h>

void pinDirectionOutput(uint8_t port, uint8_t pin)
{
  uint8_t temp = _SFR_IO8(port-1);
  temp |= pin;
  _SFR_IO8(port-1) = temp;
}
void pinDirectionInput(uint8_t port, uint8_t pin)
{
  uint8_t temp = _SFR_IO8(port-1);
  temp &= ~pin;
  _SFR_IO8(port-1) = temp;
}

void pinSet(uint8_t port, uint8_t pin)
{
  uint8_t temp = _SFR_IO8(port);
  temp |= pin;
  _SFR_IO8(port) = temp; 
}

void pinClear(uint8_t port, uint8_t pin)
{
  uint8_t temp = _SFR_IO8(port);
  temp &= ~pin;
  _SFR_IO8(port) = temp; 
}

void pinToggle(uint8_t port, uint8_t pin)
{
  _SFR_IO8(port - 2) = pin;
}