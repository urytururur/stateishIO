#include "Game.h"
#include <iostream>
#include <SFML/System.hpp>

using namespace std;

Game::Game():
    gameWindow{800, 800, "StateishIO"}, nodes{}
{
    nodes.push_back(Node{gameWindow, 100.f, 100.f, 1, 10, 400, 400});
}

void Game::run()
{
    while(true)
    {
        gameWindow.checkIfClosed();

        update();

        gameWindow.clear();
        render();
        gameWindow.display();

        sf::sleep(sf::milliseconds(16));
    }
}

void update()
{
    for(Node & node : nodes)
    {
        node.update();
    }
}

void render()
{
    for(Node & node : nodes)
    {
        node.render();
    }
}