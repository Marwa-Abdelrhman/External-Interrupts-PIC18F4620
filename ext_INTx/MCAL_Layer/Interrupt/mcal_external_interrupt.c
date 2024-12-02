/* 
 * File:   mcal_external_interrupt.c
 * Author: Marwa Abdelrahman
 *
 * Created on September 29, 2024, 2:37 PM
 */


#include"mcal_external_interrupt.h"


/*pointer to function to hold callback for INTx */

static interrupt_handler INT0_InterruptHandler=NULL;
static interrupt_handler INT1_InterruptHandler=NULL;
static interrupt_handler INT2_InterruptHandler=NULL;

/*helper functions for INTx interrupts main functions to enable driver portability*/

static Std_RetrunType interrupt_INTx_Enable(const interrupt_INTx_t *intr_obj);
static Std_RetrunType interrupt_INTx_Disable(const interrupt_INTx_t *intr_obj);
static Std_RetrunType interrupt_INTx_priority_set(const interrupt_INTx_t *intr_obj);
static Std_RetrunType interrupt_INTx_edge_set(const interrupt_INTx_t *intr_obj);
static Std_RetrunType interrupt_INTx_clear_flag(const interrupt_INTx_t *intr_obj);
static Std_RetrunType interrupt_INTx_pin_cfg(const interrupt_INTx_t *intr_obj);

static Std_RetrunType INT0_set_interrupt_handler(void(*interrupt_handler)(void));
static Std_RetrunType INT1_set_interrupt_handler(void(*interrupt_handler)(void));
static Std_RetrunType INT2_set_interrupt_handler(void(*interrupt_handler)(void));
static Std_RetrunType interrupt_INTx_set_interrupt_handler(const interrupt_INTx_t *intr_obj);

/*INTx ISR*/

void INT0_ISR (void);
void INT1_ISR (void);
void INT2_ISR (void);




/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
Std_RetrunType interrupt_INTx_Init(const interrupt_INTx_t *intr_obj){
     Std_RetrunType ret = E_NOK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        /*disable the external interrupt*/
        ret=interrupt_INTx_Disable(intr_obj);
        /*clear interrupt flag: the ext intr didn't occur*/
        ret=interrupt_INTx_clear_flag(intr_obj);
        /*configure intr edge*/
        ret=interrupt_INTx_edge_set(intr_obj);
        /*config intr pin @ MCU*/
        ret=interrupt_INTx_pin_cfg(intr_obj);
        /*config intr callback*/
        ret=interrupt_INTx_set_interrupt_handler(intr_obj);
        /*enable the external interrupt*/
        ret=interrupt_INTx_Enable(intr_obj);
             
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
Std_RetrunType interrupt_INTx_DeInit(const interrupt_INTx_t *intr_obj){
    Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
    
                
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
Std_RetrunType interrupt_RBx_Init(const interrupt_RBx_t *intr_obj){
    Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
    
                
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
Std_RetrunType interrupt_RBx_DeInit(const interrupt_RBx_t *intr_obj){
    Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
    
                
    }
    
    
    return ret;   
}




static Std_RetrunType interrupt_INTx_Enable(const interrupt_INTx_t *intr_obj){
    Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        switch(intr_obj->src)
        {
            case INTERRUPT_INT0:
                EXTERNAL_INT0_INTERRUPT_ENABLE();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_ENABLE_GLOBAL_HIGH_PRIORITY_INTERRUPTS();
#else
                INTERRUPT_ENABLE_GLOBAL_INTERRUPTS();
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPTS();
#endif
                ret=E_OK;
                break;
            case INTERRUPT_INT1:
                EXTERNAL_INT1_INTERRUPT_ENABLE();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                if(intr_obj->priority == INTERRUPT_HIGH_PRIORITY){ 
                    INTERRUPT_ENABLE_GLOBAL_HIGH_PRIORITY_INTERRUPTS();
                }
                else if(intr_obj->priority == INTERRUPT_LOW_PRIORITY){
                    INTERRUPT_ENABLE_GLOBAL_LOW_PRIORITY_INTERRUPTS();
                }
                else{/*nothing*/}
#else
                INTERRUPT_ENABLE_GLOBAL_INTERRUPTS();
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPTS();
#endif
        
                ret=E_OK;
                break;
            case INTERRUPT_INT2:
                EXTERNAL_INT2_INTERRUPT_ENABLE();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
                if(intr_obj->priority == INTERRUPT_HIGH_PRIORITY){ 
                    INTERRUPT_ENABLE_GLOBAL_HIGH_PRIORITY_INTERRUPTS();
                }
                else if(intr_obj->priority == INTERRUPT_LOW_PRIORITY){
                    INTERRUPT_ENABLE_GLOBAL_LOW_PRIORITY_INTERRUPTS();
                }
                else{/*nothing*/}
#else
                INTERRUPT_ENABLE_GLOBAL_INTERRUPTS();
                INTERRUPT_ENABLE_PERIPHERAL_INTERRUPTS();
#endif
        
                ret=E_OK;
            break;
            default:ret= E_NOK;
               
        
        }
                
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
static Std_RetrunType interrupt_INTx_Disable(const interrupt_INTx_t *intr_obj){
        Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        switch(intr_obj->src)
        {
            case INTERRUPT_INT0:
                EXTERNAL_INT0_INTERRUPT_DISABLE();
                ret=E_OK;
                break;
            case INTERRUPT_INT1:
                EXTERNAL_INT1_INTERRUPT_DISABLE();
                ret=E_OK;
                break;
            case INTERRUPT_INT2:
                EXTERNAL_INT2_INTERRUPT_DISABLE();
                ret=E_OK;
            break;
            default:ret= E_NOK;
               
        
        }
                
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
static Std_RetrunType interrupt_INTx_priority_set(const interrupt_INTx_t *intr_obj){
            Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        switch(intr_obj->src)
        {
            case INTERRUPT_INT0:
                ret=E_OK;
                break;
            case INTERRUPT_INT1:
                ret=E_OK;
                break;
            case INTERRUPT_INT2:
                ret=E_OK;
            break;
            default:ret= E_NOK;
               
        
        }
                
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
static Std_RetrunType interrupt_INTx_edge_set(const interrupt_INTx_t *intr_obj){
    Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        switch(intr_obj->src)
        {
            case INTERRUPT_INT0:
                if(intr_obj->edge == INTERRUPT_FALLING_EDGE){
                    EXTERNAL_INT0_FALLING_EDGE(); 
                }
                else if(intr_obj->edge == INTERRUPT_RISING_EDGE){
                    EXTERNAL_INT0_RISING_EDGE();
                }
                else{/*nothing*/}
                ret=E_OK;
                break;
            case INTERRUPT_INT1:
                if(intr_obj->edge == INTERRUPT_FALLING_EDGE){
                    EXTERNAL_INT1_FALLING_EDGE(); 
                }
                else if(intr_obj->edge == INTERRUPT_RISING_EDGE){
                    EXTERNAL_INT1_RISING_EDGE();
                }
                else{/*nothing*/}
                ret=E_OK;
                break;
            case INTERRUPT_INT2:
                if(intr_obj->edge == INTERRUPT_FALLING_EDGE){
                    EXTERNAL_INT2_FALLING_EDGE(); 
                }
                else if(intr_obj->edge == INTERRUPT_RISING_EDGE){
                    EXTERNAL_INT2_RISING_EDGE();
                }
                else{/*nothing*/}
                ret=E_OK;
            break;
            default:ret= E_NOK;
               
        
        }
                
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
static Std_RetrunType interrupt_INTx_clear_flag(const interrupt_INTx_t *intr_obj){
    Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        switch(intr_obj->src)
        {
            case INTERRUPT_INT0:
                EXTERNAL_INT0_INTERRUPT_FLAG_CLEAR();
                ret=E_OK;
                break;
            case INTERRUPT_INT1:
                EXTERNAL_INT1_INTERRUPT_FLAG_CLEAR();
                ret=E_OK;
                break;
            case INTERRUPT_INT2:
                EXTERNAL_INT2_INTERRUPT_FLAG_CLEAR();
                ret=E_OK;
            break;
            default:ret= E_NOK;
               
        
        }
                
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
static Std_RetrunType interrupt_INTx_pin_cfg(const interrupt_INTx_t *intr_obj){
    Std_RetrunType ret = E_NOK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
      /*initialize the needed pin for external interrupts*/
        ret=gpio_pin_direction_init(&(intr_obj->intx_pin));
    }
    
    
    return ret;
}
/**
 * 
 * @param interrupt_handler
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue 
 */
static Std_RetrunType INT0_set_interrupt_handler(void(*interrupt_handler)(void)){
    
    Std_RetrunType ret = E_NOK;
    if(interrupt_handler == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        INT0_InterruptHandler = interrupt_handler;
        ret=E_OK;
    }
    
    
    return ret;
}

/**
 * 
 * @param interrupt_handler
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue 
 */
static Std_RetrunType INT1_set_interrupt_handler(void(*interrupt_handler)(void)){
    Std_RetrunType ret = E_NOK;
    if(interrupt_handler == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        INT1_InterruptHandler = interrupt_handler;
        ret=E_OK;
    }
    
    
    return ret;
}
/**
 * 
 * @param interrupt_handler
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue 
 */
static Std_RetrunType INT2_set_interrupt_handler(void(*interrupt_handler)(void)){
    Std_RetrunType ret = E_NOK;
    if(interrupt_handler == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        INT2_InterruptHandler = interrupt_handler;
        ret=E_OK;
    }
    
    
    return ret;
}
/**
 * @brief 
 * @param intr_obj
 * @return status of function call
 *         (E_OK) the function call is successfull 
 *         (E_NOK) the function call has issue
 */
static Std_RetrunType interrupt_INTx_set_interrupt_handler(const interrupt_INTx_t *intr_obj){
               Std_RetrunType ret = E_OK;
    if(intr_obj == NULL )
    {
        ret=E_NOK;
    }
    else
    {
        switch(intr_obj->src)
        {
            case INTERRUPT_INT0:
                /*didn't pass by addr because it is a rvalue*/
                INT0_set_interrupt_handler(intr_obj->external_interrupt_handler);
                ret=E_OK;
                break;
            case INTERRUPT_INT1:
                ret=E_OK;
                INT1_set_interrupt_handler(intr_obj->external_interrupt_handler);
                break;
            case INTERRUPT_INT2:
                INT2_set_interrupt_handler(intr_obj->external_interrupt_handler);
                ret=E_OK;
            break;
            default:ret= E_NOK;
               
        
        }
                
    }
    
    
    return ret;
}
/**
 * @brief to be called @ interrupt_manager
 */
void INT0_ISR (void){
    EXTERNAL_INT0_INTERRUPT_FLAG_CLEAR();
    if(INT0_InterruptHandler != NULL){
        INT0_InterruptHandler();
    }
    else{/*nothing*/}
}
/**
 * @brief to be called @ interrupt_manager
 */
void INT1_ISR (void){
    EXTERNAL_INT1_INTERRUPT_FLAG_CLEAR();
    if(INT1_InterruptHandler){
        INT1_InterruptHandler();
    }
    else{/*nothing*/}
}
/**
 * @brief to be called @ interrupt_manager 
 */
void INT2_ISR (void){
    EXTERNAL_INT2_INTERRUPT_FLAG_CLEAR();
    if(INT2_InterruptHandler){
        INT2_InterruptHandler();
    }
    else{/*nothing*/}
}
