#include <animation.h>

namespace animation {
    Animation::Animation(AbstractObject * object) {
        this->object = object;
        this->currentFrame = 0;
    };

    Animation::~Animation() {

    };

    void Animation::update(float dt) {
        
    }
};