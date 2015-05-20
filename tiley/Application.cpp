//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "Application.h"


namespace mcw {

Application::Application() {
    _window.create(sf::VideoMode(800, 600), "tiley");
}

void Application::run() {
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            handleEvent(event);
        }

        draw();
    }
}

void Application::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed)
        _window.close();
}

void Application::draw() {
    _window.clear();
    _window.display();
}

} // namespace mcw
