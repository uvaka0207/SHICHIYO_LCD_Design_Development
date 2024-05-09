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
* @file          utf8.h
* $Rev: 236 $
* $Date:: 2014-03-19 21:35:37 +0900#$
* @brief         UTF-8 character encoding conversions
******************************************************************************/

#ifndef UTF8_H
#define UTF8_H

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
Typedef definitions
******************************************************************************/

/******************************************************************************
Macro definitions
******************************************************************************/

/******************************************************************************
Variable Externs
******************************************************************************/

/******************************************************************************
Functions Prototypes
******************************************************************************/
extern int32_t ucs2le_to_utf8(const wchar_t *pwchar, int32_t count, char_t *pmbchar);
extern int32_t ucs2be_to_utf8(const wchar_t *pwchar, int32_t count, char_t *pmbchar);
extern int32_t ucs2le_to_utf8_l(const wchar_t *pwchar, int32_t count, char_t *pmbchar, int32_t size);
extern int32_t check_buffer_size_ucs2le_to_utf8(const wchar_t * const pwchar, int32_t const count);
extern int32_t ucs2be_to_utf8_l(const wchar_t *pwchar, int32_t count, char_t *pmbchar, int32_t size);
extern int32_t check_buffer_size_ucs2be_to_utf8(const wchar_t * const pwchar, int32_t const count);
extern int32_t check_utf8_byte_number(const char_t * const pmbchar);
extern int32_t utf8_to_ucs4(const char_t *pmbchar, wchar_t *pwchar, int32_t count);
extern int32_t utf8_to_ucs4le(const char_t *pmbchar, wchar_t *pwchar, int32_t count);
extern int32_t utf8_to_ucs4be(const char_t *pmbchar, wchar_t *pwchar, int32_t count);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* UTF8_H */

