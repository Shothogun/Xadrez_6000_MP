#include "tabuleiro.h"

//Vê qual é o tipo da peça
std :: string Board :: Type(Piece* piece){
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
	getline(std :: cin, option);

	if(option.compare("Sim") == 0){
		std :: cout << "Digite o nome do jogo que deseja salvar: " << std :: endl;
		std :: string name;
		getline(std :: cin, name);
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
		Save << "Data: "    << day  << "/" << mounth << "/" << year << std :: endl;


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

    while(getline(Default, line)) DataDefault.push_back(line);

    for(int i = 0; i < 35; i++){
		if((DataDefault[i].substr(0, 5)).compare(White) == 0){
			//white_pieces.push_back(DataDefault[i]);
			white_pieces->position = DataDefault[i].substr(13, 2);
			white_pieces->chess_piece = DataDefault[i].substr(7, 6); //Verificar
			white_pieces->chess_piece = DataDefault[i].substr(0, 5); //Verificar
		}
		else if((DataDefault[i].substr(0, 5)).compare(Black) == 0){
			//black_pieces.push_back(DataDefault[i]);
			black_pieces->position = DataDefault[i].substr(13, 2);
			black_pieces->chess_piece = DataDefault[i].substr(7, 6); //Verificar
			black_pieces->chess_piece = DataDefault[i].substr(0, 5); //Verificar
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
	getline(std :: cin, name);
	std :: fstream Save("../JogosSalvos/" + name + ".pgn");
	
    while(getline(Save, line)){
		DataFile.push_back(line);
		numlines++;
	}

    for(int i = 0; i < numlines; i++){
		if((DataFile[i].substr(0, 5)).compare(White) == 0){
			white_pieces.push_back(DataFile[i]);
		}
		else if((DataFile[i].substr(0, 5)).compare(Black) == 0){
			black_pieces.push_back(DataFile[i]);
		}
		
	}

	UpdateWeight();

}
