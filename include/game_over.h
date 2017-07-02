#pragma once

#include <SDL2/SDL_ttf.h>
#include <abstract_object.h>

namespace model {
    class GameOver : public AbstractObject{
        public:
            GameOver();
            ~GameOver();
            void update(float dt);
        private:
            TTF_Font *font;
            SDL_Color color;
    };
}
