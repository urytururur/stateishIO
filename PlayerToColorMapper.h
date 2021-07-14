#pragma once

#include "SFML/Graphics.hpp"
#include <unordered_map>

class PlayerToColorMapper
{
private:
    std::unordered_map<int, sf::Color> mapper;
public:
    PlayerToColorMapper();
	sf::Color getColor(int const playerId) const;
};
