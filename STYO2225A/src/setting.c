/*
 *  Copyright (C) 2003-04 INX Corporation. All rights reserved.
 *  @(#) $Id: setting.c,v 1.1 2019/09/02 12:38:26 satou Exp $
 */
#include "common.h"
#include "setting.h"
#include "eep_rw.h"
#include <string.h>
#include "serial_flash.h"
#include "sf_system.h"
#include "touch_ctrl.h"


struct
{
	int M_data_save;
	int A_data_save;
	int T_data_save;
	time_t timer;

}setting_info;

void M_DataSave(void)
{
	setting_info.M_data_save = 1;
}

void A_DataSave(void)
{
	setting_info.A_data_save = 1;
}

void T_DataSave(void)
{
	setting_info.T_data_save = 1;
}

/*
 *		データを保存する処理
 */
void SettingDataSaveCtrl(void)
{
	if(setting_info.M_data_save == 1){
		sfsys_flash_block_erase(SAVE_M_DATA_BLOCK_ID1);
		sfsys_flash_block_write(SAVE_M_DATA_BLOCK_ID1 , (uint8_t *)&m , sizeof(m));
		sfsys_flash_block_erase(SAVE_M_DATA_BLOCK_ID2);
		sfsys_flash_block_write(SAVE_M_DATA_BLOCK_ID2 , (uint8_t *)&m , sizeof(m));
		setting_info.M_data_save = 0;
	}

	if(setting_info.A_data_save == 1){
		sfsys_flash_block_erase(SAVE_A_DATA_BLOCK_ID1);
		sfsys_flash_block_write(SAVE_A_DATA_BLOCK_ID1 , (uint8_t *)&a , sizeof(a));
		sfsys_flash_block_erase(SAVE_A_DATA_BLOCK_ID2);
		sfsys_flash_block_write(SAVE_A_DATA_BLOCK_ID2 , (uint8_t *)&a , sizeof(a));
		setting_info.A_data_save = 0;
	}

	if(setting_info.T_data_save == 1){
		sfsys_flash_block_erase(SAVE_T_DATA_BLOCK_ID1);
		sfsys_flash_block_write(SAVE_T_DATA_BLOCK_ID1 , (uint8_t *)&t , sizeof(t));
		sfsys_flash_block_erase(SAVE_T_DATA_BLOCK_ID2);
		sfsys_flash_block_write(SAVE_T_DATA_BLOCK_ID2 , (uint8_t *)&t , sizeof(t));
		setting_info.T_data_save = 0;
	}
	eep_handle();
}

/*
 *		基板起動時にデータを読み込みする処理
 */
void SettingDataLoad(void)
{
	int init_m = 0;
	int init_a = 0;
	int init_t = 0;
	sfsys_init();						// フラッシュメモリの初期化

	if(sfsys_flash_block_read(SAVE_M_DATA_BLOCK_ID1 , (uint8_t *)&m , sizeof(m)) == 0){
		if(sfsys_flash_block_read(SAVE_M_DATA_BLOCK_ID2 , (uint8_t *)&m , sizeof(m)) == 0){
			init_m = 1;
		}
	}

	if(sfsys_flash_block_read(SAVE_A_DATA_BLOCK_ID1 , (uint8_t *)&a , sizeof(a)) == 0){
		if(sfsys_flash_block_read(SAVE_A_DATA_BLOCK_ID2 , (uint8_t *)&a , sizeof(a)) == 0){
			init_a = 1;
		}
	}

	if(sfsys_flash_block_read(SAVE_T_DATA_BLOCK_ID1 , (uint8_t *)&t , sizeof(t)) == 0){
		if(sfsys_flash_block_read(SAVE_T_DATA_BLOCK_ID2 , (uint8_t *)&t , sizeof(t)) == 0){
			init_t = 1;
		}
	}

	if(init_m == 1){
		Initialize_m();
	}

	if(init_a == 1){
		Initialize_a();
	}

	if(init_t == 1){
		Initialize_t();
	}
}




















