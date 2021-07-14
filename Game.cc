#include "Game.h"
#include <iostream>
#include <SFML/System.hpp>
#include "NodeBattle.h"

using namespace std;

Game::Game():
    gameWindow{800, 800, "StateishIO"}, nodes{}, playerToColorMapper{}, nodeBattles{}, selectedNodes{}
{
    nodes.push_back(Node{gameWindow, 30.f, 1, 100, 700, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 30.f, 2, 700, 100, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 10.f, 0, 400, 400, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 10.f, 0, 200, 200, playerToColorMapper});
    nodes.push_back(Node{gameWindow, 10.f, 0, 600, 600, playerToColorMapper});
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
    //rensa ur alla som inte längre är våra
    for(list<Node*>::iterator it{selectedNodes.begin()}; it != selectedNodes.end(); ++it)
    {
        if((*it)->getBelongsTo() != 1)
        {
            selectedNodes.erase(it);
            --it;
        }
    }
	
cout << 0 << endl;
    if(gameWindow.getUnhandeledMouseClick())
    {
	cout << 1 << endl;
        pair<float, float> coords{gameWindow.getMouseClickCoords()};

        for(Node & node : nodes)
        {
            //kolla kollision
            if(isCollision({coords.first, coords.second}, node.getBounds()))
            {
                if(node.getBelongsTo() == 1) //god nod
                {
                	selectedNodes.push_back(&node);
			node.setSelected(true);
                }
                else                         //ond nod
                {
                    for(Node* const  selectedNode : selectedNodes)
                    {
                        nodeBattles.push_back({*selectedNode, node});
			selectedNode->setSelected(false);
                    }
			selectedNodes.clear();
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

bool Game::isCollision(pair<float, float> const mouseCoords, sf::FloatRect const& spriteCoords) const
{
    if(mouseCoords.first >= spriteCoords.left &&
    mouseCoords.first <= spriteCoords.left + spriteCoords.width &&
    mouseCoords.second >= spriteCoords.top &&
    mouseCoords.second <= spriteCoords.top + spriteCoords.height)
    {
        return true;
    }
    return false;
}
