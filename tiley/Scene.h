//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#pragma once
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Tile.h"


namespace mcw {

class Scene : public sf::Drawable {
public:
    Scene() = default;

    void addTile(std::unique_ptr<Tile> tile) {
        _tiles.push_back(std::move(tile));
    }

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    std::vector<std::unique_ptr<Tile>> _tiles;
};

} // namespace mcw
