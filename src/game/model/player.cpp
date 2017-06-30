#include <player_config.h>
#include <player.h>
#include <assets.h>
#include <input.h>
#include <iostream>

using namespace input;

namespace model {
    
    Player::Player() {

        this->loadTexture(assets::PLAYER)->setSX(2)->setSY(2);
        
        int initialX = playerConfig::INITIAL_X - this->getWidth()/2;
        int initialY = playerConfig::INITIAL_Y - this->getHeight()*1.5;

        this->setX(initialX)->setY(initialY);
    };

    Player::~Player() {

    };

    void Player::update(float dt) {
        if(Input::getInstance().isPressed(SDLK_RIGHT)){
            this->addDDY(0.1);
        }
        this->updateDX(dt);
        this->updateDY(dt);
        //this->updateXPosition(dt);
        this->updateY(dt);
    };
}
