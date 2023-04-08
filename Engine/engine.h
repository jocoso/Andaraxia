// ./engine/engine.h
#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <system_error>
#include <map>
#include <stdexcept>
#include <SFML/Graphics.hpp>

#include "./prop.h"

class Engine {
private:
    std::map<int, Prop*> _propList; // Made a map to keep id integrity when erasing
    sf::RenderWindow *_win = nullptr;
public:
    Engine(sf::RenderWindow *_win);
    int add_prop(Prop *prop);
    bool rmv_prop(unsigned id);
    bool has_prop(unsigned id);
    void run(void);
};

#endif // ENGINE_H