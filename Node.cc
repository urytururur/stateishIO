#include "Node.h"

Node::Node(Window & gameWindow, float const size, int const belongsTo, float const x, float const y, PlayerToColorMapper & playerToColorMapper):
    gameWindow{gameWindow}, shape{size}, belongsTo{belongsTo}, x{x}, y{y}, playerToColorMapper{playerToColorMapper}, size{size}, selected{false} {}

void Node::update()
{
    size += 1;
    if(size > 60) size = 60;
    shape.setOrigin(size, size);
    shape.setRadius(size);
	shape.setPosition(x, y);

	if(selected)
	{
		shape.setFillColor(sf::Color::Cyan);
	}
	else
	{
		shape.setFillColor(playerToColorMapper.getColor(belongsTo));
	}
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

sf::FloatRect Node::getBounds() const
{
	return shape.getGlobalBounds();
}

void Node::setSelected(bool const value)
{
	selected = value;
}
