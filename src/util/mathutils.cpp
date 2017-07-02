#include <mathutils.h>
#include <cmath>

namespace util {

    double clamp(double x, double a, double b) {
        if(x < a) return a;
        if(x > b) return b;
        return x;
    };

    double max(double x, double y) {
        return x > y ? x : y;
    };

    double dist(double x1, double x2, double y1, double y2){
        return sqrt( pow(std::abs(x2-x1), 2) + pow(std::abs(y2-y1), 2) );
    };
}