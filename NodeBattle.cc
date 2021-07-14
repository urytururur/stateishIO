#include "NodeBattle.h"

NodeBattle::NodeBattle(Node & attacker, Node & defender):
    attacker{attacker}, defender{defender}, isDone{false}

void NodeBattle::update()
{
    if(attacker.getSize() < 0)
    {
        isDone = true;
    }
    else if(defender.getSize() < 0)
    {
        defender.setBelongsTo(attacker.getBelongsTo());
        idDone = true;
    }
    attacker.shrink(1);
    defender.shrink(1);
}

/*
void NodeBattle::render()
{

}
*/

bool NodeBattle::getIsDone() const
{
    return isDone;
}