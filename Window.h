#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>


class Window
{
private:
    int width;
    int height;
    std::string title;
    sf::RenderWindow window;
public:
    Window(int const width, int const height, std::string const& title);
    void render();
};
