#ifndef ASPECT_H
#define ASPECT_H

#include <string>
#include <SFML/Graphics.hpp>

class Aspect : public sf::Drawable {
    protected:
        std::string _type;
    public:
        void draw (sf::RenderTarget &target, sf::RenderStates states);
    protected:
        Aspect(std::string type) : _type(type){}
};

#endif // ASPECT_H