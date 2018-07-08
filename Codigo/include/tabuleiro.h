#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <algorithm> 


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

#endif //TABULEIRO_H
