#ifndef CHESSPIECE_H
#define CHESSPIECE_H

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

	// Como usar:
	// Piece piece(Color::White, Piece::pawn, weight);
	// Para pegar cor, exemplo: piece.getColor();

  Piece(PieceColor c, PieceType p, int weight, QGraphicsItem* parent = 0);

  void setImage(PieceColor c, PieceType type);
  void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
  void promotion(QGraphicsSceneMouseEvent* mouseEvent);
};


#endif // CHESSPIECE_H
