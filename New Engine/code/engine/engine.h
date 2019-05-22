#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "datastorage.h"
#include "logicsmanager.h"
#include "rendermanager.h"
#include "physicsmanager.h"
#include "camera.h"
#include "map.h"

class DataStorage;
class LogicsManager;
class RenderManager;
class PhysicsManager;
class Camera;
class Engine   
{

public:
    Engine();
    ~Engine();
    Camera* camera;
    LogicsManager* logics_manager;
    DataStorage* data_storage;
    RenderManager* render_manager;
    PhysicsManager* physics_manager;
    sf::Clock clock;
    float time;
    void main_while();
    v
};

#endif // ENGINE_H
