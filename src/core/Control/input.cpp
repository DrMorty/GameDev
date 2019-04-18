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
    
    
    
