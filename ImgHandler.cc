#include "ImgHandler.h"
#include <iostream>

using namespace std; 

ImgHandler::ImgHandler():
    cachedTextures{} {}

sf::Texture& ImgHandler::provideTexture(std::string const& pathToImg)
{
    if(cachedTextures.find(pathToImg) == cachedTextures.end())
    {
        cachedTextures.insert({pathToImg, sf::Texture{}});
        if(!cachedTextures.find(pathToImg)->second.loadFromFile(pathToImg))
        {
            	//return EXIT_FAILURE;
		cout << "failed to read texture." << endl; 
        }
    }
    return cachedTextures.find(pathToImg)->second;
}
