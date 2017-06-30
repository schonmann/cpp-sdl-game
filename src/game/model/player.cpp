#include <player.h>
#include <assets.h>

namespace model {
    
    Player::Player() {
        this->loadTexture(assets::PLAYER);
    };

    Player::~Player() {

    };
    
    void Player::update(float dt, const Uint8 * input) {

    };
}
