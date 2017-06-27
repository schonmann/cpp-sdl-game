#pragma once

#include <renderer.h>
#include <SDL2/SDL.h>

namespace core{
    class SDLGraphics : public Renderer {
        private:
            bool batching;
            SDL_Window * window;
            SDL_Renderer * renderer;
            SDL_Window * createWindow();
            SDL_Renderer * createRenderer(SDL_Window * window);
            void setScale(float x, float y);
            SDLGraphics();
        public:
            static SDLGraphics *getInstance();
            void startBatch();
            void batchRender(SDL_Texture * texture, SDL_Rect * src, SDL_Rect * dest);
            void endBatch();
            ~SDLGraphics();
    };
}