#pragma once

#include <vector>
#include <abstract_object.h>
#include <background_layer.h>

using namespace std;
using namespace core;

namespace model {
    class Background : public AbstractObject {
        private:
            AbstractObject * referential;
            vector<BackgroundLayer*> backgroundLayers;
            Background * addLayer(char * path, double dx);
        public:
            Background();
            ~Background();
            void draw(Renderer * renderer);
            void update(float dt);
            Background * setReferential(AbstractObject * referential);
    };
}
