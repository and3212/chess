//
// Created by and3212 on 1/1/17.
//

#include "pieces.hpp"
#include "iostream"

int listOfMoves[10][10];
int listOfCaptures[10][10];

void moveList(int file, int rank){
    static int i = 0;
    listOfMoves[i][i] = (file, rank);
    i++;
}

void captureList(int file, int rank){
    static int i = 0;
    listOfCaptures[i][i] = (file, rank);
    i++;
}

/* PAWN */
void pieces::pawn(int board[8][8], int rank, int file, char player){
    int move;
    int newfile;
    int newrank;
    int newTile[1][1];

    // Determines the direction the piece moves
    if(player == 'w')
        move = 1;
    else
        move = -1;


    // Moving the pawn forward
    if(board[rank + (1 * move)][file] == 0) {
        moveList(rank + (1 * move), file); // one space forward if empty

        // The initial two space jump for each player
        if (player == 'w' && rank == 2 && board[rank + (2 * move)][file] == 0) {
            moveList(file, rank + (2 * move));

        } else if (player == 'b' && rank == 6 && board[file][rank + (2 * move)] == 0) {
            moveList(file, rank + (2 * move));
        }
    }

    // Capturing a piece with the pawn
    if((player == 'w' && board[file + (1 * move)][rank + 1] < 0) ||
       (player == 'b' && board[file + (1 * move)][rank + 1] > 0))
        captureList(file + (1 * move), rank + (1 * move));

    if((player == 'w' && board[file + (1 * move)][rank + -1] < 0) ||
       (player == 'b' && board[file + (1 * move)][rank + -1] > 0))
        captureList(file + (1 * move), rank + -1);


    std::cout << "Where would you like to move?:";
    std::cin >> newrank;
    std::cin >> newfile;
    newTile[0][0] = (newfile, newrank);

    for(int i = 0; i < 10; i++){
        if(newTile[0][0] == listOfMoves[i][i]){
            board[file][rank] = 0;
            board[newfile][newrank] = (1 * move);
            break;
        }
    }

    for(int i = 0; i < 10; i++){
        if(newTile[0][0] == listOfCaptures[i][i]){
            board[file][rank] = 0;
            board[newfile][newrank] = (1 * move);
            break;
        }
    }
}
/* END PAWN */