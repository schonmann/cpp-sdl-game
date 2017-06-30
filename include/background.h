#pragma once

#include <vector>
#include <abstract_object.h>

using namespace std;
using namespace core;

namespace model {
    class Background : public AbstractObject {
        private:
            AbstractObject * referential;
            vector<AbstractObject*> backgroundLayers;
            Background * addLayer(char * path, double dx);
        public:
            Background();
            ~Background();
            void draw(Renderer * renderer);
            void update(float dt);
            Background * setReferential(AbstractObject * referential);
    };
}
