#pragma once

#include <abstract_object.h>

using namespace std;
using namespace core;
using namespace model;

namespace model {
    class Enemy : public AbstractObject {
        private:
            AbstractObject * referential;
            void reset();
            bool lazy;
        public:
            Enemy(AbstractObject * player, bool lazy);
            ~Enemy();
            void update(float dt);
            Enemy * setLazy(bool lazy);
    };
}
