#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

namespace graphicsConfig {
    extern char * GAME_NAME;
    extern int WINDOW_X;
    extern int WINDOW_Y;
    extern int WINDOW_WIDTH;
    extern int WINDOW_HEIGHT;
    extern int RENDERER_SCALE_X;
    extern int RENDERER_SCALE_Y;
    extern Uint32 WINDOW_FLAGS;
    extern Uint32 RENDERER_FLAGS;
    extern int MAX_FPS;
    extern int TICKS_PER_FRAME;
    extern int TIMESTEP;
    extern int IMG_FLAGS;
    extern int SDL_INIT_FLAGS;
}