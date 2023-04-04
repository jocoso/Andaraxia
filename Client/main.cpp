#include "../KrakenEngine/Core/krakeneng.h"

int main() {
    sf::RenderWindow win(sf::VideoMode(800, 600), "Prototype 0.0");
    KrakenEngine e(&win);
    e.run();

    return 0;
}