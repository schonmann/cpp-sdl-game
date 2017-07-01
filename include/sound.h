#pragma once

#include <SDL2/SDL_mixer.h>

namespace core {
    class Sound {
        public:
            static Sound& getInstance();
            void startPlaying(char * path);
        private:
            Mix_Music * music;
            Sound();
            ~Sound();
    };
}