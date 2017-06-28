#pragma once

#include <abstract_object.h>
#include <graphics.h>
#include <string>
#include <map>

using namespace std;
using namespace core;
using namespace model;

typedef map<string,AbstractObject*>::iterator gameObjIter;

namespace scene{
    class AbstractScene{
        protected:
            map<string, AbstractObject*> objects;
        public:
            virtual void draw(Renderer * renderer);
            virtual void update(Uint32 dt, const Uint8 * input);
            void addObject(AbstractObject * newObject);
    };
}