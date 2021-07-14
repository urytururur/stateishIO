#include "Game.h"
#include <iostream>
#include <SFML/System.hpp>

using namespace std;

Game::Game():
    gameWindow{} {}

void Game::run()
{
    while(true)
    {
        gameWindow.render();
        sf::sleep(sf::milliseconds(17));
    }
}
