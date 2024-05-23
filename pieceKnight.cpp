/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Cayden Lords
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
   pgout->drawKnight(position, fWhite);
}


/**********************************************
 * KNIGHT : GET POSITIONS
 * INPUT: 
 * moves = empty list of possible moves
 * board = the current game board 
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   this->knightMoves(moves, board);
}