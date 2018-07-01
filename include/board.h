#ifndef INCLUDE_BOARD_H
#define INCLUDE_BOARD_H

#include <vector>

namespace chess {

class board {

	public:
		board();
		~board();

		std::vector<std::vector <int>> board_mat;

	private:
		
};

}

#endif