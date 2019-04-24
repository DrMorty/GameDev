#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <iostream>
#include <iterator>

#include "management/RenderManager.h"
#include "management/LogicManager.h"
#include "management/PhysicsManager.h"
#include "storage/DataStorage.h"
#include "shortcuts/Shortcuts.h"

#include "GameControl/ControlFPS.h"
#include "GameControl/GameControlScript.h"
#include "GameControl/Camera.h"

using engine::Renderer;
using engine::Collision;
using engine::CollisionDetails;
using engine::Script;

namespace engineS
{
    void createObject(std::string name)
    {
        auto& v = Engine::instance()->dataStorage->getGameObjects();

        if (v.find(name) != v.end())
            throw GameObjectAlreadyExist;

        v.try_emplace(name, name);
    }

    GameObject& getObject(std::string name)
    {
        return Engine::instance()->dataStorage->gameObjects[name];
    }

    void deleteObject(std::string name)
    {
        Engine::instance()->dataStorage->gameObjects.erase(name);
    }

    void deleteObject(GameObject* object)
    {
        Engine::instance()->dataStorage->gameObjects.erase(object->name);
    }

    void run()
    {
        Engine::instance()->engineRun();
    }
}
