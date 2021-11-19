//----------------------------------------------------------------------------------------------------------------------------------

#include "stub_functions.h"
#include "ff.h"
#include "variables.h"

//----------------------------------------------------------------------------------------------------------------------------------

void sys_clock_init(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void arm32_icache_enable(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void arm32_dcache_enable(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void arm32_interrupt_enable(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void timer0_setup(void)
{
  timer0ticks = 0;
}

//----------------------------------------------------------------------------------------------------------------------------------

uint32 timer0_get_ticks(void)
{
  return(timer0ticks);
}

//----------------------------------------------------------------------------------------------------------------------------------

void timer0_delay(uint32 timeout)
{
  //Calculate the timeout ticks
  timeout += timer0ticks;
  
  //While technically prone to error on timer ticks overflow the scope has to be running for >49 days before it occurs
  //Wait until time has past
  while(timer0ticks < timeout);
}

//----------------------------------------------------------------------------------------------------------------------------------

void power_interrupt_init(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void battery_check_init(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void battery_check_status(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void sys_spi_flash_init(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void sys_spi_flash_read(int addr, unsigned char *buffer, int length)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void sys_spi_flash_write(int addr, unsigned char *buffer, int length)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_init(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_write_cmd(uint8 command)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

uint8 fpga_read_cmd(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_write_byte(uint8 data)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

uint8 fpga_read_byte(void)
{
 return 1;
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_write_short(uint16 data)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

uint16 fpga_read_short(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_write_int(uint32 data)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_backlight_brightness(uint16 brightness)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_translated_brightness(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

uint16 fpga_get_version(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_check_ready(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_enable_system(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_1_enable(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_1_coupling(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_1_voltperdiv(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_1_offset(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_2_enable(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_2_coupling(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_2_voltperdiv(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_channel_2_offset(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_trigger_timebase(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_trigger_channel(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_trigger_edge(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_swap_trigger_channel(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_trigger_level(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_trigger_mode(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_long_timebase(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_short_timebase(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

uint16 fpga_prepare_for_transfer(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_read_trace_data(uint8 command, uint16 *buffer, int32 count)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

uint16 fpga_average_trace_data(uint8 command)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_set_battery_level(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_init_parameter_ic(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void fpga_write_parameter_ic(uint8 id, uint32 value)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

uint32 fpga_read_parameter_ic(uint8 id, uint32 value)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void sys_init_display(uint16 xsize, uint16 ysize, uint16 *address)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void tp_i2c_setup(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void tp_i2c_read_status(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void tp_i2c_wait_for_touch_release(void)
{
  //Wait until touch is released
  while(havetouch);
}

//----------------------------------------------------------------------------------------------------------------------------------

void usb_device_init(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void usb_device_disable(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

void usb_device_enable(void)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

FRESULT f_open (FIL* fp, const TCHAR* path, BYTE mode)
{
}

//----------------------------------------------------------------------------------------------------------------------------------
FRESULT f_close (FIL* fp)
{
}

//----------------------------------------------------------------------------------------------------------------------------------
FRESULT f_read (FIL* fp, void* buff, UINT btr, UINT* br)
{
}

//----------------------------------------------------------------------------------------------------------------------------------
FRESULT f_write (FIL* fp, const void* buff, UINT btw, UINT* bw)
{
}

//----------------------------------------------------------------------------------------------------------------------------------
FRESULT f_lseek (FIL* fp, FSIZE_t ofs)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

FRESULT f_unlink (const TCHAR* path)
{
}

//----------------------------------------------------------------------------------------------------------------------------------

FRESULT f_mount (FATFS* fs, const TCHAR* path, BYTE opt)
{
 return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------