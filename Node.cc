#include "Node.h"

Node::Node(Window const& gameWindow, float const spriteSize, int const belongsTo, int const strength, int const x, int const y):
    GameWindow{window}, shape{spriteSize}, belongsTo{belongsTo}, strength{strength}, x{x}, y{y}
    {
        shape.setFillColor(sf::Color::Green);
    }

void Node::update()
{
    x++;
    y++;
}

void Node::render()
{
    gameWindow.window.draw(shape);
}