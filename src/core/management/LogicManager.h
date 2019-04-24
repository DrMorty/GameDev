#ifndef LOGIC_MANAGER_H
#define LOGIC_MANAGER_H

#include <vector>
#include <list>
#include <map>

#include "../storage/GameObject.h"
#include "EventManager.h"

namespace engine
{   
    class LogicManager
    {
    public:
        void updateLogic();
        void callStartForScripts();
        void clearNotStarted();
        void callUpdateForScripts();
        void callOnCollisionForObject(GameObject* object, CollisionDetails& details);

        void registerScript(Script* script);
        void unregisterScript(Script* script);

        EventManager eventManager;
    private:
        std::list<Script*> notStartedScripts;
        std::vector<Script*> scripts; 
    };
}

#endif 
