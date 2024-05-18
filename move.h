/***********************************************************************
 * Header File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // constructor
   Move();
	Move(Position sourceP, Position destP, PieceType piece);
   Move(const string & rhs) {
		text = rhs;
		string srcChars = text.substr(0, 2);
		string destChars = text.substr(2, 2);
		source = Position(srcChars.c_str());
		dest = Position(destChars.c_str());

		source = (source.getCol(), source.getRow());
		dest = (dest.getCol(), dest.getRow());

		if (size(text) == 4)
		{
			moveType = MoveType{ MOVE };
		}
		else if (size(text) == 5)  // Check that text is long enough
		{
			switch (text[4])
			{
			case 'E':
				moveType = MoveType{ ENPASSANT };
				break;
			case 'c':
				moveType = MoveType{ CASTLE_KING };
				break;
			case 'C':
				moveType = MoveType{ CASTLE_QUEEN };
				break;
			default:
				PieceType piece = pieceTypeFromLetter(text[4]);
				capture = piece;
				moveType = MoveType{ MOVE };
				break;
			}
		}
   }
	bool operator <  (const Move& rhs) const { return dest < rhs.dest; }
	bool operator == (const Move& rhs) const { return ((source == source) && (dest == dest)); }
	bool operator != (const Move& rhs) const { return !(*this == rhs); }
	const Position& operator =  (const Move& rhs) {
		source = rhs.source;
		dest = rhs.dest;
		promote = rhs.promote;
		capture = rhs.capture;
		moveType = rhs.moveType;
		isWhite = rhs.isWhite;
		text = rhs.text;
	}
   void read(const string & rhs) {}
	string getText() const;



private:
	char letterFromPieceType(PieceType pt)     const;
	PieceType pieceTypeFromLetter(char letter) const;



   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};


