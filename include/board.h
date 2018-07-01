#ifndef INCLUDE_BOARD_H
#define INCLUDE_BOARD_H

#include <vector>
#include <string>

namespace chess {

typedef struct Piece {

	int weight;

} Piece;

typedef struct BoardPlace {

	Piece* chess_piece = NULL;
	std::string position;

} BoardPlace;


class Board {

	public:
		Board();
		~Board();

		std::vector<std::vector <BoardPlace>> board_mat;

	private:
		
};

}

#endif