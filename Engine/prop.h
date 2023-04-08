// ./Engine/Prop.h
#ifndef PROP_H
#define PROP_H

#include <string>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class Prop {
private:
    std::map<int, std::string> _componentList;
    int _componentCount;

protected:
    std::string _name;
    std::string _desc;
public:
    Prop():_componentCount(0){}
    int add_component(std::string placeholdername);
    bool rmv_component(int id);
    void render(sf::RenderWindow *win);
};

#endif // PROP_H