/* Author: Liam Lawrence and Elijah Hodges
 * Date: 5.11.17
 * Main file to control the chess board
 */

#include <stdio.h>  //TODO remove this once we are finished if we can
#include "bluetoothController.c"
#include "motorController.c"
#include "watchDog.c"

/* CHESS PIECES */
#define pawn 1
#define bishop 2
#define rook 3
#define knight 4
#define queen 5
#define king 6

// initializes an 8x8 board to play on
// [file][rank] == [y][x]
int board[8][8];
int tempBoard[8][8];  // Temp board to revert illegal moves

// Initial setup for a new game
// Positives are 'white' and negatives are 'black'
const int startingBoard[8][8] = {
        {rook, knight, bishop, queen, king, bishop, knight, rook},
        {pawn, pawn, pawn, pawn, pawn, -pawn, pawn, pawn},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {-pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn, -pawn},
        {-rook, -knight, -bishop, -queen, -king, -bishop, -knight, -rook}
};


// Sets up the board to the default position
void newGame() {
    setupNewGame(startingBoard);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            board[i][j] = startingBoard[i][j];
        }
    }
}

// Prints out the current layout of the board   TODO: Remove this if we run out of memory
void printScreen(int board[8][8]) {
    char piece;
    printf("   --------------------------\n");

    // Uppercase is white and Lowercase is black
    for(int i = 7; i > -1; i--) {
        for(int j = 0; j < 8; j++) {
            switch(board[i][j]) {
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

            if(j == 0) {
                printf("%d | ", 8 - i);
            }
            printf(" %c ", piece);
        }
        printf(" |\n");
    }
    printf("   --------------------------\n");
    printf("     A  B  C  D  E  F  G  H\n");
}

int main() {
    //uart_init();
    newGame();
    printScreen(board);
}