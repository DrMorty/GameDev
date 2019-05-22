cmake_minimum_required(VERSION 2.8)
project(1)


set(SFML_INCLUDE_DIR "SFML/include")
set(SFML_LIBRARY_DIR "SFML/lib")

include_directories("SFML/include")
link_directories("SFML/lib")

set(SFML_DIR "SFML/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)



add_executable(${PROJECT_NAME} "main.cpp" "code/api.cpp" "code/engine/engine.cpp" "code/engine/datastorage.cpp"
    "code/engine/storage/components.cpp" "code/engine/storage/gameobject.cpp"
    "code/engine/rendermanager.cpp" "code/engine/physicsmanager.cpp" "code/engine/logicsmanager.cpp"
     "code/engine/storage/script.cpp"
    "code/engine/storage/rigidbody.cpp" "code/engine/storage/collider.cpp"
    "code/engine/storage/renderer.cpp" "code/engine/camera.cpp"
    "code/engine/map.cpp" )

target_link_libraries (${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

