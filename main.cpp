#include <SFML/Graphics.hpp>
#include "Engine/engine.h"
#include "Engine/Hub.h"
#include "Engine/aspect.h"
#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow) {
    Scene s0;
    Scene s1;
    

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    Hub hub;
    Aspect *as = &hub;

    s0.register_prop("main_hub");
    s0.add_aspect("main_hub", as);

    e.add_scene(&s0);

    e.run();
    return 0;
}