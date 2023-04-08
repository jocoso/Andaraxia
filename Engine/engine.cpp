// ./KrakenEngine/Core/krakeneng.cpp
#include "engine.h"

Engine::Engine(sf::RenderWindow *win) {
    _win = win;
}

int Engine::add_prop(Prop *prop) {
    _propList[_propList.size()] = prop;
    return _propList.size() -1;
}

bool Engine::rmv_prop(int id) {
    if(_propList.find(id) != _propList.end()) {
        _propList.erase(id);
        return true;
    }

    return false;
}

// Library Core Run
void Engine::run() {
    // Sanity Check
    try {
        _win->isOpen();
    } catch(std::exception &e) {
            std::cout << "CAUGHT " << e.what() << std::endl;
            std::cout << "KRAK_ERR: INVALID WINDOW _WIN" << std::endl;
    }
    int i;
    while(_win->isOpen()) {
        sf::Event event;

        while(_win->pollEvent(event)) {
            if(event.type == sf::Event::Closed) _win->close();
        }

        // if _win is nullpointer or null
        
        _win->clear(sf::Color::Black);
        
        for(i = 0; i < _propList.size(); i++) {
            _propList[i]->render(_win);
        }

        _win->display();
    }
}