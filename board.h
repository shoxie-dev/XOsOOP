#ifndef _BOARD_
#define _BOARD_

class Board {
private:
    char grid[3][3];
public:
    Board();
    void display();
    bool isValidMove(int row, int col);
    void placeMove(int row, int col, char symbol);
    bool checkWin(char symbol);
    bool isFull();
};
#endif