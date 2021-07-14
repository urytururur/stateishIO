#include "Node.h"

Node::Node(Window & gameWindow, float const spriteSize, int const belongsTo, int const strength, float const x, float const y):
    gameWindow{gameWindow}, shape{spriteSize}, belongsTo{belongsTo}, strength{strength}, x{x}, y{y}
    {
        shape.setFillColor(sf::Color::Green);
    }

void Node::update()
{
    x++;
    y++;
	shape.setPosition(x, y);
}

void Node::render()
{
    gameWindow.getWindow().draw(shape);
}
