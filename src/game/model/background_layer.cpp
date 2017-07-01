#include <background_layer.h>

namespace model {
    BackgroundLayer::BackgroundLayer(){   
    };

    BackgroundLayer::~BackgroundLayer(){
    };

    BackgroundLayer * BackgroundLayer::setSpeedFactor(double speedFactor){
        this->speedFactor = speedFactor;
        return this;
    };

    double BackgroundLayer::getSpeedFactor() {
        return this->speedFactor;
    };
}