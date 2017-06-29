#include <iostream>
#include <vector>
#include <assets.h>
#include <abstract_object_factory.h>
#include <background.h>

using namespace std;

namespace model {

    Background::Background() {
        AbstractObject * l1 = (new AbstractObject())->loadTexture(assets::BACKGROUND_L1)->setLayer(1);
        AbstractObject * l2 = (new AbstractObject())->loadTexture(assets::BACKGROUND_L2)->setLayer(2);
        AbstractObject * l3 = (new AbstractObject())->loadTexture(assets::BACKGROUND_L3)->setLayer(3);

        this->backgroundLayers.push_back(l1);
        this->backgroundLayers.push_back(l2);
        this->backgroundLayers.push_back(l3);

        this->setLayer(0);
    };

    Background::~Background() {
        
    };

    AbstractObject * Background::addLayer(AbstractObject *bgLayer) {
        this->backgroundLayers.push_back(bgLayer);
		return this;
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
