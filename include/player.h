#pragma once

#include <abstract_object.h>

using namespace std;
using namespace core;
using namespace model;

namespace model {
    class Player : public AbstractObject {
        public:
            Player();
            ~Player();
            void draw(Renderer * renderer);
            void update(Uint32 dt, const Uint8 * input);
    };
}
