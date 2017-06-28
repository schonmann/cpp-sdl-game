#include <iostream>
#include <vector>
#include <assets.h>
#include <abstract_object_factory.h>
#include <background.h>

using namespace std;

namespace model {

    Background::Background() {
        AbstractObject * l1 = new AbstractObject();
        AbstractObject * l2 = new AbstractObject();
        AbstractObject * l3 = new AbstractObject();

        l1->loadTexture(assets::BACKGROUND_L1);
        l1->setLayer(1);

        l2->loadTexture(assets::BACKGROUND_L2); 
        l2->setLayer(2);

        l3->loadTexture(assets::BACKGROUND_L3);
        l3->setLayer(3);

        this->backgroundLayers.push_back(l1);
        this->backgroundLayers.push_back(l2);
        this->backgroundLayers.push_back(l3);
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
                this->backgroundLayers[i]->getDestRect()
            );
        }
    };

    void Background::update(Uint32 dt, const Uint8 * input) {
        //...
    };
}