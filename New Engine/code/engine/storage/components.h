#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <SFML/Graphics.hpp>
#include <string>
#include "gameobject.h"
class Components
{
public:
    class GameObject;
    GameObject* object;
    Components();

    std::string components_type;


};

#endif // COMPONENTS_H
