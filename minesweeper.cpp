#include "minesweeper.h"

#include <iostream>

// Board :: Board() 
// {
    
// }

Board :: Board(size_t size, size_t mines)
: size_(size), mines_(mines) 
{
    board.resize(size, std::vector<Cell>(size));
}

void Board :: Print() const
{
    std::cout << "#########################" << "\n";
        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j].state != CellState::OPENED)
                {
                    std::cout << "0";
                }
            }
            std::cout << '\n';
        }
        std::cout << "#########################" << '\n';
}

Game :: Game(size_t size, size_t mines)
: board(size, mines) {}

void Game :: Start() const
{

}

int main()
{
    Game game(50, 10);
    game.Start();

    #if defined(_WIN32) || defined(_WIN64)
        std::cout << "Running on Windows." << std::endl;
    #elif defined(__APPLE__) || defined(__MACH__)
        std::cout << "Running on macOS." << std::endl;
    #endif

    return 0;
}