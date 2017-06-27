#pragma once

#include <abstract_object.h>
#include <string>
#include <map>
#include <graphics.h>


namespace scene{
    class AbstractScene{
        protected:
            std::map<std::string, model::AbstractObject> objects;
        public:
            void draw(core::Renderer * renderer);
            void update(Uint32 dt, const Uint8 * input);
    };
}