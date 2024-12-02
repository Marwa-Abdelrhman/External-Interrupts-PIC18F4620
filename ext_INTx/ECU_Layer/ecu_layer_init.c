/* 
 * File:   ecu_layer_init.c
 * Author: Marwa Abdelrahman
 *
 * Created on September 2, 2024, 2:18 PM
 */

//#include "KeyPad/ecu_keypad.h"
//#include "Char_LCD/ecu_char_LDC.h"
#include "LED/ecu_led.h"



led_t led_0={.port_name=PORTC_INDEX,.pin=GPIO_PIN0,.led_state=GPIO_STATE_LOW};
led_t led_1={.port_name=PORTC_INDEX,.pin=GPIO_PIN1,.led_state=GPIO_STATE_LOW};
led_t led_2={.port_name=PORTC_INDEX,.pin=GPIO_PIN2,.led_state=GPIO_STATE_LOW};

/**
 * @brief initialize all needed drivers in ecu layer
 */
void ecu_layer_initialize(void)
{  
    led_init(&led_0);
    led_init(&led_1);
    led_init(&led_2);

}