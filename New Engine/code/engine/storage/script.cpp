#include "script.h"
#include "components.h"
#include "gameobject.h"

Script::Script(){
    components_type="Script";
}
void Script::onCollision(){

}
void Script::onKeyPressed(RigidBody* rd, sf::Event event){
    switch (event.type) {
    case sf::Event::KeyPressed:
    if (event.key.code == sf::Keyboard::Right){
        rd->Velocity.x=1;
    }
    else if (event.key.code == sf::Keyboard::Left){
        rd->Velocity.x=-1;
    }
    else if (event.key.code == sf::Keyboard::Up){
        rd->Velocity.y=-1;
    }
    else if (event.key.code == sf::Keyboard::Down){
        rd->Velocity.y=1;
    }
    break;

    case sf::Event::KeyReleased:
    if (event.key.code == sf::Keyboard::Right){
        rd->Velocity.x=0;
    }
    else if (event.key.code == sf::Keyboard::Left){
        rd->Velocity.x=0;
    }
    else if (event.key.code == sf::Keyboard::Up){
        rd->Velocity.y=0;
    }
    else if (event.key.code == sf::Keyboard::Down){
        rd->Velocity.y=0;
    }

    default:
        break;
    }
}
