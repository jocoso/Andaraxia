#include <SFML/Graphics.hpp>
#include "Engine/engine.hpp"
#include "Engine/imagener.hpp"
#include "Engine/hub.hpp"

int main() {
    Scene s0;
    sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
    Engine e(&window);
    
    Hub hub(-1);
    Prop *pHub = &hub;

    s0.register_prop(pHub);

    int i = e.add_scene(&s0);
    
    e.run();
    return 0;
}