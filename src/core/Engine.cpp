#include "Engine.h"
#include <iostream>
#include <iterator>
#include "Controllers/Metrics.h"
#include <exception>

namespace engine
{
    class EngineException: public std::exception
    {
    };

    EngineException GameObjectAlreadyExist;

    Engine* Engine::prev_instance = 0;

    Engine::Engine()
    {
        logicsManager = new LogicsManager();
        renderManager = new RenderManager();
        physicsManager = new PhysicsManager();
        dataStorage = new DataStorage();

        Metrics::enableLogging();
    };
    
    Engine::~Engine()
    {
    };

    Engine* Engine::instance()
    {
        if (!prev_instance)
        {
            prev_instance = new Engine();
        }

        return prev_instance;
    }

    void Engine::run()
    {
        Metrics::updateMetrics();
        logicsManager -> updateLogics();
        renderManager -> renderDrawableObjects(); 
    };
}

