#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "board.hpp"
#include <random>
#include <chrono>

std::vector<std::array<int, 2>> neighbors(int x, int y)
{
    std::vector<std::array<int, 2>> v;
    int neighbors[][2] = {
        {x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1}, {x, y - 1}, {x, y + 1}, {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1}};

    for (int i = 0; i < 8; i++)
    {
        int nx = neighbors[i][0];
        int ny = neighbors[i][1];

        // Check if the neighbor indices are within valid range
        if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20)
        {
            v.push_back({nx, ny});
        }
    }

    return v;
}

int bombsTotal(block a[][20], int x, int y)
{
    int sum = 0;

    std::vector<std::array<int, 2>> v = neighbors(x, y);

    for (std::array<int, 2> e : v)
    {
        if (a[e[0]][e[1]].getValue() == -1)
        {
            sum += 1;
        }
    }

    return sum;
}

board::board()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    int totalCells = 20 * 20;
    int bombsToPlace = 80;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            // Calculate the probability of placing a bomb based on remaining bombs
            double bombProbability = static_cast<double>(bombsToPlace) / totalCells;

            if (bombsToPlace > 0 && (gen() % totalCells) < (bombProbability * totalCells))
            {
                grid[i][j].setValue(-1);
                bombsToPlace -= 1;
            }

            totalCells -= 1; // Decrement remaining cells
        }
    }
    // std::cout<<bombsToPlace<<std::endl;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (grid[i][j].getValue() == 0)
            {
                grid[i][j].setValue(bombsTotal(grid, i, j));
            }
        }
    }
}

std::string board::click(int x, int y)
{
    if (grid[x][y].getValue() == -1)
    {
        std::cout << "game over" << std::endl;
        return "game over";
    }
    else if (grid[x][y].getValue() != -1 && grid[x][y].getValue() != 0)
    {
        grid[x][y].setCover();
    }
    else
    {
        grid[x][y].setCover();
        for (std::array<int, 2> e : neighbors(x, y))
        {
            if (grid[e[0]][e[1]].getCover() == true)
            {
                click(e[0], e[1]);
            }
        }
    }
    return "On going";
}

block (*board::getBoard())[20]
{
    return grid;
}

void board::showBoard()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << grid[i][j].getValue() << ',';
        }
        std::cout << std::endl;
    }
}

void board::showCoveredBoard()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << grid[i][j].getCover() << ',';
        }
        std::cout << std::endl;
    }
}