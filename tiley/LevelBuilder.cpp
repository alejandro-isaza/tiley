//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "LevelBuilder.h"

namespace mcw {

LevelBuilder::LevelBuilder(Scene& scene) : _scene(scene) {
    _groundTexture = std::make_shared<sf::Texture>();
    if (!_groundTexture->loadFromFile("assets/ground.png"))
        throw std::runtime_error("Failed to load ground texture");

    _waterTexture = std::make_shared<sf::Texture>();
    if (!_waterTexture->loadFromFile("assets/water.png"))
        throw std::runtime_error("Failed to load water texture");
}

void LevelBuilder::buildLevel1() {
    static const auto kLevelRows = 12;

    auto i = 0;
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _waterTexture);
    addTile(i++, kLevelRows - 1, _waterTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
    addTile(i++, kLevelRows - 1, _groundTexture);
}

void LevelBuilder::addTile(int x, int y, std::shared_ptr<sf::Texture> texture) {
    auto tile = std::make_unique<Tile>(std::move(texture));
    tile->setLocation(Vector2D(x * kTileSize, y * kTileSize));
    _scene.addTile(std::move(tile));
}

} // namespace mcw
