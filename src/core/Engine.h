#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "management/RenderManager.h"
#include "management/LogicsManager.h"
#include "management/PhysicsManager.h"
#include "storage/DataStorage.h"

#include "controllers/KeyboardInput.h"
#include "controllers/Time.h"
#include "controllers/Camera.h"

using engine::Renderer2D;
using engine::BoxCollider;
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

        DataStorage* DataStorage;
        DrawManager* DrawManager;
        LogicsManager* LogicsManager;

    private:
        Engine();
        static Engine* prev_instance;
    };
}
