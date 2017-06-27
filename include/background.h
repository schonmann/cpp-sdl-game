#pragma once

#include <vector>
#include <abstract_object.h>

using namespace std;
using namespace core;

namespace model {
    class Background : public AbstractObject {
        private:
            vector<AbstractObject*> backgroundLayers;
            void addLayer(AbstractObject *bgLayer);
        public:
            Background();
            ~Background();
            void draw(Renderer * renderer);
            void update(Uint32 dt, const Uint8 * input);
    };
}