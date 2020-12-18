/*
* Después de la inicialización todos los LEDs deben quedar apagados.
* Se puede prender un LED individual.
* Se puede apagar un LED individual.
* Se pueden prender y apagar múltiples LED’s.
* Se pueden prender todos los LEDs de una vez.
* Se pueden apagar todos los LEDs de una vez.
* Se puede consultar el estado de un LED.
*/


#include "unity.h"
#include "leds.h"

uint16_t ledsVirtuales;

void setUp(void) {
    Leds_Create(&ledsVirtuales);
}

void tearDown(void) {

}

// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void) {
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

// Se puede prender un LED individual.
void test_prender_led_individual(void) {
    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(1,ledsVirtuales);
}

// Se puede apagar un LED individual.
void test_apagar_led_individual(void) {
    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED’s.
void test_prender_apagar_multiples(void) {
    Leds_On(3);
    Leds_On(4);
    Leds_Off(3);
    TEST_ASSERT_EQUAL_HEX16(1<<3,ledsVirtuales);
}

// Se pueden prender todos los LEDs de una vez.
void test_prender_todos(void) {
    Leds_All_On();
    TEST_ASSERT_EQUAL_HEX16(0x1111,ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez.
void test_apagar_todos(void) {
    Leds_On(5);
    Leds_On(7);
    Leds_All_Off();
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
}

// Se puede consultar el estado de un LED.
void test_leer_led(void) {
    uint16_t lectura;
    Leds_On(7);
    Leds_On(15);
    Leds_Off(7);
    lectura = Read_Led(15);
    TEST_ASSERT_EQUAL_HEX16(1,lectura);
}