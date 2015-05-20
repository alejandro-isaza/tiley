//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#pragma once
#include <SFML/Graphics.hpp>


namespace mcw {

class Application {
public:
    Application();

    sf::RenderWindow& window() {
        return _window;
    }

    void run();
    
protected:
    void handleEvent(const sf::Event& event);
    void draw();
    
private:
    sf::RenderWindow _window;
};

} // namespace mcw
