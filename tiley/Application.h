//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"


namespace mcw {

/**
 `Application` manages the window and executes the event loop.
 */
class Application {
public:
    static constexpr int kWidth = 800;
    static constexpr int kHeight = 770;
    static const sf::Color kBackgroundColor;

public:
    Application();

    sf::RenderWindow& window() {
        return _window;
    }

    /// Executes the event loop, will not return until the application is ready to terminate
    void run();
    
protected:
    void createScene();
    void handleEvent(const sf::Event& event);
    void draw();
    
private:
    sf::RenderWindow _window;
    Scene _scene;
};

} // namespace mcw
