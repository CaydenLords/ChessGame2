/***********************************************************************
 * Source File:
 *    QUEEN
 * Author:
 *    Cayden Lords and Ryan Donaldson
 * Summary:
 *    The queen class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Queen::display(ogstream* pgout) const
{
   pgout->drawQueen(position, fWhite);
}


/**********************************************
 * QUEEN : GET POSITIONS
 * INPUT:
 * moves = empty list of possible moves
 * board = the current game board
 *********************************************/
void Queen::getMoves(set <Move>& moves, const Board& board) const
{
   this->diagonalMoves(moves, board);
   this->straightMoves(moves, board);
}