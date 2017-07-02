#include <enemy.h>
#include <enemy_config.h>
#include <graphics_config.h>
#include <player_config.h>
#include <player.h>
#include <assets.h>
#include <input.h>
#include <sound.h>
#include <iostream>
#include <time.h>
#include <mathutils.h>
#include <math.h>

using namespace core;

namespace model {
    
    Enemy::Enemy(AbstractObject * player, bool lazy) {
        this->referential = player;
        this->lazy = lazy;
        this->loadTexture(assets::ENEMY, 1, 1)->setSX(2)->setSY(2);
        this->reset();
    };

    Enemy::~Enemy() {

    };

    void Enemy::update(float dt) {
        AbstractObject::update(dt);

        double playerVelocity = this->referential->getDX();
        this->addX(-playerVelocity*dt);
    
        if(this->lazy) this->setDY(0.5*sin(SDL_GetTicks() / 100.0));

        if(this->getX() <= -this->getWidth()) {
            this->reset();
        }

        this->getAnimation()->update(dt);
    };

    void Enemy::reset() {
        int initialX = enemyConfig::INITIAL_X;
        int initialY = util::clamp(rand() % (11*graphicsConfig::WINDOW_HEIGHT/12 - graphicsConfig::WINDOW_HEIGHT/12), 
            graphicsConfig::WINDOW_HEIGHT/12, 11*graphicsConfig::WINDOW_HEIGHT/12);

        this->setX(initialX)->setY(initialY);
        if(!this->lazy) this->setDDX(-0.0010)->setDX(0);
    };

    Enemy * Enemy::setLazy(bool lazy) {
        this->lazy = lazy;
    };
} 
