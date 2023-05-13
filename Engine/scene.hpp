// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    04/08/2023
 * FILENAME:        ./Engine/scene.h
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

#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <iostream>
#include <system_error>
#include <map>
#include <stdexcept>
#include <SFML/Graphics.hpp>

#include "prop.hpp"

/*! Compartmentalize all code to be render and execute it all at once*/
class Scene {
private:
    std::map<std::string, Prop *> _propList;
protected:
    std::string _name;
    std::string _desc;
public:
    Scene();
    ~Scene();

    /**
     * @brief Adds a Prop to the list of renderable objects.
     * 
     * @param name the name of prop
     * @return true if the prop was successfully registered
     */
    bool register_prop(std::string name);

    /**
     * @brief Remove a Prop from the list of renderable objects.
     * 
     * @param id The id of the Prop to eliminate.
     * @return true if removal was successful
     * @return false if removal couldn't be achieved for a reason or another.
     */
    bool rmv_prop(std::string name);

    /**
     * @brief Renders all items inside the renderable list.
     * 
     * @param win A pointer to the window where we want the items rendered,
     */
    void render(sf::RenderWindow *win);

    /**
     * @brief Check if a prop exists inside an scene
     * 
     * @param propname the name of the prop we are looking for
     * @return true if the prop exists
     * @return false if it doesn't
     */
    bool has_prop(std::string name);

    void add_aspect(std::string name, Aspect *aspect);
    void init(sf::RenderWindow &window);
};

#endif // SCENE_HPP