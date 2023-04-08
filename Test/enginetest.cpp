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

bool returnErrorWhenParamIsNULL() {
    try {
        Engine e(nullptr);
        return false;
    } catch(std::exception &e) {
        return true;
    }
}

bool adding3PropsAndGetProperID() {
    try {

        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Prop p0; // ID 0
        Prop p1; // ID 1
        Prop p2; // ID 2

        p0.add_component("ID 0");
        p1.add_component("ID 1");
        p2.add_component("ID 2");

        unsigned a = e.add_prop(&p0);
        unsigned b = e.add_prop(&p1);
        unsigned c = e.add_prop(&p2);

        if(a == 0 && b == 1 && c == 2) {
            return true;
        } else {
            return false;
        }

    } catch(std::exception &e) {
        return false;
    }
}

bool adding3PropsAndRemoveOneSuccessfully() {
    try{
        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Prop p0; // ID 0
        Prop p1; // ID 1
        Prop p2; // ID 2

        p0.add_component("ID 0");
        p1.add_component("ID 1");
        p2.add_component("ID 2");

        unsigned a = e.add_prop(&p0);
        unsigned b = e.add_prop(&p1);
        unsigned c = e.add_prop(&p2);

        bool res = e.rmv_prop(b);

        if(res && e.has_prop(a) && !e.has_prop(b) && e.has_prop(c)) return true;
        else return false;
    } catch(std::exception &e) {
        return false;
    }


}

void assert(bool assertion, std::string success_msg, std::string failure_msg) {
    if(assertion) {
        std::cout << "SUCCESS: " << success_msg << std::endl;
    } else {
        std::cout << "FAILED: " << failure_msg << std::endl;
    }
}

int main() {
    assert(
        canInitEngine(), 
        "Engine was initialized without issue", 
        "Engine couldn't be initialized"
    );

    assert(
        returnErrorWhenParamIsNULL(),
        "Given a null pointer as constructor parameter return error",
        "Given a null pointer as constructor parameter does not return error"
    );

    assert(
        adding3PropsAndGetProperID(),
        "Get ID that makes sense",
        "Ids don't make sense"
    );

    assert(
        adding3PropsAndRemoveOneSuccessfully(),
        "Able to add and remove props keeping ID Integrity",
        "Unable to add and remove props keeping ID Integrity"
    );
}