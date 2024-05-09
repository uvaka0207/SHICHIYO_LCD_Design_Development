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

static void L_HOME00_start(void);
static void L_HOME00_end(void);
static void L_HOME00_always(void);
static void BakeTimerStatus(void);

/*
 * タッチ用関数のプロトタイプ宣言があるオブジェクトがタッチの動作が作られていると認識します。
 * 下記の「touch_prototype」部分で囲まれている宣言部をプロトタイプ宣言として認識します。
 * オブジェクトの関数作成して編集を押すと自動で生成されます。
 */
/**********touch_prototype(start)**********/
static void OBJ_IMG_SKIP00_touch(int obj_id , int touch_type);
static void OBJ_IMG_TIME00_touch(int obj_id , int touch_type);
static void OBJ_IMG_UH00_touch(int obj_id , int touch_type);
static void OBJ_IMG_LH00_touch(int obj_id , int touch_type);
static void OBJ_IMG_CLEAR00_touch(int obj_id , int touch_type);
static void OBJ_IMG_BUZZER00_touch(int obj_id , int touch_type);
static void OBJ_IMG_N_DAMPER00_touch(int obj_id , int touch_type);
static void OBJ_IMG_C_TEMP00_touch(int obj_id , int touch_type);
static void OBJ_IMG_RECIPE00_touch(int obj_id , int touch_type);
static void OBJ_IMG_START00_touch(int obj_id , int touch_type);
static void OBJ_IMG_A_DAMPER00_touch(int obj_id , int touch_type);
static void OBJ_IMG_STEAM00_touch(int obj_id , int touch_type);
static void OBJ_IMG_LAMP00_touch(int obj_id , int touch_type);
static void OBJ_IMG_ECO00_touch(int obj_id , int touch_type);
static void OBJ_IMG_MORNING00_touch(int obj_id , int touch_type);
static void OBJ_IMG_OPTION00_touch(int obj_id , int touch_type);
static void OBJ_IMG_TIME_OR_C_TEMP00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECT_TITLE00  10
#define OBJ_RECT_TITLE01  12
#define OBJ_RECT_TITLE02  13
#define OBJ_TEXT_TITLE00  5
#define OBJ_TEXT_TITLE01  14
#define OBJ_TEXT_TITLE02  15
#define OBJ_IMG_SKIP00  109
#define OBJ_TEXT_SKIP00  906
#define OBJ_TEXT_PROCESS00  17
#define OBJ_TEXT_PROCESS01  20
#define OBJ_TEXT_PROCESS02  21
#define OBJ_TEXT_PROCESS03  22
#define OBJ_TEXT_PROCESS04  23
#define OBJ_TEXT_PROCESS05  24
#define OBJ_TEXT_PROCESS06  25
#define OBJ_TEXT_PROCESS07  26
#define OBJ_TEXT_PROCESS08  27
#define OBJ_TEXT_PROCESS09  28
#define OBJ_TEXT_PROCESS10  29
#define OBJ_TEXT_PROCESS11  30
#define OBJ_TEXT_PROCESS12  31
#define OBJ_TEXT_PROCESS13  32
#define OBJ_TEXT_PROCESS14  33
#define OBJ_TEXT_PROCESS15  34
#define OBJ_TEXT_PROCESS16  35
#define OBJ_TEXT_PROCESS17  36
#define OBJ_TEXT_PROCESS18  37
#define OBJ_IMG_TIME_OR_C_TEMP00  1
#define OBJ_IMG_TIME_OR_C_TEMP01  53
#define OBJ_TEXT_TIME00  56
#define OBJ_TEXT_TIME01  57
#define OBJ_TEXT_TIME02  59
#define OBJ_TEXT_TIME03  60
#define OBJ_TEXT_TIME04  61
#define OBJ_TEXT_TIME05  62
#define OBJ_TEXT_TIME06  64
#define OBJ_TEXT_TIME07  65
#define OBJ_TEXT_TIME08  66
#define OBJ_TEXT_C_TEMP10  1709
#define OBJ_TEXT_C_TEMP11  1710
#define OBJ_TEXT_C_TEMP15  1858
#define OBJ_TEXT_C_TEMP16  1859
#define OBJ_TEXT_C_TEMP12  1711
#define OBJ_TEXT_C_TEMP13  1712
#define OBJ_TEXT_C_TEMP14  1713
#define OBJ_IMG_UH00  38
#define OBJ_IMG_UH01  54
#define OBJ_IMG_UH02  1389
#define OBJ_IMG_UH03  1390
#define OBJ_IMG_UH04  1391
#define OBJ_TEXT_UH00  67
#define OBJ_TEXT_UH01  68
#define OBJ_TEXT_UH02  69
#define OBJ_TEXT_UH03  70
#define OBJ_TEXT_UH04  71
#define OBJ_IMG_LH00  39
#define OBJ_IMG_LH01  1392
#define OBJ_IMG_LH02  1393
#define OBJ_IMG_LH03  1394
#define OBJ_IMG_LH04  1395
#define OBJ_TEXT_LH00  72
#define OBJ_TEXT_LH01  73
#define OBJ_TEXT_LH02  74
#define OBJ_TEXT_LH03  75
#define OBJ_TEXT_LH04  76
#define OBJ_IMG_CLEAR00  78
#define OBJ_TEXT_CLEAR00  79
#define OBJ_IMG_BUZZER00  84
#define OBJ_TEXT_BUZZER00  85
#define OBJ_IMG_N_DAMPER00  91
#define OBJ_TEXT_N_DAMPER00  93
#define OBJ_IMG_C_TEMP00  92
#define OBJ_TEXT_C_TEMP00  94
#define OBJ_IMG_RECIPE00  81
#define OBJ_TEXT_RECIPE00  82
#define OBJ_IMG_START00  87
#define OBJ_TEXT_START00  88
#define OBJ_IMG_A_DAMPER00  97
#define OBJ_TEXT_A_DAMPER00  99
#define OBJ_IMG_STEAM00  98
#define OBJ_TEXT_STEAM00  100
#define OBJ_RECT_COMMENT00  101
#define OBJ_RECT_COMMENT01  103
#define OBJ_IMG_COMMENT00  102
#define OBJ_IMG_COMMENT01  104
#define OBJ_IMG_LAMP00  112
#define OBJ_TEXT_LAMP00  113
#define OBJ_IMG_ECO00  115
#define OBJ_TEXT_ECO00  116
#define OBJ_IMG_MORNING00  106
#define OBJ_TEXT_MORNING00  107
#define OBJ_IMG_OPTION00  905
#define OBJ_TEXT_OPTION00  110
#define OBJ_RECT_SCALE00  1388
#define OBJ_CHILD00  1365
#define OBJ_CHILD01  1396
#define OBJ_CHILD02  1714

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_TITLE00_TEXT[] = L"00";
static const wchar_t OBJ_TEXT_TITLE01_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_TITLE02_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_SKIP00_TEXT[] = L"工程省略";
static const wchar_t OBJ_TEXT_PROCESS00_TEXT[] = L"0";
static const wchar_t OBJ_TEXT_PROCESS01_TEXT[] = L"1";
static const wchar_t OBJ_TEXT_PROCESS02_TEXT[] = L"2";
static const wchar_t OBJ_TEXT_PROCESS03_TEXT[] = L"3";
static const wchar_t OBJ_TEXT_PROCESS04_TEXT[] = L"4";
static const wchar_t OBJ_TEXT_PROCESS05_TEXT[] = L"5";
static const wchar_t OBJ_TEXT_PROCESS06_TEXT[] = L"6";
static const wchar_t OBJ_TEXT_PROCESS07_TEXT[] = L"7";
static const wchar_t OBJ_TEXT_PROCESS08_TEXT[] = L"8";
static const wchar_t OBJ_TEXT_PROCESS09_TEXT[] = L"9";
static const wchar_t OBJ_TEXT_PROCESS10_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS11_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS12_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS13_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS14_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS15_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS16_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS17_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_PROCESS18_TEXT[] = L"⇒";
static const wchar_t OBJ_TEXT_TIME00_TEXT[] = L"設定時間";
static const wchar_t OBJ_TEXT_TIME01_TEXT[] = L"12";
static const wchar_t OBJ_TEXT_TIME02_TEXT[] = L"\"";
static const wchar_t OBJ_TEXT_TIME03_TEXT[] = L"00";
static const wchar_t OBJ_TEXT_TIME04_TEXT[] = L"\'";
static const wchar_t OBJ_TEXT_TIME05_TEXT[] = L"0";
static const wchar_t OBJ_TEXT_TIME06_TEXT[] = L"\'";
static const wchar_t OBJ_TEXT_TIME07_TEXT[] = L"20";
static const wchar_t OBJ_TEXT_TIME08_TEXT[] = L"\"";
static const wchar_t OBJ_TEXT_C_TEMP10_TEXT[] = L"芯温設定温度";
static const wchar_t OBJ_TEXT_C_TEMP11_TEXT[] = L"88";
static const wchar_t OBJ_TEXT_C_TEMP15_TEXT[] = L"8";
static const wchar_t OBJ_TEXT_C_TEMP16_TEXT[] = L".";
static const wchar_t OBJ_TEXT_C_TEMP12_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_C_TEMP13_TEXT[] = L"75.0";
static const wchar_t OBJ_TEXT_C_TEMP14_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_UH00_TEXT[] = L"上火設定温度";
static const wchar_t OBJ_TEXT_UH01_TEXT[] = L"200";
static const wchar_t OBJ_TEXT_UH02_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_UH03_TEXT[] = L"201";
static const wchar_t OBJ_TEXT_UH04_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_LH00_TEXT[] = L"下火設定温度";
static const wchar_t OBJ_TEXT_LH01_TEXT[] = L"200";
static const wchar_t OBJ_TEXT_LH02_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_LH03_TEXT[] = L"199";
static const wchar_t OBJ_TEXT_LH04_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_CLEAR00_TEXT[] = L"クリア";
static const wchar_t OBJ_TEXT_BUZZER00_TEXT[] = L"ブザー切";
static const wchar_t OBJ_TEXT_N_DAMPER00_TEXT[] = L"自然排気";
static const wchar_t OBJ_TEXT_C_TEMP00_TEXT[] = L"芯温";
static const wchar_t OBJ_TEXT_RECIPE00_TEXT[] = L"レシピ設定";
static const wchar_t OBJ_TEXT_START00_TEXT[] = L"スタート";
static const wchar_t OBJ_TEXT_A_DAMPER00_TEXT[] = L"強制排気";
static const wchar_t OBJ_TEXT_STEAM00_TEXT[] = L"蒸気";
static const wchar_t OBJ_TEXT_LAMP00_TEXT[] = L"炉内照明";
static const wchar_t OBJ_TEXT_ECO00_TEXT[] = L"エコモード";
static const wchar_t OBJ_TEXT_MORNING00_TEXT[] = L"おはよう";
static const wchar_t OBJ_TEXT_OPTION00_TEXT[] = L"設定/表示";

static const obj_data_t object_list[97] = {
	{OBJ_RECT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,0,600,104,ON,OFF,0xFF007A44,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_TITLE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,99,600,3,ON,OFF,0xFF005030,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_TITLE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,2,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,50,30,50,33,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_TEXT_TITLE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,85,30,41,36,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE01_TEXT,NULL},
	{OBJ_TEXT_TITLE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,100,30,500,46,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE02_TEXT,NULL},
	{OBJ_IMG_SKIP00,skip_a_off,skip_a_on,skip_a_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,501,16,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_SKIP00_touch},
	{OBJ_TEXT_SKIP00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,545,80,50,33,ON,OFF,0,Font20,(wchar_t *)&OBJ_TEXT_SKIP00_TEXT,NULL},
	{OBJ_TEXT_PROCESS00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,30,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS00_TEXT,NULL},
	{OBJ_TEXT_PROCESS01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,80,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS01_TEXT,NULL},
	{OBJ_TEXT_PROCESS02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,130,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS02_TEXT,NULL},
	{OBJ_TEXT_PROCESS03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,180,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS03_TEXT,NULL},
	{OBJ_TEXT_PROCESS04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,230,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS04_TEXT,NULL},
	{OBJ_TEXT_PROCESS05,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,280,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS05_TEXT,NULL},
	{OBJ_TEXT_PROCESS06,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,330,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS06_TEXT,NULL},
	{OBJ_TEXT_PROCESS07,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,380,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS07_TEXT,NULL},
	{OBJ_TEXT_PROCESS08,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,430,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS08_TEXT,NULL},
	{OBJ_TEXT_PROCESS09,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,480,75,50,36,ON,OFF,0,Font32,(wchar_t *)&OBJ_TEXT_PROCESS09_TEXT,NULL},
	{OBJ_TEXT_PROCESS10,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,55,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS10_TEXT,NULL},
	{OBJ_TEXT_PROCESS11,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,105,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS11_TEXT,NULL},
	{OBJ_TEXT_PROCESS12,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,155,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS12_TEXT,NULL},
	{OBJ_TEXT_PROCESS13,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,205,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS13_TEXT,NULL},
	{OBJ_TEXT_PROCESS14,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,255,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS14_TEXT,NULL},
	{OBJ_TEXT_PROCESS15,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,305,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS15_TEXT,NULL},
	{OBJ_TEXT_PROCESS16,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,355,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS16_TEXT,NULL},
	{OBJ_TEXT_PROCESS17,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,405,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS17_TEXT,NULL},
	{OBJ_TEXT_PROCESS18,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,455,75,50,36,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS18_TEXT,NULL},
	{OBJ_IMG_TIME_OR_C_TEMP00,c_setting_a_off,c_setting_a_on,c_setting_c_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,32,127,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_TIME_OR_C_TEMP00_touch},
	{OBJ_IMG_TIME_OR_C_TEMP01,logo_timer1,IMG_NONE,logo_timer1,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,40,135,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TIME00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,150,100,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_TIME00_TEXT,NULL},
	{OBJ_TEXT_TIME01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,175,190,80,32,OFF,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_TIME01_TEXT,NULL},
	{OBJ_TEXT_TIME02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,225,185,80,32,OFF,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_TIME02_TEXT,NULL},
	{OBJ_TEXT_TIME03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,227,192,75,32,OFF,OFF,0,Font28A,(wchar_t *)&OBJ_TEXT_TIME03_TEXT,NULL},
	{OBJ_TEXT_TIME04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,175,185,80,32,OFF,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_TIME04_TEXT,NULL},
	{OBJ_TEXT_TIME05,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,145,270,80,27,OFF,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_TIME05_TEXT,NULL},
	{OBJ_TEXT_TIME06,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,145,260,80,27,OFF,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_TIME06_TEXT,NULL},
	{OBJ_TEXT_TIME07,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,250,275,80,27,OFF,OFF,0,Font60A,(wchar_t *)&OBJ_TEXT_TIME07_TEXT,NULL},
	{OBJ_TEXT_TIME08,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,245,260,80,27,OFF,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_TIME08_TEXT,NULL},
	{OBJ_TEXT_C_TEMP10,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,150,100,24,OFF,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_C_TEMP10_TEXT,NULL},
	{OBJ_TEXT_C_TEMP11,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,190,191,55,32,ON,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_C_TEMP11_TEXT,NULL},
	{OBJ_TEXT_C_TEMP15,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,220,191,55,32,ON,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_C_TEMP15_TEXT,NULL},
	{OBJ_TEXT_C_TEMP16,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_RIGHT,200,191,55,32,ON,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_C_TEMP16_TEXT,NULL},
	{OBJ_TEXT_C_TEMP12,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,225,193,55,32,ON,OFF,0,Font28A,(wchar_t *)&OBJ_TEXT_C_TEMP12_TEXT,NULL},
	{OBJ_TEXT_C_TEMP13,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,130,273,80,27,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_C_TEMP13_TEXT,NULL},
	{OBJ_TEXT_C_TEMP14,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,220,278,55,32,ON,OFF,0,Font60A,(wchar_t *)&OBJ_TEXT_C_TEMP14_TEXT,NULL},
	{OBJ_IMG_UH00,c_setting_a_off,c_setting_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,32,339,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH00_touch},
	{OBJ_IMG_UH01,logo_u_or_l_s,IMG_NONE,logo_u_or_l_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,40,355,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_UH02,logo_mode_on_s,IMG_NONE,logo_mode_on_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,40,375,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_UH03,logo_mode_on_s,IMG_NONE,logo_mode_on_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,68,375,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_UH04,logo_mode_on_s,IMG_NONE,logo_mode_on_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,96,375,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_UH00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,363,100,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_UH00_TEXT,NULL},
	{OBJ_TEXT_UH01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,180,403,55,32,ON,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_UH01_TEXT,NULL},
	{OBJ_TEXT_UH02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,225,405,55,32,ON,OFF,0,Font28A,(wchar_t *)&OBJ_TEXT_UH02_TEXT,NULL},
	{OBJ_TEXT_UH03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,140,480,80,27,ON,OFF,0,Font80A,(wchar_t *)&OBJ_TEXT_UH03_TEXT,NULL},
	{OBJ_TEXT_UH04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,220,490,55,32,ON,OFF,0,Font60A,(wchar_t *)&OBJ_TEXT_UH04_TEXT,NULL},
	{OBJ_IMG_LH00,c_setting_a_off,c_setting_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,32,551,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH00_touch},
	{OBJ_IMG_LH01,logo_u_or_l_s,IMG_NONE,logo_u_or_l_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,40,620,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_LH02,logo_mode_on_s,IMG_NONE,logo_mode_on_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,40,567,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_LH03,logo_mode_on_s,IMG_NONE,logo_mode_on_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,68,567,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_LH04,logo_mode_on_s,IMG_NONE,logo_mode_on_s,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,96,567,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_LH00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,130,575,100,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_LH00_TEXT,NULL},
	{OBJ_TEXT_LH01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,180,615,55,32,ON,OFF,0,Font32A,(wchar_t *)&OBJ_TEXT_LH01_TEXT,NULL},
	{OBJ_TEXT_LH02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,225,617,55,32,ON,OFF,0,Font28A,(wchar_t *)&OBJ_TEXT_LH02_TEXT,NULL},
	{OBJ_TEXT_LH03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,140,692,80,27,ON,OFF,0,Font80A,(wchar_t *)&OBJ_TEXT_LH03_TEXT,NULL},
	{OBJ_TEXT_LH04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,220,702,55,32,ON,OFF,0,Font60A,(wchar_t *)&OBJ_TEXT_LH04_TEXT,NULL},
	{OBJ_IMG_CLEAR00,clear_a_off,clear_a_on,clear_c_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,306,127,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_CLEAR00_touch},
	{OBJ_TEXT_CLEAR00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,368,245,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_CLEAR00_TEXT,NULL},
	{OBJ_IMG_BUZZER00,buzzer_b_off,buzzer_b_on,buzzer_c_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,306,286,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_BUZZER00_touch},
	{OBJ_TEXT_BUZZER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,368,404,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_BUZZER00_TEXT,NULL},
	{OBJ_IMG_N_DAMPER00,n_damper_a_off,n_damper_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,306,445,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_N_DAMPER00_touch},
	{OBJ_TEXT_N_DAMPER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,368,563,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_N_DAMPER00_TEXT,NULL},
	{OBJ_IMG_C_TEMP00,c_temp_a_off,c_temp_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,306,604,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_C_TEMP00_touch},
	{OBJ_TEXT_C_TEMP00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,368,722,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_C_TEMP00_TEXT,NULL},
	{OBJ_IMG_RECIPE00,recipe_a_off,recipe_a_on,recipe_c_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,443,127,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RECIPE00_touch},
	{OBJ_TEXT_RECIPE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,505,245,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_RECIPE00_TEXT,NULL},
	{OBJ_IMG_START00,start_a_off,start_a_on,start_c_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,443,286,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_START00_touch},
	{OBJ_TEXT_START00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,505,404,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_START00_TEXT,NULL},
	{OBJ_IMG_A_DAMPER00,a_damper_a_off,a_damper_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,443,445,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_A_DAMPER00_touch},
	{OBJ_TEXT_A_DAMPER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,505,563,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_A_DAMPER00_TEXT,NULL},
	{OBJ_IMG_STEAM00,steam_a_off,steam_a_on,steam_b_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,443,604,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_STEAM00_touch},
	{OBJ_TEXT_STEAM00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,505,722,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_STEAM00_TEXT,NULL},
	{OBJ_RECT_COMMENT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,763,600,86,ON,OFF,0xFF5A5A5A,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_COMMENT01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,766,600,80,ON,OFF,0xFF000000,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_COMMENT00,logo_shichiyo,IMG_NONE,logo_shichiyo,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,25,766,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_COMMENT01,logo_ecobacken,IMG_NONE,logo_ecobacken,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,166,766,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_LAMP00,lamp_a_off,lamp_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,32,865,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LAMP00_touch},
	{OBJ_TEXT_LAMP00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,94,983,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_LAMP00_TEXT,NULL},
	{OBJ_IMG_ECO00,eco_a_off,eco_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,169,865,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_ECO00_touch},
	{OBJ_TEXT_ECO00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,231,983,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_ECO00_TEXT,NULL},
	{OBJ_IMG_MORNING00,morning_a_off,morning_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,306,865,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_MORNING00_touch},
	{OBJ_TEXT_MORNING00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,368,983,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_MORNING00_TEXT,NULL},
	{OBJ_IMG_OPTION00,option_a_off,option_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,443,865,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_OPTION00_touch},
	{OBJ_TEXT_OPTION00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,505,983,117,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_OPTION00_TEXT,NULL},
	{OBJ_RECT_SCALE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,0,600,1024,OFF,OFF,0xaa555555,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_CHILD00,L_W_SETTING00,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,50,64,64,OFF,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_CHILD01,L_W_SETTING01,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,50,64,64,OFF,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_CHILD02,L_W_SETTING02,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_CHILD,OBJECT_DRAW_TYPE_NORMAL,0,50,64,64,OFF,OFF,0xFFFFFFFF,0,(wchar_t *)&TEXT_DATA_NON,NULL},
};

void L_HOME00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_HOME00 , object_list , 97 , (VOID_CALLBACK)L_HOME00_start , (VOID_CALLBACK)L_HOME00_end , (VOID_CALLBACK)L_HOME00_always);
}
/**********auto(end)**********/

const int text_process[19] = {OBJ_TEXT_PROCESS00 , OBJ_TEXT_PROCESS01 , OBJ_TEXT_PROCESS02 , OBJ_TEXT_PROCESS03 , OBJ_TEXT_PROCESS04 , OBJ_TEXT_PROCESS05 ,
		OBJ_TEXT_PROCESS06 , OBJ_TEXT_PROCESS07 , OBJ_TEXT_PROCESS08 , OBJ_TEXT_PROCESS09 , OBJ_TEXT_PROCESS10 , OBJ_TEXT_PROCESS11 , OBJ_TEXT_PROCESS12 ,
		OBJ_TEXT_PROCESS13 , OBJ_TEXT_PROCESS14 , OBJ_TEXT_PROCESS15 , OBJ_TEXT_PROCESS16 , OBJ_TEXT_PROCESS17 , OBJ_TEXT_PROCESS18};
const int text_time[8] = {OBJ_TEXT_TIME01 , OBJ_TEXT_TIME02 , OBJ_TEXT_TIME03 , OBJ_TEXT_TIME04 ,
		OBJ_TEXT_TIME05 , OBJ_TEXT_TIME06 , OBJ_TEXT_TIME07 , OBJ_TEXT_TIME08};
const int text_c_temp[7] = {OBJ_TEXT_C_TEMP10 , OBJ_TEXT_C_TEMP11 , OBJ_TEXT_C_TEMP12 , OBJ_TEXT_C_TEMP13 ,
		 OBJ_TEXT_C_TEMP14 , OBJ_TEXT_C_TEMP15 , OBJ_TEXT_C_TEMP16};

/*
 *		レイヤーの表示開始時の処理
 */
static void L_HOME00_start(void)
{
	switch (h.select_m_a) {
	case S_MANUAL:
		h.uh_temp_set = m.uh_temp_m;
		h.lh_temp_set = m.lh_temp_m;
		h.uh_mode_now = m.uh_mode_m;
		h.lh_mode_now = m.lh_mode_m;
		h.time_minute_set = m.time_minute_m;
		h.time_second_set = m.time_second_m;
		h.core_temp_set_integer = m.core_temp_integer_m;
		h.core_temp_set_decimal = m.core_temp_decimal_m;
		break;
	case S_AUTO:

		break;
	}
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_HOME00_end(void)
{

}

/*
 *		レイヤーの定期処理
 */
static void L_HOME00_always(void)
{
	obj_SetString_Number(OBJ_TEXT_TITLE00, h.code_no_now, 12);	//コード番号の反映
	obj_SetString(OBJ_TEXT_TITLE02, h.code_name_now);			//コード名称の反映

	switch (h.select_m_a) {
	case S_MANUAL:											//手動運転の場合は、工程番号を非表示化
		for(int i = 0; i <= 18; i++){
			obj_hide(text_process[i]);
		}
		obj_hide(OBJ_IMG_SKIP00);
		obj_hide(OBJ_TEXT_SKIP00);

		switch (h.core_temp_sts_now) {
		case STS_NONE:
			obj_set_img(OBJ_IMG_C_TEMP00, c_temp_a_off);
			obj_set_touch_img(OBJ_IMG_C_TEMP00, c_temp_a_on);
			obj_set_img(OBJ_IMG_TIME_OR_C_TEMP01, logo_timer1);

			for(int i = 0; i <= 7; i++){
				obj_show(text_time[i]);
			}
			for(int i = 0; i <= 6; i++){
				obj_hide(text_c_temp[i]);
			}

			break;
		case STS_TRUE:
			obj_set_img(OBJ_IMG_C_TEMP00, c_temp_b_off);
			obj_set_touch_img(OBJ_IMG_C_TEMP00, c_temp_b_on);
			obj_set_img(OBJ_IMG_TIME_OR_C_TEMP01, logo_c_temp1);

			for(int i = 0; i <= 7; i++){
				obj_hide(text_time[i]);
			}
			for(int i = 0; i <= 6; i++){
				obj_show(text_c_temp[i]);
			}

			break;
		}

		break;
	case S_AUTO:												//自動運転の場合は、工程番号を表示
		if(h.process_now != 0){
			h.time_minute_set = a.time_minute[h.code_no_now - 2][h.process_now - 1];
			h.time_second_set = a.time_second[h.code_no_now - 2][h.process_now - 1];
			h.core_temp_sts_now = a.core_temp_sts[h.code_no_now - 2][h.process_now - 1];
			h.core_temp_set_integer = a.core_temp_integer[h.code_no_now - 2][h.process_now - 1];
			h.core_temp_set_decimal = a.core_temp_decimal[h.code_no_now - 2][h.process_now - 1];
			h.steam_sts_now = a.steam_sts[h.code_no_now - 2][h.process_now - 1];
		}

		h.uh_temp_set = a.uh_temp[h.code_no_now - 2][h.process_now];
		h.lh_temp_set = a.lh_temp[h.code_no_now - 2][h.process_now];
		h.uh_mode_now = a.uh_mode[h.code_no_now - 2][h.process_now];
		h.lh_mode_now = a.lh_mode[h.code_no_now - 2][h.process_now];
		h.damper_sts_now = a.damper_sts[h.code_no_now - 2][h.process_now];

		for(int i = 0; i <= 18; i++){
			obj_show(text_process[i]);
		}
		obj_show(OBJ_IMG_SKIP00);
		obj_show(OBJ_TEXT_SKIP00);

		if (h.process_now == 0) {
			obj_set_touch(OBJ_IMG_TIME_OR_C_TEMP00, false);				//自動運転0工程時は、時間テキストを非表示、ボタンを無効化
			obj_set_disable_img(OBJ_IMG_TIME_OR_C_TEMP01, logo_timer2);
			for(int i = 0; i <= 7; i++){
				obj_hide(text_time[i]);
			}
			for(int i = 0; i <= 6; i++){
				obj_hide(text_c_temp[i]);
			}
		}
		else {
			obj_set_touch(OBJ_IMG_TIME_OR_C_TEMP00, true);
			obj_set_disable_img(OBJ_IMG_TIME_OR_C_TEMP01, logo_timer1);

		}
		if (h.process_now == 0) {
			obj_set_font_style(OBJ_TEXT_PROCESS00, Font32Y);
		}
		else {
			obj_set_font_style(OBJ_TEXT_PROCESS00, Font32);
		}
		for (int i = 1; i < PROCESS_MAX_SIZE_ZERO_ON; i++) {
			if (h.process_now == i) {				//運転中の工程番号は、黄色フォント
				obj_set_font_style(text_process[i], Font32Y);
				obj_set_font_style(text_process[i + 9], Font32);
			}
			else {
				if (h.process_max < i) {			//菓子コードに登録されている工程外であれば、灰色フォント
					obj_set_font_style(text_process[i], Font32G);
					obj_set_font_style(text_process[i + 9], Font32G);
				}
				else {								//菓子コード登録の範囲内で運転中でないものは、白色フォント
					obj_set_font_style(text_process[i], Font32);
					obj_set_font_style(text_process[i + 9], Font32);
				}
			}
		}
		break;
	}

	//時間・温度の表示

	obj_printf(OBJ_TEXT_TIME01 , L"%2d", h.time_minute_set );				//設定時間[分]
	obj_printf(OBJ_TEXT_TIME03 , L"%2d", h.time_second_set );				//設定時間[秒]
	obj_printf(OBJ_TEXT_TIME05 , L"%2d", h.time_minute_now );				//現在時間[分]
	obj_printf(OBJ_TEXT_TIME07 , L"%2d", h.time_second_now );				//現在時間[秒]

	obj_printf(OBJ_TEXT_UH01 , L"%3d" , h.uh_temp_set);						//設定温度[上火]
	obj_printf(OBJ_TEXT_LH01 , L"%3d" , h.lh_temp_set);						//設定温度[下火]
	obj_printf(OBJ_TEXT_C_TEMP11 , L"%2d" , h.core_temp_set_integer);		//設定温度[芯温:整数値]
	obj_printf(OBJ_TEXT_C_TEMP15 , L"%d" , h.core_temp_set_decimal);		//設定温度[芯温:小数値]
	obj_printf(OBJ_TEXT_UH03 , L"%3d" , h.uh_temp_now);						//炉内温度[上火]
	obj_printf(OBJ_TEXT_LH03 , L"%3d" , h.lh_temp_now);						//炉内温度[上火]
	obj_printf(OBJ_TEXT_C_TEMP13 , L"%.1f" , h.core_temp_now);				//設定温度[芯温]

	//上火の火力表示切替
	switch (h.uh_mode_now) {
	case HIGH:
		obj_set_disable_img(OBJ_IMG_UH03, logo_mode_on_s);
		obj_set_disable_img(OBJ_IMG_UH04, logo_mode_on_s);
		break;
	case MEDIUM:
		obj_set_disable_img(OBJ_IMG_UH03, logo_mode_on_s);
		obj_set_disable_img(OBJ_IMG_UH04, logo_mode_off_s);
		break;
	case LOW:
		obj_set_disable_img(OBJ_IMG_UH03, logo_mode_off_s);
		obj_set_disable_img(OBJ_IMG_UH04, logo_mode_off_s);
		break;
	}

	//下火の火力表示切替
	switch (h.lh_mode_now) {
	case HIGH:
		obj_set_disable_img(OBJ_IMG_LH03, logo_mode_on_s);
		obj_set_disable_img(OBJ_IMG_LH04, logo_mode_on_s);
		break;
	case MEDIUM:
		obj_set_disable_img(OBJ_IMG_LH03, logo_mode_on_s);
		obj_set_disable_img(OBJ_IMG_LH04, logo_mode_off_s);
		break;
	case LOW:
		obj_set_disable_img(OBJ_IMG_LH03, logo_mode_off_s);
		obj_set_disable_img(OBJ_IMG_LH04, logo_mode_off_s);
		break;
	}

	switch (h.start_sts) {
	case SS_NONE:
		obj_set_disable_img(OBJ_IMG_START00, start_c_off);
		obj_set_touch(OBJ_IMG_START00, false);
		obj_set_font_style(OBJ_TEXT_START00, Font24_G);
		break;
	case SS_WAIT:
		obj_set_touch(OBJ_IMG_START00, true);
		obj_set_font_style(OBJ_TEXT_START00, Font24);
		break;
	case SS_RUNTIME:
		obj_set_disable_img(OBJ_IMG_START00, start_b_off);
		obj_set_touch(OBJ_IMG_START00, false);
		obj_set_font_style(OBJ_TEXT_START00, Font24);
		break;
	}

	switch (h.damper_sts_now) {
	case D_CLOSE:
		obj_set_img(OBJ_IMG_N_DAMPER00, n_damper_a_off);
		obj_set_img(OBJ_IMG_A_DAMPER00, a_damper_a_off);
		obj_set_touch_img(OBJ_IMG_N_DAMPER00, n_damper_a_on);
		obj_set_touch_img(OBJ_IMG_A_DAMPER00, a_damper_a_on);
		break;
	case D_NATURAL:
		obj_set_img(OBJ_IMG_N_DAMPER00, n_damper_b_off);
		obj_set_img(OBJ_IMG_A_DAMPER00, a_damper_a_off);
		obj_set_touch_img(OBJ_IMG_N_DAMPER00, n_damper_b_on);
		obj_set_touch_img(OBJ_IMG_A_DAMPER00, a_damper_a_on);
		break;
	case D_AUTO:
		obj_set_img(OBJ_IMG_N_DAMPER00, n_damper_a_off);
		obj_set_img(OBJ_IMG_A_DAMPER00, a_damper_b_off);
		obj_set_touch_img(OBJ_IMG_N_DAMPER00, n_damper_a_on);
		obj_set_touch_img(OBJ_IMG_A_DAMPER00, a_damper_b_on);
		break;
	}

	switch (h.steam_sts_now) {
	case STS_NONE:
		obj_set_touch(OBJ_IMG_STEAM00, true);
		break;
	case STS_TRUE:
		obj_set_touch(OBJ_IMG_STEAM00, false);
		if (wait_timeout(t.steam_timer, h.steam_count)) {
				h.steam_sts_now = STS_NONE;
		}
		break;
	}

	switch (h.lamp_sts) {
	case STS_NONE:
		obj_set_img(OBJ_IMG_LAMP00, lamp_a_off);
		obj_set_touch_img(OBJ_IMG_LAMP00, lamp_a_on);
		break;
	case STS_TRUE:
		obj_set_img(OBJ_IMG_LAMP00, lamp_b_off);
		obj_set_touch_img(OBJ_IMG_LAMP00, lamp_b_on);
		break;
	}
	switch (h.clear_sts) {
	case STS_NONE:
		obj_set_touch(OBJ_IMG_CLEAR00, false);
		obj_set_font_style(OBJ_TEXT_CLEAR00, Font24_G);
		break;
	case STS_TRUE:
		obj_set_touch(OBJ_IMG_CLEAR00, true);
		obj_set_font_style(OBJ_TEXT_CLEAR00, Font24);
		break;
	}
	switch (h.buzzer_sts) {
	case STS_NONE:
		obj_set_touch(OBJ_IMG_BUZZER00, false);
		obj_set_font_style(OBJ_TEXT_BUZZER00, Font24_G);
		break;
	case STS_TRUE:
		obj_set_touch(OBJ_IMG_BUZZER00, true);
		obj_set_font_style(OBJ_TEXT_BUZZER00, Font24);
		break;
	}

	switch (h.recipe_sts) {
	case STS_NONE:
		obj_set_touch(OBJ_IMG_RECIPE00, false);
		obj_set_font_style(OBJ_TEXT_RECIPE00, Font24_G);
		break;
	case STS_TRUE:
		obj_set_touch(OBJ_IMG_RECIPE00, true);
		obj_set_font_style(OBJ_TEXT_RECIPE00, Font24);
		break;
	}

	switch (h.eco_sts) {
	case STS_NONE:
		obj_set_img(OBJ_IMG_ECO00, eco_a_off);
		obj_set_touch_img(OBJ_IMG_ECO00, eco_a_on);
		break;
	case STS_TRUE:
		obj_set_img(OBJ_IMG_ECO00, eco_b_off);
		obj_set_touch_img(OBJ_IMG_ECO00, eco_b_on);
		break;
	}

	switch (h.popup_temp_sts) {
	case STS_NONE:
		switch (h.popup_time_sts) {
		case STS_NONE:
			switch (h.popup_c_temp_sts){
			case STS_NONE:
				obj_set_touch(OBJ_CHILD00, false);
				obj_hide(OBJ_CHILD00);
				obj_set_touch(OBJ_CHILD01, false);
				obj_hide(OBJ_CHILD01);
				obj_set_touch(OBJ_CHILD02, false);
				obj_hide(OBJ_CHILD02);
				obj_set_touch(OBJ_RECT_SCALE00, false);
				obj_hide(OBJ_RECT_SCALE00);
				break;
			case STS_TRUE:
				obj_set_touch(OBJ_CHILD00, false);
				obj_hide(OBJ_CHILD00);
				obj_set_touch(OBJ_CHILD01, false);
				obj_hide(OBJ_CHILD01);
				obj_set_touch(OBJ_CHILD02, true);
				obj_show(OBJ_CHILD02);
				obj_set_touch(OBJ_RECT_SCALE00, true);
				obj_show(OBJ_RECT_SCALE00);
				break;
			}
			break;
		case STS_TRUE:
			obj_set_touch(OBJ_CHILD00, false);
			obj_hide(OBJ_CHILD00);
			obj_set_touch(OBJ_CHILD01, true);
			obj_show(OBJ_CHILD01);
			obj_set_touch(OBJ_CHILD02, false);
			obj_hide(OBJ_CHILD02);
			obj_set_touch(OBJ_RECT_SCALE00, true);
			obj_show(OBJ_RECT_SCALE00);
			break;
		}
		break;
	case STS_TRUE:
		obj_set_touch(OBJ_CHILD00, true);
		obj_show(OBJ_CHILD00);
		obj_set_touch(OBJ_CHILD01, false);
		obj_hide(OBJ_CHILD01);
		obj_set_touch(OBJ_CHILD02, false);
		obj_hide(OBJ_CHILD02);
		obj_set_touch(OBJ_RECT_SCALE00, true);
		obj_show(OBJ_RECT_SCALE00);
		break;
	}

	if((h.dl_sts == DL_OPEN) &&
		(h.buzzer_sts == STS_TRUE)){
		//ブザー切と同じ記述
	}

	BakeTimerStatus();
}

static void BakeTimerStatus(void){
	switch(h.b_t_sts){
	case BTS_NONE:
		switch(h.select_m_a){
		case S_MANUAL:
			switch(t.mns){
			case NS_NONE:
				h.b_t_sts = BTS_WAIT;
				h.manual_first_counter = 1;
				break;
			case NS_FIRST:
				switch(h.manual_first_counter){
				case 0:
					if(((h.uh_temp_now + t.warmup_temp) >= h.uh_temp_set) &&
								((h.lh_temp_now + t.warmup_temp) >= h.lh_temp_set)) {
						h.buzzer_sts = STS_TRUE;
						h.b_t_sts = BTS_WAIT;
						h.manual_first_counter = 1;
					}
					else{
						h.start_sts = SS_NONE;
						h.clear_sts = STS_NONE;
						h.recipe_sts = STS_TRUE;
					}
					break;
				case 1:
					h.b_t_sts = BTS_WAIT;
					break;
				}
				break;
			case NS_EVERY:
				if(((h.uh_temp_now + t.warmup_temp) >= h.uh_temp_set) &&
							((h.lh_temp_now + t.warmup_temp) >= h.lh_temp_set)) {
					h.buzzer_sts = STS_TRUE;
					h.b_t_sts = BTS_WAIT;
					h.manual_first_counter = 1;
				}
				else{
					h.start_sts = SS_NONE;
					h.clear_sts = STS_NONE;
					h.recipe_sts = STS_TRUE;
				}
				break;
			}
			break;
		case S_AUTO:
			if(a.warmup_buzzer[h.code_no_now - 2] == STS_NONE){
				h.b_t_sts = BTS_WAIT;
			}
			else if(((h.uh_temp_now + t.warmup_temp) >= h.uh_temp_set) &&
					((h.lh_temp_now + t.warmup_temp) >= h.lh_temp_set) &&
					(a.warmup_buzzer[h.code_no_now - 2] == STS_TRUE)) {
				h.buzzer_sts = STS_TRUE;
				h.b_t_sts = BTS_WAIT;
			}
			else{
				h.start_sts = SS_NONE;
				h.clear_sts = STS_NONE;
				h.recipe_sts = STS_TRUE;
			}
			break;
		}
		break;
	case BTS_WAIT:
		switch(h.select_m_a){
		case S_MANUAL:
			if(((h.time_minute_set == 0) && (h.time_second_set == 0)) ||
					(h.buzzer_sts == STS_TRUE)){
				h.start_sts = SS_NONE;
				h.clear_sts = STS_NONE;
				h.recipe_sts = STS_TRUE;
			}
			else{
				h.b_t_sts = BTS_STOP;
			}
			break;
		case S_AUTO:
			if((a.process_max[h.code_no_now - 2] == 0) &&
					(h.buzzer_sts == STS_NONE)){
				h.start_sts = SS_NONE;
				h.clear_sts = STS_NONE;
				h.recipe_sts = STS_TRUE;
			}
			else{
				h.b_t_sts = BTS_STOP;
			}
			break;
		}
		break;
	case BTS_STOP:
		h.start_sts = SS_WAIT;
		h.clear_sts = STS_NONE;
		h.recipe_sts = STS_TRUE;
		break;
	case BTS_RUNTIME:									//運転中
		h.start_sts = SS_RUNTIME;
		h.clear_sts = STS_TRUE;
		h.recipe_sts = STS_NONE;
		if(wait_timeout(10000UL, h.auto_count)) {		//10秒毎に時間を観測
			if (h.time_second_now == 50) {				//秒数が50秒なら秒数を0秒にして、経過時間に1分加算する
				h.time_minute_now = h.time_minute_now + 1;
				h.time_second_now = h.time_second_now - 50;
				h.auto_count = get_sys_timer();
			}
			else {										//0-40秒の場合は、10秒加算する
				h.time_second_now = h.time_second_now + 10;
				h.auto_count = get_sys_timer();
			}
			if ((h.time_minute_now * 60 + h.time_second_now)
				>= (h.time_minute_set * 60 + h.time_second_set) &&
				(h.select_m_a == S_MANUAL)) {
				h.buzzer_sts = STS_TRUE;
				h.b_t_sts = BTS_COMPLETE;
			}
			else if ((h.time_minute_now * 60 + h.time_second_now)
				>= (h.time_minute_set * 60 + h.time_second_set) &&
				(h.select_m_a == S_AUTO)) {
														//設定時間を測定時間が超えている場合、
				if (h.process_max == h.process_now) {	//最終工程なら[complete]
					h.buzzer_sts = STS_TRUE;
					h.b_t_sts = BTS_COMPLETE;
				}
				else {									//工程途中なら[process_sw]
					h.buzzer_sts = STS_TRUE;
					h.process_count = get_sys_timer();
					h.b_t_sts = BTS_PROCESS_SW;
				}
			}
		}
		break;
	case BTS_PROCESS_SW:
		if(wait_timeout(t.process_sw_timer, h.auto_count)) {
			h.buzzer_sts = STS_NONE;
			h.process_now = h.process_now + 1;
			h.time_minute_now = 0;
			h.time_second_now = 0;
			h.process_count = get_sys_timer();
			h.b_t_sts = BTS_RUNTIME;
		}
		break;
	case BTS_COMPLETE:
		h.start_sts = SS_RUNTIME;
		h.clear_sts = STS_TRUE;
		h.recipe_sts = STS_NONE;
		h.buzzer_sts = STS_TRUE;
		if(wait_timeout(10000UL, h.auto_count)) {		//10秒毎に時間を観測
			if (h.time_second_now == 50) {				//秒数が50秒なら秒数を0秒にして、経過時間に1分加算する
				h.time_minute_now = h.time_minute_now + 1;
				h.time_second_now = h.time_second_now - 50;
				h.auto_count = get_sys_timer();
			}
			else {										//0-40秒の場合は、10秒加算する
				h.time_second_now = h.time_second_now + 10;
				h.auto_count = get_sys_timer();
			}
		}
		break;
	}
}

/**********touch_source**********/


/*
 *          OBJ_IMG_SKIP00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_SKIP00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		if (h.process_now == h.process_max) {
			h.process_now = 0;
			h.time_minute_set = 0;
			h.time_second_set = 0;
			h.time_minute_now = 0;
			h.time_second_now = 0;
			h.uh_temp_set = a.uh_temp[h.code_no_now - 2][0];
			h.lh_temp_set = a.lh_temp[h.code_no_now - 2][0];
			h.uh_mode_now = a.uh_mode[h.code_no_now - 2][0];
			h.lh_mode_now = a.lh_mode[h.code_no_now - 2][0];
			h.damper_sts_now = a.damper_sts[h.code_no_now - 2][0];
			h.core_temp_sts_now = STS_NONE;
			h.steam_sts_now = STS_NONE;
			h.b_t_sts = BTS_NONE;
		}
		else{
			h.process_now = h.process_now + 1;
			h.time_minute_set = a.time_minute[h.code_no_now - 2][h.process_now - 1];
			h.time_second_set = a.time_second[h.code_no_now - 2][h.process_now - 1];
			h.time_minute_now = 0;
			h.time_second_now = 0;
			h.uh_temp_set = a.uh_temp[h.code_no_now - 2][h.process_now];
			h.lh_temp_set = a.lh_temp[h.code_no_now - 2][h.process_now];
			h.uh_mode_now = a.uh_mode[h.code_no_now - 2][h.process_now];
			h.lh_mode_now = a.lh_mode[h.code_no_now - 2][h.process_now];
			h.damper_sts_now = a.damper_sts[h.code_no_now - 2][h.process_now];
			h.core_temp_sts_now = a.core_temp_sts[h.code_no_now - 2][h.process_now - 1];
			h.steam_sts_now = a.steam_sts[h.code_no_now - 2][h.process_now - 1];
		}

		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
/*
 *          OBJ_IMG_TIME_OR_C_TEMP00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_TIME_OR_C_TEMP00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(h.core_temp_sts_now){
		case STS_NONE:
			h.popup_time_sts = STS_TRUE;
			l_time.time_minute_prov = h.time_minute_set;
			l_time.time_second_prov = h.time_second_set;
			break;
		case STS_TRUE:
			h.popup_c_temp_sts = STS_TRUE;
			l_c_temp.c_temp_prov_integer = h.core_temp_set_integer;
			l_c_temp.c_temp_prov_decimal = h.core_temp_set_decimal;
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
 *          OBJ_IMG_UH00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UH00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		h.popup_temp_sts = STS_TRUE;
		l_temp.uh_temp_prov = h.uh_temp_set;
		l_temp.lh_temp_prov = h.lh_temp_set;
		l_temp.uh_mode_prov = h.uh_mode_now;
		l_temp.lh_mode_prov = h.lh_mode_now;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_LH00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LH00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		h.popup_temp_sts = STS_TRUE;
		l_temp.uh_temp_prov = h.uh_temp_set;
		l_temp.lh_temp_prov = h.lh_temp_set;
		l_temp.uh_mode_prov = h.uh_mode_now;
		l_temp.lh_mode_prov = h.lh_mode_now;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_CLEAR00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_CLEAR00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (h.select_m_a) {
		case S_MANUAL:
			h.time_minute_now = 0;
			h.time_second_now = 0;
			break;
		case S_AUTO:
			h.process_now = 0;
			h.time_minute_set = 0;
			h.time_second_set = 0;
			h.time_minute_now = 0;
			h.time_second_now = 0;
			h.uh_temp_set = a.uh_temp[h.code_no_now - 2][0];
			h.lh_temp_set = a.lh_temp[h.code_no_now - 2][0];
			h.uh_mode_now = a.uh_mode[h.code_no_now - 2][0];
			h.lh_mode_now = a.lh_mode[h.code_no_now - 2][0];
			h.damper_sts_now = a.damper_sts[h.code_no_now - 2][0];
			h.core_temp_sts_now = STS_NONE;
			h.steam_sts_now = STS_NONE;
			break;
		}
		h.b_t_sts = BTS_NONE;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_BUZZER00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_BUZZER00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(h.b_t_sts){
		case BTS_WAIT:
			h.buzzer_sts = STS_NONE;
			break;
		case BTS_PROCESS_SW:
			h.buzzer_sts = STS_NONE;
			h.process_now = h.process_now + 1;
			h.time_minute_set = a.time_minute[h.code_no_now - 2][h.process_now - 1];
			h.time_second_set = a.time_second[h.code_no_now - 2][h.process_now - 1];
			h.time_minute_now = 0;
			h.time_second_now = 0;
			h.uh_temp_set = a.uh_temp[h.code_no_now - 2][h.process_now];
			h.lh_temp_set = a.lh_temp[h.code_no_now - 2][h.process_now];
			h.uh_mode_now = a.uh_mode[h.code_no_now - 2][h.process_now];
			h.lh_mode_now = a.lh_mode[h.code_no_now - 2][h.process_now];
			h.damper_sts_now = a.damper_sts[h.code_no_now - 2][h.process_now];
			h.core_temp_sts_now = a.core_temp_sts[h.code_no_now - 2][h.process_now - 1];
			h.core_temp_set_integer = a.core_temp_integer[h.code_no_now - 2][h.process_now - 1];
			h.core_temp_set_decimal = a.core_temp_decimal[h.code_no_now - 2][h.process_now - 1];
			h.steam_sts_now = a.steam_sts[h.code_no_now - 2][h.process_now - 1];
			h.process_count = get_sys_timer();
			h.b_t_sts = BTS_RUNTIME;
			break;
		case BTS_COMPLETE:
			h.buzzer_sts = STS_NONE;
			h.time_minute_now = 0;
			h.time_second_now = 0;
			switch (h.select_m_a) {
			case S_MANUAL:
				switch(t.mns){
				case NS_NONE:
				case NS_FIRST:
					h.b_t_sts = BTS_WAIT;
					break;
				case NS_EVERY:
					h.b_t_sts = BTS_NONE;
					break;
				}
				break;
			case S_AUTO:
				h.process_now = 0;
				switch(a.warmup_buzzer[h.code_no_now - 2]){
				case STS_NONE:
					h.b_t_sts = BTS_WAIT;
					break;
				case STS_TRUE:
					h.b_t_sts = BTS_NONE;
					break;
				}
				break;
			}
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
 *          OBJ_IMG_N_DAMPER00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_N_DAMPER00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (h.damper_sts_now) {
		case D_CLOSE:
		case D_AUTO:
			h.damper_sts_now = D_NATURAL;
			break;
		case D_NATURAL:
			h.damper_sts_now = D_CLOSE;
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
 *          OBJ_IMG_C_TEMP00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_C_TEMP00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (h.core_temp_sts_now) {
		case STS_NONE:
			h.core_temp_sts_now = STS_TRUE;
			break;
		case STS_TRUE:
			h.core_temp_sts_now = STS_NONE;
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
 *          OBJ_IMG_RECIPE00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_RECIPE00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		cl.m_select = C_MODE_ENTER;
		change_mode(MODE_CODELIST);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_START00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_START00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (h.select_m_a) {
		case S_AUTO:
			if(h.process_now == 0){
				h.process_now = 1;
			}
			h.b_t_sts = BTS_RUNTIME;
			h.auto_count = get_sys_timer();
			break;
		case S_MANUAL:
			h.b_t_sts = BTS_RUNTIME;
			h.auto_count = get_sys_timer();
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
 *          OBJ_IMG_A_DAMPER00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_A_DAMPER00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (h.damper_sts_now) {
		case D_CLOSE:
		case D_NATURAL:
			h.damper_sts_now = D_AUTO;
			break;
		case D_AUTO:
			h.damper_sts_now = D_CLOSE;
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
 *          OBJ_IMG_STEAM00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_STEAM00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		h.steam_sts_now = STS_TRUE;
		h.steam_count = get_sys_timer();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_LAMP00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LAMP00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (h.lamp_sts) {
		case STS_NONE:
			h.lamp_sts = STS_TRUE;
			break;
		case STS_TRUE:
			h.lamp_sts = STS_NONE;
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
 *          OBJ_IMG_ECO00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_ECO00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch (h.eco_sts) {
		case STS_NONE:
			h.eco_sts = STS_TRUE;
			break;
		case STS_TRUE:
			h.eco_sts = STS_NONE;
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
 *          OBJ_IMG_MORNING00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_MORNING00_touch(int obj_id , int touch_type)
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

/*
 *          OBJ_IMG_OPTION00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_OPTION00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		change_mode(MODE_CONFIG);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
