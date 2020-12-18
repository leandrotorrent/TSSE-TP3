
#include "leds.h"

#define LEDS_ALL_OFF    0x0000
#define LEDS_ALL_ON     0x1111
#define LED_OFFSET      1
#define LSB             1

static uint16_t * direccion;

uint16_t LedToMask(uint8_t led) {
    return (LSB << (led-LED_OFFSET));
}

void Leds_Create(uint16_t * puerto) {
    direccion = puerto;
    *puerto = LEDS_ALL_OFF;
}

void Leds_On(uint8_t led) {
    *direccion |= LedToMask(led);
}

void Leds_Off(uint8_t led) {
    *direccion &= ~LedToMask(led);
}

void Leds_All_On(void) {
    *direccion = LEDS_ALL_ON;
}

void Leds_All_Off(void) {
    *direccion = LEDS_ALL_OFF;
}

uint16_t Read_Led(uint8_t led) {
    if(*direccion == LedToMask(led)) {
        return 1;
    }
    else return 0;

}