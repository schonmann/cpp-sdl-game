#pragma once
#include <SDL2/SDL.h>

namespace core {
    class Renderer {
        public:
            virtual void batchRender(SDL_Texture * texture, SDL_Rect * src, SDL_Rect * dest) = 0;
    };
}