#include <iostream>
#include <array>
#include <vector>
#include "snake.hpp"

snake::snake()
{
    orientation = 'r';
    cells.push_back({0, 3});
    cells.push_back({0, 4});
    cells.push_back({0, 5});
}

void snake::forward()
{
    if (snake::bitSelf() == false)
    {
        switch (orientation)
        {
        case 'r':
            for (int i = 0; i < cells.size() - 1; i++)
            {
                cells[i] = cells[i + 1];
            }
            if (cells[cells.size() - 1][1] + 1 < 100)
            {
                cells[cells.size() - 1] = {cells[cells.size() - 1][0], cells[cells.size() - 1][1] + 1};
            }
            else
            {
                cells[cells.size() - 1] = {cells[cells.size() - 1][0], 0};
            }
            break;
        case 'u':
            for (int i = 0; i < cells.size() - 1; i++)
            {
                cells[i] = cells[i + 1];
            }
            if (cells[cells.size() - 1][0] - 1 > -1)
            {
                cells[cells.size() - 1] = {cells[cells.size() - 1][0] - 1, cells[cells.size() - 1][1]};
            }
            else
            {
                cells[cells.size() - 1] = {99, cells[cells.size() - 1][1]};
            }
            break;
        case 'l':
            for (int i = 0; i < cells.size() - 1; i++)
            {
                cells[i] = cells[i + 1];
            }
            if (cells[cells.size() - 1][1] - 1 > -1)
            {
                cells[cells.size() - 1] = {cells[cells.size() - 1][0], cells[cells.size() - 1][1] - 1};
            }
            else
            {
                cells[cells.size() - 1] = {cells[cells.size() - 1][0], 99};
            }
            break;
        case 'd':
            for (int i = 0; i < cells.size() - 1; i++)
            {
                cells[i] = cells[i + 1];
            }
            if (cells[cells.size() - 1][0] + 1 < 100)
            {
                cells[cells.size() - 1] = {cells[cells.size() - 1][0] + 1, cells[cells.size() - 1][1]};
            }
            else
            {
                cells[cells.size() - 1] = {0, cells[cells.size() - 1][1]};
            }
            break;

        default:
            break;
        }
    }
}

void snake::expand()
{
    switch (orientation)
    {
    case 'u':
        // if (cells[cells.size() - 1][0] + 1 < 100)
        // {
        //     cells.push_back({cells[cells.size() - 1][0] + 1 , cells[cells.size() - 1][1]});
        // }
        // else
        // {
        //     cells.push_back({0, cells[cells.size() - 1][1]});
        // }
        // break;
        if (cells[0][0] + 1 < 99)
        {
            cells.insert(cells.begin(), {cells[0][0] + 1, cells[0][1]});
        }
        else
        {
            cells.insert(cells.begin(), {0, cells[0][1]});
        }
        break;
    case 'd':
        if (cells[0][0] - 1 > -1)
        {
            cells.insert(cells.begin(), {cells[0][0] - 1, cells[0][1]});
        }
        else
        {
            cells.insert(cells.begin(), {99, cells[0][1]});
        }
        break;
    case 'l':
        // if (cells[cells.size() - 1][1] + 1 < 100)
        // {
        //     cells.push_back({cells[cells.size() - 1][0], cells[cells.size() - 1][1] + 1});
        // }
        // else
        // {
        //     cells.push_back({cells[cells.size() - 1][0], 0});
        // }
        // break;
        if (cells[0][1] + 1 < 100)
        {
            cells.insert(cells.begin(), {cells[0][0], cells[0][1] + 1});
        }
        else
        {
            cells.insert(cells.begin(), {cells[0][0], 0});
        }
        break;
    case 'r':
        if (cells[0][1] - 1 > -1)
        {
            cells.insert(cells.begin(), {cells[0][0], cells[0][1] - 1});
        }
        else
        {
            cells.insert(cells.begin(), {cells[0][0], 99});
        }
        break;

    default:
        break;
    }
}

bool snake::bitSelf()
{
    for (int i = 0; i < cells.size() - 1; i++)
    {
        if (cells[i] == cells[cells.size() - 1])
        {
            return true;
        }
    }
    return false;
}

std::vector<std::array<int, 2>> snake::getCells()
{
    return cells;
}

void snake::setOrientation(char newOrientaion)
{
    orientation = newOrientaion;
}

char snake::getOrientaion()
{
    return orientation;
}

void snake::showSnake()
{
    std::cout << std::endl
              << "[";
    for (int i = 0; i < cells.size(); i++)
    {
        std::cout << "(" << cells[i][0] << "," << cells[i][1] << "), ";
    }
    std::cout << "]" << std::endl;
}
