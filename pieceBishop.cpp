/***********************************************************************
 * Source File:
 *    BISHOP
 * Author:
 *    Cayden Lords and Ryan Donaldson
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Bishop::display(ogstream* pgout) const
{
   pgout->drawBishop(position, fWhite);
}


/**********************************************
 * BISHOP : GET POSITIONS
 * INPUT:
 * moves = empty list of possible moves
 * board = the current game board
 *********************************************/
void Bishop::getMoves(set <Move>& moves, const Board& board) const
{
   this->diagonalMoves(moves, board);
}