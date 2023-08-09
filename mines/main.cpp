#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "board.hpp"

const float WINDOW_HEIGHT = 900.0f;
const float WINDOW_WIDTH = 800.0f;
const float TIMER_OFFSET_X = 20.0f;
const float TIMER_OFFSET_Y = 828.0f;
const float CELL_SIDE = 40.0f;

// check whether the player won or not
bool checkStatus(board b)
{
    int sum = 0;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (b.getBoard()[i][j].getCover() == true)
            {
                sum += 1;
            }
        }
    }
    if (sum == 80)
    {
        return true;
    }
    return false;
}

int main()
{
    board b; // creating the game board

    std::string gameStatus = "begining"; // variable for storing the status of the game

    // window setup
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Minesweeper", sf::Style::Titlebar | sf::Style::Close);
    sf::Color bgColor(54, 54, 168);

    // font setup
    sf::Font font;
    if (!font.loadFromFile("RobotoCondensed-Bold.ttf"))
    {
        return 1;
    }

    // grid setup
    sf::RectangleShape lines[40];

    for (int i = 0; i < 20; i++)
    {
        lines[i].setSize(sf::Vector2f(CELL_SIDE, WINDOW_WIDTH));
        lines[i].setPosition(i * CELL_SIDE, 0.0f);
        lines[i].setOutlineColor(sf::Color::Black);
        lines[i].setFillColor(sf::Color::Transparent);
        lines[i].setOutlineThickness(1.0f);
    }

    for (int i = 20; i < 40; i++)
    {
        lines[i].setSize(sf::Vector2f(WINDOW_WIDTH, CELL_SIDE));
        lines[i].setPosition(0.0f, (i - 20) * CELL_SIDE);
        lines[i].setOutlineColor(sf::Color::Black);
        lines[i].setFillColor(sf::Color::Transparent);
        lines[i].setOutlineThickness(1.0f);
    }

    // event listener setup
    sf::Event event;

    // game timer setup
    sf::Clock clock;
    sf::Time elapsed_time;
    sf::Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(36);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition(TIMER_OFFSET_X, TIMER_OFFSET_Y);
    timerText.setString("00:00");

    // game loop
    while (window.isOpen())
    {
        // listen for current events
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
                    // update the game board until the player's first click is an empty cell(makes the game a lot easier)
                    if (gameStatus == "begining")
                    {
                        int mouseX = event.mouseButton.y / CELL_SIDE;
                        int mouseY = event.mouseButton.x / CELL_SIDE;
                        while (b.getBoard()[mouseX][mouseY].getValue() != 0)
                        {
                            board c;
                            b = c;
                        }
                        clock.restart();
                        gameStatus = b.click(mouseX, mouseY);
                    }
                    // game is finished
                    else if (gameStatus == "finished" || gameStatus == "game over")
                    {
                        std::cout << "yes man" << std::endl;
                    }
                    else
                    {
                        int mouseX = event.mouseButton.y / 40;
                        int mouseY = event.mouseButton.x / 40;
                        if (b.getBoard()[mouseX][mouseY].getFlag() == false)
                        {
                            gameStatus = b.click(mouseX, mouseY);
                        }
                        if (checkStatus(b) == true)
                        {
                            gameStatus = "finished";
                        }
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (gameStatus == "On going")
                    {
                        int mouseX = event.mouseButton.y / 40;
                        int mouseY = event.mouseButton.x / 40;
                        b.getBoard()[mouseX][mouseY].setFlag();
                    }
                }
                break;

            default:
                break;
            }
        }

        window.clear(bgColor);

        // update timer
        if (gameStatus == "On going")
        {
            elapsed_time = clock.getElapsedTime();
            int minutes = static_cast<int>(elapsed_time.asSeconds()) / 60;
            int seconds = static_cast<int>(elapsed_time.asSeconds()) % 60;
            timerText.setString(std::to_string(minutes / 10) + std::to_string(minutes % 10) + ":" + std::to_string(seconds / 10) + std::to_string(seconds % 10));
        }

        // draw the board cells
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                // set flagged cells color to yellow
                if (b.getBoard()[i][j].getFlag() == true)
                {
                    sf::RectangleShape square(sf::Vector2f(CELL_SIDE, CELL_SIDE));
                    square.setPosition(CELL_SIDE * j, CELL_SIDE * i);
                    square.setFillColor(sf::Color::Yellow);
                    window.draw(square);
                }
                else if (b.getBoard()[i][j].getCover() == false)
                {
                    b.getBoard()[i][j].display(window, b.getBoard()[i][j].setup(i, j, font), i, j);
                }
            }
        }

        // set all bombs cell color to red(loss)
        if (gameStatus == "game over")
        {
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (b.getBoard()[i][j].getValue() == -1)
                    {
                        sf::RectangleShape square(sf::Vector2f(CELL_SIDE, CELL_SIDE));
                        square.setPosition(CELL_SIDE * j, CELL_SIDE * i);
                        square.setFillColor(sf::Color::Red);
                        window.draw(square);
                    }
                }
            }
        }

        // set all bombs cell color to green(win)
        else if (gameStatus == "finished")
        {
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (b.getBoard()[i][j].getValue() == -1)
                    {
                        sf::RectangleShape square(sf::Vector2f(CELL_SIDE, CELL_SIDE));
                        square.setPosition(CELL_SIDE * j, CELL_SIDE * i);
                        square.setFillColor(sf::Color::Green);
                        window.draw(square);
                    }
                }
            }
        }

        // draw the grid
        for (int i = 0; i < 40; i++)
        {
            window.draw(lines[i]);
        }

        // draw the timer
        window.draw(timerText);

        window.display();
    }
    return 0;
}