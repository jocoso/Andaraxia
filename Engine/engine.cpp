// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    04/08/2023
 * FILENAME:        ./Engine/engine.cpp
 * AUTHOR:          Joshua Collado
 * 
 * ------------------------------------------------------------------------------
 * Novella Engine is a new way to enjoy RPGs. The main purpose of this software 
 * is to play a particular story engaging in different perspectives
 * of the universe presented. Novella allows a reader to not only make
 * decisions of how they want the story to progress but also who they
 * want to be in this universe. This advantages allow for a more engaging
 * reading experience that can later be exported and read as a standalone.
 * ------------------------------------------------------------------------------
 * 
 * This file is part of {{ Novella.Engine }}.
 *
 * Developed for the creation of text-based games.
 * This product includes software developed by Joshua Collado
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 ***************************************************************************/


#include "engine.hpp"

Engine::Engine(sf::RenderWindow *win) {

    // Sanity Check if not window
    if (win == nullptr || win == NULL) {
        throw std::invalid_argument("KRAK_ERR: INVALID WINDOW _WIN");
    }

    _win = win;

}

int Engine::add_scene(Scene *scene) {
    _sceneList[_sceneList.size()] = scene;
    return _sceneList.size() - 1;
}

bool Engine::rmv_scene(unsigned id) {
    if (has_scene(id)) { 
        _sceneList.erase(id); // Main reason why _sceneList is a map and not a list.
        return true;
    }

    return false;
}

bool Engine::has_scene(unsigned id) {
    return _sceneList.find(id) != _sceneList.end();
}

// Library Core Run
void Engine::run()
{
    for(auto it = _sceneList.begin(); it != _sceneList.end();) {
        it->second->init(*_win);
        ++it;
    }

    int i;

    while (_win->isOpen()) {
        sf::Event event;

        while (_win->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _win->close();
        }

        // if _win is nullpointer or null
        _win->clear(sf::Color::White);

        for (i = 0; i < _sceneList.size(); i++) {
        
            if (has_scene(i)) _sceneList[i]->render(_win);

        }
        _win->display();
    }
}

