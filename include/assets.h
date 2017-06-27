#pragma once

#include <graphics.h>
#include <vector>

using namespace core;

namespace assets{
    class Assets {
        public:
            Assets();
            ~Assets();
            static Assets& Instance();
        private:
            SDLGraphics * graphics;
    };
}