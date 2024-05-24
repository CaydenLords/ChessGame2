/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    Cayden Lords and Ryan Donaldson
 * Summary:
 *    The pawn class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, fWhite);
}


/**********************************************
 * PAWN : GET POSITIONS
 * INPUT:
 * moves = empty list of possible moves
 * board = the current game board
 *********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{
   if (this->fWhite == true)
   {
      this->pawnSimpleWhiteMove(moves, board);
      this->pawnWhiteDoubleMove(moves, board);
      this->pawnWhiteCaptureBlack(moves, board);
      this->enPassantWhite(moves, board);
   }
   else
   {
      this->pawnSimpleBlackMove(moves, board);
      this->pawnBlackDoubleMove(moves, board);
      this->pawnBlackCaptureWhite(moves, board);
      this->enPassantBlack(moves, board);
   }
   
}