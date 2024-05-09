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

static void L_W_SETTING00_start(void);
static void L_W_SETTING00_end(void);
static void L_W_SETTING00_always(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_UH_MODE00_touch(int obj_id , int touch_type);
static void OBJ_IMG_UH_UKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_UH_UKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_UH_UKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_UH_DKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_UH_DKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_UH_DKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH_MODE00_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH_UKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH_UKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH_UKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH_DKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH_DKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH_DKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_RETURN00_touch(int obj_id , int touch_type);
static void OBJ_IMG_ENTER00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECT_BASE00  1321
#define OBJ_RECT_BASE01  1323
#define OBJ_RECT_BASE02  1324
#define OBJ_RECT_BASE03  1329
#define OBJ_RECT_BASE04  1333
#define OBJ_RECT_BASE05  1344
#define OBJ_TEXT_TITLE00  1330
#define OBJ_IMG_U_HEATER00  1322
#define OBJ_IMG_U_HEATER01  1325
#define OBJ_IMG_U_HEATER02  1326
#define OBJ_IMG_U_HEATER03  1327
#define OBJ_IMG_UH_MODE00  1331
#define OBJ_IMG_UH_UKEY00  1334
#define OBJ_IMG_UH_UKEY01  1335
#define OBJ_IMG_UH_UKEY02  1336
#define OBJ_IMG_UH_DKEY00  1337
#define OBJ_IMG_UH_DKEY01  1338
#define OBJ_IMG_UH_DKEY02  1339
#define OBJ_TEXT_UH_SET00  1340
#define OBJ_TEXT_UH_SET03  1343
#define OBJ_IMG_L_HEATER00  1345
#define OBJ_IMG_L_HEATER01  1346
#define OBJ_IMG_L_HEATER02  1347
#define OBJ_IMG_L_HEATER03  1348
#define OBJ_IMG_LH_MODE00  1350
#define OBJ_IMG_LH_UKEY00  1352
#define OBJ_IMG_LH_UKEY01  1353
#define OBJ_IMG_LH_UKEY02  1354
#define OBJ_IMG_LH_DKEY00  1355
#define OBJ_IMG_LH_DKEY01  1356
#define OBJ_IMG_LH_DKEY02  1357
#define OBJ_TEXT_LH_SET00  1358
#define OBJ_TEXT_LH_SET03  1361
#define OBJ_IMG_RETURN00  1362
#define OBJ_TEXT_RETURN00  1400
#define OBJ_IMG_ENTER00  1364
#define OBJ_TEXT_ENTER00  1399

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_TITLE00_TEXT[] = L"温度/火力　設定画面";
static const wchar_t OBJ_TEXT_UH_SET00_TEXT[] = L"123";
static const wchar_t OBJ_TEXT_UH_SET03_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_LH_SET00_TEXT[] = L"98";
static const wchar_t OBJ_TEXT_LH_SET03_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_RETURN00_TEXT[] = L"戻る";
static const wchar_t OBJ_TEXT_ENTER00_TEXT[] = L"確定";

static const obj_data_t object_list[37] = {
	{OBJ_RECT_BASE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,39,116,522,792,ON,OFF,0x00000000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,49,126,502,772,ON,OFF,0xFFdcc800,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,55,132,490,760,ON,OFF,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,55,203,490,3,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,55,490,490,3,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BASE05,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,55,777,490,3,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,90,165,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_IMG_U_HEATER00,logo_uh,IMG_NONE,logo_uh,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,110,226,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER01,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,112,311,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER02,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,144,311,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER03,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,176,311,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_UH_MODE00,m_select_a_off,m_select_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,110,370,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_MODE00_touch},
	{OBJ_IMG_UH_UKEY00,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,236,226,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_UKEY00_touch},
	{OBJ_IMG_UH_UKEY01,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,318,226,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_UKEY01_touch},
	{OBJ_IMG_UH_UKEY02,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,400,226,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_UKEY02_touch},
	{OBJ_IMG_UH_DKEY00,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,236,398,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_DKEY00_touch},
	{OBJ_IMG_UH_DKEY01,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,318,398,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_DKEY01_touch},
	{OBJ_IMG_UH_DKEY02,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,400,398,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_DKEY02_touch},
	{OBJ_TEXT_UH_SET00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,480,346,200,200,ON,OFF,0,Font70B,(wchar_t *)&OBJ_TEXT_UH_SET00_TEXT,NULL},
	{OBJ_TEXT_UH_SET03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,485,356,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_UH_SET03_TEXT,NULL},
	{OBJ_IMG_L_HEATER00,logo_lh,IMG_NONE,logo_lh,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,110,513,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_L_HEATER01,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,112,598,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_L_HEATER02,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,144,598,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_L_HEATER03,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,176,598,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_LH_MODE00,m_select_a_off,m_select_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,110,657,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_MODE00_touch},
	{OBJ_IMG_LH_UKEY00,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,236,513,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_UKEY00_touch},
	{OBJ_IMG_LH_UKEY01,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,318,513,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_UKEY01_touch},
	{OBJ_IMG_LH_UKEY02,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,400,513,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_UKEY02_touch},
	{OBJ_IMG_LH_DKEY00,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,236,685,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_DKEY00_touch},
	{OBJ_IMG_LH_DKEY01,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,318,685,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_DKEY01_touch},
	{OBJ_IMG_LH_DKEY02,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,400,685,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_DKEY02_touch},
	{OBJ_TEXT_LH_SET00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,480,632,200,24,ON,OFF,0,Font70B,(wchar_t *)&OBJ_TEXT_LH_SET00_TEXT,NULL},
	{OBJ_TEXT_LH_SET03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,485,642,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LH_SET03_TEXT,NULL},
	{OBJ_IMG_RETURN00,return_a_off,enter_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,105,800,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RETURN00_touch},
	{OBJ_TEXT_RETURN00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,160,835,185,20,ON,OFF,0,Font36_green,(wchar_t *)&OBJ_TEXT_RETURN00_TEXT,NULL},
	{OBJ_IMG_ENTER00,enter_a_off,enter_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,323,800,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_ENTER00_touch},
	{OBJ_TEXT_ENTER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,378,835,185,20,ON,OFF,0,Font36_orange,(wchar_t *)&OBJ_TEXT_ENTER00_TEXT,NULL},
};

void L_W_SETTING00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_W_SETTING00 , object_list , 37 , (VOID_CALLBACK)L_W_SETTING00_start , (VOID_CALLBACK)L_W_SETTING00_end , (VOID_CALLBACK)L_W_SETTING00_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_W_SETTING00_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_W_SETTING00_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_W_SETTING00_always(void)
{
	obj_printf(OBJ_TEXT_UH_SET00 , L"%3d" , l_temp.uh_temp_prov);
	obj_printf(OBJ_TEXT_LH_SET00 , L"%3d" , l_temp.lh_temp_prov);

	switch (l_temp.uh_mode_prov) {
	case HIGH:
		obj_set_disable_img(OBJ_IMG_U_HEATER02, logo_mode_on);
		obj_set_disable_img(OBJ_IMG_U_HEATER03, logo_mode_on);
		break;
	case MEDIUM:
		obj_set_disable_img(OBJ_IMG_U_HEATER02, logo_mode_on);
		obj_set_disable_img(OBJ_IMG_U_HEATER03, logo_mode_off);
		break;
	case LOW:
		obj_set_disable_img(OBJ_IMG_U_HEATER02, logo_mode_off);
		obj_set_disable_img(OBJ_IMG_U_HEATER03, logo_mode_off);
		break;
	}

	switch (l_temp.lh_mode_prov) {
	case HIGH:
		obj_set_disable_img(OBJ_IMG_L_HEATER02, logo_mode_on);
		obj_set_disable_img(OBJ_IMG_L_HEATER03, logo_mode_on);
		break;
	case MEDIUM:
		obj_set_disable_img(OBJ_IMG_L_HEATER02, logo_mode_on);
		obj_set_disable_img(OBJ_IMG_L_HEATER03, logo_mode_off);
		break;
	case LOW:
		obj_set_disable_img(OBJ_IMG_L_HEATER02, logo_mode_off);
		obj_set_disable_img(OBJ_IMG_L_HEATER03, logo_mode_off);
		break;
	}
}

/**********touch_source**********/


/*
 *          OBJ_IMG_UH_MODE00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH_MODE00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.uh_mode_prov) {
		case HIGH:
			l_temp.uh_mode_prov = MEDIUM;
			break;
		case MEDIUM:
			l_temp.uh_mode_prov = LOW;
			break;
		case LOW:
			l_temp.uh_mode_prov = HIGH;
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
 *          OBJ_IMG_UH_UKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH_UKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.uh_temp_prov / 100) {
		case 2:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov - 200;
			break;
		default:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov + 100;
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
 *          OBJ_IMG_UH_UKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH_UKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.uh_temp_prov % 100 / 10) {
		case 9:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov - 90;
			break;
		default:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov + 10;
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
 *          OBJ_IMG_UH_UKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH_UKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.uh_temp_prov % 100 % 10) {
		case 9:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov - 9;
			break;
		default:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov + 1;
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
 *          OBJ_IMG_UH_DKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH_DKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.uh_temp_prov / 100) {
		case 0:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov + 200;
			break;
		default:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov - 100;
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
 *          OBJ_IMG_UH_DKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH_DKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.uh_temp_prov % 100 / 10) {
		case 0:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov + 90;
			break;
		default:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov - 10;
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
 *          OBJ_IMG_UH_DKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH_DKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.uh_temp_prov % 100 % 10) {
		case 0:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov + 9;
			break;
		default:
			l_temp.uh_temp_prov = l_temp.uh_temp_prov - 1;
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
 *          OBJ_IMG_LH_MODE00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH_MODE00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.lh_mode_prov) {
		case HIGH:
			l_temp.lh_mode_prov = MEDIUM;
			break;
		case MEDIUM:
			l_temp.lh_mode_prov = LOW;
			break;
		case LOW:
			l_temp.lh_mode_prov = HIGH;
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
 *          OBJ_IMG_LH_UKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH_UKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.lh_temp_prov / 100) {
		case 2:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov - 200;
			break;
		default:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov + 100;
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
 *          OBJ_IMG_LH_UKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH_UKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.lh_temp_prov % 100 / 10) {
		case 9:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov - 90;
			break;
		default:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov + 10;
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
 *          OBJ_IMG_LH_UKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH_UKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.lh_temp_prov % 100 % 10) {
		case 9:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov - 9;
			break;
		default:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov + 1;
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
 *          OBJ_IMG_LH_DKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH_DKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(l_temp.lh_temp_prov/ 100) {
		case 0:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov + 200;
			break;
		default:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov - 100;
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
 *          OBJ_IMG_LH_DKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH_DKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.lh_temp_prov % 100 / 10) {
		case 0:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov + 90;
			break;
		default:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov - 10;
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
 *          OBJ_IMG_LH_DKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH_DKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (l_temp.lh_temp_prov % 100 % 10) {
		case 0:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov + 9;
			break;
		default:
			l_temp.lh_temp_prov = l_temp.lh_temp_prov - 1;
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
		l_temp.uh_temp_prov = 0;
		l_temp.lh_temp_prov = 0;
		l_temp.uh_mode_prov = HIGH;
		l_temp.lh_mode_prov = HIGH;
		h.popup_temp_sts = STS_NONE;
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
		h.uh_temp_set = l_temp.uh_temp_prov;
		h.lh_temp_set = l_temp.lh_temp_prov;
		h.uh_mode_now = l_temp.uh_mode_prov;
		h.lh_mode_now = l_temp.lh_mode_prov;

		switch (h.select_m_a) {
		case S_MANUAL:
			m.uh_temp_m = l_temp.uh_temp_prov;
			m.lh_temp_m = l_temp.lh_temp_prov;
			m.uh_mode_m = l_temp.uh_mode_prov;
			m.lh_mode_m = l_temp.lh_mode_prov;
			M_DataSave();
			break;
		}

		l_temp.uh_temp_prov = 0;
		l_temp.lh_temp_prov = 0;
		l_temp.uh_mode_prov = HIGH;
		l_temp.lh_mode_prov = HIGH;
		h.popup_temp_sts = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
