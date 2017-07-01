#include <SDL2/SDL.h>
#include <abstract_object.h>

using namespace model;

namespace animation{
    class Animation{
        public:
            Animation(AbstractObject * object);
            ~Animation();
            void update(float dt);
        private:
            AbstractObject * object;
            SDL_Rect * clips;
            int currentFrame;
    };
}