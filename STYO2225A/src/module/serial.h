//
//	Serial input/output functions header.
//
//		Copyright (C) 2003-04 INX Corporation
//		$Id: serial.h,v 1.1 2019/09/02 12:38:26 satou Exp $
//
#ifndef	_SERIAL_H
#define	_SERIAL_H

#include	"stdinx.h"


// ユーザー使用関数

extern void serial_rs485_send_mode(int port_id , int mode);


extern void serial_open(int port_id);
extern void serial_close(int port_id);
extern size_t get_serial_rxdata(int port_id);
extern size_t serial_read(int port_id , uint8_t *buf, size_t len);
extern size_t serial_write(int port_id, uint8_t *buf, size_t len);
extern size_t serial_strings_write(int port_id, char *buf);
extern int serial_get_write_buf_size(int port_id);
extern int serial_get_txd_free_size(int port_id);
extern int serial_get_send_end(int port_id);

extern void serial_set_bitrate(int port_id , int bitrate);
extern void serial_set_parity(int port_id , int parity);
extern void serial_set_bitnum(int port_id , int bit_num);
extern void serial_set_stopbit(int port_id  , int stopbit);

// SCIモジュールから呼び出される関数

extern void serial_rxd_callback(int port_id , uint8_t ch);
extern void serial_txd_callback(int port_id);

// 送信・受信バッファーサイズ
#define	SERIAL_RECV_BUFSZ	64
#define	SERIAL_SEND_BUFSZ	256




#define SERIAL_BITRATE_9600			9600
#define SERIAL_BITRATE_19200		19200
#define SERIAL_BITRATE_38400		38400

#define SERIAL_STOPBIT1				1
#define SERIAL_STOPBIT2				2


#define SERIAL_PARITY_NONE			0
#define SERIAL_PARITY_EVEN			1
#define SERIAL_PARITY_ODD			2

#define SERIAL_BIT_NUM7				7
#define SERIAL_BIT_NUM8				8
#define SERIAL_BIT_NUM9				9


#endif		// _SERIAL_H
