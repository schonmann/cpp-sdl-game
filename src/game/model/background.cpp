#include <algorithm>
#include <iostream>
#include <vector>
#include <assets.h>
#include <background.h>
#include <graphics_config.h>
#include <background_config.h>
#include <math.h>

using namespace std;

namespace model {

    Background::Background() {
        this->setLayer(0);
        for(int i = 0; i < backgroundConfig::NUM_LAYERS; i++) {
            this->addLayer(assets::BACKGROUND_LAYERS[i], backgroundConfig::LAYER_DX_MULTIPLIER[i]);
        }
    };

    Background::~Background() {
        for_each(this->backgroundLayers.begin(), this->backgroundLayers.end(), free);
    };

    Background * Background::addLayer(char * path, double dx) {

        AbstractObject * layer = (new AbstractObject())->loadTexture(path)->setLayer(0)->setDX(dx);

        double xScaleFactor = graphicsConfig::WINDOW_WIDTH/(double) layer->getWidth();
        double yScaleFactor = graphicsConfig::WINDOW_HEIGHT/(double) layer->getHeight();

        layer->setSX(xScaleFactor);
        layer->setSY(yScaleFactor);

        this->backgroundLayers.push_back(layer);
        
		return this;
    };

    void Background::draw(Renderer * renderer) {
        for(int i = 0; i < this->backgroundLayers.size(); i++) {
            AbstractObject * layer = this->backgroundLayers[i];
            SDL_Rect dest = *layer->getDestRect();
            
            //Draw center.

            renderer->batchRender(
                layer->getTexture(),
                layer->getSrcRect(),
                &dest
            );

            //Draw left.

            dest.x = layer->getX() - dest.w;
            
            renderer->batchRender(
                layer->getTexture(),
                layer->getSrcRect(),
                &dest
            );

            //Draw right.

            dest.x = layer->getX() + dest.w;

            renderer->batchRender(
                layer->getTexture(),
                layer->getSrcRect(),
                &dest
            );
        }
    };

    void Background::update(float dt, const Uint8 * input) {
        AbstractObject * referential = this->referential;
        
        if(referential == NULL) return;

        for(int i = 0; i < this->backgroundLayers.size(); i++) {
            AbstractObject * layer = this->backgroundLayers[i];

            //Add the position of this layer according to the referential object
            //movement variables at the given time, the velocity of the layer, 
            //and the delta time.

            layer->addX(referential->getDX() * layer->getDX() * dt);

            //If the background is out of bounds, reset it.

            if(layer->getX() >= graphicsConfig::WINDOW_WIDTH || 
                layer->getX() <= -graphicsConfig::WINDOW_WIDTH) layer->setX(0);
        }
    };

    Background * Background::setReferential(AbstractObject * referential) {
        this->referential = referential;
        return this;
    };
}
