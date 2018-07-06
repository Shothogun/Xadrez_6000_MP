/*Estruturas:
- Peça branca ou preta (union ou namespace)
- Classe peças
    - struct posição, vetor posições anteriores, 

Funções:
- posição válida
*/

#ifndef PECA_H
#define PECA_H

//#include <QDebug>
#include <iostream>
#include <list>
#include <utility>
#include <QGraphicsPixmapItem>
// #include "interface.h"

enum class Color { White, Black } Color;
enum class Type { pawn, knight, bishop, rook, queen, king } Type;

class Piece: public QGraphicsPixmapItem{
public:

  enum Color color;
  enum Type type;
	int weight;
	std::pair <int, int> position;
	std::list<std::string> lost_Pieces;

	// Como usar:
	// Piece piece(Color::White, Piece::pawn, weight);
	// Para pegar cor, exemplo: piece.getColor();
  Piece(enum Color c, enum Type p, int weight);
};


#endif // PECA_H
