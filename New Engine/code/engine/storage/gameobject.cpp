#include "gameobject.h"

GameObject::GameObject()
{
    coordinates.x=0;
    coordinates.y=0;
    rotation=0;
    size.x=266;
    size.y=399;
    has_Script=false;
    has_Collider=false;
    has_Renderer=false;
    has_RigidBody=false;
}
void GameObject::change_game_object_characteristics(sf::Vector2f new_size, float new_rotation){
    size.x=new_size.x;
    size.y=new_size.y;
    rotation=new_rotation;
}
void GameObject::change_coordinates(float x, float y){
    coordinates.x=x;
    coordinates.y=y;

}
