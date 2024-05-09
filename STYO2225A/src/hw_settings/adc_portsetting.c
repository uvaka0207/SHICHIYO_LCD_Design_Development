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

/**************************************************************************//**
* @file         adc_portsetting.c
* $Rev: 31 $
* $Date:: 2016-12-22 11:24:10 +0900#$
* @brief        ADC Driver port setting functions
******************************************************************************/

/*******************************************************************************
Includes <System Includes>, "Project Includes"
*******************************************************************************/
#include "iodefine.h"
#include "hw_setting.h"
#include "stdinx.h"
#include "io.h"

/**************************************************************************//**
* Function Name: ADC_PortSetting
* @brief         Set the GPIO to be used by the ADC.
*
*                Description:<br>
*                
* @param[in]     Void
* @retval        None.
******************************************************************************/
void ADC_PortSetting(void)
{
        /* ->IPA R2.4.2 : This is implicit type conversion that doesn't have bad effect on writing to 16bit register. */
	uint32_t gpio_an_value = GPIO_BIT_N8
                  | GPIO_BIT_N9
                  | GPIO_BIT_N10
                  | GPIO_BIT_N11
                  | GPIO_BIT_N12
                  | GPIO_BIT_N13
                  | GPIO_BIT_N14
                  | GPIO_BIT_N15;


		/* GPIO SET */
        GPIOPIBC1  &= (uint16_t)~gpio_an_value;
        GPIOPBDC1  &= (uint16_t)~gpio_an_value;
        GPIOPM1    |= (uint16_t)gpio_an_value;
        GPIOPMC1   &= (uint16_t)~gpio_an_value;
        GPIOPIPC1  &= (uint16_t)~gpio_an_value;
        GPIOPBDC1  &= (uint16_t)~gpio_an_value;
        
        GPIOPFC1   &= (uint16_t)~gpio_an_value;
        GPIOPFCE1  &= (uint16_t)~gpio_an_value;
        GPIOPFCAE1 &= (uint16_t)~gpio_an_value;

        GPIOPIPC1  |= (uint16_t)gpio_an_value;
        GPIOPMC1   |= (uint16_t)gpio_an_value;

}
/* End of File */
