#include <SFML/Graphics.hpp>
#include "Engine/engine.h"
#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow) {
    Scene s0;
    Scene s1;

    s0.register_prop("Joshua");
    s0.register_prop("Roy");
    s1.register_prop("Cara");

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    e.add_scene(&s0);
    e.add_scene(&s1);

    e.run();
    return 0;
}