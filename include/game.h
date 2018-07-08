#ifndef INCLUDE_GAME_H_
#define INCLUDE_GAME_H_

#include "board.h"

namespace chess {
/** \brief Struct representativa de uma jogada na arvore de decisoes

*/
typedef struct Play {
	/** Tabuleiro que representa a situacao atual do jogo*/
	Board cur_board;
	/** Movimento que originou no tabuleiro atual*/
	std::vector<int> movement;

}Play;

std::string GraficCoord2Chess(std::tuple<int, int> coord);

std::tuple <int, int> Chess2GraficCoord (string chess_coord);

std::tuple <string, string> Movement2ChessMov (std::vector<int> movement);

std::vector<std::vector<int>> GetPossiblemovements (Board orig_board,PieceColor color);

/** \brief Verificador de final do jogo

		A funcao verifica se a melhor jogada do jogador da vez e perder.
		\param Vetor de inteiros com o melhor movimento a ser feito, Vetor de vetores de inteiros com
		os movimentos que geram fim de jogo, e cor do jogador da vez.
		\return Um inteiro que diz se o jogo acabou. 1 se o jogador de pecas pretas perdeu, -1 se o jogador 
		de pecas brancas perdeu, 0 se ninguem perdeu. 
		\pre Vetor com melhor movimento de tamanho 4 com as coordenadas x y x y da jogada, vetor de vetores
		com os movimentos de fim de jogo com os movimentos seguindo o padrao ja mencionado, e a cor sendo
		alguma valida (preta ou branca).
*/
int EndGame (std::vector<int> best_mov, std::vector<std::vector<int>> checks_mov, PieceColor color);


/** \brief Transformador da posicao do tabuleiro

		A funcao transforma a string com as coordenadas do tabuleiro de xadrez em uma dupla de
		inteiros que armazenam as mesmas coordenadas porem como coordenadas da matriz.
		\param String com a posicao determinada pelas coordenadas de xadrez.
		\return Uma tuple de dois inteiros com as coordenadas (linhas, colunas) da matriz.
		\pre String com coordenadas validas seguindo o padrao do xadrez e matriz do tabuleiro de mesmo
		tamanho que a inicializada.
*/
int MakeMovement (Board* cur_board, std::vector<int> movement);


/** \brief Transformador da posicao do tabuleiro

		A funcao transforma a string com as coordenadas do tabuleiro de xadrez em uma dupla de
		inteiros que armazenam as mesmas coordenadas porem como coordenadas da matriz.
		\param String com a posicao determinada pelas coordenadas de xadrez.
		\return Uma tuple de dois inteiros com as coordenadas (linhas, colunas) da matriz.
		\pre String com coordenadas validas seguindo o padrao do xadrez e matriz do tabuleiro de mesmo
		tamanho que a inicializada.
*/
Tree BuildMovementsTree (Board orig_board, string color);


/** \brief Transformador da posicao do tabuleiro

		A funcao transforma a string com as coordenadas do tabuleiro de xadrez em uma dupla de
		inteiros que armazenam as mesmas coordenadas porem como coordenadas da matriz.
		\param String com a posicao determinada pelas coordenadas de xadrez.
		\return Uma tuple de dois inteiros com as coordenadas (linhas, colunas) da matriz.
		\pre String com coordenadas validas seguindo o padrao do xadrez e matriz do tabuleiro de mesmo
		tamanho que a inicializada.
*/
bool Validatemovement (Tree mov_tree, std::vector<int>movement, std::vector <std::vector<int>> checks);


/** \brief Transformador da posicao do tabuleiro

		A funcao transforma a string com as coordenadas do tabuleiro de xadrez em uma dupla de
		inteiros que armazenam as mesmas coordenadas porem como coordenadas da matriz.
		\param String com a posicao determinada pelas coordenadas de xadrez.
		\return Uma tuple de dois inteiros com as coordenadas (linhas, colunas) da matriz.
		\pre String com coordenadas validas seguindo o padrao do xadrez e matriz do tabuleiro de mesmo
		tamanho que a inicializada.
*/
tuple <std::vector<int>, std::vector<std::vector<int>>> GetBestMoveAndChecks (Tree mov_tree, string color);

} // namespace chess

#endif