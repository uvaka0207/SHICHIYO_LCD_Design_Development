﻿/*
 *  Copyright (C) 2003-04 INX Corporation. All rights reserved.
 *  @(#) $Id: debug.c,v 1.1 2019/09/02 12:38:26 satou Exp $
 */

#include "stdinx.h"
#include "sci_rz.h"
#include "serial.h"

#include "common.h"
#include "string.h"
#include "version.h"
#include "layer/layer.h"
#include "touch_ctrl.h"
#define DEBUG_PORT		PORTID_UART_4

#define MAXSTRSIZE 128

#define DEBUG_MESSAGE_MAX_NUM			16
#define DEBUG_MESSAGE_MAX_BUF			32

struct _debug_data
{
	uint8_t read_data[32];
	uint8_t read_num;


	int debug_message_input;
	int debug_message_output;

	char debug_message[DEBUG_MESSAGE_MAX_NUM][DEBUG_MESSAGE_MAX_BUF];


}debug_data;





/*
 *		文字列検索
 */
int debug_indexOf(const char src[],const char search[])
{
	int n;
	int i;
	int j;
	n = strlen(search);

	for(i = 0; i < MAXSTRSIZE && src[i] != 0;i++)
	{
		if(src[i] == search[0]){
			int check = 1;
			for(j = 1; j < n;j++){
				if(src[i + j] == 0){
					check = 0;
					break;
				}
				if(src[i + j] != search[j]){
					check = 0;
					break;
				}
			}
			if(check == 1){
				return i;
			}
		}
		
	}
	return -1;
}

/*
 *		文字列から文字列を取り出す
 *		引数
 *			buf        : 読み出す文字列
 *			startIndex : 開始位置
 *			size       : 読み込むサイズ
 */
char *debug_strmid(char dest[] , const char buf[] , int startIndex , int size)
{
	int i;
	for(i = 0 ; i < size ; i++){
		dest[i] = buf[startIndex + i];
		if(buf[startIndex + i] == 0){
			break;
		}
	}
	dest[i] = 0;
	return dest;
	
}
/*
 *		文字列を比較する
 *		引数
 *			buf        : 読み出す文字列
 *			startIndex : 開始位置
 *			size       : 読み込むサイズ
 */
int debug_strcmp(const char n1[],const char n2[])
{
	int i;
	for(i = 0;i < MAXSTRSIZE;i++){	//限界繰り返し数がMAXSTRSIZE
		if(n1[i] == 0 && n2[i] == 0) return 0;	//同じなら0
		if(n1[i] == 0)return 1;		//n1の方が先
		if(n2[i] == 0)return -1;		//n2の方が先
		if(n1[i] < n2[i])return 1;	//n1の方が先
		if(n1[i]>n2[i])return -1;	//n2の方が先
	}
	return 0;	
}




/*
 * 数値を文字列に変換する
 * dat:変換前数値
 * buf:格納先文字列
 * n:n進数
 * flag: 0～32:空白埋め文字数    101～132:0埋め文字数
 */
char *debug_itoString(int32_t dat,char *buf,int n,int flag)
{
	int32_t i = 0,j;
	int32_t len;
	int32_t sign = 1;
	char temp;
	if(dat == 0){
		buf[0]='0';
		i++;
	}
	if(dat < 0){
		dat=-dat;
		sign=-1;
	}
	while(dat > 0){				//文字の生成
		uint8_t w = (uint8_t)(dat % n);
		if(w < 10){
			buf[i] =(int8_t)(w + '0');
		}else{
			buf[i] =(int8_t)((w - 10) + 'A');
		}
		dat /= n;
		i++;
	}

	if(flag > 100 && flag <= 132){	//0埋め
		len = i;
		for(j = 0;j < (flag - 100) - len;j++){
			buf[i]='0';
			i++;
		}
	}
	if(sign == -1){					//-なら-を書く
		buf[i]='-';
		i++;
	}
	if(flag > 0 && flag <= 32){		//空白埋め
		len = i;
		for(j = 0;j < flag - len;j++){
			buf[i]=' ';
			i++;
		}
	}

	for(j = 0;j < i / 2;j++)				//文字の順番を交換する
	{
		temp = buf[j];
		buf[j] = buf[i - j-1];
		buf[i - j-1] = temp;
	}
	buf[i] = 0;						//NULLをつける
	return buf;

}
char *debug_itoa(int32_t n,char buf[],int flag)
{
	int32_t i = 0;
	int32_t j;
	int32_t len;
	int32_t sign = 1;

	if(n == 0){
		buf[0] = '0';
		i++;
	}

	if(n < 0){
		n = -n;
		sign = -1;
	}

	while(n > 0){						//文字の生成
		buf[i] = (char)((n % 10) + '0');
		n /= 10;
		i++;
	}

	if((flag > 10) && (flag <= 20)){	//0埋め
		len = i;
		for(j = 0; j < ((flag - 10) - len); j++){
			buf[i] = '0';
			i++;
		}
	}

	if(sign == -1){						//-なら-を書く
		buf[i] = '-';
		i++;
	}

	if((flag > 0) && (flag <= 10)){		//空白埋め
		len = i;
		for(j = 0; j < (flag - len); j++){
			buf[i] = ' ';
			i++;
		}
	}

	for(j = 0; j < (i / 2); j++)		//文字の順番を交換する
	{
		char temp;

		temp = buf[j];
		buf[j] = buf[i - j - 1];
		buf[i - j - 1] = temp;
	}

	buf[i] = 0;							//NULLをつける

	return buf;

}

char *debug_dtoa(int32_t n, uint8_t dot, char buf[])
{
	int32_t	sign;
	int32_t	len = 0;
	int32_t j;

	sign = n;
	if (sign < 0){
		n = -n;				// 負数
	}

	do {		// 文字列を逆順に生成する.
		if ((dot == 0) || (len != dot)){
			buf[len] = (char)(n % 10 + '0');
			n /= 10;
		}
		else {
			buf[len] = '.';
		}
		++len;
	} while ((n != 0) || ((dot != 0) && len < (dot + 2)));

	if (sign < 0){
		buf[len++] = '-';		// 負数
	}


	for(j = 0; j < (len / 2); j++)		//文字の順番を交換する
	{
		char temp;

		temp = buf[j];
		buf[j] = buf[len - j - 1];
		buf[len - j - 1] = temp;
	}

	buf[len] = '\0';
	return buf;
}
char *debug_ftoa(float n, uint8_t dig, char buf[])
{
	int	len = 0;
	int32_t	work;
	uint8_t	sign = 0;
	int		i;
	int		j;

	if (n < 0){
		n = -n;
		sign = 1;				// 負数
	}

	for (i = 0; i < dig; i++){
		n *= 10.0f;
	}
	work = (int32_t)n;

	do {		// 文字列を逆順に生成する.
		if ((dig == 0) || (len != dig)){
			buf[len++] = (char)((work % 10) + '0');
			work /= 10;
		}
		else {
			buf[len++] = '.';
		}
	} while ((work != 0) || ((dig > 0) && (len < (dig + 2))));

	if (sign){
		buf[len++] = '-';			// 負数
	}

	// 文字列を逆順に並べ替える.
	for(j = 0 ; j < (len / 2) ; j++)				//文字の順番を交換する
	{
		char temp;

		temp = buf[j];
		buf[j] = buf[len - j - 1];
		buf[len - j - 1] = temp;
	}

	buf[len] = '\0';
	return buf;
}
int32_t debug_atoi(const char buf[])
{
	int32_t ret = 0;
	int i;								/* ループ用のカウンタはintを使用する */
	int sign = 0;

	for(i = 0; (i < 16) && (buf[i] != 0) ; i++){
		uint16_t t;

		t = buf[i];
		if((t >= '0') && (t <= '9')){	//0 - 9の文字なら
			ret *= 10;
			ret += (t - '0');
		}
		else if(t == '-'){				// 負の符号を検出
			sign = 1;
		}
		else if(t == '.'){				// 小数点を検出したら終了
			break;
		}
		else{
			/* 範囲外はスルー */
		}
	}

	if (sign){
		ret = -ret;						// 負数
	}

	return ret;
}
int32_t debug_atod(const char buf[] , int dot)
{
	int32_t ret = 0;
	int i;								/* ループ用のカウンタはintを使用する */
	int sign = 0;
	int d = 0;
	// 整数部変換
	for(i = 0; (i < 16) && (buf[i] != 0) ; i++){
		uint16_t t;

		t = buf[i];
		if((t >= '0') && (t <= '9')){	//0 - 9の文字なら
			ret *= 10;
			ret += (t - '0');
		}
		else if(t == '-'){				// 負の符号を検出
			sign = 1;
		}
		else if(t == '.'){				// 小数点を検出したら終了
			break;
		}
		else{
			/* 範囲外はスルー */
		}
	}
	// 小数部変換
	for(; (i < 16) && (buf[i] != 0) ; i++){
		uint16_t t;

		t = buf[i];
		if((t >= '0') && (t <= '9')){	//0 - 9の文字なら
			ret *= 10;
			ret += (t - '0');
			d++;
			if(d > dot){
				break;
			}
		}
		else{
			/* 範囲外はスルー */
		}
	}
	// 小数部データが足りない場合
	for(; (d < dot); d++){
		ret *= 10;
	}

	if (sign){
		ret = -ret;						// 負数
	}

	return ret;
}

void debug_serial_write_str(char *data)
{
	while(serial_get_txd_free_size(DEBUG_PORT) < 16){								// シリアルポートに16バイト以上の空きがある場合
		Sleep(100);
	}
	serial_strings_write(DEBUG_PORT , data);
}



void debug_serial_write(int32_t data,int flag)
{
	char buf[16];
	debug_itoa(data,buf,0);
	if(flag == 1){
		int i = 0;
		while(buf[i] != 0 ){
			i++;
		}
		buf[i++] = ',';
		buf[i++] = 0;

	}
	debug_serial_write_str(buf);
}


void debug_serial_decimal(int32_t data,int flag , int dig)
{
	char buf[16];
	debug_dtoa(data , dig , buf);
	if(flag == 1){
		int i = 0;
		while(buf[i] != 0 ){
			i++;
		}
		buf[i++] = ',';
		buf[i++] = 0;

	}
	debug_serial_write_str(buf);
}

void debug_serial_write_float(float data,int flag)
{
	char buf[32];
	debug_ftoa(data , 2 , buf);
	if(flag == 1){
		int i = 0;
		while(buf[i] != 0 ){
			i++;
		}
		buf[i++] = ',';
		buf[i++] = 0;
	}
	debug_serial_write_str(buf);
}


void debug_data_send(void)
{
	int cpu_use[16];
	int i;
	int x;
	int y;
	static time_t debug_timer;
	if(wait_timeout(1000UL , debug_timer)){
		debug_timer = get_sys_timer();
		debug_serial_write_str("D=");
		debug_serial_write(mode.mode,1);
		// 画面レイヤー情報の送信
		if(GetTouchRealXY(&x , &y)){
			debug_serial_write(x , 1);
			debug_serial_write(y , 1);
		}else{
			debug_serial_write(0 , 1);
			debug_serial_write(0 , 1);

		}


		for(i = 0 ; i < MAX_LAYER ; i++){
			debug_serial_write(mode.layer[i],1);
		}


		// CPU利用率の送信
		GetThreadCpuUse(cpu_use  , 16);
		for(i = 0 ; i < 16 ; i++){
			debug_serial_decimal(cpu_use[i] , 1 , 1);
		}
		// IO情報の送信



		debug_serial_write_str(VERSION);
		debug_serial_write_str(",");
		// デバッグ用専用データ
		if(debug_data.debug_message_input != debug_data.debug_message_output){
			debug_serial_write_str(debug_data.debug_message[debug_data.debug_message_output]);
			debug_data.debug_message_output++;
			if(debug_data.debug_message_output >= DEBUG_MESSAGE_MAX_NUM){
				debug_data.debug_message_output = 0;
			}
		}


		debug_serial_write_str("\n");
	}
}


/*
 *		パラメータ送信処理
 */
void debug_parameter_send(void)
{
	int i;
	debug_serial_write_str("P=");
//	for(i = 0; i < PARAMETER_DATA_MAX; i++){
//		debug_serial_decimal(GetParameterData((enum PARAMETER_DATA)(i)) , 1 , GetParameterDig((enum PARAMETER_DATA)(i)));
//	}
	debug_serial_write_str("\n");
}


/*
 *		パラメータ送信処理
 */
void debug_err_history_send(void)
{

}

void debug_message_send(void)
{
}

void debug_read_command(void)
{
	if(strcmp("GET E",(char *)debug_data.read_data) == 0){			// エラー履歴送信要求コマンドの場合
		debug_err_history_send();
	}
	if(strcmp("GET P",(char *)debug_data.read_data) == 0){			// パラメータ送信要求コマンドの場合
		debug_parameter_send();
	}
	if(debug_indexOf((char *)debug_data.read_data , "SET P") == 0){						// パラメータ設定コマンドの場合
		int sep = debug_indexOf((char *)debug_data.read_data , "=");						// = 文字列のある場所
		if(sep > 5){
			char id_str[16];
			char number_str[32];
			int id;
			int number;
			debug_strmid(id_str , (char *)debug_data.read_data , 5 , sep - 5);			// ID文字列の取り出し
			debug_strmid(number_str , (char *)debug_data.read_data , sep + 1 , 32);		// 番号の取り出し
			id = (int)debug_atoi(id_str) - 1;
			// IDによって特殊な処理が必要な場合は処理を変更する。
//			number = (int)debug_atod(number_str , GetParameterDig((enum PARAMETER_DATA)(id)));
//			SetParameterData((enum PARAMETER_DATA)id , number);
		}
	}

	if(strcmp("PARAMETER DEFAULT",(char *)debug_data.read_data) == 0){			// パラメータ初期化コマンド
//		Set_DefaultParameterData();
	}
	
}
void debug_read(void)
{
	int i;
	int len = get_serial_rxdata(DEBUG_PORT);
	for(i = 0 ; i < len ; i++){
		uint8_t ch;
		serial_read(DEBUG_PORT , (uint8_t *)&ch , 1);
		if(ch == '\n'){
			debug_data.read_data[debug_data.read_num++] = 0;			// 改行をNull文字に変更して格納
			debug_read_command();										// コマンド確認
			debug_data.read_num = 0;									// 初期化
		}else{
			debug_data.read_data[debug_data.read_num++] = ch;			// データを格納
			if(debug_data.read_num >= sizeof(debug_data.read_data)){	// 初期化
				debug_data.read_num = 0;
			}
		}
		
		
	}
	
	
}



void init_debug(void)
{
	serial_set_bitrate(DEBUG_PORT , 9600);
	serial_set_parity(DEBUG_PORT , SERIAL_PARITY_NONE);
	serial_set_bitnum(DEBUG_PORT , SERIAL_BIT_NUM8);
	serial_set_stopbit(DEBUG_PORT , SERIAL_STOPBIT1);
	serial_open(DEBUG_PORT);

}



int Debug_Task(void)
{
	init_debug();
	while(1){
		debug_data_send();
		debug_read();
		Sleep(10);
	}

}

/*
 *		デバッグ用のメッセージを送信する。
 */
void debug_message(char mes[])
{
	int i;
	for(i = 0 ; mes[i] != 0 && i < DEBUG_MESSAGE_MAX_BUF - 1 ;i++){
		debug_data.debug_message[debug_data.debug_message_input][i] = mes[i];
	}
	debug_data.debug_message[debug_data.debug_message_input][i] = 0x00;
	debug_data.debug_message_input++;
	if(debug_data.debug_message_input >= DEBUG_MESSAGE_MAX_NUM){
		debug_data.debug_message_input = 0;
	}
}
