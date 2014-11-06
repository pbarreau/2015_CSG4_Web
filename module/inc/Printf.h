/****************************************************************************
 *
 * MODULE:             Printf Header
 *
 * COMPONENT:          $RCSfile: Printf.h,v $
 *
 * VERSION:            $Name:  $
 *
 * REVISION:           $Revision: 1.2 $
 *
 * DATED:              $Date: 2006/08/31 11:49:17 $
 *
 * STATUS:             $State: Exp $
 *
 * AUTHOR:             LJM
 *
 * DESCRIPTION:
 * Printf header file
 *
 * CHANGE HISTORY:
 *
 * $Log: Printf.h,v $
 * Revision 1.2  2006/08/31 11:49:17  lmitch
 * Modified title block
 *
 * Revision 1.1  2006/08/25 14:22:11  lmitch
 * Added to this project to create self contained build
 *
 * Revision 1.1  2006/01/13 09:54:48  lmitch
 * Initial revision
 *
 *
 *
 *
 * LAST MODIFIED BY:   $Author: lmitch $
 *                     $Modtime: $
 *
 ****************************************************************************
 *
 * This software is owned by Jennic and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on Jennic products. You, and any third parties must reproduce
 * the copyright and warranty notice and any other legend of ownership on
 * each copy or partial copy of the software.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS". JENNIC MAKES NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
 * ACCURACY OR LACK OF NEGLIGENCE. JENNIC SHALL NOT, IN ANY CIRCUMSTANCES,
 * BE LIABLE FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO, SPECIAL,
 * INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER.
 *
 * Copyright Jennic Ltd 2005, 2006. All rights reserved
 *
 ***************************************************************************/

#ifndef PRINTF_H_INCLUDED
#define PRINTF_H_INCLUDED

#if defined __cplusplus
extern "C" {
#endif

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void vInitPrintf(void (*fp)(char c));
PUBLIC void vPrintf(const char *fmt, ...);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

#if defined __cplusplus
}
#endif

#endif /* PRINTF_H_INCLUDED */

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
