#ifndef	_IMAGE_PIXEL_H
#define	_IMAGE_PIXEL_H

/*
 *		Color形式からRGB565形式のデータを取得する
 */
uint16_t get_RGB565_from_color(Color c);
/*
 *		R ,G , B 形式からRGB565形式のデータを取得する
 */
uint16_t get_RGB565_from_RGB(uint8_t Red , uint8_t Green , uint8_t Blue);
/*
 *		RGB565形式からColor形式のデータを取得する
 */
Color get_color_from_RGB565(uint16_t co);

/*
 *		RGB565 ＋ alpha形式からColor形式のデータを取得する
 */
Color get_color_from_RGB565A(uint16_t co , uint8_t alpha);
/*
 *		ARGB8888形式からColor形式のデータを取得する
 */
Color get_color_from_ARGB(uint32_t co);
/*
 *		RGB565のuint16_t形式でフレームバッファからデータを取得する。
 */

uint16_t GetPixel(inx_frame_t *fb , int x , int y);

/*
 *		Color形式でフレームバッファからデータを取得する。
 */
Color GetPixelA(inx_frame_t *fb , int x , int y);

/*
 *		RGB565のuint16_t形式でフレームバッファにデータを描画する
 */
void SetPixel(inx_frame_t *fb , int x , int y , uint16_t color);

/*
 *		RGBA形式のcolor情報をフレームバッファに描画する
 */
void DrawPixel(inx_frame_t *fb , int x , int y , Color c);
uint16_t alpha_blend(uint16_t dest , uint16_t src , uint8_t alpha);

/*
 *		RGBA形式のcolor情報をフレームバッファに描画する
 */
void DrawPixel_rgb_a(inx_frame_t *fb , int x , int y , uint16_t c_in , uint8_t alpha);
/*
 *  	四角同士が重なっているかどうか調べる
 */
int RectangleCheck(Rectangle rect1 , Rectangle rect2);
/*
 * 		四角の中にポイントが入っているか調べる
 */
int RectanglePointCheck(Rectangle rect , Point p);
/*
 *  	四角同士を合成して新しい四角に変更する
 */
void Rectangle_mix(Rectangle *rect  , Rectangle rect1 , Rectangle rect2);

/*
 *  	四角同士の重なり合っている場所のみに縮小する。
 */
void Rectangle_and(Rectangle *rect  , Rectangle rect1 , Rectangle rect2);
#endif
