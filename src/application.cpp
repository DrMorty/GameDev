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
        object->getComponent<Collision>()->setCollision(-100, 100, 100, -100);

    }

    void update()
    {
        if (engineS::KeyboardInput::getKey(KeyCode::A))
            object->transform.position.x -= 20;

        if (engineS::KeyboardInput::getKey(KeyCode::D))
            object->transform.position.x += 20;
            
        if (engineS::KeyboardInput::getKey(KeyCode::S))
            object->transform.position.y -= 20;

        if (engineS::KeyboardInput::getKey(KeyCode::W))
            object->transform.position.y += 20;

    }
};

class staticSquare : public Script
{
 public:
  void start():
  {
     tmp = 100 + rand()%10
     object->addComponent<Collision>();
     object->getComponent<Collision>()->setCollision(-tmp, tmp, tmp, -tmp);
      object->transform.position.y = -tmp;
       object->transform.position.x = tmp;
      
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
 
    sf::Texture error;
    error.loadFromFile("error.jpg");

 
    engineS::createObject("square");
    engineS::getObject("square").addComponent<movingSquare>();
    engineS::getObject("square").addComponent<Renderer>();
    engineS::getObject("square").getComponent<Renderer>()->setSprite(error); 
    
    sf::Event event;
    while(true) {
     if(event.type ==sf::Event::KeyeboardInput)
      i = 0
       engineS::createObject("i");
       engineS::getObject("i").addComponent<staticSquare>();
    engineS::getObject("i").addComponent<Renderer>();
    engineS::getObject("i").getComponent<Renderer>()->setSprite(background);
     i += 1
    }
      

     
    engineS::run();
 return 0;
}
