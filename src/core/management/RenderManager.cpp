
#include "RenderManager.h"
#include "../objects/Renderer.h"
#include "../Engine.h"


namespace engine
{   
    RenderManager::RenderManager()
    {
    }
    
     void RenderManager::renderObject(sf::Drawable& object)
    {
        Engine::instance()->dataStorage->window().draw(object);
    }
    
   void RenderManager::renderCollider(Collision* collider)
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

    Engine::instance()->dataStorage->window().draw(lines, 8, sf::Lines);
   }
   
   
       void RenderManager::addRenderer(Renderer* renderer)
    {
        renderers.push_back(renderer);
    }

    void RenderManager::deleteRenderer(Renderer* renderer)
    {
        renderers.erase(remove(renderers.begin(), renderers.end(), renderer), renderers.end());
    }

    void RenderManager::addCollider(Collision* collider)
    {
        colliders.push_back(collider);
    }

    void RenderManager::deleteCollider(Collision* collider)
    {
        colliders.erase(remove(colliders.begin(), colliders.end(), collider), colliders.end());
    }
