//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "LevelBuilder.h"

#include <iostream>
#include <fstream>


namespace mcw {

LevelBuilder::LevelBuilder(Scene& scene) : _scene(scene) {
    _groundTexture = std::make_shared<sf::Texture>();
    if (!_groundTexture->loadFromFile("assets/ground.png"))
        throw std::runtime_error("Failed to load ground texture");

    _waterTexture = std::make_shared<sf::Texture>();
    if (!_waterTexture->loadFromFile("assets/water.png"))
        throw std::runtime_error("Failed to load water texture");
}

void LevelBuilder::buildFromTextFile(const std::string& filePath) {
    // Build texture map
    std::map<char, std::shared_ptr<sf::Texture>> textureMap;
    textureMap.insert({'G', _groundTexture});
    textureMap.insert({'W', _waterTexture});

    // Open file for reading
    std::ifstream is(filePath.c_str());
    std::string line;

    // Read by lines and match characters to textures
    int row = 0;
    while (std::getline(is, line)) {
        int col = 0;
        for (auto c : line) {
            auto texture = textureMap[c];
            if (texture)
                addTile(col, row, std::move(texture));
            col += 1;
        }
        row += 1;
    }
}

void LevelBuilder::addTile(int col, int row, std::shared_ptr<sf::Texture> texture) {
    auto tile = std::make_unique<Tile>(std::move(texture));
    tile->setLocation(Vector2D(col * kTileSize, row * kTileSize));
    _scene.addTile(std::move(tile));
}

} // namespace mcw
