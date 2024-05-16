/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

 /******************************************
  * POSITION INSERTION OPERATOR
  ******************************************/
ostream& operator << (ostream& out, const Position& rhs)
{
	out << "error";
	return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream& operator >> (istream& in, Position& rhs)
{
	return in;
}

/*************************************
 * GET COLUMN
 * OUTPUT:
 * Column number
 * If invalid, returns -1
 **************************************/
int Position::getCol() const
{
	if (isInvalid())
	{
		return -1;
	}
	return (int)((colRow & 0xf0) >> 4);
}

/*************************************
 * GET ROW
 * OUTPUT:
 * Row number
 * If invalid, returns -1
 **************************************/
int Position::getRow() const
{
	if (isInvalid())
	{
		return -1;
	}
	return (int)((colRow & 0x0f) >> 0);
}

/*************************************
 * SET COLUMN
 * INPUT:
 * int c = Column number
 **************************************/
void Position::setCol(int c)
{
	colRow = getRow() + (c * 16);
}

/*************************************
 * SET ROW
 * INPUT:
 * int r = Row number
 **************************************/
void Position::setRow(int r)
{
	colRow = (getCol() * 16) + r;
}

/*************************************
 * SET
 * INPUT:
 * int r = Row Number
 * int c = Column Number
 **************************************/
void Position::set(int c, int r)
{
	colRow = (c * 16) + r;
	if (isInvalid())
	{
		colRow = 0xff;
	}
}

/*************************************
 * isInvalid
 * OUTPUT:
 * True if the position is invalid, false otherwise
 **************************************/
bool Position::isInvalid() const
{
	if (colRow == 0xff)
	{
		return true;
	}
	if (((int)((colRow & 0xf0) >> 4) > 7) || ((int)((colRow & 0xf0) >> 4) < 0))
	{
		return true;
	}
	if (((int)((colRow & 0x0f) >> 0) > 7) || ((int)((colRow & 0x0f) >> 0) < 0))
	{
		return true;
	}
	return false;
}

/*************************************
 * isValid
 * OUTPUT:
 * True if the position is valid, false otherwise
 **************************************/
bool Position::isValid() const
{
	return !isInvalid();
}

/*************************************
 * GET Location
 * OUTPUT:
 * Get the representative number for the location (the Column Number + the Row number times 8)
 * If invalid, returns -1
 **************************************/
int Position::getLocation() const
{
	if (isInvalid())
	{
		return -1;
	}
	return getCol() + (getRow() * 8);
}

