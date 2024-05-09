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
#include <wchar.h>

static void L_KEY00_start(void);
static void L_KEY00_end(void);
static void L_KEY00_always(void);

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
static void OBJ_IMG_KEY10_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY11_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY12_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY13_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY14_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY15_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY16_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY17_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY18_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY19_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY20_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY21_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY22_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY23_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY24_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY25_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY27_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY28_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY29_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY30_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY31_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY32_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY33_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY34_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY35_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY36_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY37_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY38_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY39_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY40_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY41_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY42_touch(int obj_id , int touch_type);

static void OBJ_IMG_KEY26_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY43_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY44_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY45_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY46_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY47_touch(int obj_id , int touch_type);
static void OBJ_IMG_KEY48_touch(int obj_id , int touch_type);
static void OBJ_IMG_AA_L_touch(int obj_id , int touch_type);
static void OBJ_IMG_AA_S_touch(int obj_id , int touch_type);
static void OBJ_IMG_DELEATE00_touch(int obj_id , int touch_type);
static void OBJ_IMG_DELEATE01_touch(int obj_id , int touch_type);
static void OBJ_IMG_UNDER_touch(int obj_id , int touch_type);
static void OBJ_IMG_RIGHT_touch(int obj_id , int touch_type);
static void OBJ_IMG_LEFT_touch(int obj_id , int touch_type);
static void OBJ_IMG_HYPHEN_touch(int obj_id , int touch_type);
static void OBJ_IMG_ENTER_touch(int obj_id , int touch_type);
/**********touch_prototype(end)**********/


/**********auto(start)**********/
#define OBJ_RECT_TITLE00  119
#define OBJ_RECT_TITLE01  120
#define OBJ_RECT_TITLE02  121
#define OBJ_RECT_TITLE03  348
#define OBJ_TEXT_TITLE00  122
#define OBJ_TEXT_TITLE01  123
#define OBJ_TEXT_TITLE02  124
#define OBJ_IMG_KEY00  979
#define OBJ_IMG_KEY01  980
#define OBJ_IMG_KEY02  981
#define OBJ_IMG_KEY03  982
#define OBJ_IMG_KEY04  983
#define OBJ_IMG_KEY05  984
#define OBJ_IMG_KEY06  985
#define OBJ_IMG_KEY07  986
#define OBJ_IMG_KEY08  987
#define OBJ_IMG_KEY09  988
#define OBJ_IMG_KEY10  989
#define OBJ_IMG_KEY11  990
#define OBJ_IMG_KEY12  991
#define OBJ_IMG_KEY13  992
#define OBJ_IMG_KEY14  993
#define OBJ_IMG_KEY15  994
#define OBJ_IMG_KEY16  995
#define OBJ_IMG_KEY17  996
#define OBJ_IMG_KEY18  997
#define OBJ_IMG_KEY19  998
#define OBJ_IMG_KEY20  999
#define OBJ_IMG_KEY21  1000
#define OBJ_IMG_KEY22  1001
#define OBJ_IMG_KEY23  1002
#define OBJ_IMG_KEY24  1003
#define OBJ_IMG_KEY25  1004
#define OBJ_IMG_KEY26  1005
#define OBJ_IMG_KEY27  1006
#define OBJ_IMG_KEY28  1007
#define OBJ_IMG_KEY29  1008
#define OBJ_IMG_KEY30  1009
#define OBJ_IMG_KEY31  1010
#define OBJ_IMG_KEY32  1011
#define OBJ_IMG_KEY33  1012
#define OBJ_IMG_KEY34  1013
#define OBJ_IMG_KEY35  1014
#define OBJ_IMG_KEY36  1015
#define OBJ_IMG_KEY37  1016
#define OBJ_IMG_KEY38  1017
#define OBJ_IMG_KEY39  1018
#define OBJ_IMG_KEY40  1019
#define OBJ_IMG_KEY41  1020
#define OBJ_IMG_KEY42  1021
#define OBJ_IMG_KEY43  1022
#define OBJ_IMG_KEY44  1023
#define OBJ_IMG_KEY45  1024
#define OBJ_IMG_KEY46  1025
#define OBJ_IMG_KEY47  1026
#define OBJ_IMG_KEY48  1027
#define OBJ_TEXT_KEY00  127
#define OBJ_TEXT_KEY01  130
#define OBJ_TEXT_KEY02  138
#define OBJ_TEXT_KEY03  139
#define OBJ_TEXT_KEY04  145
#define OBJ_TEXT_KEY05  148
#define OBJ_TEXT_KEY06  151
#define OBJ_TEXT_KEY07  154
#define OBJ_TEXT_KEY08  157
#define OBJ_TEXT_KEY09  160
#define OBJ_TEXT_KEY10  165
#define OBJ_TEXT_KEY11  171
#define OBJ_TEXT_KEY12  177
#define OBJ_TEXT_KEY13  183
#define OBJ_TEXT_KEY14  189
#define OBJ_TEXT_KEY15  166
#define OBJ_TEXT_KEY16  172
#define OBJ_TEXT_KEY17  178
#define OBJ_TEXT_KEY18  184
#define OBJ_TEXT_KEY19  190
#define OBJ_TEXT_KEY20  199
#define OBJ_TEXT_KEY21  211
#define OBJ_TEXT_KEY22  223
#define OBJ_TEXT_KEY23  235
#define OBJ_TEXT_KEY24  247
#define OBJ_TEXT_KEY25  201
#define OBJ_TEXT_KEY26  213
#define OBJ_TEXT_KEY27  225
#define OBJ_TEXT_KEY28  237
#define OBJ_TEXT_KEY29  249
#define OBJ_TEXT_KEY30  200
#define OBJ_TEXT_KEY31  212
#define OBJ_TEXT_KEY32  224
#define OBJ_TEXT_KEY33  236
#define OBJ_TEXT_KEY34  248
#define OBJ_TEXT_KEY35  202
#define OBJ_TEXT_KEY36  214
#define OBJ_TEXT_KEY37  226
#define OBJ_TEXT_KEY38  238
#define OBJ_TEXT_KEY39  250
#define OBJ_TEXT_KEY40  283
#define OBJ_TEXT_KEY41  286
#define OBJ_TEXT_KEY42  289
#define OBJ_TEXT_KEY43  292
#define OBJ_TEXT_KEY44  295
#define OBJ_TEXT_KEY45  298
#define OBJ_TEXT_KEY46  301
#define OBJ_TEXT_KEY47  304
#define OBJ_TEXT_KEY48_00  313
#define OBJ_TEXT_KEY48_01  312
#define OBJ_IMG_KANA  326
#define OBJ_IMG_AA_L  327
#define OBJ_IMG_AA_S  328
#define OBJ_IMG_DELEATE00  329
#define OBJ_IMG_DELEATE01  332
#define OBJ_IMG_UNDER  335
#define OBJ_IMG_RIGHT  338
#define OBJ_IMG_LEFT  341
#define OBJ_IMG_HYPHEN  344
#define OBJ_IMG_ENTER  346
#define OBJ_TEXT_ENTER  347

extern const wchar_t TEXT_DATA_NON;
static const wchar_t OBJ_TEXT_TITLE00_TEXT[] = L"00";
static const wchar_t OBJ_TEXT_TITLE01_TEXT[] = L"：";
static const wchar_t OBJ_TEXT_TITLE02_TEXT[] = L"××××××××××";
static const wchar_t OBJ_TEXT_KEY00_TEXT[] = L"ア";
static const wchar_t OBJ_TEXT_KEY01_TEXT[] = L"イ";
static const wchar_t OBJ_TEXT_KEY02_TEXT[] = L"ウ";
static const wchar_t OBJ_TEXT_KEY03_TEXT[] = L"エ";
static const wchar_t OBJ_TEXT_KEY04_TEXT[] = L"オ";
static const wchar_t OBJ_TEXT_KEY05_TEXT[] = L"カ";
static const wchar_t OBJ_TEXT_KEY06_TEXT[] = L"キ";
static const wchar_t OBJ_TEXT_KEY07_TEXT[] = L"ク";
static const wchar_t OBJ_TEXT_KEY08_TEXT[] = L"ケ";
static const wchar_t OBJ_TEXT_KEY09_TEXT[] = L"コ";
static const wchar_t OBJ_TEXT_KEY10_TEXT[] = L"サ";
static const wchar_t OBJ_TEXT_KEY11_TEXT[] = L"シ";
static const wchar_t OBJ_TEXT_KEY12_TEXT[] = L"ス";
static const wchar_t OBJ_TEXT_KEY13_TEXT[] = L"セ";
static const wchar_t OBJ_TEXT_KEY14_TEXT[] = L"ソ";
static const wchar_t OBJ_TEXT_KEY15_TEXT[] = L"タ";
static const wchar_t OBJ_TEXT_KEY16_TEXT[] = L"チ";
static const wchar_t OBJ_TEXT_KEY17_TEXT[] = L"ツ";
static const wchar_t OBJ_TEXT_KEY18_TEXT[] = L"テ";
static const wchar_t OBJ_TEXT_KEY19_TEXT[] = L"ト";
static const wchar_t OBJ_TEXT_KEY20_TEXT[] = L"ナ";
static const wchar_t OBJ_TEXT_KEY21_TEXT[] = L"ニ";
static const wchar_t OBJ_TEXT_KEY22_TEXT[] = L"ヌ";
static const wchar_t OBJ_TEXT_KEY23_TEXT[] = L"ネ";
static const wchar_t OBJ_TEXT_KEY24_TEXT[] = L"ノ";
static const wchar_t OBJ_TEXT_KEY25_TEXT[] = L"ハ";
static const wchar_t OBJ_TEXT_KEY26_TEXT[] = L"ヒ";
static const wchar_t OBJ_TEXT_KEY27_TEXT[] = L"フ";
static const wchar_t OBJ_TEXT_KEY28_TEXT[] = L"ヘ";
static const wchar_t OBJ_TEXT_KEY29_TEXT[] = L"ホ";
static const wchar_t OBJ_TEXT_KEY30_TEXT[] = L"マ";
static const wchar_t OBJ_TEXT_KEY31_TEXT[] = L"ミ";
static const wchar_t OBJ_TEXT_KEY32_TEXT[] = L"ム";
static const wchar_t OBJ_TEXT_KEY33_TEXT[] = L"メ";
static const wchar_t OBJ_TEXT_KEY34_TEXT[] = L"モ";
static const wchar_t OBJ_TEXT_KEY35_TEXT[] = L"ヤ";
static const wchar_t OBJ_TEXT_KEY36_TEXT[] = L"ユ";
static const wchar_t OBJ_TEXT_KEY37_TEXT[] = L"ヨ";
static const wchar_t OBJ_TEXT_KEY40_TEXT[] = L"ラ";
static const wchar_t OBJ_TEXT_KEY41_TEXT[] = L"リ";
static const wchar_t OBJ_TEXT_KEY42_TEXT[] = L"ル";
static const wchar_t OBJ_TEXT_KEY43_TEXT[] = L"レ";
static const wchar_t OBJ_TEXT_KEY44_TEXT[] = L"ロ";
static const wchar_t OBJ_TEXT_KEY45_TEXT[] = L"ワ";
static const wchar_t OBJ_TEXT_KEY46_TEXT[] = L"ヲ";
static const wchar_t OBJ_TEXT_KEY47_TEXT[] = L"ン";
static const wchar_t OBJ_TEXT_KEY48_00_TEXT[] = L"  ゛゜";
static const wchar_t OBJ_TEXT_KEY48_01_TEXT[] = L"小";
static const wchar_t OBJ_TEXT_ENTER_TEXT[] = L"確定";

static const obj_data_t object_list[117] = {
	{OBJ_RECT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,0,600,104,ON,OFF,0xFF007A44,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_TITLE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,99,600,3,ON,OFF,0xFF005030,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_TITLE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,0,2,600,3,ON,OFF,0xFF4A9F48,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_RECT_TITLE03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_RECTANGLE,OBJECT_DRAW_TYPE_NORMAL,109,34,3,40,ON,OFF,0xFF96C84B,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_TITLE00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,50,52,50,50,ON,OFF,0,Font40A,(wchar_t *)&OBJ_TEXT_TITLE00_TEXT,NULL},
	{OBJ_TEXT_TITLE01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,100,52,41,36,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_TITLE01_TEXT,NULL},
	{OBJ_TEXT_TITLE02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_LEFT,110,52,500,46,ON,OFF,0,Font50,(wchar_t *)&OBJ_TEXT_TITLE02_TEXT,NULL},
	{OBJ_IMG_KEY00,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,133,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY00_touch},
	{OBJ_IMG_KEY01,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,133,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY01_touch},
	{OBJ_IMG_KEY02,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,133,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY02_touch},
	{OBJ_IMG_KEY03,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,133,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY03_touch},
	{OBJ_IMG_KEY04,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,133,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY04_touch},
	{OBJ_IMG_KEY05,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,221,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY05_touch},
	{OBJ_IMG_KEY06,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,221,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY06_touch},
	{OBJ_IMG_KEY07,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,221,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY07_touch},
	{OBJ_IMG_KEY08,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,221,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY08_touch},
	{OBJ_IMG_KEY09,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,221,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY09_touch},
	{OBJ_IMG_KEY10,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,309,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY10_touch},
	{OBJ_IMG_KEY11,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,309,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY11_touch},
	{OBJ_IMG_KEY12,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,309,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY12_touch},
	{OBJ_IMG_KEY13,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,309,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY13_touch},
	{OBJ_IMG_KEY14,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,309,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY14_touch},
	{OBJ_IMG_KEY15,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,397,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY15_touch},
	{OBJ_IMG_KEY16,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,397,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY16_touch},
	{OBJ_IMG_KEY17,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,397,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY17_touch},
	{OBJ_IMG_KEY18,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,397,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY18_touch},
	{OBJ_IMG_KEY19,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,397,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY19_touch},
	{OBJ_IMG_KEY20,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,485,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY20_touch},
	{OBJ_IMG_KEY21,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,485,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY21_touch},
	{OBJ_IMG_KEY22,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,485,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY22_touch},
	{OBJ_IMG_KEY23,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,485,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY23_touch},
	{OBJ_IMG_KEY24,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,485,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY24_touch},
	{OBJ_IMG_KEY25,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,573,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY25_touch},
	{OBJ_IMG_KEY26,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,573,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY26_touch},
	{OBJ_IMG_KEY27,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,573,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY27_touch},
	{OBJ_IMG_KEY28,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,573,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY28_touch},
	{OBJ_IMG_KEY29,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,573,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY29_touch},
	{OBJ_IMG_KEY30,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,661,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY30_touch},
	{OBJ_IMG_KEY31,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,661,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY31_touch},
	{OBJ_IMG_KEY32,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,661,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY32_touch},
	{OBJ_IMG_KEY33,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,661,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY33_touch},
	{OBJ_IMG_KEY34,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,661,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY34_touch},
	{OBJ_IMG_KEY35,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,749,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY35_touch},
	{OBJ_IMG_KEY36,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,749,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY36_touch},
	{OBJ_IMG_KEY37,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,749,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY37_touch},
	{OBJ_IMG_KEY38,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,749,117,137,OFF,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY38_touch},
	{OBJ_IMG_KEY39,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,749,117,137,OFF,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY39_touch},
	{OBJ_IMG_KEY40,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,837,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY40_touch},
	{OBJ_IMG_KEY41,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,837,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY41_touch},
	{OBJ_IMG_KEY42,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,837,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY42_touch},
	{OBJ_IMG_KEY43,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,837,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY43_touch},
	{OBJ_IMG_KEY44,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,837,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY44_touch},
	{OBJ_IMG_KEY45,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,38,925,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY45_touch},
	{OBJ_IMG_KEY46,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,126,925,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY46_touch},
	{OBJ_IMG_KEY47,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,214,925,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY47_touch},
	{OBJ_IMG_KEY48,key_a_off,key_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,302,925,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_KEY48_touch},
	{OBJ_TEXT_KEY00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,170,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY00_TEXT,NULL},
	{OBJ_TEXT_KEY01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,170,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY01_TEXT,NULL},
	{OBJ_TEXT_KEY02,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,170,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY02_TEXT,NULL},
	{OBJ_TEXT_KEY03,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,170,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY03_TEXT,NULL},
	{OBJ_TEXT_KEY04,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,170,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY04_TEXT,NULL},
	{OBJ_TEXT_KEY05,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,258,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY05_TEXT,NULL},
	{OBJ_TEXT_KEY06,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,258,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY06_TEXT,NULL},
	{OBJ_TEXT_KEY07,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,258,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY07_TEXT,NULL},
	{OBJ_TEXT_KEY08,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,258,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY08_TEXT,NULL},
	{OBJ_TEXT_KEY09,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,258,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY09_TEXT,NULL},
	{OBJ_TEXT_KEY10,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,346,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY10_TEXT,NULL},
	{OBJ_TEXT_KEY11,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,346,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY11_TEXT,NULL},
	{OBJ_TEXT_KEY12,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,346,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY12_TEXT,NULL},
	{OBJ_TEXT_KEY13,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,346,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY13_TEXT,NULL},
	{OBJ_TEXT_KEY14,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,346,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY14_TEXT,NULL},
	{OBJ_TEXT_KEY15,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,434,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY15_TEXT,NULL},
	{OBJ_TEXT_KEY16,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,434,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY16_TEXT,NULL},
	{OBJ_TEXT_KEY17,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,434,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY17_TEXT,NULL},
	{OBJ_TEXT_KEY18,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,434,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY18_TEXT,NULL},
	{OBJ_TEXT_KEY19,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,434,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY19_TEXT,NULL},
	{OBJ_TEXT_KEY20,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,522,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY20_TEXT,NULL},
	{OBJ_TEXT_KEY21,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,522,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY21_TEXT,NULL},
	{OBJ_TEXT_KEY22,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,522,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY22_TEXT,NULL},
	{OBJ_TEXT_KEY23,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,522,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY23_TEXT,NULL},
	{OBJ_TEXT_KEY24,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,522,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY24_TEXT,NULL},
	{OBJ_TEXT_KEY25,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,610,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY25_TEXT,NULL},
	{OBJ_TEXT_KEY26,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,610,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY26_TEXT,NULL},
	{OBJ_TEXT_KEY27,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,610,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY27_TEXT,NULL},
	{OBJ_TEXT_KEY28,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,610,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY28_TEXT,NULL},
	{OBJ_TEXT_KEY29,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,610,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY29_TEXT,NULL},
	{OBJ_TEXT_KEY30,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,698,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY30_TEXT,NULL},
	{OBJ_TEXT_KEY31,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,698,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY31_TEXT,NULL},
	{OBJ_TEXT_KEY32,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,698,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY32_TEXT,NULL},
	{OBJ_TEXT_KEY33,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,698,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY33_TEXT,NULL},
	{OBJ_TEXT_KEY34,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,698,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY34_TEXT,NULL},
	{OBJ_TEXT_KEY35,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,786,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY35_TEXT,NULL},
	{OBJ_TEXT_KEY36,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,786,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY36_TEXT,NULL},
	{OBJ_TEXT_KEY37,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,786,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY37_TEXT,NULL},
	{OBJ_TEXT_KEY38,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,786,200,24,OFF,OFF,0,Font36,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_KEY39,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,786,200,24,OFF,OFF,0,Font36,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_TEXT_KEY40,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,874,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY40_TEXT,NULL},
	{OBJ_TEXT_KEY41,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,874,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY41_TEXT,NULL},
	{OBJ_TEXT_KEY42,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,874,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY42_TEXT,NULL},
	{OBJ_TEXT_KEY43,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,874,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY43_TEXT,NULL},
	{OBJ_TEXT_KEY44,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,427,874,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY44_TEXT,NULL},
	{OBJ_TEXT_KEY45,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,75,962,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY45_TEXT,NULL},
	{OBJ_TEXT_KEY46,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,163,962,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY46_TEXT,NULL},
	{OBJ_TEXT_KEY47,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,251,962,200,24,ON,OFF,0,Font36,(wchar_t *)&OBJ_TEXT_KEY47_TEXT,NULL},
	{OBJ_TEXT_KEY48_00,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,960,200,24,ON,OFF,0,Font40A,(wchar_t *)&OBJ_TEXT_KEY48_00_TEXT,NULL},
	{OBJ_TEXT_KEY48_01,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,339,970,200,24,ON,OFF,0,Font28A,(wchar_t *)&OBJ_TEXT_KEY48_01_TEXT,NULL},
	{OBJ_IMG_KANA,katakana_b_off,IMG_NONE,katakana_b_off,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,133,117,137,ON,OFF,0,0,(wchar_t *)&TEXT_DATA_NON,NULL},
	{OBJ_IMG_AA_L,uppercase_a_off,uppercase_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,221,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_AA_L_touch},
	{OBJ_IMG_AA_S,lowercase_a_off,lowercase_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,309,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_AA_S_touch},
	{OBJ_IMG_DELEATE00,deleate_a_off,deleate_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,397,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_DELEATE00_touch},
	{OBJ_IMG_DELEATE01,a_deleate_a_off,a_deleate_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,485,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_DELEATE01_touch},
	{OBJ_IMG_UNDER,under_a_off,under_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,573,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_UNDER_touch},
	{OBJ_IMG_RIGHT,right2_a_off,right2_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,661,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_RIGHT_touch},
	{OBJ_IMG_LEFT,left2_a_off,left2_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,749,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_LEFT_touch},
	{OBJ_IMG_HYPHEN,hyphen_a_off,hyphen_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,478,837,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_HYPHEN_touch},
	{OBJ_IMG_ENTER,enter_a_off,enter_a_on,IMG_NONE,GRAFIC_OBJECT_TYPE_IMG,OBJECT_DRAW_TYPE_NORMAL,390,925,117,137,ON,ON,0,0,(wchar_t *)&TEXT_DATA_NON,OBJ_IMG_ENTER_touch},
	{OBJ_TEXT_ENTER,IMG_NONE,IMG_NONE,IMG_NONE,GRAFIC_OBJECT_TYPE_TEXT,OBJECT_DRAW_TYPE_CENTER,445,960,185,20,ON,OFF,0,Font36_orange,(wchar_t *)&OBJ_TEXT_ENTER_TEXT,NULL},
};

void L_KEY00_LoadLayer(layer_data_t *layer)
{
	NewLayer(layer , L_KEY00 , object_list , 117 , (VOID_CALLBACK)L_KEY00_start , (VOID_CALLBACK)L_KEY00_end , (VOID_CALLBACK)L_KEY00_always);
}
/**********auto(end)**********/

/*
 *		レイヤーの表示開始時の処理
 */
static void L_KEY00_start(void)
{

}

/*
 *		レイヤーの表示終了時の処理
 */
static void L_KEY00_end(void)
{
	
}

/*
 *		レイヤーの定期処理
 */
static void L_KEY00_always(void)
{
	obj_SetString_Number(OBJ_TEXT_TITLE00, cl.code_no_select, 12);
	obj_SetString(OBJ_TEXT_TITLE02, k.code_name_prov);
	obj_set_point(OBJ_RECT_TITLE03, 109 + 47 * (wcslen(k.code_name_prov)- k.title_bar_point), 34);

	switch (k.title_bar_sts) {
	case STS_NONE:
		obj_hide(OBJ_RECT_TITLE03);
		break;
	case STS_TRUE:
		obj_show(OBJ_RECT_TITLE03);
		break;
	}

	if (wait_timeout(500UL, k.flicker_count)) {
		switch (k.title_bar_sts) {
		case STS_NONE:
			k.title_bar_sts = STS_TRUE;
				break;
		case STS_TRUE:
			k.title_bar_sts = STS_NONE;
				break;
		}
		k.flicker_count = get_sys_timer();
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY00), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY01), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY02), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY03), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY04), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY05), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY06), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY07), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY08), k.title_bar_point);
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
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY09), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY10をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY10_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY10), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY11をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY11_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY11), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY12をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY12_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY12), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY13をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY13_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY13), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY14をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY14_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY14), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY15をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY15_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY15), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY16をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY16_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY16), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY17をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY17_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY17), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY18をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY18_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY18), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY19をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY19_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY19), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY20をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY20_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY20), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY21をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY21_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY21), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY22をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY22_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY22), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY23をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY23_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY23), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY24をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY24_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY24), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY25をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY25_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY25), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY26をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY26_touch(int obj_id, int touch_type)
{
	switch (touch_type) {
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY26), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY27をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY27_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY27), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY28をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY28_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY28), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY29をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY29_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY29), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY30をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY30_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY30), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY31をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY31_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY31), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY32をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY32_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY32), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY33をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY33_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY33), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY34をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY34_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY34), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY35をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY35_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY35), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY36をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY36_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY36), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY37をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY37_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY37), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY38をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY38_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY38), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY39をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY39_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY39), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY40をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY40_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY40), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY41をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY41_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY41), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY42をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY42_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY42), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY43をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY43_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY43), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY44をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY44_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY44), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY45をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY45_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY45), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY46をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY46_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY46), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY47をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY47_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, obj_GetString(OBJ_TEXT_KEY47), k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_KEY48をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_KEY48_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ア') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ァ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ァ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ア';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'イ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ィ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ィ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'イ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ウ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ゥ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ゥ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ヴ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ヴ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ウ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'エ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ェ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ェ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'エ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'オ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ォ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ォ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'オ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'カ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ガ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ガ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'カ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'キ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ギ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ギ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'キ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ク') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'グ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'グ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ク';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ケ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ゲ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ゲ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ケ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'コ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ゴ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ゴ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'コ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'サ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ザ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ザ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'サ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'シ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ジ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ジ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'シ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ス') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ズ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ズ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ス';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'セ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ゼ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ゼ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'セ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ソ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ゾ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ゾ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ソ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'タ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ダ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ダ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'タ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'チ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ヂ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ヂ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'チ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ツ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ッ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ッ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ヅ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ヅ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ツ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'テ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'デ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'デ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'テ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ト') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ド';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ド') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ト';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ハ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'バ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'バ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'パ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'パ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ハ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ヒ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ビ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ビ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ピ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ピ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ヒ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'フ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ブ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ブ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'プ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'プ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'フ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ヘ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ベ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ベ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ペ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ペ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ヘ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ホ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ボ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ボ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ポ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ポ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ホ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ヤ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ャ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ャ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ヤ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ユ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ュ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ュ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ユ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ヨ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ョ';
		}
		else if (k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] == L'ョ') {
			k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point] = L'ヨ';
		}
		else {
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_AA_Lをタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_AA_L_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		change_mode(MODE_KEY01);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_AA_Sをタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_AA_S_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		change_mode(MODE_KEY02);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_DELEATE00をタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_DELEATE00_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		if (wcslen(k.code_name_prov) <= k.title_bar_point) {
		}
		else {
			for (int i = 0; i <= k.title_bar_point; i++) {
				k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point + i] =
					k.code_name_prov[wcslen(k.code_name_prov) - k.title_bar_point + i + 1];
			}
		}
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
		wmemset(k.code_name_prov, L'\0', CODE_NAME_MAX_SIZE);
		k.title_bar_point = 0;
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_UNDERをタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_UNDER_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, L"_", k.title_bar_point);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_RIGHTをタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_RIGHT_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		if (k.title_bar_point<=0){
		}
		else {
			k.title_bar_point = k.title_bar_point - 1;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_LEFTをタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_LEFT_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		if (wcslen(k.code_name_prov) - k.title_bar_point <= 0) {
		}
		else {
			k.title_bar_point = k.title_bar_point + 1;
		}
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}

/*
 *          OBJ_IMG_HYPHENをタッチした場合
 *          (関数宣言を変更しないで下さい)
 */
static void OBJ_IMG_HYPHEN_touch(int obj_id , int touch_type)
{
	switch(touch_type){
	case TOUCH_ON:				// タッチした瞬間
		break;
	case TOUCH_LONG:			// タッチし続けて1秒
		break;
	case TOUCH_OFF:				// 放した瞬間
		TextImput(k.code_name_prov, L"-", k.title_bar_point);
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
		wmemset(a.code_name[cl.code_no_select - 2], L'\0', CODE_NAME_MAX_SIZE);
		wcsncpy(a.code_name[cl.code_no_select - 2], k.code_name_prov, wcslen(k.code_name_prov));
		wmemset(k.code_name_prov, L'\0', CODE_NAME_MAX_SIZE);
		k.title_bar_point = 0;
		change_mode(MODE_CODELIST);
		break;
	case TOUCH_SHORT_OFF:		// 押してすぐ放した
		break;
	case TOUCH_REPEAT:			// タッチ後1秒の後連続
		break;
	}
}
