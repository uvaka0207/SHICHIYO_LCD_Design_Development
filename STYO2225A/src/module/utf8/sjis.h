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
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/
/**************************************************************************//**
* @file          sjis.h
* $Rev: 506 $
* $Date:: 2014-08-05 17:29:42 +0900#$
* @brief         SJIS character encoding conversions
******************************************************************************/

#ifndef SJIS_H
#define SJIS_H

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "stdinx.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/* Gather following contents by the component unit of the object. */


/******************************************************************************
Macro definitions
******************************************************************************/

/******************************************************************************
Variable Externs
******************************************************************************/

/******************************************************************************
Functions Prototypes
******************************************************************************/
extern int32_t ucs2le_to_sjis(uint8_t * const sjis, wchar_t * const unicode, int32_t const num, int32_t * const def_flag);
extern int32_t sjis_to_ucs2le(wchar_t * const unicode, uint8_t * const sjis, int32_t const num);
extern int32_t sjis_to_ucs2le_isleadbyte(uint16_t ch);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SJIS_H */

