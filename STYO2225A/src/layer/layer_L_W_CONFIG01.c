#include "common.h"
#include "stdinx.h"
#include "graphics_ctrl.h"
#include "graphics_obj.h"
#include "layer/layer.h"
#include "font/font_style.h"
#include "image.h"
#include "img/img.h"
#include "timer.h"
#include "touch_check.h"

static void L_W_CONFIG01_start(void);
static void L_W_CONFIG01_end(void);
static void L_W_CONFIG01_always(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_CODELIST_RESET00_touch(int obj_id , int touch_type);
static void OBJ_IMG_SETTING_RESET00_touch(int obj_id , int touch_type);
static void OBJ_IMG_ALL_RESET00_touch(int obj_id , int touch_type);
static void OBJ_IMG_HOME00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECTANGLE1883  1910
#define OBJ_TEXT_RESET00  1911
#define OBJ_TEXT_CODELIST_RESET00  1912
#define OBJ_IMG_CODELIST_RESET00  1915
#define OBJ_TEXT_SETTING_RESET00  1932
#define OBJ_IMG_SETTING_RESET00  1933
#define OBJ_TEXT_ALL_RESET00  1934
#define OBJ_IMG_ALL_RESET00  1935
#define OBJ_CHILD00  1931
#define OBJ_IMG_HOME00  1938

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_RESET00_TEXT[] = L"○ 設定値初期化";
static const wchar_t OBJ_TEXT_CODELIST_RESET00_TEXT[] = L"菓子コードリスト初期化";
static const wchar_t OBJ_TEXT_SETTING_RESET00_TEXT[] = L"設定値初期化";
static const wchar_t OBJ_TEXT_ALL_RESET00_TEXT[] = L"全パラメータ初期化";

static const obj_data_t object_list[10] = {
	{OBJ_RECTANGLE1883,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,15,49,570,950,ON,OFF,0xFF5a5a5a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_RESET00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,27,113,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_RESET00_TEXT,NULL},
	{OBJ_TEXT_CODELIST_RESET00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,63,163,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_CODELIST_RESET00_TEXT,NULL},
	{OBJ_IMG_CODELIST_RESET00,enter_button_off,enter_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,464,146,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_CODELIST_RESET00_touch},
	{OBJ_TEXT_SETTING_RESET00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,63,213,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_SETTING_RESET00_TEXT,NULL},
	{OBJ_IMG_SETTING_RESET00,enter_button_off,enter_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,464,196,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SETTING_RESET00_touch},
	{OBJ_TEXT_ALL_RESET00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,63,263,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_ALL_RESET00_TEXT,NULL},
	{OBJ_IMG_ALL_RESET00,enter_button_off,enter_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,464,246,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_ALL_RESET00_touch},
	{OBJ_CHILD00,L_W_SETTING03,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,0,64,64,OFF,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_HOME00,logo_home,logo_home,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,510,54,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_HOME00_touch},
};

void L_W_CONFIG01_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_W_CONFIG01 , object_list , 10 , (VOID_CALLBACK)L_W_CONFIG01_start , (VOID_CALLBACK)L_W_CONFIG01_end , (VOID_CALLBACK)L_W_CONFIG01_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_W_CONFIG01_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_W_CONFIG01_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_W_CONFIG01_always(void)
{
	
}

/**********touch_source**********/


/*
 *          OBJ_IMG_CODELIST_RESET00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_CODELIST_RESET00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		Initialize_a();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_SETTING_RESET00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_SETTING_RESET00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		Initialize_m();
		Initialize_t();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_ALL_RESET00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_ALL_RESET00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		Initialize_m();
		Initialize_a();
		Initialize_t();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_HOME00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_HOME00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		change_mode(MODE_HOME);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
