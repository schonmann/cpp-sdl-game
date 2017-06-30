#include <player_config.h>
#include <player.h>
#include <assets.h>

namespace model {
    
    Player::Player() {
        this->loadTexture(assets::PLAYER);
        this->setSX(2)->setSY(2);
        this->setX(playerConfig::INITIAL_X - this->getWidth()/2);
        this->setY(playerConfig::INITIAL_Y - this->getHeight()*1.5);
    };

    Player::~Player() {

    };

    void Player::update(float dt, const Uint8 * input) {
        //updateXMotion(dx); Do not update x axis!
        this->updateYMotion(dt);
    };
}
