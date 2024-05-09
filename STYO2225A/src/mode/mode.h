#ifndef  _MODE_H
#define  _MODE_H

#include "graphics_obj.h"
#include "popup.h"


typedef void * (* KEY_CALLBACK)(int key , int type);
typedef void * (* ROTARY_CALLBACK)(int delta);


#define MAX_POPUP				6
#define POPUP_LAYER				(MAX_LAYER - MAX_POPUP)

// 動作モード一覧

enum MODE_ENUM{
	MODE_NONE,					// モードなし
	MODE_HOME,					// 起動画面
	MODE_CODELIST,				// 菓子コード一覧
	MODE_KEY00,
	MODE_KEY01,
	MODE_KEY02,
	MODE_DETAIL,
	MODE_PROCESS00,
	MODE_PROCESS01,
	MODE_CONFIG
};



typedef struct {
	uint32_t background_color;				// 背景色
	
	VOID_CALLBACK always_callback;			// 常に呼び出すコールバック
	VOID_CALLBACK action_callback;			// Actionを動作させるコールバック
	VOID_CALLBACK move_callback;			// このモードから移動する時に動作させるコールバック
	KEY_CALLBACK key_callback;				// ボタンが押された場合のコールバック
	ROTARY_CALLBACK rotary_callback;		// ロータリーエンコーダーが回った場合のコールバック
	
	
	// POPUP専用データ
	int popup;
	POP_CLOSE_CALLBACK pop_close_callback[MAX_POPUP];	// ポップアップを閉じた場合のコールバック
	layer_data_t *pop_call_layer[MAX_POPUP];
	int pop_Touch_Enable[MAX_POPUP][MAX_LAYER];
}mode_data_t ;




typedef struct{
	
	int mode;									// 動作モード
	int next_mode;
	int before_mode;							// 前回モード
	
	
	int layer[MAX_LAYER];
	int layer_old[MAX_LAYER];

	
}mode_value_t;



extern void change_mode_create(void);
extern void change_mode(int mode);
extern void mode_ctrl(void);


extern mode_data_t mode_data;
extern mode_value_t mode;






#endif
