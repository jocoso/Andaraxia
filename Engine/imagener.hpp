// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    05/12/2023
 * FILENAME:        ./Engine/imagener.hpp
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
#ifndef IMAGENER_H
#define IMAGENER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

/*! Creates a standalone image that don't require multiple definitions of texture and sprites */
class Imagener {

    private:
    sf::Texture *_img;
    sf::Sprite  *_spr;
    std::string _path;

    public:
    Imagener(std::string path);

    /**
     * @brief Set the image path
     * 
     * @param path 
     */
    void set_image(std::string path);

    /**
     * @brief Draw the image to the screen
     * 
     * @param win 
     */
    void draw(sf::RenderWindow &win);

    /**
     * @brief Memory deallocation of img and spr
     */
    void reset();

    ~Imagener();

    private:
    /**
     * @brief Meat of the class. Delete and reload image.
     * 
     */
    void locknload();

};

#endif // IMAGENER_H