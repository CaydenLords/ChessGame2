/***********************************************************************
 * Source File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include "position.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
{
	source = Position();
	dest = Position();
}

/*************************************
 * pieceTypeFromLetter
 * INPUT:
 * char letter = a letter that corresponds to a piece.
 * OUTPUT
 * The piece type that corresponds to the letter.
 **************************************/
PieceType Move::pieceTypeFromLetter(char letter) const {
	switch (letter) {
	case 'p':
		return PAWN;
	case 'b':
		return BISHOP;
	case 'n':
		return KNIGHT;
	case 'r':
		return ROOK;
	case 'q':
		return QUEEN;
	case 'k':
		return KING;
	case ' ':
		return SPACE;
	default:
		return INVALID;
	}
}
/*************************************
 * letterFromPieceType
 * INPUT:
 * PieceType pt = A type of piece.
 * OUTPUT
 * The letter that corresponds to the piece type.
 **************************************/
char Move::letterFromPieceType(PieceType pt) const {
	switch (pt) {
	case PAWN:
		return 'p';
	case BISHOP:
		return 'b';
	case KNIGHT:
		return 'n';
	case ROOK:
		return 'r';
	case QUEEN:
		return 'q';
	case KING:
		return 'k';
	case SPACE:
		return ' ';
	default:
		return '?';
	}
}

/***************************************************
 * MOVE : GET TEXT
 *	Create a string for a move like "e5e6r"
 * OUTPUT: (example) e5e6r
 ***************************************************/
string Move::getText() const
{
	string text;
	text += 'a' + source.getCol();
	text += '1' + source.getRow();
	text += 'a' + dest.getCol();
	text += '1' + dest.getRow();
	if (moveType == Move::MoveType::MOVE && capture == SPACE)
	{
		text += "";
	}
	else if (moveType == Move::MoveType::ENPASSANT)
	{
		text += "E";
	}
	else if (moveType == Move::MoveType::CASTLE_KING)
	{
		text += "c";
	}
	else if (moveType == Move::MoveType::CASTLE_QUEEN)
	{
		text += "C";
	}
	else if (moveType == Move::MoveType::MOVE_ERROR)
	{
		text = "ERROR";
	}
	else
	{
		text += letterFromPieceType(capture);
	}


	return text;
}

