#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include "components.h"
#include <vector>
class Components;
class GameObject
{
public:
    GameObject();
    sf::Vector2f coordinates;
    sf::Vector2f size;
    float rotation;
    std::vector<Components*> components;
    void change_game_object_characteristics(sf::Vector2f new_size, float new_rotation);
    void change_coordinates(float x, float y);
    bool has_Script;
    bool has_Collider;
    bool has_Renderer;
    bool has_RigidBody;
    int ScriptNumber;
    int ColliderNumber;
    int RigidBodyNumber;
    int RendererNumber;



};

#endif // GAMEOBJECT_H
