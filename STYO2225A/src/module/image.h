

#ifndef	_INX_IMAGE_H
#define	_INX_IMAGE_H


#define   IMG_NONE       -1
#define	IMG_FILE			(0x7000)			// USBメモリから読み込んだデータ指示


void DrawImage_CallBack(inx_frame_t *fb ,int x , int y , Rectangle rect, inx_call_back_t callback);
void DrawImage(inx_frame_t *fb , const uint8_t *image , int x , int y);
void DrawImagePart(inx_frame_t *fb , const uint8_t *image , int x , int y  , Rectangle rect);
void DrawZoomImage_CallBack(inx_frame_t *fb ,int x , int y  , int w , int h , inx_call_back_t callback);
void DrawZoomImage(inx_frame_t *fb , const uint8_t *image , int x , int y , int w , int h);

void GetImageSize_CallBack(int *w , int *h , inx_call_back_t callback);
void GetImageSize(int *w , int *h , const uint8_t *image);

void Clear_Buffer(inx_frame_t *fb , Color c);
void Draw_Rectangle(inx_frame_t *fb , Color c ,Rectangle rect );
void Draw_Line(inx_frame_t *fb , Color c , int x0 , int y0 , int x1 , int y1 );
void DrawEllipse(inx_frame_t *fb , Rectangle draw_rect , Color c, int obj_x, int obj_y, int obj_w, int obj_h, float start_angle, float end_angle, float line_size );
void FillEllipse(inx_frame_t *fb , Rectangle draw_rect , Color c, int obj_x, int obj_y, int obj_w, int obj_h, float start_angle, float end_angle);
Rectangle EllipseObjectCreateQuickRedrawArea(Rectangle *draw_rect , float new_start_angle , float new_end_angle , float new_line_size, float old_start_angle , float old_end_angle , float old_line_size);


extern int image_load_usb(int id , char *path);
extern void image_unload(int id);
extern void image_load_cancel(void);
extern uint8_t *get_usb_image_address(int id);
extern int get_usb_image_size(int id);
extern int get_usb_img_empty_id(void);

#endif
