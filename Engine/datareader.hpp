#ifndef DATA_READER_HPP
#define DATA_READER_HPP

#include <string>
#include <mutex>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

class DataReader {
    private:
        static DataReader* _pInstance;
        static std::mutex _mutex;

    protected:
        std::string _datapath;
        json _data;
        DataReader(const std::string datapath): _datapath(datapath) {
            std::ifstream f(_datapath);
            _data = json::parse(f);
        }
        ~DataReader() {}
    
    public:
        DataReader(DataReader &other) = delete;
        void operator=(const DataReader &) = delete;
        static DataReader *getData(const std::string& value);
        std::string datapath() const {
            return _datapath;
        }
};

#endif // DATA_READER_HPP