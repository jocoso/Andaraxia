// ./KrakenEngine/Core/krakeneng.cpp
#include "engine.h"

Engine::Engine(sf::RenderWindow *win) {
    // Sanity Check
    if(win == nullptr || win == NULL) {
        throw std::invalid_argument("KRAK_ERR: INVALID WINDOW _WIN");
    }

    _win = win;
}


int Engine::add_prop(Prop *prop) {
    _propList[_propList.size()] = prop;
    return _propList.size() -1;
}

bool Engine::rmv_prop(unsigned id) {
    if(has_prop(id)) {
        _propList.erase(id);
        return true;
    }

    return false;
}

bool Engine::has_prop(unsigned id) {
    return _propList.find(id) != _propList.end();
}

// Library Core Run
void Engine::run() {
    int i;
    while(_win->isOpen()) {
        sf::Event event;

        while(_win->pollEvent(event)) {
            if(event.type == sf::Event::Closed) _win->close();
        }

        // if _win is nullpointer or null
        
        _win->clear(sf::Color::Black);
        
        for(i = 0; i < _propList.size(); i++) {

            if(has_prop(i)) _propList[i]->render(_win);

        }

        _win->display();
    }
}