#include <SFML/Graphics.hpp>
#include "Engine/engine.h"

int main() {
    Scene s0;
    Scene s1;

    s0.register_prop("Joshua", "Yes");
    s0.register_prop("Roy", "Acevedo");
    s1.register_prop("Cara", "HO");

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    e.add_scene(&s0);
    e.add_scene(&s1);

    e.run();
    return 0;
}