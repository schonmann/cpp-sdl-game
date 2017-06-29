#include <iostream>
#include <SDL2/SDL_image.h>
#include <graphics.h>
#include <abstract_object.h>

using namespace core;
using namespace std;

namespace model {

    AbstractObject::AbstractObject() {
    };

    AbstractObject::~AbstractObject() {

    };

    void AbstractObject::draw(Renderer *renderer) {
        renderer->batchRender(this->getTexture(),
            this->getSrcRect(),
            this->getDestRect());
    };

    void AbstractObject::update(Uint32 dt, const Uint8 * input) {
        //...
    };

    SDL_Texture * AbstractObject::getTexture() {
        return this->texture;
    };

    SDL_Rect * AbstractObject::getSrcRect() {
        return NULL;
    };

    SDL_Rect * AbstractObject::getDestRect() {
        static SDL_Rect destination;

        destination.x = this->x;
        destination.y = this->y;
        destination.w = this->w;
        destination.h = this->h;

        return &destination;
    };

    AbstractObject * AbstractObject::loadTexture(string path) {
        SDL_Surface * surface = IMG_Load(path.c_str());
        SDL_Renderer * renderer = SDLGraphics::getInstance()->getRenderer();
        
        this->w = surface->w;
        this->h = surface->h;

        this->texture = SDL_CreateTextureFromSurface(renderer, surface);
		return this;
    };

    int AbstractObject::getLayer() {
        return this->layer;
    };

    AbstractObject * AbstractObject::setLayer(int layer) {
        this->layer = layer;
		return this;
    };

	AbstractObject * AbstractObject::setX(int x) {
        this->x = x;
		return this;
    };

	AbstractObject * AbstractObject::setY(int y) {
        this->y = y;
		return this;
    };

	AbstractObject * AbstractObject::setDX(int dx) {
        this->dx = dx;
		return this;
    };

	AbstractObject * AbstractObject::setDY(int dy) {
        this->dy = dy;
		return this;
    };
	
	AbstractObject * AbstractObject::setDDX(int ddx) {
        this->ddx = ddx;
		return this;
    };

	AbstractObject * AbstractObject::setDDY(int ddy) {
        this->ddy = ddy;
		return this;
    };

	AbstractObject * AbstractObject::setWidth(int w) {
        this->w = w;
		return this;
    };

	AbstractObject * AbstractObject::setHeight(int h) {
        this->h = h;
		return this;
    };
}
