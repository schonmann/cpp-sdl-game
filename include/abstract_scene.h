#pragma once

#include <abstract_object.h>
#include <graphics.h>
#include <string>
#include <map>

using namespace std;
using namespace core;
using namespace model;

struct drawPriority{
    bool operator()(const AbstractObject& a, const AbstractObject& b) const {
        return a.layer > b.layer;
    }
};

typedef map<string, AbstractObject*, struct drawPriority>::iterator gameObjIter;

namespace scene{
    class AbstractScene{
        protected:
            map<string, AbstractObject*, struct drawPriority> objects;
        public:
            virtual void draw(Renderer * renderer);
            virtual void update(Uint32 dt, const Uint8 * input);
            void addObject(AbstractObject * newObject);
    };
}