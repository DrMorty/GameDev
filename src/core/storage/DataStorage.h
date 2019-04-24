    
#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <map>
#include <string>
#include <memory>

#include "GameObject.h"

namespace engine
{   
    struct WindowSettings
    {
        std::string name;

        int width;
        int height;
    };

    const Window HD_Window = {"HD", 1280, 720}
    const Window Full_HD_Window = {"FHD", 1920, 1080}


    class DataStorage
    {
    public:

        DataStorage(WindowSettings windowSettings = HD);
        ~DataStorage();

        sf::RenderWindow& getWindowInstance();
        std::map<std::string, GameObject>& getGameObjects();

        std::map<std::string, GameObject> gameObjects;

    private:
        sf::RenderWindow windowInstance;
    };
}

#endif

