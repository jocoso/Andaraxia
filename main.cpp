#include "Engine/engine.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);
    e.run();
    return 0;
}