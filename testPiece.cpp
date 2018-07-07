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
