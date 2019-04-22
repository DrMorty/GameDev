#include "input.h"
#include "../Engine.h"

namespace engine
{
    std::map<KeyCode, bool> Input::isKeyHold;
    std::map<KeyCode, bool> Input::isKeyPressed;
    
    bool Input::getKey(KeyCode key)
    {
      return isKeyHold[key];
    }
    
    bool Input::isKeyDown(KeyCode key)
    {  auto keyPressedEvents = Engine::instance()->logicsManager->eventManager.getAllEventsOfType(sf::Event::KeyPressed);

        for (auto& event : keyPressedEvents)
            if (event.key.code == key && isPressedOnce[key])
                return true;
                
        return false;
    }
    
    bool Input::isKeyUp(KeyCode key)
    {
        auto keyPressedEvents = Engine::instance()->logicsManager->eventManager.getAllEventsOfType(sf::Event::KeyReleased);

        for (auto& event : keyPressedEvents)
            if (event.key.code == key)
                return true;

        return false;
    }

    void Input::keyPressed(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        isKeyPressed[keyCode] = true;

        if (isKeyHold[keyCode])
            isKeyPressed[keyCode] = false;

        isKeyHold[keyCode] = true;
    }
    
    
        void Input::keyReleased(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        isKeyPressed[keyCode] = false;
        isKeyHold[keyCode] = false;
    }
    
     KeyCode Input::convertFromSfmlKey(sf::Keyboard::Key key)
    {
        switch(key)
        {
            case KeyCode::W:        return W;
            case KeyCode::A:        return A;
            case KeyCode::S:        return S;
            case KeyCode::D:        return D;
            case KeyCode::E:        return E;
            case KeyCode::Q:        return Q;
            case KeyCode::Space:    return Space;
            case KeyCode::Escape:   return Escape;
        }
    }
}
