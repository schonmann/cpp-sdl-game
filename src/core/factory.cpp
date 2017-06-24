#include <SDL2/SDL.h>
#include "../config/core.cpp"

namespace core {
    class CoreFactory{
        public:
        
            static SDL_Renderer * getRenderer(SDL_Window * window) {
                return SDL_CreateRenderer(window, -1,
                    config::RENDERER_FLAGS);
            }

            static SDL_Window * getWindow() {
                return SDL_CreateWindow(config::GAME_NAME,
                    config::WINDOW_X,
                    config::WINDOW_Y,
                    config::WINDOW_WIDTH, 
                    config::WINDOW_HEIGHT, 
                    config::WINDOW_FLAGS);
            }

        private:
            CoreFactory(){};
    };
}