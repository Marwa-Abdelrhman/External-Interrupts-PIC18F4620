/* 
 * File:   mcal_interrupt_manager.h
 * Author: Marwa Abdelrahman
 *
 * Created on September 29, 2024, 2:35 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H



/*.....................................Includes.....................................*/


#include "mcal_interrupt_config.h"
/*.....................................Macros Declarations.....................................*/


/*.....................................Macros Functions Declarations.....................................*/



/*.....................................Data Types Declarations.....................................*/
/*.....................................Functions Declarations.....................................*/
void INT0_ISR (void);
void INT1_ISR (void);
void INT2_ISR (void);

#endif	/* MCAL_INTERRUPT_MANAGER_H */

