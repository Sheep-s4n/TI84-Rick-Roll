#include <ti/screen.h>
#include <ti/getcsc.h>
#include <stdlib.h>
#include <graphx.h>
#include <compression.h>
#include <sys/timers.h>

#include "gfx/gfx.h"

#define SCREEN_X_MAX 320 
#define SCREEN_Y_MAX 240 
#define IMAGE_X 255
#define FRAME_NUMBER 54
#define SPRITE_SIZE 120
#define X_DRAW (SCREEN_X_MAX - SPRITE_SIZE) / 2
#define Y_DRAW (SCREEN_Y_MAX - SPRITE_SIZE) / 2


void drawFrame(gfx_sprite_t* spriteBuffer , unsigned char* frame_data) {
    zx0_Decompress(spriteBuffer , frame_data);
    gfx_TransparentSprite(spriteBuffer, X_DRAW , Y_DRAW);
    msleep(20);
}

int main(void)
{

    /* Clear the homescreen */
    os_ClrHome();
    gfx_Begin();

   /* Set the palette for sprites */
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(0);
    gfx_FillScreen(2);

    gfx_sprite_t* spriteBuffer = gfx_MallocSprite(SPRITE_SIZE, SPRITE_SIZE);
    if (spriteBuffer == NULL) {
        gfx_PrintStringXY("Failed to allocate memory for the sprite" , 0 ,0);
        return 1;
    }
    do {       
        drawFrame(spriteBuffer , frame_0_compressed);
        drawFrame(spriteBuffer , frame_0_compressed);
        drawFrame(spriteBuffer , frame_1_compressed);
        drawFrame(spriteBuffer , frame_2_compressed);
        drawFrame(spriteBuffer , frame_3_compressed);
        drawFrame(spriteBuffer , frame_4_compressed);
        drawFrame(spriteBuffer , frame_5_compressed);
        drawFrame(spriteBuffer , frame_6_compressed);
        drawFrame(spriteBuffer , frame_7_compressed);
        drawFrame(spriteBuffer , frame_8_compressed);
        drawFrame(spriteBuffer , frame_9_compressed);
        drawFrame(spriteBuffer , frame_10_compressed);
        drawFrame(spriteBuffer , frame_11_compressed);
        drawFrame(spriteBuffer , frame_12_compressed);
        drawFrame(spriteBuffer , frame_13_compressed);
        drawFrame(spriteBuffer , frame_14_compressed);
        drawFrame(spriteBuffer , frame_15_compressed);
        drawFrame(spriteBuffer , frame_16_compressed);
        drawFrame(spriteBuffer , frame_17_compressed);
        drawFrame(spriteBuffer , frame_18_compressed);
        drawFrame(spriteBuffer , frame_19_compressed);
        drawFrame(spriteBuffer , frame_20_compressed);
        drawFrame(spriteBuffer , frame_21_compressed);
        drawFrame(spriteBuffer , frame_22_compressed);
        drawFrame(spriteBuffer , frame_23_compressed);
        drawFrame(spriteBuffer , frame_24_compressed);
        drawFrame(spriteBuffer , frame_25_compressed);
        drawFrame(spriteBuffer , frame_26_compressed);
        drawFrame(spriteBuffer , frame_27_compressed);
        drawFrame(spriteBuffer , frame_28_compressed);
        drawFrame(spriteBuffer , frame_29_compressed);
        drawFrame(spriteBuffer , frame_30_compressed);
        drawFrame(spriteBuffer , frame_31_compressed);
        drawFrame(spriteBuffer , frame_32_compressed);
        drawFrame(spriteBuffer , frame_33_compressed);
        drawFrame(spriteBuffer , frame_34_compressed);
        drawFrame(spriteBuffer , frame_35_compressed);
        drawFrame(spriteBuffer , frame_36_compressed);
        drawFrame(spriteBuffer , frame_37_compressed);
        drawFrame(spriteBuffer , frame_38_compressed);
        drawFrame(spriteBuffer , frame_39_compressed);

    }
    while (!os_GetCSC()); // wait for a key

    gfx_End();

    /* Return 0 for success */
    return 0;
}


    /*
    gfx_SetDefaultPalette();
    
    gfx_SetDrawBuffer();

    do {

        //gfx_SetColor(color);
        //gfx_SetTextFGColor(254);
        //gfx_PrintStringXY("Os Major Version: " , 3 , SCREEN_Y_MAX - 10);
        //gfx_PrintInt(majorVersion , 1);
        gfx_SwapDraw();

    } 
    while (!os_GetCSC()); // wait for a key
    */

/*
int x = 0;
int y = 0;
gfx_sprite_t *behind_sprite = gfx_MallocSprite(SPRITE_WIDTH, SPRITE_HEIGHT);

// ...draw the background code  here...

// set initial sprite state
gfx_GetSprite(behind_sprite, x, y);
gfx_TransparentSprite(sprite, x, y);

do {
    // if we don't need to move, loop
    if (no_move) continue;

    // clear out the old sprite
    gfx_Sprite(behind_sprite, x, y);

    // ...movement code here...
    // updates x and y

    // get the new background and draw the moved sprite
    gfx_GetSprite(behind_sprite, x, y);
    gfx_TransparentSprite(sprite, x, y);
} while (moving);
*/

// Todo :
// add a "You have been rickrolled" text
// make it possible to exit without reseting RAM
// refactor code