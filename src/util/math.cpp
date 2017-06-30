namespace util {
    double clamp(double x, double a, double b) {
        if(x < a) return a;
        if(x > b) return b;
        return x;
    }
}