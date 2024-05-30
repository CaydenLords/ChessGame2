/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *   Ryan Donaldson and Cayden Lords
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "pieceRook.h"
#include "pieceBishop.h"
#include "pieceKing.h"
#include "pieceQueen.h"
#include "piecePawn.h"
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
         

   // add pieces
   board[0][0] = new Rook(Position(0, 0), false);
   board[1][0] = new Knight(Position(1, 0), false);
   board[2][0] = new Bishop(Position(2, 0), false);
   board[3][0] = new Queen(Position(3, 0), false);
   board[4][0] = new King(Position(4, 0), false);
   board[5][0] = new Bishop(Position(5, 0), false);
   board[6][0] = new Knight(Position(6, 0), false);
   board[7][0] = new Rook(Position(7, 0), false);
   board[0][7] = new Rook(Position(0, 7), true);
   board[1][7] = new Knight(Position(1, 7), true);
   board[2][7] = new Bishop(Position(2, 7), true);
   board[3][7] = new Queen(Position(3, 7), true);
   board[4][7] = new King(Position(4, 7), true);
   board[5][7] = new Bishop(Position(5, 7), true);
   board[6][7] = new Knight(Position(6, 7), true);
   board[7][7] = new Rook(Position(7, 7), true);
   for (int x = 0; x < 8; x++) {
      board[x][1] = new Pawn(Position(x, 1), false);
      board[x][6] = new Pawn(Position(x, 6), true);
   }
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


   if (board[col][row] == nullptr) {
      space = Space(col, row);
      return space;
   }
   return *(board[col][row]);
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect, set <Move> possible) const
{
   ogstream stream;

   // draw any selections
   stream.drawHover(posHover);
   stream.drawSelected(posSelect);
   for (Move item: possible) {
      stream.drawPossible(item.dest);
    }
   //draw the board
   stream.drawBoard();
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
      {
         if (board[c][r] != nullptr){
            board[c][r]->display(&stream);
         }
      }
   
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
 * BOARD : SET NUM MOVES - FOR TESTING
 *         Set the move number the board is on
 *********************************************/
void BoardEmpty::setMovesNumber(int numMoves)
{
   moveNumber = numMoves;
}

/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the obtained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
   // Perform the move
   Piece* pPiece = board[move.source.getCol()][move.source.getRow()];
   board[move.dest.getCol()][move.dest.getRow()] = pPiece;
   board[move.source.getCol()][move.source.getRow()] = new PieceDummy;

   // for En Passant moves
   if (move.isWhite == true && move.moveType == Move::ENPASSANT)
   {
      delete board[move.dest.getCol()][move.source.getRow()]; // Remove the captured pawn
      board[move.dest.getCol()][move.source.getRow()] = new PieceDummy;
   }
   else if (move.isWhite == false && move.moveType == Move::ENPASSANT)
   {
      delete board[move.dest.getCol()][move.source.getRow()]; // Remove the captured pawn
      board[move.dest.getCol()][move.source.getRow()] = new PieceDummy;
   }

   // for king-side castling
   if (move.moveType == Move::CASTLE_KING)
   {
      // Fetch the rook
      Piece* rook = board[move.source.getCol() + 3][move.source.getRow()];
      // Move the rook
      board[move.source.getCol() + 1][move.source.getRow()] = rook;
      board[move.source.getCol() + 3][move.source.getRow()] = new PieceDummy;
   }

   // for queen-side castling
   if (move.moveType == Move::CASTLE_QUEEN)
   {
      // fetch the rook
      Piece* rook = board[move.source.getCol() - 4][move.source.getRow()];
      // move the rook
      board[move.source.getCol() - 1][move.source.getRow()] = rook;
      board[move.source.getCol() - 4][move.source.getRow()] = new PieceDummy;
   }

   // Update the piece's position
   pPiece->setPosition(move.dest);

   // for promotion moves
   if (move.isWhite == true && move.promote == QUEEN)
   {
      delete board[move.dest.getCol()][move.dest.getRow()]; // Remove the pawn to be promoted
      board[move.dest.getCol()][move.dest.getRow()] = new Queen(Position(move.dest.getCol(), move.dest.getRow()), true);
      pPiece = board[move.dest.getCol()][move.dest.getRow()];

   }
   else if (move.isWhite == false && move.promote == QUEEN)
   {
      delete board[move.dest.getCol()][move.dest.getRow()]; // Remove the pawn to be promoted
      board[move.dest.getCol()][move.dest.getRow()] = new Queen(Position(move.dest.getCol(), move.dest.getRow()), false);
      pPiece = board[move.dest.getCol()][move.dest.getRow()];
   }
 
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