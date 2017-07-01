#pragma once
#include <SDL2/SDL_ttf.h>
#include <abstract_object.h>
#include <player.h>

namespace model {
    class ScoreBoard : public AbstractObject{
        public:
            ScoreBoard(Player * player);
            ~ScoreBoard();
            void setScore(int score);
            void update(float dt);
        private:
            int score;
            Player * player;
            TTF_Font *font;
            SDL_Color color;
    };
}
