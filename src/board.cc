#define ASSERT_DEBUG
#include "board.h"

namespace chess {

const int real_board_dim = 22; // Dimensao real da matriz
const int use_board_start = 7; // Onde comeca o tabuleiro usavel
const int use_board_end = 14; // Onde termina o tabuleiro usavel
const int use_board_dim = 8; // Dimensao do tabuleiro usavel

/** \brief Board constructor

		The function inicializes the board acording with the pre-defined parameters: creates a 
		22x22 matrix and give each element a position name.\n"00" if the position is not part of the 
		using part of the matrix and the right chess coordinate for the others.
*/

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