//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "Scene.h"

namespace mcw {

void Scene::update() {
    _avatar.update();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto& tile : _tiles) {
        target.draw(*tile, states);
    }
    target.draw(_avatar, states);
}

} // namespace mcw
