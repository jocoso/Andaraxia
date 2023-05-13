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
        Hub(int id) : Prop("hub", id), _frame("") {}
        void init(sf::RenderWindow &win) override;
        void render(sf::RenderWindow &win) override;
};

#endif // HUB_HPP