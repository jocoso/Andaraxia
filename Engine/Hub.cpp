#include "Hub.h"

Hub::Hub() : Aspect("hub") {
}

void Hub::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_char_menu);
    target.draw(_hub_picture);
    target.draw(_output);
    target.draw(_input);
}

void Hub::init(sf::RenderWindow &window) {
    float menu_size = window.getSize().x/4;
        // Creating our shape.
    _char_menu.setSize(sf::Vector2f(menu_size, window.getSize().y));
    _char_menu.setFillColor(sf::Color::Red);
    _char_menu.setPosition(0, 0);

    _hub_picture.setSize(sf::Vector2f(window.getSize().x - menu_size, window.getSize().y * 0.5));
    _hub_picture.setFillColor(sf::Color::Blue);
    _hub_picture.setPosition(menu_size, 0);

    _output.setSize(sf::Vector2f(window.getSize().x - menu_size, window.getSize().y * 0.4));
    _output.setFillColor(sf::Color::Green);
    _output.setPosition(menu_size, window.getSize().y * 0.5);

    _input.setSize(sf::Vector2f(window.getSize().x - menu_size, window.getSize().y * 0.1));
    _input.setFillColor(sf::Color::Yellow);
    _input.setPosition(menu_size, window.getSize().y * 0.9);
  
    //_char_menu.setOrigin(_char_menu.getSize().x / 2, _char_menu.getSize().y / 2);
}