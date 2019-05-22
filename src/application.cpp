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
        object->getComponent<Collision>()->setCollision(-20, 20, 20, -20);
        object->transform.position.y = 360;
        
        
       
    }

    void update()
    {
        object->transform.position.y -= 20;
        if (object->transform.position.y < -400)
            std::cout << "Too bad" << std::endl;
    }
    
    void collision(CollisionDetails& details)
    {
        if (engineS::KeyboardInput::getKey(KeyCode::D))
            engineS::deleteObject(object);
            
            
    }
};

class staticSquare : public Script
{
 public:
  void start()
  {
     object->addComponent<Collision>();
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

    engineS::createObject("texture");
 
    sf::Texture texture;
   texture.loadFromFile("green button.jpeg");
  
    engineS::createObject("msquare");
    engineS::getObject("msquare").addComponent<movingSquare>();
    engineS::getObject("msquare").addComponent<Renderer>();
    engineS::getObject("msquare").getComponent<Renderer>()->setSprite(texture);
    //engineS::getObject("msquare").addComponent<Renderer>();
 
    engineS::createObject("ssquare");
    engineS::getObject("ssquare").addComponent<staticSquare>();
     engineS::getObject("square").addComponent<Renderer>();
    engineS::getObject("square").getComponent<Renderer>()->setSprite(texture);
    //engineS::getObject("ssquare").addComponent<Renderer>();

    for (int i = 0; i < 10; i++ )
    {
     std::string square = std::to_string(i);
     engineS::createObject("ssquare");
     engineS::getObject("ssquare").addComponent<staticSquare>();
    }
    

    engineS::run();
 
 return 0;
}
