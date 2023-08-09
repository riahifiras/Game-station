#ifndef BOARD_H
#define BOARD_H

#include "block.hpp"

class board
{
private:
    block grid[4][4];

public:
    board();
    void shift(char direction);
    void generate();
    block (*getBoard())[4];
    void render();
    void showBoard();
};

#endif