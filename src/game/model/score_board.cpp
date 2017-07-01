#include <score_board.h>
#include <SDL2/SDL_ttf.h>
#include <assets.h>
#include <assert.h>
#include <graphics_config.h>

namespace model {
    
    ScoreBoard::ScoreBoard(Player * player) {
        this->player = player;

        int ret = TTF_Init();

        assert(ret != -1);
        
        this->font = TTF_OpenFont(assets::FONT_ARCADE, 30);

        assert(this->font != NULL);

        this->color.r = 255;
        this->color.g = 255;
        this->color.b = 255;

        this->score = 0;
    };

    ScoreBoard::~ScoreBoard() {
    };

    void ScoreBoard::setScore(int score) {
        this->score = score; 
    };

    void ScoreBoard::update(float dt) {
        this->setScore(this->player->getScore());
        
        char str[100];
        sprintf(str, "score   %d", this->score);

        SDL_Surface * message = TTF_RenderText_Solid(this->font, str, this->color);
        
        this->loadTexture(message, 1, 1);
        
        double posX = graphicsConfig::WINDOW_WIDTH/2 - this->getWidth()/2;
        double posY = this->getHeight();
        
        this->setX(posX)->setY(posY);
    };
}