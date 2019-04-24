    
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

    const WindowSettings HD_Window = {"HD", 1280, 720}
    const WindowSettings Full_HD_Window = {"FHD", 1920, 1080}


    class DataStorage
    {
    public:

        DataStorage(WindowSettings windowSettings = HD_Window);
        ~DataStorage();

        sf::RenderWindow& getWindowInstance();
        std::map<std::string, GameObject>& getGameObjects();

        std::map<std::string, GameObject> gameObjects;

    private:
        sf::RenderWindow windowInstance;
    };
}

#endif

