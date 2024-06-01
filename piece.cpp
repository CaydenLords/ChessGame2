/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{

   return *this;
}

/************************************************
 * PIECE : IS WHITE
 * OUTPUT: tells if piece is white or not
 ***********************************************/
bool Piece::isWhite() const
{
   return fWhite;
}

/************************************************
 * PIECE : IS MOVED
 * OUTPUT: tells if piece has moved or not
 ***********************************************/
bool Piece::isMoved() const
{
   if (nMoves == 0)
      return false;
   else
      return true;
}

/************************************************
 * PIECE : GET N MOVES
 * OUTPUT: Number of moves
 ***********************************************/
int Piece::getNMoves() const
{
   return nMoves;
}

void Piece::incrementNMoves()
{
   nMoves = nMoves+1;
}

/************************************************
 * PIECE : GET POSITION
 * OUTPUT: Return's the classes position
 ***********************************************/
const Position& Piece::getPosition() const
{
   return position;
}

/************************************************
 * PIECE : JUST MOVED
 * Tells us if the piece just moved by comparing to board's moves
 * INPUT: current move number
 * OUTPUT: tells if piece just moved or not
 ***********************************************/
bool Piece::justMoved(int currentMove) const
{
   return (lastMove == currentMove-1);
}

/************************************************
 * PIECE : SET LAST MOVE
 * INPUT: current board move number
 * 
 ***********************************************/
void Piece::setLastMove(int currentMove)
{
   lastMove = currentMove;
}

void Piece::setPosition(const Position & pos)
{
   position = pos;
}


/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

/************************************************
 * PIECE : GET DIAGONAL MOVES
 * Iterate through all of the diagonal slide moves
 ***********************************************/
void Piece::diagonalMoves(set <Move>& moves, const Board& board) const{
   // List of Possible moves
   Delta possibleMoves[4] =
   {
   { -1, 1},          { 1,  1},

   { -1, -1},         { 1, -1},
   };
   // For each possible move
   for (int i = 0; i < 4; i++)
   {
      Position pos = position;
      bool continueSlide = true;
      // Check that it's valid
      while (continueSlide) 
      {
            pos = Position(pos.getCol() + possibleMoves[i].dCol, pos.getRow() + possibleMoves[i].dRow);
            if (pos.isValid()) 
            {
               // Check whether it's a space
               if (board[pos].getType() == SPACE) 
               {
                  moves.insert(Move(position, pos, SPACE));
               }
               // Otherwise, check if it's a capturable piece
               else if (board[pos].isWhite() != isWhite()) 
               {
                  moves.insert(Move(position, pos, board[pos].getType()));
                  continueSlide = false;
               }
               else 
               {
                  continueSlide = false;
               }
            }
            else 
            {
               continueSlide = false;
            }
      }
   }
}

/************************************************
 * PIECE : GET ADJACENT MOVES
 * Iterate through all of the diagonal slide moves
 ***********************************************/
void Piece::straightMoves(set <Move>& moves, const Board& board) const {
   // List of Possible moves
   Delta possibleMoves[4] =
   {
             { 0, 1},          
   { -1,  0},         { 1, 0},         
            { 0, -1},
   };
   // For each possible move
   for (int i = 0; i < 4; i++)
   {
      Position pos = position;
      bool continueSlide = true;
      // Check that it's valid
      while (continueSlide) 
      {
         pos = Position(pos.getCol() + possibleMoves[i].dCol, pos.getRow() + possibleMoves[i].dRow);
         if (pos.isValid()) 
         {
            // Check whether it's a space
            if (board[pos].getType() == SPACE) 
            {
               moves.insert(Move(position, pos, SPACE));
            }
            // Otherwise, check if it's a capturable piece
            else if (board[pos].isWhite() != isWhite()) 
            {
               moves.insert(Move(position, pos, board[pos].getType()));
               continueSlide = false;
            }
            else 
            {
               continueSlide = false;
            }
         }
         else 
         {
            continueSlide = false;
         }
      }
   }
}
/************************************************
 * PIECE : GET KNIGHT MOVES
 * Iterate through all of the l-shaped moves the piece could make
 ***********************************************/
void Piece::knightMoves(set <Move>& moves, const Board& board) const 
{
   // List of Possible moves
   Delta possibleMoves[8] =
   {
            {-1,  2}, { 1,  2},
   {-2,  1},                    { 2,  1},
   {-2, -1},                    { 2, -1},
            {-1, -2}, { 1, -2}
   };

   // For each possible move
   for (int i = 0; i < 8; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Check that it's valid
      if (pos.isValid()) 
      {
         // Check whether it's a space
         if (board[pos].getType() == SPACE) 
         {
            moves.insert(Move(position, pos, SPACE));
         }
         // Otherwise, check if it's a capturable piece
         else if (board[pos].isWhite() != isWhite()) 
         {
            moves.insert(Move(position, pos, board[pos].getType()));
         }
      }
   }
}

/************************************************
 * PIECE : GET KING MOVES
 * Iterate through all of the one space moves
 ***********************************************/
void Piece::kingMoves(set <Move>& moves, const Board& board) const 
{
   Delta possibleMoves[8] =
   {
      {-1, 1},  { 0, 1}, { 1, 1},
      {-1, 0},           { 1, 0},
      {-1,-1}, { 0, -1}, { 1,-1}
   };
   for (int i = 0; i < 8; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Check that it's valid
      if (pos.isValid()) 
      {
         // Check whether it's a space
         if (board[pos].getType() == SPACE) 
         {
            moves.insert(Move(position, pos, SPACE));
         }
         // Otherwise, check if it's a capturable piece
         else if (board[pos].isWhite() != isWhite()) 
         {
            moves.insert(Move(position, pos, board[pos].getType()));
         }
      }
   }
}

/************************************************
 * PIECE : CASTLING MOVES
 * See if the piece can castle
 ***********************************************/
void Piece::castlingMoves(set <Move>& moves, const Board& board) const 
{
   Delta possibleMoves[2] =
   {
      {0, -2},  {0, 2},
   };
   // Has the king moved? 
   if (board[position].isMoved() == false)
   {
      // Get rooks assumed positions and either side of king
      Position qRook((position.getCol() - 4), position.getRow());
      Position kRook((position.getCol() + 3), position.getRow());
      Position rSide((position.getCol() + 1), position.getRow());
      Position lSide((position.getCol() - 1), position.getRow());
      // Check each side
      for (int i = 0; i < 2; i++)
      {
         Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
         
         // Is either side valid?
         if (rSide.isValid() || lSide.isValid() )
         {
            // Are either side of the king clear?
            if (board[rSide].getType() == SPACE || board[lSide].getType() == SPACE)
            {
               // Now check king's new position(s)
               if (pos.isValid())
               {
                  if (board[pos].getType() == SPACE)
                  {
                     // Check rooks for moved, color, actually rooks
                     if ((board[qRook].getType() == ROOK && board[qRook].nMoves == 0 && board[qRook].isWhite() == board[position].isWhite()))
                     {
                        moves.insert(Move(position, pos, SPACE, Move::MoveType::CASTLE_QUEEN).getText() + 'C');
                     }
                     else if ((board[kRook].getType() == ROOK && board[kRook].nMoves == 0 && board[kRook].isWhite() == board[position].isWhite()))
                     {
                        moves.insert(Move(position, pos, SPACE, Move::MoveType::CASTLE_KING).getText() + 'c');
                     }
                  }
               }
               
            }
            
         }
         
      }
   }
}

/************************************************
 * PIECE : GET PAWN MOVE WHITE
 * Tell where the white pawn can move
 ***********************************************/
void Piece::pawnSimpleWhiteMove(set <Move>& moves, const Board& board) const 
{
   Delta possibleMoves[1] =
   {
      {1, 0}
   };
   for (int i = 0; i < 1; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Is the position valid?
      if (pos.isValid())
      {
         // Is the position a space?
         if (board[pos].getType() == SPACE)
         {
            moves.insert(Move(position, pos, SPACE));
         }
      }
   }
}

/************************************************
 * PIECE : GET PAWN MOVE BLACK
 * Tell where the black pawn can move
 ***********************************************/
void Piece::pawnSimpleBlackMove(set <Move>& moves, const Board& board) const
{
   Delta possibleMoves[1] =
   {
      {-1, 0}
   };
   for (int i = 0; i < 1; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Is the position valid?
      if (pos.isValid())
      {
         // Is the position a space?
         if (board[pos].getType() == SPACE)
         {
            moves.insert(Move(position, pos, SPACE));
         }
      }
   }
}

/************************************************
 * PIECE : GET WHITE PAWN DOUBLE MOVE
 * Tell the white pawn it can move two spaces
 ***********************************************/
void Piece::pawnWhiteDoubleMove(set<Move>& moves, const Board& board) const
{
   Delta possibleMoves[1] =
   {
      {2, 0}
   };
   // Has the pawn moved?
   if (isMoved() == false)
   {
      // get position in front of pawn
      Position front(position.getCol(), position.getRow() + 1);
      for (int i = 0; i < 1; i++)
      {
         Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
         // Is the space directly in front empty and valid?
         if (front.isValid() && board[front].getType() == SPACE)
         {
            // Is the position valid?
            if (pos.isValid())
            {
               // Is the position a space?
               if (board[pos].getType() == SPACE)
               {
                  moves.insert(Move(position, pos, SPACE));
               }
            }
         }
      }
   }
}

/************************************************
 * PIECE : GET BLACK PAWN DOUBLE MOVE
 * Tell the black pawn it can move two spaces
 ***********************************************/
void Piece::pawnBlackDoubleMove(set<Move>& moves, const Board& board) const
{
   Delta possibleMoves[1] =
   {
      {-2, 0}
   };
   // Has the pawn moved?
   if (isMoved() == false)
   {
      // get position in front of pawn
      Position front(position.getCol(), position.getRow() - 1);
      for (int i = 0; i < 1; i++)
      {
         Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
         // Is the space directly in front empty and valid?
         if (front.isValid() && board[front].getType() == SPACE)
         {
            // Is the position valid?
            if (pos.isValid())
            {
               // Is the position a space?
               if (board[pos].getType() == SPACE)
               {
                  moves.insert(Move(position, pos, SPACE));
               }
            }
         }
         
      }
   }
}

/************************************************
 * PIECE : GET WHITE PAWN CAPTURE MOVE
 * Tell the white pawn if it can capture
 ***********************************************/
void Piece::pawnWhiteCaptureBlack(set<Move>& moves, const Board& board) const
{
   Delta possibleMoves[2] =
   {
      {1, 1}, {1, -1}
   };
   for (int i = 0; i < 2; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Is the position valid?
      if (pos.isValid())
      {
         // Check if the space is empty
         if (board[pos].getType() != SPACE)
         {
            // Piece must be black to capture
            if (board[pos].isWhite() == false)
            {
               moves.insert(Move(position, pos, board[pos].getType()));
            }
         }
      }
   }
}

/************************************************
 * PIECE : GET BLACK PAWN CAPTURE MOVE
 * Tell the black pawn if it can capture
 ***********************************************/
void Piece::pawnBlackCaptureWhite(set<Move>& moves, const Board& board) const
{
   Delta possibleMoves[2] =
   {
      {-1, 1}, {-1, -1}
   };
   for (int i = 0; i < 2; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Is the position valid?
      if (pos.isValid())
      {
         // Check if the space is empty
         if (board[pos].getType() != SPACE)
         {
            // Piece must be white to capture
            if (board[pos].isWhite() == true)
            {
               moves.insert(Move(position, pos, board[pos].getType()));
            }
         }
      }
   }
}

/************************************************
 * PIECE : GET WHITE PROMOTION MOVE
 * Tell the white pawn it can promote
 ***********************************************/
void Piece::promoteWhite(set<Move>& moves, const Board& board) const
{
   Delta possibleMoves[3] =
   {
      {1, -1}, {1, 0}, {1, 1}
   };
   for (int i = 0; i < 3; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Is the position valid?
      if (pos.isValid())
      {
         // Is the position the end of the board?
         if (pos.getRow() == 7)
         {
            // Is the position empty and in the same column?
            if (board[pos].getType() == SPACE && pos.getCol() == 0)
            {
               moves.insert(Move(position, pos, SPACE, QUEEN).getText() + "q");
            }
            // Is there a piece the pawn can capture?
            else if (board[pos].isWhite() == false)
            {
               moves.insert(Move(position, pos, board[pos].getType(), QUEEN).getText() + "q");
            }
         }
      }
   }
}

/************************************************
 * PIECE : GET BLACK PROMOTION MOVE
 * Tell the black pawn it can promote
 ***********************************************/
void Piece::promoteBlack(set<Move>& moves, const Board& board) const
{
   Delta possibleMoves[3] =
   {
      {-1, -1}, {-1, 0}, {-1, 1}
   };
   for (int i = 0; i < 3; i++)
   {
      Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
      // Is the position valid?
      if (pos.isValid())
      {
         // Is the position the end of the board?
         if (pos.getRow() == 0)
         {
            // Is the position empty and in the same column?
            if (board[pos].getType() == SPACE && pos.getCol() == 0)
            {
               moves.insert(Move(position, pos, SPACE, QUEEN).getText() + "Q");
            }
            // Is there a piece the pawn can capture?
            else if (board[pos].isWhite() == true)
            {
               moves.insert(Move(position, pos, board[pos].getType(), QUEEN).getText() + "Q");
            }
         }
      }
   }
}

/************************************************
 * PIECE : GET WHITE EN PASSANT MOVE
 * Tell the white pawn it can en passant capture
 ***********************************************/
void Piece::enPassantWhite(set<Move>& moves, const Board& board) const
{
   // Pawn must be on row 5
   if (position.getRow() != 4)
   {
      return;
   }
   
   // Check adjacent positions for type, color, and just moved
   Position posLeft(position.getCol() - 1, position.getRow());
   Position posRight(position.getCol() + 1, position.getRow());
   if (posLeft.isValid() && board[posLeft].getType() != SPACE)
   {
      if (board[posLeft].getType() == PAWN && !board[posLeft].isWhite() && board[posLeft].justMoved(board.getCurrentMove()) && board[posLeft].nMoves == 1)
      {
         // En Passant positions
         Delta possibleMoves[1] =
         {
            {1, -1}
         };
         for (int i = 0; i < 1; i++)
         {
            Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
            // Is the position valid?
            if (pos.isValid())
            {
               // Is the position holding a space?
               if (board[pos].getType() == SPACE)
               {
                  moves.insert(Move(position, pos, SPACE, Move::MoveType::ENPASSANT).getText() + "E");
               }
            }
         }
      }
   }
   if (posRight.isValid() && board[posRight].getType() != SPACE)
   {
      if (board[posRight].getType() == PAWN && !board[posRight].isWhite() && board[posRight].justMoved(board.getCurrentMove()) && board[posRight].nMoves == 1)
      {
         // En Passant positions
         Delta possibleMoves[1] =
         {
            {1, 1}
         };
         for (int i = 0; i < 1; i++)
         {
            Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
            // Is the position valid?
            if (pos.isValid())
            {
               // Is the position holding a space?
               if (board[pos].getType() == SPACE)
               {
                  moves.insert(Move(position, pos, SPACE, Move::MoveType::ENPASSANT).getText() + "E");
               }
            }
         }
      }
   } 
}

/************************************************
 * PIECE : GET BLACK EN PASSANT MOVE
 * Tell the white pawn it can en passant capture
 ***********************************************/
void Piece::enPassantBlack(set<Move>& moves, const Board& board) const
{
   // Pawn must be on row 4
   if (position.getRow() != 3)
   {
      return;
   }

   // Check adjacent positions for type, color, and just moved
   Position posLeft(position.getCol() - 1, position.getRow());
   Position posRight(position.getCol() + 1, position.getRow());
   if (posLeft.isValid() && board[posLeft].getType() != SPACE)
   {
      if (board[posLeft].getType() == PAWN && board[posLeft].isWhite() && board[posLeft].justMoved(board.getCurrentMove()) && board[posLeft].nMoves == 1)
      {
         // En Passant positions
         Delta possibleMoves[1] =
         {
            {-1, -1}
         };
         for (int i = 0; i < 1; i++)
         {
            Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
            // Is the position valid?
            if (pos.isValid())
            {
               // Is the position holding a space?
               if (board[pos].getType() == SPACE)
               {
                  moves.insert(Move(position, pos, SPACE, Move::MoveType::ENPASSANT).getText() + "E");
               }
            }
         }
      }
   }
   if (posRight.isValid() && board[posRight].getType() != SPACE)
   {
      if (board[posRight].getType() == PAWN && board[posRight].isWhite() && board[posRight].justMoved(board.getCurrentMove()) && board[posRight].nMoves == 1)
      {
         // En Passant positions
         Delta possibleMoves[1] =
         {
            {-1, 1}
         };
         for (int i = 0; i < 1; i++)
         {
            Position pos(position.getCol() + possibleMoves[i].dCol, position.getRow() + possibleMoves[i].dRow);
            // Is the position valid?
            if (pos.isValid())
            {
               // Is the position holding a space?
               if (board[pos].getType() == SPACE)
               {
                  moves.insert(Move(position, pos, SPACE, Move::MoveType::ENPASSANT).getText() + "E");
               }
            }
         }
      }
   }
}