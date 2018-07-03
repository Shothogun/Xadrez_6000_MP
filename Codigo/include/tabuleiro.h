/**
 *@file tabuleiro.h
 *@version 1.0
 *@date 30/06/2018 
 *@author Ayllah Ahmad Lopes
 *@title Funções do Tabuleiro
 *@brief Funções auxiliares para manipulação do tabuleiro
 */

#ifndef TABULEIRO_H					
#define TABULEIRO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm> 


namespace chess {
	typedef struct Piece {

		int weight;
		int type;

	} Piece;

	typedef struct BoardPlace {
		Piece* chess_piece = NULL;
		std::string position;

	} BoardPlace;

	class Board {

	public:
		Board();
		~Board();
		int UpdateWeight();

		std::vector<std::vector <BoardPlace>> board_mat;
		int weight = 0;
		std::list <BoardPlace> white_pieces;
		std::list <BoardPlace> black_pieces;
		std::list <BoardPlace> :: iterator k;

		/**
 		 *@brief Função para salvar o jogo atual
 		 *return Arquivo.pgn com os dados do jogo
 		 */	
		void SaveGame();

		/**
 		 *@brief Função que checa a promoção dos peões
 		 *return ------------------
 		 */	
		void ChecksPromotion();

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



#endif //TABULEIRO_H