#include "rigidbody.h"
#include "components.h"
RigidBody::RigidBody(){
    components_type="RigidBody";
    mass=1;
    gravity=0;
    Velocity.x=0.1;
    Velocity.y=0.1;
    acceleration.x=0;
    acceleration.y=0;
    isGravity=true;
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
