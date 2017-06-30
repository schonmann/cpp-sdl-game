namespace model {
    class Vector2 {
        private:
            double a;
            double b;
        public:
            Vector2(double a, double b);
            Vector2();
            ~Vector2();
            void set(double a, double b);
            double getA();
            double getB();
    };
}