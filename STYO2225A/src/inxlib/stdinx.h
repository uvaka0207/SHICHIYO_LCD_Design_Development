//
//  標準ライブラリ
//
//  ファイル名 : stdinx.h
//
//  機能       : 各種定義(RX専用)
//
//   Copyright inX Corporation
//
//<<<<< 変更履歴 >>>>>
//	ver.0001	2014/05/01	: 1) 1st


#ifndef	_STDINX_H
#define	_STDINX_H

#include <wchar.h>



#ifndef	NULL
#define	NULL		((void *)0)
#endif	// NULL


//
//	INX標準データ型定義.
//

// 符号付き整数
typedef signed char				int8_t;
typedef signed short int		int16_t;
typedef signed long int			int32_t;

// 符号無し整数
typedef unsigned char			uint8_t;
typedef unsigned short int		uint16_t;
typedef unsigned long int		uint32_t;

typedef float					float32_t;

typedef unsigned char			char_t;
typedef unsigned char			bool_t;
// 符号付き整数最大値

#ifndef INT8_MAX
#define	INT8_MAX				127
#endif
#ifndef INT16_MAX
#define	INT16_MAX				32767
#endif
#ifndef INT32_MAX
#define	INT32_MAX				2147483647L
#endif

// 符号付き整数最小値
#ifndef INT8_MIN
#define	INT8_MIN				(-INT8_MAX - 1)
#endif
#ifndef INT16_MIN
#define	INT16_MIN				(-INT16_MAX - 1)
#endif
#ifndef INT32_MIN
#define	INT32_MIN				(-INT32_MAX - 1L)
#endif

// 符号付き整数最大値
#ifndef UINT8_MAX
#define	UINT8_MAX				255U
#endif
#ifndef UINT16_MAX
#define	UINT16_MAX				65535U
#endif
#ifndef UINT32_MAX
#define	UINT32_MAX				4294967295UL
#endif

// 常用型
typedef unsigned int			uint;
typedef uint8_t					uchar;
typedef uint16_t				ushort;
typedef uint32_t				ulong;


#ifndef  _TIME_T_DECLARED
#define  _TIME_T_DECLARED
typedef uint32_t	time_t;
#endif

#ifndef	_SIZE_T
#define	_SIZE_T
typedef uint32_t	size_t;
#endif


typedef uint32_t		paddr_t;					// Physical address space.

#pragma bit_order right

typedef unsigned char	bit_fld;				// ビットフィールド型


typedef struct  {
	bit_fld		b0:1;
	bit_fld		b1:1;
	bit_fld		b2:1;
	bit_fld		b3:1;
	bit_fld		b4:1;
	bit_fld		b5:1;
	bit_fld		b6:1;
	bit_fld		b7:1;
}bit_fld8;

typedef struct  {
	bit_fld		b01:2;
	bit_fld		b23:2;
	bit_fld		b45:2;
	bit_fld		b67:2;
}bit_fld8_2;

typedef struct  {
	bit_fld		b012:3;
	bit_fld		b345:3;
	bit_fld		b67:2;
}bit_fld8_3;

typedef struct  {
	bit_fld		b00:1;
	bit_fld		b01:1;
	bit_fld		b02:1;
	bit_fld		b03:1;
	bit_fld		b04:1;
	bit_fld		b05:1;
	bit_fld		b06:1;
	bit_fld		b07:1;
	bit_fld		b08:1;
	bit_fld		b09:1;
	bit_fld		b10:1;
	bit_fld		b11:1;
	bit_fld		b12:1;
	bit_fld		b13:1;
	bit_fld		b14:1;
	bit_fld		b15:1;
}bit_fld16;


typedef struct  {
	bit_fld		b00:1;
	bit_fld		b01:1;
	bit_fld		b02:1;
	bit_fld		b03:1;
	bit_fld		b04:1;
	bit_fld		b05:1;
	bit_fld		b06:1;
	bit_fld		b07:1;
	bit_fld		b08:1;
	bit_fld		b09:1;
	bit_fld		b10:1;
	bit_fld		b11:1;
	bit_fld		b12:1;
	bit_fld		b13:1;
	bit_fld		b14:1;
	bit_fld		b15:1;
	bit_fld		b16:1;
	bit_fld		b17:1;
	bit_fld		b18:1;
	bit_fld		b19:1;
	bit_fld		b20:1;
	bit_fld		b21:1;
	bit_fld		b22:1;
	bit_fld		b23:1;
	bit_fld		b24:1;
	bit_fld		b25:1;
	bit_fld		b26:1;
	bit_fld		b27:1;
	bit_fld		b28:1;
	bit_fld		b29:1;
	bit_fld		b30:1;
	bit_fld		b31:1;
}bit_fld32;


typedef union  {
	uint8_t				BYTE;
	bit_fld8			BIT;
}flag_data8;


typedef union  {
	uint16_t			WORD;
	bit_fld16			BIT;
}flag_data16;


typedef union  {
	uint32_t			DWORD;
	bit_fld32			BIT;
}flag_data32;

#pragma bit_order


void __enable_irq(void);
unsigned long int __disable_irq(void);

#define enable_int()		__enable_irq()
#define disable_int()		__disable_irq()

#define NOP()				__asm volatile ("nop")


#define ON 1
#define OFF 0

#define CLOSE 1
#define OPEN 0


#define OK 1
#define NG 0

#define true 1
#define false 0

typedef uint8_t * (* DATA_READ_CALLBACK)(uint8_t *buf , int offset , int size , int *read_size);
typedef void * (* VOID_CALLBACK)(void);


typedef struct{
	uint8_t *callback_buf;
	DATA_READ_CALLBACK read_callback;
	int callback_type;
	int tag;
}inx_call_back_t;


typedef struct{
    uint8_t  Red;
    uint8_t  Green;
    uint8_t  Blue;
    uint8_t  Alpha;
}Color;
typedef struct{
	int x;
	int y;
}Point;

typedef struct{
	int x;
	int y;
	int w;
	int h;
}Rectangle;


typedef struct{
	int     color_type;			// 0:RGB565  1:YCbCr422
	uint8_t *buffer;			// RGB565 バッファ
	int		width;				// バッファの幅
	int		height;				// バッファの高さ
	int		stride;				// バッファのストライド
	int		alpha_bit;			// アルファ合成用のデータのビット数
	uint8_t *alpha_buffer;		// アルファ合成用のバッファ
	
}inx_frame_t;


#endif		// _STDINX_H
