#include "SFML/Graphics"
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
    Node(Window const& gameWindow, float const spriteSize, int const belongsTo, int const strength, int const x, int const y);
    void update();
    void render();
}
