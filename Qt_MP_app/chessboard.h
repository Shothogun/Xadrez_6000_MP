#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "../chesspiece.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <math.h>


class ChessBoard : public QGraphicsView
{
public:
    ChessBoard();
    QGraphicsScene * board;

};


#endif // CHESSBOARD_H
