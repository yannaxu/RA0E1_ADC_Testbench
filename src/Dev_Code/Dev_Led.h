#ifndef DEV_LED_H
#define DEV_LED_H

//////////
#include "Dev_Defines.h"

/* LED selection macros (16-bit mask) */
#define LED_SEL_MASK_X(LED_NO)   ((unsigned int)(0x0001U << (LED_NO)))
#define LED_SEL_MASK_ALL          0xFFFFU

#define LED_SEL_00   LED_SEL_MASK_X(0)
#define LED_SEL_01   LED_SEL_MASK_X(1)
#define LED_SEL_02   LED_SEL_MASK_X(2)
#define LED_SEL_03   LED_SEL_MASK_X(3)
#define LED_SEL_04   LED_SEL_MASK_X(4)
#define LED_SEL_05   LED_SEL_MASK_X(5)
#define LED_SEL_06   LED_SEL_MASK_X(6)
#define LED_SEL_07   LED_SEL_MASK_X(7)
#define LED_SEL_08   LED_SEL_MASK_X(8)
#define LED_SEL_09   LED_SEL_MASK_X(9)
#define LED_SEL_10   LED_SEL_MASK_X(10)
#define LED_SEL_11   LED_SEL_MASK_X(11)
#define LED_SEL_12   LED_SEL_MASK_X(12)
#define LED_SEL_13   LED_SEL_MASK_X(13)
#define LED_SEL_14   LED_SEL_MASK_X(14)
#define LED_SEL_15   LED_SEL_MASK_X(15)

/* Command definitions - match STM32 version's behavior */
#define LED_STATE_0V          GPIO_LEVEL_LOW      /* 0 -> output low */
#define LED_STATE_5V          GPIO_LEVEL_HIGH     /* 1 -> output high */
#define LED_STATE_TOGGLE      GPIO_LEVEL_TOGGLE   /* 2 -> toggle */

/* High-level state commands (auto-converts based on highIsOn flag) */
#define LED_STATE_OFF         0x03U
#define LED_STATE_ON          0x04U

/* Public functions */
void LEDs_Init(void);
void LEDs_SetValue(unsigned int unSelMask, unsigned char ucCmd);

/* Predefined LED aliases for specific functions (example) */
#define LED_SEL_CPU_TEST      LED_SEL_00
#define LED_CPU_TEST_OFF      LEDs_SetValue(LED_SEL_CPU_TEST, LED_STATE_OFF)
#define LED_CPU_TEST_ON       LEDs_SetValue(LED_SEL_CPU_TEST, LED_STATE_ON)
#define LED_CPU_TEST_TOGGLE   LEDs_SetValue(LED_SEL_CPU_TEST, LED_STATE_TOGGLE)

#endif /* DEV_LED_H */
