//
// Created by and3212 on 1/1/17.
//

#include "pieces.hpp"
#include "iostream"

int listOfMoves[15][15];

void moveList(int file, int rank){
    static int i = 0;
    listOfMoves[i][i] = (rank, file);
    i++;
}

/* PAWN */
void pieces::pawn(int board[8][8], int rank, int file, char player){
    int move;
    int newFile;
    int newRank;
    int newTile[1][1];

    // Determines the direction the piece moves
    if(player == 'w')
        move = 1;
    else
        move = -1;


    // Moving the pawn forward
    if(board[rank + (1 * move)][file] == 0) {
        moveList(rank + (1 * move), file); // one space forward if empty
        std::cout << "CHECK ONE" << "\n";

        // The initial two space jump for each player
        if (player == 'w' && rank == 1 && board[rank + 2][file] == 0) {
            moveList(rank + (2 * move), file);
            std::cout << "CHECK TWO" << "\n";

        } else if (player == 'b' && rank == 6 && board[rank - 2][file] == 0) {
            moveList(rank + (2 * move), file);
            std::cout << "CHECK TWO" << "\n";
        }
    }

    // Capturing a piece with the pawn
    if((player == 'w' && board[rank + (1 * move)][file + 1] < 0) ||
       (player == 'b' && board[rank + (1 * move)][file + 1] > 0))
        moveList(rank + (1 * move), file + 1);   // The upwards diagonal

    if((player == 'w' && board[rank + (1 * move)][file + -1] < 0) ||
       (player == 'b' && board[rank + (1 * move)][file + -1] > 0))
        moveList(rank + (1 * move), file + -1);  // The downwards diagonal


    std::cout << "Where would you like to move?:";
    std::cin >> newRank;
    std::cin >> newFile;
    newTile[0][0] = (newFile, newRank);

    for(int i = 0; i < 10; i++){
        if(newTile[0][0] == listOfMoves[i][i]){
            board[rank][file] = 0;
            board[newRank][newFile] = (1 * move);
            return; // or break?
        }
    }

    //TODO add when a pawn reaches the end of the board
}
/* END PAWN */

/* ROOK */
void pieces::rook(int board[8][8], int rank, int file, char player){

    int move;
    // Is the players color
    if(player == 'w')
        move = 1;
    else
        move = -1;

    // Moving Right
    for(int i = 1; i < 8; i++){
            // Board limits
        if(rank + i > 7)
            break;

            // Friendly piece
        if((board[rank + i][file] > 0 && player == 'w') || (board[rank + i][file] < 0 && player == 'b'))
            break;

            // Empty space
        else if(board[rank + i][file] == 0)
            moveList(rank + i, file);

            // Enemy piece
        else if((board[rank + i][file] < 0 && player == 'w') || (board[rank + i][file] > 0 && player == 'b')) {
            moveList(rank + i, file);
            break;
        }
    }
    // Moving Left
    for(int i = -1; i > -8; i--){
        // Board limits
        if(rank + i < 0)
            break;

        // Friendly piece
        if((board[rank + i][file] > 0 && player == 'w') || (board[rank + i][file] < 0 && player == 'b'))
            break;

            // Empty space
        else if(board[rank + i][file] == 0)
            moveList(rank + i, file);

            // Enemy piece
        else if((board[rank + i][file] < 0 && player == 'w') || (board[rank + i][file] > 0 && player == 'b')) {
            moveList(rank + i, file);
            break;
        }
    }
    // Moving Up
    for(int i = 1; i < 8; i++){
        // Board limits
        if(rank + i > 7)
            break;

        // Friendly piece
        if((board[rank][file + i] > 0 && player == 'w') || (board[rank][file + i] < 0 && player == 'b'))
            break;

            // Empty space
        else if(board[rank][file + i] == 0)
            moveList(rank, file + i);

            // Enemy piece
        else if((board[rank][file + i] < 0 && player == 'w') || (board[rank][file + i] > 0 && player == 'b')) {
            moveList(rank, file + i);
            break;
        }
    }
    // Moving Down
    for(int i = -1; i > -8; i--){
        // Board limits
        if(rank + i < 0)
            break;

        // Friendly piece
        if((board[rank][file + i] > 0 && player == 'w') || (board[rank][file + i] < 0 && player == 'b'))
            break;

            // Empty space
        else if(board[rank][file + i] == 0)
            moveList(rank, file + i);

            // Enemy piece
        else if((board[rank][file + i] < 0 && player == 'w') || (board[rank][file + i] > 0 && player == 'b')) {
            moveList(rank, file + i);
            break;
        }
    }

    int newRank;
    int newFile;
    int newTile[1][1];
    std::cout << "Where would you like to move?:";
    std::cin >> newRank;
    std::cin >> newFile;
    newTile[0][0] = (newFile, newRank);

    for(int i = 0; i < 15; i++) {
        if (newTile[0][0] == listOfMoves[i][i]) {
            board[rank][file] = 0;
            board[newRank][newFile] = (3 * move);
            return; // or break?
        }
    }
}

/* END ROOK */