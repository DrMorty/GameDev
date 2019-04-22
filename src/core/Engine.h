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

        void run();

        std::unique_ptr<RenderManager> renderManager;
        std::unique_ptr<LogicsManager> logicsManager;
        std::unique_ptr<DataStorage> dataStorage;

    private:
        Engine();

        static Engine* m_instance;
    };
}

namespace engineX
{
    using namespace engine;

    void createObject(std::string name);
    GameObject& getObject(std::string name);
    void deleteObject(std::string name);
    void deleteObject(GameObject* object);

    void runScene();
}

#endif
