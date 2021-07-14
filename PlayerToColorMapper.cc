#include "PlayerToColorMapper.h"

PlayerToColorMapper::PlayerToColorMapper():
    mapper{ {0, sf::Color::White}, {1, sf::Color::Blue}, {2, sf::Color::Red} } {}

sf::Color PlayerToColorMapper::getColor(int const playerId) const
{
    return mapper.find(playerId)->second;
}
