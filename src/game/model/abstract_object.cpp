#include <iostream>
#include <SDL2/SDL_image.h>
#include <graphics.h>
#include <abstract_object.h>
#include <graphics_config.h>
#include <player_config.h>
#include <mathutils.h>
#include <limits>

using namespace core;
using namespace std;
using namespace animation;

namespace model {

    AbstractObject::AbstractObject() {
        this->sx = 1; 
        this->sy = 1;
        this->x = 0; this->bounds_x.set(-numeric_limits<double>::max(), numeric_limits<double>::max());
        this->y = 0; this->bounds_y.set(-numeric_limits<double>::max(), numeric_limits<double>::max());
        this->dx = 0; this->bounds_dx.set(-numeric_limits<double>::max(), numeric_limits<double>::max());
        this->dy = 0; this->bounds_dy.set(-numeric_limits<double>::max(), numeric_limits<double>::max());
        this->ddx = 0; this->bounds_ddx.set(-numeric_limits<double>::max(), numeric_limits<double>::max());
        this->ddy = 0; this->bounds_ddy.set(-numeric_limits<double>::max(), numeric_limits<double>::max());
        this->w = 0;
        this->h = 0;
        this->texture = NULL;
        this->animation = new Animation();
    };

    AbstractObject::~AbstractObject() {
        SDL_DestroyTexture(this->texture);
        delete this->animation;
    };

    void AbstractObject::draw(Renderer *renderer) {
        renderer->batchRender(this->getTexture(),
            this->animation->getSrcRect(),
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

        this->animation->update(dt);
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
        this->x += this->dx * dt;
        this->x = util::clamp(this->x, bounds_x.getA(), bounds_x.getB());
    };

    void AbstractObject::updateY(float dt) {
        this->y += this->dy * dt;
        this->y = util::clamp(this->y, bounds_y.getA(), bounds_y.getB());
    };

    SDL_Texture * AbstractObject::getTexture() {
        return this->texture;
    };

    SDL_Rect * AbstractObject::getSrcRect() {
        return this->animation->getSrcRect();
    };

    SDL_Rect * AbstractObject::getDestRect() {
        static SDL_Rect destination;

        destination.x = this->getX();
        destination.y = this->getY();
        destination.w = this->getWidth();
        destination.h = this->getHeight();

        return &destination;
    };

    AbstractObject * AbstractObject::loadTexture(char * path, int rows, int cols) {
        
        SDL_Surface * surf = IMG_Load(path);
        
        this->loadTexture(surf, rows, cols);
        
        return this;
    };

    AbstractObject * AbstractObject::loadTexture(SDL_Surface * surface, int rows, int cols) {
        
        SDL_Renderer * renderer = SDLGraphics::getInstance()->getRenderer();

        this->w = surface->w/rows;
        this->h = surface->h/cols;

        this->texture = SDL_CreateTextureFromSurface(renderer, surface);
        this->animation = new Animation(rows, cols, this->w, this->h);

        SDL_FreeSurface(surface);

		return this;
    };

    int AbstractObject::getLayer() {
        return this->layer;
    };

    AbstractObject * AbstractObject::setLayer(int layer) {
        this->layer = layer;
		return this;
    };

	AbstractObject * AbstractObject::setX(double x) {
        this->x = x;
		return this;
    };

    double AbstractObject::getX() {
        return this->x;
    };

    AbstractObject * AbstractObject::addX(double dx) {
        this->x += round(dx);
        return this;
    };

    AbstractObject * AbstractObject::addDX(double ddx){
        this->dx += ddx;
        return this;
    }

    AbstractObject * AbstractObject::addDDX(double dddx){
        this->ddx += dddx;
        return this;
    }

    AbstractObject * AbstractObject::addY(double dy) {
        this->y += round(dy);
        return this;
    };

    AbstractObject * AbstractObject::addDY(double ddy){
        this->dy += ddy;
        return this;
    }

    AbstractObject * AbstractObject::addDDY(double dddy){
        this->ddy += dddy;
        return this;
    }
    
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

	AbstractObject * AbstractObject::setY(double y) {
        this->y = y;
		return this;
    };
    
    double AbstractObject::getY() {
        return this->y;
    };

	AbstractObject * AbstractObject::setDX(double dx) {
        this->dx = dx;
		return this;
    };

    double AbstractObject::getDX() {
        return this->dx;
    };

    AbstractObject * AbstractObject::setDDX(double ddx) {
        this->ddx = ddx;
        return this;
    };

    double AbstractObject::getDDX() {
        return this->ddx;
    };

	AbstractObject * AbstractObject::setDY(double dy) {
        this->dy = dy;
		return this;
    };
    
    double AbstractObject::getDY() {
        return this->dy;
    };

	AbstractObject * AbstractObject::setDDY(double ddy) {
        this->ddy = ddy;
		return this;
    };

    double AbstractObject::getDDY() {
        return this->ddy;
    };

	AbstractObject * AbstractObject::setWidth(double w) {
        this->w = w * this->sx;
		return this;
    };\

    double AbstractObject::getWidth() {
        return this->w * this->sx;
    };

	AbstractObject * AbstractObject::setHeight(double h) {
        this->h = h * this->sy;
		return this;
    };

    double AbstractObject::getHeight() {
        return this->h * this->sy;
    };

    AbstractObject * AbstractObject::setBoundsX(double a, double b){
        this->bounds_x.set(a,b);
        return this;
    };

    AbstractObject * AbstractObject::setBoundsY(double a, double b){
        this->bounds_y.set(a,b);
        return this;
    };

    Vector2 AbstractObject::getBoundsX(){
        return this->bounds_x;
    };

    Vector2 AbstractObject::getBoundsY() {
        return this->bounds_y;
    };

    AbstractObject * AbstractObject::setBoundsDX(double a, double b){
        this->bounds_dx.set(a,b);
        return this;
    };
    
    AbstractObject * AbstractObject::setBoundsDY(double a, double b){
        this->bounds_dy.set(a,b);
        return this;
    };
    
    Vector2 AbstractObject::getBoundsDX(){
        return this->bounds_dx;
    };
    
    Vector2 AbstractObject::getBoundsDY() {
        return this->bounds_dy;
    };

    Animation *AbstractObject::getAnimation() {
        return this->animation;
    };
}
