#pragma once

#include <abstract_object.h>

namespace model {
    class BackgroundLayer : public AbstractObject {
        private:
            double speedFactor;
        public:
            BackgroundLayer();
            ~BackgroundLayer();
            BackgroundLayer * setSpeedFactor(double speedFactor);
            double getSpeedFactor();
    };
}