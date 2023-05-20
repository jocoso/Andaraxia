// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    04/16/2023
 * FILENAME:        ./Engine/prop.h
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

#ifndef PROP_HPP
#define PROP_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <system_error>
#include <map>
#include <stdexcept>

#include "aspect.hpp"

/*! A customizable container for everything that requires rendering in a scene */
class Prop {
private:
    std::string                  _name;
    std::map<unsigned, Aspect *> _aspectList; // Made a map to keep id integrity when erasing

public:
    Prop(std::string name) :  _name(name) {}
    virtual ~Prop() {}

    /**
     * @brief Changes the name of the Prop
     * 
     * @param name Name of the prop
     */
    void set_name(std::string name);
    
    /**
     * 
     * @brief Get the name of the Prop
     * @return A string representing name of the prop
     * 
     */
    std::string get_name(void);

    /**
     * @brief Adds an instance of an Aspect to the prop
     * 
     * @param aspect aspect instance
     * @return an unsigned int representing the id of the aspect inside the Prop class
     */
    unsigned add_aspect(Aspect *aspect);

    /**
     * @brief Removes an instance of an aspect from the prop
     * 
     * @param id ID of the instance to be removed
     * @return true if the instance could be removed successfully
     * @return false if the instance was already removed from the Prop
     */
    bool rmv_aspect(unsigned id);

    /**
     * @brief Renders all the Aspects in the prop
     * 
     * @param win Target window where to render.
    */
    virtual void render(sf::RenderWindow &win) {
        for(auto it = _aspectList.begin(); it != _aspectList.end();) {
            win.draw(*it->second);
            ++it;
        }
    }
    
    /**
     * @brief Called before rendering. Initialize all needed variables.
     * 
     * @param win Window used to render
     */
    virtual void init(sf::RenderWindow &win);
};

#endif // PROP_HPP