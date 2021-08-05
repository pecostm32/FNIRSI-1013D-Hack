//----------------------------------------------------------------------------------------------------------------------------------

#ifndef SCOPE_FUNCTIONS_H
#define SCOPE_FUNCTIONS_H

//----------------------------------------------------------------------------------------------------------------------------------

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   480

//----------------------------------------------------------------------------------------------------------------------------------

void scope_setup_display_lib(void);

void scope_setup_main_screen(void);
  
//----------------------------------------------------------------------------------------------------------------------------------

void scope_setup_right_control_menu(void);

//----------------------------------------------------------------------------------------------------------------------------------
// Right side bar functions
//----------------------------------------------------------------------------------------------------------------------------------
  
void scope_control_button(int mode);
void scope_run_stop_button(int mode);
void scope_auto_set_button(int mode);
void scope_page_up_button(int mode);
void scope_page_down_button(int mode);
void scope_t_cursor_button(int mode);
void scope_v_cursor_button(int mode);
void scope_measures_button(int mode);
void scope_save_picture_button(int mode);
void scope_save_wave_button(int mode);
void scope_delete_wave_button(int mode);
void scope_50_percent_trigger_button(int mode);
void scope_show_grid_button(int mode);
void scope_ch1_sensitivity_control(int type, int mode);
void scope_ch2_sensitivity_control(int type, int mode);

//----------------------------------------------------------------------------------------------------------------------------------
// Top bar functions
//----------------------------------------------------------------------------------------------------------------------------------

void scope_menu_button(int mode);
void scope_main_return_button(int mode);
void scope_run_stop_text(int mode);
void scope_channel1_settings(int mode);
void scope_channel2_settings(int mode);
void scope_time_div_setting(void);
void scope_move_speed(int mode);
void scope_trigger_settings(int mode);
void scope_battery_status(void);

//----------------------------------------------------------------------------------------------------------------------------------
// Menu functions
//----------------------------------------------------------------------------------------------------------------------------------

void scope_open_main_menu(void);
void scope_main_menu_system_settings(int mode);
void scope_main_menu_picture_view(int mode);
void scope_main_menu_waveform_view(int mode);
void scope_main_menu_usb_connection(int mode);

void scope_open_channel1_menu(void);
void scope_channel1_enable_select(void);
void scope_channel1_fft_show(void);
void scope_channel1_coupling_select(void);
void scope_channel1_probe_magnification_select(void);

void scope_open_channel2_menu(void);
void scope_channel2_enable_select(void);
void scope_channel2_fft_show(void);
void scope_channel2_coupling_select(void);
void scope_channel2_probe_magnification_select(void);

void scope_open_trigger_menu(void);
void scope_trigger_mode_select(void);
void scope_trigger_edge_select(void);
void scope_trigger_channel_select(void);

void scope_open_system_settings_menu(void);
void scope_system_settings_screen_brightness_item(int mode);
void scope_system_settings_screen_brightness_value(void);
void scope_system_settings_grid_brightness_item(int mode);
void scope_system_settings_grid_brightness_value(void);
void scope_system_settings_trigger_50_item(void);
void scope_system_settings_calibration_item(int mode);
void scope_system_settings_x_y_mode_item(void);

void scope_open_calibration_start_text(void);
void scope_show_calibrating_text(void);
void scope_show_calibration_done_text(void);

void scope_open_measures_menu(void);
void scope_measures_menu_item(int channel, int item);

//----------------------------------------------------------------------------------------------------------------------------------

void scope_open_slider(uint16 xpos, uint16 ypos, uint8 position);
void scope_display_slider(uint16 xpos, uint16 ypos, uint8 position);
int scope_move_slider(uint16 xpos, uint16 ypos, uint8 *position);

void scope_display_slide_button(uint16 xpos, uint16 ypos, uint8 state);

void scope_display_ok_button(uint16 xpos, uint16 ypos, uint8 mode);

//----------------------------------------------------------------------------------------------------------------------------------
// Grid and cursor functions
//----------------------------------------------------------------------------------------------------------------------------------

void scope_draw_grid(void);
void scope_draw_pointers(void);
void scope_draw_time_cursors(void);
void scope_draw_vlot_cursors(void);

//----------------------------------------------------------------------------------------------------------------------------------
// Signal data processing functions
//----------------------------------------------------------------------------------------------------------------------------------

void scope_process_trace_data(void);



void scope_get_long_timebase_data(void);

void scope_get_short_timebase_data(void);

//----------------------------------------------------------------------------------------------------------------------------------

#endif /* SCOPE_FUNCTIONS_H */
