#include <play_scene.h>
#include <menu_scene.h>
#include <iostream>
#include <background.h>
#include <player.h>
#include <score_board.h>
#include <enemy.h>
#include <game.h>
#include <game_over.h>
#include <collision.h>
#include <iostream>

using namespace std;
using namespace model;
using namespace game;

namespace scene{
    
    PlayScene::PlayScene(Game * game) {
        this->game = game;
        
        Player * player = new Player();
        Background * background = new Background(player);
        ScoreBoard * scoreboard = new ScoreBoard(player);
        Enemy * enemy = new Enemy(player, false);

        player->setInputEnabled(true);
        
        this->objects["background"] = background;
        this->objects["player"] = player;
        this->objects["scoreboard"] = scoreboard;
        this->objects["enemy"] = enemy;

        this->gameOverTime = 0;
    };

    PlayScene::~PlayScene() {

    };

    void PlayScene::update(float dt) {
        if(this->gameOverTime != 0) {
            Uint32 now = SDL_GetTicks();
            if(now - this->gameOverTime >= 1500) {
                MenuScene * menu = new MenuScene(this->game);
                this->game->setScene(menu);
            }
            return;
        }

        if(util::circularCollisionBetween(this->objects["enemy"], this->objects["player"])) {
            this->objects["game_over"] = new GameOver();
            this->objects["game_over"]->update(dt);
            this->gameOverTime = SDL_GetTicks();
        }
        AbstractScene::update(dt);
    };
}
