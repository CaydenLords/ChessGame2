/***********************************************************************
 * Header File:
 *    QUEEN
 * Author:
*    Cayden Lords
 * Summary:
 *    The Queen class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * QUEEN
  * The queen, aka the "Best Piece"
  ***************************************************/
class Queen : public Piece
{
public:
   // Constructors
   Queen(const Position& pos, bool isWhite) : Piece(10, 10, true)
   {
      position = pos;
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   Queen(int c, int r, bool isWhite) : Piece(10, 10, true)
   {
      position = Position(c, r);
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   ~Queen() {  }

   PieceType getType()            const { return QUEEN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};