// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    04/16/2023
 * FILENAME:        ./engine/prop.h
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

#ifndef PROP_H
#define PROP_H

#include <string>
#include <system_error>
#include <map>
#include <stdexcept>

/*! A customizable container for everything that requires rendering in a scene */
class Prop {
private:
    std::string     _name;
    std::string     _desc;
    unsigned        _id;
    std::map<unsigned, std::string> _aspectList; // Made a map to keep id integrity when erasing

public:
    Prop(std::string name, std::string description, unsigned id) : _name(name), _desc(description), _id(id) {}

    /**
     * @brief Changes the name of the Prop
     * 
     * @param name Name of the prop
     */
    void set_name(std::string name);

    /**
     * @brief Changes the description of the Prop
     * 
     * @param description Description of the prop
     */
    void set_description(std::string description);

    // TODO: Delete this because the id is something that must be managed internally and never changed by the user
    void set_id(unsigned id);
    
    /**
     * @brief Get the name of the Prop
     * 
     * @return A string representing name of the prop
     */
    std::string get_name(void);

    /**
     * @brief Get the description of the Prop
     * 
     * @return A string representing the description of the prop
     */
    std::string get_description(void);

    /**
     * @brief Get the id of the Prop
     * 
     * @return An unsigned int representing an id of the prop
     */
    unsigned get_id(void);

    /**
     * @brief Adds an instance of an Aspect to the prop
     * 
     * @param aspectname aspect instance
     * @return an unsigned int representing the id of the aspect inside the Prop class
     */
    unsigned add_aspect(std::string aspectname);

    /**
     * @brief Removes an instance of an aspect from the prop
     * 
     * @param id ID of the instance to be removed
     * @return true if the instance could be removed successfully
     * @return false if the instance was already removed from the Prop
     */
    bool rmv_aspect(unsigned id);
    
    // TODO: Add a render method class
protected:
private:
};

#endif // PROP_H