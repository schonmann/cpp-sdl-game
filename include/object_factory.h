#include <vector>
#include <abstract_object.h>

namespace factory {
    class ObjectFactory {
        public:
            static ObjectFactory * getInstance();
            Player * buildPlayer();
            Background * buildBackground();
            AbstractObject * buildObject();
        private:
            ObjectFactory();
            ~ObjectFactory();
    };
}