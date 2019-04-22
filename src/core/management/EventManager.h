#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <SFML/Graphics.hpp>
#include <functional>
#include <map>

namespace engine
{
    class EventManager
    {
        
        void checkEvents();
        void resetEvents();
        
        std::vector<sf:Event> newEvents;
        
        std::vector<sf::Event> getEvents(sf::Event::EventType);
        
    };
}

#endif
