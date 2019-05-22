#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include "engine.h"
#include "datastorage.h"
#include "storage/gameobject.h"
#include "storage/rigidbody.h"

class Engine;

class PhysicsManager
{
public:
    PhysicsManager(Engine& exampleEngine);
    PhysicsManager();
    Engine& engine;
    void motion();
    void collision(std::vector<GameObject> all_game_objects);


};

#endif // PHYSICSMANAGER_H
