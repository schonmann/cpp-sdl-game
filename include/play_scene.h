#pragma once

#include <abstract_scene.h>
#include <game.h>

using namespace game;

namespace scene {
    class PlayScene : public AbstractScene {
        public:
            PlayScene(Game * game);
            ~PlayScene();
            void update(float dt);
        private:
			Game * game;
            Uint32 gameOverTime;
    };
}