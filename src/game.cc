#include "game.h"
#include <climits>

namespace chess {

std::string GraficCoord2Chess(std::tuple<int, int> coord)
{
	std::string chess_coord;

	int x = (std::get<0>coord - 25) / 50;
	int y = (std::get<1>coord - 30) / 50;

	const char chess_col = 'a';
	const int first_chess_row = 8;

	chess_coord = (chess_col + x) + (first_chess_row - y);

	return chess_coord;
}

std::tuple <int, int> Chess2GraficCoord (string chess_coord)
{
	const char chess_col = 'a';
	const int first_chess_row = 8;

	int x = ((chess_coord[0] - chess_col) * 50) + 25;
	int y = ((first_chess_row - chess_coord[1]) * 50) + 30;

	return std::make_tuple(x, y);
}

std::tuple <string, string> Movement2ChessMov (std::vector<int> movement)
{
	string chess_coord_1, chess_coord_2;

	chess_coord_1 = GraficCoord2Chess ((movement[0], movement[1]));
	chess_coord_2 = GraficCoord2Chess ((movement[2], movement[3]));

	return std::make_tuple(chess_coord_1, chess_coord_2)
}

std::vector<std::vector<int>> GetPossiblemovements (Board orig_board,PieceColor color)
{

}

int EndGame (std::vector<int> best_mov, std::vector<std::vector<int>> checks_mov, PieceColor color)
{
	uint number;
	int check = 0;

	for (number = 0; number < checks_mov.size(); number++)
	{
		if(checks[number] == best_mov)
			check = 1;
	}

	if (check && color == PieceColor::Black)
		return 1;

	else if (check)
		return -1;

	else 
		return 0;
}

int MakeMovement (Board* cur_board, std::vector<int> movement)
{
	int situation;

	Piece* cur_piece;

	std::tuple <int, int> matrix_place;

	std::tuple <string, string> chess_mov;

	chess_mov = Movement2ChessMov (movement);

	matrix_mov = cur_board->PositionChess2Tuple(std::get<0>chess_mov);

	cur_piece = cur_board->board_mat[std::get<1>matrix_mov][std::get<1>matrix_mov].chess_piece;

	situation = cur_board->PlacePiece(cur_piece->color, cur_piece->type, cur_piece->weight, std::get<1>chess_mov);

	cur_board->RemovePiece (std::get<0>chess_mov, cur_piece->color);

	return situation;//nao_pode, pode e nao come, podee e come;
}

/*Return arvore*/
Tree BuildMovementsTree (Board orig_board, PieceColor color)
{
	uint index;
	uint counter;

	Play play;
	play.cur_board = orig_board;

	std::vector <Board> future_boards;
	std::vector <Board> future_boards_2;
	std::vector <std::vector<int>> mov_vector;
	std::vector <std::vector<int>> mov_vector_2;

	Board new_board;

	Tree <Play> mov_tree;

	mov_tree.insertRoot();

	//mov_vector = GetPossiblemovements (Board orig_board,PieceColor color) // Verificar diagonal piao

	for (index = 0; index < mov_vector.size(); index ++)
	{
		new_board = orig_board;
		future_boards.push_back(new_board);

		play.movement = mov_vector[index];
		MakeMovement (future_boards.back(), mov_vector[index]);

		play.cur_board = future_boards.back();
		mov_tree.insertSon (play);
		mov_tree.gotoSonNode (index);

		mov_vector_2.clear();
		future_boards_2.clear();

		for (counter = 0; counter < mov_vector_2.size(); counter++)
		{
			//mov_vector_2 = GetPossiblemovements (Board orig_board,PieceColor color); (verificar peao)
			new_board = future_boards.back();
			future_boards_2.push_back(new_board);

			play.movement = mov_vector_2[counter];
			MakeMovement (future_boards_2.back(), mov_vector_2[index]);

			play.cur_board = future_boards_2.back();
			mov_tree.insertSon (play);

			mov_vector_2.clear();
			future_boards_2.clear();
		}
		mov_tree.gotoDadNode();
	}

	// Calcular as arvores e tabuleiros (colocar indicador de cheque-mate)
	return mov_tree;
}

bool Validatemovement (Tree mov_tree, std::vector<int> movement, std::vector <std::vector<int>> checks)
{
	uint number;
	int found = 0;
	int check = 0;

	for (number = 0; number < checks.size(); number++)
	{
		if(checks[number] == movement)
			check = 1;
	}
	
	for (number = 0; number < mov_tree.numSonsNode(); number++)
	{
		mov_tree.gotoSonNode(number);
		if (mov_tree.itemNode().movement == movement && check == 0)
		{
			found = 1;
		}
		mov_tree.gotoDadNode();
	}

	if (found)
	{
		return true;
	}
	else
		return false;
}

//mov tree na raiz
tuple <std::vector<int>, std::vector<std::vector<int>>> GetBestMoveAndChecks (Tree mov_tree, PieceColor color)
{
	int index;
	int counter;

	int best_weight;
	movement best_mov;
	std::vector <std::vector<int>> check_mov;

	for (index = 0; index < mov_vector.size(); index ++)
	{
		mov_tree.gotoSonNode (index);

		for (counter = 0; counter > mov_vector_2.size(); counter++)
		{
			mov_tree.gotoSonNode (counter);
			if (color == PieceColor::White)
			{
				best_weight = std::INT_MAX;
				if (mov_tree.itemNode().weight > 200)
				{
					mov_tree.gotoDadNode();
					check_mov.push_back(mov_tree.itemNode().movement);
					mov_tree.gotoSonNode(counter);
				}

				if (mov_tree.itemNode().weight < best_weight)
				{
					best_weight = mov_tree.itemNode().weight;
					mov_tree.gotoDadNode();
					best_mov = mov_tree.itemNode().movement;
				}
				else	
					mov_tree.gotoDadNode();
			}
			else 
			{
				best_weight = std::INT_MIN;
				if (mov_tree.itemNode().weight < -200)
				{
					mov_tree.gotoDadNode();
					check_mov.push_back(mov_tree.itemNode().movement);
					mov_tree.gotoSonNode(counter);
				}

				if (mov_tree.itemNode().weight > best_weight)
				{
					best_weight = mov_tree.itemNode().weight;
					mov_tree.gotoDadNode();
					best_mov = mov_tree.itemNode().movement;
				}
				else	
					mov_tree.gotoDadNode();
			}
		}
		mov_tree.gotoDadNode();
	}

	return (best_mov, check_mov);
}

} // namespace chess