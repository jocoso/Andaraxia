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
