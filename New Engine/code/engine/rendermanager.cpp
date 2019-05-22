#include "rendermanager.h"
#include "engine.h"
#include <vector>
#include <iostream>
#include <map>

RenderManager::RenderManager(Engine& exampleEngine): engine(exampleEngine), window(sf::VideoMode(1000, 700), "This is the best engine", sf::Style::Default, settings){
    settings.antialiasingLevel = 8;
    view.reset(sf::FloatRect(0,0,1000,700));
}

void RenderManager::window_clear(){
    window.clear();
}
void RenderManager::draw_text(GameObject go){
    sf::Font font;
    font.loadFromFile(reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->address);
    sf::Text text(reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->text, font, reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->text_size);
    text.setPosition(go.coordinates);
    if (reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->isRendered){
        window.draw(text);
    }

}
void RenderManager::draw_sprite(GameObject go){
    sf::Texture texture;
    texture.loadFromFile(reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->address);
    sf::Sprite sprite(texture);
    sprite.setPosition(go.coordinates.x, go.coordinates.y);
    sprites.push_back(sprite);
    if (reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->isRendered){
        window.draw(sprite);
    }
}
void RenderManager::draw_circle(GameObject go){
    sf::CircleShape circle(go.size.x/2);
    circle.setFillColor(reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->color);
    circle.setPosition(go.coordinates);
    if (reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->isRendered){
        window.draw(circle);
    }

}
void RenderManager::draw_rectangle(GameObject go){
    sf::RectangleShape rectangle(go.size);
    rectangle.setFillColor(reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->color);
    rectangle.setPosition(go.coordinates);
    if(reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->isRendered){
        window.draw(rectangle);
    }
}
void RenderManager::draw_background(std::string address){
    window.setView(view);
    sf::Texture texture;
    texture.loadFromFile(address);
    sf::Sprite sprite(texture);
    window.draw(sprite);
}

void RenderManager::draw_display(){

    window.display();
}

void RenderManager::make_map(){
    gameMap.loadFromFile("images/map.png");
    sf::Texture map;
    map.loadFromImage(gameMap);
    sf::Sprite s_map;
    s_map.setTexture(map);


}
void RenderManager::draw_map(){

}
void RenderManager::draw_game_objects(GameObject go){
    std::map <std::string, int> mapping;
    mapping["sprite"]  = 1;
    mapping["text"] = 2;
    mapping["circle"] = 3;
    mapping["rectangle"]  = 4;
    if(go.has_Renderer){
        switch (mapping[reinterpret_cast<Renderer*>(go.components[go.RendererNumber])->Renderertype]) {
        case 1:
            draw_sprite(go);
            break;
        case 2:
            draw_text(go);
            break;
        case 3:
            draw_circle(go);
            break;
        case 4:
            draw_rectangle(go);
            break;

        }

    }
}

void RenderManager::draw_all_game_objects(std::vector<GameObject> all_game_objects){
    for (int i=0; i<all_game_objects.size();i++){
        draw_game_objects(all_game_objects[i]);
    }
}
