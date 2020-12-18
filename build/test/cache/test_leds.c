#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


uint16_t ledsVirtuales;



void setUp(void) {

    Leds_Create(&ledsVirtuales);

}



void tearDown(void) {



}





void test_LedsOffAfterCreate(void) {

    uint16_t ledsVirtuales = 0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_led_individual(void) {

    Leds_On(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_led_individual(void) {

    Leds_On(1);

    Leds_Off(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_apagar_multiples(void) {

    Leds_On(3);

    Leds_On(4);

    Leds_Off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1<<3)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_todos(void) {

    Leds_All_On();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x1111)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos(void) {

    Leds_On(5);

    Leds_On(7);

    Leds_All_Off();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

}





void test_leer_led(void) {

    uint16_t lectura;

    Leds_On(7);

    Leds_On(15);

    Leds_Off(7);

    lectura = Read_Led(7);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((lectura)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_HEX16);

}
