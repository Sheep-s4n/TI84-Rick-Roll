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
#define FRAME_NUMBER 40
#define SPRITE_SIZE 120
#define X_DRAW (SCREEN_X_MAX - SPRITE_SIZE) / 2
#define Y_DRAW (SCREEN_Y_MAX - SPRITE_SIZE) / 2 - (SCREEN_Y_MAX - SPRITE_SIZE) / 6

bool key_press = false;

unsigned char* frames_data[FRAME_NUMBER] = {
    frame_0_compressed,
    frame_1_compressed,
    frame_2_compressed,
    frame_3_compressed,
    frame_4_compressed,
    frame_5_compressed,
    frame_6_compressed,
    frame_7_compressed,
    frame_8_compressed,
    frame_9_compressed,
    frame_10_compressed,
    frame_11_compressed,
    frame_12_compressed,
    frame_13_compressed,
    frame_14_compressed,
    frame_15_compressed,
    frame_16_compressed,
    frame_17_compressed,
    frame_18_compressed,
    frame_19_compressed,
    frame_20_compressed,
    frame_21_compressed,
    frame_22_compressed,
    frame_23_compressed,
    frame_24_compressed,
    frame_25_compressed,
    frame_26_compressed,
    frame_27_compressed,
    frame_28_compressed,
    frame_29_compressed,
    frame_30_compressed,
    frame_31_compressed,
    frame_32_compressed,
    frame_33_compressed,
    frame_34_compressed,
    frame_35_compressed,
    frame_36_compressed,
    frame_37_compressed,
    frame_38_compressed,
    frame_39_compressed,
};

void gfx_init() {
    gfx_SetTextFGColor(254);
    gfx_SetTextScale(1 , 2);
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(0);
    gfx_FillScreen(2);
}

void drawFrame(gfx_sprite_t* sprite_buffer , unsigned char* frame_data) {
    if (key_press) return;
    if (os_GetCSC()) key_press = true;
    zx0_Decompress(sprite_buffer , frame_data);
    gfx_TransparentSprite(sprite_buffer, X_DRAW , Y_DRAW);
    gfx_PrintStringXY("You just got rick rolled !" , SCREEN_X_MAX / 4 , SCREEN_Y_MAX - 45);
    msleep(15);
}

int main(void)
{

    os_ClrHome();
    gfx_Begin();

    gfx_init();
    gfx_sprite_t* sprite_buffer = gfx_MallocSprite(SPRITE_SIZE, SPRITE_SIZE);
    if (sprite_buffer == NULL) return 1;

    do {
        for (int i = 0; i < FRAME_NUMBER; i++) {
            drawFrame(sprite_buffer , frames_data[i]);
        };
    }
    while (key_press == false);

    gfx_End();

    return 0;
}

