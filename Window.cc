#include "Window.h"
#include "SFML/Graphics.hpp"
#include <string>

using namespace std;

Window::Window(int const width, int const height, string const& title):
    width{width}, height{height}, title{title}, window{sf::VideoMode(width, height), title} {}

void Window::render()
{
    if(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}

