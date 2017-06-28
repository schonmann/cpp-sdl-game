#include <engine.h>
#include <graphics_config.h>

namespace core {

    void Engine::StartGameLoop() {

        assert(game != NULL);

        game->init();

        Uint32 lastTick = SDL_GetTicks();

        int frameCount = 0;

        while(game->isRunning()) 
        {
            Uint32 dt = SDL_GetTicks() - lastTick;
            lastTick = SDL_GetTicks();

            game->update(dt, SDL_GetKeyboardState(NULL));
            
            this->graphics->startBatch();

            game->draw(this->graphics);

            this->graphics->endBatch();

            #ifdef DEBUG
            printf("AVG: %f\n", frameCount/(SDL_GetTicks()/1000.0f));
            #endif

            if(SDL_GetTicks() - lastTick < config::TICKS_PER_FRAME) {
                SDL_Delay(config::TICKS_PER_FRAME - (SDL_GetTicks() -  lastTick));
            }

            frameCount++;
            
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
