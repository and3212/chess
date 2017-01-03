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
    std::cout << "   --------------------------\n"
              << "     A  B  C  D  E  F  G  H\n";
}

int main() {
    newGame();
    printScreen(board);

    int newFile;
    int newRank;
    int pieceType;
    char color;
    std::string coord;

    for(int i = 1; i < 5; i++) {  //plays several moves //TODO force black and white moves to alternate, make the for loop end at checkmake
        std::cout << "What piece do you wanna move?: ";
        std::cin >> coord;

        newRank = debugTools::charGrabber(coord);
        newFile = debugTools::intGrabber(coord);

        if (board[newRank][newFile] > 0) {
            color = 'w';
            pieceType = board[newRank][newFile];
        } else if (board[newRank][newFile] < 0) {
            color = 'b';
            pieceType = -1 * board[newRank][newFile];
        } else {  //TODO insert catch that forces user to chose a different coordinate with a piece on it.  Not practical for mechanical use but stops bugs in computer program
            color = 'w';
            pieceType = board[newRank][newFile];
        }

        switch (pieceType) {
            case pawn:
                pieces::pawn(board, newRank, newFile, color);
                break;
            case knight:
                pieces::knight(board, newRank, newFile, color);
                break;
            case bishop:
                pieces::bishop(board, newRank, newFile, color);
                break;
            case rook:
                pieces::rook(board, newRank, newFile, color);
                break;
            case queen:
                pieces::pawn(board, newRank, newFile, color);  //TODO make queen method when queen move is added
                break;
            case king:
                pieces::pawn(board, newRank, newFile, color);  //TODO make king method when king move is added
                break;
        }

        printScreen(board);
    }

    //TODO currently if you move the pawn at 6x0 to 4x0, the rook at 7x0 can capture the piece at 4x0 -- fix this

    return 0;
}
