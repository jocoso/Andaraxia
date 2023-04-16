#ifndef PROP_H
#define PROP_H

#include <string>
#include <system_error>
#include <map>
#include <stdexcept>

class Prop {
private:
    std::string     _name;
    std::string     _desc;
    unsigned        _id;
    std::map<unsigned, std::string> _aspectList;

public:
    Prop(std::string name, std::string description, unsigned id) : _name(name), _desc(description), _id(id) {}

    void set_name(std::string name);
    void set_description(std::string description);
    void set_id(unsigned id);
    
    std::string get_name(void);
    std::string get_description(void);
    unsigned get_id(void);

    unsigned add_aspect(std::string aspectname);
    bool rmv_aspect(unsigned id);
    
protected:
private:
};

#endif // PROP_H