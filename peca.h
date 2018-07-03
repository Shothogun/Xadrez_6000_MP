/*Estruturas:
- Peça branca ou preta (union ou namespace)
- Classe peças
    - struct posição, vetor posições anteriores, 

Funções:
- posição válida
*/

#ifndef PECA_H
#define PECA_H

#include <iostream>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QDebug>
// #include "interface.h"


class Piece{
public:
	enum Color { White, Black } color;

	std::pair <int, int> position;
	QGraphicsPixmapItem *image
	std::list<static const std::string> lost_Pieces;
	std::list<std::pair> positions_board;



	Piece(Color c) : color(c) {};
	~Piece();
	//void piecesImages(/* Janela *cena */);
	//void mousePressEvent(QMouseEvent *event);
	//void mouseMoveEvent(QMouseEvent *event);
	//void putFigures(Piece::Color color);
	void getColor() { const return Color; }

signals:
	void mouse_Pressed();
	void mouse_Pos();
}

class pawn: public: Piece{
	const int weight = 1;
}
class knight: public: Piece{
	const int weight = 3;
}
class bishop: public: Piece{
	const int weight = 3;
}
class rook: public: Piece{
	const int weight = 5;
}
class queen: public: Piece{
	const int weight = 9;
}
class king: public: Piece{
	const int weight = 500;
}


#endif // PECA_H