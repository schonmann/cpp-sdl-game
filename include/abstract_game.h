#pragma once

#include <abstract_scene.h>
#include <SDL2/SDL.h>
#include <map>

namespace game{
    class AbstractGame{
        private:
            scene::AbstractScene * scene;
            bool running;
            bool paused;
        protected:
            AbstractGame();
            void setScene(scene::AbstractScene * scene);
            scene::AbstractScene * currentScene();
        public:
            bool isRunning();
            virtual void init();
            virtual void update(float dt);
            virtual void draw(core::Renderer * renderer);
            void setPaused(bool paused);
            void setRunning(bool running);
    };
}