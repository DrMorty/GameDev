#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SFML/Graphics.hpp>
#include "../object_components/Renderer2D.h"
#include "../object_components/BoxCollider.h"

namespace engine
{   
    class RenderManager
    {
    public:
        RenderManager();

        void renderDrawableObjects();
        void renderObject(sf::Drawable& object);
        void addRenderer(Renderer* renderer);
        void deleteRenderer(Renderer* renderer);

        void addCollider(BoxCollider* collider);
        void deleteCollider(BoxCollider* collider);

    private:
        std::vector<Renderer*> renderers;
        std::vector<BoxCollider*> colliders;

        void renderCollider(BoxCollider* collider);
    };
}

#endif
