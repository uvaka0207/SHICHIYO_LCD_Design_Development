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
 * Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
 *******************************************************************************/
/**************************************************************************//**
 * File Name :    vdc5_portsetting.c
 * @file          vdc5_portsetting.c
 * $Rev:  $
 * $Date::  #$
 * @brief        VDC5 port setting functions
 ******************************************************************************/

/*******************************************************************************
 Includes <System Includes>, "Project Includes"
 *******************************************************************************/
#include     "iodefine.h"
#include "hw_setting.h"





/**************************************************************************//**
 * Function Name : VDC5_LcdPortSetting
 * @brief       LCD panel I/O port setup (VDC5 channel 0)
 * @param[in]   param     :
 * @retval      None
 ******************************************************************************/
void VDC5_LcdPortSetting(void)
{
    volatile uint32_t dummy_read;
    uint32_t reg_data;

    /* RSK TFT (RGB888)
     LVDS CLK							 ...P5_0 P5_1
     LVDS RIN0							 ...P5_6 P5_6
     LVDS RIN1							 ...P5_4 P5_5
     LVDS RIN2							 ...P5_2 P5_3
     */

    GPIO.PFCAE5 &= (uint16_t) 0xFF00;
    GPIO.PFCE5 &= (uint16_t) 0xFF00;
    GPIO.PFC5 &= (uint16_t) 0xFF00;				// 機能1を選択
	
    GPIO.PIPC5 &= (uint16_t) 0xFF00;	
	GPIO.PM5 |= 0x00FF;
    GPIO.PMC5 |= (uint16_t) 0x00FF;				// 兼用機能を選択


} /* End of function VDC5_LcdPortSetting() */

