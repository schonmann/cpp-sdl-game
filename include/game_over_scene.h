#pragma once

#include <abstract_scene.h>
#include <game.h>

namespace scene {
    class GameOverScene : public AbstractScene {
        public:
            GameOverScene(game::Game *game);
            ~GameOverScene();
            void update(float dt);
        private:
            int t;
    };
}