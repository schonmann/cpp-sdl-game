#pragma once

#include <abstract_object.h>

using namespace std;
using namespace core;
using namespace model;

namespace model {
    class Player : public AbstractObject {
        private:
            void handleInput();
            void fly();
            void jump();
            void goRight();
            void goLeft();
            void goDown();
            void stayIdle();
            void interpolateFly(float dt);
            bool flying;
            bool inputEnabled;
            bool isGrounded();
            double score;
        public:
            Player();
            ~Player();
            void update(float dt);
            double getScore();
            void setInputEnabled(bool inputEnabled);
    };
}
