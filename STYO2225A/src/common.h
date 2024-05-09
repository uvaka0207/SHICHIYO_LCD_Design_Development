
#ifndef	_COMMON_H
#define	_COMMON_H

#include "stdinx.h"
#include "os/os.h"
#include "os/intc.h"
#include "timer.h"
#include "inx_tool.h"
#include "mode.h"
#include "io.h"
#include "buzzer.h"
#include "library.h"
#include "debug.h"
#include "touch_check.h"
#include "setting.h"

enum pop_type
{
	POP_TYPE_NONE,
	POP_TYPE_CLOSE_MESSAGE,				// 通常 CLOSEメッセージ表示
	POP_TYPE_SELECT_MESSAGE,			// 通常 OK Cancelメッセージ表示

};

/* 共通情報構造体  */
struct info_struct
{
	// システムデータ

	int year;
	int month;
	int day;
	int week;
	int hour;
	int minute;
	int second;



	uint32_t clock_sec;			// 2000年1月1日からの累積秒


	int set_year;
	int set_month;
	int set_day;
	int set_hour;
	int set_minute;


	// その他必要なデータ

};

struct err_struct
{
	uint8_t err;						// エラー番号
	time_t err1_timer;					// エラー1用タイマー
	time_t err2_timer;					// エラー2用タイマー
	time_t err3_timer;					// エラー3用タイマー

};

#ifdef GLOBAL_DEFINE
#define GLOBAL
#else
#define GLOBAL extern
#endif
#define	CODE_LIST_MAX_SIZE			39
#define	CODE_NAME_MAX_SIZE			11
#define PROCESS_MAX_SIZE_ZERO_ON	10
#define PROCESS_MAX_SIZE_ZERO_OFF	9
#define CODE_LIST_MAX_SIZE_IN_PAGE	10

typedef enum {			//ヒーターの出力
	HIGH,				//荒火
	MEDIUM,				//軟火
	LOW,				//極軟
}heater_mode;

typedef enum {			//手動運転or自動運転(工程番号の表示/非表示に使用)
	S_MANUAL,			//手動運転
	S_AUTO,				//自動運転
}select_manual_or_auto;

typedef enum {			//扉リミット　[開/閉]
	DL_OPEN,			//開
	DL_CLOSE,			//閉
}door_limit;

typedef enum {			//2択状態確認
	STS_NONE,			//未使用
	STS_TRUE,			//使用中
}status;

typedef enum {			//タイマー状態
	BTS_NONE,			//昇温中
	BTS_WAIT,			//タイマー未設定
	BTS_STOP,			//停止中
	BTS_RUNTIME,		//運転中
	BTS_PROCESS_SW,		//工程の切替時
	BTS_COMPLETE,		//タイマー終了
}bake_timer_status;

typedef enum {			//スタートボタンの状態
	SS_NONE,			//押下不可
	SS_WAIT,			//待機状態
	SS_RUNTIME,			//焼成中
}start_status;

typedef enum {			//排気状態
	D_CLOSE,			//ダンパー閉
	D_NATURAL,			//自然排気
	D_AUTO,				//強制排気
}damper_status;

typedef enum {
	CONF_NONE,					//未選択
	CONF_WARMUP_TEMP, 			//立上通知温度設定中
	CONF_PROCESS_SW_TIMER,		//自動運転切替時間設定中
	CONF_STEAM_TIMER,			//蒸気出力時間設定中
}config_status;

typedef enum {			//選択しているモード
	C_MODE_ENTER,		//コード選択
	C_MODE_DETAIL,		//詳細確認
	C_MODE_DELEATE,		//コード削除
	C_MODE_NAME,		//コード名称変更
	C_MODE_PROCESS,		//コード内容変更
}c_mode_select;

typedef enum {			//選択しているモード
	D_MODE_NONE,		//モード未選択
	D_MODE_DELEATE,		//工程削除
	D_MODE_EDIT,		//工程編集
}d_mode_select;

typedef enum {
	NS_NONE,
	NS_FIRST,
	NS_EVERY,
}notic_status;

typedef struct {					//手動運転内容記憶用	(ram_manual_parameter m;)
	int time_minute_m;				//前回手動運転時の設定時間(分)
	int time_second_m;				//前回手動運転時の設定時間(秒)
	int uh_temp_m;					//前回手動運転時の上火設定温度
	int lh_temp_m;					//前回手動運転時の下火設定温度
	int core_temp_integer_m;		//前回手動運転時の芯温設定温度(整数)
	int core_temp_decimal_m;		//前回手動運転時の芯温設定温度(小数)
	heater_mode uh_mode_m;			//前回手動運転時の上火火力モード
	heater_mode lh_mode_m;			//前回手動運転時の下火火力モード
	damper_status damper_sts_m;		//前回手動運転時のダンパー状態
	status core_temp_sts_m;			//前回手動運転時の芯温状態[OFF/ON]
}ram_manual_parameter;

typedef struct {															//自動運転内容記憶用	(ram_auto_parameter a;)
	wchar_t code_name[CODE_LIST_MAX_SIZE][CODE_NAME_MAX_SIZE];				//菓子コード名[39種][10文字]
	int process_max[CODE_LIST_MAX_SIZE];									//各コードの工程数[39種]
	int time_minute[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_OFF];			//自動運転設定時間(分)[39種][1-9工程]
	int time_second[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_OFF];			//自動運転設定時間(秒)[39種][1-9工程]
	int uh_temp[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_ON];				//自動運転上火設定温度[39種][0-9工程]
	int lh_temp[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_ON];				//自動運転下火設定温度[39種][0-9工程]
	int core_temp_integer[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_OFF];	//自動運転芯温設定温度[39種][1-9工程]
	int core_temp_decimal[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_OFF];	//自動運転芯温設定温度[39種][1-9工程]
	heater_mode uh_mode[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_ON];		//自動運転上火火力モード[39種][0-9工程]
	heater_mode lh_mode[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_ON];		//自動運転上火火力モード[39種][0-9工程]
	damper_status damper_sts[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_ON];	//自動運転ダンパー状態[39種][0-9工程]
	status core_temp_sts[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_OFF];	//自動運転芯温状態[39種][1-9工程]
	status steam_sts[CODE_LIST_MAX_SIZE][PROCESS_MAX_SIZE_ZERO_OFF];		//自動運転蒸気状態[39種][1-9工程]
	status warmup_buzzer[CODE_LIST_MAX_SIZE];								//昇温通知(無し/有り：初期設定は有り)
	select_manual_or_auto process_change[CODE_LIST_MAX_SIZE];				//工程の切替(手動/自動：初期設定は自動)
}ram_auto_parameter;

typedef struct {					//その他記憶用	(ram_other t;)
	time_t process_sw_timer;		//工程を自動で切り替えるまでの時間(初期値：2000msec、ユーザー設定可)
	time_t steam_timer;				//蒸気出力時間の設定(初期値:3000msec、ユーザー設定可)
	notic_status mns;				//手動運転時、昇温通知設定
	int warmup_temp;				//運転準備完了とする温度(初期値：10、ユーザー設定可)
}ram_other;

typedef struct{									//ホーム画面で使用するパラメータ	(home_parameter h;)
	int code_no_now;							//選択している菓子コード番号
	wchar_t code_name_now[CODE_NAME_MAX_SIZE];	//選択している菓子コードの名称
	int process_now;							//運転中の工程番号
	int process_max;							//使用コードの最終工程番号
	int time_minute_set;						//設定時間(分表示用)
	int time_second_set;						//設定時間(秒表示用)
	int time_minute_now;						//焼成時間(分)
	int time_second_now;						//焼成時間(秒)
	int uh_temp_set;							//上火設定温度
	int lh_temp_set;							//下火設定温度
	int core_temp_set_integer;					//芯温設定温度(整数)
	int core_temp_set_decimal;					//芯温設定温度(小数)
	float uh_temp_now;							//上火現在温度
	float lh_temp_now;							//下火現在温度
	float core_temp_now;						//芯温現在温度
	select_manual_or_auto select_m_a;			//手動自動の状態
	heater_mode uh_mode_now;					//上火設定火力状態
	heater_mode lh_mode_now;					//下火設定火力状態
	bake_timer_status b_t_sts;					//焼成の運転状態
	start_status start_sts;						//スタート状態[無効/待機中/運転中]
	damper_status damper_sts_now;				//ダンパー状態[閉/自然/強制]
	status core_temp_sts_now;					//芯温状態[OFF/ON]
	status steam_sts_now;						//蒸気状態[無/放出中]
	status lamp_sts;							//炉内照明状態[OFF/ON]
	status clear_sts;							//クリア状態[無効/有効]
	status buzzer_sts;							//ブザー状態[無効/有効]
	status recipe_sts;							//レシピ状態[無効/有効]
	status eco_sts;								//エコモード状態[OFF/ON]
	status popup_temp_sts;						//温度設定ウィンドウ表示状態
	status popup_time_sts;						//時間設定ウィンドウ表示状態
	status popup_c_temp_sts;					//芯温設定ウィンドウ表示状態
	door_limit dl_sts;							//扉リミットの開閉確認
	time_t auto_count;							//運転時間計測用
	time_t process_count;						//工程切替時間計測用
	time_t steam_count;							//蒸気ON時間計測用
	int manual_first_counter;
}home_parameter;

typedef struct{							//温度設定画面で使用するパラメータ	(layer_temp_parameter l_temp;)
	int uh_temp_prov;					//上火設定温度
	int lh_temp_prov;					//下火設定温度
	heater_mode uh_mode_prov;			//上火設定モード
	heater_mode lh_mode_prov;			//下火設定モード
}layer_temp_parameter;

typedef struct {						//時間設定画面で使用するパラメータ	(layer_time_parameter l_time;)
	int time_minute_prov;				//設定時間[分]
	int time_second_prov;				//設定時間[秒]
}layer_time_parameter;

typedef struct {						//芯温設定画面で使用するパラメータ	(layer_c_temp_parameter l_c_temp;)
	int c_temp_prov_integer;			//芯温設定温度(整数単位)
	int c_temp_prov_decimal;			//芯温設定温度(小数単位)
}layer_c_temp_parameter;

typedef struct {						//コードリストの画面で使用するパラメータ	(codelist_parameter cl;)
	int page_no;						//コードリストの表示画面番号
	int code_no_select;					//選択したコード番号
	c_mode_select m_select;				//選択中の移行モード
	status m_window;					//モードウィンドウの開閉
}codelist_parameter;

typedef struct {						//菓子コード名称入力画面で使用するパラメータ	(key_parameter k;)
	wchar_t code_name_prov[11];			//入力中の文字列
	time_t flicker_count;				//文字列位置示唆用バーのフリッカ
	status title_bar_sts;				//文字列位置示唆用バーの表示状態
	int title_bar_point;				//入力バーの位置0が標準、増えていくと左にずれる個数を差す
}key_parameter;

typedef struct {
	d_mode_select m_select;				//選択中の移行モード
	int process_no_select;				//選択した工程番号
	status rect_on_color[CODE_LIST_MAX_SIZE_IN_PAGE];	//選択時の色変化
}detail_parameter;

typedef struct {
	int page;				//設定変更中のページ[0,1,2]
	config_status mode;		//設定変更中のパラメータ
	status child;			//設定値入力画面の表示
	int imput_value;		//設定入力値
}config_parameter;

typedef struct {
	int process_no;
	select_manual_or_auto process_change;
	status warmup_buzzer;
	heater_mode uh_mode[PROCESS_MAX_SIZE_ZERO_ON];
	heater_mode lh_mode[PROCESS_MAX_SIZE_ZERO_ON];
	int uh_temp[PROCESS_MAX_SIZE_ZERO_ON];
	int lh_temp[PROCESS_MAX_SIZE_ZERO_ON];
	damper_status damper_sts[PROCESS_MAX_SIZE_ZERO_ON];
	status core_temp_sts[PROCESS_MAX_SIZE_ZERO_OFF];
	int time_minute[PROCESS_MAX_SIZE_ZERO_OFF];
	int time_second[PROCESS_MAX_SIZE_ZERO_OFF];
	int core_temp_integer[PROCESS_MAX_SIZE_ZERO_OFF];
	int core_temp_decimal[PROCESS_MAX_SIZE_ZERO_OFF];
	status steam_sts[PROCESS_MAX_SIZE_ZERO_OFF];
}process_parameter;

GLOBAL ram_manual_parameter m;
GLOBAL ram_auto_parameter a;
GLOBAL ram_other t;
GLOBAL home_parameter h;
GLOBAL layer_temp_parameter l_temp;
GLOBAL layer_time_parameter l_time;
GLOBAL layer_c_temp_parameter l_c_temp;
GLOBAL key_parameter k;
GLOBAL codelist_parameter cl;
GLOBAL detail_parameter d;
GLOBAL config_parameter conf;
GLOBAL process_parameter p;

// 関数宣言

void Initialize_m(void);
void Initialize_a(void);
void Initialize_t(void);
void Initialize_h(void);
void Initialize_l_temp(void);
void Initialize_l_time(void);
void Initialize_l_c_temp(void);
void Initialize_k(void);
void Initialize_cl(void);
void Initialize_d(void);
void Initialize_conf(void);
void Initialize_p(void);
GLOBAL void ProcessInitialize(void);
GLOBAL void ProcessImput(void);
GLOBAL void TextImput(wchar_t *word1,wchar_t *word2,int number);

void wd_flag_set(void);


// 必要に応じて構造体を作成する。

extern struct info_struct info;
extern struct err_struct err;

#endif
