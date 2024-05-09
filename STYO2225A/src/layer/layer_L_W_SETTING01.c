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

static void L_W_SETTING01_start(void);
static void L_W_SETTING01_end(void);
static void L_W_SETTING01_always(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_T_UKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_UKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_UKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_LKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_LKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_LKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_RETURN00_touch(int obj_id , int touch_type);
static void OBJ_IMG_ENTER00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECT_BASE00  1366
#define OBJ_RECT_BASE01  1367
#define OBJ_RECT_BASE02  1368
#define OBJ_RECT_BASE03  1369
#define OBJ_RECT_BASE04  1383
#define OBJ_TEXT_TITLE00  1371
#define OBJ_IMG_T_UKEY00  1372
#define OBJ_IMG_T_UKEY01  1373
#define OBJ_IMG_T_UKEY02  1374
#define OBJ_IMG_T_LKEY00  1375
#define OBJ_IMG_T_LKEY01  1376
#define OBJ_IMG_T_LKEY02  1377
#define OBJ_TEXT_T_SET00  1378
#define OBJ_TEXT_T_SET02  1380
#define OBJ_TEXT_T_SET03  1381
#define OBJ_TEXT_T_SET04  1382
#define OBJ_IMG_RETURN00  1384
#define OBJ_TEXT_RETURN00  1401
#define OBJ_IMG_ENTER00  1386
#define OBJ_TEXT_ENTER00  1402

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_TITLE00_TEXT[] = L"時間　設定画面";
static const wchar_t OBJ_TEXT_T_SET00_TEXT[] = L"98";
static const wchar_t OBJ_TEXT_T_SET02_TEXT[] = L"50";
static const wchar_t OBJ_TEXT_T_SET03_TEXT[] = L"\'";
static const wchar_t OBJ_TEXT_T_SET04_TEXT[] = L"\"";
static const wchar_t OBJ_TEXT_RETURN00_TEXT[] = L"戻る";
static const wchar_t OBJ_TEXT_ENTER00_TEXT[] = L"確定";

static const obj_data_t object_list[20] = {
	{OBJ_RECT_BASE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,39,116,522,792,ON,OFF,0x00000000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,49,237,502,550,ON,OFF,0xFFdcc800,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,55,243,490,538,ON,OFF,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,55,314,490,3,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,55,667,490,3,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,90,278,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_IMG_T_UKEY00,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,176,370,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_UKEY00_touch},
	{OBJ_IMG_T_UKEY01,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,263,370,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_UKEY01_touch},
	{OBJ_IMG_T_UKEY02,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,350,370,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_UKEY02_touch},
	{OBJ_IMG_T_LKEY00,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,176,542,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_LKEY00_touch},
	{OBJ_IMG_T_LKEY01,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,263,542,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_LKEY01_touch},
	{OBJ_IMG_T_LKEY02,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,350,542,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_LKEY02_touch},
	{OBJ_TEXT_T_SET00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,345,493,200,50,ON,OFF,0,Font70B,(wchar_t *)&OBJ_TEXT_T_SET00_TEXT,NULL},
	{OBJ_TEXT_T_SET02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,385,501,200,24,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_T_SET02_TEXT,NULL},
	{OBJ_TEXT_T_SET03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,335,482,200,24,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_T_SET03_TEXT,NULL},
	{OBJ_TEXT_T_SET04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,433,482,200,24,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_T_SET04_TEXT,NULL},
	{OBJ_IMG_RETURN00,return_a_off,return_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,105,690,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RETURN00_touch},
	{OBJ_TEXT_RETURN00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,160,725,185,20,ON,OFF,0,Font36_green,(wchar_t *)&OBJ_TEXT_RETURN00_TEXT,NULL},
	{OBJ_IMG_ENTER00,enter_a_off,enter_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,323,690,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_ENTER00_touch},
	{OBJ_TEXT_ENTER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,378,725,185,20,ON,OFF,0,Font36_orange,(wchar_t *)&OBJ_TEXT_ENTER00_TEXT,NULL},
};

void L_W_SETTING01_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_W_SETTING01 , object_list , 20 , (VOID_CALLBACK)L_W_SETTING01_start , (VOID_CALLBACK)L_W_SETTING01_end , (VOID_CALLBACK)L_W_SETTING01_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_W_SETTING01_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_W_SETTING01_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_W_SETTING01_always(void)
{
	obj_SetString_Number(OBJ_TEXT_T_SET00, l_time.time_minute_prov , 12);
	obj_SetString_Number(OBJ_TEXT_T_SET02, l_time.time_second_prov , 12);

}

/**********touch_source**********/


/*
 *          OBJ_IMG_T_UKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_UKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_time.time_minute_prov / 10) {
		case 9:
			l_time.time_minute_prov = l_time.time_minute_prov - 90;
			break;
		default:
			l_time.time_minute_prov = l_time.time_minute_prov + 10;
			break;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_T_UKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_UKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_time.time_minute_prov % 10) {
		case 9:
			l_time.time_minute_prov = l_time.time_minute_prov - 9;
			break;
		default:
			l_time.time_minute_prov = l_time.time_minute_prov + 1;
			break;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_T_UKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_UKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_time.time_second_prov) {
		case 50:
			l_time.time_second_prov = l_time.time_second_prov - 50;
			break;
		default:
			l_time.time_second_prov = l_time.time_second_prov + 10;
			break;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_T_LKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_LKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_time.time_minute_prov / 10) {
		case 0:
			l_time.time_minute_prov = l_time.time_minute_prov + 90;
			break;
		default:
			l_time.time_minute_prov = l_time.time_minute_prov - 10;
			break;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_T_LKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_LKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_time.time_minute_prov % 10) {
		case 0:
			l_time.time_minute_prov = l_time.time_minute_prov + 9;
			break;
		default:
			l_time.time_minute_prov = l_time.time_minute_prov - 1;
			break;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_T_LKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_LKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_time.time_second_prov) {
		case 0:
			l_time.time_second_prov = l_time.time_second_prov + 50;
			break;
		default:
			l_time.time_second_prov = l_time.time_second_prov - 10;
			break;
		}
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
		l_time.time_minute_prov = 0;
		l_time.time_second_prov = 0;
		h.popup_time_sts = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_ENTER00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_ENTER00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		h.time_minute_set = l_time.time_minute_prov;
		h.time_second_set = l_time.time_second_prov;

		switch (h.select_m_a) {
		case S_MANUAL:
			m.time_minute_m = l_time.time_minute_prov;
			m.time_second_m = l_time.time_second_prov;
			M_DataSave();
			break;
		}

		l_time.time_minute_prov = 0;
		l_time.time_second_prov = 0;
		h.popup_time_sts = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
