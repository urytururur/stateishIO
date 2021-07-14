#include "SFML/Graphics.hpp"
#include <unordered_map>

class PlayerToColorMapper
{
private:
    std::unordered_map<int, sf::Color> mapper;
public:
    PlayerToColorMapper();
};