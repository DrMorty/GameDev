#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include "engine.h"
#include <vector>
#include "storage/gameobject.h"

class Engine;
class DataStorage
{
public:
    DataStorage(Engine& exampleEngine);
    DataStorage();
    Engine& engine;
    std::vector<GameObject> game_objects;
    void add_object();


};

#endif // DATASTORAGE_H
