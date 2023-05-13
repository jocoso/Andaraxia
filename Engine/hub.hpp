#ifndef HUB_HPP
#define HUB_HPP

#include "prop.hpp"

class Hub : public Prop {
    public:
        Hub(int id) : Prop("hub", id) {}
};

#endif // HUB_HPP