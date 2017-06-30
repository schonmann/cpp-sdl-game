#include <graphics.h>
#include <abstract_scene.h>

namespace scene{

    void AbstractScene::draw(core::Renderer * renderer) {
        for(gameObjIter it = this->objects.begin(); it != this->objects.end(); it++) it->second->draw(renderer);
    }
    
    void AbstractScene::update(Uint32 dt, const Uint8 * input) {
        for(gameObjIter it = this->objects.begin(); it != this->objects.end(); it++) it->second->update(dt, input);
    }

    void AbstractScene::addObject(string key, AbstractObject *newObject) {
        this->objects[key] = newObject;
        this->objectHeap.push(newObject);
    }
}
