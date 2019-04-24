#include "ControlFPS.h"
#include "KeyboardInput.h"
#include "Camera.h"

namespace engine
{
  class GameControlScript
    {
     public:
        static bool getKey(KeyCode key);
        static bool isKeyDown(KeyCode key);
        static bool isKeyUp(KeyCode key);

        static void keyPressed(sf::Keyboard::Key key);
        static void keyReleased(sf::Keyboard::Key key);

        static std::map<KeyCode, bool> isKeyHold;
        static std::map<KeyCode, bool> isKeyPressed;
        
        static float deltaTime;
        static void updateTime();

     private:
        KeyboardInput();
        static KeyCode convertFromSfmlKey(sf::Keyboard::Key key)
        Camera();

        static Vector3 position;  
   };
}

#endif
