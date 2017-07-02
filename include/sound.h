#pragma once

#include <SDL2/SDL_mixer.h>
#include <map>

namespace core {
    class Sound {
        public:
            static Sound& getInstance();
            void playMusic(char * path);
            void playChunk(char * path);
        private:
            Mix_Music * music;
            std::map<char*, Mix_Chunk*> chunks;  

            Sound();
            ~Sound();
    };
}