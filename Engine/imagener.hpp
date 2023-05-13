#ifndef IMAGENER_H
#define IMAGENER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Imagener {

    private:
    sf::Texture *_img;
    sf::Sprite  *_spr;
    std::string _path;

    public:
    Imagener(std::string path);
    void set_image(std::string path);
    void draw(sf::RenderWindow &win);
    ~Imagener();

    private:
    void cook();

};

#endif // IMAGENER_H