#include "datareader.hpp"

DataReader *DataReader::_pInstance{nullptr};
std::mutex DataReader::_mutex;

DataReader *DataReader::getData(const std::string &datapath) {
    std::lock_guard<std::mutex> lock(_mutex);

    if(_pInstance == nullptr) {
        _pInstance = new DataReader(datapath);
    }

    return _pInstance;
}