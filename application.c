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
#include "MCAL_Layer/SPI/hal_spi.h"
#define _XTAL_FREQ 8000000

spi_cfg_t _spi = {
    .serial_port_enable = ENABLE_SERIAL_PORT,  
    .spi_clock_Polarity = Idle_State_Low,
    .spi_clock_phase = SPI_Transmit_On_Trans_From_Idle_To_Active,
    .spi_mode = SPI_Master_Clock_Fosc_Div_By_64,
    .spi_sample_data = SPI_Data_Sampled_At_End_Of_Output,
    //.spi_mode = SPI_Slave_SS_Pin_Enabled
};

//uint8 receivedByte = 0;

int main(void){  
    
//    Pin_Config_t rd0={
//    .port = PORTD_INDEX,
//    .pin = PIN0,
//    .direction = OUTPUT,
//    .logic = LOW
//};
//Pin_Config_t rd1={
//    .port = PORTD_INDEX,
//    .pin = PIN1,
//    .direction = OUTPUT,
//    .logic = LOW
//};
//Pin_Config_t rd2={
//    .port = PORTD_INDEX,
//    .pin = PIN2,
//    .direction = OUTPUT,
//    .logic = LOW
//};
//Pin_Config_t rd3={
//    .port = PORTD_INDEX,
//    .pin = PIN3,
//    .direction = OUTPUT,
//    .logic = LOW
//};

        
//Pin_Config_t arr[4]={rd0,rd1,rd2,rd3};
    
    mcal_spi_init(&_spi);
//    gpio_pin_initialize(&rd0);
//    gpio_pin_initialize(&rd1);
//    gpio_pin_initialize(&rd2);
//    gpio_pin_initialize(&rd3);
    
    //LATA |= (1 << 5);
    
    while(1){
        mcal_spi_select_slave(5);
        mcal_spi_send_byte_blocking('M');
        __delay_ms(1000);
        mcal_spi_select_slave(5);
        mcal_spi_send_byte_blocking('S');
        __delay_ms(1000);
        
//        mcal_spi_receive_byte_blocking(&receivedByte);
//        if(receivedByte == 'M'){
//            for(int i = 0 ; i < 4 ; i++){
//                gpio_pin_write_logic(&arr[i],HIGH);
//                __delay_ms(100);
//            }
//        }
//        else if(receivedByte == 'S'){
//            for(int i = 0 ; i < 4 ; i++){
//                gpio_pin_write_logic(&arr[i],LOW);
//                __delay_ms(100);
//            }
//        }
//        receivedByte = 0;
        
    }
    
    
    
    
    return (EXIT_SUCCESS);
}


//void application_init(void){
//    
//    ecu_layer_initialize();
//    
//}
