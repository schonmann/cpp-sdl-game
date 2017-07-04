#pragma once

#include <abstract_object.h>
#include <graphics.h>
#include <input.h>
#include <string>
#include <queue>
#include <map>

using namespace std;
using namespace core;
using namespace model;


namespace game {
    class Game;
}

namespace scene{

    typedef map<string, AbstractObject*, less<string> >::iterator gameObjIter;

    struct sortByLayer {
        bool operator() (AbstractObject* a, AbstractObject* b) {
            return a->getLayer() < b->getLayer();
        }
    };

    class AbstractScene{
        protected:
            game::Game *game;
            map<string, AbstractObject*, less<string> > objects;
            priority_queue<AbstractObject*, vector<AbstractObject*>, sortByLayer> objectHeap;
        public:
            virtual void draw(Renderer * renderer);
            virtual void update(float dt);
            AbstractScene(game::Game * game);
            ~AbstractScene();
            AbstractScene * addObject(string key, AbstractObject *newObject);
            AbstractObject * getObject(string key);
            AbstractScene * addObjects(map<string, AbstractObject*, less<string> > objects);
    };
}