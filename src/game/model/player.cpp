#include <player_config.h>
#include <player.h>
#include <assets.h>

namespace model {
    
    Player::Player() {

        this->loadTexture(assets::PLAYER)->setSX(2)->setSY(2);
        
        int initialX = playerConfig::INITIAL_X - this->getWidth()/2;
        int initialY = playerConfig::INITIAL_Y - this->getHeight()*1.5;

        this->setX(initialX)->setY(initialY)->setDX(1);
    };

    Player::~Player() {

    };

    void Player::update(float dt, const Uint8 * input) {
        //updateXMotion(dx); Do not update x axis!
        this->updateYMotion(dt);
    };
}
