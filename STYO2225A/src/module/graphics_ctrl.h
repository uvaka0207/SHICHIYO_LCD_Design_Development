 
#ifndef  GRAPHICS_CTRL_H
#define  GRAPHICS_CTRL_H

#include "graphics_obj.h"

#define		FRAME_PIXCEL_SIZE				2u
//#define		DISPLAY_ROT_R
 #define		DISPLAY_ROT_L


#define     FRAME_FORMAT                (VDC5_GR_FORMAT_RGB565)
#define     FRAME_WIDTH                 (1024u)
#define     FRAME_HEIGHT                (600u)
#define     FRAME_STRIDE               (((FRAME_WIDTH * FRAME_PIXCEL_SIZE) + 31u) & ~31u)


#ifndef DISPLAY_ROT_R
#ifndef DISPLAY_ROT_L

#define     FRAME_BUFFER_WIDTH          (FRAME_WIDTH)
#define     FRAME_BUFFER_HEIGHT         (FRAME_HEIGHT)

#endif
#endif

#ifdef DISPLAY_ROT_L
#define     FRAME_BUFFER_WIDTH          (FRAME_HEIGHT)
#define     FRAME_BUFFER_HEIGHT         (FRAME_WIDTH)
#endif

#ifdef DISPLAY_ROT_R
#define     FRAME_BUFFER_WIDTH          (FRAME_HEIGHT)
#define     FRAME_BUFFER_HEIGHT         (FRAME_WIDTH)
#endif


#define     FRAME_BUFFER_STRIDE         (((FRAME_BUFFER_WIDTH * FRAME_PIXCEL_SIZE) + 31u) & ~31u)


int Graphics_Task(void);

extern void inx_Graphics_Init(void);
extern void inx_Graphics_Ctrl(void);


void touch_check_obj(void);
void SetBackColor(uint32_t Co);


void chage_obj_start(void);
void chage_obj_end(void);
void obj_redraw(void);
void set_wait_quick_redraw(int value);

void SetBackLight(int on_off);
int get_back_image_draw_end(void);

void GraphicsSemaphoreWait(void);
void GraphicsSemaphoreRelease(void);


void inx_get_obj_draw_size(obj_data_t *obj ,Rectangle *rect );
void quick_redraw_run(void);
void quick_redraw(int x, int y , int w, int h);
void redraw_wait(void);
void redraw(void);



#endif
