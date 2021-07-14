#include "Game.h"
#include <iostream>
#include <SFML/System.hpp>
#include "NodeBattle.h"

using namespace std;

Game::Game():
    gameWindow{800, 800, "StateishIO"}, nodes{}, playerToColorMapper{}, nodeBattles{}
{
    nodes.push_back(Node{gameWindow, 40.f, 1, 100, 700, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 60.f, 1, 100, 100, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 30.f, 2, 700, 100, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 40.f, 0, 400, 400, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 40.f, 0, 300, 300, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 40.f, 0, 500, 500, playerToColorMapper});

    nodeBattles.push_back({nodes.at(0), nodes.at(2)});
	nodeBattles.push_back({nodes.at(1), nodes.at(2)});
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

        sf::sleep(sf::milliseconds(256));
    }
}

void Game::update()
{
    //rensa ur alla som inte längre är våra
    for(list<Node>::iterator it{selected.begin()}; it != selecte.end(); ++it)
    {
        if(it->getBelongsTo() != 1)
        {
            selectedNodes.erase(it);
            --it;
        }
    }

    if(gameWindow.unhandeledMouseClick())
    {
        pair<float, float> coords{gameWindow.getMouseClickCoords()};

        for(Node & node : nodes)
        {
            //kolla kollision
            if(isCollision({coords.first, coords.second}, node.shape.getGlobalBounds()))
            {
                if(node.getBelongsTo() == 1) //god nod
                {
                    selectedNodes.push_back(node);
                }
                else                         //ond nod
                {
                    for(Node & selectedNode : selectedNodes)
                    {
                        nodeBattles.push_back({selectedNode, node});
                    }
                }
            }
        }

        gameWindow.setMouseClickHandeled();
    }

    for(Node & node : nodes)
        node.update();

    for(list<NodeBattle>::iterator it{nodeBattles.begin()}; it != nodeBattles.end(); ++it)
    {
        it->update();

        if(it->getIsDone())
        {
            nodeBattles.erase(it);
            --it;
        }
    }

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

bool isCollision(pair<float, float> const mouseCoords, sf::FloatRect const& spriteCoords)
{
    if(mouseCoods.first >= spriteCoords.left &&
    mouseCoords.first <= spriteCoords.left + spriteCoods.width &&
    mouseCoords.second >= spriteCoords.top &&
    mouseCoords.second <= spriteCoords.top + spriteCoords.height)
    {
        return true
    }
    return false;
}