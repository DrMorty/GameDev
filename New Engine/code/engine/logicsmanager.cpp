#include "logicsmanager.h"
#include "engine.h"
#include "camera.h"
#include "storage/script.h"
LogicsManager::LogicsManager(Engine& exampleEngine): engine(exampleEngine){}
void LogicsManager::event_manager(){
    engine.physics_manager->motion();
    while (engine.render_manager->window.pollEvent(event)){
        switch (event.type) {
        case sf::Event::Closed:
            engine.render_manager->window.close();
            break;
        }
        callScriptOnKeyPressed(0,event);


    }

}
void LogicsManager::callScriptOnKeyPressed(int i, sf::Event events){
    if (engine.data_storage->game_objects[i].has_Script && engine.data_storage->game_objects[i].has_Script){
        reinterpret_cast<Script*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].ScriptNumber])->onKeyPressed(reinterpret_cast<RigidBody*>(engine.data_storage->game_objects[i].components[engine.data_storage->game_objects[i].RigidBodyNumber]),events);
    }


}
