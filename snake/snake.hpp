#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <array>

class snake
{
private:
    std::vector<std::array<int, 2>> cells;
    char orientation;
public:
    snake();
    void expand();
    void forward();
    void shift(char direction);
    bool bitSelf();
    void showSnake();
    void setOrientation(char);
    char getOrientaion();
    std::vector<std::array<int, 2>> getCells();
};


#endif