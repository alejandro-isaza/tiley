//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "Scene.h"

namespace mcw {

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto& tile : _tiles) {
        target.draw(*tile, states);
    }
}

} // namespace mcw
