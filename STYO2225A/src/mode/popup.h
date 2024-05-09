
#ifndef  POPUP_H
#define  POPUP_H

enum POPUP_RET_ENUM{

	POPUP_RET_MES_NONE,
	POPUP_RET_MES_OK,
	POPUP_RET_MES_CANCEL,
	POPUP_RET_MES_NG,
	POPUP_RET_MES_CLOSE,

};




typedef void * (* POP_CLOSE_CALLBACK)(int layer_id , int ret_mes , int value);










void popup(int layer_id , POP_CLOSE_CALLBACK pop_close_call_back);						// POPUPを表示する
void popup_close(int ret_mes , int value);		// ポップアップメッセージを閉じる
int get_pop(int layer_id);						// ポップアップが開いているか調べる
int get_upper_pop_up(void);						// 最上位に開いているポップアップを調べる


#endif
