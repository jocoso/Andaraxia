#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine/engine.hpp"
#include "Engine/hub.hpp"
#include "Engine/datareader.hpp"

int main() {
    DataReader* dr = DataReader::getData("./data/data.nva");
    sf::RenderWindow window(sf::VideoMode(800, 700), "prototype 0.0.0");
    
    Engine e(&window, dr);
    e.run();

    return 0;
}