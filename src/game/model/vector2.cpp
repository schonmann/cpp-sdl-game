#include <vector2.h>

namespace model {
    Vector2::Vector2(double a, double b) {
        this->a = a;
        this->b = b;
    };

    Vector2::Vector2() {
        Vector2(0,0);
    };

    Vector2::~Vector2() {
        
    };

    void Vector2::set(double a, double b) {
        this->a = a;
        this->b = b;
    };

    double Vector2::getA() {
        return this->a;
    };

    double Vector2::getB() {
        return this->b;
    };
}