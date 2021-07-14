#include "Game.h"
#include <iostream>
#include <SFML/System.hpp>

using namespace std;

Game::Game()
{

}

void Game::run()
{
    while(true)
    {
        cout << "." << endl;
        sf::sleep(sf::Time::asMilliseconds(1000));
    }
}