#ifndef HUB_H
#define HUB_H

#include "./aspect.h"
#include <iostream>

class Hub : public Aspect {
    private:

        sf::RectangleShape _char_menu;
        sf::RectangleShape _hub_picture;
        sf::RectangleShape _output;
        sf::RectangleShape _input;

    public:
        Hub();
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void init(sf::RenderWindow &window) override;
};

#endif // HUB_H