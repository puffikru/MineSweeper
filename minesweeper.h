#pragma once

#include <termios.h>
#include <unistd.h>
#include <vector>

#if defined(__APPLE__) || defined(__MACH__)
char getch() {
    struct termios oldt, newt;
    char ch;

    // Получаем текущие настройки терминала
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Отключаем буферизацию и ввод по нажатию Enter
    newt.c_lflag &= ~(ICANON | ECHO);

    // Устанавливаем новые настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Считываем символ
    ch = getchar();

    // Восстанавливаем старые настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
#endif

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


    Board(size_t size, size_t mines);

    void Print() const;
    
private:
    const size_t size_;
    const size_t mines_;
    std::vector<std::vector<Cell>> board;
};

class Game
{
public:
    Game(size_t size, size_t mines);

    void Start() const;



private:
    Board board;
};