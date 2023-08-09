#ifndef FOOD_H
#define FOOD_H

#include <array>

class food
{
private:
    int x, y;
public:
    food();
    void generateFood();
    void setx(int);
    void sety(int);
    std::array<int, 2> getFoodPosition();
    int getx();
    int gety();
};


#endif