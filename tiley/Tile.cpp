//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "Tile.h"

namespace mcw {

Tile::Tile() {
    setLocation(Vector2D{});
}

Tile::Tile(std::shared_ptr<sf::Texture> texture) : _texture(texture), _sprite(*texture) {
    setLocation(Vector2D{});
}

Vector2D Tile::location() const {
    const auto& origin = _sprite.getOrigin();
    return {-origin.x, static_cast<float>(_texture->getSize().y) - origin.y};
}

void Tile::setLocation(const Vector2D& location) {
    _sprite.setOrigin(-location.x(), -location.y() + static_cast<float>(_texture->getSize().y));
}

bool Tile::collidesTop() const {
    return _collisionBitset.test(static_cast<std::size_t>(CollisionBit::Top));
}

void Tile::setCollideTop(bool v) {
    _collisionBitset.set(static_cast<std::size_t>(CollisionBit::Top), v);
}

bool Tile::collidesLeft() const {
    return _collisionBitset.test(static_cast<std::size_t>(CollisionBit::Left));
}

void Tile::setCollideLeft(bool v) {
    _collisionBitset.set(static_cast<std::size_t>(CollisionBit::Left), v);
}

bool Tile::collidesBottom() const {
    return _collisionBitset.test(static_cast<std::size_t>(CollisionBit::Bottom));
}

void Tile::setCollideBottom(bool v) {
    _collisionBitset.set(static_cast<std::size_t>(CollisionBit::Bottom), v);
}

bool Tile::collidesRight() const {
    return _collisionBitset.test(static_cast<std::size_t>(CollisionBit::Right));
}

void Tile::setCollideRight(bool v) {
    _collisionBitset.set(static_cast<std::size_t>(CollisionBit::Right), v);
}

}
