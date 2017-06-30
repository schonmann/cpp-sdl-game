#pragma once

#include <queue>
#include <abstract_object.h>
#include <graphics.h>
#include <string>
#include <map>

using namespace std;
using namespace core;
using namespace model;

typedef map<string, AbstractObject*, less<string> >::iterator gameObjIter;

struct sortByLayer {
    bool operator() (AbstractObject* a, AbstractObject* b) {
        return a->getLayer() < b->getLayer();
    }
};

namespace scene{
    class AbstractScene{
        protected:
            map<string, AbstractObject*, less<string> > objects;
            priority_queue<AbstractObject*, vector<AbstractObject*>, sortByLayer> objectHeap;
        public:
            virtual void draw(Renderer * renderer);
            virtual void update(Uint32 dt, const Uint8 * input);
            void addObject(string key, AbstractObject *newObject);
    };
}