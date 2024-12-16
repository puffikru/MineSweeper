#pragma once

#include <vector>

enum CellState
{
    HIDDEN,
    OPENED,
    FLAGGED
};

struct Cell
{
    CellState state;
    bool isMine;
    uint8_t minesAround;
};

class Board
{
public:
    Board();

    Board(int size, int mines) : size_(size), mines_(mines) {};
    
private:
    int size_;
    int mines_;
    std::vector<std::vector<Cell>> board;
};

class Game
{
public:
    Game(int size, int mines) : board(size, mines) {}

    void Start();

private:
    Board board;
};