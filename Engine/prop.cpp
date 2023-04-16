#include "./prop.h"

void Prop::set_name(std::string name) {
    _name = name;
}

void Prop::set_description(std::string description) {
    _desc = description;
}

void Prop::set_id(unsigned id) {
    _id = id;
}

std::string Prop::get_name() {
    return _name;
}

std::string Prop::get_description() {
    return _desc;
}

unsigned Prop::get_id() {
    return _id;
}