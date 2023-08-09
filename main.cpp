#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h> // Include the header for changing the working directory
#include "button.hpp"

void openGame(const char *path)
{
    const char *exePath = path;

    if (chdir(exePath) == 0)
    {
        const char *command = ".\\main"; // Assuming main is the name of your executable

        int result = system(command);

        if (result == 0)
        {
            std::cout << "Command executed successfully.\n";
        }
        else
        {
            std::cerr << "Command execution failed with error code: " << result << "\n";
        }
    }
    else
    {
        std::cerr << "Failed to change working directory.\n";
    }
}

int main()
{

    // Set the path to the executable directory

    std::string game = "";

    button button1(61.0f, 236.0f, "open snake", "icons\\snake.png");
    button button2(311.0f, 236.0f, "open snake", "icons\\bomb.png");
    button button3(561.0f, 236.0f, "open snake", "icons\\sudoku.png");
    button button4(811.0f, 236.0f, "open snake", "icons\\2048.png");

    sf::RenderWindow window(sf::VideoMode(1000, 600), "snake", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("RobotoCondensed-Bold.ttf"))
    {
        return 1;
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
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;

                    if (mouseX > 61 && mouseX < 128 + 61 && mouseY > 236 && mouseY < 236 + 128)
                    {
                        openGame(".\\snake");
                        chdir("..");
                    }
                    if (mouseX > 311 && mouseX < 128 + 311 && mouseY > 236 && mouseY < 236 + 128)
                    {
                        openGame(".\\mines");
                        chdir("..");
                    }
                    if (mouseX > 561 && mouseX < 128 + 561 && mouseY > 236 && mouseY < 236 + 128)
                    {
                        openGame(".\\sudoku");
                        chdir("..");
                    }
                    if (mouseX > 811 && mouseX < 128 + 811 && mouseY > 236 && mouseY < 236 + 128)
                    {
                        openGame(".\\2048");
                        chdir("..");
                    }
                }
                break;
            }
            break;
        }
        window.clear();

        button1.render(window);
        button2.render(window);
        button3.render(window);
        button4.render(window);

        window.display();
    }

    return 0;
}
