//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#pragma once
#include <memory>

#include <SFML/Graphics.hpp>

#include "Scene.h"


namespace mcw {

class LevelBuilder {
public:
    static constexpr int kTileSize = 70;

public:
    explicit LevelBuilder(Scene& scene);
    void buildFromTextFile(const std::string& filePath);

protected:
    /// Add a tile at the given tile column and row with the given texture
    void addTile(int col, int row, std::shared_ptr<sf::Texture> texture);

private:
    Scene& _scene;
    std::shared_ptr<sf::Texture> _groundTexture;
    std::shared_ptr<sf::Texture> _waterTexture;
};

} // namespace mcw
