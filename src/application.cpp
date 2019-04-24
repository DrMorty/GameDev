#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Engine.h"
#include "core/shortcuts/Shortcuts.h"



class Square : public Script
{
 public:
    void start()
    {
    
        object->transform.position.y = 100;
        object->transform.position.x = 100;
        object->addComponent<Collision>();
        object->getComponent<Collision>()->enableHighlight();
        object->getComponent<Collision>()->setCollider(-50, 15, 50, -15);
        
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
        
        if (engineS::KeyboardInput::getKey(KeyCode::Escape))
            engineS::stop();

    }
};


int main()
{
    engineS::createObject("square");
    engineS::getObject("square").addComponent<Square>();
    
    
    engineS::run();
 return 0;
}
