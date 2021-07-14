#include "Node.h"

Node::Node(Window & gameWindow, float const size, int const belongsTo, float const x, float const y, PlayerToColorMapper & playerToColorMapper):
    gameWindow{gameWindow}, shape{size}, belongsTo{belongsTo}, x{x}, y{y}, playerToColorMapper{playerToColorMapper}
    {
        shape.setFillColor(playerToColorMapper.getColor(belongsTo));
    }

void Node::update()
{
	shape.setPosition(x, y);
}

void Node::render()
{
    gameWindow.getWindow().draw(shape);
}
