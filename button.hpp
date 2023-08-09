#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <SFML/Graphics.hpp>

class button
{
private:
    float posX, posY;
    std::string action = "";
    std::string image = "";
    std::string buttonText = "";
public:
    button(float, float, std::string, std::string);
    float getPosX();
    float getPosY();
    std::string getAction();
    std::string getImage();
    void setAction(std::string);
    bool hover();
    void click();
    void render(sf::RenderWindow &window);
};

#endif