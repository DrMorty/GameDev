#include "engine.h"

Engine::Engine(): physics_manager(new PhysicsManager(*this)),
    render_manager(new RenderManager(*this)),
    data_storage(new DataStorage(*this)),
    logics_manager(new LogicsManager(*this)),
    camera(new Camera(*this)){}
Engine::~Engine(){}
void Engine::main_while(){
    time=time/800;
    while(render_manager->window.isOpen()){
        render_manager->draw_background("golovan_home.jpeg");
        time=clock.getElapsedTime().asMilliseconds();
        clock.restart();
        time=time/8;
        logics_manager->event_manager();
        physics_manager->collision(data_storage->game_objects);
        physics_manager->motion();

        render_manager->window_clear();
        render_manager->draw_all_game_objects(data_storage->game_objects);
        render_manager->draw_display();
    }
}
