#include <random>
#include <chrono>
#include <array>
#include "food.hpp"

food::food(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> xDist(0, 100);
    std::uniform_int_distribution<int> yDist(0, 100);
    setx(xDist(gen));
    sety(yDist(gen));
}

void food::generateFood(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> xDist(0, 98);
    std::uniform_int_distribution<int> yDist(0, 98);
    setx(xDist(gen));
    sety(yDist(gen));
}

void food::setx(int newX){
    x = newX;
}

void food::sety(int newY){
    y = newY;
}

std::array<int, 2> food::getFoodPosition(){
    return {x, y};
}


int food::getx(){
    return x;
}

int food::gety(){
    return y;
}
