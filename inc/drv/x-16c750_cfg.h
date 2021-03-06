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
 * @brief   	Configuration for 16C750 UART hardware
 *********************************************************************//** @{ */

#if !defined(X_16C750_CFG_H_)
#define X_16C750_CFG_H_

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
/*==============================================================  SETTINGS  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Generic driver configuration
 * @{ *//*--------------------------------------------------------------------*/

#define CFG_DEFAULT_BAUD_RATE           921600

/**@brief       UART number as assigned by silicon manufacturer
 * @note        The chosen driver must not be managed by Linux kernel
 */
#define CFG_UART_ID                     3

/** @} *//*---------------------------------------------------------------*//**
 * @name        Advanced driver settings
 * @{ *//*--------------------------------------------------------------------*/

#define CFG_DRV_NAME                    "xuart"

/**@brief       Internal buffer sizes - MUST be of size of power of 2!
 */
#define CFG_DRV_BUFF_SIZE               4096U

#define CFG_TIMEOUT_MS                  2000

/**@brief       Trigger level of UART FIFO
 * @details     Lower value:    + less generated interrupts
 *                              - may cause pauses in data flow
 *              Higher values:  + data flow is more consistent
 *                              - interrupts are generated very often
 */
#define CFG_FIFO_TRIG                   56

#define CFG_BUFF_BACKOFF                56

/**@brief       DMA mode
 * @details     0 - DMA mode not enabled
 *              1 - Software triggered DMA mode
 *              2 - Hardware triggered DMA mode
 */
#define CFG_DMA_MODE                    0

#define CFG_CRITICAL_INT_ENABLE         0

/** @} *//*-------------------------------------------------------------------*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of x-16c750_cfg.h
 ******************************************************************************/
#endif /* X_16C750_CFG_H_ */
