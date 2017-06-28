#include <iostream>
#include <vector>
#include <assets.h>
#include <abstract_object_factory.h>
#include <background.h>

using namespace std;

namespace model {

    Background::Background() {
        AbstractObject * o = new AbstractObject();
        o->loadTexture(assets::BACKGROUND_L1);
        this->backgroundLayers.push_back(o);
    };

    Background::~Background() {
        
    };

    void Background::addLayer(AbstractObject *bgLayer) {
        this->backgroundLayers.push_back(bgLayer);
    };

    void Background::draw(Renderer * renderer) {
        for(int i = 0; i < this->backgroundLayers.size(); i++) {
            renderer->batchRender(
                this->backgroundLayers[i]->getTexture(), 
                this->backgroundLayers[i]->getSrcRect(), 
                this->backgroundLayers[i]->getDestRect());
        }
    };

    void Background::update(Uint32 dt, const Uint8 * input) {
        //...
    };
}