#include "LogicsManager.h"

#include "../object_components/Script.h"
#include "../Engine.h"

namespace engine
{   
    void LogicManager::callUpdateForScripts()
    {  
        for (auto  script : scripts)
            script->update();
    }
    void LogicManager::callStartForScripts()
    {  
        for (auto  script : notStartedScripts)
            script->start();
    }
    
    void LogicManager::clearNotStarted()
    {
      for (auto  script : notStartedScripts)
             notStartedScripts.clear();
    }
    
        void LogicManager::callOnCollisionForObject(GameObject* object, CollisionDetails& details)
    {
        for (auto script : scripts)
            if (script->object == object)
                script->onCollision(details);
    }

    void LogicManager::updateLogics()
    {
        Time::updateTime();
        
        eventManager.pollEvents();

        callStartForScripts();
        callUpdateForScripts();
        
        eventManager.clearEvents();
    }

    void LogicsManager::registerScript(Script* script)
    {
        notStartedScripts.push_back(script);
        scripts.push_back(script);
    }

    void LogicManager::unregisterScript(Script* script)
    {
        scripts.erase(remove(scripts.begin(), scripts.end(), script), scripts.end());
    }
}
