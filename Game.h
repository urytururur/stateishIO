#pragma once

#include "Window.h"
#include <vector>
#include "Node.h"
#include "PlayerToColorMapper.h"

class Game
{
private:
    Window gameWindow;
    std::vector<Node> nodes;
    PlayerToColorMapper playerToColorMapper;
    std::vector<NodeBattle> nodeBattles;
public:
    Game();
    void run();
private:
    void update();
    void render();
};
