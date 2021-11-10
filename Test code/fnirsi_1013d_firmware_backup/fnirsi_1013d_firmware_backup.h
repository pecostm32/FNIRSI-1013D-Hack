//----------------------------------------------------------------------------------------------------------------------------------

#ifndef FNIRSI_1013D_SCOPE_H
#define FNIRSI_1013D_SCOPE_H

//----------------------------------------------------------------------------------------------------------------------------------

#include "types.h"

//----------------------------------------------------------------------------------------------------------------------------------

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   480

#define SCREEN_SIZE     (SCREEN_WIDTH * SCREEN_HEIGHT)

//----------------------------------------------------------------------------------------------------------------------------------

void setup_display_lib(void);

void draw_startup_screen(void);

void draw_progress_bar(uint32 xpos, uint32 ypos, uint32 progress);

int32 save_tp_config(uint32 ypos);

int32 save_full_flash_data(uint32 ypos, uint32 blocksize);

int32 save_firmware_data(uint32 ypos);

//----------------------------------------------------------------------------------------------------------------------------------


#endif /* FNIRSI_1013D_SCOPE_H */

