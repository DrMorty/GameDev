#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <iostream>

#include "../objects/GameObjectComponent.h"
#include "../objects/Collision.h"
#include "../objects/Renderer.h"
#include "../objects/RigidBody.h"
#include "../objects/Script.h"

#include "../math/Math.h"

namespace engine
{   
    class Transform
    {
    public:
        Vector3 position = {0.0, 0.0};
        Vector3 rotation = {0.0, 0.0};
        Vector3 scale = {1.0, 1.0};
    };

    class GameObject
    {
    public:
        GameObject();
        GameObject(std::string t_name);
        ~GameObject();

        template <typename ComponentType>
        void addComponent();

        template <typename ComponentType>
        ComponentType* getComponent();

        template <typename ComponentType>
        bool hasComponent();

        void setSprite(const sf::Texture& texture);

        std::string name;
        Transform transform;

    private:
        void registerScriptForThisObject(GameObjectComponent* script);
        void registerRendererForThisObject(GameObjectComponent* renderer);
        void registerColliderForThisObject(GameObjectComponent* collider);
        void registerRigidBodyForThisObject(GameObjectComponent* rigidBody);

        void unregisterScriptForThisObject(GameObjectComponent* script);
        void unregisterRendererForThisObject(GameObjectComponent* renderer);
        void unregisterColliderForThisObject(GameObjectComponent* collider);
        void unregisterRigidBodyForThisObject(GameObjectComponent* rigidBody);


        std::vector<std::shared_ptr<GameObjectComponent>> m_components;
    };

    template <typename ComponentType>
    void GameObject::addComponent()
    {
        std::shared_ptr<ComponentType> component = std::make_shared<ComponentType>();
        
        component->typeName = typeid(ComponentType).name();
        component->object = this;

        m_components.push_back(component);

        if (std::is_base_of<Script, ComponentType>())
            registerScriptForThisObject(component.get());

        if (typeid(ComponentType).name() == typeid(Renderer).name())
            registerRendererForThisObject(component.get());

        if (typeid(ComponentType).name() == typeid(Collision).name())
            registerColliderForThisObject(component.get());

        if (typeid(ComponentType).name() == typeid(RigidBody).name())
            registerRigidBodyForThisObject(component.get());
    }

    template <typename ComponentType>
    ComponentType* GameObject::getComponent()
    {
        for (auto component : m_components)
            if (component->typeName == typeid(ComponentType).name())
            {
                ComponentType* casted = static_cast<ComponentType*>(component.get());
                return casted;
            }
    }

    template <typename ComponentType>
    bool GameObject::hasComponent()
    {
        for (auto component : m_components)
            if (component->typeName == typeid(ComponentType).name())
            {
                return true;
            }

        return false;
    }
}
#endif
