#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include <array>
#include <SFML/Graphics.hpp>
#include "sudoku.hpp"

int main()
{
    sudoku sudoku;

    bool gameFinished = false;

    sf::RenderWindow window(sf::VideoMode(900, 900), "sudoku", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("RobotoCondensed-Bold.ttf"))
    {
        return 1;
    }

    sf::RectangleShape lines[18];

    for (int i = 0; i < 9; i++)
    {
        lines[i].setSize(sf::Vector2f(100.0f, 900.0f));
        lines[i].setPosition(i * 100.0f, 0.0f);
        lines[i].setOutlineColor(sf::Color::Black);
        lines[i].setFillColor(sf::Color::Transparent);
        lines[i].setOutlineThickness(1.0f);
    }

    for (int i = 9; i < 18; i++)
    {
        lines[i].setSize(sf::Vector2f(900.0f, 100.0f));
        lines[i].setPosition(0.0f, (i - 9) * 100.0f);
        lines[i].setOutlineColor(sf::Color::Black);
        lines[i].setFillColor(sf::Color::Transparent);
        lines[i].setOutlineThickness(1.0f);
    }

    sf::Text numbers[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            numbers[i][j].setFont(font);
            numbers[i][j].setCharacterSize(24);
            numbers[i][j].setPosition(46.0f + j * 100.0f, 32.0f + i * 100.0f);
        }
    }

    std::array<int, 2> selectedCell = {99, 99};
    bool isCellSelected = false;

    std::map<std::array<int, 2>, int> addedNumbers;

    sf::RectangleShape selectedCellSquare;
    selectedCellSquare.setSize(sf::Vector2f(100.0f, 100.0f));
    selectedCellSquare.setFillColor(sf::Color(228, 228, 228));
    selectedCellSquare.setOutlineColor(sf::Color::Black);
    selectedCellSquare.setOutlineThickness(1.0f);

    int **boardPtr = sudoku.getboard();

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int mouseY = event.mouseButton.y;
                    int mouseX = event.mouseButton.x;
                    if (boardPtr[mouseY / 100][mouseX / 100] == 0 || addedNumbers.count({mouseX / 100, mouseY / 100}) > 0)
                    {
                        selectedCell[0] = mouseX / 100;
                        selectedCell[1] = mouseY / 100;
                        isCellSelected = true;
                    }
                    else
                    {
                        selectedCell[0] = 99;
                        selectedCell[1] = 99;
                        isCellSelected = false;
                    }
                }

            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    selectedCell[0] = 99;
                    selectedCell[1] = 99;
                    isCellSelected = false;
                    break;

                case sf::Keyboard::Numpad1:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 1;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 1);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad2:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 2;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 2);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad3:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 3;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 3);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad4:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 4;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 4);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad5:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 5;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 5);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad6:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 6;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 6);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad7:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 7;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 7);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad8:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 8;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 8);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::Numpad9:
                    if (isCellSelected)
                    {
                        addedNumbers[selectedCell] = 9;
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 9);
                        gameFinished = sudoku.checkBoard();
                        if (gameFinished == true)
                        {
                            std::cout << "done" << std::endl;
                        }
                    }
                    break;

                case sf::Keyboard::BackSpace:
                    if (isCellSelected)
                    {
                        addedNumbers.erase(selectedCell);
                        sudoku.setNumber(selectedCell[1], selectedCell[0], 0);
                    }
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }

        boardPtr = sudoku.getboard();

        window.clear(sf::Color::White);

        selectedCellSquare.setPosition(selectedCell[0] * 100, selectedCell[1] * 100);
        window.draw(selectedCellSquare);

        for (int i = 0; i < 18; i++)
        {
            window.draw(lines[i]);
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (boardPtr[i][j] != 0 && addedNumbers.count({j, i}) == 0)
                {
                    numbers[i][j].setFillColor(sf::Color::Black);
                    numbers[i][j].setString(std::to_string(boardPtr[i][j]));
                    window.draw(numbers[i][j]);
                }
            }
        }

        for (const auto &element : addedNumbers)
        {
            sf::Text added;
            added.setFont(font);
            added.setCharacterSize(24);
            added.setPosition(46.0f + element.first[0] * 100.0f, 32.0f + element.first[1] * 100.0f);
            added.setFillColor(sf::Color::Blue);
            added.setString(std::to_string(element.second));
            window.draw(added);
        }

        window.display();

        // for (int i = 0; i < 9; ++i)
        // {
        //     delete[] boardPtr[i];
        // }
        // delete[] boardPtr;
    }

    return 0;
}