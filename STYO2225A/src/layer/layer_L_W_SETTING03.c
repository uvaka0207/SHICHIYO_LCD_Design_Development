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

static void L_W_SETTING03_start(void);
static void L_W_SETTING03_end(void);
static void L_W_SETTING03_always(void);
static void ImputValues(int);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_KEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY03_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY04_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY05_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY06_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY07_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY08_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY09_touch(int obj_id , int touch_type);
static void OBJ_IMG_ENTER_touch(int obj_id , int touch_type);
static void OBJ_IMG_RETURN00_touch(int obj_id , int touch_type);
static void OBJ_IMG_DELEATE01_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECTANGLE1879  1879
#define OBJ_IMG_KEY00  1882
#define OBJ_IMG_KEY01  1883
#define OBJ_IMG_KEY02  1884
#define OBJ_IMG_KEY03  1885
#define OBJ_IMG_KEY04  1886
#define OBJ_IMG_KEY05  1887
#define OBJ_IMG_KEY06  1888
#define OBJ_IMG_KEY07  1889
#define OBJ_IMG_KEY08  1890
#define OBJ_IMG_KEY09  1891
#define OBJ_TEXT_KEY00  1892
#define OBJ_TEXT_KEY01  1893
#define OBJ_TEXT_KEY02  1894
#define OBJ_TEXT_KEY03  1895
#define OBJ_TEXT_KEY04  1896
#define OBJ_TEXT_KEY05  1897
#define OBJ_TEXT_KEY06  1898
#define OBJ_TEXT_KEY07  1899
#define OBJ_TEXT_KEY08  1900
#define OBJ_TEXT_KEY09  1901
#define OBJ_IMG_ENTER  1902
#define OBJ_TEXT_ENTER  1903
#define OBJ_IMG_RETURN00  1904
#define OBJ_TEXT_RETURN00  1905
#define OBJ_RECTANGLE1907  1907
#define OBJ_TEXT1906  1906
#define OBJ_TEXT_SETTING_VALLUE00  1908
#define OBJ_IMG_DELEATE01  1909

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_KEY00_TEXT[] = L"1";
static const wchar_t OBJ_TEXT_KEY01_TEXT[] = L"2";
static const wchar_t OBJ_TEXT_KEY02_TEXT[] = L"3";
static const wchar_t OBJ_TEXT_KEY03_TEXT[] = L"4";
static const wchar_t OBJ_TEXT_KEY04_TEXT[] = L"5";
static const wchar_t OBJ_TEXT_KEY05_TEXT[] = L"6";
static const wchar_t OBJ_TEXT_KEY06_TEXT[] = L"7";
static const wchar_t OBJ_TEXT_KEY07_TEXT[] = L"8";
static const wchar_t OBJ_TEXT_KEY08_TEXT[] = L"9";
static const wchar_t OBJ_TEXT_KEY09_TEXT[] = L"0";
static const wchar_t OBJ_TEXT_ENTER_TEXT[] = L"確定";
static const wchar_t OBJ_TEXT_RETURN00_TEXT[] = L"戻る";
static const wchar_t OBJ_TEXT1906_TEXT[] = L"設定値：";
static const wchar_t OBJ_TEXT_SETTING_VALLUE00_TEXT[] = L"0";

static const obj_data_t object_list[29] = {
	{OBJ_RECTANGLE1879,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,50,500,500,450,ON,OFF,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_KEY00,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,72,630,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY00_touch},
	{OBJ_IMG_KEY01,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,168,630,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY01_touch},
	{OBJ_IMG_KEY02,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,264,630,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY02_touch},
	{OBJ_IMG_KEY03,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,360,630,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY03_touch},
	{OBJ_IMG_KEY04,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,456,630,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY04_touch},
	{OBJ_IMG_KEY05,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,72,720,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY05_touch},
	{OBJ_IMG_KEY06,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,168,720,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY06_touch},
	{OBJ_IMG_KEY07,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,264,720,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY07_touch},
	{OBJ_IMG_KEY08,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,360,720,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY08_touch},
	{OBJ_IMG_KEY09,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,456,720,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY09_touch},
	{OBJ_TEXT_KEY00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,92,665,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY00_TEXT,NULL},
	{OBJ_TEXT_KEY01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,188,665,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY01_TEXT,NULL},
	{OBJ_TEXT_KEY02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,284,665,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY02_TEXT,NULL},
	{OBJ_TEXT_KEY03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,380,665,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY03_TEXT,NULL},
	{OBJ_TEXT_KEY04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,476,665,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY04_TEXT,NULL},
	{OBJ_TEXT_KEY05,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,92,755,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY05_TEXT,NULL},
	{OBJ_TEXT_KEY06,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,188,755,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY06_TEXT,NULL},
	{OBJ_TEXT_KEY07,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,284,755,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY07_TEXT,NULL},
	{OBJ_TEXT_KEY08,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,380,755,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY08_TEXT,NULL},
	{OBJ_TEXT_KEY09,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,476,755,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_KEY09_TEXT,NULL},
	{OBJ_IMG_ENTER,enter_a_off,enter_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,330,840,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_ENTER_touch},
	{OBJ_TEXT_ENTER,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,390,875,185,20,ON,OFF,0,Font36_orange,(wchar_t *)&OBJ_TEXT_ENTER_TEXT,NULL},
	{OBJ_IMG_RETURN00,return_a_off,return_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,105,840,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RETURN00_touch},
	{OBJ_TEXT_RETURN00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,160,875,185,20,ON,OFF,0,Font36_green,(wchar_t *)&OBJ_TEXT_RETURN00_TEXT,NULL},
	{OBJ_RECTANGLE1907,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,80,520,250,71,ON,OFF,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT1906,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,95,553,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT1906_TEXT,NULL},
	{OBJ_TEXT_SETTING_VALLUE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,252,553,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_SETTING_VALLUE00_TEXT,NULL},
	{OBJ_IMG_DELEATE01,a_deleate_a_off,a_deleate_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,400,520,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_DELEATE01_touch},
};

void L_W_SETTING03_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_W_SETTING03 , object_list , 29 , (VOID_CALLBACK)L_W_SETTING03_start , (VOID_CALLBACK)L_W_SETTING03_end , (VOID_CALLBACK)L_W_SETTING03_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_W_SETTING03_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_W_SETTING03_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_W_SETTING03_always(void)
{
	obj_printf(OBJ_TEXT_SETTING_VALLUE00 , L"%2d", conf.imput_value );
}

static void ImputValues(int value){
	switch(conf.child){
	case CONF_WARMUP_TEMP:
		if(conf.imput_value == 0){
			conf.imput_value = value;
		}
		else if((conf.imput_value > 0) && (conf.imput_value <= 9)){
			conf.imput_value = conf.imput_value * 10 + value;
		}
		else{
		}
		break;
	case CONF_PROCESS_SW_TIMER:
	case CONF_STEAM_TIMER:
		if(conf.imput_value == 0){
			conf.imput_value = value;
		}
		else{
		}
		break;
	}
}
/**********touch_source**********/


/*
 *          OBJ_IMG_KEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(1);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(2);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(3);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY03をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY03_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(4);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY04をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY04_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(5);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY05をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY05_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(6);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY06をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY06_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(7);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY07をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY07_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(8);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY08をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY08_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(9);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY09をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY09_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ImputValues(0);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_ENTERをタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_ENTER_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(conf.child){
		case CONF_WARMUP_TEMP:
			t.warmup_temp = conf.imput_value;
			break;
		case CONF_PROCESS_SW_TIMER:
			t.process_sw_timer = conf.imput_value * 1000;
			break;
		case CONF_STEAM_TIMER:
			t.steam_timer = conf.imput_value * 1000;
			break;
		}
		T_DataSave();
		conf.imput_value = 0;
		conf.child = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_RETURN00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_RETURN00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		conf.imput_value = 0;
		conf.child = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_DELEATE01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_DELEATE01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		conf.imput_value = 0;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
