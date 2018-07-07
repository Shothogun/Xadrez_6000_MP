#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsRectItem>
#include "../chesspiece.h"
#include <QGraphicsSceneMouseEvent>
#include <QPoint>


class ChessSquare:public QGraphicsRectItem{
public:
    QPoint center;

    //Constructor
    ChessSquare(QGraphicsItem *parent=0);
    ~ChessSquare();

    //public member function
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QPoint getCenter(){ return center; }
    Piece *currentPiece;
};

#endif // SQUARE_H
