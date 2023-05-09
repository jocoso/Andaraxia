#include <SFML/Graphics.hpp>
#include "Engine/engine.h"
#include "Engine/aspect.h"
#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow) {
    Scene s0;
    Scene s1;
    

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    e.run();
    return 0;
}