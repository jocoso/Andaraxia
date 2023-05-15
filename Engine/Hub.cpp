#include "hub.hpp"

void Hub::init(sf::RenderWindow &win) {
    _inputMenu.setPosition(0.f, 0.f);
    _inputMenu.setSize(sf::Vector2f(win.getSize().x, win.getSize().y*0.05));
    _inputMenu.setFillColor(sf::Color::Yellow);

    _frame.setPosition(0.f, win.getSize().y*0.05);
    _frame.changeSize(win.getSize().x*0.75, win.getSize().y*0.475);

    _output.setPosition(0.f, win.getSize().y*0.525);
    _output.setSize(sf::Vector2f(win.getSize().x*0.75, win.getSize().y*0.475));
    _output.setFillColor(sf::Color::Red);

    _menuBar.setPosition(win.getSize().x*0.75, win.getSize().y*0.05);
    _menuBar.setSize(sf::Vector2f(win.getSize().x*0.25, win.getSize().y*0.95));
    _menuBar.setFillColor(sf::Color::Magenta);
}

void Hub::render(sf::RenderWindow &win, sf::RenderStates states) {
    win.draw(_inputMenu);
    _frame.draw(win, states);
    win.draw(_output);
    win.draw(_menuBar);
}