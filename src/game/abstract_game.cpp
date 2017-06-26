#include <abstract_game.h>

namespace game {
    AbstractGame::AbstractGame() {
        this->running = true;
        this->paused = false;
    };
    
    void AbstractGame::setPaused(bool paused){
        this->paused = paused;
    };
    
    void AbstractGame::setRunning(bool running) {
        this->running = running;
    };
    
    bool AbstractGame::isRunning(){
        return this->running;
    };

    scene::AbstractScene * AbstractGame::currentScene() {
        return this->scene;
    };

    void AbstractGame::setScene(scene::AbstractScene * scene) {
        this->scene = scene;
    };
}