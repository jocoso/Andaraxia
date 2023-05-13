#ifndef HUB_HPP
#define HUB_HPP

#include "prop.hpp"
#include "imagener.hpp"

// TODO: Comment
class Hub : public Prop {
    private:
        sf::RectangleShape _inputMenu;
        Imagener _frame;
        sf::RectangleShape _output;
        sf::RectangleShape _menuBar;
    public:
        // FIX: Hub take data singleton
        Hub(int id) : Prop("hub", id), _frame("C:\\Users\\Josh\\Downloads\\handsomeman.jpg") {}
        void init(sf::RenderWindow &win);
        void render(sf::RenderWindow &win, sf::RenderStates states);
};

#endif // HUB_HPP