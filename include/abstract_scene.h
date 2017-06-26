#pragma once

#include <game_object.h>
#include <string>
#include <map>
#include <graphics.h>


namespace scene{
    class AbstractScene{
        protected:
            std::map<std::string, model::GameObject> objects;
        public:
            void draw(core::SDLGraphics *graphics);
            void update(Uint32 dt, const Uint8 * input);
    };
}