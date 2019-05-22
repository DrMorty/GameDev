#include <iostream>
#include "code/engine/engine.h"
#include "code/api.h"
using namespace std;

int main()
{
    API myAPI;
    myAPI.create_game_object();
    myAPI.add_components(0,"Renderer");
    myAPI.add_components(0,"RigidBody");
    myAPI.add_components(0,"Script");
    myAPI.engine.data_storage->game_objects[0].change_coordinates(500,650);
    myAPI.engine.data_storage->game_objects[0].change_velocity((0,0));
    myAPI.create_game_object();
    myAPI.add_components(1,"Renderer");
    myAPI.add_components(1,"RigidBody");
    myAPI.add_components(1,"Script");
    myAPI.engine.data_storage->game_objects[1].change_coordinates(500,0);

    myAPI.engine.main_while();


    return 0;
}
