#include "SFML/Graphics.hpp"
#include "Window.h"

class Node
{
private:
    Window& gameWindow;
    //sprite
    sf::CircleShape shape;
    //text
    int belongsTo;
    int strength;
    float x;
    float y;
public:
    Node(Window & gameWindow, float const spriteSize, int const belongsTo, int const strength, float const x, float const y);
    void update();
    void render();
};
