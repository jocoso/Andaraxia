#ifndef HUB_HPP
#define HUB_HPP

#include "prop.hpp"
#include "imagener.hpp"

// TODO: Comment
class Hub : public Prop {
    private:
        sf::RectangleShape _inputMenu;
        sf::RectangleShape _output;
        sf::RectangleShape _menuBar;
        sf::RectangleShape _placeName;
        Imagener _frame;

    public:
        // FIX: Hub take data singleton
        Hub(int id) : 
            Prop("hub", id), 
            _frame("./assets/waterfalls.jpg")
            {}

        void init(sf::RenderWindow &win);
        void render(sf::RenderWindow &win, sf::RenderStates states);
};

#endif // HUB_HPP