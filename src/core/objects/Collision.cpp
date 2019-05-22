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
  
  void Collision::enableHighlight()
    {
        if (!highlighted)
            Engine::instance()->renderManager->registerCollider(this);

        highlighted = true;
    }
  
  void Collision::disableHighlight()
    {
        if (!highlighted)
            Engine::instance()->renderManager->unregisterCollider(this);

        highlighted = false;
    }
  
  void Collision::setCollisionWithSprite()
  {
    if (!object ->hasComponent<Renderer>())
      return;
      
    auto spriteSize = object -> getComponent<Renderer>()->getTexture().getSize();
    
    leftTop.x = spriteSize.x / 2.0;
    leftTop.y = spriteSize.y / 2.0;
    rightDown.x = spriteSize.x / 2.0;
    rightDown.y = spriteSize.y / 2.0;
  }
}
