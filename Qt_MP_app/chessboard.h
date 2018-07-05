#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QBrush>

class ChessBoard : public QGraphicsView
{
public:
    ChessBoard(QWidget * parent=0);

    QGraphicsScene * chess;

};

class Janela : public QGraphicsView
{
public:

    Janela(QWidget * parent=0);

    QGraphicsView* janela1;
    QGraphicsScene* chess1;

    QGraphicsView* janela2;
    QGraphicsScene* chess2;

};

#endif // CHESSBOARD_H
