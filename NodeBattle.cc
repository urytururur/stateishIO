#include "NodeBattle.h"

NodeBattle::NodeBattle(Node & attacker, Node & defender, ImgHandler const& imgHandler, sf::Sprite & sprite):
    attacker{attacker}, defender{defender}, isDone{false}, imgHandler{imgHandler}, sprite{imgHandler.provideTexture("./img/fire/blue/spritesheet-512px-by197px-per-frame.png")} {}

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

void NodeBattle::render()
{
    sprite.setPosition(300.f, 400.f);
    gameWindow.draw(sprite);
}

bool NodeBattle::getIsDone() const
{
    return isDone;
}
