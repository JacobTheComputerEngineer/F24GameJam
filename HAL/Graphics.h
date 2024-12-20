/*
 * Graphics.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Matthew Zhong
 */

#ifndef HAL_GRAPHICS_H_
#define HAL_GRAPHICS_H_

#include <HAL/LcdDriver/Crystalfontz128x128_ST7735.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include <string.h>
#include <stdio.h>

#define FG_COLOR GRAPHICS_COLOR_WHITE
#define BG_COLOR GRAPHICS_COLOR_BLACK

//LCD pixel borders
#define LeftBorder 7
#define RightBorder 120
#define TopBorder 22
#define DownBorder 110

struct _GFX
{
    Graphics_Context context;
    uint32_t foreground;
    uint32_t background;
    uint32_t defaultForeground;
    uint32_t defaultBackground;
    Graphics_Font font;
};
typedef struct _GFX GFX;

GFX GFX_construct(uint32_t defaultForeground, uint32_t defaultBackground);

void GFX_resetColors(GFX* gfx_p);
void GFX_clear(GFX* gfx_p);

void GFX_print(GFX* gfx_p, char* string, int row, int col);
void GFX_printChar(GFX* gfx_p, char* string, int row, int col);
void GFX_setForeground(GFX* gfx_p, uint32_t foreground);
void GFX_setBackground(GFX* gfx_p, uint32_t background);

void GFX_drawSolidCircle(GFX* gfx_p, int x, int y, int radius);
void GFX_drawHollowCircle(GFX* gfx_p, int x, int y, int radius);
void GFX_removeSolidCircle(GFX* gfx_p, int x, int y, int radius);
void GFX_removeHollowCircle(GFX* gfx_p, int x, int y, int radius);

void GFX_drawFilledRectangle(GFX *gfx, int x, int y, int width, int height);
void GFX_drawHollowRectangle(GFX *gfx, int x, int y, int width, int height);
void GFX_removeFilledRectangle(GFX *gfx, int x, int y, int width, int height);
void GFX_removeHollowRectangle(GFX *gfx, int x, int y, int width, int height);


//custom functions


#endif /* HAL_GRAPHICS_H_ */
