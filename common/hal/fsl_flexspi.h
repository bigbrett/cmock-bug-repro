/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FSL_FLEXSPI_H_
#define __FSL_FLEXSPI_H_

#include "fsl_common.h"

/*!
 * @brief Software reset for the FLEXSPI logic.
 *
 * This function sets the software reset flags for both AHB and buffer domain and
 * resets both AHB buffer and also IP FIFOs.
 *
 * @param base FLEXSPI peripheral base address.
 */
static inline void FLEXSPI_SoftwareReset(void * addr)
{
    volatile int a = 3;
    a++;
}

retval_t FLEXSPI_Init(void);


#endif
