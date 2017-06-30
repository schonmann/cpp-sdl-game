#include <SDL2/SDL.h>
#include <input.h>

namespace input {
    
    Input & Input::getInstance() {
        static Input * instance = new Input();
        return *instance;
    };

    bool Input::isPressed(Uint8 key) {
        return this->state[key];
    };

    Input::Input() : state( SDL_GetKeyboardState(NULL) ) {
    };

    Input::~Input() {

    };
}