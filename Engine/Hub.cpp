#include "hub.hpp"



void Hub::init(sf::RenderWindow &win) {

    // INPUT MENU
    float inputMenuSizeWidth  = win.getSize().x;
    float inputMenuSizeHeight = win.getSize().y*0.05; // 5 percent

    _inputMenu.setPosition(0.f, 0.f);
    _inputMenu.setSize(sf::Vector2f(inputMenuSizeWidth, inputMenuSizeHeight));
    _inputMenu.setFillColor(sf::Color::Yellow);

    // PLACE NAME
    float frameNameAndOutputSizeWidth  = win.getSize().x * 0.40; // 40 percent
    float placeNameHeight              = win.getSize().y * 0.10; // 20 percent

    _placeName.setPosition(
        (frameNameAndOutputSizeWidth / 2) - (frameNameAndOutputSizeWidth / 3), 
        inputMenuSizeHeight + 20 /* Small padding */
        ); // Centered
    _placeName.setSize(sf::Vector2f(frameNameAndOutputSizeWidth/2, placeNameHeight));
    _placeName.setFillColor(sf::Color::Green);

    // FRAME
    float frameSizeHeight = win.getSize().y * 0.95; // 75 percent

    _frame.setPosition(0.f, inputMenuSizeHeight);
    _frame.changeSize(frameNameAndOutputSizeWidth, frameSizeHeight);

    // OUTPUT
    float generalSizeHeight = win.getSize().y * 0.95; // 95 percent

    _output.setPosition(frameNameAndOutputSizeWidth, inputMenuSizeHeight);
    _output.setSize(sf::Vector2f(frameNameAndOutputSizeWidth, generalSizeHeight));
    _output.setFillColor(sf::Color::Red);

    // MENU BAR
    float menuBarPosX      = frameNameAndOutputSizeWidth*2;
    float menuBarSizeWidth = win.getSize().x*0.20;

    _menuBar.setPosition(menuBarPosX, inputMenuSizeHeight);
    _menuBar.setSize(sf::Vector2f(menuBarSizeWidth, generalSizeHeight));
    _menuBar.setFillColor(sf::Color::Magenta);

}

void Hub::render(sf::RenderWindow &win) {
    win.draw(_inputMenu);
    win.draw(_frame);
    win.draw(_placeName);
    win.draw(_output);
    win.draw(_menuBar);
}

void Hub::change_point(Point &scn) {

}