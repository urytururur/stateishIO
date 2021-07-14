#include "Window.h"
#include "SFML/Graphics.hpp"
#include <string>

using namespace std;

Window::Window(int const width, int const height, string const& title):
    width{width}, height{height}, title{title}, window{sf::VideoMode(width, height), title}, unhandeledMouseClick{false}, mouseClickCoords{0.f, 0.f} {}

void Window::checkIfClosed()
{
    if(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    mouseClickCoords = {event.mouseButton.x, event.mouseButton.y};
                    unhandeledMouseClick = true;
                }
            }
        }
    }
}

void Window::clear()
{
    window.clear();
}

void Window::display()
{
    window.display();
}

sf::RenderWindow& Window::getWindow()
{
	return window;
}

bool Window::getUnhandeledMouseClick() const
{
    return unhandeledMouseClick;
}

pair<float, float> Window::getMouseClickCoords() const
{
    return mouseClickCoords;
}

void Window::setMouseClickHandeled()
{
    unhandeledMouseClick = false;
}