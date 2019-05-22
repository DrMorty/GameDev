#ifndef API_H
#define API_H
#include "engine/engine.h"
#include <string>
#include "engine/storage/components.h"
#include "engine/storage/rigidbody.h"
#include "engine/storage/script.h"
#include "engine/storage/collider.h"
#include "engine/storage/renderer.h"

class RigidBody;
class Script;
class Collider;
class Renderer;



class API
{
public:
    API();
    Engine engine;
    void create_game_object();
    void delete_game_object();
    void add_components(int GameObjectNumber, std::string new_components_type);

};

#endif // API_H
