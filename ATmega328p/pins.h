#include <inttypes.h>

#define PIN_0 (1<<0)
#define PIN_1 (1<<1)
#define PIN_2 (1<<2)
#define PIN_3 (1<<3)
#define PIN_4 (1<<4)
#define PIN_5 (1<<5)
#define PIN_6 (1<<6)
#define PIN_7 (1<<7)
#define PIN_0_PORT  (0x0B)
#define PIN_1_PORT  (0x0B)
#define PIN_2_PORT  (0x0B)
#define PIN_3_PORT  (0x0B)
#define PIN_4_PORT  (0x0B)
#define PIN_5_PORT  (0x0B)
#define PIN_6_PORT  (0x0B)
#define PIN_7_PORT  (0x0B)

#define PIN_8 (1<<0)
#define PIN_9 (1<<1)
#define PIN_10 (1<<2)
#define PIN_11 (1<<3)
#define PIN_12 (1<<4)
#define PIN_13 (1<<5)
#define PIN_8_PORT  (0x05)
#define PIN_9_PORT  (0x05)
#define PIN_10_PORT  (0x05)
#define PIN_11_PORT  (0x05)
#define PIN_12_PORT  (0x05)
#define PIN_13_PORT  (0x05)

#define PIN_A0 (1<<0)
#define PIN_A1 (1<<1)
#define PIN_A2 (1<<2)
#define PIN_A3 (1<<3)
#define PIN_A4 (1<<4)
#define PIN_A5 (1<<5)
#define PIN_RESET (1<<6)
#define PIN_A0_PORT  (0x08)
#define PIN_A1_PORT  (0x08)
#define PIN_A2_PORT  (0x08)
#define PIN_A3_PORT  (0x08)
#define PIN_A4_PORT  (0x08)
#define PIN_A5_PORT  (0x08)
#define PIN_RESET_PORT  (0x08)

void pinDirectionOutput(uint8_t port, uint8_t pin);
void pinDirectionInput(uint8_t port, uint8_t pin);

void pinSet(uint8_t port, uint8_t pin);
void pinClear(uint8_t port, uint8_t pin);
void pinToggle(uint8_t port, uint8_t pin);