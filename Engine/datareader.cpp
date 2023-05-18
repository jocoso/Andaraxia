// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    05/18/2023
 * FILENAME:        ./Engine/datareader.cpp
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
#include "datareader.hpp"

DataReader *DataReader::_pInstance{nullptr};
std::mutex DataReader::_mutex;

DataReader *DataReader::getData(const std::string &datapath) { // Singleton creates instance here
    std::lock_guard<std::mutex> lock(_mutex); // Making sure no more than one instance was created

    if(_pInstance == nullptr) {
        _pInstance = new DataReader(datapath);
    }

    return _pInstance;
}

void DataReader::update() {
    // Add Sanity Check
    std::ifstream f(_datapath);
    _data = json::parse(f);
}

Point &DataReader::getPoint(std::string id) {
    update();
    Point r;
    
    for(long long unsigned int i = 0; i < _data.at("points").size(); i++) {
        if(_data.at("points").at(i).at("id") == id) {
  
            r.id = _data.at("points").at(i).at("id");
            r.type = _data.at("points").at(i).at("type");
            r.title = _data.at("points").at(i).at("title");
            r.desc = _data.at("points").at(i).at("desc");

        }
    }

    return r;
}
