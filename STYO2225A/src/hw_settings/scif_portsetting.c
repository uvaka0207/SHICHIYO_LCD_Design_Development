/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
* Copyright (C) 2016-2017 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*******************************************************************************
* File Name   : scif_cfg.c
* $Rev: 30 $
* $Date:: 2016-12-21 12:02:44 +0900#$
* Description : SCIF driver userown functions
******************************************************************************/

/*******************************************************************************
Includes <System Includes>, "Project Includes"
*******************************************************************************/
#include "iodefine.h"
#include "hw_setting.h"
#include "stdinx.h"
#include "io.h"

/*******************************************************************************
Macro definitions
*******************************************************************************/



/******************************************************************************
* Function Name: SCIF_PortSetting
* @brief         Set the GPIO to be used by the SCIF.
*
*                Description:<br>
*                
* @param[in]     ch           :channel number.
* @retval        none
******************************************************************************/
void SCIF_PortSetting(const uint32_t ch)
{


    switch (ch)
    {
    case SCIF_CH_NUM_0:
    	CPG.STBCR4 &= ~(OSPL_CPG_STBCR_MSTP7); /* enable  */
        // P4_9=TxD0(Alternative Mode 7,Output:PFCAE1,PFCE1,PFC0)
        GPIO.PIBC4  &=~(uint32_t)GPIO_BIT_N9;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N9;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM4    |= (uint32_t)GPIO_BIT_N9;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC4   &=~(uint32_t)GPIO_BIT_N9;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC4  &=~(uint32_t)GPIO_BIT_N9;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N9;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE4 |= (uint32_t)GPIO_BIT_N9;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE4  |= (uint32_t)GPIO_BIT_N9;				// ポート機能制御拡張レジスタ
        GPIO.PFC4   &=~(uint32_t)GPIO_BIT_N9;				// ポート機能制御レジスタ

        GPIO.PIPC4  |= (uint32_t)GPIO_BIT_N9;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC4   |= (uint32_t)GPIO_BIT_N9;				// ポートモードレジスタ 0:ポートモード 1:兼用モード

        // P4_10=RxD0(Alternative Mode 7,Input:PFCAE1,PFCE1,PFC0)
        GPIO.PIBC4  &=~(uint32_t)GPIO_BIT_N10;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N10;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM4    |= (uint32_t)GPIO_BIT_N10;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC4   &=~(uint32_t)GPIO_BIT_N10;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC4  &=~(uint32_t)GPIO_BIT_N10;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N10;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE4 |= (uint32_t)GPIO_BIT_N10;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE4  |= (uint32_t)GPIO_BIT_N10;				// ポート機能制御拡張レジスタ
        GPIO.PFC4   &=~(uint32_t)GPIO_BIT_N10;				// ポート機能制御レジスタ

        GPIO.PIPC4  |= (uint32_t)GPIO_BIT_N10;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC4   |= (uint32_t)GPIO_BIT_N10;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        break;
    case SCIF_CH_NUM_1:
    	CPG.STBCR4 &= ~(OSPL_CPG_STBCR_MSTP6); /* enable  */
        // P4_12=TxD1(Alternative Mode 7,Output:PFCAE1,PFCE1,PFC0)
    	GPIO.PIBC4  &=~(uint32_t)GPIO_BIT_N12;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N12;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM4    |= (uint32_t)GPIO_BIT_N12;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC4   &=~(uint32_t)GPIO_BIT_N12;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC4  &=~(uint32_t)GPIO_BIT_N12;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N12;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE4 |= (uint32_t)GPIO_BIT_N12;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE4  |= (uint32_t)GPIO_BIT_N12;				// ポート機能制御拡張レジスタ
        GPIO.PFC4   &=~(uint32_t)GPIO_BIT_N12;				// ポート機能制御レジスタ

        GPIO.PIPC4  |= (uint32_t)GPIO_BIT_N12;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC4   |= (uint32_t)GPIO_BIT_N12;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        /* P4_13=RxD1(Alternative Mode 7,Input:PFCAE1,PFCE1,PFC0) */
    	GPIO.PIBC4  &=~(uint32_t)GPIO_BIT_N13;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N13;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM4    |= (uint32_t)GPIO_BIT_N13;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC4   &=~(uint32_t)GPIO_BIT_N13;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC4  &=~(uint32_t)GPIO_BIT_N13;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N13;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE4 |= (uint32_t)GPIO_BIT_N13;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE4  |= (uint32_t)GPIO_BIT_N13;				// ポート機能制御拡張レジスタ
        GPIO.PFC4   &=~(uint32_t)GPIO_BIT_N13;				// ポート機能制御レジスタ

        GPIO.PIPC4  |= (uint32_t)GPIO_BIT_N13;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC4   |= (uint32_t)GPIO_BIT_N13;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        break;
    case SCIF_CH_NUM_2:
    	CPG.STBCR4 &= ~(OSPL_CPG_STBCR_MSTP5); /* enable  */
        // P4_14=TxD2(Alternative Mode 7,Output:PFCAE1,PFCE1,PFC0)

    	GPIO.PIBC4  &=~(uint32_t)GPIO_BIT_N14;
        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N14;
        GPIO.PM4    |= (uint32_t)GPIO_BIT_N14;
        GPIO.PMC4   &=~(uint32_t)GPIO_BIT_N14;
        GPIO.PIPC4  &=~(uint32_t)GPIO_BIT_N14;

        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N14;
        GPIO.PFCAE4 |= (uint32_t)GPIO_BIT_N14;
        GPIO.PFCE4  |= (uint32_t)GPIO_BIT_N14;
        GPIO.PFC4   &=~(uint32_t)GPIO_BIT_N14;

        GPIO.PIPC4  |= (uint32_t)GPIO_BIT_N14;
        GPIO.PMC4   |= (uint32_t)GPIO_BIT_N14;

        /* P4_15=RxD2(Alternative Mode 7,Input:PFCAE1,PFCE1,PFC0) */
        GPIO.PIBC4  &=~(uint32_t)GPIO_BIT_N15;
        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N15;
        GPIO.PM4    |= (uint32_t)GPIO_BIT_N15;
        GPIO.PMC4   &=~(uint32_t)GPIO_BIT_N15;
        GPIO.PIPC4  &=~(uint32_t)GPIO_BIT_N15;

        GPIO.PBDC4  &=~(uint32_t)GPIO_BIT_N15;
        GPIO.PFCAE4 |= (uint32_t)GPIO_BIT_N15;
        GPIO.PFCE4  |= (uint32_t)GPIO_BIT_N15;
        GPIO.PFC4   &=~(uint32_t)GPIO_BIT_N15;

        GPIO.PIPC4  |= (uint32_t)GPIO_BIT_N15;
        GPIO.PMC4   |= (uint32_t)GPIO_BIT_N15;
        break;
    case SCIF_CH_NUM_3:
    	CPG.STBCR4 &= ~(OSPL_CPG_STBCR_MSTP4); /* enable  */
    	// IOT通信初期化
        // P3_5=TxD3(Alternative Mode 7,Output:PFCAE1,PFCE1,PFC0)
        GPIO.PIBC3  &=~(uint32_t)GPIO_BIT_N5;
        GPIO.PBDC3  &=~(uint32_t)GPIO_BIT_N5;
        GPIO.PM3    |= (uint32_t)GPIO_BIT_N5;
        GPIO.PMC3   &=~(uint32_t)GPIO_BIT_N5;
        GPIO.PIPC3  &=~(uint32_t)GPIO_BIT_N5;

        GPIO.PBDC3  &=~(uint32_t)GPIO_BIT_N5;
        GPIO.PFCAE3 |= (uint32_t)GPIO_BIT_N5;
        GPIO.PFCE3  |= (uint32_t)GPIO_BIT_N5;
        GPIO.PFC3   &=~(uint32_t)GPIO_BIT_N5;

        GPIO.PIPC3  |= (uint32_t)GPIO_BIT_N5;
        GPIO.PMC3   |= (uint32_t)GPIO_BIT_N5;

        /* P3_6=RxD3(Alternative Mode 7,Input:PFCAE1,PFCE1,PFC0) */
        GPIO.PIBC3  &=~(uint32_t)GPIO_BIT_N6;
        GPIO.PBDC3  &=~(uint32_t)GPIO_BIT_N6;
        GPIO.PM3    |= (uint32_t)GPIO_BIT_N6;
        GPIO.PMC3   &=~(uint32_t)GPIO_BIT_N6;
        GPIO.PIPC3  &=~(uint32_t)GPIO_BIT_N6;

        GPIO.PBDC3  &=~(uint32_t)GPIO_BIT_N6;
        GPIO.PFCAE3 |= (uint32_t)GPIO_BIT_N6;
        GPIO.PFCE3  |= (uint32_t)GPIO_BIT_N6;
        GPIO.PFC3   &=~(uint32_t)GPIO_BIT_N6;

        GPIO.PIPC3  |= (uint32_t)GPIO_BIT_N6;
        GPIO.PMC3   |= (uint32_t)GPIO_BIT_N6;
        break;
    case SCIF_CH_NUM_4:
    	CPG.STBCR4 &= ~(OSPL_CPG_STBCR_MSTP3); /* enable  */
		// デバッグポート
        // P8_14=TxD0(Alternative Mode 7,Output:PFCAE1,PFCE1,PFC0)
        GPIO.PIBC8  &=~(uint32_t)GPIO_BIT_N14;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N14;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM8    |= (uint32_t)GPIO_BIT_N14;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC8   &=~(uint32_t)GPIO_BIT_N14;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC8  &=~(uint32_t)GPIO_BIT_N14;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N14;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE8 |= (uint32_t)GPIO_BIT_N14;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE8  |= (uint32_t)GPIO_BIT_N14;				// ポート機能制御拡張レジスタ
        GPIO.PFC8   &=~(uint32_t)GPIO_BIT_N14;				// ポート機能制御レジスタ

        GPIO.PIPC8  |= (uint32_t)GPIO_BIT_N14;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC8   |= (uint32_t)GPIO_BIT_N14;				// ポートモードレジスタ 0:ポートモード 1:兼用モード

        /* P8_15=RxD0(Alternative Mode 7,Input:PFCAE1,PFCE1,PFC0) */
        GPIO.PIBC8  &=~(uint32_t)GPIO_BIT_N15;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N15;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM8    |= (uint32_t)GPIO_BIT_N15;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC8   &=~(uint32_t)GPIO_BIT_N15;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC8  &=~(uint32_t)GPIO_BIT_N15;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N15;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE8 |= (uint32_t)GPIO_BIT_N15;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE8  |= (uint32_t)GPIO_BIT_N15;				// ポート機能制御拡張レジスタ
        GPIO.PFC8   &=~(uint32_t)GPIO_BIT_N15;				// ポート機能制御レジスタ

        GPIO.PIPC8  |= (uint32_t)GPIO_BIT_N15;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC8   |= (uint32_t)GPIO_BIT_N15;				// ポートモードレジスタ 0:ポートモード 1:兼用モード

        break;
    case SCIF_CH_NUM_5:
    	CPG.STBCR4 &= ~(OSPL_CPG_STBCR_MSTP2); /* enable  */
		// デバッグポート
        // P8_13=TxD0(Alternative Mode 5,Output:PFCAE1,PFCE0,PFC0)
        GPIO.PIBC8  &=~(uint32_t)GPIO_BIT_N13;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N13;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM8    |= (uint32_t)GPIO_BIT_N13;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC8   &=~(uint32_t)GPIO_BIT_N13;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC8  &=~(uint32_t)GPIO_BIT_N13;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N13;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE8 |= (uint32_t)GPIO_BIT_N13;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE8  &=~(uint32_t)GPIO_BIT_N13;				// ポート機能制御拡張レジスタ
        GPIO.PFC8   &=~(uint32_t)GPIO_BIT_N13;				// ポート機能制御レジスタ

        GPIO.PIPC8  |= (uint32_t)GPIO_BIT_N13;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC8   |= (uint32_t)GPIO_BIT_N13;				// ポートモードレジスタ 0:ポートモード 1:兼用モード

        /* P8_11=RxD0(Alternative Mode 7,Input:PFCAE1,PFCE0,PFC0) */
        GPIO.PIBC8  &=~(uint32_t)GPIO_BIT_N11;				// ポート入力バッファ制御レジスタ 0：禁止 1:許可
        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N11;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PM8    |= (uint32_t)GPIO_BIT_N11;				// ポート方向レジスタ 0：出力モード 1:入力モード
        GPIO.PMC8   &=~(uint32_t)GPIO_BIT_N11;				// ポートモードレジスタ 0:ポートモード 1:兼用モード
        GPIO.PIPC8  &=~(uint32_t)GPIO_BIT_N11;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御

        GPIO.PBDC8  &=~(uint32_t)GPIO_BIT_N11;				// ポート双方向モード 0：禁止 1:許可
        GPIO.PFCAE8 |= (uint32_t)GPIO_BIT_N11;				// ポート機能制御追加拡張レジスタ
        GPIO.PFCE8  &=~(uint32_t)GPIO_BIT_N11;				// ポート機能制御拡張レジスタ
        GPIO.PFC8   &=~(uint32_t)GPIO_BIT_N11;				// ポート機能制御レジスタ

        GPIO.PIPC8  |= (uint32_t)GPIO_BIT_N11;				// ポートIP制御レジスタ 0：入出力はPMによって制御 1:入出力は兼用機能によって制御
        GPIO.PMC8   |= (uint32_t)GPIO_BIT_N11;				// ポートモードレジスタ 0:ポートモード 1:兼用モード

        break;
    }
}
