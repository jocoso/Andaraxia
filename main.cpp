#include <SFML/Graphics.hpp>
#include "Engine/engine.hpp"
#include "Engine/imagener.hpp"

int main() {
    Scene s0;

    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);

    int i = e.add_scene(&s0);
    
    e.run();
    return 0;
}