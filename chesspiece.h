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
	QPointF position;
	std::list<std::string> lost_Pieces;
  std::vector<QPointF> centers;
  bool first; // for Pawn

	// Como usar:
    // Piece piece(Color::White, Piece::pawn, number);
  Piece(PieceColor c, PieceType p, int weight, QGraphicsItem* parent = 0);

  void setImage(PieceColor c, PieceType type);
  void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
  void promotion(QPointF point);
  void CentersRegions();
  int FoundCenterRegion(QPointF point);
  bool checkPawnMove(int fromr, int fromc, int tor, int toc);
  bool checkRookMove(int fromr, int fromc, int tor, int toc);
  bool checkKnightMove(int fromr, int fromc, int tor, int toc);
  bool checkKnightMove(int fromr, int fromc, int tor, int toc);
  bool checkBishopMove(int fromr, int fromc, int tor, int toc);
  bool checkKingMove(int fromr, int fromc, int tor, int toc);
  bool checkMove(int fromr, int fromc, int tor, int toc);
};


#endif // CHESSPIECE_H
