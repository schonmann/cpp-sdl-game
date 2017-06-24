#include <iostream>
#include <SDL2/SDL.h>
#include "factory.cpp"

using namespace std;

namespace core{

    //Singleton class that initialize primary SDL entities for game usage.
    
    class SDLCore {
        private:
            SDL_Window * window;
            SDL_Renderer * renderer;

            SDLCore() {
                SDL_Init(SDL_INIT_EVERYTHING);
                
                this->window = CoreFactory::getWindow();
                this->renderer = CoreFactory::getRenderer(this->window);
            }
        public:

            SDL_Window * getWindow() {
                return this->window;
            }

            SDL_Renderer * getRenderer() {
                return this->renderer;
            }

            static SDLCore &Instance() {
                static SDLCore *instance = new SDLCore();
                return *instance;
            }
    };
}