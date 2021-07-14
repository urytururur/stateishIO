#include "ImgHandler.h"

ImgHandler::ImgHandler():
    cachedTextures{} {}

sf::Texture& ImgHandlerprovideTexture(std::string const& pathToImg)
{
    if(cachedTextures.find(pathToImg) == cachedTextures.end())
    {
        cachedTextures.insert({pathToImg, sf::Texture{}});
        if(!cachedTextures.find(pathToImg)->second.loadFromFile(pathToImg))
        {
            return EXIT_FAILURE;
        }
    }
    return cachedTextures.find(pathToImg)->second;
}