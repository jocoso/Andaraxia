#include <SFML/Graphics.hpp>
#include "Engine/engine.hpp"
#include "Engine/imagener.hpp"
#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow) {
    Scene s0;

    Imagener img("C:\\Users\\Jocoso2218\\Desktop\\cooloutfits.jpg");
    Aspect *as = &img;

    s0.register_prop("floor");
    s0.add_aspect("floor", as);

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    int i = e.add_scene(&s0);

    e.run();
    return 0;
}