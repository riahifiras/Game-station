#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include "sudoku.hpp"
#include "sudokuArray.hpp"

bool checkRow(int i, int j, int board[][9])
{
    for (int x = 0; x < 9; x++)
    {
        if (x != j)
        {
            if (board[i][x] == board[i][j])
                return false;
        }
    }
    return true;
}

bool checkCol(int i, int j, int board[][9])
{
    for (int x = 0; x < 9; x++)
    {
        if (x != i)
        {
            if (board[x][j] == board[i][j])
                return false;
        }
    }
    return true;
}

bool checkBox(int i, int j, int board[][9])
{
    int a = (i / 3);
    int b = (j / 3);
    for (int x = a * 3; x < a * 3 + 3; x++)
    {
        for (int y = b * 3; y < b * 3 + 3; y++)
        {
            if (x != i && y != j)
            {
                if (board[x][y] == board[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

sudoku::sudoku()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(0, 49);
    int randomIndex = dist(gen);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board[i][j] = sudokuGrids[randomIndex][i][j];
            }
        }
}

bool sudoku::checkBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if ((checkRow(i, j, board) && checkCol(i, j, board) && checkBox(i, j, board)) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int** sudoku::getboard(){
    int** ptr = new int*[9];
    for (int i = 0; i < 9; ++i) {
        ptr[i] = new int[9];
        for (int j = 0; j < 9; ++j) {
            ptr[i][j] = board[i][j];
        }
    }
    return ptr;
}

void sudoku::setNumber(int i, int j, int num){
    board[i][j] = num;
}

void sudoku::showBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << board[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}