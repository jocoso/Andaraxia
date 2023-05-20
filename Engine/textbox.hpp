#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include "aspect.hpp"

class TextBox : public Aspect {
private:
    sf::RectangleShape _background;
    sf::Text _text;
    sf::Font _font;
    int font;
public:
    TextBox() : Aspect("textbox") {}
    void init();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
}

#endif // TEXT_BOX_HPP