#include <sound.h>
#include <sound_config.h>
#include <assets.h>
#include <SDL2/SDL_mixer.h>

namespace core{
    
    Sound &Sound::getInstance() {
        static Sound *instance = new Sound();
        return *instance;
    };

    void Sound::playMusic(char * path) {
        Mix_PlayMusic(this->music, 0);
    };

    void Sound::playChunk(char * path) {
        Mix_PlayChannel( -1, this->chunks[path], 0 );
    };

    Sound::Sound() {
        Mix_Init(soundConfig::MIXER_FLAGS);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
        this->music = Mix_LoadMUS(assets::MAIN_MUSIC);
        this->chunks[assets::JUMP_LOW_1] = Mix_LoadWAV(assets::JUMP_LOW_1);
        this->chunks[assets::JUMP_LOW_2] = Mix_LoadWAV(assets::JUMP_LOW_2);
        this->chunks[assets::JUMP_HIGH_1] = Mix_LoadWAV(assets::JUMP_HIGH_1);
        this->chunks[assets::JUMP_HIGH_2] = Mix_LoadWAV(assets::JUMP_HIGH_2);
    };

    Sound::~Sound() {
        Mix_FreeMusic(this->music);
    };
}