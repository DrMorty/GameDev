#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>
#include <map>

enum KeyCode {
    W = sf::Keyboard::Key::W,
    A = sf::Keyboard::Key::A,
    S = sf::Keyboard::Key::S, 
    D = sf::Keyboard::Key::D,
    Q = sf::Keyboard::Key::Q,
    E = sf::Keyboard::Key::E,
    Space = sf::Keyboard::Key::Space
};


namespace engine
{
    class Input
    {
     public:
        static bool getKey(KeyCode key);
        static bool isKeyDown(KeyCode key);
        static bool isKeyUp(KeyCode key);

        static void keyPressed(sf::Keyboard::Key key);
        static void keyReleased(sf::Keyboard::Key key);

        static std::map<KeyCode, bool> isKeyHold;
        static std::map<KeyCode, bool> isKeyPressed;

     private:
        Input();
        static KeyCode convertFromSfmlKey(sf::Keyboard::Key key);
    };
}

#endif