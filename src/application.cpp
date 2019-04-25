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
        object->getComponent<Collision>()->enableHighlight();
        object->getComponent<Collision>()->setCollision(-100, 100, 100, -100);
        
        object->transform.position.y = 100;
        object->transform.position.x = 100;
    }

    void update()
    {
        if (engineS::KeyboardInput::getKey(KeyCode::A))
            object->transform.position.x -= 0.5;

        if (engineS::KeyboardInput::getKey(KeyCode::D))
            object->transform.position.x += 0.5;
            
        if (engineS::KeyboardInput::getKey(KeyCode::S))
            object->transform.position.y -= 0.5;

        if (engineS::KeyboardInput::getKey(KeyCode::W))
            object->transform.position.y += 0.5;
        
        //if (engineS::KeyboardInput::getKey(KeyCode::Escape))
          //  window.close();

    }
};


int main()
{
    engineS::createObject("background"); 

    sf::Texture background;
    background.loadFromFile("background.jpg");

    engineS::getObject("background").transform.position.y = 350;
    engineS::getObject("background").transform.position.x = 200;
    engineS::getObject("background").addComponent<Renderer>();
    engineS::getObject("background").getComponent<Renderer>()->setSprite(background);
 
    sf::Texture error;
    error.loadFromFile("error.jpg");
    sf::Sprite sprite;
    sprite.setTexture(error);
 
    engineS::createObject("square");
    engineS::getObject("square").addComponent<Square>();
    engineS::getObject("square").addComponent<Renderer>();
    engineS::getObject("square").getComponent<Renderer>()->setSprite(sprite); 
    
    engineS::run();
 return 0;
}
