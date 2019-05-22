#ifndef LOGICSMANAGER_H
#define LOGICSMANAGER_H

#include "engine.h"
class Engine;
class LogicsManager
{
public:
    LogicsManager(Engine& exampleEngine);
    LogicsManager();
    Engine& engine;
    sf::Event event;
    void event_manager();
    void callScriptOnKeyPressed(int i, sf::Event events);


};

#endif // LOGICSMANAGER_H
