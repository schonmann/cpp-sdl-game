#include <iostream>
#include <SDL2/SDL.h>
#include <game.h>
#include <graphics.h>
#include <play_scene.h>

using namespace std;

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
        cout << "Game: Initialized" << endl;
    };
}