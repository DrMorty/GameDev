#include "datastorage.h"
#include "engine.h"
#include "storage/gameobject.h"
DataStorage::DataStorage(Engine& exampleEngine): engine(exampleEngine){}
void DataStorage::add_object(){
    GameObject  new_object;
    game_objects.push_back(new_object);

}
