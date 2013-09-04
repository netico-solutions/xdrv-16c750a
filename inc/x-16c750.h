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
 * @brief       Driver level shared types
 *********************************************************************//** @{ */

#if !defined(X_16C750_H_)
#define X_16C750_H_

/*=========================================================  INCLUDE FILES  ==*/

#include <linux/platform_device.h>

#include <rtdm/rtdm_driver.h>
#include <native/heap.h>
#include <native/queue.h>

#include "circ_buff.h"
#include "x-16c750_ioctl.h"

/*===============================================================  MACRO's  ==*/

/**@brief       Return value: operation was successful
 */
#define RETVAL_SUCCESS                  0
#define RETVAL_FAILURE                  !RETVAL_SUCCESS

/*------------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

enum uartStatus {
    UART_STATUS_NORMAL,
    UART_STATUS_SOFT_OVERFLOW
};

/**@brief       UART device context structure
 */
struct uartCtx {
    rtdm_lock_t         lock;                                                   /**<@brief Lock to protect this structure                   */
    rtdm_irq_t          irqHandle;                                              /**<@brief IRQ routine handler structure                    */
    volatile u8 *       ioCache;
    u32                 idCache;
    struct {
        RT_HEAP             heapHandle;                                         /**<@brief Heap for internal buffers                        */
        RT_QUEUE            queueHandle;                                        /**<@brief Queue for RT comms                               */
        CIRC_BUFF           buffHandle;                                         /**<@brief Buffer handle                                    */
        nanosecs_rel_t      timeout;
        rtdm_mutex_t        mtx;                                                /**<@brief Write to buffer mutex                            */
        void *              queue;                                              /**<@brief Buffer storage                                   */
        enum uartStatus     status;
    }                   tx, rx;                                                 /**<@brief TX and RX channel                                */
    struct xUartProto   proto;
    u32                 signature;
};

/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of x-16c750.h
 ******************************************************************************/
#endif /* X_16C750_H_ */
