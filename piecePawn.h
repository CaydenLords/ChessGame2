/***********************************************************************
 * Header File:
 *    PAWN
 * Author:
*    Cayden Lords
 * Summary:
 *    The PAWN class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * PAWN
  * The pawn, aka the "cannon fodder"
  ***************************************************/
class Pawn : public Piece
{
public:
   // Constructors
   Pawn(const Position& pos, bool isWhite) : Piece(10, 10, true)
   {
      position = pos;
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   Pawn(int c, int r, bool isWhite) : Piece(10, 10, true)
   {
      position = Position(c, r);
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   ~Pawn() {  }

   PieceType getType()            const { return PAWN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};