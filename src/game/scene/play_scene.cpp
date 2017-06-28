#include <play_scene.h>
#include <iostream>
#include <background.h>

using namespace std;
using namespace model;

namespace scene{
    
    PlayScene::PlayScene() {
        this->objects["background"] = new Background();
    };

    PlayScene::~PlayScene() {
    };
}