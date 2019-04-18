#include "Collision.h"
#include "../Engine.h"

namespace engine
{
  Collision::Collision()
  {
  }
  
  void Collision::setCollision(float x1, float y1, float x2, float y2)
  {
    leftTop.x = x1;
    leftTop.y = y1;
    
    rightDown.x = x2;
    rightDown.y = y2;  
  }
  
  void Collision::setCollisionWithSprite()
  {
    if (!object ->hasComponent<Renderer>())
      return;
      
    auto spriteSize = object -> getComponent<Renderer>()->getTexture().getSize();
    
    leftTop.x = 0 - spriteSize.x /2.0;
    leftTop.y = 0 + spriteSize.y /2.0;
    rightDown.x = 0 + spriteSize.x /2.0;
    rightDown.y = 0 - spriteSize.y /2.0;
  }
}
