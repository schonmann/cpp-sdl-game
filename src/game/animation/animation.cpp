#include <animation.h>

using namespace core;

namespace animation {
    Animation::Animation(int rows, int cols, double w, double h) {
        this->currentFrame = 0;
        this->rows = rows;
        this->cols = cols;
        this->w = w;
        this->h = h;
    };

    Animation::Animation() {
        this->currentFrame = 0;
        this->rows = 1;
        this->cols = 1;
        this->w = 0;
        this->h = 0;
    };

    Animation::~Animation() {

    };

    void Animation::update(float dt) {
        this->currentFrame++;
        if(this->currentFrame >= rows*cols - 1) this->currentFrame = 0;
    };

    SDL_Rect * Animation::getSrcRect() {
        static SDL_Rect r;
        r.x = this->w * (this->currentFrame % this->cols);
        r.y = this->h * (this->currentFrame / this->cols);
        r.w = this->w;
        r.h = this->h;
        return &r;
    };
};