#pragma once


namespace input {
    class Input{
        public:
            const Uint8 * state;
            static Input &getInstance();
            bool isPressed(Uint8 key);
        private:
            Input();
            ~Input();
    };
}