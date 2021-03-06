#include <engine.h>
#include <graphics_config.h>

namespace core {

    void Engine::StartGameLoop() {

        assert(game != NULL);

        game->init();

        Uint32 lastTick = SDL_GetTicks();

        while(game->isRunning()) 
        {
            float dt = (SDL_GetTicks() - lastTick);
            lastTick = SDL_GetTicks();

            game->update(dt);
            
            this->graphics->startBatch();

            game->draw(this->graphics);

            this->graphics->endBatch();

            if(SDL_GetTicks() - lastTick < graphicsConfig::TICKS_PER_FRAME) {
                SDL_Delay(graphicsConfig::TICKS_PER_FRAME - (SDL_GetTicks() -  lastTick));
            }
            
            SDL_Event e;
            while(SDL_PollEvent(&e)) {
                switch(e.type) {
                    case SDL_QUIT:
                        delete this->graphics;
                        game->setRunning(false);
                }
            }
        }
    };

    Engine::Engine(game::AbstractGame *game) {
        this->graphics = SDLGraphics::getInstance();
        this->game = game;
    };

    void Engine::Run(game::AbstractGame *game) {
        static Engine * instance = new Engine(game);
        instance->StartGameLoop();
    };
}
