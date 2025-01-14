//----------------------------------------------------------------------------------------------------------------------------------

#ifndef STUB_FUNCTIONS_H
#define STUB_FUNCTIONS_H

//----------------------------------------------------------------------------------------------------------------------------------

#include "types.h"
#include "variables.h"

//----------------------------------------------------------------------------------------------------------------------------------

void timer0_setup(void);

//----------------------------------------------------------------------------------------------------------------------------------

void sys_spi_flash_init(void);

//----------------------------------------------------------------------------------------------------------------------------------

void sys_init_display(uint16 xsize, uint16 ysize, uint16 *address);

//----------------------------------------------------------------------------------------------------------------------------------

void usb_device_init(void);

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_exit(void);

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_read_adc_data(PCHANNELSETTINGS settings);

//----------------------------------------------------------------------------------------------------------------------------------

//Requests data from the user interface controller and returns it to the caller
uint8 uart1_receive_data(void);

//Requests data from the user interface controller when no previous command is set and sets it in the toprocesscommand variable
uint8 uart1_get_user_input(void);

//Waits for user input and sets the received command in the lastreceivedcommand variable
void uart1_wait_for_user_input(void); 

//----------------------------------------------------------------------------------------------------------------------------------

void disk_exit(void);

//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------

#endif /* STUB_FUNCTIONS_H */

