// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    04/08/2023
 * FILENAME:        ./engine/engine.h
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

#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <system_error>
#include <map>
#include <stdexcept>
#include <SFML/Graphics.hpp>

#include "./scene.h"

/*! Creates and execute all Scenes, menus and other core processes */
class Engine {
private:
    std::map<int, Scene*> _sceneList; // Made a map to keep id integrity when erasing
    sf::RenderWindow *_win = nullptr;
public:
    Engine(sf::RenderWindow *_win);

    /**
     * @brief Adds an instance of Scene to the Engine for it to execute
     * 
     * @param prop An Scene to display
     * @return int Id of the given scene needed to access it inside Engine
     */
    int add_scene(Scene *scene);

    /**
     * @brief Removes an instance of Scene from the Engine list
     * 
     * @param id The id of the scene to eliminate.
     * @return true if removal was successful
     * @return false if removal couldn't be achieved for a reason or another
     */
    bool rmv_scene(unsigned id);

    /**
     * @brief Check if an scene exists in the Engine list.
     * 
     * @param id id of the scene to look for.
     * @return true if the scene is in the list,
     * @return false otherwise.
     */
    bool has_scene(unsigned id);



    /**
     * @brief Open the main window and 
     * render every scene on it.
     */
    void run(void);
};

#endif // ENGINE_H