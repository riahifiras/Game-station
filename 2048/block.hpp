#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class block
{
private:
    int value;
    int x, y;

public:
    block() : value(0), x(0), y(0) {}
    block(int, int, int);
    int getValue();
    int getx();
    int gety();
    void setupRender(int, int, sf::Text, sf::Font);
    void render(sf::RenderWindow, sf::Text);
    block operator+(const block &other);
};

#endif
