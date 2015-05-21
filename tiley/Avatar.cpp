//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "Avatar.h"

#include <iomanip>
#include <sstream>


namespace mcw {

Avatar::Avatar() {
    setLocation(Vector2D{});
    load();
}

Vector2D Avatar::location() const {
    const auto& origin = _sprite.getOrigin();
    return {-origin.x, _height - origin.y};
}

void Avatar::setLocation(const Vector2D& location) {
    _sprite.setOrigin(-location.x(), -location.y() + _height);
}

void Avatar::load() {
    for (auto i = 1; i <= 10; i += 1) {
        std::stringstream path;
        path << "assets/character/walk/walk" << std::setfill('0') << std::setw(4) << i << ".png";

        auto texture = std::make_shared<sf::Texture>();
        texture->loadFromFile(path.str());
        _frames.push_back(std::move(texture));
    }
    _sprite.setTexture(*_frames[_currentFrame]);

    // Save the size
    const auto size = _frames.front()->getSize();
    _width = size.x;
    _height = size.y;
}

void Avatar::walk() {
    _animating = true;
}

void Avatar::stop() {
    _animating = false;
    _sprite.setTexture(*_frames.front());
}

void Avatar::update() {
    if (_frames.empty())
        return;

    if (_animating)
        stepAnimation();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _sprite.setTextureRect(sf::IntRect(_width, 0, -_width, _height));
        _sprite.move(-_walkingSpeed, 0);
        walk();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _sprite.setTextureRect(sf::IntRect(0, 0, _width, _height));
        _sprite.move(_walkingSpeed, 0);
        walk();
    } else {
        stop();
    }
}

void Avatar::stepAnimation() {
    auto now = Clock::now();
    auto interval = std::chrono::duration_cast<Duration>(now - _lastAnimationStep);
    if (interval < _frameInterval)
        return;

    _currentFrame += 1;
    if (_currentFrame >= _frames.size())
        _currentFrame = 0;

    _sprite.setTexture(*_frames[_currentFrame]);
    _lastAnimationStep = now;
}

void Avatar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

} // namespace mcw
