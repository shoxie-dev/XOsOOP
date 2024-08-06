#ifndef _GAME_
#define _GAME_
#include "board.h"
class Game {
private:
    Board board;
    char currentPlayer;
public:
    Game();
    void play();
    void switchPlayer(char& currentPlayer);
    //void announceResult();
};
#endif