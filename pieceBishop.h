/***********************************************************************
 * Header File:
 *    BISHOP
 * Author:
*    Cayden Lords
 * Summary:
 *    The BISHOP class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * BISHOP
  * The bishop, aka the "Separation of church and state"
  ***************************************************/
class Bishop : public Piece
{
public:
   // Constructors
   Bishop(const Position& pos, bool isWhite) : Piece(10, 10, true)
   {
      position = pos;
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   Bishop(int c, int r, bool isWhite) : Piece(10, 10, true)
   {
      position = Position(c, r);
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   ~Bishop() {  }

   PieceType getType()            const { return BISHOP; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};