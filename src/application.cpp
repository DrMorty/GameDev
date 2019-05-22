#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Engine.h"
#include "core/shortcuts/Shortcuts.h"



class movingSquare : public Script
{
 public:
    void start()
    {
        object->addComponent<Collision>();
        object->getComponent<Collision>()->enableHighlight();
        object->getComponent<Collision>()->isDynamic = false;
        object->getComponent<Collision>()->setCollision(-20, 20, 20, -20);
        object->transform.position.y = 360;
        
        object->addComponent<RigidBody>();
        object->getComponent<RigidBody>()->velocity = sf::Vector2f(0, 80);
        object->getComponent<RigidBody>()->isGravity = false;
        

    }

    void update()
    {

        
    }
    
    void collision()
    {
        if (engineS::KeyboardInput::getKey(KeyCode::D))
            //engineS::deleteObject(object);
            object->transform.position.y += 200;
            
    }
};

class staticSquare : public Script
{
 public:
  void start()
  {
     object->addComponent<Collision>();
     object->getComponent<Collision>()->enableHighlight();
     object->getComponent<Collision>()->setCollision(-50, 50, 50, -50);
     object->transform.position.y = -360;
 
  }
  void update()
    {  
    }
};

int main()
{
    engineS::createObject("background"); 

    sf::Texture background;
    background.loadFromFile("background.jpg");

    engineS::getObject("background").transform.position.y = 360;
    engineS::getObject("background").transform.position.x = -640;
    engineS::getObject("background").addComponent<Renderer>();
    engineS::getObject("background").getComponent<Renderer>()->setSprite(background);

 
    engineS::createObject("msquare");
    engineS::getObject("msquare").addComponent<movingSquare>();
    //engineS::getObject("msquare").addComponent<Renderer>();
 
    engineS::createObject("ssquare");
    engineS::getObject("ssquare").addComponent<staticSquare>();
    //engineS::getObject("ssquare").addComponent<Renderer>();

    
    
      

     
    engineS::run();
 
 return 0;
}
