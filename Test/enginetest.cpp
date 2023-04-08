#include "../Engine/engine.h"
#include <SFML/Graphics.hpp>
#include <system_error>
#include <string>
#include <iostream>

bool canInitEngine() {
    try {
        sf::RenderWindow window(sf::VideoMode(800, 500), "prototype 0.0.0");
        Engine e(&window);
        return true;
    } catch(std::exception &e) {
        return false;
    }
}

void assert(bool assertion, std::string success_msg, std::string failure_msg) {
    if(assertion) {
        std::cout << "SUCCESS:" << success_msg << std::endl;
    } else {
        std::cout << "FAILED:" << failure_msg << std::endl;
    }
}

int main() {
    assert(
        canInitEngine(), 
        "Engine was initialized without issue", 
        "Engine couldn't be initialized"
    );
}