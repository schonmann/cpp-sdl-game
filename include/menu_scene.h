#pragma once

#include <abstract_scene.h>
#include <game.h>

namespace scene {
    class MenuScene : public AbstractScene {
        private:
			game::Game * game;
        public:
            MenuScene(game::Game * game);
            ~MenuScene();
			
            void update(float dt);
    };
}