#include <abstract_game.h>
#include <renderer.h>
#include <play_scene.h>

namespace game {
    class Game : public AbstractGame {
        private:
            Game();
            ~Game();
        public:
            static Game *Instance();
            void init();
            // void update(float dt, const Uint8 *input);
            // void draw(core::Renderer * renderer);
    };
}