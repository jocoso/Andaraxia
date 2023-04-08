#include "Engine/engine.h"
#include <SFML/Graphics.hpp>

int main() {
    Prop p0;
    Prop p1;

    p0.add_component("Rosa");
    p0.add_component("Roja");
    p1.add_component("Carajo");
    p1.add_component("Verde");

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    e.add_prop(&p0);
    e.add_prop(&p1);

    e.run();
    return 0;
}