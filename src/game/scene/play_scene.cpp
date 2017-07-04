#include <play_scene.h>
#include <menu_scene.h>
#include <iostream>
#include <background.h>
#include <player.h>
#include <score_board.h>
#include <enemy.h>
#include <game.h>
#include <collision.h>
#include <iostream>
#include <game_over_scene.h>

using namespace std;
using namespace model;

namespace game {
    class Game;
}

namespace scene{
    
    PlayScene::PlayScene(game::Game * game) : AbstractScene(game) {
        
        Player * player = new Player();
        Background * background = new Background(player);
        ScoreBoard * scoreboard = new ScoreBoard(player);
        Enemy * enemy = new Enemy(player, false);

        player->setInputEnabled(true);
        
        this->addObject("background", background);
        this->addObject("player", player);
        this->addObject("scoreboard", scoreboard);
        this->addObject("enemy", enemy);
    };

    PlayScene::~PlayScene() {

    };

    void PlayScene::update(float dt) {

        if(util::circularCollisionBetween(this->getObject("enemy"), this->getObject("player"))) {
            GameOverScene * gameOverScene = new GameOverScene(this->game);
            gameOverScene->addObjects(this->objects);
            this->game->setScene(gameOverScene);
        }

        AbstractScene::update(dt);
    };
}
