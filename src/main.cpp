/* Author: Liam Lawrence
 * Date: 1.1.17
 * Code for the self-moving chess board
 */

#include <iostream>
#include "pieces.hpp"
#include "debug/debugTools.hpp"
//TODO remove this once done debugging

typedef int array_type[8][8];

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
                                  0, 0, 0, 0, 0, 0, 0, 0, //TODO remove the -knight from here once done debugging
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

bool isInCheck(char color){
    int kingRank;
    int kingFile;

    for(int i = 7; i > -1; i--) {
        for (int j = 0; j < 8; j++) {
            if (color == 'w' && board[j][i] == king ||
                (color == 'b' && board[j][i] == -king)){
                kingRank = j;
                kingFile = i;
            }
        }
    }

            // Checking Right
    int i = 1;
            while(i < 8){
                if(kingRank + i > 7)
                    break;

                if(board[kingRank + i][kingFile] == 0)
                    i++;

                else if(color == 'w' && board[kingRank + i][kingFile] == -rook ||  //check for white
                   (color == 'w' && board[kingRank + i][kingFile] == -queen) ||  //check for white
                   (color == 'b' && board[kingRank + i][kingFile] == rook) ||  //check for black
                   (color == 'b' && board[kingRank + i][kingFile] == queen)){ //check for black
                    return true;
                }
                else
                    break;
            }

            // Checking Left
    i = 1;
            while(i < 8){
                if (kingRank - i < 0)
                    break;

                if(board[kingRank - i][kingFile] == 0)
                    i++;

                else if (color == 'w' && board[kingRank - i][kingFile] == -rook ||  //check for white
                    (color == 'w' && board[kingRank - i][kingFile] == -queen) ||  //check for white
                    (color == 'b' && board[kingRank - i][kingFile] == rook) ||  //check for black
                    (color == 'b' && board[kingRank - i][kingFile] == queen)) { //check for black
                    return true;
                }
                else
                    break;
            }

            // Checking Up
    i = 1;
            while(i < 8){
                if(kingFile + i > 7)
                    break;

                if(board[kingRank][kingFile + i] == 0)
                    i++;

                if (color == 'w' && board[kingRank][kingFile + i] == -rook ||  //check for white
                    (color == 'w' && board[kingRank][kingFile + i] == -queen) ||  //check for white
                    (color == 'b' && board[kingRank][kingFile + i] == rook) ||  //check for black
                    (color == 'b' && board[kingRank][kingFile + i] == queen)) { //check for black
                    return true;
                }
                else
                    break;
            }

            // Checking Down
    i = 1;
            while(i < 8){
                if(kingFile - 1 < 0)
                    break;

                if(board[kingRank][kingFile - i] == 0)
                    i++;

                if (color == 'w' && board[kingRank][kingFile - i] == -rook ||  //check for white
                    (color == 'w' && board[kingRank][kingFile - i] == -queen) ||  //check for white
                    (color == 'b' && board[kingRank][kingFile - i] == rook) ||  //check for black
                    (color == 'b' && board[kingRank][kingFile - i] == queen)) { //check for black
                    return true;
                }
                else
                    break;
            }

            // Checking up-right
    i = 1;
            while(i < 8){
                if(kingRank + i > 7 || kingFile + i > 7)
                    break;

                if(board[kingRank + i][kingFile + i] == 0)
                    i++;

                if (color == 'w' && board[kingRank + i][kingFile + i] == -bishop ||  //check for white
                    (color == 'w' && board[kingRank + i][kingFile + i] == -queen) ||  //check for white
                    (color == 'w' && board[kingRank + i][kingFile + i] == -pawn && i == 1) ||  //check for white
                    (color == 'b' && board[kingRank + i][kingFile + i] == bishop) ||  //check for black
                    (color == 'b' && board[kingRank + i][kingFile + i] == queen)) { //check for black
                    return true;
                }
                else
                    break;
            }

            // Checking up-left
    i = 1;
            while(i < 8){
                if(kingRank + i > 7 || kingFile - i < 0)
                    break;

                if(board[kingRank + i][kingFile - i] == 0)
                    i++;

                if (color == 'w' && board[kingRank + i][kingFile - i] == -bishop ||  //check for white
                    (color == 'w' && board[kingRank + i][kingFile - i] == -queen) ||  //check for white
                    (color == 'b' && board[kingRank + i][kingFile - i] == bishop) ||  //check for black
                    (color == 'b' && board[kingRank + i][kingFile - i] == queen) ||   //check for black
                    (color == 'b' && board[kingRank + i][kingFile - i] == pawn && i == 1)) { //check for black
                    return true;
                }
                else
                    break;
            }

            // Checking down-right
    i = 1;
            while(i < 8){
                if(kingRank - i < 0 || kingFile + i > 7)
                    break;

                if(board[kingRank - i][kingFile + i] == 0)
                    i++;

                if (color == 'w' && board[kingRank - i][kingFile + i] == -bishop ||  //check for white
                    (color == 'w' && board[kingRank - i][kingFile + i] == -queen) ||  //check for white
                    (color == 'w' && board[kingRank - i][kingFile + i] == -pawn && i == 1) ||  //check for white
                    (color == 'b' && board[kingRank - i][kingFile + i] == bishop) ||  //check for black
                    (color == 'b' && board[kingRank - i][kingFile + i] == queen)) { //check for black
                    return true;
                }
                else
                    break;
            }

            // Checking down-left
    i = 1;
            while(i < 8) {
                if((kingRank - i) < 0 || (kingFile - i) < 0)
                    break;

                if(board[kingRank - i][kingFile - i] == 0)
                    i++;

                if (color == 'w' && board[kingRank - i][kingFile - i] == -bishop ||  //check for white
                    (color == 'w' && board[kingRank - i][kingFile - i] == -queen) ||  //check for white
                    (color == 'b' && board[kingRank - i][kingFile - i] == bishop) ||  //check for black
                    (color == 'b' && board[kingRank - i][kingFile - i] == queen) || //check for black
                    (color == 'b' && board[kingRank + i][kingFile - i] == pawn && i == 1)) { //check for black
                    return true;
                }
                else
                    break;
            }

        //checking knight
    for(int i = 0; i < 4; i++){
        int j;
        int k;

        switch(i){
            case 0:
                j = 2;
                k = 1;
                break;
            case 1:
                j = -2;
                k = 1;
                break;
            case 2:
                j = 1;
                k = 2;
                break;
            case 3:
                j = 1;
                k = -2;
                break;
        }
        if((board[kingRank + j][kingFile + k] == -knight && color == 'w') || (board[kingRank + j][kingFile + k] == knight && color == 'b')) {
            return true;
        }
        if((board[kingRank - j][kingFile - k] == -knight && color == 'w') || (board[kingRank - j][kingFile - k] == knight && color == 'b')) {
            return true;
        }
    }
    //TODO make check for pawns work can't use same thing cause they have to be one away

            return false;
}

int main() {
    newGame();
    printScreen(board);

    int newFile;
    int newRank;
    int pieceType;
    char color;
    std::string coord;

    for(int i = 1; i < 10; i++) {  //plays several moves //TODO force black and white moves to alternate, make the for loop end at checkmake


        if(i%2 == 1) {
            color = 'w';
            if (!isInCheck(color))
                std::cout << "It is white's move select a white piece: ";
            else
                std::cout << "White is in check, select a piece to move out of check: ";

            std::cin >> coord;

            newRank = debugTools::charGrabber(coord);
            newFile = debugTools::intGrabber(coord);

            while (board[newRank][newFile] <= 0) {
                std::cout << "It is white's move select a white piece: ";
                std::cin >> coord;

                newRank = debugTools::charGrabber(coord);
                newFile = debugTools::intGrabber(coord);
            }
            pieceType = board[newRank][newFile];
        }
        else {
            color = 'b';
            if (!isInCheck(color))
                std::cout << "It is black's move select a black piece: ";
            else
                std::cout << "Black is in check, select a piece to move out of check: ";

            std::cin >> coord;

            newRank = debugTools::charGrabber(coord);
            newFile = debugTools::intGrabber(coord);

            while (board[newRank][newFile] >= 0) {
                std::cout << "It is black's move select a black piece: ";
                std::cin >> coord;

                newRank = debugTools::charGrabber(coord);
                newFile = debugTools::intGrabber(coord);
            }
            pieceType = -1 * board[newRank][newFile];
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
                pieces::queen(board, newRank, newFile, color);
                break;
            case king:
                pieces::king(board, newRank, newFile, color);
                break;
        }

        printScreen(board);
    }

    //TODO currently if you move the pawn at 6x0 to 4x0, the rook at 7x0 can capture the piece at 4x0 -- fix this

    return 0;
}
