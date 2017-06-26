#include <SDL2/SDL.h>
#include <game.h>
#include <graphics.h>
#include <play_scene.h>

namespace game {

    Game::Game() {
        scene::PlayScene * s = new scene::PlayScene();
        this->setScene(s);
    };

    Game *Game::Instance() {
        static Game *instance = new Game();
        return instance;
    };

    void Game::init() {

    };

    void Game::update(Uint32 dt, const Uint8 *input) {

    };

    void Game::draw(core::SDLGraphics * graphics) {
        
    };
}