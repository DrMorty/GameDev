#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>
#include "engine.h"
class Engine;
class Camera
{
public:
    Camera(Engine& exampleEngine);
    Camera();
    sf::Vector2f camera_position;
    sf::Vector2f projectionToCamera(sf::Vector2f objectPosition);
    Engine& engine;
};

#endif // CAMERA_H
