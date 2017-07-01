#include <graphics_config.h>
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

        this->setX(initialX)->setY(initialY)->setDDY(0.002)->
            setBoundsX(0, graphicsConfig::WINDOW_WIDTH - this->getWidth())->
            setBoundsY(0, graphicsConfig::WINDOW_HEIGHT - this->getHeight()*1.5);
    };

    Player::~Player() {

    };

    void Player::update(float dt) {
        if(Input::getInstance().isPressed(SDL_SCANCODE_RIGHT)) this->setDDX(0.002);
        else if(Input::getInstance().isPressed(SDL_SCANCODE_LEFT)) this->setDDX(-0.002);
        else this->setDDX(0);

        int ground = this->getBoundsY().getB();
        
        if(Input::getInstance().isPressed(SDL_SCANCODE_SPACE) && this->getY() == ground)
            this->setDY(playerConfig::JUMP_SPEED);
        
        this->updateDX(dt);
        this->updateDY(dt);
        this->updateX(dt);
        this->updateY(dt);
    };
}
