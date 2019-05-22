#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "storage/gameobject.h"
#include "engine.h"
#include <string>
#include <vector>
#include "storage/renderer.h"
#include <iostream>
#include "map.h"
class Engine;
class RenderManager
{
public:
    RenderManager(Engine& exampleEngine);
    RenderManager();
    Engine& engine;
    sf::Image gameMap;
    sf::ContextSettings settings;
    sf::RenderWindow window;
    sf::View view;
    std::vector<sf::Sprite> sprites;
    sf::View get_camera_move(float x,float y){
        view.setCenter(x+100,y);
        return view;
    }


    void window_clear();
    void draw_text(GameObject go);
    void draw_sprite(GameObject go);
    void draw_circle(GameObject go);
    void draw_rectangle(GameObject go);
    void draw_game_objects(GameObject go);
    void draw_all_game_objects(std::vector<GameObject> all_game_objects);
    void draw_display();
    void make_map();
    void draw_map();
    void make_view();
    void draw_background(std::string address);
};

#endif // RENDERMANAGER_H
