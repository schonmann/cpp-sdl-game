#include <play_scene.h>
#include <iostream>
#include <background.h>
#include <player.h>

using namespace std;
using namespace model;

namespace scene{
    
    PlayScene::PlayScene() {
        this->objects["background"] = new Background();
        this->objects["player"] = new Player();
    };

    PlayScene::~PlayScene() {

    };
}
