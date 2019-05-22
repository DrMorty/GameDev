#ifndef RENDERER_H
#define RENDERER_H
#include "components.h"
#include <string>
class Components;
class Renderer: public Components
{
public:
    Renderer();
    bool isRendered;
    std::string Renderertype;
    std::string address;
    std::string text;
    int text_size;
    sf::Color color;
    void change_type(std::string new_type);
    void change_isRenderes(bool new_isRendered);
    void change_address(std::string new_address);
    void change_text(std::string new_text);
    void change_text_size(int new_text_size);
    void change_color(sf::Color new_change_color);
};

#endif // RENDERER_H
