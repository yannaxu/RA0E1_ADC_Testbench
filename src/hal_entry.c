/*******************************************************************************************************************//**
 * hal_entry.c
 * RA0E1 LED control example
 **********************************************************************************************************************/

#include "hal_data.h"
//#include "Dev_Led.h"
#include "Dev_Code/Dev_Led.h"

/* Delay times in milliseconds */
#define INITIAL_BLINK_INTERVAL_MS   500     // 0.5 seconds
#define INITIAL_BLINK_COUNT         4       // Blink 4 times
#define FINAL_BLINK_INTERVAL_MS     2000    // 2 seconds

void hal_entry(void)
{
    uint32_t blink_count = 0;

    /* Initialize all LEDs (sets them to OFF state) */
    LEDs_Init();

    /* ===== Phase 1: Both LEDs blink 4 times at 0.5 second interval ===== */
    for (blink_count = 0; blink_count < INITIAL_BLINK_COUNT; blink_count++)
    {
        /* Turn both LEDs ON */
        LEDs_SetValue(LED_SEL_00 | LED_SEL_01, LED_STATE_TOGGLE);
        R_BSP_SoftwareDelay(INITIAL_BLINK_INTERVAL_MS, BSP_DELAY_UNITS_MILLISECONDS);
    }

    /* ===== Phase 2: LED1 blinks continuously at 2 second interval ===== */
    while (1)
    {
        /* Turn LED1 ON */
        LEDs_SetValue(LED_SEL_00, LED_STATE_ON);
        R_BSP_SoftwareDelay(FINAL_BLINK_INTERVAL_MS, BSP_DELAY_UNITS_MILLISECONDS);

        /* Turn LED1 OFF */
        LEDs_SetValue(LED_SEL_00, LED_STATE_OFF);
        R_BSP_SoftwareDelay(FINAL_BLINK_INTERVAL_MS, BSP_DELAY_UNITS_MILLISECONDS);
    }
}
