#ifndef  FONT_H
#define  FONT_H

#include <wchar.h>

struct font_data_hedder{
    uint16_t    font_code;              // SJISコード
    uint8_t     w;                      // 幅
    uint8_t     h;                      // 高さ
    uint32_t    offset;                 // データのオフセット
};                

typedef struct{
	int font_id;
	uint32_t color;
	int font_size;
	int width_mode;
	int width;
	int LineInterval;
	int LineAlign;

}font_style_t;




void InitFont(void);
void FontSerchDataCtrl(void);

//int DrawFont(inx_frame_t *fb ,uint16_t val , int font_id , int x , int y , Color color, int width_mode);
//int DrawFontZoom(inx_frame_t *fb ,uint16_t val , int font_id , int x , int y , int Zoom, Color color , int width_mode);
//void DrawString(inx_frame_t *fb ,char *str , int font_id , int x, int y , Color color , int font_size, int width_mode , int align);
//void MeasureString(char *str , int font_id , int x, int y, int font_size ,int width_mode ,Rectangle *rect , int align);

extern void DrawString(inx_frame_t *fb ,wchar_t *str , int font, int x, int y , int align);
extern void MeasureString(wchar_t *str ,int font ,  int x , int y , Rectangle *rect , int align);



int GetFontBase(int font_id );

#endif
