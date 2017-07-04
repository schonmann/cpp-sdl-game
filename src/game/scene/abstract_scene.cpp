#include <graphics.h>
#include <abstract_scene.h>
#include <iostream>

namespace game {
    class Game;
}

namespace scene{

    void AbstractScene::draw(core::Renderer * renderer) {
        for(gameObjIter it = this->objects.begin(); it != this->objects.end(); it++) it->second->draw(renderer);
    };
    
    void AbstractScene::update(float dt) {
        for(gameObjIter it = this->objects.begin(); it != this->objects.end(); it++) it->second->update(dt);
    };

    AbstractScene * AbstractScene::addObject(string key, AbstractObject *newObject) {
        this->objects[key] = newObject;
        this->objectHeap.push(newObject);
    };

    AbstractScene::AbstractScene(game::Game * game) {
        this->game = game;
    };

    AbstractScene::~AbstractScene() {
        for(gameObjIter it = this->objects.begin(); it != this->objects.end(); it++) delete it->second;
    };

    AbstractObject * AbstractScene::getObject(string key) {
        return this->objects[key];
    };
    
    AbstractScene * AbstractScene::addObjects(map<string, AbstractObject*, less<string> > toAdd) {
        this->objects.insert(toAdd.begin(), toAdd.end());
    };
}
