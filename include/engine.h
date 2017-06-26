#include <graphics.h>
#include <assert.h>
#include <iostream>
#include <abstract_game.h>

namespace core{
    class Engine{
        private:
            game::AbstractGame *game;
            SDLGraphics *graphics;
            Engine(game::AbstractGame *game);
            void StartGameLoop();
        public:
            static void Run(game::AbstractGame * game);
    };
}