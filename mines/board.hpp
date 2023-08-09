#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include "block.hpp"

class board
{
private:
    block grid[20][20];
    int bombs = 50;

public:
    board();
    std::string click(int, int);
    void showBoard();
    void showCoveredBoard();
    block (*getBoard())[20];
    void display(sf::RenderWindow, sf::Font);
};

#endif