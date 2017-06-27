#include <abstract_object.h>

namespace model {
    AbstractObject::AbstractObject() {
    };

    AbstractObject::~AbstractObject() {
    };

    void AbstractObject::draw(core::Renderer *renderer) {
        //...
    };

    void AbstractObject::update(Uint32 dt, const Uint8 * input) {
        //...
    };


    SDL_Texture * AbstractObject::getTexture(){
        return this->texture;
    };

    SDL_Rect * AbstractObject::getSrcRect(){
        return NULL;
    };

    SDL_Rect * AbstractObject::getDestRect(){
        static SDL_Rect destination;
        destination.x = this->x;
        destination.y = this->y;
        destination.w = this->w;
        destination.h = this->h;
        return &destination;
    };

}