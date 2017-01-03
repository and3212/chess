/* Author: Liam Lawrence
 * Date: 1.1.17
 * Movement for each type of piece for the chess board
 */

#include "debug/debugTools.hpp"
#include "pieces.hpp"
#include "iostream"

// Initializes the list of moves and fills the spaces with '-99's
int listOfMoves[15][2] = {{-99}};

// Allows you to add valid positions to the listOfMoves array
void moveList(int rank, int file){
    static int i = 0;
    listOfMoves[i][0] = rank;
    listOfMoves[i][1] = file;
    i++;
}

/* PAWN */
void pieces::pawn(int board[8][8], int rank, int file, char player){
    int move;
    int newFile;
    int newRank;
    int newTile[1];

    // Determines the direction the piece moves and final color of moved piece
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


    char rankHolder;
    std::cout << "Where would you like to move?: ";
    std::cin >> rankHolder;
    std::cin >> newFile;

    newRank = debugTools::charToCoords(rankHolder);
    newFile = debugTools::intToCoords(newFile);

    newTile[0] = newRank;
    newTile[1] = newFile;

    // Checks to see if the player specified a valid move
    for(int i = 0; i < 10; i++){
        if(newTile[0] == listOfMoves[i][0] && newTile[1] == listOfMoves[i][1]){
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
    // Determines the final color of the moved piece
    if(player == 'w')
        move = 1;
    else
        move = -1;


    // Moving Right
    for(int i = 1; i < 8; i++){
        if(rank + i > 7)
            break;
        //TODO remove the 'board[rank][file] == 0' and make the other two <= or >= 0
        if(board[rank + i][file] == 0 ||                     // Empty space
           (player == 'w' && board[rank + i][file] < 0) ||   // Enemy for white
           (player == 'b' && board[rank + i][file] > 0)){    // Enemy for black
            moveList(rank + i, file);
        }
        else{
            break;
        }
    }

    std::cout << "RANK OF 4x0 is " << board[4][0] << "\n"; //TODO remove this after debugging
    // Moving Left
    for(int i = 1; i < 8; i++){
        if(rank - i < 0)
            break;
        if(board[rank - i][file] == 0 ||                     // Empty space
           (player == 'w' && board[rank - i][file] < 0) ||   // Enemy for white
           (player == 'b' && board[rank - i][file] > 0)){    // Enemy for black
            moveList(rank - i, file);
        }
        else{
            break;
        }
    }

    // Moving Up
    for(int i = 1; i < 8; i++){
        if(file + i > 7)
            break;

        if(board[rank][file + i] == 0 ||                     // Empty space
           (player == 'w' && board[rank][file + i] < 0) ||   // Enemy for white
           (player == 'b' && board[rank][file + i] > 0)){    // Enemy for black
            moveList(rank, file + i);
        }
        else{
            break;
        }
    }

    // Moving Down
    for(int i = 1; i < 8; i++){
        if(file - 1 < 0)
            break;

        if(board[rank][file - i] == 0 ||                    // Empty space
           (player == 'w' && board[rank][file - i] < 0) ||   // Enemy for white
           (player == 'b' && board[rank][file - i] > 0)){    // Enemy for black
            moveList(rank, file - i);
        }
        else{
            break;
        }
    }

    int newRank;
    int newFile;
    int newTile[1];
    char rankHolder;
    std::cout << "Where would you like to move?: ";
    std::cin >> rankHolder;
    std::cin >> newFile;
    newRank = debugTools::charToCoords(rankHolder);
    newFile = debugTools::intToCoords(newFile);

    newTile[0] = newRank;
    newTile[1] = newFile;

    // Checks if the player specified a valid move
    for(int i = 0; i < 15; i++) {
        if (newTile[0] == listOfMoves[i][0] && newTile[1] == listOfMoves[i][1]) {
            board[rank][file] = 0;
            board[newRank][newFile] = (3 * move);
            return; // or break?
        }
    }
}
//TODO add castling on both king and queen side
/* END ROOK */

/* BISHOP */
void pieces::bishop(int board[8][8], int rank, int file, char player){
    int move;
    int newFile;
    int newRank;
    int newTile[1];

    // Determines the direction the piece moves
    if(player == 'w')
        move = 1;
    else
        move = -1;

    // Moving up-right
    for(int i = 1; i < 8; i++){

        if(board[rank + i][file + i] == 0 ||                    // spot is empty
           (player == 'w' && board[rank + i][file + i] < 0) ||  // spot is an enemy for white
           (player = 'b' && board[rank + i][file + i] > 0)){    // spot is an enemy for black
                moveList(rank + i, file + i);
        }
        else{
            break;
        }
    }
    // Moving up-left
    for(int i = 1; i < 8; i++){
        if(board[rank + i][file - i] == 0 ||                    // spot is empty
           (player == 'w' && board[rank + i][file - i] < 0) ||  // spot is an enemy for white
           (player = 'b' && board[rank + i][file - i] > 0)){    // spot is an enemy for black
            moveList(rank + i, file - i);
        }
        else{
            break;
        }
    }
    // Moving down-right
    for(int i = 1; i < 8; i++){
        if(board[rank - i][file + i] == 0 ||                    // spot is empty
           (player == 'w' && board[rank - i][file + i] < 0) ||  // spot is an enemy for white
           (player = 'b' && board[rank - i][file + i] > 0)){    // spot is an enemy for black
            moveList(rank - i, file + i);
        }
        else{
            break;
        }
    }
    // Moving down-left
    for(int i = 1; i < 8; i++) {
        if (board[rank - i][file - i] == 0 ||                    // spot is empty
            (player == 'w' && board[rank - i][file - i] < 0) ||  // spot is an enemy for white
            (player = 'b' && board[rank - i][file - i] > 0)) {    // spot is an enemy for black
            moveList(rank - i, file - i);
        } else {
            break;
        }
    }

    std::cout << "Where would you like to move?:";
    std::cin >> newRank;
    std::cin >> newFile;
    newTile[0] = newRank;
    newTile[1] = newFile;

    // Checks if the player specified a valid move
    for(int i = 0; i < 15; i++) {
        if (newTile[0] == listOfMoves[i][0] && newTile[1] == listOfMoves[i][1]) {
            board[rank][file] = 0;
            board[newRank][newFile] = (2 * move);
            return; // or break?
        }
    }
}
/* END BISHOP */

/* KNIGHT */
void pieces::knight(int board[8][8], int rank, int file, char player){
    int move;
    // Determines the final color of the moved piece
    if(player == 'w')
        move = 1;
    else
        move = -1;

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
                j = -1;
                k = -2;
                break;
        }
        if(board[rank + j][file + k] <= 0 && player == 'w' || board[rank + j][file + k] >= 0 && player == 'b')
            moveList(rank + j, file + k);
        if(board[rank - j][file - k] <= 0 && player == 'w' || board[rank - j][file - k] >= 0 && player == 'b')
            moveList(rank - j, file - k);
    }



    int newRank;
    int newFile;
    int newTile[1];

    char rankHolder;
    std::cout << "Where would you like to move?: ";
    std::cin >> rankHolder;
    std::cin >> newFile;

    newRank = debugTools::charToCoords(rankHolder);
    newFile = debugTools::intToCoords(newFile);

    newTile[0] = newRank;
    newTile[1] = newFile;

    // Checks to see if the player specified a valid move
    for(int i = 0; i < 10; i++){
        if(newTile[0] == listOfMoves[i][0] && newTile[1] == listOfMoves[i][1]){
            board[rank][file] = 0;
            board[newRank][newFile] = (1 * move);
            return; // or break?
        }
    }

}
/* END KNIGHT */
