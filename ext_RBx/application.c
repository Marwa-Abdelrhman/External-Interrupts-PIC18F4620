/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"
#include "MCAL_Layer/Interrupt/mcal_external_interrupt.h"

//void ISR_RB4_App(void);

/*interrupt_RBx_t rb4_obj={   .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_interrupt_handler=ISR_RB4_HIGH_App,
                            .rbx_pin.direction=GPIO_DIRECTION_INPUT,
                            .rbx_pin.port=PORTB_INDEX,
                            .rbx_pin.pin=GPIO_PIN4
                            };*/
void ISR_RB4_HIGH_App(void);
void ISR_RB4_LOW_App(void);
void ISR_RB5_HIGH_App(void);
void ISR_RB5_LOW_App(void);
void ISR_RB6_HIGH_App(void);
void ISR_RB6_LOW_App(void);
void ISR_RB7_HIGH_App(void);
void ISR_RB7_LOW_App(void);

 interrupt_RBx_t rb4_obj={   .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_High_interrupt_handler=ISR_RB4_HIGH_App,
                            .external_Low_interrupt_handler=ISR_RB4_LOW_App,
                            .rbx_pin.direction=GPIO_DIRECTION_INPUT,
                            .rbx_pin.port=PORTB_INDEX,
                            .rbx_pin.pin=GPIO_PIN4
                            };
interrupt_RBx_t rb5_obj={   .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_High_interrupt_handler=ISR_RB5_HIGH_App,
                            .external_Low_interrupt_handler=ISR_RB5_LOW_App,
                            .rbx_pin.direction=GPIO_DIRECTION_INPUT,
                            .rbx_pin.port=PORTB_INDEX,
                            .rbx_pin.pin=GPIO_PIN5
                            };
interrupt_RBx_t rb6_obj={   .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_High_interrupt_handler=ISR_RB6_HIGH_App,
                            .external_Low_interrupt_handler=ISR_RB6_LOW_App,
                            .rbx_pin.direction=GPIO_DIRECTION_INPUT,
                            .rbx_pin.port=PORTB_INDEX,
                            .rbx_pin.pin=GPIO_PIN6
                            };
interrupt_RBx_t rb7_obj={   .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_High_interrupt_handler=ISR_RB7_HIGH_App,
                            .external_Low_interrupt_handler=ISR_RB7_LOW_App,
                            .rbx_pin.direction=GPIO_DIRECTION_INPUT,
                            .rbx_pin.port=PORTB_INDEX,
                            .rbx_pin.pin=GPIO_PIN7
                            };

 

Std_RetrunType ret=E_NOK;

int main() {
    ecu_layer_initialize();
    app_init();
    
        
    while(1){
        
                 
        
        
         


    }
        return (EXIT_SUCCESS);
}

void app_init(void){
  
     ret=interrupt_RBx_Init(&rb4_obj);
     ret=interrupt_RBx_Init(&rb5_obj);
     ret=interrupt_RBx_Init(&rb6_obj);
     ret=interrupt_RBx_Init(&rb7_obj);
     
     
}
/*void ISR_RB4_App(void){
    led_toggle(&led_4);
}*/
/*call back functions for RBx interrupts*/

void ISR_RB4_HIGH_App(void){
    led_on(&led_4);
    
    
}

void ISR_RB4_LOW_App(void){
    led_on(&led_5);
}


void ISR_RB5_HIGH_App(void){
    led_off(&led_4);
    
    
}
void ISR_RB5_LOW_App(void){
    led_off(&led_5);
}



void ISR_RB6_HIGH_App(void){
    led_on(&led_6);
    
    
}
void ISR_RB6_LOW_App(void){
    led_on(&led_7);
}


void ISR_RB7_HIGH_App(void){
    led_off(&led_6);
    
    
}
void ISR_RB7_LOW_App(void){
    led_off(&led_7);
}
