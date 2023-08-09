#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "button.hpp"

button::button(float newPosX, float newPosY, std::string newAction, std::string newImage) :  posX(newPosX), posY(newPosY), action(newAction), image(newImage){};

void button::setAction(std::string newAction)
{
    action = newAction;
}

float button::getPosX()
{
    return posX;
}

float button::getPosY()
{
    return posY;
}

std::string button::getAction()
{
    return action;
}

std::string button::getImage()
{
    return image;
}


void button::render(sf::RenderWindow &window){
    sf::Texture texture;
    if (!texture.loadFromFile(image))
    {
        std::cout << "woops" << std::endl;
    }
    sf::Sprite sprite(texture);
    sprite.setPosition(posX , posY);
    window.draw(sprite);
}