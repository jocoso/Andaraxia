// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    05/12/2023
 * FILENAME:        ./Engine/imagener.cpp
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

#include "imagener.hpp"

Imagener::Imagener(std::string path) : Aspect("image"), _img(nullptr),  _spr(nullptr), _path(path) {
    locknload();
}

void Imagener::set_image(std::string path) {
    _path = path;
    locknload();
}

void Imagener::locknload() {
    
    reset();

    _img = new sf::Texture();
    _spr = new sf::Sprite();

    if(!_img->loadFromFile(_path)) { 
        std::cout << "Not able to make image into sprite" << std::endl;
        exit(-1);
    }

    _spr->setTexture(*_img);
}

void Imagener::reset() {
    if(_img != nullptr) {
        delete(_img);
        _img = nullptr;
    }

    if(_spr != nullptr) {
        delete(_spr);
        _spr = nullptr;
    }
}

void Imagener::init(sf::RenderWindow &window) {}

void Imagener::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*_spr);
}

void Imagener::changeSize(float width, float height) {
    locknload();
    _spr->setScale(
        width/_spr->getLocalBounds().width,
        height/_spr->getLocalBounds().height
    );
}

void Imagener::changeSize(float size) {

    _spr->setScale(
        size/_spr->getLocalBounds().width, 
        size/_spr->getLocalBounds().height 
    );

}

Imagener::~Imagener() {
    reset();
}