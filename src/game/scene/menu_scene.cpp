#include <play_scene.h>
#include <player.h>
#include <background.h>
#include <menu_scene.h>
#include <menu.h>
#include <iostream>

namespace scene {
    MenuScene::MenuScene(game::Game * game) {
        this->game = game;

        Player * player = new Player();
        Background * background = new Background(player);
        Menu * menu = new Menu();

        player->setInputEnabled(false);

        this->objects["background"] = background;
        this->objects["player"] = player;
        this->objects["menu"] = menu;
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