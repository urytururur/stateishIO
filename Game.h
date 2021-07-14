#pragma once

#include "Window.h"
#include <vector>
#include "Node.h"

class Game
{
private:
    Window gameWindow;
    std::vector<Node> nodes;
public:
    Game();
    void run();
private:
    void update();
    void render();
};
