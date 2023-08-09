#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "snake.hpp"
#include "food.hpp"

int main()
{
    int board[10][10];
    int score = 0;

    sf::RenderWindow window(sf::VideoMode(1280, 1000), "snake", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("RobotoCondensed-Bold.ttf"))
    {
        return 1;
    }

    snake snake;
    food food;

    sf::RectangleShape sideBox(sf::Vector2f(280, 1000));
    sideBox.setPosition(1000, 0);
    sideBox.setFillColor(sf::Color::Black);
    sideBox.setOutlineColor(sf::Color::White);
    sideBox.setOutlineThickness(1.0f);

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(36);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(1088, 80);

    std::vector<std::array<int, 2>> snakeCells;
    sf::Clock keyPressTimer;
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

            case sf::Event::KeyPressed:
                if (keyPressTimer.getElapsedTime().asMilliseconds() > 40)
                {
                    keyPressTimer.restart();

                    switch (event.key.code)
                    {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;

                    case sf::Keyboard::Up:
                        if (snake.getOrientaion() != 'd')
                        {
                            snake.setOrientation('u');
                        }
                        break;

                    case sf::Keyboard::Down:
                        if (snake.getOrientaion() != 'u')
                        {
                            snake.setOrientation('d');
                        }
                        break;

                    case sf::Keyboard::Left:
                        if (snake.getOrientaion() != 'r')
                        {
                            snake.setOrientation('l');
                        }
                        break;

                    case sf::Keyboard::Right:
                        if (snake.getOrientaion() != 'l')
                        {
                            snake.setOrientation('r');
                        }
                        break;

                    default:
                        break;
                    }
                    break;
                }
            }
            break;
        }
        snakeCells = snake.getCells();
        // snake.showSnake();

        // for (int i = 0; i < 10; ++i)
        // {
        //     for (int j = 0; j < 10; ++j)
        //     {
        //         board[i][j] = 0;
        //     }
        // }
        // for (int i = 0; i < snakeCells.size(); i++)
        // {
        //     board[snakeCells[i][0]][snakeCells[i][1]] = 1;
        //     // std::cout << "board[" << snakeCells[i][0] << "][" << snakeCells[i][1] << "] = " <<  board[snakeCells[i][0]][snakeCells[i][1]] << std::endl;
        // }
        // for (int i = 0; i < 10; ++i)
        // {
        //     for (int j = 0; j < 10; ++j)
        //     {
        //         std::cout << board[i][j] << ", ";
        //     }
        //     std::cout << std::endl;
        // }
        // snake.expand();

        window.clear();
        window.draw(sideBox);
        scoreText.setString("score: " + std::to_string(score));
        window.draw(scoreText);

        // food.generateFood();
        sf::RectangleShape square(sf::Vector2f(10, 10));
        square.setPosition(10 * food.getFoodPosition()[1], 10 * food.getFoodPosition()[0]);
        square.setFillColor(sf::Color::Red);
        window.draw(square);

        if (snakeCells[snakeCells.size() - 1] == food.getFoodPosition())
        {
            score += 5;
            std::cout << score << std::endl;
            snake.expand();
            food.generateFood();
        }

        for (int i = 0; i < snakeCells.size(); i++)
        {
            sf::RectangleShape square(sf::Vector2f(10, 10));
            square.setPosition(10 * snakeCells[i][1], 10 * snakeCells[i][0]);
            square.setFillColor(sf::Color::Yellow);
            window.draw(square);
            // std::cout << "board[" << snakeCells[i][0] << "][" << snakeCells[i][1] << "] = " <<  board[snakeCells[i][0]][snakeCells[i][1]] << std::endl;
        }

        snake.forward();

        window.display();

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
    return 0;
}