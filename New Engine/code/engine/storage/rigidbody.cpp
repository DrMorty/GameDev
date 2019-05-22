#include "rigidbody.h"
#include "components.h"
RigidBody::RigidBody(){
    components_type="RigidBody";
    mass=1;
    gravity=0;
    Velocity.x=0;
    Velocity.y=5;
    acceleration.x=0;
    acceleration.y=0;
    isGravity=false;
    startPosition.x=100;
    startPosition.y=100;
}
void RigidBody::change_gravity(float new_gravity){
    gravity=new_gravity;
}
void RigidBody::change_isGravity(bool new_isGravity){
    isGravity=new_isGravity;
}
void RigidBody::change_mass(float new_mass)
{
    mass=new_mass;
}
void RigidBody::change_velocity(sf::Vector2f new_velocity)
{
    Velocity.x=new_velocity.x;
    Velocity.y=new_velocity.y;
}
