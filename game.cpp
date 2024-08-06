#include "game.h"
#include <iostream>


void Game::switchPlayer(char& currentPlayer){
    if(currentPlayer == 'o'){
        currentPlayer = 'x';
    }else if(currentPlayer == 'x'){
        currentPlayer = 'o';
    }
}

Game::Game(){
    Board board;
    char player1 = 'o';
    char player2 = 'x';
}

void Game::play(){
    Game game;
    Board board;
    bool drawGame = false;
    bool winGame = false;
    char playerNow = 'o';
    int r{};
    int c{};
    while(drawGame == false && winGame == false){
        board.display();
        std::cout << "Input a move" << std::endl;
        std::cin >> r;
        std::cin >> c;
        board.isValidMove(r,c);
        board.placeMove(r,c,playerNow);
        drawGame = board.isFull();
        winGame = board.checkWin(playerNow);
        game.switchPlayer(playerNow);
    }

}
