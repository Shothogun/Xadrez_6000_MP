#ifndef INCLUDE_BOARD_H
#define INCLUDE_BOARD_H

//#include "chesspiece.h"
#include <vector>
#include <string>
#include <list>
#include <tuple>

namespace chess {

/** \brief Local do tabuleiro

		Contem a informacao necessaria sobre uma posicao do tabuleiro
*/

typedef struct BoardPlace {
	/** Ponteiro para a peca presente na localizacao atual*/
	Piece* chess_piece = NULL;

	/** Coordenadas de xadrez da posicao atual no tabuleiro*/
	std::string position;

} BoardPlace;

/** \brief Uma classe de tabuleiro de xadrez

	A classe consiste em uma matriz de BoardPlace compando o tabuleiro de xadrez, um inteiro com 
	o peso do tabuleiro atual e listas com os BoardPlace que apresentam um peca neles.  

*/

class Board {

	public:
		Board();
		~Board();
		int UpdateWeight();
		void CreateCustomBoard();
		std::tuple<int, int> PositionChess2Tuple (std::string position_chess);
		int PlacePiece (PieceColor color, PieceType type,std:: string position_chess);
		int RemovePiece (std::string position_chess, PieceColor color);
		Board& operator=(Board& other);
		int GetWeight (PieceType type)

		std::list <BoardPlace> :: iterator it;
		std::list <BoardPlace> :: iterator k;

		/**
			A matriz que armazena o tabuleiro em si
		*/
		std::vector<std::vector <BoardPlace>> board_mat;

		/**
			Um inteiro que armazena o peso do tabuleiro.
		*/
		int weight;

		/**
			Uma lista que armazena as pecas brancas e suas posicoes.
		*/
		std::list <BoardPlace> white_pieces;

		/**
			Uma lista que armazena as pecas pretas e suas posicoes.
		*/
		std::list <BoardPlace> black_pieces;

			/**
 		 *@brief Função para retornar o tipo da peça
	 	 *param Peça a ser comparada
	 	 *return Uma string com o tipo de peça
	 	 */
		std :: string Type(Piece* piece);

		/**
	 	 *@brief Função para salvar o jogo atual
	 	 *return Arquivo.pgn com os dados do jogo
	 	 */	
		void SaveGame();

		/**
	 	 *@brief Função que checa a promoção dos peões
	 	 *return ------------------
	 	 */	
		//void ChecksPromotion();

		/**
	 	 *@brief Função para iniciar tabuleiro padrão
	 	 *return ------------------
	 	 */
		void BeginChessboardDefault();

		/**
	 	 *@brief Função para iniciar tabuleiro a partir de um arquivo
	 	 *return ------------------
	 	 */
		void BeginChessboardFile();

	private:
		
};

}

#endif