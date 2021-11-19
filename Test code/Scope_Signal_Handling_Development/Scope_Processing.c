//----------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "Scope_Processing.h"
#include "Scope_Signal_Handling_Development.h"

#include "stub_functions.h"

#include "fnirsi_1013d_scope.h"
#include "fpga_control.h"
#include "scope_functions.h"
#include "statemachine.h"
#include "display_lib.h"
#include "variables.h"
#include "power_and_battery.h"

//----------------------------------------------------------------------------------------------------------------------------------

//#define maindisplaybuffer   scope_data->displaymemory

//----------------------------------------------------------------------------------------------------------------------------------

int interrupthandlers[64];


//----------------------------------------------------------------------------------------------------------------------------------

pthread_t scope_processing_thread;

int quit_scopeprocessing_thread_on_zero = 0;

//----------------------------------------------------------------------------------------------------------------------------------

int startscopeprocessing(void)
{
  //Setup for keeping the arm core thread running
  quit_scopeprocessing_thread_on_zero = 1;
  
  //Start up the arm core thread
  return(pthread_create(&scope_processing_thread, NULL, scopeprocessingthread, NULL));
}

//----------------------------------------------------------------------------------------------------------------------------------

void stopscopeprocessing(void)
{
  //Stop the arm core thread
  quit_scopeprocessing_thread_on_zero = 0;
}

//----------------------------------------------------------------------------------------------------------------------------------

void *scopeprocessingthread(void *arg)
{
  //Initialize the scope
  
  //Load a program to arm memory
//  FILE *fp = fopen("scope_spl.bin", "rb");
//  FILE *fp = fopen("fnirsi_1013d_bootloader.bin", "rb");
  
  
  
//  if(fp)
//  {
//    fread(parm_core->sram1, 1, 32768, fp);
    
//    fclose(fp);
//  }
  
  //Initialize the clock system
  sys_clock_init();
  
  //Instead of full memory management just the caches enabled
  arm32_icache_enable();
  arm32_dcache_enable();
  
  //Clear the interrupt variables
  memset(interrupthandlers, 0, 256);
  
  //Setup timer interrupt
  timer0_setup();
  
  //Setup power monitoring
  power_interrupt_init();
  
  //Setup battery monitoring
  battery_check_init();
  
  //Enable interrupts only once. In the original code it is done on more then one location.
  arm32_interrupt_enable();
  
  //Initialize SPI for flash (PORT C + SPI0)
  sys_spi_flash_init();
  
  //Initialize FPGA (PORT E)
  fpga_init();
  
  //Turn of the display brightness
  fpga_set_backlight_brightness(0x0000);
  
  //Initialize display (PORT D + DEBE)
  sys_init_display(SCREEN_WIDTH, SCREEN_HEIGHT, (uint16 *)maindisplaybuffer);
  
  //Setup the display library for the scope hardware
  scope_setup_display_lib();

  //Setup the touch panel interface
  tp_i2c_setup();
  
  //Setup and check SD card on file system being present
  if(f_mount(&fs, "0", 1))
  {
    //Show SD card error message on failure
    //Set max screen brightness
    fpga_set_backlight_brightness(0xEA60);

    //Clear the display
    display_set_fg_color(0x00000000);
    display_fill_rect(0, 0, 800, 480);

    //Display the message in red
    display_set_fg_color(0x00FF0000);
    display_set_font(&font_3);
    display_text(30, 50, "SD ERROR");
    
    //On error just hang, as long as system is up
    while(quit_scopeprocessing_thread_on_zero);
    
    //Exit the thread the way it is supposed to
    pthread_exit(NULL);
  }
  
  //In the original code there is some hardware check function here. Actions are not performed unless some data in the FLASH is not set
  //This tests the basic hardware and verifies the touch panel
  
  //Setup the USB interface
  usb_device_init();
  
  //Load configuration data from FLASH
  scope_load_configuration_data();

  //25nS/div testing first
  scopesettings.channel1.magnification = 0;
  scopesettings.channel1.voltperdiv = 4;
  scopesettings.timeperdiv = 29;
  scopesettings.triggerchannel = 0;
  saved_sample_buffers_count = 0;
  
  //Enable or disable the channels based on the scope loaded settings
  fpga_set_channel_1_enable();
  fpga_set_channel_2_enable();
  
  //Set the volts per div for each channel based on the loaded scope settings
  fpga_set_channel_1_voltperdiv();
  fpga_set_channel_2_voltperdiv();
  
  //Set the channels AC or DC coupling based on the loaded scope settings
  fpga_set_channel_1_coupling();
  fpga_set_channel_2_coupling();
  
  //Enable something in the FPGA
  fpga_enable_system();
  
  //Initialize the communication with the parameter IC
  fpga_init_parameter_ic();
  
  //Setup the trigger system in the FPGA based on the loaded scope settings
  fpga_set_trigger_timebase();
  fpga_set_trigger_channel();
  fpga_swap_trigger_channel();   //This is a bit redundant since the correct channel should be in the loaded settings.
  fpga_set_trigger_edge();
  fpga_set_trigger_level();
  fpga_set_trigger_mode();
  
  fpga_set_channel_1_offset();
  fpga_set_channel_2_offset();
  
  //Some initialization of the FPGA??. Data written with command 0x3C
  fpga_set_battery_level();      //Only called here and in hardware check

  //In the original code there is another hardware check function here. Actions are not performed unless some data in the FLASH is not set
  //This is for testing the analog response
  //When all tests run through the flash is updated to no longer run the hardware tests.
  

  //Here a function is called that looks at some system file????? Firmware upgrade!!!

  
  //Setup the main parts of the screen
  scope_setup_main_screen();
    
  //Set screen brightness
  fpga_set_translated_brightness();
  
  //Keep running the scope until stopped
  while(quit_scopeprocessing_thread_on_zero)
  {
    //Monitor the battery status
    battery_check_status();
    
    //Go through the trace data and make it ready for displaying
    scope_process_trace_data();
    
    //Display the trace data
    scope_display_trace_data();
    
    //Handle the touch panel input
    touch_handler();
  }

  //Could emulate parameter save here
  
  
  //Exit the thread the way it is supposed to
  pthread_exit(NULL);

}



/* This can be used to emulate the timer ticks
#include <sys/time.h>

  timeval    starttime;
  timeval    midtime;
  timeval    endtime;
  long int   duration;

           //Get the current time for duration calculation
          gettimeofday(&starttime, 0);
 
          //Get the current time for duration calculation
          gettimeofday(&endtime, 0);

          //Calculate the duration in micro seconds
          duration = ((endtime.tv_sec - starttime.tv_sec) * 1000000) + (endtime.tv_usec - starttime.tv_usec);

          //11-12-2016 Changed to 1 second instead of 10 seconds
          //Calculate the needed delay for 1 second time slots
          duration = 1000000 - duration;

          //Go to sleep if the delay is bigger then 10 micro seconds
          if(duration > 10)
              usleep(duration);
*/


//----------------------------------------------------------------------------------------------------------------------------------