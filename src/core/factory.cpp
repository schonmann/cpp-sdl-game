#include <SDL2/SDL.h>
#include "../config/core.cpp"

namespace core {
    class CoreFactory{
        public:
        
            static SDL_Renderer * getRenderer(SDL_Window * window) {
                return SDL_CreateRenderer(window, -1,
                    config::SDL_RENDERER_FLAGS);
            }

            static SDL_Window * getWindow() {
                return SDL_CreateWindow(config::GAME_NAME,
                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                    config::WIN_WIDTH, 
                    config::WIN_HEIGHT, 
                    config::SDL_WINDOW_FLAGS);
            }

        private:
            CoreFactory(){};
    };
}