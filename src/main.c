#include <ti/screen.h>
#include <ti/getcsc.h>
#include <ti/info.h>
#include <stdlib.h>
#include <graphx.h>

#include "gfx/gfx.h"

#define SCREEN_X_MAX 320 
#define SCREEN_Y_MAX 240 
#define IMAGE_X 255

int main(void)
{
    /* Clear the homescreen */
    os_ClrHome();
    gfx_Begin();

   /* Set the palette for sprites */
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    gfx_FillScreen(2);
    /* Draw a normal sprite */
    gfx_Sprite(rickroll, 32 , 0);

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
