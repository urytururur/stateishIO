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
    bool unhandeledMouseClick;
    std::pair<float, float> mouseClickCoords;
public:
    Window(int const width, int const height, std::string const& title);
    void checkIfClosed();
    void clear();
    void display();
    bool getUnhandeledMouseClick() const;
    std::pair<float, float> getMouseClickCoords() const;
    void setMouseClickHandeled();

sf::RenderWindow& getWindow();
};
