/***********************************************************************
 * Header File:
 *    KNIGHT
 * Author:
*    Cayden Lords
 * Summary:
 *    The KNIGHT class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KNIGHT
  * The knight, aka the "Horse"
  ***************************************************/
class Knight : public Piece
{
public:
   // Constructors
   Knight(const Position& pos, bool isWhite) : Piece(10,10,true) 
   {
      position = pos;
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   Knight(int c, int r, bool isWhite) : Piece(10, 10, true) 
   {
      position = Position(c, r);
      fWhite = isWhite;
      lastMove = 0;
      nMoves = 0;
   }
   ~Knight() {  }

   PieceType getType()            const { return KNIGHT; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};