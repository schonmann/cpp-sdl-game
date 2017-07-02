#include <assets.h>
#include <vector>

namespace assets {
    char * PLAYER = (char *) "./res/player.png";
    char * ENEMY = (char *) "./res/enemy.png";
    char * BACKGROUND_LAYERS[] = { 
        (char*)"./res/bg0.png", 
        (char*)"./res/bg1.png", 
        (char*)"./res/bg2.png", 
        (char*)"./res/bg3.png" 
    };
    char * MAIN_MUSIC = (char *) "./res/main.mp3";
    char * FONT_ARCADE = (char *) "./res/arcade.TTF";
    char * BAT = (char *) "./res/bat.gif";
    char * JUMP_LOW_1 = (char *) "./res/jump_sml_01.wav";
    char * JUMP_LOW_2 = (char *) "./res/jump_sml_02.wav";
    char * JUMP_HIGH_1 = (char *) "./res/jump_hgh_01.wav";
    char * JUMP_HIGH_2 = (char *) "./res/jump_hgh_02.wav";
}