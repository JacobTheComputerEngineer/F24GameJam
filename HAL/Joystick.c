/*
 * Joystick.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Jacob Ramirez
 */

#include <HAL/Joystick.h>

void initADC() {
    ADC14_enableModule();

    ADC14_initModule(ADC_CLOCKSOURCE_SYSOSC,
                     ADC_PREDIVIDER_1,
                     ADC_DIVIDER_1,
                      0
                     );

    // This configures the ADC to store output results
    // in ADC_MEM0 for joystick X.
    // Todo: if we want to add joystick Y, then, we have to use more memory locations
    ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM1, true);

    // This configures the ADC in manual conversion mode
    // Software will start each conversion.
    ADC14_enableSampleTimer(ADC_AUTOMATIC_ITERATION);
}

void startADC() {
   // Starts the ADC with the first conversion
   // in repeat-mode, subsequent conversions run automatically
   ADC14_enableConversion();
   ADC14_toggleConversionTrigger();
}

void initJoyStick() {

    // This configures ADC_MEM0 to store the result from
    // input channel A15 (Joystick X), in non-differential input mode
    // (non-differential means: only a single input pin)
    // The reference for Vref- and Vref+ are VSS and VCC respectively
    ADC14_configureConversionMemory(ADC_MEM0,
                                  ADC_VREFPOS_AVCC_VREFNEG_VSS,
                                  ADC_INPUT_A15,                 // joystick X
                                  ADC_NONDIFFERENTIAL_INPUTS);

    // This selects the GPIO as analog input
    // A15 is multiplexed on GPIO port P6 pin PIN0
    // TODO: which one of GPIO_PRIMARY_MODULE_FUNCTION, or
    //                    GPIO_SECONDARY_MODULE_FUNCTION, or
    //                    GPIO_TERTIARY_MODULE_FUNCTION
    // should be used in place of 0 as the last argument?
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6,
                                               GPIO_PIN0,
                                               GPIO_TERTIARY_MODULE_FUNCTION);

    // TODO: add joystick Y
    ADC14_configureConversionMemory(ADC_MEM1,
                                      ADC_VREFPOS_AVCC_VREFNEG_VSS,
                                      ADC_INPUT_A9,                 // joystick Y
                                      ADC_NONDIFFERENTIAL_INPUTS);

    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4,
                                                   GPIO_PIN4,
                                                   GPIO_TERTIARY_MODULE_FUNCTION);

}

void getSampleJoyStick(unsigned *X, unsigned *Y) {
    // ADC runs in continuous mode, we just read the conversion buffers
    *X = ADC14_getResult(ADC_MEM0);

    // TODO: Read the Y channel
    *Y = ADC14_getResult(ADC_MEM1);
}

//identifies direction of joystick movement
void interpretJoyStick(Joystick* jst)
{
    //defaults, return to 0 when joystick isn't moving
    jst->left = false;
    jst->right = false;
    jst->down = false;
    jst->up = false;

    if (jst->x < LEFT_THRESHOLD)
    {//if joystick is moved left, left is true
        jst->left = true;
    }
    if (jst->x > RIGHT_THRESHOLD)
    {//etc
        jst->right = true;
    }
    if (jst->y < DOWN_THRESHOLD)
    {
        jst->down = true;
    }
    if (jst->y > UP_THRESHOLD)
    {
        jst->up = true;
    }

}
