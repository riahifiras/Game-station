#ifndef SUDOKU_H
#define SUDOKU_H

class sudoku
{
private:
    int board[9][9];
public:
    sudoku();
    bool checkBoard();
    int** getboard();
    void setNumber(int, int, int);
    void showBoard();
};



#endif