#include <SDL2/SDL.h>
#include <game.h>
#include <engine.h>

using namespace core;

int main(int argc, char *argv[]) {

    Engine::Run(game::Game::Instance());
    
    return 0;
}