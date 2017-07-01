#include <graphics_config.h>
#include <player_config.h>
#include <player.h>
#include <assets.h>
#include <input.h>
#include <iostream>

using namespace core;

namespace model {
    
    Player::Player() {
        this->loadTexture(assets::PLAYER, 1, 1)->setSX(2)->setSY(2);

        int initialX = playerConfig::INITIAL_X - this->getWidth()/2;
        int initialY = playerConfig::INITIAL_Y - this->getHeight()*1.5;

        this->setX(initialX)->setY(initialY)->setDDY(0.002)->
            setBoundsX(0, graphicsConfig::WINDOW_WIDTH - this->getWidth())->
            setBoundsY(0, graphicsConfig::WINDOW_HEIGHT - this->getHeight()*1.5)->
            setBoundsDX(-playerConfig::MAX_DX, playerConfig::MAX_DX)->
            setBoundsDY(-playerConfig::MAX_DY, playerConfig::MAX_DY);

        this->flying = false;
    };

    Player::~Player() {

    };

    void Player::jump() {
        this->setDY(playerConfig::JUMP_SPEED);
    };

    void Player::fly() {
        this->flying = true;
    };

    void Player::goRight() {
        this->setDDX(playerConfig::X_ACCEL);
    };

    void Player::goLeft() {
        this->setDDX(-playerConfig::X_ACCEL);
    };

    void Player::stayIdle() {
        this->setDDX(0);
    };

    void Player::goDown() {
        this->setDY(.8);
    };

    void Player::interpolateFly(float dt) {
        this->addDDY(-playerConfig::FLY_ACCEL);
        if(this->getDY() <= -.5) {
            this->setDDY(0.002);
            this->flying = false;
        }
    };

    bool Player::isGrounded() {
        return this->getY() == this->getBoundsY().getB();
    };

    void Player::handleInput() {
        Input * input = &Input::getInstance();
        
        if(input->isPressed(SDL_SCANCODE_RIGHT)) this->goRight();
        else if(input->isPressed(SDL_SCANCODE_LEFT)) this->goLeft();
        else this->stayIdle();
        
        bool spacePressed = input->isPressed(SDL_SCANCODE_SPACE);

        if(spacePressed) {
            if(this->isGrounded()) this->jump();
            else if (this->getDY() > 0) this->fly();
        } 
    };

    void Player::update(float dt) {
        this->handleInput();

        if(this->flying) this->interpolateFly(dt);

        this->score += this->getDX() * dt;

        this->updateDX(dt);
        this->updateDY(dt);
        //this->updateX(dt);
        this->updateY(dt);

        this->getAnimation()->update(dt);
    };

    double Player::getScore() {
        return this->score;
    };
}
