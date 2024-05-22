/***********************************************************************
 * Source File:
 *    KING
 * Author:
 *    Cayden Lords and Ryan Donaldson
 * Summary:
 *    The king class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void King::display(ogstream* pgout) const
{
   pgout->drawKing(position, fWhite);
}


/**********************************************
 * KING : GET POSITIONS
 * INPUT:
 * moves = empty list of possible moves
 * board = the current game board
 *********************************************/
void King::getMoves(set <Move>& moves, const Board& board) const
{

}