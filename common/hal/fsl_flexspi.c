#include "fsl_flexspi.h"

retval_t FLEXSPI_Init(void)
{
    static volatile int retval = 3;
    return ++retval;
}
