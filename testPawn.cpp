/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    Ryan Donaldson
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"
#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"
#include <cassert>      



 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board: b4
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5     .               5
  * 4    (p)              4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 3, true /*white*/);
   pawn.position.set(1, 3);
   // "Move" the pawn so that pawn.isMoves() = true
   pawn.incrementNMoves();
   board.board[1][3] = &pawn;
   set <Move> moves;
   
   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("b4b5")) != moves.end());
   // TEARDOWN
   board.board[1][3] = nullptr;
   moves.clear();
}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board: b4
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4
 * 3     .               3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 3, false /*white*/);
   pawn.position.set(1, 3);
   // "Move" the pawn so that pawn.isMoves() = true
   pawn.incrementNMoves();
   board.board[1][3] = &pawn;
   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);
   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("b4b3")) != moves.end());
   // TEARDOWN
   board.board[1][3] = nullptr;
   moves.clear();
}


/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4     .               4
 * 3     .               3
 * 2    (p)              2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 1, true /*white*/);
   pawn.position.set(1, 1);
   board.board[1][1] = &pawn;
   set <Move> moves;
   // EXERCISE
   pawn.getMoves(moves, board);
   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("b2b3")) != moves.end());
   assertUnit(moves.find(Move("b2b4")) != moves.end());
   // TEARDOWN
   board.board[1][1] = nullptr;
   moves.clear();
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7      (P)            7
 * 6       .             6
 * 5       .             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 6, false /*white*/);
   pawn.position.set(2, 6);
   board.board[2][6] = &pawn;
   set <Move> moves;
   // EXERCISE
   pawn.getMoves(moves, board);
   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(Move("c7c6")) != moves.end());
   assertUnit(moves.find(Move("c7c5")) != moves.end());
   // TEARDOWN
   board.board[2][6] = nullptr;
   moves.clear();
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7   P P P             7
 * 6    (p)              6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawnW(1, 5, true /*white*/);
   Pawn pawnB1(0, 6, false /*white*/);
   Pawn pawnB2(1, 6, false /*white*/);
   Pawn pawnB3(2, 6, false /*white*/);
   board.board[1][5] = &pawnW;
   board.board[0][6] = &pawnB1;
   board.board[1][6] = &pawnB2;
   board.board[2][6] = &pawnB3;
   set <Move> moves1;
   set <Move> moves2;
   set <Move> moves3;

   // EXERCISE
   pawnB1.getMoves(moves1, board);
   pawnB2.getMoves(moves2, board);
   pawnB3.getMoves(moves3, board);
   // VERIFY
   assertUnit(moves1.size() == 3);
   assertUnit(moves2.size() == 0);
   assertUnit(moves3.size() == 3);
   assertUnit(moves1.find(Move("a7a6")) != moves1.end());
   assertUnit(moves1.find(Move("a7a5")) != moves1.end());
   assertUnit(moves1.find(Move("a7b6p")) != moves1.end());
   assertUnit(moves3.find(Move("c7c6")) != moves3.end());
   assertUnit(moves3.find(Move("c7c5")) != moves3.end());
   assertUnit(moves3.find(Move("c7b6p")) != moves3.end());
   // TEARDOWN
   board.board[1][5] = nullptr;
   board.board[0][6] = nullptr;
   board.board[1][6] = nullptr;
   board.board[2][6] = nullptr;
   moves1.clear();
   moves2.clear();
   moves3.clear();
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6    (P)              6
 * 5   p p p             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawnB(1, 5, false /*white*/);
   Pawn pawnW1(0, 4, true /*white*/);
   Pawn pawnW2(1, 4, true /*white*/);
   Pawn pawnW3(2, 4, true /*white*/);
   board.board[1][5] = &pawnB;
   board.board[0][4] = &pawnW1;
   board.board[1][4] = &pawnW2;
   board.board[2][4] = &pawnW3;
   board.setMovesNumber(1);
   // 'Move' pawns to eliminate double moves
   pawnW1.incrementNMoves();
   pawnW2.incrementNMoves();
   pawnW3.incrementNMoves();
   board.setMovesNumber(5);
   set <Move> moves1;
   set <Move> moves2;
   set <Move> moves3;

   // EXERCISE
   pawnW1.getMoves(moves1, board);
   pawnW2.getMoves(moves2, board);
   pawnW3.getMoves(moves3, board);
   // VERIFY
   assertUnit(moves1.size() == 2);
   assertUnit(moves2.size() == 0);
   assertUnit(moves3.size() == 2);
   assertUnit(moves1.find(Move("a5a6")) != moves1.end());
   assertUnit(moves1.find(Move("a5b6p")) != moves1.end());
   assertUnit(moves3.find(Move("c5c6")) != moves3.end());
   assertUnit(moves3.find(Move("c5b6p")) != moves3.end());
   // TEARDOWN
   board.board[1][5] = nullptr;
   board.board[0][4] = nullptr;
   board.board[1][4] = nullptr;
   board.board[2][4] = nullptr;
   moves1.clear();
   moves2.clear();
   moves3.clear();
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant b5a6E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6   . P .             6
 * 5   P(p)P             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawnW(1, 4, true /*white*/);
   Pawn pawnB1(0, 4, false /*white*/);
   Pawn pawnB2(1, 5, false /*white*/);
   Pawn pawnB3(2, 4, false /*white*/);
   board.board[1][4] = &pawnW;
   board.board[0][4] = &pawnB1;
   board.board[1][5] = &pawnB2;
   board.board[2][4] = &pawnB3;
   set <Move> moves;
   
   pawnW.incrementNMoves(); // To know the white pawn isn't in starting position
   pawnB3.incrementNMoves(); // To know the black pawn B3 has moved already
   pawnB3.incrementNMoves();
   board.setMovesNumber(4); // Simulate the board being on white's turn
   pawnB1.setLastMove(board.getCurrentMove()); // Set move number for pawnB1 pretending it just moved forward
   // increment the boards current move number after black's 'move'
   board.setMovesNumber(5);
   
   // EXERCISE
   pawnW.getMoves(moves, board);
   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("b5a6E")) != moves.end());
   // TEARDOWN
   board.board[1][4] = nullptr;
   board.board[0][4] = nullptr;
   board.board[1][5] = nullptr;
   board.board[2][4] = nullptr;
   moves.clear();
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant f4g3E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4           p(P)p     4
 * 3           . p .     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawnB(5, 3, false /*white*/);
   Pawn pawnW1(4, 3, true /*white*/);
   Pawn pawnW2(5, 2, true /*white*/);
   Pawn pawnW3(6, 3, true /*white*/);
   board.board[5][3] = &pawnB;
   board.board[4][3] = &pawnW1;
   board.board[5][2] = &pawnW2;
   board.board[6][3] = &pawnW3;
   set <Move> moves;

   pawnB.incrementNMoves(); // To know the black pawn isn't in starting position
   pawnW1.incrementNMoves(); // To know the first white pawn has moved
   pawnW1.incrementNMoves();
   board.setMovesNumber(5); // Simulate the board being on black's turn
   pawnW3.setLastMove(board.getCurrentMove()); // Pretend the third white pawn just double moved
   // Increment the board's move number after white's 'move'
   board.setMovesNumber(6);
   
   // EXERCISE
   pawnB.getMoves(moves, board);
   // VERIFY
   assertUnit(moves.size() == 1);
   assertUnit(moves.find(Move("f4g3E")) != moves.end());
   // TEARDOWN
   board.board[5][3] = nullptr;
   board.board[4][3] = nullptr;
   board.board[5][2] = nullptr;
   board.board[6][3] = nullptr;
   moves.clear();
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: b7a8rq
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R . R             8
 * 7    (p)              7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 6, true /*white*/);
   Rook rook1(0, 7, false /*white*/);
   Rook rook2(2, 7, false /*white*/);
   board.board[1][6] = &pawn;
   board.board[0][7] = &rook1;
   board.board[2][7] = &rook2;
   set <Move> moves;
   // EXERCISE
   pawn.getMoves(moves, board);
   // VERIFY
   assertUnit(moves.size() == 3);
   assertUnit(moves.find(Move("b7b8q")) != moves.end());
   assertUnit(moves.find(Move("b7a8Rq")) != moves.end());
   assertUnit(moves.find(Move("b7c8Rq")) != moves.end());
   // TEARDOWN
   board.board[1][6] = nullptr;
   board.board[0][7] = nullptr;
   board.board[2][7] = nullptr;
   moves.clear();
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: e2d1rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2          (P)        2
 * 1         r . r       1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(4, 1, false /*white*/);
   Rook rook1(3, 0, true /*white*/);
   Rook rook2(5, 0, true /*white*/);
   board.board[4][1] = &pawn;
   board.board[3][0] = &rook1;
   board.board[5][0] = &rook2;
   set <Move> moves;
   // EXERCISE
   pawn.getMoves(moves, board);
   // VERIFY
   assertUnit(moves.size() == 3);
   assertUnit(moves.find(Move("e2e1")) != moves.end());
   assertUnit(moves.find(Move("e2d1rQ")) != moves.end());
   assertUnit(moves.find(Move("e2f1rQ")) != moves.end());
   // TEARDOWN
   board.board[4][1] = nullptr;
   board.board[3][0] = nullptr;
   board.board[5][0] = nullptr;
   moves.clear();
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   // SETUP
   Pawn pawn(5, 5, true);
   // EXERCISE
   pawn.getType();
   // VERIFY
   assertUnit(pawn.getType() == PAWN);
   // TEARDOWN
   
}

