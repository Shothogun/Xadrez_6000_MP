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

		// Checa se as dimensoes estao corretas

		REQUIRE (test_board.board_mat.size() == real_board_dim);
		REQUIRE (test_board.board_mat[0].size() == real_board_dim);

		// Checa se a nomeclatura das posicoes esta correta

		REQUIRE (test_board.board_mat[0][0].position.compare("00") == 0 );
		REQUIRE (test_board.board_mat[9][9].position.compare("00") != 0 );
		REQUIRE (test_board.board_mat[9][9].position.compare("c6") == 0 );

		// Checa se as listas e o peso foram inicializados corretamente

		REQUIRE (test_board.weight == 0);

		REQUIRE (test_board.white_pieces.empty() == 1);
		REQUIRE (test_board.black_pieces.empty() == 1);

	}

	SECTION ("Updating the weight") {

		Board test_board;
		BoardPlace test_place;
		Piece test_piece1;
		Piece test_piece2;
		Piece test_piece3;
		Piece test_piece4;

		// Checa o peso com so uma lista existente

		test_piece1.weight = 1;
		test_place.chess_piece = &test_piece1;
		test_board.black_pieces.push_back(test_place);
		test_board.UpdateWeight();
		REQUIRE (test_board.weight > 0);
		REQUIRE (test_board.weight == 1);

		// Checa o peso com as duas listas existentes

		test_piece2.weight = -1;
		test_place.chess_piece = &test_piece2;
		test_board.white_pieces.push_back(test_place);
		test_board.UpdateWeight();
		REQUIRE (test_board.weight == 0);

		// Checa peso maior que 0 com as duas listas existentes

		test_piece3.weight = 2;
		test_place.chess_piece = &test_piece3;
		test_board.black_pieces.push_back(test_place);
		test_board.UpdateWeight();
		REQUIRE (test_board.weight > 0);
		REQUIRE (test_board.weight == 2);

		// Checa peso menor que 0 com as duas listas existentes

		test_piece4.weight = -3;
		test_place.chess_piece = &test_piece4;
		test_board.white_pieces.push_back(test_place);
		test_board.UpdateWeight();
		REQUIRE (test_board.weight < 0);
		REQUIRE (test_board.weight == -1);

	}

}

}