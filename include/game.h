#pragma once

#include <abstract_game.h>
#include <renderer.h>

namespace game {
    class Game : public AbstractGame {
        private:
            Game();
            ~Game();
        public:
            static Game *Instance();
            void init();
            // void update(float dt);
            // void draw(core::Renderer * renderer);
    };
}