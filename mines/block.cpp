#include <string>
#include <SFML/Graphics.hpp>
#include "block.hpp"


block::block(int val, bool cover = true, bool flag = false) : value(val), isCovered(cover), isFlagged(flag) {}
void block::click()
{
    isCovered = false;
}

void block::setValue(int val){
    value = val;
}

int block::getValue(){
    return value;
}

void block::setCover(){
    isCovered = false;
}

bool block::getCover(){
    return isCovered;
}

void block::setFlag(){
    isFlagged = !isFlagged;
}

bool block::getFlag(){
    return isFlagged;
}

sf::Text block::setup(int i, int j, sf::Font font){
    sf::Text text;
    text.setString(std::to_string(value));
    text.setFillColor(sf::Color::Black);
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(14.0f + j * 40.0f, i * 40.0f + 3.0f);
    return text;
}

void block::display(sf::RenderWindow &window, sf::Text text, int i, int j){
    sf::RectangleShape square(sf::Vector2f(40.0f, 40.0f));
    square.setPosition(40.0f*j, 40.0f*i);
    square.setFillColor(sf::Color::White);
    // square.setOutlineColor(sf::Color::Black);
    // square.setOutlineThickness(1.0f);
    window.draw(square);
    if(value != 0 && value != -1){
        window.draw(text);
    }
}