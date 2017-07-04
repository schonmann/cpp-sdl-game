#include <play_scene.h>
#include <player.h>
#include <background.h>
#include <menu_scene.h>
#include <menu.h>
#include <iostream>

namespace scene {

    MenuScene::MenuScene(game::Game * game) : AbstractScene(game) {
        this->game = game;
        
        Player * player = new Player();
        Background * background = new Background(player);
        Menu * menu = new Menu();

        player->setInputEnabled(false);

        this->addObject("background", background);
        this->addObject("player", player);
        this->addObject("menu", menu);
    };

    MenuScene::~MenuScene() {

    };

    void MenuScene::update(float dt) {
        Input * input = &Input::getInstance();
        if(input->isPressed(SDL_SCANCODE_W) || input->isPressed(SDL_SCANCODE_A) || 
            input->isPressed(SDL_SCANCODE_S) || input->isPressed(SDL_SCANCODE_D) || 
            input->isPressed(SDL_SCANCODE_UP) || input->isPressed(SDL_SCANCODE_LEFT) || 
            input->isPressed(SDL_SCANCODE_DOWN) || input->isPressed(SDL_SCANCODE_RIGHT)) {

            PlayScene * scene = new PlayScene(this->game);
            this->game->setScene(scene);
        }
        
        AbstractScene::update(dt);
    };
}