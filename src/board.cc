#define ASSERT_DEBUG
#include "board.h"

namespace chess {

const int real_board_dim = 22; // dimensao real da matriz

board::board() {

	int rows, cols;

	std::vector <int> empty_vector;

	for (rows = 0; rows < real_board_dim; rows ++) {

		board_mat.push_back(empty_vector);

		for (cols = 0; cols < real_board_dim; cols ++) {

			board_mat[rows].push_back(0);

		}

	}

}

board::~board() {

}

}