#include "../Engine.h"
#include <iostream>
#include <iterator>
#include "../GameControl/GameControlScript.h"
#include <exception>

namespace engine
{    
    EngineException GameObjectAlreadyExist;

    Engine* Engine::m_instance = 0;
}

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
    
    void stop()
    {
        Engine::instance()->~Engine();
    }
}
