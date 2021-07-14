#pragma once

#include "Window.h"
#include <vector>

class Game
{
private:
    Window gameWindow;
    vector<Node> nodes;
public:
    Game();
    void run();
private:
    void update();
    void render();
};
