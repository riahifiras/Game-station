# Game-station
Welcome to Game Station, a collection of four classic games written in C using the SFML (Simple and Fast Multimedia Library). Enjoy hours of entertainment with Snake, Minesweeper, 2048, and Sudoku, all in one convenient package.

![Screenshot 2024-01-16 140938](https://github.com/riahifiras/Game-station/assets/120566908/707c913a-bd3a-4177-83a0-56abf67d79df)

## Game Descriptions
### Snake
Navigate the snake through the grid, eating food to grow longer. Be careful not to collide with the walls or yourself!

![Screenshot 2024-01-16 141017](https://github.com/riahifiras/Game-station/assets/120566908/6d5ea2d6-2a9a-413d-838a-cda72475edfc)

### Minesweeper
Uncover the hidden mines on the grid by clicking on squares. Use the numbers to deduce the locations of mines and clear the board without triggering any explosions.

![Screenshot 2024-01-16 141051](https://github.com/riahifiras/Game-station/assets/120566908/6ea80b41-238e-4ed0-9b3b-e9a276614642)

### 2048
Slide tiles on a 4x4 grid to combine identical numbers and reach the elusive 2048 tile. Can you achieve the highest score?

![Screenshot 2024-01-16 194651](https://github.com/riahifiras/Game-station/assets/120566908/8175fc5a-067a-4060-969c-54808d7b9263)

### Sudoku
Solve the classic Sudoku puzzles by filling in the numbers 1 through 9 in each row, column, and 3x3 subgrid without repeating. Challenge your logical thinking skills!

![Screenshot 2024-01-16 194608](https://github.com/riahifiras/Game-station/assets/120566908/adf8ca25-a835-44fc-8870-cc18a65e1dfd)

## Installation
Clone the repository and follow the instructions below to compile and run the Game Station on your machine.

```bash
Copy code
git clone https://github.com/riahifiras/Game-station.git
cd Game-station
```

To build the Game Station from source, make sure you have the following dependencies installed:

SFML library

Run the following commands:
```bash
cd mines
g++ -c board.cpp -I<path to your SFML-2.5.1\include file> ; g++ -c block.cpp -I<path to your SFML-2.5.1\include file> ; g++ -c main.cpp -I<path to your SFML-2.5.1\include file> ; g++ board.o block.o main.o -o main -L<path to your SFML-2.5.1\lib file> -lsfml-graphics -lsfml-window -lsfml-system ; ./main
cd ..
cd 2048
g++ -c board.cpp -I<path to your SFML-2.5.1\include file> ; g++ -c block.cpp -I<path to your SFML-2.5.1\include file> ; g++ -c main.cpp -I<path to your SFML-2.5.1\include file> ; g++ board.o block.o main.o -o main -L<path to your SFML-2.5.1\lib file> -lsfml-graphics -lsfml-window -lsfml-system ; ./main
cd ..
cd snake
g++ -c snake.cpp -I<path to your SFML-2.5.1\include file> ;g++ -c food.cpp -I<path to your SFML-2.5.1\include file> ; g++ -c main.cpp -I<path to your SFML-2.5.1\include file> ; g++ snake.o food.o  main.o -o main -L<path to your SFML-2.5.1\lib file> -lsfml-graphics -lsfml-window -lsfml-system ; ./main
cd ..
cd sudoku
g++ -c sudoku.cpp -I<path to your SFML-2.5.1\include file>; g++ -c sudokuArray.cpp -I<path to your SFML-2.5.1\include file>; g++ -c main.cpp -I<path to your SFML-2.5.1\include file> ; g++ sudokuArray.o  sudoku.o  main.o -o main -L<path to your SFML-2.5.1\lib file> -lsfml-graphics -lsfml-window -lsfml-system ; ./main
cd ..
g++ -c main.cpp -IC:\Users\user\OneDrive\Documents\libraries\SFML-2.5.1\include; g++ main.o -o main -L<path to your SFML-2.5.1\lib file> -lsfml-graphics -lsfml-window -lsfml-system ; ./main
```

Contributing
Feel free to contribute by reporting issues, suggesting improvements, or adding new features. Fork the repository, create a new branch, make your changes, and submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE file for details. Enjoy playing the games!
