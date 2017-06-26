#include <graphics.h>

namespace model {
    class GameObject {
        public:
            GameObject();
            ~GameObject();
            void draw(core::SDLGraphics *graphics);
            void update(Uint32 dt, const Uint8 * input);
        private:
            int x,y,dx,dy,ddx,ddy;
            SDL_Surface * surface;
    };
}