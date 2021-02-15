#include "proto_flash.h"

#include "fsl_flexspi.h"

#define FLASH_ADDR (0xFEEDBEEF)

int proto_flash_init(void)
{
    FLEXSPI_SoftwareReset(FLASH_ADDR);
    return FLEXSPI_Init();
}


