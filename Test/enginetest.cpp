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

bool adding3ScenesWNoErrors() {
    try {

        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Scene s1;
        Scene s2;
        Scene s3;

        e.add_scene(&s1);
        e.add_scene(&s2);
        e.add_scene(&s3);

        return true;

    } catch(std::exception &e) {
        return false;
    }
}

// No Run
bool registerAPropTo3ScenesAndAddToEngineNR() {
    try{
        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Scene s0; // ID 0
        Scene s1; // ID 1
        Scene s2; // ID 2

        s0.register_prop("a prop", "to love");
        s1.register_prop("another", "to hate");
        s2.register_prop("a third", "to relate");

        e.add_scene(&s0);
        e.add_scene(&s1);
        e.add_scene(&s2);

        return true;

    } catch(std::exception &e) {
        return false;
    }
}

// NR = No Run
bool canRegisterAndRemovePropsWithoutThrowingException0NR() {
    try {
        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Scene s0; // ID 0
        Scene s1; // ID 1
        Scene s2; // ID 2

        s0.register_prop("a prop", "to love");
        s1.register_prop("another", "to hate");
        s2.register_prop("a third", "to relate");

        unsigned a = e.add_scene(&s0);
        unsigned b = e.add_scene(&s1);
        unsigned c = e.add_scene(&s2);

        e.rmv_scene(a);
        e.rmv_scene(b);

        return !e.has_scene(a) && !e.has_scene(b) && e.has_scene(c);

    } catch(std::exception &e) {
        return false;
    }
}

// NR = No Run
bool canRegisterAndRemovePropsWithoutThrowingException1NR() {
    try {
        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Scene s0; // ID 0
        Scene s1; // ID 1
        Scene s2; // ID 2

        s0.register_prop("a prop", "to love");
        s1.register_prop("another", "to hate");
        s2.register_prop("a third", "to relate");

        unsigned a = e.add_scene(&s0);
        unsigned b = e.add_scene(&s1);
        unsigned c = e.add_scene(&s2);

        e.rmv_scene(b);

        return e.has_scene(a) && !e.has_scene(b) && e.has_scene(c);

    } catch(std::exception &e) {
        return false;
    }
}

// NR = No Run
bool removingASceneTwiceWillThrowAnError() {
    try {
        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Scene s0; // ID 0
        Scene s1; // ID 1
        Scene s2; // ID 2

        s0.register_prop("a prop", "to love");
        s1.register_prop("another", "to hate");
        s2.register_prop("a third", "to relate");

        unsigned a = e.add_scene(&s0);
        unsigned b = e.add_scene(&s1);
        unsigned c = e.add_scene(&s2);

        e.rmv_scene(b);
        

        return !e.rmv_scene(b);

    } catch(std::exception &e) {
        return true;
    }
}

bool registerAPropAlreadyInAndGetError() {
    
    try{
        sf::RenderWindow window(sf::VideoMode(800, 500), "Prototype 0.0.0");
        Engine e(&window);

        Scene s0;

        s0.register_prop("one", "two");
        s0.register_prop("one", "three");

        e.add_scene(&s0);

        return false;

    }catch(std::exception &e) {

        return true;

    }

}

void assert(bool assertion, std::string success_msg, std::string failure_msg) {
    if(assertion) {
        std::cout << "=====> SUCCESS: " << success_msg << " <=====" << std::endl;
    } else {
        std::cout << "=====> FAILED: " << failure_msg << " <=====" << std::endl;
    }
}

int main() {
    assert(
        canInitEngine(),
        "Engine was initialized properly",
        "Engine failed to initialize"
    );

    assert(
        returnErrorWhenParamIsNULL(),
        "Engine returned an error when param is null",
        "Engine failed to return an error when parameter was null"
    );

    assert(
        registerAPropTo3ScenesAndAddToEngineNR(),
        "Registering some props to scene didn't return any error state",
        "Registering some props to scene returned an error state"
    );

    assert(
        registerAPropAlreadyInAndGetError(),
        "Registering two props with the same name throws an exception",
        "Registering two props with the same name doesn't throw an exception"
    );

    assert(
        canRegisterAndRemovePropsWithoutThrowingException0NR(),
        "Adding and Removing props remains consistent",
        "Adding and Removing props isn't consistent"
    );

    assert(
        canRegisterAndRemovePropsWithoutThrowingException1NR(),
        "Adding and Removing props remains consistent",
        "Adding and Removing props isn't consistent"
    );

    assert(
        removingASceneTwiceWillThrowAnError(),
        "Engine Threw error when trying to remove a prop twice",
        "To throw error when removing a prop twice"
    );

    return 0;
}