#ifndef INCLUDE_BOARD_H
#define INCLUDE_BOARD_H

#include <vector>
#include <string>
#include <list>

namespace chess {

typedef struct Piece {

	int weight;
	int type;

} Piece;

/** \brief Board place

		It contains the necessary information of a position of the board
*/

typedef struct BoardPlace {
	/**  Piece pointer to the piece at the current location*/
	Piece* chess_piece = NULL;

	/** Chess coordinates of the current location on the board*/
	std::string position;

} BoardPlace;

/** \brief A chess board class

	The class consists of a matrix of BoardPlace composing the actual board, a integer with the
	weight of the current board and lists with all the BoardPlace that have a piece in it.  

*/

class Board {

	public:
		Board();
		~Board();

		/**
			The matrix that stores the actual board
		*/
		std::vector<std::vector <BoardPlace>> board_mat;

		/**
			An integer that shows the board weight
		*/
		int weight = 0;

		/**
			A list that stores the white pieces and their position.
		*/
		std::list <BoardPlace> white_pieces;

		/**
			A list that stores the black pieces and their position.
		*/
		std::list <BoardPlace> black_pieces;

	private:
		
};

}

#endif