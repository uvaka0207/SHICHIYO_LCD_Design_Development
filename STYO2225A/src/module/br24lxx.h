//
//	EEPROM access control header file.
//
//		Copyright (C) 2004-08 INX Corporation
//		$Id: br24lxx.h,v 1.1 2016/02/16 08:22:18 satou Exp $
//
#ifndef	_BR24LXX_H
#define	_BR24LXX_H



//
//	Global function references
//
//		eeprom書き込み動作
extern	int eep_write_process(uint8_t data_top[], uint16_t data_size, uint16_t eep_top);
//		eeprom読み込み動作
extern	int eep_read_process(uint8_t data_ptr[], uint16_t data_size, uint16_t eep_top);

extern	int eep_data_fill(uint8_t fill_data);
extern	int eep_fill_data_check(uint8_t fill_data);
extern	void eep_all_data_read(uint8_t *dt_ptr, uint16_t size);




//
//	EEPROM　品種選択
//	使用するEEPROMの型番だけを有効にする。
//
//#define	BR24L04
//#define	BR24L08
#define	BR24L128
//#define	BR24L256


#ifdef	BR24L02
#define	EEPROM_SIZE				256			//	EEPROMサイズ
#define	EEP_PAGE_SIZE			8			//	EERPOMページサイズ(ページライトコマンドにて書き込めるByte数)
#define	EEP_PAGE_NUM			0			//	EEPROMページ数(書き込みアドレス指定時に指定できる最大ページ数)
#define	EEP_MAX_DEV				8			//	EEPROM最大デバイス数(同一IICバス上に接続できる最大デバイス数)
#endif

#ifdef	BR24L04
#define	EEPROM_SIZE				512			//	EEPROMサイズ
#define	EEP_PAGE_SIZE			16			//	EERPOMページサイズ(ページライトコマンドにて書き込めるByte数)
#define	EEP_PAGE_NUM			2			//	EEPROMページ数(書き込みアドレス指定時に指定できる最大ページ数)
#define	EEP_MAX_DEV				4			//	EEPROM最大デバイス数(同一IICバス上に接続できる最大デバイス数)
#endif

#ifdef	BR24L08
#define	EEPROM_SIZE				1024		//	EEPROMサイズ
#define	EEP_PAGE_SIZE			16			//	EERPOMページサイズ(ページライトコマンドにて書き込めるByte数)
#define	EEP_PAGE_NUM			4			//	EEPROMページ数(書き込みアドレス指定時に指定できる最大ページ数)
#define	EEP_MAX_DEV				2			//	EEPROM最大デバイス数(同一IICバス上に接続できる最大デバイス数)
#endif

#ifdef	BR24L64
#define	EEPROM_SIZE				8192		//	EEPROMサイズ
#define	EEP_PAGE_SIZE			32			//	EERPOMページサイズ(ページライトコマンドにて書き込めるByte数)
#define	EEP_PAGE_NUM			0			//	EEPROMページ数(書き込みアドレス指定時に指定できる最大ページ数)
#define	EEP_MAX_DEV				8			//	EEPROM最大デバイス数(同一IICバス上に接続できる最大デバイス数)
#endif

#ifdef	BR24L128
#define	EEPROM_SIZE				16384		//	EEPROMサイズ
#define	EEP_PAGE_SIZE			64			//	EERPOMページサイズ(ページライトコマンドにて書き込めるByte数)
#define	EEP_PAGE_NUM			0			//	EEPROMページ数(書き込みアドレス指定時に指定できる最大ページ数)
#define	EEP_MAX_DEV				8			//	EEPROM最大デバイス数(同一IICバス上に接続できる最大デバイス数)
#endif

#ifdef	BR24L256
#define	EEPROM_SIZE				32768		//	EEPROMサイズ
#define	EEP_PAGE_SIZE			64			//	EERPOMページサイズ(ページライトコマンドにて書き込めるByte数)
#define	EEP_PAGE_NUM			0			//	EEPROMページ数(書き込みアドレス指定時に指定できる最大ページ数)
#define	EEP_MAX_DEV				8			//	EEPROM最大デバイス数(同一IICバス上に接続できる最大デバイス数)
#endif

#ifdef	BR24L512
#define	EEPROM_SIZE				65536		//	EEPROMサイズ
#define	EEP_PAGE_SIZE			128			//	EERPOMページサイズ(ページライトコマンドにて書き込めるByte数)
#define	EEP_PAGE_NUM			0			//	EEPROMページ数(書き込みアドレス指定時に指定できる最大ページ数)
#define	EEP_MAX_DEV				8			//	EEPROM最大デバイス数(同一IICバス上に接続できる最大デバイス数)
#endif

//
//	Global data references
//


//	IOレジスター






#endif		// _BR24LXX_H
