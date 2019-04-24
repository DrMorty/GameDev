#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Engine.h"


Engine* Engine::ex_instance = 0;

class Square : public Script
{
 public:
    void start()
    {
        object->transform.position.y = -350;
        object->transform.position.x = 350;
    }

    void update()
    {
        if (engineS::Input::getKey(KeyCode::A))
            object->transform.position.x -= 0.5;

        if (engineS::Input::getKey(KeyCode::D))
            object->transform.position.x += 0.5;
            
        if (engineS::Input::getKey(KeyCode::S))
            object->transform.position.y -= 0.5;

        if (engineS::Input::getKey(KeyCode::W))
            object->transform.position.y += 0.5;
    }
};


int main()
{
    engineS::createObject("square");
    engineS::getObject("square").addComponent<Square>();
    
    
    engineS::run();
}
