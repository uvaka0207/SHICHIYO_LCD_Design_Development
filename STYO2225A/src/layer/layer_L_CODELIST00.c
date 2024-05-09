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

static void L_CODELIST00_start(void);
static void L_CODELIST00_end(void);
static void L_CODELIST00_always(void);
static void L_Migarate_Page00(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_SELECT01_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT02_touch(int obj_id , int touch_type);
static void OBJ_IMG_SELECT03_touch(int obj_id , int touch_type);
static void OBJ_IMG_RIGHT00_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST01_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST02_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST03_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST04_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST05_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST06_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST07_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST08_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST09_touch(int obj_id , int touch_type);
static void OBJ_RECT_LIST10_touch(int obj_id , int touch_type);
static void OBJ_IMG_LEFT00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECT_OUTLINE00  1413
#define OBJ_RECT_EXPLAIN00  918
#define OBJ_RECT_EXPLAIN01  927
#define OBJ_TEXT_EXPLAIN00  919
#define OBJ_RECT_SELECT00  921
#define OBJ_RECT_SELECT01  1414
#define OBJ_RECT_SELECT02  1415
#define OBJ_TEXT_SELECT00  920
#define OBJ_IMG_SELECT01  940
#define OBJ_IMG_SELECT02  941
#define OBJ_IMG_SELECT03  943
#define OBJ_TEXT_SELECT01  928
#define OBJ_TEXT_SELECT02  931
#define OBJ_TEXT_SELECT03  933
#define OBJ_IMG_LEFT00  974
#define OBJ_IMG_RIGHT00  977
#define OBJ_TEXT_TITLE00  117
#define OBJ_TEXT_TITLE01  1681
#define OBJ_TEXT_TITLE02  1682
#define OBJ_RECT_TABLE00  907
#define OBJ_RECT_LIST01  908
#define OBJ_TEXT_LIST01_0  944
#define OBJ_TEXT_LIST01_1  945
#define OBJ_TEXT_LIST01_2  1416
#define OBJ_RECT_LIST02  909
#define OBJ_TEXT_LIST02_0  946
#define OBJ_TEXT_LIST02_1  947
#define OBJ_TEXT_LIST02_2  1417
#define OBJ_RECT_LIST03  1418
#define OBJ_TEXT_LIST03_0  1419
#define OBJ_TEXT_LIST03_1  1420
#define OBJ_TEXT_LIST03_2  1421
#define OBJ_RECT_LIST04  1422
#define OBJ_TEXT_LIST04_0  1423
#define OBJ_TEXT_LIST04_1  1424
#define OBJ_TEXT_LIST04_2  1425
#define OBJ_RECT_LIST05  1426
#define OBJ_TEXT_LIST05_0  1427
#define OBJ_TEXT_LIST05_1  1428
#define OBJ_TEXT_LIST05_2  1429
#define OBJ_RECT_LIST06  1430
#define OBJ_TEXT_LIST06_0  1431
#define OBJ_TEXT_LIST06_1  1432
#define OBJ_TEXT_LIST06_2  1433
#define OBJ_RECT_LIST07  1434
#define OBJ_TEXT_LIST07_0  1435
#define OBJ_TEXT_LIST07_1  1436
#define OBJ_TEXT_LIST07_2  1437
#define OBJ_RECT_LIST08  1438
#define OBJ_TEXT_LIST08_0  1439
#define OBJ_TEXT_LIST08_1  1440
#define OBJ_TEXT_LIST08_2  1441
#define OBJ_RECT_LIST09  1442
#define OBJ_TEXT_LIST09_0  1443
#define OBJ_TEXT_LIST09_1  1444
#define OBJ_TEXT_LIST09_2  1445
#define OBJ_RECT_LIST10  1446
#define OBJ_TEXT_LIST10_0  1447
#define OBJ_TEXT_LIST10_1  1448
#define OBJ_TEXT_LIST10_2  1449
#define OBJ_RECT_SCALE00  1450
#define OBJ_CHILD00  1456

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_EXPLAIN00_TEXT[] = L"コードメニュー -> 菓子コード番号の順で選択";
static const wchar_t OBJ_TEXT_SELECT00_TEXT[] = L"コードメニュー";
static const wchar_t OBJ_TEXT_SELECT01_TEXT[] = L"コード選択";
static const wchar_t OBJ_TEXT_SELECT02_TEXT[] = L"モード選択";
static const wchar_t OBJ_TEXT_SELECT03_TEXT[] = L"ホームへ";
static const wchar_t OBJ_TEXT_TITLE00_TEXT[] = L"菓子コード一覧";
static const wchar_t OBJ_TEXT_TITLE01_TEXT[] = L"(    / 4 )";
static const wchar_t OBJ_TEXT_TITLE02_TEXT[] = L"1";
static const wchar_t OBJ_TEXT_LIST01_0_TEXT[] = L"01";
static const wchar_t OBJ_TEXT_LIST01_1_TEXT[] = L"手動運転選択（固定）";
static const wchar_t OBJ_TEXT_LIST01_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST02_0_TEXT[] = L"02";
static const wchar_t OBJ_TEXT_LIST02_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST02_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST03_0_TEXT[] = L"03";
static const wchar_t OBJ_TEXT_LIST03_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST03_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST04_0_TEXT[] = L"04";
static const wchar_t OBJ_TEXT_LIST04_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST04_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST05_0_TEXT[] = L"05";
static const wchar_t OBJ_TEXT_LIST05_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST05_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST06_0_TEXT[] = L"06";
static const wchar_t OBJ_TEXT_LIST06_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST06_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST07_0_TEXT[] = L"07";
static const wchar_t OBJ_TEXT_LIST07_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST07_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST08_0_TEXT[] = L"08";
static const wchar_t OBJ_TEXT_LIST08_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST08_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST09_0_TEXT[] = L"09";
static const wchar_t OBJ_TEXT_LIST09_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST09_2_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_LIST10_0_TEXT[] = L"10";
static const wchar_t OBJ_TEXT_LIST10_1_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_LIST10_2_TEXT[] = L"：";

static const obj_data_t object_list[62] = {
	{OBJ_RECT_OUTLINE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,0,600,3,ON,OFF,0xFFFFF000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_EXPLAIN00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,205,600,55,ON,OFF,0xFFFFF000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_EXPLAIN01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,260,600,3,ON,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_EXPLAIN00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,30,234,200,24,ON,OFF,0,Font24_black,(wchar_t *)&OBJ_TEXT_EXPLAIN00_TEXT,NULL},
	{OBJ_RECT_SELECT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,190,23,410,3,ON,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_SELECT01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,185,44,1,158,ON,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_SELECT02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,415,44,1,158,ON,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_SELECT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,15,23,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_SELECT00_TEXT,NULL},
	{OBJ_IMG_SELECT01,codehome_a_off,codehome_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,35,52,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT01_touch},
	{OBJ_IMG_SELECT02,modeselect_a_off,modeselect_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,241,52,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT02_touch},
	{OBJ_IMG_SELECT03,home_a_off,home_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,448,52,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SELECT03_touch},
	{OBJ_TEXT_SELECT01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,94,177,100,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SELECT01_TEXT,NULL},
	{OBJ_TEXT_SELECT02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,300,177,200,25,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SELECT02_TEXT,NULL},
	{OBJ_TEXT_SELECT03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,506,177,200,24,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SELECT03_TEXT,NULL},
	{OBJ_IMG_LEFT00,codelist_leftkey,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,345,282,117,137,OFF,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LEFT00_touch},
	{OBJ_IMG_RIGHT00,codelist_rightkey,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,475,282,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RIGHT00_touch},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,50,310,200,24,ON,OFF,0,Font28B,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_TEXT_TITLE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,250,310,200,24,ON,OFF,0,Font28B,(wchar_t *)&OBJ_TEXT_TITLE01_TEXT,NULL},
	{OBJ_TEXT_TITLE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,270,310,200,24,ON,OFF,0,Font28B,(wchar_t *)&OBJ_TEXT_TITLE02_TEXT,NULL},
	{OBJ_RECT_TABLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,33,348,534,653,ON,OFF,0xFF5A5A5A,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_LIST01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,351,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST01_touch},
	{OBJ_TEXT_LIST01_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,382,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST01_0_TEXT,NULL},
	{OBJ_TEXT_LIST01_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,382,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST01_1_TEXT,NULL},
	{OBJ_TEXT_LIST01_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,382,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST01_2_TEXT,NULL},
	{OBJ_RECT_LIST02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,416,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST02_touch},
	{OBJ_TEXT_LIST02_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,447,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST02_0_TEXT,NULL},
	{OBJ_TEXT_LIST02_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,447,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST02_1_TEXT,NULL},
	{OBJ_TEXT_LIST02_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,447,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST02_2_TEXT,NULL},
	{OBJ_RECT_LIST03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,481,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST03_touch},
	{OBJ_TEXT_LIST03_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,512,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST03_0_TEXT,NULL},
	{OBJ_TEXT_LIST03_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,512,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST03_1_TEXT,NULL},
	{OBJ_TEXT_LIST03_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,512,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST03_2_TEXT,NULL},
	{OBJ_RECT_LIST04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,546,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST04_touch},
	{OBJ_TEXT_LIST04_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,577,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST04_0_TEXT,NULL},
	{OBJ_TEXT_LIST04_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,577,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST04_1_TEXT,NULL},
	{OBJ_TEXT_LIST04_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,577,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST04_2_TEXT,NULL},
	{OBJ_RECT_LIST05,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,611,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST05_touch},
	{OBJ_TEXT_LIST05_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,642,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST05_0_TEXT,NULL},
	{OBJ_TEXT_LIST05_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,642,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST05_1_TEXT,NULL},
	{OBJ_TEXT_LIST05_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,642,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST05_2_TEXT,NULL},
	{OBJ_RECT_LIST06,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,676,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST06_touch},
	{OBJ_TEXT_LIST06_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,707,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST06_0_TEXT,NULL},
	{OBJ_TEXT_LIST06_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,707,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST06_1_TEXT,NULL},
	{OBJ_TEXT_LIST06_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,707,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST06_2_TEXT,NULL},
	{OBJ_RECT_LIST07,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,741,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST07_touch},
	{OBJ_TEXT_LIST07_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,772,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST07_0_TEXT,NULL},
	{OBJ_TEXT_LIST07_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,772,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST07_1_TEXT,NULL},
	{OBJ_TEXT_LIST07_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,772,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST07_2_TEXT,NULL},
	{OBJ_RECT_LIST08,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,806,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST08_touch},
	{OBJ_TEXT_LIST08_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,837,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST08_0_TEXT,NULL},
	{OBJ_TEXT_LIST08_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,837,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST08_1_TEXT,NULL},
	{OBJ_TEXT_LIST08_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,837,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST08_2_TEXT,NULL},
	{OBJ_RECT_LIST09,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,871,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST09_touch},
	{OBJ_TEXT_LIST09_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,902,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST09_0_TEXT,NULL},
	{OBJ_TEXT_LIST09_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,902,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST09_1_TEXT,NULL},
	{OBJ_TEXT_LIST09_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,902,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST09_2_TEXT,NULL},
	{OBJ_RECT_LIST10,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,36,936,528,62,ON,ON,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,OBJ_RECT_LIST10_touch},
	{OBJ_TEXT_LIST10_0,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,95,967,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST10_0_TEXT,NULL},
	{OBJ_TEXT_LIST10_1,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,967,185,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST10_1_TEXT,NULL},
	{OBJ_TEXT_LIST10_2,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,110,967,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_LIST10_2_TEXT,NULL},
	{OBJ_RECT_SCALE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,205,600,819,OFF,OFF,0xaa555555,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_CHILD00,L_W_MODESELECT00,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,0,64,64,OFF,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
};

void L_CODELIST00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_CODELIST00 , object_list , 62 , (VOID_CALLBACK)L_CODELIST00_start , (VOID_CALLBACK)L_CODELIST00_end , (VOID_CALLBACK)L_CODELIST00_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_CODELIST00_start(void)
{

}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_CODELIST00_end(void)
{

}

/*
 *		レイヤーの定期処理
 */
static void L_CODELIST00_always(void)
{
	obj_SetString_Number(OBJ_TEXT_LIST01_0, cl.page_no * 10 + 1, 12);
	obj_SetString_Number(OBJ_TEXT_LIST02_0, cl.page_no * 10 + 2, 12);
	obj_SetString_Number(OBJ_TEXT_LIST03_0, cl.page_no * 10 + 3, 12);
	obj_SetString_Number(OBJ_TEXT_LIST04_0, cl.page_no * 10 + 4, 12);
	obj_SetString_Number(OBJ_TEXT_LIST05_0, cl.page_no * 10 + 5, 12);
	obj_SetString_Number(OBJ_TEXT_LIST06_0, cl.page_no * 10 + 6, 12);
	obj_SetString_Number(OBJ_TEXT_LIST07_0, cl.page_no * 10 + 7, 12);
	obj_SetString_Number(OBJ_TEXT_LIST08_0, cl.page_no * 10 + 8, 12);
	obj_SetString_Number(OBJ_TEXT_LIST09_0, cl.page_no * 10 + 9, 12);
	obj_SetString_Number(OBJ_TEXT_LIST10_0, cl.page_no * 10 + 10, 12);

	switch (cl.page_no){
	case 0:
		obj_SetString(OBJ_TEXT_LIST01_1, L"手動運転選択(固定)");
		obj_SetString(OBJ_TEXT_LIST02_1, a.code_name[0]);
		obj_SetString(OBJ_TEXT_LIST03_1, a.code_name[1]);
		obj_SetString(OBJ_TEXT_LIST04_1, a.code_name[2]);
		obj_SetString(OBJ_TEXT_LIST05_1, a.code_name[3]);
		obj_SetString(OBJ_TEXT_LIST06_1, a.code_name[4]);
		obj_SetString(OBJ_TEXT_LIST07_1, a.code_name[5]);
		obj_SetString(OBJ_TEXT_LIST08_1, a.code_name[6]);
		obj_SetString(OBJ_TEXT_LIST09_1, a.code_name[7]);
		obj_SetString(OBJ_TEXT_LIST10_1, a.code_name[8]);
		obj_show(OBJ_IMG_RIGHT00);
		obj_set_touch(OBJ_IMG_RIGHT00,true);
		obj_hide(OBJ_IMG_LEFT00);
		obj_set_touch(OBJ_IMG_LEFT00,false);
		break;
	case 1:
	case 2:
		obj_SetString(OBJ_TEXT_LIST01_1,
				a.code_name[9 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST02_1,
				a.code_name[10 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST03_1,
				a.code_name[11 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST04_1,
				a.code_name[12 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST05_1,
				a.code_name[13 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST06_1,
				a.code_name[14 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST07_1,
				a.code_name[15 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST08_1,
				a.code_name[16 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST09_1,
				a.code_name[17 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST10_1,
				a.code_name[18 + (cl.page_no - 1) * 10]);
		obj_show(OBJ_IMG_RIGHT00);
		obj_set_touch(OBJ_IMG_RIGHT00,true);
		obj_show(OBJ_IMG_LEFT00);
		obj_set_touch(OBJ_IMG_LEFT00,true);
		break;
	case 3:
		obj_SetString(OBJ_TEXT_LIST01_1,
				a.code_name[9 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST02_1,
				a.code_name[10 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST03_1,
				a.code_name[11 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST04_1,
				a.code_name[12 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST05_1,
				a.code_name[13 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST06_1,
				a.code_name[14 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST07_1,
				a.code_name[15 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST08_1,
				a.code_name[16 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST09_1,
				a.code_name[17 + (cl.page_no - 1) * 10]);
		obj_SetString(OBJ_TEXT_LIST10_1,
				a.code_name[18 + (cl.page_no - 1) * 10]);
		obj_hide(OBJ_IMG_RIGHT00);
		obj_set_touch(OBJ_IMG_RIGHT00,false);
		obj_show(OBJ_IMG_LEFT00);
		obj_set_touch(OBJ_IMG_LEFT00,true);
		break;
	default:
		break;
	}

	switch (cl.m_select) {
	case C_MODE_ENTER:
		switch (cl.m_window){
		case STS_TRUE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, modeselect_b_off);
			obj_set_touch(OBJ_IMG_SELECT01, false);
			obj_set_touch(OBJ_IMG_SELECT02, false);
			obj_set_touch(OBJ_IMG_SELECT03, false);
			break;
		case STS_NONE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_b_off);
			obj_set_img(OBJ_IMG_SELECT02, modeselect_a_off);
			obj_set_touch_img(OBJ_IMG_SELECT02, modeselect_a_on);
			obj_set_touch(OBJ_IMG_SELECT01, false);
			obj_set_touch(OBJ_IMG_SELECT02, true);
			obj_set_touch(OBJ_IMG_SELECT03, true);
			break;
		}
		break;
	case C_MODE_DETAIL:
		switch (cl.m_window){
		case STS_TRUE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, codedetail_s_off);
			obj_set_touch(OBJ_IMG_SELECT01, false);
			obj_set_touch(OBJ_IMG_SELECT02, false);
			obj_set_touch(OBJ_IMG_SELECT03, false);
			break;
		case STS_NONE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, codedetail_s_off);
			obj_set_touch_img(OBJ_IMG_SELECT02, codedetail_s_on);
			obj_set_touch(OBJ_IMG_SELECT01, true);
			obj_set_touch(OBJ_IMG_SELECT02, true);
			obj_set_touch(OBJ_IMG_SELECT03, true);
			break;
		}
		break;
	case C_MODE_DELEATE:
		switch (cl.m_window){
		case STS_TRUE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, codedeleate_s_off);
			obj_set_touch(OBJ_IMG_SELECT01, false);
			obj_set_touch(OBJ_IMG_SELECT02, false);
			obj_set_touch(OBJ_IMG_SELECT03, false);
			break;
		case STS_NONE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, codedeleate_s_off);
			obj_set_touch_img(OBJ_IMG_SELECT02, codedeleate_s_on);
			obj_set_touch(OBJ_IMG_SELECT01, true);
			obj_set_touch(OBJ_IMG_SELECT02, true);
			obj_set_touch(OBJ_IMG_SELECT03, true);
			break;
		}
		break;
	case C_MODE_NAME:
		switch (cl.m_window){
		case STS_TRUE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, namechange_s_off);
			obj_set_touch(OBJ_IMG_SELECT01, false);
			obj_set_touch(OBJ_IMG_SELECT02, false);
			obj_set_touch(OBJ_IMG_SELECT03, false);
			break;
		case STS_NONE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, namechange_s_off);
			obj_set_touch_img(OBJ_IMG_SELECT02, namechange_s_on);
			obj_set_touch(OBJ_IMG_SELECT01, true);
			obj_set_touch(OBJ_IMG_SELECT02, true);
			obj_set_touch(OBJ_IMG_SELECT03, true);
			break;
		}
		break;
	case C_MODE_PROCESS:
		switch (cl.m_window){
		case STS_TRUE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, contents_s_off);
			obj_set_touch(OBJ_IMG_SELECT01, false);
			obj_set_touch(OBJ_IMG_SELECT02, false);
			obj_set_touch(OBJ_IMG_SELECT03, false);
			break;
		case STS_NONE:
			obj_set_img(OBJ_IMG_SELECT01, codehome_a_off);
			obj_set_img(OBJ_IMG_SELECT02, contents_s_off);
			obj_set_touch_img(OBJ_IMG_SELECT02, contents_s_on);
			obj_set_touch(OBJ_IMG_SELECT01, true);
			obj_set_touch(OBJ_IMG_SELECT02, true);
			obj_set_touch(OBJ_IMG_SELECT03, true);
			break;
		}
		break;
	}

	switch (cl.m_window) {
	case STS_NONE:
		obj_set_touch(OBJ_CHILD00, false);
		obj_set_touch(OBJ_RECT_SCALE00, false);
		obj_hide(OBJ_CHILD00);
		obj_hide(OBJ_RECT_SCALE00);
		break;
	case STS_TRUE:
		obj_set_touch(OBJ_CHILD00, true);
		obj_set_touch(OBJ_RECT_SCALE00, true);
		obj_show(OBJ_CHILD00);
		obj_show(OBJ_RECT_SCALE00);
		break;
	}
}

/*
 *		押した際の移行先処理
 */
void L_Migarate_Page(void)
{
	switch (cl.m_select) {
	case C_MODE_ENTER:
		switch (cl.code_no_select) {
		case 1:
			h.code_no_now = cl.code_no_select;
			wcsncpy(h.code_name_now,
					L"手動運転(固定)", CODE_NAME_MAX_SIZE);
			h.process_now = 0;
			h.process_max = 0;
			h.time_minute_set = m.time_minute_m;
			h.time_second_set = m.time_second_m;
			h.time_minute_now = 0;
			h.time_second_now = 0;
			h.uh_temp_set = m.uh_temp_m;
			h.lh_temp_set = m.lh_temp_m;
			h.select_m_a = S_MANUAL;
			h.uh_mode_now = m.uh_mode_m;
			h.lh_mode_now = m.lh_mode_m;
			h.damper_sts_now = m.damper_sts_m;
			h.b_t_sts = BTS_NONE;
			break;
		default:
			h.code_no_now = cl.code_no_select;
			wcsncpy(h.code_name_now,
					a.code_name[cl.code_no_select - 2], CODE_NAME_MAX_SIZE);
			h.process_now = 0;
			h.process_max = a.process_max[cl.code_no_select - 2];
			h.uh_temp_set = a.uh_temp[cl.code_no_select - 2][0];
			h.lh_temp_set = a.lh_temp[cl.code_no_select - 2][0];
			h.select_m_a = S_AUTO;
			h.uh_mode_now = a.uh_mode[cl.code_no_select - 2][0];
			h.lh_mode_now = a.lh_mode[cl.code_no_select - 2][0];
			h.damper_sts_now = a.damper_sts[cl.code_no_select - 2][0];
			h.b_t_sts = BTS_NONE;
			break;
		}
		Initialize_cl();
		change_mode(MODE_HOME);
		break;
	case C_MODE_DETAIL:
		switch (cl.code_no_select) {
		case 1:
			break;
		default:
			cl.m_select = C_MODE_ENTER;
			change_mode(MODE_DETAIL);
			break;
		}
		break;
	case C_MODE_DELEATE:
		switch(cl.code_no_select){
		case 1:
			/*PopUp:手動運転は削除できません*/
			break;
		default:
			wmemset(a.code_name[cl.code_no_select - 2],
					L'\0', CODE_NAME_MAX_SIZE);
			a.process_max[cl.code_no_select - 2] = 0;
			for ( int i = 0; i < PROCESS_MAX_SIZE_ZERO_OFF; i++){
				a.time_minute[cl.code_no_select - 2][i] = 0;
				a.time_second[cl.code_no_select - 2][i] = 0;
				a.core_temp_sts[cl.code_no_select - 2][i] = STS_NONE;
				a.steam_sts[cl.code_no_select - 2][i] = STS_NONE;
			}
			for ( int i = 0; i < PROCESS_MAX_SIZE_ZERO_ON; i++){
				a.uh_temp[cl.code_no_select - 2][i]=0;
				a.lh_temp[cl.code_no_select - 2][i]=0;
				a.uh_mode[cl.code_no_select - 2][i]=HIGH;
				a.lh_mode[cl.code_no_select - 2][i]=HIGH;
				a.damper_sts[cl.code_no_select - 2][i]=D_CLOSE;
			}
			cl.m_select = C_MODE_ENTER;
			break;
		}
		break;
	case C_MODE_NAME:
		wcsncpy(k.code_name_prov,
				a.code_name[cl.code_no_select - 2], CODE_NAME_MAX_SIZE);
		k.flicker_count = get_sys_timer();
		cl.m_select = C_MODE_ENTER;
		change_mode(MODE_KEY00);
		break;
	case C_MODE_PROCESS:
		cl.m_select = C_MODE_ENTER;
		ProcessInitialize();
		change_mode(MODE_PROCESS00);
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
		cl.m_select = C_MODE_ENTER;
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
		cl.m_window = STS_TRUE;
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
		change_mode(MODE_HOME);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_RIGHT00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_RIGHT00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.page_no = cl.page_no + 1;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_LEFT00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LEFT00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.page_no = cl.page_no - 1;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 1 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 2 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST03をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST03_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 3 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST04をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST04_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 4 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST05をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST05_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 5 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST06をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST06_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 6 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST07をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST07_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 7 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST08をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST08_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 8 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST09をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST09_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 9 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_RECT_LIST10をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_RECT_LIST10_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.code_no_select = 10 + cl.page_no * 10;
		L_Migarate_Page();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
