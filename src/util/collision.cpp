#include <collision.h>
#include <mathutils.h>

namespace util {
    bool circularCollisionBetween(model::AbstractObject *a, model::AbstractObject *b) {
        double ax = a->getX() + a->getWidth()/2;
        double ay = a->getY() + a->getHeight()/2;
        double ar = a->getWidth()/2;

        double bx = b->getX() + b->getWidth()/2;
        double by = b->getY() + b->getHeight()/2;
        double br = b->getWidth()/2;

        return dist(ax,bx,ay,by) < ar + br;
    };
}