#ifndef SHORTCUTS_H
#define SHORTCUTS_H
#include "../objects/GameObjectComponent.h"
#include <string>
#include "core/engine.h"
#include "scripts/picturescript.h"



namespace engineS
{
    using namespace engine;
    void createObject(std::string name);
    void deleteObject(std::string name);
    void deleteObject(GameObject* object);
    GameObject* findObject(std::string name);
    void run();


}

#endif
