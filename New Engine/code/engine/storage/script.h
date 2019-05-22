#ifndef SCRIPT_H
#define SCRIPT_H
#include "gameobject.h"
#include "components.h"
#include "rigidbody.h"#include "rigidbody.h"
class Components;

class Script: public Components
{
public:
    Script();
    ~Script();
    void onCollision();
    void onKeyPressed(RigidBody* rd, sf::Event event);


};

#endif // SCRIPT_H
