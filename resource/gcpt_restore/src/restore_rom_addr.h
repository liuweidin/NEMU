#ifndef __RESTORE_ROM_ADDR__
#define __RESTORE_ROM_ADDR__

#define CPT_MAGIC_BUMBER    0xbeef
#define BOOT_CODE           0x2000000000L
#define BOOT_FLAGS          0x2000000f00L
#define INT_REG_CPT_ADDR    0x2000001000L
#define FLOAT_REG_CPT_ADDR  0x2000001100L
#define PC_CPT_ADDR         0x2000001200L
#define CSR_CPT_ADDR        0x2000001300L

#ifndef RESET_VECTOR
    #define RESET_VECTOR        0x20000a0000L
#endif

#define CLINT_MMIO 0x1f10000000L
#define CLINT_MTIMECMP 0x4000
#define CLINT_MTIME 0xBFF8

#endif //__RESTORE_ROM_ADDR__
