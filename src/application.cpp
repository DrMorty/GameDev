#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/Engine.h"
#include "core/shortcuts/Shortcuts.h"


engine* Engine::ex_instance = 0;

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
}
