#include "proto_flash.h"

int main(void)
{
    volatile int ret = proto_flash_init();
    return 0;
}
