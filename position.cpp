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
	return (colRow >> 4) & 0x0F;
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
	return colRow & 0x0F;
}

/*************************************
 * SET COLUMN
 * INPUT:
 * int c = Column number
 **************************************/
void Position::setCol(int c)
{
	colRow = (colRow & 0x0F) | (c << 4);
}

/*************************************
 * SET ROW
 * INPUT:
 * int r = Row number
 **************************************/
void Position::setRow(int r)
{
	colRow = (colRow & 0xF0) | r;
}

/*************************************
 * SET
 * INPUT:
 * int r = Row Number
 * int c = Column Number
 **************************************/
void Position::set(int c, int r)
{
	setCol(c);
	setRow(r);

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

