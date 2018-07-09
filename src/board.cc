#define ASSERT_DEBUG
#include "board.h"
#include <iostream>

namespace chess {

const int real_board_dim = 22; // Dimensao real da matriz
const int use_board_start = 7; // Onde comeca o tabuleiro usavel
const int use_board_end = 14; // Onde termina o tabuleiro usavel
const int use_board_dim = 8; // Dimensao do tabuleiro usavel
const int w_pawn =  1;	// Pesos das pecas
const int w_horse = 3;
const int w_bishop = 3;
const int w_tower = 5;
const int w_queen = 9;
const int w_king = 500;


/** \brief Construtor do tabuleiro

		A funcao inicializa o tabuleiro de acordo com parametros pre-determinados: cria uma matriz 
		22x22 e atribui a cada elemento o nome de sua posicao.\n A posicao e dada por "00", que significa
		que ela	nao esta na parte utilizavel da matriz, ou pela coordenada correspondente ao tabuleiro de
		xadrez.
*/

Board::Board() {

	const char chess_col = 'a';
	char cur_chess_col; 
	std::string cur_chess_row;
	int rows, cols;

	board_mat.clear();
	weight = 0;
	white_pieces.clear();
	black_pieces.clear();

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

/** \brief Destruidor do tabuleiro

		A funcao desaloca as pecas existentes.

*/

Board::~Board() {

 for (it = black_pieces.begin(); it != black_pieces.end(); it++) {

		delete it->chess_piece;
	}

}

/** \brief Operador de copia

		A funcao copia um tabuleiro em outro sem compartilhar das mesmas estruturas de pecas.
		\param Outro tabuleiro.

*/

Board& Board::operator=(Board& other) {
	other.~Board();
	other = Board();

	int piece_weight;
	PieceColor piece_color;
	PieceType piece_type;

	for (other.it = other.white_pieces.begin(); other.it != other.white_pieces.end(); other.it++)
	{
		piece_color = other.it->chess_piece.color;
		piece_type = other.it->chess_piece.type;

		piece_weight = other.it->chess_piece.weight;

		PlacePiece (piece_color, piece_type, piece_weight, other.it->position);
	}

	for (other.it = other.black_pieces.begin(); other.it != other.black_pieces.end(); other.it++)
	{
		piece_color = other.it->chess_piece.color;
		piece_type = other.it->chess_piece.type;

		piece_weight = other.it->chess_piece.weight;

		PlacePiece (piece_color, piece_type, piece_weight, other.it->position);
	}

}

/** \brief Atualizador do peso

		A funcao calcula o peso do tabuleiro de acordo com a soma dos pesos das pecas nas listas
		white_pieces e black_pieces e muda seu valor.
		\return O peso do tabuleiro.
*/

int Board::UpdateWeight() {

	weight = 0;

	if (white_pieces.empty() != 1) { // Se a lista nao estiver vazia, somar os pesos das pecas

		for (it = white_pieces.begin(); it != white_pieces.end(); it++) {

			weight -= it->chess_piece->weight;
		}
	}

	if (black_pieces.empty() != 1) { // Se a lista nao estiver vazia, somar os pesos das pecas

		for (it = black_pieces.begin(); it != black_pieces.end(); it++) {

			weight += it->chess_piece->weight;
		}
	}

	return weight;
}

/** \brief Transformador da posicao do tabuleiro

		A funcao transforma a string com as coordenadas do tabuleiro de xadrez em uma dupla de
		inteiros que armazenam as mesmas coordenadas porem como coordenadas da matriz.
		\param String com a posicao determinada pelas coordenadas de xadrez.
		\return Uma tuple de dois inteiros com as coordenadas (linhas, colunas) da matriz.
		\pre String com coordenadas validas seguindo o padrao do xadrez e matriz do tabuleiro de mesmo
		tamanho que a inicializada.
*/

std::tuple<int, int> Board::PositionChess2Tuple (std::string position_chess)
{
	const char chess_col = 'a';
	const int beg = 7;
	const int first_chess_row = 8;
	int col, row;
	std::tuple<int, int> position_matrix;

 	col = (chess_col - position_chess[0]) + beg;
 	row = beg + (first_chess_row - position_chess[1]);

 	position_matrix = std::make_tuple(row, col);
}

/** \brief Colocador de peca em local no tabuleiro

		A funcao adiciona uma peca com as caracteristicas passadas em uma posicao especifica do tabuleiro.
		\param PieceColor com a cor da peca a ser adicionada, PieceType com o tipo da peca a ser adicionada,
		e string com a posicao determinada pelas coordenadas de xadrez.
		\return Um inteiro que diz qual o resultado da operacao. -1 se foi impossivel realiza-la pois existia
		uma peca amiga no locar, 0 se foi possivel realiza-la mas nao existia peca no local, e 1 se foi possivel
		realiza-la mas tinha uma peca inimiga no local que foi removida.
		\pre Caracteristicas validas da peca e string com coordenadas validas seguindo o padrao do xadrez.
*/
int Board::PlacePiece (PieceColor color, PieceType type, std::string position_chess)
{
	int eat;
	int piece_weight;

	piece_weight = GetWeight (type);

	BoardPlace place;

	std::tuple<int, int> position_matrix;

	position_matrix = PositionChess2Tuple(position_chess);

	if (board_mat[std::get<0>position_matrix][std::get<1>position_matrix].chess_piece != NULL)
	{
	 	if(color != board_mat[std::get<0>position_matrix][std::get<1>position_matrix].chess_piece->color)
	 	{
			RemovePiece(position_chess, board_mat[std::get<0>position_matrix][std::get<1>position_matrix].chess_piece->color);
			eat = 1;
		}
		else 
			return -1;
	}
	else 
		eat = 0;

	board_mat[std::get<0>position_matrix][std::get<1>position_matrix].chess_piece = new Piece;

	board_mat[std::get<0>position_matrix][std::get<1>position_matrix].chess_piece->Piece(color, type, piece_weight);

	place = board_mat[std::get<0>position_matrix][std::get<1>position_matrix];

	if (color == PieceColor::White)
	{
		white_pieces.push_back(place);
	}
	else 
	{
		black_pieces.push_back(place);
	}
	UpdateWeight();

	if (eat == 1)
	{
		return 1;
	}
	
	return 0;

}

/** \brief Removedor de peca em local no tabuleiro

		A funcao remove uma peca existente em um local especifico do tabuleiro.
		\param String com a posicao determinada pelas coordenadas de xadrez e cor da peca a ser deletada.
		\return Um inteiro. -1 se nao existia uma peca nessa posicao e 0 se a operacao foi feita corretamente.
		\pre String com coordenadas validas seguindo o padrao do xadrez e variavel PieceColor valida.
*/
int Board::RemovePiece (std::string position_chess, PieceColor color)
{
	std::tuple<int, int> position_matrix;

	position_matrix = PositionChess2Tuple(position_chess);

	int found = 0;
	std::list <BoardPlace> :: iterator it; 


	if (color == PieceColor::White)
	{

		for (it = white_pieces.begin(); it != white_pieces.end() && found == 0; it ++)
		{
			if (it->position.compare(position_chess) == 0)
			{
				found = 1;
				white_pieces.erase(it);
			}
		}
	}

	else 
	{
		for (it = black_pieces.begin(); it != black_pieces.end() && found == 0; it ++)
		{
			if (it->position.compare(position_chess) == 0)
			{
				found = 1;
				black_pieces.erase(it);
			}
		}
	}

	if (found == 1)
	{
		delete board_mat[std::get<0>position_matrix][std::get<1>position_matrix].chess_piece;
		board_mat[std::get<0>position_matrix][std::get<1>position_matrix].chess_piece = NULL;
	}

	else 
		return -1;

	UpdateWeight();
	return 0;
}

/*int CreateCustomBoard () {

	int stop = 0;
	int color;

	int piece_type; // or string

	string chess_position;

	const int pawn = 0;
	const int horse = 1;
	const int bishop = 2;
	const int tower = 3;
	const int queen = 4;
	const int king = 5;

	std::tuple<int, int> position_matrix;

	int piece_quant[2][6] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};

	~Board();
	*this = Board();

	while (stop == 0)
	{
		>> operation;
		>> piece_color;
		>> piece_type;
		>> chess_position;

		position_matrix = PositionChess2Tuple(position_chess);

		if (operation == add)
		{
			>> piece_color;
			>> piece_type;
			>> chess_position;

			if (piece_color = white)
				color = 0;
			else 
				color = 1;

			position_matrix = PositionChess2Tuple(position_chess);

			if (piece_type =="pawn" && piece_quant[color][pawn] < 8)
				piece_quant[color][pawn] += 1;
	
			else if (piece_type == "horse" && piece_quant[color][horse] < 2)
				piece_quant[color][horse] += 1;

			else if (piece_type == "bishop" && piece_quant[color][bishop] < 2)
				piece_quant[color][bishop] += 1;

			else if (piece_type == "tower" && piece_quant[color][tower] < 2)
				piece_quant[color][tower] += 1;

			else if (piece_type == "queen" && piece_quant[color][queen] < 1)
				piece_quant[color][queen] += 1;

			else if (piece_type == "king" && piece_quant[color][king] < 1)
				piece_quant[color][king] += 1;

			PlacePiece ();
		}
		else if (operation == del)
		{
			>> chess_position;

			position_matrix = PositionChess2Tuple(position_chess);

			//gettype
			//getcolor
			if (piece_color = white)
				color = 0;
			else 
				color = 1;

			if (type =="pawn")
			{
				piece_quant[color][pawn] += -1;
			}
			else if (type == "horse")
				piece_quant[color][horse] += -1;

			else if (type == "bishop")
				piece_quant[color][bishop] += -1;

			else if (type == "tower")
				piece_quant[color][tower] += -1;

			else if (type == "queen")
				piece_quant[color][queen] += -1;

			else if (type == "king")
				piece_quant[color][king] += -1;

			RemovePiece();
		}

		else if (operation == stop && piece_quant[1][king] && piece_quant[0][king])
		{
			stop = 1;
		}

	}
}
*/

std :: string Board :: PieceType(Piece* piece) {

	std :: string pieceType;
	if(piece->type == Type::pawn) pieceType = "pawn  ";
	else if(piece->type == Type::rook) pieceType = "rook  ";
	else if(piece->type == Type::knight) pieceType = "knight";
	else if(piece->type == Type::bishop) pieceType = "bishop";
	else if(piece->type == Type::queen) pieceType = "queen ";
	else if(piece->type == Type::king) pieceType = "king  ";

	return pieceType;	
}

// Salva o jogo atual em um arquivo.pgn
void Board :: SaveGame(){
	std :: cout << "Deseja salvar o jogo? <Sim> <Nao>" << std :: endl;
	std :: string option;
	std::getline(std :: cin, option);

	if(option.compare("Sim") == 0){
		std :: cout << "Digite o nome do jogo que deseja salvar: " << std :: endl;
		std :: string name;
		std:: getline(std :: cin, name);
		std :: ofstream Save("../JogosSalvos/" + name + ".pgn");

		time_t timer;
  		struct tm *LocalTime;

  		time(&timer); // Obtem informações de data e hora
  		LocalTime = localtime(&timer); // Converte a hora atual para a hora local

  		int day = LocalTime->tm_mday;
  		int mounth = LocalTime->tm_mon + 1;
  		int year = LocalTime->tm_year + 1900;

  		int hour = LocalTime->tm_hour;
  		int min  = LocalTime->tm_min;
  		int sec  = LocalTime->tm_sec;

  		Save << "Horário: " << hour << ":" << min << ":" << sec << std :: endl;
		Save << "Data: " << day  << "/" << mounth << "/" << year << std :: endl;


		for ( k = white_pieces.begin(); k != white_pieces.end(); k++ ){
			Save << "White" << "|" << Type(k->chess_piece) << "|" << k->position << std :: endl;
		}

		for ( k = black_pieces.begin(); k != black_pieces.end(); k++ ){
			Save << "Black"<< "|" << Type(k->chess_piece) << "|" << k->position << std :: endl;
		}

		Save.close();

	}
	else if(option.compare("Nao") == 0)
		exit(0);
	else
		std :: cout << "Digite opção valida!" << std :: endl;

}

//Checa se foi válida a promoção dos peões quando atingem a última linha do time oposto
/*void Board :: ChecksPromotion(){
	int qntdPieces;
	if(line == 7 && qntdPieces > 1 && COLOR == preta)
	else if(line == 14 && qntdPeao > 1 && COLOR == branca)
}*/

//Inicia tabuleiro no modo padrão
void Board :: BeginChessboardDefault(){
	std::list <std :: string> :: iterator k , j;
  std :: string White = "White"; 
  std :: string Black = "Black";
	std :: fstream Default("../JogosSalvos/ChessboardDefault.pgn");
	std :: string line;
	std :: vector<std :: string> DataDefault;

    while(std::getline(Default, line)) DataDefault.push_back(line);

    for(int i = 0; i < 35; i++){
		if((DataDefault[i].substr(0, 5)).compare(White) == 0){
			//white_pieces.push_back(DataDefault[i]);
			white_pieces.position = DataDefault[i].substr(13, 2);
			white_pieces.chess_piece = DataDefault[i].substr(7, 6); //Verificar
			white_pieces.chess_piece = PieceColor::White; //Verificar
		}
		else if((DataDefault[i].substr(0, 5)).compare(Black) == 0){
			//black_pieces.push_back(DataDefault[i]);
			black_pieces.position = DataDefault[i].substr(13, 2);
			black_pieces.chess_piece = DataDefault[i].substr(7, 6); //Verificar
			black_pieces.chess_piece = PieceColor::Black; //Verificar
		}	
	}

}

//Inicia tabuleiro a partir de um arquivo salvo
void Board :: BeginChessboardFile(){
	std :: string line, name;
	std :: vector<std :: string> DataFile;
	std :: string White = "White";
	std :: string Black =  "Black";
	int numlines = 0;

	std :: cout << "Digite o nome do jogo salvo que deseja iniciar: " << std :: endl;	
	std:: getline(std :: cin, name);
	std :: fstream Save("../JogosSalvos/" + name + ".pgn");
	
    while(std::getline(Save, line)){
		DataFile.push_back(line);
		numlines++;
	}

    for(int i = 0; i < numlines; i++){
		if((DataFile[i].substr(0, 5)).compare(White) == 0){
			white_pieces.position = DataDefault[i].substr(13, 2);
			white_pieces.chess_piece = DataDefault[i].substr(7, 6); //Verificar
			white_pieces.chess_piece = DataDefault[i].substr(0, 5); //Verificar
		}
		else if((DataFile[i].substr(0, 5)).compare(Black) == 0){
			black_pieces.position = DataDefault[i].substr(13, 2);
			black_pieces.chess_piece = DataDefault[i].substr(7, 6); //Verificar
			black_pieces.chess_piece = DataDefault[i].substr(0, 5); //Verificar
		}
		
	}

	UpdateWeight();

}
/** \brief Obtedor do peso de um tipo especifico de peca

		A funcao diz o peso de uma peca especifica do jogo.
		\param PieceType com o tipo da peca em questao.
		\return Um inteiro referente ao peso do tipo de peca passado como parametro.
		\pre Tipo de peca valido.
*/
int Board::GetWeight (PieceType type)
{
	if(type == Type::pawn) piece_weight = w_pawn;
	else if(type == Type::rook) piece_weight = w_rook;
	else if(type == Type::knight) piece_weight = w_knight;
	else if(type == Type::bishop) piece_weight = w_bishop;
	else if(type == Type::queen) piece_weighte = w_queen;
	else if(type == Type::king) piece_weight = w_king;

	return piece_weight;
}


} // namespace chess
