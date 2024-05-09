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

static void L_PROCESS01_start(void);
static void L_PROCESS01_end(void);
static void L_PROCESS01_always(void);

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
static void OBJ_IMG_T_OR_CT01_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_OR_CT_UKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_OR_CT_UKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_OR_CT_UKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_OR_CT_DKEY00_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_OR_CT_DKEY01_touch(int obj_id , int touch_type);
static void OBJ_IMG_T_OR_CT_DKEY02_touch(int obj_id , int touch_type);
static void OBJ_IMG_STEAM00_touch(int obj_id , int touch_type);
static void OBJ_IMG_DAMPER_SELECT00_touch(int obj_id , int touch_type);
static void OBJ_IMG_CANCEL00_touch(int obj_id , int touch_type);
static void OBJ_IMG_RETURN_PROCESS00_touch(int obj_id , int touch_type);
static void OBJ_IMG_NEXT_PROCESS00_touch(int obj_id , int touch_type);
static void OBJ_IMG_COMPLETE00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECT_HEADER00  1958
#define OBJ_RECT_HEADER01  1959
#define OBJ_RECT_HEADER02  1960
#define OBJ_RECT_FOOTER02  1961
#define OBJ_RECT_FOOTER01  1962
#define OBJ_RECT_FOOTER00  1963
#define OBJ_TEXT_TITLE00  1964
#define OBJ_TEXT_TITLE01  1965
#define OBJ_TEXT_TITLE02  1966
#define OBJ_TEXT_PROCESS00  1967
#define OBJ_TEXT_PROCESS01  1968
#define OBJ_TEXT_PROCESS02  1969
#define OBJ_TEXT_PROCESS03  1970
#define OBJ_TEXT_PROCESS04  1971
#define OBJ_TEXT_PROCESS05  1972
#define OBJ_TEXT_PROCESS06  1973
#define OBJ_TEXT_PROCESS07  1974
#define OBJ_TEXT_PROCESS08  1975
#define OBJ_TEXT_PROCESS09  1976
#define OBJ_TEXT_PROCESS10  1977
#define OBJ_TEXT_PROCESS11  1978
#define OBJ_TEXT_PROCESS12  1979
#define OBJ_TEXT_PROCESS13  1980
#define OBJ_TEXT_PROCESS14  1981
#define OBJ_TEXT_PROCESS15  1982
#define OBJ_TEXT_PROCESS16  1983
#define OBJ_TEXT_PROCESS17  1984
#define OBJ_TEXT_PROCESS18  1985
#define OBJ_RECT_BORDER01  1987
#define OBJ_RECT_BORDER02  1988
#define OBJ_IMG_U_HEATER00  1989
#define OBJ_IMG_U_HEATER01  1990
#define OBJ_IMG_U_HEATER02  1991
#define OBJ_IMG_U_HEATER03  1992
#define OBJ_IMG_UH_MODE00  1993
#define OBJ_IMG_UH_UKEY00  1994
#define OBJ_IMG_UH_UKEY01  1995
#define OBJ_IMG_UH_UKEY02  1996
#define OBJ_IMG_UH_DKEY00  1997
#define OBJ_IMG_UH_DKEY01  1998
#define OBJ_IMG_UH_DKEY02  1999
#define OBJ_TEXT_UH00  2000
#define OBJ_TEXT_UH01  2001
#define OBJ_TEXT_UH02  2002
#define OBJ_TEXT_UH03  2003
#define OBJ_IMG_L_HEATER00  2004
#define OBJ_IMG_L_HEATER01  2005
#define OBJ_IMG_L_HEATER02  2006
#define OBJ_IMG_L_HEATER03  2007
#define OBJ_IMG_LH_MODE00  2008
#define OBJ_IMG_LH_UKEY00  2009
#define OBJ_IMG_LH_UKEY01  2010
#define OBJ_IMG_LH_UKEY02  2011
#define OBJ_IMG_LH_DKEY00  2012
#define OBJ_IMG_LH_DKEY01  2013
#define OBJ_IMG_LH_DKEY02  2014
#define OBJ_TEXT_LH00  2015
#define OBJ_TEXT_LH01  2016
#define OBJ_TEXT_LH02  2017
#define OBJ_TEXT_LH03  2018
#define OBJ_IMG_T_OR_CT00  2059
#define OBJ_IMG_T_OR_CT01  2063
#define OBJ_IMG_T_OR_CT_UKEY00  2064
#define OBJ_IMG_T_OR_CT_UKEY01  2065
#define OBJ_IMG_T_OR_CT_UKEY02  2066
#define OBJ_IMG_T_OR_CT_DKEY00  2067
#define OBJ_IMG_T_OR_CT_DKEY01  2068
#define OBJ_IMG_T_OR_CT_DKEY02  2069
#define OBJ_TEXT_T_OR_CT00  2070
#define OBJ_TEXT_T_OR_CT01  2071
#define OBJ_TEXT_T_OR_CT02  2072
#define OBJ_TEXT_T_OR_CT03  2085
#define OBJ_TEXT_T_OR_CT04  2073
#define OBJ_TEXT_T_OR_CT05  2078
#define OBJ_TEXT_T_OR_CT06  2076
#define OBJ_TEXT_T_OR_CT07  2077
#define OBJ_IMG_STEAM00  2081
#define OBJ_TEXT_STEAM00  2082
#define OBJ_IMG_DAMPER_SELECT00  2023
#define OBJ_IMG_DAMPER_SELECT01  2024
#define OBJ_TEXT_DAMPER_SELECT00  2025
#define OBJ_IMG_CANCEL00  2026
#define OBJ_TEXT_CANCEL00  2027
#define OBJ_IMG_RETURN_PROCESS00  2083
#define OBJ_TEXT_RETURN_PROCESS00  2084
#define OBJ_IMG_NEXT_PROCESS00  2028
#define OBJ_TEXT_NEXT_PROCESS00  2029
#define OBJ_IMG_COMPLETE00  2030
#define OBJ_TEXT_COMPLETE00  2031

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_TITLE00_TEXT[] = L"00";
static const wchar_t OBJ_TEXT_TITLE01_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_TITLE02_TEXT[] = L"××××××××××";
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
static const wchar_t OBJ_TEXT_UH00_TEXT[] = L"1";
static const wchar_t OBJ_TEXT_UH01_TEXT[] = L"2";
static const wchar_t OBJ_TEXT_UH02_TEXT[] = L"3";
static const wchar_t OBJ_TEXT_UH03_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_LH00_TEXT[] = L"1";
static const wchar_t OBJ_TEXT_LH01_TEXT[] = L"2";
static const wchar_t OBJ_TEXT_LH02_TEXT[] = L"3";
static const wchar_t OBJ_TEXT_LH03_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_T_OR_CT00_TEXT[] = L"1";
static const wchar_t OBJ_TEXT_T_OR_CT01_TEXT[] = L"2";
static const wchar_t OBJ_TEXT_T_OR_CT02_TEXT[] = L"3";
static const wchar_t OBJ_TEXT_T_OR_CT03_TEXT[] = L".";
static const wchar_t OBJ_TEXT_T_OR_CT04_TEXT[] = L"℃";
static const wchar_t OBJ_TEXT_T_OR_CT05_TEXT[] = L"50";
static const wchar_t OBJ_TEXT_T_OR_CT06_TEXT[] = L"\'";
static const wchar_t OBJ_TEXT_T_OR_CT07_TEXT[] = L"\"";
static const wchar_t OBJ_TEXT_STEAM00_TEXT[] = L"蒸気";
static const wchar_t OBJ_TEXT_DAMPER_SELECT00_TEXT[] = L"閉";
static const wchar_t OBJ_TEXT_CANCEL00_TEXT[] = L"変更取消";
static const wchar_t OBJ_TEXT_RETURN_PROCESS00_TEXT[] = L"前工程へ";
static const wchar_t OBJ_TEXT_NEXT_PROCESS00_TEXT[] = L"次工程へ";
static const wchar_t OBJ_TEXT_COMPLETE00_TEXT[] = L"記憶完了";

static const obj_data_t object_list[89] = {
	{OBJ_RECT_HEADER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,0,600,104,ON,OFF,0xFF007A44,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_HEADER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,99,600,3,ON,OFF,0xFF005030,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_HEADER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,2,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_FOOTER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,1019,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_FOOTER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,907,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_FOOTER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,905,600,119,ON,OFF,0xFF007A44,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,50,30,50,33,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_TEXT_TITLE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,85,30,41,36,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE01_TEXT,NULL},
	{OBJ_TEXT_TITLE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,100,30,500,46,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE02_TEXT,NULL},
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
	{OBJ_RECT_BORDER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,30,381,380,3,ON,OFF,0xFF5a5a5a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BORDER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,30,643,380,3,ON,OFF,0xFF5a5a5a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER00,logo_uh,IMG_NONE,logo_lh,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,30,391,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER01,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,32,471,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER02,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,64,471,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER03,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,96,471,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_UH_MODE00,m_select_a_off,m_select_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,30,531,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_MODE00_touch},
	{OBJ_IMG_UH_UKEY00,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,150,396,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_UKEY00_touch},
	{OBJ_IMG_UH_UKEY01,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,235,396,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_UKEY01_touch},
	{OBJ_IMG_UH_UKEY02,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,320,396,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_UKEY02_touch},
	{OBJ_IMG_UH_DKEY00,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,150,559,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_DKEY00_touch},
	{OBJ_IMG_UH_DKEY01,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,235,559,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_DKEY01_touch},
	{OBJ_IMG_UH_DKEY02,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,320,559,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UH_DKEY02_touch},
	{OBJ_TEXT_UH00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,200,513,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_UH00_TEXT,NULL},
	{OBJ_TEXT_UH01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,273,513,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_UH01_TEXT,NULL},
	{OBJ_TEXT_UH02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,350,513,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_UH02_TEXT,NULL},
	{OBJ_TEXT_UH03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,411,524,200,25,ON,OFF,0,Font40A,(wchar_t *)&OBJ_TEXT_UH03_TEXT,NULL},
	{OBJ_IMG_L_HEATER00,logo_lh,IMG_NONE,logo_lh,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,30,653,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_L_HEATER01,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,32,733,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_L_HEATER02,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,64,733,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_L_HEATER03,logo_mode_on,IMG_NONE,logo_mode_on,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,96,733,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_LH_MODE00,m_select_a_off,m_select_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,30,793,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_MODE00_touch},
	{OBJ_IMG_LH_UKEY00,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,150,658,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_UKEY00_touch},
	{OBJ_IMG_LH_UKEY01,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,235,658,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_UKEY01_touch},
	{OBJ_IMG_LH_UKEY02,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,320,658,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_UKEY02_touch},
	{OBJ_IMG_LH_DKEY00,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,150,821,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_DKEY00_touch},
	{OBJ_IMG_LH_DKEY01,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,235,821,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_DKEY01_touch},
	{OBJ_IMG_LH_DKEY02,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,320,821,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LH_DKEY02_touch},
	{OBJ_TEXT_LH00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,200,775,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_LH00_TEXT,NULL},
	{OBJ_TEXT_LH01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,273,775,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_LH01_TEXT,NULL},
	{OBJ_TEXT_LH02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,350,775,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_LH02_TEXT,NULL},
	{OBJ_TEXT_LH03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,411,786,200,25,ON,OFF,0,Font40A,(wchar_t *)&OBJ_TEXT_LH03_TEXT,NULL},
	{OBJ_IMG_T_OR_CT00,logo_timer1,IMG_NONE,logo_lh,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,43,138,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_T_OR_CT01,sampleb_button_off,sampleb_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,31,230,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_OR_CT01_touch},
	{OBJ_IMG_T_OR_CT_UKEY00,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,150,134,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_OR_CT_UKEY00_touch},
	{OBJ_IMG_T_OR_CT_UKEY01,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,235,134,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_OR_CT_UKEY01_touch},
	{OBJ_IMG_T_OR_CT_UKEY02,bulekey_u_a_off,bulekey_u_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,320,134,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_OR_CT_UKEY02_touch},
	{OBJ_IMG_T_OR_CT_DKEY00,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,150,297,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_OR_CT_DKEY00_touch},
	{OBJ_IMG_T_OR_CT_DKEY01,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,235,297,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_OR_CT_DKEY01_touch},
	{OBJ_IMG_T_OR_CT_DKEY02,bulekey_d_a_off,bulekey_d_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,320,297,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_T_OR_CT_DKEY02_touch},
	{OBJ_TEXT_T_OR_CT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,200,251,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_T_OR_CT00_TEXT,NULL},
	{OBJ_TEXT_T_OR_CT01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,273,251,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_T_OR_CT01_TEXT,NULL},
	{OBJ_TEXT_T_OR_CT02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,360,251,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_T_OR_CT02_TEXT,NULL},
	{OBJ_TEXT_T_OR_CT03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,318,252,200,25,ON,OFF,0,Font70A,(wchar_t *)&OBJ_TEXT_T_OR_CT03_TEXT,NULL},
	{OBJ_TEXT_T_OR_CT04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,411,262,200,25,ON,OFF,0,Font40A,(wchar_t *)&OBJ_TEXT_T_OR_CT04_TEXT,NULL},
	{OBJ_TEXT_T_OR_CT05,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,350,259,200,25,OFF,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_T_OR_CT05_TEXT,NULL},
	{OBJ_TEXT_T_OR_CT06,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,310,235,200,25,OFF,OFF,0,Font40A,(wchar_t *)&OBJ_TEXT_T_OR_CT06_TEXT,NULL},
	{OBJ_TEXT_T_OR_CT07,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,390,235,200,25,OFF,OFF,0,Font40A,(wchar_t *)&OBJ_TEXT_T_OR_CT07_TEXT,NULL},
	{OBJ_IMG_STEAM00,sampleb_button_off,sampleb_button_off,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,460,430,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_STEAM00_touch},
	{OBJ_TEXT_STEAM00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,508,551,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_STEAM00_TEXT,NULL},
	{OBJ_IMG_DAMPER_SELECT00,sampleb_button_off,sampleb_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,460,728,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_DAMPER_SELECT00_touch},
	{OBJ_IMG_DAMPER_SELECT01,logo_mode_close,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,448,657,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_DAMPER_SELECT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,537,684,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_DAMPER_SELECT00_TEXT,NULL},
	{OBJ_IMG_CANCEL00,sample_button_off,sample_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,30,920,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_CANCEL00_touch},
	{OBJ_TEXT_CANCEL00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,62,1000,200,24,ON,OFF,0,Font16,(wchar_t *)&OBJ_TEXT_CANCEL00_TEXT,NULL},
	{OBJ_IMG_RETURN_PROCESS00,sample_button_off,sample_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,180,920,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RETURN_PROCESS00_touch},
	{OBJ_TEXT_RETURN_PROCESS00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,212,1000,200,24,ON,OFF,0,Font16,(wchar_t *)&OBJ_TEXT_RETURN_PROCESS00_TEXT,NULL},
	{OBJ_IMG_NEXT_PROCESS00,sample_button_off,sample_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,300,920,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_NEXT_PROCESS00_touch},
	{OBJ_TEXT_NEXT_PROCESS00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,332,1000,200,24,ON,OFF,0,Font16,(wchar_t *)&OBJ_TEXT_NEXT_PROCESS00_TEXT,NULL},
	{OBJ_IMG_COMPLETE00,sample_button_off,sample_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,480,920,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_COMPLETE00_touch},
	{OBJ_TEXT_COMPLETE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,512,1000,200,24,ON,OFF,0,Font16,(wchar_t *)&OBJ_TEXT_COMPLETE00_TEXT,NULL},
};

void L_PROCESS01_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_PROCESS01 , object_list , 89 , (VOID_CALLBACK)L_PROCESS01_start , (VOID_CALLBACK)L_PROCESS01_end , (VOID_CALLBACK)L_PROCESS01_always);
}
/**********auto(end)**********/

const int text_process_2[17] = {OBJ_TEXT_PROCESS01 , OBJ_TEXT_PROCESS02 , OBJ_TEXT_PROCESS03 , OBJ_TEXT_PROCESS04 , OBJ_TEXT_PROCESS05 ,
		OBJ_TEXT_PROCESS06 , OBJ_TEXT_PROCESS07 , OBJ_TEXT_PROCESS08 , OBJ_TEXT_PROCESS09 , OBJ_TEXT_PROCESS11 , OBJ_TEXT_PROCESS12 ,
		OBJ_TEXT_PROCESS13 , OBJ_TEXT_PROCESS14 , OBJ_TEXT_PROCESS15 , OBJ_TEXT_PROCESS16 , OBJ_TEXT_PROCESS17 , OBJ_TEXT_PROCESS18};

/*
 *		レイヤーの表示開始時の処理
 */
static void L_PROCESS01_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_PROCESS01_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_PROCESS01_always(void)
{
	obj_SetString_Number(OBJ_TEXT_TITLE00,cl.code_no_select,12);
	obj_SetString(OBJ_TEXT_TITLE02,a.code_name[cl.code_no_select - 2]);
	obj_SetString_Number(OBJ_TEXT_T_OR_CT02,
			p.core_temp_decimal[p.process_no],1);
	obj_SetString_Number(OBJ_TEXT_T_OR_CT05,
			p.time_second[p.process_no],1);
	
	switch(p.core_temp_sts[p.process_no]){
	case STS_NONE:
		obj_set_disable_img(OBJ_IMG_T_OR_CT00,logo_timer1);
		obj_hide(OBJ_TEXT_T_OR_CT02);
		obj_hide(OBJ_TEXT_T_OR_CT03);
		obj_hide(OBJ_TEXT_T_OR_CT04);
		obj_show(OBJ_TEXT_T_OR_CT05);
		obj_show(OBJ_TEXT_T_OR_CT06);
		obj_show(OBJ_TEXT_T_OR_CT07);
		obj_SetString_Number(OBJ_TEXT_T_OR_CT00,
				p.time_minute[p.process_no] / 10,1);
		obj_SetString_Number(OBJ_TEXT_T_OR_CT01,
				p.time_minute[p.process_no] % 10,1);

		if(p.time_minute[p.process_no] >= 10){
			obj_show(OBJ_TEXT_T_OR_CT00);
		}
		else{
			obj_hide(OBJ_TEXT_T_OR_CT00);
		}

		break;
	case STS_TRUE:
		obj_set_disable_img(OBJ_IMG_T_OR_CT00,logo_c_temp1);
		obj_show(OBJ_TEXT_T_OR_CT02);
		obj_show(OBJ_TEXT_T_OR_CT03);
		obj_show(OBJ_TEXT_T_OR_CT04);
		obj_hide(OBJ_TEXT_T_OR_CT05);
		obj_hide(OBJ_TEXT_T_OR_CT06);
		obj_hide(OBJ_TEXT_T_OR_CT07);
		obj_SetString_Number(OBJ_TEXT_T_OR_CT00,
				p.core_temp_integer[p.process_no] / 10,1);
		obj_SetString_Number(OBJ_TEXT_T_OR_CT01,
				p.core_temp_integer[p.process_no] % 10,1);

		if(p.core_temp_integer[p.process_no] >= 10){
			obj_show(OBJ_TEXT_T_OR_CT00);
		}
		else{
			obj_hide(OBJ_TEXT_T_OR_CT00);
		}

		break;
	}

	switch(p.uh_mode[p.process_no]){
	case HIGH:
		obj_set_disable_img(OBJ_IMG_U_HEATER01,logo_mode_on);
		obj_set_disable_img(OBJ_IMG_U_HEATER02,logo_mode_on);
		obj_set_disable_img(OBJ_IMG_U_HEATER03,logo_mode_on);
		break;
	case MEDIUM:
		obj_set_disable_img(OBJ_IMG_U_HEATER01,logo_mode_off);
		obj_set_disable_img(OBJ_IMG_U_HEATER02,logo_mode_on);
		obj_set_disable_img(OBJ_IMG_U_HEATER03,logo_mode_on);
		break;
	case LOW:
		obj_set_disable_img(OBJ_IMG_U_HEATER01,logo_mode_off);
		obj_set_disable_img(OBJ_IMG_U_HEATER02,logo_mode_off);
		obj_set_disable_img(OBJ_IMG_U_HEATER03,logo_mode_on);
		break;
	}

	switch(p.lh_mode[p.process_no]){
	case HIGH:
		obj_set_disable_img(OBJ_IMG_L_HEATER01,logo_mode_on);
		obj_set_disable_img(OBJ_IMG_L_HEATER02,logo_mode_on);
		obj_set_disable_img(OBJ_IMG_L_HEATER03,logo_mode_on);
		break;
	case MEDIUM:
		obj_set_disable_img(OBJ_IMG_L_HEATER01,logo_mode_off);
		obj_set_disable_img(OBJ_IMG_L_HEATER02,logo_mode_on);
		obj_set_disable_img(OBJ_IMG_L_HEATER03,logo_mode_on);
		break;
	case LOW:
		obj_set_disable_img(OBJ_IMG_L_HEATER01,logo_mode_off);
		obj_set_disable_img(OBJ_IMG_L_HEATER02,logo_mode_off);
		obj_set_disable_img(OBJ_IMG_L_HEATER03,logo_mode_on);
		break;
	}

	obj_SetString_Number(OBJ_TEXT_UH00,p.uh_temp[p.process_no] / 100,1);
	obj_SetString_Number(OBJ_TEXT_UH01,p.uh_temp[p.process_no] % 100 / 10,1);
	obj_SetString_Number(OBJ_TEXT_UH02,p.uh_temp[p.process_no] % 10,1);
	obj_SetString_Number(OBJ_TEXT_LH00,p.lh_temp[p.process_no] / 100,1);
	obj_SetString_Number(OBJ_TEXT_LH01,p.lh_temp[p.process_no] % 100 / 10,1);
	obj_SetString_Number(OBJ_TEXT_LH02,p.lh_temp[p.process_no] % 10,1);

	if(p.uh_temp[p.process_no] >= 100){
		obj_show(OBJ_TEXT_UH00);
		obj_show(OBJ_TEXT_UH01);
	}
	else if((p.uh_temp[p.process_no] >= 10) &&
			(p.uh_temp[p.process_no] <= 99)){
		obj_hide(OBJ_TEXT_UH00);
		obj_show(OBJ_TEXT_UH01);
	}
	else{
		obj_hide(OBJ_TEXT_UH00);
		obj_hide(OBJ_TEXT_UH01);
	}

	if(p.lh_temp[p.process_no] >= 100){
		obj_show(OBJ_TEXT_LH00);
		obj_show(OBJ_TEXT_LH01);
	}
	else if((p.lh_temp[p.process_no] >= 10) &&
			(p.lh_temp[p.process_no] <= 99)){
		obj_hide(OBJ_TEXT_LH00);
		obj_show(OBJ_TEXT_LH01);
	}
	else{
		obj_hide(OBJ_TEXT_LH00);
		obj_hide(OBJ_TEXT_LH01);
	}

	switch(p.damper_sts[p.process_no]){
	case D_CLOSE:
		obj_set_img(OBJ_IMG_DAMPER_SELECT01,logo_mode_close);
		break;
	case D_NATURAL:
		obj_set_img(OBJ_IMG_DAMPER_SELECT01,logo_mode_natural);
		break;
	case D_AUTO:
		obj_set_img(OBJ_IMG_DAMPER_SELECT01,logo_mode_auto);
		break;
	}

	switch(p.steam_sts[p.process_no]){
	case STS_NONE:
		obj_set_img(OBJ_IMG_STEAM00,sampleb_button_off);
		break;
	case STS_TRUE:
		obj_set_img(OBJ_IMG_STEAM00,sampleb_button_on);
		break;
	}

	for (int i = 0; i < PROCESS_MAX_SIZE_ZERO_OFF; i++) {
		if (p.process_no == i) {
			obj_set_font_style(text_process_2[i], Font32Y);
			obj_set_font_style(text_process_2[i + 8], Font32);
		}
		else{
			if(((p.core_temp_sts[i] == STS_NONE) &&
					((p.time_minute[i] == 0) &&
							(p.time_second[i] == 0))) ||
					((p.core_temp_sts[i] == STS_TRUE) &&
							((p.core_temp_integer[i] == 0) &&
									(p.core_temp_decimal[i] == 0)))){
				obj_set_font_style(text_process_2[i], Font32G);
				obj_set_font_style(text_process_2[i + 8], Font32G);
			}
			else{
				obj_set_font_style(text_process_2[i], Font32);
				obj_set_font_style(text_process_2[i + 8], Font32);
			}
		}
	}

	switch(p.process_no){
	case 9:
		obj_hide(OBJ_TEXT_NEXT_PROCESS00);
		obj_hide(OBJ_IMG_NEXT_PROCESS00);
		break;
	default:
		obj_show(OBJ_TEXT_NEXT_PROCESS00);
		obj_show(OBJ_IMG_NEXT_PROCESS00);
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
		switch(p.uh_mode[p.process_no]){
		case HIGH:
			p.uh_mode[p.process_no] = MEDIUM;
			break;
		case MEDIUM:
			p.uh_mode[p.process_no] = LOW;
			break;
		case LOW:
			p.uh_mode[p.process_no] = HIGH;
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
		if(p.uh_temp[p.process_no] < 200){
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] + 100;
		}
		else{
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] - 200;
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
		if(p.uh_temp[p.process_no] % 100 < 90){
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] + 10;
		}
		else{
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] - 90;
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
		if(p.uh_temp[p.process_no] % 10 != 9){
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] + 1;
		}
		else{
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] - 9;
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
		if(p.uh_temp[p.process_no] >= 100){
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] - 100;
		}
		else{
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] + 200;
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
		if(p.uh_temp[p.process_no] % 100 >= 10){
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] - 10;
		}
		else{
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] + 90;
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
		if(p.uh_temp[p.process_no] % 10 != 0){
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] - 1;
		}
		else{
			p.uh_temp[p.process_no] = p.uh_temp[p.process_no] + 9;
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
		switch(p.lh_mode[p.process_no]){
		case HIGH:
			p.lh_mode[p.process_no] = MEDIUM;
			break;
		case MEDIUM:
			p.lh_mode[p.process_no] = LOW;
			break;
		case LOW:
			p.lh_mode[p.process_no] = HIGH;
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
		if(p.lh_temp[p.process_no] < 200){
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] + 100;
		}
		else{
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] - 200;
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
		if(p.lh_temp[p.process_no] % 100 < 90){
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] + 10;
		}
		else{
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] - 90;
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
		if(p.lh_temp[p.process_no] % 10 != 9){
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] + 1;
		}
		else{
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] - 9;
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
		if(p.lh_temp[p.process_no] >= 100){
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] - 100;
		}
		else{
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] + 200;
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
		if(p.lh_temp[p.process_no] % 100 >= 10){
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] - 10;
		}
		else{
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] + 90;
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
		if(p.lh_temp[p.process_no] % 10 != 0){
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] - 1;
		}
		else{
			p.lh_temp[p.process_no] = p.lh_temp[p.process_no] + 9;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_T_OR_CT01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_OR_CT01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.core_temp_sts[p.process_no]){
		case STS_NONE:
			p.core_temp_sts[p.process_no] = STS_TRUE;
			break;
		case STS_TRUE:
			p.core_temp_sts[p.process_no] = STS_NONE;
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
 *          OBJ_IMG_T_OR_CT_UKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_OR_CT_UKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.core_temp_sts[p.process_no]){
		case STS_NONE:
			if(p.time_minute[p.process_no] >= 90){
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] - 90;
			}
			else{
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] + 10;
			}
			break;
		case STS_TRUE:
			if(p.core_temp_integer[p.process_no] >= 90){
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] - 90;
			}
			else{
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] + 10;
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
 *          OBJ_IMG_T_OR_CT_UKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_OR_CT_UKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.core_temp_sts[p.process_no]){
		case STS_NONE:
			if(p.time_minute[p.process_no] / 10 == 9){
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] - 9;
			}
			else{
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] + 1;
			}
			break;
		case STS_TRUE:
			if(p.core_temp_integer[p.process_no] / 10 == 9){
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] - 9;
			}
			else{
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] + 1;
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
 *          OBJ_IMG_T_OR_CT_UKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_OR_CT_UKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.core_temp_sts[p.process_no]){
		case STS_NONE:
			if(p.time_second[p.process_no] == 50){
				p.time_second[p.process_no] =
						p.time_second[p.process_no] - 50;
			}
			else{
				p.time_second[p.process_no] =
						p.time_second[p.process_no] + 10;
			}
			break;
		case STS_TRUE:
			if(p.core_temp_decimal[p.process_no] == 9){
				p.core_temp_decimal[p.process_no] =
						p.core_temp_decimal[p.process_no] - 9;
			}
			else{
				p.core_temp_decimal[p.process_no] =
						p.core_temp_decimal[p.process_no] + 1;
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
 *          OBJ_IMG_T_OR_CT_DKEY00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_OR_CT_DKEY00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.core_temp_sts[p.process_no]){
		case STS_NONE:
			if(p.time_minute[p.process_no] < 10){
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] + 90;
			}
			else{
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] - 10;
			}
			break;
		case STS_TRUE:
			if(p.core_temp_integer[p.process_no] < 10){
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] + 90;
			}
			else{
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] - 10;
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
 *          OBJ_IMG_T_OR_CT_DKEY01をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_OR_CT_DKEY01_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.core_temp_sts[p.process_no]){
		case STS_NONE:
			if(p.time_minute[p.process_no] % 10 == 0){
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] + 9;
			}
			else{
				p.time_minute[p.process_no] =
						p.time_minute[p.process_no] - 1;
			}
			break;
		case STS_TRUE:
			if(p.core_temp_integer[p.process_no] % 10 == 0){
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] + 9;
			}
			else{
				p.core_temp_integer[p.process_no] =
						p.core_temp_integer[p.process_no] - 1;
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
 *          OBJ_IMG_T_OR_CT_DKEY02をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_T_OR_CT_DKEY02_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.core_temp_sts[p.process_no]){
		case STS_NONE:
			if(p.time_second[p.process_no] == 0){
				p.time_second[p.process_no] =
						p.time_second[p.process_no] + 50;
			}
			else{
				p.time_second[p.process_no] =
						p.time_second[p.process_no] - 10;
			}
			break;
		case STS_TRUE:
			if(p.core_temp_decimal[p.process_no] == 0){
				p.core_temp_decimal[p.process_no] =
						p.core_temp_decimal[p.process_no] + 9;
			}
			else{
				p.core_temp_decimal[p.process_no] =
						p.core_temp_decimal[p.process_no] - 1;
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
		switch(p.steam_sts[p.process_no]){
		case STS_NONE:
			p.steam_sts[p.process_no] = STS_TRUE;
			break;
		case STS_TRUE:
			p.steam_sts[p.process_no] = STS_NONE;
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
 *          OBJ_IMG_DAMPER_SELECT00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_DAMPER_SELECT00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.damper_sts[p.process_no]){
		case D_CLOSE:
			p.damper_sts[p.process_no] = D_NATURAL;
			break;
		case D_NATURAL:
			p.damper_sts[p.process_no] = D_AUTO;
			break;
		case D_AUTO:
			p.damper_sts[p.process_no] = D_CLOSE;
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
 *          OBJ_IMG_CANCEL00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_CANCEL00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		Initialize_p();
		change_mode(MODE_CODELIST);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_RETURN_PROCESS00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_RETURN_PROCESS00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.process_no){
		case 1:
			p.process_no = 0;
			change_mode(MODE_PROCESS00);
			break;
		default:
			p.process_no = p.process_no - 1;
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
 *          OBJ_IMG_NEXT_PROCESS00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_NEXT_PROCESS00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		p.process_no = p.process_no + 1;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_COMPLETE00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_COMPLETE00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		ProcessImput();
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
