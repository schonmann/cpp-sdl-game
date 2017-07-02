#include <menu.h>
#include <SDL2/SDL_ttf.h>
#include <assets.h>
#include <assert.h>
#include <graphics_config.h>
#include <math.h>

namespace model {
    
    Menu::Menu() {
        int ret = TTF_Init();

        assert(ret != -1);
        
        this->font = TTF_OpenFont(assets::FONT_ARCADE, 40);

        assert(this->font != NULL);

        this->color.r = 255;
        this->color.g = 255;
        this->color.b = 255;
    };

    Menu::~Menu() {

    };

    void Menu::update(float dt) {
        SDL_Surface * message = TTF_RenderText_Solid(this->font, "Use  W A S D  to  fly!", this->color);

        this->loadTexture(message, 1, 1);

        double posX = graphicsConfig::WINDOW_WIDTH/2 - this->getWidth()/2;
        double posY = graphicsConfig::WINDOW_HEIGHT/2 - this->getHeight()/2;

        this->setX(posX)->setY(posY);
        this->setS(1.5 + sin(SDL_GetTicks()/100.0)/100.0 );
    };
}