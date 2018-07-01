#define CATCH_CONFIG_MAIN

#include "../framework/catch.h"
#include "board.h"

namespace chess {

TEST_CASE ( "Board Basics", "Board operators and strcuture are working right" ) {

	const int real_board_dim = 22; // Dimensao real da matriz

	SECTION ("Creating a location of the board") {

		BoardPlace test_place;

		REQUIRE (test_place.chess_piece == NULL);

	}

	SECTION ("Creating a board") {

		Board test_board;

		REQUIRE (test_board.board_mat.size() == real_board_dim);
		REQUIRE (test_board.board_mat[0].size() == real_board_dim);

		REQUIRE (test_board.board_mat[0][0].position.compare("00") == 0 );
		REQUIRE (test_board.board_mat[9][9].position.compare("00") != 0 );
		REQUIRE (test_board.board_mat[9][9].position.compare("c6") == 0 );

	}

}

}