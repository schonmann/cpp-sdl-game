#include <play_scene.h>
#include <iostream>
#include <background.h>
#include <player.h>
#include <score_board.h>

using namespace std;
using namespace model;

namespace scene{
    
    PlayScene::PlayScene() {
        Player * player = new Player();
        Background * background = new Background(player);
        ScoreBoard * scoreboard = new ScoreBoard(player);

        this->objects["background"] = background;
        this->objects["player"] = player;
        this->objects["scoreboard"] = scoreboard;
    };

    PlayScene::~PlayScene() {

    };
}
