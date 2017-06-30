#include <iostream>
#include <SDL2/SDL_image.h>
#include <graphics.h>
#include <abstract_object.h>
#include <graphics_config.h>
#include <player_config.h>
#include <util.h>

using namespace core;
using namespace std;

namespace model {

    AbstractObject::AbstractObject() {
        this->sx = 1; 
        this->sy = 1;
        this->x = 0; this->bounds_x.set(0, graphicsConfig::WINDOW_WIDTH);
        this->y = 0; this->bounds_y.set(0, graphicsConfig::WINDOW_HEIGHT);
        this->dx = 0; this->bounds_dx.set(-playerConfig::MAX_DX, +playerConfig::MAX_DX);
        this->dy = 0; this->bounds_dy.set(-playerConfig::MAX_DY, +playerConfig::MAX_DY);
        this->ddx = 0; this->bounds_ddx.set(-playerConfig::MAX_DDX, +playerConfig::MAX_DDX);
        this->ddy = 0; this->bounds_ddy.set(-playerConfig::MAX_DDY, +playerConfig::MAX_DDY);
        this->w = 0;
        this->h = 0;
        this->texture = NULL;
    };

    AbstractObject::~AbstractObject() {

    };

    void AbstractObject::draw(Renderer *renderer) {
        renderer->batchRender(this->getTexture(),
            this->getSrcRect(),
            this->getDestRect());
    };
    
    //Apply physics behavior to all abstract objects, by default.
    //If any inherited object is not intended to follow these rules, override this.

    void AbstractObject::update(float dt) {
        this->updateDDX(dt);
        this->updateDDY(dt);
        this->updateDX(dt);
        this->updateDY(dt);
        this->updateX(dt);
        this->updateY(dt);
    };

    void AbstractObject::updateDDX(float dt) {
        this->ddx = util::clamp(this->ddx, bounds_ddx.getA(), bounds_ddx.getB());
    };

    void AbstractObject::updateDDY(float dt) {
        this->ddy = util::clamp(this->ddy, bounds_ddy.getA(), bounds_ddy.getB());
    };
 

    void AbstractObject::updateDX(float dt) {
        this->dx += this->ddx * dt;
        this->dx = util::clamp(this->dx, bounds_dx.getA(), bounds_dx.getB());
    };

    void AbstractObject::updateDY(float dt) {
        this->dy += this->ddy * dt;
        this->dy = util::clamp(this->dy, bounds_dy.getA(), bounds_dy.getB());
    };

    void AbstractObject::updateX(float dt) {
        this->x += round(this->dx * dt);
        this->x = util::clamp(this->x, bounds_x.getA(), bounds_x.getB());
    };

    void AbstractObject::updateY(float dt) {
        this->y += round(this->dy * dt);
        this->y = util::clamp(this->y, bounds_y.getA(), bounds_y.getB());
    };
    

    SDL_Texture * AbstractObject::getTexture() {
        return this->texture;
    };

    SDL_Rect * AbstractObject::getSrcRect() {
        return NULL;
    };

    SDL_Rect * AbstractObject::getDestRect() {
        static SDL_Rect destination;

        destination.x = this->getX();
        destination.y = this->getY();
        destination.w = this->getWidth();
        destination.h = this->getHeight();

        return &destination;
    };

    AbstractObject * AbstractObject::loadTexture(char * path) {
        SDL_Surface * surf = IMG_Load(path);
        SDL_Renderer * renderer = SDLGraphics::getInstance()->getRenderer();

        this->w = surf->w;
        this->h = surf->h;

        this->texture = SDL_CreateTextureFromSurface(renderer, surf);

        SDL_FreeSurface(surf);

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

    int AbstractObject::getX() {
        return this->x;
    };

    AbstractObject * AbstractObject::addX(int dx) {
        this->x += dx;
        return this;
    };

    AbstractObject * AbstractObject::setS(double s) {
        this->sx = s;
        this->sy = s;
        return this;
    };

    AbstractObject * AbstractObject::setSX(double sx) {
        this->sx = sx;
        return this;
    };

    double AbstractObject::getSX() {
        return this->sx;
    };
    
    AbstractObject * AbstractObject::setSY(double sy) {
        this->sy = sy;
        return this;
    };
    
    double AbstractObject::getSY() {
        return this->sy;
    };

	AbstractObject * AbstractObject::setY(int y) {
        this->y = y;
		return this;
    };
    
    int AbstractObject::getY() {
        return this->y;
    };

	AbstractObject * AbstractObject::setDX(double dx) {
        this->dx = dx;
		return this;
    };

    double AbstractObject::getDX() {
        return this->dx;
    };

	AbstractObject * AbstractObject::setDY(double dy) {
        this->dy = dy;
		return this;
    };
	
	AbstractObject * AbstractObject::setDDX(double ddx) {
        this->ddx = ddx;
		return this;
    };

	AbstractObject * AbstractObject::setDDY(double ddy) {
        this->ddy = ddy;
		return this;
    };

	AbstractObject * AbstractObject::setWidth(int w) {
        this->w = w * this->sx;
		return this;
    };

    int AbstractObject::getWidth() {
        return this->w * this->sx;
    };

	AbstractObject * AbstractObject::setHeight(int h) {
        this->h = h * this->sy;
		return this;
    };

    int AbstractObject::getHeight() {
        return this->h * this->sy;
    };
}
