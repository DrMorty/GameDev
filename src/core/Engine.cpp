#include "Engine.h"
#include <iostream>
#include <iterator>
#include "Controllers/Metrics.h"
#include <exception>

namespace engine
{
    
    Engine* Engine::prev_instance = 0;
    
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
        Metrics::updateMetrics();
        logicsManager -> updateLogics();
        renderManager -> renderDrawableObjects(); 
    };
    
    
    Engine::Engine()
    {
        logicsManager = new LogicsManager();
        renderManager = new RenderManager();
        physicsManager = new PhysicsManager();
        dataStorage = new DataStorage();

        Metrics::enableLogging();
    };
}

