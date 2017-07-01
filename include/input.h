#pragma once


namespace core {
    class Input{
        public:
            const Uint8 * state;
            static Input &getInstance();
            bool isPressed(char key);
        private:
            Input();
            ~Input();
    };
}