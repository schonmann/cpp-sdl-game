#pragma once

#include <abstract_scene.h>

namespace game {
    class Game;
}

namespace scene {
    class PlayScene : public AbstractScene {
        public:
            PlayScene(game::Game * game);
            ~PlayScene();
            void update(float dt);
    };
}