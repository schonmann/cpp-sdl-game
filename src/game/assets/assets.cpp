#include <assets.h>
#include <vector>

namespace assets {

    Assets::Assets() {

    };

    Assets::~Assets() {

    };
    
    Assets& Assets::Instance() {
        static Assets * instance = new Assets();
        return *instance;
    };
}