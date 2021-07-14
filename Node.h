#include "SFML/Graphics.hpp"
#include "Window.h"
#include "PlayerToColorMapper.h"

class Node
{
private:
    Window& gameWindow;
    sf::CircleShape shape;
    int belongsTo;
    float size;
    float x;
    float y;
    PlayerToColorMapper& playerToColorMapper;
public:
    Node(Window & gameWindow, float const size, int const belongsTo,
     float const x, float const y, PlayerToColorMapper & playerToColorMapper);
    void update();
    void render();
    void shrink(int const amount);
    void grow(int const amount);
    int getBelongsTo();
    void setBelongsTo(int const playerId);
};
