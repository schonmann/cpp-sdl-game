#include <assert.h>
#include <graphics_config.h>
#include <graphics.h>

using namespace core;

SDL_Window * SDLGraphics::createWindow() {
    return SDL_CreateWindow(config::GAME_NAME,
        config::WINDOW_X, config::WINDOW_Y, 
        config::WINDOW_WIDTH, config::WINDOW_HEIGHT, 
        config::WINDOW_FLAGS);
};

SDL_Renderer * SDLGraphics::createRenderer(SDL_Window * window) {
    return SDL_CreateRenderer(window, -1, config::RENDERER_FLAGS);
};

void SDLGraphics::setScale(float x, float y) {
    SDL_RenderSetScale(this->renderer, x, y);
};

SDLGraphics::SDLGraphics() {
    
    int err = SDL_Init(config::SDL_INIT_FLAGS);

    assert(err == 0);

    this->window = this->createWindow();

    assert(this->window != NULL);

    this->renderer = this->createRenderer(this->window);

    assert(this->renderer != NULL);

    this->setScale(config::RENDERER_SCALE_X, config::RENDERER_SCALE_Y);
    
    int imgLoadSuccess = (IMG_Init(config::IMG_FLAGS) & config::IMG_FLAGS) == config::IMG_FLAGS;

    assert(imgLoadSuccess);
    
    this->batching = false;
};

SDLGraphics::~SDLGraphics() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
};

void SDLGraphics::startBatch() {
    assert(this->batching == false);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
    SDL_RenderClear(renderer);

    this->batching = true;
};

void SDLGraphics::batchRender(SDL_Texture * texture, SDL_Rect * src, SDL_Rect * dest) {
    assert(this->batching == true);
    SDL_RenderCopy(this->renderer, texture, src, dest);
};

void SDLGraphics::endBatch() {
    assert(this->batching == true);

    SDL_RenderPresent(renderer);
    
    this->batching = false;
};

SDLGraphics *SDLGraphics::getInstance() {
    static SDLGraphics *instance = new SDLGraphics();
    return instance;
};

SDL_Renderer * SDLGraphics::getRenderer() {
    return this->renderer;
};