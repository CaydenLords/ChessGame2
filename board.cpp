/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "move.h"
#include <cassert>
#include <vector>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
      {
         //delete board[c][r];
         board[c][r]  = nullptr;
      }
         

   // add knights...????
   board[1][0] = new Knight(Position(1, 0), false);
   board[6][0] = new Knight(Position(6, 0), false);
   board[1][7] = new Knight(Position(1, 7), true);
   board[6][7] = new Knight(Position(6, 7), true);
}


/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   int col = pos.getCol();
   int row = pos.getRow();

   return *(board[col][row]);
}
Piece& Board::operator [] (const Position& pos)
{
   int col = pos.getCol();
   int row = pos.getRow();

   return *(board[col][row]);
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   vector<std::pair<Position, bool>> knights = { {Position(1, 0), false}, {Position(6, 0), false}, {Position(1, 7), true}, {Position(6, 7), true} };
   ogstream stream;

   // draw the board and knights
   stream.drawBoard();
   for (const auto& knight : knights) 
   {
      stream.drawKnight(knight.first, knight.second);
   };
   
}

/***********************************************
* BOARD : GET CURRENT MOVE
*         Get the move number
* OUTPUT: an integer telling number of moves
***********************************************/
int Board::getCurrentMove() const
{
   return numMoves;
}

/***********************************************
* BOARD : WHITE TURN
*         Determine if it is white's turn
* OUTPUT: true or false
***********************************************/
bool Board::whiteTurn() const
{
   if (numMoves == 0 || numMoves % 2 == 0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{

}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{

}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
   // Perform the move
   Piece* pPiece = board[move.source.getCol()][move.source.getRow()];
   board[move.dest.getCol()][move.dest.getRow()] = pPiece;
   board[move.source.getCol()][move.source.getRow()] = new PieceDummy;

   // Update the piece's position
   pPiece->setPosition(move.dest);

   pPiece->incrementNMoves();
   numMoves++;

}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new PieceDummy;
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}