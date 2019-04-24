#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "GameObjectComponent.h"

namespace engine
{   
    class Renderer : public GameObjectComponent
    {
    public:
        ~Renderer() 
        {};

        void setSprite(const sf::Texture& t_texture);
        void setTexture(const sf::Texture& t_texture);
        void draw(sf::RenderWindow& windowInstance);

        sf::Texture& getTexture();

    private:
        sf::Sprite sprite;
        sf::Texture texture;
    };
}

#endif
