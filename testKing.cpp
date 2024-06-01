/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>     
#include <iostream>


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p p p         6
 * 5       p(k)p         5
 * 4       p p p         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blocked()
{
   BoardEmpty board;
   King king(3, 4, false /*white*/);
   king.fWhite = true;
   king.position.set(3, 4);
   board.board[3][4] = &king;
   White white1(PAWN);
   board.board[4][4] = &white1;
   White white2(PAWN);
   board.board[4][5] = &white2;
   White white3(PAWN);
   board.board[3][5] = &white3;
   White white4(PAWN);
   board.board[2][5] = &white4;
   White white5(PAWN);
   board.board[2][4] = &white5;
   White white6(PAWN);
   board.board[2][3] = &white6;
   White white7(PAWN);
   board.board[3][3] = &white7;
   White white8(PAWN);
   board.board[4][3] = &white8;
   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // no possible moves

   // TEARDOWN
   board.board[3][4] = nullptr; // white King
   board.board[4][4] = nullptr; // white pawn
   board.board[4][5] = nullptr; // white pawn
   board.board[3][5] = nullptr; // white pawn
   board.board[2][5] = nullptr; // white pawn
   board.board[2][4] = nullptr; // white pawn
   board.board[2][3] = nullptr; // white pawn
   board.board[3][3] = nullptr; // white pawn
   board.board[4][3] = nullptr; // white pawn

   moves.clear();
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
   BoardEmpty board;
   King king(3, 4, false /*white*/);
   king.fWhite = true;
   king.position.set(3, 4);
   board.board[3][4] = &king;
   Black black1(PAWN);
   board.board[4][4] = &black1;
   Black black2(PAWN);
   board.board[4][5] = &black2;
   Black black3(PAWN);
   board.board[3][5] = &black3;
   Black black4(PAWN);
   board.board[2][5] = &black4;
   Black black5(PAWN);
   board.board[2][4] = &black5;
   Black black6(PAWN);
   board.board[2][3] = &black6;
   Black black7(PAWN);
   board.board[3][3] = &black7;
   Black black8(PAWN);
   board.board[4][3] = &black8;
   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);  // no possible moves
   assertUnit(moves.find(Move("d5e4p")) != moves.end());
   assertUnit(moves.find(Move("d5e5p")) != moves.end());
   assertUnit(moves.find(Move("d5e6p")) != moves.end());
   assertUnit(moves.find(Move("d5d6p")) != moves.end());
   assertUnit(moves.find(Move("d5c6p")) != moves.end());
   assertUnit(moves.find(Move("d5c5p")) != moves.end());
   assertUnit(moves.find(Move("d5c4p")) != moves.end());
   assertUnit(moves.find(Move("d5d4p")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr; // white King
   board.board[4][4] = nullptr; // white pawn
   board.board[4][5] = nullptr; // white pawn
   board.board[3][5] = nullptr; // white pawn
   board.board[2][5] = nullptr; // white pawn
   board.board[2][4] = nullptr; // white pawn
   board.board[2][3] = nullptr; // white pawn
   board.board[3][3] = nullptr; // white pawn
   board.board[4][3] = nullptr; // white pawn

   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
   BoardEmpty board;
   King king(3, 4, false /*white*/);
   king.fWhite = true;
   king.incrementNMoves();
   king.position.set(3, 4);
   board.board[3][4] = &king;
   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);  // no possible moves
   assertUnit(moves.find(Move("d5e4")) != moves.end());
   assertUnit(moves.find(Move("d5e5")) != moves.end());
   assertUnit(moves.find(Move("d5e6")) != moves.end());
   assertUnit(moves.find(Move("d5d6")) != moves.end());
   assertUnit(moves.find(Move("d5c6")) != moves.end());
   assertUnit(moves.find(Move("d5c5")) != moves.end());
   assertUnit(moves.find(Move("d5c4")) != moves.end());
   assertUnit(moves.find(Move("d5d4")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr; // white King
   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
   BoardEmpty board;
   King king(0, 0, false /*white*/);
   king.fWhite = true;
   king.incrementNMoves();
   king.position.set(0, 0);
   board.board[0][0] = &king;
   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);  // no possible moves
   assertUnit(moves.find(Move("a1a2")) != moves.end());
   assertUnit(moves.find(Move("a1b2")) != moves.end());
   assertUnit(moves.find(Move("a1b1")) != moves.end());

   // TEARDOWN
   board.board[0][0] = nullptr; // white King
   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
   BoardEmpty board;
   King king(4, 0, true /*white*/);
   king.fWhite = true;
   king.position.set(4, 0);
   board.board[4][0] = &king;
   White white1(PAWN);
   board.board[3][1] = &white1;
   White white2(PAWN);
   board.board[4][1] = &white2;
   White white3(PAWN);
   board.board[5][1] = &white3;
   Rook white4(0, 0, true);
   board.board[0][0] = &white4;
   Rook white5(7, 0, true);
   board.board[7][0] = &white5;
   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 4);  // a couple possible moves
   assertUnit(moves.find(Move("e1d1")) != moves.end());
   assertUnit(moves.find(Move("e1f1")) != moves.end());
   assertUnit(moves.find(Move("e1c1C")) != moves.end());
   assertUnit(moves.find(Move("e1g1c")) != moves.end());

   // TEARDOWN
   board.board[4][0] = nullptr; // white King
   board.board[3][1] = nullptr; // white pawn
   board.board[4][1] = nullptr; // white pawn
   board.board[5][1] = nullptr; // white pawn
   board.board[0][0] = nullptr; // white rook
   board.board[7][0] = nullptr; // white rook
   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
   BoardEmpty board;
   King king(4, 7, false /*black*/);
   king.fWhite = false;
   king.position.set(4, 7);
   board.board[4][7] = &king;
   Black black1(PAWN);
   board.board[4][6] = &black1;
   Black black2(PAWN);
   board.board[3][6] = &black2;
   Black black3(PAWN);
   board.board[5][6] = &black3;
   Rook black4(0, 7, false);
   board.board[0][7] = &black4;
   Rook black5(7, 7, false);
   board.board[7][7] = &black5;
   set <Move> moves;
   // EXERCISE
   king.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 4);  // a couple possible moves
   assertUnit(moves.find(Move("e8d8")) != moves.end());
   assertUnit(moves.find(Move("e8f8")) != moves.end());
   assertUnit(moves.find(Move("e8g8c")) != moves.end());
   assertUnit(moves.find(Move("e8c8C")) != moves.end());

   // TEARDOWN
   board.board[4][7] = nullptr; // black King
   board.board[3][6] = nullptr; // black pawn
   board.board[4][6] = nullptr; // black pawn
   board.board[5][6] = nullptr; // black pawn
   board.board[0][7] = nullptr; // black rook
   board.board[7][7] = nullptr; // black rook
   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
   BoardEmpty board;
   King king(4, 0, true /*white*/);
   king.fWhite = true;
   king.position.set(4, 0);
   board.board[4][0] = &king;
   king.setLastMove(1);
   White white1(PAWN);
   board.board[3][1] = &white1;
   White white2(PAWN);
   board.board[4][1] = &white2;
   White white3(PAWN);
   board.board[5][1] = &white3;
   White white4(ROOK);
   board.board[0][0] = &white4;
   White white5(ROOK);
   board.board[7][0] = &white5;
   set <Move> moves;
   king.incrementNMoves();
   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // a couple possible moves
   assertUnit(moves.find(Move("e1d1")) != moves.end());
   assertUnit(moves.find(Move("e1f1")) != moves.end());


   // TEARDOWN
   board.board[4][0] = nullptr; // white King
   board.board[3][1] = nullptr; // white pawn
   board.board[4][1] = nullptr; // white pawn
   board.board[5][1] = nullptr; // white pawn
   board.board[0][0] = nullptr; // white rook
   board.board[7][0] = nullptr; // white rook
   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
   BoardEmpty board;
   King king(4, 0, true /*white*/);
   king.fWhite = true;
   king.position.set(4, 0);
   board.board[4][0] = &king;
   king.setLastMove(1);
   White white1(PAWN);
   board.board[3][1] = &white1;
   White white2(PAWN);
   board.board[4][1] = &white2;
   White white3(PAWN);
   board.board[5][1] = &white3;
   White white4(ROOK);
   board.board[0][0] = &white4;
   White white5(ROOK);
   board.board[7][0] = &white5;
   set <Move> moves;
   white4.incrementNMoves();
   white5.incrementNMoves();
   // EXERCISE
   king.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 2);  // a couple possible moves
   assertUnit(moves.find(Move("e1d1")) != moves.end());
   assertUnit(moves.find(Move("e1f1")) != moves.end());


   // TEARDOWN
   board.board[4][0] = nullptr; // white King
   board.board[3][1] = nullptr; // white pawn
   board.board[4][1] = nullptr; // white pawn
   board.board[5][1] = nullptr; // white pawn
   board.board[0][0] = nullptr; // white rook
   board.board[7][0] = nullptr; // white rook
   moves.clear();
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
   // SETUP
   // EXERCISE
   King king = King(Position(), true);
   //VERIFY
   assertUnit(king.getType() == KING);
}  // TEARDOWN



