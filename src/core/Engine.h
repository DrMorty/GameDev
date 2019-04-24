#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

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

namespace engine
{
    class Engine
    {
    public: 

        static Engine* instance();
        ~Engine();

        void engineRun();

        dataStorage* DataStorage;
        drawManager* DrawManager;
        logicsManager* LogicsManager;

    private:
        Engine();
        static Engine* prev_instance;
    };
}
