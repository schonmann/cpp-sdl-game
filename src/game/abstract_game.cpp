#include <abstract_game.h>
#include <iostream>

using namespace std;

namespace game {

    AbstractGame::AbstractGame() {
        this->running = true;
        this->paused = false;
    };
    
    void AbstractGame::setPaused(bool paused) {
        this->paused = paused;
    };
    
    void AbstractGame::setRunning(bool running) {
        this->running = running;
    };
    
    bool AbstractGame::isRunning() {
        return this->running;
    };

    scene::AbstractScene * AbstractGame::currentScene() {
        return this->scene;
    };

    void AbstractGame::setScene(scene::AbstractScene * scene) {
        this->scene = scene;
    };

    void AbstractGame::init() {
        cout << "AbstractGame: Initialized!" << endl;
    };

    void AbstractGame::update(Uint32 dt, const Uint8 *input) {
        if(this->scene == NULL) cout << "NULL!" << endl;
        if(!this->paused) this->scene->update(dt, input);
    };

    void AbstractGame::draw(core::Renderer * renderer) {
        this->scene->draw(renderer);
    };
}