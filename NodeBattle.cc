#include "NodeBattle.h"

NodeBattle::NodeBattle(Node & attacker, Node & defender):
    attacker{attacker}, defender{defender}, isDone{false} {}

void NodeBattle::update()
{
    if(attacker.getSize() < 0)
    {
	attacker.resetSizeToZero();
	isDone = true;
    }
    else if(defender.getSize() < 0)
    {
	defender.resetSizeToZero();
        defender.setBelongsTo(attacker.getBelongsTo());
        isDone = true;
    }
    attacker.shrink(2);
    defender.shrink(2);
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
