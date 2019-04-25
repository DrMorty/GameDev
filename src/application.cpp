#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Engine.h"
#include "core/shortcuts/Shortcuts.h"



class Square : public Script
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
        
        //if (engineS::KeyboardInput::getKey(KeyCode::Escape))
         //   window->close();

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
    engineS::getObject("square").addComponent<Square>();
    engineS::getObject("square").addComponent<Renderer>();
    engineS::getObject("square").getComponent<Renderer>()->setSprite(error); 
    
    engineS::run();
 return 0;
}
