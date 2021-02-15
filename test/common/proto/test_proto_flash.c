#include "unity.h"

#include "proto_flash.h"
#include "mock_fsl_flexspi.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_protoFlashInit(void)
{
    FLEXSPI_SoftwareReset_Expect((void*)0xFEEDBEEF);
    FLEXSPI_Init_ExpectAndReturn(0);

    TEST_ASSERT_EQUAL(0, proto_flash_init());
}

