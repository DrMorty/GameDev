#ifndef COLLISION_H
#define COLLISION_H

#include "GameObjectComponent.h"

#include "SFML/Graphics.hpp"

#include <iostream>

namespace engine
{
  class Collision;
  
  struct CollisionDetails
  {
    CollisionDetails(Collision* object1, Collision* object2, float depth, sf::Vector2f trajectory) :
    Collider1 (object1), Collider2(object2), depth(depth), collisionTrajectory(trajectory)
    {};
    
    Collision* Collider1 = 0;
    Collision* Collider2 = 0;
    
    float depth;
    sf::Vector2f collisionTrajectory;
  };
  
  class Collision: public GameObjectComponent
  {
    public:
      Collision();
      ~Collision() {};
      
      void setCollision(float x1, float y1, float x2, float y2);
      void setCollisionWithSprite();
      void enableHighlight();
      void disableHighlight();
      
     sf::Vector2f leftTop;
     sf::Vector2f rightDown;
     
     bool isDynamic = true;
   private:
     bool highlighted = false;
  };
}

#endif
