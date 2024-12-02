/* 
 * File:   mcal_interrupt_manger.c
 * Author: Marwa Abdelrahman
 *
 * Created on September 29, 2024, 2:35 PM
 */

#include "mcal_interrupt_manager.h"



#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
 void __interrupt() Interrupt_Manager_High(void){
 }
 
 
  void __interrupt(low_priority) Interrupt_Manager_High(void){
 }
 
     
#else
void __interrupt() Interrupt_Manager(void){
    if((INTERRUPT_ENABLE==INTCONbits.INT0IE) && (INTERRUPT_FLAG_OCCUR==INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCON3bits.INT1IE) && (INTERRUPT_FLAG_OCCUR==INTCON3bits.INT1IF)){
        INT1_ISR();
    }
    else{/*nothing*/}
    if((INTERRUPT_ENABLE==INTCON3bits.INT2IE) && (INTERRUPT_FLAG_OCCUR==INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{/*nothing*/}
        
    
}

#endif