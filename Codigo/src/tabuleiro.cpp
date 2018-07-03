#include "tabuleiro.h"

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

		
		for ( k = white_pieces.begin(); k != white_pieces.end(); k++ )
			Save << *k << std :: endl;

		for ( k = black_pieces.begin(); k != black_pieces.end(); k++ )
			Save << *k << std :: endl;

		Save.close();

	}
	else if(option.compare("Nao") == 0)
		exit(0);
	else
		std :: cout << "Digite opção valida!" << std :: endl;

}

