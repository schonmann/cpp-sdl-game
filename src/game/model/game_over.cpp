#include <game_over.h>
#include <SDL2/SDL_ttf.h>
#include <assets.h>
#include <assert.h>
#include <graphics_config.h>
#include <math.h>

namespace model {
    
    GameOver::GameOver() {
        int ret = TTF_Init();

        assert(ret != -1);
        
        this->font = TTF_OpenFont(assets::FONT_ARCADE, 40);

        assert(this->font != NULL);

        this->color.r = 255;
        this->color.g = 80;
        this->color.b = 80;
    };

    GameOver::~GameOver() {

    };

    void GameOver::update(float dt) {
        SDL_Surface * message = TTF_RenderText_Solid(this->font, "GAME OVER!", this->color);

        this->loadTexture(message, 1, 1);

        double posX = graphicsConfig::WINDOW_WIDTH/2 - this->getWidth()/2;
        double posY = graphicsConfig::WINDOW_HEIGHT/2 - this->getHeight()/2;

        this->setX(posX)->setY(posY);
    };
}