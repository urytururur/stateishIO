#include "Node.h"

Node::Node(Window & gameWindow, float const size, int const belongsTo, float const x, float const y, PlayerToColorMapper & playerToColorMapper):
    gameWindow{gameWindow}, shape{size}, belongsTo{belongsTo}, x{x}, y{y}, playerToColorMapper{playerToColorMapper}, size{size} {}

void Node::update()
{
    size += 1;
    if(size > 100) size = 100;
    shape.setOrigin(size, size);
    shape.setRadius(size);
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

float Node::getSize() const
{
	return size;
}

void Node::resetSizeToZero()
{
	size = 0;
}
