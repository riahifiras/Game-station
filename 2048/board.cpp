#include <iostream>
#include <random>
#include <chrono>
#include "board.hpp"
#include "block.hpp"

using namespace std;

board::board()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 3 && j == 0)
                grid[i][j] = block(2, i, j);
            else
                grid[i][j] = block(0, i, j);
        }
    }
}

void board::generate()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> rowDist(0, 3);
    std::uniform_int_distribution<int> colDist(0, 3);

    int i = rowDist(gen);
    int j = colDist(gen);
    while (grid[i][j].getValue() != 0)
    {
        i = rowDist(gen);
        j = colDist(gen);
    }
    grid[i][j] = block(2, i, j);
}

block (*board::getBoard())[4]
{
    return grid;
}

void board::shift(char direction)
{   
    bool shifted = false;
    switch (direction)
    {
    case 'u':
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j].getValue() != 0)
                {
                    for (int k = i + 1; k < 4; k++)
                    {
                        if(grid[k][j].getValue() != 0 && grid[k][j].getValue() != grid[i][j].getValue()){
                            break;
                        }
                        if (grid[k][j].getValue() == grid[i][j].getValue())
                        {
                            grid[i][j] = grid[i][j] + grid[k][j];
                            grid[k][j] = block(0, i, j);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j].getValue() == 0){
                    for (int k = i + 1; k < 4; k++)
                    {
                        if (grid[k][j].getValue() != 0)
                        {
                            grid[i][j] = grid[k][j];
                            grid[k][j] = block(0, i, j);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        break;
    case 'd':
        for (int i = 3; i > 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j].getValue() != 0)
                {
                    for (int k = i - 1; k > -1; k--)
                    {
                        if(grid[k][j].getValue() != 0 && grid[k][j].getValue() != grid[i][j].getValue()){
                            break;
                        }
                        if (grid[k][j].getValue() == grid[i][j].getValue())
                        {
                            grid[i][j] = grid[i][j] + grid[k][j];
                            grid[k][j] = block(0, i, j);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 3; i > 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j].getValue() == 0)
                {
                    for (int k = i - 1; k > -1; k--)
                    {
                        if (grid[k][j].getValue() != 0)
                        {
                            grid[i][j] = grid[k][j];
                            grid[k][j] = block(0, i, j);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        break;
    case 'l':
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[j][i].getValue() != 0)
                {
                    for (int k = i + 1; k < 4; k++)
                    {
                        if(grid[j][k].getValue() != 0 && grid[j][k].getValue() != grid[j][i].getValue()){
                            break;
                        }
                        if (grid[j][k].getValue() == grid[j][i].getValue())
                        {
                            grid[j][i] = grid[j][i] + grid[j][k];
                            grid[j][k] = block(0, j, i);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[j][i].getValue() == 0)
                {
                    for (int k = i + 1; k < 4; k++)
                    {
                        if (grid[j][k].getValue() != 0)
                        {
                            grid[j][i] = grid[j][k];
                            grid[j][k] = block(0, j, i);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        break;
    case 'r':
        for (int i = 3; i > 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[j][i].getValue() != 0)
                {
                    for (int k = i - 1; k > -1; k--)
                    {
                        if(grid[j][k].getValue() != 0 && grid[j][k].getValue() != grid[j][i].getValue()){
                            break;
                        }
                        if (grid[j][k].getValue() == grid[j][i].getValue())
                        {
                            grid[j][i] = grid[j][i] + grid[j][k];
                            grid[j][k] = block(0, j, i);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 3; i > 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[j][i].getValue() == 0)
                {
                    for (int k = i - 1; k > -1; k--)
                    {
                        if (grid[j][k].getValue() != 0)
                        {
                            grid[j][i] = grid[j][k];
                            grid[j][k] = block(0, j, i);
                            shifted = true;
                            break;
                        }
                    }
                }
            }
        }
        break;
    default:
        break;
    }
    if(shifted == true){
        generate();
    } 
}

// void board::render(){
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             grid[i][j].render();
//         }
//     }
// }

void board::showBoard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j].getValue() << ',';
        }
        cout << endl;
    }
}
