/****************************************************************************
 *
 * MODULE:             Printf Function
 *
 * COMPONENT:          $RCSfile: Printf.c,v $
 *
 * VERSION:            $Name: RD_RELEASE_6thMay09 $
 *
 * REVISION:           $Revision: 1.3 $
 *
 * DATED:              $Date: 2008/10/22 10:27:00 $
 *
 * STATUS:             $State: Exp $
 *
 * AUTHOR:             LJM
 *
 * DESCRIPTION:
 * Code to provide a simple printf function
 *
 * LAST MODIFIED BY:   $Author: pjtw $
 *                     $Modtime: $
 *
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

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <stdarg.h>
#include <ctype.h>
#include <Printf.h>

#include <AppHardwareApi.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/


/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PRIVATE void vNum2String(uint32 u32Number, uint8 u8Base);

/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/* pointer to whatever putchar function the user gives us */
PRIVATE void (*vPutChar) (char c) = NULL;

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/*
* Before using these functions, you must call vInitPrintf
* and give it a pointer to a function that will write the individual
* characters to whatever device you decide to use for displaying output.
*
* example below :-
*
*   #include "Printf.h"
*
*   void main(void)
*   {
*
*       vInitPrintf((void*)vPutC);  // pass the pointer to the putc function
*
*       vPrintf("\nHello World!");  // show some text !
*       while(1);
*   }
*
*   void vPutC(char c)
*   {
*       do something with c here, maybe write it to a uart
*   }
*
*/
PUBLIC void vInitPrintf(void (*fp)(char c))
{
    vPutChar = fp;
}


/*
 * printf()
 *  Print to display - really trivial impelementation!
 */
PUBLIC void vPrintf(const char *fmt, ...)
{
    char *bp = (char *)fmt;
    va_list ap;
    char c;
    char *p;
    int32 i;

    va_start(ap, fmt);

    while ((c = *bp++)) {
        if (c != '%') {
            if (c == '\n'){
                vPutChar('\n');
                vPutChar('\r');
            } else {
                vPutChar(c);
            }
            continue;
        }

        switch ((c = *bp++)) {

        /* %d - show a decimal value */
        case 'd':
            vNum2String(va_arg(ap, uint32), 10);
            break;

        /* %x - show a value in hex */
        case 'x':
            vPutChar('0');
            vPutChar('x');
            vNum2String(va_arg(ap, uint32), 16);
            break;

        /* %b - show a value in binary */
        case 'b':
            vPutChar('0');
            vPutChar('b');
            vNum2String(va_arg(ap, uint32), 2);
            break;

        /* %c - show a character */
        case 'c':
            vPutChar(va_arg(ap, int));
            break;

        case 'i':
            i = va_arg(ap, int32);
            if(i < 0){
                vPutChar('-');
                vNum2String((~i)+1, 10);
            } else {
                vNum2String(i, 10);
            }
            break;

        /* %s - show a string */
        case 's':
            p = va_arg(ap, char *);
            do {
                vPutChar(*p++);
            } while (*p);
            break;

        /* %% - show a % character */
        case '%':
            vPutChar('%');
            break;

        /* %something else not handled ! */
        default:
            vPutChar('?');
            break;

        }
    }

    return;
}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/*
 * vNum2String()
 *  Convert a number to a string
 */
PRIVATE void vNum2String(uint32 u32Number, uint8 u8Base)
{
    char buf[33];
    char *p = buf + 33;
    uint32 c, n;

    *--p = '\0';
    do {
        n = u32Number / u8Base;
        c = u32Number - (n * u8Base);
        if (c < 10) {
            *--p = '0' + c;
        } else {
            *--p = 'a' + (c - 10);
        }
        u32Number /= u8Base;
    } while (u32Number != 0);

    while (*p){
        vPutChar(*p);
        p++;
    }

    return;
}

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/


