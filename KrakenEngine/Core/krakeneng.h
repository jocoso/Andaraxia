#ifndef KRAKEN_ENGINE_H
#define KRAKEN_ENGINE_H

#include <iostream>
#include <string>
#include <system_error>
#include <SFML/Graphics.hpp>

class KrakenEngine {
private:
    sf::RenderWindow *_win = nullptr;
public:
    KrakenEngine(sf::RenderWindow *_win);
    void run(void);
};

#endif // KrakenEngine