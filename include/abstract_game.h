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
            virtual void init() = 0;
            virtual void update(Uint32 dt, const Uint8 *input) = 0;
            virtual void draw(core::SDLGraphics * graphics) = 0;
            void setPaused(bool paused);
            void setRunning(bool running);
    };
}