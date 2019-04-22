
#include "RendererManager.h"
#include "../object_components/Renderer.h"
#include "../Engine.h"


namespace engine
{   
    RenderManager::RenderManager()
    {
    }
    
   void RenderManager::renderCollider(BoxCollider* collider)
   {
    sf::Vertex lines[] = 
    {
        sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->leftTop.y)),
        sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->rightDown.y)),

        sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->leftTop.y)),
        sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->leftTop.y)),

        sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->leftTop.y)),
        sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->rightDown.y)),

        sf::Vertex(sf::Vector2f(collider->leftTop.x, collider->rightDown.y)),
        sf::Vertex(sf::Vector2f(collider->rightDown.x, collider->rightDown.y)),
    };

    for (auto& line : lines)
        line.position = Camera::projectionToCamera(line.position + collider->object->transform.position);

    Engine::instance()->dataStorage->getWindowInstance().draw(lines, 8, sf::Lines);
   }
   
   
       void RenderManager::registerRenderer(Renderer* renderer)
    {
        renderers.push_back(renderer);
    }

    void RenderManager::unregisterRenderer(Renderer* renderer)
    {
        renderers.erase(remove(renderers.begin(), renderers.end(), renderer), renderers.end());
    }

    void RenderManager::registerCollider(BoxCollider* collider)
    {
        colliders.push_back(collider);
    }

    void RenderManager::unregisterCollider(BoxCollider* collider)
    {
        colliders.erase(remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }
