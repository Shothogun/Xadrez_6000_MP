#include "peca.h"


int main(int argc, char const *argv[]){
	Piece Pawn(Color::White, Type::pawn, 2);
	std::cout << Pawn.color << std::endl;
	std::cout << Pawn.type << std::endl;
	std::cout << Pawn.weight << std::endl;
	return 0;
}