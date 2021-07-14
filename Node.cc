#include "Node.h"

Node::Node(Window & gameWindow, float const size, int const belongsTo, float const x, float const y, PlayerToColorMapper & playerToColorMapper):
    gameWindow{gameWindow}, shape{size}, belongsTo{belongsTo}, x{x}, y{y}, playerToColorMapper{playerToColorMapper} {}

void Node::update()
{
    shape.setSize(size);
	shape.setPosition(x, y);
    shape.setFillColor(playerToColorMapper.getColor(belongsTo));
}

void Node::render()
{
    gameWindow.getWindow().draw(shape);
}

void Node::shrink(int const amount)
{
    size -= amount;
}

void Node::grow(int const amount)
{
    size += amount;
}

int Node::getBelongsTo()
{
    return belongsTo;
}

void Node::setBelongsTo(int const playerId)
{
    belongsTo = playerId;
}