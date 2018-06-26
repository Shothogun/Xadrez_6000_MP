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

enum class Color { White, Black }

class Piece{
public:
	std::pair <int, int> position;
	QGraphicsPixmapItem *image


	Piece();
	~Piece();
	void piecesImages(/* Janela *cena */);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void putFigures(Piece::Color color);
	void setColor(Color color) _color = color; 
	void getColor() const return _color;

signals:
	void mouse_Pressed();
	void mouse_Pos();

private:
	std::list<static const std::string> lostWhite;
	std::list<static const std::string> lostBlack;	
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



// É melhor a gnt usar 
//o clássico pião 1, cavalo e bispo 3, torre 5 e dama 9


#endif // PECA_H