/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"

void ISR_INT0_App(void);
void ISR_INT1_App(void);
void ISR_INT2_App(void);
interrupt_INTx_t int0_obj={.src=INTERRUPT_INT0,
                            .edge=INTERRUPT_RISING_EDGE,
                            .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_interrupt_handler=ISR_INT0_App,
                            .intx_pin.direction=GPIO_DIRECTION_INPUT,
                            .intx_pin.port=PORTB_INDEX,
                            .intx_pin.pin=GPIO_PIN0
                            };
interrupt_INTx_t int1_obj={.src=INTERRUPT_INT1,
                            .edge=INTERRUPT_FALLING_EDGE,
                            .priority=INTERRUPT_LOW_PRIORITY,
                            .external_interrupt_handler=ISR_INT1_App,
                            .intx_pin.direction=GPIO_DIRECTION_INPUT,
                            .intx_pin.port=PORTB_INDEX,
                            .intx_pin.pin=GPIO_PIN1
                            };
interrupt_INTx_t int2_obj={.src=INTERRUPT_INT2,
                            .edge=INTERRUPT_RISING_EDGE,
                            .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_interrupt_handler=ISR_INT2_App,
                            .intx_pin.direction=GPIO_DIRECTION_INPUT,
                            .intx_pin.port=PORTB_INDEX,
                            .intx_pin.pin=GPIO_PIN2
                             };
    

Std_RetrunType ret=E_NOK;

int main() {
    app_init();
    
        
    while(1){
        
                 
        
        
         


    }
        return (EXIT_SUCCESS);
}

void app_init(void){
  
     ret=interrupt_INTx_Init(&int0_obj);
     ret=interrupt_INTx_Init(&int1_obj);
     ret=interrupt_INTx_Init(&int2_obj);
     ecu_layer_initialize();
}

void ISR_INT0_App(void)
{
    led_toggle(&led_0);
}
void ISR_INT1_App(void)
{
    led_toggle(&led_1);
}
void ISR_INT2_App(void)
{
    led_toggle(&led_2);
}

