#include <play_scene.h>
#include <iostream>
#include <background.h>
#include <player.h>

using namespace std;
using namespace model;

namespace scene{
    
    PlayScene::PlayScene() {
        Player * player = new Player();
        Background * background = new Background();
        background->setReferential(player);

        this->objects["background"] = background;
        this->objects["player"] = player;
    };

    PlayScene::~PlayScene() {

    };
}
