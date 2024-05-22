/***********************************************************************
 * Header File:
 *    ROOK
 * Author:
*    Cayden Lords
 * Summary:
 *    The ROOK class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KNIGHT
  * The rook, aka the "Tower"
  ***************************************************/
class Rook : public Piece
{
public:
   // Constructors
   Rook(const Position& pos, bool isWhite) : Piece(10, 10, true)
   {
      position = pos;
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   Rook(int c, int r, bool isWhite) : Piece(10, 10, true)
   {
      position = Position(c, r);
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   ~Rook() {  }

   PieceType getType()            const { return ROOK; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};