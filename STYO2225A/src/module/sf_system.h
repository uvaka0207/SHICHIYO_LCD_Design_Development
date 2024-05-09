﻿#ifndef		_SF_SYSTEM_H
#define		_SF_SYSTEM_H

#include "stdinx.h"

//------------------------------------------------------------------------------
// 外部参照変数宣言
//------------------------------------------------------------------------------

extern void sfsys_init(void);

//------------------------------------------------------------------------------
// 関数名	sfsys_flash_page_read
// 機能		FLASHからデータを読み出す
//			2048バイト以上の場合は次のページも読み込む
// 引数		address:読み出しアドレス, buf:データバッファ, size:読み出しサイズ
// 戻り値	0:読み出し失敗, 1:読み出し成功
//------------------------------------------------------------------------------
int sfsys_flash_page_read(uint32_t block_id , int page_id ,  uint8_t buf[], uint16_t size);
//------------------------------------------------------------------------------
// 関数名	sfsys_flash_page_write
// 機能		FLASHのページにデータを書き込む
//			2048バイト以上の場合は次のページにもデータを書き込む
// 引数		address:書き込みアドレス , buf:データバッファ, size:書き込みサイズ
// 戻り値	0:書き込み失敗, 1:書き込み成功
//------------------------------------------------------------------------------
int sfsys_flash_page_write(uint32_t block_id , int page_id ,  uint8_t buf[], uint16_t size);

//------------------------------------------------------------------------------
// 関数名	sfsys_flash_block_read
// 機能		FLASHからデータを読み出す
//			MAX 1block(128Kbyte)
// 引数		address:読み出しアドレス, buf:データバッファ, size:読み出しサイズ
// 戻り値	0:読み出し失敗, 1:読み出し成功
//------------------------------------------------------------------------------
int sfsys_flash_block_read(uint32_t block_id ,  uint8_t buf[], uint16_t size);
//------------------------------------------------------------------------------
// 関数名	sfsys_flash_block_write
// 機能		FLASHのブロックにデータを書き込む
//			MAX 1block(128Kbyte)
// 引数		address:書き込みアドレス , buf:データバッファ, size:書き込みサイズ
// 戻り値	0:書き込み失敗, 1:書き込み成功
//------------------------------------------------------------------------------
int sfsys_flash_block_write(uint32_t block_id ,  uint8_t buf[], uint16_t size);


//------------------------------------------------------------------------------
// 関数名	sfsys_flash_block_erase
// 機能		フラッシュメモリの割当済みブロックを消去する
// 引数		なし
// 戻り値	なし
//------------------------------------------------------------------------------
int sfsys_flash_block_erase(uint32_t block_id);

#endif		// _SF_SYSTEM_H
