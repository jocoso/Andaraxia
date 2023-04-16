#include "../Engine/engine.h"
#include <SFML/Graphics.hpp>
#include <system_error>
#include <string>
#include <iostream>

#include "../Engine/prop.h"

bool can_be_instantiated() {
    try {
        Prop test0("aname", "adescription", 0);
        return true;
    } catch(std::exception &e) {
        return false;
    } 
}

bool add_multiple_aspects_to_prop() {
    try {
        Prop test0("aname", "adescription", 0);
        
        test0.add_aspect("sprite");
        test0.add_aspect("text");

        return true;
    } catch(std::exception &e) {
        return false;
    }
}

bool rmving_3_added_aspect_1() {
    try {
        Prop test0("aname", "adescription", 0);
        
        unsigned a = test0.add_aspect("sprite");
        unsigned b = test0.add_aspect("text");
        unsigned c = test0.add_aspect("text");

        return test0.rmv_aspect(a);
    } catch(std::exception &e) {
        return false;
    }
}

void assert(bool assertion, std::string success_msg, std::string failure_msg) {
    if(assertion) {
        std::cout << "SUCCESS => " << success_msg << std::endl;
    } else {
        std::cout << "FAILED => " << failure_msg << std::endl;
    }
}

int main() {
    assert(
        can_be_instantiated(), 
        "Prop was instantiated.", 
        "Prop failed to instantiate"
    );

    assert(
        add_multiple_aspects_to_prop(),
        "Added dummy aspect",
        "Unable to add dummy aspect"
    );

    assert(
        rmving_3_added_aspect_1(),
        "Added and removing works",
        "Added and removing return an error"
    );

}
