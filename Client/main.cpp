#include "../KrakenEngine/Core/krakeneng.h"
#include "../KrakenEngine/Props/krakenobj.h"

int main() {
    KrakenObject o("Object", "This is an Object");
    sf::RenderWindow win(sf::VideoMode(800, 600), "Prototype 0.0");
    KrakenEngine e(&win);
    e.run();

    return 0;
}