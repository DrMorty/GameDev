#ifndef SHORTCUTS_H
#define SHORTCUTS_H
#include "../objects/GameObjectComponent.h"

#include <string>
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



namespace engineS
{
    using namespace engine;
    void createObject(std::string name);
    void deleteObject(std::string name);
    void deleteObject(GameObject* object);
    GameObject* findObject(std::string name);
    void run();
    void stop();

}

#endif
