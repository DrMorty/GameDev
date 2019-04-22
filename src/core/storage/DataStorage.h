#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include "../objects/gameobject.h"

namespace engine
{
    struct Window
    {
        std::string name;
        int width;
        int height;
    };
    
    const Window HD_Window = {"HD", 1280, 720}
    const Window Full_HD_Window = {"HD", 1920, 1080}
    
    class Datastorage
    {
       
    public:
        DataStorage(Window window = HD_window);
        ~DataStorage();
        std::map<std::string, GameObject>& getGameObjects();

        std::map<std::string, GameObject> gameObjects;
        
#endif 
