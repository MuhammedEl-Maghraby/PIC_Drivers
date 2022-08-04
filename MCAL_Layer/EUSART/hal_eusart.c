/* 
 * File:   hal_eusart.c
 * Author: Maghraby
 *
 * Created on July 31, 2022, 10:30 PM
 */

#include "hal_eusart.h"

static STD_ReturnType eusart_baudrate_configuration_bits_init(const eusart_t *eusart_obj);

STD_ReturnType mcal_eusart_asynchronous_init(const eusart_t *eusart_obj){
    STD_ReturnType Status = E_OK;
    if(eusart_obj){        
        RCSTAbits.SPEN = 1;
        TRISCbits.RC6 = 1;
        TRISCbits.RC7 = 1;        
        eusart_baudrate_configuration_bits_init(eusart_obj);
        
        if(eusart_obj->eusart_tx_cfg.eusart_tx_interrupt_enabled == EUSART_TX_INTERRUPT_ENABLE){
            
        }
        else if(eusart_obj->eusart_tx_cfg.eusart_tx_interrupt_enabled == EUSART_TX_INTERRUPT_DISABLE){
            
        }
        else{
            Status = E_NOT_OK;
        }
    }
    else{
        Status = E_NOT_OK;
    }    
    return Status;
}

STD_ReturnType mcal_eusart_synchronous_init(const eusart_t *eusart_obj){
    
    
}

STD_ReturnType mcal_eusart_deinit(void){
    STD_ReturnType Status = E_OK;   
    
    return Status;
    
}


STD_ReturnType mcal_eusart_send_byte_blocking(uint8 data){
    STD_ReturnType Status = E_OK;   
    
    return Status;
}


STD_ReturnType mcal_eusart_send_byte_non_blocking(uint8 data){
    STD_ReturnType Status = E_OK;   
    
    return Status;    
}


STD_ReturnType mcal_eusart_receive_byte_blocking(uint8 *data){
    STD_ReturnType Status = E_OK;   
    
    return Status;    
}


STD_ReturnType mcal_eusart_receive_byte_non_blocking(uint8  *data){
    STD_ReturnType Status = E_OK;   
    
    return Status;    
}


STD_ReturnType mcal_eusart_send_string_blocking(uint8 *str , uint8 str_length){
    STD_ReturnType Status = E_OK;   
    
    return Status;
}


STD_ReturnType mcal_eusart_send_string_non_blocking(uint8 *str , uint8 str_length){
    STD_ReturnType Status = E_OK;   
    
    return Status;
    
}


/*Helper Functions */
static STD_ReturnType eusart_baudrate_configuration_bits_init(const eusart_t *eusart_obj){
    STD_ReturnType Status = E_OK;   
    float baudrate_val = 0;
    if(eusart_obj){
        switch(eusart_obj->baudrate_cfg){
            case EUSART_Asynchronous_8bit_LowSpeed:
                EUSART_Asynchronous_Mode();
                EUSART_BaudRate_Generator_8Bit_Select();
                EUSART_BaudRate_LowSpeed_Select();
                baudrate_val = ((_XTAL_FREQ/(float)eusart_obj->baudrate_value)/64)-1;
                SPBRG = (uint8)((uint32)baudrate_val);
                SPBRGH = (uint8)(((uint32)baudrate_val) >> 8);                
                break;
                
            case EUSART_Asynchronous_8bit_HighSpeed:
                EUSART_Asynchronous_Mode();
                EUSART_BaudRate_Generator_8Bit_Select();
                EUSART_BaudRate_HighSpeed_Select();
                baudrate_val = ((_XTAL_FREQ/(float)eusart_obj->baudrate_value)/16)-1;
                SPBRG = (uint8)((uint32)baudrate_val);
                SPBRGH = (uint8)(((uint32)baudrate_val) >> 8);  
                break;                
                
            case EUSART_Asynchronous_16bit_LowSpeed:
                EUSART_Asynchronous_Mode();
                EUSART_BaudRate_Generator_16Bit_Select();
                EUSART_BaudRate_LowSpeed_Select();
                baudrate_val = ((_XTAL_FREQ/(float)eusart_obj->baudrate_value)/16)-1;
                SPBRG = (uint8)((uint32)baudrate_val);
                SPBRGH = (uint8)(((uint32)baudrate_val) >> 8);                  
                break;
                
            case EUSART_Asynchronous_16bit_HighSpeed:
                EUSART_Asynchronous_Mode();
                EUSART_BaudRate_Generator_16Bit_Select();
                EUSART_BaudRate_HighSpeed_Select();
                baudrate_val = ((_XTAL_FREQ/(float)eusart_obj->baudrate_value)/4)-1;
                SPBRG = (uint8)((uint32)baudrate_val);
                SPBRGH = (uint8)(((uint32)baudrate_val) >> 8);                
                break;
                
            case EUSART_Synchronous_8bit:
                EUSART_Synchronous_Mode();
                EUSART_BaudRate_Generator_8Bit_Select();
                baudrate_val = ((_XTAL_FREQ/(float)eusart_obj->baudrate_value)/4)-1;
                SPBRG = (uint8)((uint32)baudrate_val);
                SPBRGH = (uint8)(((uint32)baudrate_val) >> 8);
                break;
                
            case EUSART_Synchronous_16bit:
                EUSART_Synchronous_Mode();
                EUSART_BaudRate_Generator_16Bit_Select();
                baudrate_val = ((_XTAL_FREQ/(float)eusart_obj->baudrate_value)/4)-1;
                SPBRG = (uint8)((uint32)baudrate_val);
                SPBRGH = (uint8)(((uint32)baudrate_val) >> 8);                
                break;
                
            default:
                
                break;   
        }             
    }
    else{
        Status = E_NOT_OK;        
    }
    return Status;    
    
}

