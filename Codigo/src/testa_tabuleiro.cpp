#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tabuleiro.h"


TEST_CASE("Tabuleiro"){
	Chessboard tab;

  tab.SaveGame();
  std :: string name;
	std :: fstream Save("../JogosSalvos/" + name + ".txt");
  
  REQUIRE(Save.is_open());
 
}