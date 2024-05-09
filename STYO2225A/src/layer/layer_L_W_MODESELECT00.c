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

static void L_W_MODESELECT00_start(void);
static void L_W_MODESELECT00_end(void);
static void L_W_MODESELECT00_always(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_RETURN00_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT00_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT01_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT02_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT03_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_IMG_WINDOW00  1455
#define OBJ_TEXT_TITLE00  1464
#define OBJ_TEXT_ENDNOTES00  1457
#define OBJ_IMG_RETURN00  1458
#define OBJ_TEXT_RETURN00  1459
#define OBJ_RECT_SELECT00  1465
#define OBJ_RECT_SELECT01  1466
#define OBJ_RECT_SELECT02  1467
#define OBJ_IMG_SELECT00  1460
#define OBJ_IMG_SELECT01  1461
#define OBJ_IMG_SELECT02  1462
#define OBJ_IMG_SELECT03  1463
#define OBJ_TEXT_SELECT00  1468
#define OBJ_TEXT_SELECT01  1471
#define OBJ_TEXT_SELECT02  1470
#define OBJ_TEXT_SELECT03  1469

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_TITLE00_TEXT[] = L"モードを選択";
static const wchar_t OBJ_TEXT_ENDNOTES00_TEXT[] = L"次の画面で一覧から菓子コードを選択して実行します";
static const wchar_t OBJ_TEXT_RETURN00_TEXT[] = L"戻る";
static const wchar_t OBJ_TEXT_SELECT00_TEXT[] = L"詳細確認";
static const wchar_t OBJ_TEXT_SELECT01_TEXT[] = L"コード削除";
static const wchar_t OBJ_TEXT_SELECT02_TEXT[] = L"名称編集";
static const wchar_t OBJ_TEXT_SELECT03_TEXT[] = L"内容編集";

static const obj_data_t object_list[16] = {
	{OBJ_IMG_WINDOW00,modewindow_b,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,14,205,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,80,280,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_TEXT_ENDNOTES00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,75,758,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_ENDNOTES00_TEXT,NULL},
	{OBJ_IMG_RETURN00,return_a_off,return_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,110,375,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RETURN00_touch},
	{OBJ_TEXT_RETURN00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,165,410,200,24,ON,OFF,0,Font36_green,(wchar_t *)&OBJ_TEXT_RETURN00_TEXT,NULL},
	{OBJ_RECT_SELECT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,78,521,444,2,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_SELECT01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,228,522,2,193,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_SELECT02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,373,522,2,193,ON,OFF,0xFF9a9a9a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_SELECT00,codedetail_a_off,codedetail_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,378,329,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT00_touch},
	{OBJ_IMG_SELECT01,codedeleate_a_off,codedeleate_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,88,534,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT01_touch},
	{OBJ_IMG_SELECT02,namechange_a_off,namechange_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,233,534,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT02_touch},
	{OBJ_IMG_SELECT03,contents_a_off,contents_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,378,534,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT03_touch},
	{OBJ_TEXT_SELECT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,444,459,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SELECT00_TEXT,NULL},
	{OBJ_TEXT_SELECT01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,156,664,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SELECT01_TEXT,NULL},
	{OBJ_TEXT_SELECT02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,301,664,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SELECT02_TEXT,NULL},
	{OBJ_TEXT_SELECT03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,444,664,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SELECT03_TEXT,NULL},
};

void L_W_MODESELECT00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_W_MODESELECT00 , object_list , 16 , (VOID_CALLBACK)L_W_MODESELECT00_start , (VOID_CALLBACK)L_W_MODESELECT00_end , (VOID_CALLBACK)L_W_MODESELECT00_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_W_MODESELECT00_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_W_MODESELECT00_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_W_MODESELECT00_always(void)
{
	switch (cl.m_select) {
	case C_MODE_ENTER:
		obj_set_img(OBJ_IMG_SELECT00, codedetail_a_off);
		obj_set_img(OBJ_IMG_SELECT01, codedeleate_a_off);
		obj_set_img(OBJ_IMG_SELECT02, namechange_a_off);
		obj_set_img(OBJ_IMG_SELECT03, contents_a_off);
		obj_set_img(OBJ_IMG_WINDOW00, modewindow_b);
		obj_set_touch(OBJ_IMG_SELECT00, true);
		obj_set_touch(OBJ_IMG_SELECT01, true);
		obj_set_touch(OBJ_IMG_SELECT02, true);
		obj_set_touch(OBJ_IMG_SELECT03, true);
		break;
	case C_MODE_DETAIL:
		obj_set_img(OBJ_IMG_SELECT00, codedetail_b_off);
		obj_set_img(OBJ_IMG_SELECT01, codedeleate_a_off);
		obj_set_img(OBJ_IMG_SELECT02, namechange_a_off);
		obj_set_img(OBJ_IMG_SELECT03, contents_a_off);
		obj_set_img(OBJ_IMG_WINDOW00, modewindow_g);
		obj_set_touch(OBJ_IMG_SELECT00, false);
		obj_set_touch(OBJ_IMG_SELECT01, true);
		obj_set_touch(OBJ_IMG_SELECT02, true);
		obj_set_touch(OBJ_IMG_SELECT03, true);
		break;
	case C_MODE_DELEATE:
		obj_set_img(OBJ_IMG_SELECT00, codedetail_a_off);
		obj_set_img(OBJ_IMG_SELECT01, codedeleate_b_off);
		obj_set_img(OBJ_IMG_SELECT02, namechange_a_off);
		obj_set_img(OBJ_IMG_SELECT03, contents_a_off);
		obj_set_img(OBJ_IMG_WINDOW00, modewindow_r);
		obj_set_touch(OBJ_IMG_SELECT00, true);
		obj_set_touch(OBJ_IMG_SELECT01, false);
		obj_set_touch(OBJ_IMG_SELECT02, true);
		obj_set_touch(OBJ_IMG_SELECT03, true);
		break;
	case C_MODE_NAME:
		obj_set_img(OBJ_IMG_SELECT00, codedetail_a_off);
		obj_set_img(OBJ_IMG_SELECT01, codedeleate_a_off);
		obj_set_img(OBJ_IMG_SELECT02, namechange_b_off);
		obj_set_img(OBJ_IMG_SELECT03, contents_a_off);
		obj_set_img(OBJ_IMG_WINDOW00, modewindow_g);
		obj_set_touch(OBJ_IMG_SELECT00, true);
		obj_set_touch(OBJ_IMG_SELECT01, true);
		obj_set_touch(OBJ_IMG_SELECT02, false);
		obj_set_touch(OBJ_IMG_SELECT03, true);
		break;
	case C_MODE_PROCESS:
		obj_set_img(OBJ_IMG_SELECT00, codedetail_a_off);
		obj_set_img(OBJ_IMG_SELECT01, codedeleate_a_off);
		obj_set_img(OBJ_IMG_SELECT02, namechange_a_off);
		obj_set_img(OBJ_IMG_SELECT03, contents_b_off);
		obj_set_img(OBJ_IMG_WINDOW00, modewindow_g);
		obj_set_touch(OBJ_IMG_SELECT00, true);
		obj_set_touch(OBJ_IMG_SELECT01, true);
		obj_set_touch(OBJ_IMG_SELECT02, true);
		obj_set_touch(OBJ_IMG_SELECT03, false);
		break;
	}
}

/**********touch_source**********/


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
		cl.m_window = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_SELECT00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_SELECT00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.m_select = C_MODE_DETAIL;
		cl.m_window = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

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
		cl.m_select = C_MODE_DELEATE;
		cl.m_window = STS_NONE;
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
		cl.m_select = C_MODE_NAME;
		cl.m_window = STS_NONE;
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
		cl.m_select = C_MODE_PROCESS;
		cl.m_window = STS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
