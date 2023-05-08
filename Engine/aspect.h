#ifndef ASPECT_H
#define ASPECT_H

#include <string>
#include <SFML/Graphics.hpp>

class Aspect : public sf::Drawable {
    protected:
        std::string _type;
    public:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
        virtual void init(sf::RenderWindow &window) = 0;
        Aspect(std::string type) : _type(type){}
};

#endif // ASPECT_H