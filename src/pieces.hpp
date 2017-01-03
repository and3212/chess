/* Author: Liam Lawrence
 * Date: 1.1.17
 * Header file for pieces.cpp
 */

#ifndef CHESS_PIECES_HPP
#define CHESS_PIECES_HPP
typedef int array_type[8][8];

class pieces {
public:
    static void pawn(array_type& board, int rank, int file, char player);
    static void rook(array_type& board, int rank, int file, char player);
    static void bishop(array_type& board, int rank, int file, char player);
    static void knight(array_type& board, int rank, int file, char player);
};


#endif //CHESS_PIECES_HPP
