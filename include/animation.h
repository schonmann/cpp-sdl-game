#pragma once

#include <SDL2/SDL.h>
#include <graphics.h>

namespace animation{
    class Animation{
        public:
            Animation(int rows, int cols, double w, double h);
            Animation();
            ~Animation();
            void update(float dt);
            void draw(core::Renderer * renderer);
            SDL_Rect * getSrcRect();
        private:
            SDL_Rect * clips;
            int currentFrame;
            int rows,cols;
            double w,h;
    };
}