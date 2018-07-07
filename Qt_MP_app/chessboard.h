#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "../chesspiece.h"
#include "square.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>


class ChessBoard : public QGraphicsView
{
public:
    ChessBoard();
    void putRegionsSquares(QGraphicsScene *board);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    QGraphicsScene * board;

};


#endif // CHESSBOARD_H
