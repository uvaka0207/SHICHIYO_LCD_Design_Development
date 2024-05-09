//
//  標準ライブラリ
//
//  ファイル名 : timer.h
//
//  機能       : タイマ制御
//
//  !!! 注意事項 !!!
//  42日以上の計測には使用しないこと
//
//   Copyright inX Corporation
//
//<<<<< 変更履歴 >>>>>
//	ver.0001	2014/05/01	: 1) 1st

#ifndef	_TIMER_H
#define	_TIMER_H

#include	"stdinx.h"



//
//	Global data references
//

#define	TIMEOUT					1
#define	WAITING					0



//
//	Global function references
//

extern	int		wait_timeout(time_t timeout, time_t basetime);	// タイムアウト待ち
extern	time_t	get_past_time(time_t basetime);					// 経過時間を取得する
extern	time_t	get_sys_timer(void);							// システムタイムカウンタを取得する
extern	void	exc_timer_handler(void);						// システムインターバルタイマ



#endif		// _TIMER_H
