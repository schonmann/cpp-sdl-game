#include <abstract_scene.h>

namespace scene{
    class AbstractScene{
        protected:
            map<string, model::GameObject> objects;
        public:
        
            void draw(core::SDLGraphics *graphics) {

            };

            void update(Uint32 dt, const Uint8 * input) {

            };
    };
}