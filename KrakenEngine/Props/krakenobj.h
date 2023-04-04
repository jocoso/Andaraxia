#ifndef KRAKEN_OBJECT_H
#define KRAKEN_OBJECT_H

#include <string>

class KrakenObject {
private:
    std::string _obj_name;
    std::string _obj_desc;
public:
    KrakenObject(std::string object_name, std::string object_description);
}


#endif // KRAKEN_OBJECT_H