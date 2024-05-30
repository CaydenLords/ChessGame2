/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input:
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default()
{
   //SETUP
   //EXERCISE
   Move move;
   //VERIFY
   assertUnit(move.source.isInvalid());
   assertUnit(move.dest.isInvalid());
   //TEARDOWN
}

/*************************************
  * CONSTRUCTOR : standard string move
  * Input:  e5e6
  * Output: source=4,4
  *         dest  =2,5
  *         type  =MOVE
  **************************************/
void TestMove::constructString_simple()
{
   // SETUP
   Move move("e5e6");
   // EXERCISE
   // VERIFY
   assertUnit(move.source == Position(4, 4));
   assertUnit(move.dest == Position(2, 5));
   assertUnit(move.moveType == 0);
   // TAKEDOWN
}

/*************************************
  * READ simple move
  * Input:  e5d6
  * Output: source=4,4
  *         dest  =4,5
  *         type  =MOVE
  **************************************/
void TestMove::read_simple()
{
   // SETUP
   Move move("e5d6");
   // EXERCISE
   // VERIFY
   assertUnit(move.source == Position(4, 4));
   assertUnit(move.dest == Position(4, 5));
   assertUnit(move.moveType == Move::MoveType::MOVE);
   // TAKEDOWN
}

/*************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::read_capture()
{
   // SETUP
   Move move("e5d6r");
   // EXERCISE
   // VERIFY
   assertUnit(move.source == Position(4, 4));
   assertUnit(move.dest == Position(4, 5));
   assertUnit(move.moveType == Move::MoveType::MOVE);
   assertUnit(move.capture == PieceType::ROOK);
   // TAKEDOWN
}

/*************************************
 * READ enpassant move
 * Input:  e5d6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::read_enpassant()
{
   // SETUP
   Move move("e5d6E");
   // EXERCISE
   // VERIFY
   assertUnit(move.source == Position(4, 4));
   assertUnit(move.dest == Position(5, 5));
   assertUnit(move.moveType == Move::MoveType::ENPASSANT);
   // TAKEDOWN
}

/*************************************
 * READ king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::read_castleKing()
{
   // SETUP
   Move move("e1g1c");
   // EXERCISE
   // VERIFY
   assertUnit(move.source == Position(4, 0));
   assertUnit(move.dest == Position(6, 0));
   assertUnit(move.moveType == Move::MoveType::CASTLE_KING);
   // TAKEDOWN
}


/*************************************
 * READ queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::read_castleQueen()
{
   // SETUP
   Move move("e1c1C");
   // EXERCISE
   // VERIFY
   assertUnit(move.source == Position(4, 0));
   assertUnit(move.dest == Position(2, 0));
   assertUnit(move.moveType == Move::MoveType::CASTLE_QUEEN);
   // TAKEDOWN
}

/*************************************
  * ASSIGN simple move
  * Input:  e5e6
  * Output: source=4,0
  *         dest  =2,0
  *         type  =MOVE
  **************************************/
void TestMove::assign_simple()
{
   // SETUP
   // EXERCISE
   Move move = Move("e5e6");
   // VERIFY
   assertUnit(move.source == Position(4, 0));
   assertUnit(move.dest == Position(2, 0));
   assertUnit(move.moveType == Move::MoveType::MOVE);
   // TAKEDOWN
}

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{
   // SETUP
   // EXERCISE
   Move move = Move("e5d6r");
   // VERIFY
   assertUnit(move.source == Position(4, 4));
   assertUnit(move.dest == Position(4, 5));
   assertUnit(move.moveType == Move::MoveType::MOVE);
   assertUnit(move.capture == PieceType::ROOK);
   // TAKEDOWN
}

/*************************************
 * ASSIGN enpassant move
 * Input:  e5d6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{
   // SETUP
   // EXERCISE
   Move move = Move("e5d6E");
   // VERIFY
   assertUnit(move.source == Position(4, 4));
   assertUnit(move.dest == Position(5, 5));
   assertUnit(move.moveType == Move::MoveType::ENPASSANT);
   // TAKEDOWN
}

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{
   // SETUP
   // EXERCISE
   Move move = Move("e1g1c");
   // VERIFY
   assertUnit(move.source == (4, 0));
   assertUnit(move.dest == (6, 0));
   assertUnit(move.moveType == Move::MoveType::CASTLE_KING);
   // TAKEDOWN
}


/*************************************
 * ASSIGN queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{
   // SETUP
   // EXERCISE
   Move move = Move("e1c1C");
   // VERIFY
   assertUnit(move.source == (4, 0));
   assertUnit(move.dest == (2, 0));
   assertUnit(move.moveType == Move::MoveType::CASTLE_QUEEN);
   // TAKEDOWN
}

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output: e5e6
 **************************************/
void TestMove::getText_simple()
{
   // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(4, 5);
   move.moveType = Move::MoveType::MOVE;
   move.capture = SPACE;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e5e6");
   // TAKEDOWN
}

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Output: e5e6r
 **************************************/
void TestMove::getText_capture()
{
   // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(4, 5);
   move.moveType = Move::MoveType::MOVE;
   move.capture = PieceType::ROOK;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e5e6r");
   // TAKEDOWN
}

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =4,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Output: e5f6E
 **************************************/
void TestMove::getText_enpassant()
{
   // SETUP
   Move move;
   move.source = Position(4, 4);
   move.dest = Position(4, 5);
   move.moveType = Move::MoveType::ENPASSANT;
   move.capture = PieceType::PAWN;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e5e6E");
   // TAKEDOWN
}

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Output: e1g1c
 **************************************/
void TestMove::getText_castleKing()
{
   // SETUP
   Move move;
   move.source = Position(4, 0);
   move.dest = Position(6, 0);
   move.moveType = Move::MoveType::CASTLE_KING;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e1g1c");
   // TAKEDOWN
}

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Output: e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{
   // SETUP
   Move move;
   move.source = Position(4, 0);
   move.dest = Position(2, 0);
   move.moveType = Move::MoveType::CASTLE_QUEEN;
   // EXERCISE
   string text = move.getText();
   // VERIFY
   assertUnit(text == "e1c1C");
   // TAKEDOWN
}

/*************************************
  * LETTER FROM PIECE TYPE space
  * Input :  SPACE
  * Output:  ' '
  **************************************/
void TestMove::letterFromPieceType_space()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.letterFromPieceType(SPACE) == ' ');
   //TEARDOWN
}


/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.letterFromPieceType(PAWN) == 'p');
   //TEARDOWN
}

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.letterFromPieceType(BISHOP) == 'b');
   //TEARDOWN
}

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.letterFromPieceType(KNIGHT) == 'n');
   //TEARDOWN
}

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.letterFromPieceType(ROOK) == 'r');
   //TEARDOWN
}

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.letterFromPieceType(QUEEN) == 'q');
   //TEARDOWN
}

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.letterFromPieceType(PAWN) == 'p');
   //TEARDOWN
}

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.pieceTypeFromLetter('p') == PAWN);
   //TEARDOWN
}

/*************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.pieceTypeFromLetter('b') == BISHOP);
   //TEARDOWN
}

/*************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Output: KNIGHT
 **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.pieceTypeFromLetter('n') == KNIGHT);
   //TEARDOWN
}

/*************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Output: ROOK
 **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.pieceTypeFromLetter('r') == ROOK);
   //TEARDOWN
}

/*************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Output: QUEEN
 **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.pieceTypeFromLetter('q') == QUEEN);
   //TEARDOWN
}

/*************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Output: KING
 **************************************/
void TestMove::pieceTypeFromLetter_king()
{
   //SETUP
   Move move;
   //EXERCISE
   //VERIFY
   assertUnit(move.pieceTypeFromLetter('k') == KING);
   //TEARDOWN
}