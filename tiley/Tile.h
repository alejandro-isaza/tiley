//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#pragma once
#include <bitset>
#include <string>

#include <SFML/Graphics.hpp>
#include "Vector2D.h"


namespace mcw {

class Tile : public sf::Drawable {
public:
    enum class CollisionBit {
        Top,
        Left,
        Bottom,
        Right
    };

public:
    Tile();
    explicit Tile(std::shared_ptr<sf::Texture> texture);

    /// Get the tile's texture
    const std::shared_ptr<sf::Texture>& texture() const {
        return _texture;
    }

    /// Set the texture to use for this tile, the tile keeps a strong reference to its texture
    void setTexture(std::shared_ptr<sf::Texture> texture) {
        _texture = std::move(texture);
        _sprite.setTexture(*_texture);
    }

    /**
     Get the location of the bottom left corner of the tile.
     
     Tile coordinates start at the top left corner and increase left and down.
     */
    Vector2D location() const;

    /**
     Set the location of the bottom left corner of the tile.

     Tile coordinates start at the top left corner and increase left and down.
     */
    void setLocation(const Vector2D& location);

    bool collidesTop() const;
    void setCollideTop(bool v = true);
    bool collidesLeft() const;
    void setCollideLeft(bool v = true);
    bool collidesBottom() const;
    void setCollideBottom(bool v = true);
    bool collidesRight() const;
    void setCollideRight(bool v = true);

    int zOrder() const {
        return _zOrder;
    }
    void setZOrder(int order) {
        _zOrder = order;
    }
    
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }

private:
    std::shared_ptr<sf::Texture> _texture;
    sf::Sprite _sprite;
    std::bitset<4> _collisionBitset = 0b1111;
    int _zOrder = 0;
};

} // namespace mcw
