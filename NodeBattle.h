#pragma once

#include "Node.h"
#include "ImgHandler.h"

class NodeBattle
{
private:
    Node& attacker;
    Node& defender;
    bool isDone;
    sf::Sprite sprite;
    ImgHandler& imgHandler;
public:
    NodeBattle(Node & attacker, Node & defender, ImgHandler const& imgHandler, sf::Sprite & sprite);
    void update();
    void render();
    bool getIsDone() const;
};