#include <SFML\Graphics.hpp>
#ifndef MAP_H
#define MAP_H






class map
{
public:
    map();
    const int HEIGHT_MAP = 25;
    const int WIDTH_MAP = 40;
    sf::String TileMap[HEIGHT_MAP];
};

#endif // MAP_H
