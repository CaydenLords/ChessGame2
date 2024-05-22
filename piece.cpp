/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{

   return *this;
}

/************************************************
 * PIECE : IS WHITE
 * OUTPUT: tells if piece is white or not
 ***********************************************/
bool Piece::isWhite() const
{
   return fWhite;
}

/************************************************
 * PIECE : IS MOVED
 * OUTPUT: tells if piece has moved or not
 ***********************************************/
bool Piece::isMoved() const
{
   if (nMoves == 0)
      return false;
   else
      return true;
}

/************************************************
 * PIECE : GET N MOVES
 * OUTPUT: Number of moves
 ***********************************************/
int Piece::getNMoves() const
{
   return nMoves;
}

void Piece::incrementNMoves()
{
   nMoves++;
}

/************************************************
 * PIECE : GET POSITION
 * OUTPUT: Return's the classes position
 ***********************************************/
const Position& Piece::getPosition() const
{
   return position;
}

/************************************************
 * PIECE : JUST MOVED
 * INPUT: current move number
 * OUTPUT: tells if piece just moved or not
 ***********************************************/
bool Piece::justMoved(int currentMove) const
{
   if (currentMove > (lastMove + 1))
      return false;
   else
      return true;
}

/************************************************
 * PIECE : SET LAST MOVE
 * INPUT: current move number
 * 
 ***********************************************/
void Piece::setLastMove(int currentMove)
{
   lastMove = currentMove;
   nMoves++;
}

void Piece::setPosition(const Position & pos)
{
   position = pos;
}


/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

/************************************************
 * PIECE : GET DIAGONAL MOVES
 * Iterate through all of the diagonal slide moves
 ***********************************************/
void Piece::diagonalMoves(set <Move>& moves, const Board& board) const{
   // List of Possible moves
   Delta possibleMoves[8] =
   {
   { -1, 1},          { 1,  1},

   { -1, -1},         { 1, -1},
   };
   // For each possible move
   for (int i = 0; i < 4; i++)
   {
      Position pos = position;
      bool continueSlide = true;
      // Check that it's valid
      while (continueSlide) {
            pos = Position(pos.getCol() + possibleMoves[i].dCol, pos.getRow() + possibleMoves[i].dRow);
            if (pos.isValid()) {
               // Check whether it's a space
               if (board[pos].getType() == SPACE) {
                  moves.insert(Move(position, pos, SPACE));
               }
               // Otherwise, check if it's a capturable piece
               else if (board[pos].isWhite() != isWhite()) {
                  moves.insert(Move(position, pos, board[pos].getType()));
                  continueSlide = false;
               }
               else {
                  continueSlide = false;
               }
            }
            else {
               continueSlide = false;
            }
      }
   }
}

/************************************************
 * PIECE : GET ADJACENT MOVES
 * Iterate through all of the diagonal slide moves
 ***********************************************/
void Piece::straightMoves(set <Move>& moves, const Board& board) const {
   // List of Possible moves
   Delta possibleMoves[8] =
   {
             { 0, 1},          
   { -1,  0},         { 1, 0},         
            { 0, -1},
   };
   // For each possible move
   for (int i = 0; i < 4; i++)
   {
      Position pos = position;
      bool continueSlide = true;
      // Check that it's valid
      while (continueSlide) {
         pos = Position(pos.getCol() + possibleMoves[i].dCol, pos.getRow() + possibleMoves[i].dRow);
         if (pos.isValid()) {
            // Check whether it's a space
            if (board[pos].getType() == SPACE) {
               moves.insert(Move(position, pos, SPACE));
            }
            // Otherwise, check if it's a capturable piece
            else if (board[pos].isWhite() != isWhite()) {
               moves.insert(Move(position, pos, board[pos].getType()));
               continueSlide = false;
            }
            else {
               continueSlide = false;
            }
         }
         else {
            continueSlide = false;
         }
      }
   }
}