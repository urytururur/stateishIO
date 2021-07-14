#include <unordered_map>
#include <SFML/Graphics.hpp> 

class ImgHandler
{
private:
    std::unordered_map<std::string, sf::Texture> cachedTextures;
public:
    ImgHandler();
    sf::Texture& provideTexture(std::string const& pathToImg);
};