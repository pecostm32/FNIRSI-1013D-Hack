//----------------------------------------------------------------------------------------------------------------------------------

#ifndef STUB_FUNCTIONS_H
#define STUB_FUNCTIONS_H

//----------------------------------------------------------------------------------------------------------------------------------

#include "types.h"

//----------------------------------------------------------------------------------------------------------------------------------

void sys_clock_init(void);

//----------------------------------------------------------------------------------------------------------------------------------

void arm32_icache_enable(void);
void arm32_dcache_enable(void);

void arm32_interrupt_enable(void);

//----------------------------------------------------------------------------------------------------------------------------------

void timer0_setup(void);

//----------------------------------------------------------------------------------------------------------------------------------

void power_interrupt_init(void);

//----------------------------------------------------------------------------------------------------------------------------------

void battery_check_init(void);

//----------------------------------------------------------------------------------------------------------------------------------

void sys_spi_flash_init(void);

//----------------------------------------------------------------------------------------------------------------------------------

void sys_init_display(uint16 xsize, uint16 ysize, uint16 *address);

//----------------------------------------------------------------------------------------------------------------------------------

void tp_i2c_setup(void);

//----------------------------------------------------------------------------------------------------------------------------------

void usb_device_init(void);

//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------

#endif /* STUB_FUNCTIONS_H */
