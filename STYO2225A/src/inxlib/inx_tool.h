//
//  標準ライブラリ
//
//  ファイル名 : inx_tool.h
//
//  機能       : サービス関数
//
//   Copyright inX Corporation
//
//<<<<< 変更履歴 >>>>>
//	ver.0001	2014/08/01	: 1) 1st



#ifndef	_INX_TOOL_H
#define	_INX_TOOL_H



#include "stdinx.h"
#include <wchar.h>
/****************************************************
 *					使用有無						*
 ***************************************************/

/* 使用状況に合わせて定義を変更する */

/* 一次直線補間関数 */
#define USE_INX_CALC_LINEAR_EQU		/*  直線補間											 */
#define USE_INX_LOOKUP_TABLE			/*  サーミスタ等のテーブルからデータの呼び出し			 */
//#define USE_INX_LOOKUP_TABLE_EX		/*  サーミスタ等のテーブルからデータの呼び出し(拡張)	 */
//#define USE_INX_LOOKUP_TABLE_EX16		/*  サーミスタ等のテーブルからデータの呼び出し(16bit)	 */

/* 文字列変換系処理 */
#define USE_INX_ATOI					/*  ASCIIコードからint32_tに変換						 */
#define USE_INX_ITOA					/*  int32_t型から10進数のASCIIコードに変換				 */
#define USE_INX_A16TOI				/*  16進数ASCIIコードからuint32_tに変換					 */
#define USE_INX_UITOA					/*  uint32_t型から10進数のASCIIコードに変換				 */
#define USE_INX_UITOA16				/*  uint32_t型から16進数のASCIIコードに変換				 */
#define USE_INX_FTOA					/*  数値(浮動小数点) => 文字列 変換関数					 */
#define USE_INX_DTOA					/*  数値(固定小数点) => 文字列(固定長0サプレス) 変換関数 */

/* BCD変換系処理 */
#define USE_INX_BCD_TO_HEX			/*  1バイトBCD⇒1バイトHEX変換							 */
#define USE_INX_HEX_TO_BCD			/*  1バイトHEX⇒1バイトBCD変換							 */

/* 平均化処理 */
//#define USE_INX_BUF_AVG_IN			/*  移動平均 バッファ処理 (新規データ入力)				 */
//#define USE_INX_BUF_AVG				/*  平均 バッファ処理									 */

/* その他処理 */
//#define USE_INX_ROUND					/*  小数点第一位を丸めて整数型にする処理				 */
#define USE_INX_INDEXOF				/*  文字列検索											 */
#define USE_INX_STRMID				/*  文字列から文字列を取り出す							 */


/* 数値計算 */
//#define USE_INX_ABS						/* 絶対値算出 */


/* 編集不可 */
#ifdef USE_INX_LOOKUP_TABLE
#ifndef USE_INX_CALC_LINEAR_EQU
#define USE_INX_CALC_LINEAR_EQU			/*  直線補間 */
#endif
#endif


/****************************************************
 *					マクロ定義						*
 ***************************************************/

#ifdef USE_INX_ABS
#define inx_abs(x) ((x) >= 0 ? (x) : -(x))
#endif


/****************************************************
 *					グローバル変数					*
 ***************************************************/

/****************************************************
 *					構造体							*
 ***************************************************/

enum CALC_ROUND_ENUM
{
	CALC_ROUND,					// 四捨五入
	CALC_ROUND_DOWN,			// 0に切り捨て
	CALC_ROUND_INT,				// 小さい数値に切り捨て
	CALC_ROUND_UP,				// 大きい数値に切り上げ
};

struct POINT{
	int32_t x;
	int32_t y;
};

struct POINT16{
	int16_t x;
	int16_t y;
};

struct LOOKUPTABLE{
	const uint16_t *table;		// テーブルのアドレス
	size_t size;				// テーブルのサイズ
	int32_t min;				// テーブルの最初の返り値
	int step;					// 温度のステップ
	int32_t power;				// 計算倍率 
	enum CALC_ROUND_ENUM round;	// 丸め指定
};


/*************************************************************************
 *						関数プロトタイプ宣言							 *
 ************************************************************************/




/*========================================================================
 *	一次直線補間関数													 *
 *======================================================================*/

#ifdef USE_INX_CALC_LINEAR_EQU
extern int32_t inx_calc_linear_equ(const struct POINT *point1 ,const struct POINT *point2 ,int32_t x , enum CALC_ROUND_ENUM round_d);
#endif



/*========================================================================
 *	テーブル参照関数													 *
 *======================================================================*/

#ifdef USE_INX_LOOKUP_TABLE
extern int32_t	inx_lookup_table(uint16_t adinput ,struct LOOKUPTABLE *look);
#endif

#ifdef USE_INX_LOOKUP_TABLE_EX
extern int32_t	inx_lookup_table_ex( int32_t x, const struct POINT table[], size_t size, enum CALC_ROUND_ENUM round_d);
#endif

#ifdef USE_INX_LOOKUP_TABLE_EX16
extern int32_t	inx_lookup_table_ex16( int16_t x, const struct POINT16 table[], size_t size, enum CALC_ROUND_ENUM round_d);
#endif



/*========================================================================
 *	文字列変換系処理(16/32bit)											 *
 *======================================================================*/
#ifdef USE_INX_ATOI
extern int32_t inx_atoi(const wchar_t buf[]);
#endif

#ifdef USE_INX_ITOA
extern wchar_t *inx_itoa(int32_t n,wchar_t buf[],int flag);
#endif

#ifdef USE_INX_A16TOI
extern uint32_t inx_a16toi(const wchar_t buf[]);
#endif

#ifdef USE_INX_UITOA
extern wchar_t *inx_uitoa(uint32_t n,wchar_t buf[],int flag);
#endif

#ifdef USE_INX_UITOA16
extern wchar_t *inx_uitoa16(uint32_t n,wchar_t buf[],int flag);
#endif

#ifdef USE_INX_FTOA
extern wchar_t *inx_ftoa(float n, uint8_t dig, wchar_t buf[]);
#endif

#ifdef USE_INX_DTOA
extern wchar_t *inx_dtoa(int32_t n, uint8_t dig, uint8_t dot, wchar_t buf[]);
#endif



/*========================================================================
 *	BCD変換系処理														 *
 *======================================================================*/

#ifdef USE_INX_BCD_TO_HEX
extern uint8_t inx_bcd_to_hex(uint8_t bcd);
#endif

#ifdef USE_INX_HEX_TO_BCD
extern uint8_t inx_hex_to_bcd(uint8_t hex);
#endif



/*========================================================================
 *	平均化処理															 *
 *======================================================================*/

#ifdef USE_INX_BUF_AVG_IN
extern uint16_t inx_buf_avg_in(uint16_t buf[], int num, uint16_t in, int flag);
#endif

#ifdef USE_INX_BUF_AVG
extern uint16_t inx_buf_avg(const uint16_t buf[], int num, int flag);
#endif

/*========================================================================
 *	その他																 *
 *======================================================================*/

#ifdef USE_INX_ROUND
extern int32_t inx_round(float num,  enum CALC_ROUND_ENUM round_type);
#endif

#ifdef USE_INX_INDEXOF
extern int16_t inx_indexOf(const char src[], const char search[]);
#endif

#ifdef USE_INX_STRMID
extern char *inx_strmid(char dest[] , const char buf[] , int startIndex , int size);
#endif




#endif


