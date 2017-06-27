#include <vector>
#include <abstract_object.h>

namespace factory {
    model::AbstractObject * getPlayer();
    std::vector<model::AbstractObject> getBackgroundLayers();
}