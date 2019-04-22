#include <SFML/Graphics.hpp>

#include <iostream>
#include <algorithm>
#include "../engine.h"
#include "EventManager.h"
#include "Datastorage.h"

namespace engine
{

  
  void EventManager::checkEvents()
  {
    sf::Event event;
    
    while((Datadtorage->window()).pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
      {
        KeyboardInput::keyPressed(event.key.code)
      };
      
      newEvents.push_back(event);
    }
  }
  
  void EventManager::resetEvents()
  {
    newEvents.clear();
  }
  
  std::vector<sf::Event> EventManager::getEvents(sf::Event::EventType type)
  {
    std::vector<sf::Event> events;
    
    for (auto event : newEvents)
      if (type == event.type)
        events.push_back(event);
    return events;
  }
}
