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

static void L_W_CONFIG00_start(void);
static void L_W_CONFIG00_end(void);
static void L_W_CONFIG00_always(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_WARMUP_TEMP00_touch(int obj_id , int touch_type);
static void OBJ_IMG_PROCESS_SW_TIMER00_touch(int obj_id , int touch_type);
static void OBJ_IMG_STEAM_TIMER00_touch(int obj_id , int touch_type);
static void OBJ_IMG_MNS00_touch(int obj_id , int touch_type);
static void OBJ_IMG_HOME00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECTANGLE1883  1883
#define OBJ_TEXT_WARMUP_TEMP00  1888
#define OBJ_TEXT_WARMUP_TEMP01  1889
#define OBJ_TEXT_WARMUP_TEMP02  1890
#define OBJ_TEXT_WARMUP_TEMP03  1891
#define OBJ_IMG_WARMUP_TEMP00  1863
#define OBJ_TEXT_PROCESS_SW_TIMER00  1864
#define OBJ_TEXT_PROCESS_SW_TIMER01  1865
#define OBJ_TEXT_PROCESS_SW_TIMER02  1866
#define OBJ_TEXT_PROCESS_SW_TIMER03  1867
#define OBJ_IMG_PROCESS_SW_TIMER00  1868
#define OBJ_TEXT_STEAM_TIMER00  1869
#define OBJ_TEXT_STEAM_TIMER01  1870
#define OBJ_TEXT_STEAM_TIMER02  1871
#define OBJ_TEXT_STEAM_TIMER03  1872
#define OBJ_IMG_STEAM_TIMER00  1873
#define OBJ_TEXT_MNS00  1874
#define OBJ_TEXT_MNS01  1875
#define OBJ_TEXT_MNS02  1876
#define OBJ_TEXT_MNS03  1877
#define OBJ_IMG_MNS00  1878
#define OBJ_IMG_HOME00  1937
#define OBJ_RECT_SCALE00  1939
#define OBJ_CHILD00  1880

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_WARMUP_TEMP00_TEXT[] = L"○ 運転準備完了温度 (設定温度 -＊＊℃)";
static const wchar_t OBJ_TEXT_WARMUP_TEMP01_TEXT[] = L"初期値： 10 ℃";
static const wchar_t OBJ_TEXT_WARMUP_TEMP02_TEXT[] = L"設定値：　　℃";
static const wchar_t OBJ_TEXT_WARMUP_TEMP03_TEXT[] = L"10";
static const wchar_t OBJ_TEXT_PROCESS_SW_TIMER00_TEXT[] = L"○ 自動運転 工程切替待機時間 ( ＊ 秒)";
static const wchar_t OBJ_TEXT_PROCESS_SW_TIMER01_TEXT[] = L"初期値： 2 秒";
static const wchar_t OBJ_TEXT_PROCESS_SW_TIMER02_TEXT[] = L"設定値：　　秒";
static const wchar_t OBJ_TEXT_PROCESS_SW_TIMER03_TEXT[] = L"2";
static const wchar_t OBJ_TEXT_STEAM_TIMER00_TEXT[] = L"○ 蒸気出力時間 ( ＊ 秒：0秒設定で、押下中出力)";
static const wchar_t OBJ_TEXT_STEAM_TIMER01_TEXT[] = L"初期値： 3 秒";
static const wchar_t OBJ_TEXT_STEAM_TIMER02_TEXT[] = L"設定値：　　秒";
static const wchar_t OBJ_TEXT_STEAM_TIMER03_TEXT[] = L"3";
static const wchar_t OBJ_TEXT_MNS00_TEXT[] = L"○ 手動運転昇温通知設定 (ON / OFF)";
static const wchar_t OBJ_TEXT_MNS01_TEXT[] = L"初期設定： 初回のみ";
static const wchar_t OBJ_TEXT_MNS02_TEXT[] = L"設定値：";
static const wchar_t OBJ_TEXT_MNS03_TEXT[] = L"初回のみ";

static const obj_data_t object_list[24] = {
	{OBJ_RECTANGLE1883,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,15,49,570,950,ON,OFF,0xFF5a5a5a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_WARMUP_TEMP00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,27,113,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_WARMUP_TEMP00_TEXT,NULL},
	{OBJ_TEXT_WARMUP_TEMP01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,63,163,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_WARMUP_TEMP01_TEXT,NULL},
	{OBJ_TEXT_WARMUP_TEMP02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,276,164,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_WARMUP_TEMP02_TEXT,NULL},
	{OBJ_TEXT_WARMUP_TEMP03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,369,164,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_WARMUP_TEMP03_TEXT,NULL},
	{OBJ_IMG_WARMUP_TEMP00,change_button_off,change_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,464,146,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_WARMUP_TEMP00_touch},
	{OBJ_TEXT_PROCESS_SW_TIMER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,27,213,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS_SW_TIMER00_TEXT,NULL},
	{OBJ_TEXT_PROCESS_SW_TIMER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,63,263,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS_SW_TIMER01_TEXT,NULL},
	{OBJ_TEXT_PROCESS_SW_TIMER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,276,264,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS_SW_TIMER02_TEXT,NULL},
	{OBJ_TEXT_PROCESS_SW_TIMER03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,377,264,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS_SW_TIMER03_TEXT,NULL},
	{OBJ_IMG_PROCESS_SW_TIMER00,change_button_off,change_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,464,246,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_PROCESS_SW_TIMER00_touch},
	{OBJ_TEXT_STEAM_TIMER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,27,313,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_STEAM_TIMER00_TEXT,NULL},
	{OBJ_TEXT_STEAM_TIMER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,63,363,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_STEAM_TIMER01_TEXT,NULL},
	{OBJ_TEXT_STEAM_TIMER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,276,364,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_STEAM_TIMER02_TEXT,NULL},
	{OBJ_TEXT_STEAM_TIMER03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,377,364,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_STEAM_TIMER03_TEXT,NULL},
	{OBJ_IMG_STEAM_TIMER00,change_button_off,change_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,464,346,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_STEAM_TIMER00_touch},
	{OBJ_TEXT_MNS00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,27,413,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_MNS00_TEXT,NULL},
	{OBJ_TEXT_MNS01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,63,463,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_MNS01_TEXT,NULL},
	{OBJ_TEXT_MNS02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,276,464,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_MNS02_TEXT,NULL},
	{OBJ_TEXT_MNS03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,355,464,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_MNS03_TEXT,NULL},
	{OBJ_IMG_MNS00,change_button_off,change_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,464,446,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_MNS00_touch},
	{OBJ_IMG_HOME00,logo_home,logo_home,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,510,54,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_HOME00_touch},
	{OBJ_RECT_SCALE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,0,600,1024,OFF,OFF,0xaa555555,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_CHILD00,L_W_SETTING03,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,0,64,64,OFF,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
};

void L_W_CONFIG00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_W_CONFIG00 , object_list , 24 , (VOID_CALLBACK)L_W_CONFIG00_start , (VOID_CALLBACK)L_W_CONFIG00_end , (VOID_CALLBACK)L_W_CONFIG00_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_W_CONFIG00_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_W_CONFIG00_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_W_CONFIG00_always(void)
{
	obj_printf(OBJ_TEXT_WARMUP_TEMP03 , L"%2d", t.warmup_temp );
	obj_printf(OBJ_TEXT_PROCESS_SW_TIMER03 , L"%d", t.process_sw_timer / 1000 );
	obj_printf(OBJ_TEXT_STEAM_TIMER03 , L"%d", t.steam_timer / 1000 );
	
	switch(t.mns){
	case NS_NONE:
		obj_SetString(OBJ_TEXT_MNS03 ,L"通知なし");
		break;
	case NS_FIRST:
		obj_SetString(OBJ_TEXT_MNS03 ,L"初回のみ");
		break;
	case NS_EVERY:
		obj_SetString(OBJ_TEXT_MNS03 ,L"毎回");
		break;
	}

	switch(conf.child){
	case STS_NONE:
		obj_set_touch(OBJ_RECT_SCALE00, false);
		obj_hide(OBJ_RECT_SCALE00);
		obj_set_touch(OBJ_CHILD00, false);
		obj_hide(OBJ_CHILD00);
		break;
	case STS_TRUE:
		obj_set_touch(OBJ_RECT_SCALE00, true);
		obj_show(OBJ_RECT_SCALE00);
		obj_set_touch(OBJ_CHILD00, true);
		obj_show(OBJ_CHILD00);
		break;
	}
}

/**********touch_source**********/


/*
 *          OBJ_IMG_WARMUP_TEMP00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_WARMUP_TEMP00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		conf.mode = CONF_WARMUP_TEMP;
		conf.child = STS_TRUE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_PROCESS_SW_TIMER00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_PROCESS_SW_TIMER00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		conf.mode = CONF_PROCESS_SW_TIMER;
		conf.child = STS_TRUE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_STEAM_TIMER00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_STEAM_TIMER00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		conf.mode = CONF_STEAM_TIMER;
		conf.child = STS_TRUE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_MNS00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_MNS00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(t.mns){
		case NS_NONE:
			t.mns = NS_FIRST;
			break;
		case NS_FIRST:
			t.mns = NS_EVERY;
			break;
		case NS_EVERY:
			t.mns = NS_NONE;
			break;
		}
		T_DataSave();
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
