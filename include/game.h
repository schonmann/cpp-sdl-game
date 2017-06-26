#include <abstract_game.h>
#include <graphics.h>
#include <play_scene.h>

namespace game {
    class Game : public AbstractGame {
        private:
            Game();
            ~Game();
        public:
            static Game *Instance();
            void init();
            void update(Uint32 dt, const Uint8 *input);
            void draw(core::SDLGraphics * graphics);
    };
}