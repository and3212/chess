/* Author: Liam Lawrence
 * Date: 1.1.17
 * Header file for pieces.cpp
 */

#ifndef CHESS_PIECES_HPP
#define CHESS_PIECES_HPP


class pieces {
public:
    static void pawn(int board[8][8], int rank, int file, char player);
    static void rook(int board[8][8], int rank, int file, char player);
    static void bishop(int board[8][8], int rank, int file, char player);
    static void knight(int board[8][8], int rank, int file, char player);
};


#endif //CHESS_PIECES_HPP
