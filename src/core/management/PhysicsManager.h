#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include <vector>

#include "../storage/GameObject.h"

namespace engine
{   
    class PhysicsManager
    {
    public:
        void updatePhysics();

        void registerCollider(Collision* collider);
        void unregisterCollider(Collision* collider);

        void registerRigidBody(RigidBody* rigidBody);
        void unregisterRigidBody(RigidBody* rigidBody);

    private:
        std::vector<Collision*> colliders;
        std::vector<RigidBody*> rigidBodies;

        void calculatePhysics();
        void detectCollisions();
        void resolveCollision(CollisionDetails& details);

        bool isCollision(Collision* first, Collision* second);

        CollisionDetails getCollisionDetails(Collision* first, Collision* second);
    };
}

#endif 
