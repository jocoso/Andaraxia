// -*- lsst-c++ -*-

/**************************************************************************
 * 
 * NAME:            Novella Engine
 * VERSION:         0.1
 * LASTREVISION:    05/18/2023
 * FILENAME:        ./Engine/datareader.hpp
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
#ifndef DATA_READER_HPP
#define DATA_READER_HPP

#include <string>
#include <mutex>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

#include "hub.hpp"

using json = nlohmann::json;

/*! Create Data from .nva file */
class DataReader {
    private:
        static DataReader* _pInstance;
        static std::mutex _mutex;

    protected:
        std::string _datapath;
        json _data;

        /**
         * @brief Construct a new Data Reader object
         * 
         * @param datapath the path to the .nva file
         */
        DataReader(const std::string datapath): _datapath(datapath) {
            update();
        }

        /**
         * @brief Update content from .nva file
         */
        void update();

        /**
         * @brief Destroy the Data Reader object
         */
        ~DataReader() {}
    
    public:
        // Deleting unneeded features
        DataReader(DataReader &other) = delete;
        void operator=(const DataReader &) = delete;

        /**
         * @brief Get the Data object 
         * 
         * @param value the path to the .nva file
         * @return DataReader* 
         */
        static DataReader *getData(const std::string& value);

        /**
         * @brief Get a Point object
         * 
         * @param id name of the data we are looking for
         * @return Point& 
         */
        Point &getPoint(std::string id);

        /**
         * @brief Return the path given
         * 
         * @return std::string 
         */
        std::string datapath() const {
            return _datapath;
        }

        Prop *point2prop(Point &pt);
};

#endif // DATA_READER_HPP