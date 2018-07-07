#define  CATCH_CONFIG_MAIN

#include "chesspiece.h"
#include "catch.hpp"
  
TEST_CASE("Constructor Tree"){
  Piece *piece = new Piece(PieceColor::White, PieceType::pawn, 1);
  CHECK(piece->color == PieceColor::White);
  CHECK(piece->type == PieceType::pawn);
  CHECK(piece->weight == 1);
}
  
TEST_CASE("Promotion"){

  SECTION("White Piece"){
  Piece *piece = new Piece(PieceColor::White, PieceType::pawn, 1);

  piece->promotion((800, 2));
  CHECK(piece->type == PieceType::queen);
  CHECK(piece->weight == 9);

  piece->promotion((0, 2));
  CHECK(piece->type == PieceType::pawn);
  CHECK(piece->weight == 1);
  }

  SECTION("Black Piece"){
  Piece *piece = new Piece(PieceColor::Black, PieceType::pawn, 1);

  piece->promotion((0, 2));
  CHECK(piece->type == PieceType::queen);
  CHECK(piece->weight == 9);

  piece->promotion((800, 2));
  CHECK(piece->type == PieceType::pawn);
  CHECK(piece->weight == 1);
  }
}

TEST_CASE("CheckMoviment"){

  SECTION("Pawn"){
    Piece *piece = new Piece(PieceColor::White, PieceType::pawn, 1);
    piece->first = true;
    CHECK_FALSE(piece->checkMove(20, 80, 200, 100));
    piece->first = false;
    CHECK_FALSE(piece->checkMove(20, 80, 200, 100));
    CHECK_FALSE(piece->checkMove(-1, 80, 200, 100));
    CHECK_FALSE(piece->checkMove(20, 840, 200, 100));
    CHECK(piece->checkMove(20, 60 , 60, 100));
  }

  SECTION("Rook"){
    Piece *piece = new Piece(PieceColor::White, PieceType::rook, 2);
    CHECK_FALSE(piece->checkMove(20, 80, 20, 160));
    CHECK_FALSE(piece->checkMove(20, 80, 160, 100));
    CHECK(piece->checkMove(20, 80, 60, 120));
  }

    SECTION("Knight"){
    Piece *piece = new Piece(PieceColor::White, PieceType::knight, 6);
    CHECK_FALSE(piece->checkMove(20, 80, 140, 160));
    CHECK_FALSE(piece->checkMove(80, 20, 160, 140));
    CHECK(piece->checkMove(20, 80, 100, 120));
    CHECK(piece->checkMove(80, 20, 120, 100));
  }

    SECTION("Bishop"){
    Piece *piece = new Piece(PieceColor::White, PieceType::bishop, 8);
    CHECK_FALSE(piece->checkMove(20, 80, 20, 160));
    CHECK_FALSE(piece->checkMove(20, 80, 160, 80));
    CHECK(piece->checkMove(20, 80, 60, 120));
  }

    SECTION("King"){
    Piece *piece = new Piece(PieceColor::White, PieceType::king, 8);
    CHECK_FALSE(piece->checkMove(20, 80, 80, 120));
    CHECK_FALSE(piece->checkMove(20, 80, 60, 160));
    CHECK(piece->checkMove(20, 80, 60, 120));
  }
}
