#include "api.h"

API::API()
{


}
void API::create_game_object(){
    engine.data_storage->add_object();

}

void API::add_components(int GameObjectNumber, std::string new_components_type){
    int number = engine.data_storage->game_objects[GameObjectNumber].components.size();
    if(new_components_type=="Script"){
        engine.data_storage->game_objects[GameObjectNumber].components.push_back(new Script);
        engine.data_storage->game_objects[GameObjectNumber].has_Script=true;
        engine.data_storage->game_objects[GameObjectNumber].ScriptNumber=number;
    }
    if(new_components_type=="RigidBody"){
        engine.data_storage->game_objects[GameObjectNumber].components.push_back(new RigidBody);
        engine.data_storage->game_objects[GameObjectNumber].has_RigidBody=true;
        engine.data_storage->game_objects[GameObjectNumber].RigidBodyNumber=number;
    }
    if(new_components_type=="Collider"){
        engine.data_storage->game_objects[GameObjectNumber].components.push_back(new Collider);
        engine.data_storage->game_objects[GameObjectNumber].has_Collider=true;
        engine.data_storage->game_objects[GameObjectNumber].ColliderNumber=number;
    }
    if(new_components_type=="Renderer"){
        engine.data_storage->game_objects[GameObjectNumber].components.push_back(new Renderer);
        engine.data_storage->game_objects[GameObjectNumber].has_Renderer=true;
        engine.data_storage->game_objects[GameObjectNumber].RendererNumber=number;
    }

}
