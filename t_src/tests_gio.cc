#define CATCH_CONFIG_MAIN

#include "../framework/catch.h"
#include "board.h"

namespace chess {

TEST_CASE ( "Board Basics", "Board operators and strcuture are working right" ) {

	const int real_board_dim = 22; // Dimensao real da matriz

	SECTION ("Creating a board") {

		board test_board;

		REQUIRE (test_board.board_mat.size() == real_board_dim);
		REQUIRE (test_board.board_mat[0].size() == real_board_dim);

	}

}

}