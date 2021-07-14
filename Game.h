#pragma once

#include "Window.h"
#include <vector>
#include <list>
#include "Node.h"
#include "PlayerToColorMapper.h"
#include "NodeBattle.h"

class Game
{
private:
    Window gameWindow;
    std::vector<Node> nodes;
    PlayerToColorMapper playerToColorMapper;
    std::list<NodeBattle> nodeBattles;
	std::list<Node*> selectedNodes;
public:
    Game();
    void run();
private:
    void update();
    void render();
	bool isCollision(std::pair<float, float> const mouseCoords, sf::FloatRect const& spriteCoords) const;
};
