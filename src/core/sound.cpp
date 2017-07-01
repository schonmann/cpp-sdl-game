#include <sound.h>
#include <sound_config.h>

#include <SDL2/SDL_mixer.h>

namespace core{
    Sound &Sound::getInstance() {
        static Sound *instance = new Sound();
        return *instance;
    };

    void Sound::startPlaying(char * path) {
        this->music = Mix_LoadMUS(path);
        Mix_PlayMusic(this->music, 0);
    };

    Sound::Sound() {
        Mix_Init(soundConfig::MIXER_FLAGS);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    };

    Sound::~Sound() {
        Mix_FreeMusic(this->music);
    };
}