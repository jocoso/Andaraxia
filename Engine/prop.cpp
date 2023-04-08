// ./Engine/Prop.cpp
#include "./prop.h"

int Prop::add_component(std::string placeholdername) {
    _componentList[_componentList.size()] = placeholdername;
    return _componentList.size() -1;
}

bool Prop::rmv_component(int id) {
    if(_componentList.find(id) != _componentList.end()) {
        _componentList.erase(id);
        return true;
    }

    return false;
}

void Prop::render(sf::RenderWindow *win) {
    for(auto it = _componentList.begin(); it != _componentList.end();) {
        std::cout << it->first << " : " << it->second << std::endl;
        ++it;
    }
}