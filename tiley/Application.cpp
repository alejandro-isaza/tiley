//  Copyright (c) 2015 Alejandro Isaza. All rights reserved.

#include "Application.h"

#include <memory>

#include "LevelBuilder.h"


namespace mcw {

const auto Application::kBackgroundColor = sf::Color{63, 127, 255, 255};

Application::Application() {
    _window.create(sf::VideoMode(kWidth, kHeight), "tiley");
    _window.setFramerateLimit(60);
    createScene();
}

void Application::createScene() {
    LevelBuilder builder(_scene);
    builder.buildFromTextFile("data/level0.txt");
}

void Application::run() {
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            handleEvent(event);
        }

        _scene.update();
        draw();
    }
}

void Application::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed)
        _window.close();
}

void Application::draw() {
    _window.clear(kBackgroundColor);
    _window.draw(_scene);
    _window.display();
}

} // namespace mcw
