#ifndef PROP_H
#define PROP_H

#include <string>

class Prop {
private:
    std::string     _name;
    std::string     _desc;
    unsigned        _id;
public:
    Prop(std::string name, std::string description, unsigned id) : _name(name), _desc(description), _id(id) {}

    void set_name(std::string name);
    void set_description(std::string description);
    void set_id(unsigned id);
    
    std::string get_name(void);
    std::string get_description(void);
    unsigned get_id(void);
    
protected:
private:
};

#endif // PROP_H