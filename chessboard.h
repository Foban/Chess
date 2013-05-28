#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "king.h"
#include "figura.h"
#include "common.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"


class ChessBoard
{
public:
    ChessBoard();
    ~ChessBoard();
    void Play();
private:
    int Checkmate(bool);
    bool Check(bool,int**);
    bool Status(bool);
    void Drow();
    bool Hod();
    int** make_mask(bool);
    void delete_mask(int**);

    Figura * board[8][8];
    Figura * active_board[8][8];

};

#endif // CHESSBOARD_H
