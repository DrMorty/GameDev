#include "physicsmanager.h"
#include "engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>
PhysicsManager::PhysicsManager(Engine& exampleEngine): engine(exampleEngine){}
void PhysicsManager::motion(){
    for(int i=0; i<engine.data_storage->game_objects.size();i++){
        if(engine.data_storage->game_objects[i].has_RigidBody){
            engine.data_storage->game_objects[i].coordinates.x+=reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->Velocity.x *engine.time;
            engine.data_storage->game_objects[i].coordinates.y+=reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->Velocity.y*engine.time;
            reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->Velocity.x+=reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->acceleration.x*engine.time;
            reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->Velocity.y+=reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->acceleration.y*engine.time;
            if (reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->isGravity==true){
                reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->acceleration.y+=reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber])->gravity;
            }
        }

    }

}
void PhysicsManager::collision(std::vector<GameObject> all_game_objects){
    for (int i=0; i<all_game_objects.size();i++){
        for (int j=i; j<all_game_objects.size();j++){
            if(i!=j && all_game_objects[i].has_Renderer
                    && all_game_objects[i].has_RigidBody
                    && all_game_objects[j].has_Renderer
                    && all_game_objects[j].has_RigidBody){
                    sf::FloatRect rect_i(all_game_objects[i].coordinates.x,
                                         all_game_objects[i].coordinates.y,
                                         all_game_objects[i].size.x,
                                         all_game_objects[i].size.y);
                    sf::FloatRect rect_j(all_game_objects[j].coordinates.x,
                                         all_game_objects[j].coordinates.y,
                                         all_game_objects[j].size.x,
                                         all_game_objects[j].size.y);
                    if(rect_i.intersects(rect_j)){
                        sf::Event event;
                        
                        if (event.key.code == sf::Keyboard::Right)
                        {
                            engine.data_storage->game_objects.erase(game_objects.begin() + i);
                        }
                        
                    }


            }
        }

    }
}

