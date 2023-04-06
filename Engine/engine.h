// ./engine/engine.h
#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <system_error>
#include <SFML/Graphics.hpp>

class Engine {
private:
    sf::RenderWindow *_win = nullptr;
public:
    Engine(sf::RenderWindow *_win);
    void run(void);
};

#endif // ENGINE_H