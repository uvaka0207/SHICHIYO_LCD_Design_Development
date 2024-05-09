#define GLOBAL_DEFINE
#include "common.h"
#include "graphics_ctrl.h"
#include "touch_check.h"
#include "debug.h"
#include "rx4803sa.h"
#include "touch_ctrl.h"
#include "font/font.h"

ram_manual_parameter m;
ram_auto_parameter a;
ram_other t;
home_parameter h;
layer_temp_parameter l_temp;
layer_time_parameter l_time;
layer_c_temp_parameter l_c_temp;
key_parameter k;
codelist_parameter cl;
detail_parameter d;
config_parameter conf;
process_parameter p;

void Initialize_m(void){
	m.time_minute_m = 0;
	m.time_second_m = 0;
	m.uh_temp_m = 0;
	m.lh_temp_m = 0;
	m.core_temp_integer_m = 0;
	m.core_temp_decimal_m = 0;
	m.uh_mode_m = HIGH;
	m.lh_mode_m = HIGH;
	m.damper_sts_m = D_CLOSE;
	m.core_temp_sts_m = STS_NONE;
}

void Initialize_a(void){
	for (int i = 0; i < CODE_LIST_MAX_SIZE; i++) {
		wmemset(a.code_name[i], L'\0', CODE_NAME_MAX_SIZE);
		a.process_max[i] = 0;
		a.warmup_buzzer[i] = STS_TRUE;
		a.process_change[i] = S_AUTO;
		for ( int j = 0; j < PROCESS_MAX_SIZE_ZERO_OFF; j++){
			a.time_minute[i][j] = 0;
			a.time_second[i][j] = 0;
			a.core_temp_integer[i][j] = 0;
			a.core_temp_decimal[i][j] = 0;
			a.core_temp_sts[i][j] = STS_NONE;
			a.steam_sts[i][j] = STS_NONE;
		}
		for ( int j = 0; j < PROCESS_MAX_SIZE_ZERO_ON; j++){
			a.uh_temp[i][j] = 0;
			a.lh_temp[i][j] = 0;
			a.uh_mode[i][j] = HIGH;
			a.lh_mode[i][j] = HIGH;
			a.damper_sts[i][j] = D_CLOSE;
		}
	}
}

void Initialize_t(void){
	t.process_sw_timer = 2000UL;
	t.steam_timer = 3000UL;
	t.mns = NS_FIRST;
	t.warmup_temp = 10;
}

void Initialize_h(void){
	h.code_no_now = 1;
	wmemset(h.code_name_now, L'\0', CODE_NAME_MAX_SIZE);
	wmemcpy(h.code_name_now, L"手動運転", wcslen(L"手動運転"));
	h.process_now = 0;
	h.process_max = 0;
	h.time_minute_set = m.time_minute_m;
	h.time_second_set = m.time_second_m;
	h.time_minute_now = 0;
	h.time_second_now = 0;
	h.uh_temp_set = m.uh_temp_m;
	h.lh_temp_set = m.lh_temp_m;
	h.core_temp_set_integer = m.core_temp_integer_m;
	h.core_temp_set_decimal = m.core_temp_decimal_m;
	h.uh_temp_now = 0;
	h.lh_temp_now = 0;
	h.core_temp_now = m.core_temp_sts_m;
	h.select_m_a = S_MANUAL;
	h.uh_mode_now = m.uh_mode_m;
	h.lh_mode_now = m.lh_mode_m;
	h.b_t_sts = BTS_NONE;
	h.start_sts = SS_NONE;
	h.damper_sts_now = m.damper_sts_m;
	h.core_temp_sts_now = STS_NONE;
	h.steam_sts_now = STS_NONE;
	h.lamp_sts = STS_NONE;
	h.clear_sts = STS_NONE;
	h.buzzer_sts = STS_NONE;
	h.recipe_sts = STS_NONE;
	h.eco_sts = STS_NONE;
	h.popup_temp_sts = STS_NONE;
	h.popup_time_sts = STS_NONE;
	h.popup_c_temp_sts = STS_NONE;
	h.dl_sts = DL_OPEN;
	h.auto_count = get_sys_timer();
	h.process_count = get_sys_timer();
	h.steam_count = get_sys_timer();
	h.manual_first_counter = 0;
}

void Initialize_l_temp(void){
	l_temp.uh_temp_prov = 0;
	l_temp.lh_temp_prov = 0;
	l_temp.uh_mode_prov = HIGH;
	l_temp.lh_mode_prov = HIGH;
}

void Initialize_l_time(void){
	l_time.time_minute_prov = 0;
	l_time.time_second_prov = 0;
}

void Initialize_l_c_temp(void){
	l_c_temp.c_temp_prov_integer = 0;
	l_c_temp.c_temp_prov_decimal = 0;
}

void Initialize_k(void){
	wmemset(k.code_name_prov, L'\0', CODE_NAME_MAX_SIZE);
	k.flicker_count = 0;
	k.title_bar_sts = STS_NONE;
	k.title_bar_point = 0;
}

void Initialize_cl(void){
	cl.page_no = 0;
	cl.code_no_select = 0;
	cl.m_select = C_MODE_ENTER;
	cl.m_window = STS_NONE;
}

void Initialize_d(void){
	d.m_select = D_MODE_NONE;
	d.process_no_select = 0;

	for(int i = 0; i < CODE_LIST_MAX_SIZE_IN_PAGE; i++){
		d.rect_on_color[i] = STS_NONE;
	}
}

void Initialize_conf(void){
	conf.page = 0;
	conf.mode = CONF_NONE;
	conf.child = STS_NONE;
	conf.imput_value = 0;
}

void Initialize_p(void){
	p.process_change = S_AUTO;
	p.warmup_buzzer = STS_TRUE;

	for ( int i = 0; i < PROCESS_MAX_SIZE_ZERO_ON; i++){
		p.uh_mode[i] = HIGH;
		p.lh_mode[i] = HIGH;
		p.uh_temp[i] = 0;
		p.lh_temp[i] = 0;
		p.damper_sts[i] = D_CLOSE;
	}

	for ( int i = 0; i < PROCESS_MAX_SIZE_ZERO_OFF; i++){
		p.core_temp_sts[i] = STS_NONE;
		p.time_minute[i] = 0;
		p.time_second[i] = 0;
		p.core_temp_integer[i] = 0;
		p.core_temp_decimal[i] = 0;
		p.steam_sts[i] = STS_NONE;
	}
}

void TextImput(wchar_t *word1, wchar_t *word2, int number) {

	// "word1"に"word2"を追加する
	// "number"の数によって、"word2"の入力箇所が変化する
	//10文字以上の入力にはならないようにする

	wchar_t code_name_prov_f[CODE_NAME_MAX_SIZE];	//文字列間に文字を打つ際の仮保管(前)
	wchar_t code_name_prov_r[CODE_NAME_MAX_SIZE];	//文字列間に文字を打つ際の仮保管(後)
	wmemset(code_name_prov_f, L'\0', CODE_NAME_MAX_SIZE);
	wmemset(code_name_prov_r, L'\0', CODE_NAME_MAX_SIZE);

	if (wcslen(word1) + wcslen(word2) >= CODE_NAME_MAX_SIZE) {	//文字列を足した結果バッファサイズより大きくなる場合は足さない
	}
	else {
		if (number > wcslen(word1)) {
			number = wcslen(word1);
		}
		wcsncpy(code_name_prov_f, word1, wcslen(word1) - number);			// 保管(前)にnumberの前のデータをコピー(コピー先はNULL文字で埋まっているため終端文字を気にしない)
		wcsncpy(code_name_prov_r, &word1[wcslen(word1) - number], number);	// 保管(後)にnumberの後のデータをコピー(コピー先はNULL文字で埋まっているため終端文字を気にしない)
		wmemset(word1, L'\0', CODE_NAME_MAX_SIZE);	// word1を一旦初期化
		wcscat(word1, code_name_prov_f);			// 3つの文字列を連結する。
		wcscat(word1, word2);
		wcscat(word1, code_name_prov_r);
	}
}

void ProcessInitialize(void){
	p.process_no = 0;
	p.process_change = a.process_change[cl.code_no_select - 2];
	p.warmup_buzzer = a.warmup_buzzer[cl.code_no_select - 2];

	for ( int i = 0; i < PROCESS_MAX_SIZE_ZERO_ON; i++){
		p.uh_mode[i] = a.uh_mode[cl.code_no_select - 2][i];
		p.lh_mode[i] = a.lh_mode[cl.code_no_select - 2][i];
		p.uh_temp[i] = a.uh_temp[cl.code_no_select - 2][i];
		p.lh_temp[i] = a.lh_temp[cl.code_no_select - 2][i];
		p.damper_sts[i] = a.damper_sts[cl.code_no_select - 2][i];
	}

	for ( int i = 0; i < PROCESS_MAX_SIZE_ZERO_OFF; i++){
		p.core_temp_sts[i] = a.core_temp_sts[cl.code_no_select - 2][i];
		p.time_minute[i] = a.time_minute[cl.code_no_select - 2][i];
		p.time_second[i] = a.time_second[cl.code_no_select - 2][i];
		p.core_temp_integer[i] = a.core_temp_integer[cl.code_no_select - 2][i];
		p.core_temp_decimal[i] = a.core_temp_decimal[cl.code_no_select - 2][i];
		p.steam_sts[i] = a.steam_sts[cl.code_no_select - 2][i];
	}
}

void ProcessImput(void){
	p.process_no = 0;
	a.process_change[cl.code_no_select - 2] = p.process_change;
	a.warmup_buzzer[cl.code_no_select - 2] = p.warmup_buzzer;
	a.process_max[cl.code_no_select - 2] = 0;

	for ( int i = 0; i < PROCESS_MAX_SIZE_ZERO_OFF; i++){
		if(((p.core_temp_sts[i] == STS_NONE) &&
				((p.time_minute[i] == 0) &&
						(p.time_second[i] == 0))) ||
				((p.core_temp_sts[i] == STS_TRUE) &&
						((p.core_temp_integer[i] == 0) &&
								(p.core_temp_decimal[i] == 0)))){
			break;
		}
		else{
			a.core_temp_sts[cl.code_no_select - 2][i] = p.core_temp_sts[i];
			a.time_minute[cl.code_no_select - 2][i] = p.time_minute[i];
			a.time_second[cl.code_no_select - 2][i] = p.time_second[i];
			a.core_temp_integer[cl.code_no_select - 2][i] = p.core_temp_integer[i];
			a.core_temp_decimal[cl.code_no_select - 2][i] = p.core_temp_decimal[i];
			a.steam_sts[cl.code_no_select - 2][i] = p.steam_sts[i];
			a.process_max[cl.code_no_select - 2] = i + 1;
		}
	}

	for ( int i = 0; i <= a.process_max[cl.code_no_select - 2]; i++){
		a.uh_mode[cl.code_no_select - 2][i] = p.uh_mode[i];
		a.lh_mode[cl.code_no_select - 2][i] = p.lh_mode[i];
		a.uh_temp[cl.code_no_select - 2][i] = p.uh_temp[i];
		a.lh_temp[cl.code_no_select - 2][i] = p.lh_temp[i];
	}

	A_DataSave();
	change_mode(MODE_DETAIL);
}

struct info_struct info;
struct err_struct err;

void clock_ctrl(void)
{
	static time_t timer;
	if(wait_timeout(1000UL , timer)){
		timer = get_sys_timer();
		int week = 0;
		RTC_get_date_long(&info.year , &info.month , &info.day , &week , &info.hour , &info.minute , &info.second);
		info.clock_sec = time_to_sec(info.year ,info.month ,info.day ,info.hour ,info.minute ,info.second);
		info.week = get_week(info.year,info.month,info.day);

	}

}

int Main_Task(void)
{
	int x;
	int y;
	time_t timer;
	SetPriority(5);

	// チェック端子確認
//	timer = get_sys_timer();
//	while(I_CH()){
//		if(wait_timeout(200UL,timer)){
//			diag_ctrl();										//
//		}
//	}
	Sleep(1000);

	if(RTC_init()== 1)
	{
		RTC_set_date_long(2023,1,1,0,0,0,0);
	}
	RTC_get_date_long(&info.year , &info.month , &info.day , &info.week , &info.hour , &info.minute , &info.second);
	SettingDataLoad();			// 設定データのロード
	Initialize_h();
	Initialize_l_temp();
	Initialize_l_temp();
	Initialize_l_c_temp();
	Initialize_k();
	Initialize_cl();
	Initialize_d();
	Initialize_conf();
	Initialize_p();
	change_mode(MODE_HOME);
	touch_enable();


	while(1){


		// メイン処理
		touch_check_obj();					// タッチの動作

		mode_ctrl();
		obj_redraw();						// 画面更新処理
		quick_redraw_run();					// 画面更新処理
		SettingDataSaveCtrl();				// データ保存処理
		clock_ctrl();						// 時計取得処理
		FontSerchDataCtrl();				// フォントの検索データの整理

		wd_flag_set();						// ループチェック
		Interval(10);
	}
}


