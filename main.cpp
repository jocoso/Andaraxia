#include "Engine/engine.h"
#include <SFML/Graphics.hpp>

int main() {
    Scene p0;
    Scene p1;

    p0.add_component("Rosa");
    p0.add_component("Roja");
    p1.add_component("Carajo");
    p1.add_component("Verde");

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    e.add_scene(&p0);
    e.add_scene(&p1);

    e.run();
    return 0;
}