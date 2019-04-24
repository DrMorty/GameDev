#include "Engine.h"
#include <iostream>
#include <iterator>
#include "objects/GameObjectComponent.h"
#include <exception>

namespace engine
{
    class EngineException: public std::exception
    {
    };

    EngineException GameObjectAlreadyExist;

    Engine* Engine::m_instance = 0;
    
    Engine* Engine::instance()
    {
        if (!prev_instance)
        {
            prev_instance = new Engine();
        }

        return prev_instance;
    }

   
    Engine::~Engine()
    {
    };

    
    void Engine::engineRun()
    {
        ControlFPS::updateMetrics();
        logicManager -> updateLogic();
        renderManager -> renderDrawableObjects(); 
    };
    
    
    Engine::Engine()
    {
        logicManager = new LogicManager();
        renderManager = new RenderManager();
        physicsManager = new PhysicsManager();
        dataStorage = new DataStorage();

        ControlFPS::enableLogging();
    };
}

