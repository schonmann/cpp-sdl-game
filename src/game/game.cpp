#include <iostream>
#include <SDL2/SDL.h>
#include <game.h>
#include <graphics.h>
#include <play_scene.h>
#include <menu_scene.h>
#include <sound.h>
#include <assets.h>

using namespace std;

namespace game {

    Game::Game() {
        scene::MenuScene * s = new scene::MenuScene(this);
        this->setScene(s);
    };

    Game *Game::Instance() {
        static Game *instance = new Game();
        return instance;
    };

    void Game::init() {
        cout << "Game: Initialized" << endl;
        Sound::getInstance().playMusic(assets::MAIN_MUSIC);
    };
}