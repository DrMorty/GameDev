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

        void registerRenderer(Renderer* renderer);
        void unregisterRenderer(Renderer* renderer);

        void registerCollider(Collision* collider);
        void unregisterCollider(Collision* collider);

    private:
        std::vector<Renderer*> renderers;
        std::vector<Collision*> colliders;

        void renderCollider(Collision* collider);
    };
}

#endif
