#include <algorithm>
#include <iostream>
#include <vector>
#include <assets.h>
#include <background.h>
#include <graphics_config.h>

using namespace std;

namespace model {

    Background::Background() {
        this->setLayer(0);
        this->addLayer(assets::BACKGROUND_L1)->
            addLayer(assets::BACKGROUND_L2)->
            addLayer(assets::BACKGROUND_L3)->
            addLayer(assets::BACKGROUND_L4);
    };

    Background::~Background() {
        for_each(this->backgroundLayers.begin(), this->backgroundLayers.end(), free);
    };

    Background * Background::addLayer(string path) {
        AbstractObject * object = (new AbstractObject())->loadTexture(path)->setLayer(0);
        this->backgroundLayers.push_back(object);
		return this;
    };

    void Background::draw(Renderer * renderer) {
        for(int i = 0; i < this->backgroundLayers.size(); i++) {
            SDL_Rect * dest = this->backgroundLayers[i]->getDestRect();
            
            float multx = config::WINDOW_WIDTH / (float) dest->w;
            float multy = config::WINDOW_HEIGHT / (float) dest->h;
            
            dest->w *= multx;
            dest->h *= multy;

            renderer->batchRender(
                this->backgroundLayers[i]->getTexture(),
                this->backgroundLayers[i]->getSrcRect(),
                dest
            );
        }
    };

    void Background::update(Uint32 dt, const Uint8 * input) {
       //...
    };
}
