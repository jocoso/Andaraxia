#ifndef HUB_HPP
#define HUB_HPP

#include "prop.hpp"
#include "imagener.hpp"

// TODO: Comment

struct Point {
    std::string id;
    std::string type;
    std::string title;
    std::string desc;
};

class Hub : public Prop {
    private:
        sf::RectangleShape _inputMenu;
        sf::RectangleShape _output;
        sf::RectangleShape _menuBar;
        sf::RectangleShape _placeName;
        Imagener _frame;

    public:
        // FIX: Hub take data singleton
        Hub() : 
            Prop("hub"),
            _frame("./assets/waterfalls.jpg")
            {}

        void init(sf::RenderWindow &win);
        void change_point(Point &pt);
        void render(sf::RenderWindow &win) override;
};

#endif // HUB_HPP