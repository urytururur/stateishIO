#include "PlayerToColorMapper.h"

PlayerToColorMapper::PlayerToColorMapper():
    mapper{ {0, sf::Color::Gray}, {1, sf::Color::Blue}, {2, sf::Color::Red} } {}

sf::Color getColor(int const playerId) const
{
    return mapper.find(1)->second;
}