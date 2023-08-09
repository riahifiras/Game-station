#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>

class block
{
private:
    bool isCovered;
    bool isFlagged;
    int value;
public:
    block() : isCovered(true), isFlagged(false), value(0) {}
    block(int, bool, bool);
    int getValue();
    void setValue(int);
    bool getCover();
    void setCover();
    bool getFlag();
    void setFlag();
    void click();
    sf::Text setup(int, int, sf::Font);
    void display(sf::RenderWindow &window, sf::Text text, int i, int j);
};


#endif