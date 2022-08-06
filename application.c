/* 
 * File:   application.c
 * Author: Maghraby
 *
 * Created on February 26, 2022, 2:43 PM
 */
#include "application.h"
#include "MCAL_Layer/EEPROM/hal_eeprom.h"
#include "MCAL_Layer/Interrupt/mcal_interrupt_manager.h"
#include "MCAL_Layer/ADC/hal_adc.h"
#include "MCAL_Layer/Timer0/hal_timer0.h"
#include "MCAL_Layer/Timer1/hal_timer1.h"
#include "MCAL_Layer/Timer2/hal_timer2.h"
#include "MCAL_Layer/Timer3/hal_timer3.h"
#include "MCAL_Layer/CCP1/hal_ccp1.h"
#include "MCAL_Layer/EUSART/hal_eusart.h"
#define _XTAL_FREQ 8000000

eusart_tx_t eusartTX = {
  .Int_Tx_Handler_Var = NULL,
  .eusart_tx_enabled = EUSART_TX_ENABLED,
  .eusart_9bit_transmission = EUSART_TX_9BIT_NOT_SELECTED,
  .eusart_tx_interrupt_enabled = EUSART_TX_INTERRUPT_DISABLE

};

eusart_t eusart = {
    .baudrate_cfg = EUSART_Asynchronous_8bit_HighSpeed, 
    .baudrate_value = 9600,
    .mode_of_operation = EUSART_ASYNCHRONOUS_MODE,
    .eusart_tx_cfg = &eusartTX,
    .eusart_rx_cfg = NULL
};


int main(void){  
    mcal_eusart_asynchronous_init(&eusart);

    while(1){

        mcal_eusart_send_string_blocking("I Love you Sama\r",16);
        __delay_ms(1000);
        
    }
    
    
    
    
    return (EXIT_SUCCESS);
}


//void application_init(void){
//    
//    ecu_layer_initialize();
//    
//}
