#include <player.h>
#include <assets.h>

namespace model {
    
    Player::Player() {
        this->loadTexture(assets::PLAYER);
        this->setSX(2)->setSY(2);
    };

    Player::~Player() {

    };

    void Player::update(float dt, const Uint8 * input) {

    };
}
