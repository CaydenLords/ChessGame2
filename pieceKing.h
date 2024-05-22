/***********************************************************************
 * Header File:
 *    KING
 * Author:
*    Cayden Lords
 * Summary:
 *    The KING class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KING
  * The king, aka the "Monarch, The Big Cheese, Mr. President, Elvis Presley"
  ***************************************************/
class King : public Piece
{
public:
   // Constructors
   King(const Position& pos, bool isWhite) : Piece(10, 10, true)
   {
      position = pos;
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   King(int c, int r, bool isWhite) : Piece(10, 10, true)
   {
      position = Position(c, r);
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   ~King() {  }

   PieceType getType()            const { return KING; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};