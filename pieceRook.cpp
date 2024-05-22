/***********************************************************************
 * Source File:
 *    ROOK
 * Author:
 *    Cayden Lords and Ryan Donaldson
 * Summary:
 *    The rook class
 ************************************************************************/

#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Rook::display(ogstream* pgout) const
{
   pgout->drawRook(position, fWhite);
}


/**********************************************
 * ROOK : GET POSITIONS
 * INPUT:
 * moves = empty list of possible moves
 * board = the current game board
 *********************************************/
void Rook::getMoves(set <Move>& moves, const Board& board) const
{

}