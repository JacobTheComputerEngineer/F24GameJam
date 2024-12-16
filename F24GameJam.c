/*
 * Starter code for the Fall 2024 Game Jam. Good luck!
 */

/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* HAL and Application includes */
#include <Application.h>
#include <HAL/HAL.h>

#include <ti/grlib/grlib.h>
#include "HAL/LcdDriver/Crystalfontz128x128_ST7735.h"

// Non-blocking check. Whenever Launchpad S1 is pressed, LED1 turns on.
static void InitNonBlockingLED()
{
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
}

// Non-blocking check. Whenever Launchpad S1 is pressed, LED1 turns on.
static void PollNonBlockingLED()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    if (GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1) == 0) {
        GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    }
}

int main()
{
    WDT_A_holdTimer();
    InitSystemTiming();

    // Do not remove this line. This is your non-blocking check.
    InitNonBlockingLED();
//
    HAL hal = HAL_construct();
    Application app = Application_construct();

    while (1)
    {
        // Do not remove this line. This is your non-blocking check.
        PollNonBlockingLED();

        HAL_refresh(&hal);
        Application_loop(&app, &hal);

    }
}
