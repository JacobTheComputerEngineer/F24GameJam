/*
 * Joystick.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Jacob Ramirez
 */

#ifndef HAL_JOYSTICK_H_
#define HAL_JOYSTICK_H_

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <HAL/Button.h>

//joystick movements defines
#define LEFT_THRESHOLD  5000
#define RIGHT_THRESHOLD 10000
#define DOWN_THRESHOLD  5000
#define UP_THRESHOLD 10000

//neutral, no movement
#define STANDING 8192

struct _Joystick
{
    //joystick positional values
    unsigned int x;
    unsigned int y;

    //flags for each movement direction
    bool right;
    bool left;
    bool up;
    bool down;
};
typedef struct _Joystick Joystick;

//default functions from in class and example code
void initADC();
void startADC();
void initJoyStick();
void getSampleJoyStick(unsigned *X, unsigned *Y);
void interpretJoyStick(Joystick* jst);

#endif /* HAL_JOYSTICK_H_ */
