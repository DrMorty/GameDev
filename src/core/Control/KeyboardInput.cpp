#include "KeyboardKeyboardInput.h"
#include "../Engine.h"

namespace engine
{
    std::map<KeyCode, bool> KeyboaKeyboardInput::isKeyHold;
    std::map<KeyCode, bool> KeyboardInput::isKeyPressed;
    
    bool KeyboardInput::getKey(KeyCode key)
    {
      return isKeyHold[key];
    }
    
    bool KeyboardInput::isKeyDown(KeyCode key)
    {  auto keyPressedEvents = Engine::instance()->logicsManager->eventManager.getAllEventsOfType(sf::Event::KeyPressed);

        for (auto& event : keyPressedEvents)
            if (event.key.code == key && isPressedOnce[key])
                return true;
                
        return false;
    }
    
    bool KeyboardInput::isKeyUp(KeyCode key)
    {
        auto keyPressedEvents = Engine::instance()->logicsManager->eventManager.getAllEventsOfType(sf::Event::KeyReleased);

        for (auto& event : keyPressedEvents)
            if (event.key.code == key)
                return true;

        return false;
    }

    void KeyboardInput::keyPressed(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        isKeyPressed[keyCode] = true;

        if (isKeyHold[keyCode])
            isKeyPressed[keyCode] = false;

        isKeyHold[keyCode] = true;
    }
    
    
        void KeyboardInput::keyReleased(sf::Keyboard::Key key)
    {
        auto keyCode = convertFromSfmlKey(key);

        isKeyPressed[keyCode] = false;
        isKeyHold[keyCode] = false;
    }
    
     KeyCode KeyboardInput::convertFromSfmlKey(sf::Keyboard::Key key)
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
