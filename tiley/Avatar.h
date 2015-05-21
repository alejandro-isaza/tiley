//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#pragma once
#include <chrono>
#include <SFML/Graphics.hpp>
#include "Vector2D.h"


namespace mcw {

class Avatar : public sf::Drawable {
public:
    using Clock = std::chrono::high_resolution_clock;
    using Duration = std::chrono::milliseconds;
    using Texture = std::shared_ptr<sf::Texture>;

public:
    Avatar();

    /// Set the time duration of each animation frame in milliseconds
    void setFrameInterval(Duration interval) {
        _frameInterval = std::move(interval);
    }

    /// Set the walking speed in pixels per frame (a frame is 1/60th of a second)
    void setWalkingSpeed(float speed) {
        _walkingSpeed = speed;
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

    /// Execute the walk animation
    void walk();

    /// Stop animating and show the stand frame
    void stop();

    /// Perform a periodic update, call this inside the game loop
    void update();

protected:
    void load();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void stepAnimation();
    
private:
    float _walkingSpeed = 3; // px/frame

    // Animation state
    Duration _frameInterval{50};
    std::vector<Texture> _frames;
    Clock::time_point _lastAnimationStep;
    std::size_t _currentFrame = 0;
    bool _animating = false;

    sf::Sprite _sprite;
    float _width = 0;
    float _height = 0;
};

} // namespace mcws
