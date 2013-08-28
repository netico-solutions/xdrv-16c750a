/*
 * This file is part of x-16c750
 *
 * Copyright (C) 2011, 2012 - Nenad Radulovic
 *
 * x-16c750 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * x-16c750 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with x-16c750; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * web site:    http://blueskynet.dyndns-server.com
 * e-mail  :    blueskyniss@gmail.com
 *//***********************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Port interface
 *********************************************************************//** @{ */

#if !defined(PORT_H_)
#define PORT_H_

/*=========================================================  INCLUDE FILES  ==*/

#include "x-16c750.h"

/*===============================================================  MACRO's  ==*/

/**@brief       Expand UART data as IO memory table
 */
#define UART_DATA_EXPAND_AS_MEM(uart, mem, irq)                                 \
    mem,

/**@brief       Expand UART data as IRQ number table
 */
#define UART_DATA_EXPAND_AS_IRQ(uart, mem, irq)                                 \
    irq,

/**@brief       Supported UARTs table
 */
#define UART_DATA_EXPAND_AS_UART(uart, mem, iqr)                                \
    uart,

/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/
/*======================================================  GLOBAL VARIABLES  ==*/

/**@brief       Hardware IO memory maps
 */
extern const u32 gIOmap[];

/**@brief       Hardware IRQ numbers
 */
extern const u32 gIRQ[];

/**@brief       Number of supported UARTs
 */
extern const u32 gUartNum;

/*===================================================  FUNCTION PROTOTYPES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Port functions
 * @{ *//*--------------------------------------------------------------------*/

/**@brief       Create and init kernel device driver
 * @param       uartCtx
 *              Current driver context
 * @return      Operation status
 *  @retval     0 - SUCCESS
 *  @retval     !0 - error code
 */
int platInit(
    struct uartCtx *    uartCtx);

/**@brief       Deinit and destroy kernel device driver
 * @param       uartCtx
 *              Current driver context
 * @return      Operation status
 *  @retval     0 - SUCCESS
 *  @retval     !0 - error code
 */
int platTerm(
    struct uartCtx *    uartCtx);

int platDMAInit(
    struct uartCtx *    uartCtx);

int platDMATerm(
    struct uartCtx *    uartCtx);

/** @} *//*-------------------------------------------------------------------*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of port.h
 ******************************************************************************/
#endif /* PORT_H_ */