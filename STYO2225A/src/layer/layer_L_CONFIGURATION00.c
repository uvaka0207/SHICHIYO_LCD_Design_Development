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

static void L_CONFIGURATION00_start(void);
static void L_CONFIGURATION00_end(void);
static void L_CONFIGURATION00_always(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_SELECT01_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT02_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT03_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_IMG_SELECT01  1878
#define OBJ_IMG_SELECT02  1879
#define OBJ_IMG_SELECT03  1880
#define OBJ_TEXT1875  1875
#define OBJ_TEXT1876  1881
#define OBJ_TEXT1877  1882
#define OBJ_CHILD1884  1884
#define OBJ_CHILD1885  1936

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT1875_TEXT[] = L"設定画面[1]";
static const wchar_t OBJ_TEXT1876_TEXT[] = L"設定画面[2]";
static const wchar_t OBJ_TEXT1877_TEXT[] = L"出荷時設定";

static const obj_data_t object_list[8] = {
	{OBJ_IMG_SELECT01,tab_b_off,tab_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,15,4,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT01_touch},
	{OBJ_IMG_SELECT02,tab_a_off,tab_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,210,4,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT02_touch},
	{OBJ_IMG_SELECT03,tab_a_off,tab_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,405,4,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT03_touch},
	{OBJ_TEXT1875,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,105,27,200,24,ON,OFF,0,Font24_yw,(wchar_t *)&OBJ_TEXT1875_TEXT,NULL},
	{OBJ_TEXT1876,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,300,27,200,24,ON,OFF,0,Font24_G,(wchar_t *)&OBJ_TEXT1876_TEXT,NULL},
	{OBJ_TEXT1877,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,495,27,200,24,ON,OFF,0,Font24_G,(wchar_t *)&OBJ_TEXT1877_TEXT,NULL},
	{OBJ_CHILD1884,L_W_CONFIG00,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,0,64,64,ON,ON,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_CHILD1885,L_W_CONFIG01,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,0,64,64,OFF,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
};

void L_CONFIGURATION00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_CONFIGURATION00 , object_list , 8 , (VOID_CALLBACK)L_CONFIGURATION00_start , (VOID_CALLBACK)L_CONFIGURATION00_end , (VOID_CALLBACK)L_CONFIGURATION00_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_CONFIGURATION00_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_CONFIGURATION00_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_CONFIGURATION00_always(void)
{
	switch(conf.page){
	case 0:
		obj_set_img(OBJ_IMG_SELECT01,tab_b_off);
		obj_set_touch(OBJ_IMG_SELECT01,false);
		obj_set_img(OBJ_IMG_SELECT02,tab_a_off);
		obj_set_touch(OBJ_IMG_SELECT02,true);
		obj_set_img(OBJ_IMG_SELECT03,tab_a_off);
		obj_set_touch(OBJ_IMG_SELECT03,true);
		obj_set_font_style(OBJ_TEXT1875, Font24_yw);
		obj_set_font_style(OBJ_TEXT1876, Font24_G);
		obj_set_font_style(OBJ_TEXT1877, Font24_G);
		obj_show(OBJ_CHILD1884);
		obj_set_touch(OBJ_CHILD1884,true);
		obj_hide(OBJ_CHILD1885);
		obj_set_touch(OBJ_CHILD1885,false);
		break;
	case 1:
		obj_set_img(OBJ_IMG_SELECT01,tab_a_off);
		obj_set_touch(OBJ_IMG_SELECT01,true);
		obj_set_img(OBJ_IMG_SELECT02,tab_b_off);
		obj_set_touch(OBJ_IMG_SELECT02,false);
		obj_set_img(OBJ_IMG_SELECT03,tab_a_off);
		obj_set_touch(OBJ_IMG_SELECT03,true);
		obj_set_font_style(OBJ_TEXT1875, Font24_G);
		obj_set_font_style(OBJ_TEXT1876, Font24_yw);
		obj_set_font_style(OBJ_TEXT1877, Font24_G);
		obj_hide(OBJ_CHILD1884);
		obj_set_touch(OBJ_CHILD1884,false);
		obj_show(OBJ_CHILD1885);
		obj_set_touch(OBJ_CHILD1885,true);
		break;
	case 2:
		break;
	}
}

/**********touch_source**********/


/*
 *          OBJ_IMG_SELECT01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_SELECT01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		conf.page = 0;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_SELECT02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_SELECT02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		conf.page = 1;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_SELECT03をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_SELECT03_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
