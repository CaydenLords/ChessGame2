/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3       p             3
 * 2     p(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_blocked()
{
   BoardEmpty board;
   Rook rook(2, 1, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;
   White white1(PAWN);
   board.board[2][2] = &white1;
   White white2(PAWN);
   board.board[2][0] = &white2;
   White white3(PAWN);
   board.board[3][1] = &white3;
   White white4(PAWN);
   board.board[1][1] = &white4;
   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // no possible moves

   // TEARDOWN
   board.board[2][1] = nullptr; // white Bishop
   board.board[2][2] = nullptr; // white pawn
   board.board[2][0] = nullptr; // white pawn
   board.board[1][1] = nullptr; // white pawn
   board.board[3][1] = nullptr; // white pawn
   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
   BoardEmpty board;
   Rook rook(2, 1, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;
   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);  // many possible moves
   assertUnit(moves.find(Move("c2c1")) != moves.end());
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2c8")) != moves.end());
   assertUnit(moves.find(Move("c2a2")) != moves.end());
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2h2")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white Bishop
   moves.clear();
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
   BoardEmpty board;
   Rook rook(2, 1, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;
   White white1(PAWN);
   board.board[0][1] = &white1;
   White white2(PAWN);
   board.board[2][0] = &white2;
   White white3(PAWN);
   board.board[7][1] = &white3;
   White white4(PAWN);
   board.board[2][7] = &white4;
   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 10);  // many possible moves
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());




   // TEARDOWN
   board.board[2][1] = nullptr; // white Bishop
   board.board[0][2] = nullptr; // white pawn
   board.board[2][0] = nullptr; // white pawn
   board.board[7][2] = nullptr; // white pawn
   board.board[2][7] = nullptr; // white pawn
   moves.clear();
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
   BoardEmpty board;
   Rook rook(2, 1, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;
   Black black1(PAWN);
   board.board[0][1] = &black1;
   Black black2(PAWN);
   board.board[2][0] = &black2;
   Black black3(PAWN);
   board.board[7][1] = &black3;
   Black black4(PAWN);
   board.board[2][7] = &black4;
   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);  // many possible moves
   assertUnit(moves.find(Move("c2c3")) != moves.end());
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2b2")) != moves.end());
   assertUnit(moves.find(Move("c2d2")) != moves.end());
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2a2p")) != moves.end());
   assertUnit(moves.find(Move("c2h2p")) != moves.end());
   assertUnit(moves.find(Move("c2c1p")) != moves.end());
   assertUnit(moves.find(Move("c2c8p")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white Bishop
   board.board[0][2] = nullptr; // black pawn
   board.board[2][0] = nullptr; // black pawn
   board.board[7][2] = nullptr; // black pawn
   board.board[2][7] = nullptr; // black pawn
   moves.clear();
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   // SETUP
   // EXERCISE
   Rook rook = Rook(Position(), true);
   //VERIFY
   assertUnit(rook.getType() == ROOK);
}  // TEARDOWN