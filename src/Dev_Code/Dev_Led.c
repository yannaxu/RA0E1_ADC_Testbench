/*
 * Dev_Led.c
 *
 *  Created on: May 17, 2026
 *      Author: LMC
 */


#define DEV_LED_C

#include "Dev_Defines.h"
#include "Dev_Led.h"
#include "bsp_api.h"
#include "r_ioport.h"
#include "hal_data.h"

#include <stdbool.h>

/* External reference to IOPORT control structure (from FSP config) */
extern ioport_instance_ctrl_t g_ioport_ctrl;

/* RA0E1 LED hardware mapping - using single bsp_io_port_pin_t */
typedef struct {
    bsp_io_port_pin_t pin;   /* Combined port+pin, e.g., BSP_IO_PORT_02_PIN_00 */
    bool              highIsOn;  /* true = HIGH turns LED on, false = LOW turns LED on */
} LedHw_t;

static const LedHw_t s_led[] = {
    /* Format: { pin, highIsOn } */
    { BSP_IO_PORT_00_PIN_08, true },   /* LED0 - Active Low (P200) */
    { BSP_IO_PORT_00_PIN_09, true },   /* LED1 - Active Low (P201) */
    /* Add more LEDs as needed */
};

#define LED_COUNT   (sizeof(s_led) / sizeof(s_led[0]))

/* Helper: Write physical pin level */
static void led_write_pin(bsp_io_port_pin_t pin, bsp_io_level_t level)
{
    g_ioport.p_api->pinWrite(&g_ioport_ctrl, pin, level);
}

/* Helper: Toggle physical pin */
static void led_toggle_pin(bsp_io_port_pin_t pin)
{
    bsp_io_level_t current_level;
    g_ioport.p_api->pinRead(&g_ioport_ctrl, pin, &current_level);

    bsp_io_level_t new_level = (current_level == BSP_IO_LEVEL_HIGH) ?
                                BSP_IO_LEVEL_LOW : BSP_IO_LEVEL_HIGH;
    g_ioport.p_api->pinWrite(&g_ioport_ctrl, pin, new_level);
}

/* Main LED control function - same API as STM32 version */
void LEDs_SetValue(unsigned int unSelMask, unsigned char ucCmd)
{
    for (uint32_t i = 0; i < LED_COUNT; i++)
    {
        if (unSelMask & LED_SEL_MASK_X(i))
        {
            unsigned char ucCmd_Each = ucCmd;

            /* Convert high-level ON/OFF commands based on LED polarity */
            if (ucCmd_Each == LED_STATE_OFF)
            {
                /* OFF: if highIsOn then output LOW, else output HIGH */
                ucCmd_Each = s_led[i].highIsOn ? GPIO_LEVEL_LOW : GPIO_LEVEL_HIGH;
            }
            else if (ucCmd_Each == LED_STATE_ON)
            {
                /* ON: if highIsOn then output HIGH, else output LOW */
                ucCmd_Each = s_led[i].highIsOn ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW;
            }

            /* Execute physical operation */
            if (ucCmd_Each == GPIO_LEVEL_HIGH)
            {
                led_write_pin(s_led[i].pin, BSP_IO_LEVEL_HIGH);
            }
            else if (ucCmd_Each == GPIO_LEVEL_LOW)
            {
                led_write_pin(s_led[i].pin, BSP_IO_LEVEL_LOW);
            }
            else if (ucCmd_Each == GPIO_LEVEL_TOGGLE)
            {
                led_toggle_pin(s_led[i].pin);
            }
        }
    }
}

/* Initialize all LEDs to OFF state */
void LEDs_Init(void)
{
    LEDs_SetValue(LED_SEL_MASK_ALL, LED_STATE_OFF);
}

