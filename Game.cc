#include "Game.h"
#include <iostream>
#include <SFML/System.hpp>
#include "NodeBattle.h"

using namespace std;

Game::Game():
    gameWindow{800, 800, "StateishIO"}, nodes{}, playerToColorMapper{}, nodeBattles{}
{
    nodes.push_back(Node{gameWindow, 40.f, 1, 100, 700, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 40.f, 2, 700, 100, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 40.f, 0, 400, 400, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 40.f, 0, 300, 300, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 40.f, 0, 500, 500, playerToColorMapper});

    nodeBattles.push_back(nodes.at(0), nodes.at(1));
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

void Game::update()
{
    for(Node & node : nodes)
        node.update();
    for(NodeBattle & nodeBattle : nodeBattles)
        nodeBattle.udate();
}

void Game::render()
{
    for(Node & node : nodes)
        node.render();
    /*
    for(NodeBattle & nodeBattle : nodeBattles)
        nodeBattle.render();
    */
}
