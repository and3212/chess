/* Author: Liam Lawrence
 * Date: 1.1.17
 *
 * Code for my personal moving chess game
 */

#include <iostream>
#include "pieces.hpp"

/* CHESS PIECES */
const int pawn = 1;
const int bishop = 2;
const int rook = 3;
const int knight = 4;
const int queen = 5;
const int king = 6;
/* END CHESS PIECES */


// initializes and 8x8 board to play on
// [rank][file] == [x][y]
int board[8][8];
int tieCounter = 50;

// Initial setup for a new game
// Positives are 'white' and negatives are 'black'
const int startingBofard[8][8] = {rook, knight, bishop, queen, king, bishop, knight, rook,
                                 pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn,
                                 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0,
                                 -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn,
                                 -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};

const int startingBoard[8][8] = {rook, pawn, 0, 0, 0, 0, -pawn, -rook,
                                 knight, pawn, 0, 0, 0, 0, -pawn, -knight,
                                bishop, pawn, 0, 0, 0, 0, -pawn, -bishop,
                                 king, pawn, 0, 0, 0, 0, -pawn, -king,
                                queen, pawn, 0, 0, 0, 0, -pawn, -queen,
                                bishop, pawn, 0, 0, 0, 0, -pawn, -bishop,
                                knight, pawn, 0, 0, 0, 0, -pawn, -knight,
                                rook, pawn, 0, 0, 0, 0, -pawn, -rook};

void newGame(){ // Sets up the board to the default position
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = startingBoard[i][j];
        }
    }
}

void printScreen(int board[8][8]){
    char piece;

    // Uppercase is white and Lowercase is black
    for(int i = 7; i > -1; i--){
        for(int j = 0; j < 8; j++){
            switch(board[i][j]){
                case 0:
                    piece = '-';
                    break;
                case pawn:
                    piece = 'P';
                    break;
                case knight:
                    piece = 'N';
                    break;
                case bishop:
                    piece = 'B';
                    break;
                case rook:
                    piece = 'R';
                    break;
                case queen:
                    piece = 'Q';
                    break;
                case king:
                    piece = 'K';
                    break;
                case -pawn:
                    piece = 'p';
                    break;
                case -knight:
                    piece = 'n';
                    break;
                case -bishop:
                    piece = 'b';
                    break;
                case -rook:
                    piece = 'r';
                    break;
                case -queen:
                    piece = 'q';
                    break;
                case -king:
                    piece = 'k';
                    break;
            }
            std::cout << " " << piece << " ";
        }
        std::cout <<"\n";
    }
}


int main() {
    newGame();
    printScreen(board);

    int newRank;
    int newFile;

    std::cout << board[1][3] << "\n";

    std::cout << "What piece do you wanna move?: ";
    std::cin >> newRank;
    std::cin >> newFile;

    pieces::pawn(board, newRank, newFile, 'w');



    printScreen(board);


    return 0;
}