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

static void L_PROCESS00_start(void);
static void L_PROCESS00_end(void);
static void L_PROCESS00_always(void);

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
static void OBJ_IMG_PROCESS_CHANGE00_touch(int obj_id , int touch_type);
static void OBJ_IMG_TEMP_RISE_NOTICE00_touch(int obj_id , int touch_type);
static void OBJ_IMG_DAMPER_SELECT00_touch(int obj_id , int touch_type);
static void OBJ_IMG_CANCEL00_touch(int obj_id , int touch_type);
static void OBJ_IMG_NEXT_PROCESS00_touch(int obj_id , int touch_type);
static void OBJ_IMG_COMPLETE00_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECT_HEADER00  1718
#define OBJ_RECT_HEADER01  1719
#define OBJ_RECT_HEADER02  1720
#define OBJ_RECT_FOOTER02  1818
#define OBJ_RECT_FOOTER01  1817
#define OBJ_RECT_FOOTER00  1816
#define OBJ_TEXT_TITLE00  1721
#define OBJ_TEXT_TITLE01  1722
#define OBJ_TEXT_TITLE02  1723
#define OBJ_TEXT_PROCESS00  1726
#define OBJ_TEXT_PROCESS01  1727
#define OBJ_TEXT_PROCESS02  1728
#define OBJ_TEXT_PROCESS03  1729
#define OBJ_TEXT_PROCESS04  1730
#define OBJ_TEXT_PROCESS05  1731
#define OBJ_TEXT_PROCESS06  1732
#define OBJ_TEXT_PROCESS07  1733
#define OBJ_TEXT_PROCESS08  1734
#define OBJ_TEXT_PROCESS09  1735
#define OBJ_TEXT_PROCESS10  1736
#define OBJ_TEXT_PROCESS11  1737
#define OBJ_TEXT_PROCESS12  1738
#define OBJ_TEXT_PROCESS13  1739
#define OBJ_TEXT_PROCESS14  1740
#define OBJ_TEXT_PROCESS15  1741
#define OBJ_TEXT_PROCESS16  1742
#define OBJ_TEXT_PROCESS17  1743
#define OBJ_TEXT_PROCESS18  1744
#define OBJ_RECT_BORDER00  1813
#define OBJ_RECT_BORDER01  1814
#define OBJ_RECT_BORDER02  1815
#define OBJ_IMG_U_HEATER00  1840
#define OBJ_IMG_U_HEATER01  1841
#define OBJ_IMG_U_HEATER02  1842
#define OBJ_IMG_U_HEATER03  1843
#define OBJ_IMG_UH_MODE00  1844
#define OBJ_IMG_UH_UKEY00  1845
#define OBJ_IMG_UH_UKEY01  1846
#define OBJ_IMG_UH_UKEY02  1847
#define OBJ_IMG_UH_DKEY00  1848
#define OBJ_IMG_UH_DKEY01  1849
#define OBJ_IMG_UH_DKEY02  1850
#define OBJ_TEXT_UH00  1851
#define OBJ_TEXT_UH01  1852
#define OBJ_TEXT_UH02  1853
#define OBJ_TEXT_UH03  1854
#define OBJ_IMG_L_HEATER00  1822
#define OBJ_IMG_L_HEATER01  1823
#define OBJ_IMG_L_HEATER02  1824
#define OBJ_IMG_L_HEATER03  1825
#define OBJ_IMG_LH_MODE00  1826
#define OBJ_IMG_LH_UKEY00  1820
#define OBJ_IMG_LH_UKEY01  1827
#define OBJ_IMG_LH_UKEY02  1828
#define OBJ_IMG_LH_DKEY00  1821
#define OBJ_IMG_LH_DKEY01  1833
#define OBJ_IMG_LH_DKEY02  1834
#define OBJ_TEXT_LH00  1835
#define OBJ_TEXT_LH01  1837
#define OBJ_TEXT_LH02  1838
#define OBJ_TEXT_LH03  1839
#define OBJ_TEXT_PROCESS_CHANGE00  1940
#define OBJ_IMG_PROCESS_CHANGE00  1942
#define OBJ_TEXT_TEMP_RISE_NOTICE00  1941
#define OBJ_IMG_TEMP_RISE_NOTICE00  1943
#define OBJ_IMG_DAMPER_SELECT00  1946
#define OBJ_IMG_DAMPER_SELECT01  1947
#define OBJ_TEXT_DAMPER_SELECT00  1948
#define OBJ_IMG_CANCEL00  1949
#define OBJ_TEXT_CANCEL00  1955
#define OBJ_IMG_NEXT_PROCESS00  1953
#define OBJ_TEXT_NEXT_PROCESS00  1956
#define OBJ_IMG_COMPLETE00  1954
#define OBJ_TEXT_COMPLETE00  1957

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
static const wchar_t OBJ_TEXT_PROCESS_CHANGE00_TEXT[] = L"工程切替";
static const wchar_t OBJ_TEXT_TEMP_RISE_NOTICE00_TEXT[] = L"昇温通知";
static const wchar_t OBJ_TEXT_DAMPER_SELECT00_TEXT[] = L"閉";
static const wchar_t OBJ_TEXT_CANCEL00_TEXT[] = L"変更取消";
static const wchar_t OBJ_TEXT_NEXT_PROCESS00_TEXT[] = L"次工程へ";
static const wchar_t OBJ_TEXT_COMPLETE00_TEXT[] = L"記憶完了";

static const obj_data_t object_list[74] = {
	{OBJ_RECT_HEADER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,0,600,104,ON,OFF,0xFF007A44,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_HEADER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,99,600,3,ON,OFF,0xFF005030,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_HEADER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,2,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_FOOTER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,1019,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_FOOTER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,907,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_FOOTER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,905,600,119,ON,OFF,0xFF007A44,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,50,30,50,33,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_TEXT_TITLE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,85,30,41,36,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE01_TEXT,NULL},
	{OBJ_TEXT_TITLE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,100,30,500,46,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_TITLE02_TEXT,NULL},
	{OBJ_TEXT_PROCESS00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,30,75,50,36,ON,OFF,0,Font32Y,(wchar_t *)&OBJ_TEXT_PROCESS00_TEXT,NULL},
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
	{OBJ_RECT_BORDER00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,30,153,540,3,ON,OFF,0xFF5a5a5a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BORDER01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,30,381,380,3,ON,OFF,0xFF5a5a5a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_BORDER02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,30,643,380,3,ON,OFF,0xFF5a5a5a,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_U_HEATER00,logo_uh,IMG_NONE,logo_uh,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,30,391,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
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
	{OBJ_TEXT_PROCESS_CHANGE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,45,220,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_PROCESS_CHANGE00_TEXT,NULL},
	{OBJ_IMG_PROCESS_CHANGE00,amselect_a_off,amselect_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,196,178,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_PROCESS_CHANGE00_touch},
	{OBJ_TEXT_TEMP_RISE_NOTICE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,45,320,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_TEMP_RISE_NOTICE00_TEXT,NULL},
	{OBJ_IMG_TEMP_RISE_NOTICE00,noticeselect_a_off,noticeselect_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,195,281,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_TEMP_RISE_NOTICE00_touch},
	{OBJ_IMG_DAMPER_SELECT00,sampleb_button_off,sampleb_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,460,728,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_DAMPER_SELECT00_touch},
	{OBJ_IMG_DAMPER_SELECT01,logo_mode_close,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,448,657,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_DAMPER_SELECT00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,537,684,200,24,ON,OFF,0,Font24,(wchar_t *)&OBJ_TEXT_DAMPER_SELECT00_TEXT,NULL},
	{OBJ_IMG_CANCEL00,sample_button_off,sample_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,30,920,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_CANCEL00_touch},
	{OBJ_TEXT_CANCEL00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,62,1000,200,24,ON,OFF,0,Font16,(wchar_t *)&OBJ_TEXT_CANCEL00_TEXT,NULL},
	{OBJ_IMG_NEXT_PROCESS00,sample_button_off,sample_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,300,920,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_NEXT_PROCESS00_touch},
	{OBJ_TEXT_NEXT_PROCESS00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,332,1000,200,24,ON,OFF,0,Font16,(wchar_t *)&OBJ_TEXT_NEXT_PROCESS00_TEXT,NULL},
	{OBJ_IMG_COMPLETE00,sample_button_off,sample_button_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,480,920,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_COMPLETE00_touch},
	{OBJ_TEXT_COMPLETE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,512,1000,200,24,ON,OFF,0,Font16,(wchar_t *)&OBJ_TEXT_COMPLETE00_TEXT,NULL},
};

void L_PROCESS00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_PROCESS00 , object_list , 74 , (VOID_CALLBACK)L_PROCESS00_start , (VOID_CALLBACK)L_PROCESS00_end , (VOID_CALLBACK)L_PROCESS00_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_PROCESS00_start(void)
{
	
}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_PROCESS00_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_PROCESS00_always(void)
{
	obj_SetString_Number(OBJ_TEXT_TITLE00,cl.code_no_select,12);
	obj_SetString(OBJ_TEXT_TITLE02,a.code_name[cl.code_no_select - 2]);

	switch(p.process_change){
	case S_MANUAL:
		obj_set_img(OBJ_IMG_PROCESS_CHANGE00,amselect_m_off);
		obj_set_touch_img(OBJ_IMG_PROCESS_CHANGE00,amselect_m_on);
		break;
	case S_AUTO:
		obj_set_img(OBJ_IMG_PROCESS_CHANGE00,amselect_a_off);
		obj_set_touch_img(OBJ_IMG_PROCESS_CHANGE00,amselect_a_on);
		break;
	}

	switch(p.warmup_buzzer){
	case STS_NONE:
		obj_set_img(OBJ_IMG_TEMP_RISE_NOTICE00,noticeselect_a_off);
		obj_set_touch_img(OBJ_IMG_TEMP_RISE_NOTICE00,noticeselect_a_on);
		break;
	case STS_TRUE:
		obj_set_img(OBJ_IMG_TEMP_RISE_NOTICE00,noticeselect_b_off);
		obj_set_touch_img(OBJ_IMG_TEMP_RISE_NOTICE00,noticeselect_b_on);
		break;
	}

	switch(p.uh_mode[0]){
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

	switch(p.lh_mode[0]){
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

	obj_SetString_Number(OBJ_TEXT_UH00,p.uh_temp[0] / 100,1);
	obj_SetString_Number(OBJ_TEXT_UH01,p.uh_temp[0] % 100 / 10,1);
	obj_SetString_Number(OBJ_TEXT_UH02,p.uh_temp[0] % 10,1);
	obj_SetString_Number(OBJ_TEXT_LH00,p.lh_temp[0] / 100,1);
	obj_SetString_Number(OBJ_TEXT_LH01,p.lh_temp[0] % 100 / 10,1);
	obj_SetString_Number(OBJ_TEXT_LH02,p.lh_temp[0] % 10,1);

	if(p.uh_temp[0] >= 100){
		obj_show(OBJ_TEXT_UH00);
		obj_show(OBJ_TEXT_UH01);
	}
	else if((p.uh_temp[0] >= 10) &&	(p.uh_temp[0] <= 99)){
		obj_hide(OBJ_TEXT_UH00);
		obj_show(OBJ_TEXT_UH01);
	}
	else{
		obj_hide(OBJ_TEXT_UH00);
		obj_hide(OBJ_TEXT_UH01);
	}

	if(p.lh_temp[0] >= 100){
		obj_show(OBJ_TEXT_LH00);
		obj_show(OBJ_TEXT_LH01);
	}
	else if((p.lh_temp[0] >= 10) && (p.lh_temp[0] <= 99)){
		obj_hide(OBJ_TEXT_LH00);
		obj_show(OBJ_TEXT_LH01);
	}
	else{
		obj_hide(OBJ_TEXT_LH00);
		obj_hide(OBJ_TEXT_LH01);
	}

	switch(p.damper_sts[0]){
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
		switch(p.uh_mode[0]){
		case HIGH:
			p.uh_mode[0] = MEDIUM;
			break;
		case MEDIUM:
			p.uh_mode[0] = LOW;
			break;
		case LOW:
			p.uh_mode[0] = HIGH;
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
		if(p.uh_temp[0] < 200){
			p.uh_temp[0] = p.uh_temp[0] + 100;
		}
		else{
			p.uh_temp[0] = p.uh_temp[0] - 200;
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
		if(p.uh_temp[0] % 100 < 90){
			p.uh_temp[0] = p.uh_temp[0] + 10;
		}
		else{
			p.uh_temp[0] = p.uh_temp[0] - 90;
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
		if(p.uh_temp[0] % 10 != 9){
			p.uh_temp[0] = p.uh_temp[0] + 1;
		}
		else{
			p.uh_temp[0] = p.uh_temp[0] - 9;
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
		if(p.uh_temp[0] >= 100){
			p.uh_temp[0] = p.uh_temp[0] - 100;
		}
		else{
			p.uh_temp[0] = p.uh_temp[0] + 200;
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
		if(p.uh_temp[0] % 100 >= 10){
			p.uh_temp[0] = p.uh_temp[0] - 10;
		}
		else{
			p.uh_temp[0] = p.uh_temp[0] + 90;
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
		if(p.uh_temp[0] % 10 != 0){
			p.uh_temp[0] = p.uh_temp[0] - 1;
		}
		else{
			p.uh_temp[0] = p.uh_temp[0] + 9;
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
		switch(p.lh_mode[0]){
		case HIGH:
			p.lh_mode[0] = MEDIUM;
			break;
		case MEDIUM:
			p.lh_mode[0] = LOW;
			break;
		case LOW:
			p.lh_mode[0] = HIGH;
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
		if(p.lh_temp[0] < 200){
			p.lh_temp[0] = p.lh_temp[0] + 100;
		}
		else{
			p.lh_temp[0] = p.lh_temp[0] - 200;
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
		if(p.lh_temp[0] % 100 < 90){
			p.lh_temp[0] = p.lh_temp[0] + 10;
		}
		else{
			p.lh_temp[0] = p.lh_temp[0] - 90;
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
		if(p.lh_temp[0] % 10 != 9){
			p.lh_temp[0] = p.lh_temp[0] + 1;
		}
		else{
			p.lh_temp[0] = p.lh_temp[0] - 9;
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
		if(p.lh_temp[0] >= 100){
			p.lh_temp[0] = p.lh_temp[0] - 100;
		}
		else{
			p.lh_temp[0] = p.lh_temp[0] + 200;
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
		if(p.lh_temp[0] % 100 >= 10){
			p.lh_temp[0] = p.lh_temp[0] - 10;
		}
		else{
			p.lh_temp[0] = p.lh_temp[0] + 90;
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
		if(p.lh_temp[0] % 10 != 0){
			p.lh_temp[0] = p.lh_temp[0] - 1;
		}
		else{
			p.lh_temp[0] = p.lh_temp[0] + 9;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_PROCESS_CHANGE00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_PROCESS_CHANGE00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.process_change){
		case S_MANUAL:
			p.process_change = S_AUTO;
			break;
		case S_AUTO:
			p.process_change = S_MANUAL;
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
 *          OBJ_IMG_TEMP_RISE_NOTICE00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_TEMP_RISE_NOTICE00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		switch(p.warmup_buzzer){
		case STS_NONE:
			p.warmup_buzzer = STS_TRUE;
			break;
		case STS_TRUE:
			p.warmup_buzzer = STS_NONE;
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
		switch(p.damper_sts[0]){
		case D_CLOSE:
			p.damper_sts[0] = D_NATURAL;
			break;
		case D_NATURAL:
			p.damper_sts[0] = D_AUTO;
			break;
		case D_AUTO:
			p.damper_sts[0] = D_CLOSE;
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
		p.process_no = 1;
		change_mode(MODE_PROCESS01);
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
