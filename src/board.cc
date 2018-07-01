#define ASSERT_DEBUG
#include "board.h"

namespace chess {

const int real_board_dim = 22; // dimensao real da matriz
const int use_board_start = 7;
const int use_board_end = 14;
const int use_board_dim = 8;

Board::Board() {

	const char chess_col = 'a';
	char cur_chess_col; 
	std::string cur_chess_row;
	int rows, cols;

	std::vector <BoardPlace> empty_vector;

	BoardPlace empty_place;

	for (rows = 0; rows < real_board_dim; rows ++) {

		board_mat.push_back(empty_vector);

		for (cols = 0; cols < real_board_dim; cols ++) {

			board_mat[rows].push_back(empty_place);

			if (rows >= use_board_start && cols >= use_board_start && 
					rows <= use_board_end && cols <= use_board_end) {

				cur_chess_row = std::to_string (use_board_dim - (rows - use_board_start)); 
				cur_chess_col = chess_col + (cols - use_board_start);
				board_mat[rows][cols].position = cur_chess_col + cur_chess_row;
			}

			else {

				board_mat[rows][cols].position = "00";

			}

		}

	}

}

Board::~Board() {

}

}