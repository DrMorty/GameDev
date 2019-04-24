#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SFML/Graphics.hpp>
#include "../objects/Renderer.h"
#include "../objects/Collision.h"

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

        void addCollider(Collision* collider);
        void deleteCollider(Collision* collider);

    private:
        std::vector<Renderer*> renderers;
        std::vector<Collision*> colliders;

        void renderCollider(Collision* collider);
    };
}

#endif
