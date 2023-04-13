// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    04/08/2023
 * FILENAME:        ./engine/scene.cpp
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

#include "./scene.h"

int Scene::add_component(std::string placeholdername) {
    _componentList[_componentList.size()] = placeholdername;
    return _componentList.size() -1;
}

bool Scene::rmv_component(int id) {
    if(_componentList.find(id) != _componentList.end()) {
        _componentList.erase(id);
        return true;
    }

    return false;
}

void Scene::render(sf::RenderWindow *win) {
    for(auto it = _componentList.begin(); it != _componentList.end();) {
        std::cout << it->first << " : " << it->second << std::endl;
        ++it;
    }
}