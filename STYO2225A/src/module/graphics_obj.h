#ifndef  GRAPHICS_OBJ_H
#define  GRAPHICS_OBJ_H


#include "stdinx.h"


#define MAX_LAYER				16
#define MAX_FREE_LAYER_DATA		16


typedef void (*TOUCH_CALLBACK)(int obj_id , int touch_type);

typedef struct {
	// GUIツールで初期されるデータ
	
	int		    object_id;				// オブジェクト番号
	int16_t		image_id;				// イメージ番号
	int16_t		touch_image_id;			// touch中イメージ番号
	int16_t		disable_image_id;			// touch中イメージ番号
	uint8_t		obj_type;				// オブジェクトの種類		0:画像オブジェクト 1:
	uint8_t		draw_type;				// 表示種類
	int16_t		x;						// X座標
	int16_t		y;						// Y座標
	int16_t		Width;					// 幅
	int16_t		Height;					// 高さ
	uint8_t		Visible;				// 表示有り無し OFF:非表示 ON:表示
	uint8_t		Touch_Enable;			// タッチ可能かどうか
	uint32_t	color;			        // 色
	uint8_t		font_style;				// フォントスタイル
	void		*data;					// データへのポインタ
	TOUCH_CALLBACK touch_callback;		// タッチした場合へのコールバック

	// 実行時に変更されるデータ


	int32_t		tag;					// オブジェクトにつけるメモ
//	uint8_t		l_depth;				// 所属するLayerの深さ(逆探知用)
	uint8_t		auto_lf;				// 自動改行
	void 		*parent_layer;			// 親レイヤーデータ
	void 		*child_layer;			// 子レイヤーデータ
}obj_data_t ;

typedef struct{
	int layer_id;						// 表示中のlayer番号
	obj_data_t *obj;					// layerに存在するオブジェクト一覧
	obj_data_t *parent_obj;				// 親オブジェクト
	int object_num;						// 準備しているオブジェクトの数 実際に使用しているオブジェクトより多い
	int Visible;						// layerのオブジェクトをすべて表示するかどうか
	int Touch_Enable;					// touch可能かどうか
	
	VOID_CALLBACK start_callback;		// 開始時に呼び出すコールバック
	VOID_CALLBACK end_callback;			// 終了時に呼び出すコールバック
	VOID_CALLBACK always_callback;		// 常に呼び出すコールバック

	int x;								// 座標変換
	int y;								// 座標変換
	
	int32_t data[MAX_FREE_LAYER_DATA];	// レイヤー内で自由に使えるデータ



}layer_data_t;



#define			GRAFIC_OBJECT_TYPE_IMG				0			// ROM画像イメージ Zoom不可 Cut可能
#define			GRAFIC_OBJECT_TYPE_BUTTON			1
#define			GRAFIC_OBJECT_TYPE_TEXT				2
#define			GRAFIC_OBJECT_TYPE_RECTANGLE		3
#define			GRAFIC_OBJECT_TYPE_ELLIPSE			4
#define			GRAFIC_OBJECT_TYPE_FILL_ELLIPSE		5
#define			GRAFIC_OBJECT_TYPE_RAM_IMG			6			// RAM画像イメージ Zoom可 Cut可能
#define			GRAFIC_OBJECT_TYPE_CHILD			7
#define			GRAFIC_OBJECT_TYPE_USER_DRAW		8


#define			OBJECT_DRAW_TYPE_NORMAL				0
#define			OBJECT_DRAW_TYPE_ZOOM				1
#define			OBJECT_DRAW_TYPE_CUT				2
#define			OBJECT_DRAW_TYPE_LEFT				3
#define			OBJECT_DRAW_TYPE_RIGHT				4
#define			OBJECT_DRAW_TYPE_CENTER				5

#define			ADD_OBJECT_ID_START					0x10000

extern layer_data_t Graphic_layer[MAX_LAYER];
          

extern void SetOperationLayer(layer_data_t *p_layer);
extern layer_data_t *GetOperationLayer(void);
extern obj_data_t *SearchObj(int obj_id);
extern int SearchLayer(int layer_id);


extern obj_data_t *obj_get_from_id(int obj_id );
extern wchar_t *obj_GetString(int obj_id);
extern void obj_SetString(int obj_id ,const wchar_t *dest_string);
extern void obj_SetString_Number(int obj_id , int number , int flag);
void obj_SetNumber_with_comma(int obj_id , int number);
extern void obj_printf(int obj_id, const wchar_t * restrict format, ...);
extern void obj_set_font_style(int obj_id , int font_style);
//extern void obj_set_font_size(int obj_id , int font_size);
extern void obj_show(int obj_id);
extern void obj_hide(int obj_id);
extern void obj_set_point(int obj_id , int x, int y);
extern void obj_set_x_point(int obj_id , int x);
extern void obj_set_y_point(int obj_id , int y);
extern void obj_move(int obj_id , int x, int y);
extern void obj_set_size(int obj_id , int w, int h);
extern void obj_set_width(int obj_id , int w);
extern void obj_set_height(int obj_id , int h);
extern void obj_set_img(int obj_id , int16_t image_id);
extern int obj_get_img_id(int obj_id);
extern void obj_set_touch_img(int obj_id , int16_t image_id);
extern void obj_set_disable_img(int obj_id , int16_t image_id);

extern void obj_set_color(int obj_id , uint32_t color);
extern void obj_set_touch(int obj_id , int Value);
extern void obj_get_draw_size(int obj_id , Rectangle *rect);
extern void obj_set_tag(int obj_id ,int32_t tag);
extern int obj_get_tag(int obj_id);
extern int obj_search_tag(int32_t tag);
extern void obj_set_type(int obj_id ,int type);
extern void obj_set_auto_lf(int obj_id ,int auto_lf);
extern void obj_move_layer_all(int x, int y);


extern int add_object_img(int x, int y , int image_id , TOUCH_CALLBACK touch);
extern int add_object_rectangle(int x, int y , int w , int h , uint32_t color , TOUCH_CALLBACK touch);
extern int add_object_text(int x, int y  , int draw_type, int font_style , wchar_t *str  , TOUCH_CALLBACK touch);

extern void NewLayer(layer_data_t *layer, int layer_id ,const obj_data_t *obj , int len , VOID_CALLBACK start_call_back , VOID_CALLBACK end_call_back , VOID_CALLBACK always_call_back);
extern void DelLayer(layer_data_t *layer);
extern void ALLLayerDel(void);
extern void LayerSetOffsetXY(int l_depth , int x , int y);
extern void LayerStartRun(layer_data_t *layer);
extern void LayerAlwaysRun(layer_data_t *layer);
extern int32_t *GetChildLayerUserData(int obj_id );
extern int32_t *GetOperationLayerUserData(void );


#endif
