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
   // List of Possible moves
   Delta possibleMoves[8] =
   {
            {-1,  2}, { 1,  2},
   {-2,  1},                    { 2,  1},
   {-2, -1},                    { 2, -1},
            {-1, -2}, { 1, -2}
   };

   // For each possible move
   for (int i = 0; i < 8; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Check that it's valid
      if (pos.isValid()) {
         // Check whether it's a space
         if (board[pos].getType() == SPACE) {
            moves.insert(Move(position, pos, SPACE));
         }
         // Otherwise, check if it's a capturable piece
         else if (board[pos].isWhite() != isWhite()) {
               moves.insert(Move(position, pos, board[pos].getType()));
            }
      }
   }
}