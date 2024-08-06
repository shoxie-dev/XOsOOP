#include "board.h"
#include <iostream>
#include <iomanip>


Board::Board(){
    for(size_t i{}; i < 3; ++i){
        for(size_t j{}; j < 3; ++j){
            grid[i][j] = '.';
        }
    }
}

void Board::display(){
    for(size_t i{}; i < 3; ++i){
        for(size_t j{}; j < 3; ++j){
            std::cout << std::setw(2) << grid[i][j];
        }
        std::cout << std::endl;
    }
}

bool Board::isValidMove(int row, int col){
    bool isValid = false;
    if((row >= 0 && row < 3) && (col >= 0 && col < 3))
        if(grid[row][col] == 'x' || grid[row][col] == 'o'){
            std::cout << "Move is invalid" << std::endl;
        }else if(grid[row][col] == '.'){
            std::cout << "Move is valid" << std::endl;
            isValid = true;
        }
    return isValid;
}

void Board::placeMove(int row, int col, char symbol){
    bool makeMove = isValidMove(row,col);
    if(makeMove == true){
        grid[row][col] = symbol;
    }
}

bool Board::checkWin(char symbol){
    bool winner = false;
    //horizontal checks
    for(size_t i{}; i < 3; ++i){
        if(grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol){
            std::cout << "Winner is player: " << symbol << std::endl;
            winner = true;
        }
    }
    //vertical checks
    for(size_t j{}; j < 3; ++j){
        if(grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol){
            std::cout << "Winner is player: " << symbol << std::endl;
            winner = true;
        }
    }
    //diagonal
    if(grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol){
        std::cout << "Winner is player: " << symbol << std::endl;
            winner = true;
    }
    //off diagonal
    if(grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol){
        std::cout << "Winner is player: " << symbol << std::endl;
            winner = true;
    }
    return winner;
}

bool Board::isFull(){
        bool draw_game = false;
        int matrix_sum{0};
        unsigned int row_fill [3][3] = {
            { 0, 0, 0},
            { 0, 0, 0},
            { 0, 0, 0}
        }; //no
        for(size_t i{}; i < 3; ++i){
            for(size_t j{}; j < 3; ++j){
                if(grid[i][j] == 'o' || grid[i][j] == 'x'){
                    row_fill[i][j] = 1; 
                }else{
                    row_fill[i][j] = 0;
                }
            }
        } 
        for(size_t i{}; i < 3; ++i){
            for(size_t j{}; j < 3; ++j){
                matrix_sum += row_fill[i][j];
            }
        }
        if(matrix_sum%9 == 0){
            std::cout << "Draw." << std::endl;
            draw_game = true;
        }
        return draw_game;
}




