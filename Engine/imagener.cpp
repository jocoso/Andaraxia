#include "imagener.hpp"

Imagener::Imagener(std::string path) {
    _path = path;
    _img = nullptr;
    _spr = nullptr;
    cook();
}

void Imagener::set_image(std::string path) {
    _path = path;
    cook();
}

void Imagener::cook() {
    if(_img != nullptr) delete(_img);
    if(_spr != nullptr) delete(_spr);

    _img = new sf::Texture();
    _spr = new sf::Sprite();

    if(!_img->loadFromFile(_path)) {
        std::cout << "Not able to make image into sprite" << std::endl;
        exit(-1);
    }

    _spr->setTexture(*_img);
}

void Imagener::draw(sf::RenderWindow &win) {
    win.draw(*_spr);
}

Imagener::~Imagener() {
    if(_img != nullptr) delete(_img);
    if(_spr != nullptr) delete(_spr);
}