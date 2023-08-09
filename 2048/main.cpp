#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "board.hpp"

int main()
{
    board b = board();

    sf::RenderWindow window(sf::VideoMode(800, 800), "2048", sf::Style::Titlebar | sf::Style::Close);
    sf::Color bgColor(54, 54, 168);

    sf::Font font;
    if (!font.loadFromFile("RobotoCondensed-Bold.ttf"))
    {
        return 1;
    }

    sf::Color boardColor(220, 220, 220);
    sf::RectangleShape board(sf::Vector2f(400.0f, 400.0f));
    board.setPosition(200.0f, 200.0f);
    board.setFillColor(boardColor);

    sf::RectangleShape grid(sf::Vector2f(360.0f, 360.0f));
    grid.setPosition(220.0f, 220.0f);
    grid.setOutlineColor(sf::Color::Black);
    grid.setOutlineThickness(2.0f);

    sf::RectangleShape lines[8];

    for (int i = 0; i < 4; i++)
    {
        lines[i].setSize(sf::Vector2f(90.0f, 360.0f));
        lines[i].setPosition(220.0f + i * 90.0f, 220.0f);
        lines[i].setOutlineColor(sf::Color::Black);
        lines[i].setFillColor(sf::Color::Transparent);
        lines[i].setOutlineThickness(1.0f);
    }

    for (int i = 4; i < 8; i++)
    {
        lines[i].setSize(sf::Vector2f(360.0f, 90.0f));
        lines[i].setPosition(220.0f, 220.0f + (i - 4) * 90.0f);
        lines[i].setOutlineColor(sf::Color::Black);
        lines[i].setFillColor(sf::Color::Transparent);
        lines[i].setOutlineThickness(1.0f);
    }

    sf::Text numbers[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            numbers[i][j].setFont(font);
            numbers[i][j].setCharacterSize(24);
            numbers[i][j].setPosition(260.0f + j * 90.0f, 250.0f + i * 90.0f);
        }
    }

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
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;

                case sf::Keyboard::Up:
                    b.shift('u');
                    break;

                case sf::Keyboard::Down:
                    b.shift('d');
                    break;

                case sf::Keyboard::Left:
                    b.shift('l');
                    break;

                case sf::Keyboard::Right:
                    b.shift('r');
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }

        window.clear(bgColor);

        window.draw(board);
        window.draw(grid);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (b.getBoard()[i][j].getValue() == 0)
                {
                    continue;
                }
                sf::RectangleShape square(sf::Vector2f(90.0f, 90.0f));
                square.setPosition(220.0f + 90.0f * j, 220.0f + 90.0f * i);
                sf::Color squareColor(3, 4, 85); // Default color

                switch (b.getBoard()[i][j].getValue())
                {
                case 2:
                    squareColor = sf::Color(202, 240, 248); // Light ocean blue
                    break;
                case 4:
                    squareColor = sf::Color(173, 232, 244); // Slightly darker ocean blue
                    break;
                case 8:
                    squareColor = sf::Color(144, 224, 239); // Deeper ocean blue
                    break;
                case 16:
                    squareColor = sf::Color(98, 210, 232); // Darker ocean blue
                    break;
                case 32:
                    squareColor = sf::Color(72, 202, 228); // Deep ocean blue
                    break;
                case 64:
                    squareColor = sf::Color(0, 180, 216); // Rich ocean blue
                    break;
                case 128:
                    squareColor = sf::Color(0, 150, 199); // Intense ocean blue
                    break;
                case 256:
                    squareColor = sf::Color(0, 119, 182); // Dark ocean blue
                    break;
                case 512:
                    squareColor = sf::Color(2, 138, 180); // Deeper ocean blue
                    break;
                case 1024:
                    squareColor = sf::Color(3, 4, 94); // Very dark ocean blue
                    break;
                case 2048:
                    squareColor = sf::Color(3, 4, 85); // Nearly black ocean blue
                    break;

                default:
                    break;
                }

                square.setFillColor(squareColor);
                window.draw(square);
                if (b.getBoard()[i][j].getValue() > 32)
                {
                    numbers[i][j].setFillColor(sf::Color::White);
                }
                else
                {
                    numbers[i][j].setFillColor(sf::Color::Black);
                }
                numbers[i][j].setString(std::to_string(b.getBoard()[i][j].getValue()));
                window.draw(numbers[i][j]);
            }
        }
        for (int i = 0; i < 8; i++)
        {
            window.draw(lines[i]);
        }
        window.display();
    }
    return 0;
}