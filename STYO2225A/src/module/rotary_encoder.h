/*
 * rotary_encoder.h
 *
 *  Created on: 2023/10/20
 *      Author: satou
 */


#ifndef MODULE_ROTARY_ENCODER_H_
#define MODULE_ROTARY_ENCODER_H_


#define ROTARY_SW_ON		1
#define ROTARY_SW_OFF		2
#define ROTARY_SW_LONG_ON	4
#define ROTARY_SW_REPEAT	8

/*
 * 	ローターリーエンコーダー処理初期化
 * 		ロータリーエンコーダーを使用するレイヤーの開始時に呼ぶ
 *
 */
void rotary_encoder_init(void);
/*
 * 	ロータリーエンコーダーの変化量を取得する
 * 		前回呼び出してから変化した値を読み込む
 *
 */
int get_rotary_encoder_delta(void);
/*
 * 	ロータリーエンコーダーのスイッチ情報を取得する
 */
int get_rotary_encoder_sw(void);


#endif /* MODULE_ROTARY_ENCODER_H_ */
