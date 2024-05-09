#ifndef	_SETTING_H
#define	_SETTING_H
#include "br24lxx.h"


// 設定データやパラメータのEEPROMの先頭アドレス

#define		SAVE_M_DATA_BLOCK_ID1			0
#define		SAVE_M_DATA_BLOCK_ID2			1
#define		SAVE_A_DATA_BLOCK_ID1			2
#define		SAVE_A_DATA_BLOCK_ID2			3
#define		SAVE_T_DATA_BLOCK_ID1			4
#define		SAVE_T_DATA_BLOCK_ID2			5

extern void M_DataSave(void);
extern void A_DataSave(void);
extern void T_DataSave(void);

extern void SettingDataSaveCtrl(void);
extern void SettingDataLoad(void);

#endif
