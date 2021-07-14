#pragma once

#include "Node.h"

class NodeBattle
{
private:
    Node& attacker;
    Node& defender;
    bool isDone;
public:
    NodeBattle(Node & attacker, Node & defender);
    void update();
    //void render();
    bool getIsDone() const;
};