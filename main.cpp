#include <SFML/Graphics.hpp>
#include "Engine/engine.hpp"
#include "Engine/imagener.hpp"
#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow) {
    Scene s0;
    Scene s1;

    s0.register_prop("floor");

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);


    e.run();
    return 0;
}