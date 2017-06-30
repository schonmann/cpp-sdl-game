#include <player.h>
#include <background.h>
#include <object_factory.h>
#include <abstract_object.h>

using namespace std;
using namespace model;

namespace factory {

    ObjectFactory::ObjectFactory() {
    }
    
    ObjectFactory::~ObjectFactory() {
    }

    ObjectFactory *ObjectFactory::getInstance() {
        static ObjectFactory *instance = new ObjectFactory();
        return instance;
    }

    Player * ObjectFactory::buildPlayer(){
        Player * player = new Player();
        return player;
    };

    Background * ObjectFactory::buildBackground(){

    };

    AbstractObject * ObjectFactory::buildObject(){

    };
}