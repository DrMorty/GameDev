#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include <SFML/Graphics.hpp>
#include "components.h"
#include <vector>
class Components;

class RigidBody: public Components
{
public:
    RigidBody();

    float gravity;
    bool isGravity;
    float mass;
    sf::Vector2f Velocity;
    sf::Vector2f acceleration;
    sf::Vector2f startPosition;
    void change_gravity(float new_gravity);
    void change_isGravity(bool new_isGravity);
    void change_mass(float mass);



};

#endif // RIGIDBODY_H
