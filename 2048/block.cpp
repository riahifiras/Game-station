#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "block.hpp"

block::block(int value, int x, int y) : value(value), x(x), y(y) {}

block block::operator+(const block &other)
{
    return block(this->value + other.value, this->x + other.x, this->y + other.y);
}

int block::getValue()
{
    return block::value;
}

int block::getx()
{
    return block::x;
}

int block::gety()
{
    return block::y;
}

void block::setupRender(int i, int j, sf::Text text, sf::Font font)
{
    text.setFillColor(sf::Color::Black);
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(260.0f + j * 90.0f, 250.0f + i * 90.0f);
}

void block::render(sf::RenderWindow window, sf::Text text)
{
    text.setString(std::to_string(this->getValue()));
    window.draw(text);
}