/*Estruturas:
- Peça branca ou preta (union ou namespace)
- Classe peças
    - struct posição, vetor posições anteriores, 

Funções:
- posição válida
*/

#ifndef PECA_H
#define PECA_H

#include <QDebug>
#include <iostream>
#include <list>
#include <utility>
#include <QPointF>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QObject>

enum class PieceColor { White, Black };
enum class PieceType { pawn, knight, bishop, rook, queen, king };

class Piece: public QGraphicsPixmapItem
{
public:

  PieceColor color;
  PieceType type;
	int weight;
	std::pair <int, int> position;
	std::list<std::string> lost_Pieces;
    QPointF offset_position;

	// Como usar:
	// Piece piece(Color::White, Piece::pawn, weight);
	// Para pegar cor, exemplo: piece.getColor();
  Piece(PieceColor c, PieceType p, int weight, QGraphicsItem* parent = 0);

  void setImage(PieceColor c, PieceType type);
  void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
};


#endif // PECA_H
