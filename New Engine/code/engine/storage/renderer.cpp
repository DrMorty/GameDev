#include "renderer.h"
#include "components.h"

Renderer::Renderer(){
    components_type="Renderer";
    isRendered=true;
    Renderertype="sprite";
    address="Golovan.png";
    text="Choose this engine";
    text_size=10;
    color=sf::Color(0,0,250);
}
void Renderer::change_type(std::string new_type){
    Renderertype=new_type;
}
void Renderer::change_isRenderes(bool new_isRendered){
    isRendered=new_isRendered;
}
void Renderer::change_address(std::string new_address){
    address=new_address;
}
void Renderer::change_text(std::string new_text){
    text=new_text;
}
void Renderer::change_text_size(int new_text_size){
    text_size=new_text_size;
}
void Renderer::change_color(sf::Color new_change_color){
    color=new_change_color;
}
