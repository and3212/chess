/* Author: Liam Lawrence
 * Date: 1.1.17
 * Code for the self-moving chess board
 */

#include <iostream>
#include "pieces.hpp"
#include "debug/debugTools.hpp"
//TODO remove this once done debugging

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
int tieCounter = 50;    //TODO add a counter where if a pawn isn't moved / a piece isn't captured in 50 turns it is a draw

// Initial setup for a new game
// Positives are 'white' and negatives are 'black'
const int startingBoard[8][8] = {rook, knight, bishop, queen, king, bishop, knight, rook,
                                  pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn,
                                  0, 0, 0, -knight, 0, 0, 0, 0, //TODO remove the -knight from here once done debugging
                                  0, 0, 0, 0, 0, 0, 0, 0,
                                  0, 0, 0, 0, 0, 0, 0, 0,
                                  0, 0, 0, 0, 0, 0, 0, 0,
                                  -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn,
                                  -rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook};

void newGame(){ // Sets up the board to the default position
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = startingBoard[i][j];
        }
    }
}

// Prints out the current layout of the board
void printScreen(int board[8][8]){
    char piece;
    std::cout << "   --------------------------\n";

    // Uppercase is white and Lowercase is black
    for(int i = 7; i > -1; i--){
        for(int j = 0; j < 8; j++){
            switch(board[j][i]){
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

            if(j == 0){
                std::cout << 8 - i << " | ";
            }


            std::cout << " " << piece << " ";
        }
        std::cout <<" |\n";
    }
    std::cout << "   --------------------------\n";
    std::cout << "     A  B  C  D  E  F  G  H\n";
}


int main() {
    newGame();
    printScreen(board);

    int newRank;
    int newFile;
    char rankHolder;
    std::cout << "What piece do you wanna move?: ";
    std::cin >> rankHolder;
    std::cin >> newFile;

    newRank = debugTools::charToCoords(rankHolder);
    newFile = debugTools::intToCoords(newFile);

    pieces::pawn(board, newRank, newFile, 'b');
    printScreen(board);

    ////////////ROOK TEST////////////////
    std::cout << "What piece do you wanna move?: ";
    std::cin >> rankHolder;
    std::cin >> newFile;

    newRank = debugTools::charToCoords(rankHolder);
    newFile = debugTools::intToCoords(newFile);


    pieces::rook(board, newRank, newFile, 'b');
    printScreen(board);

    //TODO currently if you move the pawn at 6x0 to 4x0, the rook at 7x0 can capture the piece at 4x0 -- fix this

    return 0;
}