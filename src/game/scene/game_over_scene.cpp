#include <menu_scene.h>
#include <game_config.h>
#include <game_over.h>
#include <game_over_scene.h>

class Game;

using namespace model;

namespace scene {

    GameOverScene::GameOverScene(game::Game *game) : AbstractScene(game) {
        this->addObject("game_over", new GameOver());
        this->t = gameConfig::GAME_OVER_DELAY;
    };

    GameOverScene::~GameOverScene() {
        //...
    };

    void GameOverScene::update(float dt) {
        this->getObject("game_over")->update(dt);
        this->t -= dt;
        if(this->t <= 0) this->game->setScene(new MenuScene(this->game));
    };
}