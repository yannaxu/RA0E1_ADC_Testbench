/*
 * Dev_Defines.h
 *
 *  Created on: May 17, 2026
 *      Author: LMC
 */

#ifndef DEV_DEFINES_H_
#define DEV_DEFINES_H_

/* Define target MCU type */
#define MCU_TYPE_RENESAS_RA0E1

/*
 * For STM32 compatibility macros - keeping same interface
 * but internal implementation uses FSP functions
 */

/* Basic data types (same as STM32 version) */
typedef unsigned char  UBYTE;       /* Unsigned  8 bit quantity */
typedef unsigned short UWORD;       /* Unsigned 16 bit quantity */
typedef unsigned long  ULONG;       /* Unsigned 32 bit quantity */

/* GPIO level definitions - matches FSP's bsp_io_level_t */
#define GPIO_LEVEL_LOW    0
#define GPIO_LEVEL_HIGH   1
#define GPIO_LEVEL_TOGGLE 2

/* Bit manipulation macros (hardware independent) */
#define DEV_GET_BIT(REG,INDEX)  (((REG) >> (INDEX)) & 1U)
#define DEV_SET_BIT(REG,INDEX)  ((REG) |= (1UL << (INDEX)))
#define DEV_CLR_BIT(REG,INDEX)  ((REG) &= ~(1UL << (INDEX)))
#define DEV_TGL_BIT(REG,INDEX)  ((REG) ^= (1UL << (INDEX)))
#define DEV_MAKE_BIT(REG,INDEX,VALUE)  ((VALUE) ? DEV_SET_BIT(REG,INDEX) : DEV_CLR_BIT(REG,INDEX))

/* Result codes */
#define RESULT_FAIL    0
#define RESULT_OK      1

#endif /* DEV_DEFINES_H_ */

