// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    04/16/2023
 * FILENAME:        ./engine/prop.cpp
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

#include "./prop.h"

void Prop::set_name(std::string name) {
    _name = name;
}

void Prop::set_id(unsigned id) {
    _id = id;
}

std::string Prop::get_name() {
    return _name;
}

unsigned Prop::get_id() {
    return _id;
}

unsigned Prop::add_aspect(Aspect *aspect) {
    
    _aspectList[_aspectList.size()] = aspect;
    return _aspectList.size() - 1;

}

bool Prop::rmv_aspect(unsigned id) {

    if(_aspectList.find(id) != _aspectList.end()) {  // Found inside the map
        _aspectList.erase(id);                      
        return true;
    }
    return false;

}

void Prop::render(sf::RenderWindow &win) {
    for(auto it = _aspectList.begin(); it != _aspectList.end();) {
        win.draw(*it->second);
        ++it;
    }
}