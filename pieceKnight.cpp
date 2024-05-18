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

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   Delta possibleMoves[8] =
   {
            {-1,  2}, { 1,  2},
   {-2,  1},                    { 2,  1},
   {-2, -1},                    { 2, -1},
            {-1, -2}, { 1, -2}
   };
   for (int i = 0; i < 8; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      if (pos.isValid()) {
         if (board[pos].getType() == SPACE) {
            moves.insert(Move(position, pos, SPACE));
         }
         else if (board[pos].isWhite() != isWhite()) {
               moves.insert(Move(position, pos, board[pos].getType()));
            }
      }
   }
}