#ifndef HUB_H
#define HUB_H

#include "./aspect.h"

class Hub : public Aspect {
    protected:
        Hub();
    public:
        void draw (sf::RenderTarget &target, sf::RenderStates states);
};

#endif // HUB_H