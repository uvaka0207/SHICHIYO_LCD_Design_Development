//
//	Serial input/output functions header.
//
//		Copyright (C) 2003-04 INX Corporation
//		$Id: sci_rx.h,v 1.1 2019/09/02 12:38:26 satou Exp $
//
#ifndef	_SCI_H
#define	_SCI_H

#include	"stdinx.h"

// ハードウェア依存関数

extern void sci_open(int port_id);
extern void sci_close(int port_id);
extern void sci_set_bitrate(int port_id , int bitrate);
extern void sci_set_parity(int port_id , int parity);
extern void sci_set_bitnum(int port_id , int bit_num);
extern void sci_set_stopbit(int port_id  , int stopbit);

extern void sci_send_buf(int port_id , uint8_t buf[] , int size);
extern void sci_send_end(int port_id );
extern int sci_get_tend(int port_id );


extern void sci_enable_txd_int(int port_id);
extern void sci_disable_txd_int(int port_id);
extern void sci_enable_rxd_int(int port_id);
extern void sci_disable_rxd_int(int port_id);



//
//	ハードウェア依存情報の定義
//

//  SCIの割り込みルーチンに登録する
extern void sci_rxd_callback(int port_id);
extern void sci_txd_callback(int port_id);


#define NUM_PORT		8			// 使用するポート数

#define SCI_SEND_BUF_SIZE 8

/* 
 *		使用するポートを設定する
 *		使用するポートのdefineを外して0から順に使用するポートに割り当てること
 */
#define PORTID_UART_0			0			// ポート番号
#define PORTID_UART_1			1			// ポート番号
#define PORTID_UART_2			2			// ポート番号
#define PORTID_UART_3			3			// ポート番号
#define PORTID_UART_4			4			// ポート番号
#define PORTID_UART_5			5			// ポート番号
#define PORTID_UART_6			6			// ポート番号
#define PORTID_UART_7			7			// ポート番号




//#define SCI_SMR_BIT_MP			0x04
#define SCI_SMR_BIT_CKS			0x03
#define SCI_SMR_BIT_STOP		0x08
#define SCI_SMR_BIT_OE			0x10
#define SCI_SMR_BIT_PE			0x20
#define SCI_SMR_BIT_CHR			0x40
#define SCI_SMR_BIT_CA			0x80


#define SCI_SCR_BIT_REIE		0x08
#define SCI_SCR_BIT_RE			0x10
#define SCI_SCR_BIT_TE			0x20
#define SCI_SCR_BIT_RIE			0x40
#define SCI_SCR_BIT_TIE			0x80


#define SCI_FSR_BIT_TEND		0x40
#define SCI_FSR_BIT_TDFE		0x20
#define SCI_FSR_BIT_RDF			0x02


#endif		// _SERIAL_H
