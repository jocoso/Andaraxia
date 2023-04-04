// ./KrakenEngine/Core/krakeneng.cpp
#include "krakeneng.h"

KrakenEngine::KrakenEngine(sf::RenderWindow *win) {
    _win = win;
}

// Library Core Run
void KrakenEngine::run() {
    // Sanity Check
    try {
        _win->isOpen();
    } catch(std::exception &e) {
            std::cout << "CAUGHT " << e.what() << std::endl;
            std::cout << "KRAK_ERR: INVALID WINDOW _WIN" << std::endl;
    }

    while(_win->isOpen()) {
        sf::Event event;

        while(_win->pollEvent(event)) {
            if(event.type == sf::Event::Closed) _win->close();
        }

        // if _win is nullpointer or null
        
        _win->clear();
        _win->display();
    }
}