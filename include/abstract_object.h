#pragma once
#include <renderer.h>

namespace model {
    class AbstractObject {
        public:
            int x, y;
            int w, h;
            int dx,dy;
            int ddx,ddy;
            SDL_Texture * texture;

            AbstractObject();
            ~AbstractObject();

            virtual void draw(core::Renderer *renderer);
            virtual void update(Uint32 dt, const Uint8 * input);
            virtual SDL_Texture * getTexture();
            virtual SDL_Rect * getSrcRect();
            virtual SDL_Rect * getDestRect();
    };
}