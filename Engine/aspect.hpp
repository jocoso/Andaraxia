// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    05/12/2023
 * FILENAME:        ./Engine/aspect.hpp
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

#ifndef ASPECT_HPP
#define ASPECT_HPP

#include <string>
#include <SFML/Graphics.hpp>

/*! Adds a functionality to props. Aspects are small programable features that runs independently
inside a prop. */
class Aspect : public sf::Drawable {
    protected:
        std::string _type;
    public:

        /**
         * @brief Any drawing should be done in this function.
         * 
         * @param target Where to draw.
         * @param states 
         */
        void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

        // TODO: Instead of window, it should be a Data Singleton passed.
        /**
         * @brief Any initialization should be done in this function.
         * 
         * @param window 
         */
        virtual void init(sf::RenderWindow &window) = 0;

        /**
         * @brief Construct a new Aspect object
         * 
         * @param type The category of Aspect (helps with organization)
         */
        Aspect(std::string type) : _type(type){}
};

#endif // ASPECT_HPP